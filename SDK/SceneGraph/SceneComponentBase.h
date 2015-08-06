#ifndef SCENECOMPONENTBASE_H
#define SCENECOMPONENTBASE_H

#include "../Core/Scene/RenderableBase.h"
//#include "../Math/BoundingVolume.h"
//#include "../Math/Matrix4.h"
//#include "../Math/Vertex.h"
#include "../Gapi/Types.h"
#include "../Platform.h"

namespace Scene
{
	class ISceneNodeBase;
	class ISceneComponentBase : public IRenderableBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		ISceneComponentBase(void) { }

		/// <summary>Деструктор класса.</summary>
		virtual ~ISceneComponentBase(void) { }

		virtual void Notify(ISceneNodeBase* sceneNode) = 0;

		virtual ISceneNodeBase* GetSceneNode(void) = 0;

		virtual void SetComponentName(std::string name)
		{
			componentName = name;
		}

		virtual const char* GetComponentName(void)
		{
			return componentName.c_str();
		}

	private:
		std::string componentName;
	};

	CORE_API ISceneComponentBase* RegisterSceneComponent(void);
}

#endif // SCENECOMPONENTBASE_H