"""Time complete frozen/current workers on identical sources and fresh outputs.

Only benchmark output paths are redirected in each worker's AST. Compilation,
archive and link logic execute unchanged; no game or user application is run.
"""
import ast
import copy
import hashlib
import json
import os
from pathlib import Path
import shutil
import sys
import threading
import time
import traceback

from benchmark_compilation import load


def digest(path):
    result = hashlib.sha256()
    with path.open('rb') as stream:
        for block in iter(lambda: stream.read(4 * 1024 * 1024), b''):
            result.update(block)
    return result.hexdigest()


def redirected_worker(module, trial, observe):
    tree = ast.parse(Path(module.__file__).read_text())
    function = copy.deepcopy(next(node for node in tree.body
                                 if isinstance(node, ast.FunctionDef) and node.name == 'compile_plan'))

    class Redirect(ast.NodeTransformer):
        replacements = 0

        def visit_BinOp(self, node):
            self.generic_visit(node)
            if (isinstance(node.op, ast.Div) and isinstance(node.left, ast.Name)
                    and node.left.id == 'work' and isinstance(node.right, ast.Constant)
                    and node.right.value in {'objects', 'compile-logs', 'precompiled-headers',
                                             'local-game-link.rsp'}):
                self.replacements += 1
                node.left = ast.Name(id='benchmark_trial', ctx=ast.Load())
            return node

    redirect = Redirect()
    function = redirect.visit(function)
    assert redirect.replacements == 4, redirect.replacements
    namespace = dict(module.__dict__, benchmark_trial=trial)
    original_subprocess = module.subprocess

    class ObservedSubprocess:
        def __getattr__(self, name):
            return getattr(original_subprocess, name)

        def run(self, command, *args, **kwargs):
            stage = ('compile' if '-c' in command else 'pch' if 'c++-header' in command
                     else 'link' if any(str(part).endswith('local-game-link.rsp') for part in command)
                     else 'archive' if 'rcs' in command else 'resource')
            started = time.perf_counter()
            observe(stage, 'begin', started, command)
            try:
                result = original_subprocess.run(command, *args, **kwargs)
                observe(stage, 'end', time.perf_counter(), command, result.returncode, started)
                return result
            except BaseException:
                observe(stage, 'error', time.perf_counter(), command, None, started)
                raise

    namespace['subprocess'] = ObservedSubprocess()
    exec(compile(ast.fix_missing_locations(ast.Module([function], type_ignores=[])),
                 module.__file__, 'exec'), namespace)
    return namespace['compile_plan']


def main():
    repo = Path(__file__).resolve().parents[2]
    out = Path(sys.argv[1]).resolve()
    if not out.is_relative_to(repo / 'build-ninja') or out.exists():
        raise ValueError('Use a fresh private build-ninja directory')
    if shutil.disk_usage(repo).free < 5 * 1024**3:
        raise RuntimeError('Two fresh builds need at least 5 GiB free')
    out.mkdir(parents=True)
    paths = json.loads((repo / 'build-ninja/import-profile-20261020/paths.json').read_text())
    os.environ['REO_LLVM_MINGW'] = paths['compiler']
    sys.path.insert(0, str(repo / 'tools/local_build'))
    kit = repo / 'build-ninja/import-optimized-20261020/kit'
    work = repo / 'build-ninja/import-optimized-20261020/worker-benchmark/work'
    modules = {'old': load('full_old_compile', kit / 'tools/local_build/compile_game.py'),
               'new': load('full_new_compile', repo / 'tools/local_build/compile_game.py')}
    report = {'fullGameCompile': True, 'gameRun': False, 'sameSourceWorkspace': str(work),
              'kit': str(kit), 'compilerRoot': paths['compiler'], 'objectCachesInitiallyEmpty': True,
              'osCachesFlushed': False, 'rows': [], 'status': 'running',
              'sourceSha256': {name: digest(Path(module.__file__)) for name, module in modules.items()},
              'schedulerSha256': digest(repo / 'tools/local_build/build_scheduler.py')}

    def save():
        temporary = out / 'results.pending.json'
        temporary.write_text(json.dumps(report, indent=2))
        temporary.replace(out / 'results.json')

    save()
    try:
        for variant, jobs in [('old', 4), ('new', 7)]:
            trial = out / variant
            trial.mkdir()
            lock = threading.Lock()
            active = maximum = 0
            phase = {}
            started = time.perf_counter()
            with (trial / 'commands.jsonl').open('w', encoding='utf-8') as events:
                def observe(stage, event, now, command, code=None, begin=None):
                    nonlocal active, maximum
                    with lock:
                        if stage == 'compile':
                            active += 1 if event == 'begin' else -1
                            maximum = max(maximum, active)
                        row = {'stage': stage, 'event': event, 'elapsedSeconds': now-started,
                               'command': list(map(str, command)), 'returncode': code}
                        if begin is not None:
                            row['durationSeconds'] = now-begin
                        events.write(json.dumps(row) + '\n')
                        events.flush()
                        bucket = phase.setdefault(stage, {'firstStartSeconds': now-started,
                                                          'lastEndSeconds': None, 'completed': 0,
                                                          'sumProcessWallSeconds': 0})
                        if event == 'end':
                            bucket['lastEndSeconds'] = now-started
                            bucket['completed'] += 1
                            bucket['sumProcessWallSeconds'] += now-begin

                print(f'BEGIN {variant} jobs={jobs} empty object cache', flush=True)
                worker = redirected_worker(modules[variant], trial, observe)
                worker(kit, work / 'project/recomp/config', work, trial / 'output', jobs)
            seconds = time.perf_counter()-started
            assert phase['compile']['completed'] == 2381, phase
            objects = {path.stem: digest(path) for path in sorted((trial / 'objects').glob('*.obj'))}
            (trial / 'object-hashes.json').write_text(json.dumps(objects, indent=2))
            row = {'variant': variant, 'seconds': seconds, 'jobsUpperBound': jobs,
                   'maximumConcurrentCompilerProcesses': maximum, 'phases': phase,
                   'objectCount': len(objects), 'exeSha256': digest(trial / 'output/reo_recomp.exe'),
                   'remainingDiskBytes': shutil.disk_usage(repo).free}
            report['rows'].append(row)
            save()
            print('FINISHED', json.dumps(row), flush=True)
        old, new = [json.loads((out / name / 'object-hashes.json').read_text()) for name in ['old', 'new']]
        assert old.keys() == new.keys()
        different = [name for name in old if old[name] != new[name]]
        report['objectParity'] = {'compared': len(old), 'byteIdentical': len(old)-len(different),
                                  'different': different}
        old_seconds, new_seconds = [row['seconds'] for row in report['rows']]
        report['improvementPercent'] = 100*(old_seconds-new_seconds)/old_seconds
        report['secondsSaved'] = old_seconds-new_seconds
        report['status'] = 'complete'
        save()
        print('COMPLETE', json.dumps(report['objectParity']),
              f"less time: {report['improvementPercent']:.2f}%", flush=True)
    except BaseException:
        report['status'] = 'failed'
        report['error'] = traceback.format_exc()
        save()
        raise


if __name__ == '__main__':
    main()
