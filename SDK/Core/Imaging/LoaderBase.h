#ifndef LOADERBASE_H
#define LOADERBASE_H

#include "../../../SDK/Gapi/TextureDescription.h"
#include "../../../SDK/Platform.h"

namespace Imaging
{
	class ILoaderBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		ILoaderBase(void) {}

		/// <summary>Деструктор класса.</summary>
		virtual ~ILoaderBase(void) {}

		virtual Gapi::PTEXTURE_DESCRIPTION LoadFromStream(std::istream& source) = 0;
	};
}

#endif // LOADERBASE_H