"""Bind canonical native phase/clock/worker/task/status comparison cohorts."""
import json,hashlib
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 names=['gameplay-update-llvm-v7','gameplay-update-gcc-v4','native-gameplay/tasks/llvm-v8','native-gameplay/tasks/gcc-v8','actor-status-llvm-v4','actor-status-gcc-v2']
 paths=[ROOT/'build-native-sjuni'/n/'receipt.json' for n in names];data=[json.loads(p.read_text()) for p in paths]
 statuses=['passed','native gameplay ownership/timer/clock units and complete original-word comparisons passed','native actor status timers and actions match seven complete original bodies']
 for pair in range(3):
  a,b=data[2*pair:2*pair+2];assert a['status']==b['status']==statuses[pair]
  assert a['source_sha256']==b['source_sha256'] and a.get('result',a.get('observed'))==b.get('result',b.get('observed'))
 source={}
 for d in data:
  for p,h in d['source_sha256'].items():
   assert sha(ROOT/p)==h,p
   assert p not in source or source[p]==h,p
   source[p]=h
 q=dict(schema='reo.native.gameplay.update.qualification.v2',status='qualified_native_outer_phase_clock_worker_task_status_composition',stage4_complete=False,game_launched=False,installed_in_game=False,source_sha256=source,
  receipts=[dict(path=p.relative_to(ROOT).as_posix(),sha256=sha(p),result=d.get('result',d.get('observed')),cases=d.get('cases'),original_instructions=d.get('original_instructions'),checked_owned_instruction_comments=d.get('checked_owned_instruction_comments'),detected_counterfactuals=len(d.get('detected_counterfactuals',[]))) for p,d in zip(paths,data)],
  documentation_and_tools_sha256={p:sha(ROOT/p) for p in ['docs/native-gameplay/UPDATE_OWNER.md','docs/native-gameplay/ACTOR_HEALTH.md',Path(__file__).relative_to(ROOT).as_posix()]},
  canonical_timing=dict(source_seconds='4BAE02',source_subseconds='4BAE03',native_owner_view=True,duplicate_owner_refused=True,detach_on_close=True,standalone_value_profile_retained=True),
  task_teardown=dict(both_stores_sealed_before_payload_release=True,cross_store_destructor_admission_refused=True,active_owner_destruction_crash_tested=False),
  limitations=['Complete5FEA30/5FED00/68C8D0/5FEE60/5FEE70/5FEE80 execute. Actor/script/task/timer children and remaining UI/audio/scene effects remain explicit declared ports in the outer cohort.','Outer cohort has no active actors and uses admitted synthetic scripts; no whole stock or transitive actor/action execution is claimed.','Seven status bodies and12task bodies separately execute with their declared services/word oracle. Counts overlap; do not sum as unique coverage.','No game installation, worker-factory/payload completion, native save semantic snapshots, co-op acceptance or completeStage4 claim.'])
 out=ROOT/'tools/native_reconstruction/native_gameplay_update_qualification_v2.json';assert not out.exists();out.write_text(json.dumps(q,indent=2)+'\n',encoding='utf8');print(out.relative_to(ROOT),sha(out))
if __name__=='__main__':main()
