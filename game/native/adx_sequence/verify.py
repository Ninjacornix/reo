#!/usr/bin/env python3
"""Qualify sealed sequence admission, pending-header ownership and clock binding."""
import argparse
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import shutil
import subprocess

HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[2];BASE=ROOT/'build-native-sjuni/adx-sequence'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();cc=shutil.which(a.cxx);out=a.output.resolve()
    if not cc or out.exists()or not out.is_relative_to(BASE):raise ValueError('Exact compiler and fresh scoped output required')
    frozen=json.loads((HERE/'manifest.json').read_bytes())
    def drift():return[n for n,d in frozen['files'].items()if sha(ROOT/n)!=d]
    if drift():raise ValueError('Frozen source drift '+str(drift()))
    helper=ROOT/'game/native/adxt_control_session/verify.py';spec=importlib.util.spec_from_file_location('owned_control_dependencies',helper);module=importlib.util.module_from_spec(spec);spec.loader.exec_module(module)
    deps=[ROOT/'game/native'/n for n in module.SOURCES if n!='adxt_phased_player/player.cpp'];objects=[out/(p.stem+'.o')for p in deps]
    if len(set(objects))!=len(objects):raise ValueError('Dependency object collision')
    out.mkdir(parents=True);env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','')
    control=ROOT/'game/native/adxt_control_session';phased=ROOT/'game/native/adxt_phased_player'
    flags=[cc,'-std=c++20','-O2','-pthread','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-misleading-indentation','-fno-fast-math','-ffp-contract=off','-frounding-math','-I'+str(ROOT),'-I'+str(control),'-I'+str(phased)]
    report=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),manifest_sha256=sha(HERE/'manifest.json'),verifier_sha256=sha(Path(__file__)),checks=[],negative_controls=[],game_run=False,device_opened=False,dynamic_lsc_implementation=False,original_whole_player_parity=False)
    def run(name,command,cwd=ROOT,negative=False):
        r=subprocess.run([str(x)for x in command],cwd=cwd,env=env,text=True,capture_output=True,timeout=90)
        (out/(name+'.txt')).write_text(r.stdout+r.stderr,encoding='utf-8',newline='\n');report['checks'].append(dict(name=name,command=[str(x)for x in command],exit=r.returncode))
        if (not negative and r.returncode)or (negative and not r.returncode):raise ValueError(name+': '+r.stdout+r.stderr)
        return r.stdout.strip()
    try:
        run('dependency-compile',flags+['-c',*deps],cwd=out);report['dependency_objects']={p.name:sha(p)for p in objects}
        binary=out/'sequence-units.exe';run('sequence-units-compile',flags+objects+[HERE/'sequence_tests.cpp','-o',binary]);report['sequence_units']=run('sequence-units',[binary])
        tests=(control/'control_session_tests.cpp').read_text(encoding='utf-8');anchor='auto pc=sequence_config(prepared.sequence);const auto reads='
        if tests.count(anchor)!=1:raise ValueError('Exact-size independent-view admission cut drift')
        expanded=tests.replace(anchor,'auto pc=sequence_config(prepared.sequence);const auto independent=reo::native::adx_sequence::Sequence::prepare(views);check(independent.status==reo::native::adx_sequence::Status::completed);check(t.session.open(pc,independent.sequence,{0,0,0,0}).status==c::Status::unsupported_profile);const auto reads=')
        derived=out/'independent-view-tests.cpp';derived.write_text(expanded,encoding='utf-8',newline='\n');report['derived_test_sha256']=sha(derived)
        def owner(name,core,negative=False):
            binary=out/(name+'.exe');run(name+'-compile',flags+objects+[core,control/'control_session.cpp',derived,'-o',binary]);result=run(name,[binary],negative=negative)
            report.setdefault('owner_executables',{})[name]=sha(binary);return result
        report['owner_units']=owner('owner',phased/'player.cpp')
        source=(phased/'player.cpp').read_text(encoding='utf-8')
        variants=[('missing-next-header-wait','if(static_cast<std::uint64_t>(before.source.cumulative_bytes)<required)return Status::completed;','if(static_cast<std::uint64_t>(before.source.cumulative_bytes)<required)(void)required;'),
                  ('missing-seamless-offset','o.offset=static_cast<std::uint32_t>(w.loop.seamless_samples);','o.offset=0;'),
                  ('clip-local-prefix-cap','config.sequence?config.sequence->total_samples():before.header.base.total_samples','before.header.base.total_samples'),
                  ('missing-sequence-identity','view!=c.sequence.get()','view==nullptr')]
        for name,old,new in variants:
            if source.count(old)!=1:raise ValueError('Negative selector drift '+name)
            core=out/(name+'.cpp');core.write_text(source.replace(old,new),encoding='utf-8',newline='\n');owner(name,core,negative=True);report['negative_controls'].append(dict(name=name,source_sha256=sha(core)))
        report['status']='passed immutable sequence preparation, actual seamless owner, pending-header/clock/identity/prefix negatives'
    except Exception as e:report.update(status='failed',failure=str(e));raise
    finally:
        report['input_drift']=drift()
        if report['input_drift']:report['status']='failed source drift'
        (out/'receipt.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=report['status'],sequence_units=report['sequence_units'],owner_units=report['owner_units'],receipt_sha256=sha(out/'receipt.json'))))

if __name__=='__main__':main()
