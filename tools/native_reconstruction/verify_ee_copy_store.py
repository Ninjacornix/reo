#!/usr/bin/env python3
"""Execute the complete owned memset with the small independently tested extension."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
from ee_copy_store_oracle import CopyStoreInstructions
from movie_position_oracle import ClockIntegerInstructions,AccessMemory
from sjuni_oracle import Elf,OracleError,StepLimit

ROOT=Path(__file__).resolve().parents[2];BASE=ROOT/'build-native-sjuni/ee-copy-store'
START,END,DIGEST=0x107C68,0x107D28,'09c7829fb0e061976495f53e07fa77cde5f74607c3657deb18319097cf4a51be'
RETURN=0xFFFFF0
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


class Machine(CopyStoreInstructions,ClockIntegerInstructions):
    def __init__(self,alignment,length,fill):
        elf=Elf(ROOT/'game_data/SLUS_207.65');raw=elf.read(START,END-START)
        if hashlib.sha256(raw).hexdigest()!=DIGEST:raise OracleError('Owned memset identity')
        self.code={START+n:struct.unpack_from('<I',raw,n)[0] for n in range(0,len(raw),4)}
        self.regs=[0]*32;self.regs[4]=0x400040+alignment;self.regs[5]=fill&0xFFFFFFFF;self.regs[6]=length;self.regs[31]=RETURN
        self.mem=AccessMemory();self.mem.span('buffer',0x400000,1024,True,0xA5);self.mem.active=True
        self.initialize_copy_store();self.initialize_mac(hi=1,lo=2,hi1=3,lo1=4);self.extension_counts={};self.steps=0

    def run(self):
        destination,length,fill=self.regs[4],self.regs[6],self.regs[5]&255;pc,pending=START,None
        while pc!=RETURN:
            if self.steps>=10000:raise StepLimit('Memset exceeded bound')
            if pc not in self.code:raise OracleError('Unowned memset transfer')
            self.steps+=1;branch=self.instruction(pc,self.code[pc])
            if pending is not None:
                if branch is not None:raise OracleError('Branch in delay slot')
                pc,pending=pending,None
            elif branch is None:pc+=4
            else:
                taken,target,likely=branch
                if likely and not taken:pc+=8
                else:pending=target if taken else pc+8;pc+=4
        self.mem.active=False
        actual=self.mem.load(0x400000,1024).to_bytes(1024,'little');expected=bytearray([0xA5]*1024);at=destination-0x400000;expected[at:at+length]=bytes([fill])*length
        if actual!=expected or self.regs[2]!=destination:raise OracleError('Complete memset bytes/guards/return differ')
        return dict(destination=destination,length=length,fill=fill,instructions=self.steps,copy_store_counts=self.copy_store_counts,bytes_sha256=hashlib.sha256(actual).hexdigest())


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists() or not out.is_relative_to(BASE):raise ValueError('Fresh scoped output required')
    out.mkdir(parents=True)
    results=[Machine(alignment,length,fill).run() for alignment in range(16) for length in [0,1,7,8,15,16,17,31,32,33,48,240,448] for fill in [0,0xAB,0x1AB]]
    (out/'results.json').write_text(json.dumps(results,indent=2)+'\n',encoding='utf-8',newline='\n')
    receipt=dict(schema=1,status='complete original memset matches authored full-byte/guard results',cases=len(results),instructions=sum(r['instructions'] for r in results),body_sha256=DIGEST,source_sha256={str(p.relative_to(ROOT)):sha(p) for p in [Path(__file__),ROOT/'tools/native_reconstruction/ee_copy_store_oracle.py',ROOT/'tools/native_reconstruction/test_ee_copy_store_oracle.py',ROOT/'tools/native_reconstruction/movie_position_oracle.py',ROOT/'tools/native_reconstruction/ee_mac_oracle.py',ROOT/'tools/native_reconstruction/sjuni_oracle.py']},results_sha256=sha(out/'results.json'),game_run=False,device_opened=False)
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8',newline='\n');print(json.dumps(dict(status=receipt['status'],cases=len(results),instructions=receipt['instructions'],receipt_sha256=sha(out/'receipt.json'))))


if __name__=='__main__':main()
