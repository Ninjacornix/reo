"""Derive independent offline dispatch/gating metadata from owned o2."""
import hashlib,json,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
def main():
    raw=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes()
    assert hashlib.sha256(raw).hexdigest()=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    ordinary=struct.unpack_from('<432I',raw,0x717830-0x570000)
    offline=[struct.unpack_from('<I4B',raw,0x73cbe0-0x570000+8*i) for i in range(432)]
    assert sum(a[0]!=b for a,b in zip(offline,ordinary))==41
    path=ROOT/'game/native/gameplay_scenario/offline_bindings.inc'
    lines=['// Pinned owned offline table0x73CBE0: handler identity plus bytes4/5/6.',
        'struct OfflineBinding {bool noop,same_handler,relation_one,restricted,relation_two;};',
        'inline constexpr std::array<OfflineBinding,432> offline_bindings{{']
    for i,row in enumerate(offline):
        values=[row[0] in (0x68cd80,0x694e90),row[0]==ordinary[i],bool(row[1]),bool(row[2]),bool(row[3])]
        lines.append('    {'+','.join('true' if v else 'false' for v in values)+'},')
    lines.append('}};')
    with path.open('x',encoding='utf8',newline='\n') as f:f.write('\n'.join(lines)+'\n')
    print(json.dumps(dict(ordinary_slots=432,offline_slots=432,different_bindings=41,offline_distinct_targets=len({r[0] for r in offline}),combined_targets=len(set(ordinary)|{r[0] for r in offline}),sha256=hashlib.sha256(path.read_bytes()).hexdigest())))
if __name__=='__main__':main()
