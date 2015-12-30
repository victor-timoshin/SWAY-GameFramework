#include "../Inc/Light.h"

namespace Scene
{
	DEF_PROPERTY(Light, Math::Color, Color, _color)
	DEF_PROPERTY(Light, Math::Vector4, Ambient, _ambient)
	DEF_PROPERTY(Light, Math::Vector4, Diffuse, _diffuse)
	DEF_PROPERTY(Light, Math::Vector4, Specular, _specular)

	/// <summary>Конструктор класса.</summary>
	/// <param name="name">Имя источника света.</param>
	Light::Light(std::string name) : ILightBase(name)
	{
	}

	DEF_PROPERTY(DirectionLight, Math::Vec3F, Direction, _direction)

	/// <summary>Конструктор класса.</summary>
	/// <param name="name">Имя направленного источника света.</param>
	DirectionLight::DirectionLight(std::string name) : Light(name)
	{
		SetDirection(Math::Vec3F(0.0f, 0.0f, -1.0f));
		SetColor(Math::Color(0.7f));
	}

	//void DirectionLight::SetDirection(float x, float y, float z)
	//{
	//	float length = sqrtf(x * x + y * y + z * z);
	//	direction = Math::Vector3F(x / length, y / length, z / length);
	//}

	DEF_PROPERTY_FLOAT(SpotLight, SpotInnerCone, _spotInnerCone)
	DEF_PROPERTY_FLOAT(SpotLight, SpotOuterCone, _spotOuterCone)
	DEF_PROPERTY_FLOAT(SpotLight, Radius, _radius)

	/// <summary>Конструктор класса.</summary>
	/// <param name="name"></param>
	SpotLight::SpotLight(std::string name) : Light(name)
	{
	}
}