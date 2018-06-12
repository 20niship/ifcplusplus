/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4/include/IfcElement.h"
#include "ifcpp/IFC4/include/IfcGloballyUniqueId.h"
#include "ifcpp/IFC4/include/IfcLabel.h"
#include "ifcpp/IFC4/include/IfcOpeningElement.h"
#include "ifcpp/IFC4/include/IfcOwnerHistory.h"
#include "ifcpp/IFC4/include/IfcRelFillsElement.h"
#include "ifcpp/IFC4/include/IfcText.h"

// ENTITY IfcRelFillsElement 
IfcRelFillsElement::IfcRelFillsElement() {}
IfcRelFillsElement::IfcRelFillsElement( int id ) { m_entity_id = id; }
IfcRelFillsElement::~IfcRelFillsElement() {}
shared_ptr<BuildingObject> IfcRelFillsElement::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcRelFillsElement> copy_self( new IfcRelFillsElement() );
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
	if( m_RelatingOpeningElement ) { copy_self->m_RelatingOpeningElement = dynamic_pointer_cast<IfcOpeningElement>( m_RelatingOpeningElement->getDeepCopy(options) ); }
	if( m_RelatedBuildingElement ) { copy_self->m_RelatedBuildingElement = dynamic_pointer_cast<IfcElement>( m_RelatedBuildingElement->getDeepCopy(options) ); }
	return copy_self;
}
void IfcRelFillsElement::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_entity_id << "= IFCRELFILLSELEMENT" << "(";
	if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->m_entity_id; } else { stream << "*"; }
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_RelatingOpeningElement ) { stream << "#" << m_RelatingOpeningElement->m_entity_id; } else { stream << "$"; }
	stream << ",";
	if( m_RelatedBuildingElement ) { stream << "#" << m_RelatedBuildingElement->m_entity_id; } else { stream << "$"; }
	stream << ");";
}
void IfcRelFillsElement::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_entity_id; }
const std::wstring IfcRelFillsElement::toString() const { return L"IfcRelFillsElement"; }
void IfcRelFillsElement::readStepArguments( const std::vector<std::wstring>& args, const std::map<int,shared_ptr<BuildingEntity> >& map )
{
	const size_t num_args = args.size();
	if( num_args != 6 ){ std::stringstream err; err << "Wrong parameter count for entity IfcRelFillsElement, expecting 6, having " << num_args << ". Entity ID: " << m_entity_id << std::endl; throw BuildingException( err.str().c_str() ); }
	m_GlobalId = IfcGloballyUniqueId::createObjectFromSTEP( args[0], map );
	readEntityReference( args[1], m_OwnerHistory, map );
	m_Name = IfcLabel::createObjectFromSTEP( args[2], map );
	m_Description = IfcText::createObjectFromSTEP( args[3], map );
	readEntityReference( args[4], m_RelatingOpeningElement, map );
	readEntityReference( args[5], m_RelatedBuildingElement, map );
}
void IfcRelFillsElement::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes )
{
	IfcRelConnects::getAttributes( vec_attributes );
	vec_attributes.push_back( std::make_pair( "RelatingOpeningElement", m_RelatingOpeningElement ) );
	vec_attributes.push_back( std::make_pair( "RelatedBuildingElement", m_RelatedBuildingElement ) );
}
void IfcRelFillsElement::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse )
{
	IfcRelConnects::getAttributesInverse( vec_attributes_inverse );
}
void IfcRelFillsElement::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcRelConnects::setInverseCounterparts( ptr_self_entity );
	shared_ptr<IfcRelFillsElement> ptr_self = dynamic_pointer_cast<IfcRelFillsElement>( ptr_self_entity );
	if( !ptr_self ) { throw BuildingException( "IfcRelFillsElement::setInverseCounterparts: type mismatch" ); }
	if( m_RelatedBuildingElement )
	{
		m_RelatedBuildingElement->m_FillsVoids_inverse.push_back( ptr_self );
	}
	if( m_RelatingOpeningElement )
	{
		m_RelatingOpeningElement->m_HasFillings_inverse.push_back( ptr_self );
	}
}
void IfcRelFillsElement::unlinkFromInverseCounterparts()
{
	IfcRelConnects::unlinkFromInverseCounterparts();
	if( m_RelatedBuildingElement )
	{
		std::vector<weak_ptr<IfcRelFillsElement> >& FillsVoids_inverse = m_RelatedBuildingElement->m_FillsVoids_inverse;
		for( auto it_FillsVoids_inverse = FillsVoids_inverse.begin(); it_FillsVoids_inverse != FillsVoids_inverse.end(); )
		{
			weak_ptr<IfcRelFillsElement> self_candidate_weak = *it_FillsVoids_inverse;
			if( self_candidate_weak.expired() )
			{
				++it_FillsVoids_inverse;
				continue;
			}
			shared_ptr<IfcRelFillsElement> self_candidate( *it_FillsVoids_inverse );
			if( self_candidate.get() == this )
			{
				it_FillsVoids_inverse= FillsVoids_inverse.erase( it_FillsVoids_inverse );
			}
			else
			{
				++it_FillsVoids_inverse;
			}
		}
	}
	if( m_RelatingOpeningElement )
	{
		std::vector<weak_ptr<IfcRelFillsElement> >& HasFillings_inverse = m_RelatingOpeningElement->m_HasFillings_inverse;
		for( auto it_HasFillings_inverse = HasFillings_inverse.begin(); it_HasFillings_inverse != HasFillings_inverse.end(); )
		{
			weak_ptr<IfcRelFillsElement> self_candidate_weak = *it_HasFillings_inverse;
			if( self_candidate_weak.expired() )
			{
				++it_HasFillings_inverse;
				continue;
			}
			shared_ptr<IfcRelFillsElement> self_candidate( *it_HasFillings_inverse );
			if( self_candidate.get() == this )
			{
				it_HasFillings_inverse= HasFillings_inverse.erase( it_HasFillings_inverse );
			}
			else
			{
				++it_HasFillings_inverse;
			}
		}
	}
}
