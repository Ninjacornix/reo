"""Check real generation resume against an existing PCH, in the private profile workspace."""
import ast
import copy
import importlib
import json
import os
from pathlib import Path
import sys
import time
from profile_followup import run


def main():
    root = Path(sys.argv[1]).resolve()
    paths = json.loads((root / 'paths.json').read_text())
    out = root / 'resume-probe'
    out.mkdir()
    kit = next(p for p in Path(paths['kit']).iterdir() if (p / 'build-kit.json').exists())
    work = root / 'worker-profile/work'
    os.environ['REO_LLVM_MINGW'] = paths['compiler']
    sys.path.insert(0, str(kit / 'tools/local_build'))
    comp = importlib.import_module('compile_game')
    build = importlib.import_module('build_game')
    tree = ast.parse(Path(comp.__file__).read_text())
    function = copy.deepcopy(next(n for n in tree.body if isinstance(n, ast.FunctionDef) and n.name == 'compile_plan'))
    boundary = next(i for i, n in enumerate(function.body) if isinstance(n, ast.FunctionDef) and n.name == 'compile_unit')
    function.name = 'prepare'
    function.body = function.body[:boundary] + [ast.Return(ast.Call(ast.Name('locals', ast.Load()), [], []))]
    ns = dict(comp.__dict__)
    exec(compile(ast.fix_missing_locations(ast.Module([function], type_ignores=[])), comp.__file__, 'exec'), ns)

    def prepare():
        return ns['prepare'](kit, work / 'project/recomp/config', work, root / 'worker-profile/output', 1)

    before = prepare()
    old_pch = {k: {'mtimeNs': p.stat().st_mtime_ns, 'sha256': comp.digest(p)} for k, p in before['precompiled'].items()}
    recipes = json.loads((kit / 'metadata/local_source_recipes.json').read_text())['recipes']
    headers = [r['destination'] for r in recipes if Path(r['destination']).suffix in {'.h', '.hpp', '.inc', '.inl'}]
    old_headers = {p: {'mtimeNs': (work / 'project' / p).stat().st_mtime_ns, 'sha256': comp.digest(work / 'project' / p)} for p in headers}
    class StopBeforeCompile(Exception):
        pass
    def stop(*args, **kwargs):
        raise StopBeforeCompile()
    build.compile_plan = stop
    started = time.perf_counter()
    try:
        build.build(kit, Path(paths['imported']) / 'data', work, root / 'worker-profile/output', 1)
    except StopBeforeCompile:
        pass
    resume_seconds = time.perf_counter() - started
    data = prepare()
    new_pch = {k: {'mtimeNs': p.stat().st_mtime_ns, 'sha256': comp.digest(p)} for k, p in data['precompiled'].items()}
    new_headers = {p: {'mtimeNs': (work / 'project' / p).stat().st_mtime_ns, 'sha256': comp.digest(work / 'project' / p)} for p in headers}
    unit = next(u for u in data['units'] if u['id'] == 'main87')
    source = out / 'resume.cpp'
    source.write_text('\n'.join('#include ' + json.dumps(str(data['source_file'](p)).replace('\\', '/')) for p in unit['sources']) + '\n')
    options = data['common'] + [data['expand'](o) for o in unit.get('options', [])]
    command = [str(data['compiler']), '-c', *data['portable_defaults'], *comp.portable_flags(options), '-include-pch', str(data['precompiled'][unit['pch']]), '-o', str(out / 'resume.obj'), str(source)]
    result = {'gameExecuted': False, 'productionChanged': False, 'resumeSeconds': resume_seconds,
              'pchReusedUnchanged': old_pch == new_pch, 'oldRecipeHeaders': old_headers, 'newRecipeHeaders': new_headers}
    try:
        result['compile'] = run(command, data['env'], out / 'compile.log', 'post-generation-resume-compile')
    except RuntimeError as error:
        result['compileFailure'] = str(error)
    (out / 'result.json').write_text(json.dumps(result, indent=2))
    print(json.dumps(result), flush=True)


if __name__ == '__main__':
    main()
