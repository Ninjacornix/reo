"""Seal native cinematic character sets and full original-body comparisons."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    target=ROOT/'tools/native_reconstruction/native_cutscene_actor_reservations_qualification_v1.json';assert not target.exists()
    sources={};cohorts={};expected=dict(status='passed',checks=870427,initializations=389,queries=133384,appends=8326,refusals=388,game_run=False)
    for cc in ['llvm','gcc']:
        path=ROOT/f'build-native-sjuni/cutscene-reservations-{cc}-v1/receipt.json';r=json.loads(path.read_bytes());assert r['status']=='passed'and r['source_unchanged']and r['compared']==expected
        for name,digest in r['source_sha256'].items():
            assert sha(ROOT/name)==digest,name
            assert name not in sources or sources[name]==digest
            sources[name]=digest
        for name,digest in r['output_sha256'].items():assert sha(path.parent/name)==digest,name
        parent=path.parent/'cmake-parent.log';raw=parent.read_bytes();log=raw.decode('utf-16'if raw.startswith(b'\xff\xfe')else'utf-8-sig');assert '100% tests passed, 0 tests failed out of 1'in log
        cohorts[cc]=dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),observed=r['compared'],native_only=r['basic'],cmake_parent=dict(path=parent.relative_to(ROOT).as_posix(),sha256=sha(parent)))
    target.write_text(json.dumps(dict(schema=1,status='qualified cinematic requested/reserved character sets',game_run=False,installed_in_game=False,stage4_complete=False,source_sha256=sources,cohorts=cohorts,limitations=[
        'Full5F0C60/5F0CF0/5F0D90 execute against pinned owned words. Bounded fill/copy are explicit ports.',
        'Native count/full refusals prevent unsafe original overflows; no source out-of-bounds cases execute.',
        'Full5F0DC0 selection, actor cloning, temporary binding, model handoff and scene lifecycle remain open.']),indent=2)+'\n')
    print(json.dumps(dict(status='passed',seal=target.relative_to(ROOT).as_posix())))
if __name__=='__main__':main()
