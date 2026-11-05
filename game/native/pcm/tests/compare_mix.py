#!/usr/bin/env python3
"""Supplement the frozen single-voice corpus with exact-source two-voice mixes."""
import argparse
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import shutil
import subprocess

ROOT = Path(__file__).resolve().parents[4]
HERE = Path(__file__).resolve().parent
TRANSCRIPT_SHA = '697194d2089779baf86074cf8cce28819607c4f7fd2e7561bcf557ac1d189183'
CORE_SHA = '5f86dd08b10b2ed8dd0bec1b0d11f83237ad0210b776d556de0b9f9a5d86f8eb'
FIXTURE_SHA = '819470f5433c09a5549fefae5f726012ba9ab34f3cc2e4ed3545007d89bea909'

CASES = r'''
int main(){try{
 for(unsigned stereo=0;stereo<2;++stereo)for(unsigned reverse=0;reverse<2;++reverse)
 for(unsigned mode=0;mode<3;++mode){
  const auto name="mix_"+std::to_string(stereo)+"_"+std::to_string(reverse)+"_"+std::to_string(mode);
  start(name.c_str());
  queue(1,{32767,-32768,12345,-5432,3000});queue(3,{-12345,22222,-32768,32767,-1});
  if(stereo){queue(2,{-32768,32767,-8000,10000,0});queue(4,{23000,-12000,125,-125,300});}
  stream_gain=1.3f;
  auto first=[&]{a::configure(10,1,stereo?2:0,stereo?2:1,44100,173,true);};
  auto second=[&]{a::configure(20,3,stereo?4:0,stereo?2:1,96000,249,true);};
  if(reverse){second();first();}else{first();second();}
  if(mode==1)a::drain(20);
  if(mode==2)a::configure(20,3,stereo?4:0,stereo?2:1,96000,249,false);
  render(8);
 }
 return 0;
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}}
'''


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--cxx', required=True)
    parser.add_argument('--output', required=True, type=Path)
    parser.add_argument('--reference', type=Path, default=ROOT/'build-native-sjuni/pcm-owner-oracle/gcc')
    parser.add_argument('--native-fixture', type=Path, default=ROOT/'build-native-sjuni/pcm-native-compare/gcc')
    args = parser.parse_args()
    out = args.output.resolve()
    allowed = ROOT/'build-native-sjuni'
    if out == allowed or not out.is_relative_to(allowed):
        raise ValueError('Use a private output directory')
    tool = shutil.which(args.cxx)
    if not tool:
        raise ValueError('C++ compiler missing')
    transcript = ROOT/'tools/native_reconstruction/pcm_owner_oracle.py'
    if sha(transcript) != TRANSCRIPT_SHA or sha(HERE.parent/'pcm.cpp') != CORE_SHA:
        raise ValueError('Original transcript or independently frozen native core changed')
    spec = importlib.util.spec_from_file_location('pcm_reference',transcript)
    ref = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(ref)
    reference = args.reference.resolve()
    if sha(reference/'fixtures.json') != FIXTURE_SHA:
        raise ValueError('Original reference observations changed')
    for name in ('Kernel/Syscalls/Helpers/CriAudio.cpp','Kernel/Syscalls/Helpers/CriAudio.h','cri_pcm_retire.h'):
        if sha(reference/'snapshot'/name) != ref.EXPECTED[name]:
            raise ValueError('Original reference source changed: '+name)
    prefix = ref.HARNESS.split('int main(){try{',1)[0]
    if prefix == ref.HARNESS:
        raise ValueError('Original harness boundary missing')
    original_include = '#define std pcm_test_std\n#include "snapshot/Kernel/Syscalls/Helpers/CriAudio.cpp"\n#undef std'
    if prefix.count(original_include) != 1:
        raise ValueError('Original implementation boundary changed')
    out.mkdir(parents=True,exist_ok=True)
    env = dict(os.environ)
    for name in list(env):
        if name.startswith(('REO_CRI_','REO_AUDIO_PATH','REO_RNA_STOP')):
            env.pop(name,None)
    cc = Path(tool).resolve()
    env['PATH'] = str(cc.parent)+os.pathsep+env.get('PATH','')
    records = {}
    proof = dict(schema=1,game_run=False,device_opened=False,compiler=tool,
        compiler_sha256=sha(cc),original_fixture_sha256=FIXTURE_SHA,
        native_core_frozen_sha256=CORE_SHA,transcript_sha256=TRANSCRIPT_SHA,
        source_sha256=sha(Path(__file__)),builds={},
        native_source_sha256={str(p.relative_to(ROOT)):sha(p) for p in
            (HERE.parent/'pcm.cpp',HERE.parent/'pcm.hpp',HERE/'native_facade.hpp')})
    for name, base in [('original',args.reference.resolve()),('native',args.native_fixture.resolve())]:
        body = prefix if name == 'original' else prefix.replace(original_include,'#include "native_facade.hpp"')
        dependencies = {str(p.relative_to(base)):sha(p) for p in sorted(base.rglob('*'))
            if p.is_file() and p.suffix in ('.h','.hpp','.inc','.cpp')}
        source, exe = out/(name+'.cpp'), out/(name+'.exe')
        source.write_text(body+CASES,encoding='utf-8')
        command = [tool,'-std=c++20','-O1','-ffp-contract=off','-Wall','-Wextra','-Wpedantic','-Werror','-pthread',
            '-I'+str(base),'-I'+str(base/'snapshot'),'-I'+str(ROOT),'-I'+str(HERE),str(source)]
        if name == 'native':
            command.append(str(HERE.parent/'pcm.cpp'))
        command += ['-o',str(exe)]
        build = subprocess.run(command,env=env,capture_output=True,text=True,timeout=90)
        if build.returncode:
            raise RuntimeError(build.stderr)
        run = subprocess.run([str(exe)],check=True,env=env,capture_output=True,text=True,timeout=30)
        records[name] = [json.loads(row) for row in run.stdout.splitlines()]
        artifact = out/(name+'.json')
        artifact.write_text(json.dumps(records[name],indent=2)+'\n',encoding='utf-8')
        proof['builds'][name] = dict(command=command,source_sha256=sha(source),
            executable_sha256=sha(exe),observations_sha256=sha(artifact),included_snapshot_sha256=dependencies)
    if records['original'] != records['native']:
        raise ValueError('Two-voice original/native snapshot difference')
    proof.update(status='passed',cases=len({r['case'] for r in records['original']}),
        snapshots=len(records['original']),float_values=sum(len(r['float_bits']) for r in records['original']))
    (out/'receipt.json').write_text(json.dumps(proof,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({k:proof[k] for k in ('status','cases','snapshots','float_values')}))


if __name__ == '__main__':
    main()
