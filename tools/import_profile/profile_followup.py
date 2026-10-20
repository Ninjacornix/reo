"""Controlled private compiler/linker experiments. Does not change the launcher or its build kit."""
import ast
import copy
import ctypes
from ctypes import wintypes
import importlib
import json
import os
from pathlib import Path
import struct
import subprocess
import sys
import threading
import time
import cProfile
import pstats
from profile_worker import K32, PSAPI, Mem, metrics

class Entry(ctypes.Structure):
    _fields_ = [('size', wintypes.DWORD), ('usage', wintypes.DWORD), ('pid', wintypes.DWORD), ('heap', ctypes.c_size_t),
        ('module', wintypes.DWORD), ('threads', wintypes.DWORD), ('parent', wintypes.DWORD), ('priority', wintypes.LONG), ('flags', wintypes.DWORD), ('exe', wintypes.WCHAR * 260)]
class MemoryStatus(ctypes.Structure):
    _fields_ = [('length', wintypes.DWORD), ('load', wintypes.DWORD)] + [(n, ctypes.c_ulonglong) for n in ('physical', 'available', 'commit', 'available_commit', 'virtual', 'available_virtual', 'extended')]
K32.CreateToolhelp32Snapshot.argtypes = [wintypes.DWORD, wintypes.DWORD]
K32.CreateToolhelp32Snapshot.restype = wintypes.HANDLE
K32.Process32FirstW.argtypes = [wintypes.HANDLE, ctypes.POINTER(Entry)]
K32.Process32NextW.argtypes = [wintypes.HANDLE, ctypes.POINTER(Entry)]
K32.OpenProcess.argtypes = [wintypes.DWORD, wintypes.BOOL, wintypes.DWORD]
K32.OpenProcess.restype = wintypes.HANDLE
K32.CloseHandle.argtypes = [wintypes.HANDLE]
K32.TerminateProcess.argtypes = [wintypes.HANDLE, wintypes.UINT]
K32.GlobalMemoryStatusEx.argtypes = [ctypes.POINTER(MemoryStatus)]

def process_tree(root):
    snapshot = K32.CreateToolhelp32Snapshot(2, 0)
    if snapshot == ctypes.c_void_p(-1).value: return set()
    rows = []; entry = Entry(); entry.size = ctypes.sizeof(entry)
    try:
        ok = K32.Process32FirstW(snapshot, ctypes.byref(entry))
        while ok:
            rows.append((entry.pid, entry.parent)); ok = K32.Process32NextW(snapshot, ctypes.byref(entry))
    finally: K32.CloseHandle(snapshot)
    found = {root}
    while True:
        expanded = found | {pid for pid, parent in rows if parent in found}
        if expanded == found: return found
        found = expanded

def run(command, env, log, name):
    before = time.perf_counter(); handles = {}; names = {}; peak = 0; failure = None
    with log.open('wb') as stream:
        process = subprocess.Popen(command, env=env, stdout=stream, stderr=subprocess.STDOUT)
        try:
            while process.poll() is None:
                for pid in process_tree(process.pid):
                    if pid not in handles:
                        handle = K32.OpenProcess(0x411, False, pid)
                        if handle: handles[pid] = handle
                working = 0
                for handle in handles.values():
                    memory = Mem(); memory.cb = ctypes.sizeof(memory)
                    if PSAPI.GetProcessMemoryInfo(handle, ctypes.byref(memory), ctypes.sizeof(memory)): working += memory.ws
                peak = max(peak, working)
                state = MemoryStatus(); state.length = ctypes.sizeof(state); K32.GlobalMemoryStatusEx(ctypes.byref(state))
                if state.available < 700 * 1024 * 1024 or state.available_commit < 700 * 1024 * 1024 or time.perf_counter() - before > 240:
                    failure = 'memory guard or 240-second experiment timeout'
                    # Handles identify only this trial's driver/descendants, never unrelated processes.
                    for handle in handles.values(): K32.TerminateProcess(handle, 99)
                    break
                time.sleep(0.05)
            process.wait()
            child_metrics = [metrics(handle) for handle in handles.values()]
        finally:
            for handle in handles.values(): K32.CloseHandle(handle)
    row = {'name': name, 'seconds': time.perf_counter() - before, 'exit': process.returncode,
        'sampledPeakTreeWorkingSetBytes': peak, 'treeCpuMs': sum(m['cpuMs'] for m in child_metrics),
        'processesSampled': len(handles), 'guardFailure': failure}
    print(json.dumps(row), flush=True)
    log.with_suffix('.metrics.json').write_text(json.dumps(row, indent=2))
    if process.returncode: raise RuntimeError('Experiment failed; see ' + str(log))
    return row

def main():
    root = Path(sys.argv[1]).resolve(); paths = json.loads((root / 'paths.json').read_text())
    out = root / 'followup'; out.mkdir()
    kit = next(p for p in Path(paths['kit']).iterdir() if (p / 'build-kit.json').exists())
    work = root / 'worker-profile/work'; output = root / 'worker-profile/output'
    os.environ['REO_LLVM_MINGW'] = paths['compiler']; sys.path.insert(0, str(kit / 'tools/local_build'))
    comp = importlib.import_module('compile_game')
    tree = ast.parse(Path(comp.__file__).read_text())
    function = copy.deepcopy(next(n for n in tree.body if isinstance(n, ast.FunctionDef) and n.name == 'compile_plan'))
    boundary = next(i for i,n in enumerate(function.body) if isinstance(n, ast.FunctionDef) and n.name == 'compile_unit')
    function.name = 'prepare'; function.body = function.body[:boundary] + [ast.Return(ast.Call(ast.Name('locals', ast.Load()), [], []))]
    ns = dict(comp.__dict__); exec(compile(ast.fix_missing_locations(ast.Module([function], type_ignores=[])), comp.__file__, 'exec'), ns)
    profiler = cProfile.Profile(); started = time.perf_counter(); profiler.enable()
    prepared = ns['prepare'](kit, work / 'project/recomp/config', work, output, 1)
    profiler.disable(); profiler.dump_stats(str(out / 'warm-preparation.pstats'))
    with (out / 'warm-preparation.txt').open('w') as stream: pstats.Stats(profiler, stream=stream).sort_stats('cumulative').print_stats(30)
    records = [{'name':'warm-preparation-profiled','seconds':time.perf_counter()-started}]
    unit = next(u for u in prepared['units'] if u['id'] == 'overlay632')
    source = out / 'overlay632.cpp'
    source.write_text('\n'.join('#include ' + json.dumps(str(prepared['source_file'](p)).replace('\\','/')) for p in unit['sources'])+'\n')
    options = prepared['common'] + [prepared['expand'](o) for o in unit.get('options', [])]
    common = [str(prepared['compiler']), '-c', *prepared['portable_defaults'], *comp.portable_flags(options)]
    for name, extra in [('default-pch', ['-include-pch', str(prepared['precompiled'][unit['pch']])]), ('default-no-pch', []), ('no-auto-inline-no-pch', ['-fno-inline-functions'])]:
        target = out / (name + '.obj'); trace = out / (name + '.json')
        row = run([*common, *extra, '-ftime-trace='+str(trace), '-o', str(target), str(source)], prepared['env'], out/(name+'.log'), name)
        row['objectBytes'] = target.stat().st_size
        events = json.loads(trace.read_text())['traceEvents']
        row['compilerTotalsMs'] = {e['name'][6:]: e['dur']/1000 for e in events if e.get('name','').startswith('Total ')}
        records.append(row)
        (out/'results.json').write_text(json.dumps({'experimentsOnly': True, 'gameLaunched': False, 'kitChanged': False, 'rows': records},indent=2))
    repo = Path(__file__).resolve().parents[2]
    response = repo/'build-ninja/portable-release/first-run/local-game-link.rsp'
    arguments = [json.loads(line) for line in response.read_text().splitlines() if line.strip()]
    arguments[arguments.index('-o')+1] = str(out/'reference-icf-safe.exe')
    arguments.append('-Wl,--icf=safe')
    rsp = out/'icf-safe.rsp'; rsp.write_text(comp.response_text(arguments, True))
    row = run([str(prepared['compiler']), '@'+str(rsp)], prepared['env'], out/'icf-safe.log', 'reference-link-icf-safe')
    row['exeBytes'] = (out/'reference-icf-safe.exe').stat().st_size; records.append(row)
    (out/'results.json').write_text(json.dumps({'experimentsOnly': True, 'gameLaunched': False, 'kitChanged': False, 'rows': records},indent=2))

if __name__ == '__main__': main()
