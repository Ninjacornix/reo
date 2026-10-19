"""Run room cadence, movement and pickup/quit trials serially; stop on failure."""
from pathlib import Path
import argparse,json,subprocess,sys

root=Path(__file__).resolve().parents[1]
ap=argparse.ArgumentParser();ap.add_argument('--manifest',type=Path,required=True);ap.add_argument('--launcher',type=Path,required=True)
ap.add_argument('--out',type=Path,required=True);ap.add_argument('--soak-seconds',type=int,default=240)
a=ap.parse_args();a.out.mkdir(parents=True,exist_ok=False);results=[]
for mode,seconds in [('idle',140),('soak',a.soak_seconds),('interact-quit',200)]:
    out=a.out/mode
    result=subprocess.run([sys.executable,str(root/'tools/room_playtest.py'),'--manifest',str(a.manifest.resolve()),'--launcher',str(a.launcher.resolve()),'--out',str(out.resolve()),'--mode',mode,'--seconds',str(seconds)],cwd=root)
    record=json.loads((out/'result.json').read_text()) if (out/'result.json').exists() else {'passed':False,'failure':'missing_trial_receipt'}
    record['tool_exit']=result.returncode
    if record['passed'] and mode!='interact-quit':
        cadence=subprocess.run([sys.executable,str(root/'tools/analyze_update_cadence.py'),str(out/'clock.csv')],cwd=root)
        rows=json.loads((out/'cadence.json').read_text()) if cadence.returncode==0 else []
        long=[r for r in rows if r['seconds']>=15]
        record['cadence']=rows
        record['cadence_passed']=bool(long) and all(r['rate']>=29.5 and r['over45ms_percent']<=1 and r['longest_over45ms_run']<=3 for r in long)
        record['passed']&=record['cadence_passed']
    results.append(record);passed=all(r['passed'] and not r['tool_exit'] for r in results)
    (a.out/'suite.json').write_text(json.dumps({'passed':passed,'trials':results},indent=2))
    if not passed:sys.exit(1)
print('Room suite PASS: original clock, controlled movement, pickup and menu return')
