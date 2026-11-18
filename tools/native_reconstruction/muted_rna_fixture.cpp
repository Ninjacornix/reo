// Explicit runtime/admission/configure ports. No audio device or game launch.
#include <algorithm>
#include <array>
#include <chrono>
#include <cstdint>
#include <iostream>
#include <map>
#include <mutex>
#include <stdexcept>
#include <unordered_map>
#include <vector>
unsigned checks{}, snapshots{};
void check(bool value){++checks;if(!value)throw std::runtime_error("muted RNA comparison failed");}
class PS2Runtime {};
PS2Runtime owner, foreign;
bool admitted=true,native=true,ram_selected=true;
unsigned leases{},scopes{};
using Row=std::array<uint32_t,7>;
std::vector<Row> requests;
std::unordered_map<uint32_t,Row> original_raw,native_raw;
std::unordered_map<uint32_t,Row>* destination=&native_raw;
namespace ps2_cri_audio {
struct SoundCall {bool allowed{};explicit operator bool()const noexcept{return allowed;}bool native()const noexcept{return ::native;}};
SoundCall acquireSoundControlCall(PS2Runtime* runtime)noexcept{++leases;return{runtime==&owner && admitted};}
bool nativeSoundRamSelectedV1()noexcept{return ram_selected;}
struct SoundCallScope {explicit SoundCallScope(const SoundCall& call){check(bool(call));++scopes;}~SoundCallScope(){--scopes;}};
void configure(uint32_t h,uint32_t l,uint32_t r,uint32_t c,uint32_t f,uint32_t v,bool p){
    check(scopes==1);Row row{h,l,r,c,f,v,uint32_t(p)};requests.push_back(row);(*destination)[h]=row;
}
}
namespace ps2_syscalls {
#include "sdk_declarations.inc"
#include "sdk_states.inc"
struct Layout {
    uint32_t urpcObjBase=0x1e0000,urpcObjLimit=0x1eff20,urpcObjStride=0x20;
    bool hasUrpcObjectRange()const{return urpcObjBase && urpcObjLimit>urpcObjBase && urpcObjStride;}
} g_dtxCompatLayout;
std::mutex g_dtx_rpc_mutex;
#include "sdk_helpers.inc"
#include "original_muted.inc"
#include "native_muted.inc"
}
namespace s=ps2_syscalls;
using Status=s::RnaMetadataStatusV1;
std::vector<std::array<uint64_t,10>> state(){
    std::vector<std::array<uint64_t,10>> out;
    for(const auto& [key,r]:s::g_dtx_ps2rna_by_handle)out.push_back({key,r.handle,r.maxChannels,r.sjHandle0,r.sjHandle1,r.channelCount,r.sampleFreq,r.volume,r.playEnabled,r.lastConsumeNs});
    return out;
}
std::vector<uint32_t> order(const std::unordered_map<uint32_t,Row>& map){std::vector<uint32_t> out;for(const auto& r:map)out.push_back(r.first);return out;}
void compare(){
    const auto before=state();destination=&original_raw;requests.clear();
    {ps2_cri_audio::SoundCallScope scope(ps2_cri_audio::acquireSoundControlCall(&owner));s::originalMuted();}
    const auto expected=requests;
    // The reference stamps the original consumption clock even while muted.
    // The new metadata-only operation deliberately does not stamp that clock.
    for(const auto& row:before)s::g_dtx_ps2rna_by_handle.at(uint32_t(row[0])).lastConsumeNs=row[9];
    destination=&native_raw;requests.clear();const auto actual=s::refreshMutedRnaMetadataV1(&owner);
    check(actual.status==Status::ok && actual.rows==before.size() && actual.requests==expected.size() && !actual.bad_handle);
    check(requests==expected && state()==before && original_raw==native_raw && order(original_raw)==order(native_raw) && !scopes);
    ++snapshots;
}
void refuse(Status status,PS2Runtime* runtime=&owner){
    const auto before=state();const auto prior=native_raw;requests.clear();
    const auto result=s::refreshMutedRnaMetadataV1(runtime);
    check(result.status==status && result.requests==0 && requests.empty() && state()==before && native_raw==prior && !scopes);
}
void add(unsigned index){
    const auto key=0x1e0000u+index*0x20u;
    s::DtxPs2RnaState r{};r.handle=key;r.maxChannels=r.channelCount=index%2+1;r.sampleFreq=index%2?44100:48000;r.volume=256-index;
    r.sjHandle0=0x1000+index*4;r.sjHandle1=r.channelCount==2?r.sjHandle0+1:0;r.lastConsumeNs=100+index;
    s::DtxSjrmtState direct{};direct.handle=r.sjHandle0;s::g_dtx_sjrmt_by_handle[r.sjHandle0]=direct;
    if(r.sjHandle1){s::DtxSjxState link{};link.handle=r.sjHandle1;link.dstSjHandle=0x2000+index;s::g_dtx_sjx_by_handle[r.sjHandle1]=link;}
    s::g_dtx_ps2rna_by_handle[key]=r;
}
int main(){try{
    refuse(Status::control_refused,nullptr);refuse(Status::control_refused,&foreign);
    admitted=false;refuse(Status::control_refused);admitted=true;
    native=false;refuse(Status::unselected);native=true;
    ram_selected=false;refuse(Status::unselected);ram_selected=true;
    compare();
    for(unsigned i=0;i<32;++i){add(i);compare();}
    auto& changed=s::g_dtx_ps2rna_by_handle.at(0x1e0080);changed.sampleFreq=32000;changed.volume=77;changed.sjHandle0=0xdead;compare();
    s::g_dtx_ps2rna_by_handle.erase(0x1e0080);original_raw.erase(0x1e0080);native_raw.erase(0x1e0080);compare();add(4);compare();
    auto& bad=s::g_dtx_ps2rna_by_handle.at(0x1e0000);
    bad.playEnabled=true;refuse(Status::playing_legacy);bad.playEnabled=false;
    bad.handle+=1;refuse(Status::invalid_metadata);bad.handle-=1;
    bad.channelCount=3;refuse(Status::invalid_metadata);bad.channelCount=1;
    bad.maxChannels=0;refuse(Status::invalid_metadata);bad.maxChannels=1;
    s::g_dtxCompatLayout.urpcObjStride=0;refuse(Status::invalid_metadata);s::g_dtxCompatLayout.urpcObjStride=0x20;
    s::g_dtxCompatLayout.urpcObjBase+=1;refuse(Status::invalid_metadata);s::g_dtxCompatLayout.urpcObjBase-=1;
    // Complete preflight must precede every request, including malformed rows
    // encountered after valid rows in the actual unsorted table traversal.
    s::g_dtx_ps2rna_by_handle.clear();s::g_dtx_sjx_by_handle.clear();s::g_dtx_sjrmt_by_handle.clear();original_raw.clear();native_raw.clear();compare();
    add(3);add(0);add(2);compare();
    for(unsigned i=0;i<2042;++i)add(i);refuse(Status::invalid_metadata);
    std::cout<<"{\"checks\":"<<checks<<",\"snapshots\":"<<snapshots<<",\"game_run\":false,\"device_opened\":false}\n";
    return 0;
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}}
