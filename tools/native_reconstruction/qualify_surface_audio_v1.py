"""Seal native surface audio comparisons and their explicit reused boundaries."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    sources, copies, cohorts = {}, {}, {}
    previous = None
    for compiler, version in [('llvm', 'v3'), ('gcc', 'v2')]:
        p = ROOT / 'build-native-sjuni' / f'surface-audio-frontends-{compiler}-{version}/receipt.json'
        r = json.loads(p.read_bytes())
        assert r['status'] == 'passed' and not r['source_drift']
        if previous:
            assert r['source_sha256'] == previous['source_sha256'] and r['results'] == previous['results']
        previous = r
        for name, digest in r['source_sha256'].items():
            frozen = p.parent / 'source' / name
            assert sha(ROOT / name) == digest and sha(frozen) == digest, name
            sources[name] = digest
            copies[name] = {'path': frozen.relative_to(ROOT).as_posix(), 'sha256': digest}
        for name, digest in r['output_sha256'].items():
            assert sha(p.parent / name) == digest, name
        cohorts[compiler] = {'path': p.relative_to(ROOT).as_posix(), 'sha256': sha(p),
                             'compiler_sha256': r['compiler_sha256'], 'results': r['results']}
    regressions = {}
    for compiler in ['llvm', 'gcc']:
        p = ROOT / f'build-native-sjuni/animation-audio-surface-regression-{compiler}-v1/receipt.json'
        r = json.loads(p.read_bytes())
        assert r['status'] == 'passed' and not r['source_drift']
        assert r['results']['frontend_cases'] == 1680
        for name, digest in r['source_sha256'].items():
            assert sha(ROOT / name) == digest, name
        regressions[compiler] = {'path': p.relative_to(ROOT).as_posix(), 'sha256': sha(p), 'results': r['results']}
    seal = ROOT / 'build-native-sjuni/surface-audio-frontends-seal-v1'
    assert not seal.exists()
    seal.mkdir()
    for name in ['docs/native-gameplay/ANIMATION_SURFACE_AUDIO.md', Path(__file__).relative_to(ROOT).as_posix()]:
        p = seal / 'source' / name
        p.parent.mkdir(parents=True, exist_ok=True)
        p.write_bytes((ROOT / name).read_bytes())
        sources[name] = sha(p)
        copies[name] = {'path': p.relative_to(ROOT).as_posix(), 'sha256': sha(p)}
    dependencies = {}
    for name in ['native_gameplay_audio_qualification_v1.json', 'native_gameplay_regions_qualification_v1.json']:
        p = ROOT / 'tools/native_reconstruction' / name
        dependencies[name] = {'path': p.relative_to(ROOT).as_posix(), 'sha256': sha(p)}
    q = {'schema': 1, 'status': 'canonical surface animation audio through real bank Session qualified on both compilers',
         'game_run': False, 'installed_in_game': False, 'stage4_complete': False,
         'source_sha256': sources, 'immutable_source_evidence': copies,
         'cohorts': cohorts, 'actor_resource_regressions': regressions, 'dependencies': dependencies,
         'limits': ['Region selection reuses the independently qualified native owner; no second region oracle claim.',
                    'Controlled bank/room inputs and canonical camera surroundings; runtime named-bank installation remains open.',
                    'Node/scenario-remapped audio and whole game acceptance remain open.']}
    p = ROOT / 'tools/native_reconstruction/native_animation_surface_audio_qualification_v1.json'
    assert not p.exists()
    p.write_text(json.dumps(q, indent=2) + '\n')
    print(sha(p))


if __name__ == '__main__':
    main()
