"""Reconcile every reference definition with audited scope or explicit exclusion.

This is coverage accounting. An ownership-boundary, unmatched or unavailable
disposition is never upgraded to a semantic match by this script.
"""
from __future__ import annotations
from collections import Counter, defaultdict
import csv
import hashlib
import json
from pathlib import Path
import re

from index import ROOT
from recvx_scope_inventory import PIN

OUT=ROOT/'build-function-index'
SCOPES=(
 ('audio','recvx-audio-complete-scope.json','AUDIO_COMPLETE_SCOPE.md'),
 ('stream_fs','recvx-streamfs-complete-scope.json','STREAM_FS_COMPLETE_SCOPE.md'),
 ('ninja','recvx-ninja-complete-scope.json','NINJA_COMPLETE_SCOPE.md'),
 ('graphics','recvx-graphics-support-complete-scope.json','GRAPHICS_SUPPORT_COMPLETE_SCOPE.md'),
 ('platform','recvx-platform-complete-scope.json','PLATFORM_COMPLETE_SCOPE.md'),
 ('tim2','recvx-tim2-complete-scope.json','TIM2_COMPLETE_SCOPE.md'),
 ('movie','recvx-movie-platform-complete-scope.json','MOVIE_PLATFORM_COMPLETE_SCOPE.md'),
 ('card_disc','recvx-card-disc-platform-complete-scope.json','CARD_DISC_PLATFORM_COMPLETE_SCOPE.md'),
 ('mixed_geometry','recvx-mixed-geometry-complete-scope.json','MIXED_GEOMETRY_COMPLETE_SCOPE.md'),
 ('availability','recvx-reference-availability.json','REFERENCE_AVAILABILITY.md'),
 ('extra_utilities','recvx-extra-utilities-complete-scope.json','EXCLUSION_AUDIT.md'),
 ('actor_utilities','recvx-actor-utility-carveouts.json','ACTOR_UTILITY_ELIGIBILITY_AUDIT.md'),
 ('sound_adapters','recvx-sound-adapter-complete-scope.json','SOUND_ADAPTER_COMPLETE_SCOPE.md'),
)


def normalized_records(data):
    if isinstance(data.get('definitions'),list):
        for record in data['definitions']: yield record,record.get('file')
    else:
        for file in data['files']:
            for record in file.get('functions',[]): yield record,file.get('path',file.get('file'))


def owned_ids(record):
    # Only explicit owned image namespaces are used here. Bare source numbers
    # and source-code fields do not become new Outbreak identities.
    result=set()
    for image,address in re.findall(r'\b(main|o\d+):(?:0x)?([0-9a-fA-F]{6,8})\b',json.dumps(record)):
        result.add(f'{image}:0x{int(address,16):08X}')
    for address in record.get('outbreak_ids',[]):
        if re.fullmatch(r'(?:0x)?[0-9a-fA-F]{6,8}',str(address)):
            result.add(f'main:0x{int(str(address),16):08X}')
    return sorted(result)


def main():
    inventory=json.loads((OUT/'recvx-complete-source-inventory.json').read_text(encoding='utf-8'))
    assert inventory['reference_commit']==PIN
    expected={}
    for file in inventory['files']:
        for r in file['functions']:
            identity=(file['path'],r['symbol'],r['start_line'])
            assert identity not in expected
            expected[identity]=(file,r)
    assert len(expected)==inventory['counts']['definitions']==4599
    actual={}
    summaries=[]
    file_owners=defaultdict(set)
    for scope,name,note in SCOPES:
        path=OUT/name
        data=json.loads(path.read_text(encoding='utf-8'))
        assert data['reference_commit']==PIN,(scope,'revision mismatch')
        assert (ROOT/'docs/recvx-crosscheck'/note).exists(),(scope,'Missing completed scope report',note)
        for f in data.get('files',[]):
            source=f.get('path',f.get('file'))
            match=next((x for x in inventory['files'] if x['path']==source),None)
            if match is not None and f.get('sha256'):
                assert f['sha256']==match['sha256'],(scope,source,'file digest')
        statuses=Counter()
        count=0
        for record,path_hint in normalized_records(data):
            source=record.get('reference_file',record.get('file',path_hint))
            line=record.get('start_line',record.get('line_start'))
            identity=(source,record['symbol'],line)
            assert identity in expected,(scope,identity)
            assert identity not in actual,('overlapping scope',scope,identity)
            source_file,original=expected[identity]
            assert record['body_sha256']==original['body_sha256'],(scope,identity,'body digest')
            end=record.get('end_line',record.get('line_end'))
            assert end==original['end_line'],(scope,identity,'end bound')
            status=record.get('status',record.get('disposition'))
            assert status and not any(word in status.lower() for word in ('pending','todo','unreviewed')),(scope,identity,status)
            reason=record.get('comparison',record.get('reason',record.get('comparison_note','')))
            assert reason,(scope,identity,'missing disposition evidence')
            ids=owned_ids(record)
            item=dict(reference_file=source,symbol=record['symbol'],start_line=line,end_line=end,
                      reference_file_sha256=source_file['sha256'],body_sha256=original['body_sha256'],
                      scope=scope,status=status,comparison_depth=record.get('comparison_depth','see detailed scope ledger'),
                      disposition_evidence=reason,owned_evidence_ids=ids,
                      ledger='build-function-index/'+name,report='docs/recvx-crosscheck/'+note,
                      implemented_shape=original['implementation_shape'])
            actual[identity]=item
            statuses[status]+=1
            file_owners[source].add(scope)
            count+=1
        summaries.append(dict(scope=scope,definitions=count,statuses=dict(statuses),
                              ledger_sha256=hashlib.sha256(path.read_bytes()).hexdigest(),
                              ledger='build-function-index/'+name,report='docs/recvx-crosscheck/'+note))
    actor_data=json.loads((OUT/'recvx-actor-utility-carveouts.json').read_text(encoding='utf-8'))
    extra_data=json.loads((OUT/'recvx-extra-utilities-complete-scope.json').read_text(encoding='utf-8'))
    def key(r):
        return (r.get('reference_file',r.get('file')),r['symbol'],r.get('start_line',r.get('line_start')))
    actor_screen={key(r):r for r in actor_data['screened_definitions']}
    extra_screen={key(r):r for r in extra_data['eligibility_screen']}
    nonactor={key(r) for r in extra_data['initial_nonactor_identities']}
    core_scopes={scope for scope,_,_ in SCOPES[:10]}
    baseline_excluded=set(expected)-{identity for identity,row in actual.items() if row['scope'] in core_scopes}
    assert len(baseline_excluded)==2952
    assert len(actor_screen)==1850 and len(nonactor)==1102
    assert not actor_screen.keys() & nonactor
    assert actor_screen.keys() | nonactor == baseline_excluded
    sound={identity for identity,row in actual.items() if row['scope']=='sound_adapters'}
    assert len(sound)==57 and extra_screen.keys() | sound == nonactor
    assert not extra_screen.keys() & sound
    eligibility={**actor_screen,**extra_screen}
    records=[]
    excluded=Counter()
    for identity,(file,r) in expected.items():
        if identity in actual: records.append(actual[identity]);continue
        assert file['path'].startswith('src/ps2/veronica/prog/'),('unassigned library source',identity)
        assert identity in eligibility,('No function-level eligibility disposition',identity)
        screened=eligibility[identity]
        reason=screened.get('reason',screened.get('comparison'))
        assert reason,('Missing function-level exclusion reason',identity)
        excluded[file['path']]+=1
        records.append(dict(reference_file=file['path'],symbol=r['symbol'],start_line=r['start_line'],end_line=r['end_line'],
                            reference_file_sha256=file['sha256'],body_sha256=r['body_sha256'],
                            scope='cvx_game_specific_exclusion',status='outside_shared_comparison_scope',
                            comparison_depth='applicability exclusion; not a semantic match',
                            disposition_evidence=reason,owned_evidence_ids=[],
                            eligibility_basis=screened.get('disposition',screened.get('applicability')),
                            ledger='',report='',
                            implemented_shape=r['implementation_shape']))
    assert len(records)==4599
    # Every alternate assembly placeholder is retained by the availability audit.
    availability=json.loads((OUT/'recvx-reference-availability.json').read_text(encoding='utf-8'))
    expected_asm={(f['path'],r['symbol'],r['line']) for f in inventory['files'] for r in f['assembly_placeholders']}
    actual_asm={(r['file'],r['symbol'],r['line']) for r in availability['assembly_placeholders']}
    assert expected_asm==actual_asm and len(actual_asm)==223
    files=[]
    for f in inventory['files']:
        if f['source_kind']=='assembly':
            status='startup_assembly_compared_with_version_differences'
        elif f['assembly_placeholders']:
            status='alternate_assembly_bodies_unavailable'
        elif not f['functions']:
            status={'adx_qtbl.c':'shared_CRI_data_tables_verified',
                    'ps2_MovieWork.c':'CVX_movie_buffer_declarations_context',
                    'ps2_dvd_image.c':'CVX_disc_index_data_context',
                    'item.c':'CVX_game_inventory_data_excluded'}[Path(f['path']).name]
        elif file_owners[f['path']]:
            status='explicit_function_dispositions'+('_with_game_exclusions' if f['path'] in excluded else '')
        else: status='CVX_game_specific_source_excluded'
        files.append(dict(path=f['path'],sha256=f['sha256'],status=status,functions=len(f['functions']),
                          scoped_functions=sum((f['path'],r['symbol'],r['start_line']) in actual for r in f['functions']),
                          excluded_game_functions=excluded[f['path']],assembly_placeholders=len(f['assembly_placeholders']),
                          scopes=sorted(file_owners[f['path']])))
    result=dict(schema=1,reference_commit=PIN,
                counts=dict(source_files=len(files),reference_C_definitions=len(expected),
                            explicitly_scoped_definitions=len(actual),CVX_game_excluded_definitions=sum(excluded.values()),
                            unavailable_alternate_ASM_bodies=len(actual_asm),audited_scopes=len(summaries)),
                scope_summaries=summaries,files=files,definitions=records,
                eligibility_screening=dict(initial_residual_definitions=2952,actor_partition=1850,
                                           nonactor_partition=1102,nonactor_dedicated_sound_scope=57,
                                           nonactor_full_screen=1045,
                                           exact_identity_union_and_disjointness_verified=True),
                unavailable_alternate_assembly=availability['assembly_placeholders'],
                all_reference_source_identities_accounted=True,no_target_activity=True,
                limits='Coverage completion is disposition completeness, not all-function equivalence. Version differences, source-specific ownership, absent counterparts and missing implementations retain their original uncertainty. CVX gameplay exclusions are not semantic matches.')
    (OUT/'recvx-complete-comparison-coverage.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    columns=('reference_file','symbol','start_line','end_line','scope','status','comparison_depth',
             'owned_evidence_ids','report')
    with (ROOT/'docs/recvx-crosscheck/complete-function-coverage.csv').open('w',newline='',encoding='utf-8') as stream:
        writer=csv.DictWriter(stream,fieldnames=columns,lineterminator='\n');writer.writeheader()
        for row in records: writer.writerow({c:';'.join(row[c]) if isinstance(row[c],list) else row[c] for c in columns})
    with (ROOT/'docs/recvx-crosscheck/complete-file-coverage.csv').open('w',newline='',encoding='utf-8') as stream:
        columns=('path','sha256','status','functions','scoped_functions','excluded_game_functions','assembly_placeholders','scopes')
        writer=csv.DictWriter(stream,fieldnames=columns,lineterminator='\n');writer.writeheader()
        for row in files: writer.writerow({c:';'.join(row[c]) if isinstance(row[c],list) else row[c] for c in columns})
    print(json.dumps(result['counts']))


if __name__=='__main__': main()
