#pragma once
// Device absent by construction. Any attempt to open/play a stream is an error.
#include <cstdlib>
struct AudioStream { unsigned unused{}; };
inline bool IsAudioDeviceReady() { return false; }
inline void SetAudioStreamBufferSizeDefault(int) { std::abort(); }
inline AudioStream LoadAudioStream(unsigned,unsigned,unsigned) { std::abort(); }
inline bool IsAudioStreamValid(AudioStream) { std::abort(); }
inline void SetAudioStreamCallback(AudioStream,void(*)(void*,unsigned)) { std::abort(); }
inline void PlayAudioStream(AudioStream) { std::abort(); }
inline void StopAudioStream(AudioStream) { std::abort(); }
inline void UnloadAudioStream(AudioStream) { std::abort(); }
