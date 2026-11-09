#include "game/native/gameplay_scenario/room_object_commands.hpp"
void test_room_object_commands(reo::native::gameplay_collision::room_objects::Owner&,reo::native::gameplay_collision::room_objects::InteractionOwner&,reo::native::gameplay_collision::room_objects::InteractionOwner::Lifetime&,const reo::native::gameplay_collision::ownership::Proxies&);
#define REO_ROOM_OBJECT_COMMANDS_TEST
#define main qualified_model_lifetime_entry
#include "scene_model_lifetime_tests.cpp"
#undef main
unsigned command_rooms{},command_moves{},command_live_moves{},command_noop_moves{};
void test_room_object_commands(r::Owner& owner,r::InteractionOwner& interactions,r::InteractionOwner::Lifetime& life,const c::ownership::Proxies& proxies){
    namespace vm=reo::native::gameplay_scenario;
    ++command_rooms;vm::RoomObjectCommands commands(owner,life);check(commands.ready(true),"canonical complete move consumer available");
    vm::RoomObjectCommands producer_only(owner);check(!producer_only.ready(true),"bare object coordinate mutator is not complete C4 consumer");
    r::Owner foreign;vm::RoomObjectCommands wrong(foreign,life);check(!wrong.ready(true)&&!wrong.move(3,1,1),"foreign canonical owner refused before writes");
    const auto* grid=owner.grid();check(grid&&grid->width>0&&grid->depth>0,"stock object grid domain");
    const auto source_move=[&](std::uint32_t external,std::uint32_t x,std::uint32_t z){ref_write(memory.data(),0x1000,external);ref_write(memory.data(),0x1004,x);ref_write(memory.data(),0x1008,z);check(invoke(0x690c40,0x1000)==0,"complete original C4 returns zero");};
    for(const auto& id:owner.objects()){
        const auto* object=owner.get(id);const auto external=object->external_id;if(external>=32)continue;
        const auto old_x=std::uint8_t(object->x),old_z=std::uint8_t(object->z);
        for(unsigned i=0;i<4;++i){
            const auto x=std::uint8_t((i*7u)%unsigned(grid->width)),z=std::uint8_t((i*11u)%unsigned(grid->depth));
            check(commands.move(external,x,z),"native full move preserves admissible publication");source_move(0x12340000u|external,0xabcd0000u|x,0x76540000u|z);
            // This intentionally tests active first-match semantics, not the
            // inactive-slot shadow rule used by separate enable/disable paths.
            for(const auto& first:owner.objects())if(owner.get(first)->external_id==external){initialized_centers.insert(*interactions.source_ordinal(first));command_live_moves+=bool(owner.get(first)->instance);break;}
            compare(owner,interactions,life,proxies);++command_moves;
        }
        check(commands.move(external,old_x,old_z),"restore source coordinates through real consumer");source_move(external,old_x,old_z);compare(owner,interactions,life,proxies);++command_moves;
    }
    for(const auto external:{32u,127u,128u,255u}){check(commands.move(std::uint8_t(external),0,0),"out-of-profile unsigned external is source no-op");source_move(external,0,0);compare(owner,interactions,life,proxies);++command_noop_moves;}
    for(const auto x:{unsigned(grid->width),127u,128u,255u}){check(commands.move(0,std::uint8_t(x),0),"unsigned coordinate admission rejects with source zero");source_move(0,x,0);compare(owner,interactions,life,proxies);++command_noop_moves;}
}
int main(int argc,char** argv){const int result=qualified_model_lifetime_entry(argc,argv);if(result)return result;
    check(command_rooms==35&&command_moves>0&&command_live_moves>0&&command_noop_moves>0,"all legacy/real stock and declared variant command cases executed");
    std::printf("{\"status\":\"passed\",\"checks\":%u,\"command_rooms\":%u,\"moves\":%u,\"live_instance_moves\":%u,\"noop_moves\":%u,\"game_launched\":false}\n",checks,command_rooms,command_moves,command_live_moves,command_noop_moves);return 0;
}
