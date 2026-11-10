"""Seal auxiliary lists and actor bank transfer through canonical resources."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT / 'tools/native_reconstruction/native_resource_auxiliary_lists_qualification_v1.json'
    assert not target.exists()
    source, cohorts, parents = {}, {}, {}
    expected = None
    for cc in ['llvm', 'gcc']:
        path = ROOT / f'build-native-sjuni/resource-auxiliary-lists-{cc}-v2/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged']
        observed = receipt['observed']
        assert observed['checks'] == 582692210 and observed['auxiliary_list_cases'] == 294912
        assert observed['auxiliary_transfer_cases'] == 393216 and observed['auxiliary_live_cases'] == 48
        assert observed['auxiliary_truncation_cases'] == 1 and observed['auxiliary_refusals'] == 8
        assert observed['heap_allocations'] == observed['heap_releases'] == 89072
        assert expected is None or expected == observed
        expected = observed
        cohorts[cc] = dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path), observed=observed)
        path = ROOT / f'build-native-sjuni/resource-auxiliary-clock-{cc}-v1/receipt.json'
        clock = json.loads(path.read_bytes())
        assert clock['status'] == 'passed' and clock['source_unchanged']
        assert clock['observed']['checks'] == 70212138 and clock['observed']['hit_gauge_cases'] == 8192
        cohorts[cc]['clock'] = dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path), observed=clock['observed'])
        for item in [receipt, clock]:
            for name, digest in item['source_sha256'].items():
                assert sha(ROOT / name) == digest, name
                assert name not in source or source[name] == digest, name
                source[name] = digest
        for kind in ['parent', 'tests']:
            path = ROOT / f'build-native-sjuni/stage4-resource-auxiliary-{kind}-{cc}-v1.log'
            raw = path.read_bytes()
            value = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 8' in value) if kind == 'tests' else ('FAILED:' not in value and 'error:' not in value)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
    name = 'game/native/gameplay_world/CMakeLists.txt'
    assert 'resource_auxiliary_lists.cpp' in (ROOT / name).read_text()
    source[name] = sha(ROOT / name)
    result = dict(schema=1, status='qualified session auxiliary resource lists and actor inventory transfer with real model release',
                  game_launched=False, installed_in_game=False, stage4_complete=False,
                  source_sha256=source, cohorts=cohorts, parent_checks=parents, limitations=[
        'Complete5B5F10/5B6180/5B6300/5F6800 execute through actual template/descriptor/frame consumers. First four signed-index player lists are admitted; other indices and invalid groups refuse rather than modeling adjacent globals or stack corruption.',
        'The Session owns four eight-ID lists independently of entity lifetime. Accepted input count and claim clearing can exceed the eight emitted IDs; no deduplication, ownership reset or resource destruction is invented.',
        'Actor bank transfer preserves selected model detachment before transferred-bit/first-slot gates, carried-before-character6 storage order, both bank clears and D92 journal timing. Forty-eight cases include actual primary/shared-secondary retirement.',
        'A prior shared test context change duplicated HI/LO in other generators. The shared header is restored and cooperative tests add HI/LO only to their generated context; both complete resource and clock/hit comparisons pass with current inputs.',
        'Other auxiliary producers/consumers, initialization/semantic save/load, terminal and periodic-gauge transition binding, other gameplay owners and coherent native game installation/acceptance remain open. InstalledV39 is unchanged.'
    ])
    target.write_text(json.dumps(result, indent=2) + '\n')
    print(sha(target))


if __name__ == '__main__':
    main()
