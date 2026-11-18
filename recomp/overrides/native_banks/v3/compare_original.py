#!/usr/bin/env python3
"""Transport the unchanged original corpus through the production packet adapter."""
import argparse
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys
HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[3]
V2=ROOT/'game/native/audio_banks/v2'
sys.path.insert(0,str(V2))
spec=importlib.util.spec_from_file_location('budget_original_comparison',V2/'compare_original.py')
v2=importlib.util.module_from_spec(spec);spec.loader.exec_module(v2)
baseline=v2.baseline
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def check_adapter():
    identity=json.loads((HERE/'identity.json').read_text(encoding='utf-8'))
    actual={p.name:sha(p) for p in HERE.iterdir() if p.is_file() and p.suffix in ('.cpp','.h','.hpp','.py')}
    if actual!=identity['candidate_sha256']:raise ValueError('Packet adapter identified source cohort changed; review a new cohort')
    if sha(V2/'cohort_identity.json')!=identity['bank_v2_identity_sha256']:raise ValueError('Identified bank v2 prerequisite changed')
def transport():
    text=v2.transport()
    text=text.replace('#include "algorithms.cpp"','#include "algorithms.cpp"\n#include "packet_adapter.cpp"\n#include "test_capture.h"')
    text=text.replace('inline n::Session session;','''namespace p=reo::native::bank_packets::v3;
inline auto nativeSession=std::make_shared<n::Session>();
inline n::Session& session=*nativeSession;
inline p::PacketAdapter adapter(nativeSession,packet_test::identity());
inline p::Call call(){auto r=adapter.begin_call();if(r.status!=p::Status::ok)throw std::runtime_error("adapter admission");return std::move(r.value);}
inline void packetCheck(p::Status s){if(s!=p::Status::ok)throw std::runtime_error("adapter status "+std::to_string(int(s)));}''')
    text=text.replace('inline unsigned pendingLoads(){auto r=session.pending_loads();check(r.status);return r.value;}','inline unsigned pendingLoads(){auto c=call();auto r=adapter.pending_loads(c);packetCheck(r.status);return r.value;}')
    text=text.replace('inline unsigned portState(unsigned port,uint32_t& count){auto r=session.port_state(port,count);check(r.status);return r.value;}','inline unsigned portState(unsigned port,uint32_t& count){auto c=call();auto r=adapter.port_state(c,port,count);packetCheck(r.status);return r.value;}')
    text=text.replace('inline unsigned seState(unsigned port,unsigned index,unsigned group){auto r=session.sequence_state(port,index,group);check(r.status);return r.value;}','inline unsigned seState(unsigned port,unsigned index,unsigned group){auto c=call();auto r=adapter.sequence_state(c,port,index,group);packetCheck(r.status);return r.value;}')
    text=text.replace('inline void reset(){check(session.reset());}','inline void reset(){auto c=call();packetCheck(adapter.reset(c));}')
    start=text.index('inline bool load(');end=text.index('struct Gain final:',start)
    text=text[:start]+'''// Synthetic input borrows live in the original harness for the complete call.
// This provider is not a real Runtime/RAM qualification or thread-safety proof.
inline bool submitBank(unsigned port,const uint8_t* hd,size_t hn,const uint8_t* bd,size_t bn,const uint8_t* tq,size_t tn){
    packet_test::Capture source;source.bank={std::span<const uint8_t>(hd,hn),std::span<const uint8_t>(bd,bn),std::span<const uint8_t>(tq,tn)};
    auto c=call();return adapter.submit_bank(c,port,source)==p::Status::ok;
}
inline bool submitPacket(const uint8_t* ram,size_t ramBytes,const uint8_t* packet,size_t bytes){
    packet_test::Capture source;source.present=packet!=nullptr;source.has_ram=ram!=nullptr;
    source.ram_extent=ramBytes;if(ram)source.ram={ram,ramBytes};if(packet)source.packet={packet,bytes};
    auto c=call();return adapter.submit_packet(c,source).parser_accepted;
}
'''+text[end:]
    text=text.replace('check(session.mix_add(out,frames,gain));','packetCheck(adapter.mix_add(out,frames,gain));')
    return text
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();cc=shutil.which(a.cxx);out=a.output.resolve()
    if not cc or not out.is_relative_to(ROOT/'build-native-sjuni/native-bank-group-capture'):raise ValueError('Existing compiler/ignored adapter output required')
    check_adapter();v2.budget_verification.check_cohort()
    for name,digest in baseline.PINNED.items():
        if sha(baseline.ORACLE/name)!=digest:raise ValueError('Frozen source oracle changed: '+name)
    out.mkdir(parents=True,exist_ok=True);(out/'native_transport.hpp').write_text(transport(),encoding='utf-8',newline='\n')
    observer=(baseline.ORACLE/'harness.cpp').read_text(encoding='utf-8').replace('#include "source/ReoSoundBanks.cpp"','#include "native_transport.hpp"').replace('namespace s = ps2_reo_sound;','namespace s = native_transport;').replace('s::Bank b;','auto b=s::makeProbeBank();').replace('s::DecodedSample d;','s::DecodedSample d(b.allocation_lease());').replace('template<class T>void nums(std::ostream&o,const std::vector<T>&v)','template<class T,class A>void nums(std::ostream&o,const std::vector<T,A>&v)')
    harness=out/'transport.cpp';harness.write_text(observer,encoding='utf-8',newline='\n');exe=out/'transport.exe';actual=out/'actual.json'
    cmd=[cc,'-std=c++20','-O1','-ffp-contract=off','-fno-fast-math','-Wall','-Wextra','-Wpedantic','-Wno-misleading-indentation','-pthread','-I',str(HERE),'-I',str(V2),str(harness),'-o',str(exe)]
    env=dict(os.environ);env['PATH']=str(Path(cc).resolve().parent)+os.pathsep+env.get('PATH','');authored={p.name:sha(p) for p in HERE.iterdir() if p.is_file()}
    receipt=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),command=cmd,authored=authored,bank_v2_identity_sha256=sha(V2/'cohort_identity.json'),source_oracle=baseline.PINNED,original_expected_observations_previously_seen=True,game_run=False,device_opened=False,
        observation_policy='Unchanged original input/JSON observer with read-only native state access; actual PacketAdapter owns submits, queries, reset and bank render; fixture CaptureSource lifetime is synthetic and not runtime qualification')
    try:
        c=subprocess.run(cmd,capture_output=True,text=True,env=env,timeout=120);receipt['compile']=dict(exit_code=c.returncode,stderr=c.stderr)
        if c.returncode:raise RuntimeError(c.stderr)
        r=subprocess.run([str(exe),str(baseline.ORACLE/'input.bin'),str(actual)],capture_output=True,text=True,env=env,timeout=120);receipt['run']=dict(exit_code=r.returncode,stdout=r.stdout,stderr=r.stderr)
        if r.returncode:raise RuntimeError(r.stderr)
        expected=json.loads((baseline.ORACLE/'0/expected.json').read_text(encoding='utf-8'));observed=json.loads(actual.read_text(encoding='utf-8'));diff=list(baseline.differences(expected,observed));(out/'differences.json').write_text(json.dumps(diff,indent=2)+'\n',encoding='utf-8',newline='\n')
        receipt.update(status='different' if diff else 'passed',differences=len(diff),actual_sha256=sha(actual),cases=len(expected['cases']),actions=sum(len(c['actions']) for c in expected['cases']),float_words=sum(len(a['pcm_bits']) for c in expected['cases'] for a in c['actions']),gain_calls=sum(len(a['gain_calls']) for c in expected['cases'] for a in c['actions']))
        print(json.dumps({k:receipt[k] for k in ['status','differences','cases','actions','float_words','gain_calls']}))
        for d in diff[:10]:print(json.dumps(d))
    except Exception as error:receipt.update(status='failed',failure=str(error));raise
    finally:
        receipt['postcheck_changed']=[name for name,digest in authored.items() if sha(HERE/name)!=digest]
        (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8',newline='\n')
    if diff or receipt['postcheck_changed']:raise SystemExit(1)
if __name__=='__main__':main()
