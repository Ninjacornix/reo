# Rewrite the old overlay codegen's FPU type-puns (*(uint32_t*)&ctx->f[N], *(int32_t*)&ctx->f[N])
# into the memcpy forms the current generator emits for main-ELF code (see
# recomp/config/output/*: mtc1/mfc1/cvt.s.w/cvt.w.s). Same bytes, same semantics; the
# source instrumenter can wrap ctx->f[N] in the memcpy form, but not under unary '&'.
#   python tools/overlay_fpu_pun_fix.py [--check]
import re, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1] / 'recomp/config/output_overlay'
F = r'ctx->f\[(\d+)\]'
RULES = [
    # mtc1: *(uint32_t*)&ctx->f[N] = E;
    (re.compile(r'^(\s*)\*\(uint32_t\*\)&' + F + r' = (.+);$'),
     lambda m: f'{m[1]}{{ uint32_t bits = {m[3]}; std::memcpy(&ctx->f[{m[2]}], &bits, sizeof(bits)); }}'),
    # cvt.w.s: *(int32_t*)&ctx->f[N] = E;
    (re.compile(r'^(\s*)\*\(int32_t\*\)&' + F + r' = (.+);$'),
     lambda m: f'{m[1]}{{ int32_t tmp = {m[3]}; std::memcpy(&ctx->f[{m[2]}], &tmp, sizeof(tmp)); }}'),
    # cvt.s.w: ctx->f[D] = FPU_CVT_S_W(*(int32_t*)&ctx->f[S]);
    (re.compile(r'^(\s*)' + F + r' = FPU_CVT_S_W\(\*\(int32_t\*\)&' + F + r'\);$'),
     lambda m: f'{m[1]}{{ int32_t tmp; std::memcpy(&tmp, &ctx->f[{m[3]}], sizeof(tmp)); ctx->f[{m[2]}] = FPU_CVT_S_W(tmp); }}'),
    # mfc1: SET_GPR_U32(ctx, R, *(uint32_t*)&ctx->f[N]);
    (re.compile(r'^(\s*)SET_GPR_U32\(ctx, (\d+), \*\(uint32_t\*\)&' + F + r'\);$'),
     lambda m: f'{m[1]}{{ uint32_t bits; std::memcpy(&bits, &ctx->f[{m[3]}], sizeof(bits)); SET_GPR_U32(ctx, {m[2]}, bits); }}'),
]
PUN = re.compile(r'\*\((?:u?int32_t)\*\)&ctx->f\[')
PIN = re.compile(r'//\s*0x[0-9a-fA-F]+:\s*0x[0-9a-fA-F]+')

check = '--check' in sys.argv
total = 0; files = 0
for path in sorted(ROOT.glob('*.cpp')):
    text = path.read_text(encoding='utf-8')
    if not PUN.search(text):
        continue
    lines = text.split('\n'); n = 0
    for i, line in enumerate(lines):
        if not PUN.search(line):
            continue
        for rx, fn in RULES:
            m = rx.match(line)
            if m:
                lines[i] = fn(m); n += 1; break
        else:
            sys.exit(f'unhandled pun form in {path.name}:{i + 1}: {line.strip()}')
    out = '\n'.join(lines)
    assert not PUN.search(out), path.name
    assert PIN.findall(out) == PIN.findall(text), ('instruction pins changed', path.name)
    if 'std::memcpy' in out and '<cstring>' not in out and '#include "ps2_runtime.h"' not in out:
        sys.exit(f'{path.name}: no header providing std::memcpy')
    total += n; files += 1
    if not check:
        path.write_text(out, encoding='utf-8', newline='')
print(f'{"would rewrite" if check else "rewrote"} {total} sites in {files} files')
