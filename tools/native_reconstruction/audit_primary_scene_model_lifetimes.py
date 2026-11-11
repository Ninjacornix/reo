"""Static owned-word audit of cinematic roster/model lifecycle surroundings.

No target is run. This is not native admission or runtime/slowdown evidence.
"""
import argparse,hashlib,json,re
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
    elf=ROOT/'game_data/SLUS_207.65';overlay=ROOT/'build-function-index/owned-overlays/o2.bin'
    assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    main_read=elf_reader(elf.read_bytes());raw=overlay.read_bytes();proof=[];files=[]
    for at in [0x1aa740,0x1b1bb0,0x1b1e20,0x1b1e50,0x5ed340,0x5ed770,0x5f0c00,0x5f0dc0,0x5f1400,0x5ec100,0x5ec270,0x66a750]:
        path=next((ROOT/('recomp/config/output'if at<0x570000 else'recomp/config/output_ovl/o2')).glob(f'*_{at:08X}_*'))
        source=path.read_text();match=re.search(r'// Address: 0x([0-9a-f]+) - 0x([0-9a-f]+)',source);assert int(match[1],16)==at;end=int(match[2],16)
        read=main_read if at<0x570000 else lambda address,size:raw[address-0x570000:address-0x570000+size]
        proof.append(compare_source('complete static primary scene ownership boundary',path.relative_to(ROOT).as_posix(),at,end,read));files.append(path)
    out.mkdir()
    for path in files:
        target=out/'source'/path.relative_to(ROOT);target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes(path.read_bytes())
    result=dict(schema=1,status='static_source_words_verified',game_run=False,installed_in_game=False,stage4_complete=False,original_owned_bodies=proof,source_sha256={f.relative_to(ROOT).as_posix():sha(f)for f in files},observations=[
        '5ED340 rebuilds the eligible scene roster from authored4BAEA0 population, hiding every visited canonical actor before status filtering.38EDCC is a different count.',
        'The compact character array38ED90 has companion physical slots38ED88 and status words38ECE8. Preference38ECDC is remapped to a compact one-based index.',
        '5ED340 has mode-specific room filters and an additional scenario0x23/mode6/one-eligible/room0x13 branch. It is not a generic unfiltered roster copy.',
        '5ED340 resets the eligible count without clearing all eight character bytes.5F1400 still searches all eight physical bytes, including values outside the current count.',
        '5ED770 invokes5ED340 before selected descriptor model retirement, family cleanup, context restoration and main actor resume marking.',
        '5ED770 visits exactly16 output descriptors and marks BA4|0x80 only through authored4BAEA0 population, then clears temporary player/object bases.',
        'Fresh66A750 stores the Actor model-work pointer for its slot; restore bypasses that store.1AA740 builds the slot work and calls66A750.',
        '5ED340 also invokes1B1E50 and bank pointer-table release helpers; those are distinct from the already qualified5F0C00 family0 cleanup.'],limitations=[
        'Static instruction/source evidence only. No entry/exit sequence or game ran in this audit.',
        'Graphics, heap compaction, object cleanup, bank header-reset admission and complete resume dispatch are not proved by this receipt.',
        'Model-cache temporary admission and physical resource handoff must remain closed until their complete native lifecycle is implemented and tested.'])
    (out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(dict(status=result['status'],bodies=len(proof))))
if __name__=='__main__':main()
