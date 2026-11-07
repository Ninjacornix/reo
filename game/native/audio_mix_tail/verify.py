#!/usr/bin/env python3
"""Qualify one shared stream/bank/packet output owner and its real source graph."""
import argparse
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import shutil
import subprocess

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
BASE = ROOT / 'build-native-sjuni/audio-mix-tail'
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--cxx', required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    cc, out = shutil.which(args.cxx), args.output.resolve()
    if not cc or out.exists() or not out.is_relative_to(BASE):
        raise ValueError('Exact compiler and fresh scoped output required')
    manifest = json.loads((HERE / 'manifest.json').read_bytes())

    def drift():
        return [n for n, d in manifest['files'].items() if sha(ROOT / n) != d]

    if drift():
        raise ValueError('Frozen source drift ' + str(drift()))
    helper = ROOT / 'game/native/adxt_control_session/verify.py'
    spec = importlib.util.spec_from_file_location('owned_control_dependencies', helper)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    replaced = {'audio_mix_tail/mixer.cpp', 'adxt_output_session/session.cpp'}
    deps = [ROOT / 'game/native' / n for n in module.SOURCES if n not in replaced]
    objects = [out / (str(i) + '_' + p.stem + '.o') for i, p in enumerate(deps)]
    if len(set(objects)) != len(objects):
        raise ValueError('Dependency object collision')
    out.mkdir(parents=True)
    env = dict(os.environ)
    env['PATH'] = str(Path(cc).parent) + os.pathsep + env.get('PATH', '')
    output = ROOT / 'game/native/adxt_output_session'
    control = ROOT / 'game/native/adxt_control_session'
    flags = [cc, '-std=c++20', '-O2', '-pthread', '-Wall', '-Wextra', '-Wpedantic', '-Werror',
             '-Wno-misleading-indentation', '-fno-fast-math', '-ffp-contract=off', '-frounding-math',
             '-I' + str(HERE), '-I' + str(output), '-I' + str(ROOT)]
    report = dict(schema=1, status='running', compiler=cc, compiler_sha256=sha(Path(cc)),
                  manifest_sha256=sha(HERE / 'manifest.json'), verifier_sha256=sha(Path(__file__)),
                  checks=[], negative_controls=[], game_run=False, device_opened=False,
                  production_selected=False, original_whole_player_parity=False)

    def run(name, command, cwd=ROOT, negative=False):
        result = subprocess.run([str(x) for x in command], cwd=cwd, env=env,
                                text=True, capture_output=True, timeout=90)
        (out / (name + '.txt')).write_text(result.stdout + result.stderr, encoding='utf-8', newline='\n')
        report['checks'].append(dict(name=name, command=[str(x) for x in command], exit=result.returncode))
        if (not negative and result.returncode) or (negative and not result.returncode):
            raise ValueError(name + ': ' + result.stdout + result.stderr)
        return result.stdout.strip()

    def owner(name, core, session, negative=False, test='mixer_tests.cpp'):
        binary = out / (name + '.exe')
        run(name + '-compile', flags + objects + [core, session, control / 'control_session.cpp',
                                                HERE / test, '-o', binary])
        result = run(name, [binary], negative=negative)
        report.setdefault('executables', {})[name] = sha(binary)
        return result

    try:
        for i, (dep, obj) in enumerate(zip(deps, objects, strict=True)):
            run('dependency-compile-' + str(i), flags + ['-c', dep, '-o', obj], cwd=out)
        report['dependency_objects'] = {p.name: sha(p) for p in objects}
        report['units'] = owner('units', HERE / 'mixer.cpp', output / 'session.cpp')
        report['owner_units'] = owner('owner', HERE / 'mixer.cpp', output / 'session.cpp', test='owner_tests.cpp')
        variants = [
            ('skip-bank-mix', HERE / 'mixer.cpp',
             'const auto accepted=packets_?packets_->mix_add(output,count,*bank_gains_)==packets::Status::ok:\n        banks_->mix_add(output,count,*bank_gains_)==banks::Status::ok;',
             'const auto accepted=true;'),
            ('reset-banks-on-stream-retire', output / 'session.cpp',
             'auto& r=s.records[slot_];auto retained=s.observe(slot_);',
             'auto& r=s.records[slot_];auto retained=s.observe(slot_);if(s.config.bank_mix)(void)s.config.bank_mix->reset();'),
            ('bank-join-before-provider-fence', output / 'session.cpp',
             'if(owner_->join()!=audio_output::JoinResult::joined)return Status::pending;\n    // Provider fence first; no stream/PCM/bank data lock is held while joining.\n    if(state_->config.bank_mix && !state_->config.bank_mix->join())return Status::pending;',
             'if(state_->config.bank_mix && !state_->config.bank_mix->join())return Status::pending;\n    if(owner_->join()!=audio_output::JoinResult::joined)return Status::pending;'),
            ('duplicate-bank-binding', HERE / 'mixer.cpp',
             'bool expected=false;return bound_.compare_exchange_strong(expected,true,std::memory_order_acq_rel);',
             'bound_=true;return true;')]
        source=(HERE/'mixer.cpp').read_text(encoding='utf-8')
        gain_start=source.index('    const auto gain=master_->gain();')
        gain_end=source.index('    frames_.fetch_add',gain_start)
        block=source[gain_start:gain_end]
        before=source.replace(block,'').replace('    const auto accepted=packets_?',block+'    const auto accepted=packets_?')
        early=out/'master-before-banks.cpp'
        early.write_text(before,encoding='utf-8',newline='\n')
        owner('master-before-banks',early,output/'session.cpp',negative=True)
        report['negative_controls'].append(dict(name='master-before-banks',source_sha256=sha(early)))
        for name, original, old, new in variants:
            source = original.read_text(encoding='utf-8')
            if source.count(old) != 1:
                raise ValueError('Negative selector drift ' + name)
            path = out / (name + '.cpp')
            path.write_text(source.replace(old, new), encoding='utf-8', newline='\n')
            owner(name, path if original.parent == HERE else HERE / 'mixer.cpp',
                  path if original.parent == output else output / 'session.cpp', negative=True)
            report['negative_controls'].append(dict(name=name, source_sha256=sha(path)))
        report['status'] = 'passed shared stream/bank/packet owner, real source graph and five detected counterfactuals'
    except Exception as error:
        report.update(status='failed', failure=str(error))
        raise
    finally:
        report['input_drift'] = drift()
        if report['input_drift']:
            report['status'] = 'failed source drift'
        (out / 'receipt.json').write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8', newline='\n')
    print(json.dumps(dict(status=report['status'], units=report['units'], receipt_sha256=sha(out / 'receipt.json'))))


if __name__ == '__main__':
    main()
