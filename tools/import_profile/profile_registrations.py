"""Private compile experiments for huge host registration functions and one large guest batch."""
import ast
import copy
import importlib
import json
import os
from pathlib import Path
import re
import sys
from profile_followup import run

def main():
    root = Path(sys.argv[1]).resolve(); paths = json.loads((root / 'paths.json').read_text())
    out = root / (sys.argv[2] if len(sys.argv) > 2 else 'registration-profile');
    if out.parent != root: raise ValueError('Use a simple new output name')
    out.mkdir()
    kit = next(p for p in Path(paths['kit']).iterdir() if (p / 'build-kit.json').exists())
    work = root / 'worker-profile/work'
    os.environ['REO_LLVM_MINGW'] = paths['compiler']; sys.path.insert(0, str(kit / 'tools/local_build'))
    comp = importlib.import_module('compile_game'); ns = dict(comp.__dict__)
    tree = ast.parse(Path(comp.__file__).read_text()); function = copy.deepcopy(next(n for n in tree.body if isinstance(n, ast.FunctionDef) and n.name == 'compile_plan'))
    boundary = next(i for i,n in enumerate(function.body) if isinstance(n, ast.FunctionDef) and n.name == 'compile_unit')
    function.name = 'prepare'; function.body = function.body[:boundary] + [ast.Return(ast.Call(ast.Name('locals', ast.Load()), [], []))]
    exec(compile(ast.fix_missing_locations(ast.Module([function], type_ignores=[])), comp.__file__, 'exec'), ns)
    data = ns['prepare'](kit, work / 'project/recomp/config', work, root/'worker-profile/output', 1)
    registry = next(u for u in data['units'] if u['id'] == 'overlay632')
    assert len(registry['sources']) == 1
    registry_path = data['source_file'](registry['sources'][0])
    original = registry_path.read_text()
    match = re.search(r'^void (\w+)\(PS2Runtime& runtime\) \{\n', original, re.M)
    assert match and original.rstrip().endswith('}')
    body = original[match.end():original.rfind('}')]
    calls = [line for line in body.splitlines() if line.strip()]
    assert all(re.fullmatch(r'\s*runtime\.registerOverlayFunction\([^\n]+\);', line) for line in calls)
    rows = []
    def compile_one(unit, source, name, extra=()):
        options = data['common'] + [data['expand'](o) for o in unit.get('options', [])]
        pch = ['-include-pch', str(data['precompiled'][unit['pch']])] if unit.get('pch') else []
        target = out/(name+'.obj'); trace = out/(name+'.json')
        row = run([str(data['compiler']), '-c', *data['portable_defaults'], *comp.portable_flags(options), *pch, *extra,
            '-ftime-trace='+str(trace), '-o', str(target), str(source)], data['env'], out/(name+'.log'), name)
        row['objectBytes'] = target.stat().st_size
        events = json.loads(trace.read_text())['traceEvents']
        row['totalsMs'] = {e['name'][6:]: e['dur']/1000 for e in events if e.get('name','').startswith('Total ')}
        rows.append(row)
        (out/'results.json').write_text(json.dumps({'experimentsOnly':True,'gameExecuted':False,'registryCalls':len(calls),'exactCallOrderPreserved':True,'rows':rows},indent=2))
    guest_only = '--guest-no-inline-only' in sys.argv[3:]
    for size in ([] if guest_only else [256, 1024]):
        chunks = [calls[i:i+size] for i in range(0,len(calls),size)]
        prefix = original[:match.start()]
        transformed = prefix + '\n'.join('static __attribute__((noinline)) void profileRegistration'+str(i)+'(PS2Runtime& runtime) {\n'+'\n'.join(chunk)+'\n}\n' for i,chunk in enumerate(chunks))
        transformed += 'void '+match[1]+'(PS2Runtime& runtime) {\n'+''.join('    profileRegistration'+str(i)+'(runtime);\n' for i in range(len(chunks)))+'}\n'
        recovered = [line for line in transformed.splitlines() if 'runtime.registerOverlayFunction(' in line]
        assert recovered == calls
        source = out/('register-'+str(size)+'.cpp'); source.write_text(transformed)
        compile_one(registry, source, 'register-chunk-'+str(size), ['-I', str(registry_path.parent)])
    # Largest reference object was main693: this is guest code, not a registry.
    guest = next(u for u in data['units'] if u['id'] == 'main693')
    assert not any(Path(p).name.startswith('register_') for p in guest['sources'])
    source = out/'main693.cpp'; source.write_text('\n'.join('#include '+json.dumps(str(data['source_file'](p)).replace('\\','/')) for p in guest['sources'])+'\n')
    if not guest_only:
        compile_one(guest, source, 'guest-default')
    compile_one(guest, source, 'guest-no-auto-inline', ['-fno-inline-functions'])

if __name__ == '__main__': main()
