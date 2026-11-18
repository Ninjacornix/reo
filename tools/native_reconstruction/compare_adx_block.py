#!/usr/bin/env python3
"""Compare the independent native keyed mono kernel to original-word fixtures.

The Python side only validates/transports fixture fields and compares results.
It contains no decoder arithmetic and does not execute/import the oracle engine.
The generated probe calls the actual C++ kernel. No game or media device runs.
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
FROZEN_FIXTURE_SHA = '11785ce1d02f0355e54c38df58216911ca33d1ca8fbeaa6a2528c539a27eb6bb'
INITIAL_NATIVE_SHA = '14a93abdd07a9fb029575c952b66055a2c4c3431818a6c0901e5dd2b27460495'
ELF_SHA = '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
BODY_SHA = 'f68258d902ba372da0e477288c3a3b98a396a07b3c43bb28e55fb5805348b115'
TABLE_SHA = '67ec51eb0fd90d668661957e826ec5f7834c84c2e7a586f9cf185e0ec7d4808f'

PROBE = r'''
#include "adx_block.hpp"
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>
namespace a=reo::native::adx_block;
int digit(char c) {
    if(c>='0'&&c<='9')return c-'0';
    if(c>='a'&&c<='f')return c-'a'+10;
    if(c>='A'&&c<='F')return c-'A'+10;
    throw std::runtime_error("invalid synthetic hexadecimal input");
}
bool half(long long x){return x>=-32768&&x<=32767;}
template<class T>void array(const std::vector<T>& values){
    std::cout<<'[';
    for(std::size_t i=0;i<values.size();++i){if(i)std::cout<<',';std::cout<<values[i];}
    std::cout<<']';
}
int main(){
    try{
        long long requested,h1,h2,c1,c2,key,mult,add;
        unsigned long long capacity;
        std::string encoded;
        while(std::cin>>requested>>h1>>h2>>c1>>c2>>key>>mult>>add>>capacity>>encoded){
            if(requested<std::numeric_limits<std::int32_t>::min()||requested>std::numeric_limits<std::int32_t>::max()||
               !half(h1)||!half(h2)||!half(c1)||!half(c2)||!half(mult)||!half(add)||key<0||key>65535||capacity>131072)
                throw std::runtime_error("fixture parameter outside the typed probe domain");
            if(encoded=="-")encoded.clear();
            if(encoded.size()%2||encoded.size()>65536)throw std::runtime_error("fixture encoded span bound");
            std::vector<std::uint8_t> input(encoded.size()/2);
            for(std::size_t i=0;i<input.size();++i)input[i]=static_cast<std::uint8_t>((digit(encoded[2*i])<<4)|digit(encoded[2*i+1]));
            const auto before=input;
            const auto result=a::decode_keyed_mono(input,static_cast<std::int32_t>(requested),
                {{static_cast<std::int16_t>(h1),static_cast<std::int16_t>(h2)},static_cast<std::uint16_t>(key)},
                {static_cast<std::int16_t>(c1),static_cast<std::int16_t>(c2),static_cast<std::int16_t>(mult),static_cast<std::int16_t>(add)},
                {static_cast<std::size_t>(capacity)});
            if(result.pcm.size()>capacity)throw std::runtime_error("native owned result exceeds fixture capacity");
            // A test-only publication plane adapts the owned prefix to the
            // original fixture's A5-initialized capacity and trailing guard.
            std::vector<std::int16_t> plane(static_cast<std::size_t>(capacity)+8,static_cast<std::int16_t>(-23131));
            std::copy(result.pcm.begin(),result.pcm.end(),plane.begin());
            std::cout<<"{\"status\":"<<static_cast<unsigned>(result.status)
                     <<",\"return\":"<<result.kernel_return<<",\"blocks\":"<<result.blocks_decoded
                     <<",\"history\":["<<result.state.history.newest<<','<<result.state.history.previous<<']'
                     <<",\"key\":"<<result.state.key<<",\"history_committed\":"<<(result.history_committed?"true":"false")
                     <<",\"consumed\":"<<result.encoded_bytes_consumed<<",\"inspected\":"<<result.encoded_bytes_inspected
                     <<",\"input_unchanged\":"<<(input==before?"true":"false")<<",\"pcm\":";
            array(result.pcm);std::cout<<",\"publication_plane\":";array(plane);std::cout<<"}\n";
        }
        if(!std::cin.eof())throw std::runtime_error("invalid fixture line");
        return 0;
    }catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
}
'''


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--cxx', required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--fixtures', type=Path, default=ROOT / 'build-native-sjuni/adx-decode-fixtures.json')
    parser.add_argument('--expected-fixture-sha256', default=FROZEN_FIXTURE_SHA)
    args = parser.parse_args()
    compiler = shutil.which(args.cxx)
    if not compiler:
        parser.error('Pass an installed native C++20 compiler')
    compiler = Path(compiler).resolve()
    output, fixture_path = args.output.resolve(), args.fixtures.resolve()
    allowed = (ROOT / 'build-native-sjuni').resolve()
    if output == allowed or not output.is_relative_to(allowed):
        parser.error('Use ignored output below build-native-sjuni')
    if sha(fixture_path) != args.expected_fixture_sha256:
        raise ValueError('Fixture changed; review/pin its exact hash explicitly')
    fixture = json.loads(fixture_path.read_text(encoding='utf-8'))
    identity = fixture['identity']
    if (fixture.get('schema') != 1 or identity.get('elf_sha256') != ELF_SHA or
            identity.get('entry_pc') != 0x1276D8 or identity.get('end_pc_exclusive') != 0x1278B4 or
            identity.get('body_sha256') != BODY_SHA or identity.get('nibble_table_sha256') != TABLE_SHA):
        raise ValueError('Fixture identity differs from the independently reviewed body/table')
    for name, expected in identity['tool_sha256'].items():
        if Path(name).name != name or sha(ROOT / 'tools/native_reconstruction' / name) != expected:
            raise ValueError('Original fixture generator/engine source differs: ' + name)
    cases = fixture['cases']
    if len(cases) != fixture['counts']['cases'] or len({case['name'] for case in cases}) != len(cases):
        raise ValueError('Fixture case counts or identities are inconsistent')
    lines = []
    for case in cases:
        value = case['input']
        encoded = bytes.fromhex(value['encoded_hex'])
        if hashlib.sha256(encoded).hexdigest() != case['expected']['state']['encoded_sha256']:
            raise ValueError('Original encoded-state identity differs in ' + case['name'])
        fields = [value['requested_i32'], *value['history_i16'], *value['coefficients_i16'], value['key_u16'],
                  value['multiplier_i16'], value['addend_i16'], value['output_capacity_samples'], encoded.hex() or '-']
        lines.append(' '.join(str(x) for x in fields))
    output.mkdir(parents=True, exist_ok=True)
    source = output / 'native_adx_probe.cpp'
    executable = output / ('native_adx_probe.exe' if os.name == 'nt' else 'native_adx_probe')
    source.write_text(PROBE, encoding='utf-8', newline='\n')
    native = ROOT / 'game/native/adx_block/adx_block.cpp'
    header = native.with_suffix('.hpp')
    receipt = dict(schema=1, status='running', fixture_sha256=sha(fixture_path), fixture_identity=identity,
                   initial_independent_native_sha256=INITIAL_NATIVE_SHA,
                   native_source_sha256=sha(native), native_header_sha256=sha(header),
                   unchanged_from_independent_implementation=sha(native) == INITIAL_NATIVE_SHA,
                   comparison_tool_sha256=sha(Path(__file__)), probe_source_sha256=sha(source),
                   compiler=str(compiler), compiler_sha256=sha(compiler),
                   game_launched=False, original_instructions_executed_by_this_tool=False,
                   cases=len(cases), comparisons=[], mismatches=[])
    env = dict(os.environ)
    bins = [compiler.parent, compiler.parent.parent / 'x86_64-w64-mingw32/bin']
    env['PATH'] = os.pathsep.join(str(p) for p in bins if p.is_dir()) + os.pathsep + env.get('PATH', '')
    try:
        command = [str(compiler), '-std=c++20', '-O2', '-Wall', '-Wextra', '-Wpedantic', '-Werror',
                   '-I' + str(native.parent), str(native), str(source)]
        if os.name == 'nt' and 'clang' not in compiler.name.lower(): command += ['-static-libgcc', '-static-libstdc++']
        command += ['-o', str(executable)]
        built = subprocess.run(command, cwd=ROOT, env=env, capture_output=True, text=True, timeout=90)
        receipt['compile'] = dict(command=command, exit_code=built.returncode, stdout=built.stdout, stderr=built.stderr)
        if built.returncode: raise RuntimeError('Native probe compile failed: ' + built.stderr)
        run = subprocess.run([str(executable)], input='\n'.join(lines) + '\n', cwd=ROOT, env=env,
                             capture_output=True, text=True, timeout=30)
        (output / 'native-results.jsonl').write_text(run.stdout, encoding='utf-8')
        receipt['probe_sha256'] = sha(executable)
        receipt['run'] = dict(exit_code=run.returncode, stderr=run.stderr,
                              result_sha256=sha(output / 'native-results.jsonl'))
        if run.returncode: raise RuntimeError('Native probe failed: ' + run.stderr)
        actual = [json.loads(line) for line in run.stdout.splitlines()]
        if len(actual) != len(cases): raise ValueError('Native result count differs')
        samples = 0
        for case, observed in zip(cases, actual):
            expected, state = case['expected'], case['expected']['state']
            capacity = case['input']['output_capacity_samples']
            stores = expected['pcm_stores']
            expected_stores = [(item['offset'], item['bytes'], item['value']) for item in stores]
            native_stores = [(i * 2, 2, sample & 0xffff) for i, sample in enumerate(observed['pcm'])]
            guard = b''.join(struct.pack('<h', sample) for sample in observed['publication_plane'][capacity:]).hex()
            history_writes = expected.get('writes', {}).get('history', {}).get('accesses', 0)
            comparisons = dict(
                admitted=observed['status'] == 0,
                defined_return=observed['return'] == expected['return_i32'],
                full_pcm_capacity=observed['publication_plane'][:capacity] == state['pcm_i16'],
                pcm_prefix_stores=native_stores == expected_stores,
                completed_blocks=observed['blocks'] * 32 == expected['pcm_store_count'],
                history=observed['history'] == state['history_i16'],
                key=observed['key'] == state['key_u16'],
                selective_history_publication=observed['history_committed'] == (history_writes == 2),
                encoded_unchanged=observed['input_unchanged'],
                publication_guard=guard == state['output_guard_hex'],
            )
            failed = [key for key, passed in comparisons.items() if not passed]
            receipt['comparisons'].append(dict(name=case['name'], passed=not failed, checks=comparisons))
            if failed: receipt['mismatches'].append(dict(name=case['name'], fields=failed, native=observed))
            samples += expected['pcm_store_count']
        receipt['pcm_samples_compared'] = samples
        receipt['status'] = 'passed' if not receipt['mismatches'] else 'failed'
        receipt['limitations'] = [
            'Bounded original-word fixtures, not linked-game or device/playback equivalence.',
            'Original cursor/MAC/frame observations are not compared as native ABI.',
            'The test publication plane adapts owned PCM to original sentinel capacity/guard; it is not a guest bridge.',
            'No stream, SJ/ADXT/RNA lifecycle, looping, timing, stereo/float kernel or performance claim.',
        ]
    except Exception as error:
        receipt['status'] = 'failed'
        receipt['failure'] = str(error)
        raise
    finally:
        (output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n', encoding='utf-8')
    print(json.dumps({key: receipt[key] for key in ('status', 'cases', 'pcm_samples_compared',
                                                  'unchanged_from_independent_implementation')}))
    if receipt['mismatches']: raise SystemExit('Original/native mismatches; inspect receipt.json')


if __name__ == '__main__':
    main()
