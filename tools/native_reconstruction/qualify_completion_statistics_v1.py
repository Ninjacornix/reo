"""Seal reconstructed completion state and actual explicit-event consumer."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 target=ROOT/'tools/native_reconstruction/native_completion_statistics_qualification_v1.json';assert not target.exists();source={};cohorts={}
 for name in ['completion-statistics-llvm-v2','completion-statistics-gcc-v1','completion-statistics-update-llvm-v1','completion-statistics-update-gcc-v1']:
  p=ROOT/'build-native-sjuni'/name/'receipt.json';r=json.loads(p.read_bytes());assert r['status']=='passed'
  for n,h in r['source_sha256'].items():
   assert sha(ROOT/n)==h,n
   assert n not in source or source[n]==h,n
   source[n]=h
  cohorts[name]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p),'observed':r.get('observed',r.get('result'))}
 for n in ['game/native/gameplay_update/cooperative_events_tests.cpp','game/native/gameplay_update/CMakeLists.txt']:source[n]=sha(ROOT/n)
 parents={}
 for cc in ['llvm','gcc']:
  for kind in ['parent','tests']:
   p=ROOT/f'build-native-sjuni/stage4-completion-statistics-{kind}-{cc}-v1.log';raw=p.read_bytes();value=raw.decode('utf-16'if raw.startswith(b'\xff\xfe')else'utf-8-sig');assert ('100% tests passed, 0 tests failed out of 8'in value)if kind=='tests'else'FAILED:'not in value;parents[p.relative_to(ROOT).as_posix()]=sha(p)
 target.write_text(json.dumps({'schema':1,'status':'qualified native event-completion metadata/state and explicit event consumer; automatic conditions and other counters remain open','game_launched':False,'installed_in_game':False,'stage4_complete':False,'source_sha256':source,'cohorts':cohorts,'parent_checks':parents,'limitations':['Initializer comparison covers reconstructed completion bits/points/total, both seen arrays and actual event-pool reset; other counters in the original232-byte block are not claimed.','All171 owned rules and48 scenario-map bytes compare; other scenario IDs and bitset/seen overflow profiles remain unavailable.','Automatic condition evaluation, remaining counter writers, item consumers, save/export and actual game installation/acceptance remain open.']},indent=2)+'\n');print(sha(target))
if __name__=='__main__':main()
