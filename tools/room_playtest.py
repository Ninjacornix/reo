"""Unattended native room trials; controller input only, guest memory read-only.

python tools/room_playtest.py --manifest <json> --launcher <ps1> --out <new-dir>
    --mode idle|soak|interact-quit --seconds 180
The launcher must support RoomExercise and immutable Exe/ExpectedSha256 inputs.
"""
from pathlib import Path
import argparse,ctypes as c,ctypes.wintypes as w,hashlib,json,os,re,struct,subprocess,sys,time

ROOT=Path(__file__).resolve().parents[1]
ap=argparse.ArgumentParser();ap.add_argument('--manifest',type=Path,required=True);ap.add_argument('--launcher',type=Path,required=True)
ap.add_argument('--out',type=Path,required=True);ap.add_argument('--mode',choices=['idle','soak','interact-quit'],default='idle');ap.add_argument('--seconds',type=float,default=180);ap.add_argument('--resume',action='store_true')
a=ap.parse_args();a.out.mkdir(parents=True,exist_ok=a.resume);a.out=a.out.resolve()
m=json.loads(a.manifest.read_text());exe=Path(m['exe']);sha=m['sha256'];assert hashlib.sha256(exe.read_bytes()).hexdigest()==sha
k=c.WinDLL('kernel32',use_last_error=True);u=c.WinDLL('user32');ps=c.WinDLL('psapi')
k.OpenProcess.argtypes=[w.DWORD,w.BOOL,w.DWORD];k.OpenProcess.restype=w.HANDLE;k.CloseHandle.argtypes=[w.HANDLE]
k.QueryFullProcessImageNameW.argtypes=[w.HANDLE,w.DWORD,w.LPWSTR,c.POINTER(w.DWORD)]
ps.EnumProcessModules.argtypes=[w.HANDLE,c.POINTER(w.HMODULE),w.DWORD,c.POINTER(w.DWORD)]
class Reader:
    def __init__(self,pid):
        # Reuse the ELF-qualified RDRAM locator, without running another process
        # for every sample. Its handle grants QUERY_INFORMATION and VM_READ only.
        prior=sys.argv;sys.argv=['guest_peek.py',str(pid),str(ROOT/'game_data/SLUS_207.65')];self.ns={}
        try:exec(compile((ROOT/'tools/guest_peek.py').read_text(),'guest_peek.py','exec'),self.ns)
        except SystemExit as error:
            if self.ns.get('h'):k.CloseHandle(self.ns['h'])
            raise RuntimeError(str(error)) from error
        finally:sys.argv=prior
        self.h=self.ns['h'];self.base=self.ns['base'];self.read=self.ns['read']
        name=c.create_unicode_buffer(32768);n=w.DWORD(len(name));assert k.QueryFullProcessImageNameW(self.h,0,name,c.byref(n));assert Path(name.value).resolve()==exe.resolve()
        mods=(w.HMODULE*256)();n=w.DWORD();assert ps.EnumProcessModules(self.h,mods,c.sizeof(mods),c.byref(n));self.image=mods[0]
        mp=Path(m['map']).read_text();pref=int(re.search('Preferred load address is ([0-9a-fA-F]+)',mp)[1],16)
        addr=int(re.search(r'g_threadCtx@ps2_sched[^\n]+?([0-9A-Fa-f]{16})\s',mp)[1],16)
        self.contexts=self.image+addr-pref
    def guest(self,at,size):
        b=self.read(self.h,self.base+at,size)
        if b is None:raise RuntimeError('guest sample unreadable')
        return b
    def state(self):
        b=self.guest(0x4badd0,0xc0);selected=b[0x1d];room=struct.unpack('<H',self.guest(0x3243dc,2))[0]
        clock=((b[0x30]*60+b[0x31])*60+b[0x32])*60+b[0x33]
        pc5=0;ptr=self.read(self.h,self.contexts+5*8,8)
        if ptr:
            address=struct.unpack('<Q',ptr)[0];v=self.read(self.h,address+512,4) if address else None
            if v:pc5=struct.unpack('<I',v)[0]
        xyz=None
        if selected<4:xyz=struct.unpack('<3f',self.guest(0x4a5c30+selected*0x10e0+0x38,12))
        return dict(clock=clock,phase=b[0],room=room,selected=selected,modal=b[0x1e],paused=b[0x28],ui=self.guest(0x755ec4,1)[0],request=b[0x37],pc5=hex(pc5),xyz=xyz)
    def capture(self,folder,state):
        folder.mkdir();(folder/'state.json').write_text(json.dumps(state,indent=2));(folder/'rdram.bin').write_bytes(self.guest(0,32*1024*1024))
        pointers=self.read(self.h,self.contexts,256*8);contexts={}
        if pointers:
            for tid,ptr in enumerate(struct.unpack('<256Q',pointers)):
                data=self.read(self.h,ptr,1648) if ptr else None
                if data:(folder/f'guest-thread-{tid}.bin').write_bytes(data);contexts[str(tid)]=hex(ptr)
        (folder/'contexts.json').write_text(json.dumps(contexts,indent=2))
        with (folder/'native-stacks.log').open('w') as f:
            subprocess.run([str(ROOT/'build-ninja/ext_sampler/ext_sampler.exe'),str(receipt['pid']),'0','8','75'],stdout=f,stderr=subprocess.STDOUT,timeout=20)
    def close(self):k.CloseHandle(self.h)
def close_owned(pid):
    callback=c.WINFUNCTYPE(w.BOOL,w.HWND,w.LPARAM)
    @callback
    def visit(hwnd,_):
        owner=w.DWORD();u.GetWindowThreadProcessId(hwnd,c.byref(owner))
        if owner.value==pid:u.PostMessageW(hwnd,0x10,0,0)
        return True
    u.EnumWindows(visit,0)

receipt=None;reader=None;failure=None;trigger=None;closed=None;last_clock=None;last_change=time.monotonic();trap=0;log_offset=0;tail='';positions=set();rooms=set();mainmenu=False;pickup=False;message=False;gameplay_seen=False;controller_reports=0
env=dict(os.environ);env['REO_VIF1_ASYNC']='1'
class Attached:
    def __init__(self,pid):self.h=k.OpenProcess(0x1000,False,pid);assert self.h
    def poll(self):
        code=w.DWORD();k.GetExitCodeProcess.argtypes=[w.HANDLE,c.POINTER(w.DWORD)]
        return None if k.GetExitCodeProcess(self.h,c.byref(code)) and code.value==259 else code.value
with (a.out/'launcher.log').open('a' if a.resume else 'w') as launcher,(a.out/'samples.jsonl').open('a' if a.resume else 'w') as samples:
    if a.resume:
        receipt=next(json.loads(s) for s in (a.out/'launcher.log').read_text().splitlines() if s.startswith('{'));assert receipt['sha256']==sha;proc=Attached(receipt['pid'])
    else:proc=subprocess.Popen(['powershell','-NoProfile','-ExecutionPolicy','Bypass','-File',str(a.launcher.resolve()),'-Exe',str(exe),'-ExpectedSha256',sha,'-RoomExercise',a.mode],cwd=ROOT,env=env,stdout=launcher,stderr=subprocess.STDOUT)
    start=time.monotonic();notice=start
    while proc.poll() is None:
        now=time.monotonic()
        if receipt is None:
            for line in (a.out/'launcher.log').read_text(errors='replace').splitlines():
                if line.startswith('{'):receipt=json.loads(line);break
        if receipt:
            if reader is None:
                try:reader=Reader(receipt['pid'])
                except RuntimeError as error:
                    if str(error)=='RDRAM not found' and now-start<30:time.sleep(.5);continue
                    raise
            p=Path(receipt['logs'])/'stderr.log'
            with p.open('rb') as stream:stream.seek(log_offset);new=stream.read();log_offset=stream.tell()
            text=new.decode(errors='replace');scan=tail+text;tail=scan[-32768:]
            mainmenu|='MAIN MENU PROOF' in scan
            pickup|='PICKUP PROOF' in scan
            message|='MESSAGE PROOF' in scan
            gameplay_seen|='[TEST-ROUTE] reached gameplay' in scan
            controller_reports+=text.count('[TEST-ROOM-SOAK]')
            if any(x in text for x in ['[CRASH]','[GS-BACKEND-FAIL]','VIF1 worker failure']):failure='runtime_fault'
            state=reader.state();state['wall_s']=now-start;samples.write(json.dumps(state)+'\n');samples.flush()
            if trigger is None and (gameplay_seen or (a.resume and state['phase']==2 and state['clock']>0)):trigger=now;last_change=now;print('room route reached',round(now-start,1),flush=True)
            if state['clock']!=last_clock:last_clock=state['clock'];last_change=now
            if trigger:
                rooms.add(state['room'])
                if state['xyz'] and state['phase']==2:positions.add(tuple(round(x,1) for x in state['xyz']))
            trap=trap+1 if 0x13ee68<=int(state['pc5'],16)<=0x13ee80 else 0
            if trap>=2:failure='CRI_chunk_assertion_13ee68'
            active=state['phase']==2 and not state['modal'] and not state['paused'] and not state['request'] and not state['ui']
            if trigger and active and now-last_change>15:failure=f'game_clock_stalled_{now-last_change:.1f}s'
            done=trigger and (now-trigger>=a.seconds or (a.mode=='interact-quit' and mainmenu))
            if closed is None and (failure or done or now-start>a.seconds+240):
                if not trigger:failure=failure or 'never_reached_gameplay'
                if failure:reader.capture(a.out/'incident',state);print('FAIL',failure,'evidence preserved',flush=True)
                close_owned(receipt['pid']);closed=now
            if closed and now-closed>25:raise RuntimeError('Owned game did not stop after WM_CLOSE; preserving process')
        if now-notice>=30:notice=now;print(a.mode,'running',round(now-start),'rooms',sorted(rooms),'positions',len(positions),flush=True)
        time.sleep(1)
    if reader:reader.close()
if not receipt:raise RuntimeError((a.out/'launcher.log').read_text())
if closed is None:failure=failure or 'unexpected_early_exit'
run=Path(receipt['logs'])
for _ in range(30):
    if (run/'exit.json').exists():break
    time.sleep(.1)
exit_info=json.loads((run/'exit.json').read_text(encoding='utf-8-sig'));clock=run/'clock.csv'
if clock.exists():
    subprocess.run([sys.executable,str(ROOT/'tools/analyze_game_clock.py'),str(clock),'--out',str(a.out/'clock-analysis.json')],check=True)
    (a.out/'clock.csv').write_bytes(clock.read_bytes())
functional=bool(trigger) and (a.mode!='soak' or (len(positions)>=8 and controller_reports>=10)) and (a.mode!='interact-quit' or (mainmenu and (pickup or message)))
result=dict(receipt=receipt,mode=a.mode,seconds=a.seconds,rooms=sorted(rooms),unique_positions=len(positions),controller_reports=controller_reports,pickup=pickup,message=message,mainmenu=mainmenu,failure=failure,exit=exit_info,passed=not failure and functional and exit_info['exitCode']==0)
(a.out/'result.json').write_text(json.dumps(result,indent=2));print(json.dumps(result,indent=2));sys.exit(0 if result['passed'] else 1)
