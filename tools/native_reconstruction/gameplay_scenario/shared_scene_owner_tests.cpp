#include "game/native/gameplay_scenario/scene_controls.hpp"
#include "game/native/gameplay_collision/ownership.hpp"
#include <iostream>
#include <stdexcept>

namespace sc=reo::native::gameplay_scenario;
namespace scene=reo::native::gameplay_scene;
namespace c=reo::native::gameplay_collision;
namespace o=c::ownership;
namespace actors=reo::native::gameplay_actors;
std::uint64_t checks{};
void check(bool value){++checks;if(!value)throw std::runtime_error("Canonical shared scene owner mismatch");}
struct Actor final:actors::Entity{};
int main(){
    for(unsigned episode=0;episode<256;++episode){
        auto records=std::make_shared<scene::Records>();sc::SceneControls controls(records);o::Proxies proxies(records);
        actors::EntityStore entities;const auto actor=entities.create(std::make_unique<Actor>());check(actor.status==actors::EntityStatus::completed);
        scene::Record original;original.authored_id=42;original.enabled=0x80;original.counter=2;
        sc::ControlTypeZero zero;zero.parameter=0x12345678;zero.destination=sc::ControlRouteDestination{7,11};
        zero.matrix_program=sc::ControlMatrixProgramResource{3,1,0x01020302};original.body=zero;
        original.collision=scene::CollisionShape{{c::Point{0,0},c::Point{100,0},c::Point{100,100},c::Point{0,100}},0,100,0,false,{}};
        original.other_resource_class=0xabcd;original.door=scene::DoorDetails{};
        const auto id=records->create(original);check(bool(id));
        check(proxies.ordered().size()==1&&proxies.ordered()[0]==*id);
        check(controls.first_route(42).id==id);
        const auto initial=proxies.get(*id);check(initial&&initial->geometry.active&&initial->geometry.priority==2);
        check(initial->door&&initial->door->destination_door==11&&initial->door->destination_room==7);
        const auto lease=proxies.acquire(*id);check(bool(lease));
        c::ActorQuery q;q.point={50,50,50};q.position=q.point;
        std::array<c::ProxyState,1> states;
        check(proxies.select(q,actor.id,states).has_value());
        auto disabled=controls.apply(sc::ControlCommand::disable_zero_two,{42},nullptr);
        check(disabled.matched==1&&!proxies.get(*id)->geometry.active);
        check(!proxies.select(q,actor.id,states)); // cached select rebuilt after VM activation
        auto native=*controls.get(*id);native.enabled=0x80;native.counter=7;
        std::get<sc::ControlTypeZero>(native.body).destination->edge=episode+19;
        check(controls.replace(*id,native)==sc::ControlStatus::completed);
        check(proxies.get(*id)->geometry.content_id==episode+19);
        check(proxies.get(*id)->door->destination_door==episode+19);
        check(proxies.get(*id)->geometry.priority==7&&proxies.select(q,actor.id,states).has_value());
        auto geometry=*proxies.get(*id);geometry.geometry.bounds[1].x=125;geometry.geometry.priority=17;
        check(proxies.replace(*id,geometry));native=*controls.get(*id);
        check(native.enabled==0x80&&native.counter==17); // raw nonzero activation is retained
        check(std::get<sc::ControlTypeZero>(native.body).parameter==0x12345678);
        check(std::get<sc::ControlTypeZero>(native.body).matrix_program->resource_class==0x01020302);
        check(lease.canonical()->collision->bounds[1].x==125);
        check(controls.erase(*id)==sc::ControlStatus::completed);
        check(!controls.get(*id)&&!proxies.get(*id)&&!proxies.acquire(*id));
        const auto replacement=records->create(original);check(replacement&&*replacement!=*id);
        check(!records->acquire(*id)&&lease.canonical()->counter==17);
        check(records->acquire(*replacement)->value.counter==2);
        check(!proxies.retire(*id));
        sc::ControlTypeTwo two;two.model_reference=sc::ControlModelReference{9,12};two.matrix_resource_class=0x10002;
        auto record=original;record.body=two;record.door.reset();
        const auto second=records->create(record);check(bool(second));
        check(!proxies.get(*second)->geometry.bypass_slot_guard); // full word, not low byte
        record.body=two;std::get<sc::ControlTypeTwo>(record.body).matrix_resource_class=2;
        check(controls.replace(*second,record)==sc::ControlStatus::completed);
        check(proxies.get(*second)->geometry.bypass_slot_guard);
        check(proxies.get(*second)->geometry.content_id==12);
        auto missing=*controls.get(*second);std::get<sc::ControlTypeTwo>(missing.body).model_reference.reset();
        records->acquire(*second)->value.other_content=0xdeadbeef;records->touch();
        check(controls.replace(*second,missing)==sc::ControlStatus::completed);
        check(!records->acquire(*second)->value.other_content);
        check(!proxies.get(*second)->geometry.active&&proxies.get(*second)->geometry.content_id==0);

        controls.clear();check(proxies.size()==0&&records->size()==0);
        for(unsigned n=0;n<64;++n)check(bool(controls.append({n,1,sc::ControlOther{3},0})));
        for(unsigned n=0;n<64;++n)check(bool(proxies.create({})));
        check(!controls.append({})&&!proxies.create({})&&controls.size()==128&&proxies.size()==128);
        auto other=std::make_shared<scene::Records>();o::Proxies foreign(other);
        check(!foreign.get(*replacement));
    }
    std::cout<<"{\"checks\":"<<checks<<",\"status\":\"passed\",\"canonical_cross_consumer_cases\":256}\n";
}
