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
	// TYPE IfcConnectionTypeEnum = ENUMERATION OF	(ATEND	,ATPATH	,ATSTART	,NOTDEFINED);
	class IFCQUERY_EXPORT IfcConnectionTypeEnum : virtual public BuildingObject
	{
	public:
		enum IfcConnectionTypeEnumEnum
		{
			ENUM_ATEND,
			ENUM_ATPATH,
			ENUM_ATSTART,
			ENUM_NOTDEFINED
		};

		IfcConnectionTypeEnum() = default;
		IfcConnectionTypeEnum( IfcConnectionTypeEnumEnum e ) { m_enum = e; }
		virtual uint32_t classID() const { return 2128902557; }
		virtual void getStepParameter( std::stringstream& stream, bool is_select_type, size_t precision ) const;
		static shared_ptr<IfcConnectionTypeEnum> createObjectFromSTEP( const std::string& arg, const BuildingModelMapType<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream, std::unordered_set<int>& entityIdNotFound );
		IfcConnectionTypeEnumEnum m_enum;
	};
}
