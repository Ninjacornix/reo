"""Summarize COMPLETED owned save cases without accessing a live process."""
import argparse,hashlib,json,re
from pathlib import Path
from run import card_manifest

ROOT=Path(__file__).resolve().parents[3]
BOUNDARY=ROOT/'build-native-sjuni/native-gameplay/live'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def summarize(label):
 case=(BOUNDARY/label).resolve()
 if not case.is_relative_to(BOUNDARY) or not(case/'check.json').is_file():
  raise ValueError('Only completed labelled private cases are admitted')
 runner=json.loads((case/'runner.json').read_bytes())
 if runner['status']=='running':raise ValueError('Case is not finalized')
 check=json.loads((case/'check.json').read_bytes());driver=json.loads((case/'driver.json').read_bytes())
 observations=case/'observations.jsonl'
 if observations.is_file():rows=[json.loads(line)for line in observations.read_text().splitlines()]
 elif runner['status']=='failed':rows=[]
 else:raise ValueError('Successful case is missing its observations')
 native=json.loads((case/'native-observations.json').read_bytes())if(case/'native-observations.json').exists()else None
 logs=Path(check['logs']).resolve()
 if not logs.is_relative_to(ROOT/'build-native-sjuni/launcher-native-prep-v1/sessions'):
  raise ValueError('Unexpected evidence directory')
 launch=json.loads((logs/'launch.json').read_bytes())
 if Path(launch['memoryCard']).resolve()!=case/'card' or launch['networkConfigured']:
  raise ValueError('Case did not select its isolated offline private card')
 paths=[case/n for n in ['runner.json','check.json','running.json','driver.json','observations.jsonl','native-observations.json','source-inventory.json','gameplay-source-inventory.json','default-route-source-inventory.json','preparation-at-launch.json']if(case/n).is_file()]
 paths += [logs/n for n in ['launch.json','stdout.log','stderr.log']if(logs/n).is_file()]
 stderr=(logs/'stderr.log').read_text(encoding='utf8',errors='strict')
 report_prefixes=['[NATIVE-AUDIO-SERVICE-REPORT]','[NATIVE-ADXT-SOURCE-REPORT]','[NATIVE-AUDIO-REPORT]','[NATIVE-AUDIO-CUE-REPORT]','[NATIVE-HOST-MOVIE-REPORT]']
 media_reports={prefix:[line for line in stderr.splitlines()if line.startswith(prefix)]for prefix in report_prefixes}
 audio=media_reports['[NATIVE-AUDIO-REPORT]']
 audio_fields=dict(re.findall(r'(\w+)=([^ ]+)',audio[-1]))if audio else {}
 gameplay_rows=[r for r in rows if r.get('gameplay',{}).get('stable')]
 gameplay_options=[r for r in gameplay_rows if r['gameplay']['ui_kind']==4 and r['gameplay']['menu_state']==1]
 gameplay_metrics=dict(stable_rows=len(gameplay_rows),ready_rows=sum(r['gameplay']['ready']for r in gameplay_rows),options_rows=len(gameplay_options),options_snapshot_matching_rows=sum(bytes.fromhex(r['saved_options'])[:8]==bytes(r['gameplay']['live_options'])for r in gameplay_options))
 card_states=sorted({(r['card']['route'],r['card']['phase'],r['card']['message'],r['card']['result_detail'],r['backend']['result'])for r in rows if 'card'in r})
 milestones={}
 for r in rows:
  c=r.get('card',{});o=r.get('options',{})
  if c.get('stable')and c.get('route')==1:
   milestones.setdefault('boot_autoload_route',dict(seconds=r['seconds'],phase=c['phase'],message=c['message']))
   if c['phase']==3 and c['message']==0x39:milestones.setdefault('boot_decode_error_dialog',dict(seconds=r['seconds'],message=c['message'],backend_result=r['backend']['result']))
  t=r.get('title',{})
  if t.get('stable')and t.get('primary')==1 and t.get('secondary')==5:
   milestones.setdefault('interactive_title_menu',dict(seconds=r['seconds'],brightness=r['brightness']))
  if c.get('stable')and c.get('result_detail')==0 and r['backend']['result']==0:
   for name,route,phase,message in [('manual_save',2,6,0x15),('explicit_load',3,5,0x20),('policy_save',5,5,0x15),('automatic_save',4,0x62,0x24)]:
    if(c['route'],c['phase'],c['message'])==(route,phase,message):milestones.setdefault(name,dict(seconds=r['seconds'],brightness=r['brightness'],saved_options=r['saved_options']))
  if o.get('stable')and driver.get('saved_brightness')is not None and r['brightness']!=driver['saved_brightness']:
   milestones.setdefault('ordinary_option_changed',dict(seconds=r['seconds'],brightness=r['brightness']))
 return dict(label=label,session=logs.name,status=runner['status'],failure=runner.get('failure'),
  selected=runner['selection'],mode=runner['mode'],check=check,launch_private_card=launch['memoryCard'],launch_candidate_sha256=launch['sha256'],final_media_report_lines=media_reports,final_audio_fields=audio_fields,
  native_totals=native['totals']if native else None,native_capture_orders=native['capture_orders']if native else None,
  native_restore_orders=native['restore_orders']if native else None,trace_overwritten=native['trace_overwritten']if native else None,
  native_joins={k:v['join']for k,v in native['groups'].items()}if native else None,
  observed_rows=len(rows),foreground_rows=sum(any(w['foreground']for w in r['windows'])for r in rows),
  minimized_visible_rows=sum(any(w['visible']and w['iconic']for w in r['windows'])for r in rows),
  brightness_values=sorted({r['brightness']for r in rows}),saved_options_values=sorted({r['saved_options']for r in rows}),
  first_brightness=rows[0]['brightness']if rows else None,last_brightness=rows[-1]['brightness']if rows else None,
  observed_card_states=card_states,source_identified_ui_milestones=milestones,gameplay_metrics=gameplay_metrics,driver={k:v for k,v in driver.items()if k not in ['actions','last','identity']},
  input_actions=len(driver['actions']),before_card=runner['before_card'],after_card=runner.get('after_card'),final_private_card=card_manifest(case/'card'),corruption=runner.get('corruption'),
  evidence_sha256={str(p.relative_to(ROOT)):sha(p)for p in paths})

def main():
 p=argparse.ArgumentParser();p.add_argument('--label',action='append',required=True);p.add_argument('--out',type=Path,required=True);a=p.parse_args()
 if a.out.exists():raise ValueError('Preserve prior analysis; output must be NEW')
 result=dict(schema=1,offline_only=True,source_sha256=sha(Path(__file__)),cases=[summarize(n)for n in a.label])
 a.out.parent.mkdir(parents=True,exist_ok=True);a.out.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(dict(path=str(a.out),sha256=sha(a.out),cases=[dict(label=c['label'],status=c['status'])for c in result['cases']])))

if __name__=='__main__':main()
