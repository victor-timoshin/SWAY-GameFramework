#ifndef BUFFER_H
#define BUFFER_H

#include "Vector3.h"

#include "../../SDK/Sapi/BufferBase.h"
#include "../../SDK/Platform.h"
#include "../StdAfx.h"

namespace Sapi
{
	class Buffer : public IBufferBase
	{
	public:
		static UInt GetFormat(BUFFER_FORMAT format);

		/// <summary>Конструктор класса.</summary>
		Buffer(void);

		/// <summary>Деструктор класса.</summary>
		virtual ~Buffer(void);

		virtual bool Fill(AUDIO_DESCRIPTION_PTR audioDesc);

		ALuint GetBuffer(void) const {
			return _buffer;
		}

	private:
		ALuint _buffer;
	};
}

#endif // BUFFER_H