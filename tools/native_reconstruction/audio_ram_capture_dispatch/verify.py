#!/usr/bin/env python3
"""Exact126 objects plus explicit private adaptation of immutable125 regressions.

No device/game/full runtime link. Every adapted driver byte is retained and
identified; expected PCM/bank observations and old assertion harness stay intact.
"""
import argparse,hashlib,importlib.util,json,os,shutil,subprocess,sys,types
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
PRIOR=ROOT/'tools/native_reconstruction/audio_bank_dispatch/verify.py'
PATCH=ROOT/'third_party/patches/ps2recomp/0125-explicit-native-sound-ram-capture-companion.patch'
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def read(p):return p.read_text(encoding='utf-8')
def write(p,s):p.parent.mkdir(parents=True,exist_ok=True);p.write_text(s,encoding='utf-8',newline='\n')
def block(s,start):
    i=s.index(start);b=s.index('{',i);depth=0
    for e in range(b,len(s)):
        depth+=(s[e]=='{')-(s[e]=='}')
        if not depth:return s[i:e+1]
    raise ValueError('Unbalanced '+start)
def prior_module(out):
    if sha(PRIOR)!='2c0a55b723e26a271ad1bfea05e535760845b79e0674ea1b9ad1ccde2da18eb8':raise ValueError('Prior125 driver changed')
    source=read(PRIOR)
    changes={"receipt['applied_count']!=125":"receipt['applied_count']!=126",
        "ROOT/'build-native-sjuni/audio-bank-dispatch'":"ROOT/'build-native-sjuni/audio-ram-capture-dispatch'",
        "'CriAudioBackend.h','CriAudioDispatch.h'":"'CriAudioBackend.h','CriAudioRamCapture.h','CriAudioDispatch.h'",
        "0124-complete-audio-bank-owner-dispatch.patch":"0125-explicit-native-sound-ram-capture-companion.patch",
        "prefix='#include <condition_variable>":"prefix='#include <span>\\n#include <condition_variable>",
        'using rpc_fixture::resolveSoundDriverIopTransfer;':'using rpc_fixture::resolveSoundDriverIopTransfer;\nusing rpc_fixture::describeSoundDriverIopTransfer;\nusing rpc_fixture::prepareSoundDriverStatusTransferCaptured;'}
    for old,new in changes.items():
        if source.count(old)!=1:raise ValueError('Prior adaptation anchor count '+old)
        source=source.replace(old,new)
    write(out/'adapted_prior_driver.py',source)
    m=types.ModuleType('audio_ram_prior');m.__file__=str(PRIOR);exec(compile(source,str(out/'adapted_prior_driver.py'),'exec'),m.__dict__)
    original=m.rpc_extract
    def rpc_extract(rpc,state,header):
        result=original(rpc,state,header)
        aliases='using RamCall=ps2_cri_audio::NativeSoundRamCallV1;\nusing RamSpace=ps2_cri_audio::NativeSoundRamSpaceV1;\nusing RamControl=ps2_cri_audio::NativeSoundRamControlV1;\nusing RamOp=ps2_cri_audio::NativeSoundRamControlOpV1;\nusing RamKind=ps2_cri_audio::NativeSoundRamControlKindV1;\n'
        helpers=aliases+'\n'.join(block(rpc,n) for n in ('template<class T>bool capturedRead(', 'template<class T>RamOp capturedWrite(',
            'bool checkSoundDriverMemoryCaptured(', 'bool backfillSoundDriverStatusCaptured(', 'bool handleSoundDriverRpcCaptured('))+'\n'
        result=result.replace('bool handleSoundDriverRpcService(',helpers+'bool handleSoundDriverRpcService(',1)
        i=result.rfind('\n}');result=result[:i]+'\n'+block(rpc,'bool describeSoundDriverIopTransfer(')+'\n'+block(rpc,'bool prepareSoundDriverStatusTransferCaptured(')+result[i:]
        return result
    m.rpc_extract=rpc_extract
    return m
SCENARIOS=('invalid','missing','foreign','unavailable','accepted_stop','paused','alias','packet','server','descriptor_alias',
    'payload_metadata','read_refusal','control_refusal','log_failure','query','clamp','status','snapshot',
    'busy','strong','transport_refusal','malformed_snapshot','iop_extent','install_run','run_first','stop_install',
    'stack','callback','backfill','unknown0','unknown1','callback_alias')
def companion(a,m,tree,out,run,cc,proof):
    # The private regression driver supplies exact126 helpers and immutable old
    # fixtures. Its no-companion cases run before these new selected cases.
    saved=sys.argv[:]
    sys.argv=[sys.argv[0],'--checkout',str(tree),'--receipt',str(a.receipt),'--cxx',cc,'--output',str(out/'prior')]
    try:m.main()
    finally:sys.argv=saved
    fake=out/'prior/snapshot/ps2_runtime.h'
    write(fake,read(fake).replace('    class ExternalWorker {','    bool hasFunction(uint32_t)const{return false;}\n    class ExternalWorker {'))
    source=tree/'ps2xRuntime/src/lib';rpc=read(source/'Kernel/Syscalls/RPC.cpp');state=read(source/'Kernel/Syscalls/Helpers/State.h')
    surround='''namespace capture_fixture {
using rpc_fixture::g_rpc_mutex;using rpc_fixture::g_soundDriverCompatLayout;
using rpc_fixture::RamCall;using rpc_fixture::RamSpace;using rpc_fixture::RamControl;using rpc_fixture::RamOp;
using rpc_fixture::capturedRead;using rpc_fixture::capturedWrite;using rpc_fixture::handleSoundDriverRpcCaptured;
struct R5900Context{int result=99;std::array<uint32_t,32> regs{};};
void setReturnS32(R5900Context* ctx,int value){ctx->result=value;}
uint32_t getRegU32(R5900Context* ctx,unsigned index){return ctx->regs.at(index);}
struct ClientState{uint32_t sid{},last_rpc{};bool busy{};};struct ServerState{uint32_t sd_ptr{};};
std::unordered_map<uint32_t,ClientState> g_rpc_clients;
std::unordered_map<uint32_t,ServerState> g_rpc_servers;
unsigned signals{};std::vector<uint32_t> signal_ids;bool signalRpcCompletionSema(uint32_t id){++signals;signal_ids.push_back(id);return true;}
std::function<void()> callback;
bool rpcInvokeFunction(uint8_t*,R5900Context*,PS2Runtime*,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t*){if(callback)callback();return false;}
constexpr uint32_t PS2_RAM_SIZE=32u*1024u*1024u,IOP_SID_SNDDRV_COMMAND=0,IOP_SID_SNDDRV_STATE=1,kSifRpcModeNowait=1;
'''
    types_source='\n'.join(block(state,'struct '+n)+';'for n in ('t_SifRpcHeader','t_SifRpcClientData','t_SifRpcServerData'))
    original_status='''namespace original_status_fixture {
using rpc_fixture::g_soundDriverRpcState;using rpc_fixture::g_soundDriverCompatLayout;using rpc_fixture::g_soundDriverIopRam;
using rpc_fixture::kSoundDriverSeSumOffset;using rpc_fixture::kSoundDriverMidiSumOffset;
const uint8_t* getConstMemPtr(const uint8_t* base,uint32_t at){return base+(at&0x1fffffffu);}
uint8_t* getMemPtr(uint8_t* base,uint32_t at){return base+(at&0x1fffffffu);}
'''+ '\n'.join(block(rpc,n)for n in ('bool readGuestS16(', 'bool writeGuestS16(', 'bool hasAnyNonZero(',
        'bool selectSoundDriverCompatChecks(', 'void backfillSoundDriverStatusFromCompatUnlocked('))+'\n}\n'
    write(out/'capture_outer.inc',surround+types_source+'\n'+block(rpc,'bool tryNativeSoundRamRpc(')+'\n}\n'+original_status)
    shutil.copyfile(HERE/'harness.cpp',out/'harness.cpp')
    flags=[cc,'-std=c++20','-O1','-ffp-contract=off','-fno-fast-math','-pthread','-Wall','-Wextra','-Wpedantic','-Wno-misleading-indentation','-Werror','-I'+str(out/'prior/snapshot')]
    if 'clang'not in Path(cc).name:flags+=['-Wno-subobject-linkage']
    exe=out/'companion.exe';run('compile_companion',flags+[str(out/'harness.cpp'),'-o',str(exe)])
    for name in SCENARIOS:run('companion_'+name,[str(exe),name],timeout=25)
    # Retain an explicit negative control with only the two superseded source
    # ordering mistakes restored. Both independently asserted wire results must
    # fail; expected observations are not changed to fit the fixed candidate.
    text=read(out/'capture_outer.inc')
    old='''                if(cap.forward(RamSpace::ee,send,RamSpace::ee,sd.buf,std::min<std::size_t>(n,1u<<20))!=ps2_cri_audio::BankStatusV2::ok)return finish(false);
                semaKnown=false; // Only a successful copy can change metadata.'''
    restored='''                semaKnown=false;
                if(cap.forward(RamSpace::ee,send,RamSpace::ee,sd.buf,std::min<std::size_t>(n,1u<<20))!=ps2_cri_audio::BankStatusV2::ok)return finish(false);'''
    if text.count(old)!=1:raise ValueError('Negative-control transport anchor')
    text=text.replace(old,restored)
    old='''                // The compat busy word can alias client.hdr.sema_id. Original
                // fallback observes it again AFTER that write.
                if(!refreshSema())return finish(false);
'''
    if text.count(old)!=1:raise ValueError('Negative-control fallback anchor')
    write(out/'capture_outer_negative.inc',text.replace(old,''))
    write(out/'negative.cpp',read(HERE/'harness.cpp').replace('#include "capture_outer.inc"','#include "capture_outer_negative.inc"'))
    bad=out/'negative.exe';run('compile_negative_control',flags+[str(out/'negative.cpp'),'-o',str(bad)])
    for name in ('transport_refusal','callback_alias'):run('negative_'+name,[str(bad),name],expect_failure=True)
    proof['negative_control_sha256']=sha(out/'capture_outer_negative.inc')
    proof['companion_cases']=len(SCENARIOS);proof['prior_regression_receipt_sha256']=sha(out/'prior/receipt.json')
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--checkout',type=Path,required=True);p.add_argument('--receipt',type=Path,required=True)
    p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);p.add_argument('--mode',choices=('objects','regressions','companion'),required=True);a=p.parse_args()
    tree=a.checkout.resolve();out=a.output.resolve();cc=shutil.which(a.cxx)
    if not cc or not out.is_relative_to(ROOT/'build-native-sjuni/audio-ram-capture-dispatch')or out.exists():raise ValueError('Compiler and fresh isolated output required')
    out.mkdir(parents=True)
    authored_before={p.name:sha(p)for p in HERE.iterdir()if p.is_file()}
    receipt=json.loads(read(a.receipt))
    if receipt['status']!='passed'or receipt['applied_count']!=126 or receipt['base_revision']!='c46d1c7d8ab00fbfa18d2c1f764c559e4e5dc78f':raise ValueError('Full126 required')
    for row in receipt['patches']:
        if sha(ROOT/row['path'])!=row['sha256']:raise ValueError('Patch drift')
    for name,digest in receipt['source_sha256'].items():
        if sha(tree/name)!=digest:raise ValueError('Source drift '+name)
    prior_tree=ROOT/'build-native-sjuni/dependency-bank-reapply-v3'
    header_name='ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/CriAudioBackend.h'
    before=read(prior_tree/header_name);after=read(tree/header_name)
    if after.replace('    friend class NativeSoundRamCallV1;\n','')!=before:raise ValueError('Published V1/V2 header changed beyond non-layout friend declaration')
    # The default function body must remain byte-for-byte text-identical except
    # for the single companion-only entry branch. No old fallback is rewritten.
    rpc_name='ps2xRuntime/src/lib/Kernel/Syscalls/RPC.cpp'
    before_rpc=block(read(prior_tree/rpc_name),'    void SifCallRpc(')
    after_rpc=block(read(tree/rpc_name),'    void SifCallRpc(')
    if after_rpc.replace('        if(tryNativeSoundRamRpc(rdram,ctx,runtime))return;\n','')!=before_rpc:raise ValueError('Default125 SifCallRpc body changed')
    iop_path=tree/'ps2xRuntime/src/lib/ps2_iop.cpp';iop_init=block(read(iop_path),'void ps2_iop::init(')
    if ''.join(iop_init.split())!='voidps2_iop::init(uint8_t*rdram){m_rdram=rdram;}':raise ValueError('IOP init is no longer host pointer assignment only')
    if 'g_rpc_clients[clientPtr].busy = false;'not in before_rpc or 'g_rpc_clients[cp].busy=false;'not in block(read(tree/rpc_name),'bool tryNativeSoundRamRpc('):raise ValueError('Final client-registry semantics changed')
    subprocess.run(['git','-C',str(tree),'apply','--reverse','--check',str(PATCH)],check=True,capture_output=True)
    m=prior_module(out)
    if a.mode=='regressions':
        sys.argv=[sys.argv[0],'--checkout',str(tree),'--receipt',str(a.receipt),'--cxx',cc,'--output',str(out/'prior')]
        m.main();return
    proof=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),reapply_receipt_sha256=sha(a.receipt),patch_sha256=sha(PATCH),checks=[],game_run=False,device_opened=False,runtime_library_linked=False)
    proof['iop_init_source_sha256']=sha(iop_path);proof['iop_init_method_sha256']=hashlib.sha256(iop_init.encode()).hexdigest()
    env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','')
    def run(name,cmd,timeout=180,expect_failure=False):
        r=subprocess.run([str(x)for x in cmd],env=env,text=True,capture_output=True,timeout=timeout)
        proof['checks'].append(dict(name=name,command=[str(x)for x in cmd],exit_code=r.returncode,expected_failure=expect_failure,stdout=r.stdout,stderr=r.stderr))
        if (r.returncode==0)==expect_failure:raise RuntimeError(name+':\n'+r.stdout+r.stderr)
        return r
    try:
        if a.mode=='objects':m.actual_objects(a,tree,out,receipt,proof,run,cc)
        else:companion(a,m,tree,out,run,cc,proof)
        for name,digest in receipt['source_sha256'].items():
            if sha(tree/name)!=digest:raise ValueError('Source drift after checks '+name)
        if authored_before!={p.name:sha(p)for p in HERE.iterdir()if p.is_file()}:raise ValueError('Authored input drift during checks')
        proof['status']='passed'
    except Exception as e:proof.update(status='failed',failure=str(e));raise
    finally:
        proof['authored_sha256']={p.name:sha(p)for p in HERE.iterdir()if p.is_file()}
        proof['authored_inputs_unchanged']=authored_before==proof['authored_sha256']
        proof['prior_driver_sha256']=sha(PRIOR);proof['adapted_driver_sha256']=sha(out/'adapted_prior_driver.py')
        write(out/'receipt.json',json.dumps(proof,indent=2)+'\n')
    print(json.dumps(dict(status=proof['status'],mode=a.mode)))
if __name__=='__main__':main()
