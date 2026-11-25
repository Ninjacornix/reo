import json
from pathlib import Path
import subprocess
import tempfile
import unittest
from unittest.mock import patch

import compile_game
from compile_game import compiler_failure, is_compiler_crash


class CompilerDiagnosticTests(unittest.TestCase):
    def test_real_missing_catalogue_diagnostic_precedes_workspace_path(self):
        with tempfile.TemporaryDirectory() as temporary:
            log = Path(temporary) / 'pch.log'
            log.write_text('Earlier compiler output\n' * 10000 +
                'C:/portable Čakovec 測試/source/irq_cpu_original_catalogue.hpp:6:10: '
                "fatal error: 'local_source_catalogues/irq_cpu_sites.inc' file not found\n"
                '1 error generated.\n', encoding='utf-8')
            message = str(compiler_failure('Shared header compilation', 1, log))
            self.assertIn("fatal error: 'local_source_catalogues/irq_cpu_sites.inc' file not found", message)
            self.assertLess(message.index('fatal error:'), message.index(str(log)))
            self.assertNotIn('Earlier compiler output', message)

    def test_msvc_diagnostic_and_unreadable_log_preserve_failure(self):
        with tempfile.TemporaryDirectory() as temporary:
            log = Path(temporary) / 'unit.log'
            log.write_text('source.cpp(7): fatal error C1083: Cannot open include file: missing.h\n')
            self.assertIn('fatal error C1083: Cannot open include file: missing.h',
                          str(compiler_failure('Compile unit runtime1', 2, log)))
            log.write_text('LINK : fatal error LNK1104: cannot open file missing.lib\n')
            self.assertIn('fatal error LNK1104: cannot open file missing.lib',
                          str(compiler_failure('Game linking', 1, log)))
            log.unlink()
            self.assertIn('Compile unit runtime1 failed (exit 2)',
                          str(compiler_failure('Compile unit runtime1', 2, log)))

    def test_compiler_crash_detection_distinguishes_signals_from_syntax_errors(self):
        with tempfile.TemporaryDirectory() as temporary:
            log = Path(temporary) / 'overlay1155.log'
            log.write_text('clang++: error: clang frontend command failed due to signal (use -v to see invocation)\n')
            self.assertTrue(is_compiler_crash(1, log))
            log.write_text('foo.cpp:4:1: error: expected \';\' after expression\n')
            self.assertFalse(is_compiler_crash(1, log))
            self.assertTrue(is_compiler_crash(0xC0000005, log))
            self.assertFalse(is_compiler_crash(0, log))

    def test_generated_unit_signal_crash_retries_serially_and_falls_back_to_o1(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            kit, gen, work, out = (root / name for name in ('kit', 'gen', 'work', 'out'))
            for d in (kit / 'toolchain/bin', gen / 'ovl', work, out):
                d.mkdir(parents=True, exist_ok=True)
            for tool in ('clang++.exe', 'llvm-ar.exe', 'llvm-windres.exe'):
                (kit / 'toolchain/bin' / tool).write_bytes(b'stub')
            (gen / 'ovl/unit0.cpp').write_text('void f() {}\n', encoding='utf-8')
            plan = {
                'format': 1, 'runtimeAbi': 'test-abi', 'toolchain': 'llvm-mingw',
                'compiler': '{kit}/toolchain/bin/clang++.exe',
                'archiver': '{kit}/toolchain/bin/llvm-ar.exe',
                'resourceCompiler': '{kit}/toolchain/bin/llvm-windres.exe',
                'sourceGroups': [{'id': 'overlay', 'root': '{generated}/ovl', 'pattern': '*.cpp'}],
                'compileOptions': [], 'linkOptions': [],
            }
            (kit / 'compile-plan.json').write_text(json.dumps(plan), encoding='utf-8')
            calls = []

            def fake_run(command, env=None, stdout=None, stderr=None):
                calls.append(list(command))
                if '-x' in command and 'c++-header' in command:
                    Path(command[command.index('-o') + 1]).write_bytes(b'pch')
                    return subprocess.CompletedProcess(command, 0)
                if '-c' in command:
                    out_file = Path(command[command.index('-o') + 1])
                    if '-O2' in command:
                        stdout.write(b'clang++: error: clang frontend command failed due to signal\n')
                        return subprocess.CompletedProcess(command, 1)
                    out_file.write_bytes(b'obj')
                    return subprocess.CompletedProcess(command, 0)
                # Link step
                return subprocess.CompletedProcess(command, 0)

            with patch.object(compile_game, 'run', side_effect=fake_run):
                compile_game.compile_plan(kit, gen, work, out, jobs=2)

            compile_cmds = [c for c in calls if '-c' in c]
            self.assertEqual(len(compile_cmds), 3)
            self.assertIn('-O2', compile_cmds[0])
            self.assertIn('-include-pch', compile_cmds[0])
            self.assertIn('-O2', compile_cmds[1])
            self.assertIn('-include-pch', compile_cmds[1])
            self.assertIn('-O1', compile_cmds[2])
            self.assertNotIn('-include-pch', compile_cmds[2])

    def test_ordinary_compile_error_fails_immediately_without_o1_fallback(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            kit, gen, work, out = (root / name for name in ('kit', 'gen', 'work', 'out'))
            for d in (kit / 'toolchain/bin', gen / 'ovl', work, out):
                d.mkdir(parents=True, exist_ok=True)
            for tool in ('clang++.exe', 'llvm-ar.exe', 'llvm-windres.exe'):
                (kit / 'toolchain/bin' / tool).write_bytes(b'stub')
            (gen / 'ovl/unit0.cpp').write_text('broken\n', encoding='utf-8')
            plan = {
                'format': 1, 'runtimeAbi': 'test-abi', 'toolchain': 'llvm-mingw',
                'compiler': '{kit}/toolchain/bin/clang++.exe',
                'archiver': '{kit}/toolchain/bin/llvm-ar.exe',
                'resourceCompiler': '{kit}/toolchain/bin/llvm-windres.exe',
                'sourceGroups': [{'id': 'overlay', 'root': '{generated}/ovl', 'pattern': '*.cpp'}],
                'compileOptions': [], 'linkOptions': [],
            }
            (kit / 'compile-plan.json').write_text(json.dumps(plan), encoding='utf-8')
            calls = []

            def fake_run(command, env=None, stdout=None, stderr=None):
                calls.append(list(command))
                if '-x' in command and 'c++-header' in command:
                    Path(command[command.index('-o') + 1]).write_bytes(b'pch')
                    return subprocess.CompletedProcess(command, 0)
                stdout.write(b'unit0.cpp:1:1: error: unknown type name\n')
                return subprocess.CompletedProcess(command, 1)

            with patch.object(compile_game, 'run', side_effect=fake_run):
                with self.assertRaisesRegex(RuntimeError, 'unknown type name'):
                    compile_game.compile_plan(kit, gen, work, out, jobs=2)
            compile_cmds = [c for c in calls if '-c' in c]
            self.assertEqual(len(compile_cmds), 1)


if __name__ == '__main__':
    unittest.main()
