"""Seal contact snapshots from canonical native hit and collision state."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT / 'tools/native_reconstruction/native_actor_contact_snapshot_qualification_v1.json'
    assert not target.exists()
    sources, cohorts, parents = {}, {}, {}
    expected = None
    for cc, version in [('llvm', 3), ('gcc', 1)]:
        path = ROOT / f'build-native-sjuni/actor-contact-snapshot-{cc}-v{version}/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged']
        observed = receipt['observed']
        for key, value in dict(checks=85601086, contact_snapshot_cases=589840,
                               contact_snapshot_messages=258305, contact_snapshot_lookups=131074,
                               contact_snapshot_refusals=13, contact_snapshot_recursions=13597).items():
            assert observed[key] == value, key
        assert expected is None or observed == expected
        expected = observed
        for name, digest in receipt['source_sha256'].items():
            assert sha(ROOT / name) == digest, name
            assert name not in sources or sources[name] == digest
            sources[name] = digest
        for name, digest in receipt['output_sha256'].items():
            assert sha(path.parent / name) == digest, name
        cohorts[cc] = dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path), observed=observed)
        for kind in ['parent', 'tests']:
            path = ROOT / f'build-native-sjuni/actor-contact-snapshot-{kind}-{cc}-v1.log'
            raw = path.read_bytes()
            text = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 8' in text) if kind == 'tests' else ('FAILED:' not in text and 'error:' not in text)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
    target.write_text(json.dumps(dict(schema=1, status='qualified canonical actor contact snapshots and selector5 publication',
        game_launched=False, installed_in_game=False, stage4_complete=False,
        source_sha256=sources, cohorts=cohorts, parent_checks=parents, limitations=[
            'Complete67E230 selector5 executes, including finite signed32 truncation followed by low16 position, raw status, selected gauge band, capture before mapped lookup and suppression5 before dispatch. Unknown stack padding is omitted from the native typed contract.',
            'Source identity11C, direction12C, source-related14A/14B, response/region141/13E and auxiliary14C are read from the existing canonical collision Component. Health/status/source/response bytes reuse HitActor; no parallel contact state is introduced.',
            'The raw original source pointer is compared through an explicit null/sender/peer identity map. Native messages carry generation-checked EntityId values, never guest addresses. This does not claim an external wire encoding or arbitrary raw-pointer admission.',
            '589840 cases cover action/yaw/health/response byte domains, finite position boundaries including signed32 extremes and low16 wrapping, raw direction bits, phase/category/status/suppression gates, mapped callback mutation, selected-peer gauges, actual UpdateOwner and recursive suppression. Thirteen refusal groups preserve the measured mutation prefix.',
            'Both compiler cohorts rerun the prior cooperative/event/gauge/snapshot/alignment and complete contact alignment math-chain matrices with identical observations. Parent builds and eight integration checks pass on each compiler.',
            'Messages3/8/9/11, actual queue/receiver/transport, remaining hit/action callers, semantic saves and installation/acceptance remain open. InstalledV39 is unchanged; this is not whole Stage4 or a measured slowdown fix.'
        ]), indent=2) + '\n')
    print(sha(target))


if __name__ == '__main__':
    main()
