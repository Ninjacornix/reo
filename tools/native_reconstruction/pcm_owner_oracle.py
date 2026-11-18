#!/usr/bin/env python3
"""Compile exact reconstructed121 PCM source with a deterministic clock/sink.

No game/device/assets; copied dependency source and all generated harness outputs
stay in ignored build-native-sjuni. This is candidate-source behavior, not an
original EE/IOP oracle. Full CriAudio.cpp is unchanged; preprocessor namespace
indirection replaces only steady_clock while other std names resolve unchanged.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import subprocess

ROOT=Path(__file__).resolve().parents[2]
EXPECTED={
 'Kernel/Syscalls/Helpers/CriAudio.cpp':'39dce6882e561ad69a0112a330ecc4023a98c21365ac2fe8709f838fce4c9a06',
 'Kernel/Syscalls/Helpers/CriAudio.h':'7103ab05367839041672898c6406ca42a41482bff1640e4a1faecfd7aa52f4be',
 'Kernel/Syscalls/Helpers/State.h':'4cab412ab2c6a54e3ff14a6f619ce61c850cae8e3b80d92d86c3bef22eb1b4b8',
 'Kernel/Syscalls/RPC.cpp':'050d63e738481ac592429a21ba317fcb28f86f8d47afe48b2ee4ed8c3dc81a9f',
 'cri_pcm_retire.h':'b7dc48ac1279f07032fbfd1de39049f0da7fd15fac8d73a4f5708912f022cbc8',
}

MOCK_HOST=r'''#pragma once
#include <cstdint>
struct AudioStream {unsigned unused{};};
inline bool IsAudioDeviceReady(){return false;}
inline void SetAudioStreamBufferSizeDefault(int){}
inline AudioStream LoadAudioStream(unsigned,unsigned,unsigned){return {};}
inline bool IsAudioStreamValid(AudioStream){return false;}
inline void SetAudioStreamCallback(AudioStream,void(*)(void*,unsigned)){}
inline void PlayAudioStream(AudioStream){}
inline void StopAudioStream(AudioStream){}
inline void UnloadAudioStream(AudioStream){}
'''
MOCK_BANK=r'''#pragma once
namespace ps2_reo_sound {void mix(float*,unsigned);void reset();void reportAudioPaths();}
'''
MOCK_DIAG=r'''#pragma once
namespace ps2_vblank_music_diag {
enum class Kind{AudioReport,PcmPush,Voice,SjxPoll,PcmRetire,SjxPublished};
template<class... T>void note(Kind,T...){}
}
'''
HARNESS=r'''
#include <algorithm>
#include <bit>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <mutex>
#include <stdexcept>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "snapshot/Kernel/Syscalls/Helpers/CriAudio.h"
#include "snapshot/Kernel/Syscalls/Helpers/ReoSoundBanks.h"
#include "snapshot/ps2_host_backend.h"
#include "snapshot/vblank_music_diag.h"
#include "snapshot/cri_pcm_retire.h"
namespace controlled_clock {inline std::int64_t nanoseconds=0;}
namespace pcm_test_std {
using namespace std;
namespace chrono {
using namespace std::chrono;
struct steady_clock {
    using duration=std::chrono::nanoseconds;
    using rep=duration::rep;using period=duration::period;
    using time_point=std::chrono::time_point<steady_clock>;
    static constexpr bool is_steady=true;
    static time_point now() noexcept{return time_point(duration(controlled_clock::nanoseconds));}
};
}
}
// Include the entire exact source. All ordinary standard names are aliases to
// real std; only its explicitly controlled steady_clock differs.
#define std pcm_test_std
#include "snapshot/Kernel/Syscalls/Helpers/CriAudio.cpp"
#undef std
float master_gain=1,stream_gain=1,bank_add=0;
unsigned bank_mix_calls=0,bank_resets=0,polls=0,route_resets=0;
float reoAudioMasterGain(){return master_gain;}
float reoAudioStreamGain(std::uint32_t){return stream_gain;}
void reoAudioPoll(){++polls;}
void reoAudioResetStreams(){++route_resets;}
namespace ps2_reo_sound {
void mix(float* p,unsigned frames){++bank_mix_calls;if(p)for(unsigned i=0;i<frames*2;++i)p[i]+=bank_add;}
void reset(){++bank_resets;}
void reportAudioPaths(){}
}
namespace rpc_fixture {
#include "rpc_methods.inc"
}

#define CHECK(x) do{if(!(x))throw std::runtime_error(#x);}while(false)
namespace a=ps2_cri_audio;
std::string scenario;
unsigned records=0;
template<class T>void numbers(const T& values){std::cout<<'[';bool comma=false;for(auto v:values){if(comma)std::cout<<',';comma=true;std::cout<<+v;}std::cout<<']';}
void snapshot(const char* operation,const std::vector<float>& pcm={},std::uint64_t result=0){
    std::cout<<"{\"case\":\""<<scenario<<"\",\"operation\":\""<<operation<<"\",\"result_u64\":"<<result
             <<",\"clock_ns\":"<<controlled_clock::nanoseconds<<",\"float_bits\":[";
    for(std::size_t i=0;i<pcm.size();++i){if(i)std::cout<<',';std::cout<<std::bit_cast<std::uint32_t>(pcm[i]);}
    std::cout<<"],\"channels\":[";std::vector<std::uint32_t> keys;
    for(const auto& p:a::channels){keys.push_back(p.first);}std::sort(keys.begin(),keys.end());
    bool comma=false;
    for(auto key:keys){if(comma)std::cout<<',';comma=true;const auto& c=a::channels.at(key);
        std::uint64_t hash=14695981039346656037ULL;
        for(auto v:c.pcm)for(unsigned i=0;i<2;++i){hash^=(static_cast<std::uint16_t>(v)>>(8*i))&255u;hash*=1099511628211ULL;}
        std::cout<<"{\"key\":"<<key<<",\"queued_bytes\":"<<c.queued<<",\"consumed_bytes\":"<<c.consumed<<",\"samples\":"<<c.pcm.size()<<",\"pcm_fnv1a64\":"<<hash<<",\"small_pcm\":";
        if(c.pcm.size()<=32)numbers(c.pcm);else std::cout<<"null";std::cout<<'}';
    }
    std::cout<<"],\"voices\":[";keys.clear();for(const auto& p:a::voices){keys.push_back(p.first);}std::sort(keys.begin(),keys.end());comma=false;
    for(auto key:keys){if(comma)std::cout<<',';comma=true;const auto& v=a::voices.at(key);
        std::cout<<"{\"key\":"<<key<<",\"left\":"<<v.left<<",\"right\":"<<v.right<<",\"channels\":"<<v.channels<<",\"frequency\":"<<v.frequency
                 <<",\"volume\":"<<v.volume<<",\"playing\":"<<(v.playing?"true":"false")<<",\"draining\":"<<(v.draining?"true":"false")
                 <<",\"phase_bits\":"<<std::bit_cast<std::uint64_t>(v.phase)<<",\"late\":"<<v.lateSamples<<",\"skipped\":"<<v.skippedSamples<<'}';
    }
    std::cout<<"],\"output_frames\":"<<a::outputFrames<<",\"signal_frames\":"<<a::signalFrames<<",\"underrun_frames\":"<<a::underrunFrames
             <<",\"external_clock\":"<<(a::externalClock?"true":"false")<<",\"last_tick_ns\":"<<a::lastTick.time_since_epoch().count()<<",\"pending\":[";
    comma=false;for(const auto& p:rpc_fixture::g_pcmPending){if(comma)std::cout<<',';comma=true;
        std::cout<<"{\"ring\":"<<p.ring<<",\"end_byte\":"<<p.endByte<<",\"replied\":"<<(p.replied?"true":"false")<<",\"retired_prefix\":"<<p.consumedPrefix<<'}';}
    std::cout<<"],\"credit_words\":[";
    for(unsigned i=0;i<16;++i){if(i)std::cout<<',';std::uint32_t v;std::memcpy(&v,rpc_fixture::wire+256+4*i,4);std::cout<<v;}
    std::cout<<"],\"ring_data_bytes\":[";keys.clear();for(const auto& p:rpc_fixture::g_dtx_sjrmt_by_handle){keys.push_back(p.first);}std::sort(keys.begin(),keys.end());
    comma=false;for(auto key:keys){if(comma)std::cout<<',';comma=true;const auto& ring=rpc_fixture::g_dtx_sjrmt_by_handle.at(key);std::cout<<'['<<key<<','<<ring.dataBytes<<','<<ring.roomBytes<<']';}
    std::cout<<"]}\n";++records;
}
void start(const char* name,bool external=true){scenario=name;controlled_clock::nanoseconds=0;master_gain=stream_gain=1;bank_add=0;a::reset();
    rpc_fixture::g_pcmPending.clear();rpc_fixture::g_sjxReplies.clear();rpc_fixture::g_dtx_sjrmt_by_handle.clear();rpc_fixture::g_dtx_sjx_by_handle.clear();std::memset(rpc_fixture::wire,0xCC,sizeof(rpc_fixture::wire));
    if(external)a::render(nullptr,0);}
std::uint64_t queue(std::uint32_t key,const std::vector<std::int16_t>& values){std::uint64_t end=0xABCDEF;
    CHECK(a::queue(key,reinterpret_cast<const std::uint8_t*>(values.data()),static_cast<std::uint32_t>(values.size()*2),end));return end;}
void render(unsigned frames){std::vector<float> pcm(frames*2,123.0f);a::render(pcm.data(),frames);snapshot("render",pcm);}
void configure(unsigned channels=1,unsigned rate=48000,unsigned volume=256,bool playing=true){a::configure(10,1,channels>1?2:0,channels,rate,volume,playing);}
int main(){try{
    start("mono");queue(1,{32767,-32768,16384,-8192});configure();render(5);
    start("stereo");queue(1,{16384,8192});queue(2,{-16384,-8192});configure(2);render(3);
    start("half_rate");queue(1,{1000,2000,3000});configure(1,24000);render(5);
    start("double_rate");queue(1,{1000,2000,3000});configure(1,96000);render(3);
    start("44100_fraction");std::vector<std::int16_t> ramp(100);for(unsigned i=0;i<100;++i)ramp[i]=static_cast<std::int16_t>(i*100);queue(1,ramp);configure(1,44100);render(100);
    start("late_catchup");configure();render(3);queue(1,{1,2,3,4,5,6});snapshot("refill");render(2);
    start("pause_phase");queue(1,{1000,2000,3000});configure(1,24000);render(1);configure(1,24000,256,false);render(2);configure(1,24000);render(1);
    start("silent_volume");queue(1,{32767,-32768});configure(1,48000,0);render(2);
    start("drain_override");queue(1,{1000,2000,3000});configure();a::drain(10);configure(1,48000,256,false);snapshot("drain_then_configure_false");render(4);
    start("discard_release");queue(1,{1000,2000,3000});configure();render(1);a::discard(1);snapshot("discard");render(1);a::release(10);snapshot("release");
    start("release_other_voice");queue(1,{1000,2000});queue(2,{3000,4000});configure();a::configure(20,2,0,1,48000,256,true);a::release(10);render(1);
    start("gain_order");queue(1,{32767});configure(1,48000,512);stream_gain=2;master_gain=0.5f;bank_add=0.25f;render(1);
    start("queue_refusals");std::uint8_t bytes[2]{};std::uint64_t end=0x12345678;
    CHECK(!a::queue(0,bytes,2,end));CHECK(!a::queue(1,nullptr,2,end));CHECK(!a::queue(1,bytes,0,end));CHECK(!a::queue(1,bytes,1,end));CHECK(!a::queue(1,bytes,0x4002,end));CHECK(end==0x12345678);snapshot("invalid",{},end);
    start("queue_capacity");std::vector<std::int16_t> chunk(8192,17);for(unsigned i=0;i<11;++i)queue(1,chunk);queue(1,std::vector<std::int16_t>(5888,23));
    end=0x12345678;CHECK(!a::queue(1,bytes,2,end));CHECK(end==0x12345678);snapshot("capacity_reject",{},end);
    start("headless_fraction",false);queue(1,{1000,2000,3000,4000});configure();for(auto ns:{20833LL,20834LL,41666LL,41667LL,-1LL}){controlled_clock::nanoseconds=ns;snapshot("consumed_query",{},a::consumed(1));}
    start("headless_cap",false);for(unsigned i=0;i<3;++i)queue(1,chunk);configure();controlled_clock::nanoseconds=500000000;snapshot("first_query",{},a::consumed(1));snapshot("second_query",{},a::consumed(1));
    for(const auto& test:std::vector<std::pair<const char*,std::pair<unsigned,bool>>>{{"stop_long_unreturned",{72001,true}},{"stop_threshold",{72000,true}},{"stop_long_returned",{72001,false}}}){
        start(test.first);std::vector<std::int16_t> samples(8192,100);unsigned remaining=test.second.first;
        while(remaining){const auto n=std::min(remaining,8192u);queue(1,std::vector<std::int16_t>(n,100));remaining-=n;}configure();
        rpc_fixture::DtxPs2RnaState rna;rna.handle=10;rna.sjHandle0=1;rna.sampleFreq=48000;rna.channelCount=1;rna.playEnabled=true;
        rpc_fixture::g_dtx_sjrmt_by_handle.emplace(1,rpc_fixture::DtxSjrmtState{});
        rpc_fixture::g_pcmPending.push_back({1,4,{0,0,0,4},0,!test.second.second});rpc_fixture::discardUnlessNaturalEnd(rna,1,0);snapshot("stop_policy");
    }
    start("paced_budget");rpc_fixture::DtxPs2RnaState rna;rna.sampleFreq=48000;rna.channelCount=2;rna.sjHandle0=1;rna.sjHandle1=2;
    snapshot("initial",{},rpc_fixture::dtxPacedConsumeBudgetBytes(rna,1000000000));snapshot("ten_ms",{},rpc_fixture::dtxPacedConsumeBudgetBytes(rna,1010000000));
    snapshot("capped",{},rpc_fixture::dtxPacedConsumeBudgetBytes(rna,2010000000));snapshot("backward_unsigned_cap",{},rpc_fixture::dtxPacedConsumeBudgetBytes(rna,100));
    start("sj_credit");queue(1,chunk);queue(1,chunk);configure();
    rpc_fixture::DtxSjrmtState ring;ring.dataBytes=32768;rpc_fixture::g_dtx_sjrmt_by_handle.emplace(1,ring);
    rpc_fixture::g_pcmPending.push_back({1,16384,{9,100,0x400000,16384}});rpc_fixture::g_pcmPending.push_back({1,32768,{9,101,0x404000,16384}});
    rpc_fixture::DtxTransferState transfer;transfer.eeWorkAddr=256;transfer.wkSize=128;
    rpc_fixture::collectSjxReplies(rpc_fixture::wire,transfer);snapshot("initial_credit");
    render(2048);rpc_fixture::collectSjxReplies(rpc_fixture::wire,transfer);snapshot("below_lead");
    render(2048);rpc_fixture::collectSjxReplies(rpc_fixture::wire,transfer);snapshot("at_lead");
    render(4096);rpc_fixture::collectSjxReplies(rpc_fixture::wire,transfer);snapshot("first_retired");
    start("reset_counters");queue(1,{1000});configure();render(1);a::reset();snapshot("reset");a::shutdown();snapshot("shutdown");
    return 0;
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}}
'''

def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()

def block(text,start,terminator='}'):
    at=text.index(start);brace=text.index('{',at);depth=1;end=brace+1
    # These exact small definitions contain no brace literals; whole-source
    # identity is pinned. Refuse ambiguous extracts rather than parse arbitrary C++.
    while depth and end<len(text):
        if text[end]=='{':depth+=1
        if text[end]=='}':depth-=1
        end+=1
    if depth:raise ValueError('Unclosed exact definition')
    if terminator==';':
        if text[end]!=';':raise ValueError('Expected complete struct terminator')
        end+=1
    return text[at:end]

def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--dependency',type=Path,default=ROOT/'build-native-sjuni/dependency-workers-v1')
    p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);args=p.parse_args()
    dep=args.dependency.resolve()/'ps2xRuntime/src/lib';out=args.output.resolve();allowed=ROOT/'build-native-sjuni'
    if out==allowed or not out.is_relative_to(allowed):p.error('Use a private ignored output')
    compiler=shutil.which(args.cxx)
    if not compiler:p.error('Existing C++20 compiler required')
    out.mkdir(parents=True,exist_ok=True);identities={}
    for name,expected in EXPECTED.items():
        actual=sha(dep/name)
        if expected and actual!=expected:raise ValueError('Reconstructed121 source changed: '+name)
        identities[name]=actual
    snapshot=out/'snapshot';helpers=snapshot/'Kernel/Syscalls/Helpers';helpers.mkdir(parents=True,exist_ok=True)
    for name in ('CriAudio.cpp','CriAudio.h'):shutil.copyfile(dep/'Kernel/Syscalls/Helpers'/name,helpers/name)
    (helpers/'ReoSoundBanks.h').write_text(MOCK_BANK);(snapshot/'ps2_host_backend.h').write_text(MOCK_HOST)
    (snapshot/'vblank_music_diag.h').write_text(MOCK_DIAG)
    rpc=(dep/'Kernel/Syscalls/RPC.cpp').read_text();state=(dep/'Kernel/Syscalls/Helpers/State.h').read_text()
    parts=[block(state,'struct '+s,';') for s in ('DtxSjxState','DtxPs2RnaState','DtxSjrmtState','DtxTransferState')]
    parts+=['std::unordered_map<uint32_t,DtxSjxState> g_dtx_sjx_by_handle;',
            'std::unordered_map<uint32_t,DtxSjrmtState> g_dtx_sjrmt_by_handle;']
    parts+=[block(rpc,'struct '+s,';') for s in ('SjxReply','PcmPending')]
    parts+=['std::deque<PcmPending> g_pcmPending;std::deque<SjxReply> g_sjxReplies;',
        'std::mutex g_dtx_rpc_mutex;'+re.search(r'constexpr uint64_t kIopPcmBufferBytes=[^;]+;',rpc).group(0),
        'uint8_t wire[1024];',
        'uint8_t* getMemPtr(uint8_t* p,uint32_t at){if(p!=wire||at>sizeof(wire)-16)throw std::runtime_error("mock wire bounds");return p+at;}',
        'void writeGuestU32(uint8_t* p,uint32_t at,uint32_t v){std::memcpy(getMemPtr(p,at),&v,4);}']
    methods=['uint32_t resolveRnaRing(','void discardUnlessNaturalEnd(','uint32_t dtxPacedConsumeBudgetBytes(','void collectSjxReplies(']
    extracted={s:block(rpc,s) for s in methods};parts+=list(extracted.values())
    (out/'rpc_methods.inc').write_text('\n'.join(parts)+'\n')
    shutil.copyfile(dep/'cri_pcm_retire.h',snapshot/'cri_pcm_retire.h')
    harness=out/'probe.cpp';harness.write_text(HARNESS);exe=out/'probe.exe'
    env=dict(os.environ)
    for key in list(env):
        if key.startswith(('REO_CRI_','REO_AUDIO_PATH','REO_RNA_STOP')):env.pop(key,None)
    cc=Path(compiler).resolve();bins=[cc.parent,cc.parent.parent/'x86_64-w64-mingw32/bin']
    env['PATH']=os.pathsep.join(str(b) for b in bins if b.is_dir())+os.pathsep+env.get('PATH','')
    command=[compiler,'-std=c++20','-O1','-Wall','-Wextra','-Wpedantic','-Werror','-I'+str(snapshot),str(harness),'-o',str(exe)]
    receipt=dict(schema=1,status='running',source_sha256=identities,tool_sha256=sha(Path(__file__)),
        extracted_method_sha256={k:hashlib.sha256(v.encode()).hexdigest() for k,v in extracted.items()},
        compiler=compiler,compiler_sha256=sha(cc),command=command,game_run=False,device_opened=False,assets_read=False)
    try:
        build=subprocess.run(command,env=env,capture_output=True,text=True,timeout=90)
        receipt['compile']={'exit_code':build.returncode,'stderr':build.stderr}
        if build.returncode:raise RuntimeError(build.stderr)
        run=subprocess.run([str(exe)],env=env,capture_output=True,text=True,timeout=30)
        receipt['execution']={'exit_code':run.returncode,'stderr':run.stderr}
        if run.returncode:raise RuntimeError(run.stderr)
        rows=[json.loads(line) for line in run.stdout.splitlines()]
        (out/'fixtures.json').write_text(json.dumps(dict(schema=1,source_sha256=identities,records=rows),indent=2)+'\n')
        def find(case,op='render'):return next(row for row in rows if row['case']==case and row['operation']==op)
        assert find('mono')['channels'][0]['consumed_bytes']==8
        assert find('half_rate')['channels'][0]['consumed_bytes']==4
        assert find('double_rate')['voices'][0]['late']==3
        assert find('late_catchup','refill')['voices'][0]['late']==3
        assert [r for r in rows if r['case']=='late_catchup' and r['operation']=='render'][-1]['voices'][0]['skipped']==3
        assert find('queue_capacity','capacity_reject')['channels'][0]['samples']==96000
        assert find('stop_long_unreturned','stop_policy')['voices']==[]
        assert find('stop_threshold','stop_policy')['voices'][0]['draining']
        assert find('stop_long_returned','stop_policy')['voices'][0]['draining']
        assert find('paced_budget','ten_ms')['result_u64']==960
        assert find('paced_budget','capped')['result_u64']==24000
        assert find('headless_cap','first_query')['result_u64']==24000
        assert find('headless_cap','second_query')['result_u64']==48000
        assert find('gain_order')['float_bits']==[1059061760,1059061760] #0.625f
        credit=find('sj_credit','initial_credit');assert credit['credit_words'][0]==1 and credit['channels'][0]['consumed_bytes']==0
        assert credit['pending'][0]['replied'] and not credit['pending'][1]['replied']
        assert find('sj_credit','below_lead')['credit_words'][0]==0
        assert find('sj_credit','at_lead')['credit_words'][0]==1
        retired=find('sj_credit','first_retired');assert len(retired['pending'])==1 and retired['ring_data_bytes'][0][1]==16384
        receipt.update(status='passed',cases=len({r['case'] for r in rows}),records=len(rows),fixture_sha256=sha(out/'fixtures.json'),fixture_bytes=(out/'fixtures.json').stat().st_size)
    except Exception as error:receipt.update(status='failed',failure=str(error));raise
    finally:
        receipt['limitations']=['Candidate-source behavior, not original EE/IOP parity.',
            'Real source mutex/containers, mocked clock/audio/gain/bank/diagnostics; no actual device or bank mixer.',
            'RPC stop/budget/credit methods exact-extracted against finite mock protocol maps/wire, not the whole RPC entry or original EE/IOP.',
            'Large queues record bounded count+FNV digest, not full serialized content.']
        (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print(json.dumps({k:receipt[k] for k in ('status','cases','records','fixture_bytes','fixture_sha256')}))

if __name__=='__main__':main()
