/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4X3/include/IfcDefinitionSelect.h"
#include "ifcpp/IFC4X3/include/IfcGloballyUniqueId.h"
#include "ifcpp/IFC4X3/include/IfcLabel.h"
#include "ifcpp/IFC4X3/include/IfcMaterialDefinition.h"
#include "ifcpp/IFC4X3/include/IfcMaterialSelect.h"
#include "ifcpp/IFC4X3/include/IfcMaterialUsageDefinition.h"
#include "ifcpp/IFC4X3/include/IfcOwnerHistory.h"
#include "ifcpp/IFC4X3/include/IfcRelAssociatesMaterial.h"
#include "ifcpp/IFC4X3/include/IfcText.h"

// ENTITY IfcRelAssociatesMaterial 
IFC4X3::IfcRelAssociatesMaterial::IfcRelAssociatesMaterial( int tag ) { m_tag = tag; }
void IFC4X3::IfcRelAssociatesMaterial::getStepLine( std::stringstream& stream, size_t precision ) const
{
	stream << "#" << m_tag << "=IFCRELASSOCIATESMATERIAL" << "(";
	if( m_GlobalId ) { m_GlobalId->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->m_tag; } else { stream << "$"; }
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream, false, precision ); } else { stream << "$"; }
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
			type_object->getStepParameter( stream, true, precision );
		}
		else
		{
			stream << "$";
		}
	}
	stream << ")";
	stream << ",";
	if( m_RelatingMaterial ) { m_RelatingMaterial->getStepParameter( stream, true, precision ); } else { stream << "$" ; }
	stream << ");";
}
void IFC4X3::IfcRelAssociatesMaterial::getStepParameter( std::stringstream& stream, bool /*is_select_type*/, size_t /*precision*/ ) const { stream << "#" << m_tag; }
void IFC4X3::IfcRelAssociatesMaterial::readStepArguments( const std::vector<std::string>& args, const BuildingModelMapType<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream, std::unordered_set<int>& entityIdNotFound )
{
	const size_t num_args = args.size();
	if( num_args > 0 ){m_GlobalId = IfcGloballyUniqueId::createObjectFromSTEP( args[0], map, errorStream, entityIdNotFound );}
	if( num_args > 1 ){readEntityReference( args[1], m_OwnerHistory, map, errorStream, entityIdNotFound );}
	if( num_args > 2 ){m_Name = IfcLabel::createObjectFromSTEP( args[2], map, errorStream, entityIdNotFound );}
	if( num_args > 3 ){m_Description = IfcText::createObjectFromSTEP( args[3], map, errorStream, entityIdNotFound );}
	if( num_args > 4 ){readSelectList( args[4], m_RelatedObjects, "IFCDEFINITIONSELECT", map, errorStream, entityIdNotFound );}
	if( num_args > 5 ){m_RelatingMaterial = IfcMaterialSelect::createObjectFromSTEP( args[5], map, errorStream, entityIdNotFound );}
	if( num_args != 6 ){ errorStream << "Wrong parameter count for entity IfcRelAssociatesMaterial, expecting 6, having " << num_args << ". Entity ID: " << m_tag << std::endl; }
}
void IFC4X3::IfcRelAssociatesMaterial::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const
{
	IFC4X3::IfcRelAssociates::getAttributes( vec_attributes );
	vec_attributes.emplace_back( std::make_pair( "RelatingMaterial", m_RelatingMaterial ) );
}
void IFC4X3::IfcRelAssociatesMaterial::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse ) const
{
	IFC4X3::IfcRelAssociates::getAttributesInverse( vec_attributes_inverse );
}
void IFC4X3::IfcRelAssociatesMaterial::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcRelAssociates::setInverseCounterparts( ptr_self_entity );
	shared_ptr<IfcRelAssociatesMaterial> ptr_self = dynamic_pointer_cast<IfcRelAssociatesMaterial>( ptr_self_entity );
	if( !ptr_self ) { throw BuildingException( "IfcRelAssociatesMaterial::setInverseCounterparts: type mismatch" ); }
	shared_ptr<IfcMaterialDefinition>  RelatingMaterial_IfcMaterialDefinition = dynamic_pointer_cast<IfcMaterialDefinition>( m_RelatingMaterial );
	if( RelatingMaterial_IfcMaterialDefinition )
	{
		RelatingMaterial_IfcMaterialDefinition->m_AssociatedTo_inverse.emplace_back( ptr_self );
	}
	shared_ptr<IfcMaterialUsageDefinition>  RelatingMaterial_IfcMaterialUsageDefinition = dynamic_pointer_cast<IfcMaterialUsageDefinition>( m_RelatingMaterial );
	if( RelatingMaterial_IfcMaterialUsageDefinition )
	{
		RelatingMaterial_IfcMaterialUsageDefinition->m_AssociatedTo_inverse.emplace_back( ptr_self );
	}
}
void IFC4X3::IfcRelAssociatesMaterial::unlinkFromInverseCounterparts()
{
	IfcRelAssociates::unlinkFromInverseCounterparts();
	shared_ptr<IfcMaterialDefinition>  RelatingMaterial_IfcMaterialDefinition = dynamic_pointer_cast<IfcMaterialDefinition>( m_RelatingMaterial );
	if( RelatingMaterial_IfcMaterialDefinition )
	{
		std::vector<weak_ptr<IfcRelAssociatesMaterial> >& AssociatedTo_inverse = RelatingMaterial_IfcMaterialDefinition->m_AssociatedTo_inverse;
		for( auto it_AssociatedTo_inverse = AssociatedTo_inverse.begin(); it_AssociatedTo_inverse != AssociatedTo_inverse.end(); )
		{
			weak_ptr<IfcRelAssociatesMaterial> self_candidate_weak = *it_AssociatedTo_inverse;
			if( self_candidate_weak.expired() )
			{
				++it_AssociatedTo_inverse;
				continue;
			}
			shared_ptr<IfcRelAssociatesMaterial> self_candidate( *it_AssociatedTo_inverse );
			if( self_candidate.get() == this )
			{
				it_AssociatedTo_inverse= AssociatedTo_inverse.erase( it_AssociatedTo_inverse );
			}
			else
			{
				++it_AssociatedTo_inverse;
			}
		}
	}
	shared_ptr<IfcMaterialUsageDefinition>  RelatingMaterial_IfcMaterialUsageDefinition = dynamic_pointer_cast<IfcMaterialUsageDefinition>( m_RelatingMaterial );
	if( RelatingMaterial_IfcMaterialUsageDefinition )
	{
		std::vector<weak_ptr<IfcRelAssociatesMaterial> >& AssociatedTo_inverse = RelatingMaterial_IfcMaterialUsageDefinition->m_AssociatedTo_inverse;
		for( auto it_AssociatedTo_inverse = AssociatedTo_inverse.begin(); it_AssociatedTo_inverse != AssociatedTo_inverse.end(); )
		{
			weak_ptr<IfcRelAssociatesMaterial> self_candidate_weak = *it_AssociatedTo_inverse;
			if( self_candidate_weak.expired() )
			{
				++it_AssociatedTo_inverse;
				continue;
			}
			shared_ptr<IfcRelAssociatesMaterial> self_candidate( *it_AssociatedTo_inverse );
			if( self_candidate.get() == this )
			{
				it_AssociatedTo_inverse= AssociatedTo_inverse.erase( it_AssociatedTo_inverse );
			}
			else
			{
				++it_AssociatedTo_inverse;
			}
		}
	}
}
