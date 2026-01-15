# Example: Checking Instanced Rendering Cache

This example demonstrates how to check and monitor the instanced rendering cache while loading IFC files.

## Simple Usage Example

```cpp
#include <ifcpp/model/BuildingModel.h>
#include <ifcpp/reader/ReaderSTEP.h>
#include <ifcpp/geometry/GeometryConverter.h>
#include <ifcpp/geometry/GeometrySettings.h>
#include <iostream>

int main()
{
    // Create IFC model
    shared_ptr<BuildingModel> ifc_model = make_shared<BuildingModel>();
    
    // Load IFC file
    shared_ptr<ReaderSTEP> step_reader = make_shared<ReaderSTEP>();
    step_reader->setMessageCallBack(ifc_model.get(), &BuildingModel::messageTarget);
    step_reader->loadModelFromFile("example.ifc", ifc_model);
    
    // Create geometry converter with default settings
    shared_ptr<GeometrySettings> geom_settings = make_shared<GeometrySettings>();
    shared_ptr<GeometryConverter> geometry_converter = 
        make_shared<GeometryConverter>(ifc_model, geom_settings);
    
    // Get representation converter to monitor cache
    shared_ptr<RepresentationConverter> rep_converter = 
        geometry_converter->getRepresentationConverter();
    
    // Check if caching is enabled (should be true by default)
    std::cout << "Instanced rendering cache enabled: " 
              << (rep_converter->isRepresentationMapCachingEnabled() ? "Yes" : "No") 
              << std::endl;
    
    // Convert geometry (cache will be populated during this process)
    std::cout << "Converting geometry..." << std::endl;
    geometry_converter->convertGeometry();
    
    // Check cache statistics after conversion
    size_t cache_size = rep_converter->getRepresentationMapCacheSize();
    std::cout << "Number of cached representation maps: " << cache_size << std::endl;
    std::cout << "These cached items will be reused for all instances in the model." << std::endl;
    
    return 0;
}
```

## Advanced: Disable Caching for Comparison

```cpp
#include <chrono>

// Function to measure conversion time
double measureConversionTime(shared_ptr<GeometryConverter>& converter)
{
    auto start = std::chrono::high_resolution_clock::now();
    converter->convertGeometry();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    return elapsed.count();
}

int main()
{
    // First conversion WITH caching (default)
    shared_ptr<BuildingModel> ifc_model1 = make_shared<BuildingModel>();
    shared_ptr<ReaderSTEP> step_reader1 = make_shared<ReaderSTEP>();
    step_reader1->loadModelFromFile("example.ifc", ifc_model1);
    
    shared_ptr<GeometrySettings> geom_settings1 = make_shared<GeometrySettings>();
    shared_ptr<GeometryConverter> converter1 = 
        make_shared<GeometryConverter>(ifc_model1, geom_settings1);
    
    double time_with_cache = measureConversionTime(converter1);
    size_t cache_size = converter1->getRepresentationConverter()->getRepresentationMapCacheSize();
    
    std::cout << "WITH caching:" << std::endl;
    std::cout << "  Time: " << time_with_cache << " seconds" << std::endl;
    std::cout << "  Cached items: " << cache_size << std::endl;
    
    // Second conversion WITHOUT caching
    shared_ptr<BuildingModel> ifc_model2 = make_shared<BuildingModel>();
    shared_ptr<ReaderSTEP> step_reader2 = make_shared<ReaderSTEP>();
    step_reader2->loadModelFromFile("example.ifc", ifc_model2);
    
    shared_ptr<GeometrySettings> geom_settings2 = make_shared<GeometrySettings>();
    shared_ptr<GeometryConverter> converter2 = 
        make_shared<GeometryConverter>(ifc_model2, geom_settings2);
    
    // Disable caching before conversion
    converter2->getRepresentationConverter()->setRepresentationMapCachingEnabled(false);
    
    double time_without_cache = measureConversionTime(converter2);
    
    std::cout << "\nWITHOUT caching:" << std::endl;
    std::cout << "  Time: " << time_without_cache << " seconds" << std::endl;
    
    // Calculate improvement
    double improvement = ((time_without_cache - time_with_cache) / time_without_cache) * 100.0;
    std::cout << "\nPerformance improvement: " << improvement << "%" << std::endl;
    
    return 0;
}
```

## Expected Output

For a typical office building with many repeated windows and doors:

```
WITH caching:
  Time: 2.45 seconds
  Cached items: 15

WITHOUT caching:
  Time: 4.23 seconds

Performance improvement: 42.1%
```

The actual improvement depends on:
- Number of unique shapes vs. total instances
- Complexity of each shape
- Hardware performance

## Notes

1. **Default Behavior**: Caching is enabled by default, so you don't need to do anything to benefit from it.

2. **Cache Clearing**: The cache is automatically cleared when:
   - Loading a new model
   - Calling `clearCache()` on RepresentationConverter
   - GeometryConverter is reset

3. **Memory Usage**: The cache stores one copy of geometry per unique RepresentationMap. For models with many instances, this typically reduces memory usage during conversion.

4. **Thread Safety**: Each GeometryConverter instance has its own cache, so parallel processing of different models is safe.
