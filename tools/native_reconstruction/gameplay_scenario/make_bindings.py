"""Derive every no-op binding from the pinned owned original opcode table."""
import hashlib,json,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
def main():
    source=ROOT/'build-function-index/owned-overlays/o2.bin';raw=source.read_bytes()
    assert hashlib.sha256(raw).hexdigest()=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    table=struct.unpack_from('<432I',raw,0x717830-0x570000)
    assert table.count(0x68cd80)==220 and len(set(table))==213 and table[0x192]==0x694e90
    values=[target in (0x68cd80,0x694e90) for target in table]
    lines=['// Derived from pinned owned o2 table at0x717830; no guest addresses are used at runtime.',
           'inline constexpr std::array<bool,432> original_noops{']
    for i in range(0,len(values),16):lines.append('    '+','.join('true' if v else 'false' for v in values[i:i+16])+',')
    lines.append('};')
    path=ROOT/'game/native/gameplay_scenario/opcode_bindings.inc'
    with path.open('x',encoding='utf8',newline='\n') as f:f.write('\n'.join(lines)+'\n')
    print(json.dumps(dict(opcodes=len(table),native_noop_bindings=sum(values),sha256=hashlib.sha256(path.read_bytes()).hexdigest())))
if __name__=='__main__':main()
