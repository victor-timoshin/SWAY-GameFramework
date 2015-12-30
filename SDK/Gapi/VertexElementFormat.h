#ifndef VERTEXELEMENTFORMAT_H
#define VERTEXELEMENTFORMAT_H

namespace Gapi
{
	typedef enum class VertexElementFormat
	{
		Float2 = 0xC97F,
		Float3 = 0x131B,
		Float4 = 0x0D65,
		UByte  = 0x14A1
	} VERTEX_ELEMENT_FORMAT;
}

#endif // VERTEXELEMENTFORMAT_H