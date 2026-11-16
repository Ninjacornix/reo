"""Run the bounded untouched-content startup diagnostic from a sealed cohort."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess

ROOT = Path(__file__).resolve().parents[2]


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--immutable-snapshot', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--compiler', type=Path, required=True)
    args = parser.parse_args()
    snapshot = args.immutable_snapshot.resolve()
    output = args.output.resolve()
    assert not output.exists() and output.is_relative_to(ROOT / 'build-native-sjuni')
    output.mkdir()
    receipt = {'status': 'failed', 'native_startup_complete': False, 'frame_run': False}
    try:
        captured = json.loads((snapshot / 'receipt.json').read_text())
        cohort_path = ROOT / captured['cohort']
        assert captured['status'] == 'passed' and sha(cohort_path) == captured['cohort_sha256']
        cohort = json.loads(cohort_path.read_text())
        assert cohort['status'] == 'passed'
        # These are immutable link inputs; unrelated live-tree edits are irrelevant.
        archives = snapshot / 'archives'
        if not archives.exists():
            archives = snapshot / 'native-build'
        assert all(sha(archives / name) == digest for name, digest in captured['archives_sha256'].items())
        case = next(item for item in cohort['commands'] if item['label'] == 'session-startup-owned')
        executable = Path(case['command'][0])
        assert sha(executable) == case['executable_sha256'], 'shared startup executable changed since cohort'
        retained = output / executable.name
        shutil.copy2(executable, retained)
        command = [str(retained), *case['command'][1:4], '--fresh-startup-diagnostic']
        environment = dict(os.environ)
        environment['PATH'] = str(args.compiler.resolve().parent) + os.pathsep + environment.get('PATH', '')
        done = subprocess.run(command, cwd=ROOT, env=environment, capture_output=True, timeout=180)
        (output / 'stdout.txt').write_bytes(done.stdout)
        (output / 'stderr.txt').write_bytes(done.stderr)
        assert done.returncode == 0, 'diagnostic process failed'
        lines = [line for line in done.stdout.decode(errors='replace').splitlines() if line.startswith('{"diagnostic":')]
        assert len(lines) == 1, 'expected exactly one structured diagnostic result'
        observed = json.loads(lines[0])
        assert observed['content_modified'] is False and observed['frame_run'] is False
        assert sha(executable) == sha(retained) == case['executable_sha256']
        receipt.update(status='passed', observed=observed, cohort=str(cohort_path.relative_to(ROOT)),
                       cohort_sha256=sha(cohort_path), executable_sha256=sha(retained),
                       archive_count=len(captured['archives_sha256']), command=command,
                       native_startup_complete=observed['native_startup_complete'],
                       scope='Observed first concrete startup refusal; no successful external callbacks or frame claim.')
    finally:
        (output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
    print(json.dumps({'status': receipt['status'], 'observed': receipt['observed']}))


if __name__ == '__main__':
    main()
