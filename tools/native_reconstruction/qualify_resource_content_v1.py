"""Seal current resource-content comparisons and parent integration evidence."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 target=ROOT/'tools/native_reconstruction/native_resource_content_qualification_v1.json'
 assert not target.exists()
 source={};cohorts={}
 for name in ['resource-content-llvm-v4','resource-content-gcc-v1']:
  path=ROOT/'build-native-sjuni'/name/'receipt.json';r=json.loads(path.read_bytes());assert r['status']=='passed'and r['source_unchanged']
  for n,h in r['source_sha256'].items():
   assert sha(ROOT/n)==h,n
   assert n not in source or source[n]==h,n
   source[n]=h
  cohorts[name]={'path':path.relative_to(ROOT).as_posix(),'sha256':sha(path),'observed':r['observed']}
 parents={}
 for cc in ['llvm','gcc']:
  for kind in ['parent','tests']:
   path=ROOT/f'build-native-sjuni/stage4-resource-content-{kind}-{cc}-v1.log';raw=path.read_bytes();value=raw.decode('utf-16'if raw.startswith(b'\xff\xfe')else'utf-8-sig')
   assert ('100% tests passed, 0 tests failed out of 5'in value)if kind=='tests'else 'FAILED:'not in value
   parents[path.relative_to(ROOT).as_posix()]=sha(path)
 target.write_text(json.dumps({'schema':1,'status':'qualified native resource content replacement and instance rebinding; higher callers remain open','game_launched':False,'installed_in_game':False,'stage4_complete':False,'source_sha256':source,'cohorts':cohorts,'parent_checks':parents,'limitations':['Only canonical native descriptors/models are admitted; callback classes outside0..3 and two greater-than-six-part roots refuse.','Full recipe/transfer, higher gameplay callers and actual installation remain open.']},indent=2)+'\n')
 print(sha(target))
if __name__=='__main__':main()
