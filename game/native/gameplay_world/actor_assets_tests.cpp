#include "actor_assets.hpp"
#include "../animation/playback.hpp"
#include "../animation/constraints.hpp"
#include "../gameplay_update/scripted_actor_construction.hpp"
#include "runtime/assets/virtual_afs.h"
#include <atomic>
#include <fstream>
#include <future>
#include <iostream>
#include <source_location>
#include <sstream>

namespace world = reo::native::gameplay_world;
namespace {
std::size_t checks{},refusals{},owned_models{},owned_skeletons{},owned_absent_skeletons{},owned_absent_models{},owned_missing{};
std::size_t model_bindings{},binding_refusals{};
std::size_t scripted_constructions{},owned_scripted_constructions{},constructor_profile_refusals{};

void check(bool condition,std::source_location at = std::source_location::current()) {
    ++checks;
    if (!condition) throw std::runtime_error("Native actor asset check at "+std::to_string(at.line()));
}
template<class T> void put(std::vector<std::uint8_t>& bytes,std::size_t at,T value) {
    check(at <= bytes.size() && sizeof(value) <= bytes.size()-at);
    std::memcpy(bytes.data()+at,&value,sizeof(value));
}
template<class Action> void refused(Action action) {
    bool caught = false;
    try { action(); } catch (const std::exception&) { caught = true; }
    check(caught);
    ++refusals;
}

std::vector<std::uint8_t> bundle(bool skeleton = true) {
    std::vector<std::uint8_t> bytes(48+112);
    if (!skeleton) return bytes;
    put(bytes,0x24,48u);put(bytes,0x28,112u);
    put(bytes,48+4,2u);put(bytes,48+8,112u);
    put(bytes,60+4,1u);put(bytes,60+8,16u);put(bytes,60+12,0u);
    put(bytes,76,1u);put(bytes,76+4,1u);put(bytes,76+8,84u);
    const auto node = 88u;
    put(bytes,node+8,0xffffffffu);put(bytes,node+12,0xffffffffu);
    for (unsigned lane = 0; lane < 3; ++lane) put(bytes,node+0x10+4*lane,1.f);
    bytes.resize(184);
    put(bytes,0x14,160u);put(bytes,0x18,24u);
    put(bytes,160+4,1u);put(bytes,160+8,24u);
    put(bytes,172,2u);put(bytes,172+4,3u);put(bytes,172+8,12u);
    return bytes;
}

using File = std::pair<std::string,std::vector<std::uint8_t>>;
std::vector<std::uint8_t> afs(std::vector<File> files) {
    check(!files.empty());
    const auto aligned = [](std::size_t size) { return (size+2047u)&~std::size_t(2047u); };
    const auto names = 16+8*files.size();
    std::vector<std::uint8_t> bytes(aligned(names+48*files.size()));
    std::memcpy(bytes.data(),"AFS\0",4);put(bytes,4,std::uint32_t(files.size()));
    put(bytes,8+8*files.size(),std::uint32_t(names));
    put(bytes,12+8*files.size(),std::uint32_t(48*files.size()));
    for (std::size_t index = 0; index < files.size(); ++index) {
        auto& [name,payload] = files[index];
        check(name.size() < 32);
        std::memcpy(bytes.data()+names+48*index,name.data(),name.size());
        const auto offset = bytes.size();
        bytes.resize(aligned(offset+payload.size()));
        put(bytes,8+8*index,std::uint32_t(offset));
        put(bytes,12+8*index,std::uint32_t(payload.size()));
        std::memcpy(bytes.data()+offset,payload.data(),payload.size());
    }
    return bytes;
}

struct Memory final : reo::assets::PositionedSource {
    const std::vector<std::uint8_t> bytes;
    mutable std::atomic<unsigned> reads{},failures{};
    explicit Memory(std::vector<std::uint8_t> input) : bytes(std::move(input)) {}
    std::uint64_t size() const noexcept override { return bytes.size(); }
    std::size_t read(std::uint64_t offset,std::size_t length,void* output) const override {
        ++reads;
        if (failures.load() && offset == 4096) { --failures;throw std::runtime_error("Injected asset read failure"); }
        if (offset > bytes.size() || length > bytes.size()-offset) throw std::runtime_error("Fixture asset extent");
        std::memcpy(output,bytes.data()+offset,length);
        return length;
    }
};
std::shared_ptr<reo::assets::Source> source(std::vector<File> files) {
    return std::make_shared<reo::assets::Source>("native actor asset fixture",
        std::make_shared<Memory>(afs({{"romdata_usa.afs",afs(std::move(files))}})));
}

void bindings(const std::shared_ptr<const world::ActorModelAsset>& asset) {
    world::Profile profile;profile.layouts.push_back({});
    world::World owner(profile,std::make_shared<world::Session>());
    auto first = std::make_unique<world::Actor>();
    first->position = {10,20,30};first->status = 0x89abcdefu;
    const auto first_id = owner.spawn_primary(0,std::move(first)).id;
    const auto second_id = owner.spawn_primary(1,std::make_unique<world::Actor>()).id;
    check(world::bind_actor_model_asset(owner,first_id,asset));
    check(world::bind_actor_model_asset(owner,second_id,asset));
    auto first_actor = owner.primary(0),second_actor = owner.primary(1);
    check(first_actor->model_asset == asset && second_actor->model_asset == asset);
    check(first_actor->model && second_actor->model && first_actor->model != second_actor->model);
    check(first_actor->animation && first_actor->animation->model() == first_actor->model);
    check(first_actor->position.x == 10 && first_actor->status == 0x89abcdefu);
    const auto old_model = first_actor->model;
    const auto old_animation = first_actor->animation;
    old_model->rebuild(reo::native::transform_math::identity());
    const auto snapshot = old_model->retain();
    const auto old_constraints = std::make_shared<reo::native::animation::Constraints>(old_model);
    first_actor->constraints = old_constraints;
    first_actor->collision.joint_two_position = reo::native::gameplay_collision::Vec3{1,2,3};
    first_actor->collision.pose_ready = true;
    check(world::bind_actor_model_asset(owner,first_id,asset));
    check(first_actor->model != old_model && first_actor->animation != old_animation);
    check(old_animation->model() == old_model && old_constraints->model() == old_model && old_model->retain() == snapshot);
    check(!first_actor->constraints && !first_actor->collision.joint_two_position && !first_actor->collision.pose_ready);
    const auto prior = second_actor->model;
    check(!world::bind_actor_model_asset(owner,second_id,{}));
    check(second_actor->model == prior);
    world::World foreign(profile,std::make_shared<world::Session>());
    check(!world::bind_actor_model_asset(foreign,second_id,asset));
    auto temporary = world::ActorAssets(source({{"e00_00.nbd",bundle()}})).read(0,0);
    const std::weak_ptr<const world::ActorModelAsset> retained = temporary;
    check(world::bind_actor_model_asset(owner,second_id,temporary));
    check(second_actor->model_asset == temporary);
    temporary.reset();
    check(!retained.expired());
    check(owner.retire_primary(0) == reo::native::gameplay_actors::EntityStatus::completed);
    const auto replacement = owner.spawn_primary(0,std::make_unique<world::Actor>()).id;
    check(replacement != first_id && !world::bind_actor_model_asset(owner,first_id,asset));
    check(!owner.primary(0)->model && first_actor->model_asset == asset);
    check(owner.close() == world::Status::completed);
    check(!world::bind_actor_model_asset(owner,replacement,asset));
    check(first_actor->model_asset == asset && old_model->retain() == snapshot);
    second_actor.reset();
    check(retained.expired());
    model_bindings += 4;binding_refusals += 4;
}

void constructors() {
    namespace u=reo::native::gameplay_update;namespace tasks=reo::native::gameplay_tasks;
    world::Profile profile;profile.layouts.push_back({});
    world::World owner(profile,std::make_shared<world::Session>()),foreign(profile,std::make_shared<world::Session>());
    tasks::Scheduler scheduler,other_scheduler;
    u::MaterialAnimations materials(owner,scheduler),other(foreign,other_scheduler);
    refused([&]{u::ScriptedActorConstruction invalid(owner,other);});
    u::ScriptedActorConstruction factory(owner,materials);
    const auto model27=world::File1LinkedModelProfiles{}.definition(27,0).model;
    const auto memory=std::make_shared<Memory>(afs({{"romdata_usa.afs",afs({
        {"e00_00.nbd",bundle()},{std::string(world::ActorAssets::model_name(model27,world::ModelDefinitionBank::ordinary)),bundle()}})}}));
    world::ActorAssets assets(std::make_shared<reo::assets::Source>("native constructor fixture",memory));
    const auto prepared=factory.prepare({0x1234,0x10000,0x10000,0x10000},assets);
    const auto animated=factory.prepare({7,27,0,0},assets);
    const auto reads=memory->reads.load();
    const auto first=factory.create(*prepared),second=factory.create(*prepared);
    check(first.status==u::ScriptedConstructionStatus::completed&&second.status==u::ScriptedConstructionStatus::completed);
    const auto a=owner.resolve(first.id),b=owner.resolve(second.id);
    check(a->model&&b->model&&a->model!=b->model&&a->animation&&a->animation!=b->animation);
    check(a->animation->channel_count==0&&a->animation->resources_known&&!a->animation->resources[0]&&!a->animation->resources[1]&&!a->animation->resources[2]);
    check(a->linked_frame&&a->linked_frame->center_cache_state==0&&a->linked_frame->transient_marker==0);
    check(a->targeting&&a->targeting->flags==0&&!a->targeting->selected_model_point&&a->targeting->model_point==0);
    check(a->targeting->head_model_point==0&&b->targeting->head_model_point==0);
    a->targeting->head_model_point=7;check(b->targeting->head_model_point==0);
    check(a->model_asset==prepared->asset()&&a->scripted&&a->scripted->model_group==0x34);
    check(a->scripted->part_visibility==std::vector<std::uint8_t>({1,1,1}));
    check(a->scripted->color==std::array<std::uint8_t,4>{255,255,255,255}&&a->scripted->alpha_mode==-1&&a->scripted->alpha==255);
    const auto uv=factory.create(*animated);check(uv.status==u::ScriptedConstructionStatus::completed&&uv.material_task.status==tasks::Status::completed);
    check(memory->reads==reads&&scheduler.size()==1);
    check(scheduler.run(tasks::Pass::update).called==1&&materials.snapshot(uv.material_task.handle)->first==450);
    check(scheduler.run(tasks::Pass::update).called==1&&owner.resolve(uv.id)->material_uv->u==449.f/450.f);
    while(owner.linked_models().remaining())check(factory.create(*prepared).status==u::ScriptedConstructionStatus::completed);
    check(factory.create(*animated).status==u::ScriptedConstructionStatus::full&&scheduler.size()==1);
    scripted_constructions+=50;
    check(owner.linked_models().reset()==world::LinkedStatus::completed);
    check(scheduler.run(tasks::Pass::update).status==tasks::Status::completed&&scheduler.size()==0);
    struct Idle final:tasks::Task{void update(tasks::Scheduler&,const tasks::Handle&)noexcept override{}};
    const auto idle=std::make_shared<Idle>();
    for(unsigned i=0;i<32;++i)check(scheduler.create(idle).status==tasks::Status::completed);
    const auto dropped=factory.create(*animated);
    check(dropped.status==u::ScriptedConstructionStatus::completed&&dropped.id&&dropped.material_task.status==tasks::Status::full);
    check(owner.resolve(dropped.id)->scripted&&scheduler.size()==32);
    const auto absent=factory.prepare({0,60,0,0},assets);
    const auto empty=factory.create(*absent);
    check(empty.status==u::ScriptedConstructionStatus::completed&&!owner.resolve(empty.id)->model_asset&&owner.resolve(empty.id)->scripted->part_visibility.empty());
    scripted_constructions+=2;
    const auto remaining=owner.linked_models().remaining();
    refused([&]{(void)factory.prepare({0,62,0,0},assets);});
    refused([&]{(void)factory.prepare({0,0,255,0},assets);});
    refused([&]{(void)factory.prepare({0,0,0,255},assets);});
    auto excessive=bundle();put(excessive,176,33u);
    refused([&]{(void)factory.prepare({0,0,0,0},world::ActorAssets(source({{"e00_00.nbd",excessive}})));});
    check(owner.linked_models().remaining()==remaining&&scheduler.size()==32);
    materials.close();
    check(factory.create(*prepared).status==u::ScriptedConstructionStatus::unavailable);
    check(owner.linked_models().remaining()==remaining&&scheduler.size()==32);
    check(owner.close()==world::Status::completed);
    check(a->model&&a->scripted&&a->model_asset==prepared->asset());
    check(a->targeting->head_model_point==7);
    check(factory.create(*prepared).status==u::ScriptedConstructionStatus::unavailable);
}

void fixtures() {
    constructors();
    const auto payload = bundle();
    auto memory = std::make_shared<Memory>(afs({{"romdata_usa.afs",afs({{"e00_00.nbd",payload}})}}));
    const auto input = std::make_shared<reo::assets::Source>("native actor asset fixture",memory);
    world::ActorAssets assets(input);
    const auto asset = assets.read(0,0);
    check(asset && asset->name() == "E00_00.NBD" && asset->bytes().size() == payload.size());
    check(std::memcmp(asset->bytes().data(),payload.data(),payload.size()) == 0);
    check(asset->skeleton() && asset->skeleton()->nodes().size() == 1);
    check(asset->part_count() == 3);
    const auto read_count = memory->reads.load();
    check(assets.read(0,0) == asset && memory->reads.load() == read_count);
    check(!assets.read(51,0) && memory->reads.load() == read_count);
    auto first = asset->make_instance(),second = asset->make_instance();
    check(first && second && first != second && &first->skeleton() == &second->skeleton());
    first->rebuild(reo::native::transform_math::identity());
    const auto retained = first->retain();
    second->local_translation(0,{10,20,30});
    second->rebuild(reo::native::transform_math::identity());
    check(retained && first->retain() == retained && second->world_translation(0).x == 10);
    check(first->world_translation(0).x == 0);
    bindings(asset);
    world::ActorAssets concurrent(input);
    auto read_one = std::async(std::launch::async,[&] { return concurrent.read(0,0); });
    auto read_two = std::async(std::launch::async,[&] { return concurrent.read(0,0); });
    check(read_one.get() == read_two.get());
    world::ActorAssets retry(input);
    memory->failures = 1;
    refused([&] { (void)retry.read(0,0); });
    check(retry.read(0,0)->skeleton()->nodes().size() == 1);
    refused([&] { (void)world::ActorAssets(nullptr); });
    const auto wrong_directory = std::make_shared<reo::assets::Source>("invalid",
        std::make_shared<Memory>(afs({{"other.afs",afs({{"e00_00.nbd",payload}})}})));
    refused([&] { (void)world::ActorAssets(wrong_directory); });
    refused([&] { (void)world::ActorAssets(source({{"e00_00.nbd",payload},{"E00_00.NBD",payload}})).read(0,0); });
    refused([&] { (void)world::ActorAssets(source({{"other.nbd",payload}})).read(0,0); });
    refused([&] { (void)assets.read(62,0); });
    refused([&] { (void)assets.read(0,255); });
    refused([&] { (void)world::ActorAssets::model_name(153,world::ModelDefinitionBank::ordinary); });
    refused([&] { (void)world::ActorAssets::model_name(30,world::ModelDefinitionBank::alternate); });
    for (const auto field : {0x24u,0x28u}) {
        auto malformed = payload;put(malformed,field,UINT32_MAX);
        refused([&] { (void)world::ActorAssets(source({{"e00_00.nbd",malformed}})).read(0,0); });
    }
    auto cyclic = payload;put(cyclic,88+8,0u);
    refused([&] { (void)world::ActorAssets(source({{"e00_00.nbd",cyclic}})).read(0,0); });
    const auto absent = world::ActorAssets(source({{"e00_00.nbd",bundle(false)}})).read(0,0);
    check(absent && !absent->skeleton() && !absent->make_instance());
    check(world::ActorAssets::model_name(60,world::ModelDefinitionBank::ordinary) == "N200.NBD");
    check(world::ActorAssets::model_name(29,world::ModelDefinitionBank::alternate) == "HE43_01.NBD");
}

void owned(const std::filesystem::path& archive,const std::filesystem::path& manifest) {
    world::ActorAssets assets(std::make_shared<reo::assets::Source>(archive));
    namespace u=reo::native::gameplay_update;namespace tasks=reo::native::gameplay_tasks;
    world::Profile profile;profile.layouts.push_back({});
    world::World actors(profile,std::make_shared<world::Session>());
    tasks::Scheduler scheduler;u::MaterialAnimations materials(actors,scheduler);
    u::ScriptedActorConstruction factory(actors,materials);
    std::ifstream rows(manifest),raw(archive,std::ios::binary);
    check(bool(rows) && bool(raw));
    std::string line;
    while (std::getline(rows,line)) {
        std::istringstream row(line);
        unsigned bank,type,variant;std::string name;std::uint64_t offset;std::size_t length,nodes,parts;
        check(bool(row>>bank>>type>>variant>>name>>offset>>length>>nodes>>parts));
        const auto selected = bank ? world::ModelDefinitionBank::alternate : world::ModelDefinitionBank::ordinary;
        if (name == "-") {
            check(!assets.read(std::uint8_t(type),std::uint16_t(variant),selected));
            ++owned_absent_models;
            continue;
        }
        if (!length) {
            refused([&] { (void)assets.read(std::uint8_t(type),std::uint16_t(variant),selected); });
            ++owned_missing;
            continue;
        }
        std::shared_ptr<const world::ActorModelAsset> asset;
        try { asset = assets.read(std::uint8_t(type),std::uint16_t(variant),selected); }
        catch (const std::exception& error) { throw std::runtime_error(name+" "+error.what()); }
        check(asset && asset->name() == name && asset->bytes().size() == length);
        check(asset->part_count() == parts);
        std::vector<std::uint8_t> expected(length);
        raw.seekg(std::streamoff(offset));raw.read(reinterpret_cast<char*>(expected.data()),std::streamsize(length));
        check(bool(raw) && std::memcmp(asset->bytes().data(),expected.data(),length) == 0);
        check(assets.read(std::uint8_t(type),std::uint16_t(variant),selected) == asset);
        const auto instance = asset->make_instance();
        check(bool(instance) == (nodes != 0));
        if (instance) {
            check(instance->nodes().size() == nodes);
            instance->rebuild(reo::native::transform_math::identity());
            check(instance->retain() && instance->retain()->joints.size() == nodes);
            ++owned_skeletons;
        } else ++owned_absent_skeletons;
        bool constructor_profile=true;
        try{(void)world::File1LinkedModelProfiles{}.definition(std::uint8_t(type),bank?1:0);}
        catch(const std::out_of_range&){constructor_profile=false;++constructor_profile_refusals;}
        if(constructor_profile){
            const auto prepared=factory.prepare({std::uint32_t(owned_models),type,variant,bank?1u:0u},assets);
            check(prepared->asset()==asset);
            const auto made=factory.create(*prepared);
            check(made.status==u::ScriptedConstructionStatus::completed);
            const auto actor=actors.resolve(made.id);
            check(actor&&actor->model_asset==asset&&actor->model&&actor->model->nodes().size()==nodes);
            check(actor->scripted&&actor->scripted->part_visibility.size()==parts);
            check(actor->targeting&&actor->targeting->head_model_point==0);
            check(actor->scripted->render.bank==selected&&actor->model!=instance);
            actor->model->rebuild(reo::native::transform_math::identity());
            check(actor->model->retain()&&actor->model->retain()->joints.size()==nodes);
            ++owned_scripted_constructions;
            if(actors.linked_models().remaining()==0){
                check(actors.linked_models().reset()==world::LinkedStatus::completed);
                check(scheduler.run(tasks::Pass::update).status==tasks::Status::completed&&scheduler.size()==0);
            }
        }
        ++owned_models;
    }
    check(rows.eof());
}
}

int main(int argc,char** argv) try {
    fixtures();
    if (argc == 3) owned(argv[1],argv[2]);
    else check(argc == 1);
    std::cout<<"{\"checks\":"<<checks<<",\"refusals\":"<<refusals<<",\"owned_models\":"<<owned_models
             <<",\"owned_skeletons\":"<<owned_skeletons<<",\"owned_absent_skeletons\":"<<owned_absent_skeletons
             <<",\"owned_absent_models\":"<<owned_absent_models
             <<",\"model_bindings\":"<<model_bindings<<",\"binding_refusals\":"<<binding_refusals
             <<",\"scripted_constructions\":"<<scripted_constructions<<",\"owned_scripted_constructions\":"<<owned_scripted_constructions
             <<",\"constructor_profile_refusals\":"<<constructor_profile_refusals
             <<",\"owned_missing\":"<<owned_missing<<"}\n";
} catch (const std::exception& error) { std::cerr<<error.what()<<'\n';return 1; }
