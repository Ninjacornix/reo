"""Ordered host-registration chunking, including a real compiled fake-runtime check."""
import os
from pathlib import Path
import re
import subprocess
import tempfile
import unittest

from registration_chunks import chunk_registrations


class RegistrationTests(unittest.TestCase):
    def source(self, count):
        return ('void install(PS2Runtime& runtime) {\n// registration list\n' +
                ''.join(f'    runtime.registerFunction({i}, {i + 1});\n' for i in range(count)) + '}\n')

    def test_small_list_is_unchanged(self):
        original = self.source(256)
        self.assertEqual(chunk_registrations(original), original)

    def test_calls_and_helper_invocation_order_are_preserved(self):
        original = self.source(1025)
        actual = chunk_registrations(original)
        calls = lambda s: re.findall(r'runtime\.registerFunction\([^;]+\);', s)
        self.assertEqual(calls(actual), calls(original))
        self.assertEqual(re.findall(r'^    install_part_(\d+)\(runtime\);', actual, re.M),
                         ['0', '1', '2', '3', '4'])

    def test_unknown_operations_fail_closed(self):
        with self.assertRaisesRegex(ValueError, 'unreviewed'):
            chunk_registrations(self.source(300).replace('runtime.registerFunction(0, 1);', 'mutate();'))
        with self.assertRaisesRegex(ValueError, 'layout'):
            chunk_registrations('void other() {}')
        with self.assertRaises(ValueError):
            chunk_registrations(self.source(1), 0)

    @unittest.skipUnless(os.environ.get('REO_TEST_CXX'), 'Set REO_TEST_CXX for native equivalence check')
    def test_compiled_registration_results_match(self):
        original = self.source(2049)
        program = ('#include <vector>\nstruct PS2Runtime {\n'
                   'std::vector<int> values;\nvoid registerFunction(int a,int b){values.push_back(a);values.push_back(b);}\n};\n'
                   'namespace baseline {\n' + original + '}\nnamespace optimized {\n' +
                   chunk_registrations(original) + '}\n'
                   'int main(){PS2Runtime a,b;baseline::install(a);optimized::install(b);return a.values==b.values?0:1;}\n')
        with tempfile.TemporaryDirectory(prefix='reo-register-order-') as folder:
            source = Path(folder) / 'check.cpp'
            source.write_text(program)
            executable = Path(folder) / ('check.exe' if os.name == 'nt' else 'check')
            subprocess.run([os.environ['REO_TEST_CXX'], '-std=c++20', '-O2', str(source), '-o', str(executable)], check=True)
            subprocess.run([str(executable)], check=True)


if __name__ == '__main__':
    unittest.main()
