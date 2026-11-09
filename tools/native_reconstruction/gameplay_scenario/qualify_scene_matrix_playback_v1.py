"""Seal current-source native matrix curve playback without overstating providers."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    paths=[ROOT/'build-native-sjuni'/n/'receipt.json' for n in ['scene-matrix-playback-llvm-v7','scene-matrix-playback-gcc-v2']]
    records=[json.loads(p.read_bytes()) for p in paths]
    assert records[0]['source_sha256']==records[1]['source_sha256']
    assert records[0]['result']==records[1]['result']
    for path,record in zip(paths,records):
        assert record['status']=='passed' and not record['pinned_shared_commit']
        for n,h in record['source_sha256'].items():
            assert sha(ROOT/n)==h and sha(path.parent/'source'/n)==h,n
    result=dict(schema=1,status='qualified_native_scene_matrix_curve_playback_with_explicit_sound_provider',stage4_complete=False,installed_in_game=False,game_launched=False,live_process_access=False,
                source_sha256=records[0]['source_sha256'],
                receipts=[dict(path=p.relative_to(ROOT).as_posix(),sha256=sha(p),compiler_sha256=r['compiler_sha256'],result=r['result']) for p,r in zip(paths,records)],
                docs_and_tools_sha256={n:sha(ROOT/n) for n in ['docs/native-gameplay/SCENARIO_MATRIX_PLAYBACK.md',Path(__file__).relative_to(ROOT).as_posix()]},
                prerequisites={n:sha(ROOT/n) for n in ['tools/native_reconstruction/native_scene_matrix_programs_qualification_v1.json','tools/native_reconstruction/native_gameplay_shared_scene_records_qualification_v1.json']},
                scope=dict(channels=16,all_curve_selections=236,signed_time_values=65536,one_or_two_original_quanta=True,sound_callback_pose_mutation=True,canonical_optional_model_sound_resources=True,source_type_byte_owned=True),
                limitations=['6B60E0 room sound resolution and actual audio consumer remain required; oracle captures exact request arguments.',
                             'Outer5D7F00 actor interaction and program-group transitions remain open.',
                             'Complete5C1390 importer, other callers, game installation and gameplay acceptance remain open.',
                             'Finite SDK131 arithmetic only; no physical PS2 exceptional parity or measured performance gain claimed.'])
    out=ROOT/'tools/native_reconstruction/native_scene_matrix_playback_qualification_v1.json'
    assert not out.exists();out.write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps(dict(path=out.relative_to(ROOT).as_posix(),sha256=sha(out),result=records[0]['result'])))
if __name__=='__main__':main()
