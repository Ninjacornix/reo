#!/usr/bin/env python3
"""Prepare reviewed one-address audio crosswalk proposals without shared writes.

The explicit selection follows the complete 375-definition body ledger. It is
reporting curation, not a new source-name or semantic-mapping admission pass.
"""
import argparse
from collections import Counter, defaultdict
import hashlib
import json
from pathlib import Path
import re

from recvx_scope_inventory import PIN

ROOT = Path(__file__).resolve().parents[2]
SELECTED = {
    'adx_amp': '122720 122770 1227C0 1228F0 122940 122948 122AE8 122AF0 122D80 122DA8 122E08 122E10 122E18 122E20 122E28 122E30 122E38',
    'adx_baif': '1230E0 123470 1234D8 1235E8 123700 123898 123A18',
    'adx_bau': '123A40 123D58 123DB0 123EC0 123FC0 124158 1242D8 124480',
    'adx_bsc': '124810 124840 124E50 1252C8 125818',
    'adx_bsps': '125878 125998 125A90 125C08',
    'adx_bwav': '125C30 125E60 125F60 1260D8 126270 126410 126478',
    'adx_crs': '1264E0 1264F8',
    'adx_dcd': '126898',
    'adx_errs': '128038 128070 1280A8 1280D0 128128 128198 1282A0',
    'adx_fini': '128348 128410',
    'adx_inis': '12A0F0 12A130 12A1E8 12A368 12A388',
    'adx_mps2': '12BDB8 12A968 12A9F0',
    'adx_rnap': '12C630 12C648 12C668 12C680 12C6B8 12C6D0 12C6E8 12C700 12C718 12C730 12C748 12C760 12C798 12C7B0 12C7C8 12C7E0 12C7F8 12C810 12C830 12C848 12C860 12C878 12C898 12C8B0 12C8F8',
    'adx_sjd': '12C948 12C978 12C9A0 12C9D8 12CB58 12CBB8 12CBC0 12CC00 12CC10 12CC80 12CCB0 12CCE0 12CEB8 12CFD8 12D338 12D590 12D638 12D678 12D6D8 12D6E0 12D6E8 12D6F0 12D728 12D738 12D748 12D750 12D758 12D760 12D768 12D770 12D778 12D790 12D7A8 12D7C0 12D7D8 12D7F0 12D808 12D820 12D838 12D868 12D880 12D8B0 12D8C8 12DA10 12DA18 12DA30',
    'adx_stmc': '130098 1300A8 1300C8 130108 130218 1302F8 130420 1305B8 1305C0 130608 130798 1307A8 130D48 130DC8 130DF8 130E10 130E18 130E28 130E40 130E58 130E98 130EF0 130F20 130FA0 130FB0 130FD0',
    'adx_tlk': '1314E0 1315E0 131918 131AE8 131B48 131B60 131C50 131D18 131D98 131E38 131F28 131F60 132028 132160 132458 132598 1325E8 132638 1326F0 1327B8 132820 1328E8 132978 1329A8 132A08 132A70 132B58 132BC8 132BD0 132C08 132D20 132D60 132D90 132DC0 132DF0 132E20 133040 133058 133140 133148 133150 133158 133170 1331A8 133240 133280 133428',
    'adx_tlk2': '133490 133580 133618 133630 133708',
    'adx_tsvr': '133928 133AB8 133B48 133D10 133FE0 1343B8 134530 1345F0 134800 1348F0 134B40 134C58',
    'ps2_rna': '13DB48 13DE40 13DF20 13DF98 13E2B8 13E6C0 13E770 13EAC0 13ED28 13EEE8 13F1C8 13F1E0',
    'rna_crs': '13F218 13F230',
}


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--ledger', type=Path, default=ROOT / 'build-function-index/recvx-audio-complete-scope.json')
    ap.add_argument('--baseline', type=Path, default=ROOT / 'tools/function_index/recvx_audio_curation_baseline.json')
    ap.add_argument('--review', type=Path, help='Optional current shared review for overlap reporting only; never changes the frozen selection/baseline.')
    ap.add_argument('--output', type=Path, default=ROOT / 'build-function-index/recvx-audio-curated-additions.json')
    args = ap.parse_args()
    raw = args.ledger.read_bytes()
    ledger = json.loads(raw)
    assert ledger['reference_commit'] == PIN and ledger['all_reference_definitions_dispositioned']
    assert ledger['counts']['functions'] == 375
    baseline = json.loads(args.baseline.read_text(encoding='utf-8'))
    assert baseline['reference_commit'] == PIN and len(baseline['addresses']) == 170
    existing = set(baseline['addresses'])
    wanted = {(stem, a) for stem, text in SELECTED.items() for a in text.split()}
    assert len(wanted) == 243
    functions = [r for f in ledger['files'] for r in f['functions']]
    address_uses = Counter(a for r in functions for a in r['outbreak_ids'])
    notes = defaultdict(list)
    for path in sorted((ROOT / 'docs').glob('SYMBOLS*.md')):
        for i, line in enumerate(path.read_text(encoding='utf-8').splitlines(), 1):
            cells = line.split('|')
            if not line.startswith('| [') or len(cells) < 5:
                continue
            # A combined authoritative row can own both lock/unlock entries.
            for match in re.finditer(r'\[(?:main )?0x([\da-f]+)\]\(', cells[1], re.I):
                a = f'{int(match[1], 16):X}'
                notes[a].append(dict(path=path.relative_to(ROOT).as_posix(), line=i,
                                     proposed_label=cells[2].strip(), contract=cells[4].strip(), text=line))
    groups = defaultdict(list)
    selected = []
    excluded = []
    consumed = set()
    for r in functions:
        stem = Path(r['reference_file']).stem
        ids = r['outbreak_ids']
        key = (stem, ids[0]) if len(ids) == 1 else None
        if key not in wanted:
            if not ids:
                why = 'Reference empty body or scoped missing counterpart; retain full per-reference disposition.'
            elif len(ids) != 1:
                why = 'Multiple Outbreak owners/suboperations; retain many-to-many comparison only in complete ledger.'
            elif address_uses[ids[0]] != 1:
                why = 'More than one reference function claims this owner; no unique function identity admitted.'
            elif ids[0] in existing:
                why = 'Already represented by the shared crosswalk baseline; no duplicate address row proposed.'
            elif ids[0] in ('1264D0', '1307E8'):
                why = 'Mechanical bookkeeping leaf kept in complete ledger; no standalone historical-name curation credit.'
            else:
                why = 'No independently admitted authoritative semantic row (for example zero-output stub or unconsumed mode store); retain full ledger.'
            excluded.append(dict(reference_file=r['reference_file'], symbol=r['symbol'], start_line=r['start_line'],
                                 outbreak_ids=ids, reason=why))
            continue
        assert key not in consumed, key
        consumed.add(key)
        a = ids[0]
        assert address_uses[a] == 1 and len(r['outbreak_evidence']) == 1, a
        assert len(notes[a]) == 1, (a, notes[a])
        assert r['status'] in ('already-compared', 'newly-compared', 'version-different')
        note = notes[a][0]
        status = 'related-different' if r['status'] == 'version-different' else 'supported-role'
        comparison = r['comparison']
        if comparison.startswith(('Same complete typed adapter', 'Complete field/callback/inner-query', 'Matched complete typed control/getter')):
            comparison += ' Literal Outbreak contract: ' + note['contract']
        groups[note['path'].removeprefix('docs/'), r['reference_file']].append([a, r['symbol'], status, comparison])
        selected.append(dict(reference_file=r['reference_file'], reference_file_sha256=r['reference_file_sha256'],
                             symbol=r['symbol'], start_line=r['start_line'], end_line=r['end_line'],
                             body_sha256=r['body_sha256'], address=a, status=status,
                             comparison=comparison, authoritative_note=note, outbreak_evidence=r['outbreak_evidence'][0]))
    assert consumed == wanted and len(selected) + len(excluded) == 375
    assert len({r['address'] for r in selected}) == len(selected)
    proposal = [dict(notebook=n, cvx_file=f, rows=rows) for (n, f), rows in groups.items()]
    result = dict(schema=1, reference_commit=PIN,
                  source_ledger=args.ledger.relative_to(ROOT).as_posix(), source_ledger_sha256=hashlib.sha256(raw).hexdigest(),
                  review_baseline_sha256=baseline['review_sha256'],
                  frozen_baseline=args.baseline.relative_to(ROOT).as_posix(),
                  groups=proposal, selected_records=selected, excluded_records=excluded,
                  counts=dict(reference_functions=375, curated_unique_addresses=len(selected), groups=len(proposal),
                              statuses=dict(Counter(r['status'] for r in selected)),
                              remaining_in_full_ledger=len(excluded)),
                  overlap_with_frozen_baseline=sorted(existing & {r['address'] for r in selected}),
                  new_semantic_mapping_credit=0, no_shared_outputs_modified=True, no_target_activity=True,
                  limits='Qualified complete-owner/typed-field/caller comparisons only. No new original-name certainty, parity, native translation, runtime activity or mapping credit. Many-to-many/phase-only and mechanical-only ambiguities remain in the complete ledger.')
    if args.review is not None:
        current = args.review.read_bytes()
        current_review = json.loads(current)
        current_addresses = {f'{int(str(r[0]), 16):X}' for g in current_review['groups'] for r in g['rows']}
        result['optional_current_review'] = dict(sha256=hashlib.sha256(current).hexdigest(),
            overlap=sorted(current_addresses & {r['address'] for r in selected}))
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2)+'\n', encoding='utf-8')
    print(json.dumps(result['counts'], indent=2))
    print('Frozen baseline overlap:', len(result['overlap_with_frozen_baseline']))


if __name__ == '__main__':
    main()
