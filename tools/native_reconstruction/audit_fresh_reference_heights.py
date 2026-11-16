"""Verify the exact fresh-process producer and66AC50 consumer of747400."""
import argparse,hashlib,json,re,struct
from pathlib import Path
from audit_retail_effect_descriptors import compare_source
ROOT=Path(__file__).resolve().parents[2]
def sha(data):return hashlib.sha256(data).hexdigest()
def main():
    parser=argparse.ArgumentParser();parser.add_argument('--output',type=Path,required=True);args=parser.parse_args()
    assert not args.output.exists()
    elf=(ROOT/'game_data/SLUS_207.65').read_bytes();overlay=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes()
    assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    phoff=struct.unpack_from('<I',elf,28)[0];stride,count=struct.unpack_from('<HH',elf,42)
    segments=[struct.unpack_from('<8I',elf,phoff+i*stride) for i in range(count)]
    bss=[row for row in segments if row[0]==1 and row[2]+row[4]<=0x747400 and 0x747420<=row[2]+row[5]]
    assert bss and all(row[4]==0 for row in bss)
    assert any(row[2]==0x570000 and row[5]==0x1ea580 for row in bss)
    assert 0x570000+len(overlay)==0x743100 and 0x570000+len(overlay)<=0x747400
    source='recomp/config/output_ovl/o2/o2_0066AC50_0x66ac50.cpp'
    end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',(ROOT/source).read_text())[1],16)
    proof=compare_source('66AC50 reads runtime reference height by character',source,0x66ac50,end,
        lambda address,size:overlay[address-0x570000:address-0x570000+size])
    receipt=dict(status='passed',elf_sha256=sha(elf),overlay_sha256=sha(overlay),zero_fill_segments=bss,
        address=0x747400,bytes=32,initial_bits=[0]*8,consumer=proof,script_sha256=sha(Path(__file__).read_bytes()),
        scope='Only explicit fresh-process ELF zero-fill authority. Does not establish absence of indirect/warm writers, or authorize clearing on retries.',game_run=False)
    args.output.parent.mkdir(parents=True,exist_ok=True);args.output.write_text(json.dumps(receipt,indent=2)+'\n')
    print(json.dumps(dict(status='passed',values=8)))
if __name__=='__main__':main()
