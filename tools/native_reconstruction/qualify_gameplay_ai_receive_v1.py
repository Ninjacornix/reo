"""Seal bounded control packet application against complete source consumers."""
import hashlib
import json
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target=ROOT/'tools/native_reconstruction/native_gameplay_ai_receive_qualification_v1.json'
    assert not target.exists()
    sources,cohorts,parents,binaries={},{},{},{}
    observed=None
    for cc in ['llvm','gcc']:
        path=ROOT/f'build-native-sjuni/gameplay-ai-receive-{cc}-v1/receipt.json'
        receipt=json.loads(path.read_bytes());data=receipt['observed']
        assert receipt['status']=='passed' and receipt['source_unchanged']
        assert data==dict(checks=75024841,goal_cases=131072,action_cases=131072,phase_cases=256,
            finish_cases=65536,profile_cases=256,profile_refusals=4,copies=20,clears=40,
            control_membership_cases=64,control_register_cases=152,control_unregister_cases=44,
            control_lookup_cases=18432,control_request_cases=18432,control_publish_cases=66,
            control_apply_cases=4096,control_receive_cases=64516,control_receive_refusals=1020,
            activity_queries=4020602)
        assert any(port.startswith('1AFE70 controlled') for port in receipt['declared_ports'])
        assert observed is None or observed==data;observed=data
        for name,digest in receipt['source_sha256'].items():
            assert sha(ROOT/name)==digest,name
            assert name not in sources or sources[name]==digest
            sources[name]=digest
        for name,digest in receipt['output_sha256'].items():
            assert sha(path.parent/name)==digest,name
        cohorts[cc]=dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),observed=data)
        for kind in ['parent','tests']:
            path=ROOT/f'build-native-sjuni/gameplay-ai-receive-{kind}-{cc}-v1.log'
            raw=path.read_bytes();text=raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 12' in text) if kind=='tests' else ('FAILED:' not in text and 'error:' not in text)
            parents[path.relative_to(ROOT).as_posix()]=sha(path)
        for suffix in ['gameplay_update/gameplay_ai_owner_tests.exe','gameplay_update/libreo_native_gameplay_update.a',
            'gameplay_update/CMakeFiles/reo_native_gameplay_update.dir/ai.cpp.obj',
            'gameplay_ai/gameplay_ai_tests.exe','gameplay_ai/libreo_native_gameplay_ai.a',
            'gameplay_ai/CMakeFiles/reo_native_gameplay_ai.dir/control_requests.cpp.obj']:
            path=ROOT/f'build-native-sjuni/gameplay-native-{cc}-v1'/suffix
            binaries[path.relative_to(ROOT).as_posix()]=sha(path)
    for name in ['game/native/CMakeLists.txt','game/native/gameplay_world/world.hpp',
        'game/native/gameplay_update/ai.cpp','game/native/gameplay_update/ai_tests.cpp',
        'game/native/gameplay_update/update.hpp','game/native/gameplay_update/CMakeLists.txt',
        'tools/native_reconstruction/gameplay_update_sources.py','tools/native_reconstruction/effect_work_sources.py',
        Path(__file__).relative_to(ROOT).as_posix()]:sources[name]=sha(ROOT/name)
    prior=ROOT/'tools/native_reconstruction/native_gameplay_ai_controls_qualification_v1.json'
    target.write_text(json.dumps(dict(schema=1,status='qualified bounded native control payload/ownership receiver',
        game_launched=False,installed_in_game=False,stage4_complete=False,source_sha256=sources,
        cohorts=cohorts,parent_checks=parents,qualified_binaries=binaries,
        prior_controls=dict(path=prior.relative_to(ROOT).as_posix(),sha256=sha(prior)),limitations=[
            'Both compilers pass75024841 identical checks. Full681820 application compares4096 calls across every encoded index, modes0/1/2/255 and activity results-1/0/1/2. Full6818D0 framing compares64516 admitted calls across all256 mode and length-byte values;1020 unsafe length-underflow profiles refuse. All preceding state/control producer comparisons retain their counts.',
            'Payload mode0 writes exactly four canonical registration bytes and masks the encoded index to six bits, including inactive registrations. Owner mode1 writes one owner-tag byte only when the external activity-mode result is zero. Other modes ignore the payload. Native optional mode facts refuse only when required for a nonempty owner update. Empty batches and value-only messages do not invent a dependency on unknown mode state.',
            'Nonzero packet modes use floor((length-4)/2) entries; odd trailing bytes are ignored as in the source. Mode0 follows its fixed single five-byte payload independently of the length byte. Native physical extents and underflow are checked before effects. Malformed input is an explicit bounded admission boundary, not an emulated original out-of-bounds result or a claimed valid outer network packet.',
            '1AFE70 is a declared controlled read-only external activity-mode result in this oracle, observed4020602 times. Its full main/overlay mode-provider and live producer are not claimed migrated. No success-returning packet/geometry double substitutes for681820/6818D0: their complete word-audited instructions execute.',
            'Both current parent builds and twelve integration tests pass. Actual Owner applies to the SAME Session registrations, verifies payload values and owner changes, refuses missing required mode, ignores mode1 writes when activity is nonzero, affects subsequent publisher admission and refuses after World closure.',
            'The service/outgoing transport, complete activity-mode provider, acknowledgements/reset/frame integration, full AI initialization/observations/dispatch and coherent native gameplay acceptance remain open. Installed V39 is unchanged; no game or performance test occurred.'
        ]),indent=2)+'\n')
    print(sha(target))


if __name__=='__main__':
    main()
