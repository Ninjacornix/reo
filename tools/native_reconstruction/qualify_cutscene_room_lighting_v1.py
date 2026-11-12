"""Seal the reached room LIG/FOG loader and current application adoption."""
import hashlib
import json
import re
from pathlib import Path
from audit_retail_effect_descriptors import compare_source

ROOT=Path(__file__).resolve().parents[2]
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    sources=['game/native/gameplay_scenario/'+name for name in [
        'cutscene_lights.hpp','cutscene_lights.cpp','cutscene_room_lighting.cpp','CMakeLists.txt',
    ]]+['tools/native_reconstruction/'+name for name in [
        'cutscene_room_lighting_tests.cpp','cutscene_room_lighting_assets_tests.cpp',
        'verify_cutscene_room_lighting.py','qualify_cutscene_room_lighting_v1.py',
    ]]+['docs/native-gameplay/CUTSCENE_ROOM_LIGHTING.md']
    current={name:sha(ROOT/name)for name in sources};receipts={};loaded=[]
    for role,pattern in [
        ('original','cutscene-room-lighting-{}-v4'),
        ('current_assets','inventory-ui-room-lighting-assets-{}-v1'),
        ('current_parents','inventory-ui-parents-{}-v2'),
    ]:
        for compiler in ['llvm','gcc']:
            path=ROOT/'build-native-sjuni'/pattern.format(compiler)/'receipt.json';value=json.loads(path.read_text());assert value['status']=='passed';assert value.get('source_unchanged',True);assert not value.get('source_drift')and not value.get('owned_source_drift')
            for proof in value.get('original_owned_bodies',[]):assert proof['conflicts']==0 and proof['matched_comments']>0
            key=role+'_'+compiler;loaded.append((key,value));receipts[key]=dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),compiler_sha256=value['compiler_sha256'],observed=value.get('observed',value.get('result')),parent_tests=value.get('parent_tests'),source_drift=value.get('source_drift',value.get('owned_source_drift')))
    matches={}
    for name,expected in current.items():
        if name.startswith('docs/')or name.endswith('qualify_cutscene_room_lighting_v1.py'):continue
        matches[name]=[role for role,value in loaded if value.get('source_sha256',{}).get(name)==expected];assert matches[name],name
    overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';data=overlay.read_bytes();caller='recomp/config/output_ovl/o2/o2_005ECF90_0x5ecf90.cpp';start,end=[int(value,16)for value in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',(ROOT/caller).read_text()).groups()];authority=compare_source('static actual5ECF90 caller;1D4870 call at5ED07C, enclosing native lifecycle still open',caller,start,end,lambda at,n:data[at-0x570000:at-0x570000+n]);assert authority['conflicts']==0
    record=dict(schema=1,status='passed',scope='Complete1D4870 composed room lighting/fog read/import/finalization over the existing canonical light worker, including version4LIG cross-owner fog-selection invalidation.',game_run=False,device_opened=False,installed_in_game=False,stage4_complete=False,source_sha256=current,matching_qualified_snapshots=matches,receipts=receipts,caller_static_authority=authority,limits=[
        'Private whole-helper comparison uses exact immutable SessionRooms v6 native archives and matching headers; current Lighting/Fog/ScenarioArchive/new light units override their prior archive units without public layout changes. Current-assets and parent28 receipts separately establish the current application ABI/link closure.',
        'All1342 default encoded keys and six authored_Htables are exercised. Original1AA1E0 selected descriptor metadata is a fixture derived from those actual tables; SDK task allocation/actual-sector transfer/completion/close and bounded standard string/format primitives are explicit seams. Complete actual namespace/name resolvers, size getters, import/math/pool bodies execute.',
        '380 physical LIG/FOG members establish369 filenames reachable through this caller grammar. The old-suffix FOG and ten common files need their different actual callers; presence alone is not reachability.',
        'Lighting owns the physical-light subset of6B1DC0. The reached loader applies its canonical Fog selection reset; other unconsumed cleared renderer words remain a renderer adoption boundary. Finite nearest-rounding numeric profile only.',
        'Complete5ECF90 and its remaining model/facial/render/reset/merge services, full scene transitions and actual session/game installation remain open. No successful missing provider is substituted.',
    ])
    destination=ROOT/'tools/native_reconstruction/native_cutscene_room_lighting_qualification_v1.json';destination.write_text(json.dumps(record,indent=2)+'\n');print(json.dumps(dict(status='passed',receipts=len(receipts),sources=len(sources),seal_sha256=sha(destination))))


if __name__=='__main__':main()
