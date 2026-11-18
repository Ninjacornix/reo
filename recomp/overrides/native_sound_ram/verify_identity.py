#!/usr/bin/env python3
"""Verify real pre-run file/RNG observations; never construct a game Runtime."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import subprocess

HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]
ELF=ROOT/'game_data/SLUS_207.65'
ELF_SHA='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'

def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--cxx',type=Path,required=True)
    parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args()
    out=args.output.resolve()
    if out.exists() or not out.is_relative_to(ROOT/'build-native-sjuni'):
        raise ValueError('Fresh private output required')
    if sha(ELF)!=ELF_SHA:
        raise ValueError('Owned original ELF identity differs')
    out.mkdir(parents=True)
    compiler=args.cxx.resolve()
    env=os.environ.copy()
    env['PATH']=str(compiler.parent)+os.pathsep+env.get('PATH','')
    inputs={str(path.relative_to(ROOT)):sha(path) for path in (
        HERE/'build_identity.cpp',HERE/'build_identity.h',HERE/'identity_runner.cpp',Path(__file__))}
    proof=dict(schema=1,status='running',compiler=str(compiler),compiler_sha256=sha(compiler),
               inputs=inputs,original_elf_sha256=ELF_SHA,checks=[],game_run=False,
               device_opened=False,runtime_constructed=False,ram_authority_exercised=False)
    def run(label,command):
        result=subprocess.run([str(part) for part in command],cwd=ROOT,env=env,text=True,capture_output=True)
        (out/(label+'.txt')).write_text(result.stdout+result.stderr,encoding='utf-8',newline='\n')
        proof['checks'].append(dict(label=label,command=[str(part) for part in command],exit_code=result.returncode))
        if result.returncode:
            raise RuntimeError(label+': '+result.stdout+result.stderr)
        return result.stdout
    def observations(exe,prefix,negative=False):
        first=json.loads(run(prefix+'valid',[exe,ELF]))
        if not negative:
            assert first['status']==0 and first['original']==ELF_SHA
            assert first['native']==sha(exe)
            assert int(first['session'],16)!=0
            assert first['runtime_incarnation']==first['ram_incarnation']==first['ram_bytes']==0
            second=json.loads(run(prefix+'repeat',[exe,ELF]))
            assert second['status']==0 and second['session']!=first['session']
            assert second['native']==first['native']
        missing=json.loads(run(prefix+'missing',[exe,out/'missing-input.elf']))
        assert missing['status']==1
        wrong=json.loads(run(prefix+'wrong',[exe,out/'wrong-input.elf']))
        if negative:
            assert wrong['status']==0
        else:
            assert wrong['status']==2
    try:
        flags=[compiler,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror',
               '-Wl,--no-insert-timestamp','-I'+str(HERE)]
        exe=out/'identity.exe'
        run('build',flags+[HERE/'build_identity.cpp',HERE/'identity_runner.cpp','-lbcrypt','-o',exe])
        (out/'wrong-input.elf').write_bytes(b'Not the owned File1 ELF\n')
        observations(exe,'primary-')
        proof['executable_sha256']=sha(exe)
        source=(HERE/'build_identity.cpp').read_text(encoding='utf-8')
        needle='if(*original!=original_digest)'
        assert source.count(needle)==1
        altered=out/'missing_original_check.cpp'
        altered.write_text(source.replace(needle,'if(false && *original!=original_digest)'),encoding='utf-8',newline='\n')
        bad=out/'missing_original_check.exe'
        run('negative_build',flags+[altered,HERE/'identity_runner.cpp','-lbcrypt','-o',bad])
        observations(bad,'negative-',negative=True)
        proof['negative_control']='Removing original ELF check admits the wrong input; primary policy detects that mismatch.'
        proof['source_unchanged']=all(sha(ROOT/name)==digest for name,digest in inputs.items()) and sha(ELF)==ELF_SHA
        assert proof['source_unchanged']
        proof['status']='passed'
    finally:
        (out/'receipt.json').write_text(json.dumps(proof,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=proof['status'],receipt=str(out/'receipt.json'),sha256=sha(out/'receipt.json'))))

if __name__=='__main__':
    main()
