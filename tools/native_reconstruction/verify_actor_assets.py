"""Verify owned actor catalogue reads, native skeletons and model ownership."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT / 'tools/assets'))
from afs_inspect import read_toc
from audit_retail_effect_descriptors import elf_reader
from verify_gameplay_collision import COMPILERS


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def skeleton_nodes(payload):
    offset,length = struct.unpack_from('<II',payload,0x24)
    if not offset:
        return 0
    assert 0 < length <= len(payload)-offset
    raw = payload[offset:offset+length]
    count,extent = struct.unpack_from('<II',raw,4)
    assert 12 <= extent <= len(raw)
    at = 12
    roots = []
    links = []
    for _ in range(count):
        kind,entries,size = struct.unpack_from('<III',raw,at)
        assert size >= 12 and at+size <= extent
        if kind & 255:
            assert size >= 84
            links.append(struct.unpack_from('<ii',raw,at+20))
        else:
            assert not roots and 4*entries <= size-12
            roots = list(struct.unpack_from('<'+str(entries)+'I',raw,at+12))
        at += size
    assert at == extent and roots
    reached = set()
    pending = [roots[0]]
    while pending:
        node = pending.pop()
        assert 0 <= node < len(links) and node not in reached
        reached.add(node)
        pending.extend(child for child in links[node] if child != -1)
    assert reached == set(range(min(reached),min(reached)+len(reached)))
    return len(reached)


def owned_manifest(data,output):
    image = ROOT / 'game_data/SLUS_207.65'
    overlay = ROOT / 'build-function-index/owned-overlays/o0.bin'
    assert sha(image) == '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    assert sha(overlay) == 'bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2'
    read = elf_reader(image.read_bytes())
    zero = overlay.read_bytes()
    archive = data / 'NETBIO00.DAT'
    lines,records = [],[]
    with archive.open('rb') as source:
        outer = read_toc(source,0)
        indices = [index for index,row in enumerate(outer[2]) if row[0].lower() == 'romdata_usa.afs']
        assert len(indices) == 1
        base = outer[0][indices[0]][0]
        common = read_toc(source,base)
        members = {}
        for index,row in enumerate(common[2]):
            if row[0]:
                key = row[0].lower()
                members.setdefault(key,[]).append(common[0][index])
        for bank,(directory,names_address,names_count) in enumerate([(0x387e90,0x236310,156),(0x3887f0,0x236580,30)]):
            roots = [struct.unpack_from('<II',zero,directory-0x370000+8*index) for index in range(62)]
            pointers = sorted({pointer for pointer,count in roots if pointer}|{directory})
            names = struct.unpack('<'+str(names_count)+'I',read(names_address,4*names_count))
            for kind,(pointer,declared) in enumerate(roots):
                if not pointer:
                    assert not declared
                    continue
                entries = max((pointers[pointers.index(pointer)+1]-pointer)//16,max(count for at,count in roots if at == pointer))
                for variant in range(entries):
                    identity = zero[pointer-0x370000+16*variant]
                    if identity == 255:
                        lines.append(f'{bank} {kind} {variant} - 0 0 0')
                        continue
                    assert identity < len(names) and names[identity]
                    path = read(names[identity],128).split(b'\0')[0]
                    name = path.rsplit(b'\\',1)[1].decode('ascii')+'.NBD'
                    if name.lower() not in members:
                        lines.append(f'{bank} {kind} {variant} {name} 0 0 0')
                        records.append(dict(bank=bank,type=kind,variant=variant,name=name,status='missing'))
                        continue
                    assert len(members[name.lower()]) == 1,name
                    offset,size = members[name.lower()][0]
                    source.seek(base+offset)
                    payload = source.read(size)
                    assert len(payload) == size
                    nodes = skeleton_nodes(payload)
                    lines.append(f'{bank} {kind} {variant} {name} {base+offset} {size} {nodes}')
                    records.append(dict(bank=bank,type=kind,variant=variant,name=name,offset=base+offset,
                                        bytes=size,sha256=hashlib.sha256(payload).hexdigest(),nodes=nodes,status='present'))
    manifest = output / 'owned-models.txt'
    manifest.write_text('\n'.join(lines)+'\n',encoding='utf-8')
    return archive,manifest,records


def main(args):
    output = args.output.resolve()
    assert not output.exists() and output.is_relative_to(ROOT / 'build-native-sjuni')
    output.mkdir(parents=True)
    compiler = COMPILERS[args.compiler]
    build = args.build.resolve()
    configured = re.search(r'^CMAKE_CXX_COMPILER:[^=]+=([^\n]+)',(build / 'CMakeCache.txt').read_text(),re.M)[1]
    assert Path(configured.strip()).resolve() == compiler.resolve()
    sys.path.insert(0,str(ROOT / 'tools/native_reconstruction/gameplay_scenario'))
    from qualify_actor_asset_names import generate as actor_names, OUTPUT as names_output
    from qualify_enemy_initialization_profiles import generate as model_profiles, MODELS, PRIORITIES
    assert names_output.read_text() == actor_names()
    assert all(path.read_text() == expected for path,expected in zip((MODELS,PRIORITIES),model_profiles()))
    sources = [path for path in (ROOT / 'game/native').rglob('*')
               if path.is_file() and (path.suffix in ('.cpp','.hpp','.h','.inc') or path.name == 'CMakeLists.txt')]
    sources += [ROOT / 'runtime/assets/virtual_afs.h',Path(__file__),
                ROOT / 'tools/native_reconstruction/gameplay_scenario/qualify_actor_asset_names.py',
                ROOT / 'tools/native_reconstruction/gameplay_scenario/qualify_enemy_initialization_profiles.py',
                ROOT / 'tools/assets/afs_inspect.py',
                ROOT / 'tools/native_reconstruction/audit_retail_effect_descriptors.py',
                ROOT / 'tools/native_reconstruction/verify_gameplay_collision.py']
    before = {path.relative_to(ROOT).as_posix():sha(path) for path in sources}
    for name in before:
        target = output / 'source' / name
        target.parent.mkdir(parents=True,exist_ok=True)
        target.write_bytes((ROOT / name).read_bytes())
    archive,manifest,models = owned_manifest(args.data_root,output)
    stamp = (archive.stat().st_size,archive.stat().st_mtime_ns)
    env = dict(os.environ)
    env['PATH'] = str(compiler.parent)+os.pathsep+env.get('PATH','')
    binary = build / 'gameplay_world/gameplay_actor_assets_tests.exe'
    commands = [('build',[str(args.cmake),'--build',str(build),'--parallel','2','--target','gameplay_actor_assets_tests']),
                ('test',[str(binary),str(archive),str(manifest)])]
    record = dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(compiler),
                  game_launched=False,installed_in_game=False,stage4_complete=False,models=models,commands=[],
                  owned_images={str(path.relative_to(ROOT)):sha(path) for path in
                                (ROOT / 'game_data/SLUS_207.65',ROOT / 'build-function-index/owned-overlays/o0.bin')})
    try:
        for label,command in commands:
            result = subprocess.run(command,env=env,capture_output=True,timeout=180)
            (output / (label+'.stdout.txt')).write_bytes(result.stdout)
            (output / (label+'.stderr.txt')).write_bytes(result.stderr)
            record['commands'].append(dict(command=command,exit_code=result.returncode))
            assert result.returncode == 0,label+' '+result.stderr.decode(errors='replace')[-3000:]
            if label == 'test':
                record['observed'] = json.loads(result.stdout)
        assert all(sha(ROOT / name) == digest for name,digest in before.items())
        assert (archive.stat().st_size,archive.stat().st_mtime_ns) == stamp
        record.update(status='passed',source_unchanged=True,binary_sha256=sha(binary))
    finally:
        record['output_sha256'] = {path.name:sha(path) for path in output.iterdir() if path.is_file()}
        (output / 'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
    print(json.dumps(dict(status=record['status'],observed=record['observed'])))


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--compiler',choices=COMPILERS,required=True)
    parser.add_argument('--build',type=Path,required=True)
    parser.add_argument('--cmake',type=Path,required=True)
    parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--data-root',type=Path,required=True)
    main(parser.parse_args())
