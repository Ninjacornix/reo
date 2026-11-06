#!/usr/bin/env python3
"""Copy actual wrapper; test structural relays with fake Memory, never RAM authority."""
import argparse,hashlib,json,os,re,shutil,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
SDK=ROOT/'build-native-sjuni/dependency-gs-sound-profile-reapply-v4'
PROOF=ROOT/'build-native-sjuni/dependency-gs-sound-profile-reapply-v4-receipt.json'
PROOF_SHA='909917fc2f766c8a43a10abbc0b94189fa24254ecfaa7f710e4eb24dc941b58a'
KIT=ROOT/'build-native-sjuni/candidate-inputs-v8'
KIT_SHA='435ae2791088c3061ffd2caa3617924daa9d1b8815eb441512f4c9f50e5b4ea0'
CPP=ROOT/'recomp/overrides/native_sound_ram/composite_backend.cpp';HEADER=CPP.with_suffix('.h')
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def read(p):return p.read_text(encoding='utf-8')
def write(p,s):p.parent.mkdir(parents=True,exist_ok=True);p.write_text(s,encoding='utf-8',newline='\n')

def dependencies(path):
    value=read(path).replace('\\\n',' ').split(':',1)[1]
    return [Path(x.replace('\\ ', ' ').replace('\\:',':')).resolve()for x in re.findall(r'(?:\\[ \t]|[^\s])+',value)]

def relay_fixture(body):
    """Omit only whole factory-only scopes; keep tested methods verbatim."""
    scopes=[('runtime_hooks','namespace {\n','\n// One SDK registration'),
            ('static_factory','    static InstallResult install(','\nprivate:'),
            ('free_factory','\nInstallResult install(','\n} // namespace reo::native::sound_ram')]
    removed=[]
    for name,start,end in scopes:
        if body.count(start)!=1 or body.count(end)!=1:raise ValueError('Fixture scope drift '+name)
        first=body.index(start);last=body.index(end,first)
        removed.append(dict(name=name,sha256=hashlib.sha256(body[first:last].encode()).hexdigest(),characters=last-first))
        body=body[:first]+body[last:]
    return body,removed
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();cc=shutil.which(a.cxx);out=a.output.resolve()
    if not cc or out.exists()or not out.is_relative_to(ROOT/'build-native-sjuni/audio-composite-wrapper'):raise ValueError('Compiler and fresh private output required')
    if sha(PROOF)!=PROOF_SHA or sha(KIT/'build-kit.json')!=KIT_SHA:raise ValueError('Final127/sealedV8 input drift')
    proof=json.loads(read(PROOF));kitfiles={x['path']:x['sha256']for x in json.loads(read(KIT/'build-kit.json'))['files']}
    for n,d in proof['source_sha256'].items():
        if sha(SDK/n)!=d:raise ValueError('SDK source drift '+n)
    for e in proof['patches']:
        if sha(ROOT/e['path'])!=e['sha256']:raise ValueError('Patch drift')
    before={str(p.relative_to(ROOT)):sha(p)for p in (CPP,HEADER,CPP.parent/'runtime_memory.h')}
    authored={p.name:sha(p)for p in HERE.iterdir()if p.is_file()};out.mkdir(parents=True)
    body=read(CPP);header=read(HEADER)
    header=header.replace('../native_audio/v2/aggregate.h','recomp/overrides/native_audio/v2/aggregate.h').replace('../native_cd_owner/ram_configuration.h','recomp/overrides/native_cd_owner/ram_configuration.h')
    fixture,omitted=relay_fixture(body)
    write(out/'source/composite_backend.cpp',fixture);write(out/'source/composite_backend.h',header);write(out/'source/runtime_memory.h',read(HERE/'fake_runtime_memory.h'))
    # Exact source-flow review only; this does not execute the actual factory,
    # PreRunSetup implementation, SDK publication, provider or aggregate create.
    positions={name:body.index(anchor)for name,anchor in (
        ('phase','auto setup=runtime.acquirePreRunSetup();'),('prepare','auto prepared=RuntimeMemory::prepare('),
        ('abort_guard','} cleanup{memory};'),('provider','auto provider=output::NativeStreamProvider::create();'),
        ('aggregate','auto built=audio::create('),('wrapper','new CompositeBackend(memory,built.owner->registration())'),
        ('publish','const auto selected=sdk::installBackendWithNativeSoundRamBeforeRunV1('),
        ('abort_join','(void)owner->join();'),('installed','cleanup.installed=true;'))}
    if list(positions.values())!=sorted(positions.values()):raise ValueError('High-level phase/preparation/publication/abort source order changed')
    flags=[cc,'-std=c++20','-O1','-ffunction-sections','-fdata-sections','-Wl,--gc-sections','-pthread','-ffp-contract=off','-fno-fast-math','-mssse3','-msse4.1',
        '-DREO_BUILD_NATIVE_SOUND_RAM_CAPTURE=2','-DREO_GAME_FILE1','-DNOMINMAX','-DWIN32_LEAN_AND_MEAN',
        '-I'+str(out),'-I'+str(SDK/'ps2xRuntime/include'),'-I'+str(SDK/'ps2xRuntime/src/lib'),'-I'+str(SDK/'ps2xRuntime/src/lib/Kernel'),'-I'+str(ROOT),'-I'+str(KIT/'source/third_party/PS2Recomp/out/build/_deps/raylib-src/src')]
    env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','')
    receipt=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),full127_proof_sha256=PROOF_SHA,sealedV8_manifest_sha256=KIT_SHA,production=before,authored=authored,source_flow_positions=positions,private_fixture_omitted_scopes=omitted,private_fixture_sha256=hashlib.sha256(fixture.encode()).hexdigest(),checks=[],real_ram_authority=False,real_sdk_admission=False,game_run=False,device_opened=False)
    def run(name,cmd,expected=0):
        r=subprocess.run([str(x)for x in cmd],env=env,capture_output=True,text=True,timeout=90)
        receipt['checks'].append(dict(name=name,command=[str(x)for x in cmd],exit_code=r.returncode,expected_exit=expected,stdout=r.stdout,stderr=r.stderr))
        if r.returncode!=expected:raise RuntimeError(name+':\n'+r.stdout+r.stderr)
    try:
        dep=out/'wrapper.pre.d';run('qualified_fixture_dependencies',flags+['-MM','-MT','input','-MF',dep,HERE/'tests.cpp'])
        consumed={}
        for path in dependencies(dep):
            digest=sha(path)
            if path.is_relative_to(SDK):
                if digest!=proof['source_sha256'][path.relative_to(SDK).as_posix()]:raise ValueError('Fixture SDK include drift')
            elif path.is_relative_to(KIT):
                if digest!=kitfiles.get(path.relative_to(KIT).as_posix()):raise ValueError('Fixture sealed header drift')
            elif path.is_relative_to(out/'source'):pass
            elif path.is_relative_to(ROOT/'build-native-sjuni')or path.is_relative_to(ROOT/'build-ninja')or path.is_relative_to(ROOT/'third_party'):raise ValueError('Unqualified private include '+str(path))
            elif not path.is_relative_to(ROOT):raise ValueError('Unidentified project include '+str(path))
            consumed[str(path)]=digest
        receipt['consumed_project_inputs']=consumed
        exe=out/'wrapper.exe';actual=out/'wrapper.d';run('compile_actual_wrapper_fake_memory',flags+['-MMD','-MT','input','-MF',actual,HERE/'tests.cpp','-o',exe])
        if set(dependencies(actual))!={Path(n)for n in consumed}:raise ValueError('Fixture include set drift')
        for name in ('relays','companion','lifecycle','stage','lifetime'):run(name,[exe,name])
        # Private negatives, changing only one production expression each.
        anchors=[('owner','s.table_.api.pcm.ensure_host_output(s.table_.owner.get());','s.table_.api.pcm.ensure_host_output(x);','relays',41),
            ('render','s.table_.api.render_admitted(s.table_.owner.get(),call,out,n);','sdk::SoundCall replacement;s.table_.api.render_admitted(s.table_.owner.get(),replacement,out,n);','relays',42),
            ('retire','s.table_.api.pcm.request_stop(s.table_.owner.get());','(void)s.memory_->retire_after_outer_drain();s.table_.api.pcm.request_stop(s.table_.owner.get());','lifecycle',1)]
        for name,anchor,changed,scenario,code in anchors:
            if fixture.count(anchor)!=1:raise ValueError('Negative anchor drift '+name)
            write(out/'source/composite_backend.cpp',fixture.replace(anchor,changed))
            bad=out/('negative_'+name+'.exe');run('compile_negative_'+name,flags+[HERE/'tests.cpp','-o',bad]);run('negative_'+name,[bad,scenario],code)
        write(out/'source/composite_backend.cpp',fixture);receipt['status']='passed'
        receipt['consumed_postcheck']=[n for n,d in consumed.items()if sha(Path(n))!=d]
        if receipt['consumed_postcheck']:raise ValueError('Fixture input drift')
    except Exception as e:receipt.update(status='failed',failure=str(e));raise
    finally:
        receipt['production_postcheck']=[n for n,d in before.items()if sha(ROOT/n)!=d]
        receipt['authored_postcheck']=[n for n,d in authored.items()if sha(HERE/n)!=d]
        write(out/'receipt.json',json.dumps(receipt,indent=2)+'\n')
    print(json.dumps({'status':receipt['status'],'checks':len(receipt['checks'])}))
if __name__=='__main__':main()
