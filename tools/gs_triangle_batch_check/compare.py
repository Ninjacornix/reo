"""Compare complete VRAM records and actual ordered fixture work."""
import pathlib,re,statistics,sys
folder=pathlib.Path(sys.argv[1]);left=(folder/'off.vram').read_bytes();right=(folder/'on.vram').read_bytes()
logs=[(folder/(mode+'.log')).read_text() for mode in ('off','on')]
summaries=[re.search(r'SUMMARY records=(\d+) checks=(\d+) failures=(\d+) batch=(\d+) parallel_batches=(\d+)',s) for s in logs]
if any(not s for s in summaries):raise SystemExit('Missing summary')
counts=[int(s[1]) for s in summaries]
if counts[0]!=counts[1] or any(int(s[3]) for s in summaries):raise SystemExit('Fixture failures or record-count disagreement')
if counts[0]!=52:raise SystemExit(f'Expected52 full-VRAM records, got{counts}')
if len(left)!=counts[0]*4194304 or len(right)!=len(left):raise SystemExit('Incomplete full-VRAM records')
if left!=right:
    pos=next(i for i,(a,b) in enumerate(zip(left,right)) if a!=b)
    raise SystemExit(f'VRAM MISMATCH record={pos//4194304} offset={pos%4194304}')
if int(summaries[0][5])!=0 or int(summaries[1][5])==0:raise SystemExit('Candidate never admitted useful parallel work')
for i,s in enumerate(logs):
    stops=re.findall(r'STOP iteration=(\d+) rows=(\d+) prefix=(\d+)',s)
    if len(stops)!=3 or any(int(p)!=1 or int(rows)==0 for _,rows,p in stops):raise SystemExit('Missing independent cancellation oracle')
print(f'PASS {counts[0]} complete4MiB VRAM records byte-identical; independent ordering/capture/stop controls pass')
pattern=r'BENCH source=(\d+) bbox=(\d+) packets=(\d+) round=(\d+) us=(\d+) hash=([0-9a-f]+)'
groups=[]
for s in logs:
    d={}
    for source,bbox,packets,round_,us,h in re.findall(pattern,s):d.setdefault((source,bbox,packets),[]).append((int(us),h))
    groups.append(d)
if groups[0].keys()!=groups[1].keys():raise SystemExit('Benchmark work differs')
for key,a in groups[0].items():
    b=groups[1][key]
    if len(a)!=5 or len(b)!=5 or {h for _,h in a}!={h for _,h in b}:raise SystemExit('Benchmark final VRAM differs')
    off=statistics.median(x for x,_ in a);on=statistics.median(x for x,_ in b)
    print('BENCH',key,'off_us',off,'on_us',on,'ratio',round(off/on,3))
print('Isolated64-triangle packet timings; no native gameplay gain is established.')
