/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */

#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "ifcpp/model/GlobalDefines.h"
#include "ifcpp/model/BasicTypes.h"
#include "ifcpp/model/BuildingObject.h"

namespace IFC4X3
{
	// TYPE IfcWorkCalendarTypeEnum = ENUMERATION OF	(FIRSTSHIFT	,SECONDSHIFT	,THIRDSHIFT	,USERDEFINED	,NOTDEFINED);
	class IFCQUERY_EXPORT IfcWorkCalendarTypeEnum : virtual public BuildingObject
	{
	public:
		enum IfcWorkCalendarTypeEnumEnum
		{
			ENUM_FIRSTSHIFT,
			ENUM_SECONDSHIFT,
			ENUM_THIRDSHIFT,
			ENUM_USERDEFINED,
			ENUM_NOTDEFINED
		};

		IfcWorkCalendarTypeEnum() = default;
		IfcWorkCalendarTypeEnum( IfcWorkCalendarTypeEnumEnum e ) { m_enum = e; }
		virtual uint32_t classID() const { return 1471118587; }
		virtual void getStepParameter( std::stringstream& stream, bool is_select_type, size_t precision ) const;
		static shared_ptr<IfcWorkCalendarTypeEnum> createObjectFromSTEP( const std::string& arg, const BuildingModelMapType<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream, std::unordered_set<int>& entityIdNotFound );
		IfcWorkCalendarTypeEnumEnum m_enum;
	};
}
