import hashlib,json,sys
from pathlib import Path
p=Path(sys.argv[1]);off=(p/'off.vram').read_bytes();on=(p/'on.vram').read_bytes()
expected=16*4*1024*1024
if len(off)!=expected or len(on)!=expected:raise SystemExit(f'Expected16 records: {len(off)} {len(on)}')
if off!=on:
    i=next(i for i,(a,b) in enumerate(zip(off,on)) if a!=b)
    raise SystemExit(f'Diagnostic changed VRAM: record{i//(4*1024*1024)} byte{i%(4*1024*1024)}')
report={'records':16,'bytes':len(off),'off_sha256':hashlib.sha256(off).hexdigest(),'on_sha256':hashlib.sha256(on).hexdigest(),'equal':True}
(p/'parity.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
