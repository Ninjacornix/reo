#!/usr/bin/env python3
"""Read-only child/link/geometry checks with frozen independent parent fixture."""
import argparse,hashlib,json,os,subprocess,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2];HERE=ROOT/'recomp/overrides/native_adxt'
sys.path.insert(0,str(ROOT/'tools/function_index'));from index import Elf
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists() or not out.is_relative_to(ROOT/'build-native-sjuni/adxt-binding/lsc-profile'):raise ValueError('Fresh owned output required')
    prior=json.loads((HERE/'handle_qualification.json').read_bytes());fixture=HERE/'handle_profile_tests.cpp'
    if sha(fixture)!=prior['authored_sha256']['handle_profile_tests.cpp']:raise ValueError('Frozen parent fixture drift')
    elf=Elf(ROOT/'game_data/SLUS_207.65')
    if elf.sha256!='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46' or int.from_bytes(elf.read(0x224c4c,4),'little')!=0x13fa38:raise ValueError('Owned SJRB method table identity')
    source=fixture.read_text();anchor='template<class F>void refuse'
    if source.count(anchor)!=1:raise ValueError('Independent fixture extraction changed')
    out.mkdir(parents=True);(out/'handle_fixture.hpp').write_text(source[:source.index(anchor)],encoding='utf-8',newline='\n')
    record=dict(schema=1,status='failed',compiler_sha256=sha(a.compiler),elf_sha256=elf.sha256,
        source_sha256={p.relative_to(ROOT).as_posix():sha(p)for p in [Path(__file__),HERE/'lsc_profile.h',HERE/'lsc_profile_tests.cpp',fixture,HERE/'handle_profile.h']},
        lifecycle_qualification_sha256=sha(ROOT/'tools/native_reconstruction/lsc_lifecycle_qualification.json'),
        capacity_qualification_sha256=sha(ROOT/'tools/native_reconstruction/lsc_capacity_qualification.json'),game_run=False,runtime_admission=False,source_capability=False,guest_writes=False,checks=[])
    env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
    def run(label,cmd):
        r=subprocess.run(list(map(str,cmd)),capture_output=True,text=True,env=env,timeout=90);(out/(label+'.txt')).write_text(r.stdout+r.stderr,encoding='utf-8',newline='\n');record['checks'].append(dict(label=label,exit_code=r.returncode,command=list(map(str,cmd))))
        if r.returncode:raise ValueError(label+' failed: '+r.stderr)
        return r.stdout
    try:
        binary=out/'lsc-profile.exe';run('compile',[a.compiler,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-misleading-indentation','-I'+str(out),'-I'+str(HERE),'-I'+str(ROOT),HERE/'lsc_profile_tests.cpp','-o',binary]);record['observation']=run('tests',[binary]);record.update(status='read-only LSC child profile checks passed',binary_sha256=sha(binary))
    finally:
        (out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(record['observation'].strip())
if __name__=='__main__':main()
