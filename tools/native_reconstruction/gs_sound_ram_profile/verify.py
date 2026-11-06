#!/usr/bin/env python3
"""Source-qualified GS selection/profile tests; no device/game/full build."""
import argparse,hashlib,json,os,re,subprocess,shutil
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def read(p):return p.read_text(encoding='utf-8')
def write(p,s):p.parent.mkdir(parents=True,exist_ok=True);p.write_text(s,encoding='utf-8',newline='\n')
def block(s,anchor):
    start=s.index(anchor);b=s.index('{',start);depth=0
    for e in range(b,len(s)):
        depth+=(s[e]=='{')-(s[e]=='}')
        if not depth:return s[start:e+1]
    raise ValueError('Unbalanced source '+anchor)
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--tree',type=Path,required=True);p.add_argument('--proof',type=Path,required=True);p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args()
    tree=a.tree.resolve();out=a.output.resolve();cc=shutil.which(a.cxx)
    if not cc or not out.is_relative_to(ROOT/'build-native-sjuni/gs-sound-ram-profile')or out.exists():raise ValueError('Existing compiler and fresh private output required')
    q=json.loads(read(a.proof))
    if q['status']!='passed'or q['applied_count']!=127:raise ValueError('Matching full127 reapply required')
    for n,d in q['source_sha256'].items():
        if sha(tree/n)!=d:raise ValueError('Reapplied source drift '+n)
    for e in q['patches']:
        if sha(ROOT/e['path'])!=e['sha256']:raise ValueError('Patch drift')
    authored={p.name:sha(p) for p in HERE.iterdir()if p.is_file()};app={n:sha(ROOT/n)for n in ('tools/parallel_gs_backend/parallel_backend.cpp','tools/parallel_gs_backend/parallel_backend.h')}
    out.mkdir(parents=True);source=read(ROOT/'tools/parallel_gs_backend/parallel_backend.cpp')
    extracts={'actual_member.inc':block(source,'    bool soundRamProfileObservedV1() const noexcept'),
        'actual_probe.inc':block(source,'bool soundRamProfileObservedV1(gs_backend_bridge::Backend& backend)'),
        'actual_factory.inc':block(source,'gs_backend_bridge::Factory makeFactory(Config config)')}
    for n,s in extracts.items():write(out/n,s+'\n')
    env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','')
    receipt=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),full127_proof_sha256=sha(a.proof),authored=authored,app=app,extracts={n:sha(out/n)for n in extracts},checks=[],game_run=False,device_opened=False,runtime_library_linked=False)
    def run(name,cmd,expected=0):
        r=subprocess.run([str(x)for x in cmd],env=env,capture_output=True,text=True,timeout=90)
        receipt['checks'].append(dict(name=name,command=[str(x)for x in cmd],exit_code=r.returncode,expected_exit=expected,stdout=r.stdout,stderr=r.stderr))
        if r.returncode!=expected:raise RuntimeError(name+':\n'+r.stdout+r.stderr)
    try:
        lib=tree/'ps2xRuntime/src/lib';flags=[cc,'-std=c++20','-O1','-pthread','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-misleading-indentation','-Wno-unused-parameter','-ffp-contract=off','-I'+str(out),'-I'+str(lib),'-I'+str(ROOT/'tools/parallel_gs_backend')]
        if 'clang' in Path(cc).name:flags.append('-Wno-keyword-macro') # read-only private observer in isolated tests
        exe=out/'gs_profile.exe';run('unit_compile',flags+[HERE/'tests.cpp','-o',exe])
        for name in ('basic','unsupported','transitions','busy','races','factory_races','global','global_races'):run(name,[exe,name])
        for name in ('illegal_stop','illegal_destructor'):run(name,[exe,name],86)
        run('actual_route_object',flags+['-MMD','-MF',out/'route.d','-c',lib/'gs_backend_route.cpp','-o',out/'route.o'])
        gs=read(lib/'ps2_gs_gpu.cpp');runtime=read(lib/'ps2_runtime.cpp')
        write(out/'actual_gateway.inc',block(gs,'SoundRamProfileResultV1 acquireSoundRamProfileBeforeRunV1(')+'\n')
        join=block(gs,'void ps2GsJoinWorker()');write(out/'actual_join_guard.inc',join[join.index('{')+1:join.index('    ps2GsRequestWorkerStop();')])
        destructor=block(runtime,'PS2Runtime::~PS2Runtime()');prefix=destructor[:destructor.index('        ps2_cri_audio::shutdown();')+len('        ps2_cri_audio::shutdown();')]
        write(out/'actual_destructor_prefix.inc',prefix+'\n    }catch(...){std::terminate();}\n}\n')
        gateway=out/'gateway.exe';run('gateway_compile',flags+[HERE/'gateway_tests.cpp','-o',gateway])
        for name in ('gateway','refusals','cancel','teardown'):run(name,[gateway,name])
        # Private negative restores the omitted early external-worker join.
        write(out/'actual_destructor_prefix.inc',read(out/'actual_destructor_prefix.inc').replace('joinExternalWorkersOrTerminate();','/* negative: no early audio drain */',1))
        negative=out/'negative_teardown.exe';run('negative_teardown_compile',flags+[HERE/'gateway_tests.cpp','-o',negative]);run('negative_teardown',[negative,'teardown'],87)
        write(out/'actual_destructor_prefix.inc',prefix+'\n    }catch(...){std::terminate();}\n}\n')

        # Private source mutation drops the controls guard, reproducing the
        # boolean-only TOCTOU: a profile can mint during a global initializer.
        route_source=read(lib/'gs_backend_route.cpp');anchor='if(profileTransitionV1_||(controlsV1&&!ownMint))'
        if route_source.count(anchor)!=1:raise ValueError('Global negative-control anchor')
        broken=route_source.replace(anchor,'if(profileTransitionV1_)').replace('const bool ownMint=permit&&permit==globalControlGenerationV1&&globalControlDepthV1==1&&controlsV1==1;','(void)permit;')
        write(out/'negative_global_route.cpp',broken)
        bad_tests=read(HERE/'tests.cpp').replace('#include "gs_backend_route.cpp"','#include "negative_global_route.cpp"')
        write(out/'negative_global_tests.cpp',bad_tests)
        bad=out/'negative_global.exe';run('negative_global_compile',flags+[out/'negative_global_tests.cpp','-o',bad]);run('negative_global',[bad,'global'],1)
        receipt['status']='passed'
    except Exception as e:receipt.update(status='failed',failure=str(e));raise
    finally:
        receipt['authored_postcheck']=[n for n,d in authored.items()if sha(HERE/n)!=d]
        receipt['app_postcheck']=[n for n,d in app.items()if sha(ROOT/n)!=d]
        receipt['source_postcheck']=[n for n,d in q['source_sha256'].items()if sha(tree/n)!=d]
        write(out/'receipt.json',json.dumps(receipt,indent=2)+'\n')
    print(json.dumps({'status':receipt['status'],'checks':len(receipt['checks'])}))
if __name__=='__main__':main()
