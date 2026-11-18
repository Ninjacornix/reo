"""Seal the explicit stock WMD absence profile and real sound composition."""
import hashlib
import json
from pathlib import Path
from audit_retail_effect_descriptors import compare_source, elf_reader

ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT / 'tools/native_reconstruction/native_stock_wmd_absence_qualification_v1.json'
    assert not target.exists()
    source, cohorts, parents = {}, {}, {}
    expected = None
    audit = None
    for cc in ['llvm', 'gcc']:
        path = ROOT / f'build-native-sjuni/stock-wmd-absence-{cc}-v2/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged']
        observed = receipt['observed']
        assert observed['checks'] == 273209210
        assert observed['weapon_refreshes'] == 6528 and observed['weapon_loaded_banks'] == 32
        assert observed['weapon_missing_banks'] == 2 and observed['weapon_missing_file_reads'] > 288
        assert observed['weapon_pcm_frames'] == 45568 and observed['weapon_signal_samples'] == 2904
        assert observed['depletion_cases'] == 786433 and observed['depletion_live'] == 4033
        assert observed['depletion_refusals'] == 4 and observed['depletion_audio_commands'] == 337
        assert observed['depletion_signal'] == 55706
        assert expected is None or expected == observed
        expected = observed
        current = receipt['stock_wmd_absence_audit']
        assert len(current['absent']) == 18 and len(current['item_selectors']) == 29
        assert len(current['named_members']) == 16 and len(current['item_rows']) == 332
        assert audit is None or audit == current
        audit = current
        assert sha(path.parent / 'owned_depletion_cue.bin') == receipt['depletion_cue_asset']['sha256']
        assert 'weapon35.snd' in [n.lower() for n in receipt['depletion_cue_asset']['names']]
        for name, digest in receipt['source_sha256'].items():
            assert sha(ROOT / name) == digest, name
            assert name not in source or source[name] == digest, name
            source[name] = digest
        cohorts[cc] = dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path), observed=observed)
        for kind in ['parent', 'tests']:
            path = ROOT / f'build-native-sjuni/stage4-stock-wmd-absence-{kind}-{cc}-v1.log'
            raw = path.read_bytes()
            value = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 8' in value) if kind == 'tests' else ('FAILED:' not in value and 'error:' not in value)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
    elf = ROOT / 'game_data/SLUS_207.65'
    assert sha(elf) == '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    read = elf_reader(elf.read_bytes())
    proofs = []
    for label, start, end in [('flag1 file dispatcher',0x1cc8f0,0x1cc950), ('argument adapter',0x1aa480,0x1aa4a0), ('lookup failure before destination write',0x1a9f20,0x1aa040), ('archive name lookup',0x1a9d70,0x1a9f20)]:
        relative = f'recomp/config/output/sub_{start:08X}_0x{start:x}.cpp'
        proofs.append(compare_source(label + '; static source/owned-word audit, not newly executed filesystem internals', relative, start, end, read))
    result = dict(schema=1, status='qualified stock WMD absence profile and continuing actual sound enqueue', game_launched=False, installed_in_game=False, stage4_complete=False, source_sha256=source, cohorts=cohorts, parent_checks=parents, asset_audit=audit, original_file_path_word_audits=proofs, limitations=[
        'File1 pinned ROM and five ITEM sections; unknown selectors still refuse after the original clear prefix.',
        'Complete original refresh/depletion callers execute; missing-file final read is an explicit no-write/zero-result port. Filesystem internals have static owned-word evidence only.',
        'Actual asynchronous loading and exact direct-install PCM comparisons cover32 existing SND banks; depletion uses the real weapon35 cue bank under controlled bank8 assignment.',
        'Ownership/transfer/UI callers, remaining gameplay, installation and coherent scenario acceptance remain open.'
    ])
    target.write_text(json.dumps(result, indent=2) + '\n')
    print(sha(target))


if __name__ == '__main__':
    main()
