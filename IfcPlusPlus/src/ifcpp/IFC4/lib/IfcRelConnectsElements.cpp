/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4/include/IfcConnectionGeometry.h"
#include "ifcpp/IFC4/include/IfcElement.h"
#include "ifcpp/IFC4/include/IfcGloballyUniqueId.h"
#include "ifcpp/IFC4/include/IfcLabel.h"
#include "ifcpp/IFC4/include/IfcOwnerHistory.h"
#include "ifcpp/IFC4/include/IfcRelConnectsElements.h"
#include "ifcpp/IFC4/include/IfcText.h"

// ENTITY IfcRelConnectsElements 
IfcRelConnectsElements::IfcRelConnectsElements() {}
IfcRelConnectsElements::IfcRelConnectsElements( int id ) { m_entity_id = id; }
IfcRelConnectsElements::~IfcRelConnectsElements() {}
shared_ptr<BuildingObject> IfcRelConnectsElements::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcRelConnectsElements> copy_self( new IfcRelConnectsElements() );
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
	if( m_ConnectionGeometry ) { copy_self->m_ConnectionGeometry = dynamic_pointer_cast<IfcConnectionGeometry>( m_ConnectionGeometry->getDeepCopy(options) ); }
	if( m_RelatingElement ) { copy_self->m_RelatingElement = dynamic_pointer_cast<IfcElement>( m_RelatingElement->getDeepCopy(options) ); }
	if( m_RelatedElement ) { copy_self->m_RelatedElement = dynamic_pointer_cast<IfcElement>( m_RelatedElement->getDeepCopy(options) ); }
	return copy_self;
}
void IfcRelConnectsElements::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_entity_id << "= IFCRELCONNECTSELEMENTS" << "(";
	if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->m_entity_id; } else { stream << "*"; }
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_ConnectionGeometry ) { stream << "#" << m_ConnectionGeometry->m_entity_id; } else { stream << "$"; }
	stream << ",";
	if( m_RelatingElement ) { stream << "#" << m_RelatingElement->m_entity_id; } else { stream << "$"; }
	stream << ",";
	if( m_RelatedElement ) { stream << "#" << m_RelatedElement->m_entity_id; } else { stream << "$"; }
	stream << ");";
}
void IfcRelConnectsElements::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_entity_id; }
const std::wstring IfcRelConnectsElements::toString() const { return L"IfcRelConnectsElements"; }
void IfcRelConnectsElements::readStepArguments( const std::vector<std::wstring>& args, const std::map<int,shared_ptr<BuildingEntity> >& map )
{
	const size_t num_args = args.size();
	if( num_args != 7 ){ std::stringstream err; err << "Wrong parameter count for entity IfcRelConnectsElements, expecting 7, having " << num_args << ". Entity ID: " << m_entity_id << std::endl; throw BuildingException( err.str().c_str() ); }
	m_GlobalId = IfcGloballyUniqueId::createObjectFromSTEP( args[0], map );
	readEntityReference( args[1], m_OwnerHistory, map );
	m_Name = IfcLabel::createObjectFromSTEP( args[2], map );
	m_Description = IfcText::createObjectFromSTEP( args[3], map );
	readEntityReference( args[4], m_ConnectionGeometry, map );
	readEntityReference( args[5], m_RelatingElement, map );
	readEntityReference( args[6], m_RelatedElement, map );
}
void IfcRelConnectsElements::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes )
{
	IfcRelConnects::getAttributes( vec_attributes );
	vec_attributes.push_back( std::make_pair( "ConnectionGeometry", m_ConnectionGeometry ) );
	vec_attributes.push_back( std::make_pair( "RelatingElement", m_RelatingElement ) );
	vec_attributes.push_back( std::make_pair( "RelatedElement", m_RelatedElement ) );
}
void IfcRelConnectsElements::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse )
{
	IfcRelConnects::getAttributesInverse( vec_attributes_inverse );
}
void IfcRelConnectsElements::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcRelConnects::setInverseCounterparts( ptr_self_entity );
	shared_ptr<IfcRelConnectsElements> ptr_self = dynamic_pointer_cast<IfcRelConnectsElements>( ptr_self_entity );
	if( !ptr_self ) { throw BuildingException( "IfcRelConnectsElements::setInverseCounterparts: type mismatch" ); }
	if( m_RelatedElement )
	{
		m_RelatedElement->m_ConnectedFrom_inverse.push_back( ptr_self );
	}
	if( m_RelatingElement )
	{
		m_RelatingElement->m_ConnectedTo_inverse.push_back( ptr_self );
	}
}
void IfcRelConnectsElements::unlinkFromInverseCounterparts()
{
	IfcRelConnects::unlinkFromInverseCounterparts();
	if( m_RelatedElement )
	{
		std::vector<weak_ptr<IfcRelConnectsElements> >& ConnectedFrom_inverse = m_RelatedElement->m_ConnectedFrom_inverse;
		for( auto it_ConnectedFrom_inverse = ConnectedFrom_inverse.begin(); it_ConnectedFrom_inverse != ConnectedFrom_inverse.end(); )
		{
			weak_ptr<IfcRelConnectsElements> self_candidate_weak = *it_ConnectedFrom_inverse;
			if( self_candidate_weak.expired() )
			{
				++it_ConnectedFrom_inverse;
				continue;
			}
			shared_ptr<IfcRelConnectsElements> self_candidate( *it_ConnectedFrom_inverse );
			if( self_candidate.get() == this )
			{
				it_ConnectedFrom_inverse= ConnectedFrom_inverse.erase( it_ConnectedFrom_inverse );
			}
			else
			{
				++it_ConnectedFrom_inverse;
			}
		}
	}
	if( m_RelatingElement )
	{
		std::vector<weak_ptr<IfcRelConnectsElements> >& ConnectedTo_inverse = m_RelatingElement->m_ConnectedTo_inverse;
		for( auto it_ConnectedTo_inverse = ConnectedTo_inverse.begin(); it_ConnectedTo_inverse != ConnectedTo_inverse.end(); )
		{
			weak_ptr<IfcRelConnectsElements> self_candidate_weak = *it_ConnectedTo_inverse;
			if( self_candidate_weak.expired() )
			{
				++it_ConnectedTo_inverse;
				continue;
			}
			shared_ptr<IfcRelConnectsElements> self_candidate( *it_ConnectedTo_inverse );
			if( self_candidate.get() == this )
			{
				it_ConnectedTo_inverse= ConnectedTo_inverse.erase( it_ConnectedTo_inverse );
			}
			else
			{
				++it_ConnectedTo_inverse;
			}
		}
	}
}
