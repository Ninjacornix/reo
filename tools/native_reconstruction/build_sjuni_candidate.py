#!/usr/bin/env python3
"""Build the separate verified SJUNI candidate; never start the game.

Uses the prepared sealed SDK's ordinary local-build worker. Runtime/backend and
game code are rebuilt together. Player folders, settings and original build
outputs are not modified. Existing owned imported disc data is read in place.
"""
import argparse
import hashlib
import json
import os
import re
from pathlib import Path
import shutil
import subprocess
import sys
import time

from prepare_sjuni_candidate import verify, ELF_SHA, ROOT


def sha(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def toolchain_identity(folder, plan):
    receipt_path = folder / 'compiler-setup.json'
    receipt = json.loads(receipt_path.read_text(encoding='utf-8'))
    if (receipt.get('Format') != 1 or receipt.get('ArchiveSha256') !=
        '2d96a4b758f7f8deaec5065833fe025aa53cfc5f704d0524002510984da0ccf4' or
        len(receipt.get('Files', [])) != 5601):
        raise ValueError('Exact installed LLVM/MinGW UCRT 20251216 receipt required')
    seen = set()
    for item in receipt['Files']:
        path = (folder / item['Path']).resolve()
        if (not path.is_relative_to(folder) or item['Path'].casefold() in seen or
            not path.is_file() or path.stat().st_size != item['Bytes'] or sha(path) != item['Sha256']):
            raise ValueError('Changed compiler/sysroot member: ' + item['Path'])
        seen.add(item['Path'].casefold())
    compiler = folder / 'bin/x86_64-w64-mingw32-clang++.exe'
    if sha(compiler) != plan['externalCompilerSha256']:
        raise ValueError('SDK compiler driver identity mismatch')
    return {'receipt_sha256': sha(receipt_path), 'verified_members': len(seen),
            'compiler_sha256': sha(compiler), 'archive_sha256': receipt['ArchiveSha256']}


def seed_object_cache(source, work, identity):
    """Copy verified object/receipt pairs, never archives, PCHs or input markers.

    The ordinary sealed compile worker still recomputes each input signature,
    including headers/options/source/ABI/driver, before accepting a cache hit.
    """
    allowed = (ROOT / 'build-native-sjuni').resolve()
    source = source.resolve()
    if (source == allowed or not source.is_relative_to(allowed) or
            source.is_relative_to(work) or work.is_relative_to(source)):
        raise ValueError('Object cache must be a distinct private candidate work folder')
    old_marker = source / 'candidate-build-inputs.json'
    result_path = source / 'candidate-build-result.json'
    old = json.loads(old_marker.read_text(encoding='utf-8'))
    result = json.loads(result_path.read_text(encoding='utf-8'))
    if old.get('toolchain') != identity['toolchain'] or result.get('status') not in ('passed', 'failed'):
        raise ValueError('Object cache needs completed build and matching verified toolchain identity')
    destination = work / 'objects'
    if destination.exists():
        raise ValueError('Seed only a fresh object directory; omit --cache-from when resuming')
    destination.mkdir()
    copied = {}
    for receipt in sorted((source / 'objects').glob('*.json')):
        if not re.fullmatch(r'[A-Za-z0-9_-]+', receipt.stem):
            raise ValueError('Invalid cached unit name')
        obj = receipt.with_suffix('.obj')
        if not obj.is_file():
            continue
        saved = json.loads(receipt.read_text(encoding='utf-8'))
        if (not isinstance(saved, dict) or not re.fullmatch(r'[0-9a-f]{64}', saved.get('input', '')) or
                saved.get('object') != sha(obj)):
            raise ValueError('Invalid cached object/receipt pair: ' + receipt.stem)
        shutil.copyfile(obj, destination / obj.name)
        shutil.copyfile(receipt, destination / receipt.name)
        if sha(destination / obj.name) != saved['object']:
            raise ValueError('Cached object copy failed verification')
        copied[receipt.stem] = dict(object_sha256=saved['object'], receipt_sha256=sha(receipt))
    report = dict(source=str(source), source_inputs_sha256=sha(old_marker),
                  source_result_sha256=sha(result_path), copied_objects=copied,
                  signature_revalidation='ordinary compile worker recomputes each input signature')
    (work / 'seeded-object-cache.json').write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8')
    return dict(source=str(source), copied_pairs=len(copied), receipt_sha256=sha(work / 'seeded-object-cache.json'))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--kit', required=True, type=Path)
    parser.add_argument('--disc', required=True, type=Path, help='Existing imported data folder containing SLUS_207.65 and BIN')
    parser.add_argument('--toolchain', required=True, type=Path)
    parser.add_argument('--work', type=Path, default=ROOT / 'build-native-sjuni/candidate-work-v1')
    parser.add_argument('--output', type=Path, default=ROOT / 'build-native-sjuni/candidate-game-v1')
    parser.add_argument('--jobs', type=int, default=2)
    parser.add_argument('--cache-from', type=Path, help='Seed a fresh work folder with verified object/receipt pairs')
    args = parser.parse_args()
    kit, disc, compiler = args.kit.resolve(), args.disc.resolve(), args.toolchain.resolve()
    work, output = args.work.resolve(), args.output.resolve()
    allowed = (ROOT / 'build-native-sjuni').resolve()
    if (not 1 <= args.jobs <= 4 or work == allowed or output == allowed or
        not work.is_relative_to(allowed) or not output.is_relative_to(allowed) or
        work.is_relative_to(output) or output.is_relative_to(work) or
        work.is_relative_to(kit) or output.is_relative_to(kit)):
        parser.error('Use distinct private work/output folders below build-native-sjuni and 1..4 jobs')
    if sha(disc / 'SLUS_207.65') != ELF_SHA or not (disc / 'BIN').is_dir():
        raise ValueError('Owned File #1 imported data identity/overlay folder mismatch')
    print('Verifying sealed candidate SDK and complete compiler/sysroot...', flush=True)
    manifest, plan = verify(kit)
    tools = toolchain_identity(compiler, plan)
    identity = dict(schema=1, candidate_manifest_sha256=sha(kit / 'build-kit.json'),
                    disc_elf_sha256=ELF_SHA, toolchain=tools,
                    base_source_delta_sha256=sha(kit / 'notices/native-sjuni-candidate.json'))
    work.mkdir(parents=True, exist_ok=True)
    marker = work / 'candidate-build-inputs.json'
    if marker.exists() and json.loads(marker.read_text(encoding='utf-8')) != identity:
        raise ValueError('Private work folder belongs to different inputs; choose another folder')
    if args.cache_from and marker.exists():
        raise ValueError('Use --cache-from only on a fresh work folder')
    cache = seed_object_cache(args.cache_from, work, identity) if args.cache_from else None
    marker.write_text(json.dumps(identity, indent=2) + '\n', encoding='utf-8')
    if shutil.disk_usage(work).free < 4 * 1024 ** 3:
        raise RuntimeError('Less than 4 GiB free; candidate build not started')
    command = [sys.executable, '-u', str(kit / 'tools/local_build/build_game.py'),
               '--kit', str(kit), '--disc', str(disc), '--work', str(work),
               '--output', str(output), '--jobs', str(args.jobs), '--game', 'file1']
    env = dict(os.environ)
    env['REO_LLVM_MINGW'] = str(compiler)
    # These affect neither generation nor compilation; ensure no inherited launch
    # mode is mistaken for a candidate build/validation setting in its receipt.
    for name in ('REO_NATIVE_SJUNI', 'REO_NATIVE_SJUNI_GUARDED', 'REO_NATIVE_SJUNI_TRACE'):
        env.pop(name, None)
    started = time.monotonic()
    print('Building a separate runtime/backend/game from matching SDK sources...', flush=True)
    log_path = work / 'candidate-build.log'
    with log_path.open('w', encoding='utf-8', newline='\n') as log:
        process = subprocess.Popen(command, cwd=ROOT, env=env, stdout=subprocess.PIPE,
                                   stderr=subprocess.STDOUT, text=True, encoding='utf-8', errors='replace')
        last = 0.0
        for line in process.stdout:
            log.write(line)
            log.flush()
            now = time.monotonic()
            if (now - last >= 10 or line.startswith(('Preparing', 'Generating', 'Reconstructing', 'Compiling', 'Linking')) or
                'error:' in line.lower() or 'traceback' in line.lower()):
                print(line.rstrip(), flush=True)
                last = now
        result = process.wait()
    record = dict(**identity, status='passed' if result == 0 else 'failed', exit_code=result,
                  elapsed_seconds=round(time.monotonic() - started, 3), command=command,
                  build_log_sha256=sha(log_path), game_launched=False,
                  precompiled_ps2_runtime_reused=False)
    record['seeded_object_cache'] = cache
    executable = output / 'reo_recomp.exe'
    if result == 0:
        if not executable.is_file():
            raise RuntimeError('Worker succeeded without expected candidate executable')
        record['executable_sha256'] = sha(executable)
        record['outputs_sha256'] = {p.relative_to(output).as_posix(): sha(p)
                                    for p in sorted(output.rglob('*')) if p.is_file()}
    (work / 'candidate-build-result.json').write_text(json.dumps(record, indent=2) + '\n', encoding='utf-8')
    print('Candidate build ' + record['status'] + '; log: ' + str(log_path.relative_to(ROOT)), flush=True)
    raise SystemExit(result)


if __name__ == '__main__':
    main()
