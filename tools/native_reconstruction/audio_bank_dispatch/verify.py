#!/usr/bin/env python3
"""Verify fully reapplied125 audio owner, actual source facades and races.

No game/device/full runtime link. Executables use exact selected source with
declared fake provider/runtime surroundings, and frozen original observations.
"""
import argparse
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import re
import shutil
import subprocess

ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
PATCH=ROOT/'third_party/patches/ps2recomp/0124-complete-audio-bank-owner-dispatch.patch'
PIN='c46d1c7d8ab00fbfa18d2c1f764c559e4e5dc78f'
SCENARIOS=('complete','wrappers','invalid','first','publication','late','registration_stop','foreign',
    'stop_render','stop_producer','self','closed','failed_join','boot','boot_first','query','rpc_foreign','unknown','v1_banks',
    'rpc_statusfail','rpc_query_stop','outer_tail','outer_cancel','accepted_after_stop','strong_bank','reset_foreign',
    'init_foreign','init_owned','control_foreign','metadata_reservation','ram_foreign',
    'metadata_first','transfer_foreign','transfer_stop')
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def read(p):return p.read_text(encoding='utf-8')
def write(p,s):p.parent.mkdir(parents=True,exist_ok=True);p.write_text(s,encoding='utf-8',newline='\n')
def load(name):
    spec=importlib.util.spec_from_file_location('bank_dispatch_'+name,ROOT/'tools/native_reconstruction'/(name+'.py'))
    value=importlib.util.module_from_spec(spec);spec.loader.exec_module(value);return value
def block(text,start):
    begin=text.index(start);brace=text.index('{',begin);depth=0
    for end in range(brace,len(text)):
        depth+=(text[end]=='{')-(text[end]=='}')
        if not depth:return text[begin:end+1]
    raise ValueError('Unbalanced source '+start)

PRIVATE_BANK_FAKE='''
namespace ps2_reo_sound::legacy_detail {
bool submitBank(unsigned,const uint8_t*,size_t,const uint8_t*,size_t,const uint8_t*,size_t){return false;}
bool submitPacket(const uint8_t*,size_t,const uint8_t*,size_t){return false;}
void mix(float* p,unsigned n){ps2_reo_sound::mix(p,n);}
void reset(){ps2_reo_sound::reset();}
void reportAudioPaths(){ps2_reo_sound::reportAudioPaths();}
uint32_t pendingLoads(){return 0;}
uint32_t portState(unsigned,uint32_t& n){n=0;return 0;}
uint32_t seState(unsigned,unsigned,unsigned){return 0;}
}
'''

def rpc_extract(rpc,state,header):
    constants='\n'.join(re.findall(r'        constexpr uint32_t kSoundDriver[^;]+;',rpc))
    # Source constants precede helper methods and require no generated body.
    surround='''
namespace rpc_fixture {
inline std::array<std::uint8_t,1024> ram{};
inline std::atomic<unsigned> read_count{},write_count{},log_count{};
inline std::atomic<unsigned> backfill_count{};
std::mutex g_rpc_mutex;
uint8_t* g_soundDriverIopRam{};
SoundDriverRpcState g_soundDriverRpcState;
PS2SoundDriverCompatLayout g_soundDriverCompatLayout;
using ps2_syscalls::g_dtx_rpc_mutex;
using ps2_syscalls::resetDtxRpcStateUnlocked;
bool g_rpc_initialized{};
std::unordered_map<unsigned,unsigned> g_rpc_servers,g_rpc_clients;
unsigned g_rpc_next_id{},g_rpc_packet_index{},g_rpc_server_index{},g_rpc_active_queue{};
struct R5900Context{int result=99;std::array<uint32_t,8> regs{};};
void setReturnS32(R5900Context* ctx,int value){ctx->result=value;}
#define RUNTIME_LOG(...) do{}while(false)
constexpr unsigned IOP_SID_SNDDRV_COMMAND=0,IOP_RPC_SNDDRV_SUBMIT=0,IOP_SID_SNDDRV_STATE=1;
constexpr unsigned IOP_RPC_SNDDRV_GET_STATUS_ADDR=0x12,IOP_RPC_SNDDRV_GET_ADDR_TABLE=0x13;
uint8_t* getMemPtr(uint8_t* base,uint32_t at){return base+at;}
const uint8_t* getConstMemPtr(const uint8_t* base,uint32_t at){++read_count;return base+at;}
bool readGuestU32(const uint8_t* base,uint32_t at,uint32_t& value){++read_count;std::memcpy(&value,base+at,4);return true;}
bool writeGuestU32(uint8_t* base,uint32_t at,uint32_t value){++write_count;std::memcpy(base+at,&value,4);return true;}
void rpcZeroRdram(uint8_t* base,uint32_t at,uint32_t count){++write_count;std::fill_n(base+at,count,0);}
void logOriginalSoundCommands(uint8_t*,const uint8_t*,uint32_t){++log_count;}
void backfillSoundDriverStatusFromCompatUnlocked(uint8_t*){++backfill_count;}
uint32_t word(uint32_t at){uint32_t value;std::memcpy(&value,ram.data()+at,4);return value;}
'''
    names=('uint32_t alignUp(', 'bool resetSoundDriverRpcStateUnlocked(',
        'bool adoptSoundDriverRuntimeUnlocked(', 'bool checkSoundDriverMemoryUnlocked(',
        'void handleSoundDriverCommandBuffer(', 'bool handleSoundDriverRpcServiceImpl(',
        'bool handleSoundDriverRpcService(', 'void resetSoundDriverRpcState(PS2Runtime* runtime)', 'void resetSoundDriverRpcState()',
        'void SifInitRpc(', 'void setSoundDriverCompatLayout(', 'void clearSoundDriverCompatLayout()',
        'bool resolveSoundDriverIopTransfer(',
        'void prepareSoundDriverStatusTransfer(uint8_t *rdram,uint32_t srcAddr,uint32_t size,PS2Runtime* runtime,const',
        'void prepareSoundDriverStatusTransfer(uint8_t* rdram,uint32_t srcAddr,uint32_t size,PS2Runtime* runtime)',
        'void prepareSoundDriverStatusTransfer(uint8_t* rdram,uint32_t srcAddr,uint32_t size)',
        'void finalizeSoundDriverStatusTransfer(')
    return block(header,'struct PS2SoundDriverCompatLayout')+';\n'+block(state,'struct SoundDriverRpcState')+';\n'+surround+constants+'\n'+'\n\n'.join(block(rpc,n) for n in names)+'\n}\n'

def setup_extract(rpc):
    surround='''namespace ps2_syscalls {
std::mutex g_rpc_mutex,g_dtx_rpc_mutex;PS2DtxCompatLayout g_dtxCompatLayout;
std::deque<int> g_pcmPending,g_sjxReplies;std::unordered_set<int> g_pcmRings;
std::unordered_map<int,int> g_dtx_remote_by_id,g_dtx_transfer_by_id,g_dtx_sjx_by_handle,g_dtx_ps2rna_by_handle,g_dtx_sjrmt_by_handle;
std::uint32_t g_dtx_next_urpc_obj{};
void setDtxCompatLayout(const PS2DtxCompatLayout&,PS2Runtime* = nullptr);
void clearDtxCompatLayout(PS2Runtime* = nullptr);
'''
    names=('void resetDtxRpcStateUnlocked(',
        'PS2DtxCompatLayout dtxCompatLayoutSnapshot()', 'void setDtxCompatLayout(', 'void clearDtxCompatLayout(')
    return surround+'\n\n'.join(block(rpc,n) for n in names)+'\n}\n'

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--checkout',type=Path,required=True);p.add_argument('--receipt',type=Path,required=True)
    p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);p.add_argument('--actual-objects',action='store_true');a=p.parse_args()
    tree=a.checkout.resolve();out=a.output.resolve();cc=shutil.which(a.cxx)
    if not cc or not out.is_relative_to(ROOT/'build-native-sjuni/audio-bank-dispatch'):raise ValueError('Existing compiler/private output required')
    receipt=json.loads(read(a.receipt))
    if receipt['status']!='passed' or receipt['applied_count']!=125 or receipt['base_revision']!=PIN:raise ValueError('Fresh fully reapplied125 required')
    for row in receipt['patches']:
        if sha(ROOT/row['path'])!=row['sha256']:raise ValueError('Public series changed')
    for name,digest in receipt['source_sha256'].items():
        if not name.startswith('.git/') and sha(tree/name)!=digest:raise ValueError('Fresh source changed '+name)
    subprocess.run(['git','-C',str(tree),'apply','--reverse','--check',str(PATCH)],check=True,capture_output=True)
    out.mkdir(parents=True,exist_ok=True);source=tree/'ps2xRuntime/src/lib';header=read(tree/'ps2xRuntime/include/ps2_runtime.h');runtime=read(source/'ps2_runtime.cpp');rpc=read(source/'Kernel/Syscalls/RPC.cpp')
    ref=load('pcm_owner_oracle');old=load('verify_pcm_backend_dispatch');banks=load('bank_session_oracle')
    if sha(ROOT/'tools/native_reconstruction/pcm_owner_oracle.py')!='697194d2089779baf86074cf8cce28819607c4f7fd2e7561bcf557ac1d189183':raise ValueError('Original PCM transcript changed')
    runtime_methods='\n\n'.join(block(runtime,n) for n in ('PS2Runtime::PreRunSetupLease::PreRunSetupLease(PreRunSetupLease&& other) noexcept',
        'PS2Runtime::PreRunSetupLease::~PreRunSetupLease()', 'PS2Runtime::PreRunSetupLease PS2Runtime::acquirePreRunSetup() noexcept',
        'void PS2Runtime::releasePreRunSetup() noexcept','bool PS2Runtime::externalWorkerResetAllowed()', 'void PS2Runtime::beginExternalWorkerRun()'))+'\n'
    helpers_list=('CriAudio.cpp','CriAudio.h','CriAudioBackend.h','CriAudioDispatch.h','ReoSoundBanks.cpp','ReoSoundBanks.h','ReoSoundBanksLegacy.h')
    def snapshot(dest,real_banks=True):
        root=dest/'snapshot';helpers=root/'Kernel/Syscalls/Helpers';helpers.mkdir(parents=True,exist_ok=True)
        for name in helpers_list:shutil.copyfile(source/'Kernel/Syscalls/Helpers'/name,helpers/name)
        if not real_banks:write(helpers/'ReoSoundBanks.h',ref.MOCK_BANK)
        shutil.copyfile(source/'cri_pcm_retire.h',root/'cri_pcm_retire.h')
        write(root/'exact_layout.inc',block(header,'struct PS2DtxCompatLayout')+';\n');write(root/'exact_lease.inc',block(header,'    class PreRunSetupLease final')+';\n')
        write(root/'exact_runtime_methods.inc',runtime_methods)
        fake=read(ROOT/'tools/native_reconstruction/pcm_boot_setup/ps2_runtime.h')
        fake=fake.replace('    class ExternalWorker {','    struct Memory {std::vector<uint8_t> iop=std::vector<uint8_t>(2u*1024u*1024u);uint8_t* rdram{};uint8_t* getRDRAM(){return rdram;}uint8_t* getIOPRAM(){return iop.data();}} memory_;\n    Memory& memory(){return memory_;}\n    struct Iop {unsigned initializations{};void init(uint8_t*){++initializations;}} iop_;\n    Iop& iop(){return iop_;}\n    class ExternalWorker {')
        write(root/'ps2_runtime.h',fake);write(root/'ps2_host_backend.h',ref.MOCK_HOST);write(root/'vblank_music_diag.h',ref.MOCK_DIAG)
        return root
    snapshot(out);shutil.copyfile(HERE/'harness.cpp',out/'harness.cpp')
    write(out/'rpc_sound.inc',rpc_extract(rpc,read(source/'Kernel/Syscalls/Helpers/State.h'),header));write(out/'rpc_setup.inc',setup_extract(rpc))
    sif_source=read(source/'Kernel/Stubs/SIF.cpp')
    transfer='''namespace ps2_syscalls {
using rpc_fixture::prepareSoundDriverStatusTransfer;
using rpc_fixture::resolveSoundDriverIopTransfer;
using rpc_fixture::finalizeSoundDriverStatusTransfer;
}
namespace sif_fixture {
using R5900Context=rpc_fixture::R5900Context;
using rpc_fixture::setReturnS32;using rpc_fixture::getMemPtr;
constexpr uint32_t PS2_RAM_SIZE=32u*1024u*1024u;
inline std::atomic<bool> pause_copy{};
inline Event copy_entered,copy_resume;
uint32_t getRegU32(R5900Context* ctx,unsigned index){return ctx->regs.at(index);}
bool canCopyGuestByteRange(uint8_t*,uint32_t,uint32_t,uint32_t){if(pause_copy){copy_entered.signal();copy_resume.wait();}return true;}
bool copyGuestByteRange(uint8_t*,uint32_t,uint32_t,uint32_t){return false;}
'''+block(sif_source,'    void sceSifGetOtherData(')+'\n}\n'
    write(out/'sif_transfer.inc',transfer)
    if sif_source.count('prepareSoundDriverStatusTransfer(rdram, srcAddr, size,runtime,audio)')!=1:raise ValueError('Actual status transfer caller not admitted')
    begin=rpc.index('        const bool isSoundRpc=');end=rpc.index('        uint32_t serverPtr = client->server;',begin)
    write(out/'rpc_outer_begin.inc',rpc[begin:end])
    # The exact SIF function has no intervening closing scope between this
    # declaration and its payload/result/end-callback/completion body.
    sif=block(rpc,'    void SifCallRpc(')
    if not (sif.index('SoundCallScope soundScope')<sif.index('if (sd && sd->buf')<sif.index('if (endFunc)')<sif.index('setReturnS32(ctx, 0);')):raise ValueError('Outer audio lease ordering changed')
    if runtime.count('ps2_syscalls::resetSoundDriverRpcState(this);')!=1 or 'ps2_syscalls::resetSoundDriverRpcState();' in runtime:raise ValueError('Runtime bank reset not identity qualified')
    env=dict(os.environ);env['PATH']=str(Path(cc).resolve().parent)+os.pathsep+env.get('PATH','')
    for key in list(env):
        if key.startswith(('REO_CRI_','REO_AUDIO_PATH','REO_RNA_STOP')):env.pop(key,None)
    proof=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),reapply_receipt_sha256=sha(a.receipt),patch_sha256=sha(PATCH),
        source_sha256=receipt['source_sha256'],checks=[],game_run=False,device_opened=False,runtime_library_linked=False)
    def run(name,command,timeout=120):
        r=subprocess.run(command,env=env,capture_output=True,text=True,timeout=timeout)
        proof['checks'].append(dict(name=name,command=[str(x) for x in command],exit_code=r.returncode,stdout=r.stdout,stderr=r.stderr))
        if r.returncode:raise RuntimeError(name+':\n'+r.stdout+r.stderr)
        return r
    flags=[cc,'-std=c++20','-O1','-ffp-contract=off','-fno-fast-math','-pthread','-Wall','-Wextra','-Wpedantic','-Wno-misleading-indentation','-Werror']
    if 'clang' not in Path(cc).name:flags.append('-Wno-subobject-linkage')
    try:
        exe=out/'joint.exe';run('compile_complete_source',flags+['-I'+str(out/'snapshot'),str(out/'harness.cpp'),'-o',str(exe)])
        for name in SCENARIOS:run('joint_'+name,[str(exe),name],timeout=20)
        # Preserve the historical V1 and original PCM assertions without changing
        # their inputs/expected observations. Bank mock supplies legacy internals.
        prior=out/'v1';snapshot(prior,real_banks=False)
        write(prior/'rpc_methods.inc',old.rpc_extract(ref,source))
        write(prior/'harness.cpp',read(ROOT/'tools/native_reconstruction/pcm_backend_dispatch/harness.cpp')+PRIVATE_BANK_FAKE)
        exe=prior/'v1.exe';run('compile_v1',flags+['-I'+str(prior/'snapshot'),str(prior/'harness.cpp'),'-o',str(exe)])
        for name in old.SCENARIOS:run('v1_'+name,[str(exe),name],timeout=20)
        setup_names=('void resetDtxRpcStateUnlocked(',
            'PS2DtxCompatLayout dtxCompatLayoutSnapshot()', 'void setDtxCompatLayout(', 'void clearDtxCompatLayout(')
        write(prior/'exact_rpc_methods.inc','void setDtxCompatLayout(const PS2DtxCompatLayout&,PS2Runtime* = nullptr);\nvoid clearDtxCompatLayout(PS2Runtime* = nullptr);\n'+'\n\n'.join(block(rpc,n) for n in setup_names)+'\n')
        write(prior/'setup.cpp',read(ROOT/'tools/native_reconstruction/pcm_boot_setup/harness.cpp')+PRIVATE_BANK_FAKE)
        exe=prior/'setup.exe';run('compile_prior_setup',flags+['-I'+str(prior/'snapshot'),str(prior/'setup.cpp'),'-o',str(exe)])
        for name in ('flow','plain','public','lease','first','install','run','stop','install_wins'):run('prior_setup_'+name,[str(exe),name],timeout=20)
        prefix='#include <condition_variable>\n#include <memory>\n#include <utility>\n#include "snapshot/ps2_runtime.h"\n'
        write(prior/'legacy.cpp',prefix+ref.HARNESS+PRIVATE_BANK_FAKE)
        exe=prior/'legacy.exe';run('compile_legacy_pcm',flags+['-I'+str(prior/'snapshot'),str(prior/'legacy.cpp'),'-o',str(exe)])
        result=run('legacy_pcm',[str(exe)]);actual=[json.loads(line) for line in result.stdout.splitlines()]
        expected_path=ROOT/'build-native-sjuni/pcm-owner-oracle/gcc/fixtures.json'
        if sha(expected_path)!='819470f5433c09a5549fefae5f726012ba9ab34f3cc2e4ed3545007d89bea909' or actual!=json.loads(read(expected_path))['records']:raise ValueError('Frozen22case/46snapshot PCM regression')
        proof['legacy_pcm']=dict(cases=22,snapshots=46,float_values=16656)
        # Full actual patched bank facade and PCM selection, original raw action
        # transcript and observer. No native bank candidate is used for expected.
        frozen=ROOT/'build-native-sjuni/bank-session-oracle-v2'
        for name,digest in [('harness.cpp','f4951c6f8e3bff5686957ca38e3f5dd1ffc2cc107223029adcafa596f309d945'),
            ('input.bin','94a2da79aa768d8bdd68279466bf7552f601b1899e0a0b25d928ac494f533862'),
            ('0/expected.json','2b0e4010c7197216625fce46838835d58da4af98353bc11d6a6b1d2db2df7d06')]:
            if sha(frozen/name)!=digest:raise ValueError('Frozen bank source input changed '+name)
        harness=read(frozen/'harness.cpp').replace('#include "source/ReoSoundBanks.cpp"','#include "snapshot/Kernel/Syscalls/Helpers/CriAudio.cpp"\n#include "snapshot/Kernel/Syscalls/Helpers/ReoSoundBanks.cpp"')
        harness+='\nfloat reoAudioMasterGain(){return 1;}\nfloat reoAudioStreamGain(uint32_t){return 1;}\nvoid reoAudioPoll(){}\nvoid reoAudioResetStreams(){}\n'
        write(out/'bank_original.cpp',harness);exe=out/'bank_original.exe'
        run('compile_legacy_bank',flags+['-I'+str(out/'snapshot'),str(out/'bank_original.cpp'),'-o',str(exe)])
        observed=out/'bank_actual.json';run('legacy_bank',[str(exe),str(frozen/'input.bin'),str(observed)])
        if json.loads(read(observed))!=json.loads(read(frozen/'0/expected.json')):raise ValueError('Full original18case/252action bank observations differ')
        proof['legacy_banks']=dict(cases=18,actions=252,float_words=13004,gain_calls=12768,differences=0)
        if a.actual_objects:actual_objects(a,tree,out,receipt,proof,run,cc)
        for name,digest in receipt['source_sha256'].items():
            if not name.startswith('.git/') and sha(tree/name)!=digest:raise ValueError('Source changed during tests '+name)
        proof['status']='passed'
    except Exception as error:proof.update(status='failed',failure=str(error));raise
    finally:
        proof['authored_sha256']={p.name:sha(p) for p in HERE.iterdir() if p.is_file()}
        proof['limitations']=['Exact extracted runtime setup/RPC sound methods with fake surrounding RAM/provider/worker registration; no full runtime linked.',
            'Joint aggregate implementation must obey admitted-render contract and keep inner banks open until outer calls drain.',
            'Wire terminal cancellation is tested separately from accepted original query/packet behavior.']
        write(out/'receipt.json',json.dumps(proof,indent=2)+'\n')
    print(json.dumps(dict(status=proof['status'],joint_cases=len(SCENARIOS),prior_v1_cases=len(old.SCENARIOS))))

def actual_objects(args,tree,out,receipt,proof,run,cc):
    # Exact same fresh dependency on both normal and project-qualified includes.
    # Sealed V6 provides only unrelated immutable geometry/raylib headers and the
    # already generated source catalogues; no old runtime header is permitted.
    kit=ROOT/'build-native-sjuni/candidate-inputs-v6';kit_sha='5457ead9e2fbbc1faa6438a49dead4c20155db3b653756e51c7f39100ff2d504'
    if sha(kit/'build-kit.json')!=kit_sha:raise ValueError('Sealed input cohort changed')
    kit_files={r['path']:r['sha256'] for r in json.loads(read(kit/'build-kit.json'))['files']}
    cohort=out/'cohort';dependency=cohort/'third_party/PS2Recomp'
    for name,digest in receipt['source_sha256'].items():
        if name.startswith('.git/'):continue
        target=dependency/name;target.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(tree/name,target)
        if sha(target)!=digest:raise ValueError('Fresh source staging drift')
    generation=ROOT/'build-native-sjuni/candidate-work-v6/generate.json'
    generation_sha='57449942f568de9c6f579ee58309d2a50ae16f0cdb69a36b43fbc96329c14e01'
    if sha(generation)!=generation_sha:raise ValueError('Generated catalogue receipt changed')
    generated=json.loads(read(generation));qualified={}
    for basename in ('irq_cpu_sites.inc','heap_control_sites.inc'):
        matches=[(Path(k.removeprefix('\\\\?\\')),v) for k,v in generated['outputs'].items() if k.endswith('\\recomp\\config\\local_source_catalogues\\'+basename)]
        if len(matches)!=1 or sha(matches[0][0])!=matches[0][1]:raise ValueError('Generated catalogue changed')
        target=out/'generated/local_source_catalogues'/basename;target.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(matches[0][0],target);qualified[str(target)]=matches[0][1]
    include=[dependency/'ps2xRuntime/include',dependency/'ps2xRuntime/src/lib',dependency/'ps2xRuntime/src/lib/Kernel',cohort,out/'generated',
        kit/'source',kit/'source/tools/parallel_gs_backend/resident_geometry',kit/'source/third_party/PS2Recomp/out/build/_deps/raylib-src/src']
    flags=[cc,'-std=c++20','-O1','-ffp-contract=off','-mssse3','-msse4.1','-pthread','-DNOMINMAX','-DWIN32_LEAN_AND_MEAN','-D_MBCS','-DWIN32','-D_WINDOWS','-DNDEBUG','-DPLATFORM_DESKTOP','-DGRAPHICS_API_OPENGL_33']+['-I'+str(p) for p in include]
    consumed={};objects={}
    for name in ('Kernel/Syscalls/RPC.cpp','Kernel/Syscalls/Helpers/CriAudio.cpp','Kernel/Syscalls/Helpers/ReoSoundBanks.cpp','ps2_runtime.cpp','Kernel/Stubs/SIF.cpp'):
        path=dependency/'ps2xRuntime/src/lib'/name;identifier=Path(name).stem;obj=out/(identifier+'.obj');deps=out/(identifier+'.d')
        run('actual_object_'+identifier,flags+['-MMD','-MF',str(deps),'-c',str(path),'-o',str(obj)])
        objects[name]=sha(obj);match=re.match(r'.*?:\s+(.*)',read(deps).replace('\\\n',' '),flags=re.S)
        if not match:raise ValueError('Malformed dependency file')
        for word in re.findall(r'(?:\\[ \t]|[^\s])+',match.group(1)):
            p=Path(word.replace('\\ ', ' ').replace('\\:',':')).resolve()
            if p.is_relative_to(dependency):digest=receipt['source_sha256'].get(p.relative_to(dependency).as_posix())
            elif p.is_relative_to(kit):
                relative=p.relative_to(kit).as_posix()
                if relative.startswith('source/third_party/PS2Recomp/ps2xRuntime/'):raise ValueError('Older runtime include mixed into125')
                digest=kit_files.get(relative)
            else:digest=qualified.get(str(p))
            if digest is None or sha(p)!=digest:raise ValueError('Unqualified compile input '+str(p))
            consumed[str(p)]=digest
    proof['actual_header_objects']=objects;proof['consumed_include_sha256']=consumed
    proof['sealed_v6_manifest_sha256']=kit_sha;proof['existing_generation_receipt_sha256']=generation_sha

if __name__=='__main__':main()
