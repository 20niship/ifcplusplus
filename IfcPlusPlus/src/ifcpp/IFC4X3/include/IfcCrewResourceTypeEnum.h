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
	// TYPE IfcCrewResourceTypeEnum = ENUMERATION OF	(OFFICE	,SITE	,USERDEFINED	,NOTDEFINED);
	class IFCQUERY_EXPORT IfcCrewResourceTypeEnum : virtual public BuildingObject
	{
	public:
		enum IfcCrewResourceTypeEnumEnum
		{
			ENUM_OFFICE,
			ENUM_SITE,
			ENUM_USERDEFINED,
			ENUM_NOTDEFINED
		};

		IfcCrewResourceTypeEnum() = default;
		IfcCrewResourceTypeEnum( IfcCrewResourceTypeEnumEnum e ) { m_enum = e; }
		virtual uint32_t classID() const { return 2952703181; }
		virtual void getStepParameter( std::stringstream& stream, bool is_select_type, size_t precision ) const;
		static shared_ptr<IfcCrewResourceTypeEnum> createObjectFromSTEP( const std::string& arg, const BuildingModelMapType<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream, std::unordered_set<int>& entityIdNotFound );
		IfcCrewResourceTypeEnumEnum m_enum;
	};
}
