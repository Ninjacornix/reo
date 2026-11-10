"""Seal scene condition lookup plus canonical ordinal initialization."""
import hashlib
import json
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target=ROOT/'tools/native_reconstruction/native_navigation_scene_lookup_qualification_v1.json'
    assert not target.exists()
    sources,cohorts,parents,binaries,failures={},{},{},{},{}
    observed,room_observed=None,None
    for cc in ['llvm','gcc']:
        for kind in ['navigation','room']:
            stem=f'navigation-lookup-{cc}' if kind=='navigation' else f'navigation-lookup-room-{cc}'
            path=ROOT/f'build-native-sjuni/{stem}-v2/receipt.json'
            receipt=json.loads(path.read_bytes());assert receipt['status']=='passed'
            data=receipt['observed' if kind=='navigation' else 'result']
            expected=dict(checks=67935384,scene_lookup_cases=13825,scene_global_lookup_cases=4608,
                scene_lookup_refusals=5,scene_candidate_cases=7172,scene_actor_cases=131329,
                cost_retail_refusals=0,local_retail_refusals=0,graph_original_limited=6725) if kind=='navigation' else dict(
                    checks=259706,original_calls=58566,controlled_rooms=64,stock_rooms=166,stock_records=2144,
                    installed_stock_profile_rooms=163,refused_stock_profile_rooms=3,
                    actual_helper84_calls=342,actual_helper85_calls=96,actual_reprojection_calls=127,actual_inverse_calls=517)
            for key,value in expected.items():
                assert data[key]==value,key
            previous=observed if kind=='navigation' else room_observed
            assert previous is None or previous==data
            if kind=='navigation':
                observed=data;assert receipt['source_unchanged']
                for name,digest in receipt['output_sha256'].items():
                    assert sha(path.parent/name)==digest,name
            else:
                room_observed=data
                assert sha(path.parent/'checks.exe')==receipt['executable_sha256']
            for name,digest in (receipt['source_sha256']|receipt.get('original_source_sha256',{})).items():
                assert sha(ROOT/name)==digest,name
                assert name not in sources or sources[name]==digest,name
                sources[name]=digest
            cohorts[cc+'_'+kind]=dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),
                observed={key:value for key,value in data.items() if key!='graph_original_limited_queries'},
                original_limited_rows_in_hashed_receipt=kind=='navigation')
        for kind in ['parent','tests']:
            path=ROOT/f'build-native-sjuni/navigation-lookup-{kind}-{cc}-v1.log'
            raw=path.read_bytes();text=raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 10' in text) if kind=='tests' else ('FAILED:' not in text and 'error:' not in text)
            parents[path.relative_to(ROOT).as_posix()]=sha(path)
        for suffix in ['gameplay_update/gameplay_navigation_owner_tests.exe',
            'gameplay_update/libreo_native_gameplay_update.a','gameplay_navigation/libreo_native_navigation_visibility.a',
            'gameplay_navigation/CMakeFiles/reo_native_navigation_visibility.dir/scene_lookup.cpp.obj',
            'gameplay_scenario/CMakeFiles/reo_native_gameplay_scenario.dir/room_scene_input.cpp.obj',
            'gameplay_navigation/reo_native_gameplay_navigation_tests.exe']:
            path=ROOT/f'build-native-sjuni/gameplay-native-{cc}-v1'/suffix
            binaries[path.relative_to(ROOT).as_posix()]=sha(path)
        for stem in [f'navigation-lookup-{cc}',f'navigation-lookup-room-{cc}']:
            path=ROOT/f'build-native-sjuni/{stem}-v1/receipt.json'
            failures[path.relative_to(ROOT).as_posix()]=dict(sha256=sha(path),status=json.loads(path.read_bytes())['status'])
    for name in ['game/native/gameplay_update/update.hpp','game/native/gameplay_update/navigation.cpp',
        'game/native/gameplay_update/navigation_tests.cpp','game/native/gameplay_world/world.hpp',
        'tools/native_reconstruction/gameplay_update_sources.py','tools/native_reconstruction/effect_work_sources.py',
        Path(__file__).relative_to(ROOT).as_posix()]:
        sources[name]=sha(ROOT/name)
    prior=ROOT/'tools/native_reconstruction/native_navigation_scene_candidates_qualification_v1.json'
    target.write_text(json.dumps(dict(schema=1,status='qualified native condition lookup and canonical scene ordinal producer',
        game_launched=False,installed_in_game=False,stage4_complete=False,source_sha256=sources,
        cohorts=cohorts,parent_checks=parents,qualified_binaries=binaries,superseded_v1_receipts=failures,
        prior_candidates=dict(path=prior.relative_to(ROOT).as_posix(),sha256=sha(prior)),limitations=[
            'Both compiler navigation cohorts pass67935384 identical checks. Complete819FF0/81A080 execute with complete81A0E0 applicability:13825 candidate-list and4608 global lookup comparisons cover every ordinal byte, condition0/1/127, activation/subtype/actor variants, reordered/empty lists and default zero. Signed byte128 never equals positive resolved index+1 of128. Rejected condition-1 searches ordinal zero; no activation/busy/geometry filter is added.',
            'Native results use the same shared Records identities. Stale/foreign candidates, unavailable collections, excessive list count and unknown condition refuse instead of reporting no match. Actual Owner tests use canonical actor room/AI-control/Bank, candidate/global selection, zero ordinal on rejection, disabled/busy records and retirement. Five tracked refusal profiles and a separate negative-condition refusal are exercised.',
            'Record.condition_ordinal owns original3F once. Existing44/45 owner snapshot/extra metadata remains separate. Full original allocator clears3F to zero; full room initializer assigns ordinal+1. RoomSceneInput now supplies that initial value, while script/control/geometry edits preserve it. Controlled full initializer comparisons check canonical values for both base and generated helper records.',
            'Both full initializer cohorts pass259706 checks and58566 original invocations over64 controlled and166 owned rooms/2144 authored records. Strict install profiles admit163 rooms and retain the three existing authored-model refusal rooms. Original inverse/model helpers execute; the prior declared authored-absence correction remains a distinct profile, not silently enabled here.',
            'Both current parent builds and ten integration checks pass. v1 navigation tests passed before the final shared record correction; v1 room builds caught removal of unrelated extra45 metadata. v2 restores that field, retains a distinct ordinal3F and reruns both source closures. Failed/superseded evidence remains retained.',
            'All prior navigation/graph comparisons retain their explicit original-work limits. Full812540 observations, remaining AI/stock VM/input/network/save owners, real scene provider/loading and coherent native gameplay acceptance remain open. Installed V39 is unchanged; no game launch, measured slowdown fix or Stage4 completion is claimed.'
        ]),indent=2)+'\n')
    print(sha(target))


if __name__=='__main__':
    main()
