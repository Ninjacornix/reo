#!/usr/bin/env python3
"""Compare actual metadata refresh with frozen original muted traversal.

Admission, PCM configure and device are explicit ports. The RPC function bodies,
RNA/SJ state structs and compiler-specific unordered containers are actual source.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parents[2]
OLD = ROOT / 'build-native-sjuni/dependency-sif-init-timing-reapply-v1'
OLD_PROOF = OLD.with_name(OLD.name + '-receipt.json')
PREFIX = 'ps2xRuntime/src/lib/Kernel/Syscalls/'


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def function(source, anchor):
    start = source.index(anchor)
    begin = source.index('{', start)
    depth = 0
    for i in range(begin, len(source)):
        depth += (source[i] == '{') - (source[i] == '}')
        if depth == 0:
            return source[start:i + 1]
    raise ValueError('Unclosed function: ' + anchor)


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--checkout', type=Path, required=True)
    p.add_argument('--receipt', type=Path, required=True)
    p.add_argument('--compiler', type=Path, required=True)
    p.add_argument('--output', type=Path, required=True)
    a = p.parse_args()
    out = a.output.resolve()
    if out.exists() or not out.is_relative_to(ROOT / 'build-native-sjuni/muted-rna'):
        raise ValueError('Fresh owned output required')
    if sha(OLD_PROOF) != '473ad00c8fcae9966455fc8f47047f2dccd619d747077fc1ffaec2c2e3444df6':
        raise ValueError('Frozen SDK130 proof changed')
    prior = json.loads(OLD_PROOF.read_bytes())
    proof = json.loads(a.receipt.read_bytes())
    if proof['status'] != 'passed' or proof['applied_count'] != 131 or proof['base_revision'] != prior['base_revision']:
        raise ValueError('Complete matching131 patch proof required')
    for name, digest in proof['source_sha256'].items():
        if sha(a.checkout / name) != digest:
            raise ValueError('SDK source drift: ' + name)
    for row in proof['patches']:
        if sha(ROOT / row['path']) != row['sha256']:
            raise ValueError('Patch drift')
    rpc = a.checkout / (PREFIX + 'RPC.cpp')
    frozen = OLD / (PREFIX + 'RPC.cpp')
    state = a.checkout / (PREFIX + 'Helpers/State.h')
    header = a.checkout / (PREFIX + 'RPC.h')
    if sha(frozen) != prior['source_sha256'][PREFIX + 'RPC.cpp'] or sha(state) != prior['source_sha256'][PREFIX + 'Helpers/State.h']:
        raise ValueError('Original reference or state definition drift')
    body = rpc.read_text(); original = frozen.read_text(); h = header.read_text()
    original_fn = function(original, 'void dtxConsumeActivePs2RnaStreamsLocked()')
    cutoff = '                const uint32_t budget = dtxPacedConsumeBudgetBytes(rna, nowNs);'
    if original_fn.count(cutoff) != 1:
        raise ValueError('Original muted/playing boundary changed')
    # Preserve the complete original muted branch. An active row is forbidden
    # in this reference, rather than substituting its original PCM producer.
    reference = original_fn[:original_fn.index(cutoff)] + 'throw std::runtime_error("unmuted reference input");\n}}'
    reference = reference.replace('dtxConsumeActivePs2RnaStreamsLocked()', 'originalMuted()')
    helpers = '\n'.join(function(original, anchor) for anchor in [
        'uint32_t resolveRnaRing(', 'void configurePcmVoice('])
    for anchor in ['uint32_t resolveRnaRing(', 'void configurePcmVoice(']:
        if function(original, anchor) != function(body, anchor):
            raise ValueError('Existing metadata configuration changed')
    states = '\n'.join(function(state.read_text(), 'struct ' + name) + ';\n' +
        'inline std::unordered_map<uint32_t,' + name + '> ' + mapping + ';'
        for name, mapping in [('DtxPs2RnaState', 'g_dtx_ps2rna_by_handle'),
                              ('DtxSjxState', 'g_dtx_sjx_by_handle'),
                              ('DtxSjrmtState', 'g_dtx_sjrmt_by_handle')])
    declarations = h[h.index('    enum class RnaMetadataStatusV1'):h.index('    void noteDtxSifDmaTransfer(')]
    current = function(body, 'RnaMetadataResultV1 refreshMutedRnaMetadataV1(')
    out.mkdir(parents=True)
    def write(name, content):
        (out / name).write_text(content, encoding='utf-8', newline='\n')
    for name, content in [('sdk_declarations.inc', declarations), ('sdk_states.inc', states),
                          ('sdk_helpers.inc', helpers), ('original_muted.inc', reference), ('native_muted.inc', current)]:
        write(name, content)
    fixture = ROOT / 'tools/native_reconstruction/muted_rna_fixture.cpp'
    env = dict(os.environ);env['PATH'] = str(a.compiler.resolve().parent) + os.pathsep + env.get('PATH', '')
    record = dict(schema=1, status='running', dependency_receipt_sha256=sha(a.receipt),
                  frozen_receipt_sha256=sha(OLD_PROOF), compiler_sha256=sha(a.compiler),
                  authored_sha256={str(x.relative_to(ROOT)).replace('\\', '/'):sha(x) for x in [Path(__file__), fixture]},
                  checks=[], negative_controls=[], game_run=False, device_opened=False,
                  scope='Actual metadata bodies/containers; runtime admission and configure are declared ports; no PCM parity or live admission claim')
    def run(name, command, failure=False):
        value = subprocess.run([str(x) for x in command], capture_output=True, text=True, env=env, timeout=90)
        write(name + '.txt', value.stdout + value.stderr)
        record['checks'].append(dict(name=name, exit_code=value.returncode, expected_failure=failure))
        if (value.returncode == 0) == failure:
            raise RuntimeError(name + ': ' + value.stderr)
        return value.stdout
    flags = [a.compiler, '-std=c++20', '-O2', '-Wall', '-Wextra', '-Werror', '-Wno-misleading-indentation', '-I' + str(out)]
    try:
        exe = out / 'metadata.exe'
        run('compile', flags + [fixture, '-o', exe])
        record['observations'] = json.loads(run('compare', [exe]))
        mutations = [
            ('skip-muted', 'configurePcmVoice(entry.second);++result.requests;', 'if(entry.second.playEnabled) {configurePcmVoice(entry.second);++result.requests;}'),
            ('allow-playing', 'if (rna.playEnabled) {', 'if (false) {'),
            ('stamp-clock', 'configurePcmVoice(entry.second);++result.requests;', 'configurePcmVoice(entry.second);g_dtx_ps2rna_by_handle.at(entry.first).lastConsumeNs=42;++result.requests;'),
            ('omit-preflight', 'result.status=RnaMetadataStatusV1::invalid_metadata;return result;', 'result.status=RnaMetadataStatusV1::invalid_metadata;'),
            ('reverse-order', 'for (const auto& entry:g_dtx_ps2rna_by_handle) {\n                configurePcmVoice(entry.second);++result.requests;\n            }',
             'std::vector<uint32_t> keys;for(const auto& entry:g_dtx_ps2rna_by_handle)keys.push_back(entry.first);std::reverse(keys.begin(),keys.end());for(auto key:keys){configurePcmVoice(g_dtx_ps2rna_by_handle.at(key));++result.requests;}'),
        ]
        for label, anchor, replacement in mutations:
            if anchor not in current:
                raise ValueError('Mutation anchor missing: ' + label)
            write('native_muted.inc', current.replace(anchor, replacement))
            binary = out / (label + '.exe');run(label + '-compile', flags + [fixture, '-o', binary]);run(label, [binary], True)
            record['negative_controls'].append(dict(name=label, detected=True))
        record['status'] = 'muted RNA metadata comparison passed'
    finally:
        write('native_muted.inc', current)
        record['outputs_sha256'] = {path.name:sha(path) for path in sorted(out.iterdir()) if path.is_file() and path.name != 'receipt.json'}
        write('receipt.json', json.dumps(record, indent=2) + '\n')
    print(json.dumps(record['observations']))


if __name__ == '__main__':
    main()
