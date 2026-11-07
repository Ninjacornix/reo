#!/usr/bin/env python3
"""Original picture-pool policy and joined public-frame/timing comparison."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import verify as timing
ROOT=timing.ROOT;HERE=Path(__file__).resolve().parent;BASE=ROOT/'build-native-sjuni/movie-video-frames'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def clock(snapshot,full):
    value=timing.projection(snapshot)
    if not full:del value[296:298]
    return value
def state(snapshot,full):
    value=clock(snapshot,full)+[v for picture in snapshot['pictures'] for v in picture]
    if full:value+=snapshot['public_valid']+[snapshot['current']]
    return value
def plan(cases,originals):
    lines=[];expected=[]
    for identity,(case,original) in enumerate(zip(cases,originals,strict=True)):
        full=bool(case.get('public_profile'));values=[identity,int(full)]+[case['facts'][name] for name in timing.FIELDS]+[case[key] for key in ['frequency','hooks','guard_depth','guard_tag','end']]+[len(case['pictures'])]
        for picture in case['pictures']:values += [picture[key] for key in ['state','references','numerator','denominator']]
        lines.append('begin '+' '.join(map(str,values)));expected.append((identity,-1,state(original['initial'],full)+[0,0,0]));lines.append(str(len(case['operations'])))
        for index,(op,row) in enumerate(zip(case['operations'],original['operations'],strict=True)):
            lines.append(op['kind']+' '+' '.join(map(str,[op['slot'],op['value']]+op['sample']+[op[key] for key in ['counter','helper_frequency','adxt_status']]+timing.patch(op['facts']))))
            returned=0 if op['kind'] in ['release','demote','tick'] else row['returned']
            events=[e for e in row['events'] if full or not e['kind'].startswith('guard_')]
            values=state(row['after'],full)+[returned,row['flag'],len(events)]
            for event in events:
                kind=event['kind'];args=event['arguments'][1:] if kind=='command' else [0,0,event['arguments'][0],0] if kind.startswith('guard_') else [0]*4
                if kind not in timing.EVENTS:raise ValueError('Unexpected original boundary '+kind)
                values += [timing.EVENTS[kind]]+args+clock(event['before'],full)
            expected.append((identity,index,values))
    return '\n'.join(lines)+'\n',expected

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);args=p.parse_args();out=args.output.resolve();cc=shutil.which(args.cxx)
    if not cc or out.exists() or not out.is_relative_to(BASE):raise ValueError('Exact compiler/fresh scope required')
    cohorts=[];receipts={}
    for tag,digest,pre_digest in [('gcc','f271a89576a24def8880e7c71e8f280d9d63de3ea791c27d588b611a55cd89b0','5515dc5cbe2a97d16edfe94563e68824ac464f3b1054f98315fa688e775ebba0'),('llvm','9d2a652768f6527ca6b32737ce1b2c478018532bc026f16d32c33aa5eb3d0d4d','43e2d6a771fb4b17a7325c307a5a8140657cb75c4163d870469812a41734c1b1')]:
        scope=BASE/('original-'+tag+'-v4');receipt=json.loads((scope/'receipt.json').read_bytes());authority=json.loads((scope/'input-manifest.json').read_bytes());pre=BASE/('original-'+tag+'-v2');before=json.loads((pre/'input-manifest.json').read_bytes())
        if sha(scope/'receipt.json')!=digest or sha(pre/'receipt.json')!=pre_digest or before['native_video_exists']:raise ValueError('Original provenance drift')
        for directory in [scope,pre]:
            record=json.loads((directory/'receipt.json').read_bytes())
            for name,pinned in record['outputs_sha256'].items():
                if sha(directory/name)!=pinned:raise ValueError('Original output drift')
        for name,pinned in authority['sources'].items():
            if sha(ROOT/name)!=pinned:raise ValueError('Original runner drift '+name)
        if sha(ROOT/'game_data/SLUS_207.65')!=authority['elf_sha256']:raise ValueError('ELF drift')
        cases=json.loads((scope/'inputs.json').read_bytes());originals=json.loads((scope/'original.json').read_bytes())
        if cases[:199]!=json.loads((pre/'inputs.json').read_bytes()) or originals[:199]!=json.loads((pre/'original.json').read_bytes()):raise ValueError('Pre-native workflows changed')
        cohorts.append((cases,originals));receipts[tag]=digest
    if cohorts[0]!=cohorts[1]:raise ValueError('Original compiler results differ')
    cases,originals=cohorts[0];text,expected=plan(cases,originals);manifest=json.loads((HERE/'manifest.json').read_bytes())
    def drift():return [name for name,digest in manifest['files'].items() if sha(ROOT/name)!=digest]
    if drift():raise ValueError('Manifest drift '+str(drift()))
    out.mkdir(parents=True);(out/'plan.txt').write_text(text,encoding='utf-8');env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','')
    flags=[cc,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-fno-fast-math','-ffp-contract=off','-frounding-math','-I'+str(HERE),'-I'+str(HERE/'../movie_selected_clock')]
    report=dict(status='running',compiler=cc,compiler_sha256=sha(Path(cc)),manifest_sha256=sha(HERE/'manifest.json'),original_receipts=receipts,cases=len(cases),operations=662,rows=len(expected),checks=[],negative_controls=[],game_run=False,device_opened=False,production_selected=False,primitive_policy_guard_observations_excluded=True,joined_public_frame_guard_observations_compared=True,legacy_public_payload_pointer_abi_excluded=True)
    def run(name,command,stdin=None):
        value=subprocess.run([str(v) for v in command],input=stdin,text=True,capture_output=True,env=env,timeout=90);(out/(name+'.txt')).write_text(value.stdout+value.stderr,encoding='utf-8');report['checks'].append(dict(name=name,exit=value.returncode))
        if value.returncode:raise ValueError(name+': '+value.stdout+value.stderr)
        return value.stdout
    def object(name,path):
        target=out/(name+'.o');run(name+'-compile',flags+['-c',path,'-o',target]);return target
    def compare(name,items):
        binary=out/(name+'.exe');run(name+'-link',[cc,*items,fixture,'-o',binary]);rows=run(name,[binary],text).splitlines();diff=[]
        if len(rows)!=len(expected):raise ValueError('Incomplete video transcript')
        for (identity,index,values),row in zip(expected,rows,strict=True):
            tokens=row.split()
            if tokens[:3]!=['row',str(identity),str(index)]:raise ValueError('Video row identity')
            actual=list(map(int,tokens[3:]))
            if values!=actual:diff.append(dict(case=cases[identity]['name'],operation=index,expected_length=len(values),actual_length=len(actual),fields=[dict(index=n,expected=a,actual=b) for n,(a,b) in enumerate(zip(values,actual)) if a!=b]))
        (out/(name+'-differences.json')).write_text(json.dumps(diff,indent=2)+'\n',encoding='utf-8');return diff
    try:
        definitions=[('context',HERE/'context.cpp'),('video',HERE/'video_frames.cpp'),('commands',HERE/'audio_commands.cpp'),('buffering',HERE/'buffering.cpp')]+[(name,HERE/'..'/directory/file) for name,directory,file in [('selected','movie_selected_clock','clock.cpp'),('counter','movie_counter_clock','clock.cpp'),('audio','movie_audio_clock','clock.cpp'),('filter','movie_audio_filter','filter.cpp'),('pause','movie_pause','controller.cpp'),('admission','movie_admission','admission.cpp'),('initialize','movie_clock_initialize','initialize.cpp')]]
        objects={name:object(name,path) for name,path in definitions};fixture=object('fixture',HERE/'video_fixture.cpp');diff=compare('native',list(objects.values()));report['native_differences']=len(diff)
        if diff:raise ValueError('Video source comparison differs '+str(diff[:2]))
        body=(HERE/'video_frames.cpp').read_text(encoding='utf-8')
        for name,old,new in [
            ('unstable-equal-timestamps','<std::bit_cast<std::int32_t>(current.time.numerator);','<=std::bit_cast<std::int32_t>(current.time.numerator);'),
            ('scaled-instead-of-raw-order','return std::bit_cast<std::int32_t>(candidate.time.numerator)<std::bit_cast<std::int32_t>(current.time.numerator);','return std::int64_t{std::bit_cast<std::int32_t>(candidate.time.numerator)}*std::bit_cast<std::int32_t>(current.time.denominator)<std::int64_t{std::bit_cast<std::int32_t>(current.time.numerator)}*std::bit_cast<std::int32_t>(candidate.time.denominator);'),
            ('allow-held-state-as-ready','if(picture.state!=2 && picture.state!=4)continue;','if(picture.state!=2 && picture.state!=4 && picture.state!=3)continue;'),
            ('ignore-reservation-references','pictures_[i].state==0 && pictures_[i].references==0','pictures_[i].state==0'),
            ('drop-ready-reference-on-release','pictures_[slot].state==4?3:0','0u'),
            ('advance-checks-first','pictures_[selection.second].time','pictures_[selection.first].time'),
            ('ignore-running-state','facts.actual!=4 || selection.count<2','false || selection.count<2'),
            ('omit-public-clock-publication','clock_->initial_.previous=pool_.pictures_[slot].time;','(void)pool_.pictures_[slot].time;')]:
            if old not in body:raise ValueError('Mutation selector drift '+name)
            path=out/(name+'.cpp');path.write_text(body.replace(old,new),encoding='utf-8');mutant=object(name,path);diff=compare(name,[mutant if key=='video' else value for key,value in objects.items()])
            if not diff:raise ValueError('Undetected video fault '+name)
            report['negative_controls'].append(dict(name=name,differing_rows=len(diff)))
        if drift():raise ValueError('Source changed during qualification')
        report['native_transcript_sha256']=sha(out/'native.txt');report['status']='qualified original video queue and joined public-frame clock behavior'
    except Exception as error:report['status']='failed';report['failure']=str(error);raise
    finally:
        report['outputs_sha256']={p.name:sha(p) for p in out.iterdir() if p.is_file() and p.suffix in ['.txt','.json','.cpp'] and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({key:report[key] for key in ['status','cases','operations','rows','native_differences']}|{'receipt_sha256':sha(out/'receipt.json')}))
if __name__=='__main__':main()
