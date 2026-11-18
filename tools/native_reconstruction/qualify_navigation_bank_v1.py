"""Seal World/session/VM room variants and native navigation state ownership."""
import hashlib
import json
from pathlib import Path
ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT/'tools/native_reconstruction/native_navigation_bank_qualification_v1.json'
    assert not target.exists()
    sources, cohorts, parents, observed = {}, {}, {}, {}
    expected_bank = dict(checks=3354950,nearest_cases=26930,action_cases=265608,
        asset_rooms=166,asset_nodes=3334,asset_conditions=2167,asset_links=432,
        refusals=27155,nearest_refusals=26672,action_refusals=0,bindings=1920,
        clears=30,bank_cells=327680,bank_visit_cells=6912,bank_clears=20)
    for cc in ['llvm', 'gcc']:
        for kind in ['bank', 'vm']:
            path = ROOT/(f'build-native-sjuni/gameplay-navigation-bank-{cc}-v2/receipt.json' if kind == 'bank' else f'build-native-sjuni/room-variant-vm-{cc}-v2/receipt.json')
            receipt = json.loads(path.read_bytes())
            assert receipt['status'] == 'passed'
            result = receipt['observed'] if kind == 'bank' else receipt['result']
            assert kind not in observed or observed[kind] == result
            observed[kind] = result
            if kind == 'bank':
                assert result == expected_bank and receipt['source_unchanged']
                for name, digest in receipt['output_sha256'].items():
                    assert sha(path.parent/name) == digest, name
            else:
                for name, value in dict(checks=19719138,room_variant_handlers=32768,room_variant_dispatches=60,room_variant_refusals=7,room_variant_world_cases=4).items():
                    assert result[name] == value, name
                assert not receipt['pinned_shared_sources'] and not receipt['pinned_current_source_drift']
                assert sha(path.parent/'checks.exe') == receipt['executable_sha256']
            for section in ['source_sha256', 'original_sources_sha256']:
                for name, digest in receipt.get(section, {}).items():
                    assert sha(ROOT/name) == digest, name
                    assert name not in sources or sources[name] == digest
                    sources[name] = digest
            cohorts[f'{cc}-{kind}'] = dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),observed=result)
        for kind in ['parent', 'tests']:
            path = ROOT/f'build-native-sjuni/navigation-bank-{kind}-{cc}-v1.log'
            raw = path.read_bytes();text = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 9' in text) if kind == 'tests' else ('FAILED:' not in text and 'error:' not in text)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
    target.write_text(json.dumps(dict(schema=1,status='qualified native session room variants and World navigation bank',
        game_launched=False,installed_in_game=False,stage4_complete=False,source_sha256=sources,cohorts=cohorts,parent_checks=parents,limitations=[
            'RoomVariants is the sole native session owner of4B9D20. Unknown entries are distinct from0; explicit bounded initialization/import or real opcode5A writes supply values. This does not migrate the whole original session initializer or native save schema.',
            'Ordinary opcode5A uses the actual World session owner and low-byte value. Complete68ECA0 and actual68C660 dispatcher compare; the different offline handler is still unsupported. World-dependent programs reject missing/closed World capabilities before executing their prefix.',
            'The World owns one lazily constructed navigation Bank borrowing that same Session map, and seals it on close. Script writes do not automatically rebind graph selection. Actual bind rereads known variants and preserves last matching descriptor, clears all occupancy and retains visits for the same asset identity.',
            'Native mutable occupancy and four per-actor byte visit masks compare complete8194F0 across all five owned inputs,327680 occupancy cells and6912 visit cells. Different-asset load resets visits to its encoded initial bytes; clear-room/rebind preserves visits. Unknown required variants and invalid capacities refuse before effects.',
            'Full current-source VM suites pass19719138 checks per compiler, including32768 direct room-variant handlers,60 real dispatcher cases,4 real World navigation compositions and7 refusals. All nine current parent tests pass. No historical pins, live game, performance measurement or installation is claimed.',
            'Mode0/1 navigation bind callbacks, actual SGL loading, dynamic condition/edge/route/AI consumers, remaining script handlers, semantic snapshots and coherent game acceptance remain open. V39 is unchanged; Stage4 is incomplete.'
        ]),indent=2)+'\n')
    print(sha(target))


if __name__ == '__main__':
    main()
