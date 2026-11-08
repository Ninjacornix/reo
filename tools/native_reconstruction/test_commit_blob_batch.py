"""Immutable candidate header reads: real Git objects and malformed framing."""
import hashlib
from pathlib import Path
import subprocess
import tempfile
import unittest
from unittest.mock import patch
import prepare_native_candidate as candidate


def identity(data):
    return hashlib.sha1(b'blob ' + str(len(data)).encode('ascii') + b'\0' + data).hexdigest()


def frame(data):
    oid = identity(data)
    return oid, oid.encode('ascii') + b' blob ' + str(len(data)).encode('ascii') + b'\n' + data + b'\n'


class BatchFrames(unittest.TestCase):
    def test_binary_empty_and_newline_payloads(self):
        values = (b'', b'abc\0\n\xff', b'no final newline')
        records = [frame(value) for value in values]
        self.assertEqual(candidate.decode_blob_batch([oid for oid, _ in records], b''.join(body for _, body in records)),
                         {identity(value): value for value in values})

    def test_wrong_identity_and_type(self):
        oid, body = frame(b'data')
        for changed in (body.replace(oid.encode(), b'0' * 40), body.replace(b' blob ', b' tree ')):
            with self.subTest(changed=changed), self.assertRaisesRegex(ValueError, 'identity/type'):
                candidate.decode_blob_batch([oid], changed)

    def test_missing_and_invalid_lengths(self):
        oid, body = frame(b'data')
        for changed in (b'', body.split(b'\n')[0], body.replace(b' blob 4', b' blob -4')):
            with self.subTest(changed=changed), self.assertRaises(ValueError):
                candidate.decode_blob_batch([oid], changed)

    def test_truncation_and_trailing_data(self):
        oid, body = frame(b'data')
        for changed in (body[:-1], body[:-2], body + b'extra'):
            with self.subTest(changed=changed), self.assertRaises(ValueError):
                candidate.decode_blob_batch([oid], changed)

    def test_content_must_match_actual_git_blob_id(self):
        oid, body = frame(b'data')
        with self.assertRaisesRegex(ValueError, 'content'):
            candidate.decode_blob_batch([oid], body.replace(b'\ndata\n', b'\ndate\n'))

    def test_failed_batch_cannot_partially_publish_cache(self):
        obj = candidate.Commit.__new__(candidate.Commit)
        obj.root = Path.cwd(); obj.entries = {'one.h': identity(b'one'), 'two.h': identity(b'two')}; obj.cache = {}
        with patch.object(candidate.subprocess, 'check_output', return_value=frame(b'one')[1] + frame(b'bad')[1]):
            with self.assertRaises(ValueError):
                obj.preload(obj.entries)
        self.assertEqual(obj.cache, {})

    def test_unknown_path_refuses_without_git_process(self):
        obj = candidate.Commit.__new__(candidate.Commit)
        obj.root = Path.cwd(); obj.entries = {}; obj.cache = {}
        with patch.object(candidate.subprocess, 'check_output') as git:
            with self.assertRaisesRegex(ValueError, 'absent'):
                obj.preload(['untracked.h'])
        git.assert_not_called()

    def test_real_git_pins_commit_and_deduplicates_equal_blobs(self):
        owned = (candidate.ROOT / 'build-native-sjuni').resolve()
        with tempfile.TemporaryDirectory(prefix='blob-batch-test-', dir=owned) as temporary:
            root = Path(temporary).resolve()
            self.assertTrue(root.is_relative_to(owned))
            def git(*args):
                return subprocess.check_output(['git', '-C', str(root), *args], stderr=subprocess.STDOUT)
            git('init', '-q'); git('config', 'user.name', 'Local test'); git('config', 'user.email', 'test@invalid')
            git('config', 'core.autocrlf', 'false')
            for name in ('one.h', 'duplicate.hpp', 'unicode \u010d.h'):
                (root / name).write_bytes(b'header\0\nraw bytes\xff')
            (root / 'body.cpp').write_bytes(b'committed body\n')
            git('add', '.'); git('commit', '-qm', 'Fixture')
            revision = git('rev-parse', 'HEAD').decode().strip()
            (root / 'one.h').write_bytes(b'dirty replacement')
            (root / 'untracked.h').write_bytes(b'untracked')
            commit = candidate.Commit(root, revision)
            real = candidate.subprocess.check_output
            with patch.object(candidate.subprocess, 'check_output', wraps=real) as calls:
                commit.preload(['one.h', 'duplicate.hpp', 'unicode \u010d.h'])
                self.assertEqual(calls.call_count, 1)
                self.assertEqual(calls.call_args.kwargs['input'].count(b'\n'), 1)
                commit.preload(['one.h'])
                self.assertEqual(calls.call_count, 1)
            self.assertEqual(commit.read('one.h'), b'header\0\nraw bytes\xff')
            self.assertEqual(commit.read('unicode \u010d.h'), commit.read('one.h'))
            self.assertEqual(commit.read('body.cpp'), b'committed body\n')
            with self.assertRaises(ValueError):
                commit.read('untracked.h')


if __name__ == '__main__':
    unittest.main()
