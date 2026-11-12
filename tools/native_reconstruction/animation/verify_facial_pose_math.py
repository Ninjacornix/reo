"""Compare complete six-bank facial blending and scalar basis reconstruction."""
import argparse
import hashlib
import json
import math
import os
import re
import struct
import subprocess
import sys
from pathlib import Path

ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
sys.path.insert(0,str(ROOT/'tools/assets'))
from audit_retail_effect_descriptors import compare_source,elf_reader
from afs_inspect import read_toc
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser=argparse.ArgumentParser();parser.add_argument('--compiler',type=Path,required=True);parser.add_argument('--output',type=Path,required=True);args=parser.parse_args();out=args.output.resolve()
    assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
    image=ROOT/'game_data/SLUS_207.65';assert sha(image)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read_main=elf_reader(image.read_bytes())
    overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';bank=overlay.read_bytes();read=lambda at,n:read_main(at,n)if at<0x570000 else bank[at-0x570000:at-0x570000+n]
    entries={};proof=[]
    for address in [0x67c990,0x18fdf0,0x191500,0x1a5050,0x1a5180,0x1a51b0,0x1a5220]:
        owner='sub'if address<0x570000 else'o2';folder=ROOT/('recomp/config/output'if owner=='sub'else'recomp/config/output_ovl/o2');path=next(folder.glob(f'{owner}_{address:08X}_*'));name=path.relative_to(ROOT).as_posix();start,end=[int(value,16)for value in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',path.read_text()).groups()];proof.append(compare_source('complete facial blend, basis, scalar normalization/cross or matrix copy body',name,start,end,read));entries[address]=name
    initializer=next((ROOT/'recomp/config/output').glob('sub_00195E50_*'));start,end=[int(value,16)for value in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',initializer.read_text()).groups()];static=compare_source('static initialized identity-cache producer authority; bootstrap not executed',initializer.relative_to(ROOT).as_posix(),start,end,read)
    units=['game/native/animation/facial_pose_math.cpp','game/native/transform_math/transform_math.cpp'];files=set(units);pending=list(units)
    while pending:
        name=pending.pop()
        for relative in re.findall(r'^#include "([^"]+)"',(ROOT/name).read_text(),re.M):
            path=((ROOT/name).parent/relative).resolve();assert path.is_file()and path.is_relative_to(ROOT);key=path.relative_to(ROOT).as_posix()
            if key not in files:files.add(key);pending.append(key)
    fixture='tools/native_reconstruction/animation/facial_pose_math_tests.cpp';reference='tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp'
    files|={fixture,reference,Path(__file__).relative_to(ROOT).as_posix(),'tools/assets/afs_inspect.py',initializer.relative_to(ROOT).as_posix(),*entries.values()};before={name:sha(ROOT/name)for name in sorted(files)};out.mkdir()
    record=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(args.compiler),original_owned_bodies=proof,identity_initializer_static_authority=static,game_run=False,stage4_complete=False,limits=['Complete67C990/1A5050/1A5180/1A51B0/1A5220/18FDF0/191500 execute without arithmetic or copy ports. Initialized shared identity294E00 is seeded from the statically word-verified195E50 profile; complete bootstrap is not executed.','Finite consumed FP32 inputs/intermediates and nearest-rounding profile. Unconsumed matrix W/third-axis and preserved basis-translation words remain literal, including arbitrary bit patterns. Physical PS2 exceptional arithmetic is not established.','All18 default HP/HN3072-byte MAT payloads are paired with their actual base NBD skeletons. Each has six track4 nodes; only those consumed ordinals are admitted. HP03/HN39 contain nonfinite data in unused matrix ordinal6, which is retained as an explicit caller-boundary finding; this does not establish facial asset loading/workspace overlap, five-channel lip evaluation, instance lifetime, actual actor-model adoption or complete scene/game installation.'])
    try:
        for name in files:
            target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/name).read_bytes())
        (out/'reference.hpp').write_text((ROOT/reference).read_text()+'\n#define FPU_SQRT_S(value) std::sqrt(value)\n#define FPU_DIV_S(a,b) ((a)/(b))\n#define FPU_C_EQ_S(a,b) ((a)==(b))\n#define PS2_VOPMUL(a,b) _mm_mul_ps(_mm_shuffle_ps((a),(a),_MM_SHUFFLE(3,0,2,1)),_mm_shuffle_ps((b),(b),_MM_SHUFFLE(3,1,0,2)))\n')
        body='\n'.join((ROOT/name).read_text()for name in entries.values());actual={Path(name).stem for name in entries.values()};calls=set(re.findall(r'\b((?:sub|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual));decl+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for name in sorted(calls-actual));(out/'functions.h').write_text('#pragma once\n'+decl);(out/'original.cpp').write_text(body);(out/'original_dispatch.hpp').write_text(''.join('case '+hex(address)+':'+Path(name).stem+'(memory,context,runtime);return;\n'for address,name in entries.items()))
        for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
        for name in ['ps2_recompiled_functions.h','o2_functions.h']:(out/name).write_text('#pragma once\n#include "functions.h"\n')
        for name in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/name).write_text('#pragma once\n')
        prior=json.loads((ROOT/'build-native-sjuni/primary-scene-scope-llvm-v4/receipt.json').read_text());archive=Path(prior['commands'][2]['command'][1]);stamp=archive.stat().st_size,archive.stat().st_mtime_ns
        table=read_main(0x2322c0,1342*4);names=[bytes(value^255 for value in read_main(pointer,512).split(b'\0')[0]).decode('ascii')for pointer in struct.unpack('<1342I',table)];selected=[(index,name)for index,name in enumerate(names)if re.fullmatch(r'MOTION_FACE_(?:HP\d{2}|HN\d{2,3})_MAT',name)];assert len(selected)==18
        payloads=[];owned=[]
        with archive.open('rb')as source:
            root,_,root_names=read_toc(source,0);base,parent=next(entry for entry,(name,_)in zip(root,root_names)if name.lower()=='romdata_usa.afs');entries_afs,_,names_afs=read_toc(source,base);assert len(entries_afs)==1342
            for ordinal,key in selected:
                offset,length=entries_afs[ordinal];assert length==3072 and offset+4096<=parent;source.seek(base+offset);payload=source.read(length);assert len(payload)==length
                actor=key.removeprefix('MOTION_FACE_').removesuffix('_MAT');model_key=('COMMON_PL_'if actor.startswith('HP')else'COMMON_NPC_')+actor+'_NBD';model_ordinal=names.index(model_key);model_offset,model_length=entries_afs[model_ordinal];source.seek(base+model_offset);model=source.read(model_length);assert len(model)==model_length
                skeleton_offset,skeleton_bytes=struct.unpack_from('<II',model,0x24);assert skeleton_offset and skeleton_bytes<=len(model)-skeleton_offset;skeleton=model[skeleton_offset:skeleton_offset+skeleton_bytes];_,count,declared=struct.unpack_from('<III',skeleton);assert declared==len(skeleton)
                roots=[];nodes=[];at=12
                for _ in range(count):
                    kind,n,size=struct.unpack_from('<III',skeleton,at);assert size>=12 and size<=len(skeleton)-at
                    if kind&255:
                        assert size>=84;body=at+12;nodes.append(dict(child=struct.unpack_from('<i',skeleton,body+8)[0],sibling=struct.unpack_from('<i',skeleton,body+12)[0],track=struct.unpack_from('<I',skeleton,body+0x44)[0]&65535))
                    else:roots=list(struct.unpack_from('<'+'I'*n,skeleton,at+12))
                    at+=size
                assert at==len(skeleton)and roots==[0];reachable=[]
                def walk(index):
                    assert 0<=index<len(nodes)and index not in reachable;reachable.append(index)
                    for field in ['child','sibling']:
                        if nodes[index][field]!=-1:walk(nodes[index][field])
                walk(0);assert len(reachable)==len(nodes)
                facial=[index for index,node in enumerate(nodes)if node['track']==4];facial_count=len(facial);assert 0<facial_count<=8
                nonfinite=[]
                for node in range(8):
                    if any(not math.isfinite(struct.unpack_from('<f',payload,pose*512+node*64+row*16+lane*4)[0])for pose in range(6)for row in [0,1,3]for lane in range(3)):nonfinite.append(node)
                assert not any(node<facial_count for node in nonfinite)
                payloads.append(struct.pack('<I',facial_count)+payload);owned.append(dict(key=key,ordinal=ordinal,display_name=names_afs[ordinal][0],archive_offset=base+offset,bytes=length,sha256=hashlib.sha256(payload).hexdigest(),model_key=model_key,model_ordinal=model_ordinal,model_sha256=hashlib.sha256(model).hexdigest(),skeleton_sha256=hashlib.sha256(skeleton).hexdigest(),facial_nodes=facial,unused_nonfinite_matrix_ordinals=nonfinite))
        corpus=out/'owned_matrices.bin';corpus.write_bytes(struct.pack('<I',len(payloads))+b''.join(payloads));record['owned_assets']=owned;record['corpus_sha256']=sha(corpus);record['archive_identity']=dict(size=stamp[0],mtime_ns=stamp[1])
        env=dict(os.environ,PATH=str(args.compiler.resolve().parent)+os.pathsep+os.environ.get('PATH',''));exe=out/'checks.exe';command=[str(args.compiler),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-Wno-unused-variable','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),*[str(out/'source'/name)for name in units],str(out/'source'/fixture),str(out/'original.cpp'),'-o',str(exe)];record['command']=command
        result=subprocess.run(command,env=env,capture_output=True,timeout=300);(out/'compile.txt').write_bytes(result.stdout+result.stderr);assert result.returncode==0,'compile failed'
        record['run_command']=[str(exe),str(corpus)];result=subprocess.run(record['run_command'],env=env,capture_output=True,timeout=180);(out/'run.txt').write_bytes(result.stdout+result.stderr);assert result.returncode==0,'comparison failed';assert stamp==(archive.stat().st_size,archive.stat().st_mtime_ns)
        record.update(status='passed',observed=json.loads(result.stdout),source_unchanged=all(sha(ROOT/name)==value for name,value in before.items()));assert record['source_unchanged']
    except BaseException as error:
        record['error']=repr(error);raise
    finally:
        record['output_sha256']={path.relative_to(out).as_posix():sha(path)for path in out.rglob('*')if path.is_file()and path.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
    print(json.dumps(dict(status=record['status'],observed=record['observed'])))


if __name__=='__main__':main()
