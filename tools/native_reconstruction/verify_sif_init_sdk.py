#!/usr/bin/env python3
"""Retain the prior SDK object regression driver with explicit 130-patch scope.

Only patch count/reverse check/output paths change. No wire, PCM, bank or RAM
expectation is rewritten. The actual current SDK objects are compiled.
"""
import argparse,hashlib,json,sys,types
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2];PRIOR=ROOT/'tools/native_reconstruction/verify_sound_rpc10.py'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--checkout',type=Path,required=True);p.add_argument('--receipt',type=Path,required=True);p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists() or not out.is_relative_to(ROOT/'build-native-sjuni/sif-init-timing/sdk'):raise ValueError('Fresh owned SDK object scope required')
    if sha(PRIOR)!='20c302c370fede3bdcbdf48249c98b968144b995ec6a421bc946daa41a083ef2':raise ValueError('Prior SDK object driver changed')
    source=PRIOR.read_text()
    for old,new in [("receipt['applied_count']!=129","receipt['applied_count']!=130"),('0128-native-sound-rpc10-reply.patch','0129-time-sif-init-rpc-stages.patch'),('build-native-sjuni/sound-rpc10','build-native-sjuni/sif-init-timing/sdk')]:
        if old not in source:raise ValueError('Explicit adaptation anchor missing '+old)
        source=source.replace(old,new)
    out.parent.mkdir(parents=True,exist_ok=True);driver=out.with_name(out.name+'-driver.py');driver.write_text(source,encoding='utf-8',newline='\n')
    module=types.ModuleType('sif_init_sdk_prior');module.__file__=str(PRIOR);exec(compile(source,str(driver),'exec'),module.__dict__)
    sys.argv=[sys.argv[0],'--checkout',str(a.checkout),'--receipt',str(a.receipt),'--compiler',str(a.compiler),'--output',str(out),'--mode','objects'];module.main()
    (out/'sif-init-sdk-receipt.json').write_text(json.dumps({'status':'current SDK sound objects qualified with initializer timing','driver_sha256':sha(Path(__file__)),'prior_driver_sha256':sha(PRIOR),'adapted_driver_sha256':sha(driver),'native_objects_receipt_sha256':sha(out/'receipt.json'),'wrapper_receipt_sha256':sha(out/'rpc10-receipt.json'),'dependency_receipt_sha256':sha(a.receipt),'game_run':False},indent=2)+'\n',encoding='utf-8',newline='\n')
if __name__=='__main__':main()
