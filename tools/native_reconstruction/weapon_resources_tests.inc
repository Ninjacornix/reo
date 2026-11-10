#include "game/native/gameplay_weapon_resources/weapon_resources.hpp"
#include "game/native/gameplay_bank_loading/aliases.hpp"
#include "game/native/resources/virtual_file_view.hpp"
#include "game/native/resources_windows/pinned_file.hpp"
#include "owned_iso.hpp"
#include <chrono>
unsigned weapon_refreshes{},weapon_loaded_banks{},weapon_missing_banks{},weapon_pcm_frames{},weapon_signal_samples{},weapon_refusals{};
#ifdef REO_RESOURCE_COMPANIONS
unsigned companion_action_audio_frames{},companion_action_audio_signal{},companion_action_audio_requests{};
#endif
namespace weapon_fixture {
namespace w=reo::native::gameplay_weapon_resources;
namespace g=reo::native::gameplay_world;
namespace a=reo::native::gameplay_audio;
namespace b=reo::native::audio_banks::v2;
namespace l=reo::native::gameplay_bank_loading;
namespace r=reo::native::resources;
namespace af=reo::native::afs_source_range;
struct Counted final:r::ByteView {
    std::shared_ptr<const r::ByteView> base;mutable unsigned reads{};
    explicit Counted(std::shared_ptr<const r::ByteView> value):base(std::move(value)){}
    std::uint64_t size()const noexcept override{return base->size();}
    r::ReadResult read(std::uint64_t at,std::span<std::byte> out)const override{++reads;return base->read(at,out);}
};
struct Gains final:b::GainProvider {float gain(unsigned,unsigned,std::uint64_t)noexcept override{return 1;}};
l::LoadResult wait(l::Loader& loader,const l::LoadTicket& ticket){const auto deadline=std::chrono::steady_clock::now()+std::chrono::seconds(10);for(;;){loader.service();const auto result=loader.poll(ticket);if(result.status!=l::LoadStatus::pending)return result;if(std::chrono::steady_clock::now()>=deadline)throw std::runtime_error("Weapon audio load timeout");std::this_thread::yield();}}
void compare_bank(const reo::native::animation::WeaponProgramBank& actual,const reo::native::animation::WeaponProgramBank& expected){
    for(unsigned i=0;i<10;++i){const auto& x=actual.selection(i);const auto& y=expected.selection(i);check(x.kind==y.kind&&bool(x.program)==bool(y.program));if(!x.program)continue;
        for(unsigned p=0;p<6;++p){check(bool(x.program->parts[p])==bool(y.program->parts[p]));if(!x.program->parts[p])continue;for(unsigned c=0;c<6;++c){const auto& ac=x.program->parts[p]->curves[c];const auto& ec=y.program->parts[p]->curves[c];check(bool(ac)==bool(ec));if(!ac)continue;check(ac->keys().size()==ec->keys().size());for(unsigned k=0;k<ac->keys().size();++k)check(ac->keys()[k].value==ec->keys()[k].value&&ac->keys()[k].time==ec->keys()[k].time);}}
    }
}
}
void compare_weapon_resources(const char* iso_path,std::vector<std::uint8_t>& ram){
    using namespace weapon_fixture;
    const auto pinned=r::win32::PinnedFile::open_verified(std::filesystem::path(iso_path),owned_iso_bytes,owned_iso_sha);check(pinned.status==r::win32::PinnedStatus::ok);
    const auto archive=[&](std::uint64_t offset,std::uint64_t bytes){reo::assets::VirtualFile file;file.size=bytes;file.segments.push_back({0,bytes,offset,std::make_shared<reo::assets::Source>(pinned.file->identity().final_path,pinned.file),{}});const auto view=r::VirtualFileView::create(file);check(view.status==r::Status::ok);auto counted=std::make_shared<Counted>(view.view);const auto opened=af::Archive::open(counted,0,bytes);check(opened.status==af::Status::completed);return std::pair{opened.archive,counted};};
    const auto [rom,counted]=archive(17065984,477052928);const auto [snd,snd_reads]=archive(924106752,1062582272);check(rom->count()==1342&&snd->count()==422);
    const auto catalogue=w::Catalogue::prepare_file1_rom(rom);const auto prepared_reads=counted->reads;check(prepared_reads>=16);
    for(const auto& weapon:owned_weapons){const auto bank=catalogue->find(std::int8_t(weapon.selector));check(bool(bank));compare_bank(*bank,*reo::native::animation::WeaponProgramBank::import(std::as_bytes(std::span(weapon.bytes))));}
    check(!catalogue->find(-1)&&!catalogue->find(3));compare_bank(*catalogue->cleared(),*reo::native::animation::WeaponProgramBank::import({}));
    g::World world{{{g::input::Remap{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<g::Session>()};s::SceneResources resources;s::ResourceTemplates templates;
    auto engine=std::make_shared<b::Session>();auto audio=std::make_shared<a::Owner>(engine,world.session().random);l::Loader loader(audio,snd);w::Owner owner(world,resources,templates,catalogue,audio,loader);check(owner.bound_to(world,resources,templates));
#ifdef REO_RESOURCE_COMPANIONS
    g::ResourceModels action_models;reo::native::gameplay_scenario::Lighting action_lighting;reo::native::gameplay_lighting::Pool action_pool(action_lighting);reo::native::gameplay_tasks::Scheduler action_tasks;reo::native::gameplay_lighting::TimedLights action_lights(world,action_tasks,action_pool);
    a::SpatialContext action_spatial;action_spatial.world_to_screen=reo::native::transform_math::identity();g::animation_events::BasicAudio action_frontend(world,*audio,action_spatial,resources,templates);e::NativeResourceCompanionActions companion_actions(world,resources,action_models,templates,action_frontend,action_lights);
#endif
    std::array<reo::native::gameplay_actors::EntityId,4> entities;for(unsigned slot=0;slot<4;++slot){auto actor=std::make_unique<g::Actor>();actor->slot=std::uint8_t(slot);entities[slot]=world.spawn_primary(slot,std::move(actor)).id;check(bool(entities[slot]));}
    std::fill(ram.begin(),ram.end(),0);auto* memory=ram.data();owned_constants(memory);
    const auto template_for=[&](int selector){std::vector<std::byte> data(56);unsigned value=3;std::memcpy(data.data(),&value,4);value=1;std::memcpy(data.data()+4,&value,4);value=32;std::memcpy(data.data()+16,&value,4);data[46]=std::byte(std::uint8_t(selector));check(templates.load(data));memory[0x74bb5e]=std::uint8_t(selector);};
    for(const auto& weapon:owned_weapons)for(unsigned slot=0;slot<4;++slot)for(unsigned mode:{0u,1u,2u,255u})for(bool active:{false,true})for(bool missing:{false,true})for(unsigned selected:{0u,3u,255u}){
        template_for(weapon.selector);const auto actor=world.resolve(entities[slot]);actor->selected_resource=std::uint8_t(selected);actor->weapon_programs=catalogue->find(51);world.session().sound_loading_mode=std::uint8_t(mode);
        s::SceneDescriptor d;d.active=std::uint8_t(active);d.template_index=missing?255:0;check(bool(resources.load(selected==255?3:selected,d)));
        const unsigned raw=0x4a5c30+slot*0x10e0,desc=0x3c5630+60*(selected==255?3:selected),programs=0x749180+2048*slot;memory[raw+3]=std::uint8_t(slot);memory[raw+0xc7c]=std::uint8_t(selected);memory[desc]=d.active;memory[desc+43]=d.template_index;memory[0x324405]=std::uint8_t(mode);std::fill_n(memory+0x2b3840,0x100,0);std::fill_n(memory+programs,2048,0);std::memcpy(memory+programs,owned_weapons.back().bytes.data(),owned_weapons.back().bytes.size());
        const auto before_reads=weapon_file_reads;call(memory,0x1d3b00,{raw});const auto result=owner.refresh(entities[slot]);const bool changed=selected!=255&&active&&!missing;check(result.status==w::Status::completed&&result.programs_changed==changed);const auto expected=changed?(selected?catalogue->find(std::int8_t(weapon.selector)):catalogue->cleared()):catalogue->find(51);check(actor->weapon_programs==expected);std::array<std::uint8_t,2048> buffer{};const auto& source=changed?weapon:owned_weapons.back();if(!changed||selected)std::copy(source.bytes.begin(),source.bytes.end(),buffer.begin());check(std::memcmp(buffer.data(),memory+programs,2048)==0&&weapon_file_reads-before_reads==unsigned(changed&&selected!=0));
        const bool queued=changed&&mode!=2;check(memory[0x2b3841]==unsigned(queued)&&bool(result.audio)==queued);if(queued){check(memory[0x2b384c]==slot+8&&weapon_string(memory,0x2b3864)=="weapon"+(weapon.selector<10?std::string("0"):std::string())+std::to_string(weapon.selector));check(result.audio->status==l::LoadStatus::accepted&&loader.cancel(result.audio->ticket));}++weapon_refreshes;
    }
    // Real background bank decode/install and PCM, no output device or game.
    reo::native::gameplay_session::Random reference_random;auto reference=std::make_shared<b::Session>();a::Owner direct(reference,reference_random);Gains gains;
    for(const auto& weapon:owned_weapons){
        template_for(weapon.selector);auto actor=world.resolve(entities[0]);actor->selected_resource=3;world.session().sound_loading_mode=0;s::SceneDescriptor d;d.active=1;d.template_index=0;check(bool(resources.load(3,d)));
        const auto result=owner.refresh(entities[0]);
        check(result.audio&&result.audio->status==l::LoadStatus::accepted);
        const auto loaded=wait(loader,result.audio->ticket);
        const auto member=l::sound_member("weapon"+(weapon.selector<10?std::string("0"):std::string())+std::to_string(weapon.selector)+".snd");
        if(!member){check((weapon.selector==0||weapon.selector==51)&&loaded.status==l::LoadStatus::not_found&&!loaded.member);++weapon_missing_banks;continue;}
        check(loaded.status==l::LoadStatus::completed&&loaded.member==member);++weapon_loaded_banks;const auto source=snd->member(*member);check(source.status==af::Status::completed);std::vector<std::uint8_t> bytes(source.view->size());check(source.view->read(0,{reinterpret_cast<std::byte*>(bytes.data()),bytes.size()}).status==r::Status::ok);check(direct.install(direct.begin_bank(8),bytes).status==a::Status::completed);const auto description=a::import_snd(bytes,8);check(description.status==a::Status::completed);
        for(unsigned cue=0;cue<128;++cue){const auto& row=description.value.descriptors[cue];if(row.type!=0||row.next!=255)continue;const b::Command stop=b::StopAll{false};check(engine->apply({&stop,1}).status==b::Status::ok&&reference->apply({&stop,1}).status==b::Status::ok);world.session().random.restore({31,217,0});reference_random.restore({31,217,0});const auto actual=audio->request({8,cue}),expected=direct.request({8,cue});check(actual.status==expected.status&&actual.commands==expected.commands&&world.session().random.state()==reference_random.state());std::array<float,256> pcm{},expected_pcm{};check(engine->mix_add(pcm.data(),128,gains)==b::Status::ok&&reference->mix_add(expected_pcm.data(),128,gains)==b::Status::ok&&pcm==expected_pcm);weapon_pcm_frames+=128;for(float sample:pcm)if(sample!=0)++weapon_signal_samples;}
#ifdef REO_RESOURCE_COMPANIONS
        for(unsigned cue=0;cue<128;++cue){
            const auto& row=description.value.descriptors[cue];if(row.type!=0||row.next!=255)continue;const b::Command stop=b::StopAll{false};check(engine->apply({&stop,1}).status==b::Status::ok&&reference->apply({&stop,1}).status==b::Status::ok);world.session().random.restore({31,217,0});reference_random.restore({31,217,0});
            check(companion_actions.cue(entities[0],std::uint16_t(cue)));const auto actual=companion_actions.last_audio();const auto expected=direct.positional({8,cue},{0,0,0},action_spatial,1);check(actual&&actual->status==expected.status&&actual->commands==expected.commands&&world.session().random.state()==reference_random.state());
            std::array<float,256> pcm{},expected_pcm{};check(engine->mix_add(pcm.data(),128,gains)==b::Status::ok&&reference->mix_add(expected_pcm.data(),128,gains)==b::Status::ok&&pcm==expected_pcm);companion_action_audio_frames+=128;++companion_action_audio_requests;for(float sample:pcm)if(sample!=0)++companion_action_audio_signal;
        }
#endif
    }
    check(weapon_loaded_banks==14&&weapon_missing_banks==2&&weapon_signal_samples>0&&counted->reads==prepared_reads);
#ifdef REO_RESOURCE_COMPANIONS
    check(companion_action_audio_frames>0&&companion_action_audio_signal>0&&companion_action_audio_requests>0);
#endif
    // Full queues do not undo the committed animation binding. Mode2 skips it.
    template_for(0);world.session().sound_loading_mode=0;std::array<l::LoadTicket,8> tickets;for(auto& ticket:tickets){const auto value=loader.enqueue("weapon00",8);check(value.status==l::LoadStatus::accepted);ticket=value.ticket;}const auto full=owner.refresh(entities[0]);check(full.status==w::Status::completed&&full.programs_changed&&full.audio&&full.audio->status==l::LoadStatus::full);++weapon_refusals;world.session().sound_loading_mode=2;check(!owner.refresh(entities[0]).audio);for(auto ticket:tickets)check(loader.cancel(ticket));
    template_for(-1);const auto old=world.resolve(entities[0])->weapon_programs;check(!owner.refresh(entities[0]).programs_changed&&world.resolve(entities[0])->weapon_programs==old);template_for(3);const auto unknown=owner.refresh(entities[0]);check(unknown.status==w::Status::unavailable&&unknown.programs_changed&&world.resolve(entities[0])->weapon_programs==catalogue->cleared());++weapon_refusals;
    s::SceneResources foreign;check(!owner.bound_to(world,foreign,templates));++weapon_refusals;bool rejected{};try{w::Catalogue::prepare_file1_rom(snd);}catch(const std::invalid_argument&){rejected=true;}check(rejected);++weapon_refusals;
    reo::native::gameplay_session::Random other_random;auto foreign_audio=std::make_shared<a::Owner>(engine,other_random);rejected=false;try{w::Owner bad(world,resources,templates,catalogue,foreign_audio,loader);}catch(const std::invalid_argument&){rejected=true;}check(rejected);++weapon_refusals;
    auto second_audio=std::make_shared<a::Owner>(engine,world.session().random);rejected=false;try{w::Owner bad(world,resources,templates,catalogue,second_audio,loader);}catch(const std::invalid_argument&){rejected=true;}check(rejected);++weapon_refusals;
    check(world.retire_primary(0)==g::actors::EntityStatus::completed&&owner.refresh(entities[0]).status==w::Status::foreign_or_stale);++weapon_refusals;check(world.close()==g::Status::completed&&owner.refresh(entities[1]).status==w::Status::closed);++weapon_refusals;loader.shutdown();check(loader.join());
}
