#ifndef SOUND_H
#define SOUND_H

#include "Vector3.h"

#include "../../SDK/Sapi/SoundBase.h"
#include "../../SDK/Platform.h"

#include "../StdAfx.h"

namespace Sapi
{
	class Sound : public ISoundBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		Sound(void);

		/// <summary>Деструктор класса.</summary>
		virtual ~Sound(void);

		virtual void SetALBuffer(IBufferBase* buffer);

		/// <summary>Запускает воспроизведение звука.</summary>
		virtual void Play(void);

		virtual bool HasPlaying(void) const;

		/// <summary>Останавливает воспроизведение звука.</summary>
		virtual void Stop(void);

		virtual bool HasStopped(void) const;

		/// <summary>Ставит на паузу воспроизведение.</summary>
		virtual void Pause(void);

		virtual bool HasPaused(void) const;

		virtual void Rewind(void);

		/// <summary>Использование циклического воспроизведение.</summary>
		virtual void UseLooping(bool looping);

		virtual bool HasLooping(void) const;

		/// <summary>Устанавливает координаты источника звука.</summary>
		virtual void SetSourcePosition(float x, float y, float z);

		/// <summary>Устанавливает координаты источника звука.</summary>
		virtual void SetSourcePosition(Math::Vec3F position);

		virtual void SetSourceVelocity(float x, float y, float z);

		virtual void SetSourceVelocity(Math::Vec3F velocity);

		/// <summary>Устанавливает координаты слушателя.</summary>
		virtual void SetListenerPosition(float x, float y, float z);

		/// <summary>Устанавливает координаты слушателя.</summary>
		virtual void SetListenerPosition(Math::Vec3F position);

		virtual void SetListenerVelocity(float x, float y, float z);

		virtual void SetListenerVelocity(Math::Vec3F velocity);

	private:
		ALuint _source;
		IBufferBase* _buffer;

		Math::Vec3F _sourcePosition; // Координаты источника звука.
		Math::Vec3F _sourceVelocity;

		Math::Vec3F _listenerPosition; // Координаты слушателя.
		Math::Vec3F _listenerVelocity;

		bool _isLooping;
	};
}

#endif // SOUND_H