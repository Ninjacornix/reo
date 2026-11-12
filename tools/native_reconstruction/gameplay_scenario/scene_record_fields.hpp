#pragma once
#include "game/native/gameplay_scenario/enemy_descriptors.hpp"
// Test-only semantic projection into the original expanded96-byte record.
// This is not native storage or a production save/wire format.
namespace scene_record_fixture {
template<class Visitor>void visit(const reo::native::gameplay_scenario::EnemyDescriptor& d,Visitor v){
    v(0,d.ordinal);v(1,d.actor_slot);v(2,d.family);v(3,d.variant);v(4,d.condition);v(5,d.parameter4);v(6,d.spawned);v(7,d.target_selector);
    for(unsigned i=0;i<2;++i)v(8+4*i,d.orientation[i]);
    for(unsigned i=0;i<3;++i)v(0x10+4*i,d.position[i]);
    v(0x1c,d.health);v(0x1e,d.maximum);v(0x20,d.parameters34_to40[6]);v(0x21,d.actor_marker);v(0x22,d.room);v(0x26,d.owner_mode);v(0x27,d.ordinal);
    v(0x29,d.parameter1f);v(0x2a,d.parameter20);v(0x2b,d.parameter5);v(0x2d,d.parameter23);v(0x2e,d.parameter2e);
    for(unsigned i=0;i<10;++i)v(0x2f+i,d.auxiliary_ids[i]);
    v(0x3a,d.parameter21);v(0x3c,d.route_wait);v(0x40,d.route_position);v(0x41,d.parameter24);v(0x42,d.route_seed);v(0x43,d.parameter25);v(0x44,d.parameter26);v(0x45,d.runtime_flags);v(0x46,d.parameter31);v(0x47,d.parameter32);
    for(unsigned i=0;i<13;++i)if(i!=6)v(i<6?0x48+i:0x47+i,d.parameters34_to40[i]);
    for(unsigned i=0;i<2;++i)v(0x55+i,d.parameters42_to43[i]);
    v(0x54,d.timing_profile);
    for(unsigned i=0;i<3;++i)v(0x57+i,d.linked_ids[i]);
    v(0x5a,d.parameter48);v(0x5b,d.choice_mask);v(0x5c,d.mapped_parameter);v(0x5d,d.route_selector);
}
}
