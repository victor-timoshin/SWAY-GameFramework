#ifndef TYPES_H
#define TYPES_H

#include "../Platform.h"

namespace Gapi
{
	typedef enum VertexElementType
	{
		TYPE_POSITION = 0x0605,
		TYPE_COLOR = 0x3407,
		TYPE_TEXCOORD = 0x309F,
		TYPE_NORMAL = 0x8CB7
	} VERTEX_ELEMENT_TYPE;

	typedef enum VertexElementFormat
	{
		FORMAT_FLOAT = 0x0D65,
		FORMAT_UBYTE = 0x14A1
	} VERTEX_ELEMENT_FORMAT;

	typedef enum FillType
	{
		TYPE_SOLID = 0x1B2E,
		TYPE_WIREFRAME = 0xD2D3
	} FILL_TYPE;

	typedef enum CullType
	{
		TYPE_NONE = 0x3F19,
		TYPE_FRONT = 0x9016,
		TYPE_BACK = 0xA1C5
	} CULL_TYPE;

	typedef enum FormatType
	{
		TYPE_A8R8G8B8 = 0x1F0F,
		TYPE_X8R8G8B8 = 0x08F5,
		TYPE_A4R4G4B4 = 0x5FE3,
		TYPE_G16R16F = 0x2033,
		TYPE_R32F = 0xAE18,
		TYPE_A2R10G10B10 = 0xDF30
	} FORMAT_TYPE;

	typedef enum PrimitiveType
	{
		TYPE_POINTLIST =0xFE12,
		TYPE_LINELIST = 0xFDBE,
		TYPE_LINESTRIP = 0x6B83,
		TYPE_TRIANGLELIST = 0x7DD0,
		TYPE_TRIANGLESTRIP = 0x9FAE
	} PRIMITIVE_TYPE;

	typedef enum MapType
	{
		TYPE_DISCARD = 0x14EC,
		TYPE_NOOVERWRITE = 0x43D6
	} MAP_TYPE;
}

#endif // TYPES_H