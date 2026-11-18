"""Build the concrete native application and exercise a hash-verified owned room.

Uses the actual CMake dependency graph and real native owners. No game process,
window, emulated CPU, or successful fixture effect service is involved.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess

ROOT = Path(__file__).resolve().parents[2]


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def dependency_sources(build, target='gameplay_application/native_session_tests.exe'):
    rules = {}
    for line in (build / 'build.ninja').read_text().splitlines():
        match = re.match(r'^build ([^:]+): \S+\s*(.*)', line)
        if match:
            for output in match[1].split():
                rules[output] = match[2].split()
    pending = [target]
    visited, sources, libraries = set(), set(), set()
    while pending:
        node = pending.pop()
        if node in visited:
            continue
        visited.add(node)
        if node.endswith('.a'):
            libraries.add(node)
        for dependency in rules.get(node, []):
            if dependency.endswith(('.a', '.obj')):
                pending.append(dependency)
            elif dependency.endswith('.cpp'):
                path = Path(dependency.replace('$:', ':')).resolve()
                assert path.is_file() and path.is_relative_to(ROOT), path
                sources.add(path)
    assert ROOT / 'game/native/gameplay_application/native_session.cpp' in sources
    assert ROOT / 'game/native/gameplay_update/update.cpp' in sources
    pending = list(sources)
    while pending:
        path = pending.pop()
        for name in re.findall(r'#\s*include\s*"([^"]+)"', path.read_text()):
            candidate = next((value.resolve() for value in (path.parent / name, ROOT / name)
                              if value.is_file()), None)
            if candidate and candidate.is_relative_to(ROOT) and candidate not in sources:
                sources.add(candidate)
                pending.append(candidate)
    sources.add(Path(__file__).resolve())
    sources.add(ROOT / 'game/native/CMakeLists.txt')
    for path in tuple(sources):
        cmake = path.parent / 'CMakeLists.txt'
        if cmake.is_file():
            sources.add(cmake)
    return sorted(sources), sorted(libraries)


def main(args):
    out = args.output.resolve()
    assert not out.exists() and out.is_relative_to(ROOT / 'build-native-sjuni')
    out.mkdir()
    build, compiler, cmake = args.native_build.resolve(), args.compiler.resolve(), args.cmake.resolve()
    env = dict(os.environ, PATH=str(compiler.parent) + os.pathsep + os.environ.get('PATH', ''))
    commands = []

    def run(command, label):
        result = subprocess.run([str(value) for value in command], env=env,
                                capture_output=True, text=True, timeout=600)
        stdout, stderr = out / (label + '.stdout.txt'), out / (label + '.stderr.txt')
        stdout.write_text(result.stdout)
        stderr.write_text(result.stderr)
        commands.append(dict(command=[str(value) for value in command], returncode=result.returncode,
                             stdout_sha256=sha(stdout), stderr_sha256=sha(stderr)))
        if result.returncode:
            raise RuntimeError(label + ': ' + result.stdout[-3000:] + result.stderr[-3000:])
        return result.stdout

    run([cmake, '-S', ROOT / 'game/native', '-B', build], 'configure')
    sources, libraries = dependency_sources(build)
    before = {path.relative_to(ROOT).as_posix(): sha(path) for path in sources}
    for path in sources:
        target = out / 'source' / path.relative_to(ROOT)
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_bytes(path.read_bytes())
    inventory = ROOT / 'build-native-sjuni/gameplay-script-content-llvm-v14/inventory.json'
    index_receipt = json.loads((inventory.parent / 'receipt.json').read_bytes())
    assert index_receipt['status'] == 'passed' and index_receipt['output_sha256']['inventory.json'] == sha(inventory)
    member = next(row for row in json.loads(inventory.read_bytes()) if row['name'] == 'r0417300.rdt')
    archive = Path(member['archive'])
    with archive.open('rb') as source:
        source.seek(member['archive_offset'])
        room = source.read(member['bytes'])
    assert hashlib.sha256(room).hexdigest() == member['sha256']
    identity = dict(size=archive.stat().st_size, mtime_ns=archive.stat().st_mtime_ns)
    run([cmake, '--build', build, '--target', 'native_session_tests', '--parallel', '2'], 'build')
    fixture = json.loads(run([build / 'gameplay_application/native_session_tests.exe'], 'fixture-tests'))
    result = json.loads(run([build / 'gameplay_application/native_session_tests.exe', archive], 'owned-tests'))
    assert result['owned_rooms'] == 4 and result['script_steps'] == 12 and result['frame_refusals'] == 4
    assert dict(size=archive.stat().st_size, mtime_ns=archive.stat().st_mtime_ns) == identity
    drift = {name: sha(ROOT / name) for name, digest in before.items() if sha(ROOT / name) != digest}
    receipt = dict(schema='reo.native.application_session.v1', status='failed' if drift else 'passed',
                   compiler=str(compiler), compiler_sha256=sha(compiler), source_sha256=before,
                   current_shared_source_drift=drift, commands=commands, fixture_result=fixture, result=result,
                   executable_sha256=sha(build / 'gameplay_application/native_session_tests.exe'),
                   native_library_sha256={name: sha(build / name) for name in libraries},
                   owned_room={key: member[key] for key in ('name', 'sha256', 'archive_offset', 'bytes')},
                   archive_identity=identity, inventory_sha256=sha(inventory),
                   game_launched=False, installed_in_game=False, stage4_complete=False,
                   limitations=['Actual owned room scripts, lighting and shared scene records run in a concrete native application owner.',
                                'Complete actor startup, terminal frame services, production installation and semantic saves remain required.',
                                'No emulated CPU/register/RAM engine is linked into this application target.'])
    (out / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
    assert not drift, drift
    print(json.dumps(dict(compiler=str(compiler), **result)))


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--compiler', type=Path, required=True)
    parser.add_argument('--cmake', type=Path, required=True)
    parser.add_argument('--native-build', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    main(parser.parse_args())
