#ifndef ALBUFFERBASE_H
#define ALBUFFERBASE_H

#include "../Platform.h"
#include "AudioDescription.h"

namespace Sapi
{
	class IBufferBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		IBufferBase(void) {}

		/// <summary>Деструктор класса.</summary>
		virtual ~IBufferBase(void) {}

		virtual bool Fill(AUDIO_DESCRIPTION_PTR audioDesc) = 0;
	};

	CORE_API IBufferBase* RegisterBuffer(void);
}

#endif // ALBUFFERBASE_H