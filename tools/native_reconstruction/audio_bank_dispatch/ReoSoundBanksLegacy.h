#pragma once
// Internal source implementation only. Public playback callers use the shared
// selected SoundCall; standalone Bank/Sequence utilities remain unselected.
#include "ReoSoundBanks.h"
namespace ps2_reo_sound::legacy_detail {
bool submitBank(unsigned,const uint8_t*,size_t,const uint8_t*,size_t,const uint8_t*,size_t);
bool submitPacket(const uint8_t*,size_t,const uint8_t*,size_t);
void mix(float*,unsigned);
void reset();
uint32_t pendingLoads();
uint32_t portState(unsigned,uint32_t&);
uint32_t seState(unsigned,unsigned,unsigned);
void reportAudioPaths();
}
