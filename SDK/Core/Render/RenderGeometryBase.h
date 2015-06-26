#ifndef RENDER_GEOMETRY_BASE_H
#define RENDER_GEOMETRY_BASE_H

#include "../../../SDK/Core/Scene/SceneComponentBase.h"

#include "../../../SDK/Gapi/DeviceBase.h"
#include "../../../SDK/Gapi/BufferBase.h"
#include "../../../SDK/Gapi/ShaderBase.h"

namespace Core
{
	namespace Render
	{
		class IRenderGeometryBase
		{
		public:
			/** Constructor. */
			IRenderGeometryBase(Scene::ISceneComponentBase* component, Gapi::IDeviceBase* device) {}

			/** Destructor. */
			virtual ~IRenderGeometryBase() {}

			virtual void CreateBuffer(void* library, Gapi::IShaderBase* shader) = 0;

			virtual void Draw() = 0;

			virtual void SetInstanceId(UInt id) = 0;

			virtual UInt GetInstanceId() = 0;
		};
	}
}

#endif // RENDER_GEOMETRY_BASE_H