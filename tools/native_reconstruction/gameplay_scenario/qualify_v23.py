"""Seal NPC decoding, canonical descriptor primitives and inventory commands."""
import json
from pathlib import Path

from qualify_v18 import QUALIFICATIONS, ROOT, sha
from qualify_v19 import read_cohort


def main():
    records, references=read_cohort('gameplay-scenario-npcs-{compiler}-v1')
    first,second=records
    assert first['source_sha256']==second['source_sha256'] and first['result']==second['result']
    result=first['result']
    assert result['npc_imports']==517 and result['npc_import_refusals']==7
    assert result['npc_primitive_calls']==16384 and result['npc_inventory_dispatches']==2048
    assert first['npc_members']==second['npc_members'] and len(first['npc_members'])==5
    parents={}
    archives=[]
    for compiler in ('llvm','gcc'):
        path=ROOT/'build-native-sjuni'/f'gameplay-scenario-npc-archive-{compiler}-v1/receipt.json'
        receipt=json.loads(path.read_bytes())
        assert receipt['status']=='passed' and receipt['result']['members']==176
        assert receipt['result']['npc_banks']==5 and not receipt['game_launched']
        assert all(sha(ROOT/name)==digest for name,digest in receipt['source_sha256'].items())
        archives.append(dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),result=receipt['result']))
        for kind in ('parent','tests'):
            log=ROOT/'build-native-sjuni'/f'npcs-{kind}-{compiler}-v2.log'
            raw=log.read_bytes()
            text=raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            if kind=='tests':
                assert '100% tests passed, 0 tests failed out of 7' in text
            else:
                assert 'FAILED:' not in text and 'error:' not in text
            parents[log.relative_to(ROOT).as_posix()]=sha(log)
    previous=QUALIFICATIONS/'gameplay_scenario_qualification_v22.json'
    ledger=json.loads(previous.read_bytes())
    for profile,coverage in result['coverage'].items():
        prior=[entry[profile]['native_algorithm'] for entry in ledger['bindings']]
        assert {i for i,bit in enumerate(coverage['native_algorithm']) if bit!=prior[i]}=={0x3a,0x3d}
        for opcode in (0x3a,0x3d):
            ledger['bindings'][opcode][profile]['native_algorithm']=True
            ledger['bindings'][opcode]['selected_native_provider_composition_qualified']=True
        ledger['coverage'][profile]['native_algorithm']=coverage['count']
        ledger['coverage'][profile]['unsupported']=coverage['total']-coverage['count']
    for key in ('forced_transition','general_publication_regression','parent_binaries_sha256'):
        ledger.pop(key)
    document=ROOT/'docs/native-gameplay/SCENARIO_NPC_DESCRIPTORS.md'
    ledger.update(
        schema='reo.native.gameplay.scenario.qualification.v23',
        status='qualified_partial_native_scenario_npc_descriptors',new_opcodes=[0x3a,0x3d],
        previous_qualification=dict(path=previous.relative_to(ROOT).as_posix(),sha256=sha(previous)),
        source_sha256=first['source_sha256'],original_sources_sha256=first['original_sources_sha256'],
        documentation_and_tools_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in (document,Path(__file__))},
        receipts=references,result=result,npc_members=first['npc_members'],
        parent_logs_sha256=parents,direct_archive_regression=archives,
        limitations=['Original file acquisition and formatting are controlled comparison ports.',
                     'Native import preserves immutable source bytes while decoding coerced mode values.',
                     'Live actor creation and model/AI preparation remain open.',
                     'Actual game caller installation and coherent native gameplay acceptance remain open.'])
    output=QUALIFICATIONS/'gameplay_scenario_qualification_v23.json'
    with output.open('x',encoding='utf-8') as target:
        target.write(json.dumps(ledger,indent=2)+'\n')
    print(json.dumps(dict(path=str(output),sha256=sha(output),coverage=ledger['coverage'])))


if __name__=='__main__':
    main()
