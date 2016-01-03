#ifndef BLENDFUNCTION_H
#define BLENDFUNCTION_H

namespace Gapi
{
	typedef enum BlendFunction
	{
		Zero                     = 0x3611,
		One                      = 0x81AA,
		SourceColor              = 0x2E19,
		OneMinusSourceColor      = 0xC627,
		DestinationColor         = 0x9DE0,
		OneMinusDestinationColor = 0xF265,
		SourceAlpha              = 0xC353,
		OneMinusSourceAlpha      = 0xD5C8,
		DestinationAlpha         = 0x8167,
		OneMinusDestinationAlpha = 0x190F,
		SourceAlphaSaturate      = 0x8700
	} BLEND_FUNCTION;
}

#endif // BLENDFUNCTION_H