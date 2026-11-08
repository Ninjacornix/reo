#!/usr/bin/env python3
"""Qualify opaque movie source capabilities through the canonical audio owner.

Rebuild every production translation unit affected by the new Instances header;
reuse only hash-verified unchanged libraries from the complete native cohort.
This is device-free native worker validation, not game integration evidence.
"""
import argparse
import hashlib
import json
import os
import re
import shutil
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
HERE = ROOT / 'game/native/movie_instance_audio'
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
REBUILT = ('game/native/adxt_instances/instances.cpp',
           'game/native/adxt_control_owner/owner.cpp')
REPLACED = ('game/native/adxt_instances/instances.cpp',
            'game/native/adxt_instances/instances.hpp', 'game/native/CMakeLists.txt')


def write(path, text):
    path.write_text(text, encoding='utf-8', newline='\n')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('compiler', 'manifest', 'native-receipt', 'output'):
        parser.add_argument('--' + name, type=Path, required=True)
    args = parser.parse_args()
    out = args.output.resolve()
    if out.exists() or not out.is_relative_to(ROOT / 'build-native-sjuni/movie-instance-audio'):
        raise ValueError('Fresh owned output required')
    if shutil.disk_usage(ROOT).free < 128 * 1024**2:
        raise ValueError('At least 128 MiB free required for isolated test outputs')
    baseline = json.loads(args.manifest.read_bytes())
    cohort = json.loads(args.native_receipt.read_bytes())
    if (cohort['status'] != 'native media pipeline standalone build and tests passed'
            or cohort['compiler_sha256'] != sha(args.compiler)
            or cohort['manifest_sha256'] != sha(args.manifest)):
        raise ValueError('Matching complete native cohort required')
    sources = {name: digest for name, digest in baseline['files'].items()
               if name.startswith('game/native/') and name not in REPLACED}
    for name, digest in sources.items():
        if sha(ROOT / name) != digest:
            raise ValueError('Unchanged native source drift: ' + name)
    for path in (*map(lambda name: ROOT / name, REPLACED),
                 ROOT / 'game/native/adxt_instances/source_key.hpp',
                 *sorted(HERE.iterdir()), Path(__file__)):
        if path.is_file():
            sources[path.relative_to(ROOT).as_posix()] = sha(path)
    # Class definitions must agree across linked translation units. Resolve the
    # complete local quoted-include closure, rather than assuming pimpl ABI is
    # sufficient to link a newly extended class to old class definitions.
    changed_header = (ROOT / 'game/native/adxt_instances/instances.hpp').resolve()
    def closure(path, visited):
        path = path.resolve()
        if path in visited:
            return
        visited.add(path)
        for include in re.findall(r'^\s*#\s*include\s*"([^"]+)"',
                                  path.read_text(encoding='utf-8'), re.M):
            child = (path.parent / include).resolve()
            if child.is_file() and child.is_relative_to(ROOT / 'game/native'):
                closure(child, visited)
    affected = []
    for name in baseline['files']:
        if name.startswith('game/native/') and name.endswith('.cpp') and not Path(name).stem.endswith('tests'):
            dependencies = set()
            closure(ROOT / name, dependencies)
            if changed_header in dependencies:
                affected.append(name)
    if set(affected) != set(REBUILT):
        raise ValueError('Changed header rebuild set drift: ' + repr(affected))
    excluded = ('/adxt_instances/', '/adxt_control_owner/')
    libraries = {name: digest for name, digest in cohort['libraries'].items()
                 if not any(part in name for part in excluded)}
    def verify():
        for name, digest in {**sources, **libraries}.items():
            if sha(ROOT / name) != digest:
                raise ValueError('Source/archive drift: ' + name)
    verify()
    out.mkdir(parents=True)
    env = dict(os.environ)
    env['PATH'] = str(args.compiler.resolve().parent) + os.pathsep + env.get('PATH', '')
    record = dict(status='failed', sources=sources, reused_libraries=libraries,
                  rebuilt_production_translation_units=affected,
                  compiler_sha256=sha(args.compiler), native_manifest_sha256=sha(args.manifest),
                  native_receipt_sha256=sha(args.native_receipt),
                  actual_native_workers=True, actual_private_submix=True,
                  game_run=False, device_opened=False, actual_runtime_binding=False, checks=[])
    def run(label, command, negative=False):
        result = subprocess.run(list(map(str, command)), env=env, text=True,
                                capture_output=True, timeout=90)
        write(out / (label + '.txt'), result.stdout + result.stderr)
        record['checks'].append(dict(label=label, exit=result.returncode, negative=negative))
        if (result.returncode == 0) == negative:
            raise ValueError(label + ' unexpected result; see retained log')
        print(label + ': ' + ('fault detected' if negative else 'passed'), flush=True)
    flags = [args.compiler, '-std=c++20', '-O2', '-pthread', '-Wall', '-Wextra',
             '-Wpedantic', '-Werror', '-fno-fast-math', '-ffp-contract=off',
             '-frounding-math', '-I' + str(ROOT / 'game/native/adxt_instances'),
             '-I' + str(HERE)]
    archives = ['-Wl,--start-group', *[ROOT / name for name in libraries], '-Wl,--end-group']
    try:
        baseline_instances = ROOT / REBUILT[0]
        baseline_provider = HERE / 'source.cpp'
        def compile_case(label, instances, provider):
            binary = out / (label + '.exe')
            run(label + '-compile', flags + [instances, ROOT / REBUILT[1], provider,
                 HERE / 'source_tests.cpp', *archives, '-o', binary])
            return binary
        binary = compile_case('canonical', baseline_instances, baseline_provider)
        run('canonical', [binary])
        for name, fixture in (
                ('instances-regression', 'game/native/adxt_instances/instances_tests.cpp'),
                ('game-controls-regression', 'game/native/adxt_instances/game_control_tests.cpp'),
                ('owner-regression', 'game/native/adxt_control_owner/owner_tests.cpp')):
            executable = out / (name + '.exe')
            run(name + '-compile', flags + [baseline_instances, ROOT / REBUILT[1],
                 ROOT / fixture, *archives, '-o', executable])
            run(name, [executable])
        mutations = {}
        faults = {
            'follow-replaced-source': (baseline_instances, (
                ('const auto observed=s.session.inspect(key.source_);',
                 'const auto observed=s.session.inspect(*record.active);'),
                ('return state_->session.inspect(key.source_);',
                 'return state_->session.inspect(*state_->records[key.instance_.slot_].active);'))),
            'lose-persistent-pause': (baseline_instances, (
                ('if(result.status==control::Status::completed)s.records[key.instance_.slot_].pause=argument;',
                 ''),)),
            'tick-inside-owner-borrow': (baseline_provider, (
                ('std::uint32_t tick{};result=tick_->read(tick);if(result!=P::completed)return result;',
                 'std::uint32_t tick{};Borrow wrong([&](auto&){result=tick_->read(tick);});'
                 'const auto wrong_admission=owner_->run(wrong);'
                 'result=admission(wrong_admission,result);if(result!=P::completed)return result;'),))}
        for name, (original, edits) in faults.items():
            body = original.read_text(encoding='utf-8')
            for anchor, replacement in edits:
                if body.count(anchor) != 1:
                    raise ValueError('Unique mutation anchor required: ' + name)
                body = body.replace(anchor, replacement)
            altered = out / (name + '.cpp')
            write(altered, body)
            executable = compile_case(name,
                altered if original == baseline_instances else baseline_instances,
                altered if original == baseline_provider else baseline_provider)
            run(name, [executable], True)
            mutations[name] = sha(altered)
        verify()
        record.update(status='canonical movie/audio source capability checks passed',
                      workflows=6, existing_regression_suites=3,
                      detected_faults=list(faults), fault_sources_sha256=mutations)
    except Exception as error:
        record['failure'] = str(error)
        raise
    finally:
        record['outputs_sha256'] = {p.name: sha(p) for p in out.iterdir() if p.is_file()}
        write(out / 'receipt.json', json.dumps(record, indent=2) + '\n')
    print(json.dumps(dict(status=record['status'], receipt_sha256=sha(out / 'receipt.json'))))


if __name__ == '__main__':
    main()
