/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4X3/include/IfcAreaMeasure.h"
#include "ifcpp/IFC4X3/include/IfcForceMeasure.h"
#include "ifcpp/IFC4X3/include/IfcGloballyUniqueId.h"
#include "ifcpp/IFC4X3/include/IfcIdentifier.h"
#include "ifcpp/IFC4X3/include/IfcLabel.h"
#include "ifcpp/IFC4X3/include/IfcNormalisedRatioMeasure.h"
#include "ifcpp/IFC4X3/include/IfcObjectPlacement.h"
#include "ifcpp/IFC4X3/include/IfcOwnerHistory.h"
#include "ifcpp/IFC4X3/include/IfcPositiveLengthMeasure.h"
#include "ifcpp/IFC4X3/include/IfcPressureMeasure.h"
#include "ifcpp/IFC4X3/include/IfcProductRepresentation.h"
#include "ifcpp/IFC4X3/include/IfcRelAdheresToElement.h"
#include "ifcpp/IFC4X3/include/IfcRelAggregates.h"
#include "ifcpp/IFC4X3/include/IfcRelAssigns.h"
#include "ifcpp/IFC4X3/include/IfcRelAssignsToProduct.h"
#include "ifcpp/IFC4X3/include/IfcRelAssociates.h"
#include "ifcpp/IFC4X3/include/IfcRelConnectsElements.h"
#include "ifcpp/IFC4X3/include/IfcRelConnectsWithRealizingElements.h"
#include "ifcpp/IFC4X3/include/IfcRelContainedInSpatialStructure.h"
#include "ifcpp/IFC4X3/include/IfcRelCoversBldgElements.h"
#include "ifcpp/IFC4X3/include/IfcRelDeclares.h"
#include "ifcpp/IFC4X3/include/IfcRelDefinesByObject.h"
#include "ifcpp/IFC4X3/include/IfcRelDefinesByProperties.h"
#include "ifcpp/IFC4X3/include/IfcRelDefinesByType.h"
#include "ifcpp/IFC4X3/include/IfcRelFillsElement.h"
#include "ifcpp/IFC4X3/include/IfcRelInterferesElements.h"
#include "ifcpp/IFC4X3/include/IfcRelNests.h"
#include "ifcpp/IFC4X3/include/IfcRelPositions.h"
#include "ifcpp/IFC4X3/include/IfcRelProjectsElement.h"
#include "ifcpp/IFC4X3/include/IfcRelReferencedInSpatialStructure.h"
#include "ifcpp/IFC4X3/include/IfcRelSpaceBoundary.h"
#include "ifcpp/IFC4X3/include/IfcRelVoidsElement.h"
#include "ifcpp/IFC4X3/include/IfcTendon.h"
#include "ifcpp/IFC4X3/include/IfcTendonTypeEnum.h"
#include "ifcpp/IFC4X3/include/IfcText.h"

// ENTITY IfcTendon 
IFC4X3::IfcTendon::IfcTendon( int tag ) { m_tag = tag; }
void IFC4X3::IfcTendon::getStepLine( std::stringstream& stream, size_t precision ) const
{
	stream << "#" << m_tag << "=IFCTENDON" << "(";
	if( m_GlobalId ) { m_GlobalId->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->m_tag; } else { stream << "$"; }
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_ObjectType ) { m_ObjectType->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_ObjectPlacement ) { stream << "#" << m_ObjectPlacement->m_tag; } else { stream << "$"; }
	stream << ",";
	if( m_Representation ) { stream << "#" << m_Representation->m_tag; } else { stream << "$"; }
	stream << ",";
	if( m_Tag ) { m_Tag->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_SteelGrade ) { m_SteelGrade->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_PredefinedType ) { m_PredefinedType->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_NominalDiameter ) { m_NominalDiameter->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_CrossSectionArea ) { m_CrossSectionArea->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_TensionForce ) { m_TensionForce->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_PreStress ) { m_PreStress->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_FrictionCoefficient ) { m_FrictionCoefficient->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_AnchorageSlip ) { m_AnchorageSlip->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_MinCurvatureRadius ) { m_MinCurvatureRadius->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ");";
}
void IFC4X3::IfcTendon::getStepParameter( std::stringstream& stream, bool /*is_select_type*/, size_t /*precision*/ ) const { stream << "#" << m_tag; }
void IFC4X3::IfcTendon::readStepArguments( const std::vector<std::string>& args, const BuildingModelMapType<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream, std::unordered_set<int>& entityIdNotFound )
{
	const size_t num_args = args.size();
	if( num_args > 0 ){m_GlobalId = IfcGloballyUniqueId::createObjectFromSTEP( args[0], map, errorStream, entityIdNotFound );}
	if( num_args > 1 ){readEntityReference( args[1], m_OwnerHistory, map, errorStream, entityIdNotFound );}
	if( num_args > 2 ){m_Name = IfcLabel::createObjectFromSTEP( args[2], map, errorStream, entityIdNotFound );}
	if( num_args > 3 ){m_Description = IfcText::createObjectFromSTEP( args[3], map, errorStream, entityIdNotFound );}
	if( num_args > 4 ){m_ObjectType = IfcLabel::createObjectFromSTEP( args[4], map, errorStream, entityIdNotFound );}
	if( num_args > 5 ){readEntityReference( args[5], m_ObjectPlacement, map, errorStream, entityIdNotFound );}
	if( num_args > 6 ){readEntityReference( args[6], m_Representation, map, errorStream, entityIdNotFound );}
	if( num_args > 7 ){m_Tag = IfcIdentifier::createObjectFromSTEP( args[7], map, errorStream, entityIdNotFound );}
	if( num_args > 8 ){m_SteelGrade = IfcLabel::createObjectFromSTEP( args[8], map, errorStream, entityIdNotFound );}
	if( num_args > 9 ){m_PredefinedType = IfcTendonTypeEnum::createObjectFromSTEP( args[9], map, errorStream, entityIdNotFound );}
	if( num_args > 10 ){m_NominalDiameter = IfcPositiveLengthMeasure::createObjectFromSTEP( args[10], map, errorStream, entityIdNotFound );}
	if( num_args > 11 ){m_CrossSectionArea = IfcAreaMeasure::createObjectFromSTEP( args[11], map, errorStream, entityIdNotFound );}
	if( num_args > 12 ){m_TensionForce = IfcForceMeasure::createObjectFromSTEP( args[12], map, errorStream, entityIdNotFound );}
	if( num_args > 13 ){m_PreStress = IfcPressureMeasure::createObjectFromSTEP( args[13], map, errorStream, entityIdNotFound );}
	if( num_args > 14 ){m_FrictionCoefficient = IfcNormalisedRatioMeasure::createObjectFromSTEP( args[14], map, errorStream, entityIdNotFound );}
	if( num_args > 15 ){m_AnchorageSlip = IfcPositiveLengthMeasure::createObjectFromSTEP( args[15], map, errorStream, entityIdNotFound );}
	if( num_args > 16 ){m_MinCurvatureRadius = IfcPositiveLengthMeasure::createObjectFromSTEP( args[16], map, errorStream, entityIdNotFound );}
	if( num_args != 17 ){ errorStream << "Wrong parameter count for entity IfcTendon, expecting 17, having " << num_args << ". Entity ID: " << m_tag << std::endl; }
}
void IFC4X3::IfcTendon::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const
{
	IFC4X3::IfcReinforcingElement::getAttributes( vec_attributes );
	vec_attributes.emplace_back( std::make_pair( "PredefinedType", m_PredefinedType ) );
	vec_attributes.emplace_back( std::make_pair( "NominalDiameter", m_NominalDiameter ) );
	vec_attributes.emplace_back( std::make_pair( "CrossSectionArea", m_CrossSectionArea ) );
	vec_attributes.emplace_back( std::make_pair( "TensionForce", m_TensionForce ) );
	vec_attributes.emplace_back( std::make_pair( "PreStress", m_PreStress ) );
	vec_attributes.emplace_back( std::make_pair( "FrictionCoefficient", m_FrictionCoefficient ) );
	vec_attributes.emplace_back( std::make_pair( "AnchorageSlip", m_AnchorageSlip ) );
	vec_attributes.emplace_back( std::make_pair( "MinCurvatureRadius", m_MinCurvatureRadius ) );
}
void IFC4X3::IfcTendon::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse ) const
{
	IFC4X3::IfcReinforcingElement::getAttributesInverse( vec_attributes_inverse );
}
void IFC4X3::IfcTendon::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcReinforcingElement::setInverseCounterparts( ptr_self_entity );
}
void IFC4X3::IfcTendon::unlinkFromInverseCounterparts()
{
	IfcReinforcingElement::unlinkFromInverseCounterparts();
}
