"""Seal full owned recipe/event comparisons and actual native composition."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 target=ROOT/'tools/native_reconstruction/native_owned_resource_recipes_qualification_v1.json';assert not target.exists();source={};cohorts={}
 for name in ['owned-recipes-llvm-v4','owned-recipes-gcc-v2','owned-recipes-update-llvm-v1','owned-recipes-update-gcc-v1']:
  p=ROOT/'build-native-sjuni'/name/'receipt.json';r=json.loads(p.read_bytes());assert r['status']=='passed'
  for n,h in r['source_sha256'].items():
   assert sha(ROOT/n)==h,n
   assert n not in source or source[n]==h,n
   source[n]=h
  observed=r.get('observed',r.get('result'));cohorts[name]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p),'observed':observed}
  if name in ['owned-recipes-llvm-v4','owned-recipes-gcc-v2']:assert observed['owned_recipe_event_mask']==0x7ff80000
 for n in ['game/native/gameplay_world/CMakeLists.txt','game/native/gameplay_world/owned_resource_recipes_tests.cpp']:source[n]=sha(ROOT/n)
 parents={}
 for cc in ['llvm','gcc']:
  for kind in ['parent','tests']:
   p=ROOT/f'build-native-sjuni/stage4-owned-recipes-{kind}-{cc}-v1.log';raw=p.read_bytes();value=raw.decode('utf-16'if raw.startswith(b'\xff\xfe')else'utf-8-sig');assert ('100% tests passed, 0 tests failed out of 8'in value)if kind=='tests'else'FAILED:'not in value;parents[p.relative_to(ROOT).as_posix()]=sha(p)
 target.write_text(json.dumps({'schema':1,'status':'qualified admitted owned recipe dispatcher and actual cooperative event consumer; game callers remain uninstalled','game_launched':False,'installed_in_game':False,'stage4_complete':False,'source_sha256':source,'cohorts':cohorts,'parent_checks':parents,'limitations':['Post-operation source owner must resolve to a current canonical primary owner1..4; other profiles refuse after earlier effects.','The exact three-word mode getter is a declared bounded oracle port; actual1B0340/1B02D0 and full event-pool bodies execute.','Remaining item effects, inventory UI/ownership transfer, game caller installation and coherent native gameplay acceptance remain open.']},indent=2)+'\n');print(sha(target))
if __name__=='__main__':main()
