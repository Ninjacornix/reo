#!/usr/bin/env python3
"""Original AFS sector-table parsing, resolution and deferred range/open words.

External header-read/status, string library and backend open/size are explicit
inputs. No native implementation, file payload or game process is used.
"""
import argparse
import collections
import csv
import hashlib
import json
from pathlib import Path
import re
import struct
from adx_window_oracle import Machine as Runner, ObservedMemory
from adxt_refill_oracle import BODIES as REFILL_BODIES
from sjuni_oracle import Elf, OracleError, MASK32, sext32

ROOT = Path(__file__).resolve().parents[2]
SCOPE = ROOT / 'build-native-sjuni/afs-source-range'
META = ROOT / 'build-native-sjuni/audio-asset-inventory/file1-v1'
IDENTITIES = {'members.json':'276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2'}
RANGES = {0x1284d0:0x1284f8,0x128b18:0x128f10,0x129d78:0x129df0,0x129e18:0x129f70,
          **{start:end for start,(end,_) in REFILL_BODIES.items()}}
DESCRIPTOR, HEADER, OUTPUT, RECORD = 0x600000,0x610000,0x620000,0x630000
PARTITIONS, LOADER = 0x20cd00,0x20d22c
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
encode = lambda value: (json.dumps(value,indent=2,sort_keys=True)+'\n').encode()


def audit():
    elf = Elf(ROOT/'game_data/SLUS_207.65'); result = []
    with (ROOT/'recomp/config/outbreak_ghidra_functions.csv').open() as stream:
        catalogue = [int(row['start'],16) for row in csv.DictReader(stream)]
    for start,end in RANGES.items():
        # Some audited refill intervals contain multiple entry points. Gather
        # only companions whose declared start is inside this exact interval.
        comments = {}; sources = {}
        for path in (ROOT/'recomp/config/output').glob(f'sub_{start:08X}_*.cpp'):
            raw = path.read_bytes(); sources[path.relative_to(ROOT).as_posix()] = hashlib.sha256(raw).hexdigest()
            comments.update({int(a,16):int(b,16) for a,b in re.findall(rb'//\s*0x([0-9a-fA-F]+):\s*0x([0-9a-fA-F]+)',raw)})
        # Public companions do not necessarily inline an entire refill block.
        if start in REFILL_BODIES:
            for address in catalogue:
                if start<=address<end:
                    path=ROOT/f'recomp/config/output/sub_{address:08X}_0x{address:x}.cpp'
                    raw=path.read_bytes();sources[path.relative_to(ROOT).as_posix()]=hashlib.sha256(raw).hexdigest()
                    comments.update({int(a,16):int(b,16)for a,b in re.findall(rb'//\s*0x([0-9a-fA-F]+):\s*0x([0-9a-fA-F]+)',raw)})
        matched=0;zeros=[]
        for pc in range(start,end,4):
            word=int.from_bytes(elf.read(pc,4),'little')
            if pc in comments:
                if word!=comments[pc]:raise OracleError('Source disagreement '+hex(pc))
                matched+=1
            elif word:raise OracleError('Missing nonzero word '+hex(pc))
            else:zeros.append(pc)
        result.append(dict(start=start,end=end,body_sha256=hashlib.sha256(elf.read(start,end-start)).hexdigest(),
                           sources=sources,matched_words=matched,omitted_zero_pcs=zeros))
    return dict(elf_sha256=elf.sha256,ranges=result)


def header(offsets,lengths):
    return b'AFS\0'+struct.pack('<I',len(lengths))+b''.join(struct.pack('<II',a,n)for a,n in zip(offsets,lengths,strict=True))


def cases():
    result=[]
    def add(name,lengths,mode=1,first=2048,**extra):
        cursor=first;offsets=[]
        for n in lengths:offsets.append(cursor);cursor+=(n+2047)//2048*2048
        result.append(dict(name=name,mode=mode,lengths=lengths,offsets=offsets,archive_bytes=cursor,
                           base_sector=7,parent_identity=31,**extra))
    for mode in (0,1):
        for count in (1,2,5,254,255,256,1000):
            add(f'synthetic-{mode}-{count}',[([0,1,2047,2048,2049][i%5])for i in range(count)],mode,first=((8+8*count+2047)//2048)*2048)
    for count in (0,1,2047,2048,2049,0xfffff):
        for total in (0,1,7):
            result.append(dict(name=f'open-{count}-{total}',kind='open',count=count,start=2,total=total))
    members=json.loads((META/'members.json').read_bytes());archives=json.loads((META/'archives.json').read_bytes())
    children=collections.defaultdict(list)
    for row in members+archives:
        if '/'in row['member']:children[row['member'].rsplit('/',1)[0]].append(row)
    for archive in archives:
        rows=sorted(children[archive['member']],key=lambda r:int(r['member'].rsplit('/',1)[1]))
        if len(rows)!=archive['entry_count']:raise OracleError('Incomplete indexed archive')
        result.append(dict(name='inventory-'+archive['member'].replace('/','-'),mode=1,
                           lengths=[r['bytes']for r in rows],offsets=[r['parent_relative_offset']for r in rows],
                           archive_bytes=archive['bytes'],base_sector=7,parent_identity=31))
    return result


class Machine(Runner):
    def __init__(self,case,authority):
        self.inputs=case;self.elf=Elf(ROOT/'game_data/SLUS_207.65');self.code={}
        for row in authority['ranges']:
            data=self.elf.read(row['start'],row['end']-row['start'])
            if hashlib.sha256(data).hexdigest()!=row['body_sha256']:raise OracleError('Original body drift')
            self.code.update({row['start']+i:struct.unpack_from('<I',data,i)[0]for i in range(0,len(data),4)})
        self.mem=ObservedMemory()
        for address,size,fill in [(0x20cd00,0x600,0),(DESCRIPTOR,0x5000,0),(HEADER,2048,0),
                                  (OUTPUT,0x200,0x5a),(RECORD,0x5c,0),(0x700000,0x2000,0xcc)]:self.mem.map(address,size,fill)
        self.mem.store(PARTITIONS,4,DESCRIPTOR);self.mem.store(0x20d234,4,0);self.mem.store(0x20d238,4,HEADER)
        self.mem.store(0x20d23c,4,1);self.mem.store(DESCRIPTOR+0xf,1,case.get('mode',1))
        self.mem.store(0x20d230,4,OUTPUT+0x180);self.mem.store(OUTPUT+0x181,1,3)
        self.mem.store(DESCRIPTOR+0x110,4,case.get('parent_identity',31));self.mem.store(DESCRIPTOR+0x114,4,case.get('base_sector',7))
        self.mem.store(DESCRIPTOR+0x10,0x100,int.from_bytes(b'container.bin\0'.ljust(0x100,b'\0'),'little'))
        self.table=header(case.get('offsets',[]),case.get('lengths',[]));self.read_offset=2048
        for i,b in enumerate(self.table[:2048]):self.mem.store(HEADER+i,1,b)
        self.retired=False;self.guard_depth=0;self.regs=[0]*32;self.all_visited=set();self.total_steps=0;self.setup=[]
        self.initialize_mac(hi=0x11111111,lo=0x22222222,hi1=0x33333333,lo1=0x44444444)

    def small(self):
        return dict(descriptor_hex=self.raw(DESCRIPTOR,0x140+4*len(self.inputs.get('lengths',[]))).hex(),
                    loader_hex=self.raw(LOADER,0x14).hex(),output_hex=self.raw(OUTPUT,0x120).hex(),
                    record_hex=self.raw(RECORD,0x5c).hex(),retired=self.retired)
    def snapshot(self):return self.small()

    def hook(self,pc):
        args=[x&MASK32 for x in self.regs[4:10]]
        event=dict(pc=pc,from_pc=self.from_pc,arguments_u32=args,write_index=len(self.mem.writes))
        if pc==0x129d48:self.regs[2]=3;event['kind']='external_header_read_status'
        elif pc==0x1297a0:
            event['kind']='external_header_read';count=args[1]*2048
            if count!=2048 or args[2]!=HEADER:raise OracleError('Unexpected header transfer')
            data=self.table[self.read_offset:self.read_offset+count].ljust(count,b'\0');self.read_offset+=count
            for i,b in enumerate(data):self.mem.store(HEADER+i,1,b)
            self.regs[2]=sext32(args[1])
        elif pc==0x128a60:self.retired=True;event['kind']='external_loader_cleanup'
        elif pc==0x107a18:
            event['kind']='bounded_signature_comparison'
            self.regs[2]=0 if self.raw(args[0],args[2])==b'AFS'else 1
        elif pc==0x10b5f8:
            event['kind']='bounded_strncpy'
            if args[2]!=256:raise OracleError('Unexpected path copy')
            for i,b in enumerate(self.raw(args[1],256)):self.mem.store(args[0]+i,1,b)
            self.regs[2]=sext32(args[0])
        elif pc in (0x1416d0,0x1416e8,0x1264e0,0x1264f8):event['kind']='external_guard';self.guard_depth+=1 if pc in (0x1416d0,0x1264e0) else -1
        elif pc==0x135930:self.regs[2]=0xffff80;event['kind']='external_file_open'
        elif pc==0x135d60:self.regs[2]=args[1];event['kind']='external_sector_seek'
        elif pc==0x135cf8:self.regs[2]=self.inputs['total'];event['kind']='external_file_sector_length'
        elif pc==0x135f50:self.regs[2]=0;event['kind']='external_file_idle_status'
        elif pc==0x1280d0:event['kind']='external_diagnostic'
        else:return False
        self.events.append(event);self.pc=self.regs[31]&MASK32;return True


def execute(case,authority):
    machine=Machine(case,authority);operations=[];ranges=[]
    if case.get('kind')=='open':
        # Pause blocks only the eventual data refill; the real configuration,
        # deferred open/seek/size/reset/start logic still runs.
        machine.mem.store(RECORD+0x40,1,1);machine.mem.store(RECORD+1,1,1)
        for entry,args in [(0x130478,[RECORD,DESCRIPTOR+0x10,31,case['start'],case['count']]),
                           (0x130658,[RECORD]),(0x130b78,[RECORD])]:
            row=machine.run(entry,args);operations.append(row)
            if row['failure']:break
        projection=dict(start_sector=machine.mem.load(RECORD+0xc,4),byte_length=machine.mem.load(RECORD+0x10,4),
                        open_requested=machine.mem.load(RECORD+0x41,1),opened=machine.mem.load(RECORD+0x45,1))
    else:
        for _ in range(20):
            row=machine.run(0x128b18,[0]);operations.append(row)
            if row['failure']or machine.retired:break
        if not operations[-1]['failure']and not machine.retired:raise OracleError('Parser did not reach cleanup')
        if not operations[-1]['failure']:
            for index in sorted({-1,0,len(case['lengths'])//2,len(case['lengths'])-1,len(case['lengths'])}):
                row=machine.run(0x129e18,[0,index,OUTPUT+0x10,OUTPUT,OUTPUT+4,OUTPUT+8]);operations.append(row)
                ranges.append(dict(index=index,result_u32=row['raw_v0_lower64_observation_only']&MASK32,
                                   parent=machine.mem.load(OUTPUT,4),start=machine.mem.load(OUTPUT+4,4),count=machine.mem.load(OUTPUT+8,4)))
                if row['failure']:break
        projection=dict(member_count=machine.mem.load(DESCRIPTOR+8,4),first_sector=machine.mem.load(DESCRIPTOR+0x118,4 if case['mode']==1 else 2),ranges=ranges)
    return dict(name=case['name'],projection=projection,operations=operations,instructions=machine.total_steps)


def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--freeze',action='store_true');parser.add_argument('--frozen',type=Path);parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args();out=args.output.resolve()
    if out.exists()or not out.is_relative_to(SCOPE):raise OracleError('Fresh scoped output required')
    if args.freeze:
        for name,digest in IDENTITIES.items():
            if sha(META/name)!=digest:raise OracleError('Pinned member inventory drift')
        authority=audit();inputs=cases();out.mkdir(parents=True);(out/'inputs.json').write_bytes(encode(inputs))
        manifest=dict(schema=1,authority=authority,inputs_sha256=sha(out/'inputs.json'),oracle_sha256=sha(Path(__file__)),
                      engines={n:sha(Path(__file__).with_name(n))for n in ['adx_window_oracle.py','adxt_refill_oracle.py','sjuni_oracle.py','sjrb_oracle.py','adx_stereo_oracle.py','ee_mac_oracle.py']},
                      metadata={n:sha(META/n)for n in ['members.json','archives.json']},
                      native_implementation_exists=(ROOT/'game/native/afs_source_range/afs_source_range.cpp').exists())
        (out/'manifest.json').write_bytes(encode(manifest));print('Frozen',len(inputs),'inputs');return
    if not args.frozen:raise OracleError('Frozen inputs required')
    manifest=json.loads((args.frozen/'manifest.json').read_bytes())
    if sha(args.frozen/'inputs.json')!=manifest['inputs_sha256']or sha(Path(__file__))!=manifest['oracle_sha256']or audit()!=manifest['authority']:raise OracleError('Frozen input/source drift')
    for n,d in manifest['engines'].items():
        if sha(Path(__file__).with_name(n))!=d:raise OracleError('Imported engine drift')
    out.mkdir(parents=True);rows=[]
    for case in json.loads((args.frozen/'inputs.json').read_bytes()):
        row=execute(case,manifest['authority']);(out/(case['name']+'.json')).write_bytes(encode(row));rows.append(dict(name=case['name'],sha256=sha(out/(case['name']+'.json')),instructions=row['instructions'],partials=[o['failure']for o in row['operations']if o['failure']]))
    receipt=dict(status='completed_original_observations',cases=rows,instructions=sum(r['instructions']for r in rows),
                 manifest_sha256=sha(args.frozen/'manifest.json'),source_postcheck=[]if audit()==manifest['authority']else['authority_changed'],
                 game_run=False,device_opened=False,limitations=['Header status/read/loader cleanup/string/backend open/size boundaries are declared hooks, not OS/file lifecycle proof'])
    (out/'receipt.json').write_bytes(encode(receipt));print(json.dumps(dict(cases=len(rows),instructions=receipt['instructions'],partial_cases=[r for r in rows if r['partials']])))


if __name__=='__main__':main()
