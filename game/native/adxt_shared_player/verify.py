#!/usr/bin/env python3
"""Shared decoder/source/output composition plus actual provider source model."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys

HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[2]
BASE=ROOT/'build-native-sjuni/adxt-shared-player'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True)
    p.add_argument('--output',type=Path,required=True);a=p.parse_args();cc=shutil.which(a.cxx);out=a.output.resolve()
    if not cc or out.exists()or not out.is_relative_to(BASE):raise ValueError('Exact compiler and fresh scoped output required')
    manifest=json.loads((HERE/'manifest.json').read_bytes())
    def drift():return[n for n,d in manifest['files'].items()if sha(ROOT/n)!=d]
    if drift():raise ValueError('Frozen graph drift '+str(drift()))
    out.mkdir(parents=True);env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','')
    report=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),manifest_sha256=sha(HERE/'manifest.json'),game_run=False,device_opened=False,checks=[],negative_controls=[])
    def run(name,cmd,negative=False):
        r=subprocess.run([str(x)for x in cmd],cwd=ROOT,env=env,text=True,capture_output=True,timeout=90)
        (out/(name+'.txt')).write_text(r.stdout+r.stderr,encoding='utf-8',newline='\n');report['checks'].append(dict(name=name,command=[str(x)for x in cmd],exit=r.returncode))
        if negative:
            if not r.returncode:raise ValueError('Negative passed '+name)
        elif r.returncode:raise ValueError(name+': '+r.stdout+r.stderr)
        return r.stdout.strip()
    flags=[cc,'-std=c++20','-O2','-pthread','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-misleading-indentation','-fno-fast-math','-ffp-contract=off','-frounding-math','-I'+str(ROOT),'-I'+str(HERE)]
    deps=[ROOT/n for n in ['game/native/sjrb/sjrb.cpp','game/native/adxt_shared_source/shared_source.cpp','game/native/adxt_refill/adxt_refill.cpp',
        'game/native/resource_io/async_read_owner.cpp','game/native/tasks/serial_worker.cpp','game/native/resources/resource_session.cpp',
        'game/native/resources/virtual_file_view.cpp','game/native/resources/bounded_view.cpp','game/native/adx_header/adx_header.cpp',
        'game/native/adx_workspace/adx_workspace.cpp','game/native/adx_pcm_store/v2/pcm_store.cpp','game/native/adx_window/v2/playback_r2/stream_window.cpp',
        'game/native/adxt_playback/playback.cpp','game/native/adxt_output_session/session.cpp','game/native/pcm/pcm.cpp','game/native/audio_output/audio_output_owner.cpp']]
    try:
        unit=out/'units.exe';run('units-compile',flags+[HERE/'player.cpp',HERE/'player_tests.cpp',*deps,'-o',unit]);report['units']=run('units',[unit])
        sys.path.insert(0,str(ROOT/'tools/native_reconstruction/audio_stream_provider'));import verify as original
        raylib=ROOT/'third_party/PS2Recomp/out/build/_deps/raylib-src/src'
        if sha(raylib/'raudio.c')!=original.SOURCE_SHA256 or sha(raylib/'raylib.h')!=original.HEADER_SHA256:raise ValueError('Provider authority drift')
        source=(raylib/'raudio.c').read_text();(out/'qualified_raudio.inc').write_text('\n\n'.join(original.function(source,s)for s in original.FUNCTIONS)+'\n',encoding='utf-8',newline='\n')
        text=(ROOT/'tools/native_reconstruction/audio_stream_provider/test_provider.cpp').read_text();prefix=text[:text.index('struct TestRenderer final')]
        fixture=prefix+'\n#include "game/native/adxt_shared_player/player.hpp"\n#include "game/native/adxt_shared_player/test_sources.hpp"\n'+r'''
int main(){
    namespace p=reo::native::adxt_shared_player;namespace t=p::testing;namespace o=reo::native::adxt_output_session;
    ready=true;auto provider=NativeStreamProvider::create();CHECK(provider);
    auto slot=std::shared_ptr<CallbackSlot>(&native_stream_callback_slot(),[](CallbackSlot*){});
    o::Session output({2},slot,provider);CHECK(output.start()==o::Status::completed);
    auto make=[&](unsigned channels,unsigned rate,unsigned samples){auto file=t::file(channels,rate,samples);p::Config c;
        c.decoder.channels=channels;c.decoder.source_config.byte_length=static_cast<std::int32_t>(file->size());
        auto producer=output.open(channels);CHECK(producer.status==o::Status::completed);
        return std::make_unique<p::Player>(c,std::move(producer.producer),file,reo::native::adxt_refill::make_async_backend(8192),std::make_shared<reo::native::adx_header::KeyContext>());};
    auto a=make(1,48000,65),b=make(2,24000,40017);
    auto pump=[&]{std::array<float,128> data{};std::lock_guard lock(AUDIO.System.lock);
        CHECK(ReadAudioBufferFramesInMixingFormat(AUDIO.Buffer.first,data.data(),64)==64);};
    for(unsigned n=0;n<10000;++n){CHECK(a->service(0)!=p::Status::fault && b->service(0)!=p::Status::fault);pump();
        if(b->snapshot().output.channel[0].consumed_bytes && a->snapshot().first_payload_samples==65)break;std::this_thread::yield();}
    CHECK(b->snapshot().output.channel[0].consumed_bytes>0 && a->snapshot().first_payload_samples==65);
    auto retire=[&](p::Player& player){for(unsigned n=0;n<10000;++n){auto result=player.retire_on_control_thread();
        if(result==p::Status::completed)return;CHECK(result==p::Status::pending);std::this_thread::yield();}CHECK(false);};
    retire(*a);CHECK(a->snapshot().decoder.source.joined && stops==0 && loads==1 && plays==1);
    const auto before=b->snapshot().output.channel[0].consumed_bytes;
    for(unsigned n=0;n<1000 && b->snapshot().output.channel[0].consumed_bytes==before;++n){CHECK(b->service(0)!=p::Status::fault);pump();std::this_thread::yield();}
    CHECK(b->snapshot().output.channel[0].consumed_bytes>before && provider->status()==NativeStreamStatus::active);
    retire(*b);CHECK(b->snapshot().decoder.source.joined && stops==0);
    CHECK(output.join()==o::Status::completed && stops==1 && converter_destroys==1 && frees==2 && !slot->occupied());
    std::cout<<"two actual decoder workers/actual provider/static slot/exact raylib functions passed (model device)\n";
}
'''
        client=out/'actual_provider.cpp';client.write_text(fixture,encoding='utf-8',newline='\n');binary=out/'actual_provider.exe'
        run('actual-provider-compile',flags+['-Wno-missing-field-initializers','-Wno-misleading-indentation','-I'+str(raylib),'-I'+str(out),HERE/'player.cpp',ROOT/'runtime/audio/native_stream_provider.cpp',client,*deps,'-o',binary])
        report['actual_provider']=run('actual-provider',[binary]);report['fixture_sha256']=sha(client);report['raylib_extraction_sha256']=sha(out/'qualified_raudio.inc')
        source=(HERE/'player.cpp').read_text()
        first='if(output->copy(spans[0],spans[1])!=output::Status::completed)return fail();\n            if(decoder.finish_pcm(*held)!=window::Status::completed)return fail();'
        second='if(decoder.finish_pcm(*held)!=window::Status::completed)return fail();\n            if(output->copy(spans[0],spans[1])!=output::Status::completed)return fail();'
        mutants=[('early-source-credit',first,second),('orphan-on-constructor','catch(...) { if(output)(void)output->retire();throw; }','catch(...) { throw; }')]
        for name,old,new in mutants:
            if source.count(old)!=1:raise ValueError('Negative source drift')
            path=out/(name+'.cpp');path.write_text(source.replace(old,new),encoding='utf-8',newline='\n');binary=out/(name+'.exe')
            run(name+'-compile',flags+[path,HERE/'player_tests.cpp',*deps,'-o',binary]);run(name,[binary],negative=True)
            report['negative_controls'].append(dict(name=name,source_sha256=sha(path)))
        report['status']='passed shared player ownership and actual provider/source-model integration'
    except Exception as error:report.update(status='failed',failure=str(error));raise
    finally:
        report['source_drift']=drift()
        if report['source_drift']:report['status']='failed source drift'
        (out/'receipt.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=report['status'],units=report['units'],receipt_sha256=sha(out/'receipt.json'))))


if __name__=='__main__':main()
