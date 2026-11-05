#!/usr/bin/env python3
"""Compile exact patched PCM facade with an isolated fake backend/provider.

No native PCM backend, game, audio device, runtime library or asset is loaded.
The public patch is checked in reverse against the supplied reconstructed tree;
all unmodified baseline sources and every prior patch are identity-verified.
"""
import argparse
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import shutil
import subprocess

ROOT = Path(__file__).resolve().parents[2]
PIN = 'c46d1c7d8ab00fbfa18d2c1f764c559e4e5dc78f'
PATCH = ROOT/'third_party/patches/ps2recomp/0121-cri-audio-session-backend-dispatch.patch'
TRANSCRIPT_SHA = '697194d2089779baf86074cf8cce28819607c4f7fd2e7561bcf557ac1d189183'
LEGACY_FIXTURE_SHA = '819470f5433c09a5549fefae5f726012ba9ab34f3cc2e4ed3545007d89bea909'
SCENARIOS = ('complete','legacy','legacy_invalid','invalid','late','publication','registration_stop','busy','allocation','reentry',
    'rejection','stopped','strong','concurrent','self','failed_join','stop_fence','plain')
HELPERS = 'ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/'
CHANGED = {HELPERS+'CriAudio.cpp'}


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def verify_sources(checkout,baseline_receipt):
    receipt = json.loads(baseline_receipt.read_text(encoding='utf-8'))
    if receipt['status']!='passed' or receipt['base_revision']!=PIN or receipt['applied_count']!=121:
        raise ValueError('Expected an exact successful reconstructed121 receipt')
    prior = sorted((ROOT/'third_party/patches/ps2recomp').glob('*.patch'))[:121]
    if [(p.relative_to(ROOT).as_posix(),sha(p)) for p in prior] != [(r['path'],r['sha256']) for r in receipt['patches']]:
        raise ValueError('Prior public patch identity/order changed')
    for name,digest in receipt['source_sha256'].items():
        # A standalone clone's audit also records administrative .git files;
        # preparing a focused diff updates its index, not dependency source.
        if name.startswith('.git/'):
            continue
        if name not in CHANGED and sha(checkout/name)!=digest:
            raise ValueError('Unreviewed baseline change: '+name)
    command = ['git','-C',str(checkout),'apply','--reverse','--check',str(PATCH)]
    subprocess.run(command,check=True,capture_output=True,text=True,timeout=30)
    return receipt


def rpc_extract(ref,source):
    rpc = (source/'Kernel/Syscalls/RPC.cpp').read_text()
    state = (source/'Kernel/Syscalls/Helpers/State.h').read_text()
    import re
    parts = [ref.block(state,'struct '+name,';') for name in ('DtxSjxState','DtxPs2RnaState','DtxSjrmtState','DtxTransferState')]
    parts += ['std::unordered_map<uint32_t,DtxSjxState> g_dtx_sjx_by_handle;',
        'std::unordered_map<uint32_t,DtxSjrmtState> g_dtx_sjrmt_by_handle;']
    parts += [ref.block(rpc,'struct '+name,';') for name in ('SjxReply','PcmPending')]
    parts += ['std::deque<PcmPending> g_pcmPending;std::deque<SjxReply> g_sjxReplies;',
        'std::mutex g_dtx_rpc_mutex;'+re.search(r'constexpr uint64_t kIopPcmBufferBytes=[^;]+;',rpc).group(0),
        'uint8_t wire[1024];',
        'uint8_t* getMemPtr(uint8_t* p,uint32_t at){if(p!=wire||at>sizeof(wire)-16)throw std::runtime_error("mock wire bounds");return p+at;}',
        'void writeGuestU32(uint8_t* p,uint32_t at,uint32_t v){std::memcpy(getMemPtr(p,at),&v,4);}']
    parts += [ref.block(rpc,name) for name in ('uint32_t resolveRnaRing(','void discardUnlessNaturalEnd(',
        'uint32_t dtxPacedConsumeBudgetBytes(','void collectSjxReplies(')]
    return '\n'.join(parts)+'\n'


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--checkout',required=True,type=Path)
    parser.add_argument('--baseline-receipt',type=Path,default=ROOT/'build-native-sjuni/dependency-pcm-dispatch-v2-receipt.json')
    parser.add_argument('--cxx',required=True)
    parser.add_argument('--output',required=True,type=Path)
    args = parser.parse_args()
    checkout,output = args.checkout.resolve(),args.output.resolve()
    allowed = ROOT/'build-native-sjuni'
    if output==allowed or not output.is_relative_to(allowed) or checkout==allowed or not checkout.is_relative_to(allowed):
        raise ValueError('Use independent ignored checkout/output directories')
    if output.is_relative_to(checkout) or checkout.is_relative_to(output):
        raise ValueError('Do not put generated checks in the source checkout')
    compiler = shutil.which(args.cxx)
    if not compiler:
        raise ValueError('Existing C++20 compiler required')
    baseline = verify_sources(checkout,args.baseline_receipt)
    transcript = ROOT/'tools/native_reconstruction/pcm_owner_oracle.py'
    if sha(transcript)!=TRANSCRIPT_SHA:
        raise ValueError('Original exact-source harness changed')
    expected_path = ROOT/'build-native-sjuni/pcm-owner-oracle/gcc/fixtures.json'
    if sha(expected_path)!=LEGACY_FIXTURE_SHA:
        raise ValueError('Frozen legacy observations changed')
    spec = importlib.util.spec_from_file_location('pcm_prior_reference',transcript)
    ref = importlib.util.module_from_spec(spec);spec.loader.exec_module(ref)
    output.mkdir(parents=True,exist_ok=True)
    snapshot = output/'snapshot';helpers=snapshot/'Kernel/Syscalls/Helpers';helpers.mkdir(parents=True,exist_ok=True)
    source = checkout/'ps2xRuntime/src/lib'
    for name in ('CriAudio.cpp','CriAudio.h','CriAudioBackend.h','CriAudioDispatch.h'):
        shutil.copyfile(source/'Kernel/Syscalls/Helpers'/name,helpers/name)
    shutil.copyfile(source/'cri_pcm_retire.h',snapshot/'cri_pcm_retire.h')
    for name,value in [('Kernel/Syscalls/Helpers/ReoSoundBanks.h',ref.MOCK_BANK),('ps2_host_backend.h',ref.MOCK_HOST),('vblank_music_diag.h',ref.MOCK_DIAG)]:
        (snapshot/name).write_text(value,encoding='utf-8',newline='\n')
    authored = ROOT/'tools/native_reconstruction/pcm_backend_dispatch'
    shutil.copyfile(authored/'ps2_runtime.h',snapshot/'ps2_runtime.h')
    shutil.copyfile(authored/'harness.cpp',output/'harness.cpp')
    (output/'rpc_methods.inc').write_text(rpc_extract(ref,source),encoding='utf-8',newline='\n')
    # Preinclude new standard/runtime surroundings before the frozen clock-only
    # namespace substitution enters the complete exact patched facade.
    prefix = '#include <condition_variable>\n#include <memory>\n#include <utility>\n#include "snapshot/ps2_runtime.h"\n'
    (output/'legacy_probe.cpp').write_text(prefix+ref.HARNESS,encoding='utf-8',newline='\n')
    env = dict(os.environ)
    for name in list(env):
        if name.startswith(('REO_CRI_','REO_AUDIO_PATH','REO_RNA_STOP')):env.pop(name,None)
    cc=Path(compiler).resolve();env['PATH']=str(cc.parent)+os.pathsep+env.get('PATH','')
    paths = [PATCH,Path(__file__),authored/'harness.cpp',authored/'ps2_runtime.h',
        checkout/'ps2xRuntime/include/ps2_runtime.h']+[
        source/'Kernel/Syscalls/Helpers'/name for name in ('CriAudio.cpp','CriAudio.h','CriAudioBackend.h','CriAudioDispatch.h')]
    hashes={str(path.relative_to(ROOT)):sha(path) for path in paths}
    proof=dict(schema=1,status='running',game_run=False,device_opened=False,runtime_library_linked=False,
        native_pcm_backend_installed=False,compiler=compiler,compiler_sha256=sha(cc),source_sha256=hashes,
        baseline_receipt_sha256=sha(args.baseline_receipt),baseline_patch_count=baseline['applied_count'],
        patch_sha256=sha(PATCH),legacy_fixture_sha256=LEGACY_FIXTURE_SHA,checks=[])
    def run(name,command,expected=0):
        result=subprocess.run(command,env=env,text=True,capture_output=True,timeout=45)
        proof['checks'].append(dict(name=name,command=[str(x) for x in command],exit_code=result.returncode,expected_exit_code=expected,stdout=result.stdout,stderr=result.stderr))
        if result.returncode!=expected:raise RuntimeError(name+' failed:\n'+result.stdout+result.stderr)
        return result
    try:
        flags=[compiler,'-std=c++20','-O1','-Wall','-Wextra','-Wpedantic','-Werror','-pthread','-I'+str(snapshot)]
        exe=output/'dispatch_tests.exe'
        run('compile_exact_patched_facade',flags+[str(output/'harness.cpp'),'-o',str(exe)])
        for scenario in SCENARIOS:run(scenario,[str(exe),scenario])
        # Negative control for the reviewed stop-signal race. Only the ignored
        # copied dispatcher loses its wait; public/source checkout stays intact.
        regression=output/'stop-signal-regression';regression.mkdir(exist_ok=True)
        shutil.copytree(snapshot,regression/'snapshot',dirs_exist_ok=True)
        shutil.copyfile(authored/'harness.cpp',regression/'harness.cpp')
        mutant=regression/'snapshot/Kernel/Syscalls/Helpers/CriAudioDispatch.h'
        contents=mutant.read_text(encoding='utf-8');waiting='while(stop_inflight)changed.wait(lock);'
        if contents.count(waiting)!=1:raise ValueError('Stop-signal guard not unique')
        mutant.write_text(contents.replace(waiting,''),encoding='utf-8',newline='\n')
        mutation_flags=[compiler,'-std=c++20','-O1','-Wall','-Wextra','-Wpedantic','-Werror','-pthread','-I'+str(regression/'snapshot')]
        run('compile_stop_signal_negative_control',mutation_flags+[str(regression/'harness.cpp'),'-o',str(regression/'counterexample.exe')])
        result=run('stop_signal_negative_control',[str(regression/'counterexample.exe'),'stop_fence'],expected=1)
        if result.stderr.strip()!='dispatch check failed':raise ValueError('Negative control failed for an unexpected reason')
        proof['stop_signal_negative_control']=dict(mutated_header_sha256=sha(mutant),
            expected_failure='shutdown/join attempted before request_stop returned')
        legacy=output/'legacy_probe.exe'
        run('compile_legacy_observer',flags+[str(output/'legacy_probe.cpp'),'-o',str(legacy)])
        result=run('legacy_original_fixture',[str(legacy)])
        actual=[json.loads(line) for line in result.stdout.splitlines()]
        expected=json.loads(expected_path.read_text(encoding='utf-8'))['records']
        if actual!=expected:raise ValueError('Legacy full-state/floating observations differ')
        gate=output/'actual-header-gate';gate.mkdir(exist_ok=True)
        actual_header=checkout/'ps2xRuntime/include/ps2_runtime.h'
        (gate/'ps2_runtime.h').write_text('#pragma once\n#include '+json.dumps(actual_header.as_posix())+'\n',encoding='utf-8',newline='\n')
        run('actual_runtime_header_object',[compiler,'-std=c++20','-O1','-Wall','-Wextra','-Werror',
            '-Wno-unused-variable','-Wno-unused-parameter','-mssse3','-msse4.1','-I'+str(gate),
            '-I'+str(snapshot),'-I'+str(checkout/'ps2xRuntime/include'),'-I'+str(source),
            '-I'+str(source/'Kernel'),'-I'+str(ROOT),'-c',str(source/'Kernel/Syscalls/Helpers/CriAudio.cpp'),
            '-o',str(output/'actual-header.o')])
        proof['actual_runtime_header_sha256']=sha(actual_header)
        proof['actual_header_object_sha256']=sha(output/'actual-header.o')
        if hashes!={str(path.relative_to(ROOT)):sha(path) for path in paths}:raise ValueError('Sources changed during check')
        proof.update(status='passed',scenarios=len(SCENARIOS),legacy_cases=len({r['case'] for r in actual}),
            legacy_snapshots=len(actual),legacy_float_values=sum(len(r['float_bits']) for r in actual),
            executable_sha256=sha(exe),legacy_executable_sha256=sha(legacy))
    except Exception as error:
        proof.update(status='failed',failure=str(error));raise
    finally:
        proof['limitations']=['Runtime registration/provider/backend execution is mocked; actual runtime header object compiled, no matching library link or callback fence execution.',
            'Complete function-table publication/strong call leases tested; declarations do not prove real backend domains or device quiescence.',
            'Real bootstrap installation, matching rebuilt runtime/game, provider tests and complete native facade remain required.']
        (output/'receipt.json').write_text(json.dumps(proof,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps({key:proof[key] for key in ('status','scenarios','legacy_cases','legacy_snapshots','legacy_float_values')}))


if __name__=='__main__':main()
