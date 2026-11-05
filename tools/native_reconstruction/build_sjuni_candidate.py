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


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--kit', required=True, type=Path)
    parser.add_argument('--disc', required=True, type=Path, help='Existing imported data folder containing SLUS_207.65 and BIN')
    parser.add_argument('--toolchain', required=True, type=Path)
    parser.add_argument('--work', type=Path, default=ROOT / 'build-native-sjuni/candidate-work-v1')
    parser.add_argument('--output', type=Path, default=ROOT / 'build-native-sjuni/candidate-game-v1')
    parser.add_argument('--jobs', type=int, default=2)
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
