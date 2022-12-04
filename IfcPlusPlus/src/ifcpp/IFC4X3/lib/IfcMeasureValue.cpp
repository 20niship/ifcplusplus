/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <map>
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/IFC4X3/include/IfcAmountOfSubstanceMeasure.h"
#include "ifcpp/IFC4X3/include/IfcAreaMeasure.h"
#include "ifcpp/IFC4X3/include/IfcComplexNumber.h"
#include "ifcpp/IFC4X3/include/IfcContextDependentMeasure.h"
#include "ifcpp/IFC4X3/include/IfcCountMeasure.h"
#include "ifcpp/IFC4X3/include/IfcDescriptiveMeasure.h"
#include "ifcpp/IFC4X3/include/IfcElectricCurrentMeasure.h"
#include "ifcpp/IFC4X3/include/IfcLengthMeasure.h"
#include "ifcpp/IFC4X3/include/IfcLuminousIntensityMeasure.h"
#include "ifcpp/IFC4X3/include/IfcMassMeasure.h"
#include "ifcpp/IFC4X3/include/IfcNonNegativeLengthMeasure.h"
#include "ifcpp/IFC4X3/include/IfcNormalisedRatioMeasure.h"
#include "ifcpp/IFC4X3/include/IfcNumericMeasure.h"
#include "ifcpp/IFC4X3/include/IfcParameterValue.h"
#include "ifcpp/IFC4X3/include/IfcPlaneAngleMeasure.h"
#include "ifcpp/IFC4X3/include/IfcPositiveLengthMeasure.h"
#include "ifcpp/IFC4X3/include/IfcPositivePlaneAngleMeasure.h"
#include "ifcpp/IFC4X3/include/IfcPositiveRatioMeasure.h"
#include "ifcpp/IFC4X3/include/IfcRatioMeasure.h"
#include "ifcpp/IFC4X3/include/IfcSolidAngleMeasure.h"
#include "ifcpp/IFC4X3/include/IfcThermodynamicTemperatureMeasure.h"
#include "ifcpp/IFC4X3/include/IfcTimeMeasure.h"
#include "ifcpp/IFC4X3/include/IfcVolumeMeasure.h"
#include "ifcpp/IFC4X3/include/IfcValue.h"
#include "ifcpp/IFC4X3/include/IfcMeasureValue.h"

// TYPE IfcMeasureValue = SELECT	(IfcAmountOfSubstanceMeasure	,IfcAreaMeasure	,IfcComplexNumber	,IfcContextDependentMeasure	,IfcCountMeasure	,IfcDescriptiveMeasure	,IfcElectricCurrentMeasure	,IfcLengthMeasure	,IfcLuminousIntensityMeasure	,IfcMassMeasure	,IfcNonNegativeLengthMeasure	,IfcNormalisedRatioMeasure	,IfcNumericMeasure	,IfcParameterValue	,IfcPlaneAngleMeasure	,IfcPositiveLengthMeasure	,IfcPositivePlaneAngleMeasure	,IfcPositiveRatioMeasure	,IfcRatioMeasure	,IfcSolidAngleMeasure	,IfcThermodynamicTemperatureMeasure	,IfcTimeMeasure	,IfcVolumeMeasure);
shared_ptr<IFC4X3::IfcMeasureValue> IFC4X3::IfcMeasureValue::createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	if( arg.empty() ){ return shared_ptr<IfcMeasureValue>(); }
	if( arg.compare("$")==0 )
	{
		return shared_ptr<IfcMeasureValue>();
	}
	if( arg.compare("*")==0 )
	{
		return shared_ptr<IfcMeasureValue>();
	}
	shared_ptr<IfcMeasureValue> result_object;
	readSelectType( arg, result_object, map, errorStream );
	return result_object;
}