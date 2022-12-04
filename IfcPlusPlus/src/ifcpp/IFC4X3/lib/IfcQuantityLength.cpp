/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4X3/include/IfcExternalReferenceRelationship.h"
#include "ifcpp/IFC4X3/include/IfcLabel.h"
#include "ifcpp/IFC4X3/include/IfcLengthMeasure.h"
#include "ifcpp/IFC4X3/include/IfcNamedUnit.h"
#include "ifcpp/IFC4X3/include/IfcPhysicalComplexQuantity.h"
#include "ifcpp/IFC4X3/include/IfcQuantityLength.h"
#include "ifcpp/IFC4X3/include/IfcText.h"

// ENTITY IfcQuantityLength 
IFC4X3::IfcQuantityLength::IfcQuantityLength( int tag ) { m_tag = tag; }
shared_ptr<BuildingObject> IFC4X3::IfcQuantityLength::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcQuantityLength> copy_self( new IfcQuantityLength() );
	if( m_Name ) { copy_self->m_Name = dynamic_pointer_cast<IfcLabel>( m_Name->getDeepCopy(options) ); }
	if( m_Description ) { copy_self->m_Description = dynamic_pointer_cast<IfcText>( m_Description->getDeepCopy(options) ); }
	if( m_Unit ) { copy_self->m_Unit = dynamic_pointer_cast<IfcNamedUnit>( m_Unit->getDeepCopy(options) ); }
	if( m_LengthValue ) { copy_self->m_LengthValue = dynamic_pointer_cast<IfcLengthMeasure>( m_LengthValue->getDeepCopy(options) ); }
	if( m_Formula ) { copy_self->m_Formula = dynamic_pointer_cast<IfcLabel>( m_Formula->getDeepCopy(options) ); }
	return copy_self;
}
void IFC4X3::IfcQuantityLength::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_tag << "= IFCQUANTITYLENGTH" << "(";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_Unit ) { stream << "#" << m_Unit->m_tag; } else { stream << "$"; }
	stream << ",";
	if( m_LengthValue ) { m_LengthValue->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_Formula ) { m_Formula->getStepParameter( stream ); } else { stream << "$"; }
	stream << ");";
}
void IFC4X3::IfcQuantityLength::getStepParameter( std::stringstream& stream, bool /*is_select_type*/ ) const { stream << "#" << m_tag; }
void IFC4X3::IfcQuantityLength::readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	const size_t num_args = args.size();
	if( num_args != 5 ){ std::stringstream err; err << "Wrong parameter count for entity IfcQuantityLength, expecting 5, having " << num_args << ". Entity ID: " << m_tag << std::endl; throw BuildingException( err.str().c_str() ); }
	m_Name = IfcLabel::createObjectFromSTEP( args[0], map, errorStream );
	m_Description = IfcText::createObjectFromSTEP( args[1], map, errorStream );
	readEntityReference( args[2], m_Unit, map, errorStream );
	m_LengthValue = IfcLengthMeasure::createObjectFromSTEP( args[3], map, errorStream );
	m_Formula = IfcLabel::createObjectFromSTEP( args[4], map, errorStream );
}
void IFC4X3::IfcQuantityLength::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const
{
	IFC4X3::IfcPhysicalSimpleQuantity::getAttributes( vec_attributes );
	vec_attributes.emplace_back( std::make_pair( "LengthValue", m_LengthValue ) );
	vec_attributes.emplace_back( std::make_pair( "Formula", m_Formula ) );
}
void IFC4X3::IfcQuantityLength::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse ) const
{
	IFC4X3::IfcPhysicalSimpleQuantity::getAttributesInverse( vec_attributes_inverse );
}
void IFC4X3::IfcQuantityLength::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcPhysicalSimpleQuantity::setInverseCounterparts( ptr_self_entity );
}
void IFC4X3::IfcQuantityLength::unlinkFromInverseCounterparts()
{
	IfcPhysicalSimpleQuantity::unlinkFromInverseCounterparts();
}