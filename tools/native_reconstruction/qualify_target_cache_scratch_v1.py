"""Seal controlled source scratch determinacy and the explicit candidate policy."""
import json
from seal_gameplay_component import ROOT,sha
if __name__=='__main__':
    target=ROOT/'tools/native_reconstruction/native_target_cache_scratch_audit_v1.json';assert not target.exists()
    sources,cohorts,failed={},{},{}
    observed=None
    for cc in ['llvm','gcc']:
        path=ROOT/f'build-native-sjuni/target-cache-scratch-{cc}-v3/receipt.json';receipt=json.loads(path.read_bytes());data=receipt['observed']
        assert receipt['status']=='passed' and receipt['source_unchanged'];assert observed is None or data==observed;observed=data
        for key,value in dict(profile_count=48,runs=192,initialized_runs=192,scratch_sensitive_profiles=24,unknown_profiles=24,unknown_reads=119712,controlled_port_calls=160104,checks=87112894).items():assert data[key]==value,key
        assert data['unknown_read_pcs']=={str(0x6d6d80):35844,str(0x6d6d84):83868}
        assert {int(k):v for k,v in data['changed_profile_ranges'].items() if v}=={0x3b2880:12,0x3b2c80:18}
        for name,digest in receipt['source_sha256'].items():
            assert sha(ROOT/name)==digest,name;assert name not in sources or sources[name]==digest;sources[name]=digest
        for name,digest in receipt['output_sha256'].items():assert sha(path.parent/name)==digest,name
        cohorts[cc]=dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),observed=data)
        for version in [1,2]:
            path=ROOT/f'build-native-sjuni/target-cache-scratch-{cc}-v{version}/receipt.json';old=json.loads(path.read_bytes());assert old['status']==('failed' if version==1 else 'passed');failed[path.relative_to(ROOT).as_posix()]=sha(path)
    sources['tools/native_reconstruction/qualify_target_cache_scratch_v1.py']=sha(ROOT/'tools/native_reconstruction/qualify_target_cache_scratch_v1.py')
    target.write_text(json.dumps(dict(schema=1,status='controlled source target-cache scratch determinacy audit passed',game_launched=False,installed_in_game=False,stage4_complete=False,source_sha256=sources,cohorts=cohorts,prior_cohorts=failed,limitations=[
        'This is a controlled original-code investigation, not a port, live reproduction or performance result. Complete6D6240/6D6D60 and raw-mode query chain execute. Distance, heading and clear collision results are declared controlled input ports; their actual math/model/collision production is not qualified by this audit.',
        'In192 strict runs across48 synthetic actor-presence profiles and four finite caller-scratch patterns,119712 reads at6D6D80/84 consume bytes not written by this invocation.24 profiles change outputs with caller scratch. Changes are confined to linked-to-auxiliary order3B2880 in12 profiles and linked-to-primary order3B2C80 in18; forward lists and all metric banks remain unchanged. Their union is24 profiles.',
        '192 separate test-only candidate-policy runs initialize only the two68x68 distance work arrays to finite maximum. All48 profiles then have zero read-before-write and identical outputs across the four other scratch patterns. The24 naturally deterministic profiles remain identical to strict originals. This establishes the bounded synthetic initialization policy; it does not establish actual stock admission or fix the installed game.',
        'A native cache implementation must explicitly own scratch initialization and identify the source correction. It should preserve known forward metrics and canonical model/collision inputs, prove equivalence where strict source data is defined, compare the corrected profile separately, and validate real callers. Do not promise exact preservation of uninitialized stack history or label this a confirmed stutter cause.',
        'First audit lacked the raw-mode getter dependency and refused an undeclared call. v2 includes the complete source getter chain and succeeds; v3 adds affected-range and candidate-policy checks. All evidence remains. Installed V39 is unchanged; Stage4 is incomplete.'
    ]),indent=2)+'\n');print(sha(target))
