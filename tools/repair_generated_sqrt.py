"""Refresh only stale R5900 SQRT.S statements after updating PS2Recomp.

The machine word in each generated comment is authoritative. Use --check to
verify without writing. No shared generated header or other statement changes.
Fresh output from the corrected generator already passes and is left alone.
"""
from pathlib import Path
import argparse
import re
import subprocess

ROOT = Path(__file__).resolve().parents[1]
PATTERN = re.compile(
    r"(?P<head>// 0x[0-9a-fA-F]+: 0x(?P<word>[0-9a-fA-F]+)[^\n]*\n"
    r"[^\n]*ctx->pc[^\n]*\n\s*)"
    r"ctx->f\[(?P<fd>\d+)\] = FPU_SQRT_S\(ctx->f\[(?P<source>\d+)\]\);"
)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--check', action='store_true')
    args = parser.parse_args()
    dirs = [ROOT/'recomp/config'/x for x in
            ['output', 'output_ovl', 'output_extra', 'output_overlay']]
    dirs = [str(x) for x in dirs if x.exists()]
    result = subprocess.run(['rg', '--no-ignore', '-l', 'FPU_SQRT_S', *dirs],
                            capture_output=True, text=True)
    if result.returncode not in (0, 1):
        raise RuntimeError(result.stderr)
    stale = 0
    for name in result.stdout.splitlines():
        path = Path(name)
        source = path.read_text(encoding="utf-8")
        matches = list(PATTERN.finditer(source))
        if len(matches) != source.count('FPU_SQRT_S('):
            raise RuntimeError(f'Unrecognized generated statement in {path}')
        def correct(match):
            nonlocal stale
            word = int(match['word'], 16)
            if word >> 26 != 0x11 or (word >> 21) & 31 != 0x10 or word & 63 != 4:
                raise RuntimeError(f'Not a SQRT.S opcode: {word:08x}')
            fd, ft = (word >> 6) & 31, (word >> 16) & 31
            if int(match['fd']) != fd:
                raise RuntimeError('Destination does not match opcode')
            if int(match['source']) == ft:
                return match[0]
            stale += 1
            return f"{match['head']}ctx->f[{fd}] = FPU_SQRT_S(ctx->f[{ft}]);"
        updated = PATTERN.sub(correct, source)
        if updated != source:
            print(path.relative_to(ROOT))
            if not args.check:
                path.write_text(updated, encoding="utf-8")
    print(f'{stale} stale SQRT.S statements' + (' found' if args.check else ' repaired'))
    return 1 if args.check and stale else 0


if __name__ == '__main__':
    raise SystemExit(main())
