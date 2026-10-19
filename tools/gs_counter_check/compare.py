from pathlib import Path
import re, sys, statistics
out=Path(sys.argv[1])
for mode in ('serial','parallel'):
    variants=[]
    for name in ('baseline','candidate'):
        log=(out/f'{name}-{mode}.log').read_text(errors='replace')
        assert 'FAIL' not in log, (name,mode)
        final=re.search(r'cases=(\d+) independent_checks=(\d+) failures=(\d+)',log)
        assert final and int(final[3])==0 and int(final[2])>=132
        counts=re.findall(r'^COUNTERS (\d+) (\S+) (\d+) (\d+) (\d+)$',log,re.M)
        assert len(counts)==int(final[1])
        variants.append(counts)
    assert variants[0]==variants[1],f'{mode} final diagnostic totals differ'
    with (out/f'baseline-{mode}.vram').open('rb') as a,(out/f'candidate-{mode}.vram').open('rb') as b:
        for row in variants[0]:
            x,y=a.read(4*1024*1024),b.read(4*1024*1024)
            assert len(x)==4*1024*1024 and x==y,(mode,row[:2])
        assert not a.read(1) and not b.read(1)
    print(f'PASS {mode}: {len(variants[0])} complete VRAM images and exact modulo32 counter triples')
    times=[]
    for name in ('baseline','candidate'):
        rounds=[]
        for p in out.glob(f'{name}-{mode}-bench-*.log'):
            m=re.search(r'BENCH triangles=\d+ us=(\d+) hash=([0-9a-f]+)',p.read_text())
            assert m
            rounds.append((int(m[1]),m[2]))
        assert len(rounds)>=7
        times.append(statistics.median(x[0] for x in rounds))
    print(f'{mode} median baseline={times[0]}us candidate={times[1]}us ratio={times[0]/times[1]:.4f}; isolated triangle workload only')
