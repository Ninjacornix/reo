#!/usr/bin/env python3
"""Compile the complete native media factory against audited 130 SDK headers.

Reuse the qualified include/provenance driver with an explicit, recorded source
list and audited patch-count change. No active SDK or installed libraries.
"""
import argparse,hashlib,json,sys,types
from pathlib import Path
HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[2]
DRIVER=ROOT/'tools/native_reconstruction/gs_sound_ram_profile/objects.py'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--compiler',required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists()or not out.is_relative_to(ROOT/'build-native-sjuni/audio-media-factory'):raise ValueError('Fresh owned output required')
    identity=DRIVER.parent/'cohort_identity.json';q=json.loads(identity.read_bytes())
    if sha(DRIVER)!=q['authored_sha256']['objects.py']:raise ValueError('Qualified object driver drift')
    proof=ROOT/'build-native-sjuni/dependency-sif-init-timing-reapply-v1-receipt.json'
    if sha(proof)!='473ad00c8fcae9966455fc8f47047f2dccd619d747077fc1ffaec2c2e3444df6':raise ValueError('Audited130 receipt required')
    source=DRIVER.read_text(encoding='utf-8')
    old="[('route',sdk/'ps2xRuntime/src/lib/gs_backend_route.cpp'),('runtime',sdk/'ps2xRuntime/src/lib/ps2_runtime.cpp'),('gs',sdk/'ps2xRuntime/src/lib/ps2_gs_gpu.cpp'),('parallel',ROOT/'tools/parallel_gs_backend/parallel_backend.cpp')]"
    if source.count(old)!=1 or source.count("q['applied_count']==127")!=1:raise ValueError('Driver anchors changed')
    adapted=source.replace(old,"[('composite',ROOT/'recomp/overrides/native_sound_ram/composite_backend.cpp')]").replace("q['applied_count']==127","q['applied_count']==130").replace('build-native-sjuni/gs-sound-ram-profile','build-native-sjuni/audio-media-factory').replace('full127_proof_sha256','audited130_proof_sha256')
    private=out.parent/(out.name+'-adapted-objects.py');private.parent.mkdir(parents=True,exist_ok=True);private.write_text(adapted,encoding='utf-8',newline='\n')
    m=types.ModuleType('media_factory_actual_objects');m.__file__=str(DRIVER);exec(compile(adapted,str(private),'exec'),m.__dict__)
    sys.argv=[sys.argv[0],'--tree',str(ROOT/'build-native-sjuni/dependency-sif-init-timing-reapply-v1'),'--proof',str(proof),'--cxx',a.compiler,'--output',str(out)]
    m.main();r=json.loads((out/'receipt.json').read_bytes());r['object_driver_adaptation']={'qualified_driver_sha256':sha(DRIVER),'adapted_driver_sha256':sha(private),'qualified_cohort_sha256':sha(identity),'changes':['factory source list','owned output allowlist','audited SDK130 patch count and receipt label'],'mocks':False}
    (out/'receipt.json').write_text(json.dumps(r,indent=2)+'\n',encoding='utf-8',newline='\n')
if __name__=='__main__':main()
