"""Seal cinematic choice preparation with full constructor roster effects."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    target=ROOT/'tools/native_reconstruction/native_cutscene_primary_selection_qualification_v1.json';assert not target.exists()
    sources={};cohorts={};expected=dict(status='passed',checks=869033,compared=31494,full_cases=40,choices=30204,descriptor_cases=10960,preference_refusals=3,game_run=False)
    for cc in ['llvm','gcc']:
        path=ROOT/f'build-native-sjuni/cutscene-primary-selection-{cc}-v6/receipt.json';r=json.loads(path.read_bytes());assert r['status']=='passed'and r['source_unchanged']and r['compared']==expected and r['basic']['compared']==0
        assert len(r['original_owned_bodies'])==6 and r['native_stream_source_extraction']['live_scheduler_executed']is False
        for name,digest in r['source_sha256'].items():
            assert sha(ROOT/name)==digest,name
            assert name not in sources or sources[name]==digest
            sources[name]=digest
        for name,digest in r['output_sha256'].items():assert sha(path.parent/name)==digest,name
        parent=path.parent/'cmake-parent.log';raw=parent.read_bytes();log=raw.decode('utf-16'if raw.startswith(b'\xff\xfe')else'utf-8-sig');assert '100% tests passed, 0 tests failed out of 2'in log
        cohorts[cc]=dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),observed=r['compared'],native_only=r['basic'],cmake_parent=dict(path=parent.relative_to(ROOT).as_posix(),sha256=sha(parent)))
    target.write_text(json.dumps(dict(schema=1,status='qualified cinematic primary choice and roster-mutation preparation',game_run=False,installed_in_game=False,stage4_complete=False,source_sha256=sources,cohorts=cohorts,limitations=[
        'Complete5F0DC0/5F0C60/5F0CF0/5F0D90/5F1330/5F1400 execute against pinned owned words.',
        'Constructor metadata output arguments are relocated into a bounded nonoverlapping arena, corresponding to native typed output. Original overlapping array storage is not admitted.',
        'Bounded fill/copy and5EC270 retirement-request observation are explicit ports. Native choice preparation does not clone complete Actors or retire actual models.',
        'Raw headers from all5480950 descriptors independently feed the original. Legacy0930/0940 and original null-target calls do not execute.',
        'Input includes all eight physical roster entries and population. Class1 matched-slot removal affects later choices; this corrects the earlier limited trace fixture.',
        'Typed native actor cloning, model-slot handoff, sixteen objects, sparse primary cinematic motion and full scene/game acceptance remain open.']),indent=2)+'\n')
    print(json.dumps(dict(status='passed',seal=target.relative_to(ROOT).as_posix())))
if __name__=='__main__':main()
