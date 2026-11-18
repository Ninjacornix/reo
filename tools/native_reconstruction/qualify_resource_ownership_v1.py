"""Seal native resource claim/assignment/exchange with actual lifecycle owners."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT / 'tools/native_reconstruction/native_resource_ownership_qualification_v1.json'
    assert not target.exists()
    source, cohorts, parents, vms = {}, {}, {}, {}
    expected = None
    for cc in ['llvm', 'gcc']:
        path = ROOT / f'build-native-sjuni/resource-ownership-{cc}-v2/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged']
        observed = receipt['observed']
        assert observed['checks'] == 322792673 and observed['ownership_claims'] == 590081
        assert observed['ownership_admissions'] == 393216
        assert all(observed[name] == 394752 for name in ['ownership_assignments','ownership_swaps','ownership_exchanges'])
        assert observed['ownership_capacity'] == 4 and observed['ownership_refusals'] == 9
        assert observed['heap_allocations'] == observed['heap_releases'] == 77024
        assert expected is None or expected == observed
        expected = observed
        assert all(any(row['start'] == hex(at) for row in receipt['original_owned_bodies']) for at in [0x593060,0x5f2210,0x5b15d0,0x5b1610,0x5b1670,0x5b16d0,0x5b1710,0x5b1760,0x5b1bf0,0x5b1de0])
        for name, digest in receipt['source_sha256'].items():
            assert sha(ROOT / name) == digest, name
            assert name not in source or source[name] == digest, name
            source[name] = digest
        cohorts[cc] = dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path), observed=observed)
        for kind in ['parent', 'tests']:
            path = ROOT / f'build-native-sjuni/stage4-resource-ownership-{kind}-{cc}-v1.log'
            raw = path.read_bytes()
            value = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 8' in value) if kind == 'tests' else ('FAILED:' not in value and 'error:' not in value)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
        path = ROOT / f'build-native-sjuni/resource-ownership-vm-{cc}-v1/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and not receipt['pinned_shared_sources']
        assert receipt['result']['checks'] == 14080853
        for name, digest in receipt['source_sha256'].items():
            assert sha(ROOT / name) == digest, name
        vms[cc] = dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),checks=receipt['result']['checks'],original_dispatch_invocations=receipt['result']['original_dispatch_invocations'])
    source['game/native/gameplay_world/CMakeLists.txt'] = sha(ROOT / 'game/native/gameplay_world/CMakeLists.txt')
    result = dict(schema=1,status='qualified native resource claims, primary admission, owner assignment, owned swap and world exchange with actual lifecycle consumers',game_launched=False,installed_in_game=False,stage4_complete=False,source_sha256=source,cohorts=cohorts,parent_checks=parents,current_vm_regressions=vms,limitations=[
        'Primary admission only; extended actors and unavailable scenario/profile/model capabilities refuse after their known prefix.',
        'Actual world exchange shape lookup admits the bounded eight-row/seven-column profile; the current factory has its separately documented admission limits.',
        'Complete original callers/query and real native lifecycle consumers execute; bounded copies/floor and other previously declared ports remain explicit.',
        'Higher-level pickup/peer/journal/statistics/network/UI consumers, authored saved-placement producers, semantic World save/load and coherent game installation remain open.'
    ])
    target.write_text(json.dumps(result,indent=2)+'\n')
    print(sha(target))


if __name__ == '__main__':
    main()
