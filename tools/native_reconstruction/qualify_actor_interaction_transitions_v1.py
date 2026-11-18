"""Seal the admitted native interaction state-selection branch and queue composition."""
import hashlib
import json
from pathlib import Path
ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT/'tools/native_reconstruction/native_actor_interaction_transition_qualification_v1.json'
    assert not target.exists()
    sources, cohorts, parents, expected = {}, {}, {}, {}
    for cc in ['llvm', 'gcc']:
        for kind in ['transition', 'reception']:
            path = ROOT/(f'build-native-sjuni/actor-interaction-transition-{cc}-v2/receipt.json' if kind == 'transition' else f'build-native-sjuni/actor-interaction-transition-reception-{cc}-v1/receipt.json')
            receipt = json.loads(path.read_bytes())
            assert receipt['status'] == 'passed' and receipt['source_unchanged']
            observed = receipt['observed']
            metrics = dict(checks=129184625, interaction_transition_cases=123714,
                interaction_transition_refusals=44226, interaction_transition_owner_cases=3) if kind == 'transition' else dict(
                checks=44260363, reception_cases=729088, reception_equipment=257,
                reception_refusals=8, reception_queue_cases=154,
                reception_auxiliary_cases=65536, reception_speech_cases=131072,
                reception_presence_cases=65536, reception_speech_refusals=7)
            for name, value in metrics.items():
                assert observed[name] == value, (name, observed[name], value)
            assert kind not in expected or expected[kind] == observed
            expected[kind] = observed
            for name, digest in receipt['source_sha256'].items():
                assert sha(ROOT/name) == digest, name
                assert name not in sources or sources[name] == digest
                sources[name] = digest
            for name, digest in receipt['output_sha256'].items():
                assert sha(path.parent/name) == digest, name
            cohorts[f'{cc}-{kind}'] = dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path), observed=observed)
        for kind in ['parent', 'tests']:
            path = ROOT/f'build-native-sjuni/actor-interaction-transition-{kind}-{cc}-v1.log'
            raw = path.read_bytes()
            text = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 8' in text) if kind == 'tests' else ('FAILED:' not in text and 'error:' not in text)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
    target.write_text(json.dumps(dict(schema=1,status='qualified admitted native interaction state-selection branch',
        game_launched=False, installed_in_game=False, stage4_complete=False,
        source_sha256=sources, cohorts=cohorts, parent_checks=parents, limitations=[
            'This is the admitted table-driven64EF10 branch, not complete64EF10 migration. Complete original64EF10 and667370 are word-audited; executed cases avoid the unimplemented room/network transition branch. Unsupported profiles refuse after canonical AB8 pending consumption instead of invoking generated code or pretending completion.',
            'Explicit711890 fifty-row/two-column prefix is compared byte-for-byte with the owned overlay. No inferred source bound or unchecked neighboring-table access is admitted. Selector narrows to its low byte. Kind0, status80 rejection set and repeated snapshot/special kind1/2 parameter behavior match executed source.',
            'Both compiler observations match across123714 source comparison cases and44226 native refusal checks, plus129184625 combined sender/event/gauge/hit/pool checks. Unknown request, invalid/closed identity and owner closure preserve their declared prefixes. Actual native Owner facade operates on the canonical World and saved action pose.',
            'Both compiler focused receiver compositions pass44260363 checks including154 queue checks. Captured interaction delivery across Worlds now reaches the actual native transition consumer and saves the receiving pose. Existing receiver/equipment/auxiliary/speech/presence checks rerun; the unrelated full resource regression is retained at the previous request qualification rather than claimed rerun here.',
            'Parent builds and all eight integration checks pass per compiler. Actual primary frame action callers,64EF10 room/network branch, further request producers, remaining incoming/action/AI/VM families, native semantic saves, external transport and coherent game installation/acceptance remain open. V39 is unchanged and Stage4 remains incomplete; no game run or slowdown fix is claimed.'
        ]), indent=2)+'\n')
    print(sha(target))


if __name__ == '__main__':
    main()
