/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4X3/include/IfcBooleanClippingResult.h"
#include "ifcpp/IFC4X3/include/IfcBooleanOperand.h"
#include "ifcpp/IFC4X3/include/IfcBooleanOperator.h"
#include "ifcpp/IFC4X3/include/IfcPresentationLayerAssignment.h"
#include "ifcpp/IFC4X3/include/IfcStyledItem.h"

// ENTITY IfcBooleanClippingResult 
IFC4X3::IfcBooleanClippingResult::IfcBooleanClippingResult( int tag ) { m_tag = tag; }
shared_ptr<BuildingObject> IFC4X3::IfcBooleanClippingResult::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcBooleanClippingResult> copy_self( new IfcBooleanClippingResult() );
	if( m_Operator ) { copy_self->m_Operator = dynamic_pointer_cast<IfcBooleanOperator>( m_Operator->getDeepCopy(options) ); }
	if( m_FirstOperand ) { copy_self->m_FirstOperand = dynamic_pointer_cast<IfcBooleanOperand>( m_FirstOperand->getDeepCopy(options) ); }
	if( m_SecondOperand ) { copy_self->m_SecondOperand = dynamic_pointer_cast<IfcBooleanOperand>( m_SecondOperand->getDeepCopy(options) ); }
	return copy_self;
}
void IFC4X3::IfcBooleanClippingResult::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_tag << "= IFCBOOLEANCLIPPINGRESULT" << "(";
	if( m_Operator ) { m_Operator->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_FirstOperand ) { m_FirstOperand->getStepParameter( stream, true ); } else { stream << "$" ; }
	stream << ",";
	if( m_SecondOperand ) { m_SecondOperand->getStepParameter( stream, true ); } else { stream << "$" ; }
	stream << ");";
}
void IFC4X3::IfcBooleanClippingResult::getStepParameter( std::stringstream& stream, bool /*is_select_type*/ ) const { stream << "#" << m_tag; }
void IFC4X3::IfcBooleanClippingResult::readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	const size_t num_args = args.size();
	if( num_args != 3 ){ std::stringstream err; err << "Wrong parameter count for entity IfcBooleanClippingResult, expecting 3, having " << num_args << ". Entity ID: " << m_tag << std::endl; throw BuildingException( err.str().c_str() ); }
	m_Operator = IfcBooleanOperator::createObjectFromSTEP( args[0], map, errorStream );
	m_FirstOperand = IfcBooleanOperand::createObjectFromSTEP( args[1], map, errorStream );
	m_SecondOperand = IfcBooleanOperand::createObjectFromSTEP( args[2], map, errorStream );
}
void IFC4X3::IfcBooleanClippingResult::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const
{
	IFC4X3::IfcBooleanResult::getAttributes( vec_attributes );
}
void IFC4X3::IfcBooleanClippingResult::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse ) const
{
	IFC4X3::IfcBooleanResult::getAttributesInverse( vec_attributes_inverse );
}
void IFC4X3::IfcBooleanClippingResult::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcBooleanResult::setInverseCounterparts( ptr_self_entity );
}
void IFC4X3::IfcBooleanClippingResult::unlinkFromInverseCounterparts()
{
	IfcBooleanResult::unlinkFromInverseCounterparts();
}