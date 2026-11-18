"""Seal missing-character mapping and canonical source alias consumers."""
import json
from pathlib import Path

from qualify_v18 import QUALIFICATIONS, ROOT, sha
from qualify_v19 import read_cohort


def main():
    records,references=read_cohort('gameplay-scenario-character-remap-{compiler}-v1')
    first,second=records
    assert first['source_sha256']==second['source_sha256'] and first['result']==second['result']
    result=first['result']
    assert result['character_remap_dispatches']==4096 and result['character_remap_refusals']==7
    assert result['npc_command_dispatches']==3584 and result['npc_command_refusals']==19
    assert result['actor_placement_dispatches']==512 and result['cutscene_command_calls']==2048
    parents={}
    archives=[]
    for compiler in ('llvm','gcc'):
        path=ROOT/'build-native-sjuni'/f'gameplay-scenario-character-archive-{compiler}-v1/receipt.json'
        receipt=json.loads(path.read_bytes())
        assert receipt['status']=='passed' and receipt['result']['members']==186
        assert all(sha(ROOT/name)==digest for name,digest in receipt['source_sha256'].items())
        archives.append(dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),result=receipt['result']))
        for kind in ('parent','tests'):
            log=ROOT/'build-native-sjuni'/f'character-remap-{kind}-{compiler}-v1.log'
            raw=log.read_bytes()
            text=raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            if kind=='tests':
                assert '100% tests passed, 0 tests failed out of 7' in text
            else:
                assert 'FAILED:' not in text and 'error:' not in text
            parents[log.relative_to(ROOT).as_posix()]=sha(log)
    previous=QUALIFICATIONS/'gameplay_scenario_qualification_v24.json'
    ledger=json.loads(previous.read_bytes())
    for profile,coverage in result['coverage'].items():
        prior=[entry[profile]['native_algorithm'] for entry in ledger['bindings']]
        assert {i for i,bit in enumerate(coverage['native_algorithm']) if bit!=prior[i]}=={0x84}
        ledger['bindings'][0x84][profile]['native_algorithm']=True
        ledger['coverage'][profile]['native_algorithm']=coverage['count']
        ledger['coverage'][profile]['unsupported']=coverage['total']-coverage['count']
    ledger['bindings'][0x84]['selected_native_provider_composition_qualified']=True
    enemy=QUALIFICATIONS/'native_enemy_descriptors_qualification_v1.json'
    document=ROOT/'docs/native-gameplay/SCENARIO_CHARACTER_REMAP.md'
    parent_source=ROOT/'game/native/gameplay_update/cooperative_events_tests.cpp'
    ledger.update(
        schema='reo.native.gameplay.scenario.qualification.v25',
        status='qualified_partial_native_scenario_character_remap',new_opcodes=[0x84],
        previous_qualification=dict(path=previous.relative_to(ROOT).as_posix(),sha256=sha(previous)),
        intervening_qualifications={enemy.relative_to(ROOT).as_posix():sha(enemy)},
        source_sha256=first['source_sha256'],original_sources_sha256=first['original_sources_sha256'],
        documentation_and_tools_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in (document,Path(__file__))},
        receipts=references,result=result,parent_logs_sha256=parents,direct_archive_regression=archives,
        parent_source_sha256={parent_source.relative_to(ROOT).as_posix():sha(parent_source)},
        parent_binaries_sha256={
            (ROOT/'build-native-sjuni'/f'gameplay-native-{compiler}-v1/gameplay_update/gameplay_cooperative_events_tests.exe').relative_to(ROOT).as_posix():
            sha(ROOT/'build-native-sjuni'/f'gameplay-native-{compiler}-v1/gameplay_update/gameplay_cooperative_events_tests.exe')
            for compiler in ('llvm','gcc')},
        limitations=['NPC/room alias indices through209 have explicit native owners. Larger addressed aliases remain outside this profile.',
                     'The placement request is a full byte. Its ordinary producers write zero/one.',
                     'Live NPC/enemy actor/model construction and actual scene installation remain open.',
                     'Coherent native gameplay acceptance remains open.'])
    output=QUALIFICATIONS/'gameplay_scenario_qualification_v25.json'
    with output.open('x',encoding='utf-8') as target:
        target.write(json.dumps(ledger,indent=2)+'\n')
    print(json.dumps(dict(path=str(output),sha256=sha(output),coverage=ledger['coverage'])))


if __name__=='__main__':
    main()
