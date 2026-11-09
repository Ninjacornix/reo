"""Freeze actual matrix selectors/terminal evaluation and immutable owned data."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 paths=[ROOT/'build-native-sjuni'/n/'receipt.json'for n in ['gameplay-scene-matrix-programs-llvm-v7','gameplay-scene-matrix-programs-gcc-v1','gameplay-scene-matrix-tables-llvm-v1','gameplay-scene-matrix-tables-gcc-v1']];data=[json.loads(p.read_text())for p in paths]
 after_seal_drift={}
 for d in data:
  assert d['status']=='passed'and not d['game_launched']and not d['installed_in_game']
  for name,h in d['source_sha256'].items():
   if name in d.get('pinned_sources_sha256',{}):assert sha(next(p.parent/'source'/name for p,entry in zip(paths,data)if entry is d))==h
   elif sha(ROOT/name)!=h:
    assert name=='game/native/gameplay_tasks/tasks.hpp',name
    snapshot=next(p.parent/'source'/name for p,entry in zip(paths,data)if entry is d);assert sha(snapshot)==h
    current=(ROOT/name).read_text();old=snapshot.read_text();assert current.replace('    bool closed()const noexcept{return closed_;}\n','')==old
    after_seal_drift[name]=dict(compiled_snapshot_sha256=h,current_sha256=sha(ROOT/name),change='Parent added only Scheduler.closed accessor after the immutable private cohort snapshot.')
 for a,b in [(data[0],data[1]),(data[2],data[3])]:assert a['source_sha256']==b['source_sha256']
 assert data[0]['result']==data[1]['result']and data[2]['checked_native_values']==data[3]['checked_native_values']==2227
 docs=[ROOT/'docs/native-gameplay/SCENARIO_MATRIX_PROGRAM_SELECTION.md',Path(__file__)];owned=ROOT/'build-native-sjuni/gameplay-scene-matrix-tables-v1/receipt.json';q=dict(schema='reo.native.scene_matrix.programs.qualification.v1',status='qualified_partial_native_selection_and_terminal_consumer',complete=False,stage4_complete=False,installed_in_game=False,game_launched=False,live_process_access=False,physical_ps2_exceptional_parity=False,source_snapshot_sha256={n:h for d in data for n,h in d['source_sha256'].items()},pinned_shared_commit='fcc285f6',pinned_sources_sha256=data[0]['pinned_sources_sha256'],shared_header_changed_after_seal=after_seal_drift,documentation_and_tools_sha256={p.relative_to(ROOT).as_posix():sha(p)for p in docs},owned_data_receipt=dict(path=owned.relative_to(ROOT).as_posix(),sha256=sha(owned)),owned_image_sha256=data[0]['owned_image_sha256'],receipts=[dict(path=p.relative_to(ROOT).as_posix(),sha256=sha(p),compiler=d['compiler'],compiler_sha256=d['compiler_sha256'],result=d.get('result'),checked_native_values=d.get('checked_native_values'),current_pinned_source_drift=d.get('current_pinned_source_drift',{}))for p,d in zip(paths,data)],contract=dict(channels=16,programs=36,groups=59,curves=64,keys=582,sound_lists=13,sound_events=15,descriptor_profile=4,single_contact_gate_and_active_owner=True,real_native_model_binding=True,full64_base_copy_at_bind=True,other_classes_retain_program_or_terminal_noop=True,actual_terminal_math_chain=True),limitations=['Only the five selection boundaries and terminal first-segment evaluation are qualified; periodic advancement/sound service and the outer scene worker remain open.','Shared headers are compiled from pinned private snapshots; later parent interpreter/provider changes are not part of this comparison.','Descriptor and channel bounds are explicit native admission profiles, not proof of arbitrary source indexing.','Full shared128 control/proxy identity/capacity/order and room importing remain required before installation.','Counts overlap and are not unique instruction or complete gameplay coverage.','No new opcode mask or complete Stage4/game/co-op/render validation is claimed.'])
 out=ROOT/'tools/native_reconstruction/native_scene_matrix_programs_qualification_v1.json';assert not out.exists();out.write_text(json.dumps(q,indent=2)+'\n');print(json.dumps(dict(path=out.relative_to(ROOT).as_posix(),sha256=sha(out))))
if __name__=='__main__':main()
