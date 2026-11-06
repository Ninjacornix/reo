#!/usr/bin/env python3
"""Qualify cooperating Pad writes; no game/device/full runtime link."""
import argparse,hashlib,json,os,re,shutil,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[4];HERE=Path(__file__).resolve().parent
BRIDGE=ROOT/'recomp/overrides/reo_hw_bridge.cpp';HEADER=ROOT/'recomp/overrides/reo_hw_bridge.h'
KIT=ROOT/'build-native-sjuni/candidate-inputs-v8'
KIT_SHA='435ae2791088c3061ffd2caa3617924daa9d1b8815eb441512f4c9f50e5b4ea0'
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def read(p):return p.read_text(encoding='utf-8')
def write(p,s):p.parent.mkdir(parents=True,exist_ok=True);p.write_text(s,encoding='utf-8',newline='\n')
def block(s,start):
    i=s.index(start);b=s.index('{',i);depth=0
    for e in range(b,len(s)):
        depth+=(s[e]=='{')-(s[e]=='}')
        if not depth:return s[i:e+1]
    raise ValueError('Unbalanced '+start)
def placement(text):
    body=block(text,'void pad2FeederLoop()')
    if body.count('auto ramWriter=pad2BeginRamWrite(rd,socks.size());')!=1:raise ValueError('Actual Pad writer guard absent')
    guard=body.index('auto ramWriter=pad2BeginRamWrite(rd,socks.size());');last=body.index('copyBytes(rec + 0x7C')
    snapshot=body.index('work = g_pad2.workAddr;');first=body.index('copyBytesForBank(rd, rd + (work')
    if not snapshot<guard<first<last:raise ValueError('Actual dynamic Pad addresses not covered')
    if 'g_pad2.m' in body[guard:last]:raise ValueError('Pad mutex reacquired under writer')
    scope=body[body.index('            {',body.index('uint32_t work = 0;')):guard]
    if scope.count('{')!=scope.count('}'):raise ValueError('Writer acquired while Pad mutex held')
    success=text.index('m_nativeRamWriterBacking = runtime.memory().getRDRAM();')
    if not text.index('ReoTraceLogger::instance().init();')<success<text.index('void ReoHwBridge::shutdown()'):raise ValueError('Witness before successful init')
    shut=block(text,'void ReoHwBridge::shutdown()')
    if not shut.index('m_nativeRamWriterBacking = nullptr;')<shut.index('reoPad2Stop();'):raise ValueError('Shutdown witness not withdrawn')
    init=block(text,'bool ReoHwBridge::init(')
    if not init.index('if (m_runtime != nullptr)')<init.index('return true;')<init.index('m_nativeRamWriterBacking = nullptr;'):raise ValueError('Double init withdraws successful witness')
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',type=Path,required=True);p.add_argument('--checkout',type=Path,required=True)
    p.add_argument('--receipt',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args()
    out=a.output.resolve();tree=a.checkout.resolve();cc=a.cxx.resolve()
    if out.exists()or not out.is_relative_to(ROOT/'build-native-sjuni'):raise ValueError('Fresh isolated output required')
    baseline=json.loads(read(a.receipt))
    if baseline['status']!='passed'or baseline['applied_count']!=126 or sha(a.receipt)!='2de11297c268e453888341b7f3ed44012ae51bdd10c9baa39a168e5cade97ec0':raise ValueError('Exact fresh126-v5 required')
    for row in baseline['patches']:
        if sha(ROOT/row['path'])!=row['sha256']:raise ValueError('Public patch drift')
    for n,h in baseline['source_sha256'].items():
        if sha(tree/n)!=h:raise ValueError('SDK source drift '+n)
    if sha(KIT/'build-kit.json')!=KIT_SHA:raise ValueError('Sealed kit drift')
    identity=json.loads(read(HERE/'cohort_identity.json'))
    for name,digest in identity['source_sha256'].items():
        if sha(ROOT/name)!=digest:raise ValueError('Frozen authored cohort drift '+name)
    text=read(BRIDGE);placement(text)
    try:placement(text.replace('auto ramWriter=pad2BeginRamWrite(rd,socks.size());',''))
    except ValueError:pass
    else:raise ValueError('Missing writer negative source check escaped')
    out.mkdir(parents=True);env=dict(os.environ);env['PATH']=str(cc.parent)+os.pathsep+env.get('PATH','')
    proof=dict(schema=1,status='running',compiler=str(cc),compiler_sha256=sha(cc),sdk_receipt_sha256=sha(a.receipt),checks=[],game_run=False,device_opened=False,runtime_library_linked=False,consumed_include_sha256={})
    authored={str(p.relative_to(ROOT)):sha(p)for p in HERE.iterdir()if p.is_file()}
    authored.update({str(p.relative_to(ROOT)):sha(p)for p in (BRIDGE,HEADER)})
    def run(name,cmd,expected=0):
        r=subprocess.run([str(x)for x in cmd],env=env,text=True,capture_output=True,timeout=180)
        proof['checks'].append(dict(name=name,command=[str(x)for x in cmd],exit=r.returncode,expected=expected,stdout=r.stdout,stderr=r.stderr))
        if r.returncode!=expected:raise RuntimeError(name+':\n'+r.stdout+r.stderr)
    try:
        flags=[cc,'-std=c++20','-O1','-pthread','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-misleading-indentation','-Wno-unused-but-set-variable']
        unit=out/'unit.exe';run('compile_unit',flags+[HERE/'cpu_authority_gate.cpp',HERE/'cpu_authority_gate_tests.cpp','-o',unit]);run('unit',[unit])
        # Private boundary fixtures change only initial ticket seed or inject a
        # throw after reservation. Production metadata/API has no test hooks.
        tiny=out/'ticket_boundary';seed='next_ticket{}';header=read(HERE/'cpu_authority_gate.hpp')
        if header.count(seed)!=1:raise ValueError('Ticket seed boundary changed')
        write(tiny/'cpu_authority_gate.hpp',header.replace(seed,'next_ticket{18446744073709551614ull}'))
        write(tiny/'cpu_authority_gate.cpp',read(HERE/'cpu_authority_gate.cpp'))
        write(tiny/'test.cpp','''#include "cpu_authority_gate.hpp"
#include <iostream>
using namespace reo::native::ram_capture::v2;
int main(){Coordinator gate;int backing{};{auto w=gate.begin_cpu_writer(&backing);if(!w.value)return1;}
if(gate.wait_cpu_group(&backing).status!=Status::capacity||gate.begin_cpu_writer(&backing).status!=Status::capacity)return 2;
{auto p=gate.try_cpu_group(&backing);if(!p.value)return 3;}auto o=gate.observe(&backing);if(o.cpu_groups||o.readers_waiting||o.writers_waiting)return 4;
std::cout<<"ticket exhaustion refused without wrap\\n";}
'''.replace('return1','return 1'))
        exe=tiny/'test.exe';run('compile_ticket_boundary',flags+[tiny/'cpu_authority_gate.cpp',tiny/'test.cpp','-o',exe]);run('ticket_boundary',[exe])
        fault=out/'wait_exception';write(fault/'cpu_authority_gate.hpp',header);code=read(HERE/'cpu_authority_gate.cpp')
        for needle in ('try{changed_.wait(lock,[&]{\n        if(e.groups||e.writers_active)',
            'try{changed_.wait(lock,[&]{\n        if(cpu_capture_disabled_'):
            if code.count(needle)!=1:raise ValueError('Wait exception boundary changed')
            code=code.replace(needle,needle.replace('try{','try{throw std::runtime_error("injected wait failure");',1))
        write(fault/'cpu_authority_gate.cpp','#include <stdexcept>\n'+code)
        write(fault/'test.cpp','''#include "cpu_authority_gate.hpp"
#include <iostream>
#include <stdexcept>
using namespace reo::native::ram_capture::v2;
int main(){Coordinator gate;int backing{};unsigned caught=0;
try{(void)gate.begin_cpu_writer(&backing);}catch(const std::runtime_error&){++caught;}
try{(void)gate.wait_cpu_group(&backing);}catch(const std::runtime_error&){++caught;}
auto o=gate.observe(&backing);if(caught!=2||o.cpu_groups||o.readers_waiting||o.writers_waiting||o.writers_active)return 1;
{auto p=gate.try_cpu_group(&backing);if(!p.value)return 2;}{auto g=gate.begin_graphics(&backing);if(!g.value)return 3;}
std::cout<<"reserved reader/writer exception cleanup passed\\n";}
''')
        exe=fault/'test.exe';run('compile_wait_exception',flags+[fault/'cpu_authority_gate.cpp',fault/'test.cpp','-o',exe]);run('wait_exception',[exe])
        proof['private_boundary_sha256']={str(p.relative_to(out)):sha(p)for folder in (tiny,fault)for p in folder.iterdir()if p.suffix in ('.cpp','.hpp')}
        # Actual complete Pad loop, registration and stop bodies; no per-write
        # source approximation. Input/window/source observers are explicit mocks.
        actual=block(text,'struct Pad2Feeder')+';\nPad2Feeder g_pad2;\n'+block(text,'uint16_t pad2ButtonBit(')+'\n'
        actual+='#if REO_BUILD_NATIVE_SOUND_RAM_CAPTURE >= 2\n'+block(text,'reo::native::ram_capture::v2::CpuWriter pad2BeginRamWrite(')+'\n#endif\n'
        for start in ('void pad2FeederLoop()', 'uint32_t pad2RegisterSocket(', 'void pad2SetWorkAddr(', 'void reoPad2RumbleFrame()', 'void reoPad2Stop() {',
            'reo::native::ram_capture::v2::Coordinator* ReoHwBridge::nativeSoundRamWriterCoordinator(', 'bool ReoHwBridge::init(', 'void ReoHwBridge::shutdown()'):actual+=block(text,start)+'\n'
        write(out/'actual_pad.inc',actual);shutil.copyfile(HERE/'pad_writer_tests.cpp',out/'pad_writer_tests.cpp')
        includes=['-I'+str(HERE),'-I'+str(ROOT)]
        for variant,defs in (('file1',['-DREO_BUILD_NATIVE_SOUND_RAM_CAPTURE=2']),('file2',['-DREO_BUILD_NATIVE_SOUND_RAM_CAPTURE=2','-DREO_GAME_FILE2']),('off',['-DREO_BUILD_NATIVE_SOUND_RAM_CAPTURE=0'])):
            exe=out/(variant+'.exe');run('compile_actual_pad_'+variant,flags+includes+defs+[HERE/'cpu_authority_gate.cpp',out/'pad_writer_tests.cpp','-o',exe])
            run('actual_pad_'+variant,[exe,'copy'])
            run('actual_init_'+variant,[exe,'init'])
            if variant!='off':
                run('actual_capacity_input_'+variant,[exe,'withdraw'])
                run('actual_socket_bound_'+variant,[exe,'oversized'])
                run('actual_wait_through_pad_'+variant,[exe,'wait'])
        # Controlled fixture locks its RAM around every observable write: the
        # negative exposes missing admission without introducing a C++ data race.
        write(out/'negative_pad.inc',actual.replace('auto ramWriter=pad2BeginRamWrite(rd,socks.size());',''))
        write(out/'negative.cpp',read(HERE/'pad_writer_tests.cpp').replace('#include "actual_pad.inc"','#include "negative_pad.inc"'))
        bad=out/'negative.exe';run('compile_missing_actual_writer',flags+includes+['-DREO_BUILD_NATIVE_SOUND_RAM_CAPTURE=2',HERE/'cpu_authority_gate.cpp',out/'negative.cpp','-o',bad]);run('missing_actual_writer_detected',[bad,'copy'],expected=1)
        # Full real bridge, fresh SDK headers, feature off/on and both games.
        dependency=out/'cohort/third_party/PS2Recomp'
        for n,h in baseline['source_sha256'].items():
            dest=dependency/n;dest.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(tree/n,dest)
        kitfiles={r['path']:r['sha256']for r in json.loads(read(KIT/'build-kit.json'))['files']}
        generation_path=ROOT/'build-native-sjuni/candidate-work-v8/generate.json';generation=json.loads(read(generation_path));generated={}
        for name in ('irq_cpu_sites.inc','heap_control_sites.inc'):
            matches=[(Path(n.removeprefix('\\\\?\\')),h)for n,h in generation['outputs'].items()if n.endswith('\\recomp\\config\\local_source_catalogues\\'+name)]
            if len(matches)!=1 or sha(matches[0][0])!=matches[0][1]:raise ValueError('Generated catalogue drift')
            dest=out/'generated/local_source_catalogues'/name;dest.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(matches[0][0],dest);generated[str(dest.resolve())]=matches[0][1]
        proof['existing_generation_receipt_sha256']=sha(generation_path);proof['generated_sha256']=generated
        include=[dependency/'ps2xRuntime/include',dependency/'ps2xRuntime/src/lib',dependency/'ps2xRuntime/src/lib/Kernel',out/'cohort',out/'generated',ROOT,KIT/'source',KIT/'source/third_party/PS2Recomp/out/build/_deps/raylib-src/src']
        for variant,defs in (('on_file1',['REO_BUILD_NATIVE_SOUND_RAM_CAPTURE=2']),('on_file2',['REO_BUILD_NATIVE_SOUND_RAM_CAPTURE=2','REO_GAME_FILE2']),('off',[])):
            obj=out/(variant+'.obj');deps=out/(variant+'.d')
            cmd=[cc,'-std=c++20','-O1','-pthread','-mssse3','-msse4.1','-D_WIN32_WINNT=0x0A00','-DWINVER=0x0A00','-DNOMINMAX','-DWIN32_LEAN_AND_MEAN']+['-D'+x for x in defs]+['-I'+str(x)for x in include]+['-MMD','-MF',deps,'-c',BRIDGE,'-o',obj]
            run('actual_bridge_object_'+variant,cmd)
            match=re.match(r'.*?:\s+(.*)',read(deps).replace('\\\n',' '),flags=re.S)
            if not match:raise ValueError('Malformed dependencies')
            for item in re.findall(r'(?:\\[ \t]|[^\s])+',match.group(1)):
                path=Path(item.replace('\\ ',' ').replace('\\:',':')).resolve()
                if path.is_relative_to(dependency):h=baseline['source_sha256'].get(path.relative_to(dependency).as_posix())
                elif path.is_relative_to(KIT):
                    rel=path.relative_to(KIT).as_posix()
                    if rel.startswith('source/third_party/PS2Recomp/ps2xRuntime/'):raise ValueError('Old SDK mixed in')
                    h=kitfiles.get(rel)
                elif path.is_relative_to(ROOT)and not path.is_relative_to(ROOT/'build-native-sjuni'):
                    if path.is_relative_to(ROOT/'third_party/PS2Recomp'):raise ValueError('Dirty active SDK mixed in')
                    h=sha(path)
                else:h=generated.get(str(path))
                if h is None or sha(path)!=h:raise ValueError('Unqualified include '+str(path))
                proof['consumed_include_sha256'][str(path)]=h
            proof.setdefault('actual_bridge_objects',{})[variant]=sha(obj)
        proof['status']='passed'
    except Exception as e:proof.update(status='failed',failure=str(e));raise
    finally:
        proof['authored_sha256']=authored;proof['source_postcheck']=[n for n,h in authored.items()if sha(ROOT/n)!=h]
        proof['include_postcheck']=[n for n,h in proof['consumed_include_sha256'].items()if sha(Path(n))!=h]
        if proof['source_postcheck']or proof['include_postcheck']:proof.update(status='failed',failure='Input drift')
        write(out/'receipt.json',json.dumps(proof,indent=2)+'\n')
    if proof['status']!='passed':raise ValueError('Input drift')
    print(json.dumps(dict(status=proof['status'],receipt=str(out/'receipt.json'))))
if __name__=='__main__':main()
