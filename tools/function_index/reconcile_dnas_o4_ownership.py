#!/usr/bin/env python3
"""Reconcile reviewed o4 envelopes with remaining catalogue partitions.

No annotation or denominator changes. Reads existing review receipts and verifies
every complete original extent against the pinned owned image before reporting.
"""
import hashlib
import json
from pathlib import Path
import sqlite3

from recover_dnas_zero_upper import BASE, SHA

ROOT = Path(__file__).resolve().parents[2]
SOURCES = (
    ('proxy-dnas-first14-review.json','cases','logical_end_exclusive','original_joined_sha256'),
    ('dnas-driver-records-review.json','owners','ownerEndExclusive','originalOwnerSha256'),
    ('dnas-query-adapters-review/receipt.json','owners','end_exclusive','complete_original_interval_sha256'),
    ('dnas-final-owner-review/receipt.json','owners','end_exclusive','complete_original_interval_sha256'),
    ('dnas-upper-root-review/receipt.json','owners','end_exclusive','complete_original_interval_sha256'),
    ('proxy-dnas-primary-first23-review.json','cases','logical_end_exclusive','joined_original_sha256'),
    ('dnas-primary-middle-review/receipt.json','owners','endExclusive','originalOwnerSha256'),
    ('dnas-primary-allocator-review/receipt.json','owners','end_exclusive','original_sha256'),
    ('dnas-primary-start-connect-review/receipt.json','owners','end_exclusive','complete_original_interval_sha256'),
    ('dnas-primary-root-review/receipt.json','owners','end_exclusive','original_joined_sha256'),
)
FIXED = (
    (0x749500,0x749638,'44cfaded211e1669b9cae9e4c4326b83b6eb84b2a9c33601eacdb6f955763b0c'),
    (0x749638,0x7497A8,'90cbc98a50fc0932f6ac894d67f084ba787066c48990d6f33d7fa5cdb9aa7340'),
    (0x74E1A8,0x74E2E0,'1dd0cd1b33de7364a28126355bc734dd57c80b3f00fa97557ffe90348def9c0c'),
    (0x74E728,0x74E830,'34910085462d8266838fb3f08eb595e2bc3ca27282d520ddca1f5af58add56df'),
)


def main():
    output = ROOT/'build-function-index'
    original = (output/'owned-overlays/o4.bin').read_bytes()
    assert hashlib.sha256(original).hexdigest()==SHA
    annotations = json.loads((ROOT/'tools/function_index/annotations.json').read_text(encoding='utf-8'))['annotations']
    reviewed = {a['id']:a for a in annotations}
    owners = []

    def admit(start,end,digest,receipt):
        identity = f'o4:0x{start:08X}'
        assert identity in reviewed
        assert hashlib.sha256(original[start-BASE:end-BASE]).hexdigest()==digest
        owners.append(dict(id=identity,start=start,end=end,original_sha256=digest,receipt=receipt,
                           name=reviewed[identity]['proposed_name'],evidence=reviewed[identity]['evidence']))

    for filename,key,end_key,hash_key in SOURCES:
        data = json.loads((output/filename).read_text(encoding='utf-8'))
        for row in data[key]:
            admit(int(row['owner'].split(':')[-1],0),int(row[end_key],0),row[hash_key],filename)
    for start,end,digest in FIXED:
        admit(start,end,digest,'fixed zero-key review; linked authoritative notebook')
    owners.sort(key=lambda row:row['start'])
    assert len(owners)==len({row['id'] for row in owners})==101
    assert all(a['end']<=b['start'] for a,b in zip(owners,owners[1:]))
    spans = []
    for family in ('upper','primary'):
        inventory = json.loads((output/f'dnas-{family}-recovery-inventory.json').read_text(encoding='utf-8'))
        assert inventory['image_sha256']==SHA
        for row in inventory['spans']:
            start,end = int(row['start'],0),int(row['end_exclusive'],0)
            matches = [owner for owner in owners if owner['start']<=start<end<=owner['end']]
            assert len(matches)==1,(family,row['start'])
            spans.append(dict(family=family,start=hex(start),end_exclusive=hex(end),owner=matches[0]['id']))
    assert len(spans)==116
    with sqlite3.connect((output/'index.sqlite').resolve().as_uri()+'?mode=ro',uri=True) as db:
        db.row_factory=sqlite3.Row
        rows=[dict(r) for r in db.execute("SELECT * FROM functions WHERE image='o4' ORDER BY start")]
    assert {r['id'] for r in rows if r['proposed_name']}=={a['id'] for a in annotations if a['image']=='o4'}
    residuals=[]
    for row in rows:
        if row['id'] in reviewed:
            continue
        start,end=row['start'],row['end']
        matches=[owner for owner in owners if owner['start']<start and end<=owner['end']]
        if matches:
            assert len(matches)==1
            owner=matches[0]['id'];category='partition inside reviewed logical owner'
        elif BASE<=start<end<=BASE+0x20:
            owner=None;category='MWo3 header partition'
        else:
            matches=[owner for owner in owners if owner['start']<start<owner['end']<end
                     and end-owner['end']<=16 and not any(original[owner['end']-BASE:end-BASE])]
            assert len(matches)==1,('unreconciled residual',row['id'],hex(end))
            owner=matches[0]['id'];category='owner partition plus verified zero padding'
        residuals.append(dict(id=row['id'],start=hex(start),end_exclusive=hex(end),category=category,
                              reviewed_parent=owner,independent_function_entry_established=False))
    counts={category:sum(r['category']==category for r in residuals) for category in sorted({r['category'] for r in residuals})}
    result=dict(schema=1,image='o4',image_sha256=SHA,reviewed_logical_owners=owners,
                protected_spans=spans,residuals=residuals,counts=counts,no_new_mapping_credit=True,
                limitations='Interior coverage does not prove an independent callable entry. Parent annotations retain '
                'their confidence, unknown providers and unverified runtime admission. No native translation, '
                'target execution or denominator change is implied.')
    (output/'dnas-o4-owner-reconciliation.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    lines=['# Network DNAS logical-owner and catalogue-partition reconciliation','',
           '**101 disjoint reviewed logical owner intervals cover all116 inventoried protected spans.** '
           'Every joined original interval SHA-256 was rechecked against the pinned owned image. '
           '**This reconciliation adds zero role annotations and changes no denominator.**','',
           'Owned o4/runtime5/base6E0000, image SHA-256 `'+SHA+'`. '
           'No game, network, runtime, target process, guest execution or owned/generated-input mutation occurred.','',
           '| Remaining unannotated catalogue class | Entries |','| --- | ---: |']
    lines += [f'| {name} | {count} |' for name,count in counts.items()]
    lines += ['', 'All remaining o4 identities are header partitions or cuts covered by these reviewed logical bodies. '
              'One cut ends four zero bytes after its parent return extent; those bytes were verified. '
              'This does not promote an interior offset, inline string, serialized blob, restore header or one-byte '
              'partition to an independent original function. Standalone entry contracts remain unproved.','',
              'The reviewed names describe known control/data contracts with their recorded confidence. Opaque '
              'callbacks, mathematical provider identities, runtime aliasing/concurrency and actual reachability '
              'remain separate unknowns. The catalogue can also omit clear support helpers, so even complete '
              'catalogue accounting would not prove complete original-source reconstruction.','',
              'Reproduce after regenerating the linked individual review receipts and refreshing annotations: '
              '`python tools/function_index/reconcile_dnas_o4_ownership.py`. Machine-readable owner bounds, '
              'whole-interval fingerprints and every residual-parent relationship are retained in '
              '`build-function-index/dnas-o4-owner-reconciliation.json`. '
              '[Upper recovery](STATIC_DNAS_UPPER_RECOVERY_INVENTORY.md), '
              '[primary recovery](STATIC_DNAS_PRIMARY_RECOVERY_INVENTORY.md), '
              '[central index](FUNCTION_INDEX.md).','',
              '| Reviewed logical entrance | End exclusive | Authoritative role evidence |',
              '| --- | --- | --- |']
    for row in owners:
        evidence=row['evidence'][0]
        notebook=Path(evidence['path']).name
        lines.append(f'| {row["id"]} | 0x{row["end"]:08X} | [{row["name"]}]({notebook}) |')
    (ROOT/'docs/STATIC_DNAS_O4_OWNER_RECONCILIATION.md').write_text('\n'.join(lines)+'\n',encoding='utf-8')
    print(f'Reconciled101 disjoint owner hashes and116 protected spans; residuals {counts}; no credit changed.')


if __name__=='__main__':
    main()
