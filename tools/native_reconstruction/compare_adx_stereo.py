#!/usr/bin/env python3
"""Compare frozen native stereo/downmix to independent original-word fixtures.

Python validates/transports inputs and compares results; no decoder arithmetic or
oracle is imported. Native probe publication planes are synthetic test adapters.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import struct
import subprocess

ROOT = Path(__file__).resolve().parents[2]
INITIAL_NATIVE_SHA = '3a323a108772aa844594fb2d4e34fb56ef0a522006d90d8b825ead7bd168d55f'
INITIAL_HEADER_SHA = '6cf5c13f765c60b36cf13ac7c9fd74fd0bc09f3ea106f4d640f98bbff157df8b'
ELF_SHA = '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
BODY_HASHES = {
    0x1278B8: 'fece7d5c5d7dc0148717351d200c67d845e0242f5e7b93c01cfc19db7c2687ab',
    0x127C80: '4a4e6da9bbda1a2a0b83c2f7bb31e777aeeb912c751b0a8a0694ce16c366f9ff',
    0x127FC8: '5aea6cbb34fbefae1bf0c40ffd7fceb604766e1fe011b46c9aaad5ed5dd8439e',
}
FROZEN_FIXTURE_SHA = 'a02fc85b996feb650751407a5a2e5fc9cd8104fd1c5d9fe4278864cf4027f6b0'
TABLE_SHA = '67ec51eb0fd90d668661957e826ec5f7834c84c2e7a586f9cf185e0ec7d4808f'

PROBE = r'''
#include "adx_stereo.hpp"
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>
namespace a=reo::native::adx_stereo;
int digit(char c){
    if(c>='0'&&c<='9')return c-'0';
    if(c>='a'&&c<='f')return c-'a'+10;
    if(c>='A'&&c<='F')return c-'A'+10;
    throw std::runtime_error("synthetic input hex");
}
bool half(long long n){return n>=-32768&&n<=32767;}
template<class T>void array(const std::vector<T>& values){
    std::cout<<'[';
    for(std::size_t i=0;i<values.size();++i){if(i)std::cout<<',';std::cout<<values[i];}
    std::cout<<']';
}
int main(){try{
    long long requested,ln,lp,rn,rp,c1,c2,key,mult,add,mode;
    unsigned long long capacity;
    std::string encoded;
    while(std::cin>>requested>>ln>>lp>>rn>>rp>>c1>>c2>>key>>mult>>add>>mode>>capacity>>encoded){
        if(requested<std::numeric_limits<std::int32_t>::min()||requested>std::numeric_limits<std::int32_t>::max()||
           !half(ln)||!half(lp)||!half(rn)||!half(rp)||!half(c1)||!half(c2)||!half(mult)||!half(add)||
           key<0||key>65535||mode<0||mode>1||capacity>131072)
            throw std::runtime_error("fixture outside typed domain");
        if(encoded=="-")encoded.clear();
        if(encoded.size()%2||encoded.size()>65536)throw std::runtime_error("encoded span bound");
        std::vector<std::uint8_t> input(encoded.size()/2);
        for(std::size_t i=0;i<input.size();++i)
            input[i]=static_cast<std::uint8_t>((digit(encoded[2*i])<<4)|digit(encoded[2*i+1]));
        const auto before=input;
        const auto result=a::decode_keyed_stereo(input,static_cast<std::int32_t>(requested),
            {{static_cast<std::int16_t>(ln),static_cast<std::int16_t>(lp)},
             {static_cast<std::int16_t>(rn),static_cast<std::int16_t>(rp)},static_cast<std::uint16_t>(key)},
            {static_cast<std::int16_t>(c1),static_cast<std::int16_t>(c2),static_cast<std::int16_t>(mult),static_cast<std::int16_t>(add)},
            mode==0?a::Mode::separate_channels:a::Mode::downmix_7_over_10,{static_cast<std::size_t>(capacity)});
        if(result.left_pcm.size()>capacity||result.right_pcm.size()>capacity)
            throw std::runtime_error("native result exceeds publication capacity");
        std::vector<std::int16_t> left(static_cast<std::size_t>(capacity)+8,-23131),right=left;
        std::copy(result.left_pcm.begin(),result.left_pcm.end(),left.begin());
        std::copy(result.right_pcm.begin(),result.right_pcm.end(),right.begin());
        std::cout<<"{\"status\":"<<static_cast<unsigned>(result.status)<<",\"return\":"<<result.kernel_return
                 <<",\"pairs\":"<<result.pairs_decoded<<",\"stop\":"<<static_cast<unsigned>(result.stop)<<",\"history\":["<<result.state.left.newest<<','
                 <<result.state.left.previous<<','<<result.state.right.newest<<','<<result.state.right.previous
                 <<"],\"key\":"<<result.state.key<<",\"histories_committed\":"<<(result.histories_committed?"true":"false")
                 <<",\"consumed\":"<<result.encoded_bytes_consumed<<",\"inspected\":"<<result.encoded_bytes_inspected
                 <<",\"input_unchanged\":"<<(input==before?"true":"false")<<",\"left_pcm\":";
        array(result.left_pcm);std::cout<<",\"right_pcm\":";array(result.right_pcm);
        std::cout<<",\"left_plane\":";array(left);std::cout<<",\"right_plane\":";array(right);std::cout<<"}\n";
    }
    if(!std::cin.eof())throw std::runtime_error("malformed fixture line");
    return 0;
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}}
'''


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--cxx', required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--fixtures', type=Path, default=ROOT / 'build-native-sjuni/adx-stereo-fixtures.json')
    parser.add_argument('--expected-fixture-sha256', default=FROZEN_FIXTURE_SHA)
    args = parser.parse_args()
    compiler = shutil.which(args.cxx)
    if not compiler:
        parser.error('Pass an installed C++20 compiler')
    compiler = Path(compiler).resolve()
    output = args.output.resolve()
    allowed = (ROOT / 'build-native-sjuni').resolve()
    if output == allowed or not output.is_relative_to(allowed):
        parser.error('Use ignored output below build-native-sjuni')
    if sha(args.fixtures) != args.expected_fixture_sha256:
        raise ValueError('Fixture hash differs; explicitly pin the reviewed receipt')
    fixture = json.loads(args.fixtures.read_text(encoding='utf-8'))
    identity = fixture['identity']
    if fixture['schema'] != 1 or identity['elf_sha256'] != ELF_SHA:
        raise ValueError('Original fixture identity mismatch')
    expected_bodies = {'normal': (0x127C80, 0x127FC8), 'downmix': (0x1278B8, 0x127C7C),
                       'selector': (0x127FC8, 0x128038)}
    for mode, (start, end) in expected_bodies.items():
        body = identity['bodies'][mode]
        if (body['entry_pc'], body['end_pc_exclusive'], body['words'], body['sha256']) != (
                start, end, (end - start) // 4, BODY_HASHES[start]):
            raise ValueError('Original body identity differs: ' + mode)
    if (identity['nibble_table_address'], identity['nibble_table_bytes'], identity['nibble_table_sha256']) != (
            0x239BE8, 64, TABLE_SHA):
        raise ValueError('Original signed-nibble table identity differs')
    for name, expected in identity['tool_sha256'].items():
        if Path(name).name != name or sha(ROOT / 'tools/native_reconstruction' / name) != expected:
            raise ValueError('Original engine/generator source differs: ' + name)
    cases = fixture['cases']
    if len(cases) != fixture['counts']['cases'] or len({c['name'] for c in cases}) != len(cases):
        raise ValueError('Fixture case identities/counts differ')
    lines = []
    for case in cases:
        value = case['input']
        mode = value['mode']
        if mode not in ('normal', 'downmix', 'selector'):
            raise ValueError('Unrecognized fixture mode')
        selected = mode == 'downmix' or (mode == 'selector' and value['selector_flag_u32'] != 0)
        encoded = bytes.fromhex(value['encoded_hex'])
        state = case['expected']['state']
        if (hashlib.sha256(encoded).hexdigest() != state['encoded_sha256'] or
                state['nibble_table_sha256'] != TABLE_SHA or state['selector_flag_u32'] != value['selector_flag_u32'] or
                state['left_guard_hex'] != 'a5' * 16 or state['right_guard_hex'] != 'a5' * 16 or
                state['history_guard_hex'] != 'b6' * 16 or state['key_guard_hex'] != 'c7' * 16):
            raise ValueError('Fixture recorded input/guard identity differs: ' + case['name'])
        for plane in ('left', 'right'):
            packed = b''.join(struct.pack('<h', sample) for sample in state[plane + '_pcm_i16'])
            if hashlib.sha256(packed).hexdigest() != state[plane + '_pcm_sha256']:
                raise ValueError('Fixture PCM identity differs: ' + case['name'])
        fields = [value['requested_i32'], *value['history_i16'], *value['coefficients_i16'], value['key_u16'],
                  value['multiplier_i16'], value['addend_i16'], int(selected),
                  value['output_capacity_samples_per_plane'], encoded.hex() or '-']
        lines.append(' '.join(str(n) for n in fields))
    output.mkdir(parents=True, exist_ok=True)
    source = output / 'native_adx_stereo_probe.cpp'
    executable = output / ('native_adx_stereo_probe.exe' if os.name == 'nt' else 'native_adx_stereo_probe')
    source.write_text(PROBE, encoding='utf-8', newline='\n')
    native = ROOT / 'game/native/adx_stereo/adx_stereo.cpp'
    header = native.with_suffix('.hpp')
    receipt = dict(schema=1, status='running', fixture_sha256=sha(args.fixtures), fixture_identity=identity,
                   independently_reviewed_body_hashes={hex(pc): value for pc, value in BODY_HASHES.items()},
                   initial_native_sha256=INITIAL_NATIVE_SHA, native_source_sha256=sha(native),
                   initial_header_sha256=INITIAL_HEADER_SHA, native_header_sha256=sha(header),
                   unchanged_from_independent_implementation=sha(native) == INITIAL_NATIVE_SHA and sha(header) == INITIAL_HEADER_SHA,
                   comparison_tool_sha256=sha(__file__), probe_source_sha256=sha(source),
                   compiler=str(compiler), compiler_sha256=sha(compiler), game_launched=False,
                   original_instructions_executed_by_this_tool=False, cases=len(cases), comparisons=[], mismatches=[])
    env = dict(os.environ)
    bins = [compiler.parent, compiler.parent.parent / 'x86_64-w64-mingw32/bin']
    env['PATH'] = os.pathsep.join(str(p) for p in bins if p.is_dir()) + os.pathsep + env.get('PATH', '')
    try:
        command = [str(compiler), '-std=c++20', '-O2', '-Wall', '-Wextra', '-Wpedantic', '-Werror',
                   '-I' + str(native.parent), str(native), str(source)]
        if os.name == 'nt' and 'clang' not in compiler.name.lower():
            command += ['-static-libgcc', '-static-libstdc++']
        command += ['-o', str(executable)]
        built = subprocess.run(command, cwd=ROOT, env=env, capture_output=True, text=True, timeout=90)
        receipt['compile'] = dict(command=command, exit_code=built.returncode, stdout=built.stdout, stderr=built.stderr)
        if built.returncode:
            raise RuntimeError('Native probe compile failed: ' + built.stderr)
        run = subprocess.run([str(executable)], input='\n'.join(lines) + '\n', cwd=ROOT, env=env,
                             capture_output=True, text=True, timeout=30)
        (output / 'native-results.jsonl').write_text(run.stdout, encoding='utf-8')
        receipt['probe_sha256'] = sha(executable)
        receipt['run'] = dict(exit_code=run.returncode, stderr=run.stderr,
                              result_sha256=sha(output / 'native-results.jsonl'))
        if run.returncode:
            raise RuntimeError('Native probe failed: ' + run.stderr)
        actual = [json.loads(line) for line in run.stdout.splitlines()]
        if len(actual) != len(cases):
            raise ValueError('Native result count differs')
        samples = 0
        for case, observed in zip(cases, actual):
            expected = case['expected']
            state = expected['state']
            capacity = case['input']['output_capacity_samples_per_plane']
            original_stores = expected['pcm_stores']
            def same_plane_stores(plane):
                stores = [(s['offset'], s['bytes'], s['value']) for s in original_stores if s['plane'] == plane + '_pcm']
                native_stores = [(i * 2, 2, sample & 65535) for i, sample in enumerate(observed[plane + '_pcm'])]
                return stores == native_stores
            comparisons = dict(
                admitted=observed['status'] == 0,
                defined_return=expected['return_is_defined'] and observed['return'] == expected['return_i32'],
                full_left_capacity=observed['left_plane'][:capacity] == state['left_pcm_i16'],
                full_right_capacity=observed['right_plane'][:capacity] == state['right_pcm_i16'],
                history=observed['history'] == state['history_i16'],
                key=observed['key'] == state['key_u16'],
                completed_pairs=observed['pairs'] * 64 == expected['pcm_store_count'],
                left_ordered_prefix_stores=same_plane_stores('left'),
                right_ordered_prefix_stores=same_plane_stores('right'),
                history_publication=observed['histories_committed'] == (expected['writes'].get('history', {}).get('accesses', 0) == 4),
                key_advances=observed['pairs'] * 2 + int(observed['stop'] == 2) == expected['writes'].get('key', {}).get('accesses', 0),
                encoded_unchanged=observed['input_unchanged'],
                publication_guards=observed['left_plane'][capacity:] == [-23131] * 8 and
                                   observed['right_plane'][capacity:] == [-23131] * 8,
            )
            failed = [key for key, value in comparisons.items() if not value]
            receipt['comparisons'].append(dict(name=case['name'], passed=not failed, checks=comparisons))
            if failed:
                receipt['mismatches'].append(dict(name=case['name'], fields=failed, native=observed))
            samples += len(observed['left_pcm']) + len(observed['right_pcm'])
        receipt['pcm_samples_compared'] = samples
        receipt['status'] = 'failed' if receipt['mismatches'] else 'passed'
        receipt['limitations'] = [
            'Finite synthetic disjoint original-word fixtures, not game/playback equivalence.',
            'Original register cursors, frames and MAC accumulators are not native ABI comparisons.',
            'Selector cases compare the explicit flag-selected typed mode, not a native global or guest selector wrapper.',
            'Test publication planes adapt owned vectors to capacity/guards; no guest bridge memory safety claim.',
            'Store order is compared within each plane; cross-plane order is unobservable for disjoint owned output vectors.',
            'No stream/SJ/ADXT/RNA lifetime, media-clock, unkeyed/float, audible quality or performance claim.',
        ]
    except Exception as error:
        receipt['status'] = 'failed'
        receipt['failure'] = str(error)
        raise
    finally:
        (output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n', encoding='utf-8')
    print(json.dumps({key: receipt[key] for key in ('status', 'cases', 'pcm_samples_compared',
                                                  'unchanged_from_independent_implementation')}))
    if receipt['mismatches']:
        raise SystemExit('Original/native mismatch; inspect receipt.json')


if __name__ == '__main__':
    main()
