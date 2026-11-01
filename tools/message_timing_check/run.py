"""Exercise both production timing hooks; optionally execute owned guest code.

The default checks need no game data. --owned-queue verifies generated instruction
comments against the supported original ELF and BIN/2.DAT before compiling them.
Original code and private receipts remain under ignored build-ninja/.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import struct
import subprocess
import sys


def verify_owned(data: Path, game: str, generated: Path) -> dict:
    file2 = game == 'file2'
    elf_path = data / ('SLUS_209.84' if file2 else 'SLUS_207.65')
    expected = ('5c0411a26247ef9974cd94b844ac5aecbcbf4705db543f51814aeed89da0fd8d' if file2 else
                '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46')
    elf = elf_path.read_bytes()
    if hashlib.sha256(elf).hexdigest() != expected:
        raise ValueError(f'{game}: original executable identity differs')
    overlay_path = data / 'BIN/2.DAT'
    packed = overlay_path.read_bytes()
    overlay = packed
    if packed[:2] == b'\x02\x00':
        sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
        from overlay_extract import decompress
        overlay = decompress(packed)
    if struct.unpack_from('<II', overlay) != (0x336f574d, 3):
        raise ValueError(f'{game}: original gameplay overlay identity differs')
    base = 0x58d000 if file2 else 0x570000
    phoff = struct.unpack_from('<I', elf, 28)[0]
    phsize, phcount = struct.unpack_from('<HH', elf, 42)
    segments = [struct.unpack_from('<8I', elf, phoff + i * phsize) for i in range(phcount)]

    def word(address):
        if base <= address <= base + len(overlay) - 4:
            return struct.unpack_from('<I', overlay, address - base)[0]
        for kind, offset, virtual, _, size, *_ in segments:
            if kind == 1 and virtual <= address <= virtual + size - 4:
                return struct.unpack_from('<I', elf, offset + address - virtual)[0]
        raise ValueError(f'{game}: instruction {address:x} is outside original code')

    witnesses = re.findall(r'// 0x([0-9a-f]+): 0x([0-9a-f]+) ', generated.read_text())
    for pc, expected_word in witnesses:
        if word(int(pc, 16)) != int(expected_word, 16):
            raise ValueError(f'{game}: generated instruction differs at {pc}')
    return {'game': game, 'elfSha256': expected, 'overlayFileSha256': hashlib.sha256(packed).hexdigest(),
            'overlayImageSha256': hashlib.sha256(overlay).hexdigest(),
            'instructionCommentsCompared': len(witnesses), 'uniqueInstructions': len(dict(witnesses)),
            'method': 'Generated opcode comments compared directly with original ELF load segments and BIN/2.DAT',
            'passed': True}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--compiler', default=shutil.which('clang++') or shutil.which('c++'))
    parser.add_argument('--owned-queue', action='store_true')
    parser.add_argument('--data-file1', type=Path)
    parser.add_argument('--data-file2', type=Path)
    args = parser.parse_args()
    if not args.compiler:
        parser.error('Provide --compiler or put a C++20 clang++/c++ compiler on PATH')
    root = Path(__file__).resolve().parents[2]
    output = root / 'build-ninja/message-timing-check'
    output.mkdir(parents=True, exist_ok=True)
    environment = os.environ.copy()
    environment['PATH'] = str(Path(args.compiler).resolve().parent) + os.pathsep + environment['PATH']
    creationflags = subprocess.CREATE_NO_WINDOW if os.name == 'nt' else 0
    results = []
    for game in ('file1', 'file2'):
        executable = output / (game + '-check' + ('-owned' if args.owned_queue else '') + ('.exe' if os.name == 'nt' else ''))
        command = [args.compiler, '-std=c++20', '-O2', '-Wall', '-Wextra',
                   '-DREO_GAME_' + game.upper(), str(Path(__file__).with_name('check.cpp')),
                   '-o', str(executable)]
        original = None
        if args.owned_queue:
            sys.path.insert(0, str(root / 'tools/subtitle_check'))
            from owned_queue import stage
            stage(root, output / game, game, timing=True)
            data = getattr(args, 'data_' + game) or root / ('game_data_file2' if game == 'file2' else 'game_data')
            original = verify_owned(data, game, output / game / 'owned_queue.inc')
            command += ['-DREO_GENERATED_QUEUE', '-I', str(output / game)]
        for label, run in [('build', command), ('test', [str(executable)])]:
            result = subprocess.run(run, env=environment, stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
                                    text=True, creationflags=creationflags, timeout=120)
            (output / (executable.stem + '-' + label + '.log')).write_text(result.stdout)
            if result.returncode:
                raise RuntimeError(result.stdout)
        print(game, result.stdout.strip())
        results.append({'game': game, 'passed': True, 'originalCode': original})
    report = output / ('owned-report.json' if args.owned_queue else 'report.json')
    report.write_text(json.dumps({'passed': True, 'results': results}, indent=2))


if __name__ == '__main__':
    main()
