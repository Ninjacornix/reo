"""Content-identified production objects for source-frozen comparison cohorts.

Only production units are cached. The oracle/fixture is compiled for each
cohort. Every cache read verifies its object hash; each cohort retains its own
copy and complete compile identity. Source snapshots remain authoritative.
"""
import concurrent.futures
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import uuid

def digest(data):
    return hashlib.sha256(data).hexdigest()

def compile_objects(root, out, compiler, flags, units, frozen, env):
    compiler_hash=digest(compiler.read_bytes())
    headers={n:digest(b) for n,b in frozen.items() if n.startswith('game/native/') and n.endswith(('.hpp','.h','.inc'))}
    header_hash=digest(json.dumps(headers,sort_keys=True).encode())
    cache=root/'build-native-sjuni'/'comparison-object-cache-v1'
    cache.mkdir(exist_ok=True)
    objects=out/'objects'
    objects.mkdir()
    # A cached object never embeds the producing cohort's absolute source path.
    compile_flags=flags+[f'-ffile-prefix-map={out}=reo-comparison']
    normalized=[arg.replace(str(out),'<cohort>') for arg in compile_flags]
    def compile_one(row):
        index,name=row
        identity={'schema':1,'source':name,'source_sha256':digest(frozen[name]),'native_headers_sha256':header_hash,'compiler_sha256':compiler_hash,'flags':normalized}
        key=digest(json.dumps(identity,sort_keys=True).encode())
        meta=cache/(key+'.json')
        target=objects/(f'{index:03d}.o')
        hit=False
        if meta.is_file():
            old=json.loads(meta.read_text())
            source=cache/(key+'-'+old['object_sha256']+'.o')
            if old['identity']==identity and source.is_file() and digest(source.read_bytes())==old['object_sha256']:
                shutil.copyfile(source,target)
                hit=True
        command=[str(compiler),*compile_flags,'-c',str(out/'source'/name),'-o',str(target)]
        if not hit:
            result=subprocess.run(command,capture_output=True,env=env,timeout=180)
            (objects/(f'{index:03d}.stdout.txt')).write_bytes(result.stdout)
            (objects/(f'{index:03d}.stderr.txt')).write_bytes(result.stderr)
            if result.returncode:
                raise RuntimeError('Production object failed: '+name+'; see '+str(objects/(f'{index:03d}.stderr.txt')))
        object_hash=digest(target.read_bytes())
        if not hit:
            # Distinct content filenames avoid overwriting another concurrent
            # writer's object. Metadata publication is an atomic final step.
            destination=cache/(key+'-'+object_hash+'.o')
            temporary=cache/(uuid.uuid4().hex+'.tmp')
            shutil.copyfile(target,temporary)
            os.replace(temporary,destination)
            temporary=cache/(uuid.uuid4().hex+'.tmp')
            temporary.write_text(json.dumps({'identity':identity,'object_sha256':object_hash},sort_keys=True)+'\n')
            os.replace(temporary,meta)
        return {'identity':identity,'cache_key':key,'cache_hit':hit,'object':target.relative_to(out).as_posix(),'object_sha256':object_hash,'command':command}
    with concurrent.futures.ThreadPoolExecutor(max_workers=4) as pool:
        receipts=list(pool.map(compile_one,enumerate(units)))
    (out/'production-objects.json').write_text(json.dumps(receipts,indent=2)+'\n')
    return [str(out/r['object']) for r in receipts],receipts
