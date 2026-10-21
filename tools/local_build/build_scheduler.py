"""Compilation scheduling and fingerprints; no generated code or compiler flag changes."""
from concurrent.futures import FIRST_COMPLETED, ThreadPoolExecutor, wait
import ctypes
import hashlib
import json
import math
import os
from pathlib import Path

GIB = 1024 ** 3
# Reservations per compiler: ordinary units peaked at 60-150 MB, single sources over 250 KB
# can compile for minutes and keep growing, and the largest guest functions reached 3.4 GiB.
DEFAULT_BUDGET = GIB // 2
MEDIUM_BUDGET = 3 * GIB // 2
LARGE_BUDGET = 4 * GIB
RESERVE = 3 * GIB // 2
MAX_WORKERS = 32
POLL_SECONDS = 2


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


def header_fingerprint(roots, digest, jobs=1, label=None):
    result = hashlib.sha256()
    with ThreadPoolExecutor(max_workers=max(1, min(jobs, 4))) as pool:
        for root in roots:
            if label is not None:
                result.update(label(str(root)).encode() + b"\0")
            # Filter suffixes before stat: generated trees contain thousands of C++ files.
            # build_game.py keeps replaced generation output as config.interruptedN for
            # diagnostics; no include path reaches it, so it must not change the fingerprint.
            headers = sorted(p for p in root.rglob('*')
                             if p.suffix in {'.h', '.hpp', '.inl', '.inc'} and p.is_file() and
                             not any(part.startswith('config.interrupted')
                                     for part in p.relative_to(root).parts))
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
    largest = max((size for source, size in zip(sources, sizes)
                   if not source.name.startswith('register')), default=0)
    return cost_estimate(sum(sizes), large_guest, receipt, largest)


def cost_estimate(source_bytes, large_guest, receipt, largest=0):
    budget = (LARGE_BUDGET if large_guest else MEDIUM_BUDGET if largest > 250000
              else DEFAULT_BUDGET)
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
    if memory() is None:
        workers = min(workers, 2)
    pending = sorted(enumerate(items), key=lambda pair: (-estimates[pair[1]['id']][0], pair[0]))
    running = {}
    reserved = 0
    capacity = 2 * DEFAULT_BUDGET
    with ThreadPoolExecutor(max_workers=workers) as pool:
        try:
            while pending or running:
                while pending and len(running) < workers:
                    # Running compilers hold their whole reservation until they finish: they grow
                    # gradually, so free memory alone overstates what is left. Capacity is measured
                    # whenever nothing runs and shrinks when other programs take memory meanwhile.
                    available = memory()
                    if available is not None:
                        capacity = (available - RESERVE if not running else
                                    min(capacity, available - RESERVE + reserved))
                    chosen = None
                    for index, (_, item) in enumerate(pending):
                        budget = estimates[item['id']][1]
                        # Either the reservations fit the measured capacity, or memory freed since
                        # then covers every running reservation again plus this one.
                        fits = (reserved + budget <= capacity if available is None else
                                available >= RESERVE + budget and
                                (reserved + budget <= capacity or
                                 available >= RESERVE + reserved + budget))
                        if not running or fits:
                            chosen = index
                            break
                    if chosen is None:
                        break
                    _, item = pending.pop(chosen)
                    budget = estimates[item['id']][1]
                    future = pool.submit(action, item)
                    running[future] = (item, budget)
                    reserved += budget
                # Wake periodically too, so freed memory and finished work admit more compilers.
                done, _ = wait(running, timeout=POLL_SECONDS, return_when=FIRST_COMPLETED)
                for future in done:
                    item, budget = running.pop(future)
                    reserved -= budget
                    yield item, future
        finally:
            for future in running:
                future.cancel()
