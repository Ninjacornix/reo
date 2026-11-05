// Identical synthetic caller/hook transcript for exact-source and bridge builds.
float master_gain=1,stream_gain=1,bank_add=0;
std::vector<std::string> events;
float reoAudioMasterGain(){events.push_back("master");return master_gain;}
float reoAudioStreamGain(std::uint32_t id){events.push_back("gain:"+std::to_string(id));return stream_gain;}
void reoAudioPoll(){events.push_back("poll");}
void reoAudioResetStreams(){events.push_back("routes-reset");}
namespace ps2_reo_sound {
void mix(float* p,unsigned frames){events.push_back("banks-mix");if(p)for(unsigned n=0;n<frames*2;++n)p[n]+=bank_add;}
void reset(){events.push_back("banks-reset");}
void reportAudioPaths(){}
}
namespace a=ps2_cri_audio;
void observe(const char* label,std::uint64_t result=0,const std::vector<float>& pcm={}) {
    std::cout<<"{\"case\":\""<<label<<"\",\"result_u64\":"<<result<<",\"events\":[";
    for(std::size_t n=0;n<events.size();++n){if(n)std::cout<<',';std::cout<<'"'<<events[n]<<'"';}
    std::cout<<"],\"float_bits\":[";
    for(std::size_t n=0;n<pcm.size();++n){if(n)std::cout<<',';std::cout<<std::bit_cast<std::uint32_t>(pcm[n]);}
    std::cout<<"],\"raw_voice_order\":[";
    bool comma=false;for(const auto& row:a::voices){if(comma)std::cout<<',';comma=true;std::cout<<row.first;}
    std::cout<<"],\"voice_state\":[";
    std::vector<std::uint32_t> keys;for(const auto& row:a::voices)keys.push_back(row.first);
    std::sort(keys.begin(),keys.end());comma=false;
    for(auto key:keys){if(comma)std::cout<<',';comma=true;const auto& v=a::voices.at(key);
        std::cout<<'['<<key<<','<<std::bit_cast<std::uint32_t>(v.mixerGain)<<','<<v.lateSamples<<','<<v.skippedSamples<<','<<std::bit_cast<std::uint64_t>(v.phase)<<']';}
    std::cout<<"],\"channel_state\":[";keys.clear();for(const auto& row:a::channels)keys.push_back(row.first);
    std::sort(keys.begin(),keys.end());comma=false;
    for(auto key:keys){if(comma)std::cout<<',';comma=true;const auto& c=a::channels.at(key);std::cout<<'['<<key<<','<<c.queued<<','<<c.consumed<<','<<c.pcm.size()<<']';}
    std::cout<<"],\"output_frames\":"<<a::outputFrames<<",\"signal_frames\":"<<a::signalFrames<<",\"underrun_frames\":"<<a::underrunFrames
        <<",\"frame_clock\":"<<(a::externalClock?"true":"false")<<",\"last_tick_ns\":"<<a::lastTick.time_since_epoch().count()<<"}\n";
}
void accepted_queue(std::uint32_t key,unsigned count){
    std::vector<std::int16_t> data(count,1000);std::uint64_t end=0;
    if(!a::queue(key,reinterpret_cast<const std::uint8_t*>(data.data()),count*2,end))throw std::runtime_error("extra queue refused");
}
int main(){try{
    controlled_clock::nanoseconds=0;a::reset();events.clear();
    a::ensureHostOutput();observe("ensure_bank_only");events.clear();
    std::uint64_t end=123;
    if(a::queue(0,nullptr,0,end))throw std::runtime_error("invalid queue admitted");
    observe("invalid_queue_before_host",end);
    accepted_queue(1,8192);accepted_queue(1,8192);accepted_queue(1,8192);
    a::configure(10,1,0,1,48000,256,true);
    stream_gain=.25f;controlled_clock::nanoseconds=1000000000;events.clear();
    a::configure(20,2,0,1,48000,256,true);observe("cap_tick_before_insert");
    events.clear();a::render(nullptr,0);observe("zero_null_refreshes_all_and_bank_master");
    stream_gain=.5f;bank_add=.25f;master_gain=2;events.clear();
    std::vector<float> pcm(2,123);a::render(pcm.data(),1);observe("cri_bank_master_order",0,pcm);
    events.clear();a::reset();observe("reset_preserves_bank_and_totals");
    controlled_clock::nanoseconds=0;events.clear();a::configure(0,1,0,0,48000,256,true);
    accepted_queue(1,2);a::drain(0);events.clear();
    a::render(nullptr,0);observe("disabled_drain_gain_refresh");
    events.clear();a::shutdown();observe("shutdown_routes_before_banks");
    return 0;
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}}
