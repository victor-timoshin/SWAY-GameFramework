#include "../Inc/Buffer.h"

namespace Sapi
{
	UInt Buffer::GetFormat(BUFFER_FORMAT format)
	{
		switch (format)
		{
		case BUFFER_FORMAT::Mono8:    return AL_FORMAT_MONO8;
		case BUFFER_FORMAT::Mono16:   return AL_FORMAT_MONO16;
		case BUFFER_FORMAT::Stereo8:  return AL_FORMAT_STEREO8;
		case BUFFER_FORMAT::Stereo16: return AL_FORMAT_STEREO16;
		default:
			return 0;
		}
	}

	/// <summary>Конструктор класса.</summary>
	Buffer::Buffer(void)
	{
		alGenBuffers(1, &_buffer);
	}

	/// <summary>Деструктор класса.</summary>
	Buffer::~Buffer(void)
	{
		alDeleteBuffers(1, &_buffer);
	}

	bool Buffer::Fill(AUDIO_DESCRIPTION_PTR audioDesc)
	{
		UInt realFormat = Buffer::GetFormat(audioDesc->format);
		if (NOT realFormat)
			return false;

		alGetError();
		alBufferData(_buffer, realFormat, audioDesc->data, audioDesc->size, audioDesc->frequency);
		if (alGetError() != AL_NO_ERROR)
			return false;

		return true;
	}

	IBufferBase* RegisterBuffer(void)
	{
		return new Buffer();
	}
}