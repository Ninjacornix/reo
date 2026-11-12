"""Seal the owned cinematic speech lookup, preparation and real caller path."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()
def main():
 sources=['game/native/gameplay_scenario/cutscene_actor_speech.hpp','game/native/gameplay_scenario/cutscene_actor_speech.cpp','game/native/gameplay_scenario/cutscene_actor_speech_assets_tests.cpp','game/native/gameplay_scenario/cutscene_playback.hpp','game/native/gameplay_scenario/cutscene_playback.cpp','game/native/gameplay_scenario/CMakeLists.txt','tools/native_reconstruction/cinematic_speech_lookup_tests.cpp','tools/native_reconstruction/verify_cinematic_speech_lookup.py','tools/native_reconstruction/cutscene_actor_speech_tests.cpp','tools/native_reconstruction/verify_cutscene_actor_speech.py','tools/native_reconstruction/qualify_cutscene_actor_speech_v1.py','docs/native-gameplay/CUTSCENE_ACTOR_SPEECH.md'];current={name:sha(ROOT/name)for name in sources};loaded=[];receipts={}
 for role,pattern in [('lookup_preparation','cinematic-speech-lookup-{}-v4'),('owner_caller','cutscene-actor-speech-{}-v6'),('current_parents_assets','session-resources-parents-{}-v1')]:
  for compiler in ['llvm','gcc']:
   path=ROOT/'build-native-sjuni'/pattern.format(compiler)/'receipt.json';value=json.loads(path.read_bytes());assert value['status']=='passed'and not value.get('source_drift')and not value.get('owned_source_drift')
   for proof in value.get('original_owned_bodies',[]):assert proof['conflicts']==0 and proof['matched_comments']>0
   key=role+'_'+compiler;loaded.append((key,value));receipts[key]=dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),compiler_sha256=value['compiler_sha256'],observed=value.get('observed'),speech=value.get('speech'),parent_tests=value.get('parent_tests'),source_drift=value.get('source_drift',value.get('owned_source_drift')))
 matches={}
 for name,digest in current.items():
  if name.startswith('docs/')or name.endswith('qualify_cutscene_actor_speech_v1.py'):continue
  matches[name]=[key for key,value in loaded if value.get('source_sha256',{}).get(name)==digest];assert matches[name],name
 record=dict(schema=1,status='passed',scope='Sole Playback-owned cinematic speech frontend, actual fixed422-name lookup and source-ordered facial claim for5EEC50 opcode3.',game_run=False,device_opened=False,installed_in_game=False,stage4_complete=False,source_sha256=current,matching_qualified_snapshots=matches,receipts=receipts,limits=[
 'Complete original1ADB30,1AB2F0,1AB050 and string helpers execute; all422 positive controls and757 generated VO-name misses are checked. Complete1AB450/1AE7D0/1ADFD0/1AE6D0 with24 declared SDK primitives precede those checks and preserve the fixed table/string bytes. SDK archive/decoder implementations are not executed by this lookup/preparation cohort.',
 '77 actual descriptor request tuples use descriptor-header scenario, not archive context;22 cross-context rows differ. Owned typed requests cover693 suffix cases. Standard formatter and SDK sector-transfer primitives remain declared ports in the separate nineteen-entry actor/face comparison; the actual voice lookup executes.',
 'Controller owns a noncopyable bound adapter; unbound/foreign/reentrant operations refuse and borrowed access expires at unbind/destruction. Actual actor-track dispatch selects it before an external speech fallback and admits the original World-update traversal.',
 'The genuine fixed-catalogue miss completes the source call and continues facial claims without reporting queued/played audio. Unexpected positive VO lookups, arbitrary replacement tables and other locales remain unavailable rather than fabricated media behavior.',
 'Current31-parent CMake cohort also executes33 actual owned-clip caller/model paths without external speech. The unprovided later object callback is an explicit unavailable boundary; complete scene entry, movies/render publication and full cinematic/application lifecycle remain separate work.',
 ])
 path=ROOT/'tools/native_reconstruction/native_cutscene_actor_speech_qualification_v1.json';path.write_text(json.dumps(record,indent=2)+'\n');print(json.dumps(dict(status='passed',receipts=len(receipts),sources=len(sources),seal_sha256=sha(path))))
if __name__=='__main__':main()
