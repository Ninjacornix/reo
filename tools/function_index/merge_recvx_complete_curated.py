"""Merge explicitly authored main-image comparisons; retain ambiguous pairs in ledgers."""
import hashlib
import json
from pathlib import Path
import sqlite3

from index import ROOT
from recvx_scope_inventory import PIN

INPUTS=(
 ('recvx-streamfs-complete-scope.json','proposed_curated_groups'),
 ('recvx-audio-curated-additions.json','groups'),
 ('recvx-movie-platform-complete-scope.json','groups'),
 ('recvx-card-disc-platform-complete-scope.json','proposed_curated_groups'),
)


def main():
    path=ROOT/'docs/recvx-crosscheck/review.json'
    original=path.read_bytes()
    review=json.loads(original)
    assert review['reference_commit']==PIN
    seen={int(row[0],16):(group,i) for group in review['groups'] for i,row in enumerate(group['rows'])}
    assert len(seen)==sum(len(g['rows']) for g in review['groups'])
    db=sqlite3.connect('file:'+str(ROOT/'build-function-index/index.sqlite')+'?mode=ro',uri=True)
    added=updated=0
    retained=[]
    inputs=[]
    for name,key in INPUTS:
        raw=(ROOT/'build-function-index'/name).read_bytes()
        data=json.loads(raw)
        assert data['reference_commit']==PIN
        groups=data[key]
        inputs.append(dict(path='build-function-index/'+name,sha256=hashlib.sha256(raw).hexdigest(),
                           proposed_rows=sum(len(g['rows']) for g in groups)))
        for proposal in groups:
            for row in proposal['rows']:
                address=int(row[0],16)
                target=db.execute('select proposed_name from functions where image=? and start=?',('main',address)).fetchone()
                assert target and target[0],('Unannotated or absent main entry',row[0])
                assert len(row)==4 and row[2] in ('supported-role','name-candidate','related-different','concept-only')
                if address in seen:
                    group,index=seen[address]
                    previous=group['rows'][index]
                    if group['notebook']==proposal['notebook'] and group['cvx_file']==proposal['cvx_file'] and previous[1]==row[1]:
                        if previous!=row: group['rows'][index]=row;updated+=1
                    else:
                        retained.append(dict(address=row[0],selected_reference=previous[1],
                                             additional_reference=row[1],source_ledger='build-function-index/'+name,
                                             reason='Keep the existing primary address crosswalk; additional scoped comparison remains in its full ledger.'))
                    continue
                group=next((g for g in review['groups'] if g['notebook']==proposal['notebook'] and g['cvx_file']==proposal['cvx_file']),None)
                if group is None:
                    group=dict(id='complete-'+str(len(review['groups'])+1),notebook=proposal['notebook'],
                               cvx_file=proposal['cvx_file'],rows=[])
                    review['groups'].append(group)
                group['rows'].append(row)
                seen[address]=(group,len(group['rows'])-1)
                added+=1
    review['review_date']='2026-11-05'
    review['complete_scope_ledger']='build-function-index/recvx-complete-comparison-coverage.json'
    review['complete_scope_note']='docs/recvx-crosscheck/COMPLETE_SCOPE_REPORT.md'
    path.write_text(json.dumps(review,indent=2)+'\n',encoding='utf-8')
    receipt=dict(schema=1,reference_commit=PIN,review_before_sha256=hashlib.sha256(original).hexdigest(),
                 review_after_sha256=hashlib.sha256(path.read_bytes()).hexdigest(),inputs=inputs,
                 added=added,updated=updated,total=len(seen),additional_pairs_retained_in_ledgers=retained,
                 limits='Curated comparisons only. This merge adds no semantic annotations, game code or equivalence claim.')
    (ROOT/'build-function-index/recvx-complete-curated-merge.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({k:receipt[k] for k in ('added','updated','total')}))


if __name__=='__main__': main()
