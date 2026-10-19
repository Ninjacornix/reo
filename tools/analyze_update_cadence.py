"""Update intervals from original-game-clock actor samples, never host presents.
Run analyze_game_clock.py first, with clock-analysis.json next to the CSV.
Skips the first second of each eligible epoch for interval tail statistics;
whole-epoch rate still includes startup. Output: cadence.json beside the CSV.
"""
from pathlib import Path
import csv,json,statistics,sys
p=Path(sys.argv[1]);lines=p.read_text().splitlines();rows=[{k:int(v) for k,v in r.items()} for r in csv.DictReader(x for x in lines if not x.startswith('#'))];a=json.loads(p.with_name('clock-analysis.json').read_text());out=[]
for key in ('dropped','invalid_clock','unpublished'):
 if int(a.get('metadata',{}).get(key,0)):raise SystemExit('Incomplete game-clock journal: '+key)
for seg in a['segments']:
 rs=[r for r in rows if seg['first_row']<=r['n']<=seg['last_row']];u=[]
 for r in rs:
  if not u or r['clock_units']!=u[-1]['clock_units']:u.append(r)
 warm=u[0]['elapsed_ns']+10**9
 ds=[(b['elapsed_ns']-aa['elapsed_ns'])/1e6 for aa,b in zip(u,u[1:]) if aa['elapsed_ns']>=warm]
 if not ds:continue
 slow=best=0
 for d in ds:
  slow=slow+1 if d>45 else 0;best=max(best,slow)
 windows=[]
 for sec in range(int(u[0]['elapsed_ns']//10**9)+1,int(u[-1]['elapsed_ns']//10**9)):
  q=[r for r in u if sec*10**9<=r['elapsed_ns']<(sec+1)*10**9]
  if len(q)>1:windows.append({'start_s':sec,'rate':(q[-1]['clock_units']-q[0]['clock_units'])/q[0]['step']/((q[-1]['elapsed_ns']-q[0]['elapsed_ns'])/1e9)})
 out.append({'room':seg['room'],'seconds':seg['host_seconds'],'rate':seg['ordinary_updates_per_host_second'],'interval_ms':{'median':statistics.median(ds),'p95':sorted(ds)[int(len(ds)*.95)],'p99':sorted(ds)[int(len(ds)*.99)],'max':max(ds)},'over45ms_percent':100*sum(d>45 for d in ds)/len(ds),'longest_over45ms_run':best,'slowest_1s':sorted(windows,key=lambda x:x['rate'])[:5]})
p.with_name('cadence.json').write_text(json.dumps(out,indent=2));print(json.dumps(out,indent=2))
