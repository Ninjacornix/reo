"""Seal the native enemy spawn/route owners and direct archive consumers."""
import json
from pathlib import Path

from qualify_v18 import QUALIFICATIONS, ROOT, sha
from qualify_v19 import read_cohort


def main():
    records,references=read_cohort('gameplay-scenario-enemy-descriptors-{compiler}-v1')
    first,second=records
    assert first['source_sha256']==second['source_sha256'] and first['result']==second['result']
    assert first['enemy_members']==second['enemy_members'] and len(first['enemy_members'])==10
    result=first['result']
    assert result['enemy_route_queries']==24800 and result['enemy_route_refusals']==7968
    assert result['enemy_imports']==1163 and result['enemy_owned_imports']==160
    assert result['enemy_import_refusals']==26
    ledger=QUALIFICATIONS/'gameplay_scenario_qualification_v24.json'
    bindings=json.loads(ledger.read_bytes())['bindings']
    for profile,coverage in result['coverage'].items():
        assert coverage['native_algorithm']==[entry[profile]['native_algorithm'] for entry in bindings]
    parents={}
    archives=[]
    for compiler in ('llvm','gcc'):
        path=ROOT/'build-native-sjuni'/f'gameplay-scenario-enemy-archive-{compiler}-v3/receipt.json'
        receipt=json.loads(path.read_bytes())
        assert receipt['status']=='passed' and receipt['result']['members']==186
        assert receipt['result']['enemy_banks']==10 and receipt['result']['enemy_boundary_cases']==3
        assert not receipt['game_launched'] and not receipt['installed_in_game']
        assert all(sha(ROOT/name)==digest for name,digest in receipt['source_sha256'].items())
        archives.append(dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),result=receipt['result']))
        for kind,version in (('parent',1),('tests',2)):
            log=ROOT/'build-native-sjuni'/f'enemy-descriptors-{kind}-{compiler}-v{version}.log'
            raw=log.read_bytes()
            text=raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            if kind=='tests':
                assert '100% tests passed, 0 tests failed out of 7' in text
            else:
                assert 'FAILED:' not in text and 'error:' not in text
            parents[log.relative_to(ROOT).as_posix()]=sha(log)
    document=ROOT/'docs/native-gameplay/ENEMY_DESCRIPTORS.md'
    notebook=ROOT/'docs/SYMBOLS_EMD_ACTOR_RECORD_INSTALLATION.md'
    qualification=dict(
        schema='reo.native.enemy.descriptors.qualification.v1',status='qualified_partial',
        installed_in_game=False,stage4_complete=False,
        source_sha256=first['source_sha256'],original_sources_sha256=first['original_sources_sha256'],
        documentation_and_tools_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in (document,notebook,Path(__file__))},
        opcode_qualification=dict(path=ledger.relative_to(ROOT).as_posix(),sha256=sha(ledger)),
        receipts=references,result=result,enemy_members=first['enemy_members'],
        direct_archive_regression=archives,parent_logs_sha256=parents,
        limitations=['The route metadata profile covers four initialized authored roots and bounded child extents.',
                     'Runtime-initialized route metadata remains unavailable when reached.',
                     'Native malformed/unavailable imports preserve prior state through a staged commit.',
                     'Actual class/room assignment producers and live actor/model construction remain open.',
                     'Game caller installation and coherent native gameplay acceptance remain open.'])
    output=QUALIFICATIONS/'native_enemy_descriptors_qualification_v1.json'
    with output.open('x',encoding='utf-8') as target:
        target.write(json.dumps(qualification,indent=2)+'\n')
    print(json.dumps(dict(path=str(output),sha256=sha(output),checks=result['checks'])))


if __name__=='__main__':
    main()
