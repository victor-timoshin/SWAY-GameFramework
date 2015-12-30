#ifndef LIGHTBASE_H
#define LIGHTBASE_H

#include "../../Math/Inc/Quaternion.h"
#include "../../Math/Inc/Matrix4F.h"
#include "../../Math/Inc/Vector3.h"
#include "../../Math/Inc/Color.h"
#include "../../Math/Inc/MathCommon.h"

#include <string>

namespace Scene
{
	class ILightBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		/// <param name="name">Имя источника света.</param>
		ILightBase(std::string name) {}
		
		/// <summary>Деструктор класса.</summary>
		virtual ~ILightBase(void) {}
	};
}

#endif // LIGHTBASE_H