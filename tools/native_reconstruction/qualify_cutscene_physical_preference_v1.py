"""Seal physical roster-tail preference admission and current construction."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    target=ROOT/'tools/native_reconstruction/native_cutscene_physical_preference_qualification_v1.json';assert not target.exists()
    sources={};cohorts={};expected={}
    for cc in ['llvm','gcc']:
        cohorts[cc]={}
        for kind,directory in [('selection',f'cutscene-physical-preference-{cc}-v1'),('construction',f'primary-physical-preference-{cc}-v1')]:
            path=ROOT/'build-native-sjuni'/directory/'receipt.json';r=json.loads(path.read_bytes());assert r['status']=='passed'and r['source_unchanged'];o=r.get('compared',r.get('owned'))
            assert kind not in expected or expected[kind]==o;expected[kind]=o
            if kind=='selection':assert o['checks']==1560783 and o['compared']==56686 and o['descriptor_cases']==19728 and o['full_cases']==72 and o['preference_refusals']==3
            else:assert o['checks']==117002 and o['construction_cases']==258 and o['construction_guards']==3
            for name,digest in r['source_sha256'].items():
                assert sha(ROOT/name)==digest,name
                assert name not in sources or sources[name]==digest
                sources[name]=digest
            for name,digest in r['output_sha256'].items():assert sha(path.parent/name)==digest,name
            cohorts[cc][kind]=dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),observed=o)
            if kind=='selection':
                parent=path.parent/'parents.log';raw=parent.read_bytes();text=raw.decode('utf-16'if raw.startswith(b'\xff\xfe')else'utf-8-sig');assert '100% tests passed, 0 tests failed out of 2'in text
                cohorts[cc][kind]['parents']=dict(path=parent.relative_to(ROOT).as_posix(),sha256=sha(parent))
    target.write_text(json.dumps(dict(schema=1,status='qualified physical roster preferences beyond eligible count',game_run=False,installed_in_game=False,stage4_complete=False,source_sha256=sources,cohorts=cohorts,limitations=[
        'Every physical preference0..8 is compared; fallback iteration still uses the independent eligible count.',
        'Original constructor metadata uses the declared nonoverlapping fixture arena; full scene storage is not admitted.',
        'Temporary model-cache admission remains closed. Native filtered roster production, independent resident resources and complete scene exit remain open.']),indent=2)+'\n')
    print(json.dumps(dict(status='passed',seal=target.relative_to(ROOT).as_posix())))
if __name__=='__main__':main()
