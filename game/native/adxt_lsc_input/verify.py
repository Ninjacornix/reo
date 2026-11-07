#!/usr/bin/env python3
"""Qualify the real queued source, worker fences and canonical player binding."""
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
BASE = ROOT / 'build-native-sjuni/adxt-lsc-input'
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
    replaced = {'adxt_lsc_input/input.cpp', 'adxt_phased_player/player.cpp'}
    deps = [ROOT / 'game/native' / n for n in module.SOURCES if n not in replaced]
    objects = [out / (p.stem + '.o') for p in deps]
    if len(set(objects)) != len(objects):
        raise ValueError('Dependency object collision')
    out.mkdir(parents=True)
    env = dict(os.environ)
    env['PATH'] = str(Path(cc).parent) + os.pathsep + env.get('PATH', '')
    phased = ROOT / 'game/native/adxt_phased_player'
    control = ROOT / 'game/native/adxt_control_session'
    flags = [cc, '-std=c++20', '-O2', '-pthread', '-Wall', '-Wextra', '-Wpedantic', '-Werror',
             '-Wno-misleading-indentation', '-fno-fast-math', '-ffp-contract=off', '-frounding-math',
             '-I' + str(HERE), '-I' + str(phased), '-I' + str(ROOT)]
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

    def owner(name, core, player, negative=False):
        binary = out / (name + '.exe')
        run(name + '-compile', flags + objects + [core, player, control / 'control_session.cpp',
                                                HERE / 'owner_tests.cpp', '-o', binary])
        result = run(name, [binary], negative=negative)
        report.setdefault('executables', {})[name] = sha(binary)
        return result

    try:
        run('dependency-compile', flags + ['-c', *deps], cwd=out)
        report['dependency_objects'] = {p.name: sha(p) for p in objects}
        report['units'] = owner('owner', HERE / 'input.cpp', phased / 'player.cpp')
        variants = [
            ('missing-next-header-wait', phased / 'player.cpp',
             'if(next==adxt_lsc_input::Header::pending)return Status::completed;',
             'if(next==adxt_lsc_input::Header::pending)(void)next;'),
            ('submission-is-file-completion', HERE / 'input.cpp',
             '++s.report.accepted_reads;', '++s.report.accepted_reads;s.report.file_state=3;'),
            ('stop-claims-worker-joined', HERE / 'input.cpp',
             's.report.closing = true; s.wanted = false;',
             's.report.joined = true; s.report.closing = true; s.wanted = false;'),
            ('missing-live-origin-identity', phased / 'player.cpp',
             'view!=c.lsc_input->origin().get()', 'view==nullptr')]
        for name, original, old, new in variants:
            source = original.read_text(encoding='utf-8')
            if source.count(old) != 1:
                raise ValueError('Negative selector drift ' + name)
            path = out / (name + '.cpp')
            path.write_text(source.replace(old, new), encoding='utf-8', newline='\n')
            owner(name, path if original.parent == HERE else HERE / 'input.cpp',
                  path if original.parent == phased else phased / 'player.cpp', negative=True)
            report['negative_controls'].append(dict(name=name, source_sha256=sha(path)))
        report['status'] = 'passed actual live LSC owner, real worker/source fences and four detected counterfactuals'
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
