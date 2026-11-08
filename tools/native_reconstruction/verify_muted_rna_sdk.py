#!/usr/bin/env python3
"""Compile actual SDK131 sound objects using unchanged SDK130 object checks."""
import argparse, hashlib, json, sys, types
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
PRIOR=ROOT/'tools/native_reconstruction/verify_sif_init_sdk.py'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser(description=__doc__)
    for name in ('checkout','receipt','compiler','output'):p.add_argument('--'+name,type=Path,required=True)
    a=p.parse_args();out=a.output.resolve()
    if out.exists() or not out.is_relative_to(ROOT/'build-native-sjuni/muted-rna/sdk'):raise ValueError('Fresh owned output required')
    if sha(PRIOR)!='6fba6e840595d5abef0264b894cb857012d48e3fc82d042f271aa1fe8729be02':raise ValueError('Prior driver changed')
    body=PRIOR.read_text()
    for old,new in [("receipt['applied_count']!=130","receipt['applied_count']!=131"),('0129-time-sif-init-rpc-stages.patch','0130-refresh-muted-rna-metadata.patch'),('build-native-sjuni/sif-init-timing/sdk','build-native-sjuni/muted-rna/sdk')]:
        if old not in body:raise ValueError('Driver adaptation anchor missing: '+old)
        body=body.replace(old,new)
    out.parent.mkdir(parents=True,exist_ok=True);adapted=out.with_name(out.name+'-driver.py');adapted.write_text(body,encoding='utf-8',newline='\n')
    module=types.ModuleType('muted_rna_sdk_prior');module.__file__=str(PRIOR);exec(compile(body,str(adapted),'exec'),module.__dict__)
    sys.argv=[sys.argv[0],'--checkout',str(a.checkout),'--receipt',str(a.receipt),'--compiler',str(a.compiler),'--output',str(out)];module.main()
    (out/'muted-rna-sdk-receipt.json').write_text(json.dumps(dict(status='actual SDK131 sound objects compiled',driver_sha256=sha(Path(__file__)),prior_driver_sha256=sha(PRIOR),adapted_driver_sha256=sha(adapted),dependency_receipt_sha256=sha(a.receipt),object_receipt_sha256=sha(out/'receipt.json'),game_run=False),indent=2)+'\n',encoding='utf-8',newline='\n')
if __name__=='__main__':main()
