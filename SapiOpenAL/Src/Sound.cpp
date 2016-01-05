#include "../Inc/Sound.h"
#include "../Inc/Buffer.h"

namespace Sapi
{
	/// <summary>Конструктор класса.</summary>
	Sound::Sound(void)
		: _source(0)
		, _buffer(nullptr)
		, _isLooping(false)
	{
		alGenSources(1, &_source);
	}

	/// <summary>Деструктор класса.</summary>
	Sound::~Sound(void)
	{
		alDeleteSources(1, &_source);
	}

	void Sound::SetALBuffer(IBufferBase* buffer)
	{
		Buffer* internalBuffer = dynamic_cast<Buffer*>(buffer);
		if (NOT internalBuffer)
			return;

		if (HasPlaying())
			Stop();

		if (buffer)
			alSourcei(_source, AL_BUFFER, internalBuffer->GetBuffer());
		else
			alSourcei(_source, AL_BUFFER, AL_NONE);

		_buffer = internalBuffer;
	}

	/// <summary>Запускает воспроизведение звука.</summary>
	void Sound::Play(void)
	{
		if (HasPlaying())
			return;

		alSourcePlay(_source);
	}

	bool Sound::HasPlaying(void) const
	{
		ALint state;
		alGetSourcei(_source, AL_SOURCE_STATE, &state);
		return (state == AL_PLAYING);
	}

	/// <summary>Останавливает воспроизведение звука.</summary>
	void Sound::Stop(void)
	{
		if (HasStopped())
			return;

		alSourceStop(_source);
	}

	bool Sound::HasStopped(void) const
	{
		ALenum state;
		alGetSourcei(_source, AL_SOURCE_STATE, &state);
		return (state == AL_STOPPED);
	}

	/// <summary>Ставит на паузу воспроизведение.</summary>
	void Sound::Pause(void)
	{
		if (HasPaused())
			return;

		alSourcePause(_source);
	}

	bool Sound::HasPaused(void) const
	{
		ALenum state;
		alGetSourcei(_source, AL_SOURCE_STATE, &state);
		return (state == AL_PAUSED);
	}

	void Sound::Rewind(void)
	{
		alSourceRewind(_source);
	}

	/// <summary>Использование циклического воспроизведение.</summary>
	void Sound::UseLooping(bool looping)
	{
		_isLooping = looping;
		alSourcei(_source, AL_LOOPING, (_isLooping) ? AL_TRUE : AL_FALSE);
	}

	bool Sound::HasLooping(void) const
	{
		return _isLooping;
	}

	/// <summary>Устанавливает координаты источника звука.</summary>
	void Sound::SetSourcePosition(float x, float y, float z)
	{
		SetSourcePosition(Math::Vec3F(x, y, z));
	}

	/// <summary>Устанавливает координаты источника звука.</summary>
	void Sound::SetSourcePosition(Math::Vec3F position)
	{
		_sourcePosition = position;
		alSource3f(_source, AL_POSITION, _sourcePosition.GetX(), _sourcePosition.GetY(), _sourcePosition.GetZ());
	}

	void Sound::SetSourceVelocity(float x, float y, float z)
	{
		SetSourceVelocity(Math::Vec3F(x, y, z));
	}

	void Sound::SetSourceVelocity(Math::Vec3F velocity)
	{
		_sourceVelocity = velocity;
		alSource3f(_source, AL_VELOCITY, _sourceVelocity.GetX(), _sourceVelocity.GetY(), _sourceVelocity.GetZ());
	}

	/// <summary>Устанавливает координаты слушателя.</summary>
	void Sound::SetListenerPosition(float x, float y, float z)
	{
		SetListenerPosition(Math::Vec3F(x, y, z));
	}

	/// <summary>Устанавливает координаты слушателя.</summary>
	void Sound::SetListenerPosition(Math::Vec3F position)
	{
		_listenerPosition = position;
		alListener3f(AL_POSITION, _listenerPosition.GetX(), _listenerPosition.GetY(), _listenerPosition.GetZ());
	}

	void Sound::SetListenerVelocity(float x, float y, float z)
	{
		SetListenerVelocity(Math::Vec3F(x, y, z));
	}

	void Sound::SetListenerVelocity(Math::Vec3F velocity)
	{
		_listenerVelocity = velocity;
		alListener3f(AL_VELOCITY, _listenerVelocity.GetX(), _listenerVelocity.GetY(), _listenerVelocity.GetZ());
	}

	ISoundBase* RegisterSound(void)
	{
		return new Sound();
	}
}