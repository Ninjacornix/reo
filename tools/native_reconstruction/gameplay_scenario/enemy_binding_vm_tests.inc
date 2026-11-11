namespace {
namespace enemy_world = reo::native::gameplay_world;
std::size_t enemy_binding_calls{},enemy_binding_refusals{},body_priority_calls{},body_priority_refusals{};

template<class Visitor> void visit_enemy_actor(const enemy_world::Actor& actor,Visitor visit) {
    visit(2,actor.category);visit(3,actor.slot);visit(4,actor.motion_subtype);
    visit(0x38,actor.position.x);visit(0x3c,actor.position.y);visit(0x40,actor.position.z);
    for (unsigned index = 0; index < 4; ++index) visit(0x90+2*index,actor.orientation[index]);
    visit(0xb4,actor.model_scale.x);visit(0xb8,actor.model_scale.y);visit(0xbc,actor.model_scale.z);
    visit(0x199,actor.collision.body_priority);
    visit(0x544,actor.current);visit(0x546,actor.maximum);
    visit(0x54a,actor.contact_flags);visit(0x54d,actor.model_pose_class);visit(0x553,actor.movement_enabled);
    visit(0xaa8,actor.model_height_correction);
    visit(0xb98,actor.character);visit(0xb99,actor.motion_style);
    visit(0xb9c,actor.previous_motion_class);visit(0xb9e,actor.interaction_marker);
    visit(0xba0,actor.status);visit(0xba4,actor.auxiliary_status);
    if (actor.gauge_value) visit(0xbac,*actor.gauge_value);
    visit(0xbb0,actor.contact.probability_bonus);visit(0xbb4,actor.model_variant);
    visit(0xbb6,actor.gauge_modifier_one);visit(0xbb8,actor.gauge_modifier_two);
    visit(0xbba,actor.linked_model_variant);visit(0xbdc,actor.frame_value_a);
    visit(0xff0,actor.ai_control);
    if (!actor.enemy) return;
    const auto& enemy = *actor.enemy;
    visit(5,enemy.header_parameter);visit(0xb9a,enemy.owner_mode);
    visit(0xb9d,enemy.parameter_b9d);visit(0xb9f,enemy.phase);
    visit(0xba9,enemy.condition);visit(0xbaa,enemy.parameter_baa);
    visit(0xbcc,enemy.distance_parameters[0]);visit(0xbd0,enemy.distance_parameters[1]);
    visit(0xbda,enemy.initial_timer);
    for (unsigned index = 0; index < 4; ++index) visit(0xc20+index,enemy.control_state[index]);
    visit(0xc24,enemy.class_flags);visit(0xc25,enemy.target_pool);visit(0xc26,enemy.target_slot);
    visit(0xc27,enemy.parameters_c27_c28[0]);visit(0xc28,enemy.parameters_c27_c28[1]);
    visit(0xc2a,enemy.parameter_c2a);visit(0xc2b,enemy.parameter_c2b);visit(0xc2e,enemy.timer_c2e);
    visit(0xc84,enemy.behavior_mode);
    for (unsigned index = 0; index < 4; ++index) visit(0xc85+index,enemy.behavior_parameters[index]);
    visit(0xc89,enemy.score_parameters[0]);visit(0xc8a,enemy.score_parameters[1]);
    visit(0xc8c,enemy.score_masks[0]);visit(0xc90,enemy.score_masks[1]);
    visit(0x24,0x4a5c30u+0x10e0u*enemy.target.identifier);
}

void compare_enemy_binding(ActorFixture& fixture,const reo::native::gameplay_actors::EntityId& id,
                           const vm::EnemyDescriptor& record,std::vector<std::uint8_t>& ram) {
    constexpr std::uint32_t at = 0x70000,source = 0x80000;
    const auto actor = fixture.world.resolve(id);
    check(bool(actor));
    std::memset(ram.data()+at,0xa5,0xd90);
    std::array<bool,0xd90> described{};
    const auto project = [&](unsigned offset,auto value) {
        fixture_write(ram.data(),at+offset,value);
        std::fill_n(described.begin()+offset,sizeof(value),true);
    };
    visit_enemy_actor(*actor,project);
    const std::vector<std::uint8_t> before(ram.begin()+at,ram.begin()+at+0xd90);
    std::memset(ram.data()+source,0,96);
    visit_enemy(record,[&](unsigned offset,auto value) { fixture_write(ram.data(),source+offset,value); });
    fixture.export_original(ram);
    check(enemy_world::bind_enemy_record(fixture.world,id,record));
    invoke_npc_original(ram,o2_006BBDA0_0x6bbda0,{at,source,0,0});
    check(bool(actor->enemy));
    visit_enemy_actor(*actor,[&](unsigned offset,auto value) {
        check(std::memcmp(ram.data()+at+offset,&value,sizeof(value)) == 0);
        std::fill_n(described.begin()+offset,sizeof(value),true);
    });
    check(actor->enemy->target.kind == reo::native::gameplay_actors::ActorReference::Kind::primary);
    check(fixture_read<std::uint32_t>(ram.data(),at+0x1dc) == at+0xaec);
    std::fill_n(described.begin()+0x1dc,4,true);
    for (unsigned byte = 0; byte < before.size(); ++byte)
        if (!described[byte]) check(ram[at+byte] == before[byte]);
    fixture.compare_original(ram);
    ++enemy_binding_calls;
}

void body_priority_tests(std::vector<std::uint8_t>& ram) {
    ActorFixture fixture;
    auto actor = fixture.world.primary(0);
    constexpr std::uint32_t at = 0x70000;
    for (const auto mode : {0u,1u,2u,255u}) {
        fixture.world.mode = std::uint8_t(mode);
        ram[0x3243f2] = fixture.world.mode;
        for (const auto category : {0u,1u,2u,3u,255u}) {
            for (unsigned index = 0; index < 256; ++index) {
                for (unsigned ai = 0; ai < 2; ++ai) {
                    actor->category = std::uint8_t(category);
                    actor->slot = actor->character = std::uint8_t(index);
                    actor->ai_control = std::uint8_t(ai);
                    const bool available = category == 0 ? !ai || index < 8 : category != 2 || index < 62;
                    const auto result = enemy_world::actor_body_priority(fixture.world,*actor);
                    check(result.has_value() == available);
                    if (!available) { ++body_priority_refusals;continue; }
                    std::memset(ram.data()+at,0x5a,0xd90);
                    visit_enemy_actor(*actor,[&](unsigned offset,auto value) { fixture_write(ram.data(),at+offset,value); });
                    const std::vector<std::uint8_t> before(ram.begin()+at,ram.begin()+at+0xd90);
                    const auto original = invoke_npc_original(ram,o2_006EFAF0_0x6efaf0,{at,0,0,0});
                    check(*result == original);
                    check(std::memcmp(before.data(),ram.data()+at,before.size()) == 0);
                    ++body_priority_calls;
                }
            }
        }
    }
    check(fixture.world.close() == enemy_world::Status::completed);
    check(!enemy_world::actor_body_priority(fixture.world,*actor));
    ++body_priority_refusals;
}

void enemy_binding_tests() {
    std::vector<std::uint8_t> ram(0x900000);
    owned_enemy_constants(ram.data());
    owned_enemy_binding_constants(ram.data());
    owned_linked_definition_constants(ram.data());
    body_priority_tests(ram);
    ActorFixture fixture;
    auto& pool = fixture.world.linked_models();
    const auto allocated = pool.allocate(true);
    check(allocated.status == enemy_world::LinkedStatus::completed);
    const auto actor = pool.resolve(allocated.id);
    actor->category = 2;
    vm::EnemyDescriptor record;
    constexpr std::array<std::int32_t,8> coordinates{INT32_MIN,INT32_MIN+1,-16777217,-1,0,1,16777217,INT32_MAX};
    for (unsigned trial = 0; trial < 4096; ++trial) {
        assertion_context = "Enemy binding trial="+std::to_string(trial);
        fixture.world.mode = std::array<std::uint8_t,4>{0,1,2,255}[trial%4];
        fixture.world.selected_actor = std::uint8_t(trial*19);
        fixture.session->random.restore({std::uint16_t(trial*257u),std::uint16_t(trial*65521u),std::uint8_t(trial)});
        actor->slot = std::uint8_t(trial%62);
        actor->status = trial^0x76543210u;
        actor->auxiliary_status = trial^0x89abcdefu;
        actor->contact_flags = std::uint16_t(trial*65521u);
        actor->motion_style = std::uint8_t(trial*17);
        actor->orientation[3] = std::bit_cast<std::int16_t>(std::uint16_t(trial*313u));
        actor->gauge_modifier_one = std::uint16_t(trial*71u);
        actor->gauge_modifier_two = std::uint16_t(trial*97u);
        record.ordinal = std::uint8_t(trial*31);
        record.variant = actor->slot == 1 ? std::uint8_t(trial%100) : 0;
        record.health = std::bit_cast<std::int16_t>(std::uint16_t(trial*65521u));
        record.maximum = std::bit_cast<std::int16_t>(std::uint16_t(trial*32749u));
        record.actor_marker = std::bit_cast<std::int8_t>(std::uint8_t(trial*53u));
        record.orientation = {trial*1664525u,trial*1013904223u};
        for (unsigned index = 0; index < 3; ++index) {
            record.position[index] = coordinates[(trial+index)%coordinates.size()];
            record.linked_ids[index] = std::uint8_t(trial*(index*2+1));
        }
        record.condition = std::uint8_t(trial*43);
        record.parameter1f = std::uint8_t(trial*71);
        record.parameter20 = std::uint8_t(trial*89);
        record.parameter5 = std::uint8_t(trial*97);
        record.parameter21 = std::bit_cast<std::int8_t>(std::uint8_t(trial*131));
        record.owner_mode = std::uint8_t(trial*151);
        record.parameter23 = std::uint8_t(trial*157);
        for (unsigned index = 0; index < 10; ++index) record.auxiliary_ids[index] = std::uint8_t(trial*17u+index*31u);
        record.target_selector = std::uint8_t(trial);
        record.parameter31 = std::uint8_t(trial*163);
        record.parameter32 = std::uint8_t(trial*173);
        for (unsigned index = 0; index < 13; ++index) record.parameters34_to40[index] = std::uint8_t(trial*181u+index*31u);
        for (unsigned index = 2; index < 6; ++index) record.parameters34_to40[index] = std::uint8_t((trial>>(index-2))&7u);
        record.timing_profile = std::uint8_t(trial&7u);
        record.parameters42_to43 = {std::uint8_t(trial*191),std::uint8_t(trial*193)};
        record.parameter48 = std::uint8_t(trial*197);
        compare_enemy_binding(fixture,allocated.id,record,ram);
        check(pool.remaining() == 49);
    }
    const auto fingerprint = [&] {
        std::vector<std::uint8_t> bytes(0xd90);
        visit_enemy_actor(*actor,[&](unsigned offset,auto value) { fixture_write(bytes.data(),offset,value); });
        return bytes;
    };
    for (unsigned refusal = 0; refusal < 10; ++refusal) {
        assertion_context = "Enemy binding refusal="+std::to_string(refusal);
        auto invalid = record;
        if (refusal < 4) invalid.parameters34_to40[2+refusal] = 8;
        if (refusal == 4) invalid.timing_profile = 8;
        if (refusal == 5) invalid.variant = 255;
        if (refusal == 6) actor->slot = 62;
        if (refusal == 7) actor->category = 1;
        const auto before = fingerprint();
        const auto random = fixture.session->random.state();
        const auto id = refusal == 8 ? fixture.world.identity(0) : refusal == 9 ? reo::native::gameplay_actors::EntityId{} : allocated.id;
        check(!enemy_world::bind_enemy_record(fixture.world,id,invalid));
        check(fingerprint() == before);
        check(fixture.session->random.state() == random);
        ++enemy_binding_refusals;
        actor->slot = std::uint8_t(4095%62);actor->category = 2;
    }
    ActorFixture foreign;
    check(!enemy_world::bind_enemy_record(foreign.world,allocated.id,record));
    auto unrelated = std::make_unique<enemy_world::Actor>();
    unrelated->category = 2;
    const auto unrelated_id = fixture.world.spawn_linked(std::move(unrelated));
    check(unrelated_id.status == reo::native::gameplay_actors::EntityStatus::completed);
    check(!enemy_world::bind_enemy_record(fixture.world,unrelated_id.id,record));
    check(pool.remaining() == 49);
    check(pool.reset() == enemy_world::LinkedStatus::completed);
    check(!enemy_world::bind_enemy_record(fixture.world,allocated.id,record));
    check(fixture.world.close() == enemy_world::Status::completed);
    check(!enemy_world::bind_enemy_record(fixture.world,allocated.id,record));
    enemy_binding_refusals += 4;
}
}
