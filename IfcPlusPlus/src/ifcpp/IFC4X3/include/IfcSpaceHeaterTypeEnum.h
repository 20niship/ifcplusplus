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
	// TYPE IfcSpaceHeaterTypeEnum = ENUMERATION OF	(CONVECTOR	,RADIATOR	,USERDEFINED	,NOTDEFINED);
	class IFCQUERY_EXPORT IfcSpaceHeaterTypeEnum : virtual public BuildingObject
	{
	public:
		enum IfcSpaceHeaterTypeEnumEnum
		{
			ENUM_CONVECTOR,
			ENUM_RADIATOR,
			ENUM_USERDEFINED,
			ENUM_NOTDEFINED
		};

		IfcSpaceHeaterTypeEnum() = default;
		IfcSpaceHeaterTypeEnum( IfcSpaceHeaterTypeEnumEnum e ) { m_enum = e; }
		virtual uint32_t classID() const { return 1855850635; }
		virtual void getStepParameter( std::stringstream& stream, bool is_select_type, size_t precision ) const;
		static shared_ptr<IfcSpaceHeaterTypeEnum> createObjectFromSTEP( const std::string& arg, const BuildingModelMapType<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream, std::unordered_set<int>& entityIdNotFound );
		IfcSpaceHeaterTypeEnumEnum m_enum;
	};
}
