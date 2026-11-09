"""Static owned-instruction evidence for remaining native motion math boundaries."""
import argparse,hashlib,json,re
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def main():
 p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);a=p.parse_args();assert not a.output.exists()
 elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read_main=elf_reader(elf.read_bytes())
 groups=[('o2','45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226',[0x65e3a0,0x65e4a0]),('o0','bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2',[0x370220,0x370320]),(None,None,[0x18fdf0,0x18fe20,0x18fe60,0x191300,0x1919d0,0x191f80,0x1902d0,0x190a10,0x18f570])]
 proofs=[]
 for tag,digest,entries in groups:
  if tag:
   image=ROOT/f'build-function-index/owned-overlays/{tag}.bin';assert sha(image)==digest;blob=image.read_bytes()
   def read(at,n):
    base=0x370000 if tag=='o0'else 0x570000
    assert base<=at and at+n<=base+len(blob)
    return blob[at-base:at-base+n]
  else:read=read_main
  for at in entries:
   folder=ROOT/(f'recomp/config/output_ovl/{tag}'if tag else'recomp/config/output');source=next(folder.glob((tag+'_'if tag else'sub_')+f'{at:08X}_*'));text=source.read_text();begin,end=[int(x,16)for x in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',text).groups()]
   proof=compare_source('remaining motion transform static source; not native execution qualification',source.relative_to(ROOT).as_posix(),begin,end,read)
   proof['direct_calls']=[dict(pc=pc,target='0x'+target.lower())for pc,target in re.findall(r'// (0x[0-9a-f]+): .*?jal\s+func_([0-9A-Fa-f]+)',text)];proofs.append(proof)
 q=dict(schema=1,status='static original instruction identities admitted; full native Euler/trig and pose-consumer reconstruction remain open',game_run=False,build_run=False,native_math_qualified=False,tool_sha256=sha(Path(__file__)),original_proofs=proofs,limits=['Existing collision Basis.direction/point admits scalar supplied bases, not the complete original Euler/trig producer.','Existing room-object yaw oracle declares angle/trig ports; it cannot independently prove full370220/370320 or18F570 semantics.','65E3A0 multiplies local-root movement by source basis/scale and actor multiplier, clears control bit8 before vector work, then adds components to current canonical position.','65E4A0 resets the canonical basis before yaw-forward calculation, uses a separate Euler order for local/world deltas, consumes both deltas, calls surface orientation6657B0, then publishes basis translation from the post-provider canonical position.','Model root-motion extraction and6657B0 surface-orientation pose effects remain explicit separate owners.'])
 a.output.parent.mkdir(parents=True,exist_ok=True);a.output.write_text(json.dumps(q,indent=2)+'\n');print(json.dumps(dict(path=str(a.output),sha256=sha(a.output),bodies=len(proofs))))
if __name__=='__main__':main()
