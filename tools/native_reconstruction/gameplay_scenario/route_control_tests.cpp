#include "game/native/gameplay_scenario/scene_controls.hpp"
#include "game/native/gameplay_scenario/saved_controls.hpp"
#include "original_fixture.hpp"
#include "original_declarations.inc"
#include <iostream>
#include <vector>
#include <cstring>
#include <stdexcept>
namespace vm=reo::native::gameplay_scenario;
std::size_t checks{};void check(bool value){++checks;if(!value)throw std::runtime_error("Route owner comparison "+std::to_string(checks));}
#include "control_vm_fixture.inc"
int main()try{
    std::size_t invocations{};std::vector<std::uint8_t> ram(0x900000);
    for(unsigned profile=0;profile<16;++profile){
        ControlFixture controls(profile);const auto add=[&](vm::SceneControlBody body,std::uint32_t id,std::uint8_t enabled){controls.ids.push_back(*controls.owner.append({id,enabled,std::move(body)}));};
        add(vm::ControlTypeZero{1,2,3,4,vm::ControlRouteDestination{0xfedcba98,0x76543210}},7,0);
        add(vm::ControlTypeTwo{5,6,7,8,9,vm::ControlModelReference{0x87654321,0xabcdef01}},7,0xff);
        add(vm::ControlTypeZero{1,2,3,4,vm::ControlRouteDestination{0,0}},0x10000007,1);
        add(vm::ControlOther{0},8,0);add(vm::ControlOther{2},9,0xff);
        for(unsigned request=0;request<256;++request){
            controls.export_original(ram);R5900Context c;PS2Runtime runtime;SET_GPR_U32(&c,4,0x12340000u|request);SET_GPR_U32(&c,31,0xdeadbeef);o2_005819C0_0x5819c0(ram.data(),&c,&runtime);check(c.pc==0xdeadbeef);++invocations;
            const auto result=controls.owner.first_route(std::uint8_t(request));check(result.status==vm::ControlStatus::completed);const auto raw=GPR_U32(&c,2);check(bool(result.id)==bool(raw));
            if(result.id){const auto found=std::find(controls.ids.begin(),controls.ids.end(),*result.id);check(found!=controls.ids.end());check(raw==control_node+unsigned(found-controls.ids.begin())*control_stride);const auto current=controls.owner.get(*result.id);check(current&&current->authored_id==request);if(const auto* zero=std::get_if<vm::ControlTypeZero>(&current->body);zero&&zero->destination){check(zero->destination->room==fixture_read<std::uint32_t>(ram.data(),raw+0x44));check(zero->destination->edge==fixture_read<std::uint32_t>(ram.data(),raw+0x48));}}
        }
        controls.owner.enabled(true);const auto found=controls.owner.first_route(7);check(found.id.has_value());const auto id=*found.id;auto record=*controls.owner.get(id);auto& zero=std::get<vm::ControlTypeZero>(record.body);zero.destination=vm::ControlRouteDestination{0x01020304,0x8000ffff};check(controls.owner.replace(id,record)==vm::ControlStatus::completed);const auto reread=controls.owner.get(id);check(std::get<vm::ControlTypeZero>(reread->body).destination==zero.destination);check(controls.owner.erase(id)==vm::ControlStatus::completed);check(!controls.owner.get(id));const auto replacement=controls.owner.append(record);check(replacement&&*replacement!=id&&!controls.owner.get(id));check(controls.owner.first_route(7).id!=replacement);check(controls.owner.first_route(255,0).status==vm::ControlStatus::budget_exhausted);
        const auto absent=controls.owner.first_route(8);check(absent.id&&std::holds_alternative<vm::ControlOther>(controls.owner.get(*absent.id)->body));
        controls.owner.clear();check(!controls.owner.first_route(7).id);check(!controls.owner.get(*replacement));
    }
    std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"original_query_invocations\":"<<invocations<<",\"game_launched\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
