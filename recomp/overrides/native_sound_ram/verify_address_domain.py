#!/usr/bin/env python3
"""Check strict address policy only; does not qualify a RAM capture factory."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import subprocess

HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]

def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--cxx',type=Path,required=True)
    parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args()
    out=args.output.resolve()
    if out.exists() or not out.is_relative_to(ROOT/'build-native-sjuni'):
        raise ValueError('Fresh private output below build-native-sjuni required')
    out.mkdir(parents=True)
    compiler=args.cxx.resolve()
    env=os.environ.copy()
    env['PATH']=str(compiler.parent)+os.pathsep+env.get('PATH','')
    files=[HERE/name for name in ('address_domain.h','address_domain.cpp','address_domain_tests.cpp','verify_address_domain.py')]
    inputs={str(path.relative_to(ROOT)):sha(path) for path in files}
    proof=dict(schema=1,status='running',game_run=False,device_opened=False,
               runtime_factory_implemented=False,ram_authority_exercised=False,
               compiler=str(compiler),compiler_sha256=sha(compiler),inputs=inputs,checks=[])
    def run(label,command,expect=0):
        result=subprocess.run([str(part) for part in command],cwd=ROOT,env=env,text=True,capture_output=True)
        (out/(label+'.txt')).write_text(result.stdout+result.stderr,encoding='utf-8',newline='\n')
        proof['checks'].append(dict(label=label,command=[str(part) for part in command],exit_code=result.returncode,expected=expect))
        if result.returncode!=expect:
            raise RuntimeError(label+' failed: '+result.stdout+result.stderr)
    try:
        run('compiler',[compiler,'--version'])
        flags=[compiler,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-Wl,--no-insert-timestamp','-I'+str(HERE)]
        exe=out/'address_domain.exe'
        run('build',flags+[HERE/'address_domain.cpp',HERE/'address_domain_tests.cpp','-o',exe])
        run('units',[exe])
        proof['executable_sha256']=sha(exe)
        source=(HERE/'address_domain.cpp').read_text(encoding='utf-8')
        variants={
            'missing_aperture':('if(overlaps(range,aperture))','if(false && overlaps(range,aperture))'),
            'extra_mirror':('std::array<std::uint32_t,4> bases{0,0x20000000u,0x80000000u,0xa0000000u}',
                            'std::array<std::uint32_t,5> bases{0,0x20000000u,0x80000000u,0xa0000000u,0xc0000000u}'),
            'missing_host_alias':('if(overlaps(extent,ee_) || overlaps(extent,iop_))',
                                  'if(false && (overlaps(extent,ee_) || overlaps(extent,iop_)))')}
        for label,(before,after) in variants.items():
            if source.count(before)!=1:
                raise ValueError('Nonunique negative control '+label)
            altered=out/(label+'.cpp')
            altered.write_text(source.replace(before,after),encoding='utf-8',newline='\n')
            bad=out/(label+'.exe')
            run(label+'_build',flags+[altered,HERE/'address_domain_tests.cpp','-o',bad])
            run(label+'_detected',[bad],expect=1)
        proof['inputs_unchanged']=all(sha(ROOT/name)==digest for name,digest in inputs.items())
        if not proof['inputs_unchanged']:
            raise ValueError('Source changed during proof')
        proof['status']='passed'
    finally:
        (out/'receipt.json').write_text(json.dumps(proof,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=proof['status'],receipt=str(out/'receipt.json'),sha256=sha(out/'receipt.json'))))

if __name__=='__main__':
    main()
