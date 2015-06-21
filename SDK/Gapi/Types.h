#ifndef TYPES_H
#define TYPES_H

namespace Gapi
{
	typedef enum VertexElementType
	{
		TYPE_POSITION,
		TYPE_POSITIONT,
		TYPE_DIFFUSE,
		TYPE_TEXCOORD,
		TYPE_NORMAL,
		TYPE_TANGENT,
		TYPE_BINORMAL
	} VERTEX_ELEMENT_TYPE;

	typedef enum VertexElementFormat
	{
		FORMAT_FLOAT1,
		FORMAT_FLOAT2,
		FORMAT_FLOAT3,
		FORMAT_FLOAT4,
		FORMAT_COLOR
	} VERTEX_ELEMENT_FORMAT;

	typedef struct VertexDescStruct
	{
		unsigned short stream;
		unsigned char type;
		unsigned char format;
	} LVERTEXDESC_STRUCT, *PVERTEXDESC_STRUCT;

	typedef enum FillType
	{
		TYPE_SOLID,
		TYPE_WIREFRAME
	} FILL_TYPE;

	typedef enum CullType
	{
		TYPE_NONE,
		TYPE_FRONT,
		TYPE_BACK
	} CULL_TYPE;

	typedef enum FormatType
	{
		TYPE_A8R8G8B8,
		TYPE_X8R8G8B8,
		TYPE_A4R4G4B4,
		TYPE_G16R16F,
		TYPE_R32F,
		TYPE_A2R10G10B10
	} FORMAT_TYPE;

	typedef enum PrimitiveType
	{
		TYPE_POINTLIST,
		TYPE_LINELIST,
		TYPE_LINESTRIP,
		TYPE_TRIANGLELIST,
		TYPE_TRIANGLESTRIP
	} PRIMITIVE_TYPE;

	typedef enum MapType
	{
		TYPE_DISCARD,
		TYPE_NOOVERWRITE
	} MAP_TYPE;
}

#endif