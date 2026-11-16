#include "game/native/gameplay_application/native_session.hpp"
#include "runtime/assets/virtual_afs.h"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include "authored_command.hpp"
#include <iostream>
#include <source_location>
#include <string>
#include <functional>
namespace app=reo::native::gameplay_application;namespace s=reo::native::gameplay_scenario;
namespace w=reo::native::gameplay_world;
namespace {
using Bytes=std::vector<std::uint8_t>;
std::uint64_t checks{},calls{},cases{},vm_dispatches{},refusals{},allocations{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Inventory resources check "+std::to_string(at.line()));
}
struct Notes final:s::FlagNotifications {
    bool changed(const s::ScenarioFlagChange&)noexcept override{std::terminate();}
    bool changed(const s::StridedFlagChange&)noexcept override{std::terminate();}
};
w::Profile profile(){w::Profile value;value.layouts.push_back({});return value;}
struct ObservedSource final:reo::assets::PositionedSource {
    std::shared_ptr<const reo::assets::Source> input;
    std::function<void(std::uint64_t)> before;
    explicit ObservedSource(std::shared_ptr<const reo::assets::Source> value):input(std::move(value)){}
    std::uint64_t size()const noexcept override{return input->size;}
    std::size_t read(std::uint64_t at,std::size_t n,void* out)const override{
        if(before)before(at);input->read(at,n,out);return n;
    }
};
struct Fixture;Fixture* running{};
struct Fixture {
    Notes notes;std::shared_ptr<const reo::assets::Source> source;app::NativeSession native;
    Bytes memory=Bytes(0x2000000);unsigned sid{};std::vector<std::string> reads;bool fail_file{};
    Fixture(std::shared_ptr<const reo::assets::Source> input,unsigned scenario,bool alternate,bool paused,unsigned mode,unsigned seed):source(std::move(input)),native(source,profile(),notes),sid(scenario){
        check(!running);running=this;owned_constants(memory.data());native.world().scenario=std::uint16_t(sid);
        check(native.inventory_ui().initialize()==w::InventoryUiStatus::completed);
        check(native.select_scene_message_catalog(alternate?s::SceneTextVariant::alternate:s::SceneTextVariant::standard)==app::SessionStatus::completed);
        native.world().paused=paused;native.world().session().asset_loading_mode=mode;
        native.world().session().random.restore({std::uint16_t(seed),19,0});
        write(0x3243da,std::uint16_t(sid));write(0x3243fd,std::uint8_t(alternate));write(0x3243d7,std::uint8_t(mode));
        write(0x4badf8,std::uint8_t(paused));write(0x324440,0xa00000u);write(0x324450,0xb00000u);
        write(0x3244b0,std::uint16_t(seed));write(0x3244b8,std::uint16_t(19));write(0x29f9bc,2u);
        write(0x4bae7c,std::uint8_t(99));write(0x4bae7d,std::uint8_t(98));write(0x4bae7e,std::uint8_t(97));
        check(!native.inventory_ui_resources().snapshot().cache_known);
    }
    ~Fixture(){running=nullptr;}
    template<class T>void write(unsigned at,T value){transform_write(memory.data(),at,value);}
    template<class T>T get(unsigned at)const{return transform_read<T>(memory.data(),at);}
    void original(){R5900Context c;PS2Runtime r;c.pc=0x604310;SET_GPR_U32(&c,29,0x1f00000);SET_GPR_U32(&c,31,0xabcdef);original_transform_port(memory.data(),&c,&r);check(c.pc==0xabcdef&&GPR_U32(&c,29)==0x1f00000);++calls;}
    void image(const s::InventoryImage& image,unsigned at){
        const auto indices=get<unsigned>(at+0x18),palette=get<unsigned>(at+0x1c);
        check(indices+image.indices.size()<memory.size());
        check(std::equal(image.indices.begin(),image.indices.end(),reinterpret_cast<const std::byte*>(memory.data()+indices)));
        for(unsigned i=0;i<image.palettes.size();++i){
            if(image.palettes[i]!=get<unsigned>(palette+4*i))std::cerr<<"Palette difference scenario="<<sid<<" record="<<std::hex<<at<<" index="<<i<<" native="<<image.palettes[i]<<" original="<<get<unsigned>(palette+4*i)<<std::dec<<'\n';
            check(image.palettes[i]==get<unsigned>(palette+4*i));
        }
    }
    void blob(const s::content::Bytes& bytes,unsigned pointer){
        const auto at=get<unsigned>(pointer);check(bool(bytes)==bool(at));
        if(bytes){check(at+bytes->size()<memory.size());check(std::equal(bytes->begin(),bytes->end(),reinterpret_cast<const std::byte*>(memory.data()+at)));}
    }
    void compare(){
        const auto& state=native.inventory_ui_resources().snapshot();check(state.cache_known);
        check(native.inventory_ui().request_blocked()==get<std::uint8_t>(0x4bae8d));
        for(unsigned i=0;i<3;++i)check(state.cache[i]==get<std::uint8_t>(0x4bae7c+i));
        check(native.world().session().sound_loading_mode==get<std::uint8_t>(0x324405));
        check(native.world().session().random.state().primary==get<std::uint16_t>(0x3244b0));
        if(native.world().paused){check(reads.empty());return;}
        blob(state.common_text,0x755778);blob(state.scenario_text,0x755780);blob(state.special_items,0x755798);
        if(state.result_present)check(*state.result_present==bool(get<unsigned>(0x755760)));
        if(native.world().session().sound_loading_mode!=1){check(!state.item_icons&&!state.background);return;}
        check(state.item_icons&&state.file_icons&&state.background);
        image(*state.item_icons,0x755d80);image(*state.file_icons,0x755e0c);
        const auto header=get<unsigned>(0x755d78);check(header);image(*state.background,header);
        for(unsigned i=0;i<32;++i){const auto& p=state.particles[i];
            check(p.angle==get<unsigned>(header+0xac+4*i));check(p.selector==get<std::uint8_t>(header+0x56c+i));
            check(std::bit_cast<unsigned>(p.velocity_x)==get<unsigned>(header+0x12c+8*i));check(std::bit_cast<unsigned>(p.velocity_y)==get<unsigned>(header+0x130+8*i));
            check(p.offset_x==get<std::int8_t>(header+0x52c+2*i));check(p.offset_y==get<std::int8_t>(header+0x52d+2*i));
            check(std::bit_cast<unsigned>(p.x)==get<unsigned>(header+0x32c+8*i));check(std::bit_cast<unsigned>(p.y)==get<unsigned>(header+0x330+8*i));
        }
    }
    void command(bool vm=false){
        check(native.inventory_ui().request_mode_ready(0));
        if(vm){std::vector<std::byte> bytes(16);const std::array<unsigned,4> words{1,authored_header,0,0xa};std::memcpy(bytes.data(),words.data(),bytes.size());
            auto p=std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{bytes},s::DispatchProfile::ordinary);
            s::Interpreter interpreter;s::Providers providers;providers.world=&native.world();providers.inventory_ui=&native.inventory_ui();
            check(interpreter.install(0,p)==s::Status::completed);check(interpreter.tick(0,{},providers).status==s::Status::yielded);++vm_dispatches;
        }else check(native.inventory_ui().configure_requests(0)==w::InventoryUiStatus::completed);
        original();compare();++cases;
    }
    s::content::Bytes read(std::string filename,bool scenario){
        reads.push_back(filename);const auto slash=filename.find_last_of("\\/");if(slash!=std::string::npos)filename.erase(0,slash+1);
        if(fail_file&&filename=="file.img")throw std::runtime_error("Authored original IO failure");
        if(scenario)return native.archive().read_resource_sectors(sid,filename);
        const std::array<std::pair<const char*,unsigned>,5> known{{{"itmsge.dat",510},{"spitem.dat",511},{"cp_back.img",514},{"file.img",515},{"itemicon.img",516}}};
        const auto match=std::find_if(known.begin(),known.end(),[&](const auto& e){return filename==e.first;});if(match==known.end())return{};
        const auto roots=reo::assets::table(*source,0,source->size);const auto rom=std::find_if(roots.entries.begin(),roots.entries.end(),[](const auto& e){return e.name=="romdata_usa.afs";});check(rom!=roots.entries.end());
        const auto table=reo::assets::table(*source,rom->offset,rom->size);const auto& entry=table.entries.at(match->second);
        auto bytes=std::make_shared<std::vector<std::byte>>((entry.size+2047)&~2047u);source->read(std::uint64_t(rom->offset)+entry.offset,bytes->size(),bytes->data());return bytes;
    }
};
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    switch(context->pc){
#include "original_dispatch.hpp"
    case 0x10a830:{const auto destination=GPR_U32(context,4);const auto* pattern=reinterpret_cast<const char*>(memory+GPR_U32(context,5));int n{};
        if(std::string_view(pattern).starts_with("%s"))n=std::snprintf(reinterpret_cast<char*>(memory+destination),128,pattern,reinterpret_cast<const char*>(memory+GPR_U32(context,6)),int(GPR_S32(context,7)));
        else n=std::snprintf(reinterpret_cast<char*>(memory+destination),128,pattern,int(GPR_S32(context,6)));
        check(n>=0&&n<128);SET_GPR_U32(context,2,n);break;}
    case 0x1aa3e0:case 0x1cc8f0:{const bool scenario=context->pc==0x1aa3e0||(GPR_U32(context,6)&0x10000u);const auto bytes=running->read(reinterpret_cast<const char*>(memory+GPR_U32(context,4)),scenario);
        if(bytes){const auto at=GPR_U32(context,5);check(at+bytes->size()<running->memory.size());std::memcpy(memory+at,bytes->data(),bytes->size());}
        SET_GPR_U32(context,2,bytes?bytes->size():0);break;}
    case 0x19c8e0:check(GPR_U32(context,4)==1792);SET_GPR_U32(context,2,0x80);++allocations;break;
    case 0x6d8e30:throw std::runtime_error("Unexpected nonzero inventory refresh family");
    default:throw std::runtime_error("Unexpected inventory original boundary "+std::to_string(context->pc));
    }
    context->pc=GPR_U32(context,31);
}
int main(int argc,char** argv)try{
    check(argc==2);const auto source=std::make_shared<const reo::assets::Source>(argv[1]);
    for(unsigned sid:{1u,2u,28u,35u,41u})for(bool alternate:{false,true})for(unsigned mode:{0u,1u}){
        Fixture f(source,sid,alternate,false,mode,sid*911);f.command(true);f.command();
    }
    {Fixture f(source,41,true,true,1,0);f.command();check(!f.native.inventory_ui_resources().snapshot().context_identity);}
    {Fixture f(source,41,true,false,1,0);f.native.world().session().sound_loading_mode=2;f.write(0x324405,std::uint8_t(2));f.command();}
    {Fixture f(source,41,true,false,1,1);f.native.world().session().sound_loading_mode=1;check(!f.native.inventory_ui().request_mode_ready(0));check(f.native.inventory_ui().configure_requests(0)==w::InventoryUiStatus::unavailable_request_reset);check(!f.native.inventory_ui_resources().snapshot().cache_known);++refusals;}
    {Notes notes;app::NativeSession native(source,profile(),notes),foreign(source,profile(),notes);
        check(native.inventory_ui().initialize()==w::InventoryUiStatus::completed);
        auto& owner=native.inventory_ui_resources();
        check(!owner.ready_zero());check(native.inventory_ui().configure_requests(0)==w::InventoryUiStatus::unavailable_request_reset);
        check(!owner.snapshot().cache_known);++refusals;
        check(native.inventory_ui().bind_resources(&foreign.inventory_ui_resources(),&owner)==w::InventoryUiStatus::unavailable_request_reset);++refusals;
        check(native.inventory_ui().resources()==&owner);native.world().paused=1;
        check(native.inventory_ui().configure_requests(0)==w::InventoryUiStatus::completed);
        check(owner.snapshot().cache_known&&!owner.snapshot().context_identity);
    }
    {const auto roots=reo::assets::table(*source,0,source->size);const auto rom=std::find_if(roots.entries.begin(),roots.entries.end(),[](const auto& e){return e.name=="romdata_usa.afs";});check(rom!=roots.entries.end());
        const auto table=reo::assets::table(*source,rom->offset,rom->size);const std::uint64_t at=std::uint64_t(rom->offset)+table.entries.at(515).offset;
        auto observed=std::make_shared<ObservedSource>(source);auto input=std::make_shared<const reo::assets::Source>("inventory-observed-input",observed);
        Fixture f(input,41,true,false,1,129);unsigned reentrant{};
        observed->before=[&](std::uint64_t offset){if(offset!=at)return;++reentrant;
            auto& owner=f.native.inventory_ui_resources();check(owner.busy());
            check(f.native.close()==app::SessionStatus::busy);check(owner.close()==s::InventoryResourcesStatus::busy);
            check(f.native.inventory_ui().bind_resources(nullptr,&owner)==w::InventoryUiStatus::busy);
            check(f.native.inventory_ui().resources()==&owner);throw std::runtime_error("Authored native IO failure");};
        check(f.native.inventory_ui().configure_requests(0)==w::InventoryUiStatus::unavailable_request_reset);check(reentrant==1);++refusals;
        observed->before={};f.fail_file=true;bool failed{};try{f.original();}catch(const std::runtime_error&){failed=true;}check(failed);f.fail_file=false;
        const auto& state=f.native.inventory_ui_resources().snapshot();
        check(f.native.inventory_ui().request_blocked()==0);check(state.cache_known&&state.cache==std::array<std::uint8_t,3>{});
        check(state.item_icons&&!state.file_icons&&!state.background);check(bool(state.context_identity));
        f.blob(state.common_text,0x755778);f.blob(state.scenario_text,0x755780);f.blob(state.special_items,0x755798);f.image(*state.item_icons,0x755d80);
        check(f.native.world().session().random.state().primary==129);check(f.get<std::uint16_t>(0x3244b0)==129);
        f.command();
    }
    std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"original_calls\":"<<calls<<",\"vm_dispatches\":"<<vm_dispatches<<",\"allocation_observations\":"<<allocations<<",\"refusals\":"<<refusals<<"}\n";return 0;
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
