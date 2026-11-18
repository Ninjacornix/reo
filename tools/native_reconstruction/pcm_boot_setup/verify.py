#!/usr/bin/env python3
"""Verify focused124 setup patch, exact runtime leases, full facade and RPC callers."""
import argparse
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import re
import shutil
import subprocess

ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
PATCH=ROOT/'third_party/patches/ps2recomp/0123-explicit-pcm-pre-run-reset-transaction.patch'
PATCH_SHA='06e19bf875b015a7119a884811befd08c850d438cfeab38daec791b4762bb145'
RECEIPT=ROOT/'build-native-sjuni/dependency-pcm-boot-reapply-v3-receipt.json'
RECEIPT_SHA='944b72d4cc977ac01d8e7a4459c601f0a331b06c8adbb5048bec45a2963f91cb'
PIN='c46d1c7d8ab00fbfa18d2c1f764c559e4e5dc78f'
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def read(path):return path.read_text(encoding='utf-8')
def load(name):
    spec=importlib.util.spec_from_file_location(name,ROOT/'tools/native_reconstruction'/(name+'.py'));module=importlib.util.module_from_spec(spec);spec.loader.exec_module(module);return module
def block(text,start):
    begin=text.index(start);brace=text.index('{',begin);depth=0
    for end in range(brace,len(text)):
        depth+=(text[end]=='{')-(text[end]=='}')
        if not depth:return text[begin:end+1]
    raise ValueError('Unbalanced source')
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True)
    p.add_argument('--checkout',type=Path,default=ROOT/'build-native-sjuni/dependency-pcm-boot-reapply-v3');args=p.parse_args()
    tree=args.checkout.resolve();out=args.output.resolve();cc=shutil.which(args.cxx)
    if not cc or not out.is_relative_to(ROOT/'build-native-sjuni/pcm-boot-setup-checks'):raise ValueError('Existing compiler/private output required')
    if sha(PATCH)!=PATCH_SHA or sha(RECEIPT)!=RECEIPT_SHA:raise ValueError('Frozen patch/reapply receipt changed')
    receipt=json.loads(read(RECEIPT))
    if receipt['status']!='passed' or receipt['applied_count']!=124 or receipt['base_revision']!=PIN:raise ValueError('Wrong124 reconstruction')
    for row in receipt['patches']:
        if sha(ROOT/row['path'])!=row['sha256']:raise ValueError('Prior patch changed')
    for name,digest in receipt['source_sha256'].items():
        if sha(tree/name)!=digest:raise ValueError('Fresh source changed: '+name)
    subprocess.run(['git','-C',str(tree),'apply','--reverse','--check',str(PATCH)],check=True,capture_output=True)
    out.mkdir(parents=True,exist_ok=True);snapshot=out/'snapshot';helpers=snapshot/'Kernel/Syscalls/Helpers';helpers.mkdir(parents=True,exist_ok=True)
    source=tree/'ps2xRuntime/src/lib';header=read(tree/'ps2xRuntime/include/ps2_runtime.h');runtime=read(source/'ps2_runtime.cpp');rpc=read(source/'Kernel/Syscalls/RPC.cpp')
    runtime_methods='\n\n'.join(block(runtime,s) for s in (
        'PS2Runtime::PreRunSetupLease::PreRunSetupLease(PreRunSetupLease&& other) noexcept',
        'PS2Runtime::PreRunSetupLease::~PreRunSetupLease()',
        'PS2Runtime::PreRunSetupLease PS2Runtime::acquirePreRunSetup() noexcept',
        'void PS2Runtime::releasePreRunSetup() noexcept','bool PS2Runtime::externalWorkerResetAllowed()',
        'void PS2Runtime::beginExternalWorkerRun()'))+'\n'
    generated={'exact_runtime_methods.inc':runtime_methods,
        'exact_layout.inc':block(header,'struct PS2DtxCompatLayout')+';\n',
        'exact_lease.inc':block(header,'    class PreRunSetupLease final')+';\n'}
    for name,text in generated.items():(snapshot/name).write_text(text,encoding='utf-8',newline='\n')
    shutil.copyfile(HERE/'ps2_runtime.h',snapshot/'ps2_runtime.h')
    ref=load('pcm_owner_oracle');dispatch=load('verify_pcm_backend_dispatch')
    if sha(ROOT/'tools/native_reconstruction/pcm_owner_oracle.py')!='697194d2089779baf86074cf8cce28819607c4f7fd2e7561bcf557ac1d189183':raise ValueError('Frozen original transcript changed')
    for name in ('CriAudio.cpp','CriAudio.h','CriAudioBackend.h','CriAudioDispatch.h'):shutil.copyfile(source/'Kernel/Syscalls/Helpers'/name,helpers/name)
    for name,text in (('Kernel/Syscalls/Helpers/ReoSoundBanks.h',ref.MOCK_BANK),('ps2_host_backend.h',ref.MOCK_HOST),('vblank_music_diag.h',ref.MOCK_DIAG)):(snapshot/name).write_text(text,encoding='utf-8',newline='\n')
    shutil.copyfile(source/'cri_pcm_retire.h',snapshot/'cri_pcm_retire.h')
    declarations='void setDtxCompatLayout(const PS2DtxCompatLayout&,PS2Runtime* = nullptr);\nvoid clearDtxCompatLayout(PS2Runtime* = nullptr);\n'
    rpc_methods='\n\n'.join(block(rpc,s) for s in ('        void resetDtxRpcStateUnlocked(PS2Runtime *runtime = nullptr)',
        '    PS2DtxCompatLayout dtxCompatLayoutSnapshot()',
        '    void setDtxCompatLayout(const PS2DtxCompatLayout &layout, PS2Runtime *runtime)',
        '    void clearDtxCompatLayout(PS2Runtime *runtime)'))
    (out/'exact_rpc_methods.inc').write_text(declarations+rpc_methods,encoding='utf-8',newline='\n')
    shutil.copyfile(HERE/'harness.cpp',out/'harness.cpp')
    shutil.copyfile(ROOT/'tools/native_reconstruction/pcm_backend_dispatch/harness.cpp',out/'dispatch.cpp')
    (out/'rpc_methods.inc').write_text(dispatch.rpc_extract(ref,source),encoding='utf-8',newline='\n')
    prefix='#include <condition_variable>\n#include <memory>\n#include <utility>\n#include "snapshot/ps2_runtime.h"\n'
    (out/'legacy.cpp').write_text(prefix+ref.HARNESS,encoding='utf-8',newline='\n')
    env=dict(os.environ);env['PATH']=str(Path(cc).resolve().parent)+os.pathsep+env.get('PATH','')
    proof=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),patch_sha256=PATCH_SHA,
        reapply_receipt_sha256=RECEIPT_SHA,source_sha256=receipt['source_sha256'],checks=[],game_run=False,device_opened=False,runtime_library_linked=False)
    def run(name,command,expected=0):
        result=subprocess.run(command,env=env,capture_output=True,text=True,timeout=120)
        proof['checks'].append(dict(name=name,command=command,exit_code=result.returncode,stdout=result.stdout,stderr=result.stderr))
        if result.returncode!=expected:raise RuntimeError(name+' failed:\n'+result.stdout+result.stderr)
        return result
    flags=[cc,'-std=c++20','-O1','-ffp-contract=off','-pthread','-Wall','-Wextra','-Wpedantic','-Werror','-I'+str(snapshot)]
    try:
        exe=out/'setup.exe';run('compile_exact_setup',flags+[str(out/'harness.cpp'),'-o',str(exe)])
        for mode in ('flow','plain','public','lease','first','install','run','stop','install_wins'):run('setup_'+mode,[str(exe),mode])
        exe=out/'dispatch.exe';run('compile_prior_dispatch',flags+[str(out/'dispatch.cpp'),'-o',str(exe)])
        for mode in dispatch.SCENARIOS:run('dispatch_'+mode,[str(exe),mode])
        exe=out/'legacy.exe';run('compile_legacy',flags+[str(out/'legacy.cpp'),'-o',str(exe)])
        result=run('legacy_frozen', [str(exe)]);actual=[json.loads(line) for line in result.stdout.splitlines()]
        fixture=ROOT/'build-native-sjuni/pcm-owner-oracle/gcc/fixtures.json'
        if sha(fixture)!='819470f5433c09a5549fefae5f726012ba9ab34f3cc2e4ed3545007d89bea909':raise ValueError('Frozen fixture changed')
        if actual!=json.loads(read(fixture))['records']:raise ValueError('Original22/46 facade observations differ')
        proof['legacy']=dict(cases=22,snapshots=46,float_values=16656)
        # Compile exact new API methods against the REAL124 header, not the
        # synthetic runtime surroundings used to link the isolated facade.
        real=out/'real_runtime_api.cpp';real.write_text('#include "ps2_runtime.h"\n'+runtime_methods,encoding='utf-8',newline='\n')
        run('compile_actual_runtime_api',flags[:-1]+['-I'+str(tree/'ps2xRuntime/include'),'-c',str(real),'-o',str(out/'real_runtime_api.obj')])
        # One physical fresh dependency cohort: sealed geometry contains
        # project-root-qualified runtime includes, so avoid old-header mixing.
        kit=ROOT/'build-native-sjuni/candidate-inputs-v6';kit_sha='5457ead9e2fbbc1faa6438a49dead4c20155db3b653756e51c7f39100ff2d504'
        if sha(kit/'build-kit.json')!=kit_sha:raise ValueError('Sealed V6 input cohort changed')
        kit_files={r['path']:r['sha256'] for r in json.loads(read(kit/'build-kit.json'))['files']}
        cohort=out/'cohort';dependency=cohort/'third_party/PS2Recomp'
        for name,digest in receipt['source_sha256'].items():
            target=dependency/name;target.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(tree/name,target)
            if sha(target)!=digest:raise ValueError('Staged fresh124 changed')
        generation=ROOT/'build-native-sjuni/candidate-work-v6/generate.json'
        generation_sha='57449942f568de9c6f579ee58309d2a50ae16f0cdb69a36b43fbc96329c14e01'
        if sha(generation)!=generation_sha:raise ValueError('Existing V6 generation receipt changed')
        generated=json.loads(read(generation));qualified={}
        for basename in ('irq_cpu_sites.inc','heap_control_sites.inc'):
            matches=[(Path(k.removeprefix('\\\\?\\')),v) for k,v in generated['outputs'].items() if k.endswith('\\recomp\\config\\local_source_catalogues\\'+basename)]
            if len(matches)!=1 or sha(matches[0][0])!=matches[0][1]:raise ValueError('V6 generated catalogue changed')
            target=out/'generated/local_source_catalogues'/basename;target.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(matches[0][0],target);qualified[str(target)]=matches[0][1]
        include=[dependency/'ps2xRuntime/include',dependency/'ps2xRuntime/src/lib',dependency/'ps2xRuntime/src/lib/Kernel',cohort,out/'generated',
            kit/'source',kit/'source/tools/parallel_gs_backend/resident_geometry',kit/'source/third_party/PS2Recomp/out/build/_deps/raylib-src/src']
        actual_flags=[cc,'-std=c++20','-O1','-ffp-contract=off','-pthread','-DNOMINMAX','-DWIN32_LEAN_AND_MEAN','-D_MBCS','-DWIN32','-D_WINDOWS','-DNDEBUG','-DPLATFORM_DESKTOP','-DGRAPHICS_API_OPENGL_33']+['-I'+str(p) for p in include]
        consumed={};objects={}
        for name in ('Kernel/Syscalls/RPC.cpp','game_overrides.cpp','Kernel/Syscalls/Helpers/CriAudio.cpp'):
            actual_source=dependency/'ps2xRuntime/src/lib'/name;identifier=Path(name).stem;obj=out/(identifier+'.obj');deps=out/(identifier+'.d')
            run('compile_actual_'+identifier,actual_flags+['-MMD','-MF',str(deps),'-c',str(actual_source),'-o',str(obj)]);objects[name]=sha(obj)
            deptext=read(deps).replace('\\\n',' ');match=re.match(r'.*?:\s+(.*)',deptext,flags=re.S)
            if not match:raise ValueError('Malformed depfile')
            for value in re.findall(r'(?:\\[ \t]|[^\s])+',match.group(1)):
                path=Path(value.replace('\\ ', ' ').replace('\\:',':')).resolve()
                if path.is_relative_to(dependency):digest=receipt['source_sha256'].get(path.relative_to(dependency).as_posix())
                elif path.is_relative_to(kit):
                    relative=path.relative_to(kit).as_posix()
                    if relative.startswith('source/third_party/PS2Recomp/ps2xRuntime/'):raise ValueError('Older runtime header mixed into124 cohort')
                    digest=kit_files.get(relative)
                else:digest=qualified.get(str(path))
                if digest is None or sha(path)!=digest:raise ValueError('Unqualified compile input: '+str(path))
                consumed[str(path)]=digest
        proof['real_header_objects']=objects;proof['consumed_include_sha256']=consumed
        proof['sealed_v6_manifest_sha256']=kit_sha;proof['existing_v6_generation_receipt_sha256']=generation_sha
        proof['status']='passed'
    except Exception as error:proof.update(status='failed',failure=str(error));raise
    finally:
        proof['authored_sha256']={str(path.relative_to(ROOT)):sha(path) for path in (HERE/'harness.cpp',HERE/'ps2_runtime.h',Path(__file__))}
        proof['limitations']=['Runtime lease/phase/reset methods are exact extracted bodies; executable runtime surroundings omit full guest/device state.',
            'Facade is complete unchanged patched source with mock provider/gain/bank; no full runtime library or game linked.']
        (out/'receipt.json').write_text(json.dumps(proof,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(dict(status=proof['status'],setup_cases=9,prior_dispatch_cases=len(dispatch.SCENARIOS),legacy=proof['legacy'])))
if __name__=='__main__':main()
