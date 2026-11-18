"""Seal canonical gauge adjustment and actual cooperative threshold events."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT / 'tools/native_reconstruction/native_actor_gauge_effects_qualification_v1.json'
    assert not target.exists()
    source, cohorts, parents = {}, {}, {}
    expected = None
    for cc in ['llvm', 'gcc']:
        path = ROOT / f'build-native-sjuni/actor-gauge-effects-{cc}-v1/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged']
        observed = receipt['observed']
        assert observed['checks'] == 70103000 and observed['gauge_adjustment_cases'] == 720920
        assert observed['gauge_crossing_cases'] == 65536 and observed['gauge_effect_events'] == 216410
        assert observed['gauge_effect_refusals'] == 9 and observed['gauge_capacity_cases'] == 24
        assert observed['actor_activity_cases'] == 481 and observed['actor_state_messages'] == 231652
        assert expected is None or expected == observed
        expected = observed
        assert receipt['actor_gauge_admission'].startswith('Complete660060/667E90/668050/1B0340')
        assert receipt['gauge_near_cap_sha256'] == '908641cecebf7b83d4241737dd04971e2e1d656ae93a6f37919c274f4e260cec'
        for name, digest in receipt['source_sha256'].items():
            assert sha(ROOT / name) == digest, name
            assert name not in source or source[name] == digest, name
            source[name] = digest
        cohorts[cc] = dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path), observed=observed)
        for kind in ['parent', 'tests']:
            path = ROOT / f'build-native-sjuni/stage4-actor-gauge-effects-{kind}-{cc}-v1.log'
            raw = path.read_bytes()
            value = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 8' in value) if kind == 'tests' else ('FAILED:' not in value and 'error:' not in value)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
    result = dict(schema=1, status='qualified native actor gauge adjustment and threshold events through canonical update Owner',
                  game_launched=False, installed_in_game=False, stage4_complete=False,
                  source_sha256=source, cohorts=cohorts, parent_checks=parents, limitations=[
        'Complete660060/667E90/668050/1B0340 execute against owned instruction-word audits. Original668110 runs at its exact caller argument100; only its exact-integral owned-cap conversion is admitted, and its discarded pure return is not projected into native state.',
        'Thresholds50/70/90 produce only the first upward event21/22/23hex. Cap event24hex uses the same actual cooperative pool and bound update counter/room; priority rejection and full capacity retain original nonfailure behavior.',
        'BB6/BB8 are canonical modifier fields; the BBA view reuses linked_model_variant rather than introducing a duplicate. Gauge state remains optional until imported or produced.',
        'Missing capabilities preserve the measured ordering of earlier writes and event requests. Closed/unavailable event consumers are reported; they are not successful no-ops.',
        'Pending-hit and other real gauge callers, periodic667420 progression, gauge import, final queue/transport and coherent native gameplay installation/acceptance remain open. InstalledV39 is unchanged.'
    ])
    target.write_text(json.dumps(result, indent=2) + '\n')
    print(sha(target))


if __name__ == '__main__':
    main()
