#!/usr/bin/env python3
"""Execute owned ADX service/odd-result words with bounded scripted codec hooks.

This isolates dispatch/publication. Hooks neither decode ADX nor model a worker,
borrow lifetime, real callback reentry, scheduler or concurrent cancellation.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import struct

from sjuni_oracle import Elf, Memory, Machine as IntegerEngine, OracleError, StepLimit, MASK32, sext32, signed

ROOT = Path(__file__).resolve().parents[2]
SERVICE, SERVICE_END = 0x135078, 0x135170
ODD, ODD_END, FLAG = 0x135068, 0x135078, 0x21B7B0
CONTEXT, INPUT, LEFT, RIGHT = 0x400000, 0x500000, 0x510000, 0x520000
SP, RETURN = 0x701000, 0xFFFFF0
MONO, STEREO = 0x1276D8, 0x127FC8
SAVED = {16: 0x123456789ABCDEF0, 17: 0xFEDCBA9876543210}


class ObservedMemory(Memory):
    def __init__(self):
        super().__init__()
        self.active, self.origin, self.writes, self.reads = False, 'original', [], []

    def observe(self, address, size, write, value=None):
        if not self.active:
            return
        # All accesses must be wholly inside one explicitly mapped synthetic span.
        self.region(address, size)
        row = dict(address=address, bytes=size, origin=self.origin)
        if write:
            row['value_u64'] = value & ((1 << (size*8))-1)
            self.writes.append(row)
        else:
            self.reads.append(row)

    def load(self, address, size):
        self.observe(address, size, False)
        return super().load(address, size)

    def store(self, address, size, value):
        self.observe(address, size, True, value)
        super().store(address, size, value)


class Machine:
    instruction = IntegerEngine.instruction

    def __init__(self, *, phase=1, mode=1, requested=4, result=4,
                 hook_effect='none', hook_payload=False, initial_flag=0,
                 elf_path=ROOT/'game_data/SLUS_207.65'):
        if any(not isinstance(x, int) or not 0 <= x <= MASK32
               for x in (phase, mode, initial_flag)):
            raise OracleError('Phase/mode/flag must be raw unsigned words')
        if any(not isinstance(x, int) or not -0x80000000 <= x <= 0x7FFFFFFF
               for x in (requested, result)):
            raise OracleError('Request and scripted result must be signed words')
        if hook_effect not in ('none','cancel','release','request','acknowledge'):
            raise OracleError('Unsupported scripted reentry effect')
        if not isinstance(hook_payload, bool):
            raise OracleError('Payload effect must be boolean')
        self.case_input = dict(phase_u32=phase, mode_u32=mode, requested_i32=requested,
            scripted_result_i32=result, scripted_effect=hook_effect,
            scripted_payload=hook_payload, initial_flag_u32=initial_flag)
        self.elf = Elf(elf_path)
        self.code = {(SERVICE,SERVICE_END):self.elf.read(SERVICE,SERVICE_END-SERVICE),
                     (ODD,ODD_END):self.elf.read(ODD,ODD_END-ODD)}
        if any(data is None or len(data) != b-a for (a,b),data in self.code.items()):
            raise OracleError('Complete owned service words unavailable')
        self.mem = ObservedMemory()
        for address, size, fill in ((CONTEXT,60,0xA5),(FLAG,4,0),
                (INPUT,64,0xD7),(LEFT,64,0xA1),(RIGHT,64,0xB2),
                (SP-128,192,0xCC)):
            self.mem.map(address,size,fill)
        for off,value in {0:1,4:7,8:0xA5A5A5A5,12:phase,16:0x89ABCDEF,
                20:mode,24:INPUT,28:requested,32:LEFT,36:RIGHT}.items():
            self.mem.store(CONTEXT+off,4,value)
        for off,value in ((40,0x1234),(42,0xFEDC),(44,0xABCD),(46,0x2345),
                          (48,0x8000),(50,0x7FFF),(52,0xFFFE),
                          (54,0x8001),(56,0xF00D)):
            self.mem.store(CONTEXT+off,2,value)
        self.mem.store(FLAG,4,initial_flag)
        self.regs=[0]*32
        self.regs[2]=0xBAD0BAD0
        self.regs[4]=CONTEXT
        self.regs[29]=SP
        self.regs[31]=RETURN
        for n,value in SAVED.items():
            self.regs[n]=value
        self.pc=SERVICE
        self.visited=set()
        self.events=[]
        self.last_transfer_pc=None
        self.ran=False

    def bytes_at(self,address,size):
        region,offset=self.mem.region(address,size)
        return bytes(region[offset:offset+size])

    def snapshot(self):
        return dict(context_words_u32=[Memory.load(self.mem,CONTEXT+4*i,4) for i in range(15)],
            odd_flag_u32=Memory.load(self.mem,FLAG,4),
            left_bytes_hex=self.bytes_at(LEFT,64).hex(), right_bytes_hex=self.bytes_at(RIGHT,64).hex(),
            input_sha256=hashlib.sha256(self.bytes_at(INPUT,64)).hexdigest(),
            frame_bytes_hex=self.bytes_at(SP-64,64).hex(),
            lower_stack_guard_hex=self.bytes_at(SP-128,64).hex(),
            caller_stack_guard_hex=self.bytes_at(SP,64).hex())

    def fetch(self,pc):
        if pc%4:
            raise OracleError('Unaligned service fetch')
        for (a,b),data in self.code.items():
            if a <= pc < b:
                return struct.unpack_from('<I',data,pc-a)[0]
        raise OracleError(f'Service fetch outside admitted bodies: {pc:#x}')

    def codec_hook(self):
        if self.pc not in (MONO,STEREO):
            return False
        if self.events:
            raise OracleError('Service called more than one codec')
        route='mono' if self.pc==MONO else 'stereo'
        sp=self.regs[29]&MASK32
        event=dict(kind='scripted_codec',route=route,target_pc=self.pc,
            caller_pc=self.last_transfer_pc,return_pc=self.regs[31]&MASK32,
            arguments_lower64=self.regs[4:12],
            stack_argument_words_u32=[Memory.load(self.mem,sp+i,4) for i in (0,8,16)],
            before=self.snapshot(),effect=self.case_input['scripted_effect'])
        self.mem.origin='scripted_codec'
        if self.case_input['scripted_payload']:
            # Fixed synthetic effects, not ADX arithmetic or actual returned units.
            self.mem.store(LEFT,8,0x0123456789ABCDEF)
            self.mem.store(CONTEXT+40,4,0x43211234)
            if route=='stereo':
                self.mem.store(RIGHT,8,0xFEDCBA9876543210)
                self.mem.store(CONTEXT+44,4,0x87655678)
            self.mem.store(CONTEXT+52,2,0x3456)
        effect=self.case_input['scripted_effect']
        self.mem.origin='scripted_reentry_effect'
        if effect=='cancel':
            self.mem.store(CONTEXT+12,4,0)
            for off in (40,44):
                self.mem.store(CONTEXT+off,4,0)
        elif effect=='release':
            for off in range(0,60,4):
                self.mem.store(CONTEXT+off,4,0)
        elif effect=='request':
            # Same known scalar contract: already-processing request does not
            # accept/clear completed; its raw return one is not acceptance.
            if Memory.load(self.mem,CONTEXT+12,4)==0:
                self.mem.store(CONTEXT+16,4,0)
                self.mem.store(CONTEXT+12,4,1)
        elif effect=='acknowledge':
            if Memory.load(self.mem,CONTEXT+12,4)==3:
                self.mem.store(CONTEXT+12,4,0)
        self.mem.origin='original'
        event['after']=self.snapshot()
        self.events.append(event)
        # A conforming external hook may clobber caller-saved registers; preserve
        # s0/s1/SP/RA as a synchronous codec ABI assumption, not kernel evidence.
        for n in (*range(3,16),24,25):
            self.regs[n]=sext32(0xD00D0000+n)
        self.regs[2]=sext32(self.case_input['scripted_result_i32'])
        self.pc=self.regs[31]&MASK32
        return True

    def run(self,step_cap=300):
        if not isinstance(step_cap,int) or step_cap<=0:
            raise OracleError('Service requires a positive finite step bound')
        if self.ran:
            raise OracleError('Service fixture invocation is one-shot')
        self.ran=True
        pending=None
        steps=0
        self.mem.active=True
        try:
            while self.pc!=RETURN:
                if steps>=step_cap:
                    raise StepLimit('Service instruction limit')
                if pending is None and self.codec_hook():
                    continue
                pc=self.pc
                word=self.fetch(pc)
                self.visited.add(pc)
                steps+=1
                branch=self.instruction(pc,word)
                if pending is not None:
                    if branch is not None:
                        raise OracleError('Control in service delay slot')
                    self.pc,self.last_transfer_pc=pending
                    pending=None
                elif branch is not None:
                    taken,target,likely=branch
                    if not taken and likely:
                        self.pc=pc+8
                    else:
                        pending=(target if taken else pc+8,pc)
                        self.pc=pc+4
                else:
                    self.pc=pc+4
        finally:
            self.mem.active=False
        return dict(return_is_defined=False,return_raw_lower64_observation_only=self.regs[2],
            steps=steps,visited_pcs=sorted(self.visited),state=self.snapshot(),events=self.events,
            writes=self.mem.writes,reads=self.mem.reads,
            abi=dict(stack_restored=self.regs[29]==SP,return_address_restored=self.regs[31]==RETURN,
                saved_registers_restored=all(self.regs[n]==v for n,v in SAVED.items())),
            observations_not_abi=dict(gpr_lower64=self.regs.copy()))


def generated_word_audit(elf_path=ROOT/'game_data/SLUS_207.65',source_root=None):
    root=source_root or ROOT/'build-native-sjuni/candidate-work-v3/project/recomp/config/output'
    elf=Elf(elf_path)
    rows=[]
    for entry,end in ((SERVICE,SERVICE_END),(ODD,ODD_END)):
        path=Path(root)/f'sub_{entry:08X}_0x{entry:x}.cpp'
        comments={}
        for pc,word in re.findall(r'//\s*0x([0-9a-f]+):\s*0x([0-9a-f]+)',path.read_text(),re.I):
            pc,word=int(pc,16),int(word,16)
            if entry <= pc < end:
                if pc in comments and comments[pc]!=word:
                    raise OracleError('Conflicting generated word comments')
                comments[pc]=word
        omitted=[]
        for pc in range(entry,end,4):
            word=int.from_bytes(elf.read(pc,4),'little')
            if pc not in comments:
                if word:
                    raise OracleError(f'Omitted nonzero service word {pc:#x}')
                omitted.append(pc)
            elif comments[pc]!=word:
                raise OracleError(f'Original/generated word mismatch {pc:#x}')
        rows.append(dict(entry_pc=entry,end_pc_exclusive=end,matched_comment_words=len(comments),
            omitted_zero_pcs=omitted,conflicts=0))
    return rows


def generate(elf_path=ROOT/'game_data/SLUS_207.65'):
    cases=[]
    def add(name,**kwargs):
        machine=Machine(elf_path=elf_path,**kwargs)
        before=machine.snapshot()
        cases.append(dict(name=name,input=machine.case_input,initial_state=before,expected=machine.run()))
    for phase in (0,1,2,3,4,0x80000000,0xFFFFFFFF):
        for mode in (0,1,2,0xFFFFFFFF):
            add(f'phase_{phase:08X}_mode_{mode:08X}',phase=phase,mode=mode,result=3)
    for mode in (1,2):
        for result in (-2147483648,-2147483647,-3,-2,-1,0,1,2,3,2147483646,2147483647):
            add(f'mode_{mode}_signed_result_{result}',mode=mode,result=result,initial_flag=0xAABBCCDD)
        for count in (-2147483648,-1,0,1,3,16,2147483647):
            add(f'mode_{mode}_request_{count}',mode=mode,requested=count,result=count)
        for effect in ('none','cancel','release','request','acknowledge'):
            add(f'mode_{mode}_payload_effect_{effect}',mode=mode,result=3,
                hook_effect=effect,hook_payload=True)
    reference=Machine(elf_path=elf_path)
    reached=set().union(*(set(c['expected']['visited_pcs']) for c in cases))
    return dict(schema=1,kind='owned-word ADX predictor service with scripted codec effects',
        identity=dict(elf_sha256=reference.elf.sha256,
            integer_engine_sha256=hashlib.sha256(Path(__file__).with_name('sjuni_oracle.py').read_bytes()).hexdigest(),
            generator_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
            bodies=[dict(entry_pc=a,end_pc_exclusive=b,words=(b-a)//4,
                sha256=hashlib.sha256(data).hexdigest()) for (a,b),data in sorted(reference.code.items())]),
        assumptions=['Codec hooks supply only scripted signed32 results and explicitly recorded synthetic effects.',
            'Codec hook preserves s0/s1/SP/RA and synchronously returns; no real codec/scheduler/device is executed.',
            'Reentry effects are scripted scalar-state mutations, not actual concurrent/reentrant function execution.',
            'Mapped aligned context/frame/flag and payload probes only; invalid object lifetimes are not admitted.',
            'Service raw return registers are observations, not a defined return contract.'],
        counts=dict(cases=len(cases),original_instructions=sum(c['expected']['steps'] for c in cases),
            codec_calls=sum(len(c['expected']['events']) for c in cases),
            body_words=sum((b-a)//4 for a,b in reference.code),reached_words=len(reached),
            unreached_pcs=sorted(set(pc for a,b in reference.code for pc in range(a,b,4))-reached)),
        cases=cases)


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--elf',type=Path,default=ROOT/'game_data/SLUS_207.65')
    parser.add_argument('--output',type=Path,default=ROOT/'build-native-sjuni/adx-service-fixtures.json')
    parser.add_argument('--audit-generated',action='store_true')
    args=parser.parse_args()
    allowed=ROOT/'build-native-sjuni'
    output=args.output.resolve()
    if output==allowed or not output.is_relative_to(allowed):
        raise ValueError('Use a private ignored output below build-native-sjuni')
    result=generate(args.elf)
    if args.audit_generated:
        result['generated_word_audit']=generated_word_audit(args.elf)
    output.parent.mkdir(parents=True,exist_ok=True)
    output.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(result['counts']))


if __name__=='__main__':
    main()
