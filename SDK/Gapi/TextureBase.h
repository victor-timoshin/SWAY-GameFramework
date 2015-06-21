#ifndef TEXTURE_BASE_H
#define TEXTURE_BASE_H

#include "../../SDK/Gapi/Types.h"
#include "../../SDK/Platform.h"

namespace Gapi
{
	class IRenderDeviceBase;
	class ITextureBase
	{
	public:
		/** Constructor. */
		ITextureBase(IRenderDeviceBase* device) {}

		/** Destructor. */
		virtual ~ITextureBase() {}
	};
}

#endif