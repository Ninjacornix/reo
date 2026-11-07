#!/usr/bin/env python3
"""Extend frozen aggregate2 with an explicit native-stream-only PCM profile.

The old null-stream profile remains a mechanical namespace derivation. New
stream output enters before banks/master, through the one retained callback.
"""
import argparse,hashlib,json
from pathlib import Path
HERE=Path(__file__).resolve().parent;PARENT=HERE.parent/'v2'
PIN='f6e7c65162da526eeb65e8a6a71335ddad83f09f5937a517eee82eeb7cb11012'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def replace(body,old,new):
    if body.count(old)!=1:raise ValueError('Unique derivation anchor required: '+old[:70])
    return body.replace(old,new)
def derived(name):
    body=(PARENT/name).read_text().replace('reo::native::audio_aggregate::v2','reo::native::audio_aggregate::v3')
    if name=='aggregate.h':
        body=replace(body,'#include "game/native/pcm_bridge/session_bridge.hpp"','#include "game/native/pcm_bridge/session_bridge.hpp"\n#include "game/native/adxt_output_session/session.hpp"')
        body=replace(body,'    bank::Snapshot banks{};','    std::uint64_t native_submix_calls{},native_submix_frames{},native_submix_failures{};\n    bool native_streams_bound{};\n    bank::Snapshot banks{};')
        body=replace(body,'    bank::Config banks;','    // When present, original PCM producers/reset are unsupported. The game\n    // binding must migrate every stream and retain its controls/source owners.\n    std::shared_ptr<adxt_output_session::Submix> native_streams;\n    bank::Config banks;')
    if name=='aggregate.cpp':
        body=replace(body,'    packet::Status checked(Operation op,packet::Status status)noexcept {','    std::atomic<std::uint64_t> native_calls{},native_frames{},native_failures{};\n    packet::Status checked(Operation op,packet::Status status)noexcept {')
        body=replace(body,'    std::shared_ptr<TestRenderProbe> test_probe;','    std::shared_ptr<TestRenderProbe> test_probe;\n    std::shared_ptr<adxt_output_session::Submix> native_streams;')
        body=replace(body,'        bank_result=render_call->mix(out,frames);','''        if(native_streams){
            ++metrics->native_calls;
            const auto status=native_streams->render_add(out,frames);
            if(status==adxt_output_session::Status::completed)metrics->native_frames.fetch_add(frames);
            else if(status!=adxt_output_session::Status::closed && status!=adxt_output_session::Status::pending){
                ++metrics->native_failures;bank_result=a::BankStatusV2::rejected;return;
            }
        }
        bank_result=render_call->mix(out,frames);''')
        body=replace(body,'bridge(host,d){host->test_probe=std::move(probe);}','bridge(host,d){host->test_probe=std::move(probe);host->native_streams=inputs.native_streams;}')
        body=replace(body,'        const auto& m=*metrics;for(std::size_t n=0;n<operation_count;++n)', '        r.native_streams_bound=bool(inputs.native_streams);r.native_submix_calls=metrics->native_calls.load();r.native_submix_frames=metrics->native_frames.load();r.native_submix_failures=metrics->native_failures.load();\n        const auto& m=*metrics;for(std::size_t n=0;n<operation_count;++n)')
        # Refuse original PCM production before effects. Separate pre-clipped
        # PCM sums cannot reproduce arbitrary interleaved original voice order.
        body=replace(body,'if(!s.raw(Operation::queue,id))return false;','if(s.inputs.native_streams){s.metrics->refuse(Operation::queue,249,id);return false;}if(!s.raw(Operation::queue,id))return false;')
        body=replace(body,'    if(s.raw(Operation::configure,id)', '    if(s.inputs.native_streams && playing){s.metrics->refuse(Operation::configure,249,id);return;}\n    if(s.raw(Operation::configure,id)')
        body=replace(body,'OperationFrame f(*s.metrics,Operation::reset,&s);s.metrics->checked', 'OperationFrame f(*s.metrics,Operation::reset,&s);if(s.inputs.native_streams){s.metrics->refuse(Operation::reset,249);return;}s.metrics->checked')
    if name=='tests.cpp':
        body=replace(body,'    Setup(){hooks->runtime=', '    Setup(std::shared_ptr<reo::native::adxt_output_session::Submix> streams={}){hooks->runtime=')
        body=replace(body,'inputs.slot=slot;inputs.banks.path_counters=', 'inputs.slot=slot;inputs.native_streams=std::move(streams);inputs.banks.path_counters=')
    return '// Derived from frozen Aggregate2; native stream-only composition profile.\n'+body
def main():
    p=argparse.ArgumentParser();p.add_argument('--check',action='store_true');a=p.parse_args()
    if sha(PARENT/'identity.json')!=PIN:raise ValueError('Frozen parent identity changed')
    for name,digest in json.loads((PARENT/'identity.json').read_bytes())['candidate_sha256'].items():
        if sha(PARENT/name)!=digest:raise ValueError('Frozen parent changed '+name)
    for name in ['aggregate.h','aggregate.cpp','tests.cpp','oracle_transport.hpp']:
        body=derived(name);path=HERE/name
        if a.check:
            if path.read_text()!=body:raise ValueError('Aggregate3 derivation drift '+name)
        else:path.write_text(body,encoding='utf-8',newline='\n')
    print('Aggregate3 derivation '+('checked'if a.check else 'written'))
if __name__=='__main__':main()
