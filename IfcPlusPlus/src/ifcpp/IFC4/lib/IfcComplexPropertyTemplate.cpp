/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4/include/IfcComplexPropertyTemplate.h"
#include "ifcpp/IFC4/include/IfcComplexPropertyTemplateTypeEnum.h"
#include "ifcpp/IFC4/include/IfcGloballyUniqueId.h"
#include "ifcpp/IFC4/include/IfcLabel.h"
#include "ifcpp/IFC4/include/IfcOwnerHistory.h"
#include "ifcpp/IFC4/include/IfcPropertySetTemplate.h"
#include "ifcpp/IFC4/include/IfcPropertyTemplate.h"
#include "ifcpp/IFC4/include/IfcRelAssociates.h"
#include "ifcpp/IFC4/include/IfcRelDeclares.h"
#include "ifcpp/IFC4/include/IfcText.h"

// ENTITY IfcComplexPropertyTemplate 
IfcComplexPropertyTemplate::IfcComplexPropertyTemplate() {}
IfcComplexPropertyTemplate::IfcComplexPropertyTemplate( int id ) { m_entity_id = id; }
IfcComplexPropertyTemplate::~IfcComplexPropertyTemplate() {}
shared_ptr<BuildingObject> IfcComplexPropertyTemplate::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcComplexPropertyTemplate> copy_self( new IfcComplexPropertyTemplate() );
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
	if( m_UsageName ) { copy_self->m_UsageName = dynamic_pointer_cast<IfcLabel>( m_UsageName->getDeepCopy(options) ); }
	if( m_TemplateType ) { copy_self->m_TemplateType = dynamic_pointer_cast<IfcComplexPropertyTemplateTypeEnum>( m_TemplateType->getDeepCopy(options) ); }
	for( size_t ii=0; ii<m_HasPropertyTemplates.size(); ++ii )
	{
		auto item_ii = m_HasPropertyTemplates[ii];
		if( item_ii )
		{
			copy_self->m_HasPropertyTemplates.push_back( dynamic_pointer_cast<IfcPropertyTemplate>(item_ii->getDeepCopy(options) ) );
		}
	}
	return copy_self;
}
void IfcComplexPropertyTemplate::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_entity_id << "= IFCCOMPLEXPROPERTYTEMPLATE" << "(";
	if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->m_entity_id; } else { stream << "*"; }
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_UsageName ) { m_UsageName->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_TemplateType ) { m_TemplateType->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	writeEntityList( stream, m_HasPropertyTemplates );
	stream << ");";
}
void IfcComplexPropertyTemplate::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_entity_id; }
const std::wstring IfcComplexPropertyTemplate::toString() const { return L"IfcComplexPropertyTemplate"; }
void IfcComplexPropertyTemplate::readStepArguments( const std::vector<std::wstring>& args, const std::map<int,shared_ptr<BuildingEntity> >& map )
{
	const size_t num_args = args.size();
	if( num_args != 7 ){ std::stringstream err; err << "Wrong parameter count for entity IfcComplexPropertyTemplate, expecting 7, having " << num_args << ". Entity ID: " << m_entity_id << std::endl; throw BuildingException( err.str().c_str() ); }
	m_GlobalId = IfcGloballyUniqueId::createObjectFromSTEP( args[0], map );
	readEntityReference( args[1], m_OwnerHistory, map );
	m_Name = IfcLabel::createObjectFromSTEP( args[2], map );
	m_Description = IfcText::createObjectFromSTEP( args[3], map );
	m_UsageName = IfcLabel::createObjectFromSTEP( args[4], map );
	m_TemplateType = IfcComplexPropertyTemplateTypeEnum::createObjectFromSTEP( args[5], map );
	readEntityReferenceList( args[6], m_HasPropertyTemplates, map );
}
void IfcComplexPropertyTemplate::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes )
{
	IfcPropertyTemplate::getAttributes( vec_attributes );
	vec_attributes.push_back( std::make_pair( "UsageName", m_UsageName ) );
	vec_attributes.push_back( std::make_pair( "TemplateType", m_TemplateType ) );
	if( m_HasPropertyTemplates.size() > 0 )
	{
		shared_ptr<AttributeObjectVector> HasPropertyTemplates_vec_object( new AttributeObjectVector() );
		std::copy( m_HasPropertyTemplates.begin(), m_HasPropertyTemplates.end(), std::back_inserter( HasPropertyTemplates_vec_object->m_vec ) );
		vec_attributes.push_back( std::make_pair( "HasPropertyTemplates", HasPropertyTemplates_vec_object ) );
	}
}
void IfcComplexPropertyTemplate::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse )
{
	IfcPropertyTemplate::getAttributesInverse( vec_attributes_inverse );
}
void IfcComplexPropertyTemplate::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcPropertyTemplate::setInverseCounterparts( ptr_self_entity );
	shared_ptr<IfcComplexPropertyTemplate> ptr_self = dynamic_pointer_cast<IfcComplexPropertyTemplate>( ptr_self_entity );
	if( !ptr_self ) { throw BuildingException( "IfcComplexPropertyTemplate::setInverseCounterparts: type mismatch" ); }
	for( size_t i=0; i<m_HasPropertyTemplates.size(); ++i )
	{
		if( m_HasPropertyTemplates[i] )
		{
			m_HasPropertyTemplates[i]->m_PartOfComplexTemplate_inverse.push_back( ptr_self );
		}
	}
}
void IfcComplexPropertyTemplate::unlinkFromInverseCounterparts()
{
	IfcPropertyTemplate::unlinkFromInverseCounterparts();
	for( size_t i=0; i<m_HasPropertyTemplates.size(); ++i )
	{
		if( m_HasPropertyTemplates[i] )
		{
			std::vector<weak_ptr<IfcComplexPropertyTemplate> >& PartOfComplexTemplate_inverse = m_HasPropertyTemplates[i]->m_PartOfComplexTemplate_inverse;
			for( auto it_PartOfComplexTemplate_inverse = PartOfComplexTemplate_inverse.begin(); it_PartOfComplexTemplate_inverse != PartOfComplexTemplate_inverse.end(); )
			{
				weak_ptr<IfcComplexPropertyTemplate> self_candidate_weak = *it_PartOfComplexTemplate_inverse;
				if( self_candidate_weak.expired() )
				{
					++it_PartOfComplexTemplate_inverse;
					continue;
				}
				shared_ptr<IfcComplexPropertyTemplate> self_candidate( *it_PartOfComplexTemplate_inverse );
				if( self_candidate.get() == this )
				{
					it_PartOfComplexTemplate_inverse= PartOfComplexTemplate_inverse.erase( it_PartOfComplexTemplate_inverse );
				}
				else
				{
					++it_PartOfComplexTemplate_inverse;
				}
			}
		}
	}
}
