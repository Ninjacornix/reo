"""Boot timeline probe: launch the game, capture the window every few seconds and log
the frontend state until the main menu. Used to design starting at the main menu.

usage: boot_probe.py --exe EXE --data DISC_DATA --out FOLDER [--seconds 90] [--env K=V ...] [--game file1|file2]
"""
from pathlib import Path
import argparse, json, os, shutil, struct, subprocess, sys, time

SOURCE = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(SOURCE / 'tools/coop_playtest'))
import coop_playtest as harness
from window_capture import capture as capture_owned
from lobby_driver import GuestRam

ap = argparse.ArgumentParser()
ap.add_argument('--exe', type=Path, required=True)
ap.add_argument('--data', type=Path, required=True)
ap.add_argument('--out', type=Path, required=True)
ap.add_argument('--seconds', type=float, default=90)
ap.add_argument('--every', type=float, default=3)
ap.add_argument('--game', default='file1')
ap.add_argument('--env', action='append', default=[])
args = ap.parse_args()
args.exe, args.data, args.out = args.exe.resolve(), args.data.resolve(), args.out.resolve()
args.out.mkdir(parents=True, exist_ok=False)
for name in ('XINPUT1_4.dll', 'XINPUT1_3.dll'):
    shutil.copyfile(SOURCE / 'launcher/artifacts/native/XINPUT1_4.dll', args.exe.parent / name)
elf = args.data / ('SLUS_207.65' if args.game == 'file1' else 'SLUS_209.84')
front_at = 0x5d4898 if args.game == 'file1' else 0x5b7d00
shutil.copytree(SOURCE / 'build-ninja/play/saves', args.out / 'saves')
env = {k: v for k, v in os.environ.items() if not k.upper().startswith('REO_')}
# Same base environment as tools/hybrid/room_driver.py, without its test route or turbo.
iso = SOURCE / ('iso/Resident Evil - Outbreak (v2.00).iso' if args.game == 'file1' else 'iso/Resident Evil - Outbreak - File #2.iso')
env.update(REO_ISO=str(iso), REO_MC0_ROOT=str(args.out / 'saves'), REO_MC1_ROOT=':none:', REO_NATURAL='1',
           REO_GS_BACKEND='parallel', REO_GS_THREAD='1', REO_GS_GPU_PRESENT='1', REO_GS_DISPATCH_PACE='2',
           REO_GS_SPRITE_DEPTH_PARALLEL='1', REO_VIF1_ASYNC='1', REO_VIF1_GPU_RESIDENT='0', REO_GPU_MOVIE='0',
           REO_WINDOW_WIDTH='640', REO_WINDOW_HEIGHT='480', REO_POST_AA='off', REO_INTERNAL_RESOLUTION='1',
           REO_PERFORMANCE_OVERLAY='0', REO_AUDIO_LEVELS='0,100,100,100,100')
env.update(dict(item.split('=', 1) for item in args.env))
timeline = []
with (args.out / 'stdout.log').open('w') as out, (args.out / 'stderr.log').open('w') as err:
    process = subprocess.Popen([str(args.exe), '--game', args.game, '--elf', str(elf), '--data', str(args.data)],
                               cwd=args.out, env=env, stdout=out, stderr=err, creationflags=subprocess.CREATE_NO_WINDOW)
    identity = harness.process_identity(process.pid)
    began = time.monotonic(); next_shot = 2.0; ram = None; last = None
    try:
        while process.poll() is None and time.monotonic() - began < args.seconds:
            t = time.monotonic() - began
            if ram is None and t > 2:
                try: ram = GuestRam(identity, elf)
                except ValueError: pass
            state = None
            if ram and front_at:
                try:
                    front = struct.unpack('<I', ram.read(front_at, 4))[0]
                    if 0x100000 <= front < 0x1fff000:
                        state = struct.unpack('<I', ram.read(front, 4))[0] & 0xffffff
                except OSError:
                    pass
            if state != last:
                timeline.append({'t': round(t, 2), 'state': None if state is None else '%06x' % state})
                print('STATE', timeline[-1], flush=True); last = state
            if t >= next_shot:
                next_shot += args.every
                try: capture_owned(identity, args.out / ('t%03d.png' % int(t)))
                except Exception as problem: print('CAPTURE', problem, flush=True)
            time.sleep(0.05)
    finally:
        if ram: ram.close()
        if process.poll() is None:
            harness.stop_owned(identity); process.wait()
(args.out / 'timeline.json').write_text(json.dumps(timeline, indent=2))
print('exit', process.returncode)
