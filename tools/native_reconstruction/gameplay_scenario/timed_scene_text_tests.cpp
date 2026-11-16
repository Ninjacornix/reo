#include "game/native/gameplay_application/native_session.hpp"
#include "game/native/gameplay_scenario/timed_scene_text.hpp"
#include "runtime/assets/virtual_afs.h"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include "authored_command.hpp"
#include <fstream>
#include <iostream>
#include <source_location>
#include <string>
namespace app=reo::native::gameplay_application;namespace s=reo::native::gameplay_scenario;
namespace tasks=reo::native::gameplay_tasks;namespace session=reo::native::gameplay_session;
namespace {
using Bytes=std::vector<std::uint8_t>;
std::uint64_t checks{},original_calls{},callbacks{},vm_dispatches{},loader_cases{},refusals{},system_cases{},choice_calls{},choice_rows{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Timed scene text check "+std::to_string(at.line()));
}
struct Memory final:reo::assets::PositionedSource {
    Bytes bytes;explicit Memory(Bytes value):bytes(std::move(value)){}
    std::uint64_t size()const noexcept override{return bytes.size();}
    std::size_t read(std::uint64_t at,std::size_t n,void* out)const override{
        if(at>bytes.size()||n>bytes.size()-at)throw std::runtime_error("Catalog read bound");
        std::memcpy(out,bytes.data()+at,n);return n;
    }
};
Bytes afs(std::vector<std::pair<std::string,Bytes>> entries){
    const auto align=[](std::size_t at){return(at+2047)&~std::size_t(2047);};
    Bytes result(align(16+8*entries.size()));std::memcpy(result.data(),"AFS\0",4);reo::assets::put32(result.data()+4,entries.size());
    for(unsigned i=0;i<entries.size();++i){const auto at=align(result.size());result.resize(at);
        reo::assets::put32(result.data()+8+8*i,at);reo::assets::put32(result.data()+12+8*i,entries[i].second.size());
        result.insert(result.end(),entries[i].second.begin(),entries[i].second.end());}
    const auto at=align(result.size());result.resize(at+48*entries.size());
    reo::assets::put32(result.data()+8+8*entries.size(),at);reo::assets::put32(result.data()+12+8*entries.size(),48*entries.size());
    for(unsigned i=0;i<entries.size();++i)std::memcpy(result.data()+at+48*i,entries[i].first.data(),entries[i].first.size());
    return result;
}
std::shared_ptr<const reo::assets::Source> catalog(unsigned selected,const Bytes& bytes){
    std::vector<std::pair<std::string,Bytes>> entries;
    for(unsigned sid:{1u,2u,28u,35u,41u}){
        const auto suffix=(sid<10?"00":"0")+std::to_string(sid);const auto name="r"+suffix;
        entries.emplace_back(name+".afs",afs({{"message.bin",sid==selected?bytes:Bytes(1)}}));
        Bytes index(sid==selected?24:8);reo::assets::put32(index.data(),0);reo::assets::put32(index.data()+4,sid==selected?1:0);
        if(sid==selected){const auto key="R"+suffix+"U_BIN";std::memcpy(index.data()+8,key.data(),key.size());}
        entries.emplace_back(name+"_h.bin",std::move(index));
    }
    return std::make_shared<const reo::assets::Source>("timed-text-owned-input",std::make_shared<Memory>(afs(std::move(entries))));
}
struct Notes final:s::FlagNotifications {
    bool changed(const s::ScenarioFlagChange&)noexcept override{std::terminate();}
    bool changed(const s::StridedFlagChange&)noexcept override{std::terminate();}
};
reo::native::gameplay_world::Profile profile(){reo::native::gameplay_world::Profile value;value.layouts.push_back({});return value;}
struct Fixture;
Fixture* running{};
struct Fixture {
    Notes notes;Bytes asset,memory=Bytes(0x900000);std::shared_ptr<const reo::assets::Source> source;
    app::NativeSession native;unsigned sid;std::vector<std::string> reads;
    Fixture(unsigned scenario,Bytes bytes):asset(std::move(bytes)),source(catalog(scenario,asset)),native(source,profile(),notes),sid(scenario){
        check(!running);running=this;owned_constants(memory.data());native.world().scenario=std::uint16_t(sid);
        check(native.application_lifecycle().begin_preparation());native.text_cache().reset();native.scene_text_bank().priority().reset_active();
        write(0x3243da,std::uint16_t(sid));write(0x3243d7,std::uint8_t(1));write(0x3243fd,std::uint8_t(1));
        write(0x4bae33,std::uint8_t(1));write(0x755ec4,std::uint8_t(0));
        write(0x32443c,0x860000u);std::fill_n(memory.data()+0x860000,65536,0xa5);
        call(0x5735a0);call(0x1b4a60);compare();
    }
    ~Fixture(){running=nullptr;}
    template<class T>void write(unsigned at,T value){transform_write(memory.data(),at,value);}
    template<class T>T get(unsigned at)const{return transform_read<T>(memory.data(),at);}
    R5900Context call(unsigned address,std::array<std::uint32_t,7> args={}){
        R5900Context c;PS2Runtime r;c.pc=address;for(unsigned i=0;i<args.size();++i)SET_GPR_U32(&c,4+i,args[i]);
        SET_GPR_U32(&c,29,0x8f0000);SET_GPR_U32(&c,31,0xabcdef);original_transform_port(memory.data(),&c,&r);
        check(c.pc==0xabcdef&&GPR_U32(&c,29)==0x8f0000);++original_calls;return c;
    }
    void compare(){
        const auto state=native.timed_scene_text().snapshot();check(state.callback_status==s::TimedTextStatus::completed);
        check(state.active&&*state.active==get<std::uint8_t>(0x4bae0a));if(state.priority)check(*state.priority==get<std::uint8_t>(0x4a5c24));
        check(native.update().linked().size()==32u-get<std::uint16_t>(0x3b5858));
        const auto cache=native.text_cache().snapshot();check(bool(cache));
        for(unsigned i=0;i<cache->size();++i){const auto& row=(*cache)[i];std::array<std::uint8_t,140> expected{};
            const auto put=[&]<class T>(unsigned at,T value){std::memcpy(expected.data()+at,&value,sizeof value);};
            put(0,std::uint16_t(row.active));put(2,row.x);put(4,row.y);put(6,row.duration);put(8,row.height);put(9,row.fade);put(10,row.alpha);put(11,row.priority);
            std::memcpy(expected.data()+12,row.text.data(),128);
            if(std::memcmp(expected.data(),memory.data()+0x3151d0+140*i,140)){
                std::cerr<<"Cache difference id="<<sid<<" row="<<i<<" native text="<<reinterpret_cast<const char*>(row.text.data())<<'\n';
                std::cerr<<"source text="<<reinterpret_cast<const char*>(memory.data()+0x3151d0+140*i+12)<<'\n';
                for(unsigned byte=0;byte<140;++byte)if(expected[byte]!=memory[0x3151d0+140*i+byte])std::cerr<<" byte"<<byte<<" native="<<unsigned(expected[byte])<<" source="<<unsigned(memory[0x3151d0+140*i+byte])<<'\n';
            }
            check(!std::memcmp(expected.data(),memory.data()+0x3151d0+140*i,140));
        }
        for(unsigned i=0;i<512;++i)check(*native.world().session().auxiliary_scene.timer_active(i)==bool(get<unsigned>(0x74e828+4*(i/32))&(1u<<(i%32))));
    }
    void load(s::SceneTextVariant variant=s::SceneTextVariant::alternate){
        const auto before=native.scene_text_bank().messages_known().size();const auto old_dm=native.scene_text_bank().known().size();
        const auto result=native.scene_text_bank().load_messages(variant);check(result.status==s::SceneTextBankStatus::completed);
        write(0x3243fd,std::uint8_t(variant==s::SceneTextVariant::alternate));call(0x1d4020);
        const auto known=native.scene_text_bank().messages_known();check(known.size()==std::max(before,result.read?asset.size():std::size_t(4)));
        check(std::equal(known.begin(),known.end(),reinterpret_cast<const std::byte*>(memory.data()+0x860000)));
        check(native.scene_text_bank().known().size()==old_dm);++loader_cases;
    }
    void request(s::TimedTextRequest input){
        check(native.timed_scene_text().request(input)==s::TimedTextStatus::completed);
        call(0x570140,{input.id,input.text_kind,std::uint32_t(std::int32_t(input.delay)),std::uint32_t(std::int32_t(input.duration)),input.priority});compare();
    }
    void vm(unsigned payload=authored_payload,bool offline=false){
        std::vector<std::byte> bytes(16);const std::array<unsigned,4> words{1,authored_header,payload,0xa};std::memcpy(bytes.data(),words.data(),bytes.size());
        auto p=std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{bytes},offline?s::DispatchProfile::offline_actor:s::DispatchProfile::ordinary);
        s::Interpreter vm;s::Providers providers;providers.world=&native.world();providers.flags=providers.canonical_flags=&native.update().flags();providers.timed_scene_text=&native.timed_scene_text();check(vm.install(0,p)==s::Status::completed);
        const auto result=offline?vm.tick_offline_channel(0,{}, {},providers):vm.tick(0,{},providers);check(result.status==s::Status::yielded);++vm_dispatches;
        write(0x10000,payload);call(0x692be0,{0x10000});compare();
    }
    void step(){check(native.update().linked().run(tasks::Pass::update).status==tasks::Status::completed);call(0x573840);++callbacks;compare();}
};
struct Idle final:tasks::Task {void update(tasks::Scheduler&,const tasks::Handle&)noexcept override{}};
Bytes synthetic(){
    Bytes bytes(2048);reo::assets::put32(bytes.data(),512);
    for(unsigned id=0;id<8;++id){reo::assets::put32(bytes.data()+4+8*id,128+id*8);reo::assets::put32(bytes.data()+8+8*id,2);
        reo::assets::put32(bytes.data()+128+id*8,768+id*64);reo::assets::put32(bytes.data()+132+id*8,800+id*64);
        const std::string first="Message "+std::to_string(id),second="Second "+std::to_string(id);
        std::memcpy(bytes.data()+768+id*64,first.data(),first.size());std::memcpy(bytes.data()+800+id*64,second.data(),second.size());
        for(unsigned cue=0;cue<8;++cue)transform_write(bytes.data(),512+id*16+cue*2,std::uint16_t(0xffff));
    }
    transform_write(bytes.data(),512,std::uint16_t(0x8000|31));transform_write(bytes.data(),514,std::uint16_t(32));return bytes;
}
void authored(const std::vector<std::pair<unsigned,Bytes>>& corpus){
    for(const auto& [sid,bytes]:corpus)for(bool gameplay:{false,true}){
        Fixture f(sid,bytes);f.vm(0x12340000u|authored_payload,sid%2==0);check(f.native.scene_text_bank().messages_known().empty());
        if(gameplay){check(f.native.application_lifecycle().enter_gameplay());f.write(0x3243f8,std::uint8_t(2));f.write(0x3243c0,std::uint8_t(1));}
        f.load();for(unsigned pass=0;pass<61;++pass)f.step();check(f.native.update().linked().size()==0);
        f.load(s::SceneTextVariant::standard);check(f.native.scene_text_bank().messages_known().size()==bytes.size());f.load();
    }
}
void policies(){
    for(auto duration:{std::int16_t(0),std::int16_t(1),std::int16_t(2),std::int16_t(60),std::int16_t(-32768)}){
        Fixture f(35,synthetic());f.load();f.request({0,duration,2,1});for(unsigned i=0;i<8;++i)f.step();
    }
    {Fixture f(35,synthetic());f.load();f.request({0,60,0,1});f.step();f.request({1,2,0,2});f.step();f.request({1,2,0,0});for(unsigned i=0;i<4;++i)f.step();}
    {Fixture f(35,synthetic());f.load();f.request({0,60,0,1});f.step();
        for(unsigned i=1;i<32;++i){check(f.native.update().linked().create(std::make_shared<Idle>()).status==tasks::Status::completed);f.call(0x573890,{0,0});}
        f.request({1,60,0,1});f.step();check(f.native.timed_scene_text().snapshot().tasks==0);}
    {Fixture f(35,synthetic());f.load();f.request({0,60,0,1});f.step();f.native.world().session().inventory_owner=1;f.write(0x4badee,std::uint8_t(1));f.step();check(f.native.timed_scene_text().snapshot().tasks==0);}
}
void system_messages(const std::vector<std::pair<unsigned,Bytes>>& corpus){
    for(unsigned id=0;id<63;++id){
        Fixture f(corpus.back().first,corpus.back().second);check(f.native.scene_text_bank().messages_known().empty());
        const auto lines=f.native.scene_text_bank().message_lines(std::int16_t(id),2);check(lines&&lines->lines.size()==1);
        const auto pointer=f.get<unsigned>(0x2352f0+4*id);const auto text=lines->lines.front();
        check(text.size()==std::strlen(reinterpret_cast<const char*>(f.memory.data()+pointer))+1);
        check(!std::memcmp(text.data(),f.memory.data()+pointer,text.size()));
        check(f.native.timed_scene_text().request({std::uint16_t(id),60,0,1,2})==s::TimedTextStatus::completed);
        f.call(0x570080,{id});f.compare();f.step();
        // Drawing kind2 needs no room catalog;6B68B4 later cancels through kind0.
        check(f.native.scene_text_bank().messages_known().empty());f.load();
        for(unsigned pass=1;pass<61;++pass)f.step();
        check(f.native.update().linked().size()==0);++system_cases;
    }
    {Fixture f(35,synthetic());f.load();f.request({13,60,0,1,0xabcd0002});f.step();
        f.request({12,2,1,1,2});for(unsigned i=0;i<5;++i)f.step();}
    {Fixture f(35,synthetic());f.load();f.request({0,60,0,1});f.step();f.request({13,60,0,1,2});f.step();
        f.request({1,2,0,1});for(unsigned i=0;i<4;++i)f.step();}
    {Fixture f(35,synthetic());f.load();f.request({13,60,0,1,2});f.step();
        f.native.world().session().inventory_owner=1;f.write(0x4badee,std::uint8_t(1));f.step();
        check(f.native.update().linked().size()==0);}
    {Fixture f(35,synthetic());f.request({13,60,0,1,2});f.step();
        check(f.native.timed_scene_text().close()==s::TimedTextStatus::completed);check(f.native.update().linked().size()==0);
        const auto cache=f.native.text_cache().snapshot();check(bool(cache));for(const auto& row:*cache)check(!row.active);}
    {Fixture f(35,synthetic());f.request({13,1,0,1,2});f.step();
        check(f.native.update().linked().run(tasks::Pass::update).status==tasks::Status::completed);
        check(f.native.timed_scene_text().snapshot().callback_status==s::TimedTextStatus::unavailable);++refusals;}
    {Fixture f(35,synthetic());
        for(unsigned id:{63u,64u,65535u}){check(!f.native.scene_text_bank().message_lines(std::int16_t(id),2));
            check(f.native.timed_scene_text().request({std::uint16_t(id),60,0,1,2})==s::TimedTextStatus::unavailable);++refusals;}
        check(f.native.timed_scene_text().request({13,60,0,1,1})==s::TimedTextStatus::unavailable);++refusals;}
}
void choice_catalog(){
    for(unsigned duration:{0u,1u,60u,65535u,0xabcd0002u}){
        Fixture f(35,synthetic());check(!f.native.scene_text_bank().choice_text(0));
        check(f.native.timed_scene_text().show_yes_no(duration)==s::TimedTextStatus::unavailable);++refusals;
        check(f.native.scene_text_bank().initialize_choices()==s::SceneTextBankStatus::completed);f.call(0x5a4f90);
        for(unsigned index=0;index<10;++index){const auto line=f.native.scene_text_bank().choice_text(index);check(bool(line));
            const auto at=f.get<unsigned>(0x743130+4*index);check(at==0x743160+64*index);
            check(line->size()==std::strlen(reinterpret_cast<const char*>(f.memory.data()+at))+1);
            check(!std::memcmp(line->data(),f.memory.data()+at,line->size()));++choice_rows;}
        check(!f.native.scene_text_bank().choice_text(10));
        check(f.native.timed_scene_text().show_yes_no(duration)==s::TimedTextStatus::completed);f.call(0x5a52c0,{duration});f.compare();++choice_calls;
        f.native.text_cache().reset();f.call(0x1b4a60);f.load();
        check(f.native.timed_scene_text().show_choice_prompt(0,duration)==s::TimedTextStatus::completed);f.call(0x5a5060,{0,duration});f.compare();++choice_calls;
        check(f.native.timed_scene_text().snapshot().tasks==0);
    }
    //5A5090 consumes at most two question rows, regardless of a larger count.
    {auto data=synthetic();reo::assets::put32(data.data()+8,3);reo::assets::put32(data.data()+136,0xffffffff);
        Fixture f(35,data);f.load();check(f.native.scene_text_bank().initialize_choices()==s::SceneTextBankStatus::completed);f.call(0x5a4f90);
        check(f.native.timed_scene_text().show_choice_prompt(0,2)==s::TimedTextStatus::completed);f.call(0x5a5060,{0,2});f.compare();++choice_calls;}
    // Missing common choices refuse after the source-ordered question/cue prefix.
    {Fixture f(35,synthetic());f.load();check(f.native.timed_scene_text().show_choice_prompt(0,2)==s::TimedTextStatus::unavailable);
        f.call(0x5a5090,{0,2,0});f.compare();++choice_calls;++refusals;}
    // The empty bank returns before reading the otherwise-invalid message id.
    {Fixture f(35,Bytes(2048));f.load();check(f.native.scene_text_bank().initialize_choices()==s::SceneTextBankStatus::completed);f.call(0x5a4f90);
        check(f.native.timed_scene_text().show_choice_prompt(0xffffffff,2)==s::TimedTextStatus::completed);f.call(0x5a5060,{0xffffffff,2});f.compare();++choice_calls;}
}
void boundaries(){
    {Notes notes;app::NativeSession unknown(catalog(35,synthetic()),profile(),notes);
        unknown.world().scenario=35;unknown.scene_text_bank().priority().reset_active();unknown.text_cache().reset();
        check(!unknown.timed_scene_text().ready(0)&&unknown.timed_scene_text().request(0)==s::TimedTextStatus::unavailable);++refusals;}

    {Fixture f(35,synthetic());f.vm(0);check(f.native.scene_text_bank().messages_known().empty());check(f.native.timed_scene_text().close()==s::TimedTextStatus::completed);check(f.native.update().linked().size()==0);++refusals;}
    {Fixture f(35,synthetic());f.request({0,60,0,1});check(!f.native.timed_scene_text().ready(1));check(f.native.timed_scene_text().request(1)==s::TimedTextStatus::unavailable);++refusals;}
    {Fixture f(35,synthetic());f.request({0,60,0,1});check(f.native.update().linked().run(tasks::Pass::update).status==tasks::Status::completed);
        check(f.native.timed_scene_text().snapshot().callback_status==s::TimedTextStatus::unavailable);++refusals;}
    {Fixture f(35,synthetic());f.load();f.native.world().session().asset_loading_mode=0;const auto known=f.native.scene_text_bank().messages_known();const Bytes before(reinterpret_cast<const std::uint8_t*>(known.data()),reinterpret_cast<const std::uint8_t*>(known.data()+known.size()));
        check(f.native.scene_text_bank().load_messages(s::SceneTextVariant::alternate).status==s::SceneTextBankStatus::unavailable);check(std::equal(before.begin(),before.end(),reinterpret_cast<const std::uint8_t*>(known.data())));++refusals;}
}
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    switch(context->pc){
#include "original_dispatch.hpp"
    case 0x10a830:{
        const auto destination=GPR_U32(context,4),format=GPR_U32(context,5);check(destination+128<running->memory.size()&&format<running->memory.size());
        const auto* pattern=reinterpret_cast<const char*>(memory+format);int n{};
        if(std::string_view(pattern).starts_with("%s"))n=std::snprintf(reinterpret_cast<char*>(memory+destination),128,pattern,reinterpret_cast<const char*>(memory+GPR_U32(context,6)),int(GPR_S32(context,7)));
        else n=std::snprintf(reinterpret_cast<char*>(memory+destination),128,pattern,int(GPR_S32(context,6)));
        check(n>=0&&n<128);SET_GPR_U32(context,2,n);context->pc=GPR_U32(context,31);return;
    }
    case 0x1aa3e0:case 0x1cc8f0:{
        const auto filename=std::string(reinterpret_cast<const char*>(memory+GPR_U32(context,4)));running->reads.push_back(filename);
        const auto key="r"+(running->sid<10?std::string("00"):std::string("0"))+std::to_string(running->sid)+"u.bin";
        const auto found=filename.ends_with(key);if(found){const auto dest=GPR_U32(context,5);check(dest+running->asset.size()<=running->memory.size());std::memcpy(memory+dest,running->asset.data(),running->asset.size());}
        SET_GPR_U32(context,2,found?running->asset.size():0);context->pc=GPR_U32(context,31);return;
    }
    default:throw std::runtime_error("Unexpected timed text original boundary "+std::to_string(context->pc));
    }
}
int main(int argc,char** argv)try{
    check(argc==2);std::ifstream input(argv[1],std::ios::binary);unsigned count{};input.read(reinterpret_cast<char*>(&count),4);check(count==10);
    std::vector<std::pair<unsigned,Bytes>> corpus;
    for(unsigned i=0;i<count;++i){std::array<unsigned,3> row;input.read(reinterpret_cast<char*>(row.data()),12);Bytes bytes(row[2]);input.read(reinterpret_cast<char*>(bytes.data()),bytes.size());check(bool(input));if(row[1])corpus.emplace_back(row[0],std::move(bytes));else check(bytes.empty());}
    authored(corpus);policies();system_messages(corpus);choice_catalog();boundaries();
    std::cout<<"{\"checks\":"<<checks<<",\"original_calls\":"<<original_calls<<",\"callback_passes\":"<<callbacks<<",\"vm_dispatches\":"<<vm_dispatches<<",\"loader_cases\":"<<loader_cases<<",\"system_messages\":"<<system_cases<<",\"choice_calls\":"<<choice_calls<<",\"choice_rows\":"<<choice_rows<<",\"refusals\":"<<refusals<<"}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
