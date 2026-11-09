"""Read only bounded final-join save/session observations; never infer calls from install.
Supports both a strict offline fixture cohort audit and normal game log parsing.
"""
import json,re
ENTRY_ADDRESSES=(0x1c5410,0x1c55c0,0x1c5630,0x1aec50,0x1aec80,0x1aed60,0x1aedb0,0x1aee40,0x1badf0)
PREFIX=re.compile(r'^\[NATIVE-GAMEPLAY-SAVE-(JOIN|ENTRY|TRACE)\] (.*)$')
def parse(text,require_fixture=False):
 groups={};ignored=0
 for line in text.splitlines():
  match=PREFIX.match(line)
  if not match:continue
  kind,body=match.groups();values=dict(re.findall(r'(\w+)=([^ ]+)',body));binding=int(values['binding']);g=groups.setdefault(binding,dict(entries={},trace=[]))
  def n(key):return int(values[key],0)
  if kind=='JOIN':
   if 'join' in g:raise ValueError('Repeated final join dump')
   if n('schema')!=1 or n('joined')!=1 or n('rng_rows')!=0:raise ValueError('Unsupported/invalid join observation')
   g['join']={key:n(key) for key in ['schema','binding','joined','installed','restore_ok','restore_error','trace_rows','trace_overwritten','rng_rows']}
  elif kind=='ENTRY':
   at=n('at')
   if at in g['entries']:raise ValueError('Duplicate entry counter')
   g['entries'][at]={key:n(key) for key in ['accepted','completed','failed','rejected']}
  else:g['trace'].append(dict(sequence=n('seq'),operation=n('operation'),ns=n('ns'),at=n('at'),event=values['event'],detail=n('detail')))
 totals={hex(at):dict(accepted=0,completed=0,failed=0,rejected=0)for at in ENTRY_ADDRESSES};capture_orders=restore_orders=failed_traces=overwritten=0
 for binding,g in groups.items():
  if 'join' not in g or set(g['entries'])!=set(ENTRY_ADDRESSES):raise ValueError('Partial counter dump')
  h=g['join'];trace=g['trace']
  if len(trace)!=h['trace_rows'] or len(trace)>128:raise ValueError('Partial/unbounded trace')
  expected=list(range(h['trace_overwritten']+1,h['trace_overwritten']+len(trace)+1))
  if [r['sequence']for r in trace]!=expected:raise ValueError('Trace sequence/drop mismatch')
  if any(b['ns']<a['ns']for a,b in zip(trace,trace[1:])):raise ValueError('Monotonic timestamp regression')
  for at,c in g['entries'].items():
   if c['accepted']!=c['completed']+c['failed']:raise ValueError('Accepted operation not drained')
   for key,value in c.items():totals[hex(at)][key]+=value
  restore=g['entries'][0x1c55c0]
  if h['restore_ok']+h['restore_error']!=restore['completed']:raise ValueError('Restore result counter mismatch')
  if any(r['at']==0x1aec80 for r in trace):raise ValueError('Per-request RNG trace unexpectedly retained')
  operations={}
  for r in trace:operations.setdefault(r['operation'],[]).append(r)
  for rows in operations.values():
   events=[r['event']for r in rows];at=rows[0]['at']
   if 'failed' in events:failed_traces+=1
   if events[0]!='begin' or events[-1]!='complete':continue # bounded history may start inside an operation
   if at==0x1c5410:
    required=['begin','capture_timestamp_return','capture_live_import','capture_plaintext','capture_rng','capture_encoded','complete'];positions=[events.index(e)for e in required]
    if positions!=sorted(positions):raise ValueError('Capture checkpoint order mismatch')
    capture_orders+=1
   if at==0x1c55c0 and rows[-1]['detail']==0:
    required=['begin','restore_decoded_settings','restore_options_return','restore_observer_refresh','restore_live_export','complete'];positions=[events.index(e)for e in required]
    if positions!=sorted(positions):raise ValueError('Restore checkpoint order mismatch')
    restore_orders+=1
  overwritten+=h['trace_overwritten']
 if require_fixture:
  if not groups or not capture_orders or not restore_orders or not failed_traces or not overwritten:raise ValueError('Missing meaningful fixture trace cases')
  if any(not c['completed'] for c in totals.values()):raise ValueError('Fixture did not exercise all nine hooks')
  if not sum(c['failed']for c in totals.values()) or not sum(c['rejected']for c in totals.values()):raise ValueError('Missing failed/reentrant/admission counters')
  if max(g['entries'][0x1aec80]['completed']for g in groups.values())<128:raise ValueError('Missing counts-only RNG stress')
  if sum(g['join']['restore_error']for g in groups.values())<2:raise ValueError('Missing failed decode returns')
  # Independent tally of explicit test calls, rather than counts inferred from
  # the instrumented implementation: 8 base cohorts, 128 shared RNG requests,
  # 80 repeated defaults, four accepted capture failures, four observer failures,
  # one failed restore, and rejected admission/reentry calls. The deliberately
  # closed-stderr seed case is absent from observations and checked in C++.
  expected=((15,11,4,4),(11,10,1,0),(32,32,0,0),(10,10,0,0),(137,137,0,1),(88,88,0,0),(8,8,0,0),(8,8,0,0),(12,8,4,0))
  for at,counts in zip(ENTRY_ADDRESSES,expected):
   if tuple(totals[hex(at)][key]for key in ['accepted','completed','failed','rejected'])!=counts:raise ValueError('Native diagnostic counts differ from independent test call inventory')
  if (capture_orders,restore_orders,failed_traces,overwritten)!=(11,8,9,192):raise ValueError('Checkpoint/retention counts differ from test call inventory')
 return dict(schema=1,bindings=len(groups),totals=totals,capture_orders=capture_orders,restore_orders=restore_orders,failed_traces=failed_traces,trace_overwritten=overwritten,groups={str(k):v for k,v in groups.items()},limits=['A valid join is a drained native-binding observation, not proof of source/device/UI behavior.','A bounded trace can omit early operations; exact per-entry counters remain available.','No per-request RNG rows are recorded.'])
if __name__=='__main__':
 import argparse
 from pathlib import Path
 p=argparse.ArgumentParser();p.add_argument('log',type=Path);p.add_argument('--output',type=Path,required=True);p.add_argument('--fixture',action='store_true');a=p.parse_args();result=parse(a.log.read_text(encoding='utf8',errors='strict'),a.fixture);a.output.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps({key:value for key,value in result.items()if key!='groups'}))
