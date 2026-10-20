"""Measure the actual candidate kit through generation and representative registry compiles."""
import ast
import copy
import importlib
import json
import os
from pathlib import Path
import subprocess
import sys
import time


def main():
    repo = Path(__file__).resolve().parents[2]
    root = Path(sys.argv[1]).resolve()
    if not root.is_relative_to(repo / 'build-ninja'):
        raise ValueError('Use a private build workspace')
    kit = root / 'kit'
    out = root / 'worker-benchmark'
    out.mkdir()
    previous = json.loads((repo / 'build-ninja/import-profile-20261020/paths.json').read_text())
    os.environ['REO_LLVM_MINGW'] = previous['compiler']
    sys.path.insert(0, str(kit / 'tools/local_build'))
    build = importlib.import_module('build_game')
    comp = importlib.import_module('compile_game')
    work, output = out / 'work', out / 'output'
    rows = []

    def save():
        (out / 'results.json').write_text(json.dumps({'fullFreshCompilation': False,
            'gameRun': False, 'kit': str(kit), 'rows': rows}, indent=2))

    class StopAtCompiler(Exception):
        pass
    def stop(*args, **kwargs):
        raise StopAtCompiler()
    build.compile_plan = stop
    for name in ['fresh-preparation-generation', 'resumed-preparation-generation']:
        started = time.perf_counter()
        try:
            build.build(kit, Path(previous['imported']) / 'data', work, output, 4)
        except StopAtCompiler:
            pass
        rows.append({'name': name, 'seconds': time.perf_counter() - started})
        save()
        print(rows[-1], flush=True)
    tree = ast.parse(Path(comp.__file__).read_text())
    function = copy.deepcopy(next(n for n in tree.body if isinstance(n, ast.FunctionDef) and n.name == 'compile_plan'))
    boundary = next(i for i, n in enumerate(function.body) if isinstance(n, ast.FunctionDef) and n.name == 'compile_unit')
    function.name = 'prepare'
    function.body = function.body[:boundary] + [ast.Return(ast.Call(ast.Name('locals', ast.Load()), [], []))]
    namespace = dict(comp.__dict__)
    exec(compile(ast.fix_missing_locations(ast.Module([function], type_ignores=[])), comp.__file__, 'exec'), namespace)
    started = time.perf_counter()
    data = namespace['prepare'](kit, work / 'project/recomp/config', work, output, 4)
    rows.append({'name': 'compiler-preparation-pch', 'seconds': time.perf_counter() - started,
                 'units': len(data['units'])})
    save()
    for name in ['register_functions.cpp', 'register_o2.cpp']:
        unit = next(u for u in data['units'] if any(Path(s).name == name for s in u['sources']))
        source = out / (name + '.unity.cpp')
        source.write_text('\n'.join('#include ' + json.dumps(str(data['source_file'](p)).replace('\\', '/')) for p in unit['sources']) + '\n')
        options = data['common'] + [data['expand'](o) for o in unit.get('options', [])]
        pch = ['-include-pch', str(data['precompiled'][unit['pch']])] if unit.get('pch') else []
        started = time.perf_counter()
        with (out / (name + '.log')).open('wb') as log:
            subprocess.run([str(data['compiler']), '-c', *data['portable_defaults'],
                *comp.portable_flags(options), *pch, '-o', str(out / (name + '.obj')), str(source)],
                env=data['env'], stdout=log, stderr=subprocess.STDOUT, check=True)
        rows.append({'name': 'compile:' + name, 'seconds': time.perf_counter() - started, 'unit': unit['id']})
        save()
        print(rows[-1], flush=True)


if __name__ == '__main__':
    main()
