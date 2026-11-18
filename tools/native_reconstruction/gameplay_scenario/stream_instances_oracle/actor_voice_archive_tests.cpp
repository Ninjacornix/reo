#include "game/native/gameplay_scenario/stream_instances.hpp"
#include "game/native/gameplay_scenario/actor_voice_archive_assets.hpp"
#include "runtime/assets/virtual_afs.h"
#include <array>
#include <cstring>
#include <iostream>
#include <source_location>
#include <stdexcept>
namespace s=reo::native::gameplay_scenario;
namespace n=reo::native;
namespace {
std::uint64_t checks{},activations{},source_cases{},source_calls{},source_polls{},busy_cases{},lifetimes{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Actor archive check "+std::string(at.file_name())+":"+std::to_string(at.line()));}
template<class F>struct Operation final:n::adxt_control_owner::Operation {F callback;explicit Operation(F f):callback(std::move(f)){}void run(n::adxt_instances::Instances& players)noexcept override{callback(players);}};
struct Opened {std::shared_ptr<n::adxt_control_owner::Owner> owner;std::unique_ptr<s::StreamInstances> backend;};
Opened open(std::shared_ptr<const s::StreamAssetCatalog> catalog){
    std::array<std::uint32_t,1000> words{};words.front()=256;const auto table=n::adxt_attenuation::Table::from_words(words);check(table.status==n::adxt_attenuation::Status::completed);
    std::array<s::StreamInstanceConfig,3> config;
    for(unsigned i=0;i<3;++i){config[i].construction={i==2?1u:2u,{i,i,i,i},table.table};config[i].player.decoder.channels=config[i].construction.channels;}
    auto owner=std::make_shared<n::adxt_control_owner::Owner>(n::adxt_instances::control::Config{{3},{}});
    auto backend=s::StreamInstances::create(owner,config,std::move(catalog),{0,1,2});check(backend.status==s::StreamStatus::completed&&backend.value);
    return{std::move(owner),std::move(backend.value)};
}
struct Legacy final:s::StreamBackend {
    s::StreamValue phase(std::uint8_t)noexcept override{return{s::StreamStatus::unbound,0};}
    s::StreamStatus start(std::uint8_t,s::StreamRequest,std::uint32_t)noexcept override{return s::StreamStatus::unbound;}
    s::StreamStatus stop(std::uint8_t)noexcept override{return s::StreamStatus::unbound;}
    s::StreamStatus pause(std::uint8_t,bool,std::uint32_t)noexcept override{return s::StreamStatus::unbound;}
    s::StreamStatus attenuation(std::uint8_t,std::int32_t)noexcept override{return s::StreamStatus::unbound;}
    s::StreamStatus service(std::uint32_t)noexcept override{return s::StreamStatus::unbound;}
};
}
#ifdef REO_ACTOR_ARCHIVE_ORIGINAL
#include "actor_voice_archive_reference.inc"
#else
void source_initialize(const s::ActorVoiceArchiveAssets&){}
void source_activate(s::StreamInstances&,unsigned,unsigned){}
void source_clear(s::StreamInstances&){}
void source_compare(s::StreamInstances&){}
#endif
int main(int argc,char** argv)try{
    check(argc==2);Legacy legacy;check(legacy.activate_actor_archive(0,0)==s::StreamStatus::unbound&&legacy.clear_actor_archives()==s::StreamStatus::unbound&&legacy.actor_archive_marker(0).status==s::StreamStatus::unbound&&legacy.actor_voice_source(0,0).status==s::StreamStatus::unbound);
    bool rejected{};try{s::ActorVoiceArchiveAssets bad({});}catch(const std::invalid_argument&){rejected=true;}check(rejected);
    auto source=std::make_shared<reo::assets::Source>(argv[1]);auto assets=std::make_unique<s::ActorVoiceArchiveAssets>(source);
    source_initialize(*assets);
    for(unsigned character=0;character<8;++character){check(assets->archive(character)&&assets->archive(character)->count()==1000&&assets->identity(character).find("vo0010"+std::to_string(character)+".afs")!=std::string::npos);for(unsigned member:{0u,1u,999u}){const auto value=assets->archive(character)->member(member);check(value.status==n::afs_source_range::Status::completed&&value.view&&value.view->size()>4);std::array<std::byte,4> header{};check(value.view->read(0,header).status==n::resources::Status::ok&&header[0]==std::byte{0x80}&&header[1]==std::byte{});}}
    auto catalog=std::make_shared<s::StreamAssetCatalog>();check(catalog->add_actor_voice_archives(*assets)&&!catalog->add_actor_voice_archives(*assets));check(!catalog->actor_voice_archive(0));catalog->seal();check(catalog->actor_voice_archive(7)==assets->archive(7)&&!catalog->actor_voice_archive(8)&&!catalog->add_actor_voice_archives(*assets));
    auto running=open(catalog);auto& backend=*running.backend;
    for(unsigned slot=0;slot<5;++slot)check(backend.actor_archive_marker(std::uint8_t(slot)).status==s::StreamStatus::unbound);
    check(backend.actor_archive_marker(5).status==s::StreamStatus::unsupported_profile);
    check(backend.activate_actor_archive(5,0)==s::StreamStatus::completed&&backend.activate_actor_archive(255,255)==s::StreamStatus::completed);
    source_clear(backend);check(backend.clear_actor_archives()==s::StreamStatus::completed);
    source_compare(backend);
    for(unsigned slot=0;slot<8;++slot)for(unsigned character=0;character<256;++character){
        source_activate(backend,slot,character);check(backend.activate_actor_archive(std::uint8_t(slot),std::uint8_t(character))==s::StreamStatus::completed);++activations;
        source_compare(backend);
        if(slot<5){const auto marker=backend.actor_archive_marker(std::uint8_t(slot));check(marker.status==s::StreamStatus::completed&&marker.value==(character<8?int(character+1):0));const auto request=backend.actor_voice_source(std::uint8_t(slot),0);if(character<8){check(request.status==s::StreamStatus::completed&&request.source.archive==401+character&&request.source.member==0);check(catalog->resolve(request.source).status==s::StreamStatus::completed);}else check(request.status==s::StreamStatus::missing_asset);}
    }
    check(backend.activate_actor_archive(2,7)==s::StreamStatus::completed);const auto before=backend.actor_archive_marker(2).value;
    s::StreamStatus nested=s::StreamStatus::completed,nested_clear=s::StreamStatus::completed;
    Operation operation([&](auto&){nested=backend.activate_actor_archive(2,0);nested_clear=backend.clear_actor_archives();});check(running.owner->run(operation)==n::adxt_control_owner::Admission::accepted&&nested==s::StreamStatus::busy&&nested_clear==s::StreamStatus::busy&&backend.actor_archive_marker(2).value==before);++busy_cases;
    const auto retained=catalog->resolve(backend.actor_voice_source(2,999).source);check(retained.status==s::StreamStatus::completed);
    check(backend.actor_voice_source(2,-1).status==s::StreamStatus::missing_asset&&backend.actor_voice_source(2,1000).status==s::StreamStatus::missing_asset&&backend.actor_voice_source(5,0).status==s::StreamStatus::unsupported_profile);
    source_clear(backend);check(backend.clear_actor_archives()==s::StreamStatus::completed&&backend.actor_archive_marker(2).value==0&&backend.actor_voice_source(2,0).status==s::StreamStatus::missing_asset);
    source_compare(backend);
    for(unsigned i=0;i<3;++i)check(!backend.inspect(std::uint8_t(i)).source); // No decoder/playback was started.
    assets.reset();source.reset();check(backend.close()==s::StreamStatus::completed&&backend.activate_actor_archive(0,0)==s::StreamStatus::closed&&backend.clear_actor_archives()==s::StreamStatus::closed&&backend.actor_archive_marker(0).status==s::StreamStatus::closed);running.backend.reset();running.owner.reset();catalog.reset();
    std::array<std::byte,4> header{};check(retained.view->read(0,header).status==n::resources::Status::ok&&header[0]==std::byte{0x80});++lifetimes;
    auto missing=std::make_shared<s::StreamAssetCatalog>();missing->seal();auto unavailable=open(missing);check(unavailable.backend->activate_actor_archive(0,0)==s::StreamStatus::unbound&&unavailable.backend->actor_archive_marker(0).status==s::StreamStatus::unbound);check(unavailable.backend->activate_actor_archive(0,8)==s::StreamStatus::completed&&unavailable.backend->actor_archive_marker(0).value==0);check(unavailable.backend->close()==s::StreamStatus::completed);
    std::cout<<"{\"checks\":"<<checks<<",\"native_activations\":"<<activations<<",\"complete_source_cases\":"<<source_cases<<",\"source_calls\":"<<source_calls<<",\"source_polls\":"<<source_polls<<",\"busy_cases\":"<<busy_cases<<",\"retained_archive_lifetimes\":"<<lifetimes<<",\"decoder_sources_started\":0,\"audio_device_opened\":false,\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
