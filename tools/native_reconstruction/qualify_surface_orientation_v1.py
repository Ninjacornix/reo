"""Join the two immutable surface-orientation original-body cohorts."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def main():
 paths={'llvm':ROOT/'build-native-sjuni/surface-orientation-llvm-v3/receipt.json','gcc':ROOT/'build-native-sjuni/surface-orientation-gcc-v1/receipt.json'}
 records={name:json.loads(p.read_bytes())for name,p in paths.items()}
 first=records['llvm'];assert first['observed']['checks']==354082
 for name,record in records.items():
  assert record['status']=='passed'and record['source_unchanged']and record['observed']==first['observed']and record['source_sha256']==first['source_sha256']
  for n,h in record['source_sha256'].items():assert sha(ROOT/n)==h and sha(paths[name].parent/'source'/n)==h,n
  for n,h in record['output_sha256'].items():assert sha(paths[name].parent/n)==h,n
  math=Path(record['qualified_math_receipt']['path']);assert sha(math)==record['qualified_math_receipt']['sha256'];assert json.loads(math.read_bytes())['source_unchanged']
 doc='docs/native-gameplay/SURFACE_ORIENTATION.md';out=ROOT/'tools/native_reconstruction/native_gameplay_surface_orientation_qualification_v1.json';assert not out.exists()
 q=dict(schema=1,status='complete native three-probe surface orientation and real native Grid pose provider match original bodies on both compilers',stage4_complete=False,game_run=False,installed_in_game=False,physical_ps2_exceptional_parity=False,native_actor_shadow_copy=False,native_guest_or_register_state=False,complete_transitive_original_floor_execution=False,
  cohorts={name:dict(path=p.relative_to(ROOT).as_posix(),sha256=sha(p),compiler_sha256=records[name]['compiler_sha256'],observed=records[name]['observed'],qualified_math_receipt=records[name]['qualified_math_receipt'])for name,p in paths.items()},source_sha256=first['source_sha256'],
  immutable_source_evidence={n:dict(path=(paths['llvm'].parent/'source'/n).relative_to(ROOT).as_posix(),sha256=h)for n,h in first['source_sha256'].items()},
  documentation=dict(path=doc,sha256=sha(ROOT/doc)),qualifier=dict(path=Path(__file__).relative_to(ROOT).as_posix(),sha256=sha(Path(__file__))),
  owned_inputs=dict(main_elf=dict(path='game_data/SLUS_207.65',sha256='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'),o0=dict(path='build-function-index/owned-overlays/o0.bin',sha256='bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2'),o2=dict(path='build-function-index/owned-overlays/o2.bin',sha256='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226')),
  original_word_audits=[{k:v for k,v in item.items()if k!='comparisons'}for item in first['original_owned_bodies']],owned_orientation_data=first['owned_orientation_data'],declared_native_child_seams=first['declared_native_child_seams'],qualified_floor=first['qualified_floor'],
  contract=['Original0=processed including rejected/cleared;1=no requested work.','Category0/1 status bit8 may set flags548 bit1/rate0.1. Other categories require existing request.','Blend increment/clamp precedes yaw work and all three ordered FF floor probes. All point translations precede first callback.','Returned floor heights are used regardless of class; greater-than80 differences clear flags bit1/weight0.','Stored normal dot up greater than cos(turn0x100) clears the blend; at/below threshold constructs and blends slope basis.','Normal/cross/basis/weighted orthogonalization preserves actual FP32 order. Zero/parallel vectors use SDK131 max-finite reciprocal-square-root behavior.','Canonical fields are reread after required query providers. No shadowActor/guest pointers/registers in production.','Required-provider/unsupported-numeric/profile failure is visible; no after-effects fallback. Enclosing pose becomes ready only after final current-position translation.'],
  preserved_intermediate_runs=[dict(path='build-native-sjuni/surface-orientation-llvm-v1',result='strict original generated unused-variable warning; source fixture-only diagnostic suppression'),dict(path='build-native-sjuni/surface-orientation-llvm-v2',result='passed pre-World/repeated-blend checkpoint')],
  limits=['617000 is a declared independently qualified unchanged native Grid seam; not complete transitive original floor execution.','Finite FP32 round-nearest/gradual-underflow/no-contraction profile; physicalPS2 exceptional semantics/flags/accumulatorprecision not claimed.','No installation, game launch, walltime-speedup claim or wholeStage4 completion.','Real room-content ownership/admission, animation root-motion production, remaining actor behavior/pose consumers, integration and controlled game retest remain separate gates.','Borrowed native floor/grid/provider lifetimes must cover synchronous calls.'])
 out.write_text(json.dumps(q,indent=2)+'\n');print(json.dumps(dict(qualification=out.relative_to(ROOT).as_posix(),sha256=sha(out))))
if __name__=='__main__':main()
