#!/usr/bin/env python3
"""Compile the unselected ordinary ABI adapter with actual audited SDK130 headers."""
import argparse,hashlib,json,sys,types
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
DRIVER=ROOT/'tools/native_reconstruction/gs_sound_ram_profile/objects.py'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--compiler',required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists() or not out.is_relative_to(ROOT/'build-native-sjuni/adxt-binding'):raise ValueError('Fresh owned output required')
    identity=DRIVER.parent/'cohort_identity.json';q=json.loads(identity.read_bytes())
    if sha(DRIVER)!=q['authored_sha256']['objects.py']:raise ValueError('Qualified object driver drift')
    proof=ROOT/'build-native-sjuni/dependency-sif-init-timing-reapply-v1-receipt.json'
    if sha(proof)!='473ad00c8fcae9966455fc8f47047f2dccd619d747077fc1ffaec2c2e3444df6':raise ValueError('Audited130 receipt required')
    body=DRIVER.read_text();anchor="[('route',sdk/'ps2xRuntime/src/lib/gs_backend_route.cpp'),('runtime',sdk/'ps2xRuntime/src/lib/ps2_runtime.cpp'),('gs',sdk/'ps2xRuntime/src/lib/ps2_gs_gpu.cpp'),('parallel',ROOT/'tools/parallel_gs_backend/parallel_backend.cpp')]"
    flags="'-DREO_BUILD_NATIVE_SOUND_RAM_CAPTURE=2']"
    if body.count(anchor)!=1 or body.count(flags)!=1 or body.count("q['applied_count']==127")!=1:raise ValueError('Qualified driver anchors changed')
    adapted=body.replace(anchor,"[('ordinary',ROOT/'recomp/overrides/native_adxt/ordinary_runtime.cpp'),('handles',ROOT/'recomp/overrides/native_adxt/game_handles.cpp'),('source_profile',ROOT/'recomp/overrides/native_adxt/source_profile.cpp'),('factory',ROOT/'recomp/overrides/native_sound_ram/composite_backend.cpp')]").replace(flags,"'-DREO_BUILD_NATIVE_SOUND_RAM_CAPTURE=2','-DREO_BUILD_NATIVE_RESOURCE_READS=1']").replace("q['applied_count']==127","q['applied_count']==130").replace('build-native-sjuni/gs-sound-ram-profile','build-native-sjuni/adxt-binding').replace('full127_proof_sha256','audited130_proof_sha256')
    private=out.parent/(out.name+'-adapted-objects.py');private.parent.mkdir(parents=True,exist_ok=True);private.write_text(adapted,encoding='utf-8',newline='\n')
    module=types.ModuleType('adxt_ordinary_actual_objects');module.__file__=str(DRIVER);exec(compile(adapted,str(private),'exec'),module.__dict__)
    sys.argv=[sys.argv[0],'--tree',str(ROOT/'build-native-sjuni/dependency-sif-init-timing-reapply-v1'),'--proof',str(proof),'--cxx',a.compiler,'--output',str(out)];module.main()
    record=json.loads((out/'receipt.json').read_bytes());record['driver_adaptation']=dict(qualified_driver_sha256=sha(DRIVER),adapted_driver_sha256=sha(private),qualified_cohort_sha256=sha(identity),changes=['ordinary/handles/source/factory units','actual resource handoff flag','owned output scope','audited130 source count'],mocks=False)
    (out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf-8',newline='\n')
if __name__=='__main__':main()
