"""Seal canonical control/hit aliases, room release and scheduler composition."""
import hashlib
import json
from pathlib import Path
ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT/'tools/native_reconstruction/native_actor_room_control_qualification_v1.json'
    assert not target.exists()
    sources, cohorts, parents, expected = {}, {}, {}, {}
    for cc in ['llvm', 'gcc']:
        specs = [
            ('control', f'actor-room-control-{cc}-v5', dict(checks=130381631,
                room_release_cases=196608, room_release_messages=271,
                room_hold_cases=65537, room_transition_cases=65419,
                room_control_refusals=123, room_control_hit_aliases=8192,
                room_response_aliases=256)),
            ('reception', f'actor-room-control-reception-{cc}-v2', dict(checks=44260363,
                reception_cases=729088, reception_queue_cases=154,
                reception_equipment=257, reception_auxiliary_cases=65536,
                reception_speech_cases=131072, reception_presence_cases=65536)),
            ('vm', f'actor-control-alias-vm-{cc}-v2', dict(checks=14080853,
                actor_request_consumers=84160, actor_request_dispatches=1280,
                actor_request_profile_refusals=48192)),
            ('update', f'actor-control-alias-update-{cc}-v2', dict(cases=2048,
                phase_cases=4096, hold_phase_cases=241, native_owner_checks=22,
                audio_tick_cases=12)),
        ]
        for kind, directory, metrics in specs:
            path = ROOT/'build-native-sjuni'/directory/'receipt.json'
            receipt = json.loads(path.read_bytes())
            assert receipt['status'] == 'passed'
            if 'source_unchanged' in receipt:
                assert receipt['source_unchanged']
            assert not receipt.get('pinned_shared_sources') and not receipt.get('scenario_source_commit')
            observed = receipt.get('observed', receipt.get('result'))
            for name, value in metrics.items():
                assert observed[name] == value, (kind, name, observed[name], value)
            assert kind not in expected or expected[kind] == observed
            expected[kind] = observed
            for name, digest in receipt['source_sha256'].items():
                assert sha(ROOT/name) == digest, name
                assert name not in sources or sources[name] == digest
                sources[name] = digest
            for name, digest in receipt.get('original_sources_sha256', {}).items():
                assert sha(ROOT/name) == digest, name
            for name, digest in receipt.get('output_sha256', {}).items():
                assert sha(path.parent/name) == digest, name
            if kind in ['vm', 'update']:
                binary = path.parent/('checks.exe' if kind == 'vm' else 'native-update.exe')
                assert sha(binary) == receipt['executable_sha256']
            cohorts[f'{cc}-{kind}'] = dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path), observed=observed)
        for kind in ['parent', 'tests']:
            path = ROOT/f'build-native-sjuni/actor-room-control-{kind}-{cc}-v2.log'
            raw = path.read_bytes()
            text = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 8' in text) if kind == 'tests' else ('FAILED:' not in text and 'error:' not in text)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
    target.write_text(json.dumps(dict(schema=1,status='qualified native room release, shared control aliases and hold-to-scheduler composition',
        game_launched=False,installed_in_game=False,stage4_complete=False,
        source_sha256=sources,cohorts=cohorts,parent_checks=parents,limitations=[
            'Complete6696C0 and1B0010 execute with811B30/811300 request branches at a2==0. Both immutable o8/o9 images are hash-pinned and word-audited. The a2!=0 membership mutation and real control transport/receiver remain open. No live user network or game process is accessed.',
            'Room release uses checked canonical primary room/selected state and typed channel7 control messages. Offline helper only admits slot0, online helper slots0..3, rooms0..127 and the local slot. Other raw modes are no-ops. Actor message phase/pause/status/suppression do not gate this independent source control path.',
            'Canonical BD0 is inherited HitActor.response_lock, also used by script/control cleanup. Canonical AD4 is inherited transient_equipment, also the script ControlRequest pending byte. Removed duplicate control_pending and ControlRequest.pending storage. Both compiler full VM runs compare84160 consumers and1280 actual opcode dispatches, while8192 real World/behavior/hit cases cancel queued AD4 requests and256 script-to-hit cases preserve the BD0 early return.',
            'Canonical3243D8 exit_requested moved from Update.State to the shared World Session. Actor hold and outer scheduler use the same value. Both compiler update comparisons include4096 phases and241 actual native hold-producer-to-phase cases, plus2048 worker cases and12 audio-clock caller checks. Default state semantics remain the existing zero-initialized exit request.',
            '64EF10 local and ordinary-mode special branches now bind actual native hold/room release. The source retains BD0 in the nonlocal nonzero-mode branch; a failed intermediate implementation cleared it and was rejected by comparison. Current observations match on both compilers, including65419 special-branch cases and196608 release cases.',
            'Offline nonlocal668F20 scene reconstruction, helper membership application, real external control transport/authentication/encoding, higher actor/AI/VM consumers, native semantic saves and coherent game installation/acceptance remain open. InstalledV39 remains unchanged. No completed Stage4 or measured slowdown fix is claimed.'
        ]),indent=2)+'\n')
    print(sha(target))


if __name__ == '__main__':
    main()
