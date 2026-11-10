"""Compare native AI goal/action state against complete owned source bodies."""
import argparse
import hashlib
import json
import os
import re
import subprocess
import struct
from pathlib import Path

from audit_retail_effect_descriptors import compare_source,elf_reader
from generate_ai_weight_profiles import generated
from generate_ai_reaction_policies import generated as generated_reactions
from verify_gameplay_collision import COMPILERS

ROOT=Path(__file__).resolve().parents[2]


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser=argparse.ArgumentParser();parser.add_argument('--compiler',choices=COMPILERS,required=True);parser.add_argument('--output',type=Path,required=True);args=parser.parse_args()
    out=args.output.resolve();assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni')
    image=ROOT/'build-function-index/owned-overlays/o9.bin';raw=image.read_bytes()
    assert sha(image)=='604126d6edca1b1333948d79d1d2c8d2f2e22f4a233efbdfb769c106dafe7343'
    main_image=ROOT/'game_data/SLUS_207.65'
    o2_image=ROOT/'build-function-index/owned-overlays/o2.bin';o2_raw=o2_image.read_bytes()
    assert sha(o2_image)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    o8_image=ROOT/'build-function-index/owned-overlays/o8.bin';o8_raw=o8_image.read_bytes()
    assert sha(o8_image)=='f42da66b07a00fb221c5954b0e02b06a46b5694afd5596e866d35feec1fc92ab'
    assert sha(main_image)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    assert (ROOT/'game/native/gameplay_ai/weight_profiles.inc').read_text()==generated()
    assert (ROOT/'game/native/gameplay_ai/reaction_policies.inc').read_text()==generated_reactions()
    assert struct.unpack_from('<I',o2_raw,0x71b034-0x570000)[0]==0x41c80000
    assert struct.unpack_from('<6I',raw,0x82b860-0x810000)==(0x8231c0,)*6
    entries={};proof=[]
    for address in [0x8120c0,0x8123e0,0x813380,0x81a6e0,0x81a6f0,0x814b30,0x107ab0,0x681240,0x6812b0,0x681330,0x681710,0x681790,0x815df0,0x681820,0x6818d0,0x1afe70,0x1b0300,0x811770,0x810f30,0x8133d0,0x825cc0,0x823190,0x817140,0x8130d0,0x1aec80]:
        folder=ROOT/('recomp/config/output' if address<0x200000 else 'recomp/config/output_ovl/'+('o8' if address==0x810f30 else 'o2' if address<0x810000 else 'o9'))
        path=next(folder.glob(f'*_{address:08X}_0x{address:x}.cpp'))
        end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',path.read_text())[1],16)
        read=elf_reader(main_image.read_bytes()) if address<0x200000 else (lambda a,n:o8_raw[a-0x810000:a-0x810000+n]) if address==0x810f30 else (lambda a,n:o2_raw[a-0x570000:a-0x570000+n]) if address<0x810000 else (lambda a,n:raw[a-0x810000:a-0x810000+n])
        name=path.relative_to(ROOT).as_posix();proof.append(compare_source('Complete AI execution/profile body',name,address,end,read));entries[address]=name
    helper='tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp'
    unit='game/native/gameplay_ai/execution.cpp';fixture='game/native/gameplay_ai/execution_tests.cpp'
    files=[unit,fixture,'game/native/gameplay_ai/execution.hpp','game/native/gameplay_ai/weight_profiles.inc',
        'game/native/gameplay_ai/CMakeLists.txt',helper,Path(__file__).relative_to(ROOT).as_posix(),
        'tools/native_reconstruction/generate_ai_weight_profiles.py',*entries.values()]
    files+=['game/native/gameplay_ai/control_requests.cpp','game/native/gameplay_ai/control_requests.hpp','game/native/gameplay_ai/control_request_tests.inc']
    files+=['game/native/gameplay_session/activity.cpp','game/native/gameplay_session/activity.hpp','game/native/gameplay_session/CMakeLists.txt','game/native/gameplay_ai/activity_tests.inc']
    files+=['game/native/gameplay_ai/initialization.cpp','game/native/gameplay_ai/initialization.hpp','game/native/gameplay_ai/initialization_tests.inc',
        'game/native/gameplay_navigation/bank.cpp','game/native/gameplay_navigation/navigation.cpp']
    goal_units=['game/native/gameplay_ai/priority_goals.cpp','game/native/gameplay_scenario/scene_resources.cpp','game/native/gameplay_scenario/resource_templates.cpp']
    files+=goal_units+['game/native/gameplay_ai/priority_goal_tests.inc']
    reaction_units=['game/native/gameplay_ai/reactions.cpp','game/native/gameplay_session/session.cpp']
    files+=reaction_units+['game/native/gameplay_ai/reaction_tests.inc','game/native/gameplay_ai/reaction_policies.inc','tools/native_reconstruction/generate_ai_reaction_policies.py']
    # Freeze native quoted-include dependencies. Original runtime headers are
    # intentionally supplied by the separately generated test-only surroundings.
    closure=set(files);pending=[ROOT/name for name in files if name not in entries.values()]
    while pending:
        path=pending.pop()
        for name in re.findall(r'#include "([^"\n]+)"',path.read_text()):
            included=next((p.resolve() for p in [path.parent/name,ROOT/name] if p.is_file()),None)
            if included and included.is_relative_to(ROOT):
                relative=included.relative_to(ROOT).as_posix()
                if relative not in closure:closure.add(relative);pending.append(included)
    files=sorted(closure)
    frozen={name:(ROOT/name).read_bytes() for name in files};out.mkdir(parents=True)
    for name,data in frozen.items():
        path=out/'source'/name;path.parent.mkdir(parents=True,exist_ok=True);path.write_bytes(data)
    reference=frozen[helper].replace(b'struct R5900Context {',b'struct R5900Context { std::uint64_t hi{},lo{};')
    assert reference!=frozen[helper]
    (out/'reference.hpp').write_bytes(reference+b'\n#define GPR_S32(c,n) std::bit_cast<std::int32_t>(GPR_U32(c,n))\n#define FPU_DIV_S(a,b) ((a)/(b))\n')
    body='\n'.join(frozen[name].decode() for name in entries.values());(out/'original.cpp').write_text(body)
    actual={Path(name).stem for name in entries.values()};calls=set(re.findall(r'\b((?:sub|o[0-9]+)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body))
    (out/'functions.h').write_text('#pragma once\n'+''.join(f'void {name}(std::uint8_t*,R5900Context*,PS2Runtime*);\n' for name in sorted(actual))+''.join(f'inline void {name}(std::uint8_t* m,R5900Context* c,PS2Runtime* r){{original_transform_port(m,c,r);}}\n' for name in sorted(calls-actual)))
    for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
    for name in ['o2_functions.h','o8_functions.h','o9_functions.h','ps2_recompiled_functions.h']:(out/name).write_text('#pragma once\n#include "functions.h"\n')
    for name in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/name).write_text('#pragma once\n')
    (out/'dispatch.inc').write_text(''.join(f'case {address}:{Path(name).stem}(memory,context,runtime);return;\n' for address,name in entries.items()))
    (out/'o9.bin').write_bytes(raw)
    (out/'o2.bin').write_bytes(o2_raw)
    compiler=COMPILERS[args.compiler];env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+env.get('PATH','')
    exe=out/'checks.exe';command=[str(compiler),'-std=c++20','-O2','-fno-fast-math','-ffp-contract=off','-msse4.1','-DREO_AI_ORIGINAL=1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-I'+str(out),'-I'+str(out/'source'),str(out/'source'/unit),str(out/'source'/fixture),str(out/'original.cpp'),'-o',str(exe)]
    command.insert(command.index(str(out/'original.cpp')),str(out/'source/game/native/gameplay_ai/control_requests.cpp'))
    command.insert(command.index(str(out/'original.cpp')),str(out/'source/game/native/gameplay_session/activity.cpp'))
    for name in ['game/native/gameplay_ai/initialization.cpp','game/native/gameplay_navigation/bank.cpp','game/native/gameplay_navigation/navigation.cpp',*goal_units,*reaction_units]:
        command.insert(command.index(str(out/'original.cpp')),str(out/'source'/name))
    receipt=dict(schema=1,status='failed',game_launched=False,installed_in_game=False,stage4_complete=False,
        compiler_sha256=sha(compiler),source_sha256={name:hashlib.sha256(data).hexdigest() for name,data in frozen.items()},
        owned_image_sha256={image.relative_to(ROOT).as_posix():sha(image),main_image.relative_to(ROOT).as_posix():sha(main_image),o2_image.relative_to(ROOT).as_posix():sha(o2_image),o8_image.relative_to(ROOT).as_posix():sha(o8_image)},
        original_word_audits=proof,commands=[],declared_ports=['107C68 exact two eight-byte zero fills in original-only profile selection surroundings'],
        immutable_evidence={'o2_71b034_f32_bits':0x41c80000,'o9_82b860_targets':[0x8231c0]*6},
        limitations=['Negative profile indices remain unavailable: original signed comparison lacks a lower bound and would address adjacent content. Indices>=20 preserve the source no-op.',
            'Reaction chance profiles admit the eight authored character columns only. Other characters refuse before effects only on branches requiring that chance table. Deterministic branches and event IDs>=13 need no profile.',
            'Qualified native state primitives and actual Owner integration are separate checks. Full observations, remaining goal/action callbacks, control servicing and game installation remain open.'])
    try:
        for label,cmd in [('compile',command),('test',[str(exe),str(out/'o9.bin'),str(out/'o2.bin')])]:
            result=subprocess.run(cmd,capture_output=True,env=env,timeout=180);(out/f'{label}.stdout.txt').write_bytes(result.stdout);(out/f'{label}.stderr.txt').write_bytes(result.stderr);receipt['commands'].append(dict(label=label,exit_code=result.returncode,command=cmd))
            assert result.returncode==0,label+': '+result.stderr.decode(errors='replace')[-2000:]
            if label=='test':receipt['observed']=json.loads(result.stdout)
        receipt['source_unchanged']=all((ROOT/name).read_bytes()==data for name,data in frozen.items());assert receipt['source_unchanged'];receipt['status']='passed'
    finally:
        receipt['output_sha256']={p.name:sha(p) for p in out.iterdir() if p.is_file()};(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print(json.dumps(receipt['observed']))


if __name__=='__main__':
    main()
