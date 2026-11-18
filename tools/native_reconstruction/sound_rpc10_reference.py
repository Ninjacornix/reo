#!/usr/bin/env python3
"""Freeze existing SDK generic reply behavior before adding RPC 0x10 coverage."""
import argparse,hashlib,json,os,subprocess
from pathlib import Path
from audio_ram_capture_dispatch.verify import block
ROOT=Path(__file__).resolve().parents[2];BASE=ROOT/'build-native-sjuni/sound-rpc10'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def cases():
    return [dict(send=s,count=n,recv=r,bytes=b) for s,n,r,b in [
        (0x2B0C80,16,0x2B0C80,16),(0x100,8,0x100,16),(0x100,5,0x203,9),
        (0x100,16,0x102,16),(0x102,16,0x100,16),(0,16,0x200,16),
        (0x100,0,0x200,16),(0x100,16,0,16),(0x100,16,0x200,0),
        (0x100,0x100020,0x180000,0x100020),(0,0,0x180000,0x100020),
        (0x100,3,0x200,1),(0x100,1,0x200,3)]]
def main():
    p=argparse.ArgumentParser();p.add_argument('--checkout',type=Path,required=True);p.add_argument('--receipt',type=Path,required=True);p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists() or not out.is_relative_to(BASE):raise ValueError('Fresh owned reference scope required')
    receipt=json.loads(a.receipt.read_bytes())
    if receipt['status']!='passed' or receipt['applied_count']!=128:raise ValueError('Frozen 128-patch pre-fix source required')
    names=['ps2xRuntime/src/lib/Kernel/Syscalls/RPC.cpp','ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/Runtime.h']
    for name in names:
        if sha(a.checkout/name)!=receipt['source_sha256'][name]:raise ValueError('Original source drift')
    rpc=(a.checkout/names[0]).read_text();runtime=(a.checkout/names[1]).read_text()
    begin=rpc.index('        if (recvBuf && recvSize > 0)\n        {\n            if (handled && resultPtr')
    reply=block(rpc[begin:],'        if (recvBuf && recvSize > 0)')
    helpers='\n'.join(block(runtime,marker) for marker in ['static void rpcCopyToRdram(','static void rpcZeroRdram('])
    source='''#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>
constexpr std::size_t ram_bytes=4*1024*1024;
uint8_t* getMemPtr(uint8_t* p,uint32_t at){return at<ram_bytes?p+at:nullptr;}
const uint8_t* getConstMemPtr(const uint8_t* p,uint32_t at){return at<ram_bytes?p+at:nullptr;}
'''+helpers+'''
void original_reply(uint8_t* rdram,uint32_t sendBuf,uint32_t sendSize,uint32_t recvBuf,uint32_t recvSize){
    const bool handled=false;const uint32_t resultPtr=0;
'''+reply+'''
}
int main(int argc,char** argv){if(argc!=2)return 2;unsigned index{},send{},count{},recv{},bytes{};
    while(std::cin>>index>>send>>count>>recv>>bytes){std::vector<uint8_t> ram(ram_bytes);
        for(std::size_t i=0;i<ram.size();++i)ram[i]=static_cast<uint8_t>(i*17+i/251);
        original_reply(ram.data(),send,count,recv,bytes);
        std::ofstream f(std::string(argv[1])+"/case-"+std::to_string(index)+".bin",std::ios::binary);f.write(reinterpret_cast<const char*>(ram.data()),ram.size());if(!f)return 3;
    }return std::cin.eof()?0:1;
}
'''
    out.mkdir(parents=True);(out/'original.cpp').write_text(source,encoding='utf-8',newline='\n')
    vectors=cases();(out/'cases.json').write_text(json.dumps(vectors,indent=2)+'\n',encoding='utf-8',newline='\n')
    env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
    record=dict(status='failed',native_route_patch_exists=(ROOT/'third_party/patches/ps2recomp/0128-native-sound-rpc10-reply.patch').exists(),source_sha256=sha(Path(__file__)),original_sources={n:sha(a.checkout/n) for n in names},source_receipt_sha256=sha(a.receipt),compiler_sha256=sha(a.compiler),cases=len(vectors),game_run=False,device_opened=False,scope='existing host SDK generic reply; not original IOP implementation or full transport execution')
    try:
        run=subprocess.run([str(a.compiler),'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror',str(out/'original.cpp'),'-o',str(out/'original.exe')],capture_output=True,text=True,env=env)
        (out/'compile.txt').write_text(run.stdout+run.stderr,encoding='utf-8')
        if run.returncode:raise ValueError('Original reference compile failed')
        plan='\n'.join(' '.join(map(str,[i,*[v[k] for k in ['send','count','recv','bytes']]])) for i,v in enumerate(vectors))+'\n'
        run=subprocess.run([str(out/'original.exe'),str(out)],input=plan,capture_output=True,text=True,env=env,timeout=30)
        (out/'run.txt').write_text(run.stdout+run.stderr,encoding='utf-8')
        if run.returncode:raise ValueError('Original reference execution failed')
        record.update(status='existing generic sound RPC reply frozen',memory_outputs={p.name:sha(p) for p in out.glob('case-*.bin')})
    finally:
        record['outputs_sha256']={p.name:sha(p) for p in out.iterdir() if p.suffix in ['.cpp','.txt','.json'] and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps({k:record[k] for k in ['status','cases','native_route_patch_exists']}))
if __name__=='__main__':main()
