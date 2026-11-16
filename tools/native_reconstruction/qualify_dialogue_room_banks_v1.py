"""Seal corrected complete room-bank bodies and same-session dialogue adoption."""
import hashlib,json,re
from pathlib import Path
from audit_retail_effect_descriptors import compare_source
ROOT=Path(__file__).resolve().parents[2]
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def main():
    owned=['game/native/gameplay_world/'+name+ext for name in ['dialogue_bank_bindings','dialogue_room_banks']for ext in ['.hpp','.cpp']]
    owned+=['game/native/gameplay_world/dialogue_pool.hpp','game/native/gameplay_world/dialogue_pool.cpp']
    owned+=['game/native/gameplay_application/'+name for name in ['session_dialogue.hpp','session_dialogue.cpp','session_dialogue_tests.cpp','dialogue_workers_tests.cpp']]
    helpers=['tools/native_reconstruction/'+name for name in ['dialogue_bank_bindings_tests.cpp','verify_dialogue_bank_bindings.py','dialogue_room_banks_tests.cpp','verify_dialogue_room_banks.py','dialogue_responses_tests.cpp','qualify_dialogue_room_banks_v1.py']]+['docs/native-gameplay/DIALOGUE_ROOM_BANKS.md']
    receipts=[];results={};parents={}
    for domain,directory,version in [('physical_publication','dialogue-bank-bindings','v3'),('complete_room_refresh','dialogue-room-banks','v3'),('complete_continuation','dialogue-responses','v10'),('current_parents','surface-follower-parents','v2')]:
        observations=[]
        for cc in ['gcc','llvm']:
            path=ROOT/'build-native-sjuni'/f'{directory}-{cc}-{version}/receipt.json';record=json.loads(path.read_text());assert record['status']=='passed',(domain,cc)
            for name,digest in record.get('output_sha256',{}).items():assert sha(path.parent/name)==digest,(domain,name)
            if domain=='current_parents':
                assert record['parent_tests']==34 and not record['source_drift'];assert '55 checks'in record['session_dialogue']and'44 checks'in record['dialogue_worker'];parents[cc]=record;value=dict(parent_tests=34,owned_session_checks=55,owned_worker_checks=44)
                for name in owned:assert record['source_sha256'][name]==sha(ROOT/name),(cc,name)
            else:
                assert record.get('snapshot_unchanged',record.get('source_unchanged')),(domain,cc);value=record['observed']
                for name,digest in record['source_sha256'].items():assert sha(path.parent/'source'/name)==digest,name
                for name,digest in record.get('native_archives',{}).items():assert sha(path.parent/'archives'/name)==digest,name
                if domain=='complete_room_refresh':
                    for name in owned:
                        if '/session_dialogue'not in name:assert record['source_sha256'][name]==sha(ROOT/name),name
            receipts.append(dict(domain=domain,path=path.relative_to(ROOT).as_posix(),sha256=sha(path),live_source_drift=record.get('live_source_drift',[])));observations.append(value)
        assert observations[0]==observations[1],domain;results[domain]=observations[0]
    overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';data=overlay.read_bytes()
    source='recomp/config/output_ovl/o2/o2_005EB6D0_0x5eb6d0.cpp';begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',(ROOT/source).read_text()).groups()]
    parent_audit=compare_source('complete finish caller, child entry only adopted',source,begin,end,lambda at,n:data[at-0x570000:at-0x570000+n]);assert int.from_bytes(data[0x5eb720-0x570000:0x5eb724-0x570000],'little')==0x0c07507c
    provenance={}
    for cc in ['gcc','llvm']:
        path=ROOT/'build-native-sjuni'/f'dialogue-room-banks-{cc}-v3-snapshot/receipt.json';record=json.loads(path.read_text());provenance[cc]=dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),refresh=record['refresh_provenance'])
    fragments={}
    for name,prefix in [('game/native/gameplay_world/CMakeLists.txt','target_sources(reo_native_dialogue PRIVATE dialogue_bank_bindings.cpp'),('game/native/gameplay_application/CMakeLists.txt','add_library(reo_native_session_dialogue STATIC')]:
        lines=(ROOT/name).read_text().splitlines();start=next(i for i,line in enumerate(lines)if line.startswith(prefix));selected=lines[start:start+(1 if 'gameplay_world/'in name else 12)];text='\n'.join(selected)+'\n';fragments[name]=dict(text=text,sha256=hashlib.sha256(text.encode()).hexdigest())
    retained=[]
    for directory,reason in [('dialogue-bank-bindings-gcc-v1','Live World source changed before snapshot admission.'),('dialogue-bank-bindings-gcc-v2','Mixed frozen include roots in the draft fixture.'),('dialogue-room-banks-gcc-v1','Fixture indentation warning; its room projection is also superseded.'),('dialogue-room-banks-gcc-v2','Superseded room_variant-to-room projection in both fixture and native loader.'),('dialogue-room-banks-llvm-v2','Same superseded room projection.'),('surface-follower-parents-gcc-v1','Owned SessionDialogue fixture lacked controlled script channel setup.'),('surface-follower-parents-llvm-v1','Same fixture setup failure; all34 CTests passed.')]:
        path=ROOT/'build-native-sjuni'/directory/'receipt.json'
        if path.is_file():retained.append(dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),reason=reason))
    result=dict(schema=1,status='qualified_native_dialogue_room_banks_and_session_owner',stage4_complete=False,game_run=False,audio_device_opened=False,source_sha256={name:sha(ROOT/name)for name in owned+helpers+[source]},owned_cmake_fragments=fragments,results=results,receipts=receipts,immutable_snapshot_refresh=provenance,finish_caller_audit=parent_audit,retained_diagnostic_evidence=retained,limits=['Only real1D41F0 child at5EB720 is explicitly adopted; complete5EB6D0 finish remains a required owner.','Current owned application fixture proves canonical inactive-actor frame/worker, I/O, timer and lifetime composition; active actor/physics services remain explicit providers.','Scene front/priority text banks and final font rendering are separate reached owners.','Reset models all consumed native roles; original unused DC4/DC6 bytes and unused header words have no fabricated native state.'])
    target=ROOT/'tools/native_reconstruction/native_dialogue_room_banks_qualification_v1.json';target.write_text(json.dumps(result,indent=2)+'\n');print(result['status'])
if __name__=='__main__':main()
