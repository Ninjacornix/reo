"""Seal native shared effect work and fog with retained original-body evidence."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()
def main():
    paths=[ROOT/'build-native-sjuni'/name/'receipt.json' for name in ['effect-work-llvm-v15','effect-work-gcc-v2']]
    records=[json.loads(path.read_bytes()) for path in paths]
    assert records[0]['observed']==records[1]['observed']
    assert records[0]['source_sha256']==records[1]['source_sha256']
    for path,record in zip(paths,records):
        assert record['status']=='passed' and record['observed']['general_unknown_profiles']==0
        for name,digest in record['source_sha256'].items():
            assert sha(path.parent/'source'/name)==digest,name
            assert sha(ROOT/name)==digest,name
        for name,digest in record['output_sha256'].items():assert sha(path.parent/name)==digest,name
    own={name:digest for name,digest in records[0]['source_sha256'].items() if name.startswith('game/native/gameplay_effects/') or name in ['game/native/gameplay_scenario/fog.cpp','game/native/gameplay_scenario/fog.hpp']}
    extra=['docs/native-gameplay/EFFECT_WORK_AND_FOG.md',Path(__file__).relative_to(ROOT).as_posix(),'tools/native_reconstruction/import_fog_assets.py']
    result=dict(schema=1,status='qualified_shared_native_effect_work_and_fog_with_explicit_remaining_callers',stage4_complete=False,installed_in_game=False,game_run=False,live_process_access=False,
                production_sha256=own,source_sha256=records[0]['source_sha256'],
                receipts=[dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),compiler_sha256=record['compiler_sha256'],observed=record['observed']) for path,record in zip(paths,records)],
                documentation_and_tools_sha256={name:sha(ROOT/name) for name in extra},
                prerequisites={name:sha(ROOT/name) for name in ['tools/native_reconstruction/native_periodic_visuals_qualification_v1.json','tools/native_reconstruction/native_effect_geometry_qualification_v1.json','tools/native_reconstruction/native_gameplay_impact_populations_qualification_v2.json','build-native-sjuni/fog-owned-v1/receipt.json']},
                canonical_domains=dict(work_capacity=168,child_capacity=256,shared_companion_capacity=True,checked_generation_edits=True,canonical_rng_binding=True),
                ef35_empty_group=dict(index=255,owned_file_offset=6124,header_bytes=20,header_sha256='89b02956dcee4386a598699c295ef683dd53dd73f15d937e92baf91d74c84595',parts=0,lifetime=12,logical_ids=[46,47,48,49,50,55,73],other_nonempty_ff_headers_not_admitted=True),
                limits=['Actual gameplay parameter producers, type17 work, positional audio routing and native output callers remain required.',
                        'Other work/update families and complete native game/task integration remain open.',
                        'Camera inverse requires finite nonzero basis axes; physical PS2 exceptional arithmetic is not claimed.',
                        'Original resource heap/cache/memcpy/memset and task-retirement surroundings remain the declared bounded oracle ports.',
                        'No game installation, performance improvement, renderer submission or wholeStage4 closure claimed.'])
    out=ROOT/'tools/native_reconstruction/native_effect_work_qualification_v1.json';assert not out.exists();out.write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps(dict(path=out.relative_to(ROOT).as_posix(),sha256=sha(out))))
if __name__=='__main__':main()
