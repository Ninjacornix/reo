#!/usr/bin/env python3
"""Archived private fault variants of the concrete Window2 graph; no game/device."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[3]


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def replace_once(source, anchor, replacement):
    if source.count(anchor) != 1:
        raise ValueError('Private fault anchor changed: ' + anchor)
    return source.replace(anchor, replacement)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--cxx', required=True)
    parser.add_argument('--implementation', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    cc = shutil.which(args.cxx)
    out = args.output.resolve()
    if not cc or out.exists() or not out.is_relative_to(ROOT / 'build-native-sjuni/window2'):
        raise ValueError('Exact compiler and fresh scoped output required')
    manifest_path = args.implementation / 'manifest.json'
    manifest = json.loads(manifest_path.read_bytes())
    for name, digest in manifest['files'].items():
        if sha(ROOT / name) != digest:
            raise ValueError('Immutable implementation drift: ' + name)
    out.mkdir(parents=True)
    env = dict(os.environ)
    env['PATH'] = str(Path(cc).parent) + os.pathsep + env.get('PATH', '')
    receipt = dict(schema=1, status='running', compiler=cc, compiler_sha256=sha(Path(cc)),
                   implementation_manifest_sha256=sha(manifest_path), verifier_sha256=sha(Path(__file__)),
                   game_run=False, device_opened=False, checks=[], variants={})
    shutil.copyfile(__file__, out / 'verify_faults.source.py')

    def run(name, command, expected=0, extra_env=None):
        process = subprocess.run([str(x) for x in command], cwd=ROOT, env={**env, **(extra_env or {})},
                                 capture_output=True, text=True, timeout=90)
        (out / (name + '.txt')).write_text(process.stdout + process.stderr, encoding='utf-8', newline='\n')
        receipt['checks'].append(dict(name=name, command=[str(x) for x in command],
                                     exit_code=process.returncode, expected=expected, env=extra_env or {},
                                     stdout=process.stdout))
        if process.returncode != expected:
            raise RuntimeError(name + ':\n' + process.stdout + process.stderr)

    flags = [cc, '-std=c++20', '-O1', '-pthread', '-Wall', '-Wextra', '-Wpedantic', '-Werror',
             '-Wno-misleading-indentation', '-fno-fast-math', '-ffp-contract=off', '-frounding-math',
             '-I' + str(ROOT), '-I' + str(HERE), '-I' + str(ROOT / 'game/native/adx_pcm_store/v2')]

    def compile_object(name, source):
        obj = out / (name + '.o')
        run(name + '_compile', flags + ['-c', source, '-o', obj])
        return obj

    try:
        common_sources = [
            'sjrb/sjrb.cpp', 'adxt_shared_source/shared_source.cpp', 'adxt_refill/adxt_refill.cpp',
            'resource_io/async_read_owner.cpp', 'tasks/serial_worker.cpp', 'resources/resource_session.cpp',
            'resources/virtual_file_view.cpp', 'resources/bounded_view.cpp', 'adx_header/adx_header.cpp',
            'adx_workspace/adx_workspace.cpp', 'adx_window/v2/stream_window_tests.cpp']
        common = [compile_object('common_' + str(i), ROOT / 'game/native' / name)
                  for i, name in enumerate(common_sources)]
        window_text = (HERE / 'stream_window.cpp').read_text(encoding='utf-8')
        pcm_path = ROOT / 'game/native/adx_pcm_store/v2/pcm_store.cpp'
        pcm_text = pcm_path.read_text(encoding='utf-8')
        normal_window = compile_object('window_normal', HERE / 'stream_window.cpp')
        normal_pcm = compile_object('pcm_normal', pcm_path)

        def variant(name, text, part):
            path = out / (name + '.cpp')
            path.write_text(text, encoding='utf-8', newline='\n')
            obj = compile_object(name, path)
            binary = out / (name + '.exe')
            run(name + '_link', flags + common + [obj, normal_pcm if part == 'window' else normal_window,
                                                 '-o', binary])
            receipt['variants'][name] = dict(source_sha256=sha(path), executable_sha256=sha(binary))
            return binary

        # Nine independent preflight terms; accepted actions never use these
        # private seeds. Each bypass control stays below actual signed overflow.
        fields = ['outer_.decoded_samples', 'outer_.encoded_bytes', 'outer_.sample_progress',
                  'outer_.encoded_progress', 'outer_.position', 'engine_.decoded_total',
                  'header_.output_cursor', 'loop_.iterations', 'loop_.seamless_samples']
        seed = 'const auto* probe = std::getenv("REO_TEST_COUNTER");\n    if (probe) switch (std::atoi(probe)) {\n'
        for i, field in enumerate(fields):
            value = 'INT32_MAX' if i == 7 else 'INT32_MAX - 2735' if i in (1, 3) else 'INT32_MAX - 2431'
            if i == 8:
                value = 'INT32_MAX - 1'
            seed += f'    case {i}: {field} = {value};'
            if i == 8:
                seed += ' outer_.decoded_samples = 32;'
            seed += ' break;\n'
        seed += '    default: std::abort();\n    }\n    '
        numeric = replace_once(window_text, '#include <algorithm>', '#include <algorithm>\n#include <cstdlib>')
        numeric = replace_once(numeric, 'ready_.play = true;', seed + 'ready_.play = true;')
        binary = variant('numeric', numeric, 'window')
        for i, field in enumerate(fields):
            run('numeric_' + str(i), [binary, 'numeric'], extra_env={'REO_TEST_COUNTER': str(i)})
        negative = replace_once(numeric, 'if (!numeric_admission()) return Status::numeric_limit;',
                                '/* private negative control: bypass numeric horizon admission */')
        binary = variant('negative_numeric', negative, 'window')
        for i in range(len(fields)):
            run('negative_numeric_' + str(i), [binary, 'numeric'], expected=1,
                extra_env={'REO_TEST_COUNTER': str(i)})

        postcredit = replace_once(window_text, 'phase_ = Phase::pcm_credit;',
                                  'return fail(Status::pcm_failure); // private injected post-input-credit failure\n    phase_ = Phase::pcm_credit;')
        run('postcredit', [variant('postcredit', postcredit, 'window'), 'postcredit'])
        # Ordinary core is the negative control: the test must notice the absent
        # failure rather than accept final-output equality as a fault proof.
        normal_binary = out / 'negative_missing_fault.exe'
        run('negative_missing_fault_link', flags + common + [normal_window, normal_pcm, '-o', normal_binary])
        run('negative_missing_fault', [normal_binary, 'postcredit'], expected=1)

        source_anchor = 'source_ = std::make_unique<source::SharedEncodedSource>'
        source_ids = replace_once(window_text, source_anchor, 'c.source_config.maximum_id = 1;\n    ' + source_anchor)
        run('source_ids', [variant('source_ids', source_ids, 'window'), 'ids'])
        pcm_ids = replace_once(pcm_text, 'domain_->channels = config.channels;',
                               'domain_->channels = config.channels; last_write_ = last_read_ = std::numeric_limits<std::uint64_t>::max();')
        run('pcm_ids', [variant('pcm_ids', pcm_ids, 'pcm'), 'pcmids'])
        partial = replace_once(pcm_text, 'producer_[c] = suffix;',
                               'producer_[c] = suffix; if (c == 0) return fail(); // private post-effect fault')
        run('partial_pcm', [variant('partial_pcm', partial, 'pcm'), 'partialpcm'])
        ignored = replace_once(partial, 'if (c == 0) return fail(); // private post-effect fault',
                               'if (c == 0) (void)Status::ring_failure; // negative: ignore the post-effect fault')
        run('negative_partial_pcm', [variant('negative_partial_pcm', ignored, 'pcm'), 'partialpcm'], expected=1)
        receipt['status'] = 'passed'
    except Exception as error:
        receipt.update(status='failed', failure=str(error))
        raise
    finally:
        receipt['input_drift'] = [n for n, digest in manifest['files'].items() if sha(ROOT / n) != digest]
        if receipt['input_drift']:
            receipt.update(status='failed', failure='Source drift during fault verification')
        (out / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n', encoding='utf-8', newline='\n')
    print(json.dumps(dict(status=receipt['status'], receipt_sha256=sha(out / 'receipt.json'))))


if __name__ == '__main__':
    main()
