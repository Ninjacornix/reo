#!/usr/bin/env python3
"""Verify original loader words and inspect source-derived packed bank spans.

Read-only owned ELF/ISO. Writes metadata, never extracts payloads or executes
original instructions, a runtime, an audio provider, or a decoder.
"""
import argparse
import hashlib
import importlib.util
import json
from pathlib import Path
import re
import struct

ROOT=Path(__file__).resolve().parents[3]
INVENTORY=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1'
INVENTORY_RECEIPT='765b03bca36fa7a3c78f57f8bf73bb72f0790d504dd14054e304dff29d570d23'
ELF_HASH='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
SDK=ROOT/'build-native-sjuni/dependency-gs-sound-profile-reapply-v4'
SDK_RECEIPT=ROOT/'build-native-sjuni/dependency-gs-sound-profile-reapply-v4-receipt.json'
SDK_HASH='909917fc2f766c8a43a10abbc0b94189fa24254ecfaa7f710e4eb24dc941b58a'
FUNCTIONS=[(0x1D3DC0,0x1D3E90),(0x1AB050,0x1AB2D0),(0x1AB310,0x1AB330),
           (0x1AC730,0x1AC7F0),(0x1ACFB0,0x1AD150),(0x1A7900,0x1A7A80),
           (0x1A77D0,0x1A7900),(0x1A85A0,0x1A8970),(0x1A7DE0,0x1A7F50),
           (0x1A82B0,0x1A8450),(0x1A8500,0x1A85A0),
           (0x1AD220,0x1AD410),(0x1AD410,0x1AD4B0),(0x1AD4E0,0x1AD5C0),
           (0x1B8380,0x1B86C0),(0x1BE6D0,0x1BF510)]


def sha(path):
    with path.open('rb')as stream:return hashlib.file_digest(stream,'sha256').hexdigest()


def write(path,value):path.write_text(json.dumps(value,indent=2)+'\n',encoding='utf-8',newline='\n')


class Elf:
    def __init__(self,path):
        self.data=path.read_bytes()
        if hashlib.sha256(self.data).hexdigest()!=ELF_HASH:raise ValueError('Owned ELF identity mismatch')
        if self.data[:6]!=b'\x7fELF\x01\x01':raise ValueError('Expected little-endian ELF32')
        at=struct.unpack_from('<I',self.data,28)[0];size,count=struct.unpack_from('<HH',self.data,42)
        self.loads=[]
        for index in range(count):
            row=struct.unpack_from('<8I',self.data,at+index*size)
            if row[0]==1:self.loads.append((row[2],row[1],row[4]))
    def read(self,address,size):
        for base,offset,length in self.loads:
            if base<=address and size<=length-(address-base):return self.data[offset+address-base:offset+address-base+size]
        raise ValueError('ELF address not wholly file-backed '+hex(address))
    def word(self,address):return struct.unpack('<I',self.read(address,4))[0]


def verify_words(elf,start,end):
    path=ROOT/('recomp/config/output/sub_%08X_0x%x.cpp'%(start,start))
    text=path.read_text(encoding='utf-8');words={}
    for at,value in re.findall(r'// (0x[0-9a-fA-F]+): (0x[0-9a-fA-F]+) ',text):
        at,value=int(at,16),int(value,16)
        if start<=at<end:
            if at in words and words[at]!=value:raise ValueError('Contradicting generated comment')
            if elf.word(at)!=value:raise ValueError('Generated instruction differs from owned ELF '+hex(at))
            words[at]=value
    missing=[hex(at)for at in range(start,end,4)if at not in words and elf.word(at)]
    if missing:raise ValueError('Nonzero original words outside selected generated interval '+str(missing))
    return dict(start=hex(start),end_exclusive=hex(end),source=path.relative_to(ROOT).as_posix(),
                source_sha256=sha(path),range_sha256=hashlib.sha256(elf.read(start,end-start)).hexdigest(),
                checked_comment_words=len(words),nonzero_words_without_comment=missing)


def checked_parts(words,size):
    """Literal little-endian wrapper pairs consumed by original1ACFB0."""
    parts={}
    for name,index in [('hd',2),('bd',4),('tq',6),('tsb',8)]:
        offset,length=words[index:index+2]
        if offset>size or length>size-offset:return None
        parts[name]=dict(offset=offset,bytes=length,rounded_transfer_bytes=(length+15)&~15)
    return parts


def normalized(name):return re.sub(r'[\\/.\-]','_',name.upper())


def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args();out=args.output.resolve()
    if out.exists()or not out.is_relative_to(ROOT/'build-native-sjuni/bank-resource-map'):raise ValueError('Fresh private metadata output required')
    if sha(INVENTORY/'receipt.json')!=INVENTORY_RECEIPT or sha(SDK_RECEIPT)!=SDK_HASH:raise ValueError('Evidence receipt drift')
    old=json.loads((INVENTORY/'receipt.json').read_bytes());sdk=json.loads(SDK_RECEIPT.read_bytes())
    for n,d in old['output_sha256'].items():
        if sha(INVENTORY/n)!=d:raise ValueError('Inventory drift')
    spec=importlib.util.spec_from_file_location('owned_inventory',ROOT/'tools/native_reconstruction/audio_asset_inventory/inventory.py')
    inv=importlib.util.module_from_spec(spec);spec.loader.exec_module(inv)
    if sha(Path(inv.__file__))!=old['inventory_tool_sha256']:raise ValueError('Reviewed inventory helper drift')
    source=Path(json.loads((INVENTORY/'read_plan.json').read_bytes())['source']['path'])
    before=source.stat();plan=json.loads((INVENTORY/'read_plan.json').read_bytes())
    if (before.st_size,before.st_mtime_ns)!=(plan['source']['bytes'],plan['source']['mtime_ns']):raise ValueError('Owned ISO identity metadata changed')
    elf=Elf(ROOT/'game_data/SLUS_207.65');out.mkdir(parents=True)
    functions=[verify_words(elf,start,end)for start,end in FUNCTIONS]
    source_inputs={p['source']:p['source_sha256']for p in functions}
    for n in ['ps2xRuntime/src/lib/Kernel/Syscalls/RPC.cpp','ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/ReoSoundBanks.cpp','ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/CriAudio.cpp','ps2xRuntime/include/runtime/ps2_iop.h']:
        if sha(SDK/n)!=sdk['source_sha256'][n]:raise ValueError('Actual127 source drift')
        source_inputs[str((SDK/n).relative_to(ROOT))]=sha(SDK/n)
    for n in ['recomp/overrides/reo_override.cpp','recomp/overrides/native_cd_owner/runtime_adapter.cpp','recomp/config/outbreak.toml','recomp/overrides/native_banks/v3/packet_adapter.cpp','game/native/audio_banks/v2/algorithms.cpp']:
        source_inputs[n]=sha(ROOT/n)
    rows=json.loads((INVENTORY/'members.json').read_bytes());archives=json.loads((INVENTORY/'archives.json').read_bytes())
    sound=next(row for row in archives if row['member']=='NETBIO01.DAT/0')
    if sound['entry_count']!=422:raise ValueError('Original lookup table/archive count mismatch')
    lookup=[]
    for index in range(422):
        pointer=elf.word(0x2337C0+index*4);raw=[]
        for n in range(256):
            byte=elf.read(pointer+n,1)[0]
            if not byte:break
            raw.append(byte^255)
        else:raise ValueError('Unbounded original complemented name')
        lookup.append(bytes(raw).decode('ascii'))
    members={r['member']:r for r in [*rows,*archives]}
    lookup_mismatch=[index for index,value in enumerate(lookup)if normalized(members['NETBIO01.DAT/0/'+str(index)]['names'][-1])!=value]
    found=[];lookup_resources=[];momo_count=0
    with source.open('rb')as stream:
        for row in rows:
            if row['bytes']<40:continue
            prefix=inv.read_at(stream,row['iso_offset'],40,before.st_size)
            if prefix[:4]!=b'MOMO':continue
            momo_count+=1;words=struct.unpack('<10I',prefix);parts=checked_parts(words,row['bytes'])
            record=dict(member=row['member'],names=row['names'],bytes=row['bytes'],iso_offset=row['iso_offset'],
                        member_sha256=row['sha256'],wrapper_version=words[1],parts=parts,status='unqualified_wrapper')
            if inv.extent_digest(stream,row['iso_offset'],row['bytes'],before.st_size)!=row['sha256']:raise ValueError('Owned candidate payload changed')
            if parts is not None:
                for name,part in parts.items():
                    part['iso_offset']=row['iso_offset']+part['offset']
                    part['sha256']=inv.extent_digest(stream,part['iso_offset'],part['bytes'],before.st_size)
                    part['within_2MiB_limit']=part['rounded_transfer_bytes']<=2*1024*1024
                    part['inside_member_after_transfer_rounding']=part['rounded_transfer_bytes']<=row['bytes']-part['offset']
                hd=parts['hd'];header=inv.read_at(stream,hd['iso_offset'],min(hd['bytes'],2*1024*1024),before.st_size)
                record['hd_structure']=inv.bank_hd_metadata(header,hd['bytes'])
                if record['hd_structure'] and record['hd_structure']['recognition']=='hsyn_hd_structural_header':
                    vagi=record['hd_structure']['chunk_offsets'][3]
                    highest=struct.unpack_from('<I',header,vagi+12)[0]
                    record['vagi_highest_index']=highest
                    record['vagi_table_fits']=vagi+16+4*(highest+1)<=len(header)
                    record['vagi_index_profile']=highest<=4095
                tq=parts['tq'];record['tq_table_count']=None
                if tq['bytes']>=16:
                    record['tq_table_count']=struct.unpack_from('<H',inv.read_at(stream,tq['iso_offset'],16,before.st_size),14)[0]
                    record['tq_offset_table_fits']=record['tq_table_count']<=(tq['bytes']-16)//4
                record['status']='source_paired_structural_bank' if record['hd_structure'] and record['hd_structure']['recognition']=='hsyn_hd_structural_header' and record.get('tq_offset_table_fits') and parts['bd']['bytes'] else 'source_paired_parts_require_more_validation'
            match=re.fullmatch(r'NETBIO01\.DAT/0/(\d+)',row['member'])
            if match:
                index=int(match[1]);record['original_lookup_index']=index;record['original_normalized_name']=lookup[index]
                record['lookup_name_matches']=index not in lookup_mismatch
            found.append(record)
        complete_keys={row['member']for row in found if row['status']=='source_paired_structural_bank'}
        for index,name in enumerate(lookup):
            if not name.endswith('_SND'):continue
            member='NETBIO01.DAT/0/'+str(index);row=members[member]
            header=inv.read_at(stream,row['iso_offset'],min(40,row['bytes']),before.st_size)
            lookup_resources.append(dict(member=member,original_lookup_index=index,original_normalized_name=name,
                                         names=row['names'],bytes=row['bytes'],sha256=row['sha256'],
                                         complete_structural_tuple=member in complete_keys,
                                         first_ten_little_endian_words=list(struct.unpack('<10I',header))if len(header)==40 else None))
    after=source.stat()
    if (before.st_size,before.st_mtime_ns)!=(after.st_size,after.st_mtime_ns):raise ValueError('ISO changed during bounded reads')
    source_postcheck=[n for n,d in source_inputs.items()if sha(ROOT/n)!=d]
    if source_postcheck:raise ValueError('Source changed during mapping')
    qualified=[r for r in found if r['status']=='source_paired_structural_bank']
    summary=dict(momo_wrappers=momo_count,structural_source_paired_banks=len(qualified),other_wrappers=len(found)-len(qualified),
                 original_lookup_entries=422,original_lookup_name_mismatches=lookup_mismatch,
                 qualified_bank_lookup_mismatches=[r['member']for r in qualified if not r.get('lookup_name_matches',False)],
                 source_named_bank_lookup_count=len(lookup_resources),
                 source_named_bank_unqualified=[r['member']for r in lookup_resources if not r['complete_structural_tuple']],
                 structurally_paired_partial_hd_bd=[r['member']for r in found if r['parts'] and r.get('hd_structure') and r['hd_structure']['recognition']=='hsyn_hd_structural_header' and not r['parts']['tq']['bytes'] and not r['parts']['tsb']['bytes']],
                 maxima={name:max((r['parts'][name]['bytes']for r in qualified),default=0)for name in ['hd','bd','tq','tsb']},
                 complete_bank_vagi_highest_index=max((r['vagi_highest_index']for r in qualified),default=0),
                 complete_bank_metadata_table_failures=[r['member']for r in qualified if not(r['vagi_table_fits']and r['vagi_index_profile'])],
                 rounded_part_limit_failures=[r['member']for r in qualified if any(not r['parts'][n]['within_2MiB_limit']for n in ['hd','bd','tq'])],
                 rounded_extent_failures=[r['member']for r in qualified if any(not r['parts'][n]['inside_member_after_transfer_rounding']for n in ['hd','bd','tq'])],
                 native_bank_decode_executed=False,merged_enemy_bank_bounds_proved=False,actual_submission_observed=False)
    write(out/'functions.json',functions);write(out/'packed_banks.json',found);write(out/'lookup_resources.json',lookup_resources);write(out/'summary.json',summary)
    receipt=dict(schema=1,status='passed',elf_sha256=ELF_HASH,prior_iso_sha256=old['iso_sha256'],
                 inventory_receipt_sha256=INVENTORY_RECEIPT,full127_receipt_sha256=SDK_HASH,
                 source_sha256=source_inputs,tool_sha256=sha(Path(__file__)),source_postcheck=source_postcheck,
                 outputs={n:sha(out/n)for n in ['functions.json','packed_banks.json','lookup_resources.json','summary.json']},
                 game_run=False,device_opened=False,instructions_executed=False,payloads_extracted=False,
                 limitations=['No running Ghidra instance; original words checked directly against file-backed owned ELF',
                              'Prior whole ISO hash plus unchanged source metadata and current candidate full hashes; no hostile-writer exclusion',
                              'Only MOMO wrappers with literal source-derived in-member pairs inspected; no decompression/carving',
                              'Part identification is static byte/loader correspondence, not observed runtime use or decoder/budget admission'])
    write(out/'receipt.json',receipt);print(json.dumps({n:summary[n]for n in ['momo_wrappers','structural_source_paired_banks','source_named_bank_lookup_count','source_named_bank_unqualified','maxima','rounded_part_limit_failures','rounded_extent_failures']},indent=2))


if __name__=='__main__':main()
