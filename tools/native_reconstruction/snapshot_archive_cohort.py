"""Capture one passing shared LLVM cohort for immutable archive-only comparisons.

The capture performs no compilation. It verifies the source and archive identities
before and after copying, so production work may resume as soon as it completes.
"""
import argparse
import hashlib
import json
from pathlib import Path
import shutil
import time

from verify_native_session import ROOT, dependency_sources


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main(args):
    started = time.monotonic()
    cohort_path = args.cohort.resolve()
    cohort = json.loads(cohort_path.read_text())
    assert cohort['status'] == 'passed'
    assert not cohort['source_drift'] and not cohort['archive_drift']
    build = args.native_build.resolve()
    out = args.output.resolve()
    assert out.is_relative_to(ROOT / 'build-native-sjuni') and not out.exists()
    native, libraries = dependency_sources(build)
    native, libraries = set(native), set(libraries)
    for target in args.target:
        target_sources, target_libraries = dependency_sources(build, target)
        native.update(target_sources)
        libraries.update(target_libraries)
    libraries = sorted(libraries)
    for name in args.include_archive:
        archive = build / name
        assert archive.resolve().is_relative_to(build) and archive.suffix == '.a'
        assert name in cohort['archives_sha256'], name
        if name not in libraries:
            libraries.append(name)
    sources = {name: ROOT / name for name in cohort['sources_sha256']}
    sources.update({path.relative_to(ROOT).as_posix(): path for path in native})
    source_hashes = {name: sha(path) for name, path in sources.items()}
    for name, digest in cohort['sources_sha256'].items():
        assert source_hashes[name] == digest, name
    archive_hashes = {name: sha(build / name) for name in libraries}
    for name, digest in archive_hashes.items():
        assert cohort['archives_sha256'].get(name) == digest, name
    cohort_hash = sha(cohort_path)
    out.mkdir()
    for name, path in sources.items():
        target = out / 'source' / name
        assert target.resolve().is_relative_to(out)
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(path, target)
        assert sha(target) == source_hashes[name] == sha(path), name
    for name, digest in archive_hashes.items():
        target = out / 'native-build' / name
        assert target.resolve().is_relative_to(out)
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(build / name, target)
        assert sha(target) == digest == sha(build / name), name
    shutil.copyfile(build / 'build.ninja', out / 'native-build/build.ninja')
    shutil.copyfile(cohort_path, out / 'cohort.json')
    assert sha(out / 'cohort.json') == cohort_hash == sha(cohort_path)
    assert all(sha(path) == source_hashes[name] for name, path in sources.items())
    assert all(sha(build / name) == digest for name, digest in archive_hashes.items())
    receipt = dict(status='passed', cohort=cohort_path.relative_to(ROOT).as_posix(),
                   cohort_sha256=cohort_hash, source_sha256=source_hashes,
                   archives_sha256=archive_hashes, seconds=time.monotonic()-started,
                   additional_targets=args.target,
                   capture_script_sha256=sha(Path(__file__).resolve()))
    (out / 'receipt.json').write_text(json.dumps(receipt, indent=2)+'\n')
    print(json.dumps(dict(status='passed', sources=len(sources),
                          archives=len(libraries), seconds=receipt['seconds'])))


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--cohort', type=Path, required=True)
    parser.add_argument('--native-build', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--include-archive', action='append', default=[])
    parser.add_argument('--target', action='append', default=[],
                        help='Include the complete Ninja source/archive closure of this additional executable target')
    main(parser.parse_args())
