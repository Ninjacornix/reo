"""Small verification-only PCPYH/PCPYLD/SQ extension with explicit upper lanes.

Sony EE Core Instruction Set Manual v6 pp189/190/287:
https://docs.alexrp.com/mips/ee_insns.pdf
Unknown upper halves remain unknown; SQ refuses rather than inventing bytes.
The shared scalar/MAC engines are unchanged. No game backend selects this code.
"""
from sjuni_oracle import MASK32, MASK64, OracleError, UnknownInstruction, signed


class CopyStoreInstructions:
    def initialize_copy_store(self):
        self.upper={0:0};self.copy_store_counts={}

    def instruction(self,pc,word):
        op=word>>26;rs=(word>>21)&31;rt=(word>>16)&31;rd=(word>>11)&31;sa=(word>>6)&31;fn=word&63
        if op==0x19:
            value=(self.regs[rs]+signed(word&0xFFFF,16))&MASK64
            if rt:self.regs[rt]=value
            name='daddiu'
        elif op==0 and fn==0x2F:
            if sa:raise UnknownInstruction('Reserved DSUBU shift field')
            value=(self.regs[rs]-self.regs[rt])&MASK64
            if rd:self.regs[rd]=value
            name='dsubu'
        elif op==0 and fn in [0x38,0x3A,0x3B]:
            if rs:raise UnknownInstruction('Reserved doubleword immediate shift rs')
            value=self.regs[rt]&MASK64
            value=(value<<sa)&MASK64 if fn==0x38 else value>>sa if fn==0x3A else (signed(value,64)>>sa)&MASK64
            if rd:self.regs[rd]=value
            name={0x38:'dsll',0x3A:'dsrl',0x3B:'dsra'}[fn]
        elif op==0x1C and fn==0x29 and sa==0x1B:
            if rs:raise UnknownInstruction('Reserved PCPYH rs')
            low=self.regs[rt]&0xFFFF;high=self.upper.get(rt)
            value=sum(low<<(16*n) for n in range(4))
            if rd:
                self.regs[rd]=value
                if high is None:self.upper.pop(rd,None)
                else:self.upper[rd]=sum((high&0xFFFF)<<(16*n) for n in range(4))
            name='pcpyh'
        elif op==0x1C and fn==0x09 and sa==0x0E:
            low=self.regs[rt]&MASK64;high=self.regs[rs]&MASK64
            if rd:self.regs[rd]=low;self.upper[rd]=high
            name='pcpyld'
        elif op==0x1F:
            if rt not in self.upper:raise OracleError('SQ requires an established upper64 source')
            address=((self.regs[rs]&MASK32)+signed(word&0xFFFF,16))&MASK32
            address&=~15
            self.mem.store(address,16,(self.regs[rt]&MASK64)|(self.upper[rt]<<64))
            name='sq'
        else:return super().instruction(pc,word)
        self.regs[0]=0;self.upper[0]=0
        self.copy_store_counts[name]=self.copy_store_counts.get(name,0)+1
        return None
