from pathlib import Path
import tempfile
import unittest

from compile_game import compiler_failure


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


if __name__ == '__main__':
    unittest.main()
