"""Build isolated native gameplay ownership and compare complete owned bodies."""
import argparse,hashlib,json,os,shutil,subprocess
from pathlib import Path
from gameplay_tasks_oracle import authority,execute,plans,serialize
from audit_retail_effect_descriptors import compare_source

ROOT=Path(__file__).resolve().parents[2];HERE=ROOT/'game/native/gameplay_tasks'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True)
    args=p.parse_args();out=args.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni/native-gameplay/tasks')
    code,profiles=authority();corpus=plans();out.mkdir(parents=True)
    (out/'authored-inputs.json').write_text(json.dumps(corpus,indent=2)+'\n',encoding='utf8')
    expected=[];instructions=0;entries=set()
    for case in corpus:
        result,steps,visited,called=execute(case,code);expected.append(dict(name=case['name'],transcript=result,original_instructions=steps,visited_words=visited,original_entries=[hex(pc)for pc in called]));instructions+=steps;entries.update(called)
    assert entries=={int(profile['start'],16)for profile in profiles},'Loaded/executed original-body mismatch'
    (out/'original-results.json').write_text(json.dumps(expected,indent=2)+'\n',encoding='utf8')
    bodies=out/'original-body-audit.json';bodies.write_text(json.dumps(profiles,indent=2)+'\n',encoding='utf8')
    # Additional caller bodies are statically word-verified, not substituted by
    # the native library or claimed as executed scenario integration.
    callers=[]
    for image,start in [('o2',0x5fea30),('o2',0x5fed00),('o2',0x5ff1b0),('o2',0x68c8d0),('o0',0x371ba0),('o2',0x5b7470),('o2',0x6900a0)]:
        blob=ROOT/f'build-function-index/owned-overlays/{image}.bin';data=blob.read_bytes();base=int.from_bytes(data[8:12],'little')
        source=next((ROOT/f'recomp/config/output_ovl/{image}').glob(f'{image}_{start:08X}_0x{start:x}.cpp'))
        import re
        end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',source.read_text())[1],16)
        callers.append(compare_source('actual caller/integration cut',source.relative_to(ROOT).as_posix(),start,end,lambda a,n,d=data,b=base:d[a-b:a-b+n]))
    (out/'caller-body-audit.json').write_text(json.dumps(callers,indent=2)+'\n',encoding='utf8')
    paths=list(HERE.glob('*'))+[Path(__file__),ROOT/'tools/native_reconstruction/gameplay_tasks_oracle.py']
    paths += [ROOT/'tools/native_reconstruction'/name for name in ('sjuni_oracle.py','movie_position_oracle.py','ee_copy_store_oracle.py','ee_mac_oracle.py','audit_retail_effect_descriptors.py')]
    sources={p.relative_to(ROOT).as_posix():sha(p)for p in paths if p.is_file()}
    sources.update({p['path']:p['sha256']for p in profiles+callers})
    snapshot=out/'source-snapshot'
    for name,digest in sources.items():
        target=snapshot/name;target.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(ROOT/name,target);assert sha(target)==digest
    fixture=snapshot/'game/native/gameplay_tasks/fixture.cpp';core=snapshot/'game/native/gameplay_tasks/tasks.cpp'
    text='\n'.join(map(serialize,corpus))+'\n';(out/'plan.txt').write_text(text,encoding='utf8')
    env=dict(os.environ);env['PATH']=str(args.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
    record=dict(schema=1,status='failed',game_run=False,process_access=False,device_opened=False,production_integrated=False,
        native_has_generated_abi_dependency=False,compiler_sha256=sha(args.compiler),source_sha256=sources,
        owned_overlays_sha256={image:sha(ROOT/f'build-function-index/owned-overlays/{image}.bin')for image in ('o0','o2')},
        original_bodies_executed=len(entries),original_body_entries=[hex(pc)for pc in sorted(entries)],caller_bodies_statically_verified=len(callers),
        original_instructions=instructions,cases=len(corpus),checks=[],detected_counterfactuals=[],
        declared_ports=['107C68 zero-fill fixture memory','native-authored callback effects and task labels','5703E0/5705F0 flag expiry consumers','1B02D0 exact session-mode predicate value'],
        limitations=['No original actor/scenario/script/flag consumer or production adapter is migrated by these tests.',
            'Original-word tests use isolated synthetic memory and declared callback/consumer effects, not a game process.',
            'Physical slot/pointer aliasing, malformed records and unbounded callback-generated work are not native compatibility requirements.',
            'Play-clock comparison covers normalized valid times and the original5FEE80 leaf; counter/gate caller bodies are statically verified, not executed here.',
            'Event-clear comparisons have no legacy render registration; migrating those registrations/consumers remains a separate integration dependency.'])
    def run(label,command,stdin=None):
        result=subprocess.run(list(map(str,command)),input=stdin,capture_output=True,text=True,env=env,timeout=90)
        (out/(label+'.txt')).write_text(result.stdout+result.stderr,encoding='utf8');record['checks'].append(dict(label=label,exit=result.returncode))
        if result.returncode:raise ValueError(label+' failed; see retained log')
        return result.stdout
    flags=[args.compiler,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-misleading-indentation','-I'+str(core.parent)]
    def compare(label,source,event_source=None):
        exe=out/(label+'.exe');run(label+'-compile',flags+[source,event_source or core.parent/'events.cpp',fixture,'-o',exe]);actual=run(label,[exe],text).splitlines()
        if len(actual)!=len(expected):raise ValueError('Incomplete native transcript')
        differences=[dict(name=row['name'],expected=row['transcript'],actual=got)for row,got in zip(expected,actual)if row['transcript']!=got]
        (out/(label+'-differences.json')).write_text(json.dumps(differences,indent=2)+'\n',encoding='utf8');return differences
    try:
        units=out/'units.exe';run('units-compile',flags+[core,core.parent/'events.cpp',snapshot/'game/native/gameplay_tasks/tests.cpp','-o',units]);record['units']=run('units',[units]).strip()
        differences=compare('native',core)
        if differences:raise ValueError('Native/original mismatch '+str(differences[:3]))
        body=core.read_text();mutants=[
            ('primary-active-gated','if (pass == Pass::update) {','if (pass == Pass::update && cursor->policy.active_flags) {'),
            ('timer-negative-decrement','if (timer.remaining <= 0) continue;','if (timer.remaining == 0) continue;'),
            ('timer-one-early','if (timer.remaining == 0) sink.expired','if (timer.remaining == 1) sink.expired'),
            ('clock-one-unit','static_cast<std::uint32_t>(step)','std::uint32_t{1}'),
            ('secondary-mask-ignored','(cursor->policy.active_flags & cursor->policy.presentation_mask)','cursor->policy.active_flags')]
        for label,anchor,replacement in mutants:
            assert body.count(anchor)==1,label
            target=out/(label+'.cpp');target.write_text(body.replace(anchor,replacement),encoding='utf8');difference=compare(label,target)
            if not difference:raise ValueError('Undetected counterfactual '+label)
            record['detected_counterfactuals'].append(dict(name=label,differences=len(difference),source_sha256=sha(target)))
        changed=body.replace('    for (auto cursor = tail_; cursor; cursor = cursor->previous) {',
            '    std::shared_ptr<Node> predecessor;\n    for (auto cursor = tail_; cursor; cursor = predecessor) {\n        predecessor = cursor->previous;')
        assert changed!=body;target=out/'early-predecessor.cpp';target.write_text(changed,encoding='utf8');difference=compare('early-predecessor',target)
        if not difference:raise ValueError('Undetected early predecessor snapshot')
        record['detected_counterfactuals'].append(dict(name='early-predecessor',differences=len(difference),source_sha256=sha(target)))
        event_body=(core.parent/'events.cpp').read_text()
        for label,anchor,replacement in [
            ('event-shared-runs-all','mode == EventMode::owner_banks ? banks : std::size_t{1}','banks'),
            ('event-owner-not-restored','if (mode == EventMode::owner_banks) owner.actor = 0;','(void)owner;')]:
            assert event_body.count(anchor)==1
            target=out/(label+'.cpp');target.write_text(event_body.replace(anchor,replacement),encoding='utf8');difference=compare(label,core,target)
            if not difference:raise ValueError('Undetected event counterfactual '+label)
            record['detected_counterfactuals'].append(dict(name=label,differences=len(difference),source_sha256=sha(target)))
        for name,digest in sources.items():assert sha(ROOT/name)==digest,'Source drift '+name
        record['status']='native gameplay ownership/timer/clock units and complete original-word comparisons passed'
    except Exception as error:record['failure']=str(error);raise
    finally:
        record['evidence_sha256']={p.name:sha(p)for p in out.iterdir()if p.is_file()}
        (out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf8')
    print(json.dumps(dict(status=record['status'],cases=len(corpus),original_instructions=instructions,receipt_sha256=sha(out/'receipt.json'))))

if __name__=='__main__':main()
