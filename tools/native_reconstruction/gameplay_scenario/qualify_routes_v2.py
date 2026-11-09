"""Freeze final clean native route query header without rewriting old receipts."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 previous=ROOT/'tools/native_reconstruction/native_scene_control_routes_qualification_v1.json';q=json.loads(previous.read_text());paths=[ROOT/'build-native-sjuni'/n/'receipt.json'for n in ['gameplay-route-controls-llvm-v3','gameplay-route-controls-gcc-v2']];data=[json.loads(p.read_text())for p in paths]
 for d in data:
  assert d['status']=='passed'
  for p,h in d['source_sha256'].items():assert sha(ROOT/p)==h,p
 assert data[0]['source_sha256']==data[1]['source_sha256']and data[0]['result']==data[1]['result']
 docs=[ROOT/'docs/native-gameplay/SCENARIO_CONTROL_ROUTES_V2.md',Path(__file__)];q.update(schema='reo.native.scene_control.routes.qualification.v2',previous_qualification=dict(path=previous.relative_to(ROOT).as_posix(),sha256=sha(previous)),source_sha256=data[0]['source_sha256'],documentation_sha256={p.relative_to(ROOT).as_posix():sha(p)for p in docs},receipts=[dict(path=p.relative_to(ROOT).as_posix(),sha256=sha(p),compiler=d['compiler'],compiler_sha256=d['compiler_sha256'],result=d['result'],checked_owned_instruction_comments=d['checked_owned_instruction_comments'])for p,d in zip(paths,data)])
 out=ROOT/'tools/native_reconstruction/native_scene_control_routes_qualification_v2.json';assert not out.exists();out.write_text(json.dumps(q,indent=2)+'\n');print(json.dumps(dict(path=out.relative_to(ROOT).as_posix(),sha256=sha(out))))
if __name__=='__main__':main()
