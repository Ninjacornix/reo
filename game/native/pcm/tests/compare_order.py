#!/usr/bin/env python3
"""Transport original actions and observed traversal order into the native core."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess

ROOT = Path(__file__).resolve().parents[4]
HERE = Path(__file__).resolve().parent
FROZEN_CORE = '5f86dd08b10b2ed8dd0bec1b0d11f83237ad0210b776d556de0b9f9a5d86f8eb'
FROZEN_HEADER = '9ad103002c108ec07fce0f1d868d6ceaa5a95f990a45bd10b86d42cd34bcef83'
FIXTURES = {'86aef42be64adbed4b6fcd43045348f19691a0de8b1323b13858f08c5494ee10',
            '361d4d35971e692ee4b5e62fff0edcce4f3d985f61b627f4b295a15394440c4d'}
PREFIX = r'''
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
void check(bool value){if(!value)throw std::runtime_error("original ordered snapshot mismatch");}
void ok(Status value){check(value==Status::ok);}
template<class T>T take(Result<T> value){ok(value.status);return value.value;}
struct VoiceRecord {Voice handle;std::uint32_t left;};
int main(){try{
 Config config;config.max_voices=config.max_channels=64;
 Session session(config);
 std::map<std::uint32_t,Channel> channels;
 std::map<std::uint32_t,VoiceRecord> voices;
 std::map<std::uint32_t,float> gains;
 auto channel=[&](std::uint32_t id){auto it=channels.find(id);if(it==channels.end())it=channels.emplace(id,take(session.create_channel())).first;return it->second;};
'''


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def u(value):
    value = int(value)
    if not 0 <= value <= 0xffffffff:
        raise ValueError('Input exceeds unsigned word')
    return str(value)+'u'


def source(fixture):
    rows = iter(fixture['records'])
    code = [PREFIX]
    count = 0
    for case in fixture['inputs']:
        for action in case['actions']:
            kind = action['kind']
            if kind == 'reset':
                if action != dict(kind='reset',now_ns=0,frame_clock=True,master_gain_bits=1065353216):
                    raise ValueError('Unknown reset domain')
                code.append('ok(session.reset(0));channels.clear();voices.clear();gains.clear();ok(session.select_frame_clock());')
            elif kind == 'gain':
                code.append('gains['+u(action['voice'])+']=std::bit_cast<float>('+u(action['value_f32_bits'])+');')
            elif kind == 'queue':
                sample, size = int(action['sample_i16']), int(action['sample_count'])
                if not -32768 <= sample <= 32767 or not 1 <= size <= 8192 or action['now_ns'] != 0:
                    raise ValueError('Unknown queue domain')
                code.append('{std::vector<std::int16_t> data('+str(size)+','+str(sample)+');take(session.enqueue(channel('+u(action['channel'])+'),{reinterpret_cast<const std::byte*>(data.data()),data.size()*2},0));}')
            elif kind == 'configure':
                if action['channels'] != 1 or action['right'] != 0 or action['now_ns'] != 0:
                    raise ValueError('This order corpus admits disjoint mono configurations')
                key = u(action['voice'])
                code.append('{auto it=voices.find('+key+');if(it==voices.end())it=voices.emplace('+key+',VoiceRecord{take(session.create_voice()),0}).first;'
                    'ok(session.configure(it->second.handle,{channel('+u(action['left'])+'),{},Channels::mono,'+
                    u(action['frequency'])+','+u(action['volume'])+','+str(bool(action['playing'])).lower()+'},0));it->second.left='+u(action['left'])+';}')
            elif kind in ('release','drain'):
                key = u(action['voice'])
                code.append('{auto it=voices.find('+key+');if(it!=voices.end()){ok(session.'+kind+'(it->second.handle));'+('voices.erase(it);' if kind == 'release' else '')+'}}')
            elif kind == 'render_observe':
                row = next(rows)
                if row['case'] != case['case'] or row['operation'] != action['operation'] or row['frames'] != action['frames']:
                    raise ValueError('Action/expected observation correspondence changed')
                frames = int(action['frames'])
                if not 0 <= frames <= 16384:
                    raise ValueError('Unsupported frame count')
                order = ','.join('voices.at('+u(key)+').handle' for key in row['declared_raw_order'])
                code.append('{std::array<Voice,'+str(len(row['declared_raw_order']))+'> order{'+order+'};ok(session.set_mix_order(order));'
                    'for(auto& pair:voices)ok(session.gain(pair.second.handle,gains.at(pair.first)));'
                    'std::vector<float> output('+str(frames*2)+',123);ok(session.render(output));')
                for index, bits in enumerate(row['float_bits']):
                    code.append('check(std::bit_cast<std::uint32_t>(output.at('+str(index)+'))=='+u(bits)+');')
                code.append('check(voices.size()=='+str(len(row['voices']))+'&&channels.size()=='+str(len(row['channels']))+');')
                for voice in row['voices']:
                    code.append('{const auto& bound=voices.at('+u(voice['key'])+');auto v=take(session.inspect(bound.handle));'
                        'check(bound.left=='+u(voice['left'])+'&&v.playing=='+str(voice['playing']).lower()+
                        '&&v.draining=='+str(voice['draining']).lower()+'&&v.frequency=='+u(voice['frequency'])+
                        '&&v.volume=='+u(voice['volume'])+'&&std::bit_cast<std::uint32_t>(v.gain)=='+u(voice['gain_bits'])+
                        '&&std::bit_cast<std::uint64_t>(v.phase)=='+str(int(voice['phase_bits']))+'ull&&v.late_samples=='+
                        str(int(voice['late']))+'ull&&v.skipped_samples=='+str(int(voice['skipped']))+'ull);}')
                for channel in row['channels']:
                    code.append('{auto c=take(session.inspect(channels.at('+u(channel['key'])+')));check(c.queued_bytes=='+str(int(channel['queued']))+
                        'ull&&c.consumed_bytes=='+str(int(channel['consumed']))+'ull&&c.samples=='+str(int(channel['remaining']))+'ull);}')
                code.append('{auto s=session.statistics();check(s.output_frames=='+str(int(row['output_frames']))+
                    'ull&&s.signal_frames=='+str(int(row['signal_frames']))+'ull&&s.underrun_frames=='+str(int(row['underrun_frames']))+'ull);}}')
                count += 1
            else:
                raise ValueError('Unknown replay action')
    if next(rows,None) is not None or count != 49:
        raise ValueError('Incomplete original observation coverage')
    code.append('std::cout<<"49 ordered PCM snapshots matched\\n";return 0;}catch(const std::exception& e){std::cerr<<e.what()<<"\\n";return 1;}}')
    return '\n'.join(code)+'\n'


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--fixture', required=True, type=Path)
    parser.add_argument('--cxx', required=True)
    parser.add_argument('--output', required=True, type=Path)
    args = parser.parse_args()
    tool = shutil.which(args.cxx)
    out = args.output.resolve()
    if not tool or out == ROOT/'build-native-sjuni' or not out.is_relative_to(ROOT/'build-native-sjuni'):
        raise ValueError('Requires compiler and private output directory')
    if sha(args.fixture) not in FIXTURES or sha(HERE.parent/'pcm.cpp') != FROZEN_CORE or sha(HERE.parent/'pcm.hpp') != FROZEN_HEADER:
        raise ValueError('Frozen original corpus or independent candidate changed')
    fixture = json.loads(args.fixture.read_text(encoding='utf-8'))
    if fixture['schema'] != 2:
        raise ValueError('Unsupported original fixture schema')
    out.mkdir(parents=True,exist_ok=True)
    probe, exe = out/'probe.cpp', out/'probe.exe'
    probe.write_text(source(fixture),encoding='utf-8',newline='\n')
    command = [tool,'-std=c++20','-O1','-ffp-contract=off','-Wall','-Wextra','-Wpedantic','-Werror','-pthread',
        '-I'+str(HERE.parent),str(probe),str(HERE.parent/'pcm.cpp'),'-o',str(exe)]
    env = dict(os.environ)
    env['PATH'] = str(Path(tool).resolve().parent)+os.pathsep+env.get('PATH','')
    result = subprocess.run(command,capture_output=True,text=True,env=env,timeout=90)
    if result.returncode:
        raise RuntimeError(result.stderr)
    result = subprocess.run([str(exe)],capture_output=True,text=True,env=env,timeout=30)
    proof = dict(schema=1,status='passed' if result.returncode == 0 else 'failed',cases=8,snapshots=49,float_values=44,
        fixture_sha256=sha(args.fixture),compiler_sha256=sha(Path(tool)),command=command,
        native_core_sha256=FROZEN_CORE,native_header_sha256=FROZEN_HEADER,
        comparator_sha256=sha(Path(__file__)),probe_sha256=sha(probe),executable_sha256=sha(exe),
        exit_code=result.returncode,stdout=result.stdout,stderr=result.stderr,game_run=False,device_opened=False,
        limitation='Original traversal is explicit input; native hash buckets/gain-callback iteration are not emulated. No headless insertion-transaction, device or whole-facade proof.')
    (out/'receipt.json').write_text(json.dumps(proof,indent=2)+'\n',encoding='utf-8')
    if result.returncode:
        raise RuntimeError(result.stderr)
    print(json.dumps({k:proof[k] for k in ('status','cases','snapshots','float_values')}))


if __name__ == '__main__':
    main()
