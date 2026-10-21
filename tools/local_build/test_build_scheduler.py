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
            # Replaced generation output kept for diagnostics is not an include input.
            (root / 'recomp' / 'config.interrupted0').mkdir(parents=True)
            (root / 'recomp' / 'config.interrupted0' / 'old.h').write_text('stale')
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
        # Free memory falls as admitted compilers use their reservations.
        used = {'value': 0}
        def memory():
            return 6 * GIB - used['value']
        def tracked(item):
            with lock:
                used['value'] += estimates[item['id']][1]
            try:
                return action(item)
            finally:
                with lock:
                    used['value'] -= estimates[item['id']][1]
        with patch('build_scheduler.os.cpu_count', return_value=16):
            result = {item['id']: future.result() for item, future in
                      scheduled_results(items, tracked, 8, estimates, memory=memory)}
        self.assertEqual(starts[0], 'large')
        self.assertLessEqual(peak, 2)
        self.assertEqual(result, {item['id']: item['id'] for item in items})
        self.assertEqual([item['id'] for item in items], ['small1', 'small2', 'large'])

    def test_capacity_rises_when_more_memory_becomes_free(self):
        items = [{'id': str(i)} for i in range(6)]
        estimates = {item['id']: (1, GIB) for item in items}
        free = {'value': 3 * GIB}  # room for two at the start
        lock = threading.Lock()
        active = peak = 0
        release = threading.Event()
        def action(item):
            nonlocal active, peak
            with lock:
                active += 1
                peak = max(peak, active)
            release.wait(timeout=5)
            with lock:
                active -= 1
            return item['id']
        def memory():
            return free['value']
        def later():
            time.sleep(0.2)
            free['value'] = 12 * GIB  # another program closed
            time.sleep(0.3)
            release.set()
        threading.Thread(target=later).start()
        with patch('build_scheduler.os.cpu_count', return_value=16),                 patch('build_scheduler.POLL_SECONDS', 0.05):
            done = [item['id'] for item, future in scheduled_results(items, action, 8, estimates, memory=memory)
                    if future.result()]
        self.assertEqual(sorted(done), sorted(item['id'] for item in items))
        self.assertGreater(peak, 2)

    def test_running_compilers_keep_their_reservation(self):
        # Free memory does not drop while compilers start up: their reservations, not the
        # measurement, limit how many run at once.
        items = [{'id': str(i)} for i in range(8)]
        estimates = {item['id']: (1, GIB // 2) for item in items}
        lock = threading.Lock()
        active = peak = 0
        def action(item):
            nonlocal active, peak
            with lock:
                active += 1
                peak = max(peak, active)
            time.sleep(0.3)
            with lock:
                active -= 1
            return item['id']
        with patch('build_scheduler.os.cpu_count', return_value=16):
            done = [future.result() for _, future in
                    scheduled_results(items, action, 8, estimates, memory=lambda: 5 * GIB // 2)]
        self.assertEqual(len(done), 8)
        self.assertLessEqual(peak, 2)

    def test_slow_medium_sources_reserve_more(self):
        with tempfile.TemporaryDirectory() as folder:
            medium = Path(folder) / 'sub_medium.cpp'
            medium.write_bytes(bytes(300000))
            small = Path(folder) / 'sub_small.cpp'
            small.write_bytes(bytes(100000))
            registry = Path(folder) / 'register_functions.cpp'
            registry.write_bytes(bytes(400000))
            receipt = Path(folder) / 'none.json'
            self.assertEqual(unit_estimates({'id': 'm'}, [medium], receipt)[1], 3 * GIB // 2)
            self.assertEqual(unit_estimates({'id': 's'}, [small, registry], receipt)[1], GIB // 2)

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
