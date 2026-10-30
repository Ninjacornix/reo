"""Compare original unlock instructions with a private dump from file2_unlock_tests.

Usage: verify_file2_unlock_elf.py SLUS_209.84 after.bin oracle.json
No game instructions or memory-card data are bundled with this verifier.
"""
import hashlib, json, struct, sys
from pathlib import Path

if len(sys.argv) != 4:
    raise SystemExit(__doc__)
image = Path(sys.argv[1]).read_bytes()
if hashlib.sha256(image).hexdigest() != '5c0411a26247ef9974cd94b844ac5aecbcbf4705db543f51814aeed89da0fd8d':
    raise ValueError('Unsupported File #2 ELF revision')
ram = bytearray(0x2000000)
for i in range(struct.unpack_from('<H', image, 44)[0]):
    typ, off, addr, _, size, *_ = struct.unpack_from('<8I', image, struct.unpack_from('<I', image, 28)[0] + i*32)
    if typ == 1: ram[addr:addr+size] = image[off:off+size]
reg = [0] * 32
reg[29] = 0x1f00000
reg[31] = 0xdeadbeef
pc, pending, steps = 0x13c190, None, 0
def signed(n, bits):
    n &= (1 << bits)-1
    return n - (1 << bits) if n >> (bits-1) else n
while pc != 0xdeadbeef:
    if steps >= 100000 or not (0x13c110 <= pc < 0x13c2ac or 0x13bd50 <= pc < 0x13bd78):
        raise ValueError('Original unlock execution left its bound: ' + hex(pc))
    word = struct.unpack_from('<I', ram, pc)[0]
    op, rs, rt, rd, shift, fn = word>>26, word>>21&31, word>>16&31, word>>11&31, word>>6&31, word&63
    imm = signed(word, 16)
    target, old_pending = None, pending
    if op == 0:
        a, b = reg[rs], reg[rt]
        if fn == 0: reg[rd] = signed(b << shift, 32)
        elif fn == 3: reg[rd] = signed(b, 32) >> shift
        elif fn == 4: reg[rd] = signed(b << (a & 31), 32)
        elif fn == 8: target = a & 0xffffffff
        elif fn in (0x21, 0x2d): reg[rd] = signed(a+b, 32 if fn == 0x21 else 64)
        elif fn == 0x25: reg[rd] = a | b
        elif fn == 0x2a: reg[rd] = int(signed(a,64) < signed(b,64))
        else: raise ValueError((hex(pc), hex(word)))
    elif op == 3: reg[31], target = pc+8, (word & 0x3ffffff)<<2
    elif op in (4,5):
        if (reg[rs] == reg[rt]) == (op == 4): target = pc+4+imm*4
    elif op == 9: reg[rt] = signed(reg[rs]+imm, 32)
    elif op == 10: reg[rt] = int(signed(reg[rs],64) < imm)
    elif op == 11: reg[rt] = int(reg[rs] & 0xffffffffffffffff < imm & 0xffffffffffffffff)
    elif op == 12: reg[rt] = reg[rs] & (word & 0xffff)
    elif op == 13: reg[rt] = reg[rs] | (word & 0xffff)
    elif op == 15: reg[rt] = signed((word & 0xffff)<<16,32)
    elif op in (0x23,0x24,0x37,0x1e):
        addr, size = (reg[rs]+imm)&0xffffffff, {0x23:4,0x24:1,0x37:8,0x1e:16}[op]
        reg[rt] = int.from_bytes(ram[addr:addr+size],'little',signed=op in (0x23,0x37))
    elif op in (0x28,0x2b,0x3f,0x1f):
        addr, size = (reg[rs]+imm)&0xffffffff, {0x28:1,0x2b:4,0x3f:8,0x1f:16}[op]
        ram[addr:addr+size] = (reg[rt]&((1<<(size*8))-1)).to_bytes(size,'little')
    else: raise ValueError((hex(pc),hex(word)))
    reg[0] = 0
    pc, pending = (old_pending if old_pending is not None else pc+4), target
    steps += 1
result = Path(sys.argv[2]).read_bytes()
if len(result) != len(ram):
    raise ValueError('Expected a complete 32 MiB native test dump')
# The native original also enables a secondary scenario-availability bank. Our
# feature leaves it to the original game. All other progression bytes must match.
if int.from_bytes(ram[0x2ff8c8:0x2ff8cc],'little') != 0xffe:
    raise ValueError('Original secondary availability bank was unexpected')
ram[0x2ff8c8:0x2ff8cc] = bytes(4)
diff = [hex(a) for a in range(0x2feea0,0x300314) if ram[a] != result[a]]
if diff:
    raise ValueError('Native/original progression mismatch at ' + ', '.join(diff[:20]))
report = {'passed':True, 'elfSha256':hashlib.sha256(image).hexdigest(),
          'routine':'0x13c190', 'executedInstructions':steps,
          'progressionBytesCompared':0x300314-0x2feea0,
          'secondaryAvailabilityBankNotWritten':True,
          'method':'Bounded interpreter executes original ELF instructions and reads its own unlock tables; compares native header result'}
Path(sys.argv[3]).write_text(json.dumps(report,indent=2))
print(json.dumps(report,indent=2))
