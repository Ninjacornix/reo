"""Seal exact paired dialogue-cache and concrete presentation evidence."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def main():
    sources=[
        'game/native/gameplay_scenario/text_cache.hpp','game/native/gameplay_scenario/text_cache.cpp',
        'game/native/gameplay_world/cached_dialogue_presentation.hpp','game/native/gameplay_world/cached_dialogue_presentation.cpp',
        'game/native/gameplay_world/dialogue_cache_contract_tests.cpp','tools/native_reconstruction/dialogue_records_tests.cpp',
        'tools/native_reconstruction/text_cache_tests.cpp','tools/native_reconstruction/dialogue_visibility_tests.cpp',
        'tools/native_reconstruction/cached_dialogue_pool_tests.cpp','tools/native_reconstruction/verify_text_cache.py',
        'tools/native_reconstruction/verify_dialogue_visibility.py','tools/native_reconstruction/verify_cached_dialogue_pool.py',
        'tools/native_reconstruction/qualify_dialogue_text_cache_v1.py','docs/native-gameplay/DIALOGUE_TEXT_CACHE.md']
    seals=[];observed={}
    groups={'cache':('text-cache','v3',1208167),'visibility':('dialogue-visibility','v1',262147),'concrete_pool':('cached-dialogue-pool','v1',1264192),'records_fixture_fix':('dialogue-records','v9',131709)}
    for group,(directory,version,checks)in groups.items():
        pair=[]
        for compiler in ['gcc','llvm']:
            path=ROOT/'build-native-sjuni'/f'{directory}-{compiler}-{version}'/'receipt.json';d=json.loads(path.read_text())
            assert d['status']=='passed' and d['snapshot_unchanged'] and not d['live_source_drift'] and d['observed']['checks']==checks
            for name,digest in d['source_sha256'].items():assert sha(path.parent/'source'/name)==digest
            for name in sources:
                if name in d['source_sha256']:assert sha(ROOT/name)==d['source_sha256'][name],name
            for name,digest in d['output_sha256'].items():assert sha(path.parent/name)==digest
            seals.append(dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),snapshot_unchanged=True,live_source_drift=[]));pair.append(d['observed'])
        assert pair[0]==pair[1];observed[group]=pair[0]
    for compiler in ['gcc','llvm']:
        path=ROOT/'build-native-sjuni/dialogue-cache-cmake-current-v1'/f'{compiler}-receipt.json';d=json.loads(path.read_text());assert d['status']=='passed' and not d['live_source_drift']
        for name in sources:
            if name in d['source_sha256']:assert sha(ROOT/name)==d['source_sha256'][name],name
        for step in d['steps']:assert step['returncode']==0 and sha(ROOT/step['log'])==step['sha256']
        seals.append(dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),live_source_drift=[]))
    parents=[]
    for compiler in ['gcc','llvm']:
        path=ROOT/'build-native-sjuni'/f'session-rooms-parents-{compiler}-v6/receipt.json';d=json.loads(path.read_text());assert d['status']=='passed'
        parents.append(dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),purpose='Current25-parent strict standalone record fixture fix, before new cache registration.'))
    fragments={}
    for name in ['game/native/gameplay_scenario/CMakeLists.txt','game/native/gameplay_world/CMakeLists.txt']:
        lines=(ROOT/name).read_text().splitlines();owned=[line for line in lines if 'dialogue_assets.cpp' in line or 'add_library(reo_native_dialogue STATIC' in line];start=next((i for i,line in enumerate(lines)if line.startswith('add_executable(dialogue_cache_contract_tests ')),None)
        if start is not None:owned+=lines[start:start+7]
        fragments[name]=dict(text='\n'.join(owned)+'\n',sha256=hashlib.sha256(('\n'.join(owned)+'\n').encode()).hexdigest())
    failure=ROOT/'build-native-sjuni/text-cache-gcc-v1/receipt.json'
    result=dict(schema=1,status='qualified_native_text_cache_and_concrete_dialogue_presentation',stage4_complete=False,game_run=False,audio_device_opened=False,source_sha256={name:sha(ROOT/name)for name in sources},owned_cmake_fragments=fragments,results=observed,native_contract_checks=15,receipts=seals,fixture_fix_parent_receipts=parents,retained_failures=[dict(path=failure.relative_to(ROOT).as_posix(),sha256=sha(failure),reason='Reference fixture lacked SRA32; no production difference.')],limits=[
        'Complete cache/string helpers and6DEE20 run; integrated complete6B7930/6B9590 bodies use the concrete cache presentation and canonical World.',
        'The native cache owns32 typed entries; the source clear also zeros an unused16-byte header. Callback installer1B4A20 and font/glyph consumer1B4500 remain separate.',
        'Suppression inputs remain optional borrowed capabilities; actual6DEC80 timed-message initialization and later writes are not manufactured.',
        'Full1D41F0 room bank publication and outer6B7E40 actor-response worker remain separate integration; no application frame/game launch is claimed.',
        'The historical dialogue-records v1 seal retains its old fixture hash. This follow-up records the oracle-only equality conditional and fresh identical v9 pair plus strict standalone current parent25-v6.',
        'One controlled copy-entry interruption proves unsupported128-byte cache text metadata prefix; no overflowing original copy executes.'])
    target=ROOT/'tools/native_reconstruction/native_dialogue_text_cache_qualification_v1.json';target.write_text(json.dumps(result,indent=2)+'\n');print(result['status'])
if __name__=='__main__':main()
