#!/usr/bin/env python3
"""New lifecycle-entry shared windows and partial-PCM ownership probes.

Original instructions and existing ISA engines remain unchanged. Freeze inputs
separately before replay. No native Window2 owner or expected results are imported.
"""
import argparse
import copy
import json
import os
from pathlib import Path
import adx_shared_window_oracle as old
from sjuni_oracle import OracleError,Elf

ROOT=old.ROOT
sha,serialized=old.sha,old.serialized
ENGINE_NAMES=old.ENGINE_NAMES+('adx_shared_window_oracle.py',)
FP_PARENTS={
    'gcc':ROOT/'build-native-sjuni/adx-header-math-oracle-v4/gcc',
    'llvm':ROOT/'build-native-sjuni/pinned-adx-qualification-v1/math/cohort',
}
FP_PARENT_SHA={
    'gcc':'7ffa76de4fe5aa56e4825c1a4a25ed591d5dfefe0331807848498974707a7158',
    'llvm':'65457f7eca4eea828a294283df3790dde0137c430f4a49d8cc0fc866759c58c5',
}


def inputs():
    result=copy.deepcopy(old.corpus_inputs())
    result.update(schema=2,stage='NEW Window2 original lifecycle-entry and PCM physical ownership evidence',
        provenance='Historical authored shared39 inputs reused with explicitly changed source-service entry; new PCM boundary inputs independently authored before expected replay. No native/expected consumer counts.')
    for case in result['cases']:
        for action in case['actions']:
            if action['kind']=='source':
                action['entry']=0x130b78
                # In a normal client a zero-sector/no-acceptance submit is not
                # an injected I/O error. The old raw-refill corpus's second
                # status3 can terminate the COMPLETE lifecycle service and
                # must remain in that preserved historical cohort.
                if action['statuses'][0]!=3:action['statuses'][1]=2
    base=copy.deepcopy(next(c for c in result['cases']if c['name']=='ready-44100-finite'))
    for channels,downmix,route in((1,0,'mono'),(2,0,'stereo'),(2,1,'downmix')):
        for total in(1,17,31,33,65):
            for free in(2,30,32,62,64,96):
                case=copy.deepcopy(base)
                header=old.header.header(total=total,channels=channels,rate=44100)
                payload=b''.join(old.window.block(i%64)for i in range(4*channels))
                data=bytes(header)+payload;data+=bytes((-len(data))%2048)
                case.update(name=f'pcm-tail-{route}-total-{total}-free-{free}',channels=channels,downmix=downmix,
                    file_hex=data.hex(),seed_bytes=len(data),initial_pcm_bytes=[16384-free]*channels,
                    actions=[dict(kind='header'),dict(kind='ready'),dict(kind='decode')],
                    domain='New partial-final/free-space physical ownership probe; not native admission or a presumed original bug')
                result['cases'].append(case)
    for first,second in((32,30),(30,32),(64,32),(32,64)):
        case=copy.deepcopy(next(c for c in result['cases']if c['name']=='pcm-tail-stereo-total-33-free-32'))
        case.update(name=f'pcm-asymmetric-free-{first}-{second}',initial_pcm_bytes=[16384-first,16384-second],
            domain='Asymmetric PCM original probe; outside proposed matching-grant Window2 admission')
        result['cases'].append(case)
    return result


def authority():
    bodies=old.owned_bodies()
    # Audit public generated companions against ELF words, not private V6 paths.
    audit=old.source_audit(bodies,ROOT/'recomp/config/output')
    sdk=ROOT/'build-native-sjuni/dependency-gs-sound-profile-reapply-v4/ps2xRuntime/include'
    return bodies,dict(elf_sha256=Elf(ROOT/'game_data/SLUS_207.65').sha256,source_audit=audit,
        actual_fp_emission=old.math.reference_statements(ROOT/'recomp/config/output')['instructions'],
        macro_sha256=sha((sdk/'ps2_runtime_macros.h').read_bytes()),
        convert_sha256=sha((sdk/'ps2_fpu_convert.h').read_bytes()),
        # C++ source line-ending translation only. Preserve both raw identities;
        # no arithmetic result or generic whitespace is normalized.
        convert_source_lf_sha256=sha((sdk/'ps2_fpu_convert.h').read_bytes().replace(b'\r\n',b'\n')),
        bodies={hex(a):dict(end=b,sha256=d)for a,(b,d)in bodies.items()})


def execute(case,worker,bodies):
    m=old.Machine(case,worker,bodies);m.prepare();initial=m.snapshot()
    backings=[m.raw(a-16,n+32).hex()for a,n in m.buffers];operations=[]
    for action in case['actions']:
        m.action=action;m.status_index=0
        if action['kind']in('header','decode'):result=m.run(0x12d638,[old.window.OUTER],full=False,limit=2500000)
        elif action['kind']=='ready':result=m.run(0x133fe0,[old.MAIN],full=False)
        elif action['kind']=='source':
            if action.get('entry')!=0x130b78:raise OracleError('Explicit complete lifecycle source entry required')
            result=m.run(action['entry'],[old.FILE_RECORD],full=False)
        elif action['kind']=='call':
            choices={'repeat':(0x133928,old.MAIN),'source_stop':(0x1306e0,old.FILE_RECORD)}
            if action['entry']not in choices:raise OracleError('Unknown source control')
            entry,argument=choices[action['entry']];result=m.run(entry,[argument],full=False)
        elif action['kind']=='write_job':
            before=[m.raw(a-16,n+32)for a,n in m.buffers];m.write_job(action['id'])
            result=dict(status='external_input',failure=None,original_instructions=0,events=[],provider_write=copy.deepcopy(m.jobs[action['id']]),after=m.small(),
                backing_effects=[dict(base=a-16,bytes=n+32,before_sha256=sha(prior),after_sha256=sha(m.raw(a-16,n+32)),changes=old.changed_bytes(prior,m.raw(a-16,n+32)))for(a,n),prior in zip(m.buffers,before,strict=True)])
        elif action['kind']=='consume_pcm':
            result=[]
            for ring in m.rings[1:]:
                result.extend((m.run(0x13fa88,[ring,1,action['bytes'],old.window.SCRATCH],full=False),m.run(0x13fbf8,[ring,0,old.window.SCRATCH],full=False)))
        else:raise OracleError('Unknown frozen action')
        operations.append(dict(input=action,results=result))
        if any(r['failure']for r in(result if isinstance(result,list)else[result])):break
    return dict(name=case['name'],setup=m.setup,initial=initial,initial_backings_hex=backings,
        operations=operations,final=m.snapshot(),original_instructions=m.total_steps,visited_pcs=sorted(m.all_visited))


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--output',type=Path,required=True)
    p.add_argument('--freeze',action='store_true');p.add_argument('--frozen',type=Path);p.add_argument('--compiler',choices=FP_PARENTS)
    p.add_argument('--case',action='append');a=p.parse_args();out=a.output.resolve()
    if not out.is_relative_to(ROOT/'build-native-sjuni/adx-window-v2-oracle')or out.exists():raise OracleError('Fresh scoped artifact path required')
    bodies,checked=authority()
    if a.freeze:
        out.mkdir(parents=True);data=serialized(inputs());(out/'inputs.json').write_bytes(data)
        manifest=dict(schema=1,authority=checked,inputs_sha256=sha(data),oracle_sha256=sha(Path(__file__).read_bytes()),
            engines={n:sha(Path(__file__).with_name(n).read_bytes())for n in ENGINE_NAMES})
        (out/'input-manifest.json').write_bytes(serialized(manifest));print('Inputs frozen; no original instructions executed');return
    if not a.frozen or not a.compiler:raise OracleError('Frozen inputs and exact qualified compiler worker required')
    frozen=a.frozen.resolve();manifest=json.loads((frozen/'input-manifest.json').read_bytes());data=(frozen/'inputs.json').read_bytes()
    if manifest['authority']!=checked or sha(data)!=manifest['inputs_sha256']or sha(Path(__file__).read_bytes())!=manifest['oracle_sha256']:raise OracleError('Frozen source/input/authority drift')
    for n,d in manifest['engines'].items():
        if sha(Path(__file__).with_name(n).read_bytes())!=d:raise OracleError('Imported engine changed')
    folder=FP_PARENTS[a.compiler];parent=json.loads((folder/'original-fixture.json').read_bytes())
    if sha((folder/'original-fixture.json').read_bytes())!=FP_PARENT_SHA[a.compiler]:raise OracleError('Unqualified FP parent')
    if (parent['fp_emission']['instructions']!=checked['actual_fp_emission']or
        parent['convert_sha256']!=checked['convert_source_lf_sha256']or
        parent['isa_reference']['source_sha256']['third_party/PS2Recomp/ps2xRuntime/include/ps2_runtime_macros.h']!=checked['macro_sha256']):
        raise OracleError('Current source/runtime FP does not match the qualified worker')
    binary=folder/'fp_worker.exe'
    if sha(binary.read_bytes())!=parent['compatibility']['worker_binary_sha256']:raise OracleError('FP worker changed')
    # Runtime DLLs are selected explicitly; worker executable identity and its
    # original qualification remain recorded separately from this PATH choice.
    compiler=Path(parent['compatibility']['compiler'])
    if sha(compiler.read_bytes())!=parent['compatibility']['compiler_sha256']:raise OracleError('Exact compiler identity changed')
    binpath=compiler.parent
    os.environ['PATH']=str(binpath)+os.pathsep+os.environ.get('PATH','')
    cases=json.loads(data)['cases'];names={c['name']for c in cases}
    if a.case and set(a.case)-names:raise OracleError('Unknown selected authored input')
    out.mkdir(parents=True);rows=[]
    with old.math.FpuWorker(binary)as worker:
        for case in cases:
            if a.case and case['name']not in a.case:continue
            row=execute(case,worker,bodies);(out/(case['name']+'.json')).write_bytes(old.compact_serialized(row));rows.append(row)
            print(case['name'],row['original_instructions'],flush=True)
    failures=[dict(name=row['name'],failure=r['failure'])for row in rows for op in row['operations']for r in(op['results']if isinstance(op['results'],list)else[op['results']])if r['failure']]
    receipt=dict(schema=1,inputs_sha256=sha(data),input_manifest_sha256=sha((frozen/'input-manifest.json').read_bytes()),compiler=a.compiler,fp_parent_sha256=FP_PARENT_SHA[a.compiler],fp_worker_sha256=sha(binary.read_bytes()),selected_cases=a.case,
        cases=[dict(name=r['name'],sha256=sha((out/(r['name']+'.json')).read_bytes()))for r in rows],
        summary=dict(cases=len(rows),original_instructions=sum(r['original_instructions']for r in rows),partials=failures),
        game_run=False,native_window2_executed=False)
    (out/'manifest.json').write_bytes(serialized(receipt));print(json.dumps(receipt['summary'],indent=2))


if __name__=='__main__':main()
