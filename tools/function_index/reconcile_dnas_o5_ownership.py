#!/usr/bin/env python3
"""Verify reviewed o5 envelopes and classify residual cuts without role credit."""
import hashlib
import json
from pathlib import Path
import sqlite3

ROOT=Path(__file__).resolve().parents[2]
BASE=0x6E0000
SHA='97174f5d367cd90bedd5ba397c6492e9fb4bbd0ec7d6021c2be524c49925d38e'
SOURCES=(
    ('dnas-o5-allocator-review/receipt.json','owners','end_exclusive','original_sha256'),
    ('dnas-o5-services-review/receipt.json','owners','endExclusive','originalOwnerSha256'),
    ('proxy-dnas-o5-large-owner-review.json','cases','logical_end_exclusive','original_joined_sha256'),
)


def main():
    output=ROOT/'build-function-index'
    original=(output/'owned-overlays/o5.bin').read_bytes()
    assert hashlib.sha256(original).hexdigest()==SHA
    annotations=json.loads((ROOT/'tools/function_index/annotations.json').read_text(encoding='utf-8'))['annotations']
    reviewed={a['id']:a for a in annotations}
    owners=[]

    def admit(start,end,digest,receipt):
        identity=f'o5:0x{start:08X}'
        assert identity in reviewed
        assert hashlib.sha256(original[start-BASE:end-BASE]).hexdigest()==digest
        owners.append(dict(id=identity,start=start,end=end,original_sha256=digest,receipt=receipt,
                           name=reviewed[identity]['proposed_name'],evidence=reviewed[identity]['evidence']))

    for name,key,end_key,hash_key in SOURCES:
        data=json.loads((output/name).read_text(encoding='utf-8'))
        for row in data[key]:
            admit(int(row['owner'].split(':')[-1],0),int(row[end_key],0),row[hash_key],name)
    admit(0x702EF0,0x703028,'4d1db7da74eba612e26a675a126e0a28253fc8a9a271686e249ce5bebd417c48',
          'separately reviewed whole-owner byte-comparison proof')
    owners.sort(key=lambda r:r['start'])
    assert len(owners)==len({r['id'] for r in owners})==32
    assert all(a['end']<=b['start'] for a,b in zip(owners,owners[1:]))
    inventory=json.loads((output/'dnas-o5-family-recovery-inventory.json').read_text(encoding='utf-8'))
    assert inventory['image_sha256']==SHA
    spans=[]
    for row in inventory['spans']:
        start,end=int(row['start'],0),int(row['end_exclusive'],0)
        matches=[owner for owner in owners if owner['start']<=start<end<=owner['end']]
        assert len(matches)==1,(row['start'],row['end_exclusive'])
        spans.append(dict(start=hex(start),end_exclusive=hex(end),owner=matches[0]['id']))
    assert len(spans)==73
    with sqlite3.connect((output/'index.sqlite').resolve().as_uri()+'?mode=ro',uri=True) as db:
        db.row_factory=sqlite3.Row
        rows=[dict(r) for r in db.execute("SELECT * FROM functions WHERE image='o5' ORDER BY start")]
    assert {r['id'] for r in rows if r['proposed_name']}=={a['id'] for a in annotations if a['image']=='o5'}
    residuals=[]
    for row in rows:
        if row['id'] in reviewed:
            continue
        start,end=row['start'],row['end']
        matches=[owner for owner in owners if owner['start']<start and end<=owner['end']]
        if matches:
            assert len(matches)==1
            parent=matches[0]['id'];category='partition inside reviewed logical owner'
        else:
            assert BASE<=start<end<=BASE+0x20,('unreconciled o5 identity',row['id'])
            parent=None;category='MWo3 header partition'
        residuals.append(dict(id=row['id'],start=hex(start),end_exclusive=hex(end),category=category,
                              reviewed_parent=parent,independent_function_entry_established=False))
    counts={name:sum(r['category']==name for r in residuals) for name in sorted({r['category'] for r in residuals})}
    result=dict(schema=1,image='o5',image_sha256=SHA,reviewed_logical_owners=owners,protected_spans=spans,
                residuals=residuals,counts=counts,no_new_mapping_credit=True,
                limitations='Partition coverage, not independent entry contracts or native translation. Shared-body '
                'secondary entries retain their separate existing annotations. Callback algorithms, runtime '
                'admission and provider correctness remain qualified by the authoritative notebooks.')
    (output/'dnas-o5-owner-reconciliation.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    lines=['# DNAS logical-owner and residual-partition reconciliation','',
           '**32 disjoint reviewed logical body intervals cover all73 protected spans.** '
           'All original joined-interval hashes were rechecked against owned o5/runtime7/base6E0000, '
           'SHA-256 `'+SHA+'`. No guest code, game, network, runtime, process attachment or build was used.','',
           '**Zero additional role annotations or denominator changes are made.**','',
           '| Remaining unannotated class | Entries |','| --- | ---: |']
    lines += [f'| {name} | {count} |' for name,count in counts.items()]
    lines += ['', 'The remaining19 generated continuation fragments and142 one-byte cuts are contained '
              'inside these reviewed bodies; the other9 identities partition the MWo3 header. They do not '
              'establish161 independent functions. Existing shared-body secondary entry contracts remain '
              'separate where already annotated. All normal entries retain their documented uncertainty '
              'about provider algorithms, bounds, aliases, callback contracts and runtime behavior.','',
              'The18 first-family paired restore descriptors are skipped on the reviewed paths. '
              'The other55 spans have individually reviewed restore-call bindings, including shared and '
              'reordered noncanonical setups; early exits can still bypass some restoration. '
              'An arithmetic paired restore is therefore kept separate from a universal runtime claim.','',
              'Rebuild the individual portable review receipts, refresh annotations, then run '
              '`python tools/function_index/reconcile_dnas_o5_ownership.py`. All owner fingerprints and '
              'residual-parent relationships are retained in `build-function-index/dnas-o5-owner-reconciliation.json`. '
              '[All-family recovery](STATIC_DNAS_O5_RECOVERY_INVENTORY.md), '
              '[independent original-transform review](STATIC_DNAS_O5_TRANSFORM_FAMILY_SUPPORT_REVIEW.md), '
              '[central index](FUNCTION_INDEX.md).','',
              '| Logical entrance | End exclusive | Authoritative role evidence |','| --- | --- | --- |']
    for row in owners:
        notebook=Path(row['evidence'][0]['path']).name
        lines.append(f'| {row["id"]} | 0x{row["end"]:08X} | [{row["name"]}]({notebook}) |')
    (ROOT/'docs/STATIC_DNAS_O5_OWNER_RECONCILIATION.md').write_text('\n'.join(lines)+'\n',encoding='utf-8')
    print(f'Reconciled32 disjoint owner hashes and73 spans; residuals {counts}; no credit changed.')


if __name__=='__main__':
    main()
