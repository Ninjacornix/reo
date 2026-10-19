import json
import unittest

from compile_game import portable_flags, response_text


class PortableFlagTests(unittest.TestCase):
    def test_preserves_defines_paths_and_precision(self):
        self.assertEqual(portable_flags(["/DNAME=1", "/IC:/path with spaces", "/fp:precise"]),
                         ["-DNAME=1", "-IC:/path with spaces", "-fno-fast-math", "-ffp-contract=off"])

    def test_unrecognized_flags_fail_instead_of_disappearing(self):
        with self.assertRaises(ValueError):
            portable_flags(["/unrecognized"])

    def test_windows_paths_are_not_gnu_response_escapes(self):
        paths = [r"C:\Users\Example\one.obj", r"C:\space in path\two.obj"]
        encoded = response_text(paths, True)
        self.assertEqual([json.loads(line) for line in encoded.splitlines()],
                         [p.replace("\\", "/") for p in paths])


if __name__ == "__main__":
    unittest.main()
