"""Seal native actor item callers and the canonical World D92 notice fix."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT / 'tools/native_reconstruction/native_actor_resource_operations_qualification_v1.json'
    assert not target.exists()
    source, cohorts, parents, worlds, primitives = {}, {}, {}, {}, {}
    expected = None
    def verify_sources(receipt):
        for name, digest in receipt['source_sha256'].items():
            assert sha(ROOT / name) == digest, name
            assert name not in source or source[name] == digest, name
            source[name] = digest
    for cc in ['llvm', 'gcc']:
        path = ROOT / f'build-native-sjuni/actor-resource-operations-{cc}-v2/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged']
        observed = receipt['observed']
        assert observed['checks'] == 372678288 and observed['actor_operation_cases'] == 1179648
        assert observed['actor_operation_live'] == 1728 and observed['actor_operation_gates'] == 393216
        assert observed['actor_operation_refusals'] == 5 and observed['actor_operation_transfer_mask'] == 27
        assert observed['actor_operation_publications'] == 12
        assert observed['heap_allocations'] == observed['heap_releases'] == 87896
        assert expected is None or expected == observed
        expected = observed
        assert all(any(row['start'] == hex(at) for row in receipt['original_owned_bodies']) for at in [0x5f4fe0,0x5f5c50,0x5f6a80])
        verify_sources(receipt)
        cohorts[cc] = dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),observed=observed)
        for kind in ['parent','tests']:
            path = ROOT / f'build-native-sjuni/stage4-actor-resource-operations-{kind}-{cc}-v2.log'
            raw = path.read_bytes()
            value = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 8' in value) if kind == 'tests' else ('FAILED:' not in value and 'error:' not in value)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
        path = ROOT / f'build-native-sjuni/actor-resource-notice-world-{cc}-v2/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['source_unchanged'] and receipt['original_body_executed']
        assert receipt['observed']['cases'] == 4096 and receipt['observed']['ordered_calls'] == 291127
        assert receipt['observed']['native_lifetime'] == dict(checks=78,status='passed',game_run=False)
        verify_sources(receipt)
        worlds[cc] = dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),observed=receipt['observed'])
        path = ROOT / f'build-native-sjuni/actor-resource-notice-primitives-{cc}-v1/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged']
        assert receipt['observed']['checks'] == 11671463 and receipt['observed']['primitive_cases'] == 45056
        assert any(row['start'] == '0x65e710' for row in receipt['original_owned_bodies'])
        verify_sources(receipt)
        primitives[cc] = dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),observed=receipt['observed'])
    source['game/native/gameplay_world/CMakeLists.txt'] = sha(ROOT / 'game/native/gameplay_world/CMakeLists.txt')
    assert 'equipment_notice_flags' not in (ROOT / 'game/native/gameplay_world/world.hpp').read_text()
    result = dict(schema=1,status='qualified native actor quantity/release/remap callers with one canonical World action notice',game_launched=False,installed_in_game=False,stage4_complete=False,source_sha256=source,cohorts=cohorts,parent_checks=parents,current_world_regressions=worlds,current_primitive_regressions=primitives,limitations=[
        'Other World frame services and final action-notice delivery remain declared seams in the16 native composition cases;12 actual publication observations include failure attempts.',
        'Quantity result2 handling is preserved but actual admitted lower operations produce0/1/3; transfer mask27 records0/1/3/-1, not a fabricated result2 producer.',
        'Native claim/lifecycle/audio/resource comparisons retain their separately declared ports and admission limits. Null/stale/foreign/reached unavailable capabilities refuse.',
        'Higher-level acquisition/transfer/peer cleanup, authority statistics/final message/UI delivery, action/AI dispatch and coherent game installation remain open.'
    ])
    target.write_text(json.dumps(result,indent=2)+'\n')
    print(sha(target))


if __name__ == '__main__':
    main()
