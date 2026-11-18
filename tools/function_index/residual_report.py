#!/usr/bin/env python3
"""Report annotation gaps without changing the catalogue or semantic credit.

Reads the existing index and hash-verified owned files only. It never starts or
attaches to a process. Run after refresh-annotations and classify_leaves.
"""
from collections import Counter
import hashlib
import json
from pathlib import Path
import re
import sqlite3
import struct

ROOT = Path(__file__).resolve().parents[2]


def main():
    output = ROOT / 'build-function-index'
    annotations = json.loads((ROOT / 'tools/function_index/annotations.json').read_text(encoding='utf-8'))['annotations']
    reviewed = {a['id'] for a in annotations}
    mechanical = {a['id'] for a in json.loads((ROOT / 'tools/function_index/leaf_classifications.json').read_text(encoding='utf-8'))['entries']}
    assert len(reviewed) == len(annotations) and not reviewed & mechanical
    identities = json.loads((ROOT / 'tools/function_index/overlay_identities.json').read_text(encoding='utf-8'))['images']
    images = {}
    for identity in identities:
        raw = (output / f'owned-overlays/{identity["image"]}.bin').read_bytes()
        assert hashlib.sha256(raw).hexdigest() == identity['imageSha256']
        assert raw[:4] == b'MWo3'
        assert struct.unpack_from('<II', raw, 4) == (identity['id'], identity['base'])
        images[identity['image']] = (identity, raw)
    with sqlite3.connect(output / 'index.sqlite') as db:
        db.row_factory = sqlite3.Row
        rows = [dict(r) for r in db.execute('SELECT * FROM functions ORDER BY image,start')]
    assert len(rows) == 17916, 'Changed catalogue: review the baseline before publishing a new denominator'
    assert {r['id'] for r in rows if r['proposed_name']} == reviewed
    # These are already reviewed data/boundary admissions, not new API names.
    # Keep them distinct from purpose-unknown executable operations.
    data_boundaries = set()
    admission_classes = {}
    admission = ROOT / 'docs/STATIC_MAIN_SEMANTIC_RESIDUAL_ADMISSION_INVENTORY.md'
    data_classes = {
        'embedded render-program data/boundary; no EE function role',
        'byte/data carrier boundary; executable role unproved',
        'embedded OSD configuration/firmware pointer data',
    }
    for line in admission.read_text(encoding='utf-8').splitlines():
        match = re.match(r'^\| (main:0x[0-9A-Fa-f]+) \|', line)
        if match:
            admission_classes[match[1]] = line.split('|', 6)[4].strip()
        if match and any(f'| {kind} |' in line for kind in data_classes):
            data_boundaries.add(match[1])
    assert len(data_boundaries) == 33
    parent_partitions = {}
    # Only use a partition ledger when it accounts for this exact pending set.
    # A stale ledger must not silently classify newly changed annotations.
    for image in ('o4', 'o5'):
        ledger = output / f'dnas-{image}-owner-reconciliation.json'
        if not ledger.exists():
            continue
        proof = json.loads(ledger.read_text(encoding='utf-8'))
        identity, _ = images[image]
        assert proof['image_sha256'] == identity['imageSha256']
        pending = {r['id'] for r in rows if r['image'] == image and r['id'] not in reviewed}
        indexed = {r['id'] for r in proof['residuals']}
        if pending == indexed:
            parent_partitions.update({r['id']: r['reviewed_parent'] for r in proof['residuals'] if r['reviewed_parent']})
    residuals = []
    for row in rows:
        if row['id'] in reviewed:
            continue
        category = 'unresolved purpose or boundary; see image admission evidence'
        digest = None
        if row['image'] in images:
            identity, raw = images[row['image']]
            start, end = row['start'] - identity['base'], row['end'] - identity['base']
            if 0 <= start < end <= len(raw):
                digest = hashlib.sha256(raw[start:end]).hexdigest()
            if 0 <= start < end <= 0x20:
                category = 'MWo3 header partition; no callable code role credited'
            elif row['id'] in mechanical:
                category = 'exact mechanical leaf; no subsystem role credited'
            elif row['id'] in parent_partitions:
                category = 'catalogue cut covered by reviewed owner; independent entry unproved'
            elif row['image'] in ('o4', 'o5'):
                category = 'protected or fragmented interval; full role unresolved'
        elif row['id'] in mechanical:
            category = 'exact mechanical leaf; no subsystem role credited'
        if row['id'] in data_boundaries:
            category = 'embedded data or byte boundary; callable role unproved'
        residuals.append(dict(id=row['id'], image=row['image'], start=f'0x{row["start"]:08X}',
                              end=f'0x{row["end"]:08X}', category=category,
                              source=row['source'], instruction_comments=row['instruction_count'],
                              reviewed_parent=parent_partitions.get(row['id']),
                              owned_interval_sha256=digest))
    counts = Counter(r['category'] for r in residuals)
    headers = 'MWo3 header partition; no callable code role credited'
    assert counts[headers] == 81
    total = len(rows)
    percent = len(reviewed) * 100 / total
    record = dict(schema=1, edition='SLUS-20765', total_catalogue_entries=total,
                  reviewed_annotations=len(reviewed), annotation_percent=percent,
                  disjoint_mechanical_classifications=len(mechanical),
                  counts=dict(counts), residuals=residuals,
                  limitations='Annotation coverage is not full semantic recovery, native translation, runtime validation or performance improvement.')
    (output / 'mapping-residuals.json').write_text(json.dumps(record, indent=2) + '\n', encoding='utf-8')
    lines = ['# Remaining mapping evidence', '',
             f'The current index contains **{len(reviewed):,} reviewed annotations / {total:,} fixed catalogue entries ({percent:.2f}%)**. '
             f'The remaining **{len(residuals):,} entries** are retained below without additional semantic credit.', '',
             'This percentage measures reviewed role annotations. Some annotations deliberately describe partial entrances, '
             'candidate purposes or byte-identical bodies. It does **not** measure complete source reconstruction, native translation, '
             'runtime equivalence or tested slowdown fixes. No game was run for this report.', '',
             '| Remaining evidence class | Entries |', '| --- | ---: |']
    lines += [f'| {name} | {count:,} |' for name, count in sorted(counts.items())]
    lines += ['', '## Per-image snapshot', '', '| Image | Catalogue | Annotated | Remaining |', '| --- | ---: | ---: | ---: |']
    for image in sorted({r['image'] for r in rows}):
        image_rows = [r for r in rows if r['image'] == image]
        done = sum(r['id'] in reviewed for r in image_rows)
        lines.append(f'| {image} | {len(image_rows):,} | {done:,} | {len(image_rows)-done:,} |')
    purpose_gaps = [r for r in residuals if r['category'].startswith('unresolved purpose')]
    lines += ['', '## Entries still requiring stronger purpose evidence', '',
              'These are kept unknown instead of assigning convenient API names. The resident '
              'admission inventory retains the earlier byte/hash snapshot; the '
              '[fifty-entry purpose review](STATIC_FINAL_PURPOSE_GAP_REVIEW.md) records subsequent '
              'caller, producer and primary-source evidence and the remaining ownership gaps. '
              'The o2 table-reset helper has a complete mechanical contract but no demonstrated typed consumer.', '',
              '| Identity | Instruction comments | Missing role context / admission class | Source |',
              '| --- | ---: | --- | --- |']
    for row in purpose_gaps:
        context = admission_classes.get(row['id'], 'untyped global table reset; typed consumer missing')
        source = f'[original source](../{row["source"]})' if row['source'] else 'No generated source'
        lines.append(f'| {row["id"]} | {row["instruction_comments"]} | {context} | {source} |')
    lines += ['', '## What the remaining work requires', '',
              'The 81 header partitions are file metadata, including single-byte cuts of MWo3 header fields. '
              'Their original image hashes, magic, runtime ID and load base were verified. Naming them as game functions '
              'would misstate progress. Their presence in the fixed denominator prevents an honest claim that every '
              'catalogue entry is a reconstructed callable function.', '',
              '[Resident residual admission](STATIC_MAIN_SEMANTIC_RESIDUAL_ADMISSION_INVENTORY.md) separates numeric kernel '
              'leaves, optional provider operations, untyped fields and embedded data. A typed consumer, original provider '
              'or verified operation contract is needed to improve those roles; an instruction-shaped byte sequence is insufficient.', '',
              '[Network DNAS boundaries](SYMBOLS_NETDNAS_RESIDUAL_BOUNDARIES.md) and '
              '[the independent clear-span audit](STATIC_O4_OUTSIDE_PAYLOAD_RESIDUAL_AUDIT.md) preserve protected entrances, '
              'fragments and source-less cuts. [DNAS admission refresh](STATIC_O5_DNAS_RESIDUAL_ADMISSION_REFRESH.md) '
              'similarly finds no independent complete clear function among its remaining continuation fragments. '
              'Recovering a full protected operation needs additional independently verified body/boundary evidence; '
              'clear wrapper analysis alone does not establish it.', '',
              '[A bounded protected field query](SYMBOLS_NETDNAS_RECOVERED_TWO_BIT_FIELD_QUERY.md) '
              'has now been reconstructed as data using its actual entry and restore schedules, independently reviewed, '
              'and admitted as one complete operation. This establishes an offline recovery route for further spans; '
              'round trips alone do not resolve original function boundaries or justify credit for every fragment.', '',
              'The [upper-family inventory](STATIC_DNAS_UPPER_RECOVERY_INVENTORY.md) now covers53 reconstructed '
              'spans whose connected owners were reviewed. [Primary-family candidates](STATIC_DNAS_PRIMARY_RECOVERY_INVENTORY.md) '
              'extend the copied-data method to63 spans, with noncanonical restore paths and inline data requiring '
              'individual ownership review. These inventories do not automatically promote internal cuts.', '',
              '[The o4 owner reconciliation](STATIC_DNAS_O4_OWNER_RECONCILIATION.md) binds all116 protected '
              'spans to101 disjoint, hash-verified logical bodies. Its remaining catalogue identities are '
              'header partitions or interior cuts, with one verified zero-padding extension. Parent coverage '
              'is recorded separately from an independently established function entry.', '',
              '[The o5 owner reconciliation](STATIC_DNAS_O5_OWNER_RECONCILIATION.md) similarly binds73 '
              'protected spans to32 reviewed logical bodies; its remaining9 header partitions and161 '
              'interior cuts receive no independent function credit. The resident admission inventory '
              'also separates33 embedded-data/byte-boundary identities from executable purpose gaps.', '',
              '[Exact mechanical leaves](FUNCTION_LEAF_CLASSIFICATIONS.md) have useful instruction-level contracts '
              'without invented subsystem names. New purpose annotations require complete owned instructions '
              'and supported callers, producers, registrations or provider implementations. The JSON snapshot lists every outstanding '
              'identity so new evidence can be reconciled without changing the denominator.', '',
              'Generated-source gaps need not be permanent unknowns: '
              '[five complete raw helpers/callbacks](SYMBOLS_RAW_COMMON_SINE_AND_LOBBY_COMPLETION_CALLBACKS.md) '
              'were recovered from owned bytes while retaining their absent generated-source status.', '',
              'Reproduce this snapshot after refreshing annotations with '
              '`python tools/function_index/residual_report.py`. The machine-readable output is '
              '`build-function-index/mapping-residuals.json`; the central index remains '
              '[FUNCTION_INDEX.md](FUNCTION_INDEX.md).', '']
    (ROOT / 'docs/STATIC_MAPPING_REMAINING_WORK.md').write_text('\n'.join(lines), encoding='utf-8')
    print(f'Residual snapshot: {len(reviewed)}/{total} annotated; {len(residuals)} remaining, including81 header partitions. No credit changed.')


if __name__ == '__main__':
    main()
