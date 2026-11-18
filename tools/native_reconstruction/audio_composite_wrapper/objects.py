#!/usr/bin/env python3
"""Reuse qualified127/V8 object driver, replacing only source list/output scope."""
import argparse,hashlib,json,sys,types
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
DRIVER=ROOT/'tools/native_reconstruction/gs_sound_ram_profile/objects.py'
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists()or not out.is_relative_to(ROOT/'build-native-sjuni/audio-composite-wrapper'):raise ValueError('Fresh private output required')
    identity=DRIVER.parent/'cohort_identity.json';q=json.loads(identity.read_bytes())
    if sha(DRIVER)!=q['authored_sha256']['objects.py']:raise ValueError('Qualified object driver drift')
    source=DRIVER.read_text(encoding='utf-8');anchor="[('route',sdk/'ps2xRuntime/src/lib/gs_backend_route.cpp'),('runtime',sdk/'ps2xRuntime/src/lib/ps2_runtime.cpp'),('gs',sdk/'ps2xRuntime/src/lib/ps2_gs_gpu.cpp'),('parallel',ROOT/'tools/parallel_gs_backend/parallel_backend.cpp')]"
    if source.count(anchor)!=1:raise ValueError('Object source-list adaptation anchor')
    adapted=source.replace(anchor,"[('composite',ROOT/'recomp/overrides/native_sound_ram/composite_backend.cpp')]").replace('build-native-sjuni/gs-sound-ram-profile','build-native-sjuni/audio-composite-wrapper')
    private=out.parent/(out.name+'-adapted-objects.py');private.parent.mkdir(parents=True,exist_ok=True);private.write_text(adapted,encoding='utf-8',newline='\n')
    m=types.ModuleType('composite_actual_objects');m.__file__=str(DRIVER);exec(compile(adapted,str(private),'exec'),m.__dict__)
    sys.argv=[sys.argv[0],'--tree',str(ROOT/'build-native-sjuni/dependency-gs-sound-profile-reapply-v4'),'--proof',str(ROOT/'build-native-sjuni/dependency-gs-sound-profile-reapply-v4-receipt.json'),'--cxx',a.cxx,'--output',str(out)]
    m.main();receipt=json.loads((out/'receipt.json').read_bytes());receipt['object_driver_adaptation']={'qualified_driver_sha256':sha(DRIVER),'adapted_driver_sha256':sha(private),'qualified_cohort_sha256':sha(identity),'changes':['actual source list: full wrapper only','private output allowlist'],'real_runtime_memory_header':True,'mocks':False}
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8',newline='\n')
if __name__=='__main__':main()
