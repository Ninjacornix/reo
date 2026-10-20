"""Native small-program cache/link checks; no game input or gameplay execution."""
import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest

from compile_game import compile_plan
from compilation_batches import with_generated_batches


@unittest.skipUnless(sys.platform == 'win32' and os.environ.get('REO_TEST_CXX'),
                     'Set REO_TEST_CXX and REO_LLVM_MINGW for Windows compiler integration')
class WindowsCompileTests(unittest.TestCase):
    def test_larger_generated_batches_preserve_calls_and_results(self):
        with tempfile.TemporaryDirectory(prefix='reo-batch-check-') as folder:
            root = Path(folder)
            kit, generated = root / 'kit', root / 'generated'
            kit.mkdir()
            generated.mkdir()
            functions = generated / 'functions'
            functions.mkdir()
            declarations = '\n'.join(f'int f{i}(int);' for i in range(40))
            (generated / 'decl.h').write_text(
                '#pragma once\nextern unsigned visits,live,destroyed;\n'
                'struct Scope{Scope(){++live;}~Scope(){--live;++destroyed;}};\n' + declarations)
            for name in ['ps2_runtime.h', 'ps2_runtime_macros.h', 'source_instruction_access.hpp']:
                (generated / name).write_text('#pragma once\n')
            for i in range(40):
                body = '(x<0?throw 17:x)' if i == 0 else f'f{i-1}(x)+{i}'
                (functions / f'f{i:02}.cpp').write_text(
                    f'#include "decl.h"\nint f{i}(int x){{Scope scope;++visits;return {body};}}\n')
            table = ','.join(f'f{i}' for i in range(40))
            (generated / 'main.cpp').write_text(
                '#include "decl.h"\nunsigned visits=0,live=0,destroyed=0;\n'
                f'int main(){{int (*functions[])(int)={{{table}}};int sum=0;'
                'for(auto f:functions)sum+=f(1);'
                'if(sum!=10700||visits!=820||destroyed!=820||live)return 1;'
                'try{f39(-1);return 2;}catch(int value){if(value!=17)return 3;}'
                'return visits!=860||destroyed!=860||live;}\n')
            compiler = Path(os.environ['REO_TEST_CXX'])
            plan = {
                'format': 1, 'runtimeAbi': 'batch-fixture', 'toolchain': 'llvm-mingw',
                'compiler': '{kit}/toolchain/bin/' + compiler.name,
                'archiver': '{kit}/toolchain/bin/llvm-ar.exe',
                'resourceCompiler': '{kit}/toolchain/bin/x86_64-w64-mingw32-windres.exe',
                'externalToolchain': True,
                'externalCompilerSha256': hashlib.sha256(compiler.read_bytes()).hexdigest(),
                'compileOptions': ['/I{generated}'],
                'units': [{'id': 'entry', 'sources': ['{generated}/main.cpp']}],
                'sourceGroups': [{'id': 'main', 'root': '{generated}/functions',
                                  'pattern': '*.cpp', 'batch': 8}],
                'copyOutputs': [
                    {'source': '{kit}/toolchain/x86_64-w64-mingw32/bin/' + name, 'destination': name}
                    for name in ['libc++.dll', 'libunwind.dll', 'libwinpthread-1.dll']],
            }
            for name, selected, count in [('old', plan, 5),
                                           ('batched', with_generated_batches(plan, batch_size=64), 1)]:
                (kit / 'compile-plan.json').write_text(json.dumps(selected))
                work, output = root / (name + '-work'), root / (name + '-output')
                compile_plan(kit, generated, work, output, 4)
                subprocess.run([str(output / 'reo_recomp.exe')], check=True)
                self.assertEqual(len(list((work / 'objects').glob('main*.obj'))), count)

    def test_archive_link_reuse_header_edit_corruption_and_failure(self):
        with tempfile.TemporaryDirectory(prefix='reo-compile-check-') as folder:
            root = Path(folder)
            kit, generated, work, output = [root / name for name in ['kit', 'generated', 'work', 'output']]
            kit.mkdir(); generated.mkdir()
            compiler = Path(os.environ['REO_TEST_CXX'])
            driver = '{kit}/toolchain/bin/' + compiler.name
            header = generated / 'value.h'
            header.write_text('#define VALUE 42\n')
            entry = generated / 'entry'
            entry.mkdir()
            (entry / 'main.cpp').write_text('#include "value.h"\nint helper();int main(){return helper()!=VALUE;}')
            for name in ['ps2_runtime.h', 'ps2_runtime_macros.h', 'source_instruction_access.hpp']:
                (generated / name).write_text('#pragma once\n')  # Synthetic empty PCH fixtures.
            helper = generated / 'helper.cpp'
            helper.write_text('#include "value.h"\nint helper(){return VALUE;}')
            plan = {'format': 1, 'runtimeAbi': 'compiler-fixture', 'toolchain': 'llvm-mingw',
                    'compiler': driver, 'archiver': '{kit}/toolchain/bin/llvm-ar.exe',
                    'resourceCompiler': '{kit}/toolchain/bin/x86_64-w64-mingw32-windres.exe',
                    'externalToolchain': True,
                    'externalCompilerSha256': hashlib.sha256(compiler.read_bytes()).hexdigest(),
                    'compileOptions': ['/I{generated}'],
                    'units': [{'id': 'helper', 'sources': ['{generated}/helper.cpp'], 'archive': 'runtime'}],
                    'sourceGroups': [{'id': 'main', 'root': '{generated}/entry', 'pattern': '*.cpp', 'batch': 8}],
                    'copyOutputs': [{'source': '{kit}/toolchain/x86_64-w64-mingw32/bin/' + name,
                                     'destination': name}
                                    for name in ['libc++.dll', 'libunwind.dll', 'libwinpthread-1.dll']]}
            (kit / 'compile-plan.json').write_text(json.dumps(plan))
            def build():
                compile_plan(kit, generated, work, output, 7)
                subprocess.run([str(output / 'reo_recomp.exe')], check=True)
            build()
            obj = work / 'objects/helper.obj'
            first = obj.stat().st_mtime_ns
            build()
            self.assertEqual(obj.stat().st_mtime_ns, first)
            obj.with_suffix('.json').write_text('[]')
            build()
            self.assertNotEqual(obj.stat().st_mtime_ns, first)
            header.write_text('#define VALUE 43\n')
            build()
            self.assertNotEqual(obj.stat().st_mtime_ns, first)
            obj.write_bytes(b'corrupt')
            build()
            self.assertGreater(obj.stat().st_size, 7)
            saved = hashlib.sha256((output / 'reo_recomp.exe').read_bytes()).hexdigest()
            helper.write_text('invalid C++')
            with self.assertRaisesRegex(RuntimeError, 'Compile unit helper failed'):
                compile_plan(kit, generated, work, output, 7)
            with self.assertRaisesRegex(RuntimeError, 'Portable preflight failed'):
                compile_plan(kit, generated, work, output, 7, preflight=True)
            self.assertEqual(hashlib.sha256((output / 'reo_recomp.exe').read_bytes()).hexdigest(), saved)


if __name__ == '__main__':
    unittest.main()
