#!/usr/bin/env python3
"""Game handle to canonical movie source, with declared guest RAM and real workers."""
import argparse
import hashlib
import json
import os
import shutil
import subprocess
from pathlib import Path

HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()

def write(path,text):path.write_text(text,encoding='utf-8',newline='\n')

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    for name in ('compiler','capability-receipt','output'):parser.add_argument('--'+name,type=Path,required=True)
    args=parser.parse_args();out=args.output.resolve()
    if out.exists() or not out.is_relative_to(ROOT/'build-native-sjuni/movie-handoff'):raise ValueError('Fresh owned output required')
    if shutil.disk_usage(ROOT).free<128*1024**2:raise ValueError('At least128MiB free required')
    qualification=ROOT/'tools/native_reconstruction/movie_instance_audio_qualification.json'
    proof=json.loads(qualification.read_bytes());receipt=args.capability_receipt.resolve()
    if proof['receipts'].get(receipt.relative_to(ROOT).as_posix())!=sha(receipt):raise ValueError('Qualified canonical capability receipt required')
    native=json.loads(receipt.read_bytes())
    if native['status']!='canonical movie/audio source capability checks passed' or native['compiler_sha256']!=sha(args.compiler):raise ValueError('Matching qualified compiler required')
    manifest=ROOT/proof['source_manifest']
    if sha(manifest)!=proof['source_manifest_sha256']:raise ValueError('Canonical capability manifest drift')
    sources=json.loads(manifest.read_bytes())['files']
    for path in (*sorted(HERE.iterdir()),ROOT/'tools/native_reconstruction/prepare_native_candidate.py'):
        if path.is_file() and path.suffix in ('.h','.cpp','.py','.json'):
            sources[path.relative_to(ROOT).as_posix()]=sha(path)
    def verify():
        for name,digest in {**sources,**native['reused_libraries']}.items():
            if sha(ROOT/name)!=digest:raise ValueError('Input/archive drift '+name)
    verify();out.mkdir(parents=True);env=dict(os.environ);env['PATH']=str(args.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
    record=dict(status='failed',sources=sources,compiler_sha256=sha(args.compiler),capability_receipt_sha256=sha(receipt),capability_qualification_sha256=sha(qualification),reused_libraries=native['reused_libraries'],rebuilt_production_translation_units=native['rebuilt_production_translation_units'],game_run=False,device_opened=False,actual_guest_hooks_installed=False,actual_runtime_acquisition=False,actual_native_workers=True,checks=[])
    def run(label,command,negative=False):
        result=subprocess.run(list(map(str,command)),env=env,capture_output=True,text=True,timeout=100)
        write(out/(label+'.txt'),result.stdout+result.stderr);record['checks'].append(dict(label=label,exit=result.returncode,negative=negative))
        if (result.returncode==0)==negative:raise ValueError(label+' unexpected result; see retained log')
        print(label+': '+('fault detected' if negative else 'passed'),flush=True)
    flags=[args.compiler,'-std=c++20','-O2','-pthread','-Wall','-Wextra','-Wpedantic','-Werror','-fno-fast-math','-ffp-contract=off','-frounding-math','-I'+str(HERE),'-I'+str(ROOT)]
    core=[*[ROOT/name for name in native['rebuilt_production_translation_units']],ROOT/'game/native/movie_instance_audio/source.cpp']
    archives=['-Wl,--start-group',*[ROOT/name for name in native['reused_libraries']],'-Wl,--end-group']
    def case(label,source,negative=False):
        exe=out/(label+'.exe');run(label+'-compile',flags+[source,HERE/'game_handles_tests.cpp',*core,*archives,'-o',exe]);run(label,[exe],negative)
    try:
        case('handoff',HERE/'game_handles.cpp');body=(HERE/'game_handles.cpp').read_text(encoding='utf-8');mutations={}
        faults=(
            ('file-slot-is-stream-slot','h.decoder_slot,h.slot,h.rna_slot','h.decoder_slot,h.file_slot,h.rna_slot'),
            ('release-pending-children','if(status==S::completed)release(key.slot_);','if(status==S::completed || status==S::pending)release(key.slot_);'),
            ('ignore-secondary-transfer','a.transfer[i]==b.transfer[j]','(i==0 && j==0 && a.transfer[i]==b.transfer[j])'),
            ('ignore-game-key','if(!valid(key))return{P::invalid_key,{}};',''),
            ('capture-inside-borrow','return movie_instance_audio::Source::capture(s.owner,r.native,std::move(tick));',
             'movie_instance_audio::Capture result;Operation wrong([&](auto&){result=movie_instance_audio::Source::capture(s.owner,r.native,std::move(tick));});'
             'if(s.owner->run(wrong)!=control_owner::Admission::accepted)return{P::closed,{}};return result;'))
        for name,anchor,replacement in faults:
            if body.count(anchor)!=1:raise ValueError('Unique mutation anchor required '+name)
            path=out/(name+'.cpp');write(path,body.replace(anchor,replacement));case(name,path,True);mutations[name]=sha(path)
        verify();record.update(status='game handle canonical movie source handoff qualified',workflows=4,detected_faults=list(mutations),fault_sources_sha256=mutations)
    except Exception as error:record['failure']=str(error);raise
    finally:
        record['outputs_sha256']={p.name:sha(p) for p in out.iterdir() if p.is_file()};write(out/'receipt.json',json.dumps(record,indent=2)+'\n')
    print(json.dumps(dict(status=record['status'],receipt_sha256=sha(out/'receipt.json'))))

if __name__=='__main__':main()
