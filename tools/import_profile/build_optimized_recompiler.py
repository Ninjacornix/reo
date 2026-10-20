"""Build only the changed guard owner against the frozen independent compiler objects."""
import ctypes
from ctypes import wintypes
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys


def arguments(command):
    shell = ctypes.WinDLL('shell32', use_last_error=True)
    shell.CommandLineToArgvW.argtypes = [wintypes.LPCWSTR, ctypes.POINTER(ctypes.c_int)]
    shell.CommandLineToArgvW.restype = ctypes.POINTER(wintypes.LPWSTR)
    count = ctypes.c_int()
    argv = shell.CommandLineToArgvW(command, ctypes.byref(count))
    try:
        return [argv[i] for i in range(count.value)]
    finally:
        kernel = ctypes.WinDLL('kernel32')
        kernel.LocalFree.argtypes = [wintypes.HLOCAL]
        kernel.LocalFree(ctypes.cast(argv, wintypes.HLOCAL))


def main():
    repo = Path(__file__).resolve().parents[2]
    output = Path(sys.argv[1]).resolve()
    if not output.is_relative_to(repo / 'build-ninja') or output.exists():
        raise ValueError('Use a new private output directory beneath build-ninja')
    output.mkdir(parents=True)
    build = repo / 'build-ninja/portable-release/independent-build'
    ninja = Path('C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/Ninja/ninja.exe')
    database = json.loads(subprocess.check_output([str(ninja), '-t', 'compdb'], cwd=build))
    unit = next(row for row in database if row.get('file', '').endswith('/code_generator.cpp'))
    command = arguments(unit['command'])
    source = output / 'code_generator.cpp'
    shutil.copyfile(unit['file'], source)
    shutil.copyfile(repo / 'tools/source_instrumentation/guard_generated_source.hpp', output / 'guard_generated_source.hpp')
    target = output / 'code_generator.obj'
    trimmed = []
    i = 0
    while i < len(command):
        flag = command[i]
        if flag in {'-MT', '-MF'}:
            i += 2
            continue
        if flag == '-MD':
            i += 1
            continue
        trimmed.append(flag)
        i += 1
    command = trimmed
    command[command.index('-o') + 1] = str(target)
    command[command.index('-c') + 1] = str(source)
    env = dict(os.environ)
    env['PATH'] = str(Path(command[0]).parent) + os.pathsep + env.get('PATH', '')
    with (output / 'compile.log').open('wb') as log:
        subprocess.run(command, cwd=build, env=env, stdout=log, stderr=subprocess.STDOUT, check=True)
    edge = next(line for line in (build / 'build.ninja').read_text().splitlines() if line.startswith('build ps2_recomp.exe:'))
    objects = edge.split(' CXX_EXECUTABLE_LINKER__ps2_recomp_Release ', 1)[1].split(' | ', 1)[0].split()
    paths = [str(target) if name.endswith('/code_generator.cpp.obj') else str(build / name) for name in objects]
    libraries = [build / 'fmt/libfmt.a', build / 'dwarf/src/lib/libdwarf/libdwarf.a', build / 'librabbitizer.a']
    executable = output / 'ps2_recomp.exe'
    with (output / 'link.log').open('wb') as log:
        subprocess.run([command[0], '-O3', '-DNDEBUG', *paths, *map(str, libraries), '-o', str(executable)], cwd=build, env=env, stdout=log, stderr=subprocess.STDOUT, check=True)
    for name in ['libc++.dll', 'libunwind.dll', 'libwinpthread-1.dll']:
        shutil.copyfile(Path(command[0]).parent.parent / 'x86_64-w64-mingw32/bin' / name, output / name)
    files = [source, output / 'guard_generated_source.hpp', *map(Path, paths), *libraries, executable]
    (output / 'build-manifest.json').write_text(json.dumps({'onlyGuardChanged': True, 'files': {str(p): hashlib.sha256(p.read_bytes()).hexdigest() for p in files}}, indent=2))
    print(executable, flush=True)


if __name__ == '__main__':
    main()
