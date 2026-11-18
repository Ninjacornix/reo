#!/usr/bin/env python3
"""Transport original missing/shared-channel and headless API observations.

The test bridge owns raw-ID metadata and supplies observed container order. PCM,
queue storage, resampling/debt and time advancement execute only the native core.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess

ROOT=Path(__file__).resolve().parents[4]
HERE=Path(__file__).resolve().parent
CORE='fe31c38f6c276c60c1f1f7cbf5bea2d9132b83c85fd0b49629b0ca721bf4e844'
HEADER='9fe0aff92070569bfd6744856ea438b92099ec38f1875dc660261ef755b659cb'
FIXTURES={'15547497f2fa81c1c9f50f40ddc5a67f5b84176dfe3d552e6a939e4a63c86206',
          'b3fcb8285711942c47fa3d644f1d236c8474db5442428d81b1bd911b90edd6e8'}
PREFIX=r'''
#include "pcm.hpp"
#include <algorithm>
#include <array>
#include <bit>
#include <cstdint>
#include <iostream>
#include <map>
#include <stdexcept>
#include <vector>
using namespace reo::native::pcm;
void check(bool value){if(!value)throw std::runtime_error("native source-domain snapshot mismatch");}
void ok(Status value){check(value==Status::ok);}
template<class T>T take(Result<T> value){ok(value.status);return value.value;}
struct BoundChannel {Channel handle;bool visible{};};
struct BoundVoice {Voice handle;std::uint32_t left{},right{};};
int main(){try{
 Config config;config.max_voices=config.max_channels=64;
 config.allow_missing_channels=config.allow_shared_channels=true;
 Session session(config);std::int64_t now=0;
 std::map<std::uint32_t,BoundChannel> channels;
 std::map<std::uint32_t,BoundVoice> voices;
 std::map<std::uint32_t,float> gains;
 auto channel=[&](std::uint32_t id){if(!id)return Channel{};auto it=channels.find(id);if(it==channels.end())it=channels.emplace(id,BoundChannel{take(session.create_channel()),false}).first;return it->second.handle;};
 auto voice=[&](std::uint32_t id){auto it=voices.find(id);if(it==voices.end())it=voices.emplace(id,BoundVoice{take(session.create_voice()),0,0}).first;return it->second.handle;};
 auto declare=[&](std::initializer_list<std::uint32_t> ids){std::vector<Voice> order;for(auto id:ids)order.push_back(voices.at(id).handle);ok(session.set_mix_order(order));};
 auto capture=[&](std::initializer_list<std::uint32_t> ids){for(auto id:ids)ok(session.gain(voices.at(id).handle,gains.at(id)));};
 // Only decide whether the facade should refresh host gain snapshots. Native
 // code performs the sole advancement, quantization, cap and remainder update.
 auto due=[&]{const auto clock=session.clock();return !clock.frame_clock&&now>clock.last_tick_ns&&
     (static_cast<std::uint64_t>(now)-static_cast<std::uint64_t>(clock.last_tick_ns))>=20834;};
'''


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def u(value):
    value=int(value)
    if not 0<=value<=0xffffffff:raise ValueError('Word outside source domain')
    return str(value)+'u'


def ids(values):return '{'+','.join(u(value) for value in values)+'}'


def state_checks(state):
    code=['{auto clock=session.clock();check(clock.frame_clock=='+str(state['frame_clock']).lower()+
          '&&clock.last_tick_ns=='+str(int(state['last_tick_ns']))+'ll);}',
          'check(voices.size()=='+str(len(state['voices']))+');',
          'check(std::count_if(channels.begin(),channels.end(),[](const auto& p){return p.second.visible;})=='+str(len(state['channels']))+');']
    if state['master_gain_bits']!=1065353216:raise ValueError('Non-unity master outside this core comparison')
    for voice in state['voices']:
        code.append('{const auto& bound=voices.at('+u(voice['key'])+');auto v=take(session.inspect(bound.handle));check('
            'bound.left=='+u(voice['left'])+'&&bound.right=='+u(voice['right'])+
            '&&static_cast<std::uint32_t>(v.channels)=='+u(voice['channels'])+
            '&&v.frequency=='+u(voice['frequency'])+'&&v.volume=='+u(voice['volume'])+
            '&&v.playing=='+str(voice['playing']).lower()+'&&v.draining=='+str(voice['draining']).lower()+
            '&&std::bit_cast<std::uint32_t>(gains.at('+u(voice['key'])+'))=='+u(voice['gain_bits'])+
            '&&std::bit_cast<std::uint32_t>(v.gain)=='+u(voice['cached_mixer_gain_bits'])+
            '&&std::bit_cast<std::uint64_t>(v.phase)=='+str(int(voice['phase_bits']))+'ull&&v.late_samples=='+str(int(voice['late']))+
            'ull&&v.skipped_samples=='+str(int(voice['skipped']))+'ull);}')
    for channel in state['channels']:
        code.append('{const auto& b=channels.at('+u(channel['key'])+');check(b.visible);auto c=take(session.inspect(b.handle));check('
            'c.queued_bytes=='+str(int(channel['queued_bytes']))+'ull&&c.consumed_bytes=='+str(int(channel['consumed_bytes']))+
            'ull&&c.samples=='+str(int(channel['sample_count']))+'ull);std::vector<std::int16_t> actual(c.samples);'
            'ok(session.copy_samples(b.handle,actual));check(actual==std::vector<std::int16_t>{'+','.join(str(int(x)) for x in channel['samples_i16'])+'});}')
    code.append('{auto s=session.statistics();check(s.output_frames=='+str(int(state['output_frames']))+'ull&&s.signal_frames=='+
        str(int(state['signal_frames']))+'ull&&s.underrun_frames=='+str(int(state['underrun_frames']))+'ull);}')
    return code


def source(fixture):
    rows={(r['case'],r['action_index']):r for r in fixture['records']}
    code=[PREFIX];observations=0
    for case in fixture['inputs']:
        for index,action in enumerate(case['actions']):
            kind=action['kind'];row=rows.get((case['case'],index))
            if 'now_ns' in action:code.append('now='+str(int(action['now_ns']))+'ll;')
            if row:
                if row['operation']!=action['operation']:raise ValueError('Observation correspondence changed')
                code.extend(state_checks(row['pre_state']))
                before=row['declared_raw_order']
            else:before=[]
            if kind=='reset':
                code.append('ok(session.reset(now));channels.clear();voices.clear();gains.clear();')
                if action['frame_clock']:code.append('ok(session.select_frame_clock());')
            elif kind=='gain':code.append('gains['+u(action['voice'])+']=std::bit_cast<float>('+u(action['value_f32_bits'])+');')
            elif kind=='queue':
                if not row:code.append('check(!due());')
                samples=action['samples_i16']
                if not 1<=len(samples)<=64 or any(not -32768<=int(v)<=32767 for v in samples):raise ValueError('Queue exceeds corpus domain')
                code.append('{auto h=channel('+u(action['channel'])+');std::vector<std::int16_t> data{'+','.join(str(int(v)) for v in samples)+
                    '};take(session.enqueue(h,{reinterpret_cast<const std::byte*>(data.data()),data.size()*2},now));channels.at('+u(action['channel'])+').visible=true;}')
            elif kind in ('configure','configure_observe'):
                raw=u(action['voice']);nch=min(int(action['channels']),2)
                if not row:code.append('check(!due());')
                code.append('{auto h=voice('+raw+');')
                if row:
                    staged=before+([] if action['voice'] in before else [action['voice']])
                    code.append('declare('+ids(staged)+');if(due())capture('+ids(before)+');')
                code.append('ok(session.configure(h,{channel('+u(action['left'])+'),'+('channel('+u(action['right'])+')' if nch==2 else 'Channel{}')+
                    ',static_cast<Channels>('+u(nch)+'),'+u(action['frequency'])+','+u(action['volume'])+','+str(action['playing']).lower()+
                    '},now));voices.at('+raw+').left='+u(action['left'])+';voices.at('+raw+').right='+u(action['right'])+';}')
            elif kind=='release':
                code.append('{auto it=voices.find('+u(action['voice'])+');if(it!=voices.end()){ok(session.release(it->second.handle));voices.erase(it);}}')
            elif kind in ('drain','discard'):
                mapping='voices' if kind=='drain' else 'channels';key=u(action['voice'] if kind=='drain' else action['channel'])
                code.append('{auto it='+mapping+'.find('+key+');if(it!='+mapping+'.end())ok(session.'+kind+'(it->second.handle));}')
            elif kind=='render_observe':
                frames=int(action['frames'])
                if not 0<=frames<=64:raise ValueError('Frame bound exceeded')
                code.append('declare('+ids(before)+');capture('+ids(before)+');{std::vector<float> output('+str(frames*2)+',123);ok(session.render(output));')
                for pos,bits in enumerate(row['float_bits']):code.append('check(std::bit_cast<std::uint32_t>(output.at('+str(pos)+'))=='+u(bits)+');')
                code.append('}')
            elif kind=='consumed_observe':
                raw=u(action['channel'])
                code.append('declare('+ids(before)+');if(due())capture('+ids(before)+');{auto it=channels.find('+raw+');std::uint64_t result=0;'
                    'if(it==channels.end())ok(session.advance_headless(now));else result=take(session.consumed(it->second.handle,now));'
                    'check(result=='+str(int(row['result_u64']))+'ull);}')
            elif kind!='state_observe':raise ValueError('Unknown source operation')
            if row:
                code.extend(state_checks(row['state']));observations+=1
    if observations!=36:raise ValueError('Incomplete original corpus')
    code.append('std::cout<<"36 source-domain observations matched\\n";return 0;}catch(const std::exception& e){std::cerr<<e.what()<<"\\n";return 1;}}')
    return '\n'.join(code)+'\n'


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--fixture',required=True,type=Path);parser.add_argument('--cxx',required=True)
    parser.add_argument('--output',required=True,type=Path);args=parser.parse_args()
    out=args.output.resolve();tool=shutil.which(args.cxx)
    if not tool or out==ROOT/'build-native-sjuni' or not out.is_relative_to(ROOT/'build-native-sjuni'):raise ValueError('Private output/compiler required')
    if sha(args.fixture) not in FIXTURES or sha(HERE.parent/'pcm.cpp')!=CORE or sha(HERE.parent/'pcm.hpp')!=HEADER:raise ValueError('Independent core/corpus changed')
    fixture=json.loads(args.fixture.read_text(encoding='utf-8'))
    if fixture['schema']!=2:raise ValueError('Unknown fixture schema')
    out.mkdir(parents=True,exist_ok=True);probe=out/'probe.cpp';exe=out/'probe.exe'
    probe.write_text(source(fixture),encoding='utf-8',newline='\n')
    command=[tool,'-std=c++20','-O1','-ffp-contract=off','-Wall','-Wextra','-Wpedantic','-Werror','-pthread','-I'+str(HERE.parent),str(probe),str(HERE.parent/'pcm.cpp'),'-o',str(exe)]
    env=dict(os.environ);env['PATH']=str(Path(tool).resolve().parent)+os.pathsep+env.get('PATH','')
    build=subprocess.run(command,env=env,capture_output=True,text=True,timeout=90)
    if build.returncode:raise RuntimeError(build.stderr)
    run=subprocess.run([str(exe)],env=env,capture_output=True,text=True,timeout=30)
    proof=dict(schema=1,status='passed' if run.returncode==0 else 'failed',cases=19,observations=36,state_images=72,float_values=228,
        fixture_sha256=sha(args.fixture),native_core_sha256=CORE,native_header_sha256=HEADER,compiler_sha256=sha(Path(tool)),
        comparator_sha256=sha(Path(__file__)),probe_sha256=sha(probe),executable_sha256=sha(exe),command=command,
        exit_code=run.returncode,stdout=run.stdout,stderr=run.stderr,game_run=False,device_opened=False,
        limitation='Raw-ID metadata/observed traversal are test-bridge inputs; no real backend registration, RPC incarnation, provider fence or runtime/default activation is proved.')
    (out/'receipt.json').write_text(json.dumps(proof,indent=2)+'\n',encoding='utf-8')
    if run.returncode:raise RuntimeError(run.stderr)
    print(json.dumps({k:proof[k] for k in ('status','cases','observations','state_images','float_values')}))


if __name__=='__main__':main()
