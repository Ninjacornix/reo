#!/usr/bin/env python3
"""Author bounded failure identity logging from the verified 127-patch source."""
import argparse,difflib,hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
PRIOR=ROOT/'build-native-sjuni/dependency-gs-sound-profile-reapply-v4'
RECEIPT=PRIOR.with_name(PRIOR.name+'-receipt.json')
PIN='909917fc2f766c8a43a10abbc0b94189fa24254ecfaa7f710e4eb24dc941b58a'
SOURCE='ps2xRuntime/src/lib/Kernel/Syscalls/RPC.cpp'
PATCH=ROOT/'third_party/patches/ps2recomp/0127-identify-native-sound-rpc-refusals.patch'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def replace(text,old,new):
    if text.count(old)!=1:raise ValueError('Nonunique source anchor '+old[:60])
    return text.replace(old,new)
def diagnostic(indent,reason,sid,rpc,client,send,mode):
    return f'''{indent}{{
{indent}    // Bounded failure identity only; no extra guest read or completion.
{indent}    static std::atomic<unsigned> reports{{0}};
{indent}    auto count=reports.load(std::memory_order_relaxed);
{indent}    while(count<8 && !reports.compare_exchange_weak(count,count+1,std::memory_order_relaxed)){{}}
{indent}    if(count<8)std::fprintf(stderr,"[NATIVE-SOUND-RPC-REFUSAL] reason={reason} sid=%08x rpc=%08x client=%08x send=%08x mode=%08x\\n",
{indent}        unsigned({sid}),unsigned({rpc}),unsigned({client}),unsigned({send}),unsigned({mode}));
{indent}}}
'''
def main():
    p=argparse.ArgumentParser();p.add_argument('--author',type=Path,required=True);a=p.parse_args();out=a.author.resolve()
    if out.exists() or not out.is_relative_to(ROOT/'build-native-sjuni') or PATCH.exists():raise ValueError('Fresh author and unused numbered patch required')
    if sha(RECEIPT)!=PIN:raise ValueError('Prior 127 receipt drift')
    receipt=json.loads(RECEIPT.read_bytes())
    if receipt['status']!='passed' or receipt['applied_count']!=127:raise ValueError('Full prior source required')
    for row in receipt['patches']:
        if sha(ROOT/row['path'])!=row['sha256']:raise ValueError('Prior patch drift')
    for name,digest in receipt['source_sha256'].items():
        if sha(PRIOR/name)!=digest:raise ValueError('Prior source drift '+name)
    before=(PRIOR/SOURCE).read_text();after='#include <atomic>\n#include <cstdio>\n'+before
    old='''            if(!ps2_cri_audio::coversSoundRpcV2(sid,rpcNum)){
                capture.reject'''
    after=replace(after,old,'''            if(!ps2_cri_audio::coversSoundRpcV2(sid,rpcNum)){
'''+diagnostic('                ','direct_uncovered_rpc','sid','rpcNum','0','sendBuf','0')+'''                capture.reject''')
    old='''        if(!ps2_cri_audio::coversSoundRpcV2(sid,rpc)){
            cap.reject'''
    after=replace(after,old,'''        if(!ps2_cri_audio::coversSoundRpcV2(sid,rpc)){
'''+diagnostic('            ','uncovered_rpc','sid','rpc','cp','send','mode')+'''            cap.reject''')
    old='''        if((serverPtr&&sd.func)||(serverPtr&&c<s+sizeof(sd)&&s<c+sizeof(client))||transportMetadata){
            cap.reject'''
    after=replace(after,old,'''        if((serverPtr&&sd.func)||(serverPtr&&c<s+sizeof(sd)&&s<c+sizeof(client))||transportMetadata){
'''+diagnostic('            ','server_or_metadata','sid','rpc','cp','send','mode')+'''            cap.reject''')
    target=out/SOURCE;target.parent.mkdir(parents=True);target.write_text(after,encoding='utf-8',newline='\n')
    patch='diff --git a/'+SOURCE+' b/'+SOURCE+'\n'+''.join(difflib.unified_diff(before.splitlines(True),after.splitlines(True),fromfile='a/'+SOURCE,tofile='b/'+SOURCE))
    PATCH.write_text(patch,encoding='utf-8',newline='\n')
    record=dict(status='authored bounded failure identity logging',prior_receipt_sha256=PIN,source=SOURCE,before_sha256=sha(PRIOR/SOURCE),after_sha256=sha(target),patch_sha256=sha(PATCH),author_tool_sha256=sha(Path(__file__)),game_run=False,active_checkout_modified=False)
    (out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf-8',newline='\n');print(json.dumps(record))
if __name__=='__main__':main()
