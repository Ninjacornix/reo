"""Prepare a pinned, test-only complete-original 6621F0 comparison fixture."""
import argparse
import hashlib
import json
import os
import re
import shutil
import struct
import subprocess
import sys
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source,elf_reader

PINS={
    'build-function-index/owned-overlays/o2.bin':'45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226',
    'build-function-index/owned-overlays/o0.bin':'bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2',
    'game_data/SLUS_207.65':'06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46',
}
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni')
    images={name:(ROOT/name).read_bytes() for name in PINS}
    for name,data in images.items():assert hashlib.sha256(data).hexdigest()==PINS[name],f'pinned owned image mismatch: {name}'
    read_o2=lambda at,n:images['build-function-index/owned-overlays/o2.bin'][at-0x570000:at-0x570000+n]
    read_o0=lambda at,n:images['build-function-index/owned-overlays/o0.bin'][at-0x370000:at-0x370000+n]
    read_main=elf_reader(images['game_data/SLUS_207.65'])
    owned_ranges=[(0x22fe20,32,'main'),(0x241c78,32,'main'),(0x38ca98,4,'o0'),
                  (0x712b30,20,'o2'),(0x712b50,20,'o2')]
    owned_constants=[]
    for address,size,bank in owned_ranges:
        raw=(read_main(address,size) if bank=='main' else read_o0(address,size) if bank=='o0' else read_o2(address,size))
        owned_constants.append((address,raw))
    elf=images['game_data/SLUS_207.65'];phoff=struct.unpack_from('<I',elf,28)[0];entsize,count=struct.unpack_from('<HH',elf,42)
    main_segments=[]
    for i in range(count):
        kind,offset,vaddr,_,filesz=struct.unpack_from('<5I',elf,phoff+i*entsize)
        if kind==1:main_segments.append((vaddr,elf[offset:offset+filesz]))
    roots=[0x6621f0,0x6dee20,0x1b0340,0x1b02d0,0x1b0300,0x107c68,
           0x376e70,0x192180,0x1226f0,0x120908,0x122140,0x1224a8,0x191ef0,0x65f0c0,0x1920a0]
    bodies={};audits=[]
    def source_for(address):
        folders=[]
        if 0x570000<=address<0x570000+len(images['build-function-index/owned-overlays/o2.bin']):folders.append(ROOT/'recomp/config/output_ovl/o2')
        if 0x370000<=address<0x370000+len(images['build-function-index/owned-overlays/o0.bin']):folders.append(ROOT/'recomp/config/output_ovl/o0')
        folders.append(ROOT/'recomp/config/output')
        for folder in folders:
            matches=list(folder.glob(f'*_{address:08X}_0x{address:x}.cpp'))
            if matches:return matches[0]
        return None
    for address in roots:
        path=source_for(address);assert path is not None,address
        text=path.read_text();stem=path.stem
        m=re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',text)
        assert m,path
        bodies[stem]=path
        begin,end=(int(v,16)for v in m.groups())
        if 0x570000<=begin<0x570000+len(images['build-function-index/owned-overlays/o2.bin']):reader=read_o2
        elif 0x370000<=begin<0x370000+len(images['build-function-index/owned-overlays/o0.bin']):reader=read_o0
        else:reader=read_main
        audits.append(compare_source('Complete original analog-control body or called helper',path.relative_to(ROOT).as_posix(),begin,end,reader))
    required={0x6621f0,0x6dee20,0x1b0340,0x1b02d0,0x1b0300,0x107c68,
              0x376e70,0x192180,0x1226f0,0x120908,0x122140,0x1224a8,0x191ef0,0x65f0c0,0x1920a0}
    found_addresses={int(re.search(r'// Address: 0x([0-9a-f]+) -',path.read_text())[1],16)for path in bodies.values()}
    assert required<=found_addresses,sorted(required-found_addresses)
    # The ten exact unsigned-short bounds consumed by6621F0.
    tables={}
    for address in [0x712b30,0x712b50]:
        raw=read_o2(address,20);tables[f'0x{address:x}']=[int.from_bytes(raw[i:i+2],'little')for i in range(0,len(raw),2)]
    assert tables['0x712b30']==[0xff00,0x0100,0xc800,0x3800,0xb000,0x5000,0x8800,0x7800,0x8000,0x8000]
    assert tables['0x712b50']==[0xfd00,0x0300,0xc800,0x3800,0xb000,0x5000,0x8800,0x7800,0x8000,0x8000]
    out.mkdir(parents=True)
    for name,data in images.items():
        pth=out/'source'/name;pth.parent.mkdir(parents=True,exist_ok=True);pth.write_bytes(data)
    with (out/'owned_elf_segments.bin').open('wb') as stream:
        stream.write(struct.pack('<I',len(main_segments)))
        for address,data in main_segments:stream.write(struct.pack('<II',address,len(data)));stream.write(data)
    fixture='tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp'
    reference=(ROOT/fixture).read_text()+'''\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))
#define FPU_DIV_S(a,b) ((a)/(b))
#define FPU_C_EQ_S(a,b) ((a)==(b))
#define PS2_PCPYLD(a,b) _mm_unpacklo_epi64((b),(a))
#define SRA32(v,n) (std::int32_t(v)>>(n))
#include "third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h"
#define FPU_CVT_W_S(v) Ps2FpuConvertWord(v)
'''
    (out/'reference.hpp').write_text(reference)
    combined='\n'.join(path.read_text()for path in bodies.values());(out/'original.cpp').write_text(combined)
    declarations=''.join(f'void {name}(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in bodies)
    callnames=set(re.findall(r'\b((?:sub|o[0-9]+)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',combined))
    declarations+=''.join(f'inline void {name}(std::uint8_t*m,R5900Context*c,PS2Runtime*r){{original_transform_port(m,c,r);}}\n'for name in sorted(callnames-set(bodies)))
    (out/'functions.h').write_text('#pragma once\n'+declarations)
    for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
    for name in ['o2_functions.h','o0_functions.h','ps2_recompiled_functions.h']:(out/name).write_text('#pragma once\n#include "functions.h"\n')
    for name in ['ps2_recompiled_stubs.h','ps2_syscalls.h','ps2_stubs.h']:(out/name).write_text('#pragma once\n')
    dispatch=[]
    for stem,path in bodies.items():
        start=int(re.search(r'// Address: 0x([0-9a-f]+) -',path.read_text())[1],16)
        prefix='++head_target_calls;' if start==0x65f0c0 else ''
        dispatch.append(f'case 0x{start:x}: {prefix}{stem}(memory,context,runtime);return;\n')
    (out/'original_dispatch.hpp').write_text(''.join(sorted(dispatch)))
    constant_code='inline void owned_constants(std::uint8_t* memory){\n'
    for address,raw in owned_constants:
        constant_code+='const std::uint8_t c'+format(address,'x')+'[]{'+','.join(map(str,raw))+'};std::memcpy(memory+'+str(address)+',c'+format(address,'x')+',sizeof c'+format(address,'x')+');\n'
    (out/'owned_constants.hpp').write_text(constant_code+'}\n')
    pinned_sources=[fixture,'tools/native_reconstruction/analog_control_tests.cpp',
      'tools/native_reconstruction/prepare_analog_control_reference.py',
      'game/native/gameplay_world/analog_control.hpp','game/native/gameplay_world/analog_control.cpp',
      'game/native/gameplay_world/world.hpp','game/native/gameplay_world/actor_initial_state.hpp',
      *[path.relative_to(ROOT).as_posix()for path in bodies.values()]]
    file_hashes={name:sha(ROOT/name)for name in dict.fromkeys(pinned_sources)}
    record={'schema':1,'status':'prepared','game_run':False,'production_wired':False,
      'owned_images':PINS,'original_bodies':audits,'primary_action_tables':tables,
      'original_dependencies':[hex(x)for x in sorted(found_addresses)],
      'head_target_helper':{'address':'0x65f0c0','included':True,'closure':'recursive direct J/JAL source bodies'},
      'source_sha256':file_hashes,'comparison_driver':'tools/native_reconstruction/analog_control_tests.cpp'}
    native_dir=(ROOT/'game/native').as_posix();root_dir=ROOT.as_posix();output_dir=out.as_posix()
    cmake=f'''cmake_minimum_required(VERSION 3.20)
project(analog_control_reference LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_subdirectory("{native_dir}" native)
add_executable(analog_control_tests
  "{root_dir}/tools/native_reconstruction/analog_control_tests.cpp"
  "{root_dir}/game/native/gameplay_world/analog_control.cpp")
target_include_directories(analog_control_tests PRIVATE "{root_dir}" "{output_dir}")
target_link_libraries(analog_control_tests PRIVATE reo_native_gameplay_world reo_native_transform_math)
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
  target_compile_options(analog_control_tests PRIVATE -Wall -Wextra -Wpedantic -Werror -Wno-unused-label -Wno-unused-parameter -Wno-unused-variable -fno-fast-math -ffp-contract=off)
endif()
'''
    (out/'CMakeLists.txt').write_text(cmake)
    record['status']='prepared';record['commands']=[];record['main_pt_load_segments']=[{'address':hex(address),'bytes':len(data)}for address,data in main_segments];record['owned_constant_spans']=[{'address':hex(address),'bytes':data.hex(),'sha256':hashlib.sha256(data).hexdigest()}for address,data in owned_constants]
    (out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
    print(json.dumps({'status':record['status'],'bodies':len(bodies),'instructions':sum(x['matched_comments']+x['omitted_zero_words']for x in audits),'tables':tables,'output':str(out)}),flush=True)
if __name__=='__main__':main()
