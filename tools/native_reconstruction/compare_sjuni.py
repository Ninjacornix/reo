#!/usr/bin/env python3
"""Emit a dependency-free C++ differential test from the owned-word oracle.

The test runs the actual native bridge/core, compares guest metadata and callback
boundary images, and checks unsupported admission for zero writes/hooks. Setup,
lifecycle and standalone-split calls remain original-oracle context. No game or
PS2Recomp executable is linked or started. Compile emitted source in an ignored
build directory alongside sjuni.cpp and queue_bridge.cpp.
"""
import argparse
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
OPERATIONS = {'take': 'get', 'put': 'put', 'unget': 'unget',
              'sum_bytes': 'queued_bytes', 'availability': 'availability',
              'queue_node_count': 'queued_nodes', 'free_node_count': 'free_nodes'}


def patches(state):
    result = [(state['object_address'], state['object_words_u32'])]
    result += [(n['address'], n['words_u32']) for n in state['nodes']]
    result += [(b['address'], b['words_u32']) for b in state['buffers'].values()]
    result.append((0x228C90, [state['pool_reference_u32']]))
    # Nonzero extra pooled objects are setup/lifecycle context. Their state must
    # also survive native queue operations.
    result += [(o['address'], o['words_u32']) for o in state['nonzero_pool_objects']
               if o['address'] != state['object_address']]
    return result


def words_literal(items):
    words = [(address + 4 * i, value) for address, values in items for i, value in enumerate(values)]
    return '{' + ','.join(f'{{{address}u,{value}u}}' for address, value in words) + '}'


def generate(fixture):
    data = json.loads(fixture.read_text(encoding='utf-8'))
    if data['schema'] != 1 or data['kind'] != 'owned_original_word_sjuni_oracle':
        raise ValueError('Unexpected original fixture schema')
    if data['identity']['elf_sha256'] != '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46':
        raise ValueError('Wrong fixture ELF identity')
    code = [r'''// Generated locally by tools/native_reconstruction/compare_sjuni.py.
#include "game/native/sjuni_adapter/queue_bridge.h"
#include <cstdlib>
#include <iostream>
#include <initializer_list>
#include <string>
#include <vector>
namespace b = reo::sjuni::bridge;
struct Word { std::uint32_t address, value; };
static void require(bool value, const char* where) {
    if (!value) { std::cerr << "FAIL: " << where << '\n'; std::exit(1); }
}
static void apply(b::Memory mem, std::initializer_list<Word> words) {
    for (const auto& w : words) require(mem.write32(w.address,w.value),"setup bounds");
}
static void verify(b::Memory mem, std::initializer_list<Word> words, const char* label) {
    for (const auto& w : words) {
        std::uint32_t actual = 0;
        if (!mem.read32(w.address,actual) || actual != w.value) {
            std::cerr << label << " address=" << std::hex << w.address
                      << " expected=" << w.value << " actual=" << actual << '\n';
            std::exit(1);
        }
    }
}
int main() {
    unsigned completed=0, fallback=0, setup=0, hooks=0;
    const b::Profile profile{0x228c98u,64u,0x228c60u,0x23da78u,4096u};
    // One explicitly registered numeric region covers all synthetic payloads,
    // including pointer-wrap admission probes. Core arithmetic remains native;
    // the bridge must reject unrepresentable 32-bit mirror values before effects.
    const b::Region region{1u,1u,0xffffffffull};
''']
    for case in data['cases']:
        code += ['{ std::vector<std::byte> bytes(8u*1024u*1024u); b::Memory memory(bytes);']
        for index, operation in enumerate(case['operations']):
            label = case['name'] + ':' + str(index) + ':' + operation['operation']
            literal_label = json.dumps(label)
            expected = operation['expected']
            if operation['operation'] not in OPERATIONS:
                code += [f'apply(memory,{words_literal(patches(expected["state"]))}); ++setup;']
                continue
            pre = [(w['address'], w['words_u32']) for w in operation['pre_writes']]
            code += [f'apply(memory,{words_literal(pre)});', '{ unsigned event_index=0;']
            code += ['auto observe = [&](b::Event event, std::int32_t error, b::Memory mem) {',
                     '(void)event; (void)error; (void)mem;',
                     'switch(event_index++) {']
            for i, event in enumerate(expected['events']):
                kind = {'enter': 'enter', 'leave': 'leave',
                        'registered_error': 'error', 'default_error_report': 'error'}.get(event['kind'])
                if kind is None:
                    raise ValueError(f'Unexpected queue callback: {event["kind"]}')
                code += [f'case {i}: require(event==b::Event::{kind},{literal_label});']
                if kind == 'error':
                    code += [f'require(error==-3,{literal_label});']
                code += [f'verify(mem,{words_literal(patches(event["observed_before"]))},{literal_label}); break;']
            code += [f'default: require(false,{literal_label});', '}', '};',
                     'b::Callbacks callbacks{&observe,[](void* p,b::Event event,std::int32_t error,b::Memory mem) {',
                     '(*static_cast<decltype(observe)*>(p))(event,error,mem); }};']
            args = expected['arguments_i32']
            operation_name = operation['operation']
            queue = (args[1] & 0xffffffff) if len(args) > 1 else 0
            request = args[2] if operation_name in ('take', 'availability') else 0
            descriptor = args[3] if operation_name in ('take', 'availability') else (
                args[2] if operation_name in ('put', 'unget') else 0)
            code += ['const auto before=bytes;',
                     f'const auto result=b::execute(memory,profile,{args[0] & 0xffffffff}u,',
                     f' std::span(&region,1),{{b::Operation::{OPERATIONS[operation_name]},{queue}u,{request},{descriptor & 0xffffffff}u}},callbacks);',
                     'if(result.disposition==b::Disposition::fallback_before_effects) {',
                     f'require(bytes==before && event_index==0,{literal_label}); ++fallback;',
                     f'apply(memory,{words_literal(patches(expected["state"]))});',
                     '} else {',
                     f'require(result.disposition==b::Disposition::completed,{literal_label});',
                     f'require(event_index=={len(expected["events"])}u,{literal_label});',
                     f'verify(memory,{words_literal(patches(expected["state"]))},{literal_label});']
            if expected['return_is_defined']:
                code += [f'require(result.value=={expected["return_u32"]}u,{literal_label});']
            code += ['++completed; hooks+=event_index;', '}', '}']
        code += ['}']
    code += ['std::cout << "Original-word comparison: " << completed << " native calls, "',
             '<< fallback << " side-effect-free admissions declined, " << setup << " original setup/helper calls, "',
             '<< hooks << " callback boundaries matched\\n";',
             'require(completed>200 && hooks>100,"comparison coverage");', '}']
    return '\n'.join(code) + '\n'


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--fixture', type=Path, default=ROOT / 'tools/native_reconstruction/sjuni_oracle_fixtures.json')
    parser.add_argument('--out', type=Path, default=ROOT / 'build-native-sjuni/original_comparison.cpp')
    args = parser.parse_args()
    source = generate(args.fixture)
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(source, encoding='utf-8', newline='\n')
    print(json.dumps({'source': str(args.out.relative_to(ROOT)),
                      'fixture_sha256': hashlib.sha256(args.fixture.read_bytes()).hexdigest(),
                      'source_bytes': len(source.encode('utf-8'))}))


if __name__ == '__main__':
    main()
