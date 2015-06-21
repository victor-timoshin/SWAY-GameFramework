#ifndef INDEX_BUFFER_H
#define INDEX_BUFFER_H

#include "../../SDK/Gapi/IndexBufferBase.h"
#include "../../GapiOpenGL/StdAfx.h"

#define BUFFER_OFFSET(x)((char*)0L + (x))

namespace Gapi
{
	namespace OpenGL
	{
		class IndexBuffer: public IIndexBufferBase
		{
		public:
#ifdef PLATFORM_WINDOWS
			static PFNGLGENBUFFERSARBPROC glGenBuffersARB;
			static PFNGLBINDBUFFERARBPROC glBindBufferARB;
			static PFNGLBUFFERDATAARBPROC glBufferDataARB;
			static PFNGLBUFFERSUBDATAARBPROC glBufferSubDataARB;
			static PFNGLMAPBUFFERARBPROC glMapBufferARB;
			static PFNGLUNMAPBUFFERARBPROC glUnmapBufferARB;
#endif

			/** Constructor. */
			IndexBuffer(IRenderDeviceBase* device);

			/** Constructor. */
			virtual ~IndexBuffer();

			virtual void Create(UInt numberOfIndices, UInt indexSize);

			virtual void SetData(void* indices);

			virtual void* Lock();

			virtual void Unlock();

			UInt GetBuffer();

			UInt GetNumberOfIndices();

		private:
			UInt indexBuffer;
			UInt indexSize;
			UInt numberOfIndices;
		};

	}
}

#endif