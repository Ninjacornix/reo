"""Seal actual model traversals and canonical frame-worker adoption."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def main():
    domain=[
        'game/native/gameplay_world/actor_model_passes.hpp',
        'game/native/gameplay_world/actor_model_passes.cpp',
        'game/native/gameplay_update/actor_model_workers.hpp',
        'game/native/gameplay_update/actor_model_workers.cpp',
        'game/native/gameplay_update/actor_model_workers_tests.cpp',
        'tools/native_reconstruction/animation/actor_model_passes_tests.inc',
        'tools/native_reconstruction/animation/constrained_attachment_tests.cpp',
        'tools/native_reconstruction/animation/verify_constrained_attachments.py',
        'docs/native-gameplay/ACTOR_MODEL_PASSES.md',
        Path(__file__).relative_to(ROOT).as_posix()]
    sources={name:sha(ROOT/name)for name in domain};cohorts={};previous=None
    for compiler in ('llvm','gcc'):
        path=ROOT/'build-native-sjuni'/f'actor-model-passes-{compiler}-v5/receipt.json'
        record=json.loads(path.read_bytes());assert record['status']=='passed' and record['source_unchanged']
        if previous is not None:assert record['observed']==previous
        previous=record['observed'];changes={}
        for name,digest in record['source_sha256'].items():
            frozen=path.parent/'source'/name
            assert frozen.is_file() and sha(frozen)==digest,name
            if sha(ROOT/name)!=digest:changes[name]={'qualified':digest,'current':sha(ROOT/name)}
            if name in sources:assert sources[name]==digest,name
        cohorts[compiler]={'path':path.relative_to(ROOT).as_posix(),'sha256':sha(path),
            'compiler_sha256':record['compiler_sha256'],'observed':record['observed'],
            'subsequent_dependency_changes':changes}
    parents={}
    for compiler in ('llvm','gcc'):
        path=ROOT/'build-native-sjuni'/f'actor-predicates-ai-counter-parents-{compiler}-v1/receipt.json'
        record=json.loads(path.read_bytes());assert record['status']=='passed' and not record.get('source_drift')
        assert record['parent_tests']==16
        for name in domain[2:4]:assert record['source_sha256'][name]==sources[name],name
        binary=ROOT/'build-native-sjuni'/f'gameplay-native-{compiler}-v1/gameplay_update/actor_model_workers_tests.exe'
        parents[compiler]={'path':path.relative_to(ROOT).as_posix(),'sha256':sha(path),'tests':16,
            'worker_binary':binary.relative_to(ROOT).as_posix(),'worker_binary_sha256':sha(binary),
            'worker_test_source_sha256_at_seal':sources[domain[4]]}
    output=ROOT/'tools/native_reconstruction/native_actor_model_passes_qualification_v1.json';assert not output.exists()
    record=dict(schema=1,status='passed',game_run=False,installed_in_game=False,stage4_complete=False,
        source_sha256=sources,cohorts=cohorts,current_worker_parent_regressions=parents,
        preserved_draft_receipts=[f'build-native-sjuni/actor-model-passes-llvm-v{n}/receipt.json'for n in (1,2,4)],
        limits=[
            'Traversal cases deliberately share one imported model to expose ordering; independent ground/resource composition also executes in the same cohort.',
            'The worker test uses explicit fixture providers for remaining frame work; it does not migrate those providers.',
            'Immutable model source snapshots retain exact identities; subsequent dependency changes are recorded and current parent tests qualify worker adoption.',
            'No complete room/session construction, rendering migration or native installed-game acceptance claim.'])
    output.write_text(json.dumps(record,indent=2)+'\n');print(sha(output))
if __name__=='__main__':main()
