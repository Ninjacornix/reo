"""File #2 room trials for hybrid swaps (based on build-ninja/rc2/file2_room_driver.py).

Presses through the menus to gameplay with File #2 state addresses, then walks.
Adds --env KEY=VALUE (game switches), --explore (analog walk/turn cycles for
--room-seconds) and PrintWindow captures. See tools/hybrid/README.md.
"""
from pathlib import Path
import argparse,ctypes,json,os,shutil,struct,subprocess,sys,time,uuid,hashlib
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools/coop_playtest'))
import coop_playtest as harness
sys.path.insert(0,str(Path(__file__).resolve().parent))
from window_capture import capture as capture_owned
from lobby_driver import GuestRam
p=argparse.ArgumentParser();p.add_argument('--exe',type=Path,required=True);p.add_argument('--out',type=Path,required=True);p.add_argument('--plan',type=Path);p.add_argument('--seconds',type=int,default=150);p.add_argument('--env',action='append',default=[]);p.add_argument('--explore',action='store_true');p.add_argument('--room-seconds',type=float,default=24)
args=p.parse_args();args.out=args.out.resolve();args.out.mkdir(parents=True,exist_ok=False)
# Match the launcher's private play-folder input adapter, absent from compiler outputs.
shutil.copyfile(ROOT/'launcher/artifacts/native/XINPUT1_4.dll',args.exe.resolve().parent/'XINPUT1_4.dll')
shutil.copyfile(ROOT/'launcher/artifacts/native/XINPUT1_4.dll',args.exe.resolve().parent/'XINPUT1_3.dll')
imports=list((ROOT/'build-ninja/asset-paks-build/launcher-smoke-data/imports/file2').glob('*/data'))
assert len(imports)==1
data=imports[0];elf=data/'SLUS_209.84'
shutil.copytree(ROOT/'build-ninja/file2-randomizer/live-wild-final/player1/card0',args.out/'saves')
map_name='Local\\REO-Asset-File2-'+uuid.uuid4().hex;publisher=harness.Publisher(map_name)
env={k:v for k,v in os.environ.items() if not k.upper().startswith('REO_')}
env.update(REO_ISO=str(ROOT/'iso/Resident Evil - Outbreak - File #2.iso'),REO_MC0_ROOT=str(args.out/'saves'),REO_MC1_ROOT=':none:',REO_LAUNCHER_PAD_MAP=map_name,REO_COOP_TEST_INPUT='1',REO_NATURAL='1',REO_TURBO='1',REO_GS_BACKEND='parallel',REO_GS_THREAD='1',REO_GS_GPU_PRESENT='1',REO_GS_DISPATCH_PACE='2',REO_GS_SPRITE_DEPTH_PARALLEL='1',REO_VIF1_ASYNC='1',REO_VIF1_GPU_RESIDENT='0',REO_GPU_MOVIE='0',REO_WINDOW_WIDTH='640',REO_WINDOW_HEIGHT='480',REO_INTERNAL_RESOLUTION='1',REO_POST_AA='off',REO_PERFORMANCE_OVERLAY='1',REO_CD_LOG='1')
if args.plan:env['REO_ASSET_OVERLAY']=str(args.plan.resolve())
env['REO_AUDIO_LEVELS']='0,100,100,100,100' # Quiet unattended test; no system volume changes.
env.update(dict(item.split('=',1) for item in args.env))
(args.out/'launch.json').write_text(json.dumps(dict(image=str(args.exe.resolve()),imageSha256=hashlib.sha256(args.exe.read_bytes()).hexdigest(),elf=str(elf),elfSha256=hashlib.sha256(elf.read_bytes()).hexdigest(),environment={k:v for k,v in env.items() if k.startswith('REO_')}),indent=2))
identity=None;ram=None;process=None;began=time.monotonic();last_capture=-10;next_sample=0;samples=[];arrived=None; inventoryCaptured=False
try:
 with (args.out/'stdout.log').open('wb') as stdout,(args.out/'stderr.log').open('wb') as stderr:
  process=subprocess.Popen([str(args.exe.resolve()),'--game','file2','--elf',str(elf),'--data',str(data)],cwd=args.out,env=env,stdout=stdout,stderr=stderr,creationflags=subprocess.CREATE_NO_WINDOW)
  identity=harness.process_identity(process.pid);(args.out/'identity.json').write_text(json.dumps(identity));print(identity,flush=True)
  while process.poll() is None and time.monotonic()-began<args.seconds:
   elapsed=time.monotonic()-began;buttons=[];axes={}
   state=samples[-1] if samples else {'phase':0,'modal':0,'paused':0}
   playing=state['phase']==2 and not state['modal'] and not state['paused']
   if playing:
    if arrived is None:arrived=elapsed
    axes={}
    if args.explore and elapsed-arrived>=4:
     motion=elapsed-arrived-4;k=int(motion//6);ph=motion-6*k
     if ph<2.4 or 3.0<=ph<5.4:axes={'ly':32767}
     elif ph<3.0:axes={'rx':32767 if k%3!=2 else -32767,'ly':32767}
     else:buttons=['cross']
    elif 4 <= elapsed-arrived < 12:buttons=['up'] if elapsed-arrived<7 else ['left']
    if elapsed-arrived>=args.room_seconds:break
   elif elapsed>=5 and elapsed-int(elapsed)<.18:
    buttons=['circle' if state['phase']==2 and state['modal'] else 'start' if state['phase'] in (1,4,14) or (state['phase']==0 and int(elapsed)%2==0) else 'cross']
   if arrived is not None:
    roomTime=elapsed-arrived
    if not args.explore and 14 <= roomTime < 20:
     buttons=['triangle'] if 14 <= roomTime < 14.18 or 19.2 <= roomTime < 19.38 else []
     if roomTime>=16 and not inventoryCaptured:
      try:
       capture_owned(identity,args.out/'inventory.png')
       inventoryCaptured=True
      except Exception as e:print('inventory capture',e,flush=True)
   command=args.out/'input.json'
   if command.exists():
    value=json.loads(command.read_text());buttons=value.get('buttons',[]) if value.get('until',0)>time.time() else buttons
   publisher.publish(dict({'buttons':buttons},**(axes if playing else {})))
   if ram is None and elapsed>3:
    try:ram=GuestRam(identity,elf,game='file2')
    except ValueError:pass
   if ram and elapsed>=next_sample:
    next_sample=elapsed+.5
    b=ram.read(0x4db390,0xc0);selected=b[0x1d]
    actor=0x4c5e10+selected*0x1100 if selected<4 else None
    state=dict(t=elapsed,phase=b[0],modal=b[0x1e],paused=b[0x28],selected=selected,scenario=struct.unpack('<H',ram.read(0x30095a,2))[0],room=struct.unpack('<H',ram.read(0x30095c,2))[0],xyz=list(struct.unpack('<3f',ram.read(actor+0x38,12))) if actor else None)
    samples.append(state);(args.out/'state.json').write_text(json.dumps(state))
    with (args.out/'samples.jsonl').open('a') as out:out.write(json.dumps(state)+'\n')
   if elapsed-last_capture>=10:
    last_capture=elapsed
    try:capture_owned(identity,args.out/('frame-'+str(int(elapsed))+'.png'))
    except Exception as e:print('capture',e,flush=True)
   time.sleep(.015)
finally:
 publisher.publish({'buttons':[]})
 if process and process.poll() is None:
  user=ctypes.WinDLL('user32');cb=ctypes.WINFUNCTYPE(ctypes.c_int,ctypes.c_void_p,ctypes.c_void_p)
  user.GetWindowThreadProcessId.argtypes=[ctypes.c_void_p,ctypes.POINTER(ctypes.c_ulong)];user.PostMessageW.argtypes=[ctypes.c_void_p,ctypes.c_uint,ctypes.c_size_t,ctypes.c_ssize_t]
  @cb
  def close(hwnd,_):
   pid=ctypes.c_ulong();user.GetWindowThreadProcessId(hwnd,ctypes.byref(pid))
   if pid.value==process.pid:user.PostMessageW(hwnd,0x10,0,0)
   return 1
  user.EnumWindows(close,0)
  try:process.wait(timeout=10)
  except subprocess.TimeoutExpired:harness.stop_owned(identity);process.wait()
 if ram:ram.close()
 publisher.close()
 (args.out/'result.json').write_text(json.dumps(dict(exit=process.returncode if process else None,samples=samples),indent=2))
