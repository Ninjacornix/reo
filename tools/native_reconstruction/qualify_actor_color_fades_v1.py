"""Seal native actor fades, real frame consumption and admitted offline resume."""
import hashlib
import json
from pathlib import Path
ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT/'tools/native_reconstruction/native_actor_color_fade_qualification_v1.json'
    assert not target.exists()
    sources, cohorts, parents, expected = {}, {}, {}, {}
    for cc in ['llvm', 'gcc']:
        for kind in ['fade', 'reception']:
            path = ROOT/(f'build-native-sjuni/actor-color-fade-{cc}-v2/receipt.json' if kind == 'fade' else f'build-native-sjuni/actor-color-fade-reception-{cc}-v2/receipt.json')
            receipt = json.loads(path.read_bytes())
            assert receipt['status'] == 'passed' and receipt['source_unchanged']
            observed = receipt['observed']
            metrics = dict(checks=138634664,color_fade_cases=1775616,
                color_fade_refusals=7,color_fade_finish_cases=65536,
                color_fade_frame_cases=4096,offline_resume_cases=1756,
                offline_resume_refusals=38,room_transition_cases=65442) if kind == 'fade' else dict(
                checks=44260363,reception_cases=729088,reception_equipment=257,
                reception_refusals=8,reception_queue_cases=154,
                reception_auxiliary_cases=65536,reception_speech_cases=131072,
                reception_presence_cases=65536,reception_speech_refusals=7)
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
            path = ROOT/f'build-native-sjuni/actor-color-fade-{kind}-{cc}-v2.log'
            raw = path.read_bytes()
            text = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 8' in text) if kind == 'tests' else ('FAILED:' not in text and 'error:' not in text)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
    target.write_text(json.dumps(dict(schema=1,status='qualified native actor color fades and admitted offline resume',
        game_launched=False, installed_in_game=False, stage4_complete=False,
        source_sha256=sources,cohorts=cohorts,parent_checks=parents,
        prior_alias_qualification=dict(path='tools/native_reconstruction/native_actor_room_control_qualification_v1.json',sha256=sha(ROOT/'tools/native_reconstruction/native_actor_room_control_qualification_v1.json'),scope='Retained earlier VM/outer-update alias qualification, not a claimed rerun with this additional fade field'),limitations=[
            'Complete6655F0/665640/665690/6656E0/665730 execute against owned originals. Canonical ColorFade owns primary actor CE8 color,CEC step andCF0 update count only within the established fade role. Other actor families reuse source offsets for unrelated meanings and do not grant this native capability.',
            'Nonzero start duration preserves low-byte alpha, integer quotient before high-byte shift and original auxiliary flag writes. Zero divisor is an explicit native preflight refusal without effects, not a claimed physical PS2 division profile. Advance preserves full unsigned wrapping, including count0 underflow, and source expiry colors/flag masks.',
            'Complete6655F0 gives increase4000 priority over decrease8000. Native ColorFadeFrameServices owns the actual World finish_actor point after grid work and before action notice publication.4096 real World updates and missing-state refusal verify the same canonical actor; other frame/AI/pose effects remain declared required providers.',
            '668F20 is admitted for original early no-op gates and when complete819880 rejects before scene work due status8/80. Canonical BD0 clears before scene selection, off-room paths hide the actor and reset the actual fade owner, then preserve source status/action/pose ordering. Actual successful scene/navigation reconstruction remains unavailable rather than skipped.',
            'Both compiler observations match across1775616 fade cases,65536 finish-policy cases,4096 World frame compositions and1756 offline resume comparisons. Updated interaction/room/alias regressions and focused receiver/equipment/queue checks pass with current sources. Parent builds and all eight integration checks pass per compiler.',
            'Prior full VM and outer update comparisons are retained at the linked control-alias qualification. They are not claimed rerun for this isolated fade addition. Actual renderer color submission belongs to Stage5; successful offline navigation/scene reconstruction, remaining actor/action/AI/VM consumers, semantic saves, external transport and coherent game installation/acceptance remain open. V39 is unchanged and Stage4 remains incomplete; no game/performance fix is claimed.'
        ]), indent=2)+'\n')
    print(sha(target))


if __name__ == '__main__':
    main()
