#ifndef PRIMITIVETYPE_H
#define PRIMITIVETYPE_H

namespace Gapi
{
	typedef enum PrimitiveType
	{
		PointList     = 0xFE12,
		LineList      = 0xFDBE,
		LineStrip     = 0x6B83,
		TriangleList  = 0x7DD0,
		TriangleStrip = 0x9FAE
	} PRIMITIVE_TYPE;
}

#endif // PRIMITIVETYPE_H