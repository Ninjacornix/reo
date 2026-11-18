"""Seal the World-owned ten-actor pool, reservations and identifier lookups."""
import hashlib
import json
import subprocess
from pathlib import Path
ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT / 'tools/native_reconstruction/native_auxiliary_actor_pool_qualification_v1.json'
    assert not target.exists()
    sources, cohorts, parents = {}, {}, {}
    expected = None
    for cc, version in [('llvm', 2), ('gcc', 1)]:
        path = ROOT / f'build-native-sjuni/auxiliary-actor-pool-{cc}-v{version}/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged']
        observed = receipt['observed']
        for key, value in dict(checks=89918019, auxiliary_pool_cases=6656,
            auxiliary_pool_lookups=267776, auxiliary_pool_reuses=2560,
            auxiliary_pool_refusals=5378, auxiliary_pool_lifetimes=4).items():
            assert observed[key] == value, key
        assert expected is None or expected == observed
        expected = observed
        inputs = [receipt]
        cohorts[cc] = dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path), observed=observed)
        for kind in ['world', 'behavior']:
            path = ROOT / f'build-native-sjuni/auxiliary-pool-{kind}-{cc}-v1/receipt.json'
            regression = json.loads(path.read_bytes())
            if kind == 'world':
                assert regression['original_body_executed'] and regression['source_unchanged']
                assert regression['observed'] == dict(cases=4096, ordered_calls=291127,
                    original_body_executed=True, game_run=False,
                    native_lifetime=dict(checks=81, status='passed', game_run=False))
            else:
                assert regression['status'] == 'passed' and regression['full_original_behavior_body']
                assert regression['result'] == dict(status='passed', cases=32768, trace_words=2572551)
            cohorts[cc][kind] = dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path), observed=regression.get('observed', regression.get('result')))
            inputs.append(regression)
        for item in inputs:
            for name, digest in item['source_sha256'].items():
                assert sha(ROOT / name) == digest, name
                assert name not in sources or sources[name] == digest
                sources[name] = digest
        for kind in ['parent', 'tests']:
            path = ROOT / f'build-native-sjuni/auxiliary-pool-{kind}-{cc}-v1.log'
            raw = path.read_bytes()
            text = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 8' in text) if kind == 'tests' else ('FAILED:' not in text and 'error:' not in text)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
    drivers = ['effect_work_sources.py', 'gameplay_update_sources.py', 'verify_gameplay_world.py', 'verify_resource_frames.py'] + ['animation/verify_'+name+'.py' for name in ['attachments','constrained_attachments','ground_constraints','model_poses','primitives','world_playback','linked_models']]
    deltas = {}
    for driver in drivers:
        name = 'tools/native_reconstruction/' + driver
        previous = subprocess.run(['git','show','b31e9689:'+name],cwd=ROOT,check=True,capture_output=True).stdout.decode()
        current = (ROOT/name).read_text()
        normalized = current.replace(",'gameplay_world/auxiliary_actors.cpp'", '').replace(",'auxiliary_actors'", '')
        assert normalized == previous, name
        sources[name] = sha(ROOT/name)
        deltas[name] = dict(previous_commit='b31e9689', previous_sha256=hashlib.sha256(previous.encode()).hexdigest(), current_sha256=sources[name], change='add required auxiliary_actors.cpp link unit only')
    target.write_text(json.dumps(dict(schema=1, status='qualified canonical ten-actor auxiliary pool and lookups',
        game_launched=False, installed_in_game=False, stage4_complete=False,
        source_sha256=sources, cohorts=cohorts, parent_checks=parents, driver_dependency_deltas=deltas, limitations=[
            'Complete682C60/682D10/682E30,666640/682F80 and683B10 execute against the pinned owned overlay. Native World owns one distinct ten-actor pool; the existing fifty-model pool retains independent budget and membership while sharing canonical Actor storage.',
            '256 epochs compare allocation ends, full refusal, list links/endpoints, all stored slot-byte values, LIFO physical reuse and reset.267776 lookups cover active/unfiltered first match, every low16 identifier and unmasked high-word rejection. Four attachment reservations are independent of actor allocation and clear with reset.',
            '2560 reuses preserve the source slot-byte contract but retire native EntityIds permanently. Retained invocation leases keep the old native Actor value; no physical guest-memory clearing or pointer-alias reuse is promised. Unresolved scene/model and phase-qualified alignment capabilities remain unavailable until actual constructors/producers supply them.',
            '5378 explicit native refusal checks cover pool/full, protected generic retirement, stale/double/foreign identities and entity generation/capacity exhaustion. Four lifetime compositions cover the independent50-model budget, reset, busy destruction reentry and World shutdown.',
            'Both compilers pass89918019 combined checks with identical observations, fresh4096-case World/81-lifetime and32768-case behavior regressions, and all eight parent checks. Eleven comparison-driver edits are verified as dependency additions only against the preceding commit.',
            'Real auxiliary template/resource/model construction, attachment release/asset ownership, actor callbacks/AI/movement, peer-message binding, semantic saves and installed-game acceptance remain open. InstalledV39 is unchanged; this is not whole Stage4 or a measured slowdown fix.'
        ]), indent=2) + '\n')
    print(sha(target))


if __name__ == '__main__':
    main()
