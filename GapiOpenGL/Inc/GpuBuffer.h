#ifndef GPUBUFFER_H
#define GPUBUFFER_H

#include "../../SDK/Gapi/BufferBase.h"
#include "../../GapiOpenGL/StdAfx.h"

#define BUFFER_OFFSET(x)((char*)0L + (x))

namespace Gapi
{
	class GpuBuffer : public IBufferBase
	{
	public:
		static UInt GetBufferType(BUFFERTYPES type);
		static UInt GetPrimitiveType(PRIMITIVETYPES type);

		static PFNGLGENBUFFERSARBPROC glGenBuffersARB;
		static PFNGLBINDBUFFERARBPROC glBindBufferARB;
		static PFNGLBUFFERDATAARBPROC glBufferDataARB;
		static PFNGLBUFFERSUBDATAARBPROC glBufferSubDataARB;
		static PFNGLMAPBUFFERARBPROC glMapBufferARB;
		static PFNGLUNMAPBUFFERARBPROC glUnmapBufferARB;
		static PFNGLDELETEBUFFERSARBPROC glDeleteBuffersARB;
		static PFNGLGETBUFFERPARAMETERIVARBPROC glGetBufferParameterivARB;


		static PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointerARB;
		static PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArrayARB;

		/// <summary>Конструктор класса.</summary>
		GpuBuffer(void);

		/// <summary>Деструктор класса.</summary>
		virtual ~GpuBuffer(void);

		/// <summary>Устанавливает декларацию вершин.</summary>
		virtual void SetVertexDeclaration(const PVERTEX_ELEMENT_DESC elementDesc, UInt numElements);

		virtual UInt Create(BUFFERTYPES type, UInt stride, UInt count);

		virtual void Destroy(void);

		virtual void SetData(void* source);

		virtual void* Lock(void);

		virtual void Unlock(void);

		virtual void Render(PRIMITIVETYPES primitiveType, IBufferBase* indexBuffer, UInt numVertices, UInt primitiveCount);

		virtual UInt GetID(void);

		UInt GetElementCount(void);

	private:
		UInt bufferID;
		UInt bufferType;
		LVERTEX_FORMAT_DESC vertexFormatDesc;
		UInt byteStride;
		UInt numElements;
	};
}

#endif // GPUBUFFER_H