#!/usr/bin/env python3
"""Reproduce static identities/word coverage for the manually reviewed audio crosswalk.

This reads source and owned bytes only. It does not compile, decode, emulate,
load modules, or connect to a game. A successful audit is not behavior parity.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import sqlite3
import struct
import subprocess

from index import Elf

ROOT = Path(__file__).resolve().parents[2]
PIN = '657b0c0c9489943116c71f151804ad7304fca975'
SHA = '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
LIB = 'src/cri/mwlib/ee/lib/libadxe/'
INC = 'include/cri/mwlib/ee/lib/libadxe/'


def groups():
    result = []

    def group(ident, notebook, filename, rows):
        result.append(dict(id=ident, notebook=notebook, cvx_file=LIB+filename, rows=rows))

    def row(address, symbol, comparison, different=False):
        return [address, symbol, 'related-different' if different else 'supported-role', comparison]

    group('audio-padding-second-pass', 'SYMBOLS_ADXB_AINF_TEXT_AND_LEADING_PADDING_PURPOSES.md', 'adx_bsc.c', [
        row('124F08', 'ADXB_GetLpInsNsmpl', 'CVX returns lp_ins_nsmpl. Its DecodeInfoExLoop sign-extends the first BE16 at byte20, matching the Outbreak producer/getter chain. Outbreak also supports the version4 byte32 loop base; do not copy the older parser.'),
    ])
    group('audio-padding-outer-second-pass', 'SYMBOLS_ADXB_AINF_TEXT_AND_LEADING_PADDING_PURPOSES.md', 'adx_sjd.c', [
        row('12D850', 'ADXSJD_GetLpInsNsmpl', 'Both forward the inner ADXB getter without a readiness gate. Outbreak encoder/wire/parser evidence independently establishes leading-padding sample units; this is a comparative API alias, not a recovered symbol.'),
    ])
    group('audio-base-queries-second-pass', 'SYMBOLS_ADXB_DECODER_LIFETIME_HEADER_AND_PHASE.md', 'adx_bsc.c', [
        row('124E68', 'ADXB_GetFormat', 'Returns parsed format tag, distinct from processing phase. Outbreak adds AHX tag10 and optional format15; CVX does not define those implementations here.'),
        row('124E80', 'ADXB_GetFmtBps', 'Returns signed encoded bits byte, distinct from GetOutBps decision table and RNA PCM16 admission.'),
        row('124EE8', 'ADXB_GetBlkSmpl', 'Returns parsed samples per encoded block, not total produced PCM or a timing measurement.'),
        row('124EF0', 'ADXB_GetBlkLen', 'Returns signed block length byte; no new length validation is implied.'),
        row('124E40', 'ADXB_EntryGetWrFunc', 'Installs output-window callback and opaque context; callback ABI follows each caller and old-style CVX prototype is not proof of all argument types.'),
        row('1251A0', 'ADXB_GetStat', 'Both expose decode engine phase, separate from format/header readiness and outer stream state.'),
        row('1251A8', 'ADXB_EntryData', 'Both borrow encoded input, divide by format-dependent geometry and clear result counters. Preserve Outbreak BREAK behavior on zero divisors and its added formats.', True),
        row('125230', 'ADXB_Start', 'Only idle phase0 changes to requested1; does not decode or wait.'),
        row('125248', 'ADXB_Stop', 'Both call predictor Stop and clear own phase. Lower reset clears predictor histories; no worker join, SJ return or input-pointer clear.'),
        row('125278', 'ADXB_Reset', 'Only ready phase3 acknowledges/reset predictor and clears engine phase/current offset.'),
        row('1252B8', 'ADXB_GetDecDtLen', 'Returns latest consumed encoded bytes used by outer prefix split; not source position or aggregate callback count.'),
        row('1252C0', 'ADXB_GetDecNumSmpl', 'Returns latest produced sample count; outer cumulative accounting is separate.'),
        row('125698', 'ADXB_ExecOneAdx', 'Same request-callback -> predictor request -> service -> result/publication-callback -> ready phase sequence. Outbreak selected kernels are keyed integer extensions; no decoder bit-parity claim.'),
        row('125768', 'ADXB_ExecHndl', 'Both dispatch by format tag. Outbreak additionally routes AHX10 and optional15, so CVX dispatch list is incomplete for Outbreak.', True),
    ])
    group('audio-reported-depth-second-pass', 'SYMBOLS_ADXB_REPORTED_DEPTH_AND_HEADER_QUERIES.md', 'adx_bsc.c', [
        row('124E88', 'ADXB_GetOutBps', 'Exact table agrees: SPSD subtype2=>4,1=>8,other=>16; WAVE subtype2=>4,other=>16; all other tags16. This is API-reported depth, not universal decoded/device format.'),
        row('124F00', 'ADXB_GetCof', 'Returns signed header filter/coefficient-frequency parameter; does not return active predictor coefficient pair.'),
        row('124F10', 'ADXB_GetNumLoop', 'Returns parsed signed loop-count/presence half; parser continues only for exact1, with partial output possible.'),
    ])
    group('audio-loop-fields-second-pass', 'SYMBOLS_ADXT_LOOP_METADATA_AND_AINF_QUERIES.md', 'adx_bsc.c', [
        row('124F18', 'ADXB_GetLpStartPos', 'Parsed loop start sample position; actual Outbreak seek/limit consumers independently establish sample units.'),
        row('124F20', 'ADXB_GetLpStartOfst', 'Parsed encoded-byte offset; Outbreak adds NULL=>0, absent from CVX getter.', True),
        row('124F38', 'ADXB_GetLpEndPos', 'Parsed loop end sample position, separate from encoded byte offset.'),
        row('124F40', 'ADXB_GetLpEndOfst', 'Parsed loop end encoded-byte offset; no bounds or ordering validation in getter.'),
    ])
    group('audio-window-second-pass', 'SYMBOLS_ADXB_DECODE_WINDOW_AND_WRAP_ACCOUNTING.md', 'adx_bsc.c', [
        row('125370', 'ADXB_EvokeDecode', 'Same four signed bounds (input, output availability, remaining sample budget, wrap window) and mono/stereo selection. Retain guest32 arithmetic and division traps.'),
        row('125518', 'ADXB_EndDecode', 'Both convert completed blocks and copy wrap extension. Crucial difference: Outbreak subtracts partial-budget gap only when k>=ceil_budget_blocks*channels; CVX compares k against unmultiplied ceil_budget_blocks. Do not copy CVX stereo edge arithmetic.', True),
    ])
    group('audio-coefficients-second-pass', 'SYMBOLS_ADX_PREDICTOR_CONTEXT_AND_WORK_DISPATCH.md', 'adx_dcd.c', [
        row('126510', 'ADX_GetCoefficient', 'Same cosine/sqrt quadratic and coefficient scale4096. Outbreak EE uses explicit single-precision operations and conversion/fallback instructions; CVX double temporaries and C casts do not prove exceptional/rounding parity.'),
    ])
    group('audio-loop-parser-second-pass', 'SYMBOLS_ADX_HEADER_HISTORY_LOOP_AND_AINF.md', 'adx_dcd.c', [
        row('126AC8', 'ADX_DecodeInfoExLoop', 'Same signed leading-padding, loop count/type, sample positions and byte offsets. Both read the final loop byte offset at base+20 decimal. This corrects an old Outbreak note incorrectly claiming base+24: t5 ends at input+base+16, and126CCC loads+4. CVX fixes byte20 loop base/requires48 bytes; Outbreak has version4 byte32 base/requires60 bytes.', True),
    ])
    group('audio-predictor-second-pass', 'SYMBOLS_ADX_PREDICTOR_CONTEXT_AND_WORK_DISPATCH.md', 'adx_xpnd.c', [
        row('134D90', 'ADXPD_Init', 'Both clear fixed predictor pool. Outbreak has16 records, CVX8; do not copy capacity or stride.', True),
        row('134DE0', 'ADXPD_Create', 'Same free-record admission/default filter500 rate44100/history clear. Outbreak16 slots and keyed parameter fields differ.', True),
        row('134EB0', 'ADXPD_SetCoef', 'Both reorder (context,frequency,filter) into GetCoefficient(filter,frequency,&k0,&k1).'),
        row('134F58', 'ADXPD_Destroy', 'NULL-tolerant record clear; borrowed input/output buffers remain caller-owned.'),
        row('134F98', 'ADXPD_GetStat', 'Returns predictor phase with0/1/2/3 lifecycle; no work is run.'),
        row('134FA0', 'ADXPD_EntryMono', 'Only idle phase admits borrowed input/block count/output and mono mode; returns1 admitted,0 busy.'),
        row('134FD0', 'ADXPD_EntrySte', 'Only idle phase admits two borrowed outputs and stereo mode; count remains block units.'),
        row('135000', 'ADXPD_Start', 'Same idle->requested transition and completed-count clear, but Outbreak leaves v0=1 on both branches; CVX API is void. Do not infer accepted request from return.', True),
        row('135020', 'ADXPD_Stop', 'Clears phase and both channel histories; retains request pointers/counts and coefficients.'),
        row('135048', 'ADXPD_Reset', 'Only ready phase3 becomes idle; completed-count query remains available.'),
        row('135060', 'ADXPD_GetNumBlk', 'Returns completed encoded-block work count; upper channel/sample geometry conversion is separate.'),
        row('135068', 'adxpd_error', 'Same internal-error latch reached for positive odd stereo result; no diagnostic, stop or thrown failure here.'),
        row('135078', 'ADXPD_ExecHndl', 'Same phase dispatch/results publication, but Outbreak routes keyed integer mono/stereo/downmix kernels and passes key triple; CVX routes unkeyed float kernels. Shared wrapper does not imply matching arithmetic.', True),
        row('135170', 'ADXPD_ExecServer', 'Active fixed-pool scan; Outbreak16 objects versus CVX8, no elapsed-time bound.', True),
        row('1252D0', 'ADXB_EvokeExpandMono', 'Same byte-address conversion from PCM halfword offset, predictor request then Start. Outbreak ignores idle-admission return.'),
        row('125318', 'ADXB_EvokeExpandSte', 'Same doubled block count and two channel outputs separated by halfword distance; caller selects stereo only for channels==2.'),
        row('125458', 'memcpy2', 'Forward signed-count halfword loop for PCM copies; nonpositive count does nothing; not general overlapping memmove.'),
        row('125488', 'ADXB_CopyExtraBufSte', 'Same two forward halfword copies from wrap extension to each channel base; bounds remain caller-owned.'),
        row('1254F8', 'ADXB_CopyExtraBufMono', 'Same single wrap-extension copy; unused channel-distance argument is preserved.'),
    ])
    # Five request/copy adapters above are in adx_bsc.c; keep their source exact.
    predictor = result[-1]
    copy_rows = predictor['rows'][-5:]
    predictor['rows'] = predictor['rows'][:-5]
    group('audio-pcm-copy-adapters-second-pass', 'SYMBOLS_ADX_PREDICTOR_CONTEXT_AND_WORK_DISPATCH.md', 'adx_bsc.c', copy_rows)
    group('audio-unkeyed-second-pass', 'SYMBOLS_ADX_UNKEYED_FLOAT_STEREO_DECODERS.md', 'adx_dcd3.c', [
        row('126FE8', 'ADX_DecodeMonoFloat', 'Same18-byte blocks,32 high/low nibble samples, float predictor scaled by65536, normal count/history commit and early-marker no history commit. No float conversion or native parity claim.'),
        row('127158', 'ADX_DecodeSteFloatAsSte', 'Same complete-pair loop, two independent float histories and early-marker return2*pairs; normal return retains original odd requested count.'),
        row('1273F0', 'ADX_DecodeSteFloatAsMono', 'Same float stereo sum*approximately0.7 duplicated into both outputs; individual channel histories stay unmixed. Does not establish keyed integer-downmix equivalence.'),
        row('127690', 'ADX_DecodeSteFloat', 'Same global zero/nonzero selector between stereo and duplicated downmix, with coefficient halfword extension.'),
    ])
    group('audio-downmix-switch-second-pass', 'SYMBOLS_ADX_KEYED_CPU_BLOCK_DECODERS.md', 'adx_dcd3.c', [
        row('126FD8', 'ADX_SetDecodeSteAsMonoSw', 'Global switch affects both reviewed Outbreak selectors. CVX owns unkeyed float counterpart only; no reason to rename keyed kernels to float APIs.'),
    ])
    controls = [
        ('13EB88','PS2RNA_Start','CVX prints then spins forever; Outbreak only reports and returns. Unsupported API name agrees, failure-control contract differs.',True),
        ('13EBA8','PS2RNA_Stop','Both call SetTransSw(0), then SetPlaySw(0); those child implementations differ by version.',True),
        ('13EBD8','PS2RNA_SetTransSw','CVX starts DTR on activation and resets flush count; Outbreak stores request then stops current-channel DTR on non1. Preserve separate Outbreak restart/service path.',True),
        ('13EC50','PS2RNA_SetPlaySw','CVX also resets local and remote queues on0; Outbreak only writes desired byte24. Do not add synchronous queue reset.',True),
        ('13EC60','PS2RNA_ClearBuf','CVX report then permanent loop; Outbreak report then return without clearing.',True),
        ('13EC80','PS2RNA_SetPcmType','CVX report then permanent loop; Outbreak report then return without converting.',True),
        ('13ECA0','PS2RNA_GetTime','Both write numerator0, denominator48000; no hardware sample-clock read.' ,False),
        ('13ECB0','PS2RNA_GetNumData','Both derive occupied halfword units from first local channel/free pool and capacity16384. CVX uses unsigned /2; Outbreak signed truncation toward0 matters for malformed counts.',True),
        ('13ECF0','PS2RNA_GetNumRoom','Both derive free halfword units from first local queue. CVX unsigned division differs from Outbreak signed truncation on negative values.',True),
        ('13EF58','PS2RNA_SetStartSmpl','CVX report then spin; Outbreak report then return, neither implements seek.',True),
        ('13EF78','PS2RNA_SetNumChan','Both store low byte of desired channel count with no array resize or bounds validation.',False),
        ('13EF80','PS2RNA_SetSfreq','CVX simply stores; Outbreak imposes48000-divisibility/even-quotient arithmetic and can BREAK or report/spin. Do not remove admission checks.',True),
        ('13F038','PS2RNA_SetOutVol','Both clamp signed attenuation to[-999,0] and store desired volume; native perceptual/decibel scale not established.',False),
        ('13F058','PS2RNA_SetOutPan','Both clamp channel pan to[-15,15], unchecked channel index; no inferred perceptual pan law.',False),
        ('13F080','PS2RNA_SetBitPerSmpl','Both admit16 unchanged; CVX spins on unsupported value whereas Outbreak reports then returns.',True),
        ('13F0B8','PS2RNA_GetStartSmpl','CVX report then spin; Outbreak report then returns0, which is stub value rather than measured position.',True),
        ('13F0E0','PS2RNA_GetSfreq','Returns configured desired sample rate, not measured hardware rate.',False),
        ('13F0E8','PS2RNA_GetOutVol','Returns stored desired attenuation before serializer lookup.',False),
        ('13F0F0','PS2RNA_GetOutPan','Returns configured channel pan with no channel bound.',False),
        ('13F100','PS2RNA_GetBitPerSmpl','Returns fixed16 matching only supported setter value; not a parsed input bit depth.',False),
        ('13F108','PS2RNA_IsOverflow','CVX report then spin; Outbreak report then0, not proof of overflow absence.',True),
        ('13F130','PS2RNA_ClearOverflow','CVX report then spin; Outbreak report then return with no overflow-state clear.',True),
        ('13F158','PS2RNA_DiscardData','CVX report then spin; Outbreak report then0 without consuming samples.',True),
        ('13F180','PS2RNA_SetTotalNumSmpl','CVX report then spin; Outbreak report then return without setting count.',True),
        ('13F1A0','PS2RNA_SetStmHdInfo','CVX report then spin; Outbreak report then0 without parsing/installing header.',True),
    ]
    group('audio-rna-controls-second-pass', 'SYMBOLS_PS2RNA_AUDIO_CONTROLS_AND_UNSUPPORTED_API.md', 'ps2_rna.c', [row(*r) for r in controls])
    group('audio-rna-commands-second-pass', 'SYMBOLS_PS2RNA_COMMAND_DELTA_TRANSPORT.md', 'ps2_rna.c', [
        row('13E000', 'ps2rna_sndcbf', 'Common16-byte command records and immediate last-sent updates, but CVX scans8 objects/emits2,3,4,5; Outbreak scans16/emits8,2,A,3,4,5,9 with stop before parameter changes and play after. Outbreak capacity and subtype behavior stay authoritative.', True),
        row('13DFA0', 'ps2rna_rcvcbf', 'Both NULL-spin and read count once for an otherwise empty signed-count loop; not command-result parsing or asynchronous completion polling.'),
    ])
    group('audio-sofdec-children-second-pass', 'SYMBOLS_CRI.md', 'adx_tlk.c', [
        row('131EF8','ADXT_GetStat','CVX returns status; Outbreak additionally checks NULL, diagnoses and returns-1. Sofdec raw3 test remains separate from a recovered enum.',True),
        row('1324A8','ADXT_GetNumSmpl','Both return declared total samples after header-ready threshold, not decoded-so-far count. Outbreak signed byte>=2 guard and NULL=>-1 are explicit.',True),
        row('1324F8','ADXT_GetSfreq','Both return header sample frequency after readiness; Outbreak additionally diagnoses NULL=>-1.',True),
        row('132548','ADXT_GetNumChan','Both forward parsed channel count after readiness; Outbreak adds NULL=>-1 and signed-byte guard.',True),
        row('1328B8','ADXT_SetSvrFreq','Same configured per-object service frequency store; Outbreak adds NULL diagnostic and no actual scheduler measurement.',True),
        row('132CF0','ADXT_GetErrCode','Both return stored error; Outbreak adds NULL=>-1 diagnostic. Neither query clears error.',True),
    ])
    return result


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--reference', type=Path, default=Path.home()/'AppData/Local/Temp/reo-recvx-crosscheck-20261104')
    ap.add_argument('--output', type=Path, default=ROOT/'build-function-index/recvx-audio-second-pass.json')
    args = ap.parse_args()
    ref = args.reference.resolve()
    head = subprocess.check_output(['git', '-C', str(ref), 'rev-parse', 'HEAD'], text=True).strip()
    assert head == PIN, head
    elf = Elf(ROOT/'game_data/SLUS_207.65')
    assert elf.sha256 == SHA
    reviewed = groups()
    reference_files = sorted({g['cvx_file'] for g in reviewed} | {
        INC+'ps2_rna.h', INC+'override_adxt.h', LIB+'adx_sjd.c',
        'src/ps2/veronica/prog/ps2_sfd_mw.c',
    })
    reference = []
    for name in reference_files:
        data = (ref/name).read_bytes()
        reference.append(dict(path=name, bytes=len(data), sha256=hashlib.sha256(data).hexdigest()))
    for g in reviewed:
        text = (ref/g['cvx_file']).read_text(encoding='utf-8')
        for _, symbol, _, _ in g['rows']:
            assert re.search(r'\b'+re.escape(symbol)+r'\s*\(', text), (g['cvx_file'], symbol)
    # Support bodies include complete optional routes, AINF and padding producers,
    # all audio service/metadata bodies, and the specific drain-mode setter.
    support = {0x13EC58,0x122E40,0x122E90,0x122FF0,0x1230B0,0x12CC50,0x132FF8,
               0x124F68,0x12D9B8,0x132890,0x12CBC0,0x134BC0,0x1249E8,0x126D28,
               0x12FC28,0x12F090,0x12F9C0,0x12FBA8,0x132548,0x135020,0x1345F0,0x131D98}
    support |= {int(a,16) for g in reviewed for a,_,_,_ in g['rows']}
    sofdec = ROOT/'docs/SYMBOLS_SOFDEC_AUDIO_SERVICE_AND_METADATA.md'
    support |= {int(a,16) for a in re.findall(r'^\| \[0x([0-9A-Fa-f]+)\]',sofdec.read_text(encoding='utf-8'),re.M)}
    db = sqlite3.connect(f'file:{ROOT/"build-function-index/index.sqlite"}?mode=ro',uri=True)
    bodies = []
    for entry in sorted(support):
        end,source = db.execute("select end,source from functions where image='main' and start=?",(entry,)).fetchone()
        raw = elf.read(entry,end-entry)
        words = {int(a,16):int(w,16) for a,w in re.findall(r'// 0x([0-9a-f]+): 0x([0-9a-f]+)\s+',
                 (ROOT/source).read_text(encoding='utf-8'),re.I) if entry<=int(a,16)<end}
        for pc,w in words.items():
            assert elf.read(pc,4) == struct.pack('<I',w),(hex(entry),hex(pc))
        omitted = [pc for pc in range(entry,end,4) if pc not in words]
        assert all(elf.read(pc,4)==b'\0'*4 for pc in omitted),hex(entry)
        bodies.append(dict(entry=f'{entry:06X}', endExclusive=f'{end:06X}', source=source,
            sha256=hashlib.sha256(raw).hexdigest(), verifiedCommentWords=len(words), omittedZeroWords=len(omitted)))
    iop = (ROOT/'build-function-index/owned-iop/cri_adx_driver.irx').read_bytes()
    assert hashlib.sha256(iop).hexdigest() == '456f07cb55a5bed66643fd95ca6ef64874265b578630b905a9328346e01aefb7'
    # ELF section2's file offset is obtained from section table, not a guessed VA mapping.
    shoff = struct.unpack_from('<I',iop,32)[0]
    shentsize = struct.unpack_from('<H',iop,46)[0]
    text_section = struct.unpack_from('<10I',iop,shoff+2*shentsize)
    iop_bodies=[]
    for name,start,n in [('ioprna_rcvcbf',0xD40,504),('IOPRNA_ExecHndl',0xF80,244)]:
        raw=iop[text_section[4]+start-text_section[3]:text_section[4]+start-text_section[3]+n]
        assert len(raw)==n
        iop_bodies.append(dict(symbol=name,start=f'{start:X}',bytes=n,sha256=hashlib.sha256(raw).hexdigest()))
    # Static register-address derivation, not guest execution/emulation. Inspect
    # only the known ADDIU field increments and the final ADDU/LW encodings.
    loop_pointer_trace = []
    relative = 0
    for pc,expected in ((0x126BB0,2),(0x126BB8,2),(0x126C08,2),
                        (0x126C14,2),(0x126C1C,4),(0x126C28,4)):
        w = struct.unpack('<I',elf.read(pc,4))[0]
        assert w>>26 == 9 and (w>>21)&31 == 13 and (w>>16)&31 == 13
        assert w&0xFFFF == expected
        relative += expected
        loop_pointer_trace.append(dict(pc=f'{pc:06X}',word=f'{w:08X}',
            constantIncrement=expected,relativeToLoopBase=f'{relative:X}'))
    w = struct.unpack('<I',elf.read(0x126C5C,4))[0]
    assert w>>26 == 0 and w&63 == 0x21 and (w>>11)&31 == 13
    assert {(w>>21)&31,(w>>16)&31} == {13,16}
    loop_pointer_trace.append(dict(pc='126C5C',word=f'{w:08X}',
        operation='ADDU t5,t5,s0 adds input pointer, not a field increment'))
    w = struct.unpack('<I',elf.read(0x126CCC,4))[0]
    assert w>>26 == 0x23 and (w>>21)&31 == 13 and w&0xFFFF == 4
    assert relative+4 == 0x14
    loop_pointer_trace.append(dict(pc='126CCC',word=f'{w:08X}',
        finalFieldRelativeToLoopBase=f'{relative+4:X}'))
    args.output.parent.mkdir(parents=True,exist_ok=True)
    report=dict(reference_commit=PIN,outbreak_elf_sha256=SHA,groups=reviewed,
        reference_files=reference, complete_owned_bodies=bodies,owned_iop_bodies=iop_bodies,
        loopFinalOffsetStaticDerivation=loop_pointer_trace,
        no_target_execution=True,comparison_note='docs/recvx-crosscheck/AUDIO_SECOND_PASS.md',
        limits='Manual contract comparison; word coverage proves source identity only. No audio/vector/output equivalence, API-name recovery, runtime hotness or performance claim.')
    args.output.write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
    print(f'{sum(len(g["rows"])for g in reviewed)} comparisons; {len(bodies)} complete owned intervals; '
          f'{sum(b["verifiedCommentWords"]for b in bodies)} source words; {len(reference)} pinned reference files. {args.output}')


if __name__ == '__main__':
    main()
