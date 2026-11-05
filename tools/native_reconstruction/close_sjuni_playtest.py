#!/usr/bin/env python3
"""Request ordinary window close for one identity-checked candidate test only.

Does not terminate a process. The supervisor still records the actual exit or
timeout. No global input, player executable, launcher or unrelated window control.
"""
import argparse
import ctypes
import json
from pathlib import Path
import sys

from analyze_sjuni_playtest import ROOT, sha
sys.path.insert(0, str(ROOT / 'tools/coop_playtest'))
import coop_playtest as owned


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--session', required=True, type=Path)
    args = parser.parse_args()
    folder = args.session.resolve()
    if not folder.is_relative_to(ROOT / 'build-native-sjuni'):
        raise ValueError('Use a private candidate test session')
    _, manifest = owned.session_record(folder)
    run = json.loads((folder / 'run.json').read_text(encoding='utf-8'))
    if len(manifest['players']) != 1 or len(run['players']) != 1 or run.get('finishedUtc'):
        raise ValueError('One running owned candidate is required')
    player, record = manifest['players'][0], run['players'][0]
    expected = {key: record[key] for key in ('pid', 'image', 'creationFileTime')}
    if Path(player['image']).resolve() != Path(record['image']).resolve() or sha(Path(player['image'])) != manifest['sourceSha256']:
        raise ValueError('Candidate image identity changed')
    k32 = owned.native()
    handle = k32.OpenProcess(0x1000, False, record['pid'])
    if not handle:
        raise ctypes.WinError(ctypes.get_last_error())
    try:
        # Keep a handle to the original process object while checking/using its
        # HWND. No new process with a reused numeric PID may own that identity.
        if owned.process_identity(record['pid']) != expected:
            raise ValueError('Process creation/executable identity changed')
        user = ctypes.WinDLL('user32', use_last_error=True)
        callback = ctypes.WINFUNCTYPE(ctypes.c_int, ctypes.c_void_p, ctypes.c_void_p)
        user.EnumWindows.argtypes = [callback, ctypes.c_void_p]
        user.GetWindowThreadProcessId.argtypes = [ctypes.c_void_p, ctypes.POINTER(ctypes.c_ulong)]
        user.IsWindowVisible.argtypes = [ctypes.c_void_p]
        user.PostMessageW.argtypes = [ctypes.c_void_p, ctypes.c_uint, ctypes.c_size_t, ctypes.c_ssize_t]
        windows = []

        @callback
        def visit(hwnd, _):
            owner_pid = ctypes.c_ulong()
            user.GetWindowThreadProcessId(hwnd, ctypes.byref(owner_pid))
            if owner_pid.value == record['pid'] and user.IsWindowVisible(hwnd):
                windows.append(hwnd)
            return 1

        user.EnumWindows(visit, None)
        if len(windows) != 1 or owned.process_identity(record['pid']) != expected:
            raise ValueError('Expected one still-owned visible candidate window')
        if not user.PostMessageW(windows[0], 0x0010, 0, 0):  # WM_CLOSE
            raise ctypes.WinError(ctypes.get_last_error())
        receipt = dict(utc=owned.utc(), **expected, hwnd=windows[0], action='WM_CLOSE requested',
                       limitation='Request only; inspect supervisor receipt and logs for actual shutdown completion')
        owned.save(folder / 'window-close-request.json', receipt)
        print(json.dumps(receipt))
    finally:
        k32.CloseHandle(handle)


if __name__ == '__main__':
    main()
