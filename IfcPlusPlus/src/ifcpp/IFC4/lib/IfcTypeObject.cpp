/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4/include/IfcGloballyUniqueId.h"
#include "ifcpp/IFC4/include/IfcIdentifier.h"
#include "ifcpp/IFC4/include/IfcLabel.h"
#include "ifcpp/IFC4/include/IfcOwnerHistory.h"
#include "ifcpp/IFC4/include/IfcPropertySetDefinition.h"
#include "ifcpp/IFC4/include/IfcRelAggregates.h"
#include "ifcpp/IFC4/include/IfcRelAssigns.h"
#include "ifcpp/IFC4/include/IfcRelAssociates.h"
#include "ifcpp/IFC4/include/IfcRelDeclares.h"
#include "ifcpp/IFC4/include/IfcRelDefinesByType.h"
#include "ifcpp/IFC4/include/IfcRelNests.h"
#include "ifcpp/IFC4/include/IfcText.h"
#include "ifcpp/IFC4/include/IfcTypeObject.h"

// ENTITY IfcTypeObject 
IfcTypeObject::IfcTypeObject() {}
IfcTypeObject::IfcTypeObject( int id ) { m_entity_id = id; }
IfcTypeObject::~IfcTypeObject() {}
shared_ptr<BuildingObject> IfcTypeObject::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcTypeObject> copy_self( new IfcTypeObject() );
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
	if( m_ApplicableOccurrence ) { copy_self->m_ApplicableOccurrence = dynamic_pointer_cast<IfcIdentifier>( m_ApplicableOccurrence->getDeepCopy(options) ); }
	for( size_t ii=0; ii<m_HasPropertySets.size(); ++ii )
	{
		auto item_ii = m_HasPropertySets[ii];
		if( item_ii )
		{
			copy_self->m_HasPropertySets.push_back( dynamic_pointer_cast<IfcPropertySetDefinition>(item_ii->getDeepCopy(options) ) );
		}
	}
	return copy_self;
}
void IfcTypeObject::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_entity_id << "= IFCTYPEOBJECT" << "(";
	if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->m_entity_id; } else { stream << "*"; }
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_ApplicableOccurrence ) { m_ApplicableOccurrence->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	writeEntityList( stream, m_HasPropertySets );
	stream << ");";
}
void IfcTypeObject::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_entity_id; }
const std::wstring IfcTypeObject::toString() const { return L"IfcTypeObject"; }
void IfcTypeObject::readStepArguments( const std::vector<std::wstring>& args, const std::map<int,shared_ptr<BuildingEntity> >& map )
{
	const size_t num_args = args.size();
	if( num_args != 6 ){ std::stringstream err; err << "Wrong parameter count for entity IfcTypeObject, expecting 6, having " << num_args << ". Entity ID: " << m_entity_id << std::endl; throw BuildingException( err.str().c_str() ); }
	m_GlobalId = IfcGloballyUniqueId::createObjectFromSTEP( args[0], map );
	readEntityReference( args[1], m_OwnerHistory, map );
	m_Name = IfcLabel::createObjectFromSTEP( args[2], map );
	m_Description = IfcText::createObjectFromSTEP( args[3], map );
	m_ApplicableOccurrence = IfcIdentifier::createObjectFromSTEP( args[4], map );
	readEntityReferenceList( args[5], m_HasPropertySets, map );
}
void IfcTypeObject::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes )
{
	IfcObjectDefinition::getAttributes( vec_attributes );
	vec_attributes.push_back( std::make_pair( "ApplicableOccurrence", m_ApplicableOccurrence ) );
	if( m_HasPropertySets.size() > 0 )
	{
		shared_ptr<AttributeObjectVector> HasPropertySets_vec_object( new AttributeObjectVector() );
		std::copy( m_HasPropertySets.begin(), m_HasPropertySets.end(), std::back_inserter( HasPropertySets_vec_object->m_vec ) );
		vec_attributes.push_back( std::make_pair( "HasPropertySets", HasPropertySets_vec_object ) );
	}
}
void IfcTypeObject::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse )
{
	IfcObjectDefinition::getAttributesInverse( vec_attributes_inverse );
	if( m_Types_inverse.size() > 0 )
	{
		shared_ptr<AttributeObjectVector> Types_inverse_vec_obj( new AttributeObjectVector() );
		for( size_t i=0; i<m_Types_inverse.size(); ++i )
		{
			if( !m_Types_inverse[i].expired() )
			{
				Types_inverse_vec_obj->m_vec.push_back( shared_ptr<IfcRelDefinesByType>( m_Types_inverse[i] ) );
			}
		}
		vec_attributes_inverse.push_back( std::make_pair( "Types_inverse", Types_inverse_vec_obj ) );
	}
}
void IfcTypeObject::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcObjectDefinition::setInverseCounterparts( ptr_self_entity );
	shared_ptr<IfcTypeObject> ptr_self = dynamic_pointer_cast<IfcTypeObject>( ptr_self_entity );
	if( !ptr_self ) { throw BuildingException( "IfcTypeObject::setInverseCounterparts: type mismatch" ); }
	for( size_t i=0; i<m_HasPropertySets.size(); ++i )
	{
		if( m_HasPropertySets[i] )
		{
			m_HasPropertySets[i]->m_DefinesType_inverse.push_back( ptr_self );
		}
	}
}
void IfcTypeObject::unlinkFromInverseCounterparts()
{
	IfcObjectDefinition::unlinkFromInverseCounterparts();
	for( size_t i=0; i<m_HasPropertySets.size(); ++i )
	{
		if( m_HasPropertySets[i] )
		{
			std::vector<weak_ptr<IfcTypeObject> >& DefinesType_inverse = m_HasPropertySets[i]->m_DefinesType_inverse;
			for( auto it_DefinesType_inverse = DefinesType_inverse.begin(); it_DefinesType_inverse != DefinesType_inverse.end(); )
			{
				weak_ptr<IfcTypeObject> self_candidate_weak = *it_DefinesType_inverse;
				if( self_candidate_weak.expired() )
				{
					++it_DefinesType_inverse;
					continue;
				}
				shared_ptr<IfcTypeObject> self_candidate( *it_DefinesType_inverse );
				if( self_candidate.get() == this )
				{
					it_DefinesType_inverse= DefinesType_inverse.erase( it_DefinesType_inverse );
				}
				else
				{
					++it_DefinesType_inverse;
				}
			}
		}
	}
}
