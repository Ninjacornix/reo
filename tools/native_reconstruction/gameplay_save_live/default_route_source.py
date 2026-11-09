"""Admit ordinary default-chapter pad controls after the optional route declines.

An empty private card normally has one unlocked chapter. The existing diagnostic
chapter selector requires five; this file does not change that selector or flags.
"""
import hashlib,re,struct,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source
from inventory import OVERLAY_SHA
from gameplay_source import O2_SHA
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def audit():
 proofs=[];sources={};images={}
 for tag,digest,entries in [('o1',OVERLAY_SHA,[0x5838e0,0x584d90,0x586690,0x587640]),('o2',O2_SHA,[0x5fe440,0x603c20])]:
  image=ROOT/f'build-function-index/owned-overlays/{tag}.bin';assert sha(image)==digest;blob=image.read_bytes();images[tag]=digest
  def read(at,n):
   assert 0x570000<=at and at+n<=0x570000+len(blob)
   return blob[at-0x570000:at-0x570000+n]
  for at in entries:
   p=next((ROOT/f'recomp/config/output_ovl/{tag}').glob(tag+'_'+f'{at:08X}_*'))
   begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',p.read_text()).groups()]
   proofs.append(compare_source('ordinary default chapter/character/difficulty/cinematic controls',p.relative_to(ROOT).as_posix(),begin,end,read));sources[p.relative_to(ROOT).as_posix()]=sha(p)
  if tag=='o2':assert struct.unpack('<16I',read(0x73f260,64))[14]==0x5fe534
 # Bind the actual packaged implementation of the existing pad-only route.
 relative='recomp/overrides/reo_hw_bridge.cpp';workspace=(ROOT/relative).read_text();sealed_path=ROOT/'build-native-sjuni/candidate-inputs-v39/source'/relative;sealed=sealed_path.read_text()
 def body(text):return text[text.index('uint16_t pad2TestRoute('):text.index('// Opt-in test steering through the original analog-input path.')]
 assert body(workspace)==body(sealed)
 return dict(schema=1,offline_only=True,owned_images_sha256=images,original_proofs=proofs,source_sha256=sources,
  packaged_pad_only_route=dict(path=sealed_path.relative_to(ROOT).as_posix(),sha256=sha(sealed_path),function_text_sha256=hashlib.sha256(body(sealed).encode()).hexdigest()),
  takeover_required_log='[TEST-ROUTE-SCENARIO-1] all five chapters must be available; automatic input disabled',
  ordinary_default_chapter=dict(selection_pointer='0x32442c',ready_word_offset='0x20',state_word_offset=4,chapter_state='0x0108',count_offset='0x25c',cursor_offset='0x260',admitted_count=1,admitted_cursor=0),
  subsequent_controls=dict(character_state='0x0109',default_mode_state='0x030a',difficulty_state='0x050b',xinput_confirm='0x1000',cinematic_phase='0x0e',cinematic_skip_substates=[4,8],xinput_start='0x10',stop_at_original_phase=2),
  guest_writes=False,chapter_unlocks_changed=False,limits=['The optional built-in selector refusal is a harness precondition, not a game failure.','Only ordinary input after the explicit disabled-route report is admitted; unknown states receive no input.','Actual runtime scenario1/single-human/ready gameplay must still be observed after choosing original default cursor0.'])

if __name__=='__main__':
 import argparse,json
 p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);a=p.parse_args();assert not a.output.exists();v=audit();v['tool_sha256']=sha(Path(__file__));a.output.write_text(json.dumps(v,indent=2)+'\n');print(json.dumps(dict(path=str(a.output),sha256=sha(a.output))))
