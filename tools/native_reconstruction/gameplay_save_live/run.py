"""Explicitly run one sealed-candidate private background save case.
Not used during preparation; root must supply the approved executable identity.
"""
import argparse,hashlib,json,os,re,shutil,subprocess,sys,time
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT/'tools/native_reconstruction/gameplay_adapter'))
from observations import parse
HERE=Path(__file__).resolve().parent
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def card_manifest(path):
 result={};total=0
 pending=[path]
 while pending:
  at=pending.pop();attrs=at.lstat()
  if at.is_symlink()or getattr(attrs,'st_file_attributes',0)&0x400:raise ValueError('Private card contains a link/reparse point')
  for entry in sorted(at.iterdir()):
   attrs=entry.lstat()
   if entry.is_symlink()or getattr(attrs,'st_file_attributes',0)&0x400:raise ValueError('Private card contains a link/reparse point')
   if entry.is_dir():pending.append(entry)
   elif entry.is_file():
    total+=attrs.st_size
    if total>64*1024*1024:raise ValueError('Private card exceeds bounded fixture budget')
    result[entry.relative_to(path).as_posix()]=dict(bytes=attrs.st_size,sha256=sha(entry))
 return result

def main():
 p=argparse.ArgumentParser();p.add_argument('--label',required=True);p.add_argument('--exe',type=Path,required=True);p.add_argument('--expected-exe-sha',required=True);p.add_argument('--helper-dll',type=Path,required=True);p.add_argument('--expected-helper-sha',required=True);p.add_argument('--mode',choices=['quiet','menu-save-load','menu-policy','autoload-error','gameplay-options'],required=True);p.add_argument('--selection',choices=['native','legacy'],required=True);p.add_argument('--route',choices=['main-menu','character','gameplay-manual'],default='main-menu');p.add_argument('--seconds',type=int,default=300);p.add_argument('--seed-card',type=Path);p.add_argument('--corrupt',choices=['checksum','magic']);a=p.parse_args()
 if not re.fullmatch('[a-zA-Z0-9-]+',a.label)or not 60<=a.seconds<=900:raise ValueError('Bounded labelled case required')
 if a.corrupt and not a.seed_card:raise ValueError('Corruption requires a copy of an actual successful private card')
 if a.mode=='gameplay-options'and(a.route!='gameplay-manual'or a.selection!='native'or a.seed_card or a.corrupt):raise ValueError('Gameplay options requires selected native ordinary gameplay route and a fresh card')
 home=ROOT/'build-native-sjuni/launcher-native-prep-v1';boundary=ROOT/'build-native-sjuni/native-gameplay/live';case=boundary/a.label;exe=a.exe.resolve();helper=a.helper_dll.resolve()
 if case.exists()or sha(exe)!=a.expected_exe_sha or sha(helper)!=a.expected_helper_sha:raise ValueError('Fresh case and approved source/helper identities required')
 if not helper.is_relative_to(ROOT/'build-native-sjuni')or not(home/'fixture-cache-reuse.json').exists():raise ValueError('Owned qualified private helper and cache fixture required')
 qualification=json.loads((ROOT/'tools/native_reconstruction/native_gameplay_save_live_preparation_qualification.json').read_bytes())
 qualified_files={str((ROOT/name).resolve()):digest for name,digest in qualification['helper_outputs_sha256'].items()}
 if qualified_files.get(str(helper))!=a.expected_helper_sha:raise ValueError('Helper must match its qualified controller/core/dependency cohort')
 for name,digest in qualified_files.items():
  path=Path(name)
  if path.parent==helper.parent and sha(path)!=digest:raise ValueError('Qualified helper/controller/dependency drift: '+path.name)
 for name,digest in qualification['game_sources_sha256'].items():
  if sha(ROOT/name)!=digest:raise ValueError('Qualified save driver/source drift: '+name)
 if(home/'native-game-session-running.json').exists():raise ValueError('Archive prior launcher fixture before a new case; this runner never deletes its evidence')
 # A different private save case must not still be active. Only inspect exact
 # identities from this owned case tree; never attach by name/PID alone.
 sys.path.insert(0,str(ROOT/'tools/coop_playtest'));import coop_playtest as owned
 for r in boundary.glob('*/running.json'):
  old=json.loads(r.read_bytes());identity={k:old[k]for k in ['pid','image','creationFileTime']}
  try:current=owned.process_identity(identity['pid'])
  except OSError:current=None
  if current==identity:raise ValueError('Another exact owned private case is still running')
 case.mkdir(parents=True);card=case/'card';card.mkdir();seed_before=None
 if a.seed_card:
  seed=a.seed_card.resolve()
  if not seed.is_relative_to(boundary)or seed==card:raise ValueError('Seed only from a previous owned private case')
  seed_before=card_manifest(seed)
  for name,row in seed_before.items():
   destination=card/name;destination.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(seed/name,destination)
 before=card_manifest(card);corruption=None
 if a.corrupt:
  matches=[]
  for path in card.rglob('*'):
   if path.is_file()and path.stat().st_size==0x3fcc8:
    with path.open('rb')as f:magic=f.read(2)
    if magic==b'\x63\x59':matches.append(path)
  if len(matches)!=1:raise ValueError('Expected one actual manifest0 primary file with verified container magic/size')
  target=matches[0];prior=target.read_bytes();after=bytearray(prior);offset=4 if a.corrupt=='checksum'else 0;after[offset]^=1;target.write_bytes(after);assert after[0x3fcc0:]==prior[0x3fcc0:]
  corruption=dict(path=target.relative_to(card).as_posix(),kind=a.corrupt,offset=offset,before_sha256=hashlib.sha256(prior).hexdigest(),after_sha256=sha(target),extra_eight_file_bytes_preserved=True)
 env=dict(os.environ);env['DOTNET_ROOT']='C:/Users/Ninjacornix/.dotnet';dotnet=Path(env['DOTNET_ROOT'])/'dotnet.exe';iso=ROOT/'iso/Resident Evil - Outbreak (v2.00).iso'
 command=list(map(str,[dotnet,helper,'--run',ROOT,exe,a.expected_exe_sha,iso,home,case,card,a.seconds,a.route,a.selection]));record=dict(schema=1,status='running',command=command,exe_sha256=a.expected_exe_sha,helper_sha256=a.expected_helper_sha,runner_sha256=sha(Path(__file__)),mode=a.mode,selection=a.selection,before_card=before,corruption=corruption,game_launch_requested=True,global_keyboard_input=False,guest_writes=False,focus_requested=False,desktop_capture=False)
 def save():(case/'runner.json').write_text(json.dumps(record,indent=2)+'\n')
 save();driver=None;started=time.monotonic()
 with(case/'helper.stdout.txt').open('x')as out,(case/'helper.stderr.txt').open('x')as err:
  game=subprocess.Popen(command,env=env,cwd=ROOT,stdin=subprocess.DEVNULL,stdout=out,stderr=err,creationflags=subprocess.CREATE_NO_WINDOW)
  record['helper_pid']=game.pid;next_report=0
  try:
   while game.poll()is None:
    elapsed=time.monotonic()-started
    if elapsed>a.seconds+1100:raise TimeoutError('Bounded owned helper did not retire; inspect its exact identity before any cleanup')
    if driver is None and(case/'running.json').exists():
     mode='observe'if a.mode=='quiet'else a.mode
     driver_command=list(map(str,[sys.executable,HERE/'drive.py','--case',case,'--expected-exe-sha',a.expected_exe_sha,'--mode',mode,'--seconds',a.seconds-3]));record['driver_command']=driver_command
     driver=subprocess.Popen(driver_command,env=env,cwd=ROOT,stdin=subprocess.DEVNULL,stdout=(case/'driver.stdout.txt').open('x'),stderr=(case/'driver.stderr.txt').open('x'),creationflags=subprocess.CREATE_NO_WINDOW)
    if elapsed>=next_report:save();print(json.dumps(dict(label=a.label,seconds=round(elapsed,1),helper_running=True)),flush=True);next_report=elapsed+30
    time.sleep(.25)
   record['helper_exit']=game.returncode
   if driver is None:raise RuntimeError('No actual owned game identity was published')
   record['driver_exit']=driver.wait(timeout=30);check=json.loads((case/'check.json').read_bytes());run=json.loads((case/'running.json').read_bytes());folder=Path(check['logs']).resolve();record['check']=check
   assert check['selection_matches']and check['exit_code']==0 and not check['forced_cleanup']and check['audio_underrun_frames']==0 and check['cue_owner_joined']and check['background_handshake']and game.returncode==0
   diagnostic=parse((folder/'stderr.log').read_text(encoding='utf8',errors='strict'));(case/'native-observations.json').write_text(json.dumps(diagnostic,indent=2)+'\n');record['native_totals']=diagnostic['totals']
   if a.selection=='native':
    assert diagnostic['bindings']>=1 and all(not c['failed']and not c['rejected']for c in diagnostic['totals'].values())
    if a.mode in ['menu-save-load','menu-policy']:assert diagnostic['totals']['0x1c5410']['completed']>0
    if a.mode=='menu-save-load':assert diagnostic['totals']['0x1c55c0']['completed']>0 and diagnostic['restore_orders']>0
    if a.mode=='autoload-error':assert sum(g['join']['restore_error']for g in diagnostic['groups'].values())>0
    if a.mode=='gameplay-options':assert diagnostic['totals']['0x1aedb0']['completed']>0
   else:assert diagnostic['bindings']==0 and not check['native_gameplay_save_observed_installed']
   observed=json.loads((case/'driver.json').read_bytes());record['driver']=observed
   assert record['driver_exit']==0 and observed['rows']>0 and not any(json.loads(line)['windows']and any(w['foreground']for w in json.loads(line)['windows'])for line in(case/'observations.jsonl').read_text().splitlines())
   if a.mode!='quiet':assert observed['finished']
   record['after_card']=card_manifest(card)
   if a.mode in ['menu-save-load','menu-policy']:assert record['after_card']!=before and record['after_card']
   if a.seed_card:assert card_manifest(a.seed_card.resolve())==seed_before
   record['status']='owned bounded background case passed stated measured gates';record['elapsed_seconds']=time.monotonic()-started
  except BaseException as error:record['status']='failed';record['failure']=repr(error);raise
  finally:
   record['helper_exit']=game.poll();record['driver_exit']=driver.poll()if driver else None;save()
 print(json.dumps({k:v for k,v in record.items()if k not in ['driver','command','driver_command']}),flush=True)
if __name__=='__main__':main()
