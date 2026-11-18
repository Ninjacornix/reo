#!/usr/bin/env python3
"""Author a bounded metadata-only RNA handoff from the frozen SDK130 cohort."""
import argparse
import difflib
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
SDK = ROOT / 'build-native-sjuni/dependency-sif-init-timing-reapply-v1'
PROOF = SDK.with_name(SDK.name + '-receipt.json')
PROOF_SHA = '473ad00c8fcae9966455fc8f47047f2dccd619d747077fc1ffaec2c2e3444df6'
PATCH = ROOT / 'third_party/patches/ps2recomp/0130-refresh-muted-rna-metadata.patch'
PREFIX = 'ps2xRuntime/src/lib/Kernel/Syscalls/'

DECLARATION = '''    // Explicit native-source adapter operation. Replays only muted voice
    // metadata in the actual RNA container order. Never consumes/queues PCM,
    // updates a progress clock or enables an original source. The subsequent
    // PCM order copy remains the authority for successfully registered routes.
    enum class RnaMetadataStatusV1 : uint32_t {
        ok, control_refused, unselected, invalid_metadata, playing_legacy, failed
    };
    struct RnaMetadataResultV1 {
        RnaMetadataStatusV1 status{RnaMetadataStatusV1::control_refused};
        uint32_t rows{}, requests{}, bad_handle{};
    };
    RnaMetadataResultV1 refreshMutedRnaMetadataV1(PS2Runtime*) noexcept;
'''

IMPLEMENTATION = '''    RnaMetadataResultV1 refreshMutedRnaMetadataV1(PS2Runtime* runtime) noexcept
    {
        RnaMetadataResultV1 result;
        try {
            if (!runtime) return result;
            auto audio=ps2_cri_audio::acquireSoundControlCall(runtime);
            if (!audio) return result;
            if (!audio.native() || !ps2_cri_audio::nativeSoundRamSelectedV1()) {
                result.status=RnaMetadataStatusV1::unselected;return result;
            }
            ps2_cri_audio::SoundCallScope scope(audio);
            std::lock_guard<std::mutex> lock(g_dtx_rpc_mutex);
            result.rows=static_cast<uint32_t>(g_dtx_ps2rna_by_handle.size());
            const auto& layout=g_dtxCompatLayout;
            if (result.rows>2041u || !layout.hasUrpcObjectRange()) {
                result.status=RnaMetadataStatusV1::invalid_metadata;return result;
            }
            // Validate the complete table before the first facade request.
            // In particular, never reuse the legacy playing/consumption path.
            for (const auto& entry:g_dtx_ps2rna_by_handle) {
                const auto& rna=entry.second;result.bad_handle=entry.first;
                if (entry.first!=rna.handle || rna.handle<layout.urpcObjBase ||
                    rna.handle>=layout.urpcObjLimit ||
                    (rna.handle-layout.urpcObjBase)%layout.urpcObjStride ||
                    !rna.channelCount || rna.channelCount>2u ||
                    rna.maxChannels<rna.channelCount || rna.maxChannels>2u) {
                    result.status=RnaMetadataStatusV1::invalid_metadata;return result;
                }
                if (rna.playEnabled) {
                    result.status=RnaMetadataStatusV1::playing_legacy;return result;
                }
            }
            result.bad_handle=0;
            for (const auto& entry:g_dtx_ps2rna_by_handle) {
                configurePcmVoice(entry.second);++result.requests;
            }
            result.status=RnaMetadataStatusV1::ok;
        } catch (...) { result.status=RnaMetadataStatusV1::failed; }
        return result;
    }

'''


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--author', type=Path, required=True)
    args = parser.parse_args()
    output = args.author.resolve()
    if output.exists() or not output.is_relative_to(ROOT / 'build-native-sjuni') or PATCH.exists():
        raise ValueError('Fresh author tree and unused patch name required')
    if sha(PROOF) != PROOF_SHA:
        raise ValueError('Frozen SDK130 receipt changed')
    proof = json.loads(PROOF.read_bytes())
    for name, digest in proof['source_sha256'].items():
        if sha(SDK / name) != digest:
            raise ValueError('Frozen source changed: ' + name)
    changes = {}
    for name, anchor, addition in [
        ('RPC.h', '    void noteDtxSifDmaTransfer(', DECLARATION),
        ('RPC.cpp', '    void noteDtxSifDmaTransfer(', IMPLEMENTATION),
    ]:
        relative = PREFIX + name
        before = (SDK / relative).read_text(encoding='utf-8')
        if before.count(anchor) != 1:
            raise ValueError('Unique source anchor required: ' + name)
        after = before.replace(anchor, addition + anchor)
        target = output / relative
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_text(after, encoding='utf-8', newline='\n')
        changes[relative] = dict(before_sha256=sha(SDK / relative), after_sha256=sha(target))
        changes[relative]['diff'] = 'diff --git a/' + relative + ' b/' + relative + '\n' + ''.join(
            difflib.unified_diff(before.splitlines(True), after.splitlines(True),
                                 fromfile='a/' + relative, tofile='b/' + relative))
    PATCH.write_text(''.join(row.pop('diff') for row in changes.values()), encoding='utf-8', newline='\n')
    (output / 'receipt.json').write_text(json.dumps(dict(
        status='authored; qualification pending', prior_receipt_sha256=PROOF_SHA,
        changes=changes, patch_sha256=sha(PATCH), author_sha256=sha(Path(__file__)),
        active_checkout_modified=False, game_run=False), indent=2) + '\n', encoding='utf-8', newline='\n')
    print('Authored metadata-only RNA refresh; no PCM consumption or original source playback')


if __name__ == '__main__':
    main()
