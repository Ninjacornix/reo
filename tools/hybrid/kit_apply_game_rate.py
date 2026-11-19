"""Copy the REO_GAME_RATE=60 hook from this repository's recomp/reo_bootstrap.cpp into a kit's
bootstrap (kits built from develop carry a different bootstrap file).

usage: kit_apply_game_rate.py KIT_BOOTSTRAP
Inserts the reo_game_rate namespace after `#include "ps2_runtime.h"` and the install block
before the Windows timer-resolution scope. Idempotent: a bootstrap that already has the hook
is left unchanged.
"""
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
source = (ROOT / 'recomp/reo_bootstrap.cpp').read_text(encoding='utf-8').replace('\r\n', '\n')
target_path = Path(sys.argv[1])
raw = target_path.read_text(encoding='utf-8')
nl = '\r\n' if '\r\n' in raw else '\n'
target = raw.replace('\r\n', '\n')
if 'namespace reo_game_rate {' in target:
    print('already applied')
    sys.exit(0)

start = source.index('#include <chrono>\n#include <cstdio>\n#include <cstring>\nnamespace reo_game_rate {')
end = source.index('\n}\n}\n', start) + len('\n}\n}\n')
namespace = source[start:end]
install_start = source.index('    // REO_GAME_RATE=60: the engine\'s own frame step')
install_end = source.index('#ifdef _WIN32\n    reo::ScopedTimerResolution timerPrecision;', install_start)
install = source[install_start:install_end]

include = '#include "ps2_runtime.h"\n'
timer = '#ifdef _WIN32\n    reo::ScopedTimerResolution timerPrecision;'
for anchor in (include, timer):
    if target.count(anchor) != 1:
        raise SystemExit(f'anchor found {target.count(anchor)} times: {anchor!r}')
target = target.replace(include, include + namespace)
target = target.replace(timer, install + timer)
target_path.write_text(target.replace('\n', nl), encoding='utf-8', newline='')
print('applied', len(namespace), 'namespace bytes,', len(install), 'install bytes')
