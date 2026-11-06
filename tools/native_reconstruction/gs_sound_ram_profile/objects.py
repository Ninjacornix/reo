#!/usr/bin/env python3
"""Compile matching127 route/runtime/GS and actual app owner objects, never link."""
import argparse,hashlib,json,os,re,shutil,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def deps(p):
    s=p.read_text().replace('\\\n',' ');s=s.split(':',1)[1]
    return [Path(x.replace('\\ ', ' ').replace('\\:',':')).resolve()for x in re.findall(r'(?:\\[ \t]|[^\s])+',s)]
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--tree',type=Path,required=True);p.add_argument('--proof',type=Path,required=True);p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();tree=a.tree.resolve();out=a.output.resolve();cc=shutil.which(a.cxx)
    if not cc or out.exists()or not out.is_relative_to(ROOT/'build-native-sjuni/gs-sound-ram-profile'):raise ValueError('Existing compiler/fresh private output required')
    q=json.loads(a.proof.read_bytes());assert q['status']=='passed'and q['applied_count']==127
    for n,d in q['source_sha256'].items():
        if sha(tree/n)!=d:raise ValueError('127 source drift '+n)
    for e in q['patches']:
        if sha(ROOT/e['path'])!=e['sha256']:raise ValueError('Patch drift')
    out.mkdir(parents=True);cohort=out/'cohort';sdk=cohort/'third_party/PS2Recomp'
    # Runtime source only: required for project-qualified includes without ever
    # admitting the older active SDK. No libraries, private build or cache copy.
    shutil.copytree(tree/'ps2xRuntime',sdk/'ps2xRuntime')
    kit=ROOT/'build-native-sjuni/candidate-inputs-v8'
    kit_sha='435ae2791088c3061ffd2caa3617924daa9d1b8815eb441512f4c9f50e5b4ea0'
    if sha(kit/'build-kit.json')!=kit_sha:raise ValueError('Sealed V8 graphics cohort drift')
    kitfiles={row['path']:row['sha256']for row in json.loads((kit/'build-kit.json').read_bytes())['files']}
    plan_path=kit/'compile-plan.json';plan_sha='45d04b5734479a6c97270f9fe2e6788b50dfebc049837d8eeea88cda27ef0c02'
    if sha(plan_path)!=plan_sha:raise ValueError('Sealed V8 compile-plan drift')
    generation_path=ROOT/'build-native-sjuni/candidate-work-v8/generate.json'
    generation_sha='864b997e4b0db93b281a50513919232483b43ad0e43df8ad0ebd0552438aa5e3'
    if sha(generation_path)!=generation_sha:raise ValueError('Owned generated catalogue receipt drift')
    generation=json.loads(generation_path.read_bytes());generated_inputs={}
    for name in ('irq_cpu_sites.inc','heap_control_sites.inc'):
        matches=[(Path(n.removeprefix('\\\\?\\')),d)for n,d in generation['outputs'].items()if n.endswith('\\recomp\\config\\local_source_catalogues\\'+name)]
        if len(matches)!=1 or sha(matches[0][0])!=matches[0][1]:raise ValueError('Generated catalogue drift')
        dest=out/'generated/local_source_catalogues'/name;dest.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(matches[0][0],dest);generated_inputs[str(dest.resolve())]=matches[0][1]
    include=[cohort,sdk/'ps2xRuntime/include',sdk/'ps2xRuntime/src/lib',sdk/'ps2xRuntime/src/lib/Kernel',out/'generated',ROOT,ROOT/'tools/parallel_gs_backend',ROOT/'tools/parallel_gs_backend/resident_gs',ROOT/'tools/parallel_gs_backend/resident_geometry']
    plan=json.loads(plan_path.read_bytes())
    for unit in (next(u for u in plan['units']if u['sources']==['{work}/project/tools/parallel_gs_backend/parallel_backend.cpp']),next(u for u in plan['units']if u['sources']==['{work}/project/recomp/reo_bootstrap.cpp'])):
        for option in unit['options']:
            if not option.startswith('/I{work}/project/'):continue
            rel=option[len('/I{work}/project/'):]
            if rel.startswith('third_party/PS2Recomp/ps2xRuntime/')or rel in ('.','tools/parallel_gs_backend','tools/parallel_gs_backend/resident_gs','tools/parallel_gs_backend/resident_geometry'):continue
            path=kit/'source'/rel
            if path not in include:include.append(path)
    flags=[cc,'-std=c++20','-O1','-ffp-contract=off','-fno-fast-math','-mssse3','-msse4.1','-pthread','-DNOMINMAX','-DWIN32_LEAN_AND_MEAN','-DWIN32','-D_WINDOWS','-DNDEBUG','-DPLATFORM_DESKTOP','-DGRAPHICS_API_OPENGL_33','-DGRANITE_SHIPPING','-DHAVE_WSI_DXGI_INTEROP','-DREO_PLATFORM_WINDOWS','-DREO_GAME_FILE1','-DREO_BUILD_NATIVE_SOUND_RAM_CAPTURE=2']+['-I'+str(x)for x in include]
    env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','')
    receipt=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),full127_proof_sha256=sha(a.proof),graphics_manifest_sha256=kit_sha,compile_plan_sha256=plan_sha,generation_receipt_sha256=generation_sha,generated_inputs=generated_inputs,objects={},checks=[],consumed_project_inputs={},game_run=False,device_opened=False,libraries_linked=False)
    def run(name,cmd):
        r=subprocess.run([str(x)for x in cmd],env=env,capture_output=True,text=True,timeout=180)
        receipt['checks'].append(dict(name=name,command=[str(x)for x in cmd],exit_code=r.returncode,stdout=r.stdout,stderr=r.stderr))
        if r.returncode:raise RuntimeError(name+':\n'+r.stderr)
    try:
        for name,source in [('route',sdk/'ps2xRuntime/src/lib/gs_backend_route.cpp'),('runtime',sdk/'ps2xRuntime/src/lib/ps2_runtime.cpp'),('gs',sdk/'ps2xRuntime/src/lib/ps2_gs_gpu.cpp'),('parallel',ROOT/'tools/parallel_gs_backend/parallel_backend.cpp')]:
            dep=out/(name+'.pre.d');run(name+'_dependencies',flags+['-MM','-MT','input','-MF',dep,source]);inputs={}
            for path in deps(dep):
                if path.is_relative_to(sdk):
                    expected=q['source_sha256'][path.relative_to(sdk).as_posix()]
                    if sha(path)!=expected:raise ValueError('Staged127 drift '+str(path))
                elif path.is_relative_to(kit):
                    rel=path.relative_to(kit).as_posix()
                    if rel.startswith('source/third_party/PS2Recomp/ps2xRuntime/'):raise ValueError('Old sealed SDK header mixed '+str(path))
                    expected=kitfiles.get(rel)
                    if expected is None or sha(path)!=expected:raise ValueError('Sealed graphics/raylib input drift '+str(path))
                elif str(path)in generated_inputs:
                    if sha(path)!=generated_inputs[str(path)]:raise ValueError('Staged generated input drift')
                elif path.is_relative_to(ROOT/'build-ninja')or path.is_relative_to(ROOT/'third_party')or path.is_relative_to(ROOT/'build-native-sjuni'):
                    raise ValueError('Unqualified private build/active dependency include '+str(path))
                elif not path.is_relative_to(ROOT):raise ValueError('Unidentified project header '+str(path))
                inputs[str(path)]=sha(path)
            obj=out/(name+'.o');actual=out/(name+'.d');run(name+'_actual_object',flags+['-MMD','-MT','input','-MF',actual,'-c',source,'-o',obj])
            if set(deps(actual))!={Path(n)for n in inputs}:raise ValueError('Consumed include set changed '+name)
            for n,d in inputs.items():
                if sha(Path(n))!=d:raise ValueError('Compile source/header changed '+n)
            receipt['objects'][name]=sha(obj);receipt['consumed_project_inputs'].update(inputs)
        receipt['status']='passed'
    except Exception as e:receipt.update(status='failed',failure=str(e));raise
    finally:
        receipt['source_postcheck']=[n for n,d in q['source_sha256'].items()if sha(tree/n)!=d]
        (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps({'status':receipt['status'],'objects':len(receipt['objects']),'project_inputs':len(receipt['consumed_project_inputs'])}))
if __name__=='__main__':main()
