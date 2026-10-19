"""Compare final VIF registers, VU memories, and ordered packet/callback bytes."""
import json
from pathlib import Path
import statistics
import struct
import sys

if sys.argv[1] == '--check-input':
    directory = Path(sys.argv[2])
    rows = [json.loads(s) for s in (directory/'vif1_buffers.jsonl').read_text().splitlines()]
    if len(rows) != 4 or [r['index'] for r in rows] != list(range(4)):
        raise SystemExit('Expected four complete original metadata records')
    for r in rows:
        path = directory/f'vif1_{r["index"]:04d}.bin'
        if not r['complete_file'] or len(path.read_bytes()) != r['bytes']:
            raise SystemExit(f'Incomplete original buffer {r["index"]}')
    print('PASS four metadata-complete original buffers; unverified vif1_0004.bin is excluded')
    raise SystemExit(0)

left, right = map(Path, sys.argv[1:3])
names = {p.name for p in left.glob('*.bin')}
if names != {p.name for p in right.glob('*.bin')} or len(names) != 44:
    raise SystemExit(f'Expected 39 synthetic + 4 complete original + 1 benchmark artifacts, got {len(names)}')
for name in sorted(names):
    a, b = (p/name for p in (left, right))
    x, y = a.read_bytes(), b.read_bytes()
    if x != y:
        at = next((i for i, (u, v) in enumerate(zip(x, y)) if u != v), min(len(x), len(y)))
        raise SystemExit(f'MISMATCH {name}: byte {at}, sizes {len(x)} / {len(y)}')
    magic, version, regs, code, data, events = struct.unpack_from('<6I', x)
    if magic != 0x46505556 or version != 1 or code != 16384 or data != 16384:
        raise SystemExit(f'Invalid output header {name}')
    pos = 24+regs+code+data
    if pos+events != len(x):
        raise SystemExit(f'Invalid event span {name}')
    while pos < len(x):
        kind, = struct.unpack_from('<I', x, pos)
        if kind in (1, 2):
            pos += 12+regs+code+data
        elif kind == 3:
            size, = struct.unpack_from('<I', x, pos+4)
            pos += 8+size
        else:
            raise SystemExit(f'Unknown event kind {kind}: {name}')
        if pos > len(x):
            raise SystemExit(f'Truncated event {name}')
a, b = (json.loads((p/'benchmark.json').read_text()) for p in (left, right))
for key in ('input_bytes', 'vectors', 'rounds'):
    if a[key] != b[key]:
        raise SystemExit(f'Workload differs: {key}')
baseline, candidate = (statistics.median(j['wall_ms']) for j in (a, b))
print('PASS 44 complete final VIF-register/VU-code/VU-data/ordered-packet/callback artifact pairs match byte-for-byte')
print(f'Representative-format in-memory workload {a["vectors"]} vectors/{a["input_bytes"]} input bytes: '
      f'baseline median {baseline:.3f} ms, candidate {candidate:.3f} ms, ratio {baseline/candidate:.3f}')
print('Callbacks are recorded, without executing original VU programs. This does not measure native FPS or full original DMA CPU cost.')
