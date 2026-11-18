#!/usr/bin/env python3
"""Copy qualified124 host bank algorithms; never edits the dependency checkout."""
import hashlib
from pathlib import Path

HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]
SOURCE=ROOT/'build-native-sjuni/dependency-pcm-boot-reapply-v3/ps2xRuntime/src/lib/Kernel/Syscalls/Helpers'
HASHES={'ReoSoundBanks.h':'28963da544d533ae8f04765558ff0665c4dc87c38cfba767a4828705c07616c8',
    'ReoSoundBanks.cpp':'e164ba72cc002311d4811d803be2e2df9a6228d5abcaa0c4fa419a31ee09b818'}
def main():
    for name,digest in HASHES.items():
        if hashlib.sha256((SOURCE/name).read_bytes()).hexdigest()!=digest:raise ValueError('Qualified reference changed')
    header=(SOURCE/'ReoSoundBanks.h').read_text(encoding='utf-8').split('// Synchronous EE bank transfers;',1)[0]
    header=header.split('// Synchronous EE bank transfers',1)[0]
    header=header.replace('namespace ps2_reo_sound {','namespace reo::native::audio_banks::detail {')
    header=header.replace('    bool active() const { return active_; }','''    bool active() const { return active_; }
    auto observe() const noexcept {return SequenceInfo{cursor_,wait_,programOffset_,active_,hasNote_};}''')
    header=header.replace('#include <cstddef>','#include "session.hpp"\n#include <cstddef>')+'}\n'
    notice='// Source-derived from PS2Recomp ReoSoundBanks.{h,cpp}, qualified124.\n// Original dependency GNU GPLv3 license retained: LICENSE-PS2Recomp.\n'
    (HERE/'algorithms.hpp').write_text(notice+header,encoding='utf-8',newline='\n')
    cpp=(SOURCE/'ReoSoundBanks.cpp').read_text(encoding='utf-8')
    prefix=cpp.split('namespace {\nstruct Envelope {',1)[0]
    prefix=prefix.replace('#include "ReoSoundBanks.h"','#include "algorithms.hpp"')
    prefix=prefix.replace('float reoAudioBankGain(unsigned port,unsigned sequence,uint64_t fingerprint);\n','')
    prefix=prefix.replace('namespace ps2_reo_sound {','namespace reo::native::audio_banks::detail {')+'}\n'
    (HERE/'algorithms.cpp').write_text(notice+prefix,encoding='utf-8',newline='\n')
    structs=cpp.split('namespace {\nstruct Envelope {',1)[1].split('std::array<Port,14> ports;',1)[0]
    structs='struct Envelope {'+structs
    structs=structs.replace('    Sample sample;','    Sample sample;\n    std::uint64_t asset_serial{};')
    structs=structs.replace('struct Port { uint64_t fingerprint=0; Bank bank;', 'struct Port { uint64_t fingerprint=0; std::shared_ptr<const AssetData> asset;')
    (HERE/'source_records.inc').write_text(notice+structs,encoding='utf-8',newline='\n')
    # Member bodies retain source traversal/arithmetic. Storage, diagnostic
    # sinks and prepared-asset indirection are explicitly separate alterations.
    start=cpp.index('void stop(unsigned port, int slot = -1, bool release = false)')
    end=cpp.index('\n}\n\nbool submitBank',start)
    members=cpp[start:end]
    i=members.index('bool installBankUnlocked(');j=members.index('bool matches(',i)
    members=members[:i]+members[j:]
    members=members.replace('p.bank.','p.asset->bank.').replace('r.sequence.tick(p.bank,','r.sequence.tick(p.asset->bank,')
    members=members.replace('r.sequence.start(p.bank,','r.sequence.start(p.asset->bank,')
    members=members.replace('    std::vector<Event> events; std::vector<Sample> samples;','    events.clear(); samples.clear();')
    members=members.replace('Voice v; v.port = port;', 'Voice v; v.asset_serial=p.asset->serial; v.port = port;')
    (HERE/'source_members.inc').write_text(notice+members+'\n',encoding='utf-8',newline='\n')
    mix=cpp.split('void mix(float* stereo, unsigned frames) {',1)[1].split('\n// Called only by',1)[0]
    mix=mix.rsplit('\n}',1)[0]
    mix=mix.replace('    if (!stereo || !frames) return;\n    std::lock_guard<std::mutex> lock(soundMutex);\n','')
    mix=mix.replace('    if (pathLog) pathMixFrames += frames;','')
    begin=mix.index('    std::array<std::array<float,16>,14> gains{};');end=mix.index('    for (unsigned frame',begin)
    mix=mix[:begin]+mix[end:]
    mix=mix.replace('''                const unsigned pitch = std::min(0x3FFFu, unsigned(std::max(0.,std::floor(4096. * s.sampleRate / kOutputRate * std::exp2(semitones / 12.)))));''','''                const double pitch_value=std::max(0.,std::floor(4096. * s.sampleRate / kOutputRate * std::exp2(semitones / 12.)));
                if(!std::isfinite(pitch_value)||pitch_value>double(UINT32_MAX))return numeric_failure();
                const unsigned pitch = std::min(0x3FFFu, unsigned(pitch_value));''')
    mix=mix.replace('''        if (frameClock % kFramesPerTick == kFramesPerTick - 1)
            voices.erase(std::remove_if(voices.begin(),voices.end(),[](const Voice& v){return !v.active;}),voices.end());''','''        if (frameClock % kFramesPerTick == kFramesPerTick - 1) reclaim_inactive();''')
    (HERE/'source_mix.inc').write_text(notice+mix+'\n',encoding='utf-8',newline='\n')
    (HERE/'LICENSE-PS2Recomp').write_bytes((SOURCE.parents[5]/'LICENSE').read_bytes())
if __name__=='__main__':main()
