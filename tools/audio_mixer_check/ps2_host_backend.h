#pragma once
// Headless device boundary only: the production mixers still render every sample.
struct AudioStream { unsigned unused=0; };
inline bool IsAudioDeviceReady() { return false; }
inline void SetAudioStreamBufferSizeDefault(int) {}
inline AudioStream LoadAudioStream(unsigned,unsigned,unsigned) { return {}; }
inline bool IsAudioStreamValid(AudioStream) { return false; }
inline void SetAudioStreamCallback(AudioStream,void(*)(void*,unsigned)) {}
inline void PlayAudioStream(AudioStream) {}
inline void StopAudioStream(AudioStream) {}
inline void UnloadAudioStream(AudioStream) {}
