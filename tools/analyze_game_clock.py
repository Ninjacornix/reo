"""Analyze original-game-clock CSV only; never launches or modifies the game."""
import argparse,csv,json,re,struct
from pathlib import Path
ap=argparse.ArgumentParser();ap.add_argument('csv');ap.add_argument('--out',required=True);a=ap.parse_args()
lines=Path(a.csv).read_text(encoding='utf8').splitlines();comments=[s for s in lines if s.startswith('#')]
metadata={}
for s in comments:
 for key,value in re.findall(r'([a-z_]+)=([^ ]+)',s):metadata[key]=value
rows=[{k:int(v) for k,v in r.items()} for r in csv.DictReader([s for s in lines if not s.startswith('#')])]
def eligible(r):
 return r['phase']==2 and not r['paused'] and not r['request'] and r['room']==r['cache_room'] and r['step'] in (1,2)
def identity(r):return tuple(r[k] for k in ['room','step','cache_scenario','cache_room','cache_variant'])
segments=[];breaks=[];current=[]
def flush():
 global current
 if len(current)>=2:
  first,last=current[0],current[-1];wall=(last['elapsed_ns']-first['elapsed_ns'])*1e-9;units=last['clock_units']-first['clock_units']
  if wall>0:
   segments.append({'first_row':first['n'],'last_row':last['n'],'room':first['room'],'samples':len(current),'host_seconds':wall,'game_seconds':units/60,'game_speed_ratio':units/60/wall,'ordinary_updates':units//first['step'],'ordinary_updates_per_host_second':units/first['step']/wall,'required_updates_per_host_second':60/first['step']})
 current=[]
for r in rows:
 if not eligible(r):
  flush();continue
 if current:
  prev=current[-1];why=None
  if identity(prev)!=identity(r):why='room_mode_epoch'
  elif r['n']!=prev['n']+1:why='noncontiguous_journal_rows'
  elif r['elapsed_ns']<=prev['elapsed_ns']:why='nonmonotonic_host_time'
  elif (r['clock_units']-prev['clock_units'],r['room_counter']-prev['room_counter']) not in ((0,0),(r['step'],1)):why='clock_counter_delta_not_zero_or_one_ordinary_update'
  # The hook runs for each active actor. Repeated global clock/counter values
  # across actor slots are valid observations, not additional updates.
  if why:
   breaks.append({'before':prev['n'],'after':r['n'],'reason':why,'clock_delta':r['clock_units']-prev['clock_units'],'counter_delta':r['room_counter']-prev['room_counter']});flush()
 current.append(r)
flush()
changes=[]
for prev,r in zip(rows,rows[1:]):
 if r['room']!=prev['room'] or r['request']!=prev['request'] or r['phase']!=prev['phase']:
  changes.append({'before':prev['n'],'after':r['n'],'old_room':prev['room'],'new_room':r['room'],'phase':r['phase'],'request':r['request'],'destination':r['destination'],'cache':[r['cache_scenario'],r['cache_room'],r['cache_variant']],'event_root':hex(r['event_root']),'manager':hex(r['manager']),'skeleton':hex(r['skeleton']),'classification':'observed_fields_not_completed_render_or_event_contents_proof'})
output={'classification':'global_original_clock_progress_sampled_during_active_actor_updates_not_host_presents','metadata':metadata,'rows':len(rows),'segments':segments,'breaks':breaks,'observed_room_request_changes':changes,'limitations':['clock is sampled before each active actor update, endpoints are censored; the slot field is the current actor-loop slot, not a permanent player identity','no hook rows occur while actor updates stop during loading','snapshot/event contents and fresh destination image still require coordinator capture','dropped/invalid/unpublished records or reset/room/pause/mode changes cannot be treated as continuous epochs']}
Path(a.out).write_text(json.dumps(output,indent=2)+'\n',encoding='utf8');print(json.dumps({'rows':len(rows),'segments':len(segments),'breaks':len(breaks),'changes':len(changes)}))
