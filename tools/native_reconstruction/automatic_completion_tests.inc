#include "game/native/gameplay_update/update.hpp"
unsigned condition_cases{},automatic_cases{},automatic_refusals{};
namespace automatic_fixture {
namespace u=reo::native::gameplay_update;
namespace g=reo::native::gameplay_world;
namespace s=reo::native::gameplay_scenario;
struct Native {
    g::World world{{{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<g::Session>()};
    s::FlagState flags;s::ActionChoices choices;
    Native(){for(unsigned i=0;i<4;++i){auto actor=std::make_unique<g::Actor>();check(bool(world.spawn_primary(i,std::move(actor)).id));}}
    void state(std::uint8_t* memory,unsigned n){
        world.selected_actor=std::uint8_t(n%4);memory[0x4baded]=world.selected_actor;
        s::FlagStateSnapshot snapshot;
        for(unsigned i=0;i<16;++i){snapshot.shared.scenario[i]=(n%3==0)?UINT32_MAX:n*1664525u+i*1013904223u;snapshot.primary[0][i]=(n%5==0)?UINT32_MAX:~(n*65521u+i*1664525u);snapshot.bounded_bytes[i]=std::uint8_t(n+i);}
        for(unsigned i=0;i<512;++i)snapshot.scenario_owners[i]=std::uint8_t(n%7?world.selected_actor+1:(n+i));
        snapshot.bounded_halfword=std::uint16_t(n);flags.restore(snapshot);
        std::memcpy(memory+0x4b9a80,snapshot.primary[0].data(),64);std::memcpy(memory+0x4b9c00,snapshot.shared.scenario.data(),64);std::memcpy(memory+0x4b9c80,snapshot.bounded_bytes.data(),16);std::memcpy(memory+0x4baa50,snapshot.scenario_owners.data(),512);put(memory,0x4bac50,snapshot.bounded_halfword);
        s::ActionChoiceState choice;choice.table_row=std::uint8_t(n%4);check(choices.restore(choice));memory[0x4bae8a]=choice.table_row;
        for(unsigned i=0;i<4;++i){auto actor=world.primary(i);actor->active=(n+i)%5!=0;actor->status=(n%2)?0:n*65521u+i*1664525u;memory[0x4a5c30+4320*i]=actor->active?std::uint8_t((n%255)+1):0;put(memory,0x4a5c30+4320*i+0xba0,actor->status);}
    }
    u::CompletionConditions conditions()const{return{world,flags,choices};}
};
void rule(std::uint8_t* memory,unsigned at,const e::Rule& value){memory[at]=value.first_kind;memory[at+1]=value.second_kind;put(memory,at+2,value.first_argument);put(memory,at+4,value.second_argument);put(memory,at+6,value.event);put(memory,at+8,value.points);}
void stock(std::uint8_t* memory,const char* path){std::ifstream input(path,std::ios::binary);unsigned n;input.read(reinterpret_cast<char*>(&n),4);check(n==48);input.read(reinterpret_cast<char*>(memory+0x38a4a0),n);for(unsigned i=0;i<10;++i){unsigned at,bytes;input.read(reinterpret_cast<char*>(&at),4);input.read(reinterpret_cast<char*>(&bytes),4);check(bytes<=650&&at>=0x389d60&&at+bytes<=0x38a4a0);input.read(reinterpret_cast<char*>(memory+at),bytes);put(memory,0x38a4d0+4*i,at);}check(bool(input));}
void automatic(e::Statistics& stats,e::Events& events,Native& native,std::uint8_t* memory,std::uint16_t scenario,unsigned counter){put(memory,0x3243da,scenario);put(memory,0x4bade8,counter);call(memory,0x37baf0);const auto result=stats.automatic(scenario,native.conditions(),events,counter);check(result.status==e::StatisticsStatus::completed&&result.matched==result.recorded+result.dropped);try{completion_fixture::compare_state(stats,events,memory);}catch(...){std::cerr<<"Automatic scenario "<<scenario<<" counter "<<counter<<" case "<<automatic_cases<<" available "<<events.available()<<'/'<<get<std::uint16_t>(memory,0x56c810)<<" threshold "<<int(events.threshold())<<'/'<<int(std::bit_cast<std::int8_t>(memory[0x56bb88]))<<'\n';unsigned raw=get<unsigned>(memory,0x56c820);for(const auto& record:events.snapshot()){std::cerr<<"event "<<record.value.id<<" slot "<<*events.physical_slot(record.id)<<" raw "<<std::hex<<raw<<std::dec<<" id "<<get<std::uint16_t>(memory,raw+12)<<" time "<<record.value.timestamp<<'/'<<get<unsigned>(memory,raw+8)<<'\n';raw=get<unsigned>(memory,raw);}throw;}++automatic_cases;}
}
void compare_automatic_completion(std::uint8_t* memory,const char* rules,const char* jump){
    using namespace automatic_fixture;using namespace completion_fixture;
    std::ifstream input(jump,std::ios::binary);input.read(reinterpret_cast<char*>(memory+0x38cce0),64);check(bool(input));Native native;
    for(unsigned kind=0;kind<16;++kind)for(unsigned n=0;n<65536;++n){
        native.state(memory,n);e::Rule value{0,0,std::uint16_t(kind==5?n%128:kind==6?n:n%512),std::uint16_t((n*37)%512),0,0};rule(memory,0x120000,value);
        const auto expected=call(memory,0x37bca0,{0x120000,(n<<8)|kind});const auto result=native.conditions()(value,(n<<8)|kind);check(result&&unsigned(*result)==expected);++condition_cases;
    }
    native.state(memory,0);for(unsigned kind=16;kind<256;++kind){e::Rule value{0,0,65535,65535,0,0};rule(memory,0x120000,value);check(call(memory,0x37bca0,{0x120000,0xabcd0000u|kind})==0&&native.conditions()(value,kind)==false);++condition_cases;}
    for(unsigned selected=0;selected<256;++selected)for(unsigned tag=0;tag<256;++tag){
        native.world.selected_actor=std::uint8_t(selected);memory[0x4baded]=std::uint8_t(selected);auto snapshot=native.flags.snapshot();snapshot.scenario_owners[0]=std::uint8_t(tag);snapshot.scenario_owners[1]=std::uint8_t(tag+selected);native.flags.restore(snapshot);memory[0x4baa50]=snapshot.scenario_owners[0];memory[0x4baa51]=snapshot.scenario_owners[1];
        e::Rule value{0,0,0,1,0,0};rule(memory,0x120000,value);for(unsigned kind:{2u,7u,12u}){const auto result=native.conditions()(value,kind);check(result&&unsigned(*result)==call(memory,0x37bca0,{0x120000,kind}));++condition_cases;}
    }
    // 255+1 is256 in the original comparison; it must not wrap to zero.
    native.world.selected_actor=255;memory[0x4baded]=255;auto flags=native.flags.snapshot();flags.scenario_owners.fill(0);native.flags.restore(flags);std::memset(memory+0x4baa50,0,512);
    for(unsigned kind:{2u,7u,12u}){e::Rule value{0,0,0,1,0,0};rule(memory,0x120000,value);check(call(memory,0x37bca0,{0x120000,kind})==0&&native.conditions()(value,kind)==false);++condition_cases;}
    check(!native.conditions()(e::Rule{},15));++automatic_refusals;
    native.state(memory,1);e::Rule outside{0,0,512,65535,0,0};for(unsigned kind:{2u,3u,4u,5u,7u,12u,13u,14u}){check(!native.conditions()(outside,kind));++automatic_refusals;}
    // Unreached arguments outside a profile are deliberately not inspected.
    outside.first_argument=0;check(native.conditions()(outside,12)==true);flags=native.flags.snapshot();flags.scenario_owners[0]=0;flags.primary[0][0]=0;flags.shared.scenario[0]=0;native.flags.restore(flags);for(unsigned kind:{7u,13u,14u})check(native.conditions()(outside,kind)==false);
    stock(memory,rules);e::Events events;e::Statistics statistics;
    for(unsigned scenario=0;scenario<48;++scenario)for(unsigned n=0;n<256;++n){native.state(memory,n);initialize(statistics,events,memory,std::uint16_t(scenario));auto state=statistics.state();state.points=UINT32_MAX-n;for(unsigned i=0;i<64;++i)state.automatic_seen[i]=std::uint8_t((n+i)%11==0?n:0);statistics.restore(state);export_state(state,memory);automatic(statistics,events,native,memory,std::uint16_t(scenario),n*65521u);automatic(statistics,events,native,memory,std::uint16_t(scenario),UINT32_MAX);}
    e::RuleGroup controlled;controlled.automatic={{0,0,0,0,63,65535},{3,6,42,99,32,17},{0,0,0,0,63,11}};const auto book=e::RuleBook::create({controlled},{0});e::Statistics stats(book);install(memory,controlled);native.state(memory,42);check(native.flags.write(s::FlagBank::scenario,42,true));put(memory,0x4b9c00+4*(42/32),get<unsigned>(memory,0x4b9c00+4*(42/32))|(1u<<(42%32)));initialize(stats,events,memory,0);automatic(stats,events,native,memory,0,123);check(stats.state().automatic_seen[1]==1&&stats.state().points==65563&&events.snapshot().size()==3);
    initialize(stats,events,memory,0);put(memory,0x4bade8,0u);for(unsigned i=0;i<128;++i){call(memory,0x37bfb0,{i});check(events.simple(i,0).status==e::Status::completed);}automatic(stats,events,native,memory,0,456);check(stats.state().points==65563&&events.available()==0);
    // Earlier completion survives an unavailable later condition, but neither
    // that record nor its successors are falsely marked seen.
    controlled.automatic={{0,0,0,0,0,1},{2,0,512,0,1,2},{0,0,0,0,2,3}};e::Statistics partial(e::RuleBook::create({controlled},{0}));check(partial.initialize(0,events)==e::StatisticsStatus::completed);auto result=partial.automatic(0,native.conditions(),events,0);check(result.status==e::StatisticsStatus::unavailable&&result.matched==1&&partial.state().points==1&&partial.state().automatic_seen[1]==0&&partial.state().automatic_seen[2]==0);++automatic_refusals;
    e::Events exhausted(0);check(partial.initialize(0,exhausted)==e::StatisticsStatus::completed);result=partial.automatic(0,native.conditions(),exhausted,0);check(result.status==e::StatisticsStatus::event_unavailable&&result.matched==1&&partial.state().automatic_seen[0]==1);++automatic_refusals;
    e::Statistics cold;check(cold.automatic(0,native.conditions(),events,0).status==e::StatisticsStatus::unavailable);++automatic_refusals;
    check(statistics.automatic(48,native.conditions(),events,0).status==e::StatisticsStatus::unavailable);++automatic_refusals;
    check(native.world.close()==g::Status::completed&&!native.conditions()(e::Rule{},0));++automatic_refusals;
}
