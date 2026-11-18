"""Seal current resource-recipe comparisons and parent integration evidence."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 target=ROOT/'tools/native_reconstruction/native_resource_recipes_qualification_v1.json'
 assert not target.exists()
 source={};cohorts={}
 for name in ['resource-recipes-llvm-v2','resource-recipes-gcc-v2']:
  path=ROOT/'build-native-sjuni'/name/'receipt.json';r=json.loads(path.read_bytes());assert r['status']=='passed'and r['source_unchanged']
  for n,h in r['source_sha256'].items():
   assert sha(ROOT/n)==h,n
   assert n not in source or source[n]==h,n
   source[n]=h
  cohorts[name]={'path':path.relative_to(ROOT).as_posix(),'sha256':sha(path),'observed':r['observed']}
 source['game/native/gameplay_world/CMakeLists.txt']=sha(ROOT/'game/native/gameplay_world/CMakeLists.txt')
 source['docs/SYMBOLS_INVENTORY_USE_RECIPES.md']=sha(ROOT/'docs/SYMBOLS_INVENTORY_USE_RECIPES.md')
 source['tools/function_index/annotations.json']=sha(ROOT/'tools/function_index/annotations.json')
 parents={}
 for cc in ['llvm','gcc']:
  for kind in ['parent','tests']:
   path=ROOT/f'build-native-sjuni/stage4-resource-recipes-{kind}-{cc}-v1.log';raw=path.read_bytes();value=raw.decode('utf-16'if raw.startswith(b'\xff\xfe')else'utf-8-sig')
   assert ('100% tests passed, 0 tests failed out of 5'in value)if kind=='tests'else 'FAILED:'not in value
   parents[path.relative_to(ROOT).as_posix()]=sha(path)
 target.write_text(json.dumps({'schema':1,'status':'qualified native recipe primitives and alternate active-pair execution; full owned dispatcher/gameplay callers remain open','game_launched':False,'installed_in_game':False,'stage4_complete':False,'source_sha256':source,'cohorts':cohorts,'parent_checks':parents,'limitations':['Owner199 primary actor underflow and foreign/closed owners refuse; original storage-slot reload and reserved-zero effects are preserved.','Owned dispatcher additionally requires canonical cooperative event consumers; full UI and game installation/acceptance remain open.']},indent=2)+'\n')
 print(sha(target))
if __name__=='__main__':main()
