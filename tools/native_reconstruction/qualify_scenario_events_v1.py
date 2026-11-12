"""Seal exact countdown-event component, whole VM and real application checks."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
CORE=[f'game/native/gameplay_scenario/{name}{suffix}'for name in ['scenario_events','timer_hud']for suffix in ['.hpp','.cpp']]
CORE += [f'game/native/{group}/{name}{suffix}'for group,name in [('gameplay_tasks','events'),('gameplay_update','update'),('gameplay_scenario','interpreter')]for suffix in ['.hpp','.cpp']]
CORE += ['game/native/gameplay_application/native_session.cpp']
TOOLS=['tools/native_reconstruction/'+name for name in ['timer_hud_tests.cpp','verify_timer_hud.py','scenario_events_tests.cpp','verify_scenario_events.py','audit_scenario_opcode_frontier.py','qualify_scenario_events_v1.py']]
TOOLS += ['tools/native_reconstruction/gameplay_scenario/'+name for name in ['tests.cpp','verify.py','scenario_events_vm_tests.inc']]
def load(name):
    path=ROOT/'build-native-sjuni'/name/'receipt.json';data=json.loads(path.read_bytes());assert data['status']=='passed',name
    return dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path)),data
def main():
    evidence=[];observed=[]
    for cc in ['llvm','gcc']:
        hud,hd=load(f'timer-hud-{cc}-v1');events,ed=load(f'scenario-events-{cc}-v5');vm,vd=load(f'scenario-events-vm-{cc}-v2');admit,ad=load(f'scenario-events-admission-{cc}-v1');parents,pd=load(f'scenario-events-parents-{cc}-v1');lights,ld=load(f'scenario-events-lights-assets-{cc}-v3')
        assert hd['source_unchanged']and ed['source_unchanged']and not ed['source_drift']
        assert not ad['current_shared_source_drift']and not pd['source_drift']and not ld['source_drift']and pd['parent_tests']==28
        for name in CORE:
            assert vd['source_sha256'][name]==sha(ROOT/name),name
        for name in CORE[:4]:assert ed['source_sha256'][name]==sha(ROOT/name),name
        assert hd['observed']['checks']==8847393 and ed['observed']['checks']==224527
        assert vd['result']['checks']==569132415 and vd['result']['scenario_event_dispatches']==144
        assert ad['admitted']=={'before':[34,27],'after':[34,27]}
        assert ld['result']['assets']==548
        evidence.extend([hud,events,vm,admit,parents,lights]);observed.append(dict(compiler=cc,hud=hd['observed'],events=ed['observed'],vm={key:vd['result'][key]for key in ['checks','scenario_event_dispatches','scenario_event_refusals']},parent_tests=28,owned_light_assets=548))
    frontier,fd=load('scenario-events-frontier-v1');assert fd['totals'][0]['unsupported_instructions']==77 and len(fd['totals'][0]['counts'])==13;evidence.append(frontier)
    result=dict(schema='reo.native.scenario_events.qualification.v1',status='passed',source_sha256={name:sha(ROOT/name)for name in CORE+TOOLS+['docs/native-gameplay/SCENARIO_EVENTS.md','docs/native-gameplay/STAGE4_INTEGRATION_AUDIT.md']},evidence=evidence,observed=observed,
        installed_in_game=False,game_launched=False,device_opened=False,stage4_complete=False,limitations=['Only actual owned D1 kind6 callback family is admitted; other generic event families and scenario-specificD0 remain unsupported.','HUD rendering emits typed CPU sprite packets; Stage5 texture/submission consumers remain outside this gameplay component.','All original CPU/register/RAM code is confined to offline comparison executables; production uses canonical typed owners.','Full application light/parent receipts retain their exact historical source identity. Later independent inherited-trail owner fixes require a new combined parent capture.','All five scenario EVBs still refuse complete admission; remaining ordinary static inventory is77 instructions across13 distinct opcodes.','Native terminal frame services, platform/input/transport/media adoption, semantic saves and installed gameV39 replacement remain required.'])
    path=ROOT/'tools/native_reconstruction/native_scenario_events_qualification_v1.json';path.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(dict(status='passed',seal=path.relative_to(ROOT).as_posix(),sha256=sha(path))))
if __name__=='__main__':main()
