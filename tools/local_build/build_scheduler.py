"""Compilation scheduling and fingerprints; no generated code or compiler flag changes."""
from concurrent.futures import FIRST_COMPLETED, ThreadPoolExecutor, wait
import ctypes
import hashlib
import json
import math
import os
from pathlib import Path

GIB = 1024 ** 3
DEFAULT_BUDGET = 5 * GIB // 4
MAX_WORKERS = 32


def available_memory():
    if os.name == 'nt':
        class Memory(ctypes.Structure):
            _fields_ = [('length', ctypes.c_ulong), ('load', ctypes.c_ulong)] + [
                (name, ctypes.c_ulonglong) for name in
                ('physical', 'available', 'commit', 'available_commit', 'virtual', 'available_virtual', 'extended')]
        state = Memory()
        state.length = ctypes.sizeof(state)
        if ctypes.windll.kernel32.GlobalMemoryStatusEx(ctypes.byref(state)):
            return min(state.available, state.available_commit)
        return None
    try:
        values = dict(line.split(':', 1) for line in Path('/proc/meminfo').read_text().splitlines())
        available = int(values['MemAvailable'].split()[0]) * 1024
        limit = Path('/sys/fs/cgroup/memory.max')
        if limit.is_file() and (maximum := limit.read_text().strip()) != 'max':
            available = min(available, max(0, int(maximum) - int(limit.with_name('memory.current').read_text())))
        return available
    except (OSError, KeyError, ValueError):
        return None


def header_fingerprint(roots, digest, jobs=1):
    result = hashlib.sha256()
    with ThreadPoolExecutor(max_workers=max(1, min(jobs, 4))) as pool:
        for root in roots:
            # Filter suffixes before stat: generated trees contain thousands of C++ files.
            headers = sorted(p for p in root.rglob('*')
                             if p.suffix in {'.h', '.hpp', '.inl', '.inc'} and p.is_file())
            for path, value in zip(headers, pool.map(digest, headers)):
                result.update(str(path.relative_to(root)).encode())
                result.update(bytes.fromhex(value))
    return result.hexdigest()


def unit_estimates(unit, sources, receipt):
    sizes = [source.stat().st_size for source in sources]
    # A measured >3 GiB guest-function outlier needs a larger reservation than
    # the ordered registration lists, whose large source size is inexpensive.
    large_guest = any(size > 750000 and not source.name.startswith('register')
                      for source, size in zip(sources, sizes))
    return cost_estimate(sum(sizes), large_guest, receipt)


def cost_estimate(source_bytes, large_guest, receipt):
    budget = 4 * GIB if large_guest else DEFAULT_BUDGET
    cost = source_bytes / 50000
    try:
        record = json.loads(receipt.read_text())
        saved = record.get('compileSeconds') if isinstance(record, dict) else None
        if isinstance(saved, (float, int)) and math.isfinite(saved) and 0 < saved < 86400:
            cost = saved
    except (OSError, ValueError, TypeError):
        pass
    return cost, budget


def scheduled_results(items, action, jobs, estimates, memory=available_memory):
    """Yield (item, completed future), submitting only bounded admitted work.

    Estimates affect timing only. The caller must still verify every source,
    object receipt and independent input. Link/archive order stays with the caller.
    """
    processors = os.cpu_count() or 2
    workers = max(1, min(jobs, MAX_WORKERS, max(1, processors - 1)))
    initial = memory()
    if initial is None:
        workers = min(workers, 2)
    capacity = max(0, initial - GIB) if initial is not None else 2 * DEFAULT_BUDGET
    pending = sorted(enumerate(items), key=lambda pair: (-estimates[pair[1]['id']][0], pair[0]))
    running = {}
    reserved = 0
    with ThreadPoolExecutor(max_workers=workers) as pool:
        try:
            while pending or running:
                while pending and len(running) < workers:
                    available = memory()
                    chosen = None
                    for index, (_, item) in enumerate(pending):
                        budget = estimates[item['id']][1]
                        if not running or (reserved + budget <= capacity and
                                           (available is None or available >= GIB + budget)):
                            chosen = index
                            break
                    if chosen is None:
                        break
                    _, item = pending.pop(chosen)
                    budget = estimates[item['id']][1]
                    future = pool.submit(action, item)
                    running[future] = (item, budget)
                    reserved += budget
                done, _ = wait(running, return_when=FIRST_COMPLETED)
                for future in done:
                    item, budget = running.pop(future)
                    reserved -= budget
                    yield item, future
        finally:
            for future in running:
                future.cancel()
