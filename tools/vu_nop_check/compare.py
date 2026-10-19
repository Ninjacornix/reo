"""Compare complete final replay artifacts; hashes are never the parity oracle."""
import json
from pathlib import Path
import statistics
import struct
import sys

left, right = map(Path, sys.argv[1:3])
names_l = {p.name for p in left.glob('*.bin')}
names_r = {p.name for p in right.glob('*.bin')}
if names_l != names_r or len(names_l) != 328:
    raise SystemExit(f'Expected same 320 capture + 8 fixture artifacts: {len(names_l)} / {len(names_r)}')
for name in sorted(names_l):
    a, b = (left/name).read_bytes(), (right/name).read_bytes()
    if a != b:
        offset = next((i for i, (x, y) in enumerate(zip(a, b)) if x != y), min(len(a), len(b)))
        raise SystemExit(f'MISMATCH {name}: offset {offset}, lengths {len(a)} / {len(b)}')
    if len(a) < 24:
        raise SystemExit(f'Short artifact {name}')
    magic, version, state_bytes, data_bytes, memory_packets, gs_packets = struct.unpack_from('<6I', a)
    if magic != 0x504F4E56 or version != 1 or data_bytes != 16384:
        raise SystemExit(f'Bad artifact header {name}')
    pos = 24 + state_bytes + data_bytes
    for _ in range(memory_packets + gs_packets):
        if pos + 4 > len(a):
            raise SystemExit(f'Truncated packet length {name}')
        size, = struct.unpack_from('<I', a, pos)
        pos += 4 + size
        if pos > len(a):
            raise SystemExit(f'Truncated packet bytes {name}')
    if pos != len(a):
        raise SystemExit(f'Trailing unaccounted bytes {name}')
bench_l, bench_r = (json.loads((p/'benchmark.json').read_text()) for p in (left, right))
for key in ('snapshots', 'rounds', 'packets', 'packet_bytes', 'ended', 'checksum'):
    if bench_l[key] != bench_r[key]:
        raise SystemExit(f'Benchmark work mismatch: {key}')
serial = statistics.median(bench_l['wall_ms'])
candidate = statistics.median(bench_r['wall_ms'])
print('PASS 328 complete final-state / VU-memory / ordered-GIF artifact pairs are byte-identical')
print(f'In-memory replay set {bench_l["snapshots"]} inputs, {bench_l["rounds"]} rounds: '
      f'baseline median {serial:.3f} ms, NOP bypass {candidate:.3f} ms, ratio {serial/candidate:.3f}')
print('This measures isolated interpreter plus packet-sink work; it does not measure native game FPS.')
