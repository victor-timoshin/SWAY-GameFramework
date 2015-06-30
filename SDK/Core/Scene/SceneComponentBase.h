#ifndef SCENE_COMPONENT_BASE_H
#define SCENE_COMPONENT_BASE_H

#include "../../../SDK/Gapi/Types.h"
#include "../../../SDK/Core/Math/BoundingVolume.h"
#include "../../../SDK/Core/Math/Matrix4.h"
#include "../../../SDK/Core/Math/Vertex.h"
#include "../../../SDK/Platform.h"

namespace Scene
{
	typedef struct AttributePacket
	{
		Core::Math::Matrix4 matrixWorld;
		Core::Math::BoundingVolume boundingBox;

		bool IsValue()
		{
			return true;
		}

	} LATTRIBUTEPACKET, *PATTRIBUTEPACKET;

	typedef struct GeometryPacket
	{
		UInt16* vertices;
		UInt16* indices;
		UInt numVertices;
		UInt numIndices;
		UInt numPrimitives;
		Gapi::PRIMITIVE_TYPE primitiveType;

		bool IsValue()
		{
			return true;
		}

	} LGEOMETRYPACKET, *PGEOMETRYPACKET;

	class Renderable
	{

	};

	class ISceneNodeBase;
	class ISceneComponentBase
	{
	public:
		/** Constructor. */
		ISceneComponentBase() {}

		/** Destructor. */
		virtual ~ISceneComponentBase() {}

		virtual void Notify(ISceneNodeBase* sceneNode) = 0;

		virtual ISceneNodeBase* GetSceneNode() = 0;

		virtual LATTRIBUTEPACKET GetAttributePacket() = 0;

		virtual void SetAttributePacket(LATTRIBUTEPACKET packet) = 0;

		virtual LGEOMETRYPACKET GetGeometryPacket() = 0;

		virtual void SetGeometryPacket(LGEOMETRYPACKET packet) = 0;

		virtual void SetComponentName(std::string name)
		{
			componentName = name;
		}

		virtual const char* GetComponentName()
		{
			return componentName.c_str();
		}

	private:
		std::string componentName;
	};

	CORE_API ISceneComponentBase* RegisterSceneComponent();
}

#endif // SCENE_COMPONENT_BASE_H