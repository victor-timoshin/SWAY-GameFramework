#ifndef MATERIALBASE_H
#define MATERIALBASE_H

#include "../../../Math/Inc/Vector4.h"
#include "../../../SDK/Platform.h"

namespace Core
{
	namespace Render
	{
		class IMaterialBase
		{
		public:
			/// <summary>Конструктор класса.</summary>
			IMaterialBase(void) {}

			/// <summary>Деструктор класса.</summary>
			virtual ~IMaterialBase(void) {}

			//virtual bool Create(const char* vertexShader, const char* fragmentShader, const char* textureName) = 0;

			virtual void Destroy(void) = 0;

			virtual void Bind(void) = 0;

			virtual void Unbind(void) = 0;

			/// <summary>Устанавливает свойства отражения окружающего цвета.</summary>
			/// <param name="red"></param>
			/// <param name="green"></param>
			/// <param name="blue"></param>
			virtual void SetAmbient(float red, float green, float blue) = 0;

			/// <summary>Устанавливает свойства диффузного отражения цвета.</summary>
			/// <param name="red"></param>
			/// <param name="green"></param>
			/// <param name="blue"></param>
			/// <param name="alpha"></param>
			virtual void SetDiffuse(float red, float green, float blue, float alpha) = 0;

			/// <summary>Устанавливает свойства зеркального отражения цвета.</summary>
			/// <param name="red"></param>
			/// <param name="green"></param>
			/// <param name="blue"></param>
			/// <param name="alpha"></param>
			virtual void SetSpecular(float red, float green, float blue, float alpha) = 0;

			/// <summary>Устанавливает свойства блеска.</summary>
			/// <param name="value"></param>
			virtual void SetShininess(float value) = 0;
			
			/// <summary>Устанавливает имя материала.</summary>
			/// <param name="name">Имя материала.</param>
			virtual void SetName(std::string name) = 0;

			/// <summary>Получает имя материала.</summary>
			virtual std::string GetName(void) const = 0;
		};
	}
}

#endif // MATERIALBASE_H