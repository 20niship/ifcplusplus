/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4/include/IfcDefinitionSelect.h"
#include "ifcpp/IFC4/include/IfcGloballyUniqueId.h"
#include "ifcpp/IFC4/include/IfcLabel.h"
#include "ifcpp/IFC4/include/IfcObjectDefinition.h"
#include "ifcpp/IFC4/include/IfcOwnerHistory.h"
#include "ifcpp/IFC4/include/IfcPropertyDefinition.h"
#include "ifcpp/IFC4/include/IfcRelAssociates.h"
#include "ifcpp/IFC4/include/IfcText.h"

// ENTITY IfcRelAssociates 
IfcRelAssociates::IfcRelAssociates() {}
IfcRelAssociates::IfcRelAssociates( int id ) { m_entity_id = id; }
IfcRelAssociates::~IfcRelAssociates() {}
shared_ptr<BuildingObject> IfcRelAssociates::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcRelAssociates> copy_self( new IfcRelAssociates() );
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
	for( size_t ii=0; ii<m_RelatedObjects.size(); ++ii )
	{
		auto item_ii = m_RelatedObjects[ii];
		if( item_ii )
		{
			copy_self->m_RelatedObjects.push_back( dynamic_pointer_cast<IfcDefinitionSelect>(item_ii->getDeepCopy(options) ) );
		}
	}
	return copy_self;
}
void IfcRelAssociates::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_entity_id << "= IFCRELASSOCIATES" << "(";
	if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->m_entity_id; } else { stream << "*"; }
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	stream << "(";
	for( size_t ii = 0; ii < m_RelatedObjects.size(); ++ii )
	{
		if( ii > 0 )
		{
			stream << ",";
		}
		const shared_ptr<IfcDefinitionSelect>& type_object = m_RelatedObjects[ii];
		if( type_object )
		{
			type_object->getStepParameter( stream, true );
		}
		else
		{
			stream << "$";
		}
	}
	stream << ")";
	stream << ");";
}
void IfcRelAssociates::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_entity_id; }
const std::wstring IfcRelAssociates::toString() const { return L"IfcRelAssociates"; }
void IfcRelAssociates::readStepArguments( const std::vector<std::wstring>& args, const std::map<int,shared_ptr<BuildingEntity> >& map )
{
	const size_t num_args = args.size();
	if( num_args != 5 ){ std::stringstream err; err << "Wrong parameter count for entity IfcRelAssociates, expecting 5, having " << num_args << ". Entity ID: " << m_entity_id << std::endl; throw BuildingException( err.str().c_str() ); }
	m_GlobalId = IfcGloballyUniqueId::createObjectFromSTEP( args[0], map );
	readEntityReference( args[1], m_OwnerHistory, map );
	m_Name = IfcLabel::createObjectFromSTEP( args[2], map );
	m_Description = IfcText::createObjectFromSTEP( args[3], map );
	readSelectList( args[4], m_RelatedObjects, map );
}
void IfcRelAssociates::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes )
{
	IfcRelationship::getAttributes( vec_attributes );
	if( m_RelatedObjects.size() > 0 )
	{
		shared_ptr<AttributeObjectVector> RelatedObjects_vec_object( new AttributeObjectVector() );
		std::copy( m_RelatedObjects.begin(), m_RelatedObjects.end(), std::back_inserter( RelatedObjects_vec_object->m_vec ) );
		vec_attributes.push_back( std::make_pair( "RelatedObjects", RelatedObjects_vec_object ) );
	}
}
void IfcRelAssociates::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse )
{
	IfcRelationship::getAttributesInverse( vec_attributes_inverse );
}
void IfcRelAssociates::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcRelationship::setInverseCounterparts( ptr_self_entity );
	shared_ptr<IfcRelAssociates> ptr_self = dynamic_pointer_cast<IfcRelAssociates>( ptr_self_entity );
	if( !ptr_self ) { throw BuildingException( "IfcRelAssociates::setInverseCounterparts: type mismatch" ); }
	for( size_t i=0; i<m_RelatedObjects.size(); ++i )
	{
		shared_ptr<IfcObjectDefinition>  RelatedObjects_IfcObjectDefinition = dynamic_pointer_cast<IfcObjectDefinition>( m_RelatedObjects[i] );
		if( RelatedObjects_IfcObjectDefinition )
		{
			RelatedObjects_IfcObjectDefinition->m_HasAssociations_inverse.push_back( ptr_self );
		}
		shared_ptr<IfcPropertyDefinition>  RelatedObjects_IfcPropertyDefinition = dynamic_pointer_cast<IfcPropertyDefinition>( m_RelatedObjects[i] );
		if( RelatedObjects_IfcPropertyDefinition )
		{
			RelatedObjects_IfcPropertyDefinition->m_HasAssociations_inverse.push_back( ptr_self );
		}
	}
}
void IfcRelAssociates::unlinkFromInverseCounterparts()
{
	IfcRelationship::unlinkFromInverseCounterparts();
	for( size_t i=0; i<m_RelatedObjects.size(); ++i )
	{
		shared_ptr<IfcObjectDefinition>  RelatedObjects_IfcObjectDefinition = dynamic_pointer_cast<IfcObjectDefinition>( m_RelatedObjects[i] );
		if( RelatedObjects_IfcObjectDefinition )
		{
			std::vector<weak_ptr<IfcRelAssociates> >& HasAssociations_inverse = RelatedObjects_IfcObjectDefinition->m_HasAssociations_inverse;
			for( auto it_HasAssociations_inverse = HasAssociations_inverse.begin(); it_HasAssociations_inverse != HasAssociations_inverse.end(); )
			{
				weak_ptr<IfcRelAssociates> self_candidate_weak = *it_HasAssociations_inverse;
				if( self_candidate_weak.expired() )
				{
					++it_HasAssociations_inverse;
					continue;
				}
				shared_ptr<IfcRelAssociates> self_candidate( *it_HasAssociations_inverse );
				if( self_candidate.get() == this )
				{
					it_HasAssociations_inverse= HasAssociations_inverse.erase( it_HasAssociations_inverse );
				}
				else
				{
					++it_HasAssociations_inverse;
				}
			}
		}
		shared_ptr<IfcPropertyDefinition>  RelatedObjects_IfcPropertyDefinition = dynamic_pointer_cast<IfcPropertyDefinition>( m_RelatedObjects[i] );
		if( RelatedObjects_IfcPropertyDefinition )
		{
			std::vector<weak_ptr<IfcRelAssociates> >& HasAssociations_inverse = RelatedObjects_IfcPropertyDefinition->m_HasAssociations_inverse;
			for( auto it_HasAssociations_inverse = HasAssociations_inverse.begin(); it_HasAssociations_inverse != HasAssociations_inverse.end(); )
			{
				weak_ptr<IfcRelAssociates> self_candidate_weak = *it_HasAssociations_inverse;
				if( self_candidate_weak.expired() )
				{
					++it_HasAssociations_inverse;
					continue;
				}
				shared_ptr<IfcRelAssociates> self_candidate( *it_HasAssociations_inverse );
				if( self_candidate.get() == this )
				{
					it_HasAssociations_inverse= HasAssociations_inverse.erase( it_HasAssociations_inverse );
				}
				else
				{
					++it_HasAssociations_inverse;
				}
			}
		}
	}
}
