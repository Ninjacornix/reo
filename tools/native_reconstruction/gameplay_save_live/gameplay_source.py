"""Offline original-body/table admission for the ordinary gameplay options case."""
import hashlib,json,re,struct,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source,elf_reader
from inventory import ELF_SHA
O2_SHA='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def audit():
 elf=ROOT/'game_data/SLUS_207.65';overlay=ROOT/'build-function-index/owned-overlays/o2.bin'
 assert sha(elf)==ELF_SHA and sha(overlay)==O2_SHA
 read=elf_reader(elf.read_bytes());blob=overlay.read_bytes()
 def ovread(at,n):
  assert 0x570000<=at and at+n<=0x570000+len(blob)
  return blob[at-0x570000:at-0x570000+n]
 proofs=[];sources={}
 for at,ov in [(0x1b0db0,False),(0x5fea30,True),(0x6deea0,True),(0x6e0ed0,True),(0x6ecde0,True),(0x6e1430,True)]:
  folder=ROOT/('recomp/config/output_ovl/o2'if ov else'recomp/config/output')
  p=next(folder.glob(('o2_'if ov else'sub_')+f'{at:08X}_*'))
  begin,end=map(lambda x:int(x,16),re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',p.read_text()).groups())
  proofs.append(compare_source('ordinary gameplay options original body',p.relative_to(ROOT).as_posix(),begin,end,ovread if ov else read));sources[p.relative_to(ROOT).as_posix()]=sha(p)
 table=list(struct.unpack('<12I',ovread(0x742d90,48)))
 assert table==[0x6ecf54,0x6ecfdc,0x6ed054,0x6ed0d0,0x6ed158,0x6ed1e0,0x6ed2fc,0x6ed398,0x6ed434,0x6ed4d4,0x6ed5ec,0x6ed634]
 assert struct.unpack('<3I',read(0x2343c0,12))==(0x100,0x20,0x10)
 word=int.from_bytes(ovread(0x6ed6a8,4),'little');assert word==0x0c06bb6c
 signature=ovread(0x6ecde0,32)
 return dict(schema=1,offline_only=True,owned_elf_sha256=ELF_SHA,owned_o2_sha256=O2_SHA,source_sha256=sources,original_proofs=proofs,
  option_table_at='0x742d90',option_table=[hex(v)for v in table],capture_options_call=dict(pc='0x6ed6a8',word=hex(word),target='0x1aedb0'),
  gameplay_ui_kind=4,state_address='0x755ec0',kind_address='0x755ec4',initial_state=1,initial_row=10,brightness_row=5,exit_row=10,
  source_code_signature=dict(at='0x6ecde0',bytes=signature.hex(),sha256=hashlib.sha256(signature).hexdigest()),
  controls=dict(select_xinput=0x20,select_converted_edge=0x4000,profile=0,profile_table=[0x100,0x20,0x10],confirm_xinput=0x1000,confirm_game_mapped_edge=0x20),
  limits=['Original code admits the menu fields. Actual native entry completion still requires final joined counters.','The built-in gameplay route produces ordinary pad input and stops at original phase2; it does not write guest state.','This case changes a private live option and checks resumption; it does not create a gameplay temporary save or install the new native World.'])

if __name__=='__main__':
 import argparse
 p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);a=p.parse_args();assert not a.output.exists()
 v=audit();v['tool_sha256']=sha(Path(__file__));a.output.write_text(json.dumps(v,indent=2)+'\n');print(json.dumps(dict(path=str(a.output),sha256=sha(a.output))))
