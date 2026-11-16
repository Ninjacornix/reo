#include "game/native/gameplay_world/animation_events.hpp"
#include "reference.hpp"
#include <fstream>
#include <iostream>
#include <vector>
namespace g = reo::native::gameplay_world;
namespace e = g::animation_events;
namespace a = reo::native::animation;
#include "functions.h"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#include "original.cpp"
#pragma GCC diagnostic pop
constexpr std::uint32_t actor_at = 0x100000;
std::uint64_t checks{}, cases{}, mutation_cases{}, family_cases{};
std::vector<e::Event> original_events;
std::vector<std::uint32_t> original_steps;
bool family_only{}, mutate{};
bool character_mode{};
std::uint32_t selected_target{};
void check(bool yes, const char* why) {
    ++checks;
    if (!yes)
        throw std::runtime_error(why);
}
e::EventKind kind(std::uint32_t address) {
    switch (address) {
        case 0x595b70:
            return e::EventKind::surface_pair_one;
        case 0x595c00:
            return e::EventKind::surface_pair_zero;
        case 0x595c90:
            return e::EventKind::actor_audio;
        case 0x595d30:
            return e::EventKind::alternate_audio;
        case 0x595dd0:
            return e::EventKind::resource_audio;
        case 0x595e30:
            return e::EventKind::resource_callback;
        case 0x595eb0:
            return e::EventKind::character_callback;
        case 0x595fa0:
            return e::EventKind::node_audio;
        case 0x596000:
            return e::EventKind::position_audio;
        case 0x596060:
            return e::EventKind::contact_action;
        case 0x596180:
            return e::EventKind::model_action;
        case 0x596470:
            return e::EventKind::resource_program;
        default:
            throw std::runtime_error("undeclared original event primitive");
    }
}
void original_transform_port(std::uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    const auto pc = ctx->pc;
    switch (pc) {
        case 0x573430:
            o2_00573430_0x573430(ram, ctx, runtime);
            return;
        case 0x5958b0:
            o2_005958B0_0x5958b0(ram, ctx, runtime);
            return;
        case 0x5959d0:
            o2_005959D0_0x5959d0(ram, ctx, runtime);
            return;
        case 0x5a8fd0:
            o2_005A8FD0_0x5a8fd0(ram, ctx, runtime);
            return;
        case 0x59fca0:
            o2_0059FCA0_0x59fca0(ram, ctx, runtime);
            return;
        case 0x5a04e0:
            o2_005A04E0_0x5a04e0(ram, ctx, runtime);
            return;
        default:
            break;
    }
    if (family_only) {
        selected_target = pc;
        ctx->pc = GPR_U32(ctx, 31);
        return;
    }
    switch (pc) {
        case 0x5965a0:
            o2_005965A0_0x5965a0(ram, ctx, runtime);
            return;
        case 0x59a820:
            o2_0059A820_0x59a820(ram, ctx, runtime);
            return;
        case 0x59ebb0:
            o2_0059EBB0_0x59ebb0(ram, ctx, runtime);
            return;
        case 0x5ec3e0:o2_005EC3E0_0x5ec3e0(ram,ctx,runtime);return;
        case 0x5baff0:o2_005BAFF0_0x5baff0(ram,ctx,runtime);return;
        case 0x5bb480:o2_005BB480_0x5bb480(ram,ctx,runtime);return;
        case 0x5bb780:o2_005BB780_0x5bb780(ram,ctx,runtime);return;
        case 0x5bbad0:o2_005BBAD0_0x5bbad0(ram,ctx,runtime);return;
        case 0x5ec7a0:o2_005EC7A0_0x5ec7a0(ram,ctx,runtime);return;
        case 0x5bbfa0:o2_005BBFA0_0x5bbfa0(ram,ctx,runtime);return;
        case 0x5bc380:o2_005BC380_0x5bc380(ram,ctx,runtime);return;
        default:
            break;
    }
    e::Event event{kind(pc), std::bit_cast<std::int32_t>(GPR_U32(ctx, 4))};
    switch (event.kind) {
        case e::EventKind::surface_pair_one:
        case e::EventKind::surface_pair_zero:
        case e::EventKind::node_audio:
        case e::EventKind::position_audio:
        case e::EventKind::resource_program:
            event.argument = GPR_U32(ctx, 6);
            break;
        case e::EventKind::actor_audio:
        case e::EventKind::alternate_audio:
        case e::EventKind::contact_action:
            event.argument = GPR_U32(ctx, 6);
            event.auxiliary = GPR_U32(ctx, 7);
            break;
        case e::EventKind::resource_audio:
            event.auxiliary = GPR_U32(ctx, 7);
            break;
        case e::EventKind::resource_callback:
        case e::EventKind::character_callback:
            break;
        case e::EventKind::model_action:
            event.argument = GPR_U32(ctx, 6);
            event.auxiliary = GPR_U32(ctx, 7);
            event.profile = GPR_U32(ctx, 8);
            break;
    }
    original_events.push_back(event);
    original_steps.push_back(std::bit_cast<std::uint32_t>(ctx->f[12]));
    if (mutate && original_events.size() == 1) {
        ram[actor_at + 2] = 0;
        ram[actor_at + 0x54f] = 0x39;
        transform_write(ram, actor_at + 0x212, std::uint16_t(0xf2));
        transform_write(ram, actor_at + 0xca8, std::uint16_t(4));
        if(character_mode){ram[actor_at+9]=15;transform_write(ram,actor_at+0x1f2,std::uint16_t(378));}
    }
    ctx->pc = GPR_U32(ctx, 31);
}
struct Consumer final : e::Consumer {
    std::vector<e::Event> events;
    std::vector<std::uint32_t> steps;
    bool mutation{}, replace{};
    void apply(g::Actor& actor, const e::Event& event, float step) override {
        events.push_back(event);
        steps.push_back(std::bit_cast<std::uint32_t>(step));
        if (mutation && events.size() == 1) {
            actor.category = 0;
            actor.motion_class = 0x39;
            actor.animation->channel(a::ModelBank::primary, 1).selector = 0xf2;
            actor.resource_action = 4;
            if(character_mode){actor.secondary=15;actor.animation->channel(a::ModelBank::primary,0).selector=378;}
        }
        if (replace)
            actor.animation.reset();
    }
};
R5900Context call(std::vector<std::uint8_t>& ram, std::uint32_t address, float step) {
    R5900Context ctx;
    PS2Runtime runtime;
    ctx.pc = address;
    SET_GPR_U32(&ctx, 4, actor_at);
    SET_GPR_U32(&ctx, 29, 0x1f00000);
    SET_GPR_U32(&ctx, 31, 0xabcdef);
    ctx.f[12] = step;
    original_transform_port(ram.data(), &ctx, &runtime);
    check(ctx.pc == 0xabcdef && GPR_U32(&ctx, 29) == 0x1f00000, "full original caller return");
    return ctx;
}
std::uint32_t address(e::Family f) {
    switch (f) {
        case e::Family::none:
            return 0;
        case e::Family::player_zero:
            return 0x5965a0;
        case e::Family::player_one:
            return 0x59a820;
        case e::Family::civilian_two:
            return 0x5ec3e0;
        case e::Family::civilian_three:
            return 0x5baff0;
        case e::Family::civilian_four:
            return 0x5bb480;
        case e::Family::civilian_five:
            return 0x5bb780;
        case e::Family::civilian_six:
            return 0x5bbad0;
        case e::Family::civilian_seven:
            return 0x5ec7a0;
        case e::Family::civilian_eight:
            return 0x5bbfa0;
        case e::Family::civilian_nine:
            return 0x5bc380;
        case e::Family::civilian_ten:
            return 0x5a06f0;
        case e::Family::extended_zero:
            return 0x59f610;
        case e::Family::extended_one:
            return 0x59f660;
        case e::Family::extended_two:
            return 0x59fb50;
        case e::Family::extended_twelve:
            return 0x59fcb0;
        case e::Family::extended_sixteen:
            return 0x59fd00;
        case e::Family::extended_eighteen:
            return 0x59fd80;
        case e::Family::extended_twenty:
            return 0x59fee0;
        case e::Family::extended_twenty_two:
            return 0x59ff30;
        case e::Family::extended_twenty_six:
            return 0x5a0210;
        case e::Family::extended_twenty_seven:
            return 0x5a0280;
        case e::Family::extended_twenty_nine:
            return 0x5a0420;
        case e::Family::extended_thirty_six:
            return 0x5a04f0;
        case e::Family::extended_forty_three:
            return 0x5a05d0;
        case e::Family::actor_zero:
            return 0x651350;
        case e::Family::actor_one:
            return 0x685530;
        case e::Family::actor_two:
            return 0x6509a0;
        case e::Family::actor_four:
            return 0x6c4550;
        case e::Family::actor_five:
            return 0x633030;
        case e::Family::actor_six:
            return 0x6cbf60;
        case e::Family::actor_seven:
            return 0x6d3e80;
        case e::Family::actor_nine:
            return 0x615c30;
        case e::Family::actor_ten:
            return 0x5af340;
        case e::Family::actor_eighteen:
            return 0x67d440;
        case e::Family::actor_nineteen:
            return 0x6c1610;
        case e::Family::actor_twenty:
            return 0x61c130;
        case e::Family::actor_twenty_two:
            return 0x60b600;
        case e::Family::actor_twenty_three:
            return 0x619a70;
        case e::Family::actor_twenty_six:
            return 0x6ce420;
        case e::Family::actor_twenty_seven:
            return 0x6c3280;
        case e::Family::actor_twenty_nine:
            return 0x67ce70;
        case e::Family::actor_thirty:
            return 0x624ef0;
        case e::Family::actor_thirty_six:
            return 0x65dcb0;
        case e::Family::actor_forty_one:
            return 0x5e07f0;
        case e::Family::actor_forty_three:
            return 0x6f8900;
        case e::Family::actor_fifty_five:
            return 0x61bd70;
        case e::Family::actor_fifty_nine:
            return 0x6edd60;
    }
    throw std::runtime_error("unreviewed family");
}
int main(int argc, char** argv) try {
    check(argc == 3, "owned o2 and skeleton corpus required");
    std::vector<std::uint8_t> ram(0x2000000);
    {
        std::ifstream f(argv[1], std::ios::binary);
        f.read(reinterpret_cast<char*>(ram.data() + 0x570000), 0x1d3100);
        check(bool(f), "complete original overlay");
    }
    std::shared_ptr<const a::Skeleton> skeleton;
    {
        std::ifstream f(argv[2], std::ios::binary);
        std::uint32_t count{}, size{};
        f.read(reinterpret_cast<char*>(&count), 4);
        f.read(reinterpret_cast<char*>(&size), 4);
        check(count == 2 && size < 0x400000, "owned skeleton corpus envelope");
        std::vector<std::byte> raw(size);
        f.read(reinterpret_cast<char*>(raw.data()), size);
        check(bool(f), "complete owned skeleton");
        skeleton = a::Skeleton::import_raw(raw);
    }
    g::Actor actor;
    actor.model = std::make_shared<a::Instance>(skeleton);
    actor.animation = std::make_shared<a::Playback>(actor.model);
    e::File1Metadata metadata;
    Consumer consumer;
    for (unsigned i = 0; i < 64; ++i) {
        check(metadata.action_flags(std::uint16_t(i)) ==
                  transform_read<std::uint32_t>(ram.data(), 0x719a60 + 68 * i),
              "actual action metadata flags");
        check(metadata.contact_id(std::uint16_t(i)) == ram[0x719a66 + 68 * i],
              "actual action metadata contact");
    }
    for (unsigned family = 0; family < 2; ++family)
        for (unsigned selector = 0; selector < 65536; ++selector)
            for (unsigned variant = 0; variant < 8; ++variant) {
                actor.category = (variant & 1) ? 0 : 1;
                actor.motion_class = (variant & 2) ? 0x39 : 0;
                actor.resource_action = std::uint16_t((variant & 4) ? 4 : 0);
                const auto lower = std::uint16_t(selector * 73u + variant * 17u);
                actor.animation->channel(a::ModelBank::primary, 0).selector = lower;
                actor.animation->channel(a::ModelBank::primary, 1).selector =
                    std::uint16_t(selector);
                ram[actor_at + 2] = actor.category;
                ram[actor_at + 0x54f] = actor.motion_class;
                transform_write(ram.data(), actor_at + 0xca8, actor.resource_action);
                transform_write(ram.data(), actor_at + 0x1f2, lower);
                transform_write(ram.data(), actor_at + 0x212, std::uint16_t(selector));
                const float step = variant % 4 == 0   ? -.5f
                                   : variant % 4 == 1 ? 0.f
                                   : variant % 4 == 2 ? .125f
                                                      : 2.5f;
                consumer.events.clear();
                consumer.steps.clear();
                original_events.clear();
                original_steps.clear();
                mutate = false;
                consumer.mutation = false;
                call(ram, family ? 0x59a820 : 0x5965a0, step);
                e::run_player(family ? e::Family::player_one : e::Family::player_zero, actor,
                              metadata, consumer, step);
                check(consumer.events == original_events,
                      "complete normal player event schedule/order/arguments");
                check(consumer.steps == original_steps,
                      "every primitive receives exact original step");
                ++cases;
            }
    for (unsigned family = 0; family < 2; ++family)
        for (unsigned selector = 0; selector < 1024; ++selector) {
            actor.category = 1;
            actor.motion_class = 0;
            actor.resource_action = 0;
            actor.animation->channel(a::ModelBank::primary, 0).selector = std::uint16_t(selector);
            actor.animation->channel(a::ModelBank::primary, 1).selector = std::uint16_t(selector);
            ram[actor_at + 2] = 1;
            ram[actor_at + 0x54f] = 0;
            transform_write(ram.data(), actor_at + 0xca8, std::uint16_t(0));
            transform_write(ram.data(), actor_at + 0x1f2, std::uint16_t(selector));
            transform_write(ram.data(), actor_at + 0x212, std::uint16_t(selector));
            consumer.events.clear();
            consumer.steps.clear();
            original_events.clear();
            original_steps.clear();
            mutate = true;
            consumer.mutation = true;
            call(ram, family ? 0x59a820 : 0x5965a0, .75f);
            e::run_player(family ? e::Family::player_one : e::Family::player_zero, actor, metadata,
                          consumer, .75f);
            check(consumer.events == original_events && consumer.steps == original_steps,
                  "fresh selectors and late canonical fields after mutable consumer");
            ++mutation_cases;
        }
    character_mode=true;
    for(unsigned family=0;family<8;++family){
        const auto selected=static_cast<e::Family>(unsigned(e::Family::civilian_two)+family);
        for(unsigned selector=0;selector<65536;++selector)for(unsigned variant=0;variant<4;++variant){
            actor.secondary=(variant&1)?15:0;
            const auto lower=std::uint16_t(selector*73u+variant*17u);
            actor.animation->channel(a::ModelBank::primary,0).selector=lower;
            actor.animation->channel(a::ModelBank::primary,1).selector=std::uint16_t(selector);
            ram[actor_at+9]=actor.secondary;transform_write(ram.data(),actor_at+0x1f2,lower);
            transform_write(ram.data(),actor_at+0x212,std::uint16_t(selector));
            consumer.events.clear();consumer.steps.clear();original_events.clear();original_steps.clear();
            mutate=consumer.mutation=(variant&2)!=0;
            const auto step=variant&1?.125f:-.5f;
            call(ram,address(selected),step);e::run_player(selected,actor,metadata,consumer,step);
            check(consumer.events==original_events&&consumer.steps==original_steps,
                  "complete character schedule, fresh lower selector and secondary state");
            ++cases;if(mutate)++mutation_cases;
        }
    }
    character_mode=false;
    family_only = true;
    mutate = false;
    for (unsigned category : {0u, 1u})
        for (unsigned kind = 0; kind < 256; ++kind)
            for (unsigned slot = 0; slot < 256; ++slot) {
                ram[actor_at + 2] = std::uint8_t(category);
                ram[actor_at + 0xce0] = std::uint8_t(kind);
                ram[actor_at + 0xce1] = std::uint8_t(slot);
                selected_target = 0;
                call(ram, 0x573430, 0);
                const auto native = e::family(std::uint8_t(category), false, 0, std::uint8_t(kind),
                                              std::uint8_t(slot));
                check(address(native) == selected_target,
                      "full573430 normal/extended family selection");
                ++family_cases;
            }
    for (unsigned category = 2; category < 256; ++category)
        for (unsigned slot = 0; slot < 256; ++slot)
            for (unsigned visible : {0u, 1u}) {
                ram[actor_at + 2] = std::uint8_t(category);
                ram[actor_at + 3] = std::uint8_t(slot);
                ram[actor_at + 1] = std::uint8_t(visible);
                selected_target = 0;
                call(ram, 0x573430, 0);
                check(address(e::family(std::uint8_t(category), visible != 0, std::uint8_t(slot), 0,
                                        0)) == selected_target,
                      "full573430 category2 visible-only family selection");
                ++family_cases;
            }
    consumer.replace = true;
    consumer.mutation = false;
    actor.animation->channel(a::ModelBank::primary, 0).selector = 65535;
    actor.animation->channel(a::ModelBank::primary, 1).selector = 243;
    bool refused{};
    try {
        e::run_player(e::Family::player_zero, actor, metadata, consumer, 1);
    } catch (const std::runtime_error&) {
        refused = true;
    }
    check(refused, "replaced animation owner refuses later schedule actions");
    bool unsupported{};
    try {
        e::run_player(e::Family::extended_one, actor, metadata, consumer, 1);
    } catch (const std::domain_error&) {
        unsupported = true;
    }
    check(unsupported, "unimplemented real event families refuse explicitly");
    std::cout << "{\"checks\":" << checks << ",\"schedule_cases\":" << cases
              << ",\"mutable_consumer_cases\":" << mutation_cases
              << ",\"family_cases\":" << family_cases << ",\"game_run\":false}\n";
} catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return 1;
}
