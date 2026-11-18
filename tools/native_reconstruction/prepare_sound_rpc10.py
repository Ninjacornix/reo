#!/usr/bin/env python3
"""Add the measured state RPC 0x10 reply through the owned capture transport."""
import argparse,difflib,hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2];BASE=ROOT/'build-native-sjuni/dependency-sound-diagnostic-reapply-v1'
RECEIPT=BASE.with_name(BASE.name+'-receipt.json');PIN='54fd56882784fba8cdea3e7a35c33ed443298b10565b2a42aa0b7a2eaad4a43b'
PATCH=ROOT/'third_party/patches/ps2recomp/0128-native-sound-rpc10-reply.patch'
RPC='ps2xRuntime/src/lib/Kernel/Syscalls/RPC.cpp';AUDIO='ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/CriAudio.cpp'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--author',type=Path,required=True);a=p.parse_args();out=a.author.resolve()
    if out.exists() or not out.is_relative_to(ROOT/'build-native-sjuni') or PATCH.exists():raise ValueError('Fresh author/unused public patch required')
    if sha(RECEIPT)!=PIN:raise ValueError('Frozen 128 source receipt drift')
    receipt=json.loads(RECEIPT.read_bytes())
    for row in receipt['patches']:
        if sha(ROOT/row['path'])!=row['sha256']:raise ValueError('Prior patch drift')
    for name,digest in receipt['source_sha256'].items():
        if sha(BASE/name)!=digest:raise ValueError('Prior source drift')
    for cohort in ['llvm','gcc']:
        scope=ROOT/'build-native-sjuni/sound-rpc10'/('original-'+cohort+'-v1');r=json.loads((scope/'receipt.json').read_bytes())
        if r['status']!='existing generic sound RPC reply frozen' or r['native_route_patch_exists']:raise ValueError('Pre-native original reply required')
        for name,digest in {**r['memory_outputs'],**r['outputs_sha256']}.items():
            if sha(scope/name)!=digest:raise ValueError('Original observation drift')
    versions={};patches=[]
    for name in [RPC,AUDIO]:
        before=(BASE/name).read_text();after=before
        if name==AUDIO:
            old='query==0x0C||rpc==0x12||rpc==0x13';new='query==0x0C||rpc==0x10||rpc==0x12||rpc==0x13'
        else:
            old='''            const uint32_t query=rpcNum&255;
            if(sid==IOP_SID_SNDDRV_STATE'''
            new='''            // This measured startup request used the generic host reply, not
            // an IOP query implementation. Preserve its exact transport rules:
            // self alias clears; a distinct short send leaves the receive tail.
            if(sid==IOP_SID_SNDDRV_STATE&&rpcNum==0x10){
                if(recvBuf&&recvSize){
                    if(sendBuf&&sendSize&&sendBuf!=recvBuf){
                        const auto bytes=std::min<std::size_t>(std::min(sendSize,recvSize),1u<<20);
                        if(cap.forward(RamSpace::ee,sendBuf,RamSpace::ee,recvBuf,bytes)!=ps2_cri_audio::BankStatusV2::ok)return true;
                    }else if(cap.zero(RamSpace::ee,recvBuf,std::min<std::size_t>(recvSize,1u<<20),RamControl::query_reply)!=ps2_cri_audio::BankStatusV2::ok)return true;
                }
                // No extra early NOWAIT signal. The normal end callback owns
                // completion, just as in the previous generic SIF path.
                return true;
            }
            const uint32_t query=rpcNum&255;
            if(sid==IOP_SID_SNDDRV_STATE'''
        if after.count(old)!=1:raise ValueError('Nonunique source anchor '+name)
        after=after.replace(old,new);target=out/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_text(after,encoding='utf-8',newline='\n')
        versions[name]=dict(before=sha(BASE/name),after=sha(target))
        patches.append('diff --git a/'+name+' b/'+name+'\n'+''.join(difflib.unified_diff(before.splitlines(True),after.splitlines(True),fromfile='a/'+name,tofile='b/'+name)))
    PATCH.write_text(''.join(patches),encoding='utf-8',newline='\n')
    (out/'receipt.json').write_text(json.dumps(dict(status='authored captured RPC 0x10 generic-reply compatibility',prior_receipt_sha256=PIN,patch_sha256=sha(PATCH),sources=versions,author_sha256=sha(Path(__file__)),game_run=False,active_checkout_modified=False),indent=2)+'\n',encoding='utf-8',newline='\n')
    print('Authored bounded captured RPC 0x10 reply; compilation and retest remain')
if __name__=='__main__':main()
