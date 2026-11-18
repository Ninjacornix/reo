"""Seal the canonical NPC startup command and Update worker comparisons."""
import json
from pathlib import Path

from qualify_v18 import QUALIFICATIONS, ROOT, sha
from qualify_v19 import read_cohort


def main():
    records,references=read_cohort('gameplay-scenario-npc-commands-{compiler}-v1')
    first,second=records
    assert first['source_sha256']==second['source_sha256'] and first['result']==second['result']
    result=first['result']
    assert result['npc_command_dispatches']==3584 and result['npc_command_refusals']==19
    parents={}
    binaries={}
    for compiler in ('llvm','gcc'):
        for kind in ('parent','tests'):
            log=ROOT/'build-native-sjuni'/f'npc-commands-{kind}-{compiler}-v2.log'
            raw=log.read_bytes()
            text=raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            if kind=='tests':
                assert '100% tests passed, 0 tests failed out of 7' in text
            else:
                assert 'FAILED:' not in text and 'error:' not in text
            parents[log.relative_to(ROOT).as_posix()]=sha(log)
        binary=ROOT/'build-native-sjuni'/f'gameplay-native-{compiler}-v1/gameplay_update/gameplay_cooperative_events_tests.exe'
        binaries[binary.relative_to(ROOT).as_posix()]=sha(binary)
    previous=QUALIFICATIONS/'gameplay_scenario_qualification_v23.json'
    ledger=json.loads(previous.read_bytes())
    new_opcodes=[0x80,0x81,0x88,0x89,0x8a,0x8b,0x8c]
    for profile,coverage in result['coverage'].items():
        prior=[entry[profile]['native_algorithm'] for entry in ledger['bindings']]
        assert {i for i,bit in enumerate(coverage['native_algorithm']) if bit!=prior[i]}==set(new_opcodes)
        for opcode in new_opcodes:
            ledger['bindings'][opcode][profile]['native_algorithm']=True
            ledger['bindings'][opcode]['selected_native_provider_composition_qualified']=True
        ledger['coverage'][profile]['native_algorithm']=coverage['count']
        ledger['coverage'][profile]['unsupported']=coverage['total']-coverage['count']
    ledger.pop('direct_archive_regression')
    document=ROOT/'docs/native-gameplay/SCENARIO_NPC_COMMANDS.md'
    parent_source=ROOT/'game/native/gameplay_update/cooperative_events_tests.cpp'
    ledger.update(
        schema='reo.native.gameplay.scenario.qualification.v24',
        status='qualified_partial_native_scenario_npc_commands',new_opcodes=new_opcodes,
        previous_qualification=dict(path=previous.relative_to(ROOT).as_posix(),sha256=sha(previous)),
        source_sha256=first['source_sha256'],original_sources_sha256=first['original_sources_sha256'],
        documentation_and_tools_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in (document,Path(__file__))},
        receipts=references,result=result,npc_members=first['npc_members'],
        parent_logs_sha256=parents,parent_binaries_sha256=binaries,
        parent_source_sha256={parent_source.relative_to(ROOT).as_posix():sha(parent_source)},
        limitations=['The eight alias values are canonical Session state in the comparison.',
                     'Opcode84 production of that state and enemy-record remapping remain open.',
                     'Live actor/model preparation and actual game caller installation remain open.',
                     'Coherent native gameplay acceptance remains open.'])
    output=QUALIFICATIONS/'gameplay_scenario_qualification_v24.json'
    with output.open('x',encoding='utf-8') as target:
        target.write(json.dumps(ledger,indent=2)+'\n')
    print(json.dumps(dict(path=str(output),sha256=sha(output),coverage=ledger['coverage'])))


if __name__=='__main__':
    main()
