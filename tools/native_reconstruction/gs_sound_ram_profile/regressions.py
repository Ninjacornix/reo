#!/usr/bin/env python3
"""Adapt the frozen126 regression driver ONLY for127 count/output; expectations unchanged."""
import argparse,hashlib,json,sys,types
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
PRIOR=ROOT/'tools/native_reconstruction/audio_ram_capture_dispatch/verify.py'
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--tree',type=Path,required=True);p.add_argument('--proof',type=Path,required=True);p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists()or not out.is_relative_to(ROOT/'build-native-sjuni/gs-sound-ram-profile'):raise ValueError('Fresh private output required')
    identity=json.loads((PRIOR.parent/'cohort_identity.json').read_bytes())
    for n,d in identity['authored_sha256'].items():
        if sha(PRIOR.parent/n)!=d:raise ValueError('Frozen126 regression source changed '+n)
    original=PRIOR.read_text(encoding='utf-8')
    adapted=original.replace("receipt['applied_count']!=126","receipt['applied_count']!=127").replace('build-native-sjuni/audio-ram-capture-dispatch','build-native-sjuni/gs-sound-ram-profile')
    private=out.parent/(out.name+'-adapted-driver.py');private.write_text(adapted,encoding='utf-8',newline='\n')
    m=types.ModuleType('qualified127_regressions');m.__file__=str(PRIOR);exec(compile(adapted,str(private),'exec'),m.__dict__)
    sys.argv=[sys.argv[0],'--checkout',str(a.tree.resolve()),'--receipt',str(a.proof.resolve()),'--cxx',a.cxx,'--output',str(out),'--mode','companion']
    m.main()
    receipt=json.loads((out/'receipt.json').read_bytes());receipt['127_adaptation']={'source_driver_sha256':sha(PRIOR),'adapted_driver_sha256':sha(private),'source_126_identity_sha256':sha(PRIOR.parent/'cohort_identity.json'),'only_changes':['126 count to127 including private prior-driver adapter','private output allowlist'],'expected_values_changed':False}
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8',newline='\n')
if __name__=='__main__':main()
