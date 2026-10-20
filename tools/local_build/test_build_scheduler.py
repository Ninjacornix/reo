import hashlib
import json
from pathlib import Path
import tempfile
import threading
import time
import unittest
from unittest.mock import patch

from build_scheduler import GIB, header_fingerprint, scheduled_results, unit_estimates


class SchedulingTests(unittest.TestCase):
    def test_high_memory_machine_can_use_more_than_eight_workers(self):
        items = [{'id': str(i)} for i in range(12)]
        estimates = {item['id']: (1, GIB) for item in items}
        barrier = threading.Barrier(12, timeout=5)
        def action(item):
            barrier.wait()
            return item['id']
        with patch('build_scheduler.os.cpu_count', return_value=24):
            result = {item['id']: future.result() for item, future in
                      scheduled_results(items, action, 12, estimates, memory=lambda: 32 * GIB)}
        self.assertEqual(result, {item['id']: item['id'] for item in items})

    def test_parallel_fingerprint_preserves_legacy_value_and_detects_edits(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            for name in ['one.hpp', 'two.h', 'sub/three.inc', 'unused.cpp']:
                path = root / name
                path.parent.mkdir(exist_ok=True)
                path.write_text(name)
            digest = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
            old = hashlib.sha256()
            for path in sorted(root.rglob('*')):
                if path.is_file() and path.suffix in {'.h', '.hpp', '.inc', '.inl'}:
                    old.update(str(path.relative_to(root)).encode())
                    old.update(bytes.fromhex(digest(path)))
            self.assertEqual(header_fingerprint((root,), digest, 4), old.hexdigest())
            (root / 'two.h').write_text('changed')
            self.assertNotEqual(header_fingerprint((root,), digest, 4), old.hexdigest())

    def test_expensive_work_starts_first_and_large_units_are_reserved(self):
        items = [{'id': name} for name in ['small1', 'small2', 'large']]
        estimates = {'small1': (1, 2 * GIB), 'small2': (1, 2 * GIB), 'large': (100, 4 * GIB)}
        lock = threading.Lock()
        active = peak = 0
        starts = []
        def action(item):
            nonlocal active, peak
            with lock:
                active += 1
                peak = max(peak, active)
                starts.append(item['id'])
            time.sleep(0.01)
            with lock:
                active -= 1
            return item['id']
        with patch('build_scheduler.os.cpu_count', return_value=16):
            result = {item['id']: future.result() for item, future in
                      scheduled_results(items, action, 8, estimates, memory=lambda: 6 * GIB)}
        self.assertEqual(starts[0], 'large')
        self.assertLessEqual(peak, 2)
        self.assertEqual(result, {item['id']: item['id'] for item in items})
        self.assertEqual([item['id'] for item in items], ['small1', 'small2', 'large'])

    def test_failures_remain_visible_and_single_large_job_can_progress(self):
        items = [{'id': 'one'}]
        def fail(item):
            raise RuntimeError('compiler refused')
        for item, future in scheduled_results(items, fail, 8, {'one': (1, 4 * GIB)}, memory=lambda: 2 * GIB):
            with self.assertRaisesRegex(RuntimeError, 'compiler refused'):
                future.result()

    def test_cost_history_is_advisory_and_malformed_values_are_ignored(self):
        with tempfile.TemporaryDirectory() as folder:
            source = Path(folder) / 'sub_guest.cpp'
            source.write_bytes(bytes(800000))
            receipt = Path(folder) / 'receipt.json'
            receipt.write_text(json.dumps({'compileSeconds': 17.5}))
            cost, memory = unit_estimates({'id': 'guest'}, [source], receipt)
            self.assertEqual((cost, memory), (17.5, 4 * GIB))
            receipt.write_text(json.dumps({'compileSeconds': -10}))
            self.assertEqual(unit_estimates({'id': 'guest'}, [source], receipt)[0], 16)
            receipt.write_text('[]')
            self.assertEqual(unit_estimates({'id': 'guest'}, [source], receipt)[0], 16)


if __name__ == '__main__':
    unittest.main()
