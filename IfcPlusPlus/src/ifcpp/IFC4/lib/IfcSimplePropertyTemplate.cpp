/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4/include/IfcComplexPropertyTemplate.h"
#include "ifcpp/IFC4/include/IfcGloballyUniqueId.h"
#include "ifcpp/IFC4/include/IfcLabel.h"
#include "ifcpp/IFC4/include/IfcOwnerHistory.h"
#include "ifcpp/IFC4/include/IfcPropertyEnumeration.h"
#include "ifcpp/IFC4/include/IfcPropertySetTemplate.h"
#include "ifcpp/IFC4/include/IfcRelAssociates.h"
#include "ifcpp/IFC4/include/IfcRelDeclares.h"
#include "ifcpp/IFC4/include/IfcSimplePropertyTemplate.h"
#include "ifcpp/IFC4/include/IfcSimplePropertyTemplateTypeEnum.h"
#include "ifcpp/IFC4/include/IfcStateEnum.h"
#include "ifcpp/IFC4/include/IfcText.h"
#include "ifcpp/IFC4/include/IfcUnit.h"

// ENTITY IfcSimplePropertyTemplate 
IfcSimplePropertyTemplate::IfcSimplePropertyTemplate() {}
IfcSimplePropertyTemplate::IfcSimplePropertyTemplate( int id ) { m_entity_id = id; }
IfcSimplePropertyTemplate::~IfcSimplePropertyTemplate() {}
shared_ptr<BuildingObject> IfcSimplePropertyTemplate::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcSimplePropertyTemplate> copy_self( new IfcSimplePropertyTemplate() );
	if( m_GlobalId )
	{
		if( options.create_new_IfcGloballyUniqueId ) { copy_self->m_GlobalId = shared_ptr<IfcGloballyUniqueId>(new IfcGloballyUniqueId( createBase64Uuid<wchar_t>().data() ) ); }
		else { copy_self->m_GlobalId = dynamic_pointer_cast<IfcGloballyUniqueId>( m_GlobalId->getDeepCopy(options) ); }
	}
	if( m_OwnerHistory )
	{
		if( options.shallow_copy_IfcOwnerHistory ) { copy_self->m_OwnerHistory = m_OwnerHistory; }
		else { copy_self->m_OwnerHistory = dynamic_pointer_cast<IfcOwnerHistory>( m_OwnerHistory->getDeepCopy(options) ); }
	}
	if( m_Name ) { copy_self->m_Name = dynamic_pointer_cast<IfcLabel>( m_Name->getDeepCopy(options) ); }
	if( m_Description ) { copy_self->m_Description = dynamic_pointer_cast<IfcText>( m_Description->getDeepCopy(options) ); }
	if( m_TemplateType ) { copy_self->m_TemplateType = dynamic_pointer_cast<IfcSimplePropertyTemplateTypeEnum>( m_TemplateType->getDeepCopy(options) ); }
	if( m_PrimaryMeasureType ) { copy_self->m_PrimaryMeasureType = dynamic_pointer_cast<IfcLabel>( m_PrimaryMeasureType->getDeepCopy(options) ); }
	if( m_SecondaryMeasureType ) { copy_self->m_SecondaryMeasureType = dynamic_pointer_cast<IfcLabel>( m_SecondaryMeasureType->getDeepCopy(options) ); }
	if( m_Enumerators ) { copy_self->m_Enumerators = dynamic_pointer_cast<IfcPropertyEnumeration>( m_Enumerators->getDeepCopy(options) ); }
	if( m_PrimaryUnit ) { copy_self->m_PrimaryUnit = dynamic_pointer_cast<IfcUnit>( m_PrimaryUnit->getDeepCopy(options) ); }
	if( m_SecondaryUnit ) { copy_self->m_SecondaryUnit = dynamic_pointer_cast<IfcUnit>( m_SecondaryUnit->getDeepCopy(options) ); }
	if( m_Expression ) { copy_self->m_Expression = dynamic_pointer_cast<IfcLabel>( m_Expression->getDeepCopy(options) ); }
	if( m_AccessState ) { copy_self->m_AccessState = dynamic_pointer_cast<IfcStateEnum>( m_AccessState->getDeepCopy(options) ); }
	return copy_self;
}
void IfcSimplePropertyTemplate::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_entity_id << "= IFCSIMPLEPROPERTYTEMPLATE" << "(";
	if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->m_entity_id; } else { stream << "*"; }
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_TemplateType ) { m_TemplateType->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_PrimaryMeasureType ) { m_PrimaryMeasureType->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_SecondaryMeasureType ) { m_SecondaryMeasureType->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_Enumerators ) { stream << "#" << m_Enumerators->m_entity_id; } else { stream << "$"; }
	stream << ",";
	if( m_PrimaryUnit ) { m_PrimaryUnit->getStepParameter( stream, true ); } else { stream << "$" ; }
	stream << ",";
	if( m_SecondaryUnit ) { m_SecondaryUnit->getStepParameter( stream, true ); } else { stream << "$" ; }
	stream << ",";
	if( m_Expression ) { m_Expression->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_AccessState ) { m_AccessState->getStepParameter( stream ); } else { stream << "$"; }
	stream << ");";
}
void IfcSimplePropertyTemplate::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_entity_id; }
const std::wstring IfcSimplePropertyTemplate::toString() const { return L"IfcSimplePropertyTemplate"; }
void IfcSimplePropertyTemplate::readStepArguments( const std::vector<std::wstring>& args, const std::map<int,shared_ptr<BuildingEntity> >& map )
{
	const size_t num_args = args.size();
	if( num_args != 12 ){ std::stringstream err; err << "Wrong parameter count for entity IfcSimplePropertyTemplate, expecting 12, having " << num_args << ". Entity ID: " << m_entity_id << std::endl; throw BuildingException( err.str().c_str() ); }
	m_GlobalId = IfcGloballyUniqueId::createObjectFromSTEP( args[0], map );
	readEntityReference( args[1], m_OwnerHistory, map );
	m_Name = IfcLabel::createObjectFromSTEP( args[2], map );
	m_Description = IfcText::createObjectFromSTEP( args[3], map );
	m_TemplateType = IfcSimplePropertyTemplateTypeEnum::createObjectFromSTEP( args[4], map );
	m_PrimaryMeasureType = IfcLabel::createObjectFromSTEP( args[5], map );
	m_SecondaryMeasureType = IfcLabel::createObjectFromSTEP( args[6], map );
	readEntityReference( args[7], m_Enumerators, map );
	m_PrimaryUnit = IfcUnit::createObjectFromSTEP( args[8], map );
	m_SecondaryUnit = IfcUnit::createObjectFromSTEP( args[9], map );
	m_Expression = IfcLabel::createObjectFromSTEP( args[10], map );
	m_AccessState = IfcStateEnum::createObjectFromSTEP( args[11], map );
}
void IfcSimplePropertyTemplate::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes )
{
	IfcPropertyTemplate::getAttributes( vec_attributes );
	vec_attributes.push_back( std::make_pair( "TemplateType", m_TemplateType ) );
	vec_attributes.push_back( std::make_pair( "PrimaryMeasureType", m_PrimaryMeasureType ) );
	vec_attributes.push_back( std::make_pair( "SecondaryMeasureType", m_SecondaryMeasureType ) );
	vec_attributes.push_back( std::make_pair( "Enumerators", m_Enumerators ) );
	vec_attributes.push_back( std::make_pair( "PrimaryUnit", m_PrimaryUnit ) );
	vec_attributes.push_back( std::make_pair( "SecondaryUnit", m_SecondaryUnit ) );
	vec_attributes.push_back( std::make_pair( "Expression", m_Expression ) );
	vec_attributes.push_back( std::make_pair( "AccessState", m_AccessState ) );
}
void IfcSimplePropertyTemplate::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse )
{
	IfcPropertyTemplate::getAttributesInverse( vec_attributes_inverse );
}
void IfcSimplePropertyTemplate::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcPropertyTemplate::setInverseCounterparts( ptr_self_entity );
}
void IfcSimplePropertyTemplate::unlinkFromInverseCounterparts()
{
	IfcPropertyTemplate::unlinkFromInverseCounterparts();
}
