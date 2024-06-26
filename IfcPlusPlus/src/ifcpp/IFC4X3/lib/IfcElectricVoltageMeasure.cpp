/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */

#include <sstream>
#include <limits>
#include <map>
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/IFC4X3/include/IfcDerivedMeasureValue.h"
#include "ifcpp/IFC4X3/include/IfcElectricVoltageMeasure.h"

// TYPE IfcElectricVoltageMeasure = REAL;
IFC4X3::IfcElectricVoltageMeasure::IfcElectricVoltageMeasure( double value ) { m_value = value; }
void IFC4X3::IfcElectricVoltageMeasure::getStepParameter( std::stringstream& stream, bool is_select_type, size_t precision ) const
{
	if( is_select_type ) { stream << "IFCELECTRICVOLTAGEMEASURE("; }
	appendRealWithoutTrailingZeros( stream, m_value, precision );
	if( is_select_type ) { stream << ")"; }
}
shared_ptr<IFC4X3::IfcElectricVoltageMeasure> IFC4X3::IfcElectricVoltageMeasure::createObjectFromSTEP( const std::string& arg, const BuildingModelMapType<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream, std::unordered_set<int>& entityIdNotFound )
{
	if( arg.size() == 0 ) { return shared_ptr<IfcElectricVoltageMeasure>(); }
	if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcElectricVoltageMeasure>(); }
	if( arg.compare( "*" ) == 0 ) { return shared_ptr<IfcElectricVoltageMeasure>(); }
	shared_ptr<IfcElectricVoltageMeasure> type_object( new IfcElectricVoltageMeasure() );
	readReal( arg, type_object->m_value );
	return type_object;
}
