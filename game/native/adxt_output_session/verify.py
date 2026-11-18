#!/usr/bin/env python3
"""Shared producer graph plus actual native adapter/exact raylib source model."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import subprocess
import shutil

HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[2]
BASE=ROOT/'build-native-sjuni/adxt-output-session'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True)
    p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();cc=shutil.which(a.cxx)
    if not cc or out.exists()or not out.is_relative_to(BASE):raise ValueError('Exact compiler and fresh output required')
    manifest=json.loads((HERE/'manifest.json').read_bytes())
    def drift():return[n for n,d in manifest['files'].items()if sha(ROOT/n)!=d]
    if drift():raise ValueError('Frozen source drift '+str(drift()))
    out.mkdir(parents=True);env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','')
    report=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),manifest_sha256=sha(HERE/'manifest.json'),
                game_run=False,device_opened=False,checks=[],negative_controls=[])
    def run(name,cmd,expected_failure=False):
        result=subprocess.run([str(x)for x in cmd],cwd=ROOT,env=env,text=True,capture_output=True,timeout=90)
        (out/(name+'.txt')).write_text(result.stdout+result.stderr,encoding='utf-8',newline='\n')
        report['checks'].append(dict(name=name,exit=result.returncode,command=[str(x)for x in cmd]))
        if expected_failure:
            if result.returncode==0:raise ValueError('Negative control passed '+name)
        elif result.returncode:raise ValueError(name+': '+result.stdout+result.stderr)
        return result.stdout.strip()
    flags=[cc,'-std=c++20','-O2','-pthread','-Wall','-Wextra','-Wpedantic','-Werror','-fno-fast-math','-ffp-contract=off','-I'+str(ROOT),'-I'+str(HERE)]
    deps=[ROOT/n for n in ['game/native/audio_mix_tail/mixer.cpp', 'game/native/audio_banks/v2/session.cpp', 'game/native/audio_banks/v2/algorithms.cpp', 'recomp/overrides/native_banks/v3/packet_adapter.cpp']]+[ROOT/'game/native/pcm/pcm.cpp',ROOT/'game/native/audio_output/audio_output_owner.cpp']
    try:
        binary=out/'units.exe';run('compile',flags+[HERE/'session.cpp',HERE/'session_tests.cpp',*deps,'-o',binary])
        report['units']=run('units',[binary])
        # Use the independently reviewed pinned raylib function extraction.
        import sys
        sys.path.insert(0,str(ROOT/'tools/native_reconstruction/audio_stream_provider'))
        import verify as original_provider
        raylib=ROOT/'third_party/PS2Recomp/out/build/_deps/raylib-src/src'
        if sha(raylib/'raudio.c')!=original_provider.SOURCE_SHA256 or sha(raylib/'raylib.h')!=original_provider.HEADER_SHA256:raise ValueError('Unqualified provider source')
        source=(raylib/'raudio.c').read_text()
        extracted={s:original_provider.function(source,s)for s in original_provider.FUNCTIONS}
        (out/'qualified_raudio.inc').write_text('\n\n'.join(extracted.values())+'\n',encoding='utf-8',newline='\n')
        original=(ROOT/'tools/native_reconstruction/audio_stream_provider/test_provider.cpp').read_text()
        prefix=original[:original.index('struct TestRenderer final')]
        fixture=prefix+'\n#include "game/native/adxt_output_session/session.hpp"\n'+r'''
int main() {
    namespace s=reo::native::adxt_output_session;
    namespace p=reo::native::adxt_playback;
    ready=true;auto provider=NativeStreamProvider::create();CHECK(provider);
    // Static process slot outlives this entire test and every successful join.
    auto slot=std::shared_ptr<CallbackSlot>(&native_stream_callback_slot(),[](CallbackSlot*){});
    s::Session session({2},slot,provider);
    auto a=session.open(1),b=session.open(1);CHECK(a.status==s::Status::completed && b.status==s::Status::completed);
    std::array<std::byte,1024> left{},right{};
    for(unsigned i=0;i<left.size();i+=2){left[i]=std::byte{64};right[i]=std::byte{128};}
    CHECK(a.producer->copy(left)==s::Status::completed && b.producer->copy(right)==s::Status::completed);
    CHECK(a.producer->play(true)==p::Status::completed && b.producer->play(true)==p::Status::completed);
    CHECK(session.start()==s::Status::completed && loads==1 && plays==1);
    std::array<float,64> output{};
    auto pump=[&]{std::lock_guard lock(AUDIO.System.lock);CHECK(AUDIO.Buffer.first && AUDIO.Buffer.first->playing);
        CHECK(ReadAudioBufferFramesInMixingFormat(AUDIO.Buffer.first,output.data(),32)==32);};
    pump();CHECK(output[0]==192.0f/32768.0f);
    CHECK(a.producer->retire()==s::Status::completed && stops==0 && converter_destroys==0);
    pump();CHECK(output[0]==128.0f/32768.0f && b.producer->snapshot().channel[0].consumed_bytes==128);
    CHECK(session.join()==s::Status::completed && session.snapshot().provider_joined);
    CHECK(provider->status()==NativeStreamStatus::unloaded && stops==1 && converter_destroys==1 && frees==2);
    CHECK(!slot->occupied() && !NativeStreamProvider::create());
    std::cout<<"actual native provider/static slot/exact raylib functions: shared streams passed (model device)\n";
}
'''
        client=out/'actual_provider.cpp';client.write_text(fixture,encoding='utf-8',newline='\n')
        binary=out/'actual_provider.exe'
        run('actual-provider-compile',flags+['-Wno-missing-field-initializers','-I'+str(raylib),'-I'+str(out),HERE/'session.cpp',ROOT/'runtime/audio/native_stream_provider.cpp',client,*deps,'-o',binary])
        report['actual_provider']=run('actual-provider',[binary]);report['extraction_sha256']=sha(out/'qualified_raudio.inc');report['generated_fixture_sha256']=sha(client)
        text=(HERE/'session.cpp').read_text()
        mutants=[('stale-generation','records[slot_index].generation==generation','records[slot_index].generation!=0 && generation!=0'),
                 ('missing-order','value && playing>=2 && s.order_required','value && playing>=2 && s.order_required && false')]
        for name,old,new in mutants:
            if text.count(old)!=1:raise ValueError('Negative source drift')
            mutant=out/(name+'.cpp');mutant.write_text(text.replace(old,new),encoding='utf-8',newline='\n')
            binary=out/(name+'.exe');run(name+'-compile',flags+[mutant,HERE/'session_tests.cpp',*deps,'-o',binary])
            run(name,[binary],expected_failure=True);report['negative_controls'].append(dict(name=name,source_sha256=sha(mutant)))
        report['status']='passed shared producer graph and actual adapter/source-model binding'
    except Exception as error:report.update(status='failed',failure=str(error));raise
    finally:
        report['source_drift']=drift()
        if report['source_drift']:report['status']='failed source drift'
        (out/'receipt.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=report['status'],units=report['units'],receipt_sha256=sha(out/'receipt.json'))))


if __name__=='__main__':main()
