#!/usr/bin/env python3
"""Compile native scalar DVCI against independent original-word fixtures.

Only the generated test bridge knows synthetic wire addresses/layout. No game,
runtime library, dependency or live device is built, linked or executed.
"""
import argparse
import hashlib
import json
from pathlib import Path
import shutil
import subprocess

from dvci_oracle import generate

ROOT=Path(__file__).resolve().parents[2]
MASK32=(1<<32)-1


def array(values):
    return '{'+','.join(str(v)+'u' for v in values)+'}'


def snapshot(value):
    return 'Snapshot{'+','.join((array(value['handle_bytes_u8']),
        array(value['destination_probe_bytes_u8']),array(value['mode_bytes_u8']),
        str(value['sync_mode_u32'])+'u'))+'}'


def event(value):
    kind=value['kind']
    indices={'diagnostic':[1],'cache_range':[0,1],
        'srd_prepare_disc':[0,1,2,3],'cd_sync':[0],
        'srd_wait':[0],'srd_destroy':[0],'srd_status':[0]}.get(kind,[])
    args=[value['arguments_u64'][i]&MASK32 for i in indices]
    response=(str(value['scripted_return_u64']&MASK32)+'u'
              if kind in ('srd_create','srd_prepare_disc','srd_status') else 'std::nullopt')
    return ('Event{'+json.dumps(kind)+','+array(args)+','+
        array(value.get('mode_bytes_u8',[]))+','+
        str(value['guard_depth_before'])+','+str(value['guard_depth_after'])+','+
        snapshot(value['observed_before'])+','+snapshot(value['observed_after'])+','+response+'}')


SUPPORT=r'''
#include "game/native/disc_stream/disc_stream.hpp"
#include <array>
#include <bit>
#include <cstdint>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>
#include <vector>
namespace ds=reo::native::disc_stream;
std::size_t calls=0,hooks_compared=0,snapshots_compared=0,returns_compared=0;
std::string context;
void check(bool value,const char* detail) {
    if(!value)throw std::runtime_error(context+": "+detail);
}
std::int32_t word(std::uint32_t value){return std::bit_cast<std::int32_t>(value);}
struct Snapshot {
    std::array<std::uint8_t,72> file;
    std::array<std::uint8_t,64> probe;
    std::array<std::uint8_t,3> mode;
    std::uint32_t sync;
    friend bool operator==(const Snapshot&,const Snapshot&)=default;
};
struct Event {
    std::string kind;
    std::vector<std::uint32_t> arguments;
    std::vector<std::uint8_t> mode;
    int before_depth,after_depth;
    Snapshot before,after;
    std::optional<std::uint32_t> consumed_response;
};
struct Plan {bool create,prepare;int request_state;};
struct Bridge final:ds::Hooks {
    Snapshot wire;
    ds::FileState file;
    Plan plan;
    const std::vector<Event>* expected{};
    std::size_t next=0;
    int depth=0;
    Bridge(Snapshot initial,Plan script):wire(initial),plan(script){}
    std::uint32_t load(unsigned at)const {
        std::uint32_t value=0;
        for(unsigned i=0;i<4;++i)value|=std::uint32_t(wire.file[at+i])<<(8*i);
        return value;
    }
    void store(unsigned at,std::uint32_t value) {
        for(unsigned i=0;i<4;++i)wire.file[at+i]=static_cast<std::uint8_t>(value>>(8*i));
    }
    ds::BufferId buffer(std::uint32_t value)const {
        check(value==0||value==0x500000u,"unknown synthetic buffer");
        return ds::BufferId{value==0?0u:1u};
    }
    ds::RequestId request_id(std::uint32_t value)const {
        check(value==0||value==0x21BB88u,"unknown synthetic request");
        return ds::RequestId{value==0?0u:1u};
    }
    std::uint32_t buffer_wire(ds::BufferId id)const {
        check(id.value<=1,"unmapped native buffer");return id?0x500000u:0u;
    }
    std::uint32_t request_wire(ds::RequestId id)const {
        check(id.value<=1,"unmapped native request");return id?0x21BB88u:0u;
    }
    void import() {
        check(wire.file[2]<=3,"unknown synthetic file status");
        file.status=static_cast<ds::FileStatus>(wire.file[2]);
        file.sectors=word(load(8));file.cursor=word(load(12));
        file.accepted=word(load(16));file.completed=word(load(20));
        file.buffer=buffer(load(24));file.request=request_id(load(28));
        file.base_sector=load(32);
        for(unsigned i=0;i<4;++i)file.read_mode[i]=wire.file[68+i];
    }
    void mirror() {
        wire.file[2]=static_cast<std::uint8_t>(file.status);
        store(8,static_cast<std::uint32_t>(file.sectors));
        store(12,static_cast<std::uint32_t>(file.cursor));
        store(16,static_cast<std::uint32_t>(file.accepted));
        store(20,static_cast<std::uint32_t>(file.completed));
        store(24,buffer_wire(file.buffer));store(28,request_wire(file.request));
        store(32,file.base_sector);
        for(unsigned i=0;i<4;++i)wire.file[68+i]=file.read_mode[i];
    }
    void prewrite(std::uint32_t address,unsigned size,std::uint64_t value) {
        check(address>=0x400000u&&address+size<=0x400048u,"prewrite outside synthetic handle");
        for(unsigned i=0;i<size;++i)
            wire.file[address-0x400000u+i]=static_cast<std::uint8_t>(value>>(8*i));
    }
    void observe(const char* kind,std::vector<std::uint32_t> arguments={},
                 std::vector<std::uint8_t> mode={},
                 std::optional<std::uint32_t> consumed_response=std::nullopt) {
        check(expected&&next<expected->size(),"unexpected native hook");
        const auto& wanted=(*expected)[next++];
        mirror();
        check(wanted.kind==kind,"hook order/kind");
        check(wanted.arguments==arguments,"consumed hook arguments");
        check(wanted.mode==mode,"pointed read-mode bytes");
        check(wanted.before_depth==depth,"before hook guard depth");
        check(wanted.before==wire,"before hook complete wire snapshot");
        check(wanted.consumed_response==consumed_response,"consumed scripted response");
        if(wanted.kind=="guard_enter")++depth;
        if(wanted.kind=="guard_leave")--depth;
        check(wanted.after_depth==depth,"after hook guard depth");
        check(wanted.after==wire,"after hook complete wire snapshot");
        ++hooks_compared;snapshots_compared+=2;
    }
    void diagnostic(ds::Diagnostic value)override {
        const auto address=value==ds::Diagnostic::null_file?0x23CBE8u:
            value==ds::Diagnostic::negative_request?0x23CC00u:0x23CC20u;
        observe("diagnostic",{address});
    }
    void enter()override{observe("guard_enter");}
    void leave()override{observe("guard_leave");}
    ds::RequestId create_request()override {
        const auto id=ds::RequestId{plan.create?1u:0u};
        observe("srd_create",{},{},request_wire(id));return id;
    }
    void cache_range(ds::BufferId id,std::uint32_t bytes)override {
        const auto start=buffer_wire(id);
        observe("cache_range",{start,start+bytes-1u});
    }
    bool prepare_disc(ds::RequestId id,std::uint32_t start,std::int32_t sectors,
                      ds::BufferId destination,const std::array<std::uint8_t,4>& mode)override {
        observe("srd_prepare_disc",{request_wire(id),start,static_cast<std::uint32_t>(sectors),
                buffer_wire(destination)},{mode.begin(),mode.end()},plan.prepare?1u:0u);
        return plan.prepare;
    }
    void cd_sync()override{observe("cd_sync",{0u});}
    void server_gate()override{observe("server_gate");}
    void server_service()override{observe("server_service");}
    void wait(ds::RequestId id)override{observe("srd_wait",{request_wire(id)});}
    void destroy(ds::RequestId id)override{observe("srd_destroy",{request_wire(id)});}
    ds::RequestStatus request_status(ds::RequestId id)override {
        observe("srd_status",{request_wire(id)},{},static_cast<std::uint32_t>(plan.request_state));
        return static_cast<ds::RequestStatus>(plan.request_state);
    }
    void finish(std::optional<std::int32_t> result,
                std::optional<std::uint32_t> expected_return,const Snapshot& final) {
        check(result.has_value()==expected_return.has_value(),"defined result presence");
        if(result){check(static_cast<std::uint32_t>(*result)==*expected_return,"defined result");++returns_compared;}
        check(next==expected->size(),"missing native hook");check(depth==0,"final guard balance");
        mirror();check(wire==final,"final complete wire snapshot");
        ++snapshots_compared;++calls;
    }
};
int main() {
try {
'''


def comparison_source(fixture):
    lines=[SUPPORT]
    for case in fixture['cases']:
        plan=case['hook_plan']
        lines+=['{','Bridge bridge('+snapshot(case['initial_state'])+',Plan{'+
            ('true' if plan['create'] else 'false')+','+
            ('true' if plan['prepare'] else 'false')+','+str(plan['srd_state'])+'});']
        for index,operation in enumerate(case['operations']):
            expected=operation['expected']
            args=expected['arguments_i32']
            name=operation['operation']
            lines+=['{','context='+json.dumps(case['name']+':'+str(index)+':'+name)+';',
                'const std::vector<Event> events{'+','.join(event(e) for e in expected['events'])+'};',
                'bridge.expected=&events;bridge.next=0;']
            for edit in operation['pre_writes']:
                lines+=['bridge.prewrite('+str(edit['address'])+'u,'+str(edit['bytes'])+'u,'+
                    str(edit['value_u64'])+'ULL);']
            lines+=['bridge.import();','ds::FileState* file='+('nullptr' if args[0]==0 else '&bridge.file')+';']
            if name=='seek':call='ds::seek(file,word('+str(args[1]&MASK32)+'u),word('+str(args[2]&MASK32)+'u),bridge)'
            elif name=='request':
                call=('ds::request(file,word('+str(args[1]&MASK32)+'u),bridge.buffer('+
                    str(args[2]&MASK32)+'u),ds::Settings{bridge.wire.mode,word(bridge.wire.sync)},bridge)')
            elif name=='update':call=None
            else:call='ds::'+name+'(file,bridge)'
            if call:lines+=['std::optional<std::int32_t> result='+call+';']
            else:lines+=['ds::update(*file,bridge);std::optional<std::int32_t> result=std::nullopt;']
            ret=str(expected['return_u32'])+'u' if expected['return_is_defined'] else 'std::nullopt'
            lines+=['bridge.finish(result,'+ret+','+snapshot(expected['state'])+');','}']
        lines+=['}']
    lines+=[r'''
std::cout<<"calls="<<calls<<" defined_returns="<<returns_compared
         <<" hooks="<<hooks_compared<<" snapshots="<<snapshots_compared<<"\n";
return 0;
}catch(const std::exception& error){std::cerr<<error.what()<<"\n";return 1;}
}
''']
    return '\n'.join(lines)


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--elf',type=Path,default=ROOT/'game_data/SLUS_207.65')
    parser.add_argument('--fixtures',type=Path)
    parser.add_argument('--output',type=Path,default=ROOT/'build-native-sjuni/disc-stream-verification')
    parser.add_argument('--cxx',default='g++')
    args=parser.parse_args()
    out=args.output.resolve()
    if not out.is_relative_to(ROOT/'build-native-sjuni') or out==ROOT/'build-native-sjuni':
        parser.error('Use a separate ignored output below build-native-sjuni')
    compiler=shutil.which(args.cxx)
    if not compiler:parser.error('Existing C++20 compiler unavailable')
    out.mkdir(parents=True,exist_ok=True)
    fixture=generate(args.elf)
    if args.fixtures and json.loads(args.fixtures.read_text(encoding='utf-8'))!=fixture:
        raise ValueError('Supplied fixture differs from fresh pinned original-word output')
    (out/'original-fixtures.json').write_text(json.dumps(fixture,indent=2)+'\n',encoding='utf-8')
    cpp=out/'original_comparison.cpp'
    cpp.write_text(comparison_source(fixture),encoding='utf-8',newline='\n')
    sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()
    receipt=dict(schema=1,status='running',game_run=False,game_built=False,runtime_linked=False,
        scope='native scalar core vs owned-word fixtures; preserving/no-reentry scripted hooks',
        fixture_counts=fixture['counts'],fixture_sha256=sha(out/'original-fixtures.json'),
        compiler=compiler,compiler_sha256=sha(Path(compiler)),
        source_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in
            [Path(__file__),ROOT/'tools/native_reconstruction/dvci_oracle.py',
             ROOT/'tools/native_reconstruction/sjuni_oracle.py',
             *sorted((ROOT/'game/native/disc_stream').glob('*'))] if p.is_file()},
        generated_comparison_sha256=sha(cpp),checks=[])
    def run(name,command):
        result=subprocess.run([str(x) for x in command],cwd=ROOT,text=True,capture_output=True,timeout=90)
        receipt['checks'].append(dict(name=name,command=[str(x) for x in command],
            exit_code=result.returncode,stdout=result.stdout,stderr=result.stderr))
        (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8')
        print(name+': '+str(result.returncode))
        if result.returncode:
            print(result.stdout,result.stderr);raise SystemExit(name+' failed')
    common=[compiler,'-std=c++20','-O1','-Wall','-Wextra','-Wpedantic','-Werror','-I',str(ROOT)]
    core=ROOT/'game/native/disc_stream/disc_stream.cpp'
    for name,sources in [('native_tests',[core,ROOT/'game/native/disc_stream/disc_stream_tests.cpp']),
                         ('original_comparison',[core,cpp])]:
        exe=out/(name+'.exe')
        run(name+'_compile',common+sources+['-o',exe])
        run(name,[exe])
    receipt['status']='passed'
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8')
    print(receipt['checks'][-1]['stdout'].strip())


if __name__=='__main__':main()
