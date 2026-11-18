"""Read the five NPC members against the retained import and asset identities."""
import hashlib
import json
import os
import struct
from pathlib import Path

ROOT=Path(__file__).resolve().parents[3]
INDEX=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1'


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def read_owned_actor_content(suffix,count):
    receipt=json.loads((INDEX/'receipt.json').read_bytes())
    assert receipt['status']=='passed'
    for name,expected in receipt['output_sha256'].items():
        assert digest(INDEX/name)==expected
    data=Path(os.environ['LOCALAPPDATA'])/'OutbreakRecomp/launcher/imports/file1/25e64b631bbaa0cac9a4822cb66174ff14c3531851d1e502c0a06704379bf446/data'
    imported=json.loads((data.parent/'import.json').read_bytes())
    assert imported['ElfSha256']=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    files={entry['Name']:entry for entry in imported['Files']}
    containers={entry['path']:entry for entry in json.loads((INDEX/'containers.json').read_bytes())}
    assets={entry['path']:entry for entry in json.loads((data.parent/'assets.json').read_bytes())['entries']}
    selected=[entry for entry in json.loads((INDEX/'members.json').read_bytes())
              if entry['names'] and entry['names'][-1].lower().endswith(suffix)]
    assert len(selected)==count
    records=[]
    for entry in selected:
        archive=data/entry['container']
        offset=entry['iso_offset']-containers[entry['container']]['offset']
        asset=assets[entry['member']]
        assert files[entry['container']]['Sha256']==entry['container_sha256']
        assert archive.stat().st_size==containers[entry['container']]['bytes']
        assert asset['offset']==offset and asset['size']==entry['bytes']
        assert asset['name'].lower()==entry['names'][-1].lower() and not asset['isArchive']
        before=archive.stat()
        with archive.open('rb') as source:
            source.seek(offset)
            payload=source.read(entry['bytes'])
        after=archive.stat()
        assert (before.st_size,before.st_mtime_ns)==(after.st_size,after.st_mtime_ns)
        assert hashlib.sha256(payload).hexdigest()==entry['sha256']
        records.append(dict(name=entry['names'][-1],archive=str(archive),archive_offset=offset,
                            bytes=len(payload),sha256=entry['sha256'],payload=payload))
    return records


def read_owned_npcs():
    return read_owned_actor_content('.npc',5)


def write_fixture(output):
    records=read_owned_npcs()
    lines=[]
    for index,entry in enumerate(records):
        payload=entry.pop('payload')
        lines.append('const std::array<std::uint8_t,'+str(len(payload))+'> owned_npc_'+str(index)+
                     '{'+','.join(str(byte) for byte in payload)+'};')
    lines.append('const std::array<std::span<const std::byte>,5> owned_npc_inputs{'+
                 ','.join('std::as_bytes(std::span(owned_npc_'+str(index)+'))' for index in range(5))+'};')
    (output/'owned_npc_fixtures.inc').write_text('\n'.join(lines)+'\n')
    return records


def write_enemy_fixture(output):
    records=read_owned_actor_content('.emd',10)
    with (output/'owned_enemy_members.bin').open('wb') as target:
        target.write(struct.pack('<I',len(records)))
        for entry in records:
            payload=entry.pop('payload')
            name=entry['name']
            offline=name.startswith('sgl_')
            scenario=int(name[5:8] if offline else name[1:4])
            target.write(struct.pack('<III',scenario,int(offline),len(payload)))
            target.write(payload)
    return records
