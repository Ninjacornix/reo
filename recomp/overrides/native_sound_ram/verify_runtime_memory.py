#!/usr/bin/env python3
"""RuntimeMemory protocol fixtures + whole actual127-header object; no device/game.

The fixture substitutes Runtime/lease/acquisition dependencies, NOT copy/token
method bodies. Its private friend deliberately bypasses prepare. This is not a
test that a real renderer/CD/bridge can issue the production capabilities.
"""
import argparse,hashlib,json,os,re,shutil,subprocess
from pathlib import Path
HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]
KIT=ROOT/'build-native-sjuni/candidate-inputs-v8'
KIT_SHA='435ae2791088c3061ffd2caa3617924daa9d1b8815eb441512f4c9f50e5b4ea0'
PROOF_SHA='909917fc2f766c8a43a10abbc0b94189fa24254ecfaa7f710e4eb24dc941b58a'
HEADER_SHA='d99bf2fa5724b6c152725eaa2ca9d95e87527cdf812add82f92e18a9a724be9b'
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def read(p):return p.read_text(encoding='utf-8')
def write(p,s):p.parent.mkdir(parents=True,exist_ok=True);p.write_text(s,encoding='utf-8',newline='\n')
def block(s,start):
    i=s.index(start);b=s.index('{',i);depth=0
    for end in range(b,len(s)):
        depth+=(s[end]=='{')-(s[end]=='}')
        if not depth:return s[i:end+1]
    raise ValueError('Unbalanced source '+start)
def deps(p):
    source=read(p).replace('\\\n',' ').split(':',1)[1]
    return [Path(x.replace('\\ ',' ').replace('\\:',':')).resolve()for x in re.findall(r'(?:\\[ \t]|[^\s])+',source)]
def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--tree',type=Path,required=True);parser.add_argument('--proof',type=Path,required=True)
    parser.add_argument('--cxx',required=True);parser.add_argument('--output',type=Path,required=True)
    a=parser.parse_args();tree=a.tree.resolve();out=a.output.resolve();cc=shutil.which(a.cxx)
    if not cc or out.exists()or not out.is_relative_to(ROOT/'build-native-sjuni/runtime-memory'):raise ValueError('Compiler/fresh private output required')
    if sha(a.proof)!=PROOF_SHA:raise ValueError('Final127-v4 proof required')
    proof=json.loads(read(a.proof));assert proof['status']=='passed'and proof['applied_count']==127
    for name,digest in proof['source_sha256'].items():
        if sha(tree/name)!=digest:raise ValueError('127 source drift '+name)
    for entry in proof['patches']:
        if sha(ROOT/entry['path'])!=entry['sha256']:raise ValueError('Patch drift '+entry['path'])
    lib=tree/'ps2xRuntime/src/lib'
    if sha(lib/'gs_sound_ram_profile.h')!=HEADER_SHA:raise ValueError('Final GS API mismatch')
    if sha(KIT/'build-kit.json')!=KIT_SHA:raise ValueError('Sealed V8 kit drift')
    authored={str(HERE/n):sha(HERE/n)for n in ('runtime_memory.h','runtime_memory.cpp','runtime_memory_tests.cpp','verify_runtime_memory.py')}
    out.mkdir(parents=True);env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','')
    receipt=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),authored=authored,
        full127_proof_sha256=sha(a.proof),sealed_v8_manifest_sha256=KIT_SHA,checks=[],consumed_project_inputs={},
        game_run=False,device_opened=False,real_runtime_acquisition_exercised=False,production_factory_object_only=True,
        fixture_policy='Exact production token/copy/source methods, substituted acquisition/context and private friend fixture; no synthetic authority claim')
    def run(name,command,expected=0):
        result=subprocess.run([str(x)for x in command],env=env,cwd=ROOT,capture_output=True,text=True,timeout=150)
        write(out/(name+'.txt'),result.stdout+result.stderr)
        receipt['checks'].append(dict(name=name,command=[str(x)for x in command],exit_code=result.returncode,expected=expected,stdout=result.stdout))
        if result.returncode!=expected:raise RuntimeError(name+':\n'+result.stdout+result.stderr)
    try:
        # Derive only exact public value/interface declarations for fake context.
        backend=read(lib/'Kernel/Syscalls/Helpers/CriAudioBackend.h')
        status=block(backend,'enum class BankStatusV2')+';'
        ram=read(lib/'Kernel/Syscalls/Helpers/CriAudioRamCapture.h')
        values=ram[ram.index('enum class NativeSoundRamSpaceV1'):ram.index('// Independent versioned COMPANION')]
        agg=read(ROOT/'recomp/overrides/native_audio/v2/aggregate.h')
        contracts=agg[agg.index('struct PacketBorrow'):agg.index('struct Report')]
        write(out/'unit_contracts.inc','#pragma once\n#include "recomp/overrides/native_banks/v3/packet_adapter.h"\n'
            'class PS2Runtime;\nnamespace ps2_cri_audio {\n'+status+'\n'
            'class SoundCall {public:bool admitted=true;bool native()const noexcept{return admitted;}BankStatusV2 status()const noexcept{return admitted?BankStatusV2::ok:BankStatusV2::closed;}};\n'+values+'}\n'
            'namespace reo::native::audio_aggregate::v2 {namespace packet=bank_packets::v3;\n'+contracts+'}\n')
        header=read(HERE/'runtime_memory.h')
        for include in ('#include "../native_audio/v2/aggregate.h"','#include "../native_cd_owner/ram_configuration.h"','#include "Kernel/Syscalls/Helpers/CriAudioRamCapture.h"'):
            if header.count(include)!=1:raise ValueError('Header fixture anchor')
            header=header.replace(include,'')
        write(out/'runtime_memory.h',header)
        source=read(HERE/'runtime_memory.cpp')
        namespace_start=source.index('namespace reo::native::sound_ram {')
        methods=source[namespace_start:]
        prepare=block(methods,'MemoryPrepareResult RuntimeMemory::prepare(')
        methods=methods.replace(prepare,'// Actual preparation excluded from the fake-context fixture.\n')
        write(out/'runtime_memory_impl.inc','#include "runtime_memory.h"\n'+methods)
        write(out/'runtime_memory_tests.cpp',read(HERE/'runtime_memory_tests.cpp'))
        flags=[cc,'-std=c++20','-O1','-pthread','-Wall','-Wextra','-Wpedantic','-Werror',
               '-Wno-misleading-indentation','-Wno-unused-function','-ffp-contract=off','-I'+str(out),'-I'+str(HERE),'-I'+str(ROOT)]
        exe=out/'memory_protocol.exe'
        sources=[ROOT/'game/native/ram_capture/v2/cpu_authority_gate.cpp',HERE/'address_domain.cpp',
                 ROOT/'game/native/audio_banks/v2/algorithms.cpp',ROOT/'game/native/audio_banks/v2/session.cpp',
                 ROOT/'recomp/overrides/native_banks/v3/packet_adapter.cpp',out/'runtime_memory_tests.cpp']
        receipt['fixture_inputs']={str(p):sha(p)for p in sources}
        for folder,identity_file,key in ((ROOT/'game/native/audio_banks/v2','cohort_identity.json','candidate_sha256'),
                                        (ROOT/'recomp/overrides/native_banks/v3','identity.json','candidate_sha256')):
            identity=json.loads(read(folder/identity_file));receipt['fixture_inputs'][str(folder/identity_file)]=sha(folder/identity_file)
            for n,d in identity[key].items():
                if sha(folder/n)!=d:raise ValueError('Frozen prerequisite drift '+str(folder/n))
                receipt['fixture_inputs'][str(folder/n)]=d
        run('protocol_compile',flags+sources+['-o',exe]);run('protocol',[exe]);receipt['protocol_executable_sha256']=sha(exe)
        # Exact evolving source is observed, not merely checked for final bytes
        # of a nonoverlapping copy. The private memmove mutation must fail.
        anchor='for(std::size_t i=0;i<bytes;++i)to[i]=from[i];'
        if methods.count(anchor)!=1:raise ValueError('Forward negative anchor')
        write(out/'runtime_memory_impl.inc','#include "runtime_memory.h"\n'+methods.replace(anchor,'std::memmove(to,from,bytes);'))
        bad=out/'negative_memmove.exe';run('negative_memmove_compile',flags+sources+['-o',bad]);run('negative_memmove',[bad],1)
        binding='&&slot.token==&token'
        if methods.count(binding)!=1:raise ValueError('Token-address negative anchor')
        write(out/'runtime_memory_impl.inc','#include "runtime_memory.h"\n'+methods.replace(binding,''))
        bad=out/'negative_copied_token.exe';run('negative_copied_token_compile',flags+sources+['-o',bad]);run('negative_copied_token',[bad],1)
        write(out/'runtime_memory_impl.inc','#include "runtime_memory.h"\n'+methods)

        # Complete actual production TU, using a project-qualified exact SDK
        # copy plus sealed graphics/header cohort. No active or older SDK.
        cohort=out/'cohort';sdk=cohort/'third_party/PS2Recomp'
        for name,digest in proof['source_sha256'].items():
            dest=sdk/name;dest.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(tree/name,dest)
        kitfiles={row['path']:row['sha256']for row in json.loads(read(KIT/'build-kit.json'))['files']}
        generation_path=ROOT/'build-native-sjuni/candidate-work-v8/generate.json'
        generation=json.loads(read(generation_path));generated={}
        for name in ('irq_cpu_sites.inc','heap_control_sites.inc'):
            matches=[(Path(n.removeprefix('\\\\?\\')),digest)for n,digest in generation['outputs'].items()if n.endswith('\\recomp\\config\\local_source_catalogues\\'+name)]
            if len(matches)!=1 or sha(matches[0][0])!=matches[0][1]:raise ValueError('Generated catalogue drift')
            dest=out/'generated/local_source_catalogues'/name;dest.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(matches[0][0],dest);generated[str(dest.resolve())]=matches[0][1]
        receipt['generation_receipt_sha256']=sha(generation_path)
        include=[cohort,sdk/'ps2xRuntime/include',sdk/'ps2xRuntime/src/lib',sdk/'ps2xRuntime/src/lib/Kernel',out/'generated',ROOT]
        plan_path=KIT/'compile-plan.json';receipt['compile_plan_sha256']=sha(plan_path)
        if receipt['compile_plan_sha256']!='45d04b5734479a6c97270f9fe2e6788b50dfebc049837d8eeea88cda27ef0c02':raise ValueError('Sealed plan drift')
        plan=json.loads(read(plan_path))
        unit=next(u for u in plan['units']if u['sources']==['{work}/project/recomp/reo_bootstrap.cpp'])
        for option in unit['options']:
            if not option.startswith('/I{work}/project/'):continue
            rel=option[len('/I{work}/project/'):]
            if rel.startswith('third_party/PS2Recomp/ps2xRuntime/')or rel=='.':continue
            include.append(KIT/'source'/rel)
        actual=[cc,'-std=c++20','-O1','-pthread','-mssse3','-msse4.1','-D_WIN32_WINNT=0x0A00','-DWINVER=0x0A00',
                '-DNOMINMAX','-DWIN32_LEAN_AND_MEAN','-DREO_BUILD_NATIVE_SOUND_RAM_CAPTURE=2','-DREO_GAME_FILE1']+['-I'+str(i)for i in include]
        dep=out/'memory.pre.d';run('actual_dependencies',actual+['-MM','-MT','input','-MF',dep,HERE/'runtime_memory.cpp'])
        consumed={}
        for path in deps(dep):
            if path.is_relative_to(sdk):digest=proof['source_sha256'].get(path.relative_to(sdk).as_posix())
            elif path.is_relative_to(KIT):
                rel=path.relative_to(KIT).as_posix()
                if rel.startswith('source/third_party/PS2Recomp/ps2xRuntime/'):raise ValueError('Old SDK mixed in')
                digest=kitfiles.get(rel)
            elif str(path)in generated:digest=generated[str(path)]
            elif path.is_relative_to(ROOT/'third_party')or path.is_relative_to(ROOT/'build-native-sjuni')or path.is_relative_to(ROOT/'build-ninja'):raise ValueError('Unqualified private/dependency include '+str(path))
            elif path.is_relative_to(ROOT):digest=sha(path)
            else:raise ValueError('Unknown project include '+str(path))
            if digest is None or sha(path)!=digest:raise ValueError('Input drift '+str(path))
            consumed[str(path)]=digest
        obj=out/'runtime_memory.o';actual_dep=out/'memory.d'
        run('actual_object',actual+['-MMD','-MT','input','-MF',actual_dep,'-c',HERE/'runtime_memory.cpp','-o',obj])
        if set(deps(actual_dep))!={Path(n)for n in consumed}:raise ValueError('Include set drift')
        receipt['consumed_project_inputs']=consumed;receipt['actual_object_sha256']=sha(obj)
        receipt['status']='passed'
    except Exception as e:receipt.update(status='failed',failure=str(e));raise
    finally:
        receipt['authored_postcheck']=[n for n,d in authored.items()if sha(Path(n))!=d]
        receipt['include_postcheck']=[n for n,d in receipt['consumed_project_inputs'].items()if sha(Path(n))!=d]
        receipt['sdk_postcheck']=[n for n,d in proof['source_sha256'].items()if sha(tree/n)!=d]
        receipt['fixture_postcheck']=[n for n,d in receipt.get('fixture_inputs',{}).items()if sha(Path(n))!=d]
        if receipt['authored_postcheck']or receipt['include_postcheck']or receipt['sdk_postcheck']or receipt['fixture_postcheck']:receipt.update(status='failed',failure='Source drift')
        write(out/'receipt.json',json.dumps(receipt,indent=2)+'\n')
    print(json.dumps(dict(status=receipt['status'],receipt=str(out/'receipt.json'),sha256=sha(out/'receipt.json'))))
if __name__=='__main__':main()
