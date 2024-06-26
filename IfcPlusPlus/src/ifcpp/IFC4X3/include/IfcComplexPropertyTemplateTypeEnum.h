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
	// TYPE IfcComplexPropertyTemplateTypeEnum = ENUMERATION OF	(P_COMPLEX	,Q_COMPLEX);
	class IFCQUERY_EXPORT IfcComplexPropertyTemplateTypeEnum : virtual public BuildingObject
	{
	public:
		enum IfcComplexPropertyTemplateTypeEnumEnum
		{
			ENUM_P_COMPLEX,
			ENUM_Q_COMPLEX
		};

		IfcComplexPropertyTemplateTypeEnum() = default;
		IfcComplexPropertyTemplateTypeEnum( IfcComplexPropertyTemplateTypeEnumEnum e ) { m_enum = e; }
		virtual uint32_t classID() const { return 1692979113; }
		virtual void getStepParameter( std::stringstream& stream, bool is_select_type, size_t precision ) const;
		static shared_ptr<IfcComplexPropertyTemplateTypeEnum> createObjectFromSTEP( const std::string& arg, const BuildingModelMapType<int,shared_ptr<BuildingEntity> >& map, std::stringstream& errorStream, std::unordered_set<int>& entityIdNotFound );
		IfcComplexPropertyTemplateTypeEnumEnum m_enum;
	};
}
