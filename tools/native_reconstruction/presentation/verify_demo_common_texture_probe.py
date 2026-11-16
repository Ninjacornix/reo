"""Qualify existing native texture decoder on the real frontend asset."""
import hashlib, json, os, subprocess, time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
OUT = ROOT / 'build-native-sjuni/frontend-demo-common-probe-v1'
CC = Path('C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe')
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()

def main():
    assert not OUT.exists()
    OUT.mkdir()
    native = ROOT / 'game/native/gameplay_presentation/texture.cpp'
    header = native.with_suffix('.hpp')
    fixture = ROOT / 'tools/native_reconstruction/presentation/demo_common_texture_probe.cpp'
    before = {p.relative_to(ROOT).as_posix(): sha(p) for p in (native, header, fixture)}
    with (ROOT / 'iso/Resident Evil - Outbreak (v2.00).iso').open('rb') as source:
        source.seek(234080256)
        payload = source.read(857152)
    assert hashlib.sha256(payload).hexdigest() == 'a06bc7b56a6768d80fac725daf30301393e0fd59f1498ebce20f0445fc50db26'
    asset = OUT / 'demo_com.tex'
    asset.write_bytes(payload)
    exe = OUT / 'probe.exe'
    env = dict(os.environ, PATH=str(CC.parent) + os.pathsep + os.environ.get('PATH', ''))
    commands = [('compile', [str(CC), '-std=c++20', '-O2', '-Wall', '-Wextra', '-Wpedantic', '-Werror',
                              '-I' + str(ROOT), str(fixture), str(native), '-o', str(exe)]),
                ('run', [str(exe), str(asset)])]
    receipt = {'status': 'failed', 'compiler_sha256': sha(CC), 'asset_sha256': sha(asset),
               'sources_sha256': before, 'driver_sha256': sha(Path(__file__)), 'checks': [], 'game_run': False}
    try:
        for name, command in commands:
            start = time.monotonic()
            result = subprocess.run(command, capture_output=True, env=env, timeout=120)
            (OUT / (name + '.out')).write_bytes(result.stdout)
            (OUT / (name + '.err')).write_bytes(result.stderr)
            receipt['checks'].append({'name': name, 'seconds': time.monotonic() - start, 'exit': result.returncode})
            if result.returncode:
                raise RuntimeError(name + ': ' + result.stderr.decode(errors='replace')[-3000:])
        observed = json.loads((OUT / 'run.out').read_text())
        assert observed['textures'] == 10 and observed['expanded_bytes'] == 2043328
        assert before == {p.relative_to(ROOT).as_posix(): sha(p) for p in (native, header, fixture)}
        receipt.update(status='passed', observed=observed)
    finally:
        (OUT / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
    print(json.dumps(receipt['observed']))

if __name__ == '__main__':
    main()
