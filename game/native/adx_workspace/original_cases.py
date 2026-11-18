#!/usr/bin/env python3
"""Freeze codec inputs/projections, then observe unchanged original EE words."""
import argparse
import copy
import hashlib
import json
from pathlib import Path
import struct
import sys

ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
import adx_decode_oracle as mono
import adx_stereo_oracle as stereo
import adx_large_block_oracle as large
from sjuni_oracle import OracleError,sext32,signed

BASE=Path(__file__).resolve().parent
sha=lambda data:hashlib.sha256(data).hexdigest()
encode=lambda value:(json.dumps(value,sort_keys=True,separators=(',',':'))+'\n').encode()
SOURCES={
 'mono':('build-native-sjuni/adx-decode-fixtures.json','11785ce1d02f0355e54c38df58216911ca33d1ca8fbeaa6a2528c539a27eb6bb'),
 'stereo':('build-native-sjuni/adx-stereo-fixtures.json','a02fc85b996feb650751407a5a2e5fc9cd8104fd1c5d9fe4278864cf4027f6b0'),
 'large':('build-native-sjuni/adx-large-block-fixtures.json','b49e2df608718db12b325903c46b2c1c132fcdf67c4472d0b10d06a90a84d514'),
 'window':('build-native-sjuni/adx-window-oracle-v5/original-fixture.json','62dfa91bf99698bc10c84356e8320912967cefadbd6a83feb95f453122fafeff'),
 'shared':('build-native-sjuni/adx-shared-window-oracle-v14/manifest.json','e41b48940b06b95d5b5641160225e10b0902dd5808d9eaf1dca5b1aa0b127972')}


def load_sources():
    values={}
    for name,(relative,digest) in SOURCES.items():
        raw=(ROOT/relative).read_bytes()
        if sha(raw)!=digest:raise OracleError('Frozen original source changed: '+name)
        values[name]=json.loads(raw)
    return values


def scalar_input(name,route,case):
    history=case['history_i16']
    capacity=case['output_capacity_samples'] if route=='mono' else case['output_capacity_samples_per_plane']
    return dict(name=name,route=route,requested=case['requested_i32'],encoded_hex=case['encoded_hex'],
        history=history if len(history)==4 else history+[0,0],key=case['key_u16'],
        coefficients=case['coefficients_i16'],multiplier=case['multiplier_i16'],addend=case['addend_i16'],
        output_samples=min(capacity,8289),original_output_samples=capacity)


def entry_input(name,entry,encoded_backing,input_base,origin):
    state=entry['state'];pred=bytes.fromhex(state['predictor_hex']);outer=bytes.fromhex(state['outer_hex'])
    pointer=entry['arguments_u64'][0]&0xFFFFFFFF;requested=signed(entry['arguments_u64'][1],32)
    start,available=struct.unpack_from('<II',outer,0x14)
    if not start<=pointer<=start+available:raise OracleError('Kernel input not inside actual outer grant')
    offset=pointer-(input_base-16);length=start+available-pointer
    if not 0<=offset<=offset+length<=len(encoded_backing):raise OracleError('Projected physical input outside original backing')
    route={0x1276D8:'mono',0x127C80:'normal',0x1278B8:'downmix'}[entry['pc']]
    groups=max(requested,0) if route=='mono' else max(requested,0)//2
    capacity=groups*32+2
    if capacity>8288:raise OracleError('Unexpected window scalar physical capacity')
    return dict(name=name,route=route,requested=requested,encoded_hex=encoded_backing[offset:offset+length].hex(),
        history=list(struct.unpack_from('<hhhh',pred,0x28)),key=struct.unpack_from('<H',pred,0x34)[0],
        coefficients=list(struct.unpack_from('<hh',pred,0x30)),multiplier=struct.unpack_from('<h',pred,0x36)[0],
        addend=struct.unpack_from('<h',pred,0x38)[0],output_samples=capacity,original_output_samples=capacity,
        projection=origin)


def inputs(sources):
    cases=[]
    for family in ('mono','stereo','large'):
        for index,row in enumerate(sources[family]['cases']):
            route='mono' if family=='mono' else row.get('mode',row['input'].get('mode','normal'))
            if route=='selector':route='downmix' if row['input']['selector_flag_u32'] else 'normal'
            case=scalar_input(f'{family}-{index}-{row["name"]}',route,row['input'])
            case['reuse']=dict(family=family,index=index);cases.append(case)
    for row in sources['window']['cases']:
        for opindex,op in enumerate(row['operations']):
            for result in op['expected'] if isinstance(op['expected'],list) else [op['expected']]:
                for index,entry in enumerate(result['traces']):
                    if entry['pc'] in (0x1276D8,0x127C80,0x1278B8):
                        cases.append(entry_input(f'window-{row["name"]}-{opindex}-{index}',entry,
                            bytes.fromhex(result['before']['encoded_backing_guard_hex']),0x400010,
                            dict(family='window',case=row['name'],operation=opindex,entry_index=index)))
    shared_dir=(ROOT/SOURCES['shared'][0]).parent
    for descriptor in sources['shared']['cases']:
        raw=(shared_dir/descriptor['file']).read_bytes()
        if sha(raw)!=descriptor['sha256']:raise OracleError('Shared case receipt changed')
        row=json.loads(raw);backing=bytearray.fromhex(row['initial_backings_hex'][0])
        for opindex,op in enumerate(row['operations']):
            for result in op['results'] if isinstance(op['results'],list) else [op['results']]:
                for index,entry in enumerate(result['events']):
                    if entry.get('kind')=='original_entry' and entry['pc'] in (0x1276D8,0x127C80,0x1278B8):
                        cases.append(entry_input(f'shared-{row["name"]}-{opindex}-{index}',entry,backing,0x400010,
                            dict(family='shared',case=row['name'],operation=opindex,event_index=index)))
                for change in result['backing_effects'][0]['changes']:
                    offset=change['offset'];before=bytes.fromhex(change['before_hex']);after=bytes.fromhex(change['after_hex'])
                    if backing[offset:offset+len(before)]!=before:raise OracleError('Projection delta preimage mismatch')
                    backing[offset:offset+len(after)]=after
    def add(name,route,encoded,requested,capacity,**changes):
        case=dict(name='new-'+name,route=route,requested=requested,encoded_hex=encoded.hex(),
            history=[32767,-32768,-12345,23456],key=65535,coefficients=[32767,-32768],
            multiplier=-32768,addend=32767,output_samples=capacity,original_output_samples=capacity)
        case.update(changes);cases.append(case)
    for route,count,capacity in [('mono',259,8288),('normal',456,7299),('downmix',457,7299),
                                  ('normal',454,7267)]:
        add(f'physical-{route}-{count}',route,large.encoded_blocks(count),count,capacity)
    for route in ('mono','normal','downmix'):
        for samples in (1152,2240,2432):
            blocks=samples//32*(1 if route=='mono' else 2)
            add(f'full-request-{route}-{samples}',route,large.encoded_blocks(blocks),blocks,samples+2)
        add(f'huge-first-marker-{route}',route,b'\x80\x00',0x7FFFFFFF,0)
    add('right-marker-twenty-bytes','normal',large.encoded_blocks(1)+b'\x80\x00',0x7FFFFFFF,0)
    add('right-marker-huge-downmix','downmix',large.encoded_blocks(1)+b'\x80\x00',0x7FFFFFFF,0)
    add('mono-marker-after210-request512','mono',large.encoded_blocks(210)+b'\x80\x00',512,6722)
    add('stereo-right-marker-after150-request511','normal',large.encoded_blocks(301)+b'\x80\x00',511,4802)
    return dict(schema=1,provenance='Frozen native core preceded this projection/comparator. Authored input and actual original kernel-entry projections; no native output used.',
                sources=SOURCES,cases=cases)


def original_machine(case):
    route=case['route'];module=mono if route=='mono' else stereo
    # Reuse unchanged original EE machines; remap synthetic output allocation
    # only before execution, without changing engine/count globals.
    history=case['history'][:2] if route=='mono' else case['history']
    machine=large.machine_for(bytes.fromhex(case['encoded_hex']),1,mode=route,output_samples=0,
        history=history,coefficients=case['coefficients'],key=case['key'],multiplier=case['multiplier'],addend=case['addend'])
    old=machine.mem;memory=module.ObservedMemory();capacity=case['output_samples']
    planes=[('pcm',mono.OUTPUT)] if route=='mono' else [('left_pcm',stereo.LEFT),('right_pcm',stereo.RIGHT)]
    replaced={a-8 for _,a in planes}
    for a,data in old.regions:
        if a not in replaced:
            memory.map(a,len(data));target,offset=memory.region(a,len(data));target[offset:offset+len(data)]=data
    for name,a,n,writable in old.allowed:
        if name not in ('pcm','left_pcm','right_pcm'):memory.allow(name,a,n,writable)
    for name,a in planes:memory.map(a-8,capacity*2+16,0xA5);memory.allow(name,a,capacity*2,True)
    machine.mem=memory;machine.output_samples=capacity;machine.regs[5]=sext32(case['requested'])
    machine.case_input['requested_i32']=case['requested']
    return machine


def observation(case,result):
    route=case['route'];mono_route=route=='mono';state=result['state'];channels=1 if mono_route else 2
    stores=result['pcm_store_count'];groups=stores//(32*channels)
    history_access=result['writes'].get('history',{}).get('accesses',0)
    key_access=result['writes'].get('key',{}).get('accesses',0)
    committed=history_access==(2 if mono_route else 4)
    stop='requested_count' if committed else 'mono_marker' if mono_route else 'right_marker' if key_access%2 else 'left_marker'
    inspected=result['reads'].get('encoded',{}).get('last_end',0)
    return dict(status='admitted',kernel_return=result['return_i32'],stop=stop,
        history=state['history_i16']+(case['history'][2:] if mono_route else []),key=state['key_u16'],
        left_history_committed=committed,right_history_committed=committed and not mono_route,
        complete_channel_blocks=groups*channels,samples_per_plane=groups*32,
        encoded_bytes_consumed=groups*18*channels,encoded_bytes_inspected=inspected,
        left_pcm=state['pcm_i16'] if mono_route else state['left_pcm_i16'],
        right_pcm=[] if mono_route else state['right_pcm_i16'],
        original_instructions=result['steps'],original_guard_hex=state.get('output_guard_hex',state.get('left_guard_hex')),
        original_history_accesses=history_access,original_key_accesses=key_access,
        original_abi=result['abi'],original_unique_words=len(result['visited_pcs']))


def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args();out=args.output.resolve()
    if out.exists():raise OracleError('Preserve completed evidence; use new directory')
    out.mkdir(parents=True);sources=load_sources();transcript=inputs(sources)
    frozen=out/'inputs.json';frozen.write_bytes(encode(transcript));transcript=json.loads(frozen.read_bytes())
    rows=[]
    for case in transcript['cases']:
        if len(bytes.fromhex(case['encoded_hex']))>8228 or case['output_samples']>8288:
            expected=dict(status='physical_span',projection='Outside first workspace physical profile; original result remains in frozen source.')
        elif 'reuse' in case:
            reuse=case['reuse'];result=sources[reuse['family']]['cases'][reuse['index']]['expected']
            expected=observation(case,result)
        else:
            machine=original_machine(case);result=machine.run(step_cap=2000000);expected=observation(case,result)
        rows.append(dict(name=case['name'],expected=expected))
    fixture=out/'expected.json';fixture.write_bytes(encode(rows))
    manifest=dict(schema=1,inputs_sha256=sha(frozen.read_bytes()),expected_sha256=sha(fixture.read_bytes()),
        generator_sha256=sha(Path(__file__).read_bytes()),core_freeze_sha256=sha((BASE/'frozen_identity.json').read_bytes()),
        sources=SOURCES,engine_sha256={name:sha((ROOT/'tools/native_reconstruction'/name).read_bytes())
            for name in (*large.ENGINE_FILES,'adx_large_block_oracle.py')},
        summary=dict(cases=len(rows),admitted=sum(r['expected']['status']=='admitted' for r in rows),
            physical_refusal=sum(r['expected']['status']=='physical_span' for r in rows),
            original_instructions=sum(r['expected'].get('original_instructions',0) for r in rows),
            samples=sum(r['expected'].get('samples_per_plane',0)*(1 if c['route']=='mono' else 2) for c,r in zip(transcript['cases'],rows))),
        limitations=['Only scalar PCM/state projection, not guest frame/GPR/MAC/intermediate scheduler or complete window equivalence.',
            'Physical-profile refusal controls are deliberately new native admission policy, not original success observations.',
            'Window codec-entry input/state projections are replayed through actual original direct kernels, not inferred by reversing later wrap/publication effects.'])
    (out/'manifest.json').write_bytes(encode(manifest));print(json.dumps(dict(**manifest['summary'],manifest_sha256=sha((out/'manifest.json').read_bytes())),indent=2))


if __name__=='__main__':main()
