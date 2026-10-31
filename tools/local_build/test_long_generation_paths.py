"""Real Windows file I/O with long paths disabled for the Python test process."""
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys
import tempfile
import unittest

from long_paths import extended

ROOT = Path(__file__).resolve().parents[2]


@unittest.skipUnless(sys.platform == 'win32', 'Win32 path-limit integration')
class WindowsGenerationPaths(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.temporary = tempfile.TemporaryDirectory(prefix='reo-path-host-')
        cls.addClassCleanup(cls.temporary.cleanup)
        cls.folder = Path(cls.temporary.name).resolve()
        # Cleanup must also work when the parent Python process has long paths
        # disabled, rather than relying on the machine used to run these tests.
        def cleanup():
            target = extended(cls.folder)
            if target.exists():
                if target.resolve() != extended(cls.temporary.name).resolve() or not cls.folder.name.startswith('reo-path-host-'):
                    raise RuntimeError('Unexpected path-test cleanup target')
                shutil.rmtree(target)
        cls.addClassCleanup(cleanup)
        cls.host = cls.folder / 'python_legacy_paths.exe'
        cls.dll = Path(os.environ.get('REO_TEST_PYTHON_DLL', str(
            Path(sys.base_prefix) / f'python{sys.version_info.major}{sys.version_info.minor}.dll')))
        if not cls.dll.is_file():
            raise unittest.SkipTest('A shared Windows Python runtime is required')
        batch = cls.folder / 'build.bat'
        batch.write_text('@echo off\ncall "' + str(ROOT / 'tools/vcvars64.bat') + '"\n'
                         'if errorlevel 1 exit /b 1\n'
                         'cl /nologo /EHsc /O2 "' + str(ROOT / 'tools/local_build/fixtures/python_legacy_paths.cpp') +
                         '" /Fo:"' + str(cls.folder / 'host.obj') + '" /Fe:"' + str(cls.host) + '"\n')
        result = subprocess.run([os.environ.get('COMSPEC', 'cmd.exe'), '/d', '/c', str(batch)],
                                capture_output=True, text=True)
        if result.returncode:
            if os.environ.get('REO_REQUIRE_LONG_PATH_TESTS'):
                raise RuntimeError(result.stdout + result.stderr)
            raise unittest.SkipTest('MSVC is required to build the non-long-path-aware test host')
        probe = cls.folder / 'probe.py'
        probe.write_text('print("test runtime ready")\n')
        result = subprocess.run([str(cls.host), str(cls.dll), str(probe)], capture_output=True, text=True,
                                env=dict(os.environ, PYTHONHOME=str(cls.dll.parent)))
        if result.returncode:
            if os.environ.get('REO_REQUIRE_LONG_PATH_TESTS'):
                raise RuntimeError(result.stderr)
            raise unittest.SkipTest('Set REO_TEST_PYTHON_DLL to a loadable shared Python runtime')

    def child(self, script, *args):
        path = self.folder / ('test-' + self.id().rsplit('.', 1)[-1] + '.py')
        path.write_text('import sys\nsys.path.insert(0, ' + repr(str(ROOT / 'tools/local_build')) + ')\n' + script)
        return subprocess.run([str(self.host), str(self.dll), str(path), *map(str, args)],
                              capture_output=True, text=True,
                              env=dict(os.environ, PYTHONHOME=str(self.dll.parent)))

    def test_ordinary_261_character_path_fails_but_extended_path_reads(self):
        name = 'coop_verified_callback_0058BFF0_0x58bff0.cpp'
        base = self.folder / ('p' * (261 - len(str(self.folder)) - len(name) - 2))
        extended(base).mkdir()
        path = base / name
        extended(path).write_text('Synthetic source fixture')
        ordinary = self.child('from pathlib import Path\nprint(Path(sys.argv[1]).read_text())\n', path)
        self.assertNotEqual(ordinary.returncode, 0)
        self.assertIn('FileNotFoundError', ordinary.stderr)
        fixed = self.child('from long_paths import extended\nprint(extended(sys.argv[1]).read_text())\n', path)
        self.assertEqual(fixed.returncode, 0, fixed.stderr)
        self.assertIn('Synthetic source fixture', fixed.stdout)

    def test_supplemental_generation_reads_long_callback_and_cleans_private_outputs(self):
        name = 'coop_verified_callback_0058BFF0_0x58bff0.cpp'
        suffix = str(Path('inputs/supplemental6') / name)
        stage = self.folder / ('s' * (261 - len(str(self.folder)) - len(suffix) - 2))
        self.assertEqual(len(str(stage / suffix)), 261)
        result = self.child(r'''
import csv,json,struct
from pathlib import Path
from long_paths import extended
from generate_support import generate_support
stage=Path(sys.argv[1]);metadata=extended(stage/'metadata')
metadata.mkdir(parents=True);extended(stage/'inputs').mkdir()
extended(stage/'inputs/o1.elf').write_bytes(bytes(160))
groups=[]
for n in range(7):
    name='coop_verified_callback_0058BFF0' if n==6 else 'synthetic_callback_'+str(n)
    groups.append({'overlay':1,'destination':'callback'+str(n)+'.cpp',
        'functions':[{'name':name,'start':'0x58bff0','end':'0x58bff8','size':8}]})
(metadata/'local_supplemental_functions.json').write_text(json.dumps({'format':1,'groups':groups}))
(metadata/'local_legacy_entries.json').write_text(json.dumps({'format':1,'entries':[]}))
def invoke(tag,elf,mapping,output):
    output=extended(output);output.mkdir()
    (output/'ps2_recompiled_functions.h').write_text('#pragma once\n')
    (output/'ps2_recompiled_stubs.h').write_text('#pragma once\n')
    with extended(mapping).open(newline='') as stream:
        for row in csv.DictReader(stream):
            source=output/(row['name']+'_0x'+format(int(row['start'],16),'x')+'.cpp')
            source.write_text('// Synthetic fixture\n#include "ps2_recompiled_functions.h"\n')
generate_support(stage,metadata,invoke)
for n in range(7):
    assert 'supplemental'+str(n)+'_functions.h' in extended(stage/f'output_extra/callback{n}.cpp').read_text()
    assert not list(extended(stage/f'inputs/supplemental{n}').glob('*.cpp'))
assert extended(stage/'output_overlay/legacy_adapters.cpp').is_file()
print('supplemental6 generated and read; private intermediates cleaned')
''', stage)
        self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
        self.assertIn('supplemental6 generated and read', result.stdout)

    def test_stage_receipts_read_and_reuse_long_outputs(self):
        base = self.folder / ('r' * 140)
        result = self.child(r'''
from long_paths import extended,native
from build_game import stage
base=extended(sys.argv[1]);base.mkdir()
source=base/('synthetic_long_source_'+('x'*80)+'.cpp')
assert len(native(source))>259
source.write_text('Synthetic receipt fixture')
calls=[]
def action():calls.append(1)
stage(base,'long-receipt',[source],action,lambda:[source],jobs=2)
stage(base,'long-receipt',[source],action,lambda:[source],jobs=2)
assert len(calls)==1
print('long-path stage receipt reused verified output')
''', base)
        self.assertEqual(result.returncode, 0, result.stdout + result.stderr)

    @unittest.skipUnless(os.environ.get('REO_TEST_CXX') and os.environ.get('REO_LLVM_MINGW'),
                         'Set REO_TEST_CXX and REO_LLVM_MINGW for the release compiler integration')
    def test_compilation_receipts_and_cache_reuse_beyond_max_path(self):
        base = self.folder / ('c' * 140)
        result = self.child(r'''
import hashlib,json,os,subprocess
from pathlib import Path
from long_paths import extended,native
from compile_game import compile_plan,digest
from build_game import stage
base=extended(sys.argv[1]);kit=base/'kit';generated=base/'generated';work=base/'work';output=base/'output'
kit.mkdir(parents=True);generated.mkdir()
name='synthetic_generation_callback_with_a_long_filename_to_exercise_max_path.cpp'
(generated/name).write_text('int main(){return 0;}\n')
assert len(native(generated/name))>259
compiler=Path(os.environ['REO_TEST_CXX'])
plan={'format':1,'runtimeAbi':'long-path-test','toolchain':'llvm-mingw','externalToolchain':True,
      'compiler':'{kit}/toolchain/bin/'+compiler.name,'archiver':'{kit}/toolchain/bin/llvm-ar.exe',
      'resourceCompiler':'{kit}/toolchain/bin/x86_64-w64-mingw32-windres.exe',
      'externalCompilerSha256':hashlib.file_digest(compiler.open('rb'),'sha256').hexdigest(),
      'units':[{'id':'entry','sources':['{generated}/'+name]}],
      'copyOutputs':[{'source':'{kit}/toolchain/x86_64-w64-mingw32/bin/'+n,'destination':n}
                     for n in ('libc++.dll','libunwind.dll','libwinpthread-1.dll')]}
(kit/'compile-plan.json').write_text(json.dumps(plan))
calls=[]
def action():calls.append(1)
stage(base,'long-receipt',[generated/name],action,lambda:[generated/name],jobs=2)
stage(base,'long-receipt',[generated/name],action,lambda:[generated/name],jobs=2)
assert len(calls)==1
compile_plan(kit,generated,work,output,1)
before=digest(work/'objects/entry.obj');stamp=(work/'objects/entry.obj').stat().st_mtime_ns
compile_plan(kit,generated,work,output,1)
assert (work/'objects/entry.obj').stat().st_mtime_ns==stamp
assert digest(work/'objects/entry.obj')==before
subprocess.run([native(output/'reo_recomp.exe')],check=True)
print('long-path native compilation, linking and cache reuse passed')
''', base)
        self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
        self.assertIn('long-path native compilation, linking and cache reuse passed', result.stdout)


if __name__ == '__main__':
    unittest.main()
