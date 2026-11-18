"""Freeze and compare scene166 sender/receiver with the real native queue.

Only the transport endpoints and unrelated receiver cases are declared ports;
all selected original command, phase, routing and receive bodies execute.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import struct
import sys

ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source,elf_reader

def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()

def main(args):
    out=args.output.resolve();assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir(parents=True)
    compiler=Path(args.compiler).resolve();env=dict(os.environ,PATH=str(compiler.parent)+os.pathsep+os.environ.get('PATH',''))
    frozen=out/'source'
    for directory in ('game','runtime','tools/native_reconstruction','recomp/overrides/native_banks'):
        shutil.copytree(ROOT/directory,frozen/directory,ignore=shutil.ignore_patterns('__pycache__','*.pyc'))
    source_hashes={p.relative_to(frozen).as_posix():sha(p) for p in frozen.rglob('*') if p.is_file() and (p.suffix in ('.cpp','.hpp','.h','.inc') or p.name=='CMakeLists.txt')}
    reference=out/'reference';reference.mkdir()
    fixture=ROOT/'build-native-sjuni/scene-record-retirement-script-audio-llvm-v1/original_fixture.hpp'
    shutil.copyfile(fixture,reference/'original_fixture.hpp');shutil.copyfile(fixture.parent/'word_conversion.hpp',reference/'word_conversion.hpp')
    elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(elf.read_bytes())
    overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';raw=overlay.read_bytes()
    selected=[('o2',0x694470),('o2',0x5a8f40),('o2',0x680fb0),('o2',0x67dd40),('main',0x1afdd0),('main',0x1b0310),('main',0x1b0300)]
    bodies=[];entries={};audits=[];original_hashes={}
    for image,at in selected:
        source=ROOT/('recomp/config/output_ovl/o2' if image=='o2' else 'recomp/config/output')/f'{"o2" if image=="o2" else "sub"}_{at:08X}_0x{at:x}.cpp'
        text=source.read_text();end=int(re.search(r'// Address: 0x[0-9a-fA-F]+ - 0x([0-9a-fA-F]+)',text)[1],16)
        reader=(lambda address,size:raw[address-0x570000:address-0x570000+size]) if image=='o2' else read
        audits.append(compare_source('scene record parameter',source.relative_to(ROOT).as_posix(),at,end,reader))
        bodies.append('\n'.join(line for line in text.splitlines() if not line.startswith('#include')))
        original_hashes[source.relative_to(ROOT).as_posix()]=sha(source);entries[at]=source.stem
    text='\n'.join(bodies)
    names=set(re.findall(r'\b((?:o2|sub)_[A-Za-z0-9_]+)\(',text));defined=set(entries.values());unexecuted=sorted(names-defined)
    declarations='\n'.join(f'void {name}(std::uint8_t*,R5900Context*,PS2Runtime*);' for name in sorted(names))+'\n'
    table=raw[0x7406e0-0x570000:0x7406e0-0x570000+44];assert hashlib.sha256(table).hexdigest()=='7d11fc262b72710fd85bb4bcebe00fe95ef23d281face9bda95bd57ad5512a65'
    declarations+='inline void owned_scene_record_receiver_table(std::uint8_t* memory){const std::uint8_t table[]{'+','.join(str(v) for v in table)+'};std::memcpy(memory+0x7406e0,table,sizeof table);}\n'
    (reference/'original_declarations.hpp').write_text(declarations)
    throws='\n'.join(f'void {name}(std::uint8_t*,R5900Context*,PS2Runtime*){{throw std::runtime_error("Unexecuted channel5 receiver branch {name}");}}' for name in unexecuted)
    (reference/'original.cpp').write_text('#include "original_fixture.hpp"\n#include "original_declarations.hpp"\n'+text+'\n'+throws+'\n')
    (reference/'original_lookup.hpp').write_text('\n'.join(f'case {at:#x}:return &{name};' for at,name in entries.items())+'\n')
    commands=[]
    def run(command,label,timeout=300):
        result=subprocess.run([str(x) for x in command],env=env,capture_output=True,text=True,timeout=timeout)
        (out/(label+'.stdout.txt')).write_text(result.stdout);(out/(label+'.stderr.txt')).write_text(result.stderr)
        commands.append(dict(command=[str(x) for x in command],returncode=result.returncode,stdout_sha256=hashlib.sha256(result.stdout.encode()).hexdigest(),stderr_sha256=hashlib.sha256(result.stderr.encode()).hexdigest()))
        if result.returncode:raise RuntimeError(label+': '+result.stdout[-3000:]+result.stderr[-6000:])
        return result.stdout
    cmake=Path('C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe')
    ninja=cmake.parent.parent.parent/'Ninja/ninja.exe'
    build=out/'build'
    run([cmake,'-S',frozen/'game/native','-B',build,'-G','Ninja','-DCMAKE_MAKE_PROGRAM='+str(ninja),'-DCMAKE_CXX_COMPILER='+str(compiler),'-DCMAKE_BUILD_TYPE=Release','-DREO_SCENE_RECORD_PARAMETERS_REFERENCE_DIR='+str(reference)],'configure')
    run([cmake,'--build',build,'--target','scene_record_parameter_tests','--parallel','2'],'build',600)
    result=json.loads(run([build/'gameplay_scenario/scene_record_parameter_tests.exe'],'test',180))
    drift={name:sha(ROOT/name) for name,digest in source_hashes.items() if (ROOT/name).exists() and sha(ROOT/name)!=digest}
    receipt=dict(schema='reo.native.scene_record_parameters.v1',status='passed',compiler=str(compiler),compiler_sha256=sha(compiler),source_frozen=True,source_sha256=source_hashes,
        original_source_sha256=original_hashes,owned_instruction_audits=audits,unexecuted_original_ports=unexecuted,
        fixture_sha256=sha(fixture),commands=commands,result=result,current_source_drift=drift,
        game_launched=False,installed_in_game=False,stage4_complete=False,
        limitations=['Transport endpoints811190/810870 are test ports recording initialized typed fields only; no socket or authentication is exercised.',
                     'The native ActorMessageQueue and ActorReception consume real owned messages; unrelated original channel5 receiver cases throw if selected.',
                     'Source snapshots are immutable during this build; subsequent live-tree drift is recorded separately.'])
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n');print(json.dumps(dict(status='passed',result=result,current_source_drift=drift)))

if __name__=='__main__':
    parser=argparse.ArgumentParser();parser.add_argument('--compiler',required=True);parser.add_argument('--output',type=Path,required=True);main(parser.parse_args())
