#!/usr/bin/env python3
"""Preserve frozen Aggregate3 and add a scoped canonical-owner reset entry."""
import argparse,hashlib
from pathlib import Path
HERE=Path(__file__).resolve().parent;PARENT=HERE.parent/'v3'
PINS={'aggregate.cpp':'108026b7390dc1a20796bcca0b266a80eb07bc109dcdbae3a9e63809867e3538','aggregate.h':'0906f56fabab112eca3a8b25c093d915c1ac056d0f9ee15b0af2d2f19f2cc3c4'}
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def derived():
    for name,digest in PINS.items():
        if sha(PARENT/name)!=digest:raise ValueError('Frozen Aggregate3 changed '+name)
    original=(PARENT/'aggregate.h').read_text()
    declaration=original[original.index('class Aggregate;'):original.index('} // namespace reo::native::audio_aggregate::v3')]
    declaration=declaration.replace('enum class BuildStatus {ready_composition,invalid_inputs,provider_rejected,allocation_failed};','using parent::BuildStatus;')
    declaration=declaration.replace('    Report report()const noexcept;','    Report report()const noexcept;\n    // Null, foreign, expired or wrong-thread proof refuses before reset effects.\n    [[nodiscard]] bool reset_native(const adxt_control_owner::Quiescent*)noexcept;')
    header='''// Derived from frozen Aggregate3. Shared ports remain the exact parent ABI.
#pragma once
#include "../v3/aggregate.h"
#include "game/native/adxt_control_owner/owner.hpp"
namespace reo::native::audio_aggregate::v4 {
namespace parent=audio_aggregate::v3;
namespace pcm=pcm_bridge;namespace bank=audio_banks::v2;namespace packet=bank_packets::v3;namespace output=reo::audio_output;
using parent::Operation;using parent::operation_count;
using parent::production_channels;using parent::production_voices;using parent::production_pcm_bytes;
using parent::PacketBorrow;using parent::BankBorrow;using parent::PacketOperation;using parent::BankOperation;
using parent::QualifiedCaptureProvider;using parent::HostHooks;using parent::Inputs;using parent::Report;
using parent::TestRenderProbe;using parent::TestDomain;
'''+declaration+'} // namespace reo::native::audio_aggregate::v4\n'
    cpp=(PARENT/'aggregate.cpp').read_text().replace('reo::native::audio_aggregate::v3','reo::native::audio_aggregate::v4')
    anchor='void Aggregate::reset_pcm()noexcept'
    if cpp.count(anchor)!=1:raise ValueError('Reset derivation anchor')
    addition='''bool Aggregate::reset_native(const adxt_control_owner::Quiescent* proof)noexcept {
    auto& s=*state_;OperationFrame frame(*s.metrics,Operation::reset,&s);
    if(!proof || !proof->authorizes(s.inputs.native_streams)){s.metrics->refuse(Operation::reset,249);return false;}
    // Canonical source creation is excluded for this entire call. Every source
    // already joined and private output fenced; the raw bridge acquires its
    // own data lock. Never take the private submix lock around raw reset:
    // actual output rendering acquires raw bridge -> private submix.
    return s.metrics->checked(Operation::reset,s.bridge.reset());
}
'''
    return {'aggregate.h':header,'aggregate.cpp':cpp.replace(anchor,addition+anchor)}

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--check',action='store_true');a=p.parse_args()
    for name,body in derived().items():
        path=HERE/name
        if a.check:
            if path.read_text()!=body:raise ValueError('Aggregate4 derivation drift '+name)
        else:path.write_text(body,encoding='utf-8',newline='\n')
    print('Aggregate4 derivation '+('checked' if a.check else 'written'))
if __name__=='__main__':main()
