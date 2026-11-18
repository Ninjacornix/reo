"""Read-only provider diagnosis through untouched fresh application startup."""
import argparse,hashlib,json,os,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()

def main():
    p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--immutable-snapshot',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args()
    snapshot=a.immutable_snapshot.resolve();source=snapshot/'source';out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir()
    captured=json.loads((snapshot/'receipt.json').read_text());cohort=json.loads((snapshot/'cohort.json').read_text());assert captured['status']==cohort['status']=='passed'and sha(snapshot/'cohort.json')==captured['cohort_sha256']
    libs={n:sha(snapshot/'native-build'/n)for n in captured['archives_sha256']};assert libs==captured['archives_sha256']
    sources={n:sha(source/n)for n in captured['source_sha256']};assert sources==captured['source_sha256']
    assert sha(a.compiler.resolve())=='f1377bd9c4e35669930d0fb2ebdc51cac1d1f4ca16638c0ed0d77c113bc195d3'
    predicates={
        'needs_signals':'p.needs_signals()', 'has_signals':'bool(v.signals)',
        'needs_streams':'p.needs_streams()', 'has_streams':'bool(v.streams)', 'has_stream_backend':'bool(v.stream_backend)', 'has_stream_tick':'bool(host.update().state.audio_tick)',
        'needs_script_audio':'p.needs_script_audio()', 'has_script_audio':'bool(v.script_audio)',
        'room_counters':'p.admits_room_counters(&host.world())', 'counter_value4':'bool(host.world().session().room_contacts.counter_policy()->value(4))',
        'inventory_grants':'p.admits_inventory_grants(&host.world(),v.scene_resources,v.resource_templates)',
        'actor_roster':'p.admits_actor_roster(&host.world())', 'character_remap':'p.admits_character_remap(&host.world())',
        'script_audio':'p.admits_script_audio(v.script_audio,&host.world())',
        'scene_parameters':'p.admits_scene_record_parameters(&host.world(),v.messages)',
        'actor_commands':'p.admits_actor_script_commands(&host.world(),v.canonical_flags)',
        'resource_parameters':'p.admits_resource_parameter_commands(&host.world(),v.resource_parameters,v.scene_resources,v.resource_templates)',
        'resource_activation':'p.admits_resource_activation(v.resource_activation,&host.world(),v.scene_resources,v.resource_templates)',
        'events':'p.admits_scenario_events(v.scenario_events,&host.world())',
        'terminal':'p.admits_actor_script_terminal(v.actor_script_terminal,&host.world())',
        'actor_interaction':'p.admits_actor_interaction_commands(&host.world(),v.scene_resources)',
        'room_variants':'p.admits_offline_room_variants(&host.world())',
        'enemy_relocation':'p.admits_scenario_enemy_relocation(&host.world(),v.canonical_flags)',
        'timed_text':'p.admits_timed_scene_text(v.timed_scene_text,&host.world())',
        'difficulty':'p.admits_difficulty(&host.world())', 'inventory_ui':'p.admits_inventory_ui(v.inventory_ui,&host.world())',
        'actor_model_classes':'p.admits_actor_model_classes(&host.world())',
        'offline_inventory':'p.admits_offline_actor_inventory(v.actor_resource_operations,&host.world(),v.scene_resources,v.resource_templates)',
        'offline_navigation':'p.admits_actor_offline_navigation(v.actor_offline_navigation,&host.world(),&host.update().scripts())',
        'needs_periodic':'p.needs_periodic_effects()', 'has_periodic':'bool(v.periodic_effects)',
        'needs_surface':'p.needs_surface_effects()', 'has_surface':'bool(v.surface_effects)',
        'needs_objects':'p.needs_room_objects()', 'has_objects':'bool(v.room_objects)',
        'needs_forced_terminal':'p.needs_forced_terminal()', 'has_forced_terminal':'bool(v.forced_terminal)'}
    # Counter-policy getter is not needed to diagnose admission; use the public
    # room counter observation separately without manufacturing an initialized row.
    predicates.pop('counter_value4')
    chunk='if(executing){const auto& p=*executing;const auto v=(host.*provider_member(ProviderProbeTag{}))();std::cout<<"{\\"provider_report\\":true"'
    for name,expr in predicates.items():chunk+='<<",\\"'+name+'\\":"<<('+expr+'?"true":"false")'
    chunk+='<<"}\\n";\n'
    detail_fields={
        'room_actor_selectors_':('selector','s::actor_room_query_ready(host.world(),request)'),
        'actor_room_population_queries_':('room','s::actor_room_population_ready(host.world(),request)'),
        'actor_profile_requests_':('mode,selector,profile','s::actor_weight_profile_ready(host.world(),request.mode,request.selector,request.profile)'),
        'actor_condition_requests_':('mode,selector,query,parameter','s::actor_condition_matches(host.world(),v.canonical_flags,request.mode,request.selector,request.query,request.parameter,0).has_value()'),
        'actor_inhibition_requests_':('selector,value','s::actor_ai_inhibition_ready(host.world(),request.selector,request.value)'),
        'actor_forced_policy_selectors_':('selector','s::actor_forced_policy_ready(host.world(),request)'),
        'destination_policy_requests_':('room,variant,policy','s::actor_destination_policy_ready(host.world(),request.room,request.variant,request.policy)'),
        'offline_navigation_requests_':('selector,room,node','v.actor_offline_navigation&&v.actor_offline_navigation->command_ready(request.selector,request.room,request.node)')}
    for field,(names,expr) in detail_fields.items():
        chunk+='for(const auto& request:p.*program_field('+field+'Tag{})){std::cout<<"{\\"request\\":\\"'+field+'\\",\\"ready\\":"<<('+expr+'?"true":"false")'
        for name in names.split(','):
            value='request'if','not in names else'request.'+name
            chunk+='<<",\\"'+name+'\\":"<<'+value
        chunk+='<<"}\\n";}\n'
    chunk+='std::cout<<"{\\"actor_records\\":[";for(unsigned slot=0;slot<8;++slot){if(slot)std::cout<<",";const auto actor=host.world().primary(slot);std::cout<<"{\\"slot\\":"<<slot<<",\\"present\\":"<<(actor?"true":"false");if(actor)std::cout<<",\\"active\\":"<<(actor->active?"true":"false")<<",\\"ai\\":"<<unsigned(actor->ai_control)<<",\\"room\\":"<<actor->room<<",\\"execution\\":"<<(actor->ai_execution?"true":"false")<<",\\"route\\":"<<(actor->navigation_route?"true":"false");std::cout<<"}";}std::cout<<"]}\\n";}\n'
    inc=(source/'game/native/gameplay_application/fresh_startup_diagnostic.inc').read_text();anchor='    std::cout<<"{\\"diagnostic\\":';assert inc.count(anchor)==1;inc=inc.replace(anchor,'    '+chunk+anchor,1);(out/'fresh_startup_diagnostic.inc').write_text(inc)
    fixture=(source/'game/native/gameplay_application/session_startup_tests.cpp').read_text()
    shim='struct ProviderProbeTag {using type=s::Providers(app::NativeSession::*)()noexcept;friend type provider_member(ProviderProbeTag);};\ntemplate<class Tag,typename Tag::type Member>struct ProviderProbeAccess{friend typename Tag::type provider_member(Tag){return Member;}};\ntemplate struct ProviderProbeAccess<ProviderProbeTag,&app::NativeSession::providers>;\n'
    shim='#include "game/native/gameplay_scenario/actor_room_population.hpp"\n#include "game/native/gameplay_scenario/actor_ai_policy.hpp"\n#include "game/native/gameplay_scenario/actor_script_predicates.hpp"\n'+shim
    shim+='template<class Tag,auto Member>struct ProgramFieldAccess{friend auto program_field(Tag){return Member;}};\n'
    for field in detail_fields:shim+='struct '+field+'Tag{friend auto program_field('+field+'Tag);};\ntemplate struct ProgramFieldAccess<'+field+'Tag,&s::Program::'+field+'>;\n'
    fixture=fixture.replace('namespace {\nunsigned checks',shim+'namespace {\nunsigned checks',1)
    (out/'fixture.cpp').write_text(fixture)
    env=dict(os.environ,PATH=str(a.compiler.resolve().parent)+os.pathsep+os.environ.get('PATH',''));commands=[]
    def run(label,command):
        done=subprocess.run(command,env=env,cwd=ROOT,capture_output=True,timeout=240);(out/(label+'.stdout.txt')).write_bytes(done.stdout);(out/(label+'.stderr.txt')).write_bytes(done.stderr);commands.append(dict(label=label,command=command,returncode=done.returncode));assert done.returncode==0,done.stderr.decode(errors='replace')[-3500:];return done.stdout
    receipt=dict(status='failed',scope='Actual untouched startup provider observations after execution returns; transient startup guards have been released. Startup/frame completion is reported only by the actual diagnostic.',commands=commands,archives_only=True,native_library_sha256=libs,source_sha256=sources,driver_sha256=sha(Path(__file__)),cohort_sha256=captured['cohort_sha256'],compiler_sha256=sha(a.compiler.resolve()))
    try:
        run('compile',[str(a.compiler.resolve()),'-std=c++20','-O2','-fno-fast-math','-ffp-contract=off','-Wall','-Wextra','-Wpedantic','-Werror','-I'+str(source),'-I'+str(source/'game/native/gameplay_application'),'-c',str(out/'fixture.cpp'),'-o',str(out/'fixture.o')])
        run('link',[str(a.compiler.resolve()),str(out/'fixture.o'),'-Wl,--start-group',*[str(snapshot/'native-build'/n)for n in libs],'-Wl,--end-group','-lgdi32','-ldxgi','-luuid','-lxinput','-luser32','-lpthread','-lole32','-loleaut32','-lwinspool','-lshell32','-lcomdlg32','-ladvapi32','-o',str(out/'probe.exe')])
        case=next(x for x in cohort['commands']if x['label']=='session-startup-owned');raw=run('test',[str(out/'probe.exe'),*case['command'][1:4],'--fresh-startup-diagnostic'])
        receipt['observed']=[json.loads(line)for line in raw.decode(errors='replace').splitlines()if line.startswith('{')];assert any(x.get('provider_report')for x in receipt['observed'])
        assert all(sha(snapshot/'native-build'/n)==h for n,h in libs.items());assert all(sha(source/n)==h for n,h in sources.items());receipt['status']='passed';print(json.dumps(dict(status='passed',observations=len(receipt['observed']),failed_requests=[x for x in receipt['observed']if x.get('request')and not x['ready']],diagnostic=next(x for x in receipt['observed']if x.get('diagnostic')))))
    finally:(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
if __name__=='__main__':main()
