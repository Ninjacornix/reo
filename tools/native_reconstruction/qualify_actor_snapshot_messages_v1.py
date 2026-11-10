"""Seal canonical actor snapshot publication and shared suppression."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    target = ROOT / 'tools/native_reconstruction/native_actor_snapshot_message_qualification_v1.json'
    assert not target.exists()
    source, cohorts, parents = {}, {}, {}
    expected = None
    for cc, version in [('llvm', 2), ('gcc', 1)]:
        path = ROOT / f'build-native-sjuni/actor-snapshot-message-{cc}-v{version}/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged']
        observed = receipt['observed']
        assert observed['checks'] == 73525738 and observed['actor_snapshot_cases'] == 589824
        assert observed['actor_snapshot_messages'] == 231191 and observed['actor_snapshot_lookups'] == 116867
        assert observed['actor_snapshot_refusals'] == 10 and observed['actor_snapshot_frames'] == 2
        assert expected is None or expected == observed
        expected = observed
        for name, digest in receipt['source_sha256'].items():
            assert sha(ROOT / name) == digest, name
            assert name not in source or source[name] == digest
            source[name] = digest
        cohorts[cc] = dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path), observed=observed,
                           word_audits=receipt['original_word_audits'])
        for kind in ['parent', 'tests']:
            path = ROOT / f'build-native-sjuni/actor-snapshot-{kind}-{cc}-v1.log'
            raw = path.read_bytes()
            value = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 8' in value) if kind == 'tests' else ('FAILED:' not in value and 'error:' not in value)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
    result = dict(schema=1, status='qualified canonical actor snapshot message selector1 and shared suppression',
                  game_launched=False, installed_in_game=False, stage4_complete=False,
                  source_sha256=source, cohorts=cohorts, parent_checks=parents, limitations=[
        'Complete67E230 executes selector1 and actual664D00/667F90/668C80 helpers. Typed fields preserve raw float XYZ, action/status/health/resources, signed aiming angles, low room byte and selected gauge band.',
        'Primary item ID C80, pitch BC8/CD4 and target index CDC have separate canonical optional fields. Owned source provenance is word-audited; their real producers/import and gameplay meaning beyond the documented mechanical roles remain open.',
        'Category1 alone initializes the low model-variant byte. Other category data and original untouched stack padding are not invented into a native wire format.',
        'Payload capture and shared744638=1 commit before mapped-room lookup; lookup mutation retains captured fields and rereads mode before send. Recursive selector1 requests are suppressed. Two native World frames demonstrate the same canonical reset and Owner facade; remaining frame providers are declared.',
        'Missing state refuses after classification before suppression; missing/rejected final consumers retain suppression. Queue, receiver, transport, remaining selectors3/5/6/8/9/11 and installation remain open.',
        'The old verifier metadata incorrectly called selector1 a float-conversion path. The actual conversions belong to selector5. New metadata corrects that statement; immutable older receipts remain unchanged.',
        'InstalledV39 is unchanged. This is not whole Stage4 or a measured slowdown fix.'
    ])
    target.write_text(json.dumps(result, indent=2) + '\n')
    print(sha(target))


if __name__ == '__main__':
    main()
