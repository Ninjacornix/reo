"""Qualify direct native archive reads and update-owner script loading."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess

ROOT = Path(__file__).resolve().parents[3]


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main(args):
    build = args.build.resolve()
    output = args.output.resolve()
    index = args.index.resolve()
    assert build.is_relative_to(ROOT / 'build-native-sjuni')
    assert output.is_relative_to(ROOT / 'build-native-sjuni') and not output.exists()
    compiler = args.compiler.resolve()
    cache = (build / 'CMakeCache.txt').read_text()
    configured = re.search(r'^CMAKE_CXX_COMPILER:[^=]+=([^\n]+)', cache, re.M).group(1).strip()
    assert Path(configured).resolve() == compiler
    index_receipt = json.loads((index / 'receipt.json').read_bytes())
    assert index_receipt['status'] == 'passed'
    for name, digest in index_receipt['output_sha256'].items():
        assert sha(index / name) == digest
    members = json.loads((index / 'inventory.json').read_bytes())
    assert len(members) == 171
    from npc_fixtures import read_owned_npcs
    npc_members=read_owned_npcs()
    for member in npc_members:
        member.pop('payload')
        members.append(dict(member,format='N'))
    archives = {Path(row['archive']).resolve() for row in members}
    assert len(archives) == 1
    archive = archives.pop()
    stamp = archive.stat()
    identity = (stamp.st_size, stamp.st_mtime_ns)
    lines = []
    with archive.open('rb') as source:
        for row in members:
            source.seek(row['archive_offset'])
            assert hashlib.sha256(source.read(row['bytes'])).hexdigest() == row['sha256']
            name = row['name']
            assert name.startswith('r')
            scenario = int(name[1:4])
            lines.append('\t'.join(map(str, (row['format'], scenario, name, row['archive_offset'],
                                              row['bytes'], row['sha256']))))
    source_names = subprocess.check_output(['rg', '--files', 'game/native'], cwd=ROOT, text=True).splitlines()
    sources = [ROOT / name for name in source_names]
    sources += [ROOT / 'runtime/assets/virtual_afs.h', Path(__file__), Path(__file__).with_name('npc_fixtures.py')]
    before = {path.relative_to(ROOT).as_posix(): sha(path) for path in sources}
    output.mkdir(parents=True)
    manifest = output / 'owned-members.tsv'
    manifest.write_text('\n'.join(lines) + '\n')
    env = dict(os.environ)
    env['PATH'] = str(compiler.parent) + os.pathsep + env.get('PATH', '')
    command = [str(args.cmake), '--build', str(build), '--parallel', '3', '--target', 'gameplay_archive_tests']
    built = subprocess.run(command, env=env, capture_output=True, text=True, timeout=180)
    (output / 'build.txt').write_text(built.stdout + built.stderr)
    assert built.returncode == 0, 'archive build failed, see build.txt'
    executable = build / 'gameplay_scenario/gameplay_archive_tests.exe'
    run = subprocess.run([str(executable), str(archive), str(manifest)], env=env,
                         capture_output=True, text=True, timeout=90)
    (output / 'run.stdout.txt').write_text(run.stdout)
    (output / 'run.stderr.txt').write_text(run.stderr)
    assert run.returncode == 0, 'archive comparison failed, see run.stderr.txt'
    assert all(sha(ROOT / name) == digest for name, digest in before.items())
    stamp = archive.stat()
    assert (stamp.st_size, stamp.st_mtime_ns) == identity
    observed = json.loads(run.stdout)
    assert observed['status'] == 'passed' and observed['members'] == 176 and observed['npc_banks'] == 5
    receipt = dict(schema='reo.native.scenario.archive.v1', status='passed',
                   compiler=str(compiler), compiler_sha256=sha(compiler), source_sha256=before,
                   index_receipt_sha256=sha(index / 'receipt.json'),
                   members={row['name']: row['sha256'] for row in members},
                   archive=dict(path=str(archive), size=identity[0], mtime_ns=identity[1]),
                   command=command, executable_sha256=sha(executable), result=observed,
                   game_launched=False, installed_in_game=False, stage4_complete=False)
    (output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
    print(json.dumps({'status': 'passed', 'output': str(output), 'result': observed}))


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--compiler', type=Path, required=True)
    parser.add_argument('--cmake', type=Path, required=True)
    parser.add_argument('--build', type=Path, required=True)
    parser.add_argument('--index', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    main(parser.parse_args())
