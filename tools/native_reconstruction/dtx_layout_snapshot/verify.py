#!/usr/bin/env python3
"""Read-only source/patch audit, exact getter bodies, real headers and RPC object."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import subprocess

ROOT=Path(__file__).resolve().parents[3]
HERE=Path(__file__).resolve().parent
PIN='c46d1c7d8ab00fbfa18d2c1f764c559e4e5dc78f'
PATCH=ROOT/'third_party/patches/ps2recomp/0122-dtx-layout-snapshot-for-native-admission.patch'
PATCH_SHA='e3fdf4985998b6f96a5d755d0953603a3d4fc9da723f4b0d9aa1c5d22bd99c13'
BASE_RECEIPT=ROOT/'build-native-sjuni/dependency-pcm-dispatch-stop-fence-v2-receipt.json'
BASE_RECEIPT_SHA='807a1740889dbd4ffccede3074f59d90bfae7088032753f4b805a2dfaa1af475'
RECEIPT=ROOT/'build-native-sjuni/dependency-pcm-profile-reapply-v1-receipt.json'
RECEIPT_SHA='8f8a001fd50b1bad9c9da8729888b1f682e75c8321bdfd1076da085db52baeb8'
KIT_SHA='5457ead9e2fbbc1faa6438a49dead4c20155db3b653756e51c7f39100ff2d504'
CHANGED={'ps2xRuntime/include/ps2_syscalls.h','ps2xRuntime/src/lib/Kernel/Syscalls/RPC.cpp'}
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def block(text,start):
    at=text.index(start);begin=text.index('{',at);depth=0
    for end in range(begin,len(text)):
        depth+=(text[end]=='{')-(text[end]=='}')
        if depth==0:return text[at:end+1]
    raise ValueError('Unbalanced exact source block')
def clean_sources(receipt):return {k:v for k,v in receipt['source_sha256'].items() if k!='.git' and not k.startswith('.git/')}
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True);p.add_argument('--output',required=True,type=Path)
    p.add_argument('--checkout',type=Path,default=ROOT/'build-native-sjuni/dependency-pcm-profile-reapply-v1')
    p.add_argument('--baseline',type=Path,default=ROOT/'build-native-sjuni/dependency-pcm-dispatch-stop-fence-v2')
    p.add_argument('--kit',type=Path,default=ROOT/'build-native-sjuni/candidate-inputs-v6');args=p.parse_args()
    out=args.output.resolve();checkout=args.checkout.resolve();baseline=args.baseline.resolve();kit=args.kit.resolve();cc=shutil.which(args.cxx)
    allowed=ROOT/'build-native-sjuni/dtx-layout-snapshot-checks'
    if not cc or out==allowed or not out.is_relative_to(allowed):raise ValueError('Requires existing compiler and private child output')
    for path,digest in ((PATCH,PATCH_SHA),(BASE_RECEIPT,BASE_RECEIPT_SHA),(RECEIPT,RECEIPT_SHA),(kit/'build-kit.json',KIT_SHA)):
        if sha(path)!=digest:raise ValueError('Pinned input changed: '+str(path))
    prior=json.loads(BASE_RECEIPT.read_text());current=json.loads(RECEIPT.read_text())
    for receipt,count in ((prior,122),(current,123)):
        if receipt['status']!='passed' or receipt['base_revision']!=PIN or receipt['applied_count']!=count:raise ValueError('Wrong source reconstruction')
        patches=sorted((ROOT/'third_party/patches/ps2recomp').glob('*.patch'))[:count]
        if [(x.relative_to(ROOT).as_posix(),sha(x)) for x in patches]!=[(x['path'],x['sha256']) for x in receipt['patches']]:raise ValueError('Prior patch order/identities changed')
    before,after=clean_sources(prior),clean_sources(current)
    if set(before)!=set(after):raise ValueError('Unexpected source file additions/removals')
    changed={k for k in before if before[k]!=after[k]}
    if changed!=CHANGED:raise ValueError('Patch changed more than the two reviewed files')
    for tree,identities in ((baseline,before),(checkout,after)):
        discovered={file.relative_to(tree).as_posix() for file in tree.rglob('*') if file.is_file()
            and file.relative_to(tree).as_posix()!='.git' and not file.relative_to(tree).as_posix().startswith('.git/')}
        if discovered!=set(identities):raise ValueError('Unrecorded source files in reconstruction')
        for name,digest in identities.items():
            if sha(tree/name)!=digest:raise ValueError('Source identity changed: '+str(tree/name))
        head=subprocess.run(['git','-C',str(tree),'rev-parse','HEAD'],capture_output=True,text=True,check=True).stdout.strip()
        if head!=PIN:raise ValueError('Unexpected recorded base revision')
    reverse=['git','-C',str(checkout),'apply','--reverse','--check',str(PATCH)]
    subprocess.run(reverse,capture_output=True,text=True,check=True,timeout=30)
    rpc_path=checkout/'ps2xRuntime/src/lib/Kernel/Syscalls/RPC.cpp';rpc=rpc_path.read_text()
    signatures=('PS2DtxCompatLayout dtxCompatLayoutSnapshot()','void setDtxCompatLayout(const PS2DtxCompatLayout &layout)','void clearDtxCompatLayout()')
    methods={s:block(rpc,s) for s in signatures}
    # The only new body must contain a both-lock value return. All prior bytes
    # elsewhere, including setter/clear/reset, are separately checked above.
    without_getter=re.sub(r'    PS2DtxCompatLayout dtxCompatLayoutSnapshot\(\)\n    \{\n        std::scoped_lock lock\(g_rpc_mutex, g_dtx_rpc_mutex\);\n        return g_dtxCompatLayout;\n    \}\n\n','',rpc)
    if without_getter!=(baseline/'ps2xRuntime/src/lib/Kernel/Syscalls/RPC.cpp').read_text():raise ValueError('RPC change exceeds new getter')
    header=checkout/'ps2xRuntime/include/ps2_syscalls.h';addition='#define PS2_RUNTIME_HAS_DTX_LAYOUT_SNAPSHOT 1\n    // Host-only admission snapshot; no guest objects or pending requests copied.\n    PS2DtxCompatLayout dtxCompatLayoutSnapshot();\n'
    if header.read_text().count(addition)!=1 or header.read_text().replace(addition,'')!=(baseline/'ps2xRuntime/include/ps2_syscalls.h').read_text():raise ValueError('Header change exceeds declaration/capability')
    manifest=json.loads((kit/'build-kit.json').read_text());kit_files={row['path']:row['sha256'] for row in manifest['files']}
    plan=kit/'compile-plan.json'
    if sha(plan)!=kit_files['compile-plan.json']:raise ValueError('Sealed compile plan changed')
    units=json.loads(plan.read_text())['units'];unit=next(x for x in units if x['id']=='runtime106')
    if unit['sources']!=['{work}/project/third_party/PS2Recomp/ps2xRuntime/src/lib/Kernel/Syscalls/RPC.cpp']:raise ValueError('Wrong V6 unit cohort')
    out.mkdir(parents=True,exist_ok=True);(out/'exact_methods.inc').write_text('\n\n'.join(methods.values())+'\n')
    shutil.copyfile(HERE/'harness.cpp',out/'harness.cpp')
    # Geometry headers contain project-root-qualified runtime includes. Compile
    # one byte-identical123 dependency copy at that expected path so #pragma once
    # never sees a second physical copy from the older sealed kit runtime.
    cohort=out/'cohort';cohort_dependency=cohort/'third_party/PS2Recomp'
    for name,digest in after.items():
        target=cohort_dependency/name;target.parent.mkdir(parents=True,exist_ok=True)
        shutil.copyfile(checkout/name,target)
        if sha(target)!=digest:raise ValueError('Staged fresh123 source changed')
    generation=ROOT/'build-native-sjuni/candidate-work-v6/generate.json'
    generation_sha='57449942f568de9c6f579ee58309d2a50ae16f0cdb69a36b43fbc96329c14e01'
    if sha(generation)!=generation_sha:raise ValueError('Existing V6 generation receipt changed')
    generated=json.loads(generation.read_text());generated_root=out/'generated'
    generated_identities={}
    for name,digest in generated['inputs'].items():
        path=Path(name.removeprefix('\\\\?\\')).resolve()
        if path.is_relative_to(kit):
            relative=path.relative_to(kit).as_posix()
            if kit_files.get(relative)!=digest or sha(path)!=digest:raise ValueError('Unsealed generation input: '+relative)
        elif digest!=manifest['elfSha256']:raise ValueError('Unexpected generation input outside sealed V6 kit')
    for basename in ('irq_cpu_sites.inc','heap_control_sites.inc'):
        matching=[(Path(name.removeprefix('\\\\?\\')),digest) for name,digest in generated['outputs'].items()
            if name.endswith('\\recomp\\config\\local_source_catalogues\\'+basename)]
        if len(matching)!=1:raise ValueError('Missing qualified V6 catalogue: '+basename)
        path,digest=matching[0]
        if sha(path)!=digest:raise ValueError('Qualified V6 catalogue changed')
        destination=generated_root/'local_source_catalogues'/basename
        destination.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(path,destination)
        generated_identities[str(destination)]=dict(source=str(path),sha256=digest)
    env=dict(os.environ);env['PATH']=str(Path(cc).resolve().parent)+os.pathsep+env.get('PATH','')
    include=[checkout/'ps2xRuntime/include',checkout/'ps2xRuntime/src/lib',checkout/'ps2xRuntime/src/lib/Kernel',generated_root,
        kit/'source',kit/'source/tools/parallel_gs_backend/resident_geometry',
        kit/'source/third_party/PS2Recomp/out/build/_deps/raylib-src/src',
        kit/'source/third_party/PS2Recomp/out/build/_deps/raylib-src/src/external/glfw/include']
    flags=[cc,'-std=c++20','-O1','-ffp-contract=off','-pthread','-DNOMINMAX','-DWIN32_LEAN_AND_MEAN']+['-I'+str(x) for x in include]
    proof=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),base_revision=PIN,
        patch_sha256=PATCH_SHA,baseline_receipt_sha256=BASE_RECEIPT_SHA,reconstruction_receipt_sha256=RECEIPT_SHA,
        kit_manifest_sha256=KIT_SHA,sealed_compile_plan_sha256=sha(plan),changed_files=sorted(changed),
        existing_v6_generation_receipt_sha256=generation_sha,qualified_local_catalogues=generated_identities,
        exact_method_sha256={s:hashlib.sha256(body.encode()).hexdigest() for s,body in methods.items()},
        full_source_files_verified=len(after),checks=[],game_run=False,device_opened=False,runtime_library_linked=False)
    def run(name,command,expected=0):
        result=subprocess.run(command,capture_output=True,text=True,env=env,timeout=120)
        proof['checks'].append(dict(name=name,command=command,exit_code=result.returncode,expected_exit=expected,stdout=result.stdout,stderr=result.stderr))
        if result.returncode!=expected:raise RuntimeError(name+' failed:\n'+result.stdout+result.stderr)
        return result
    try:
        dependency_lists=[]
        for mode,extra in (('observed',[]),('real',['-DREAL_MUTEX'])):
            exe=out/(mode+'.exe');deps=out/(mode+'.d')
            run('compile_exact_'+mode,flags+['-Wall','-Wextra','-Wpedantic','-Werror','-MMD','-MF',str(deps)]+extra+[str(out/'harness.cpp'),'-o',str(exe)])
            result=run('run_exact_'+mode,[str(exe)]);proof[mode]=json.loads(result.stdout);dependency_lists.append(deps)
        negative=[]
        for omitted,kept in (('rpc','g_dtx_rpc_mutex'),('dtx','g_rpc_mutex')):
            folder=out/('negative-'+omitted);folder.mkdir(exist_ok=True)
            shutil.copyfile(HERE/'harness.cpp',folder/'harness.cpp')
            mutation=methods[signatures[0]].replace('std::scoped_lock lock(g_rpc_mutex, g_dtx_rpc_mutex);',
                'std::lock_guard lock('+kept+');')
            (folder/'exact_methods.inc').write_text('\n\n'.join([mutation]+[methods[s] for s in signatures[1:]])+'\n')
            exe=folder/'negative.exe'
            run('compile_negative_missing_'+omitted,flags+['-Wall','-Wextra','-Wpedantic','-Werror',str(folder/'harness.cpp'),'-o',str(exe)])
            result=run('negative_missing_'+omitted,[str(exe)],expected=1)
            if not result.stderr.startswith('snapshot assertion '):raise ValueError('Negative control failed for unrelated reason')
            negative.append(dict(omitted_mutex=omitted,exact_methods_sha256=sha(folder/'exact_methods.inc'),expected_failure='getter completed without the held required mutex'))
        proof['negative_controls']=negative
        obj=out/'RPC.cpp.obj';deps=out/'rpc.d'
        # Exactly the new source and fresh123 headers, with sealed V6 SDK and
        # authored geometry includes. Compile only: no old/new runtime library.
        rpc_include=[cohort_dependency/'ps2xRuntime/include',cohort_dependency/'ps2xRuntime/src/lib',
            cohort_dependency/'ps2xRuntime/src/lib/Kernel',cohort,generated_root]+include[4:]
        rpc_flags=[cc,'-std=c++20','-O1','-ffp-contract=off','-pthread','-DNOMINMAX','-DWIN32_LEAN_AND_MEAN']+['-I'+str(x) for x in rpc_include]
        staged_rpc=cohort_dependency/'ps2xRuntime/src/lib/Kernel/Syscalls/RPC.cpp'
        proof['actual_rpc_source_sha256']=sha(staged_rpc)
        run('compile_actual_RPC_object',rpc_flags+['-D_MBCS','-DWIN32','-D_WINDOWS','-DNDEBUG','-DPLATFORM_DESKTOP','-DGRAPHICS_API_OPENGL_33',
            '-MMD','-MF',str(deps),'-c',str(staged_rpc),'-o',str(obj)])
        dependency_lists.append(deps);proof['actual_rpc_object_sha256']=sha(obj)
        consumed={}
        for file in dependency_lists:
            # Preserve Windows path separators; POSIX shlex would incorrectly
            # remove them. Only make-escaped whitespace/colons are unescaped.
            text=file.read_text().replace('\\\n',' ')
            match=re.match(r'.*?:\s+(.*)',text,flags=re.S)
            if not match:raise ValueError('Malformed compiler depfile')
            for name in re.findall(r'(?:\\[ \t]|[^\s])+',match.group(1)):
                path=Path(name.replace('\\ ', ' ').replace('\\:',':')).resolve()
                if path.is_relative_to(checkout):
                    relative=path.relative_to(checkout).as_posix();digest=after.get(relative)
                    if digest is None or sha(path)!=digest:raise ValueError('Unqualified dependency header: '+str(path))
                    consumed[str(path)]=digest
                elif path.is_relative_to(kit):
                    relative=path.relative_to(kit).as_posix();digest=kit_files.get(relative)
                    if relative.startswith('source/third_party/PS2Recomp/ps2xRuntime/'):
                        raise ValueError('Older sealed-kit runtime header mixed into fresh123 compile')
                    if digest is None or sha(path)!=digest:raise ValueError('Unsealed V6 include: '+str(path))
                    consumed[str(path)]=digest
                elif path.is_relative_to(cohort_dependency):
                    relative=path.relative_to(cohort_dependency).as_posix();digest=after.get(relative)
                    if digest is None or sha(path)!=digest:raise ValueError('Unqualified staged runtime input: '+str(path))
                    consumed[str(path)]=digest
                elif path.is_relative_to(out):
                    if path not in (out/'harness.cpp',out/'exact_methods.inc') and str(path) not in generated_identities:
                        raise ValueError('Undeclared generated/private compile input: '+str(path))
                    consumed[str(path)]=sha(path)
                else:raise ValueError('Unexpected private header/input: '+str(path))
        proof['consumed_include_sha256']=consumed
        proof['status']='passed'
    except Exception as error:proof.update(status='failed',failure=str(error));raise
    finally:
        proof['authored_sha256']={str(x.relative_to(ROOT)):sha(x) for x in (HERE/'harness.cpp',Path(__file__))}
        (out/'receipt.json').write_text(json.dumps(proof,indent=2)+'\n')
    print(json.dumps({k:proof[k] for k in ('status','full_source_files_verified','observed','real','actual_rpc_object_sha256')}))
if __name__=='__main__':main()
