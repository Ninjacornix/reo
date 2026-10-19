"""Per-ring PCM arrival/retire timeline from a vblank-music ledger (REO_VBLANK_MUSIC_LOG jsonl).
usage: python -I analyze_pcm_ledger.py <ledger.jsonl> [ring_hex ...]"""
import json,sys,collections
recs=[json.loads(l) for l in open(sys.argv[1]) if l.strip()]
meta=recs[0];recs=[r for r in recs if 'kind' in r]
print('meta',{k:meta.get(k) for k in('after','until','claimed','dropped')})
t0=recs[0]['ns'] if recs else 0
want={int(x,16) for x in sys.argv[2:]}
by=collections.defaultdict(list)
for r in recs:
    if r['kind'] in (17,19,20): by[r['args'][0]].append(r)
for ring,rs in sorted(by.items()):
    if want and ring not in want: continue
    pushes=[r for r in rs if r['kind']==19]; retires=[r for r in rs if r['kind']==17]
    if not pushes: continue
    span=(pushes[-1]['ns']-pushes[0]['ns'])/1e9 or 1
    total=sum(r['args'][1] for r in pushes)
    gaps=[(b['ns']-a['ns'])/1e6 for a,b in zip(pushes,pushes[1:])]
    print('ring %x pushes=%d bytes=%d rate=%.0f B/s (nominal 96000) maxgap=%.1fms sizes=%s'%(ring,len(pushes),total,total/span,max(gaps) if gaps else 0,
          collections.Counter(r['args'][1] for r in pushes).most_common(5)))
    for r in rs[:60]:
        a=r['args'];t=(r['ns']-t0)/1e6
        if r['kind']==19:print('  %9.1fms PUSH len=%5d queuedSamples=%5d consumed=%d'%(t,a[1],a[4],a[3]))
        elif r['kind']==17:print('  %9.1fms RETIRE len=%5d consumed=%d'%(t,a[1],a[3]))
        else:print('  %9.1fms VOICE %s'%(t,a))
