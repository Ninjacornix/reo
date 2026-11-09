"""Seal the owned content prefix inventory against interpreter v17."""
import hashlib
import json
from pathlib import Path
ROOT = Path(__file__).resolve().parents[3]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    paths = [ROOT / 'build-native-sjuni' / ('gameplay-script-content-' + cc + '-v14') / 'receipt.json' for cc in ['llvm', 'gcc']]
    data = [json.loads(path.read_bytes()) for path in paths]
    ledger = ROOT / 'tools/native_reconstruction/gameplay_scenario_qualification_v17.json'
    for record in data:
        assert record['status'] == 'passed' and not record['game_launched'] and not record['installed_in_game']
        assert record['capability_ledger_sha256'] == sha(ledger)
        for name, digest in record['source_sha256'].items():
            assert sha(ROOT / name) == digest, name
    assert data[0]['source_sha256'] == data[1]['source_sha256'] and data[0]['output_sha256'] == data[1]['output_sha256']
    docs = [ROOT / 'docs/native-gameplay/SCENARIO_CONTENT_FRONTIERS_V17.md', Path(__file__)]
    result = dict(schema='reo.native.gameplay.script_content.qualification.v14', status='qualified_bounded_tables_partial_flow_inventory',
                  complete=False, stage4_complete=False, installed_in_game=False, game_launched=False,
                  live_process_access=False, runtime_reachability_proven=False, full_stock_program_admission=False,
                  source_sha256=data[0]['source_sha256'], source_authority_sha256=data[0]['source_authority_sha256'],
                  capability_ledger_sha256=sha(ledger), checked_owned_instruction_comments=data[0]['checked_owned_instruction_comments'],
                  documentation_and_tools_sha256={p.relative_to(ROOT).as_posix(): sha(p) for p in docs},
                  summary=json.loads((paths[0].parent / 'summary.json').read_bytes()),
                  receipts=[dict(path=p.relative_to(ROOT).as_posix(), sha256=sha(p), compiler=d['compiler'], compiler_sha256=d['compiler_sha256'],
                                 native_fixture_result=d['native_fixture_result'], output_sha256=d['output_sha256']) for p, d in zip(paths, data)],
                  limitations=data[0]['limitations'])
    output = ROOT / 'tools/native_reconstruction/gameplay_script_content_qualification_v14.json'
    assert not output.exists()
    output.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(dict(path=output.relative_to(ROOT).as_posix(), sha256=sha(output))))


if __name__ == '__main__':
    main()
