# Instanced Rendering Optimization

## Overview

This feature implements geometry caching for IFC objects that share the same shape (via `IfcRepresentationMap`) but have different positions. This optimization significantly reduces parsing time and memory usage for models with many repeated elements (e.g., windows, doors, columns, furniture).

## How It Works

### IFC Standard Background

The IFC standard provides a built-in mechanism for instancing through:
- **IfcRepresentationMap**: Defines a reusable shape representation
- **IfcMappedItem**: References an IfcRepresentationMap with an optional transformation

When multiple objects reference the same IfcRepresentationMap, they share the same geometry definition but with different placements.

### Implementation

The optimization works as follows:

1. **Detection**: When parsing an `IfcMappedItem`, the system extracts the `IfcRepresentationMap` entity ID
2. **Cache Lookup**: Before converting geometry, check if this RepresentationMap has been processed before
3. **Cache Hit**: If found, clone the cached geometry and apply only the instance-specific transformation
4. **Cache Miss**: If not found, perform full geometry conversion and store the result in cache

### Performance Benefits

For typical architectural models with repeated elements:
- **Reduced computation**: Geometry is generated only once per unique shape
- **Faster parsing**: Subsequent instances only require copying and transformation
- **Memory efficiency**: During conversion, only one copy of geometry is generated per RepresentationMap

## Usage

### Basic Usage

The caching is **enabled by default**. No code changes are required to benefit from this optimization.

```cpp
// Standard usage - caching is automatically enabled
shared_ptr<GeometryConverter> geometry_converter = 
    make_shared<GeometryConverter>(ifc_model, geom_settings);

geometry_converter->convertGeometry();
```

### Advanced Control

You can control the caching behavior through the RepresentationConverter:

```cpp
// Access the representation converter
shared_ptr<RepresentationConverter> rep_converter = 
    geometry_converter->getRepresentationConverter();

// Disable caching (if needed for specific use cases)
rep_converter->setRepresentationMapCachingEnabled(false);

// Check if caching is enabled
bool is_enabled = rep_converter->isRepresentationMapCachingEnabled();

// Get cache statistics
size_t cached_items = rep_converter->getRepresentationMapCacheSize();
std::cout << "Number of cached representation maps: " << cached_items << std::endl;

// Clear cache manually (automatically cleared on model reload)
rep_converter->clearRepresentationMapCache();
```

### When to Disable Caching

Caching should remain enabled in most scenarios. Consider disabling only if:
- Memory is extremely constrained and the model has very few repeated elements
- Debugging geometry conversion issues
- Implementing custom caching mechanisms

## Implementation Details

### Cache Key

The cache uses the `IfcRepresentationMap` entity ID (`m_tag`) as the dictionary key. This ensures:
- Unique identification of each representation map
- Efficient O(1) lookup performance
- Automatic handling by the IFC entity system

### Data Structure

```cpp
// In RepresentationConverter class
std::map<int, shared_ptr<ItemShapeData>> m_representationMapCache;
bool m_enableRepresentationMapCaching = true;
```

### Geometry Copying

When a cache hit occurs:
1. The `ItemShapeData::copyFrom()` method creates deep copies of meshsets
2. Mesh cloning is handled by Carve's `meshset->clone()` method
3. Only the instance-specific transformation is then applied

### Cache Lifecycle

- **Initialization**: Created when RepresentationConverter is instantiated
- **Population**: Filled during `convertIfcRepresentation()` calls
- **Clearing**: Automatically cleared when:
  - Model is reset or reloaded
  - `clearCache()` is called on RepresentationConverter
  - RepresentationConverter is destroyed

## Example Scenarios

### Scenario 1: Office Building with Repeated Windows

An office building with 500 identical windows:
- **Without caching**: Window geometry generated 500 times
- **With caching**: Window geometry generated once, copied 499 times
- **Result**: Significant reduction in parsing time

### Scenario 2: Apartment Complex with Furniture

An apartment complex with 100 apartments, each with identical furniture sets:
- **Without caching**: Each furniture piece generated 100 times
- **With caching**: Each furniture piece generated once, copied 99 times
- **Result**: Faster loading and reduced memory usage during conversion

## Technical Notes

### Thread Safety

The current implementation is not explicitly thread-safe. If using multi-threaded geometry conversion:
- Each thread should have its own RepresentationConverter instance
- Or implement locking around cache access

### Memory Trade-offs

- **Cache storage**: Stores one copy of ItemShapeData per unique RepresentationMap
- **Savings**: N instances × (full geometry generation cost - copy and transform cost)
- **Typical result**: Net memory reduction during parsing, as generating geometry is more expensive than storing it

### Compatibility

This optimization:
- ✅ Preserves exact geometry output (bit-identical results)
- ✅ Maintains all transformations correctly
- ✅ Handles styles and materials per instance
- ✅ Works with openings and boolean operations
- ✅ Compatible with existing code and workflows

## Future Enhancements

Potential improvements for future versions:
- Cache statistics and performance metrics
- Configurable cache size limits
- Cache persistence across multiple model loads
- Support for GPU-instanced rendering data export

## Code References

Key files modified:
- `IfcPlusPlus/src/ifcpp/geometry/RepresentationConverter.h` (lines 95-165, 237-330)
- Implementation in `convertIfcRepresentation()` method

Key data structures used:
- `ItemShapeData` (GeometryInputData.h)
- `IfcRepresentationMap` (IFC4X3/include/IfcRepresentationMap.h)
- `IfcMappedItem` (IFC4X3/include/IfcMappedItem.h)
