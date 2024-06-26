/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4X3/include/IfcTimeSeriesValue.h"
#include "ifcpp/IFC4X3/include/IfcValue.h"

// ENTITY IfcTimeSeriesValue 
IFC4X3::IfcTimeSeriesValue::IfcTimeSeriesValue( int tag ) { m_tag = tag; }
void IFC4X3::IfcTimeSeriesValue::getStepLine( std::stringstream& stream, size_t precision ) const
{
	stream << "#" << m_tag << "=IFCTIMESERIESVALUE" << "(";
	stream << "(";
	for( size_t ii = 0; ii < m_ListValues.size(); ++ii )
	{
		if( ii > 0 )
		{
			stream << ",";
		}
		const shared_ptr<IfcValue>& type_object = m_ListValues[ii];
		if( type_object )
		{
			type_object->getStepParameter( stream, true, precision );
		}
		else
		{
			stream << "$";
		}
	}
	stream << ")";
	stream << ");";
}
void IFC4X3::IfcTimeSeriesValue::getStepParameter( std::stringstream& stream, bool /*is_select_type*/, size_t /*precision*/ ) const { stream << "#" << m_tag; }
void IFC4X3::IfcTimeSeriesValue::readStepArguments( const std::vector<std::string>& args, const BuildingModelMapType<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream, std::unordered_set<int>& entityIdNotFound )
{
	const size_t num_args = args.size();
	if( num_args > 0 ){readSelectList( args[0], m_ListValues, "IFCVALUE", map, errorStream, entityIdNotFound );}
	if( num_args != 1 ){ errorStream << "Wrong parameter count for entity IfcTimeSeriesValue, expecting 1, having " << num_args << ". Entity ID: " << m_tag << std::endl; }
}
void IFC4X3::IfcTimeSeriesValue::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const
{
	shared_ptr<AttributeObjectVector> ListValues_vec_object( new AttributeObjectVector() );
	std::copy( m_ListValues.begin(), m_ListValues.end(), std::back_inserter( ListValues_vec_object->m_vec ) );
	vec_attributes.emplace_back( std::make_pair( "ListValues", ListValues_vec_object ) );
}
void IFC4X3::IfcTimeSeriesValue::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse ) const
{
}
void IFC4X3::IfcTimeSeriesValue::setInverseCounterparts( shared_ptr<BuildingEntity> )
{
}
void IFC4X3::IfcTimeSeriesValue::unlinkFromInverseCounterparts()
{
}
