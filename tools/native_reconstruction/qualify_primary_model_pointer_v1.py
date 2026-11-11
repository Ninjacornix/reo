"""Seal the previously masked fresh-versus-restore pointer distinction."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    target=ROOT/'tools/native_reconstruction/native_primary_model_pointer_qualification_v1.json';assert not target.exists()
    cohorts={};sources={};expected=None
    for cc in ['llvm','gcc']:
        path=ROOT/f'build-native-sjuni/primary-model-pointer-{cc}-v1/receipt.json';r=json.loads(path.read_bytes());assert r['status']=='passed'and r['source_unchanged'];o=r['owned']
        assert expected is None or expected==o;expected=o;assert o['checks']==39837137 and o['restores']==4096 and o['selector_restores']==255
        fresh=o['initializations']+o['custom_initializations']+o['saved_initializations']+o['selector_cases']-o['selector_restores'];restored=o['restores']+o['selector_restores'];assert(fresh,restored)==(167969,4351)
        helper=ROOT/'tools/native_reconstruction/primary_actor_initialization_reference.inc';text=helper.read_text();assert 'put(0x34,previous_work)'in text and '(restore?previous_work:work)'in text
        for name,digest in r['source_sha256'].items():
            assert sha(ROOT/name)==digest,name
            assert name not in sources or sources[name]==digest
            sources[name]=digest
        for name,digest in r['output_sha256'].items():assert sha(path.parent/name)==digest,name
        cohorts[cc]=dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),observed=o,fresh_pointer_stores=fresh,restore_pointer_preservations=restored)
    audit=ROOT/'build-native-sjuni/primary-scene-model-lifetime-audit-v1/receipt.json';r=json.loads(audit.read_bytes());assert r['status']=='static_source_words_verified'and len(r['original_owned_bodies'])==12
    for name,digest in r['source_sha256'].items():assert sha(ROOT/name)==digest
    target.write_text(json.dumps(dict(schema=1,status='qualified distinct fresh/restore original model-pointer behavior',game_run=False,installed_in_game=False,stage4_complete=False,source_sha256=sources,cohorts=cohorts,static_audit=dict(path=audit.relative_to(ROOT).as_posix(),sha256=sha(audit),bodies=12),limitations=[
        'Fixture improvement only: no production behavior or temporary model-cache admission changed.',
        'The static twelve-body roster/cleanup audit is not an executed complete entry/exit sequence.',
        'Filtered roster preparation, additional bank cleanup, physical resource ownership and full native scene/game acceptance remain open.']),indent=2)+'\n')
    print(json.dumps(dict(status='passed',seal=target.relative_to(ROOT).as_posix())))
if __name__=='__main__':main()
