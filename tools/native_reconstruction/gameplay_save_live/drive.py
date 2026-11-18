"""Source-identified ordinary private-pad steering and passive save UI evidence.
Attach only to the exact launcher-owned identity in a NEW private case. No RAM
writes, suspension, global keys, focus/window writes, or screenshots are used.
"""
import argparse,ctypes,hashlib,json,math,os,struct,sys,time
from contextlib import closing
from pathlib import Path
from ctypes import wintypes as w
ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT/'tools/coop_playtest'))
import coop_playtest as owned
from lobby_driver import GuestRam
from inventory import audit,ROOT_HANDLERS,OVERLAY_SHA,ELF_SHA
RAM=0x2000000

def phys(at,n):
 bank=at&0xfe000000;p=at&0x1fffffff
 if bank not in [0,0x20000000,0x80000000,0xa0000000]or p>=RAM or n>RAM-p:raise ValueError('Observed guest pointer exceeds admitted banks/bounds')
 return p

def main():
 p=argparse.ArgumentParser();p.add_argument('--case',type=Path,required=True);p.add_argument('--expected-exe-sha',required=True);p.add_argument('--mode',choices=['observe','menu-save-load','menu-policy','autoload-error','gameplay-options'],required=True);p.add_argument('--seconds',type=int,default=300);a=p.parse_args();case=a.case.resolve();assert case.is_relative_to(ROOT/'build-native-sjuni/native-gameplay/live')and 30<=a.seconds<=900 and not(case/'driver.json').exists()
 end=time.monotonic()+180
 while not(case/'running.json').exists():
  if time.monotonic()>end:raise TimeoutError('Owned helper did not publish a running identity')
  time.sleep(.1)
 budget_started=time.monotonic();observation_deadline=budget_started+a.seconds
 run=json.loads((case/'running.json').read_bytes());identity={k:run[k]for k in ['pid','image','creationFileTime']};folder=Path(run['logs']).resolve();home=(ROOT/'build-native-sjuni/launcher-native-prep-v1').resolve();assert run['background']and Path(run['card']).resolve()==case/'card' and folder.is_relative_to(home/'sessions')and Path(identity['image']).resolve().is_relative_to(home/'game-cache')and owned.process_identity(identity['pid'])==identity and owned.digest(Path(identity['image']))==a.expected_exe_sha==run['executable_sha256']
 launch=json.loads((folder/'launch.json').read_bytes());elf=Path(launch['discRoot'])/'SLUS_207.65';assert owned.digest(elf)==ELF_SHA
 # Running identity is published immediately after Process.Start, before RAM
 # allocation/load. Reuse the qualified monitor's actual recorder handshake.
 startup=time.monotonic()+120
 while True:
  if owned.process_identity(identity['pid'])!=identity:raise RuntimeError('Owned process changed before native readiness')
  stderr=(folder/'stderr.log').read_text(errors='replace');stdout=(folder/'stdout.log').read_text(errors='replace')
  if '[NATIVE-GAMEPLAY-SAVE-ERROR]'in stderr:raise RuntimeError('Native save/session admission failed before observation')
  selected='[NATIVE-GAMEPLAY-SAVE] nine native save/session entries installed'in stdout
  if '[NATIVE-ADXT] ordinary-file binding selected'in stderr and (not run['native_gameplay_save_requested']or selected):break
  if time.monotonic()>min(startup,observation_deadline):raise TimeoutError('Actual native startup handshakes missing within case budget; no RAM attachment attempted')
  time.sleep(.1)
 inventory=audit();(case/'source-inventory.json').write_text(json.dumps(inventory,indent=2)+'\n');overlay=ROOT/'build-function-index/owned-overlays/o1.bin';assert owned.digest(overlay)==OVERLAY_SHA;signature=overlay.read_bytes()[0xf1f0:0xf210]
 gameplay_proof=None
 if a.mode=='gameplay-options':
  from gameplay_source import audit as gameplay_audit
  from default_route_source import audit as default_route_audit
  assert run['route']=='gameplay-manual'and run['fixture_scenario']==0
  gameplay_proof=gameplay_audit();(case/'gameplay-source-inventory.json').write_text(json.dumps(gameplay_proof,indent=2)+'\n')
  default_route_proof=default_route_audit();(case/'default-route-source-inventory.json').write_text(json.dumps(default_route_proof,indent=2)+'\n')
 u=ctypes.WinDLL('user32',use_last_error=True);callback=ctypes.WINFUNCTYPE(w.BOOL,w.HWND,w.LPARAM);u.EnumWindows.argtypes=[callback,w.LPARAM];u.EnumWindows.restype=w.BOOL;u.GetWindowThreadProcessId.argtypes=[w.HWND,ctypes.POINTER(w.DWORD)];u.GetWindowThreadProcessId.restype=w.DWORD;u.IsIconic.argtypes=[w.HWND];u.IsIconic.restype=w.BOOL;u.IsWindowVisible.argtypes=[w.HWND];u.IsWindowVisible.restype=w.BOOL;u.GetForegroundWindow.restype=w.HWND
 def windows():
  result=[]
  @callback
  def visit(hwnd,_):
   pid=w.DWORD();u.GetWindowThreadProcessId(hwnd,ctypes.byref(pid))
   if pid.value==identity['pid']:result.append(dict(hwnd=int(hwnd),iconic=bool(u.IsIconic(hwnd)),visible=bool(u.IsWindowVisible(hwnd)),foreground=u.GetForegroundWindow()==hwnd))
   return True
  if not u.EnumWindows(visit,0):raise ctypes.WinError(ctypes.get_last_error())
  return result
 started=time.monotonic();stage='save'if a.mode=='menu-save-load'else'enable-policy'if a.mode=='menu-policy'else'wait-gameplay'if a.mode=='gameplay-options'else'observe';changed=False;write_success=False;load_success=False;policy_success=False;error_seen=False;baseline=None;next_action=0;actions=[];last=None;rows=0;observed_handlers=set();finished=False;movement_origin=None;movement_attempt=0;movement_axis=[(23000,0),(-23000,0),(0,23000),(0,-23000)];snapshot_deadline=None;default_route_takeover=False;next_route_log_read=0
 report=dict(schema=1,status='running',startup_seconds=time.monotonic()-budget_started,deadline_origin='running identity before startup wait',identity=identity,exe_sha256=a.expected_exe_sha,mode=a.mode,source_sha256=owned.digest(Path(__file__)),guest_writes=False,threads_suspended=False,global_keyboard_input=False,focus_requested=False,window_writes=False,desktop_capture=False,actions=actions,observed_handlers=[],coverage_interpretation='Handler identity is inferred from source-verified root state plus independent native entry evidence; no guest PC sample or direct callsite trace is claimed.')
 control=case/'input.json'
 def publish(button,reason,state,x=0,y=0,duration=.2):
  nonlocal next_action
  assert owned.process_identity(identity['pid'])==identity
  assert -32768<=x<=32767 and -32768<=y<=32767 and 0<duration<=1
  owned.save(control,dict(buttons=button,leftX=x,leftY=y,expiresUnix=time.time()+duration,nonce=run['input_nonce']));actions.append(dict(seconds=time.monotonic()-started,button=hex(button),leftX=x,leftY=y,duration=duration,reason=reason,before=state));next_action=time.monotonic()+max(.7,duration+.2)
 def neutral():
  owned.save(control,dict(buttons=0,leftX=0,leftY=0,expiresUnix=time.time()+.05,nonce=run['input_nonce']))
 def current_identity():
  try:return owned.process_identity(identity['pid'])
  except OSError:return None
 try:
  with closing(GuestRam(identity,str(elf)))as reader,(case/'observations.jsonl').open('x',encoding='utf8')as stream:
   def sample():
    reader.check();r=dict(seconds=time.monotonic()-started,unix=time.time(),windows=windows(),room=list(struct.unpack('<HH',reader.read(0x3243da,4))),profile_flag=reader.read(0x324476,1)[0],saved_options=reader.read(0x3241a0,16).hex(),brightness=reader.read(0x3243f0,1)[0]);backend=reader.read(0x326c50,0xac);r['backend']=dict(result=struct.unpack_from('<i',backend,0x24)[0],task=struct.unpack_from('<I',backend,0x98)[0],busy=struct.unpack_from('<I',backend,0xa8)[0])
    raw=struct.unpack('<I',reader.read(0x326f10,4))[0]
    if raw:
     try:
      address=phys(raw,0xf4);b=reader.read(address,0xf4);selfptr,outptr,inptr=struct.unpack_from('<III',b,0xe4)
      if selfptr==raw and outptr==raw+0x100 and inptr==raw+0x40100:
       r['card']=dict(pointer=raw,route=b[1],phase=b[2],nested=b[3],root_mode=struct.unpack_from('<I',b,0x20)[0],root_submode=struct.unpack_from('<I',b,0x1c)[0],message=struct.unpack_from('<I',b,0x2c)[0],yes_no=struct.unpack_from('<I',b,0x30)[0],result_detail=struct.unpack_from('<I',b,0x34)[0],selection=struct.unpack_from('<I',b,0x38)[0],pending=struct.unpack_from('<I',b,0x3c)[0],asset_ready=struct.unpack_from('<I',b,0x40)[0],input=list(struct.unpack_from('<3H',b,8)),outgoing=outptr,incoming=inptr,stable=reader.read(address,16)==b[:16])
     except ValueError:pass
    if gameplay_proof:r['original_phase']=list(reader.read(0x4badd0,2))
    if reader.read(0x57f1f0,32)==signature:
     titleptr=struct.unpack('<I',reader.read(0x5d4898,4))[0]
     if 0x10000<=titleptr<=RAM-0x220:
      b=reader.read(titleptr,0x74);r['title']=dict(pointer=titleptr,primary=b[0],secondary=b[1],selection=b[0xc],submenu=struct.unpack_from('<I',b,0x64)[0],stable=reader.read(titleptr,16)==b[:16])
     optionptr=struct.unpack('<I',reader.read(0x594390,4))[0]
     if 0x10000<=optionptr<=RAM-0x188:
      b=reader.read(optionptr,0x188);r['options']=dict(pointer=optionptr,root_state=b[1],substate=b[2],nested=b[3],row=struct.unpack_from('<H',b,4)[0],subrow=struct.unpack_from('<H',b,6)[0],brightness=b[0x11],row_count=struct.unpack_from('<I',b,0x168)[0],stable=reader.read(optionptr,16)==b[:16])
     if gameplay_proof:
      ptr=struct.unpack('<I',reader.read(0x32442c,4))[0]
      if 0x10000<=ptr<=RAM-0x264 and ptr%4==0:
       b=reader.read(ptr,0x24);s=struct.unpack_from('<I',b,4)[0];r['frontend_selection']=dict(pointer=ptr,state=s,ready=struct.unpack_from('<I',b,0x20)[0]==0,stable=reader.read(ptr,0x24)==b and struct.unpack('<I',reader.read(0x32442c,4))[0]==ptr)
       if s&0xffff==0x0108:r['frontend_selection'].update(zip(['count','cursor'],struct.unpack('<II',reader.read(ptr+0x25c,8))))
    if gameplay_proof and reader.read(0x6ecde0,32)==bytes.fromhex(gameplay_proof['source_code_signature']['bytes']):
     phase=reader.read(0x4badd0,0xc0);menu=reader.read(0x755ec0,5)
     g=dict(phase=phase[0],modal=phase[0x1e],paused=phase[0x28],gameplay_pause=reader.read(0x4bae94,1)[0],ui_kind=menu[4],menu_state=menu[0],menu_row=menu[1],menu_substate=menu[2],menu_choice=menu[3],input_mode=reader.read(0x3243f2,1)[0],launch_humans=reader.read(0x316684,1)[0],live_options=[reader.read(at,1)[0]for at in [0x3243c5,0x3243c9,0x3243ca,0x3243ec,0x3243ef,0x3243f0,0x3243ed,0x3243ee]],ready=False)
     slots=[]
     if g['phase']==2 and r['room'][0]==1 and g['input_mode']==0 and g['launch_humans']==1:
      for slot in range(4):
       at=0x4a5c30+slot*0x10e0;b=reader.read(at,4)
       if b[0]==1 and b[3]==slot and reader.read(at+0xff0,1)[0]==0:slots.append(slot)
      if len(slots)==1:
       at=0x4a5c30+slots[0]*0x10e0;b=reader.read(at,0xbd1);g.update(slot=slots[0],x=struct.unpack_from('<f',b,0x38)[0],z=struct.unpack_from('<f',b,0x40)[0],actor_state=b[8:12].hex(),inhibited=b[0xbd0])
       assert math.isfinite(g['x'])and math.isfinite(g['z'])
       g['ready']=not(g['modal']or g['paused']or g['gameplay_pause']or g['ui_kind']or b[0xbd0]or phase[0xbd])
     g['human_slots']=slots;g['stable']=reader.read(0x755ec0,5)==menu and reader.read(0x4badd0,1)[0]==phase[0];r['gameplay']=g
    reader.check();return r
   while time.monotonic()<observation_deadline:
    if current_identity()!=identity:
     report['owned_process_ended']=True
     if not finished:report['status']='owned game ended before the requested route completed'
     break
    try:r=sample()
    except(OSError,ValueError)as error:
     if current_identity()!=identity:
      report['owned_process_ended']=True
      if not finished:report['status']='owned game ended before the requested route completed'
      break
     raise
    rows+=1;last=r;stream.write(json.dumps(r,separators=(',',':'))+'\n');stream.flush()
    if any(v['foreground']for v in r['windows']):raise RuntimeError('Owned game became foreground; input stopped without changing windows')
    c=r.get('card');o=r.get('options');t=r.get('title');active=bool(o and o['stable']and o['root_state']==5 and o['row']==4 and o['substate']in [5,7])
    if c and c['stable']and(active or a.mode=='autoload-error'and c['route']==1):
     if c['route']in ROOT_HANDLERS:observed_handlers.add(hex(ROOT_HANDLERS[c['route']]))
     if c['route']==2 and c['phase']==6 and c['message']==0x15 and c['result_detail']==0 and r['backend']['result']==0:write_success=True
     if c['route']==4 and c['phase']==0x62 and c['message']==0x24 and c['result_detail']==0 and r['backend']['result']==0:write_success=True
     if c['route']==3 and c['phase']==5 and c['message']==0x20 and c['result_detail']==0 and r['backend']['result']==0:load_success=True
     if c['route']==5 and c['phase']==5 and c['message']==0x15 and c['result_detail']==0 and r['backend']['result']==0:policy_success=True
     if c['route']==1 and c['phase']==3 and c['message']==0x39:error_seen=True
    if time.monotonic()<next_action:time.sleep(.1);continue
    if len(actions)>=100:raise RuntimeError('Bounded ordinary input budget exhausted; route remains incomplete')
    if a.mode=='observe' or finished:time.sleep(.1);continue
    if a.mode=='gameplay-options':
     g=r.get('gameplay')
     if stage=='wait-gameplay'and not(g and g['ready']):
      if not default_route_takeover and time.monotonic()>=next_route_log_read:
       next_route_log_read=time.monotonic()+1
       if default_route_proof['takeover_required_log']in(folder/'stderr.log').read_text(errors='strict'):
        default_route_takeover=True;report['default_route_takeover']=dict(seconds=r['seconds'],reason='Optional all-five-chapter selector explicitly disabled; ordinary pad confirms only admitted default chapter0/count1')
      if default_route_takeover:
       front=r.get('frontend_selection');phase=r['original_phase']
       if phase[0]==0x0e and phase[1]in [4,8]:publish(0x10,'original cinematic START skip in admitted substate',r)
       elif front and front['stable']:
        state=front['state']&0xffff
        if state in [0x030a,0x050b]:publish(0x1000,'ordinary original mode/difficulty confirmation without unrelated +20 timer gate',r)
        elif state==0x0108 and front['ready']:
         if front.get('count')!=1 or front.get('cursor')!=0:raise RuntimeError('Unadmitted default chapter cursor/count; no unlocks or cursor writes attempted')
         publish(0x1000,'ordinary default unlocked chapter0 confirmation',r)
        elif state==0x0109 and front['ready']:publish(0x1000,'ordinary original character confirmation',r)
      time.sleep(.1);continue
     if not g or not g['stable']:time.sleep(.1);continue
     if stage=='wait-gameplay'and g['ready']:
      report['initial_gameplay']=r;baseline=r['brightness'];movement_attempt=0;stage='before-movement'
     if stage in ['before-movement','after-movement']and g['ready']:
      if movement_origin is not None:
       distance=math.hypot(g['x']-movement_origin['gameplay']['x'],g['z']-movement_origin['gameplay']['z'])
       report.setdefault('movement_checks',[]).append(dict(stage=stage,before=movement_origin,after=r,distance=distance))
       movement_origin=None
       if distance>3:
        if stage=='before-movement':stage='open-options';movement_attempt=0
        else:finished=True;report['status']='ordinary gameplay movement, options edit/native snapshot and resumed movement observed'
       else:movement_attempt+=1
      if not finished and stage in ['before-movement','after-movement']:
       if movement_attempt>=len(movement_axis):raise RuntimeError('Ordinary movement not established within four bounded axes')
       x,y=movement_axis[movement_attempt];movement_origin=r;publish(0,'bounded ordinary movement '+stage,r,x,y,.65)
     elif stage=='open-options'and g['ready']:publish(0x20,'ordinary SELECT opens in-game options',r);stage='edit-gameplay-option'
     elif stage=='edit-gameplay-option'and g['ui_kind']==4 and g['menu_state']==1 and g['menu_substate']==0:
      assert g['live_options'][3]==0,'Only source-admitted default controller profile0 is steered'
      if g['menu_row']!=5:publish(1 if g['menu_row']>5 else 2,'navigate original in-game brightness row5',r)
      elif r['brightness']==baseline:publish(8 if baseline<164 else 4,'change original in-game brightness option',r)
      else:
       if bytes.fromhex(r['saved_options'])[:8]!=bytes(g['live_options'])or r['brightness']!=g['live_options'][5]:
        snapshot_deadline=snapshot_deadline or time.monotonic()+5
        report['option_snapshot_noncoherent_observations']=report.get('option_snapshot_noncoherent_observations',0)+1
        if time.monotonic()>snapshot_deadline:raise RuntimeError('Native saved option snapshot did not converge within five seconds')
        time.sleep(.1);continue
       changed=True;report['changed_gameplay_option']=r;snapshot_deadline=None
       stage='exit-gameplay-options'
     elif stage=='exit-gameplay-options'and g['ui_kind']==4 and g['menu_state']==1 and g['menu_substate']==0:
      if g['menu_row']!=10:publish(2 if g['menu_row']<10 else 1,'navigate original in-game EXIT row10',r)
      else:publish(0x1000,'source-admitted profile0 EXIT confirmation',r);stage='wait-resumed-gameplay'
     elif stage=='wait-resumed-gameplay'and g['ready']:
      if not changed or r['brightness']==baseline or bytes.fromhex(r['saved_options'])[:8]!=bytes(g['live_options']):raise RuntimeError('Resumed native option snapshot was not retained')
      report['resumed_gameplay']=r;stage='after-movement';movement_attempt=0;movement_origin=None
     time.sleep(.1);continue
    if a.mode=='autoload-error':
     if c and c['stable']and c['route']==1 and c['phase']==3:
      publish(4 if c['selection']else 0x1000,'choose finish on autoload retry/error dialog',r)
     elif error_seen and t and t['stable']and t['primary']==1 and t['secondary']==5:finished=True;report['status']='autoload error acknowledged back to title menu'
     time.sleep(.1);continue
    if active and c and c['stable']:
     if c['yes_no']:publish(4 if c['selection']else 0x1000,'accept current private-card confirmation',r)
     elif(c['route']==2 and c['phase']in [6,0x63]or c['route']==3 and c['phase']in [4,5]or c['route']==5 and c['phase']in [5,0x63]or c['route']==4 and c['phase']==0x63):publish(0x1000,'acknowledge source-verified terminal private-card result',r)
     time.sleep(.1);continue
    if t and t['stable']and t['primary']==1 and t['secondary']==5:
     publish(2 if t['selection']<4 else 1 if t['selection']>4 else 0x1000,'navigate original title OPTIONS row',r);time.sleep(.1);continue
    if not(o and o['stable']):time.sleep(.1);continue
    if a.mode=='menu-save-load':
     if stage=='save'and write_success and o['root_state']==5 and o['substate']==2:stage='leave-save-page';baseline=r['brightness']
     if stage=='leave-save-page':
      if o['root_state']==5 and o['substate']==2:publish(0x2000,'leave save/load after successful save',r)
      elif o['root_state']==3:stage='brightness'
     elif stage=='brightness':
      if o['root_state']==3:publish(2 if o['row']<2 else 1 if o['row']>2 else 0x1000,'open brightness using original options menu',r)
      elif o['root_state']==5 and o['row']==2 and o['substate']==3:
       if baseline is None:baseline=r['brightness']
       if not changed and o['brightness']==baseline:publish(8 if baseline<164 else 4,'change private live option before reload',r)
       else:changed=True;publish(0x2000,'commit changed brightness through original menu',r);stage='return-save-page'
     elif stage=='return-save-page':
      if o['root_state']==3:stage='load'
     elif stage in ['save','load']:
      if stage=='load'and load_success and o['root_state']==5 and o['substate']==2:
       if not changed or r['brightness']!=baseline:raise RuntimeError('Loaded options did not restore the saved brightness')
       finished=True;report['status']='ordinary menu save, option change, load and option restoration observed'
      elif o['root_state']==3:publish(2 if o['row']<4 else 1 if o['row']>4 else 0x1000,'open original SAVE/LOAD page',r)
      elif o['root_state']==5 and o['row']==4 and o['substate']==2:
       goal=0 if stage=='save'else 1;publish(2 if o['subrow']<goal else 1 if o['subrow']>goal else 0x1000,'select original SAVE DATA or LOAD DATA',r)
    elif a.mode=='menu-policy':
     if stage=='enable-policy'and policy_success and r['profile_flag']==1 and o['substate']==2:stage='automatic-save';write_success=False
     if stage=='automatic-save'and write_success and o['root_state']==5 and o['substate']==2:finished=True;report['status']='ordinary save-policy and automatic-save UI success observed'
     elif o['root_state']==3:publish(2 if o['row']<4 else 1 if o['row']>4 else 0x1000,'open original SAVE/LOAD page',r)
     elif o['root_state']==5 and o['row']==4 and o['substate']==2:
      goal=2 if stage=='enable-policy'else 0
      if o['subrow']!=goal:publish(2 if o['subrow']<goal else 1,'select AUTO SAVE or SAVE DATA row',r)
      elif stage=='enable-policy':publish(8 if r['profile_flag']==0 else 4,'ordinary autosave policy toggle',r)
      else:publish(0x1000,'ordinary automatic save request',r)
    time.sleep(.1)
   else:
    if a.mode=='observe':report['status']='bounded passive observations completed'
    elif not finished:report['status']='bounded ordinary route incomplete'
 except BaseException as error:report['status']='failed';report['error']=repr(error);raise
 finally:
  try:neutral()
  except OSError:pass
  report.update(rows=rows,stage=stage,finished=finished,write_success=write_success,load_success=load_success,policy_success=policy_success,autoload_error_seen=error_seen,brightness_changed=changed,saved_brightness=baseline,last=last,observed_handlers=sorted(observed_handlers),elapsed_seconds=time.monotonic()-started)
  (case/'driver.json').write_text(json.dumps(report,indent=2)+'\n')
 print(json.dumps({k:v for k,v in report.items()if k not in ['actions','last']}))
 if a.mode!='observe'and not finished:raise SystemExit(2)
if __name__=='__main__':main()
