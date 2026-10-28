#include <cstdint>
// Match the independent SDK callers; this translation unit has no bridge header.
float reoAudioMasterGain();
float reoAudioStreamGain(uint32_t);
float reoAudioBankGain(unsigned,unsigned,uint64_t);
void reoAudioResetStreams();
void reoAudioPoll();
float bridgeApiRoundtrip() {
    reoAudioPoll();
    reoAudioResetStreams();
    return reoAudioMasterGain()+reoAudioStreamGain(0x9876)+reoAudioBankGain(0,0,0);
}
