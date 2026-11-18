"""Seal native model publication, part queries and actor lifetime checks."""
import hashlib
import json
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT / 'tools/native_reconstruction/gameplay_scenario'))
from qualify_v19 import read_cohort
from audit_retail_effect_descriptors import compare_source


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    queries,query_references = read_cohort('gameplay-model-parts-{compiler}-v2')
    assert queries[0]['source_sha256'] == queries[1]['source_sha256']
    assert queries[0]['result'] == queries[1]['result']
    result = queries[0]['result']
    assert result['model_part_queries'] == 4100 and result['model_part_refusals'] == 7
    records,references,logs = [],[],{}
    for compiler in ('llvm','gcc'):
        path = ROOT / 'build-native-sjuni' / f'actor-model-binding-{compiler}-v2/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged']
        assert all(sha(ROOT / name) == digest for name,digest in receipt['source_sha256'].items())
        assert all(sha(path.parent / name) == digest for name,digest in receipt['output_sha256'].items())
        records.append(receipt)
        references.append(dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path)))
        for kind in ('parent','tests'):
            log = ROOT / 'build-native-sjuni' / f'actor-model-binding-integration-{kind}-{compiler}-v1.log'
            raw = log.read_bytes()
            text = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            if kind == 'tests':
                assert '100% tests passed, 0 tests failed out of 5' in text
            else:
                assert 'FAILED:' not in text and 'error:' not in text
            logs[log.relative_to(ROOT).as_posix()] = sha(log)
    first,second = records
    assert first['source_sha256'] == second['source_sha256']
    assert first['models'] == second['models'] and first['observed'] == second['observed']
    assert first['observed'] == dict(checks=3483,refusals=13,owned_models=406,owned_skeletons=406,
                                   owned_absent_skeletons=0,owned_absent_models=3,model_bindings=4,
                                   binding_refusals=4,owned_missing=1)
    overlay = ROOT / 'build-function-index/owned-overlays/o0.bin'
    assert sha(overlay) == 'bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2'
    raw = overlay.read_bytes()
    shadow_audits = []
    for start,end in [(0x377560,0x3777a8),(0x3777b0,0x3777b8),(0x3777c0,0x3777f8),
                      (0x377800,0x377a64)]:
        name = f'recomp/config/output_ovl/o0/o0_{start:08X}_0x{start:x}.cpp'
        shadow_audits.append(compare_source('Actor shadow construction/render boundary',name,start,end,
                                           lambda at,size:raw[at-0x370000:at-0x370000+size]))
    documents = [ROOT / 'docs/native-gameplay/ACTOR_MODEL_BINDING.md',
                 ROOT / 'docs/native-gameplay/ACTOR_CONSTRUCTION_RENDER_BOUNDARY.md']
    previous = ROOT / 'tools/native_reconstruction/native_actor_model_assets_qualification_v1.json'
    record = dict(schema=1,status='qualified_partial_native_actor_model_binding',
        game_launched=False,installed_in_game=False,stage4_complete=False,
        source_sha256=first['source_sha256'],receipts=references,observed=first['observed'],models=first['models'],
        query_receipts=query_references,query_result=result,parent_logs_sha256=logs,
        original_shadow_boundary_audits=shadow_audits,
        documentation_and_tools_sha256={path.relative_to(ROOT).as_posix():sha(path) for path in documents+[Path(__file__)]},
        previous_qualification=dict(path=previous.relative_to(ROOT).as_posix(),sha256=sha(previous)),
        limitations=[
            'Prepared assets bind to actual canonical World actors through fresh model/animation instances.',
            'Source part queries use unsigned search and signed ordinal counts; malformed consumed extents refuse.',
            'One named model remains absent from owned common content, as recorded in the previous catalogue qualification.',
            'Shadow data belongs to the rendering boundary; native shadow rendering is Step 5 work.',
            'Actor construction, material task registration, motion/sound acquisition and real game installation remain open.',
            'Full native Step 4 acceptance remains open.',
        ])
    output = ROOT / 'tools/native_reconstruction/native_actor_model_binding_qualification_v1.json'
    with output.open('x',encoding='utf-8') as target:
        target.write(json.dumps(record,indent=2)+'\n')
    print(json.dumps(dict(path=str(output),sha256=sha(output),observed=record['observed'])))


if __name__ == '__main__':
    main()
