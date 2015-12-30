#ifndef LIGHT_H
#define LIGHT_H

#include "../../SDK/SceneGraph/LightBase.h"

namespace Scene
{
	class Light : public ILightBase
	{
		DECL_PROPERTY_VIRTUAL(Math::Color, Color, _color)
		DECL_PROPERTY_VIRTUAL(Math::Vector4, Ambient, _ambient)
		DECL_PROPERTY_VIRTUAL(Math::Vector4, Diffuse, _diffuse)
		DECL_PROPERTY_VIRTUAL(Math::Vector4, Specular, _specular)

	public:
		/// <summary>Конструктор класса.</summary>
		/// <param name="name">Имя источника света.</param>
		Light(std::string name);
		
		/// <summary>Деструктор класса.</summary>
		virtual ~Light(void) {}

	private:
	};

	class DirectionLight : public Light
	{
		DECL_PROPERTY_VIRTUAL(Math::Vec3F, Direction, _direction)

	public:
		/// <summary>Конструктор класса.</summary>
		/// <param name="name">Имя направленного источника света.</param>
		DirectionLight(std::string name);

		/// <summary>Деструктор класса.</summary>
		virtual ~DirectionLight(void) {}
	};

	class SpotLight : public Light
	{
		DECL_PROPERTY_VIRTUAL_FLOAT(SpotInnerCone, _spotInnerCone)
		DECL_PROPERTY_VIRTUAL_FLOAT(SpotOuterCone, _spotOuterCone)
		DECL_PROPERTY_VIRTUAL_FLOAT(Radius, _radius)

	public:
		/// <summary>Конструктор класса.</summary>
		/// <param name="name">Имя направленного источника света.</param>
		SpotLight(std::string name);

		/// <summary>Деструктор класса.</summary>
		virtual ~SpotLight(void) {}
	};
}

#endif // LIGHT_H