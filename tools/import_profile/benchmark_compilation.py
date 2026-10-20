"""Compare old/new preparation, scheduling, flags and compiled objects on real private units."""
import ast
import copy
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import subprocess
import sys
import time
from concurrent.futures import ThreadPoolExecutor, as_completed


def load(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    module = importlib.util.module_from_spec(spec)
    # Read the verified source directly; do not write bytecode into a sealed kit.
    exec(compile(Path(path).read_text(), str(path), 'exec'), module.__dict__)
    return module


def prepare(module, kit, work, output, jobs):
    tree = ast.parse(Path(module.__file__).read_text())
    function = copy.deepcopy(next(n for n in tree.body if isinstance(n, ast.FunctionDef) and n.name == 'compile_plan'))
    boundary = next(i for i, n in enumerate(function.body) if isinstance(n, ast.FunctionDef) and n.name == 'compile_unit')
    nested = function.body[boundary]
    function.name = 'prepare'
    function.body = function.body[:boundary] + [ast.Return(ast.Call(ast.Name('locals', ast.Load()), [], []))]
    namespace = dict(module.__dict__)
    exec(compile(ast.fix_missing_locations(ast.Module([function], type_ignores=[])), module.__file__, 'exec'), namespace)
    before = time.perf_counter()
    data = namespace['prepare'](kit, work / 'project/recomp/config', work, output, jobs)
    return data, time.perf_counter() - before, nested


def main():
    repo = Path(__file__).resolve().parents[2]
    out = Path(sys.argv[1]).resolve()
    if not out.is_relative_to(repo / 'build-ninja') or out.exists():
        raise ValueError('Use a fresh private directory')
    out.mkdir(parents=True)
    paths = json.loads((repo / 'build-ninja/import-profile-20261020/paths.json').read_text())
    os.environ['REO_LLVM_MINGW'] = paths['compiler']
    sys.path.insert(0, str(repo / 'tools/local_build'))
    from build_scheduler import scheduled_results, unit_estimates
    kit = repo / 'build-ninja/import-optimized-20261020/kit'
    work = repo / 'build-ninja/import-optimized-20261020/worker-benchmark/work'
    modules = {'old': load('old_compile', kit / 'tools/local_build/compile_game.py'),
               'new': load('new_compile', repo / 'tools/local_build/compile_game.py')}
    prepared = {}
    rows = []
    def save():
        (out / 'results.json').write_text(json.dumps({'gameRun': False, 'fullGameCompile': False, 'rows': rows}, indent=2))
    for name in ['old', 'new', 'new', 'old']:
        data, seconds, nested = prepare(modules[name], kit, work, out / 'unused-output', 7)
        prepared[name] = (data, nested)
        rows.append({'stage': 'preparation', 'variant': name, 'seconds': seconds})
        save()
        print(rows[-1], flush=True)
    old, new = prepared['old'][0], prepared['new'][0]
    remove_pch = lambda units: [{k: v for k, v in u.items() if k != 'pch'} for u in units]
    assert remove_pch(old['units']) == remove_pch(new['units'])
    assert old['portable_defaults'] == new['portable_defaults'] and old['common'] == new['common']
    assert json.loads(old['base'])['headers'] == json.loads(new['base'])['headers']
    for unit in new['units']:
        if unit['id'] not in new.get('size_hints', {}):
            continue
        sources = [new['source_file'](p) for p in unit['sources']]
        sizes = [p.stat().st_size for p in sources]
        assert new['size_hints'][unit['id']] == (sum(sizes), any(
            size > 750000 and not path.name.startswith('register') for path, size in zip(sources, sizes)))
    (out / 'plan-parity.json').write_text(json.dumps({'sameUnitsSourcesOptions': True,
        'sameDefaultsAndCommonFlags': True, 'sameHeaderFingerprint': True, 'units': len(old['units'])}, indent=2))
    if '--plan-only' in sys.argv[2:]:
        return
    # Balanced real workload: ordinary guest batches plus runtime/backend work.
    selected = []
    if '--runtime' in sys.argv[2:]:
        selected = [u for u in old['units'] if not u.get('generated')]
    for prefix, count in ([] if selected else [('main', 10), ('overlay', 10), ('authored', 4), ('runtime', 4), ('backend', 4)]):
        group = [u for u in old['units'] if u['id'].rstrip('0123456789') == prefix]
        group.sort(key=lambda u: sum(old['source_file'](p).stat().st_size for p in u['sources']))
        for i in range(count):
            index = len(group) * (i + 1) // (count + 1)
            if group[index] not in selected:
                selected.append(group[index])
    ids = {u['id'] for u in selected}
    for variant, jobs in [('old', 4), ('new', 7)]:
        data, nested = prepared[variant]
        trial = out / variant
        trial.mkdir()
        objects, logs = trial / 'objects', trial / 'logs'
        objects.mkdir(); logs.mkdir()
        namespace = {**modules[variant].__dict__, **data, 'objects': objects, 'logs': logs}
        exec(compile(ast.fix_missing_locations(ast.Module([copy.deepcopy(nested)], type_ignores=[])), modules[variant].__file__, 'exec'), namespace)
        units = [u for u in data['units'] if u['id'] in ids]
        started = time.perf_counter()
        if variant == 'old':
            with ThreadPoolExecutor(max_workers=jobs) as pool:
                futures = {pool.submit(namespace['compile_unit'], unit): unit for unit in units}
                for future in as_completed(futures):
                    future.result()
                    print(variant, futures[future]['id'], flush=True)
        else:
            estimates = {u['id']: unit_estimates(u, [data['source_file'](p) for p in u['sources']], objects / (u['id']+'.json')) for u in units}
            for unit, future in scheduled_results(units, namespace['compile_unit'], jobs, estimates):
                future.result()
                print(variant, unit['id'], flush=True)
        rows.append({'stage': 'compile', 'variant': variant, 'seconds': time.perf_counter()-started, 'jobsUpperBound': jobs, 'units':len(units)})
        save()
        print(rows[-1], flush=True)
    differences = []
    for ident in ids:
        a, b = (out / name / 'objects' / (ident + '.obj') for name in ['old', 'new'])
        if a.read_bytes() != b.read_bytes():
            differences.append(ident)
    (out / 'object-parity.json').write_text(json.dumps({'byteIdentical': len(ids)-len(differences),
        'different': sorted(differences), 'units': len(ids)}, indent=2))
    print('Object byte differences:', differences, flush=True)


if __name__ == '__main__':
    main()
