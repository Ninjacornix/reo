"""Chapter-opening trials for hybrid swaps: ordinary pad input and read-only guest observations.

Based on build-ninja/rc2/file1_room_driver.py. Adds --env KEY=VALUE (passed to the game;
the base driver strips REO_* variables), --explore (walk/turn/cross cycles that cross
camera zones and doors) and PrintWindow capture (works under covering windows).
See docs/native-gameplay/HYBRID_INTEGRATION_PLAN.md.
"""
from pathlib import Path
import argparse, collections, csv, ctypes, hashlib, json, math, os, re, shutil, statistics, struct, subprocess, sys, time

SOURCE = Path(__file__).resolve().parents[2]  # repository root
sys.path.insert(0, str(SOURCE / 'tools/coop_playtest'))
import coop_playtest as harness
from window_capture import capture as capture_owned  # PrintWindow: works under covering windows
from lobby_driver import GuestRam

CHAPTERS = ['Outbreak', 'Below Freezing Point', 'The Hive', 'Hellfire', 'Decisions, Decisions']
ap = argparse.ArgumentParser()
ap.add_argument('--exe', type=Path, required=True)
ap.add_argument('--scenario', type=int, choices=range(5), required=True)
ap.add_argument('--out', type=Path, required=True)
ap.add_argument('--seconds', type=float, default=25)
ap.add_argument('--move-at', type=float, default=13.5)
ap.add_argument('--iso', type=Path, default=SOURCE / 'iso/Resident Evil - Outbreak (v2.00).iso')
ap.add_argument('--boot-fast', action='store_true')
ap.add_argument('--asset-plan', type=Path)
ap.add_argument('--data', type=Path)
ap.add_argument('--env', action='append', default=[], help='Extra KEY=VALUE for the game process')
ap.add_argument('--explore', action='store_true', help='Walk/turn/press cross in cycles instead of the fixed movement check')
ap.add_argument('--analog', action='store_true', help='With --explore: walk with the left stick and turn with the right stick (modern camera)')
ap.add_argument('--reverse-walk', action='store_true', help='With --explore --analog: alternate forward/backward stick walks (sharp reversals)')
ap.add_argument('--warp-probe', action='store_true', help='Idle captures before/after short right-stick turns (presentation warp validation)')
ap.add_argument('--aim-probe', action='store_true', help='Hold R1 with the left stick up/centre/down/up and dump the player actor record after each')
args = ap.parse_args()
args.exe = args.exe.resolve(); args.iso = args.iso.resolve(); args.out = args.out.resolve()
for name in ("XINPUT1_4.dll", "XINPUT1_3.dll"):
    shutil.copyfile(SOURCE/"launcher/artifacts/native/XINPUT1_4.dll", args.exe.parent/name)
args.out.mkdir(parents=True, exist_ok=False)
if args.data:
    mount = {'owned':False,'drive':None,'data':str(args.data.resolve())}
    disc = args.data.resolve()
else:
    raise RuntimeError('This private asset driver requires --data from the owned import')
(args.out/'mount.json').write_text(json.dumps(mount,indent=2))
elf = disc / 'SLUS_207.65'
publisher = None; ram = None; process = None; identity = None; samples = []; inputs = []; screenshots = []; arrived = None; error = None; confirmed_cursor = None

def record_input(buttons, why, elapsed):
    inputs.append({'t':elapsed, 'buttons':buttons, 'why':why})
    print('PAD '+json.dumps(inputs[-1]), flush=True)

def close_owned():
    if process is None or process.poll() is not None: return
    user = ctypes.WinDLL('user32')
    callback = ctypes.WINFUNCTYPE(ctypes.c_int, ctypes.c_void_p, ctypes.c_void_p)
    user.GetWindowThreadProcessId.argtypes = [ctypes.c_void_p, ctypes.POINTER(ctypes.c_ulong)]
    user.PostMessageW.argtypes = [ctypes.c_void_p, ctypes.c_uint, ctypes.c_size_t, ctypes.c_ssize_t]
    @callback
    def close(hwnd, _):
        pid = ctypes.c_ulong(); user.GetWindowThreadProcessId(hwnd, ctypes.byref(pid))
        if pid.value == process.pid: user.PostMessageW(hwnd, 0x10, 0, 0)
        return 1
    user.EnumWindows(close, 0)
    try: process.wait(timeout=12)
    except subprocess.TimeoutExpired: harness.stop_owned(identity); process.wait()

def snapshot(elapsed):
    word = lambda address: struct.unpack('<I', ram.read(address,4))[0]
    game = ram.read(0x4badd0, 0xc0)
    front = word(0x5d4898); selection = word(0x32442c)
    valid = lambda address: 0x100000 <= address < 0x1fff000
    fs = word(front) & 0xffffff if valid(front) else None
    ss = word(selection+4) & 0xffff if valid(selection) else None
    selected = game[0x1d]
    actor = 0x4a5c30 + selected * 0x10e0 if selected < 4 else None
    xyz = list(struct.unpack('<3f', ram.read(actor+0x38,12))) if actor else None
    return {'t':elapsed, 'front':front, 'frontState':fs, 'selection':selection, 'selectionState':ss,
            'selectionCursor':word(selection+0x260) if valid(selection) and ss == 0x0108 else None,
            'selectionTimer':word(selection+0x20) if valid(selection) else None,
            'phase':game[0], 'subphase':game[1], 'modal':game[0x1e], 'paused':game[0x28], 'selected':selected,
            'request':game[0x37], 'room':struct.unpack('<H',ram.read(0x3243dc,2))[0],
            'cacheScenario':ram.read(0x7434b0,1)[0], 'cacheRoom':ram.read(0x7434b1,1)[0],
            'roomCounter':word(0x4bade8), 'clockUnits':((game[0x30]*60+game[0x31])*60+game[0x32])*60+game[0x33], 'xyz':xyz}

def capture(label):
    path = args.out/(label+'.png')
    try:
        capture_owned(identity,path)
        screenshots.append(str(path))
    except Exception as problem: print('CAPTURE '+str(problem),flush=True)

try:
    shutil.copytree(SOURCE/'build-ninja/play/saves',args.out/'saves')
    (args.out/'cheats.txt').write_text('REO-CHEATS-2\nbuiltin unlock\n')
    map_name = 'Local\\REO-Chapter-'+args.out.name
    publisher = harness.Publisher(map_name)
    env = {key:value for key,value in os.environ.items() if not key.upper().startswith('REO_')}
    env.update(REO_ISO=str(args.iso), REO_MC0_ROOT=str(args.out/'saves'), REO_MC1_ROOT=':none:',
               REO_LAUNCHER_PAD_MAP=map_name,
               REO_COOP_TEST_INPUT='1', REO_NATURAL='1', REO_TURBO='1', REO_TEST_ROUTE='scenario',
               REO_GS_BACKEND='parallel', REO_GS_THREAD='1', REO_GS_GPU_PRESENT='1', REO_GS_DISPATCH_PACE='2',
               REO_GS_SPRITE_DEPTH_PARALLEL='1', REO_VIF1_ASYNC='1', REO_VIF1_GPU_RESIDENT='0', REO_GPU_MOVIE='0',
               REO_WINDOW_WIDTH='640', REO_WINDOW_HEIGHT='480', REO_POST_AA='off', REO_INTERNAL_RESOLUTION='1',
               REO_PERFORMANCE_OVERLAY='1', REO_FRAME_PACING_FILE=str(args.out/'frames.csv'), REO_GAME_CLOCK_LOG='1',
               REO_GAME_CLOCK_FROM_SECS='0', REO_GAME_CLOCK_SECONDS='300', REO_GAME_CLOCK_FILE=str(args.out/'clock.csv'))
    env['REO_AUDIO_LEVELS']='0,100,100,100,100'
    env.update(dict(item.split('=',1) for item in args.env))
    if args.scenario>0:env['REO_CHEATS_FILE']=str(args.out/'cheats.txt')
    if args.asset_plan: env.update(REO_ASSET_OVERLAY=str(args.asset_plan.resolve()), REO_CD_LOG='1')
    if args.boot_fast: env.update(REO_TURBO='16', REO_TURBO_UNTIL='0x5d4898')
    launch = {'scenario':args.scenario,'chapter':CHAPTERS[args.scenario], 'image':str(args.exe),
              'imageSha256':hashlib.sha256(args.exe.read_bytes()).hexdigest(), 'elf':str(elf),
              'elfSha256':hashlib.sha256(elf.read_bytes()).hexdigest(), 'environment':{k:v for k,v in env.items() if k.startswith('REO_')}}
    (args.out/'launch.json').write_text(json.dumps(launch,indent=2))
    with (args.out/'stdout.log').open('w') as stdout, (args.out/'stderr.log').open('w') as stderr:
        process = subprocess.Popen([str(args.exe),'--game','file1','--elf',str(elf),'--data',str(disc)],cwd=args.out,env=env,stdout=stdout,stderr=stderr,creationflags=subprocess.CREATE_NO_WINDOW)
        identity = harness.process_identity(process.pid); (args.out/'identity.json').write_text(json.dumps(identity,indent=2))
        print('START '+json.dumps(identity),flush=True)
        began=time.monotonic(); next_sample=0; next_pad=0; held_until=0; held=[]; held_axes={}; dumped=set()
        initial_shot=False; final_shot=False; scenario_shot=False; next_cancel=0
        while process.poll() is None and time.monotonic()-began < max(240, args.seconds+120):
            elapsed=time.monotonic()-began
            active=elapsed<held_until
            publisher.publish(dict({'buttons':held if active else []},**(held_axes if active else {})))
            if ram is None and elapsed>3:
                try: ram=GuestRam(identity,elf)
                except ValueError: pass
            if ram and elapsed>=next_sample:
                next_sample=elapsed+.2
                try:row=snapshot(elapsed)
                except OSError as problem:
                    if getattr(problem,'winerror',None)==299 and process.poll() is None:
                        ram.check()
                        print('TRANSIENT-READ '+str(problem),flush=True)
                        continue
                    raise
                samples.append(row)
                (args.out/'state.json').write_text(json.dumps(row,indent=2))
                with (args.out/'states.jsonl').open('a') as sample_file:sample_file.write(json.dumps(row)+'\n')
                button=None; why=None
                if arrived is None:
                    if row['phase']==2 and row['selected']<4:
                        arrived=elapsed; print('ARRIVED '+json.dumps(row),flush=True)
                    elif elapsed>=next_pad:
                        if row['frontState'] is not None and row['frontState']&0xffff==0x0202 and row['selectionState']==0:
                            button='cross';why='open-scenarios'
                        elif row['selectionState']==0x0108 and row['selectionTimer']==0:
                            if row['selectionCursor']==args.scenario:
                                confirmed_cursor=row['selectionCursor']
                                if not scenario_shot:
                                    scenario_shot=True;capture('scenario-confirmed')
                                button='cross';why='confirm-observed-scenario-'+str(row['selectionCursor'])
                            elif row['selectionCursor'] in range(5):button='right' if row['selectionCursor']<args.scenario else 'left';why='scenario-cursor-'+str(row['selectionCursor'])
                        elif row['selectionState'] in (0x0109,0x030a,0x050b):
                            button='cross';why='confirm-character-partners-difficulty'
                        elif row['phase'] in (0xe,1,4):button='start';why='skip-opening-cutscene'
                else:
                    room_elapsed=elapsed-arrived
                    if room_elapsed>=4 and not initial_shot:
                        initial_shot=True;capture('opening')
                    if room_elapsed>=args.move_at:
                        if row['phase']!=2 or row['modal'] or row['paused']:
                            if elapsed>=next_cancel:
                                button='start' if row['phase']==4 else 'circle'
                                why='skip-original-cutscene' if row['phase']==4 else 'dismiss-original-menu'
                                next_cancel=elapsed+1.0
                        elif row['selected']<4:
                            axes=None
                            motion=room_elapsed-args.move_at
                            if args.warp_probe and motion>=0:
                                # Pairs: idle capture, short yaw turn (~8 deg), idle capture; long turns between pairs; one pitch pair.
                                plan=[('w0',1.0),('w1',3.5),('w2',8.0),('w3',10.5),('w4',15.0),('w5',17.5),('w6',20.0)]
                                for name,at in plan:
                                    if motion>=at and name not in dumped:
                                        pose=lambda:struct.unpack('<7f',ram.read(0x324138,0x18)+ram.read(0x324138+0x48,4))
                                        before=pose();dumped.add(name);capture('warp-'+name);after=pose()
                                        print('WARP-CAPTURE '+name+' t=%.3f'%elapsed+' pose='+json.dumps(before)+' stable='+str(before==after),flush=True)
                                turns=[(2.0,2.3,'rx',32767),(4.5,7.0,'rx',32767),(9.0,9.3,'rx',32767),(11.5,14.0,'rx',-32767),
                                       (16.0,16.3,'rx',-32767),(18.5,18.7,'ry',32767)]
                                for lo,hi,ax,v in turns:
                                    if lo<=motion<hi:button='analog';axes={ax:v}
                            elif args.aim_probe and motion>=0:
                                # 4 s per hold: R1 + stick, dump at 3 s. Order up, mid, down, up.
                                probe=[('up',32767),('mid',0),('down',-32767),('up2',32767)]
                                k=int(motion//4);ph=motion-4*k
                                if k<len(probe) and ph<3.6:
                                    name,ly=probe[k];button='analog';axes={'ly':ly}
                                    if ph>=3.0 and name not in dumped:
                                        dumped.add(name)
                                        (args.out/('actor-'+name+'.bin')).write_bytes(ram.read(0x4a5c30,0x10e0))
                                        print('DUMP '+name,flush=True)
                            elif args.explore and args.analog and motion>=0:
                                k=int(motion//6);ph=motion-6*k
                                walk=-32767 if args.reverse_walk and k%2 else 32767
                                if ph<2.4 or 3.0<=ph<5.4:axes={'ly':walk}
                                elif ph<3.0:axes={'rx':32767 if k%3!=2 else -32767,'ly':walk}
                                else:button='cross'
                                if axes:button='analog'
                            elif args.explore and motion>=0:
                                k=int(motion//6);ph=motion-6*k
                                if ph<2.4 or 3.0<=ph<5.4:button='up'
                                elif ph<3.0:button='left' if k%3!=2 else 'right'
                                else:button='cross'
                                if ph>=2.4 and ph<3.0 and ph-2.4>0.3+0.1*(k%4):button='up'
                            elif 0<=motion<.8:button='left'
                            elif 1<=motion<3:button='up'
                            elif 3.3<=motion<4.3:button='right'
                            elif 4.5<=motion<6.5:button='up'
                            elif 6.5<=motion<7.8:button='down'
                            elif args.scenario==1 and 18<=room_elapsed<23:button='up'
                            if button:why='explore' if (args.explore or args.aim_probe) else 'movement-check'
                    if room_elapsed>=22 and not final_shot:
                        final_shot=True;capture('after-movement')
                    if room_elapsed>=args.seconds:break
                if button:
                    held=(['r1'] if args.aim_probe and why=='explore' else []) if button=='analog' else [button];held_axes=axes if button=='analog' else {}
                    held_until=time.monotonic()-began+.12;next_pad=elapsed+1.2
                    if why in ('movement-check','explore'):held_until=time.monotonic()-began+.23
                    if args.warp_probe and button=='analog':held_until=time.monotonic()-began+.05;next_pad=elapsed
                    record_input(held,why,elapsed)
            time.sleep(.015)
        close_owned()
except Exception as problem:
    error=repr(problem); print('ERROR '+error,flush=True)
finally:
    if publisher:publisher.close()
    close_owned()
    if ram:ram.close()
    if mount['owned']:
        subprocess.run(['powershell','-NoProfile','-Command',"Dismount-DiskImage -ImagePath '"+iso_text+"' | Out-Null"],check=True)
    (args.out/'inputs.json').write_text(json.dumps(inputs,indent=2))
    stderr_text=(args.out/'stderr.log').read_text(errors='replace') if (args.out/'stderr.log').exists() else ''
    stdout_text=(args.out/'stdout.log').read_text(errors='replace') if (args.out/'stdout.log').exists() else ''
    fatal=[]; cancellations=[]
    for log_name,text in [('stderr.log',stderr_text),('stdout.log',stdout_text)]:
        close_at=text.find('[run] window close requested')
        offset=0
        for line in text.splitlines(keepends=True):
            if re.search(r'\[CRASH\]|\[GS-BACKEND-FAIL\]|Called unimplemented function|VIF1 worker failure|graphics backend failure|Error during program execution|Owned source failure',line,re.I):
                if line.strip()=='Error during program execution: PS2 Thread Exit' and 0<=close_at<offset:
                    cancellations.append({'log':log_name,'message':line.strip(),'afterRequestedWindowClose':True})
                else:fatal.append(line.strip())
            offset+=len(line)
    missing=collections.Counter(re.findall(r'Function at address (0x[0-9a-f]+) not found',stderr_text+'\n'+stdout_text,re.I))
    result={'chapter':CHAPTERS[args.scenario],'requestedScenario':args.scenario,'arrived':arrived,'error':error,
            'exitCode':process.returncode if process else None,'fatal':fatal,'shutdownCancellations':cancellations,'missingFunctions':dict(missing),
            'screenshots':screenshots,'mountOwnedByTask':mount['owned'],'confirmedMenuCursor':confirmed_cursor}
    game_samples=[row for row in samples if arrived is not None and row['t']>=arrived and row['phase']==2 and row['selected']<4 and row['xyz'] and all(math.isfinite(v) for v in row['xyz'])]
    result['observedCacheScenarios']=sorted(set(row['cacheScenario'] for row in game_samples))
    if game_samples:
        origin=game_samples[0]['xyz']; result['initialPosition']=origin
        result['maximumPositionDistance']=max(math.dist(origin,row['xyz']) for row in game_samples)
        before_move=[row for row in game_samples if row['t']<arrived+args.move_at]
        movement_origin=before_move[-1]['xyz'] if before_move else origin
        moves=[row for row in game_samples if row['t']>=arrived+args.move_at]
        result['movementOrigin']=movement_origin
        result['movementStartsAtRoomSecond']=args.move_at
        result['movementDistance']=max((math.dist(movement_origin,row['xyz']) for row in moves),default=0)
        result['movementObserved']=result['movementDistance']>1
        controlled=[]
        sent=[event['t'] for event in inputs if event['why']=='movement-check']
        for a,b in zip(samples,samples[1:]):
            if (a['phase']==b['phase']==2 and not a['paused'] and not b['paused'] and
                a['selected']==b['selected']==0 and a['room']==b['room'] and a['xyz'] and b['xyz'] and
                all(math.isfinite(v) for v in a['xyz']+b['xyz']) and
                any(a['t']-.24<=t<=b['t'] for t in sent)):
                distance=math.dist(a['xyz'],b['xyz'])
                if distance>1:controlled.append({'from':a['t'],'to':b['t'],'distance':distance,'room':b['room']})
        result['movementInputPositionChanges']=controlled
        result['movementObserved']=bool(controlled)
    clock=args.out/'clock.csv'
    if clock.exists():
        clock_rows=[{k:int(v) for k,v in row.items()} for row in csv.DictReader(line for line in clock.read_text().splitlines() if not line.startswith('#'))]
        measured=[row for row in clock_rows if row['selected']==0 and row['phase']==2 and not row['paused'] and 3e9<=row['elapsed_ns']<=13e9]
        if len(measured)>1:
            first,last=measured[0],measured[-1]; duration=(last['elapsed_ns']-first['elapsed_ns'])/1e9
            deltas=[(b['elapsed_ns']-a['elapsed_ns'])/1e6 for a,b in zip(measured,measured[1:]) if b['room_counter']!=a['room_counter']]
            result['timing']={'windowRoomSeconds':[3,13],'samples':len(measured),'durationSeconds':duration,
                              'updatesPerSecond':(last['room_counter']-first['room_counter'])/duration,
                              'clockUnitsPerSecond':(last['clock_units']-first['clock_units'])/duration,
                              'medianUpdateMs':statistics.median(deltas) if deltas else None,
                              'p99UpdateMs':sorted(deltas)[int(.99*(len(deltas)-1))] if deltas else None}
    (args.out/'result.json').write_text(json.dumps(result,indent=2));print('RESULT '+json.dumps(result),flush=True)
