"""Seal source-compared navigation predicates and actual UpdateOwner consumers."""
import hashlib
import json
from pathlib import Path
ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT/'tools/native_reconstruction/native_navigation_conditions_qualification_v1.json'
    assert not target.exists()
    sources, cohorts, parents, binaries = {}, {}, {}, {}
    expected = dict(checks=9364884,nearest_cases=26930,action_cases=265608,
        asset_rooms=166,asset_nodes=3334,asset_conditions=2167,asset_links=432,
        refusals=27155,nearest_refusals=26672,action_refusals=0,bindings=1920,
        clears=34,bank_cells=327680,bank_visit_cells=6912,bank_clears=20,
        condition_cases=561008,link_cases=2062,link_refusals=3077)
    for cc in ['llvm', 'gcc']:
        path = ROOT/f'build-native-sjuni/navigation-conditions-{cc}-v2/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged'] and receipt['observed'] == expected
        for name, digest in receipt['source_sha256'].items():
            assert sha(ROOT/name) == digest, name
            assert name not in sources or sources[name] == digest
            sources[name] = digest
        for name, digest in receipt['output_sha256'].items():
            assert sha(path.parent/name) == digest, name
        cohorts[cc] = dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),observed=receipt['observed'])
        for kind in ['parent', 'tests']:
            path = ROOT/f'build-native-sjuni/navigation-conditions-{kind}-{cc}-v1.log'
            raw = path.read_bytes();text = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 10' in text) if kind == 'tests' else ('FAILED:' not in text and 'error:' not in text)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
        for suffix in ['gameplay_update/gameplay_navigation_owner_tests.exe', 'gameplay_update/CMakeFiles/reo_native_gameplay_update.dir/navigation.cpp.obj', 'gameplay_update/libreo_native_gameplay_update.a']:
            path = ROOT/f'build-native-sjuni/gameplay-native-{cc}-v1'/suffix
            binaries[path.relative_to(ROOT).as_posix()] = sha(path)
    for name in [
        'game/native/gameplay_update/update.hpp','game/native/gameplay_update/update.cpp',
        'game/native/gameplay_update/navigation.cpp','game/native/gameplay_update/navigation_tests.cpp',
        'game/native/gameplay_update/CMakeLists.txt','game/native/gameplay_world/world.hpp',
        'game/native/gameplay_world/world.cpp','game/native/gameplay_world/CMakeLists.txt',
        'game/native/gameplay_scenario/flags.hpp','game/native/gameplay_scenario/flags.cpp',
        'tools/native_reconstruction/gameplay_update_sources.py','tools/native_reconstruction/effect_work_sources.py',
    ]:
        sources[name] = sha(ROOT/name)
    prior = ROOT/'tools/native_reconstruction/native_navigation_bank_qualification_v1.json'
    target.write_text(json.dumps(dict(schema=1,status='qualified native navigation conditions and admitted links',
        game_launched=False,installed_in_game=False,stage4_complete=False,source_sha256=sources,
        cohorts=cohorts,parent_checks=parents,owner_binaries=binaries,
        prior_vm=dict(path=prior.relative_to(ROOT).as_posix(),sha256=sha(prior),scope='Historical full VM room-variant qualification; not a claimed full VM rerun for these additional predicates'),limitations=[
            'Complete81A0E0/819220/819360/8193A0/819410 execute against pinned instruction-word-audited originals. All condition type/subtype bytes, character and AI-control predicates, actor slot comparisons, active/default cases and flag shift wrapping compare within bounded valid records.',
            'Native conditions read ephemeral facts from the sole canonical Actor character,slot,ai_control fields; ai_control already owns sourceFF0. Actual UpdateOwner methods use that World navigation bank and its own FlagState strided room slot0, not duplicate actor or flag state.',
            'First matching unfiltered link and first admitted duplicate link preserve order. Signed link operands remain signed. Missing graph/record/context returns unavailable before unsafe reads; completed absence/denial remains distinct.3077 link refusals include the synthetic invalid ordinal and actual queries under deliberately unbound room variants, not3077 diagnosed retail defects.',
            'Both compiler cohorts pass9364884 checks,561008 condition and2062 admitted-link comparisons. All2167 retail conditions are exercised under16 actor/flag combinations. Actual UpdateOwner composition verifies current flag mutations, canonical ai_control changes, absence, invalid/foreign/retired actors and World closure. All ten parent tests pass per compiler.',
            'Prior current-source full VM qualification is retained and explicitly historical. No game launched or installed and no performance cause/fix is claimed. Node-edge/route policies, successful scene/AI execution, actual loading, semantic saves and coherent native game acceptance remain open; Stage4 is incomplete.'
        ]),indent=2)+'\n')
    print(sha(target))


if __name__ == '__main__':
    main()
