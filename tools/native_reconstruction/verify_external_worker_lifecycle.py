#!/usr/bin/env python3
"""Verify new external-worker methods from a supplied patched runtime checkout.

Compile/run exact method and guard extractions with mocked runtime surroundings.
No game or runtime library is linked. Optional --syntax checks the actual runtime
TU using a sealed SDK and explicit owned ELF catalogue inputs in ignored output.
Neither the checkout nor the sealed SDK is modified.
"""
from pathlib import Path
import argparse
import hashlib
import json
import os
import shutil
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]
parser=argparse.ArgumentParser(description=__doc__)
parser.add_argument('--checkout',required=True,type=Path)
parser.add_argument('--output',type=Path,default=ROOT/'build-native-sjuni/external-worker-verification')
parser.add_argument('--cxx',default='g++')
parser.add_argument('--syntax',action='store_true')
parser.add_argument('--clang')
parser.add_argument('--kit',type=Path)
parser.add_argument('--elf',type=Path)
parser.add_argument('--catalogue-manifest',type=Path,default=ROOT/'recomp/config/local_source_catalogues.json')
args=parser.parse_args()
DEP=args.checkout.resolve()
OUT=args.output.resolve()
if not OUT.is_relative_to(ROOT/'build-native-sjuni') or OUT==ROOT/'build-native-sjuni':
    parser.error('Output must be a separate ignored directory below build-native-sjuni')
OUT.mkdir(parents=True,exist_ok=True)
found=shutil.which(args.cxx)
if not found:parser.error('Existing C++20 compiler unavailable; pass --cxx')
CXX=Path(found).resolve()
if args.syntax and not all((args.clang,args.kit,args.elf)):
    parser.error('--syntax requires --clang, --kit and --elf')
KIT=args.kit.resolve() if args.kit else None
SDK=KIT/'source' if KIT else None
CLANG=Path(args.clang).resolve() if args.clang else None
CPP = DEP / 'ps2xRuntime/src/lib/ps2_runtime.cpp'
HEADER = DEP / 'ps2xRuntime/include/ps2_runtime.h'
text = CPP.read_text(encoding='utf-8')
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
receipt = dict(schema=1, scope='isolated exact-method extraction with mocked runtime surroundings; optional full public runtime syntax check',
               game_run=False, game_built=False, runtime_linked=False,
               source_sha256={str(p):sha(p) for p in (CPP,HEADER)}, checks=[],
               verifier_sha256=sha(Path(__file__)),full_runtime_syntax_requested=args.syntax)

def run(name, command, expected=0):
    result = subprocess.run([str(x) for x in command], cwd=ROOT, text=True, capture_output=True,timeout=90)
    receipt['checks'].append(dict(name=name,command=[str(x) for x in command],exit_code=result.returncode,
                                 stdout=result.stdout,stderr=result.stderr))
    (OUT/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print(name, result.returncode)
    if result.returncode != expected:
        print(result.stdout,result.stderr)
        raise SystemExit(name+' failed')

def method(signature):
    start=text.index(signature)
    end=text.index('\n}\n',start)+3
    return text[start:end]

interface=HEADER.read_text(encoding='utf-8')
interface=interface[interface.index('    class ExternalWorker\n'):interface.index('    using RecompiledFunction')]
fields=HEADER.read_text(encoding='utf-8')
fields=fields[fields.index('    using ExternalWorkerList'):fields.index('    // TODO remove this later')]
assert '#define PS2_RUNTIME_HAS_EXTERNAL_WORKERS 1' in HEADER.read_text(encoding='utf-8')
guard=text[text.index('    struct ExternalWorkerRunUnwind\n'):text.index('    ps2_sched::g_shutdown.store(false',text.index('void PS2Runtime::run()'))]
game_guard=text[text.index('    struct GameThreadRunUnwind\n'):text.index('    gameThread = std::thread([&]()')]
present_guard=text[text.index('    struct PresentFrameLifetime\n'):text.index('    s_presentFrame = &presentFrame;')]
run_body=text[text.index('void PS2Runtime::run()'):]
assert run_body.index('std::atomic<bool> gameThreadFinished') < run_body.index('struct GameThreadRunUnwind') < run_body.index('gameThread = std::thread')
assert run_body.index('struct PresentFrameLifetime') < run_body.index('s_presentFrame = &presentFrame;')
shutdown=run_body[run_body.index('    ps2_syscalls::joinAllGuestHostThreads();'):]
assert shutdown.index('joinExternalWorkersOrTerminate') < shutdown.index('reo_async_vif::shutdown') < shutdown.index('ps2_syscalls::finishRuntimeStop')
destructor=text[text.index('PS2Runtime::~PS2Runtime()'):text.index('bool PS2Runtime::syncCoreSubsystems()')]
assert destructor.index('joinExternalWorkersOrTerminate') < destructor.index('ps2_syscalls::finishRuntimeStop')
receipt['source_placement_checks']='capture/guard order, presentation publication guard, normal pre-VIF/GS/registry join, destructor pre-registry join'

source=r'''
#include <atomic>
#include <condition_variable>
#include <cstdlib>
#include <exception>
#include <functional>
#include <iostream>
#include <memory>
#include <mutex>
#include <stdexcept>
#include <string>
#include <thread>
#include <vector>
#define CHECK(x) do { if(!(x)) throw std::runtime_error(#x); } while(false)
namespace ps2_sched { std::atomic<bool> g_shutdown{false}; void notifyAll(){} }
void ps2GsRequestWorkerStop(){}
namespace reo_async_vif { void requestStop(int){} }
namespace ps2_syscalls { void requestRuntimeWorkerStop(){} }
class PS2Runtime;
thread_local unsigned guestDepth=0;
unsigned ps2ActualGuestExecutionDepth(PS2Runtime*) {return guestDepth;}
class PS2Runtime {
public:
''' + interface + r'''
    std::atomic<bool> m_stopRequested{false};
''' + fields + r'''
    int m_memory{};
    void requestStop();
    bool externalWorkerResetAllowed();
    void beginExternalWorkerRun();
    void joinExternalWorkersOrTerminate() noexcept;
    void exception_path(unsigned stage);
    bool stopped() const { return m_stopRequested.load(); }
};
''' + '\n'.join(method(s) for s in [
    'bool PS2Runtime::registerExternalWorker(', 'bool PS2Runtime::externalWorkerResetAllowed()',
    'void PS2Runtime::beginExternalWorkerRun()', 'void PS2Runtime::joinExternalWorkersOrTerminate()',
    'void PS2Runtime::requestStop()']) + r'''
struct FakeWorker : PS2Runtime::ExternalWorker {
    std::atomic<unsigned> stops{0}, joins{0};
    std::function<void()> onStop;
    bool result=true;
    void requestStop() noexcept override { stops.fetch_add(1); if(onStop)onStop(); }
    bool join() noexcept override {joins.fetch_add(1); return result;}
};
std::atomic<bool> captureAlive{false},presentationAlive{false};
std::atomic<unsigned> captureFaults{0};
std::function<void(bool)>* exposedFrame=nullptr;
struct CaptureSentinel {
    std::atomic<bool>& alive;
    explicit CaptureSentinel(std::atomic<bool>& value):alive(value){alive=true;}
    ~CaptureSentinel(){alive=false;}
};
void PS2Runtime::exception_path(unsigned stage) {
    auto& runtime=*this;
''' + guard + r'''
    if(stage==0)throw std::runtime_error("injected setup failure");
    CaptureSentinel presentationSentinel(presentationAlive);
    std::function<void(bool)> presentFrame=[](bool){CHECK(presentationAlive);};
    auto*& s_presentFrame=exposedFrame;
''' + present_guard + r'''
    s_presentFrame=&presentFrame;
    if(stage==1)throw std::runtime_error("injected modal installation failure");
    CaptureSentinel captureSentinel(captureAlive);
    std::atomic<bool> gameThreadFinished{false};
    std::thread gameThread;
''' + game_guard + r'''
    gameThread=std::thread([&]{
        while(!runtime.stopped())std::this_thread::yield();
        if(!captureAlive||!presentationAlive){captureFaults.fetch_add(1);return;}
        gameThreadFinished=true;
        (*exposedFrame)(false);
    });
    throw std::runtime_error("injected run failure");
}
int main(int argc,char** argv) {
    std::set_terminate([]{std::_Exit(77);});
    if(argc>1) {
        PS2Runtime runtime;
        auto worker=std::make_shared<FakeWorker>();
        runtime.registerExternalWorker(worker);
        if(std::string(argv[1])=="failed-join")worker->result=false;
        else guestDepth=1;
        runtime.joinExternalWorkersOrTerminate();
        return 99;
    }
    {
        PS2Runtime runtime;
        CHECK(!runtime.registerExternalWorker({}));
        auto worker=std::make_shared<FakeWorker>();
        auto raw=worker.get();
        std::weak_ptr<FakeWorker> weak=worker;
        CHECK(runtime.registerExternalWorker(worker));
        CHECK(!runtime.registerExternalWorker(worker));
        CHECK(!runtime.externalWorkerResetAllowed());
        worker.reset();
        CHECK(!weak.expired());
        runtime.beginExternalWorkerRun();
        CHECK(!runtime.registerExternalWorker(std::make_shared<FakeWorker>()));
        runtime.requestStop();
        runtime.joinExternalWorkersOrTerminate();
        CHECK(raw->stops>=1 && raw->joins==1);
        bool rejected=false;
        try{runtime.beginExternalWorkerRun();}catch(const std::logic_error&){rejected=true;}
        CHECK(rejected);
        CHECK(!weak.expired());
    }
    std::cout<<"ownership/registration/reset/one-shot: PASS\n";
    {
        PS2Runtime runtime;
        auto worker=std::make_shared<FakeWorker>();
        CHECK(runtime.registerExternalWorker(worker));
        std::atomic<unsigned> reentered{0};
        worker->onStop=[&]{
            CHECK(!runtime.registerExternalWorker(std::make_shared<FakeWorker>()));
            runtime.requestStop();
            reentered.fetch_add(1);
        };
        runtime.requestStop();
        runtime.joinExternalWorkersOrTerminate();
        CHECK(reentered==2);
    }
    std::cout<<"stop callback reentry outside registration lock: PASS\n";
    for(unsigned round=0;round<250;++round) {
        PS2Runtime runtime;
        std::vector<std::shared_ptr<FakeWorker>> workers;
        std::vector<bool> accepted(16,false);
        for(unsigned i=0;i<16;++i)workers.push_back(std::make_shared<FakeWorker>());
        std::atomic<bool> go{false};
        std::thread registerer([&]{while(!go.load()){};for(unsigned i=0;i<16;++i)accepted[i]=runtime.registerExternalWorker(workers[i]);});
        std::thread stopper([&]{while(!go.load()){};runtime.requestStop();});
        go=true;
        registerer.join();stopper.join();
        runtime.joinExternalWorkersOrTerminate();
        for(unsigned i=0;i<16;++i) {
            CHECK((workers[i]->stops>0)==accepted[i]);
            CHECK((workers[i]->joins==1)==accepted[i]);
        }
    }
    std::cout<<"250 registration/stop races: PASS\n";
    for(unsigned round=0;round<250;++round) {
        PS2Runtime runtime;
        auto worker=std::make_shared<FakeWorker>();
        CHECK(runtime.registerExternalWorker(worker));
        std::atomic<bool> go{false};
        std::thread runner([&]{while(!go.load()){};try{runtime.beginExternalWorkerRun();}catch(const std::logic_error&){};});
        std::thread stopper([&]{while(!go.load()){};runtime.requestStop();});
        go=true;runner.join();stopper.join();
        CHECK(runtime.stopped() && worker->stops>0);
        runtime.joinExternalWorkersOrTerminate();
    }
    std::cout<<"250 run-start/stop races: PASS\n";
    {
        PS2Runtime runtime;
        runtime.requestStop();
        CHECK(!runtime.registerExternalWorker(std::make_shared<FakeWorker>()));
        runtime.beginExternalWorkerRun();
        CHECK(!runtime.stopped() && runtime.externalWorkerResetAllowed());
        runtime.requestStop();runtime.beginExternalWorkerRun();
        CHECK(!runtime.stopped());
    }
    std::cout<<"no-worker restart compatibility: PASS\n";
    for(unsigned stage:{0,1,2}) {
        PS2Runtime runtime;
        auto worker=std::make_shared<FakeWorker>();
        CHECK(runtime.registerExternalWorker(worker));
        runtime.beginExternalWorkerRun();
        try{runtime.exception_path(stage);}catch(const std::runtime_error&){}
        CHECK(runtime.stopped() && worker->joins>=1);
        CHECK(exposedFrame==nullptr && captureFaults==0);
        CHECK(!captureAlive && !presentationAlive);
    }
    std::cout<<"setup/modal/game exception guards + capture sentinels + presentation reset: PASS\n";
    {
        struct BlockingWorker:PS2Runtime::ExternalWorker {
            std::mutex mutex;
            std::condition_variable cv;
            bool released=false,started=false,registry=true;
            std::atomic<bool> exited{false};
            std::thread thread;
            BlockingWorker():thread([this]{
                std::unique_lock lock(mutex);started=true;cv.notify_all();
                cv.wait(lock,[this]{return released;});
                CHECK(registry);exited=true;
            }){}
            void requestStop() noexcept override{}
            bool join() noexcept override{if(thread.joinable())thread.join();return exited;}
        };
        PS2Runtime runtime;
        auto worker=std::make_shared<BlockingWorker>();
        CHECK(runtime.registerExternalWorker(worker));
        {std::unique_lock lock(worker->mutex);worker->cv.wait(lock,[&]{return worker->started;});}
        std::atomic<bool> clearing{false};
        std::thread shutdown([&]{runtime.requestStop();runtime.joinExternalWorkersOrTerminate();clearing=true;});
        CHECK(!worker->exited && !clearing);
        {std::lock_guard lock(worker->mutex);worker->released=true;worker->cv.notify_all();}
        shutdown.join();
        CHECK(clearing && worker->exited);
    }
    std::cout<<"join retains callback/provider until registry-clear boundary: PASS\n";
}
'''
(OUT/'lifecycle_methods.cpp').write_text(source,newline='\n')
run('compile_exact_methods', [CXX,'-std=c++20','-O1','-pthread','-Wall','-Wextra','-Wpedantic','-Werror',
                              OUT/'lifecycle_methods.cpp','-o',OUT/'lifecycle_methods.exe'])
run('lifecycle_methods', [OUT/'lifecycle_methods.exe'])
run('join_failure_fail_closed', [OUT/'lifecycle_methods.exe','failed-join'],77)
run('guest_lock_fail_closed', [OUT/'lifecycle_methods.exe','guest-lock'],77)

# Syntax-check the real patched public runtime TU, not merely the extraction.
# Its external raylib headers come from the sealed SDK; no library is linked.
if args.syntax:
    # Root-relative authored includes must resolve to the SAME supplied patched
    # checkout, not a second copy in the SDK or the active dependency checkout.
    link=OUT/'project/third_party/PS2Recomp'
    link.parent.mkdir(parents=True,exist_ok=True)
    if link.exists():
        if link.resolve()!=DEP:parser.error('Existing output junction targets another checkout; use new --output')
    elif os.name=='nt':
        quote=lambda value: "'" + str(value).replace("'","''") + "'"
        run('private_include_junction',['powershell','-NoProfile','-Command',
            'New-Item -ItemType Junction -Path '+quote(link)+' -Target '+quote(DEP)+' | Out-Null'])
    else:
        os.symlink(DEP,link,target_is_directory=True)
    plan=json.loads((KIT/'compile-plan.json').read_text(encoding='utf-8'))
    unit=next(u for u in plan['units'] if any(s.endswith('/ps2_runtime.cpp') for s in u['sources']))
    flags=['-I',str(OUT/'project')]
    for option in unit['options']:
        if option.startswith('/I'):
            path=option[2:].replace('{work}/project/',str(SDK).replace('\\','/')+'/')
            original=str(SDK/'third_party/PS2Recomp').replace('\\','/')
            if path.startswith(original+'/ps2xRuntime'):path=str(DEP).replace('\\','/')+path[len(original):]
            flags+=['-I',path]
        elif option.startswith('/D'): flags+=['-D'+option[2:]]
    flags+=['-I',str(ROOT/'tools/parallel_gs_backend/resident_geometry'),'-I',str(ROOT),'-DNOMINMAX','-msse4.1']
    run('private_owned_catalogues', [sys.executable,ROOT/'tools/local_build/generate_catalogues.py',
        '--elf',args.elf.resolve(),'--manifest',args.catalogue_manifest.resolve(),
        '--output',OUT/'local_source_catalogues'])
    flags+=['-I',str(OUT)]
    run('full_public_runtime_syntax', [CLANG,'-std=c++20','-fsyntax-only',*flags,CPP])
    receipt['syntax_inputs_sha256']={str(p):sha(p) for p in
        (KIT/'compile-plan.json',KIT/'build-kit.json',args.elf.resolve(),args.catalogue_manifest.resolve())}
receipt['status']='passed'
receipt['generated_test_sha256']=sha(OUT/'lifecycle_methods.cpp')
receipt['compiler_sha256']={str(p):sha(p) for p in (CXX,CLANG) if p}
(OUT/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
