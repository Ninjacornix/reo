#!/usr/bin/env python3
"""Replay complete original ready configuration with variable service divisors.

The earlier native fixed-60 profile already exists. Freeze this dynamic-control
input domain before authoring its native extension. Reuse qualified original
header/FP/ISA engines, never the native request calculation.
"""
import argparse,copy,json,os
from pathlib import Path
import adx_window_v2_oracle as authority
import adx_shared_window_oracle as original
from sjuni_oracle import OracleError
ROOT=original.ROOT;sha=original.sha;encoded=original.serialized
def frozen_inputs():
    templates={c['name']:c for c in original.corpus_inputs()['cases']if c['name'].startswith('ready-') and c['name'].endswith(('finite','loop'))}
    divisors=(1,2,5,10,24,25,30,50,59,60,61,100,1000,48000,48001,0x7fffffff)
    cases=[dict(name=name+'-divisor-'+str(divisor),template=name,divisor=divisor)for name in sorted(templates)for divisor in divisors]
    return dict(schema=1,templates=templates,cases=cases,scope='Complete original header and ready visits; prepared synthetic stream, scripted void RNA observation ports; not live scheduling or device output')
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--output',type=Path,required=True);p.add_argument('--freeze',action='store_true');p.add_argument('--frozen',type=Path);p.add_argument('--compiler',choices=authority.FP_PARENTS);a=p.parse_args();out=a.output.resolve()
    if out.exists() or not out.is_relative_to(ROOT/'build-native-sjuni/adxt-ready-quantum'):raise OracleError('Fresh owned output required')
    bodies,proof=authority.authority();engines={n:sha(Path(__file__).with_name(n).read_bytes())for n in (*authority.ENGINE_NAMES,'adx_window_v2_oracle.py')}
    if a.freeze:
        out.mkdir(parents=True);data=encoded(frozen_inputs());(out/'inputs.json').write_bytes(data)
        (out/'input-manifest.json').write_bytes(encoded(dict(schema=1,authority=proof,inputs_sha256=sha(data),oracle_sha256=sha(Path(__file__).read_bytes()),engines=engines,dynamic_native_extension_authored=False,prior_native_fixed_60_profile_exists=True)))
        print('Dynamic divisor inputs frozen; no original execution');return
    if not a.frozen or not a.compiler:raise OracleError('Frozen input and qualified original FP worker required')
    frozen=a.frozen.resolve();plan=json.loads((frozen/'input-manifest.json').read_bytes());data=(frozen/'inputs.json').read_bytes()
    if plan['authority']!=proof or plan['inputs_sha256']!=sha(data) or plan['oracle_sha256']!=sha(Path(__file__).read_bytes()) or plan['engines']!=engines:raise OracleError('Frozen input/engine drift')
    folder=authority.FP_PARENTS[a.compiler];parent=json.loads((folder/'original-fixture.json').read_bytes());binary=folder/'fp_worker.exe'
    if sha((folder/'original-fixture.json').read_bytes())!=authority.FP_PARENT_SHA[a.compiler] or sha(binary.read_bytes())!=parent['compatibility']['worker_binary_sha256']:raise OracleError('Qualified FP parent/worker drift')
    if parent['fp_emission']['instructions']!=proof['actual_fp_emission'] or parent['convert_sha256']!=proof['convert_source_lf_sha256'] or parent['isa_reference']['source_sha256']['third_party/PS2Recomp/ps2xRuntime/include/ps2_runtime_macros.h']!=proof['macro_sha256']:raise OracleError('Current original FP semantics differ')
    compiler=Path(parent['compatibility']['compiler'])
    if sha(compiler.read_bytes())!=parent['compatibility']['compiler_sha256']:raise OracleError('FP compiler drift')
    os.environ['PATH']=str(compiler.parent)+os.pathsep+os.environ.get('PATH','');inputs=json.loads(data);out.mkdir(parents=True);rows=[]
    with original.math.FpuWorker(binary)as worker:
        for case in inputs['cases']:
            template=copy.deepcopy(inputs['templates'][case['template']]);machine=original.Machine(template,worker,bodies);machine.prepare()
            # A declared game-owned field, not a supplied result or answer hook.
            machine.mem.store(original.MAIN+0x38,4,case['divisor']);operations=[]
            for kind,entry,args in [('header',0x12d638,[original.window.OUTER]),('ready',0x133fe0,[original.MAIN])]:
                machine.action={'kind':kind};value=machine.run(entry,args,full=False,limit=2500000)
                if value['failure']:raise OracleError(str(value['failure']))
                operations.append(dict(kind=kind,instructions=value['original_instructions'],effects_sha256=sha(encoded(value))))
            row=dict(**case,request_u32=machine.mem.load(original.MAIN+0x48,4),decoder_request_u32=machine.mem.load(original.window.OUTER+0x38,4),state=machine.mem.load(original.MAIN+1,1),operations=operations,original_instructions=machine.total_steps)
            rows.append(row)
    result=encoded(rows);(out/'expected.json').write_bytes(result)
    record=dict(schema=1,status='complete original ready configuration replay passed',cases=len(rows),original_instructions=sum(r['original_instructions']for r in rows),input_manifest_sha256=sha((frozen/'input-manifest.json').read_bytes()),expected_sha256=sha(result),compiler=a.compiler,fp_parent_sha256=authority.FP_PARENT_SHA[a.compiler],fp_worker_sha256=sha(binary.read_bytes()),dynamic_native_extension_authored=False,game_run=False,device_opened=False)
    (out/'receipt.json').write_bytes(encoded(record));print(json.dumps(record))
if __name__=='__main__':main()
