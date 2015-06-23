#ifndef TEXTURE_BASE_H
#define TEXTURE_BASE_H

#include "../../SDK/Gapi/Types.h"
#include "../../SDK/Platform.h"

namespace Gapi
{
	class IDeviceBase;
	class ITextureBase
	{
	public:
		/** Constructor. */
		ITextureBase(IDeviceBase* device) {}

		/** Destructor. */
		virtual ~ITextureBase() {}
	};
}

#endif