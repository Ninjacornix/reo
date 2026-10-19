import re,sys,bisect,collections
mp=open(sys.argv[1],errors='replace').read()
base=int(re.search(r'Preferred load address is ([0-9a-fA-F]+)',mp).group(1),16)
syms=[]
for m in re.finditer(r'^\s*[0-9a-fA-F]{4}:[0-9a-fA-F]{8}\s+(\S+)\s+([0-9a-fA-F]{16})\s',mp,re.M):
    syms.append((int(m.group(2),16)-base,m.group(1)))
syms.sort();keys=[a for a,_ in syms]
def name(t):
    if not t.startswith('0x'):return t
    a=int(t,16);i=bisect.bisect_right(keys,a)-1
    return syms[i][1][:70] if i>=0 else t
stacks=collections.Counter()
for line in open(sys.argv[2],errors='replace'):
    if not line.startswith('[STACKDUMP]'):continue
    parts=line.split()
    tid=parts[1];frames=[name(f) for f in parts[3:]][:9]
    stacks[(tid,' <- '.join(frames))]+=1
for (tid,s),n in stacks.most_common(200):print(n,tid,s[:600]);print()
