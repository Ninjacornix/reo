"""Compile only the native gameplay adapter against audited actual SDK131.
Reuses the sealed actual-object provenance checker; never builds/links a game.
"""
import argparse,hashlib,json,sys,types
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
DRIVER=ROOT/'tools/native_reconstruction/gs_sound_ram_profile/objects.py'
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',required=True);p.add_argument('--output',required=True,type=Path);a=p.parse_args();out=a.output.resolve();assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni/native-gameplay/adapter-objects')
 identity=DRIVER.parent/'cohort_identity.json';q=json.loads(identity.read_bytes());assert sha(DRIVER)==q['authored_sha256']['objects.py']
 proof=ROOT/'build-native-sjuni/dependency-muted-rna-reapply-v1-receipt.json';assert sha(proof)=='9f1e67e084ed94fb3e41bf6b1a3f013dcb43aaef15b6a82b06f56a261573a67c'
 body=DRIVER.read_text();anchor="[('route',sdk/'ps2xRuntime/src/lib/gs_backend_route.cpp'),('runtime',sdk/'ps2xRuntime/src/lib/ps2_runtime.cpp'),('gs',sdk/'ps2xRuntime/src/lib/ps2_gs_gpu.cpp'),('parallel',ROOT/'tools/parallel_gs_backend/parallel_backend.cpp')]";flags="'-DREO_BUILD_NATIVE_SOUND_RAM_CAPTURE=2']"
 assert body.count(anchor)==body.count(flags)==body.count("q['applied_count']==127")==1
 adapted=body.replace(anchor,"[('save_session',ROOT/'recomp/overrides/native_gameplay/save_session.cpp')]").replace(flags,"'-DREO_BUILD_NATIVE_SOUND_RAM_CAPTURE=2','-DREO_BUILD_NATIVE_GAMEPLAY_SAVE=1']").replace("q['applied_count']==127","q['applied_count']==131").replace('build-native-sjuni/gs-sound-ram-profile','build-native-sjuni/native-gameplay/adapter-objects').replace('full127_proof_sha256','audited131_proof_sha256')
 private=out.parent/(out.name+'-driver.py');private.parent.mkdir(parents=True,exist_ok=True);private.write_text(adapted,encoding='utf8',newline='\n');module=types.ModuleType('native_gameplay_actual_objects');module.__file__=str(DRIVER);exec(compile(adapted,str(private),'exec'),module.__dict__)
 sys.argv=[sys.argv[0],'--tree',str(ROOT/'build-native-sjuni/dependency-muted-rna-reapply-v1'),'--proof',str(proof),'--cxx',a.compiler,'--output',str(out)];module.main()
 receipt=json.loads((out/'receipt.json').read_bytes());receipt['driver_adaptation']=dict(qualified_driver_sha256=sha(DRIVER),adapted_driver_sha256=sha(private),driver_sha256=sha(Path(__file__)),cohort_identity_sha256=sha(identity),changes=['one new native save/session adapter translation unit','explicit gameplay candidate flag','audited131 source count','owned output scope'],fixture_headers=False)
 (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf8',newline='\n')
if __name__=='__main__':main()
