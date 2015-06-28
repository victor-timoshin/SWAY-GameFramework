#ifndef RENDER_GEOMETRY_H
#define RENDER_GEOMETRY_H

#include "../../../SDK/Core/Render/RenderGeometryBase.h"

namespace Core
{
	namespace Render
	{
		class RenderGeometry : public IRenderGeometryBase
		{
		public:
			/** Constructor. */
			RenderGeometry(Scene::ISceneComponentBase* component, Gapi::IDeviceBase* device);

			/** Destructor. */
			virtual ~RenderGeometry();

			virtual void BuildVBOs(void* library, Gapi::IShaderBase* shader);

			virtual void Draw();

			virtual void SetInstanceId(UInt id);

			virtual UInt GetInstanceId();
		private:
			Scene::ISceneComponentBase* sceneComponent;

			Gapi::IDeviceBase* renderDevice;
			Gapi::IBufferBase* vertexBuffer;
			Gapi::IBufferBase* indexBuffer;

			UInt instanceId;
		};
	}
}

#endif // RENDER_GEOMETRY_H