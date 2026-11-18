#!/usr/bin/env python3
"""Inputs-only Source2 transport versus newly frozen independent original replay."""
import argparse,hashlib,importlib.util,json,os,shutil,subprocess
from pathlib import Path
HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[2]
ORACLE=ROOT/'build-native-sjuni/adxt-shared-source-oracle/v3'
INPUT_SHA='eb358b57da388fcfe54bc0e233c80d64c5cec50223e21dbf5153c685da6da9cd'
MANIFEST_SHA='8598ffc6894c960be7cc93000821b6b1b252f2007fd6e589de8f4bcb082e8b23'
EXPECTED_SHA='f6ab00eb1f0f88ad35fb3215e826d2f59471e70e4f240289d9f1c05f3a3c6446'
CORE_SHA='a1eb49209edf71ee13911f556a67be18ae271f658949e2335f33c64fb819f631'
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def write(p,s):p.write_text(s,encoding='utf-8',newline='\n')
def load(p):return json.loads(p.read_bytes())
def commands(case):
    if 'expected'in json.dumps(case):raise ValueError('Expected output entered transport')
    config=[case[k]for k in ('capacity','start_sector','byte_length','threshold','max_request_bytes','max_sectors','target','finite_limit','retry_limit','position','occupied')]
    config+=[int(case['callback']),case.get('initial_progress',0),int(case.get('file_action','none')=='file_loop'),int(case.get('loop_enabled',False)),case.get('sample_limit',-1),*case.get('header_geometry',[0,0,0,0])]
    lines=[' '.join(map(str,config))+' '+(case['file_hex']or'-')]
    for i,a in enumerate(case['actions']):
        k=a['kind'];tail=[]
        if k in ('source','lifecycle','refill'):
            if k=='source'and a.get('entry')!=0x130b78:raise ValueError('Source2 public service requires explicit original lifecycle wrapper')
            k='source';statuses=a['statuses'];tail=[statuses[0],-999 if a['accept']=='requested'else a['accept'],int(len(statuses)>1 and statuses[1]==3),int(a['inline_write'])]
        elif k=='borrow':tail=[a['shape'],a['first'],a['second']]
        elif k=='finish':tail=[a['plan'],a['prefix']]
        elif k=='configure':tail=[*a['header_geometry'],a['sample_limit'],a['target'],int(a['file_action']=='file_loop')]
        elif k=='write_job':tail=[a['id']]
        elif k in ('loop_enable','pause'):tail=[a['value']]
        elif k in ('stop','close'):pass
        else:
            # Non8192 original rows terminate at constructor refusal. Do not
            # invent native equivalents for their unimplemented reset commands.
            if case['capacity']!=8192:break
            raise ValueError('Unsupported admitted input '+k)
        lines.append(' '.join(map(str,[i,k,*tail])))
    return '\n'.join(lines)+'\n'
def difference(a,b,path='root'):
    if type(a)!=type(b):return path+': type '+type(a).__name__+'/'+type(b).__name__
    if isinstance(a,dict):
        if a.keys()!=b.keys():return path+': keys '+str(list(a))+'/'+str(list(b))
        for k in a:
            d=difference(a[k],b[k],path+'.'+k)
            if d:return d
    elif isinstance(a,list):
        if len(a)!=len(b):return path+': length '+str(len(a))+'/'+str(len(b))
        for i,(x,y)in enumerate(zip(a,b)):
            d=difference(x,y,path+f'[{i}]')
            if d:return d
    elif a!=b:return path+': '+str(a)[:100]+'/'+str(b)[:100]
    return None
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();cc=shutil.which(a.cxx)
    if not cc or out.exists()or not out.is_relative_to(ROOT/'build-native-sjuni/adxt-shared-source-parity'):raise ValueError('Compiler/fresh private parity output required')
    for p,d in ((ORACLE/'inputs.json',INPUT_SHA),(ORACLE/'input-manifest.json',MANIFEST_SHA),(ORACLE/'expected.json',EXPECTED_SHA),(HERE/'frozen_identity.json',CORE_SHA)):
        if sha(p)!=d:raise ValueError('Frozen source/evidence drift '+str(p))
    frozen=load(HERE/'frozen_identity.json')
    for n,d in frozen['files'].items():
        if sha(ROOT/n)!=d:raise ValueError('Frozen native/dependency drift '+n)
    expected=load(ORACLE/'expected.json');inputs=load(ORACLE/'inputs.json')
    for n,d in expected['engine_sha256'].items():
        if sha(ROOT/'tools/native_reconstruction'/n)!=d:raise ValueError('Original engine drift '+n)
    if sha(ROOT/'tools/native_reconstruction/adxt_shared_source_oracle.py')!=expected['oracle_sha256']:raise ValueError('Original support source drift')
    helper=ROOT/'game/native/adxt_refill/compare_original.py'
    if sha(helper)!=expected['original_view_helper_sha256']:raise ValueError('Original view helper drift')
    out.mkdir(parents=True);env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','')
    files={str(p.relative_to(ROOT)):sha(p)for p in (HERE/'fixture_runner.cpp',HERE/'compare_original.py')}
    receipt=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),core_freeze_sha256=CORE_SHA,authored=files,
        input_manifest_sha256=MANIFEST_SHA,inputs_sha256=INPUT_SHA,expected_sha256=EXPECTED_SHA,game_run=False,device_opened=False,checks=[],cases=[],records=0,published_and_held_bytes=0,
        historical_shared39_classification='Whole window transactions deferred to Window2; no expected-derived consumer stimuli used')
    def run(name,command,stdin=None):
        r=subprocess.run([str(x)for x in command],env=env,cwd=ROOT,input=stdin,text=True,capture_output=True,timeout=90)
        write(out/(name+'.stdout.txt'),r.stdout);write(out/(name+'.stderr.txt'),r.stderr)
        receipt['checks'].append(dict(name=name,command=[str(x)for x in command],exit_code=r.returncode))
        if r.returncode:raise RuntimeError(name+': '+r.stderr)
        return r.stdout
    try:
        deps=['game/native/sjrb/sjrb.cpp','game/native/adxt_refill/adxt_refill.cpp','game/native/resource_io/async_read_owner.cpp','game/native/tasks/serial_worker.cpp','game/native/resources/resource_session.cpp']
        sources=[ROOT/n for n in deps]+[HERE/'shared_source.cpp',HERE/'fixture_runner.cpp'];exe=out/'source_runner.exe'
        run('compile',[cc,'-std=c++20','-O2','-pthread','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-misleading-indentation',*sources,'-o',exe]);receipt['executable_sha256']=sha(exe)
        actual_by_name={}
        for case,want_case in zip(inputs['cases'],expected['cases'],strict=True):
            if case['name']!=want_case['name']:raise ValueError('Original case order drift')
            name=case['name'];wire=out/(name+'.input.txt');write(wire,commands(case));raw=run(name,[exe,wire]);rows=[json.loads(line)for line in raw.splitlines()]
            if len(rows)!=len(want_case['rows']):raise ValueError('Row count '+name)
            normalized=[]
            for i,(row,want)in enumerate(zip(rows,want_case['rows'],strict=True)):
                status=row.pop('status');ownership=row.pop('ownership')
                if status not in (0,8):raise ValueError('Native refusal '+name+' '+str(status))
                if min(ownership)<0 or sum(ownership)+row['state']['ring'][2]+row['state']['ring'][3]!=8192:raise ValueError('Native ledger conservation '+name)
                # JSON emits native C++ bools as0/1 for fixed word projections;
                # these are original numeric words, not boolean schema fields.
                mismatch=difference(row,want)
                if mismatch:raise ValueError(name+' row'+str(i)+' '+mismatch)
                receipt['records']+=1;receipt['published_and_held_bytes']+=sum(view['bytes']for view in row['views']);normalized.append(row)
            actual_by_name[name]=normalized;receipt['cases'].append(dict(name=name,classification='new_authored_original_source_projection',records=len(rows),wire_sha256=sha(wire)))
        # Exact earlier8192 authored case is independently compared with its
        # historical fixture. Other28 earlier geometries are explicit new
        # Source2 profile refusals, not counted as original behavior equivalence.
        spec=importlib.util.spec_from_file_location('prior_projection',helper);prior=importlib.util.module_from_spec(spec);spec.loader.exec_module(prior)
        old_fixture=ROOT/'build-native-sjuni/adxt-refill-oracle-v2/original-fixture.json'
        if sha(old_fixture)!=prior.FIXTURE_SHA:raise ValueError('Prior original fixture drift')
        old=load(old_fixture);old_inputs=ROOT/old['inputs_file']
        if sha(old_inputs)!=prior.INPUT_SHA:raise ValueError('Prior inputs drift')
        old_cases=load(old_inputs)['cases'];classifications=[];proofs=[]
        for case,observation in zip(old_cases,old['cases'],strict=True):
            if case['capacity']==8192:
                wanted=prior.projection(case,observation,proofs);got=actual_by_name['prior-large-capacity']
                translated=[dict(index=x['index'],sub=0,state={k:v for k,v in x['state'].items()if k!='loop'},
                    callbacks=[{k:v for k,v in t['before'].items()if k!='loop'}for t in x['targets']],view=x['views'][0])for x in got]
                if difference(translated,wanted):raise ValueError('Prior8192 direct refill mismatch '+str(difference(translated,wanted)))
                classifications.append(dict(name=case['name'],classification='historical_original_refill_projection',records=len(got)))
            else:
                wire=out/('prior-'+case['name']+'.input.txt');write(wire,commands(case));raw=run('prior-'+case['name'],[exe,wire]);rows=[json.loads(line)for line in raw.splitlines()]
                if rows!=[{'constructor_refused':True}]:raise ValueError('Missing Source2 geometry refusal')
                classifications.append(dict(name=case['name'],classification='new_before_effects_unsupported_geometry',original_parity_claim=False))
        receipt['prior_refill_classifications']=classifications
        receipt['prior_fixture_sha256']=sha(old_fixture);receipt['prior_inputs_sha256']=sha(old_inputs)
        receipt['prior_view_proofs']=proofs
        receipt['status']='passed'
    except Exception as e:receipt.update(status='failed',failure=str(e));raise
    finally:
        receipt['core_postcheck']=[n for n,d in frozen['files'].items()if sha(ROOT/n)!=d]
        receipt['authored_postcheck']=[n for n,d in files.items()if sha(ROOT/n)!=d]
        if receipt['core_postcheck']or receipt['authored_postcheck']:receipt.update(status='failed',failure='Source changed during qualification')
        write(out/'receipt.json',json.dumps(receipt,indent=2)+'\n')
    print(json.dumps(dict(status=receipt['status'],records=receipt['records'],bytes=receipt['published_and_held_bytes'],receipt_sha256=sha(out/'receipt.json'))))
if __name__=='__main__':main()
