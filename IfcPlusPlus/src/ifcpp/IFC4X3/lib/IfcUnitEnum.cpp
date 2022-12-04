/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */

#include <sstream>
#include <limits>
#include <map>
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/IFC4X3/include/IfcUnitEnum.h"

// TYPE IfcUnitEnum = ENUMERATION OF	(ABSORBEDDOSEUNIT	,AMOUNTOFSUBSTANCEUNIT	,AREAUNIT	,DOSEEQUIVALENTUNIT	,ELECTRICCAPACITANCEUNIT	,ELECTRICCHARGEUNIT	,ELECTRICCONDUCTANCEUNIT	,ELECTRICCURRENTUNIT	,ELECTRICRESISTANCEUNIT	,ELECTRICVOLTAGEUNIT	,ENERGYUNIT	,FORCEUNIT	,FREQUENCYUNIT	,ILLUMINANCEUNIT	,INDUCTANCEUNIT	,LENGTHUNIT	,LUMINOUSFLUXUNIT	,LUMINOUSINTENSITYUNIT	,MAGNETICFLUXDENSITYUNIT	,MAGNETICFLUXUNIT	,MASSUNIT	,PLANEANGLEUNIT	,POWERUNIT	,PRESSUREUNIT	,RADIOACTIVITYUNIT	,SOLIDANGLEUNIT	,THERMODYNAMICTEMPERATUREUNIT	,TIMEUNIT	,VOLUMEUNIT	,USERDEFINED);
shared_ptr<BuildingObject> IFC4X3::IfcUnitEnum::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcUnitEnum> copy_self( new IfcUnitEnum() );
	copy_self->m_enum = m_enum;
	return copy_self;
}
void IFC4X3::IfcUnitEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
{
	if( is_select_type ) { stream << "IFCUNITENUM("; }
	switch( m_enum )
	{
		case ENUM_ABSORBEDDOSEUNIT:	stream << ".ABSORBEDDOSEUNIT."; break;
		case ENUM_AMOUNTOFSUBSTANCEUNIT:	stream << ".AMOUNTOFSUBSTANCEUNIT."; break;
		case ENUM_AREAUNIT:	stream << ".AREAUNIT."; break;
		case ENUM_DOSEEQUIVALENTUNIT:	stream << ".DOSEEQUIVALENTUNIT."; break;
		case ENUM_ELECTRICCAPACITANCEUNIT:	stream << ".ELECTRICCAPACITANCEUNIT."; break;
		case ENUM_ELECTRICCHARGEUNIT:	stream << ".ELECTRICCHARGEUNIT."; break;
		case ENUM_ELECTRICCONDUCTANCEUNIT:	stream << ".ELECTRICCONDUCTANCEUNIT."; break;
		case ENUM_ELECTRICCURRENTUNIT:	stream << ".ELECTRICCURRENTUNIT."; break;
		case ENUM_ELECTRICRESISTANCEUNIT:	stream << ".ELECTRICRESISTANCEUNIT."; break;
		case ENUM_ELECTRICVOLTAGEUNIT:	stream << ".ELECTRICVOLTAGEUNIT."; break;
		case ENUM_ENERGYUNIT:	stream << ".ENERGYUNIT."; break;
		case ENUM_FORCEUNIT:	stream << ".FORCEUNIT."; break;
		case ENUM_FREQUENCYUNIT:	stream << ".FREQUENCYUNIT."; break;
		case ENUM_ILLUMINANCEUNIT:	stream << ".ILLUMINANCEUNIT."; break;
		case ENUM_INDUCTANCEUNIT:	stream << ".INDUCTANCEUNIT."; break;
		case ENUM_LENGTHUNIT:	stream << ".LENGTHUNIT."; break;
		case ENUM_LUMINOUSFLUXUNIT:	stream << ".LUMINOUSFLUXUNIT."; break;
		case ENUM_LUMINOUSINTENSITYUNIT:	stream << ".LUMINOUSINTENSITYUNIT."; break;
		case ENUM_MAGNETICFLUXDENSITYUNIT:	stream << ".MAGNETICFLUXDENSITYUNIT."; break;
		case ENUM_MAGNETICFLUXUNIT:	stream << ".MAGNETICFLUXUNIT."; break;
		case ENUM_MASSUNIT:	stream << ".MASSUNIT."; break;
		case ENUM_PLANEANGLEUNIT:	stream << ".PLANEANGLEUNIT."; break;
		case ENUM_POWERUNIT:	stream << ".POWERUNIT."; break;
		case ENUM_PRESSUREUNIT:	stream << ".PRESSUREUNIT."; break;
		case ENUM_RADIOACTIVITYUNIT:	stream << ".RADIOACTIVITYUNIT."; break;
		case ENUM_SOLIDANGLEUNIT:	stream << ".SOLIDANGLEUNIT."; break;
		case ENUM_THERMODYNAMICTEMPERATUREUNIT:	stream << ".THERMODYNAMICTEMPERATUREUNIT."; break;
		case ENUM_TIMEUNIT:	stream << ".TIMEUNIT."; break;
		case ENUM_VOLUMEUNIT:	stream << ".VOLUMEUNIT."; break;
		case ENUM_USERDEFINED:	stream << ".USERDEFINED."; break;
	}
	if( is_select_type ) { stream << ")"; }
}
shared_ptr<IFC4X3::IfcUnitEnum> IFC4X3::IfcUnitEnum::createObjectFromSTEP( const std::string& arg, const std::map<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream )
{
	if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcUnitEnum>(); }
	if( arg.compare( "*" ) == 0 ) { return shared_ptr<IfcUnitEnum>(); }
	shared_ptr<IfcUnitEnum> type_object( new IfcUnitEnum() );
	if( std_iequal( arg, ".ABSORBEDDOSEUNIT." ) )
	{
		type_object->m_enum = IfcUnitEnum::ENUM_ABSORBEDDOSEUNIT;
	}
	else if( std_iequal( arg, ".AMOUNTOFSUBSTANCEUNIT." ) )
	{
		type_object->m_enum = IfcUnitEnum::ENUM_AMOUNTOFSUBSTANCEUNIT;
	}
	else if( std_iequal( arg, ".AREAUNIT." ) )
	{
		type_object->m_enum = IfcUnitEnum::ENUM_AREAUNIT;
	}
	else if( std_iequal( arg, ".DOSEEQUIVALENTUNIT." ) )
	{
		type_object->m_enum = IfcUnitEnum::ENUM_DOSEEQUIVALENTUNIT;
	}
	else if( std_iequal( arg, ".ELECTRICCAPACITANCEUNIT." ) )
	{
		type_object->m_enum = IfcUnitEnum::ENUM_ELECTRICCAPACITANCEUNIT;
	}
	else if( std_iequal( arg, ".ELECTRICCHARGEUNIT." ) )
	{
		type_object->m_enum = IfcUnitEnum::ENUM_ELECTRICCHARGEUNIT;
	}
	else if( std_iequal( arg, ".ELECTRICCONDUCTANCEUNIT." ) )
	{
		type_object->m_enum = IfcUnitEnum::ENUM_ELECTRICCONDUCTANCEUNIT;
	}
	else if( std_iequal( arg, ".ELECTRICCURRENTUNIT." ) )
	{
		type_object->m_enum = IfcUnitEnum::ENUM_ELECTRICCURRENTUNIT;
	}
	else if( std_iequal( arg, ".ELECTRICRESISTANCEUNIT." ) )
	{
		type_object->m_enum = IfcUnitEnum::ENUM_ELECTRICRESISTANCEUNIT;
	}
	else if( std_iequal( arg, ".ELECTRICVOLTAGEUNIT." ) )
	{
		type_object->m_enum = IfcUnitEnum::ENUM_ELECTRICVOLTAGEUNIT;
	}
	else if( std_iequal( arg, ".ENERGYUNIT." ) )
	{
		type_object->m_enum = IfcUnitEnum::ENUM_ENERGYUNIT;
	}
	else if( std_iequal( arg, ".FORCEUNIT." ) )
	{
		type_object->m_enum = IfcUnitEnum::ENUM_FORCEUNIT;
	}
	else if( std_iequal( arg, ".FREQUENCYUNIT." ) )
	{
		type_object->m_enum = IfcUnitEnum::ENUM_FREQUENCYUNIT;
	}
	else if( std_iequal( arg, ".ILLUMINANCEUNIT." ) )
	{
		type_object->m_enum = IfcUnitEnum::ENUM_ILLUMINANCEUNIT;
	}
	else if( std_iequal( arg, ".INDUCTANCEUNIT." ) )
	{
		type_object->m_enum = IfcUnitEnum::ENUM_INDUCTANCEUNIT;
	}
	else if( std_iequal( arg, ".LENGTHUNIT." ) )
	{
		type_object->m_enum = IfcUnitEnum::ENUM_LENGTHUNIT;
	}
	else if( std_iequal( arg, ".LUMINOUSFLUXUNIT." ) )
	{
		type_object->m_enum = IfcUnitEnum::ENUM_LUMINOUSFLUXUNIT;
	}
	else if( std_iequal( arg, ".LUMINOUSINTENSITYUNIT." ) )
	{
		type_object->m_enum = IfcUnitEnum::ENUM_LUMINOUSINTENSITYUNIT;
	}
	else if( std_iequal( arg, ".MAGNETICFLUXDENSITYUNIT." ) )
	{
		type_object->m_enum = IfcUnitEnum::ENUM_MAGNETICFLUXDENSITYUNIT;
	}
	else if( std_iequal( arg, ".MAGNETICFLUXUNIT." ) )
	{
		type_object->m_enum = IfcUnitEnum::ENUM_MAGNETICFLUXUNIT;
	}
	else if( std_iequal( arg, ".MASSUNIT." ) )
	{
		type_object->m_enum = IfcUnitEnum::ENUM_MASSUNIT;
	}
	else if( std_iequal( arg, ".PLANEANGLEUNIT." ) )
	{
		type_object->m_enum = IfcUnitEnum::ENUM_PLANEANGLEUNIT;
	}
	else if( std_iequal( arg, ".POWERUNIT." ) )
	{
		type_object->m_enum = IfcUnitEnum::ENUM_POWERUNIT;
	}
	else if( std_iequal( arg, ".PRESSUREUNIT." ) )
	{
		type_object->m_enum = IfcUnitEnum::ENUM_PRESSUREUNIT;
	}
	else if( std_iequal( arg, ".RADIOACTIVITYUNIT." ) )
	{
		type_object->m_enum = IfcUnitEnum::ENUM_RADIOACTIVITYUNIT;
	}
	else if( std_iequal( arg, ".SOLIDANGLEUNIT." ) )
	{
		type_object->m_enum = IfcUnitEnum::ENUM_SOLIDANGLEUNIT;
	}
	else if( std_iequal( arg, ".THERMODYNAMICTEMPERATUREUNIT." ) )
	{
		type_object->m_enum = IfcUnitEnum::ENUM_THERMODYNAMICTEMPERATUREUNIT;
	}
	else if( std_iequal( arg, ".TIMEUNIT." ) )
	{
		type_object->m_enum = IfcUnitEnum::ENUM_TIMEUNIT;
	}
	else if( std_iequal( arg, ".VOLUMEUNIT." ) )
	{
		type_object->m_enum = IfcUnitEnum::ENUM_VOLUMEUNIT;
	}
	else if( std_iequal( arg, ".USERDEFINED." ) )
	{
		type_object->m_enum = IfcUnitEnum::ENUM_USERDEFINED;
	}
	return type_object;
}