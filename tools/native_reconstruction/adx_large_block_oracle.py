#!/usr/bin/env python3
"""Large bounded synthetic ADX spans using the unchanged original-word engines.

The frozen small-corpus modules and their MAX_BLOCKS globals stay unchanged.
Only this wrapper's synthetic allocation geometry/request register is enlarged;
the original run/instruction/snapshot implementations execute every instruction.
"""
import argparse
import hashlib
import json
from pathlib import Path

import adx_decode_oracle as mono
import adx_stereo_oracle as stereo
from sjuni_oracle import OracleError, sext32

ROOT = Path(__file__).resolve().parents[2]
MAX_ORIGINAL_BLOCKS = 513
PROPOSED_ADAPTER_BLOCKS = 512
STEP_CAP = 2_000_000
ENGINE_FILES = ('sjuni_oracle.py','ee_mac_oracle.py','adx_decode_oracle.py','adx_stereo_oracle.py')


def identities():
    return {name:hashlib.sha256(Path(__file__).with_name(name).read_bytes()).hexdigest()
            for name in ENGINE_FILES}


def raw(machine,address,size):
    data,offset=machine.mem.region(address,size)
    return bytes(data[offset:offset+size])


def machine_for(encoded,requested,*,mode='mono',output_samples=None,elf_path=None,**parameters):
    if mode not in ('mono','normal','downmix'):
        raise OracleError('Only the three direct original kernels are admitted')
    if not isinstance(requested,int) or not 1<=requested<=MAX_ORIGINAL_BLOCKS:
        raise OracleError('Large-wrapper count must be1..513')
    if not isinstance(encoded,bytes) or len(encoded)>MAX_ORIGINAL_BLOCKS*18:
        raise OracleError('Large-wrapper input exceeds finite synthetic bound')
    default_samples=(requested if mode=='mono' else requested//2)*32
    if output_samples is None:
        output_samples=default_samples
    max_samples=(MAX_ORIGINAL_BLOCKS if mode=='mono' else MAX_ORIGINAL_BLOCKS//2)*32
    if not isinstance(output_samples,int) or not 0<=output_samples<=max_samples:
        raise OracleError('Large-wrapper output capacity exceeds finite bound')
    module=mono if mode=='mono' else stereo
    if elf_path is not None:
        parameters['elf_path']=elf_path
    seed=module.Machine(b'',0,output_samples=0,**parameters,**({} if mode=='mono' else {'mode':mode}))
    old=seed.mem
    memory=module.ObservedMemory()
    planes=[('pcm',module.OUTPUT)] if mode=='mono' else [('left_pcm',module.LEFT),('right_pcm',module.RIGHT)]
    replaced={base-8 for _,base in planes}
    # This is synthetic setup only. No original instruction has executed yet.
    # Preserve the original constructors' history/key/table/stack/flag bytes.
    for base,data in old.regions:
        if base not in replaced:
            memory.map(base,len(data))
            target,offset=memory.region(base,len(data))
            target[offset:offset+len(data)]=data
    for name,base,length,writable in old.allowed:
        if name not in ('encoded','pcm','left_pcm','right_pcm'):
            memory.allow(name,base,length,writable)
    if encoded:
        memory.map(module.INPUT,len(encoded))
        target,offset=memory.region(module.INPUT,len(encoded))
        target[offset:offset+len(encoded)]=encoded
        memory.allow('encoded',module.INPUT,len(encoded))
    for name,base in planes:
        memory.map(base-8,output_samples*2+16,0xA5)
        memory.allow(name,base,output_samples*2,True)
    seed.mem=memory
    seed.output_samples=output_samples
    seed.regs[5]=sext32(requested)
    # Match135078's LH/SW argument publication rather than the small stereo
    # constructor's optional low-halfword packing experiment. Lower original
    # words still execute and consume these actual canonical ABI values.
    if mode!='mono':
        for reg,value in zip((10,11),seed.case_input['coefficients_i16']):
            seed.regs[reg]=sext32(value)
        seed.mem.store(module.STACK_TOP+8,4,seed.case_input['multiplier_i16'])
        seed.mem.store(module.STACK_TOP+16,4,seed.case_input['addend_i16'])
    else:
        seed.mem.store(module.STACK_TOP,4,seed.case_input['addend_i16'])
    seed.case_input['encoded_hex']=encoded.hex()
    seed.case_input['requested_i32']=requested
    capacity='output_capacity_samples' if mode=='mono' else 'output_capacity_samples_per_plane'
    seed.case_input[capacity]=output_samples
    seed.case_input['canonical_caller_argument_words']=True
    seed.case_input['canonical_halfword_register_arguments']=True
    return seed


def frame_initial(machine,mode):
    module=mono if mode=='mono' else stereo
    size=80 if mode=='mono' else 112
    return dict(frame_address=module.STACK_TOP-size,frame_bytes=size,
        initial_frame_hex=raw(machine,module.STACK_TOP-size,size).hex(),
        initial_lower_stack_guard_hex=raw(machine,module.STACK_TOP-size-16,16).hex(),
        caller_stack_address=module.STACK_TOP,
        caller_argument_bytes_hex=raw(machine,module.STACK_TOP,32).hex(),
        initial_gpr_lower64=machine.regs.copy(),
        saved_register_indices=sorted(machine.saved),return_address_u32=module.RETURN)


def return_jr(machine,result,mode):
    candidates=[]
    for pc in result['visited_pcs']:
        if mode=='mono':
            word=int.from_bytes(machine.code[pc-mono.ENTRY:pc-mono.ENTRY+4],'little')
        else:
            word=machine.code[pc]
        if word>>26==0 and word&63==8 and (word>>21)&31==31:
            candidates.append(pc)
    if len(candidates)!=1:
        raise OracleError('Direct original kernel lacks its unique observed JR ra')
    return candidates[0]


def encoded_blocks(count):
    return b''.join(mono.block((i*127+19)&0x7FFF,
        bytes((j*37+i*19)&255 for j in range(16))) for i in range(count))


def parameters_for(mode,count):
    history=(23456,-12345) if mode=='mono' else (23456,-12345,-11111,22222)
    parameters=dict(history=history,coefficients=(7192,-3172),key=32766,
        multiplier=-32767,addend=12345)
    if count==17:
        parameters.update(coefficients=(-32768,32767),key=65535,multiplier=-1,addend=-32768)
    elif count==300:
        parameters.update(coefficients=(4096,0),key=1,multiplier=7,addend=-9)
    elif count==511:
        parameters.update(coefficients=(32767,32767),key=23456,multiplier=7,addend=-9)
    elif count==512:
        parameters['mac_initial']=(0x123456789ABCDEF0,0xFEDCBA9876543210,
            0x9999999999999999,0x7777777777777777)
    return parameters


def generate(elf_path=ROOT/'game_data/SLUS_207.65'):
    before=identities()
    cases=[]
    def add(name,mode,encoded,count,**extra):
        parameters=parameters_for(mode,count)
        parameters.update(extra)
        machine=machine_for(encoded,count,mode=mode,elf_path=elf_path,**parameters)
        initial=frame_initial(machine,mode)
        result=machine.run(step_cap=STEP_CAP)
        result['original_abi']=dict(**initial,
            final_frame_hex=raw(machine,initial['frame_address'],initial['frame_bytes']).hex(),
            final_lower_stack_guard_hex=raw(machine,initial['frame_address']-16,16).hex(),
            final_caller_argument_bytes_hex=raw(machine,initial['caller_stack_address'],32).hex(),
            final_pc_u32=machine.pc,return_branch_pc=return_jr(machine,result,mode),
            final_gpr_lower64_observation_only=machine.regs.copy())
        cases.append(dict(name=name,mode=mode,
            proposed_adapter_count_admitted=count<=PROPOSED_ADAPTER_BLOCKS,
            input=machine.case_input,expected=result))
    for mode in ('mono','normal','downmix'):
        for count in (17,210,300,511,512,513):
            add(f'{mode}_full_{count}',mode,encoded_blocks(count),count)
    add('mono_marker_after210_request512','mono',encoded_blocks(210)+b'\x80\x00',512)
    add('normal_right_marker_after150pairs_odd_request511','normal',
        encoded_blocks(301)+b'\x80\x00',511)
    add('downmix_left_marker_after105pairs_request512','downmix',
        encoded_blocks(210)+b'\x80\x00',512)
    if identities()!=before or mono.MAX_BLOCKS!=16 or stereo.MAX_BLOCKS!=16:
        raise OracleError('A frozen engine/module changed during large fixture generation')
    ref=machine_for(b'\x80\x00',1,mode='mono',elf_path=elf_path,
        **parameters_for('mono',1))
    stereo_ref=machine_for(b'\x80\x00',2,mode='normal',elf_path=elf_path,
        **parameters_for('normal',2))
    reached={mode:set().union(*(set(c['expected']['visited_pcs']) for c in cases if c['mode']==mode))
             for mode in ('mono','normal','downmix')}
    return dict(schema=1,kind='large bounded original-word keyed ADX kernels and ABI',
        identity=dict(elf_sha256=ref.elf.sha256,tool_sha256=before,
            generator_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
            mono_body=dict(entry_pc=mono.ENTRY,end_pc_exclusive=mono.END,
                sha256=hashlib.sha256(ref.code).hexdigest()),
            stereo_bodies={name:dict(entry_pc=a,end_pc_exclusive=b,
                sha256=hashlib.sha256(stereo_ref.body_bytes[name]).hexdigest())
                for name,(a,b) in stereo.BODIES.items() if name!='selector'},
            nibble_table_sha256=hashlib.sha256(ref.table).hexdigest()),
        assumptions=['Count1..513 is wrapper admission only; original instruction/snapshot/EE engines are unchanged.',
            'Seed zero-count constructors execute no instruction; only this wrapper remaps synthetic spans and requested register.',
            'All original loop instructions execute with a finite2000000-step cap; no loop teleport or native decoder.',
            'Direct normal/downmix bodies only; no original selection flag change or selector override.',
            'Count513 remains an original-code observation explicitly outside proposed512 native admission.',
            'Live pool snapshots motivate coverage but are not atomic argument captures or fixture data.',
            'No game/device/media asset execution; ABI is selective saved-state/frame/return, not volatile/MAC equivalence.'],
        counts=dict(cases=len(cases),original_instructions=sum(c['expected']['steps'] for c in cases),
            pcm_halfword_stores=sum(c['expected']['pcm_store_count'] for c in cases),
            visited_pcs={mode:len(pcs) for mode,pcs in reached.items()}),cases=cases)


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--elf',type=Path,default=ROOT/'game_data/SLUS_207.65')
    parser.add_argument('--output',type=Path,default=ROOT/'build-native-sjuni/adx-large-block-fixtures.json')
    args=parser.parse_args()
    output=args.output.resolve()
    allowed=ROOT/'build-native-sjuni'
    if output==allowed or not output.is_relative_to(allowed):
        raise ValueError('Use ignored private output')
    result=generate(args.elf)
    output.parent.mkdir(parents=True,exist_ok=True)
    output.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(result['counts']))


if __name__=='__main__':
    main()
