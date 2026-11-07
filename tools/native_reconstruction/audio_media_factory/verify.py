#!/usr/bin/env python3
"""Exact factory bodies with declared acquisition/device ports and audited SDK API.

The fixture does not prove actual runtime/GS/CD RAM authority. The independent
actual-header object check separately consumes the audited production SDK.
"""
import argparse,hashlib,json,os,shutil,subprocess
from pathlib import Path
HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[2]
BASE=ROOT/'recomp/overrides/native_sound_ram'
PRIOR=ROOT/'build-native-sjuni/native-audio-aggregate-v3/attenuation-lsc-llvm-v1'
PRIOR_SHA='ec75830700bc477a853507240722053d3ff021f7d31f61ef7535507bada3834c'
SDK=ROOT/'build-native-sjuni/dependency-sif-init-timing-reapply-v1'
PROOF=SDK.with_name(SDK.name+'-receipt.json')
PROOF_SHA='473ad00c8fcae9966455fc8f47047f2dccd619d747077fc1ffaec2c2e3444df6'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def read(p):return p.read_text(encoding='utf-8')
def write(p,s):p.parent.mkdir(parents=True,exist_ok=True);p.write_text(s,encoding='utf-8',newline='\n')
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--compiler',type=Path,required=True);p.add_argument('--native-receipt',type=Path,required=True);p.add_argument('--manifest',type=Path,required=True);p.add_argument('--native-manifest',type=Path);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists() or not out.is_relative_to(ROOT/'build-native-sjuni/audio-media-factory'):raise ValueError('Fresh owned output required')
    if sha(PRIOR/'receipt.json')!=PRIOR_SHA or sha(PROOF)!=PROOF_SHA:raise ValueError('Explicit parent and SDK provenance required')
    proof=json.loads(PROOF.read_bytes());native=json.loads(a.native_receipt.read_bytes());manifest=json.loads(a.manifest.read_bytes())
    native_path=a.native_manifest or a.manifest;native_manifest=json.loads(native_path.read_bytes())
    if native['status']!='native media pipeline standalone build and tests passed' or native['compiler_sha256']!=sha(a.compiler) or native['manifest_sha256']!=sha(native_path):raise ValueError('Matching complete native build required')
    # A fixture-only correction need not rebuild all native archives. Every
    # production input, native test and contract must remain byte-identical.
    fixture_only={'tools/native_reconstruction/audio_media_factory/tests.cpp','tools/native_reconstruction/audio_media_factory/verify.py'}
    compatible_changes={n for n,d in native_manifest['files'].items()if manifest['files'].get(n)!=d}
    if not compatible_changes.issubset(fixture_only):raise ValueError('Native cohort production inputs differ: '+str(compatible_changes))
    def verify():
        for n,d in manifest['files'].items():
            if sha(ROOT/n)!=d:raise ValueError('Source drift '+n)
        for n,d in native['libraries'].items():
            if sha(ROOT/n)!=d:raise ValueError('Archive drift '+n)
        for n,d in proof['source_sha256'].items():
            if sha(SDK/n)!=d:raise ValueError('SDK drift '+n)
    verify();out.mkdir(parents=True);shutil.copytree(PRIOR/'snapshot',out/'snapshot')
    # The retained facade surroundings have exact production API declarations.
    for name in ('CriAudio.h','CriAudioBackend.h','CriAudioRamCapture.h'):
        rel='ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/'+name
        if sha(out/'snapshot/Kernel/Syscalls/Helpers'/name)!=proof['source_sha256'][rel]:raise ValueError('Mock API differs from production '+name)
    write(out/'snapshot/ps2_syscalls.h','#pragma once\n#include "ps2_runtime.h"\nnamespace ps2_syscalls {PS2DtxCompatLayout dtxCompatLayoutSnapshot();}\nstd::uint32_t ps2ActualGuestExecutionDepth(PS2Runtime*)noexcept;\n')
    # The retained facade's host port already declares a synthetic AudioStream.
    # Use that same explicit device port for the provider header in this fixture;
    # the separate actual-header object check uses the real raylib declaration.
    write(out/'snapshot/raylib.h','#pragma once\n#include "ps2_host_backend.h"\n')
    # Keep the actual factory, relay and lifecycle bodies verbatim. Only local
    # include resolution is adjusted in the private copy to the declared ports.
    for name in ('composite_backend.cpp','composite_backend.h','capture_provider_v3.h'):
        body=read(BASE/name)
        if name!='composite_backend.cpp':
            body=body.replace('"../native_audio/','"recomp/overrides/native_audio/').replace('"../native_cd_owner/','"recomp/overrides/native_cd_owner/')
        write(out/'source'/name,body)
    fake=read(ROOT/'tools/native_reconstruction/audio_composite_wrapper/fake_runtime_memory.h')
    fake=fake.replace('#include <span>','#include <span>\n#include "recomp/overrides/native_banks/v3/test_capture.h"')
    fake=fake.replace('MemoryStatistics stats;','MemoryStatistics stats;packet::MemoryIdentity profile;')
    fake=fake.replace('identity()const noexcept override{return {};}','identity()const noexcept override{return profile;}')
    old='packet::PacketResult with_packet(const aggregate::PacketBorrow&,aggregate::PacketOperation&)noexcept override{return {packet::Status::unsupported};}'
    new='packet::PacketResult with_packet(const aggregate::PacketBorrow& raw,aggregate::PacketOperation& operation)noexcept override{packet_test::Capture source;source.profile=profile;source.has_ram=raw.ram!=nullptr;source.ram_extent=raw.ram_bytes;source.present=raw.packet!=nullptr;if(raw.ram)source.ram={raw.ram,raw.ram_bytes};if(raw.packet)source.packet={raw.packet,raw.packet_bytes};return operation.run(source);}'
    if fake.count(old)!=1:raise ValueError('Fake capture anchor')
    fake=fake.replace(old,new)
    old='packet::Status with_bank(const aggregate::BankBorrow&,aggregate::BankOperation&)noexcept override{return packet::Status::unsupported;}'
    new='packet::Status with_bank(const aggregate::BankBorrow& raw,aggregate::BankOperation& operation)noexcept override{packet_test::Capture source;source.profile=profile;source.bank={std::span<const uint8_t>(raw.hd,raw.hd_bytes),std::span<const uint8_t>(raw.bd,raw.bd_bytes),std::span<const uint8_t>(raw.tq,raw.tq_bytes)};return operation.run(source);}'
    if fake.count(old)!=1:raise ValueError('Fake bank anchor')
    write(out/'source/runtime_memory.h',fake.replace(old,new))
    kit=ROOT/'build-native-sjuni/candidate-inputs-v8'
    raylib=kit/'source/third_party/PS2Recomp/out/build/_deps/raylib-src/src'
    flags=[a.compiler,'-std=c++20','-O1','-pthread','-ffp-contract=off','-fno-fast-math','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-misleading-indentation','-Wno-unused-function','-DNOMINMAX','-DWIN32_LEAN_AND_MEAN','-DREO_BUILD_NATIVE_SOUND_RAM_CAPTURE=2','-DREO_GAME_FILE1','-I'+str(out),'-I'+str(out/'snapshot'),'-I'+str(ROOT),'-I'+str(raylib)]
    env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
    for key in list(env):
        if key.startswith(('REO_CRI_','REO_AUDIO_PATH','REO_RNA_STOP')):env.pop(key,None)
    record=dict(schema=1,status='failed',compiler_sha256=sha(a.compiler),candidate_manifest_sha256=sha(a.manifest),native_manifest_sha256=sha(native_path),compatible_fixture_only_changes=sorted(compatible_changes),native_receipt_sha256=sha(a.native_receipt),audited_sdk_receipt_sha256=sha(PROOF),prior_facade_receipt_sha256=sha(PRIOR/'receipt.json'),checks=[],game_run=False,device_opened=False,actual_runtime_acquisition=False,actual_factory_bodies=True,actual_source_workers=True)
    def run(label,command):
        r=subprocess.run(list(map(str,command)),env=env,capture_output=True,text=True,timeout=120);write(out/(label+'.txt'),r.stdout+r.stderr);record['checks'].append(dict(label=label,exit=r.returncode,command=list(map(str,command))))
        if r.returncode:raise ValueError(label+' failed; see owned log')
        print(label+': passed',flush=True)
    try:
        binary=out/'factory.exe'
        run('compile',flags+[ROOT/'recomp/overrides/native_audio/v2/aggregate.cpp',ROOT/'recomp/overrides/native_audio/v3/aggregate.cpp',HERE/'tests.cpp','-Wl,--start-group',*[ROOT/n for n in native['libraries']],'-Wl,--end-group','-o',binary])
        for case in ('live','blocked','scoped','device_fence','legacy','disabled','phase','layout','memory','provider','registration','publication'):run(case,[binary,case])
        verify();record.update(status='native media factory protocol passed',scenarios=12,binary_sha256=sha(binary))
    finally:
        record['outputs_sha256']={p.name:sha(p)for p in out.iterdir()if p.is_file() and p.suffix=='.txt'};write(out/'receipt.json',json.dumps(record,indent=2)+'\n')
    print(json.dumps({'status':record['status'],'receipt_sha256':sha(out/'receipt.json')}))
if __name__=='__main__':main()
