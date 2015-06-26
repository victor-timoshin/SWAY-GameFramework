#ifndef SCENE_COMPONENT_BASE_H
#define SCENE_COMPONENT_BASE_H

#include "../../../SDK/Gapi/Types.h"
#include "../../../SDK/Core/Math/Vertex.h"
#include "../../../SDK/Platform.h"

namespace Scene
{
	typedef struct AttributePacket
	{
		void* matrixWorld;
		void* boundingBox;

		bool IsValue()
		{
			return true;
		}

	} LATTRIBUTEPACKET, *PATTRIBUTEPACKET;

	typedef struct GeometryPacket
	{
		Core::Math::PVERTEXDIFFUSE_STRUCT vertices;
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

		virtual const LATTRIBUTEPACKET& GetAttributePacket() const = 0;

		virtual void SetAttributePacket(const LATTRIBUTEPACKET& packet) = 0;

		virtual const LGEOMETRYPACKET& GetGeometryPacket() const = 0;

		virtual void SetGeometryPacket(const LGEOMETRYPACKET& packet) = 0;

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