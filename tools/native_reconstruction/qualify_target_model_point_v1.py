"""Seal independent native linked model-point and motion-style ownership."""
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


def sha(path):
    import hashlib
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    records = []
    references = []
    logs = {}
    for compiler in ('llvm', 'gcc'):
        path = ROOT / 'build-native-sjuni' / f'target-model-point-{compiler}-v1/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged']
        assert all(sha(ROOT / name) == digest for name, digest in receipt['source_sha256'].items())
        for name, digest in receipt['output_sha256'].items():
            assert sha(path.parent / name) == digest
        assert not receipt['game_launched'] and not receipt['installed_in_game']
        records.append(receipt)
        references.append(dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path)))
        for kind in ('parent', 'tests'):
            log = ROOT / 'build-native-sjuni' / f'target-model-point-{kind}-{compiler}-v1.log'
            raw = log.read_bytes()
            text = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            if kind == 'tests':
                assert '100% tests passed, 0 tests failed out of 4' in text
            else:
                assert 'FAILED:' not in text and 'error:' not in text
            logs[log.relative_to(ROOT).as_posix()] = sha(log)
    first, second = records
    assert first['source_sha256'] == second['source_sha256']
    assert first['observed'] == second['observed']
    observed = first['observed']
    assert observed['checks'] == 5781403 and observed['refusals'] == 5
    assert observed['profiles'] == 192 and observed['strict_profiles'] == 75
    document = ROOT / 'docs/native-gameplay/TARGET_METRICS.md'
    prior = ROOT / 'tools/native_reconstruction/native_target_metrics_worker_qualification_v1.json'
    record = dict(
        schema=1, status='qualified_partial_native_target_model_point_correction',
        game_launched=False, installed_in_game=False, stage4_complete=False,
        source_sha256=first['source_sha256'], receipts=references, observed=observed,
        original_word_audits=first['original_word_audits'], parent_logs_sha256=logs,
        documentation_and_tools_sha256={p.relative_to(ROOT).as_posix(): sha(p) for p in (document, Path(__file__))},
        previous_qualification=dict(path=prior.relative_to(ROOT).as_posix(), sha256=sha(prior)),
        limitations=[
            'The previous native algorithm and fixture incorrectly shared B99 motion style with the 551 linked model-point selector.',
            'The revised native owner and fixture supply independent values and explicit unknown-index refusal.',
            'Original scratch-read limitations and declared heading/geometry comparison ports retain their existing scope.',
            'Real model-point construction, game caller installation and full Step 4 acceptance remain open.',
        ])
    output = ROOT / 'tools/native_reconstruction/native_target_model_point_qualification_v1.json'
    with output.open('x', encoding='utf-8') as target:
        target.write(json.dumps(record, indent=2) + '\n')
    print(json.dumps(dict(path=str(output), sha256=sha(output), observed=observed)))


if __name__ == '__main__':
    main()
