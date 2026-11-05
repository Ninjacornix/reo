"""Small EE scalar MAC extension; no change to the shared integer engine.

Architectural results only, no pipeline cycle/interlock timing. The EE manual's
canonical sign-extended-word operand restriction is checked before any mutation.
HI/LO have two independent lower64 banks; upper128 GPR lanes are not modeled.
"""
import hashlib
from pathlib import Path
from sjuni_oracle import Machine as IntegerEngine,OracleError,UnknownInstruction
from sjuni_oracle import MASK32,MASK64,sext32,signed

ROOT=Path(__file__).resolve().parents[2]
GENERATOR=ROOT/'third_party/PS2Recomp/ps2xRecomp/src/lib/code_generator.cpp'
MACROS=ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_runtime_macros.h'
GENERATOR_SHA='cf90c94d772b028bc71ebe965a6c3ad29cc9e89f6b22ac481c87e88d868c6f55'
MACROS_SHA='763baab6071c4a10c418a2f9f968e92e4da2e62a1e5ace642593a38d4c734287'


def implementation_identity():
    """Pin the inspected local ISA implementation; not a compiled-runtime claim."""
    records={}
    for path,expected in ((GENERATOR,GENERATOR_SHA),(MACROS,MACROS_SHA)):
        actual=hashlib.sha256(path.read_bytes()).hexdigest()
        if actual!=expected:raise OracleError('Local ISA reference changed: '+str(path))
        records[path.relative_to(ROOT).as_posix()]=actual
    return dict(base_commit='c46d1c7d8ab00fbfa18d2c1f764c559e4e5dc78f',source_sha256=records)


class EeMacInstructions:
    """Mixin over the unchanged bounded integer engine's instruction method."""
    def initialize_mac(self, *, hi, lo, hi1, lo1):
        values=(hi,lo,hi1,lo1)
        if any(not isinstance(x,int) or not 0<=x<=MASK64 for x in values):
            raise OracleError('Explicit lower64 MAC bank initialization required')
        self.hi,self.lo,self.hi1,self.lo1=values
        self.mac_counts={}

    def mac_state(self):
        return dict(hi=self.hi,lo=self.lo,hi1=self.hi1,lo1=self.lo1)

    def instruction(self,pc,word):
        op=word>>26
        rs,rt,rd,sa,fn=(word>>21)&31,(word>>16)&31,(word>>11)&31,(word>>6)&31,word&63
        base_moves={0x10:('hi',False),0x11:('hi',True),0x12:('lo',False),0x13:('lo',True)}
        secondary_moves={0x10:('hi1',False),0x11:('hi1',True),0x12:('lo1',False),0x13:('lo1',True)}
        move=(base_moves if op==0 else secondary_moves if op==0x1C else {}).get(fn)
        if move is not None:
            bank,to_bank=move
            if sa or rt or (rd if to_bank else rs):
                raise UnknownInstruction('Reserved EE move encoding')
            if to_bank:setattr(self,bank,self.regs[rs]&MASK64)
            else:self.regs[rd]=getattr(self,bank)
            name=('mt' if to_bank else 'mf')+bank
        elif (op==0 and fn in (0x18,0x19)) or (op==0x1C and fn in (0,1,0x18,0x19,0x20,0x21)):
            if sa:raise UnknownInstruction('Reserved EE MAC shift field')
            if any(self.regs[n]!=sext32(self.regs[n]) for n in (rs,rt)):
                raise OracleError('EE MAC source is not a canonical sign-extended word')
            secondary=op==0x1C and fn in (0x18,0x19,0x20,0x21)
            add=op==0x1C and fn in (0,1,0x20,0x21)
            unsigned=bool(fn&1)
            lhs=self.regs[rs]&MASK32 if unsigned else signed(self.regs[rs],32)
            rhs=self.regs[rt]&MASK32 if unsigned else signed(self.regs[rt],32)
            hi,lo=('hi1','lo1') if secondary else ('hi','lo')
            accumulator=((getattr(self,hi)&MASK32)<<32)|(getattr(self,lo)&MASK32) if add else 0
            result=(accumulator+lhs*rhs)&MASK64
            setattr(self,lo,sext32(result));setattr(self,hi,sext32(result>>32))
            self.regs[rd]=sext32(result)
            name=('madd' if add else 'mult')+('u' if unsigned else '')+('1' if secondary else '')
        else:
            return IntegerEngine.instruction(self,pc,word)
        self.regs[0]=0
        self.mac_counts[name]=self.mac_counts.get(name,0)+1
        return None


class MicroMachine(EeMacInstructions):
    """No memory or branch runner: individual authored microinstructions only."""
    def __init__(self, *, hi, lo, hi1, lo1):
        self.regs=[0]*32
        self.initialize_mac(hi=hi,lo=lo,hi1=hi1,lo1=lo1)


def encode(op,fn,rs=0,rt=0,rd=0,sa=0):
    """Encode an authored test instruction, not original target text."""
    if any(not 0<=x<32 for x in (rs,rt,rd,sa)) or not 0<=op<64 or not 0<=fn<64:
        raise ValueError('Invalid microinstruction field')
    return op<<26|rs<<21|rt<<16|rd<<11|sa<<6|fn
