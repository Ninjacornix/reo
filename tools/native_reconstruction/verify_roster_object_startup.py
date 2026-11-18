"""Verify the complete 6AD5C0 caller and its observable source-order prefix."""
import argparse
import hashlib
import json
import os
import re
import subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source

ROOT=Path(__file__).resolve().parents[2]
COMPILER=Path('C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe')
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def main():
    parser=argparse.ArgumentParser();parser.add_argument('--output',type=Path,required=True);args=parser.parse_args()
    out=args.output.resolve();allowed=(ROOT/'build-native-sjuni').resolve()
    if out.exists() or out==allowed or not out.is_relative_to(allowed):raise ValueError('Fresh private output required')
    source=ROOT/'recomp/config/output_ovl/o2/o2_006AD5C0_0x6ad5c0.cpp'
    original=source.read_text();end=int(re.search(r'// Address: 0x[0-9a-fA-F]+ - 0x([0-9a-fA-F]+)',original)[1],16)
    image=ROOT/'build-function-index/owned-overlays/o2.bin';data=image.read_bytes()
    if sha(image)!='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226':raise ValueError('Owned image changed')
    audit=compare_source('room-object-startup',str(source.relative_to(ROOT)),0x6ad5c0,end,lambda at,n:data[at-0x570000:at-0x570000+n])
    base=ROOT/'tools/native_reconstruction/gameplay_collision_oracle/reference.hpp'
    header=base.read_text().split('void o0_00370760')[0].replace('#pragma once','',1)
    ports=r'''
#include <algorithm>
#include <cstdio>
#include <vector>
struct Event {unsigned stage,scenario,a,b,c;};
std::vector<Event> events;
void o2_006ACF80_0x6acf80(std::uint8_t* m,R5900Context* c,PS2Runtime*){
    events.push_back({0,0,m[0x74b2ba],m[0x74b2b9],m[0x74b2bc]});c->pc=GPR_U32(c,31);
}
void o2_006AD720_0x6ad720(std::uint8_t* m,R5900Context* c,PS2Runtime*){
    events.push_back({1,GPR_U32(c,4),m[0x74b2ba],m[0x74b2b9],m[0x74b2bc]});c->pc=GPR_U32(c,31);
}
void o2_006AD610_0x6ad610(std::uint8_t* m,R5900Context* c,PS2Runtime*){
    events.push_back({2,0,m[0x74b2ba],m[0x74b2b9],m[0x74b2bc]});c->pc=GPR_U32(c,31);
}
PS2Runtime::Fn PS2Runtime::lookupFunction(std::uint32_t)const{throw std::runtime_error("Undeclared startup support call");}
'''
    main=r'''
int main(){
    std::vector<std::uint8_t> m(0x800000);unsigned checks=0;
    for(unsigned i=0;i<256;++i){
        std::fill(m.begin(),m.end(),0);events.clear();
        m[0x74b2ba]=std::uint8_t(i);m[0x74b2b9]=std::uint8_t(i^0x55);m[0x74b2bc]=std::uint8_t(i^0xaa);
        ref_write(m.data(),0x3243da,std::uint16_t(0x8100+i));R5900Context c{};c.g[29].lo=0x7f0000;c.g[31].lo=0x1234;
        PS2Runtime runtime;o2_006AD5C0_0x6ad5c0(m.data(),&c,&runtime);
        const bool ok=events.size()==3&&events[0].stage==0&&events[1].stage==1&&events[2].stage==2&&
            events[1].scenario==0x8100+i&&events[0].a==i&&events[1].a==i&&
            events[0].b==(i^0x55)&&events[1].b==(i^0x55)&&events[0].c==(i^0xaa)&&events[1].c==(i^0xaa)&&
            events[2].a==0&&events[2].b==4&&events[2].c==0&&m[0x74b2ba]==0&&m[0x74b2b9]==4&&m[0x74b2bc]==0&&c.pc==0x1234;
        if(!ok)return 1;++checks;
    }
    std::printf("{\"original_cases\":%u,\"observed_calls_per_case\":3,\"game_launched\":false}\n",checks);
}
'''
    out.mkdir();fixture=out/'original_6ad5c0.cpp';fixture.write_text(header+ports+original[original.index('// Function:'):]+main)
    exe=out/'original_6ad5c0.exe';env=dict(os.environ);env['PATH']=str(COMPILER.parent)+os.pathsep+env.get('PATH','')
    command=[str(COMPILER),'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-parameter','-I'+str(ROOT),str(fixture),'-o',str(exe)]
    record={'status':'failed','compiler_sha256':sha(COMPILER),'original_source_sha256':sha(source),'original_word_audit':audit,'checks':[]}
    try:
        for name,cmd in [('compile',command),('test',[str(exe)])]:
            run=subprocess.run(cmd,capture_output=True,env=env,timeout=120)
            (out/(name+'.stdout.txt')).write_bytes(run.stdout);(out/(name+'.stderr.txt')).write_bytes(run.stderr)
            record['checks'].append({'name':name,'exit':run.returncode})
            if run.returncode:raise RuntimeError(name+': '+run.stderr.decode(errors='replace')[-3000:])
            if name=='test':record['result']=json.loads(run.stdout)
        record['status']='passed'
    finally:(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
    print(json.dumps(record['result']))
if __name__=='__main__':main()
