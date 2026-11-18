#include "primary_custom_statistics.hpp"
#include <bit>
#include <iostream>
#include <source_location>
#include <stdexcept>
#ifdef REO_PRIMARY_CUSTOM_STATISTICS_ORIGINAL
#include "primary_reference.hpp"
#endif
namespace g=reo::native::gameplay_world;
namespace {
std::uint64_t checks{},statistic_cases{},index_cases{},terminal_cases{},refusals{},original_calls{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Native custom statistic check "+std::to_string(at.line()));}
void compare_statistics(const g::Actor&,const g::Actor&,std::uint16_t);
void compare_index(std::uint16_t,std::optional<std::size_t>);
void run(){
    const auto rows=g::file1_primary_custom_statistics();check(rows.size()==91&&rows.back().identity==999);
    for(unsigned identity=0;identity<65536;++identity){const auto result=g::primary_custom_actor_index(std::uint16_t(identity));compare_index(std::uint16_t(identity),result);++index_cases;}
    std::array<std::uint16_t,8> representative{};std::array<bool,8> found{};
    for(const auto& row:rows){
        if(row.identity==999)continue;
        try{(void)g::primary_substitution_definition(std::uint16_t(row.identity+1));const auto band=row.health_band&7u;if(!found[band]){representative[band]=std::uint16_t(row.identity+1);found[band]=true;}}
        catch(const std::out_of_range&){}
    }
    // Exhaust every RNG word for every health-band selector witnessed by the
    // actual initialized rows. Do not invent rows for unused selectors.
    const auto compare=[&](std::uint16_t variant,std::uint16_t random_value){
        g::Actor actor;actor.primary_state.emplace();actor.model_variant=variant;actor.character=7;actor.current=-123;actor.maximum=456;actor.gauge_rate_variant=77;actor.motion_style=88;actor.motion_subtype=99;actor.status=0x12345678;actor.model_scale={2,3,4};actor.model_height_correction=5;actor.primary_state->statistic_multiplier=6;actor.contact.damage_scale=7;
        const auto before=actor;reo::native::gameplay_session::Random random({123,random_value,77});const auto random_before=random.state();
        check(g::apply_primary_custom_statistics(actor,random)==g::PrimaryInitializationStatus::completed&&random.state()==random_before);
        check(actor.model_variant==variant&&actor.character==7&&actor.status==0x12345678);
        compare_statistics(actor,before,random_value);++statistic_cases;if(variant&&!g::primary_custom_actor_index(std::uint16_t(variant-1)))++terminal_cases;
    };
    for(unsigned band=0;band<8;++band)if(found[band])for(unsigned random=0;random<65536;++random)compare(representative[band],std::uint16_t(random));
    for(unsigned variant=1;variant<256;++variant){
        try{(void)g::primary_substitution_definition(std::uint16_t(variant));}
        catch(const std::out_of_range&){continue;}
        for(unsigned sample=0;sample<64;++sample)compare(std::uint16_t(variant),std::uint16_t(sample*1041));
    }
    compare(0,65535);g::Actor absent;reo::native::gameplay_session::Random random({12,34,56});check(g::apply_primary_custom_statistics(absent,random)==g::PrimaryInitializationStatus::completed);
    absent.model_variant=1;check(g::apply_primary_custom_statistics(absent,random)==g::PrimaryInitializationStatus::unavailable);++refusals;
    absent.primary_state.emplace();absent.model_variant=65535;const auto before=random.state();check(g::apply_primary_custom_statistics(absent,random)==g::PrimaryInitializationStatus::unavailable&&random.state()==before);++refusals;
    check(statistic_cases>100000&&terminal_cases>0);
}
}
#ifdef REO_PRIMARY_CUSTOM_STATISTICS_ORIGINAL
#include "primary_custom_statistics_reference.inc"
#else
namespace {void compare_statistics(const g::Actor&,const g::Actor&,std::uint16_t){}void compare_index(std::uint16_t,std::optional<std::size_t>){} }
#endif
int main()try{run();std::cout<<"{\"checks\":"<<checks<<",\"statistic_cases\":"<<statistic_cases<<",\"index_cases\":"<<index_cases<<",\"terminal_cases\":"<<terminal_cases<<",\"refusals\":"<<refusals<<",\"original_calls\":"<<original_calls<<",\"game_run\":false}\n";}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
