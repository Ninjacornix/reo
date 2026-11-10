"""Seal cooperative pool, actual update binding and current worker regressions."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 target=ROOT/'tools/native_reconstruction/native_cooperative_events_qualification_v1.json';assert not target.exists();source={};cohorts={}
 for name in ['cooperative-events-llvm-v1','cooperative-events-gcc-v1','cooperative-events-update-llvm-v3','cooperative-events-update-gcc-v1']:
  p=ROOT/'build-native-sjuni'/name/'receipt.json';r=json.loads(p.read_bytes());assert r['status']=='passed'
  for n,h in r['source_sha256'].items():
   assert sha(ROOT/n)==h,n
   assert n not in source or source[n]==h,n
   source[n]=h
  cohorts[name]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p),'observed':r.get('observed',r.get('result'))}
 for n in ['game/native/gameplay_update/CMakeLists.txt','game/native/gameplay_update/cooperative_events_tests.cpp']:source[n]=sha(ROOT/n)
 parents={}
 for cc in ['llvm','gcc']:
  for kind in ['parent','tests']:
   version=2 if kind=='parent'and cc=='llvm'else 1;p=ROOT/f'build-native-sjuni/stage4-cooperative-events-{kind}-{cc}-v{version}.log';raw=p.read_bytes();value=raw.decode('utf-16'if raw.startswith(b'\xff\xfe')else'utf-8-sig');assert ('100% tests passed, 0 tests failed out of 7'in value)if kind=='tests'else'FAILED:'not in value;parents[p.relative_to(ROOT).as_posix()]=sha(p)
 target.write_text(json.dumps({'schema':1,'status':'qualified cooperative event pool bound to actual native update clock/room; game callers remain uninstalled','game_launched':False,'installed_in_game':False,'stage4_complete':False,'source_sha256':source,'cohorts':cohorts,'parent_checks':parents,'limitations':['Typed priority admission is the actual39-byte prefix0..0x26; other IDs remain unavailable.','Worker ordering comparison declares separately qualified child ports, not full transitive game execution.','Remaining event producers, statistics/export/save consumers, full native gameplay and game acceptance remain open.']},indent=2)+'\n');print(sha(target))
if __name__=='__main__':main()
