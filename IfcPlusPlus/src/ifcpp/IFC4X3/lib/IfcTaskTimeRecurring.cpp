/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4X3/include/IfcBoolean.h"
#include "ifcpp/IFC4X3/include/IfcDataOriginEnum.h"
#include "ifcpp/IFC4X3/include/IfcDateTime.h"
#include "ifcpp/IFC4X3/include/IfcDuration.h"
#include "ifcpp/IFC4X3/include/IfcLabel.h"
#include "ifcpp/IFC4X3/include/IfcPositiveRatioMeasure.h"
#include "ifcpp/IFC4X3/include/IfcRecurrencePattern.h"
#include "ifcpp/IFC4X3/include/IfcTaskDurationEnum.h"
#include "ifcpp/IFC4X3/include/IfcTaskTimeRecurring.h"

// ENTITY IfcTaskTimeRecurring 
IFC4X3::IfcTaskTimeRecurring::IfcTaskTimeRecurring( int tag ) { m_tag = tag; }
void IFC4X3::IfcTaskTimeRecurring::getStepLine( std::stringstream& stream, size_t precision ) const
{
	stream << "#" << m_tag << "=IFCTASKTIMERECURRING" << "(";
	if( m_Name ) { m_Name->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_DataOrigin ) { m_DataOrigin->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_UserDefinedDataOrigin ) { m_UserDefinedDataOrigin->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_DurationType ) { m_DurationType->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_ScheduleDuration ) { m_ScheduleDuration->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_ScheduleStart ) { m_ScheduleStart->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_ScheduleFinish ) { m_ScheduleFinish->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_EarlyStart ) { m_EarlyStart->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_EarlyFinish ) { m_EarlyFinish->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_LateStart ) { m_LateStart->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_LateFinish ) { m_LateFinish->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_FreeFloat ) { m_FreeFloat->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_TotalFloat ) { m_TotalFloat->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_IsCritical ) { m_IsCritical->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_StatusTime ) { m_StatusTime->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_ActualDuration ) { m_ActualDuration->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_ActualStart ) { m_ActualStart->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_ActualFinish ) { m_ActualFinish->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_RemainingTime ) { m_RemainingTime->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_Completion ) { m_Completion->getStepParameter( stream, false, precision ); } else { stream << "$"; }
	stream << ",";
	if( m_Recurrence ) { stream << "#" << m_Recurrence->m_tag; } else { stream << "$"; }
	stream << ");";
}
void IFC4X3::IfcTaskTimeRecurring::getStepParameter( std::stringstream& stream, bool /*is_select_type*/, size_t /*precision*/ ) const { stream << "#" << m_tag; }
void IFC4X3::IfcTaskTimeRecurring::readStepArguments( const std::vector<std::string>& args, const BuildingModelMapType<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream, std::unordered_set<int>& entityIdNotFound )
{
	const size_t num_args = args.size();
	if( num_args > 0 ){m_Name = IfcLabel::createObjectFromSTEP( args[0], map, errorStream, entityIdNotFound );}
	if( num_args > 1 ){m_DataOrigin = IfcDataOriginEnum::createObjectFromSTEP( args[1], map, errorStream, entityIdNotFound );}
	if( num_args > 2 ){m_UserDefinedDataOrigin = IfcLabel::createObjectFromSTEP( args[2], map, errorStream, entityIdNotFound );}
	if( num_args > 3 ){m_DurationType = IfcTaskDurationEnum::createObjectFromSTEP( args[3], map, errorStream, entityIdNotFound );}
	if( num_args > 4 ){m_ScheduleDuration = IfcDuration::createObjectFromSTEP( args[4], map, errorStream, entityIdNotFound );}
	if( num_args > 5 ){m_ScheduleStart = IfcDateTime::createObjectFromSTEP( args[5], map, errorStream, entityIdNotFound );}
	if( num_args > 6 ){m_ScheduleFinish = IfcDateTime::createObjectFromSTEP( args[6], map, errorStream, entityIdNotFound );}
	if( num_args > 7 ){m_EarlyStart = IfcDateTime::createObjectFromSTEP( args[7], map, errorStream, entityIdNotFound );}
	if( num_args > 8 ){m_EarlyFinish = IfcDateTime::createObjectFromSTEP( args[8], map, errorStream, entityIdNotFound );}
	if( num_args > 9 ){m_LateStart = IfcDateTime::createObjectFromSTEP( args[9], map, errorStream, entityIdNotFound );}
	if( num_args > 10 ){m_LateFinish = IfcDateTime::createObjectFromSTEP( args[10], map, errorStream, entityIdNotFound );}
	if( num_args > 11 ){m_FreeFloat = IfcDuration::createObjectFromSTEP( args[11], map, errorStream, entityIdNotFound );}
	if( num_args > 12 ){m_TotalFloat = IfcDuration::createObjectFromSTEP( args[12], map, errorStream, entityIdNotFound );}
	if( num_args > 13 ){m_IsCritical = IfcBoolean::createObjectFromSTEP( args[13], map, errorStream, entityIdNotFound );}
	if( num_args > 14 ){m_StatusTime = IfcDateTime::createObjectFromSTEP( args[14], map, errorStream, entityIdNotFound );}
	if( num_args > 15 ){m_ActualDuration = IfcDuration::createObjectFromSTEP( args[15], map, errorStream, entityIdNotFound );}
	if( num_args > 16 ){m_ActualStart = IfcDateTime::createObjectFromSTEP( args[16], map, errorStream, entityIdNotFound );}
	if( num_args > 17 ){m_ActualFinish = IfcDateTime::createObjectFromSTEP( args[17], map, errorStream, entityIdNotFound );}
	if( num_args > 18 ){m_RemainingTime = IfcDuration::createObjectFromSTEP( args[18], map, errorStream, entityIdNotFound );}
	if( num_args > 19 ){m_Completion = IfcPositiveRatioMeasure::createObjectFromSTEP( args[19], map, errorStream, entityIdNotFound );}
	if( num_args > 20 ){readEntityReference( args[20], m_Recurrence, map, errorStream, entityIdNotFound );}
	if( num_args != 21 ){ errorStream << "Wrong parameter count for entity IfcTaskTimeRecurring, expecting 21, having " << num_args << ". Entity ID: " << m_tag << std::endl; }
}
void IFC4X3::IfcTaskTimeRecurring::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const
{
	IFC4X3::IfcTaskTime::getAttributes( vec_attributes );
	vec_attributes.emplace_back( std::make_pair( "Recurrence", m_Recurrence ) );
}
void IFC4X3::IfcTaskTimeRecurring::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse ) const
{
	IFC4X3::IfcTaskTime::getAttributesInverse( vec_attributes_inverse );
}
void IFC4X3::IfcTaskTimeRecurring::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcTaskTime::setInverseCounterparts( ptr_self_entity );
}
void IFC4X3::IfcTaskTimeRecurring::unlinkFromInverseCounterparts()
{
	IfcTaskTime::unlinkFromInverseCounterparts();
}
