"""Seal native actor asset ownership and both owned model definition banks."""
import hashlib
import json
from pathlib import Path
import struct
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT / 'tools/native_reconstruction/gameplay_scenario'))
from qualify_v19 import read_cohort
from audit_retail_effect_descriptors import compare_source,elf_reader


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    metadata,metadata_references = read_cohort('gameplay-actor-model-profiles-{compiler}-v1')
    assert metadata[0]['source_sha256'] == metadata[1]['source_sha256']
    assert metadata[0]['result'] == metadata[1]['result']
    assert metadata[0]['result']['linked_definition_cases'] == 32768
    records,references,logs = [],[],{}
    for compiler in ('llvm','gcc'):
        path = ROOT / 'build-native-sjuni' / f'actor-assets-{compiler}-v1/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged']
        assert all(sha(ROOT / name) == digest for name,digest in receipt['source_sha256'].items())
        assert all(sha(path.parent / name) == digest for name,digest in receipt['output_sha256'].items())
        assert not receipt['game_launched'] and not receipt['installed_in_game']
        records.append(receipt)
        references.append(dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path)))
        for kind in ('parent','tests'):
            log = ROOT / 'build-native-sjuni' / f'actor-assets-integration-{kind}-{compiler}-v1.log'
            raw = log.read_bytes()
            text = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            if kind == 'tests':
                assert '100% tests passed, 0 tests failed out of 5' in text
            else:
                assert 'FAILED:' not in text and 'error:' not in text
            logs[log.relative_to(ROOT).as_posix()] = sha(log)
    first,second = records
    assert first['source_sha256'] == second['source_sha256']
    assert first['observed'] == second['observed'] and first['models'] == second['models']
    assert first['observed'] == dict(checks=3010,refusals=13,owned_models=406,owned_skeletons=406,
                                   owned_absent_skeletons=0,owned_absent_models=3,owned_missing=1)
    present = [model for model in first['models'] if model['status'] == 'present']
    assert len({model['name'] for model in present}) == 180
    missing = [model for model in first['models'] if model['status'] == 'missing']
    assert missing == [dict(bank=0,type=3,variant=1,name='E03_01.NBD',status='missing')]
    image = ROOT / 'game_data/SLUS_207.65'
    assert sha(image) == '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    read = elf_reader(image.read_bytes())
    assert struct.unpack('<II',read(0x1d1f40,8)) == (0x03e00008,0)
    leaf = compare_source('Complete no-op texture preload',
        'recomp/config/output/sub_001D1F40_0x1d1f40.cpp',0x1d1f40,0x1d1f48,read)
    document = ROOT / 'docs/native-gameplay/ACTOR_MODEL_ASSETS.md'
    notebook = ROOT / 'docs/SYMBOLS_SCENARIO_ACTOR_NODE_POOL_AND_FACTORY.md'
    record = dict(schema=1,status='qualified_partial_native_actor_model_assets',
        game_launched=False,installed_in_game=False,stage4_complete=False,
        source_sha256=first['source_sha256'],receipts=references,observed=first['observed'],
        models=first['models'],metadata_receipts=metadata_references,metadata_result=metadata[0]['result'],
        original_texture_preload_leaf=leaf,parent_logs_sha256=logs,
        documentation_and_tools_sha256={path.relative_to(ROOT).as_posix():sha(path)
                                        for path in (document,notebook,Path(__file__))},
        limitations=[
            'The native owner covers ordinary/alternate enemy and cutscene model catalogues in File #1 common content.',
            'E03_01.NBD is absent from the owned common archive and reports a missing asset when selected.',
            'The alternative definition group for class22 overlaps a following initialized row; both rows are admitted.',
            'AHI skeleton data is imported into native objects; mesh/texture bundle bytes remain retained for their rendering consumer.',
            'Constructor orchestration, motion/sound acquisition, enemy behavior and game caller installation remain open.',
            'Full native Step 4 acceptance remains open.',
        ])
    output = ROOT / 'tools/native_reconstruction/native_actor_model_assets_qualification_v1.json'
    with output.open('x',encoding='utf-8') as target:
        target.write(json.dumps(record,indent=2)+'\n')
    print(json.dumps(dict(path=str(output),sha256=sha(output),observed=record['observed'])))


if __name__ == '__main__':
    main()
