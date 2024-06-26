/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */

#include <sstream>
#include <limits>
#include <map>
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/IFC4X3/include/IfcSimpleValue.h"
#include "ifcpp/IFC4X3/include/IfcText.h"

// TYPE IfcText = STRING;
IFC4X3::IfcText::IfcText( std::string value ) { m_value = value; }
void IFC4X3::IfcText::getStepParameter( std::stringstream& stream, bool is_select_type, size_t precision ) const
{
	if( is_select_type ) { stream << "IFCTEXT("; }
	stream << "'" << encodeStepString( m_value ) << "'";
	if( is_select_type ) { stream << ")"; }
}
shared_ptr<IFC4X3::IfcText> IFC4X3::IfcText::createObjectFromSTEP( const std::string& arg, const BuildingModelMapType<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream, std::unordered_set<int>& entityIdNotFound )
{
	if( arg.size() == 0 ) { return shared_ptr<IfcText>(); }
	if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcText>(); }
	if( arg.compare( "*" ) == 0 ) { return shared_ptr<IfcText>(); }
	shared_ptr<IfcText> type_object( new IfcText() );
	readString( arg, type_object->m_value );
	return type_object;
}
