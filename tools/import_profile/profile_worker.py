"""Profile private generation, compile samples and an optional reference relink; never publish/run a game."""
import argparse
import ast
import copy
import ctypes
from ctypes import wintypes
from concurrent.futures import ThreadPoolExecutor
from contextlib import contextmanager
import functools
import hashlib
import importlib
import json
import os
from pathlib import Path
import shutil
import statistics
import subprocess
import sys
import threading
import time

ROWS = []
LOCK = threading.Lock()
LOCAL = threading.local()
OUT = None
HASHES = {}

class Io(ctypes.Structure):
    _fields_ = [(n, ctypes.c_ulonglong) for n in ('read_ops', 'write_ops', 'other_ops', 'read_bytes', 'write_bytes', 'other_bytes')]
class Mem(ctypes.Structure):
    _fields_ = [('cb', wintypes.DWORD), ('page_faults', wintypes.DWORD)] + [(n, ctypes.c_size_t) for n in ('peak_ws', 'ws', 'peak_paged', 'paged', 'peak_nonpaged', 'nonpaged', 'pagefile', 'peak_pagefile')]
K32 = ctypes.WinDLL('kernel32', use_last_error=True)
PSAPI = ctypes.WinDLL('psapi', use_last_error=True)
K32.GetCurrentProcess.restype = wintypes.HANDLE
K32.GetProcessIoCounters.argtypes = [wintypes.HANDLE, ctypes.POINTER(Io)]
K32.GetProcessTimes.argtypes = [wintypes.HANDLE] + [ctypes.POINTER(wintypes.FILETIME)] * 4
PSAPI.GetProcessMemoryInfo.argtypes = [wintypes.HANDLE, ctypes.POINTER(Mem), wintypes.DWORD]

def metrics(handle=None):
    handle = handle or K32.GetCurrentProcess()
    io = Io(); memory = Mem(); memory.cb = ctypes.sizeof(memory)
    times = [wintypes.FILETIME() for _ in range(4)]
    K32.GetProcessIoCounters(handle, ctypes.byref(io))
    K32.GetProcessTimes(handle, *(ctypes.byref(t) for t in times))
    PSAPI.GetProcessMemoryInfo(handle, ctypes.byref(memory), ctypes.sizeof(memory))
    cpu = sum((t.dwHighDateTime << 32) | t.dwLowDateTime for t in times[2:]) / 10000
    return {'cpuMs': cpu, 'readBytes': io.read_bytes, 'writeBytes': io.write_bytes, 'peakWorkingSetBytes': memory.peak_ws}

def save():
    with LOCK:
        (OUT / 'worker-profile.json').write_text(json.dumps({'fullGameCompileRun': False, 'gameLaunched': False, 'timingsOverlap': True, 'rows': ROWS, 'hashes': HASHES}, indent=2))

@contextmanager
def span(name, **extra):
    started = time.perf_counter(); before = metrics()
    previous = getattr(LOCAL, 'phase', '')
    LOCAL.phase = name
    print('START ' + name, flush=True)
    status = 'ok'
    try:
        yield
    except BaseException:
        status = 'failed'; raise
    finally:
        after = metrics(); elapsed = time.perf_counter() - started
        with LOCK:
            ROWS.append({'name': name, 'parent': previous, 'wallSeconds': elapsed, 'status': status,
                'cpuMs': after['cpuMs'] - before['cpuMs'], 'logicalReadBytes': after['readBytes'] - before['readBytes'],
                'logicalWriteBytes': after['writeBytes'] - before['writeBytes'], **extra})
        LOCAL.phase = previous
        save(); print(f'DONE {name}: {elapsed:.3f}s [{status}]', flush=True)

def wrap(module, attribute, name):
    original = getattr(module, attribute)
    @functools.wraps(original)
    def measured(*args, **kwargs):
        with span(name): return original(*args, **kwargs)
    setattr(module, attribute, measured)
    return measured

def hash_wrap(module, attribute):
    original = getattr(module, attribute)
    @functools.wraps(original)
    def measured(path, *args, **kwargs):
        started = time.perf_counter()
        value = original(path, *args, **kwargs)
        key = getattr(LOCAL, 'phase', 'other') + ':' + module.__name__ + '.' + attribute
        with LOCK:
            record = HASHES.setdefault(key, {'calls': 0, 'bytes': 0, 'seconds': 0})
            record['calls'] += 1; record['bytes'] += Path(path).stat().st_size
            record['seconds'] += time.perf_counter() - started
        return value
    setattr(module, attribute, measured)

OriginalPopen = subprocess.Popen
class ProfilePopen(OriginalPopen):
    def __init__(self, *args, **kwargs):
        self.profile_start = time.perf_counter()
        self.profile_phase = getattr(LOCAL, 'phase', 'other')
        command = args[0] if args else kwargs.get('args', [])
        self.profile_command = list(map(str, command)) if isinstance(command, (list, tuple)) else [str(command)]
        self.profile_done = False
        super().__init__(*args, **kwargs)
    def __exit__(self, *args):
        result = super().__exit__(*args)
        if not self.profile_done:
            stats = metrics(int(self._handle))
            with LOCK:
                ROWS.append({'name': 'child:' + Path(self.profile_command[0]).name,
                    'parent': self.profile_phase, 'wallSeconds': time.perf_counter() - self.profile_start,
                    'exit': self.returncode, 'command': self.profile_command, **stats})
            self.profile_done = True
            save()
        return result

class StopBeforeCompile(Exception): pass

def main():
    global OUT
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root', required=True, type=Path)
    parser.add_argument('--samples', type=int, default=10)
    parser.add_argument('--relink', action='store_true')
    args = parser.parse_args()
    root = args.root.resolve()
    paths = json.loads((root / 'paths.json').read_text())
    kits = [p for p in Path(paths['kit']).iterdir() if (p / 'build-kit.json').is_file()]
    if len(kits) != 1: raise ValueError('Expected one verified private kit')
    kit = kits[0]; compiler = Path(paths['compiler']); disc = Path(paths['imported']) / 'data'
    OUT = root / 'worker-profile'; OUT.mkdir()
    os.environ['REO_LLVM_MINGW'] = str(compiler)
    sys.path.insert(0, str(kit / 'tools/local_build'))
    build = importlib.import_module('build_game')
    gen = importlib.import_module('generate_game')
    comp = importlib.import_module('compile_game')
    subprocess.Popen = ProfilePopen
    copytree = shutil.copytree
    def copy_profile(*a, **kw):
        depth = getattr(LOCAL, 'copy_depth', 0)
        LOCAL.copy_depth = depth + 1
        try:
            if depth == 0:
                with span('source-copytree', source=str(a[0])): return copytree(*a, **kw)
            return copytree(*a, **kw)
        finally: LOCAL.copy_depth = depth
    shutil.copytree = copy_profile
    old_stage = build.stage
    def measured_stage(work, name, *a, **kw):
        with span('receipt-stage:' + name): return old_stage(work, name, *a, **kw)
    build.stage = measured_stage
    build.generate = wrap(gen, 'generate', 'generate-main-overlays-support')
    wrap(gen, 'decompress', 'overlay-decompress')
    wrap(gen, 'generate_support', 'generate-supplemental-support')
    wrap(gen, 'generate_catalogues', 'generate-instruction-catalogues')
    wrap(build, 'apply_plan', 'apply-source-recipes')
    wrap(build, 'generate_queue_control', 'generate-queue-control')
    wrap(build, 'reconstruct', 'reconstruct-vu')
    hash_wrap(build, 'sha'); hash_wrap(gen, 'sha'); hash_wrap(comp, 'digest')
    def boundary(*a, **kw): raise StopBeforeCompile()
    build.compile_plan = boundary
    work = OUT / 'work'; output = OUT / 'output'
    for label in ['generation-fresh', 'generation-resume']:
        with span(label):
            try: build.build(kit, disc, work, output, 1)
            except StopBeforeCompile: pass
    # Execute the exact preparation prefix of compile_plan, stopping before compile_unit.
    tree = ast.parse(Path(comp.__file__).read_text())
    definition = copy.deepcopy(next(node for node in tree.body if isinstance(node, ast.FunctionDef) and node.name == 'compile_plan'))
    stop = next(i for i, node in enumerate(definition.body) if isinstance(node, ast.FunctionDef) and node.name == 'compile_unit')
    definition.name = 'profile_prepare'
    definition.body = definition.body[:stop] + [ast.Return(ast.Call(ast.Name('locals', ast.Load()), [], []))]
    namespace = dict(comp.__dict__)
    exec(compile(ast.fix_missing_locations(ast.Module([definition], type_ignores=[])), comp.__file__, 'exec'), namespace)
    with span('compile-plan-headers-pch-fresh'):
        prepared = namespace['profile_prepare'](kit, work / 'project/recomp/config', work, output, 1)
    with span('compile-plan-headers-pch-resume'):
        namespace['profile_prepare'](kit, work / 'project/recomp/config', work, output, 1)
    units = prepared['units']; source_file = prepared['source_file']; expand = prepared['expand']
    sizes = {unit['id']: sum(source_file(p).stat().st_size for p in unit['sources']) for unit in units}
    groups = {}
    for unit in units:
        group = ''.join(c for c in unit['id'] if not c.isdigit())
        groups.setdefault(group, []).append(unit)
    summary = {name: {'units': len(items), 'sourceBytes': sum(sizes[u['id']] for u in items),
        'largestUnit': max(sizes[u['id']] for u in items), 'medianUnit': statistics.median(sizes[u['id']] for u in items)} for name, items in groups.items()}
    (OUT / 'unit-census.json').write_text(json.dumps({'units': len(units), 'pchCount': len(prepared['precompiled']), 'groups': summary}, indent=2))
    chosen = []
    # Sample large and median generated units, plus representative runtime/graphics/VU units.
    for name in ['main', 'overlay', 'extra', 'legacy', 'authored', 'backend', 'runtime', 'vu']:
        items = sorted(groups.get(name, []), key=lambda u: sizes[u['id']])
        if items:
            chosen.append(items[-1])
            if name in ('main', 'overlay') and len(items) > 1: chosen.append(items[len(items)//2])
    for unit in sorted(units, key=lambda u: sizes[u['id']], reverse=True):
        if len(chosen) >= args.samples: break
        if unit not in chosen: chosen.append(unit)
    chosen = chosen[:args.samples]
    defaults = prepared['portable_defaults']
    tool = str(prepared['compiler']); environment = prepared['env']
    def compile_sample(unit, trial):
        name = unit['id']; target = OUT / trial; target.mkdir(exist_ok=True)
        source = target / (name + '.cpp')
        source.write_text('\n'.join('#include ' + json.dumps(str(source_file(p)).replace('\\', '/')) for p in unit['sources']) + '\n')
        options = prepared['common'] + [expand(o) for o in unit.get('options', [])]
        pch = ['-include-pch', str(prepared['precompiled'][unit['pch']])] if unit.get('pch') else []
        command = [tool, '-c', *defaults, *comp.portable_flags(options), *pch,
            '-ftime-trace=' + str(target / (name + '.json')), '-o', str(target / (name + '.obj')), str(source)]
        LOCAL.phase = trial + ':' + name
        with (target / (name + '.log')).open('wb') as log:
            subprocess.run(command, env=environment, stdout=log, stderr=subprocess.STDOUT, check=True)
        trace = json.loads((target / (name + '.json')).read_text())['traceEvents']
        totals = {e['name'].removeprefix('Total '): e['dur']/1000 for e in trace if e.get('name', '').startswith('Total ')}
        passes = {}
        for event in trace:
            if event.get('name') == 'RunPass':
                label = event.get('args', {}).get('detail', '?')
                passes[label] = passes.get(label, 0) + event.get('dur', 0)/1000
        with LOCK: ROWS.append({'name': 'compile-sample', 'unit': name, 'trial': trial, 'sourceBytes': sizes[name],
            'objectBytes': (target / (name + '.obj')).stat().st_size, 'totalsMs': totals,
            'topPassesMs': sorted(passes.items(), key=lambda x:x[1], reverse=True)[:10]})
        save()
    with span('compile-samples-serial', count=len(chosen)):
        for unit in chosen: compile_sample(unit, 'serial')
    # Same generated workload, different job limits; runtime outliers measured once above.
    parallel = [u for u in chosen if u.get('generated')][:6]
    if len(parallel) >= 4:
        for jobs in [2, 4]:
            with span('compile-samples-parallel-' + str(jobs), count=len(parallel)):
                with ThreadPoolExecutor(max_workers=jobs) as pool:
                    list(pool.map(lambda u: compile_sample(u, 'parallel-' + str(jobs)), parallel))
    if args.relink:
        repo = Path(__file__).resolve().parents[2]
        reference = repo / 'build-ninja/portable-release/first-run/local-game-link.rsp'
        arguments = [json.loads(line) for line in reference.read_text().splitlines() if line.strip()]
        position = arguments.index('-o') + 1
        arguments[position] = str(OUT / 'reference-relink.exe')
        response = OUT / 'reference-link.rsp'; response.write_text(comp.response_text(arguments, True))
        with span('reference-full-relink', cachedReferenceObjects=True):
            with (OUT / 'reference-link.log').open('wb') as log:
                subprocess.run([tool, '@' + str(response)], env=environment, stdout=log, stderr=subprocess.STDOUT, check=True)
    save()
    print('PROFILE COMPLETE ' + str(OUT), flush=True)

if __name__ == '__main__':
    main()
