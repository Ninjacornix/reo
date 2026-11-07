#!/usr/bin/env python3
"""Qualify actual phased players, retained credits and preserved clock bodies."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess

HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[2]
BASE=ROOT/'build-native-sjuni/adxt-phased-player'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
SOURCES=['audio_mix_tail/mixer.cpp', 'audio_banks/v2/session.cpp', 'audio_banks/v2/algorithms.cpp', '../../recomp/overrides/native_banks/v3/packet_adapter.cpp','adx_sequence/sequence.cpp','adx_sequence/clip.cpp','adxt_lsc_input/input.cpp','lsc_queue/queue.cpp','resources/bounded_view.cpp','sjrb/sjrb.cpp','adxt_shared_source/shared_source.cpp','adxt_refill/adxt_refill.cpp',
         'resource_io/async_read_owner.cpp','tasks/serial_worker.cpp','resources/resource_session.cpp',
         'resources/virtual_file_view.cpp','adx_header/adx_header.cpp','adx_workspace/adx_workspace.cpp',
         'adx_pcm_store/v2/pcm_store.cpp','adx_window/v2/queue_safe_r3/stream_window.cpp',
         'adxt_playback/playback.cpp','adxt_estimated_clock/estimated_clock.cpp',
         'adxt_integer_clock/integer_clock.cpp','adxt_serviced_clock/completion.cpp','adxt_output_session/session.cpp','pcm/pcm.cpp',
         'audio_output/audio_output_owner.cpp','adxt_service_group/service_group.cpp','adxt_transfer_groups/transfer_groups.cpp']


def body(text,needle):
    if text.count(needle)!=1:raise ValueError('Inherited source selector drift '+needle)
    start=text.index('{',text.index(needle));depth=0
    for i in range(start,len(text)):
        if text[i]=='{':depth+=1
        elif text[i]=='}':
            depth-=1
            if not depth:return text[start:i+1]
    raise ValueError('Unclosed inherited body')


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();cc=shutil.which(a.cxx);out=a.output.resolve()
    if not cc or out.exists()or not out.is_relative_to(BASE):raise ValueError('Exact compiler and fresh scoped output required')
    manifest=json.loads((HERE/'manifest.json').read_bytes())
    def drift():return[n for n,d in manifest['files'].items()if sha(ROOT/n)!=d]
    if drift():raise ValueError('Frozen input drift '+str(drift()))
    inherited=(ROOT/'game/native/adxt_clocked_player/player.cpp').read_text(encoding='utf-8');current=(HERE/'player.cpp').read_text(encoding='utf-8');identical={};extensions={}
    for needle in ['Status fail()noexcept','clock::integer::Observation observation(const','clock::integer::Observation observation()const',
                   'void synchronize_clock()','Status pump()', 'Player::Player(', 'Player::~Player()', 'Status Player::gain(',
                   'ClockResult Player::estimate(', 'ClockResult Player::centiseconds(', 'ClockControl Player::pause(',
                   'ClockControl Player::discard_rebase(', 'Status Player::set_time_base(', 'void Player::request_stop(', 'Status Player::retire_on_control_thread(']:
        old,new=body(inherited,needle),body(current,needle)
        actual=new
        if needle=='clock::integer::Observation observation(const':
            new=new.replace('        o.offset=static_cast<std::uint32_t>(w.loop.seamless_samples);\n','').replace('actual owned seamless accumulation.','no admitted seamless/A4 offset in this cut.')
        if needle=='Status pump()':
            new=new.replace('            const auto maximum=config.lsc_input?config.lsc_input->snapshot().planned_samples:\n                config.sequence?config.sequence->total_samples():before.header.base.total_samples;\n','').replace('maximum-first','before.header.base.total_samples-first')
        if needle=='void Player::request_stop(':
            new=new.replace('if(state_->config.lsc_input)state_->config.lsc_input->request_stop();','')
        if needle=='Status Player::retire_on_control_thread(':
            new=new.replace('    if(s.config.lsc_input)s.config.lsc_input->request_stop();\n','').replace('    if(s.config.lsc_input)s.config.lsc_input->after_source(s.decoder.snapshot().source,true);\n','')
        if old!=new:raise ValueError('Unreviewed inherited algorithm delta '+needle)
        if actual==old:identical[needle]=hashlib.sha256(actual.encode()).hexdigest()
        else:extensions[needle]=dict(actual_sha256=hashlib.sha256(actual.encode()).hexdigest(),legacy_absence_normalization_sha256=hashlib.sha256(new.encode()).hexdigest())
    out.mkdir(parents=True);env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','')
    report=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),manifest_sha256=sha(HERE/'manifest.json'),inherited_bodies=identical,reviewed_profile_extensions=extensions,checks=[],negative_controls=[],game_run=False,device_opened=False,original_whole_pipeline_parity=False)
    flags=[cc,'-std=c++20','-O2','-pthread','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-misleading-indentation','-fno-fast-math','-ffp-contract=off','-frounding-math','-I'+str(HERE),'-I'+str(ROOT)]
    deps=[ROOT/'game/native'/n for n in SOURCES]
    def run(name,cmd,negative=False,cwd=ROOT):
        r=subprocess.run([str(x)for x in cmd],cwd=cwd,env=env,text=True,capture_output=True,timeout=90)
        (out/(name+'.txt')).write_text(r.stdout+r.stderr,encoding='utf-8',newline='\n');report['checks'].append(dict(name=name,command=[str(x)for x in cmd],exit=r.returncode))
        if negative:
            if not r.returncode:raise ValueError('Negative passed '+name)
        elif r.returncode:raise ValueError(name+': '+r.stdout+r.stderr)
        return r.stdout.strip()
    try:
        objects=[out/(str(i)+'_'+p.stem+'.o')for i,p in enumerate(deps)]
        if len(set(objects))!=len(objects):raise ValueError('Colliding dependency object names')
        
        for i,(dep,obj) in enumerate(zip(deps,objects,strict=True)):run('dependency-compile-'+str(i),flags+['-c',dep,'-o',obj],cwd=out)
        report['dependency_objects']={p.name:sha(p)for p in objects}
        binary=out/'units.exe';run('units-compile',flags+objects+[HERE/'player.cpp',HERE/'player_tests.cpp','-o',binary]);report['units']=run('units',[binary]);report['executable_sha256']=sha(binary)
        credit='if(decoder.finish_pcm(*held)!=window::Status::completed)return fail();'
        old='if(output->copy(spans[0],spans[1])!=output::Status::completed)return fail();\n            '+credit
        mutants=[('early-decoder-credit',old,credit+'\n            if(output->copy(spans[0],spans[1])!=output::Status::completed)return fail();'),
                 ('missing-rna-prime','s.transfer_primed=true;','/* missing native RNA prime */'),
                 ('hidden-source-poll','const auto result=s.decoder.service(s.request);','(void)s.decoder.service_source();const auto result=s.decoder.service(s.request);')]
        for name,old,new in mutants:
            if current.count(old)!=1:raise ValueError('Mutation source drift '+name)
            path=out/(name+'.cpp');path.write_text(current.replace(old,new),encoding='utf-8',newline='\n');binary=out/(name+'.exe')
            run(name+'-compile',flags+objects+[path,HERE/'player_tests.cpp','-o',binary]);run(name,[binary],negative=True)
            report['negative_controls'].append(dict(name=name,source_sha256=sha(path)))
        report.update(status='passed actual phased player/group ownership and preserved clock/data-plane bodies',finite_matrix=48)
    except Exception as error:report.update(status='failed',failure=str(error));raise
    finally:
        report['source_drift']=drift()
        if report['source_drift']:report['status']='failed source drift'
        (out/'receipt.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=report['status'],units=report['units'],receipt_sha256=sha(out/'receipt.json'))))


if __name__=='__main__':main()
