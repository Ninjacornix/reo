"""Audit actual1BA440 activation facts before adding a native archive owner."""
import argparse,hashlib,json,re,struct,sys
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools/assets'))
from afs_inspect import read_toc
sha=lambda data:hashlib.sha256(data).hexdigest()
def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--audio-archive',type=Path,required=True)
    parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args();assert not args.output.exists()
    elf=ROOT/'game_data/SLUS_207.65';raw=elf.read_bytes()
    assert sha(raw)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    read=elf_reader(raw);proof=[]
    for address in [0x1ba440,0x1ab450,0x1ab2f0,0x1ab050,0x1ba330,0x1ba250]:
        path=next((ROOT/'recomp/config/output').glob(f'sub_{address:08X}_*'))
        begin,end=[int(value,16)for value in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',path.read_text()).groups()]
        proof.append(compare_source('complete actor archive activation/lookup/reset/consumer body',path.relative_to(ROOT).as_posix(),begin,end,read))
    formats={hex(address):read(address,32).split(b'\0')[0].decode('ascii')for address in [0x250220,0x24fd10]}
    assert set(formats.values())=={'vo001%02d.afs'}
    pointers=struct.unpack('<422I',read(0x2337c0,422*4))
    names=[bytes(value^255 for value in read(pointer,128).split(b'\0')[0]).decode('ascii')for pointer in pointers]
    rows=[dict(character=character,lookup_index=401+character,normalized=names[401+character],filename=f'vo001{character:02}.afs',loaded_marker=character+1)for character in range(8)]
    assert all(row['normalized']==row['filename'].upper().replace('.','_')for row in rows)
    assert not any(f'VO001{character:02}_AFS'in names for character in range(8,256))
    inventory_path=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json';assert sha(inventory_path.read_bytes())=='276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2'
    inventory={row['member']:row for row in json.loads(inventory_path.read_bytes())}
    stamp=args.audio_archive.stat().st_size,args.audio_archive.stat().st_mtime_ns
    with args.audio_archive.open('rb')as source:
        outer=read_toc(source,0);assert outer[2][0][0].lower()=='adxsnd.afs';base=outer[0][0][0];audio=read_toc(source,base)
        for row in rows:
            ordinal=row['lookup_index'];offset,length=audio[0][ordinal]
            assert audio[2][ordinal][0].lower()==row['filename']
            archive_base=base+offset;voice=read_toc(source,archive_base)
            source.seek(archive_base);body=source.read(length);assert len(body)==length
            leaf_rows=[]
            for member,(member_offset,member_bytes)in enumerate(voice[0]):
                key=f'NETBIO01.DAT/0/{ordinal}/{member}';expected=inventory[key]
                source.seek(archive_base+member_offset);data=source.read(member_bytes)
                assert len(data)==member_bytes==expected['bytes']and sha(data)==expected['sha256']
                assert [name.lower()for name in expected['names']]==['adxsnd.afs',row['filename'],voice[2][member][0].lower()]
                leaf_rows.append(dict(member=member,bytes=member_bytes,sha256=expected['sha256']))
            row.update(offset=archive_base,bytes=length,archive_sha256=sha(body),members=len(voice[0]),verified_member_sha256=leaf_rows)
    assert stamp==(args.audio_archive.stat().st_size,args.audio_archive.stat().st_mtime_ns)
    result=dict(schema=1,status='static_source_and_owned_archive_audit',elf_sha256=sha(raw),source_sha256={Path(__file__).relative_to(ROOT).as_posix():sha(Path(__file__).read_bytes())},original_owned_bodies=proof,formats=formats,lookup_table=dict(address='0x2337c0',entries=422,pointer_bytes_sha256=sha(read(0x2337c0,422*4))),owned_inventory_sha256=sha(inventory_path.read_bytes()),archives=rows,findings=['1BA440 accepts ordinary slot0..4; >=5 is no-op. Negative direct slots are outside the finite caller profile.','1AB450 resolves the name then activates SDK archive slot5+ordinarySlot and polls until phase3. Native unavailable I/O must not be fabricated as known missing.','On successful activation1BA440 writes character+1, not lookupIndex+1; known absent names write0.','1BA330 clears five ordinary markers only.1BA250 uses actor.slot for category0 and separate marker index5 for other categories.','Archive metadata belongs to explicit NETBIO01/adxsnd capability, separate from NETBIO00 model/scenario source. Existing scene voice catalog archive0 is not a mutable loaded-slot owner.'],native_implemented=False,game_run=False,stage4_complete=False)
    args.output.parent.mkdir(parents=True,exist_ok=True);args.output.write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps(dict(status=result['status'],archives=len(rows),members=sum(row['members']for row in rows),audited_bodies=len(proof))))
if __name__=='__main__':main()
