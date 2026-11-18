#!/usr/bin/env python3
"""Compile real owner-thread observer with explicit guest/runtime fixture ports."""
import argparse,hashlib,json,os,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists() or not out.is_relative_to(ROOT/'build-native-sjuni/cri-timer'):raise ValueError('Fresh owned output required')
    header=ROOT/'recomp/overrides/reo_cri_server_observer.h';fixture=ROOT/'tools/native_reconstruction/cri_timer_observer_check.cpp'
    body=header.read_text()
    if any(s in body for s in ['std::thread','sample_slots','reinterpret_cast<volatile','begin_samples','end_samples']):raise ValueError('Concurrent plain-context sampling remains')
    out.mkdir(parents=True);(out/'observer.h').write_bytes(header.read_bytes())
    (out/'ps2_runtime.h').write_text('#pragma once\n#include <cstdint>\nconstexpr uint32_t PS2_RAM_SIZE=0x2000000;\nstruct R5900Context {uint32_t regs[32]{};uint32_t pc{};};struct PS2Runtime {};\n',encoding='utf-8',newline='\n')
    (out/'ps2_runtime_macros.h').write_text('#pragma once\n#define GPR_U32(c,n) ((c)->regs[n])\n',encoding='utf-8',newline='\n')
    (out/'reo_game_clock_observer.h').write_text('#pragma once\n#include <cstring>\nnamespace reo_game_clock {inline uint32_t word(const uint8_t* m,uint32_t p){uint32_t v;std::memcpy(&v,m+p,4);return v;}}\n',encoding='utf-8',newline='\n')
    env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');binary=out/'check.exe'
    record=dict(status='failed',sources={str(x.relative_to(ROOT)):sha(x)for x in [header,fixture,Path(__file__)]},compiler_sha256=sha(a.compiler),game_run=False,thread_sampling=False,fixture_runtime=True)
    try:
        cmd=[str(a.compiler),'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-I'+str(out),str(fixture),'-o',str(binary)]
        build=subprocess.run(cmd,capture_output=True,text=True,env=env);(out/'compile.txt').write_text(build.stdout+build.stderr,encoding='utf-8',newline='\n')
        if build.returncode:raise ValueError('Observer compile failed')
        run=subprocess.run([str(binary)],capture_output=True,text=True,env=env,timeout=10);(out/'run.txt').write_text(run.stdout+run.stderr,encoding='utf-8',newline='\n')
        if run.returncode or 'pc_samples=unavailable' not in run.stderr:raise ValueError('Observer delegation failed')
        if any(sha(ROOT/n)!=v for n,v in record['sources'].items()):raise ValueError('Source changed')
        record.update(status='owner-thread CRI timer delegation qualified',binary_sha256=sha(binary))
    finally:
        record['outputs_sha256']={x.name:sha(x)for x in out.iterdir()if x.suffix in ['.h','.txt']};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=record['status'],receipt_sha256=sha(out/'receipt.json'))))
if __name__=='__main__':main()
