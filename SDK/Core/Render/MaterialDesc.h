#ifndef MATERIALDESC_H
#define MATERIALDESC_H

#include "../../../SDK/Math/Vector4.h"
#include "../../../SDK/Platform.h"

namespace Render
{
	typedef struct MaterialDesc
	{
		MaterialDesc() {
			ambient = diffuse = specular = Math::CVector4(1.0f, 1.0f, 1.0f, 1.0f);
			shininess = 1.0f;
		}

		Math::Vector4 ambient;
		Math::Vector4 diffuse;
		Math::Vector4 specular;
		float shininess;
	} LMATERIALDESC_STRUCT, *PMATERIALDESC_STRUCT;
}

#endif // MATERIALDESC_H