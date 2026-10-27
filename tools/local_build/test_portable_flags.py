import json
import shlex
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

    def test_non_ascii_paths_reach_tools_as_literal_utf8(self):
        paths = ["C:/Users/Jos\u00e9/game files/main.obj", "D:/\u0418\u0433\u0440\u044b/runtime.lib"]
        self.assertEqual(shlex.split(response_text(paths, True)), paths)


if __name__ == "__main__":
    unittest.main()
