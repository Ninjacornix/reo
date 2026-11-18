"""Qualify bounded gate and compile actual guarded Service with a fresh SDK.

No Vulkan/device/game link or execution. Sealed V8 supplies only immutable
third-party graphics headers; current authored headers and fresh SDK are hashed.
"""
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
SERVICE='tools/parallel_gs_backend/resident_geometry/parent/parent_owner_service.hpp'
KIT=ROOT/'build-native-sjuni/candidate-inputs-v8'
KIT_SHA='435ae2791088c3061ffd2caa3617924daa9d1b8815eb441512f4c9f50e5b4ea0'


def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()


def placement(text,version=1):
    declaration=text.index('class Service final : private protocol::Backend {')
    qualifier='reo::native::ram_capture::'+('v2::' if version==2 else '')
    gate=text.index(qualifier+'GraphicsActivity captureActivity_;',declaration)
    first=text.index('mutable std::recursive_mutex hostProtocolMutex_;',declaration)
    constructor=text.index('    Service(Vulkan::Device& d,')
    initial=text.index('captureActivity_(beginCaptureExclusion(c)),',constructor)
    device=text.index('device_(d),',constructor)
    if not declaration<gate<first<constructor<initial<device:raise ValueError('Graphics guard placement lost')
    if 'begin_graphics(c.cold->ram)' not in text[gate:constructor]:raise ValueError('Actual backing not gated')


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--cxx',type=Path,required=True)
    p.add_argument('--checkout',type=Path,required=True)
    p.add_argument('--receipt',type=Path,required=True)
    p.add_argument('--output',type=Path,required=True)
    p.add_argument('--service-version',type=int,choices=(1,2),default=1)
    p.add_argument('--service-only',action='store_true',help='Compile actual Service only; versioned core has separate unit receipts.')
    a=p.parse_args();out=a.output.resolve();tree=a.checkout.resolve();cc=a.cxx.resolve()
    if not out.is_relative_to(ROOT/'build-native-sjuni') or out==ROOT/'build-native-sjuni':raise ValueError('Private output subdirectory required')
    baseline=json.loads(a.receipt.read_bytes())
    if baseline['status']!='passed' or baseline['applied_count']<125 or baseline['base_revision']!='c46d1c7d8ab00fbfa18d2c1f764c559e4e5dc78f':raise ValueError('Qualified fresh125+ SDK required')
    for row in baseline['patches']:
        if sha(ROOT/row['path'])!=row['sha256']:raise ValueError('Dependency patch changed')
    for name,digest in baseline['source_sha256'].items():
        if sha(tree/name)!=digest:raise ValueError('Fresh SDK changed: '+name)
    if sha(KIT/'build-kit.json')!=KIT_SHA:raise ValueError('Sealed graphics input cohort changed')
    kitfiles={row['path']:row['sha256'] for row in json.loads((KIT/'build-kit.json').read_bytes())['files']}
    service_text=(ROOT/SERVICE).read_text(encoding='utf-8');placement(service_text,a.service_version)
    try:placement(service_text.replace('captureActivity_(beginCaptureExclusion(c)),','captureActivity_(),'),a.service_version)
    except ValueError:pass
    else:raise ValueError('Missing-constructor-gate negative control escaped source check')
    out.mkdir(parents=True,exist_ok=True)
    dependency=out/'cohort/third_party/PS2Recomp'
    for name,digest in baseline['source_sha256'].items():
        dest=dependency/name;dest.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(tree/name,dest)
        if sha(dest)!=digest:raise ValueError('SDK staging drift')
    generation_path=ROOT/'build-native-sjuni/candidate-work-v8/generate.json'
    generation=json.loads(generation_path.read_bytes());generated_inputs={}
    for name in ('irq_cpu_sites.inc','heap_control_sites.inc'):
        matches=[(Path(n.removeprefix('\\\\?\\')),h) for n,h in generation['outputs'].items()
                 if n.endswith('\\recomp\\config\\local_source_catalogues\\'+name)]
        if len(matches)!=1 or sha(matches[0][0])!=matches[0][1]:raise ValueError('Existing generated source catalogue changed')
        dest=out/'generated/local_source_catalogues'/name;dest.parent.mkdir(parents=True,exist_ok=True)
        shutil.copyfile(matches[0][0],dest);generated_inputs[str(dest.resolve())]=matches[0][1]
    env=dict(os.environ);env['PATH']=str(cc.parent)+os.pathsep+env.get('PATH','')
    proof=dict(schema=1,status='running',game_run=False,device_opened=False,runtime_library_linked=False,
        compiler=str(cc),compiler_sha256=sha(cc),sdk_receipt_sha256=sha(a.receipt),
        graphics_manifest_sha256=KIT_SHA,checks=[],consumed_include_sha256={},
        service_version=a.service_version,service_only=a.service_only,
        existing_generation_receipt_sha256=sha(generation_path),generated_include_sha256=generated_inputs,
        source_placement_negative_control='missing actual constructor gate rejected')
    authored={str(x.relative_to(ROOT)):sha(x) for x in HERE.iterdir() if x.is_file()}
    authored[SERVICE]=sha(ROOT/SERVICE)
    def run(name,cmd,expected=0):
        result=subprocess.run([str(x) for x in cmd],env=env,capture_output=True,text=True,timeout=180)
        proof['checks'].append(dict(name=name,command=[str(x) for x in cmd],exit=result.returncode,stdout=result.stdout,stderr=result.stderr))
        if result.returncode!=expected:raise RuntimeError(name+':\n'+result.stdout+result.stderr)
        return result
    try:
        flags=[cc,'-std=c++20','-O2','-pthread','-Wall','-Wextra','-Wpedantic','-Werror']
        exe=out/'unit.exe'
        if not a.service_only:
            run('compile_units',flags+[HERE/'cpu_authority_gate.cpp',HERE/'cpu_authority_gate_tests.cpp','-o',exe])
            run('units',[exe])
        # Isolate a source-placement counterexample, without racing raw bytes:
        # only the Service-shaped fixture omits its lifetime guard. Real gate
        # implementation remains unchanged. It must fail pending-state checks.
        tests=(HERE/'cpu_authority_gate_tests.cpp').read_text(encoding='utf-8')
        original=':activity([&]{auto r=gate.begin_graphics(backing);if(r.status!=Status::ok)throw std::runtime_error("service gate");return std::move(r.value);}()),'
        if tests.count(original)!=1:raise ValueError('Service lifetime negative-control boundary changed')
        negative=out/'negative.cpp';negative.write_text(tests.replace(original,':activity(),'),encoding='utf-8',newline='\n')
        bad=out/'negative.exe'
        if not a.service_only:
            run('compile_missing_service_guard',flags+['-I'+str(HERE),HERE/'cpu_authority_gate.cpp',negative,'-o',bad])
            run('missing_service_guard_detected',[bad],expected=1)
        probe=out/'actual_service.cpp'
        probe.write_text('#include "'+SERVICE+'"\nreo_parent_install::Service* actual_construct(Vulkan::Device& d,ParallelGS::GSInterface& gs,std::shared_ptr<reo_resident_live::ProgramBank> target,reo_gpu_vif_upload::ResidentVifUnpack& unpack,const reo_parent_install::Configuration& c,uint64_t epoch,uint64_t generation){return new reo_parent_install::Service(d,gs,std::move(target),unpack,c,epoch,generation);}\n',encoding='utf-8',newline='\n')
        plan=json.loads((KIT/'compile-plan.json').read_bytes())
        boot=next(u for u in plan['units'] if u['sources']==['{work}/project/recomp/reo_bootstrap.cpp'])
        include=[dependency/'ps2xRuntime/include',dependency/'ps2xRuntime/src/lib',dependency/'ps2xRuntime/src/lib/Kernel',out/'cohort',out/'generated',ROOT,ROOT/'tools/parallel_gs_backend/resident_geometry']
        defines=['REO_BUILD_NATIVE_SOUND_RAM_CAPTURE='+str(a.service_version)]
        for option in boot['options']:
            if option.startswith('/I'):
                suffix=option[2:]
                if suffix.startswith('{work}/project/'):
                    relative=suffix[len('{work}/project/'):]
                    if relative.startswith('third_party/PS2Recomp/ps2xRuntime/') or relative in ('.','tools/parallel_gs_backend/resident_geometry'):continue
                    include.append(KIT/'source'/relative)
            elif option.startswith('/D') and not option[2:].startswith('REO_BUILD_NATIVE_'):defines.append(option[2:])
        obj=out/'actual_service.obj';deps=out/'actual_service.d'
        command=[cc,'-std=c++20','-O1','-pthread','-mssse3','-msse4.1','-D_WIN32_WINNT=0x0A00','-DWINVER=0x0A00']+['-D'+d for d in defines]+['-I'+str(i) for i in include]+['-MMD','-MF',deps,'-c',probe,'-o',obj]
        run('actual_service_header_object',command)
        deptext=deps.read_text(encoding='utf-8').replace('\\\n',' ')
        match=re.match(r'.*?:\s+(.*)',deptext,flags=re.S)
        if not match:raise ValueError('Malformed compiler dependencies')
        for item in re.findall(r'(?:\\[ \t]|[^\s])+',match.group(1)):
            path=Path(item.replace('\\ ',' ').replace('\\:',':')).resolve()
            if path.is_relative_to(dependency):digest=baseline['source_sha256'].get(path.relative_to(dependency).as_posix())
            elif path.is_relative_to(KIT):
                rel=path.relative_to(KIT).as_posix()
                if rel.startswith('source/third_party/PS2Recomp/ps2xRuntime/'):raise ValueError('Old runtime header mixed into production probe')
                digest=kitfiles.get(rel)
            elif path==probe:digest=sha(probe)
            elif str(path) in generated_inputs:digest=generated_inputs[str(path)]
            elif path.is_relative_to(ROOT) and not path.is_relative_to(ROOT/'build-native-sjuni'):
                if path.is_relative_to(ROOT/'third_party/PS2Recomp'):raise ValueError('Dirty active dependency included')
                digest=sha(path)
            else:digest=None
            if digest is None or sha(path)!=digest:raise ValueError('Unqualified compile input: '+str(path))
            proof['consumed_include_sha256'][str(path)]=digest
        proof['actual_service_object_sha256']=sha(obj)
        proof['status']='passed'
    except Exception as error:proof.update(status='failed',failure=str(error));raise
    finally:
        proof['authored_sha256']=authored
        proof['source_postcheck']=[n for n,h in authored.items() if sha(ROOT/n)!=h]
        proof['include_postcheck']=[n for n,h in proof['consumed_include_sha256'].items() if sha(Path(n))!=h]
        if proof['source_postcheck'] or proof['include_postcheck']:
            proof.update(status='failed',failure='Input changed during verification')
        proof['limitations']=['Core proves admission/lifetime protocol only, not complete guest/CD writer authority.',
            'Actual Service constructor is compiled, not executed with Vulkan; no linked-game instrumentation witness exists yet.',
            'Service gate is conditional; future candidate must compile all owner paths with the same capture flag and matching sources.']
        (out/'receipt.json').write_text(json.dumps(proof,indent=2)+'\n',encoding='utf-8')
    if proof['source_postcheck'] or proof['include_postcheck']:raise ValueError('Input changed during verification')
    print(json.dumps(dict(status=proof['status'],receipt=str(out/'receipt.json'),includes=len(proof['consumed_include_sha256']))))


if __name__=='__main__':main()
