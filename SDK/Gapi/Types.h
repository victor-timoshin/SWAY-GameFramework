#ifndef TYPES_H
#define TYPES_H

namespace Gapi
{
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

	typedef enum MapType
	{
		TYPE_DISCARD = 0x14EC,
		TYPE_NOOVERWRITE = 0x43D6
	} MAP_TYPE;
}

#endif // TYPES_H