/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */

#include <sstream>
#include <limits>
#include <map>
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/IFC4X3/include/IfcCostItemTypeEnum.h"

// TYPE IfcCostItemTypeEnum = ENUMERATION OF	(USERDEFINED	,NOTDEFINED);
shared_ptr<BuildingObject> IFC4X3::IfcCostItemTypeEnum::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcCostItemTypeEnum> copy_self( new IfcCostItemTypeEnum() );
	copy_self->m_enum = m_enum;
	return copy_self;
}
void IFC4X3::IfcCostItemTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
{
	if( is_select_type ) { stream << "IFCCOSTITEMTYPEENUM("; }
	switch( m_enum )
	{
		case ENUM_USERDEFINED:	stream << ".USERDEFINED."; break;
		case ENUM_NOTDEFINED:	stream << ".NOTDEFINED."; break;
	}
	if( is_select_type ) { stream << ")"; }
}
shared_ptr<IFC4X3::IfcCostItemTypeEnum> IFC4X3::IfcCostItemTypeEnum::createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcCostItemTypeEnum>(); }
	if( arg.compare( "*" ) == 0 ) { return shared_ptr<IfcCostItemTypeEnum>(); }
	shared_ptr<IfcCostItemTypeEnum> type_object( new IfcCostItemTypeEnum() );
	if( std_iequal( arg, ".USERDEFINED." ) )
	{
		type_object->m_enum = IfcCostItemTypeEnum::ENUM_USERDEFINED;
	}
	else if( std_iequal( arg, ".NOTDEFINED." ) )
	{
		type_object->m_enum = IfcCostItemTypeEnum::ENUM_NOTDEFINED;
	}
	return type_object;
}