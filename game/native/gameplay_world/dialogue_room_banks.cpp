#include "dialogue_room_banks.hpp"
#include "dialogue_pool.hpp"
#include "dialogue_responses_state.hpp"
#include "../gameplay_scenario/auxiliary_room_rows.hpp"
#include <bit>
#include <cstdio>
#include <new>
#include <stdexcept>
namespace reo::native::gameplay_world {
DialogueStatus DialoguePool::reset_room_banks_unchecked(std::size_t& actors_reset)noexcept{
    clear_records_unchecked();responses_->uses_={};responses_->selected_use_=-1;
    // The source also clears two unused bytes DC4/DC6 and unused header words.
    // No native consumer observes those padding roles. All consumed selection,
    // cooldown and history roles are projected here; bank state is preserved.
    for(std::size_t i=0;;++i){
        const auto population=world_.session().primary_population;if(!population)return DialogueStatus::unavailable;
        if(std::int32_t(i)>=std::bit_cast<std::int32_t>(*population))return DialogueStatus::completed;
        if(i>=World::primary_capacity)return DialogueStatus::unsupported_profile;
        const auto actor=world_.primary(i);if(!actor)return DialogueStatus::unavailable;
        auto& speech=actor->speech;speech.selection=SpeechSelection{0,0,0,0,0};speech.gauge_notice=0;
        speech.dialogue_delay=0;speech.response_delay=0;speech.target_lock=0;speech.repeat_delay=0;++actors_reset;
    }
}
DialogueStatus DialoguePool::reset_room_banks()noexcept{
    if(world_.closed())return DialogueStatus::closed;
    if(running_||world_.busy())return DialogueStatus::busy;
    if(!initialized_||!responses_)return DialogueStatus::unavailable;
    running_=world_.updating_=true;struct Reset{DialoguePool& pool;~Reset(){pool.running_=pool.world_.updating_=false;}}reset{*this};
    std::size_t count{};return reset_room_banks_unchecked(count);
}
DialogueStatus DialoguePool::publish_room_bank(std::size_t physical,bool texts,
    gameplay_scenario::content::Bytes data,std::string identity){
    if(!physical_banks_)return DialogueStatus::unavailable;
    if(physical>=5)return DialogueStatus::unsupported_profile;
    auto next=*physical_banks_;
    std::optional<std::uint8_t> character;
    if(physical!=4){const auto actor=world_.primary(physical);if(actor)character=actor->character;}
    const auto published=texts?next.publish_texts(physical,character,std::make_shared<const gameplay_scenario::DialogueTexts>(std::move(data)),std::move(identity)):
        next.publish_cues(physical,character,std::make_shared<const gameplay_scenario::DialogueCues>(std::move(data)),std::move(identity));
    if(published.physical_published){
        auto logical=std::make_shared<const DialogueBanks>(next.logical());responses_->bind(*logical);
        physical_banks_=std::move(next);banks_=std::move(logical);
    }
    switch(published.status){case DialogueBankBindingStatus::completed:return DialogueStatus::completed;case DialogueBankBindingStatus::unavailable:return DialogueStatus::unavailable;case DialogueBankBindingStatus::unsupported_profile:return DialogueStatus::unsupported_profile;}
    return DialogueStatus::unsupported_profile;
}
DialogueBanksRefreshed DialoguePool::refresh_room_banks(const gameplay_scenario::content::ScenarioArchive& archive,
    const gameplay_scenario::content::ScriptBank& scenario_bank)noexcept{
    DialogueBanksRefreshed report;const auto fail=[&](DialogueStatus status){report.status=status;return report;};
    if(world_.closed())return fail(DialogueStatus::closed);
    if(running_||world_.busy())return fail(DialogueStatus::busy);
    if(!initialized_||!responses_)return fail(DialogueStatus::unavailable);
    running_=world_.updating_=true;struct Reset{DialoguePool& pool;~Reset(){pool.running_=pool.world_.updating_=false;}}reset{*this};
    try{
        report.stage=DialogueBankLoadStage::section;
        // The caller lends the actual retained scenario EVB, source324424.
        // Selector/cache storage stays in the existing canonical AuxiliaryScene.
        const auto rows=gameplay_scenario::AuxiliaryRoomRows::import(scenario_bank);
        std::int32_t section=-1;
        if(rows&&world_.session().auxiliary_scene.row()<=rows->row_count()){
            // Only row>count returns -1. Equal count indexes the source's
            // FFFFFFFF sentinel and has no bounded row read.
            if(world_.session().auxiliary_scene.row()==rows->row_count())return fail(DialogueStatus::unsupported_profile);
            const auto index=rows->index(world_.session().auxiliary_scene.row(),world_.room);
            if(!index)return fail(DialogueStatus::unsupported_profile);
            section=*index;
        }
        report.section=section;report.stage=DialogueBankLoadStage::cache;
        if(std::int32_t(world_.session().auxiliary_scene.loaded_index())==section){report.cache_hit=true;return report;}
        report.stage=DialogueBankLoadStage::reset;report.reset=true;
        auto status=reset_room_banks_unchecked(report.actors_reset);if(status!=DialogueStatus::completed)return fail(status);
        if(section<0){world_.session().auxiliary_scene.publish_loaded_index(std::uint8_t(section));report.cache_published=true;report.stage=DialogueBankLoadStage::completed;return report;}
        const auto load=[&](std::size_t physical,bool texts,std::uint8_t character)->DialogueStatus{
            report.physical=physical;const auto scenario=world_.session().scenario;const auto mode=world_.session().asset_loading_mode;
            if(!scenario||!mode)return DialogueStatus::unavailable;
            std::array<char,32> name{};const auto length=std::snprintf(name.data(),name.size(),texts?"spm%02u%02u%02u.bin":"sp%02u%02u%02u.bin",unsigned(*scenario),unsigned(section),unsigned(character));
            if(length<0||std::size_t(length)>=name.size())return DialogueStatus::unsupported_profile;
            // Resident path and archive basename select the same owned key.
            // ScenarioArchive performs the real H.BIN ordinal lookup and read;
            // no successful resource callback or fabricated zero fill is used.
            ++report.requested;auto data=archive.read_resource(*scenario,name.data());
            if(!data||data->empty()){++report.missing;return DialogueStatus::completed;}
            const auto result=publish_room_bank(physical,texts,std::move(data),name.data());
            if(result==DialogueStatus::completed)++report.loaded;
            return result;
        };
        for(bool texts:{false,true}){
            report.stage=texts?DialogueBankLoadStage::texts:DialogueBankLoadStage::cues;
            for(std::size_t i=0;;++i){
                const auto population=world_.session().primary_population;if(!population)return fail(DialogueStatus::unavailable);
                if(std::int32_t(i)>=std::bit_cast<std::int32_t>(*population))break;
                if(i>=World::primary_capacity)return fail(DialogueStatus::unsupported_profile);
                const auto actor=world_.primary(i);if(!actor)return fail(DialogueStatus::unavailable);
                status=load(i,texts,actor->character);if(status!=DialogueStatus::completed)return fail(status);
            }
            status=load(4,texts,8);if(status!=DialogueStatus::completed)return fail(status);
        }
        world_.session().auxiliary_scene.publish_loaded_index(std::uint8_t(section));report.cache_published=true;
        report.stage=DialogueBankLoadStage::completed;return report;
    }catch(const std::bad_alloc&){return fail(DialogueStatus::no_memory);}
    catch(const std::invalid_argument&){return fail(DialogueStatus::unsupported_profile);}
    catch(const std::exception&){return fail(DialogueStatus::unavailable);}
}
}
