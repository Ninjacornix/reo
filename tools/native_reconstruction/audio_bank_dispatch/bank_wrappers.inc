// Playback facade: selection/admission precedes every source side effect.
bool submitBank(unsigned port,const uint8_t* hd,size_t hn,const uint8_t* bd,size_t bn,const uint8_t* tq,size_t tn) {
    auto call=ps2_cri_audio::acquireSoundCall();return call.submit_bank(port,hd,hn,bd,bn,tq,tn)==ps2_cri_audio::BankStatusV2::ok;
}
bool submitPacket(const uint8_t* ram,size_t ramBytes,const uint8_t* packet,size_t bytes) {
    auto call=ps2_cri_audio::acquireSoundCall();return call.submit_packet(ram,ramBytes,packet,bytes)==ps2_cri_audio::BankStatusV2::ok;
}
void mix(float* out,unsigned frames) {auto call=ps2_cri_audio::acquireSoundCall();(void)call.mix(out,frames);}
void reset() {auto call=ps2_cri_audio::acquireSoundCall();(void)call.reset_banks();}
uint32_t pendingLoads() {auto call=ps2_cri_audio::acquireSoundCall();auto result=call.pending_loads();return result.status==ps2_cri_audio::BankStatusV2::ok?result.value:0;}
uint32_t portState(unsigned port,uint32_t& count) {auto call=ps2_cri_audio::acquireSoundCall();auto result=call.port_state(port,count);return result.status==ps2_cri_audio::BankStatusV2::ok?result.value:0;}
uint32_t seState(unsigned port,unsigned index,unsigned group) {auto call=ps2_cri_audio::acquireSoundCall();auto result=call.se_state(port,index,group);return result.status==ps2_cri_audio::BankStatusV2::ok?result.value:0;}
void reportAudioPaths() {auto call=ps2_cri_audio::acquireSoundCall();(void)call.report_audio_paths();}
