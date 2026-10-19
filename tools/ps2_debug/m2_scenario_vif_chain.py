"""Read-only reconstruction of an original VIF1 DMA chain from an EE RAM dump.

Snapshots can be taken during a synchronous DMA call. This tool records original
commands and MPG bytes, not VU execution or inferred successful rendering.
"""
import argparse
import hashlib
import json
import struct
from pathlib import Path


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('ram',type=Path)
    p.add_argument('--packet',type=lambda x:int(x,0))
    p.add_argument('--chcr',type=lambda x:int(x,0),default=0x1C5)
    p.add_argument('--out',type=Path,required=True)
    args=p.parse_args();ram=args.ram.read_bytes()
    if len(ram)!=32*1024*1024:raise ValueError('Expected complete EE32MiB snapshot')
    def read(address,size):
        # Never treat VU or scratchpad as masked main RAM.
        address &= 0x1FFFFFFF
        if address+size>len(ram):raise ValueError(f'Non-EE source {address:X}+{size:X}')
        return ram[address:address+size]
    def word(address):return struct.unpack('<I',read(address,4))[0]
    address=args.packet if args.packet is not None else word(0x29F71C)&0x0FFFFFFF
    initial=address;tags=[];stack=[];stream=bytearray()
    for n in range(4096):
        raw=read(address,16);lo,hi=struct.unpack('<QQ',raw)
        qwc=lo&0xFFFF;kind=(lo>>28)&7;irq=bool(lo>>31&1);target=(lo>>32)&0x7FFFFFFF
        payload=address+16 if kind in (1,2,5,6,7) else target
        if args.chcr&0x40:stream.extend(raw[8:])
        stream.extend(read(payload,qwc*16))
        tags.append({'address':address,'kind':kind,'qwc':qwc,'irq':irq,'target':target,
                     'upper_vif_words':list(struct.unpack('<II',raw[8:])),'stream_end':len(stream)})
        if kind in (0,7) or irq and args.chcr&0x80:break
        if kind in (1,):address=address+16+qwc*16
        elif kind in (3,4):address+=16
        elif kind==2:address=target
        elif kind==5:
            if len(stack)==2:raise ValueError('DMAC CALL stack overflow')
            stack.append(address+16+qwc*16);address=target
        elif kind==6:
            if not stack:break
            address=stack.pop()
        else:raise ValueError('Unrecognized chain tag')
    else:raise ValueError('Chain exceeded original bounded tag count')
    args.out.mkdir(parents=True,exist_ok=True)
    (args.out/'vif-stream.bin').write_bytes(stream)
    commands=[];pos=0;cl=wl=1
    names={0:'NOP',1:'STCYCL',2:'OFFSET',3:'BASE',4:'ITOP',5:'STMOD',6:'MSKPATH3',7:'MARK',
           0x10:'FLUSHE',0x11:'FLUSH',0x13:'FLUSHA',0x14:'MSCAL',0x15:'MSCALF',0x17:'MSCNT',
           0x20:'STMASK',0x30:'STROW',0x31:'STCOL',0x4A:'MPG',0x50:'DIRECT',0x51:'DIRECTHL'}
    while pos+4<=len(stream):
        start=pos;code=struct.unpack_from('<I',stream,pos)[0];pos+=4
        op=code>>24&0x7F;num=code>>16&255;imm=code&0xFFFF;count=num or 256
        payload=0;entry={'offset':start,'word':code,'opcode':op,'name':names.get(op,'UNPACK' if op>=0x60 else 'UNKNOWN'),'num':num,'imm':imm}
        if op==1:cl=imm&255 or 256;wl=imm>>8 or 256
        elif op==0x20:payload=4
        elif op in (0x30,0x31):payload=16
        elif op==0x4A:
            payload=count*8;entry['vu_code_byte_address']=imm*8
            if pos+payload<=len(stream):
                codebytes=stream[pos:pos+payload];entry['payload_sha256']=hashlib.sha256(codebytes).hexdigest()
                (args.out/f'mpg-{start:06x}-vu-{imm*8:04x}.bin').write_bytes(codebytes)
        elif op in (0x50,0x51):payload=(imm or 65536)*16
        elif op>=0x60:
            vn=(op>>2)&3;vl=op&3;components=vn+1
            bits=16 if vn==3 and vl==3 else components*{0:32,1:16,2:8,3:16}[vl]
            source=count if cl>=wl else count//wl*cl+min(count%wl,cl)
            payload=(source*((bits+7)//8)+3)&~3
        elif op not in names:
            commands.append(entry);entry['error']='Unknown VIF opcode; parsing stops';break
        if op!=0:commands.append(entry)
        entry['payload_size']=payload
        if pos+payload>len(stream):entry['error']='Truncated payload';break
        pos+=payload
    report={'snapshot':str(args.ram),'snapshot_sha256':hashlib.sha256(ram).hexdigest(),
            'packet':initial,'assumed_chcr':args.chcr,'channel':word(0x29F6F0),
            'stream_size':len(stream),'stream_sha256':hashlib.sha256(stream).hexdigest(),
            'parsed_end':pos,'tags':tags,'commands':commands}
    (args.out/'report.json').write_text(json.dumps(report,indent=2))
    print(f'packet=0x{initial:X} tags={len(tags)} bytes={len(stream)} parsed={pos} commands={len(commands)}')
    interesting=[entry for entry in commands if entry['opcode'] in (2,3,4,0x14,0x15,0x17,0x4A) or 'error' in entry]
    for entry in interesting[:16]:print(entry)
    if len(interesting)>16:print(f'{len(interesting)-16} additional setup/dispatch commands retained in report.json')


if __name__=='__main__':main()
