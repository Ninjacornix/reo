"""Freeze owned script-prefix inventory against native interpreter v8."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 paths=[ROOT/'build-native-sjuni'/f'gameplay-script-content-{cc}-v5/receipt.json' for cc in ['llvm','gcc']];data=[json.loads(p.read_text()) for p in paths]
 for d in data:
  assert d['status']=='passed' and not d['game_launched'] and not d['installed_in_game']
  for p,digest in d['source_sha256'].items():assert sha(ROOT/p)==digest
 assert data[0]['source_sha256']==data[1]['source_sha256'] and data[0]['output_sha256']==data[1]['output_sha256']
 ledger=ROOT/'tools/native_reconstruction/gameplay_scenario_qualification_v8.json';assert all(d['capability_ledger_sha256']==sha(ledger) for d in data)
 summary=json.loads((paths[0].parent/'summary.json').read_text());docs=[ROOT/'docs/native-gameplay/SCENARIO_CONTENT_FRONTIERS_V8.md',Path(__file__)]
 q=dict(schema='reo.native.gameplay.script_content.qualification.v5',status='qualified_bounded_tables_partial_flow_inventory',complete=False,stage4_complete=False,installed_in_game=False,game_launched=False,live_process_access=False,runtime_reachability_proven=False,full_stock_program_admission=False,
  source_sha256=data[0]['source_sha256'],source_authority_sha256=data[0]['source_authority_sha256'],capability_ledger_sha256=sha(ledger),checked_owned_instruction_comments=data[0]['checked_owned_instruction_comments'],documentation_and_tools_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in docs},summary=summary,
  receipts=[dict(path=p.relative_to(ROOT).as_posix(),sha256=sha(p),compiler=d['compiler'],compiler_sha256=d['compiler_sha256'],native_fixture_result=d['native_fixture_result'],output_sha256=d['output_sha256']) for p,d in zip(paths,data)],limitations=data[0]['limitations'])
 out=ROOT/'tools/native_reconstruction/gameplay_script_content_qualification_v5.json';assert not out.exists();out.write_text(json.dumps(q,indent=2)+'\n');print(json.dumps(dict(path=out.relative_to(ROOT).as_posix(),sha256=sha(out))))
if __name__=='__main__':main()
