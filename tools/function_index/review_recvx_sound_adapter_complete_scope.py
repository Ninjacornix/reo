#!/usr/bin/env python3
"""Offline exhaustive CVX SDK-facing sound facade applicability ledger."""
import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import re
import sqlite3
import struct

from index import Elf
from recvx_scope_inventory import function_records, PIN
from review_recvx_audio_second_pass import SHA

ROOT = Path(__file__).resolve().parents[2]
BASE = 'src/ps2/veronica/prog/'


def dispositions():
    rows = {}

    def add(file, family, candidates, text):
        for line in text.strip().splitlines():
            name, contract = (p.strip() for p in line.split('|', 1))
            assert (file, name) not in rows
            rows[file, name] = dict(status='no-demonstrated-counterpart', family=family,
                reference_contract=contract, outbreak_ids=[], searched_candidates=candidates.split())

    add('sdc.c', 'driver-transfer-lifecycle', '1A71E0 1AC6D0 1A7FA0 1A7F50 1AC730 1A7900', '''
TransWaitCallBackFunction | Destroys global SdMemBlk and clears TransCompleteFlag; Outbreak RPC completion1A7FA0 signals a supplied semaphore only. No same shared memory-block lifetime/flag callback.
CheckTransComplete | Returns global TransCompleteFlag directly. Outbreak1A7F50 polls/waits then restores a semaphore and returns0/1; it is not this plain flag accessor or proof of payload/audio completion.
SetupSoundDriver | sdLibInit, create/set driver memory block using prior callback, sdDrvInit, destroy block, DMA transfer mode, install callback and slot maxima36/20/8. Outbreak initializes two SDR RPC clients/queue/semaphores and separate named-bank state; no same sd library/memory-block/port setup.
ExitSoundDriver | Stops tracked FX, sdSndStopAll and sdSysFinish. No matching complete sd MIDI/shot port shutdown facade established in SDR/CRI owners.
SetMultiUnit | Creates block, sets transfer flag, configures callback-1, downloads multi-unit and destroys block. Outbreak three-span bank-transfer admission/packing has different metadata, callback and ownership protocol.
SetSoundData | Creates shared block, sets flag, binds caller payload and current callback, invokes sdBankDownload(DataType,BankNo); no local destroy, leaving callback lifetime. Outbreak1AC730/1A7900 use converted bank sections and RPC/queue acknowledgement; not the same complete transfer API.
''')
    add('sdc.c', 'sound-mode-configuration', '1AC6D0 1A71E0 1A7FB0', '''
SetSoundModeEx | Mode0 selects stereo and GDDA pan127/-127; other modes mono and0/0; caches original mode and optionally calls syCfgSetSoundMode. No identical SDR/CRI mode field, port-pan law or persistence wrapper demonstrated.
SetSoundMode | Calls SetSoundModeEx with persistence flag1. No Outbreak full stereo/GDDA/cache/config wrapper pair established from generic control RPC.
GetSoundMode | Lazy caches syCfgGetSoundMode only while local cache-1. Outbreak inspected audio initialization/control has no demonstrated matching lazy OSD-cache owner; no cross-game cache-field identity.
''')
    add('sdc.c', 'volume-configuration', '1ACEB0 1ADFD0 1AE0C0 13F038', '''
SetMasterVolume | sdSndSetMasterVol(charVolume) then caches byte. Outbreak1ACEB0 uses zero-gain gate and queued slot/global SDR commands; CRI attenuation13F038 clamps-999..0. No identical complete master-volume facade or units.
SetGdDaVolume | Stores byte SdcGdDaVolume only, without SDK call. No connected Outbreak GDDA field/consumer identified; a generic byte store is insufficient identity.
SetMidiDefaultVolume | Stores SdcMidiDefaultVolume byte only; no whole corresponding Outbreak8-MIDI-port default field/consumer identified. Do not infer effect from storage spelling alone.
SetSeDefaultVolume | Stores SdcSeDefaultVolume byte, which both extended request bodies can select. No same Outbreak default byte/request structure demonstrated.
''')
    add('sdc.c', 'midi-port-adapters', '1AC7F0 1A7310 1A7430 1A7550 1AE2E0 1AE190 13F058', '''
InitMidiInfo | Visits8 SDS_INFO slots; first initialization clears flags, later initialization frees registered ports; zeros volume/limit/fade/pan modes. Outbreak SDR request queue and three ADXT records have different storage/lifetime.
RegistMidiSlot | Already registered returns1; otherwise sdMidiOpenPort into MidiHandle[slot], sets flag1, returns0, ignoring child status. No local slot bound; no matching Outbreak8-port allocation facade.
FreeMidiSlot | If registered calls sdMidiClosePort then clears flag. Outbreak cancellation/stream stop does not close an equivalent per-slot MIDI port.
CheckPlayMidi | sdMidiGetStat into local status then returns m_Flg&1; no registration guard. Outbreak query1AE2E0 multiplexes ADXT state/control fields, not the same status bit/port object.
PlayMidi | Registered slot and ListNo!=-1 gate sdMidiPlay(handle,bank,list,priority). Outbreak descriptor request links/randomization/queue identity differ; no same port ownership or signed request sentinel.
ExPlayMidi | SND_REQ per-field delay-2 resets,-1 preserves,others update; volume reset uses SdcSeDefaultVolume even for MIDI, not Midi default. Pitch/speed/effect controls precede PlayMidi; no same Outbreak descriptor/request ABI demonstrated.
StopMidi | Registered flag gates sdMidiStop(handle), preserving open slot. Outbreak cancel coalescing or ADXT stop uses distinct handles/state and is not a matching full MIDI wrapper.
SetPanMidi2 | Registered AND (PanFunc!=0 OR FadeFunc!=2) gates sdMidiSetPan(float,shortDelay), then caches float pan. This surprising FadeFunc predicate is literal source; no Outbreak corresponding guard or delayed float-pan port API.
SetPanMidi | Converts char pan to float and delegates SetPanMidi2. Outbreak signed-byte SDR presence flags and CRI-15..15 pan clamp are different units/ownership.
SetVolumeMidiEx | Active FadeFunc0 sends/stores caller volume; FadeFunc1 may retarget fade when Flag0 and new volume<VolLast, stores volume then falls through2 to send cached volume with delay0. No same Outbreak setter/fade-state fallthrough contract.
SetVolumeMidi | Char volume adapter to SetVolumeMidiEx with Flag0. Outbreak quantized level/attenuation setters are another representation and cancellation policy.
SetVolumeMidi2 | Float volume adapter to SetVolumeMidiEx with Flag0. No identical Outbreak8-port volume/fade-state facade established.
SetPitchMidi | Registered slot gates sdMidiSetPitch(shortPitch,shortDelay). Outbreak SDR pitch payload does not establish MIDI port or delay semantics.
SetSpeedMidi | Registered slot gates sdMidiSetSpeed(shortSpeed,shortDelay). No matching complete MIDI tempo/speed owner shown in SDR effect requests or ADXT streams.
SetFxLevelMidi | Registered slot gates sdMidiSetFxLev(charFxLevel). No identical Outbreak port-specific effect-send facade or parameter units established.
''')
    add('sdc.c', 'shot-port-adapters', '1AC7F0 1A7310 1A7430 1A7550 1AE2E0 1AE190 13F058', '''
InitSeInfo | Visits20 SDS_INFO slots, initial flag clear or later FreeSeSlot, zeroes volume/limit/fade/pan modes. Distinct from32 queued SDR command slots or three ADXT channels.
RegistSeSlot | Existing registration returns1; otherwise sdShotOpenPort, flag1, return0 without checking status. No same Outbreak20-shot-port allocation interface.
FreeSeSlot | Conditionally sdShotClosePort then clears registration flag; not equivalent to SDR queued cancellation or retained ADXT stop.
CheckPlaySe | sdShotGetStat and lowbit query without local registration guard. No same Outbreak status bit/shot-port record established.
PlaySe | Registered and ListNo!=-1 gates sdShotPlay(handle,bank,list,priority). Outbreak SdrSeReq exposes packed identity and parameter presence, not this registered shot handle/request tuple.
ExPlaySe | SND_REQ delay-2 resets,-1 preserves,others update pan/volume/pitch; FX switch-2 explicitly sends0,-1 skips. No MIDI speed path here and no same Outbreak whole request ABI.
StopSe | Registered slot gates sdShotStop on retained port. SDR cancellation edits pending commands/coalesces before enqueue; no equivalent full registered-shot stop facade.
SetPanSe2 | Registered slot sends float pan/short delay then caches pan; unlike MIDI variant it has no FadeFunc/PanFunc admission condition. Outbreak pan fields and deferred queue controls differ.
SetPanSe | Char-to-float wrapper to SetPanSe2. No same typed slot/port/float-delay wrapper in the inspected Outbreak consumers.
SetVolumeSeEx | Shot counterpart of FadeFunc0 direct setter and FadeFunc1 retarget/store/fallthrough2 cached immediate update. Outbreak channel level setter cancels a different ramp representation, not this protocol.
SetVolumeSe | Char volume and Flag0 adapter to SetVolumeSeEx. No same shot-port registration/fade-state ABI demonstrated.
SetVolumeSe2 | Float volume and Flag0 adapter to SetVolumeSeEx. Not identical to Outbreak signed integer level plus gain-table conversion.
SetPitchSe | Registered shot port gates short pitch/delay SDK call. Outbreak queue pitch halfword alone cannot establish same delay or ownership contract.
SetFxLevelSe | Registered shot port gates sdShotSetFxLev. No same complete Outbreak slot-specific effect-send facade established.
''')
    add('sdc.c', 'effect-program-adapters', '1A7FB0 1A8060 1AC6D0', '''
SetFxProgram | sdSndSetFxPrg(charProgram,charOutput) then sets ExecFxFlag1. Inspected SDR numeric control RPC is not decoded to this program/output API; no enum or ownership identity inferred.
StopFxProgram | Calls sdSndClearFxPrg only if ExecFxFlag nonzero, always clears flag. No same connected Outbreak effect-program flag/set/clear pair demonstrated.
''')
    add('sdc.c', 'volume-fade-state', '1AE3F0 1AE470 1AE4B0 1ADFD0', '''
RequestMidiFadeFunction | Sets start-127/targetLimit forFunc1 or target-127 forFunc2; count=((Timer/100)*30+((Timer%100)*6)/10)/2, exact0=>1; speed=(Volume-target)/count. Different from Outbreak maximum-capped target/duration step with no timer conversion/countdown.
RequestMidiFadeFunctionEx | Start-1 uses integer conversion of current float volume, stores target/count; Frame0 leaves old VolSpeed, then speed<0 choosesFunc1 else2. Outbreak1AE3F0 always divides by supplied duration and has no matching stale-speed or sentinel branch.
StopFadeMidi | Clears MidiInfo.FadeFunc only; no SDK stop. Outbreak1ADFD0 clears its ramp as part of volume publication, not this isolated8-port state operation.
RequestSeFadeFunction |20-slot shot counterpart of timer formula, Func1 start-127/targetLimit,Func2 target-127 and exact-zero count fixup. No same Outbreak ramp/count/units or stop sentinel established.
RequestSeFadeFunctionEx | Shot start-1/current-to-int, explicit target/count and Frame0 stale speed preserved. No identical Outbreak whole request or state transition.
StopFadeSe | Clears SeInfo.FadeFunc only; no port stop or volume change. No same connected Outbreak20-port isolated fade-mode clear.
CheckFadeEndSe | Returns0 when FadeFunc0,otherwise1, i.e. outstanding fade flag despite End name. Outbreak1AE470 tests float ramp!=0 (including NaN), different representation/ownership.
ExecSoundFadeManager | Scans8 MIDI+20 shot SDS_INFO records; modes1/2 subtract speed and predecrement count, snaps only when count<0, stops port at intVolume==-127, then sends through forced setter. Outbreak three-channel worker uses maximum/gain-table quantization and target crossing with no such countdown or MIDI/shot stop sentinel.
''')
    add('sdc.c', 'pan-ramp-state', '1AE3F0 1AE4B0 13F058 1A7550', '''
RequestMidiPanFunctionEx | StartPan-1 uses int conversion of current float, sets last/count, updates speed only if Frame!=0 using128+pan operands, always sets PanFunc1. No identical Outbreak pan-ramp/count/slot protocol.
RequestSePanFunctionEx |20-slot shot counterpart retaining old PanSpeed for Frame0; explicit128-offset arithmetic and signed sentinel are reference-specific. No same Outbreak complete pan-ramp constructor shown.
ExecSoundPanManager | Scans8+20 slots; active pan subtracts speed/decrements count, snaps/clears only below0, calls per-port float pan setter every active invocation. Outbreak ramp worker is volume-only and CRI pan setter is a clamped stored integer, not this complete pan manager.
''')
    add('sdcwrap.c', 'sound-bootstrap-facade', '1AC6D0 1A71E0 1AC730 1ACEB0', '''
InitSdcParameter | Reads/applies cached config mode, sets master15/GDDA127/default MIDI0/default shot0, initializes8/20 slot tables, then sets first flag1. No same Outbreak defaults, local tables or sd port lifecycle established.
InitSoundDriver | Queries/allocates/reads driver file with tray check and ExitApplication on read failure, calls SetupSoundDriver and frees buffer; optional multi-unit repeats flow, then parameter init/return0. No same complete Outbreak filename-driven sd driver/multi-unit loader facade demonstrated.
''')
    assert len(rows) == 57
    return rows


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--reference', type=Path, default=Path.home() / 'AppData/Local/Temp/reo-recvx-crosscheck-20261104')
    ap.add_argument('--output', type=Path, default=ROOT / 'build-function-index/recvx-sound-adapter-complete-scope.json')
    args = ap.parse_args()
    universe = json.loads((ROOT / 'build-function-index/recvx-complete-source-inventory.json').read_text(encoding='utf-8'))
    assert universe['reference_commit'] == PIN
    elf = Elf(ROOT / 'game_data/SLUS_207.65')
    assert elf.sha256 == SHA
    db = sqlite3.connect(f'file:{ROOT / "build-function-index/index.sqlite"}?mode=ro', uri=True)
    annotations = {}
    for path in sorted((ROOT / 'docs').glob('SYMBOLS*.md')):
        for i, line in enumerate(path.read_text(encoding='utf-8').splitlines(), 1):
            m = re.match(r'^\| \[(?:main )?0x([\da-f]+)\]\(', line, re.I)
            if m:
                annotations.setdefault(f'{int(m[1],16):X}', []).append(dict(path=path.relative_to(ROOT).as_posix(), line=i, text=line))
    audited = {}

    def owned(address):
        if address in audited:
            return audited[address]
        start = int(address, 16)
        row = db.execute('select end,source,proposed_name from functions where image=? and start=?', ('main', start)).fetchone()
        assert row, address
        end, source, label = row
        raw = elf.read(start, end-start)
        assert raw is not None and len(raw) == end-start
        words = {int(pc, 16): int(w, 16) for pc, w in re.findall(r'// 0x([\da-f]+): 0x([\da-f]+)\s+', (ROOT/source).read_text(encoding='utf-8'), re.I) if start <= int(pc,16) < end}
        for pc, word in words.items():
            assert elf.read(pc, 4) == struct.pack('<I', word), (address, hex(pc))
        missing = [pc for pc in range(start, end, 4) if pc not in words]
        assert all(elf.read(pc, 4) == b'\0'*4 for pc in missing), address
        audited[address] = dict(id='main:'+address, source=source, label=label, end_exclusive=f'{end:X}',
            sha256=hashlib.sha256(raw).hexdigest(), verified_words=len(words), omitted_zero_words=len(missing), notes=annotations.get(address, []))
        return audited[address]

    manual = dispositions()
    files = []
    consumed = set()
    for name in ('sdc.c', 'sdcwrap.c'):
        original = next(f for f in universe['files'] if f['path'] == BASE+name)
        raw = (args.reference / original['path']).read_bytes()
        assert hashlib.sha256(raw).hexdigest() == original['sha256']
        text = raw.decode('utf-8-sig')
        parsed = function_records(text)
        assert [(x['symbol'], x['start_line'], x['body_sha256']) for x in parsed] == [(x['symbol'], x['start_line'], x['body_sha256']) for x in original['functions']]
        entries = []
        for source, parsed_source in zip(original['functions'], parsed):
            key = (name, source['symbol'])
            assert key in manual and source['implementation_shape'] == 'nonempty'
            consumed.add(key)
            record = dict(reference_file=original['path'], reference_file_sha256=original['sha256'], **source, **manual[key])
            record['signature'] = text[source['header_start']:source['body_start']].strip()
            comments = re.findall(r'//[^\r\n]*matching[^\r\n]*', text[max(0, source['header_start']-160):source['header_start']], re.I)
            record['reference_progress_comment'] = comments[-1] if comments else None
            record['reference_calls'] = sorted(set(re.findall(r'\b([A-Za-z_]\w*)\s*\(', parsed_source['masked_body'])) - {'if', 'for', 'while', 'switch', 'sizeof', 'return'})
            body_lines = text[source['body_start']:source['body_end_offset']].splitlines()
            record['reference_state_witnesses'] = [dict(line=source['body_start_line']+i, text=line.strip()) for i, line in enumerate(body_lines)
                if re.search(r'\b(?:MidiInfo|SeInfo|MidiHandle|SeHandle|SdMemBlk|TransCompleteFlag|TransCallBackFunc|ExecFxFlag|SddFirstFlag|Sdc\w+)\b', line)]
            record['searched_evidence'] = [owned(a) for a in record['searched_candidates']]
            record['comparison'] = record['reference_contract']
            record['limitations'] = ('SDK-facing reusable facade is explicitly included, not excluded by filename or game provenance. '
                'Complete available source body reviewed; matching percentages in reference comments are source project claims, not independently rebuilt CVX parity. '
                'No demonstrated whole Outbreak counterpart in the listed owned candidates; no universal binary-absence, shared slot layout, enum, parameter-unit, clock or API-name inference.')
            entries.append(record)
        files.append(dict(path=original['path'], sha256=original['sha256'], functions=entries))
    assert consumed == set(manual)
    support = []
    for name in ('sdc.h', 'sdcwrap.h', 'types.h'):
        path = 'include/ps2/veronica/prog/'+name
        raw = (args.reference/path).read_bytes()
        support.append(dict(path=path, sha256=hashlib.sha256(raw).hexdigest()))
    result = dict(schema=1, reference_commit=PIN, outbreak_elf_sha256=SHA, files=files,
        support_headers=support, proposed_curated_groups=[], all_reference_definitions_dispositioned=True,
        counts=dict(files=2, functions=sum(len(f['functions']) for f in files),
                    statuses=dict(Counter(x['status'] for f in files for x in f['functions'])),
                    families=dict(Counter(x['family'] for f in files for x in f['functions'])),
                    owned_complete_intervals=len(audited), owned_verified_words=sum(e['verified_words'] for e in audited.values()),
                    owned_omitted_zero_words=sum(e['omitted_zero_words'] for e in audited.values())),
        new_semantic_mapping_credit=0, no_target_activity=True, no_shared_outputs_modified=True,
        notes='docs/recvx-crosscheck/SOUND_ADAPTER_COMPLETE_SCOPE.md')
    assert result['counts']['functions'] == 57
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2)+'\n', encoding='utf-8')
    print(json.dumps(result['counts'], indent=2))


if __name__ == '__main__':
    main()
