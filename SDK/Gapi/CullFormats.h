#ifndef CULLFORMATS_H
#define CULLFORMATS_H

namespace Gapi
{
	typedef enum CullFormats
	{
		ECF_CW   = 0xCBA3,
		ECF_CCW  = 0x391D,
		ECF_NONE = 0x602F
	} CULL_FORMATS;
}

#endif // CULLFORMATS_H