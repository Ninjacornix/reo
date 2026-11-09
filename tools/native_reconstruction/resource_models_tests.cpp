#include "game/native/gameplay_world/resource_models.hpp"
#include "reference.hpp"
#include <functional>
#include <iostream>
#include <source_location>
#include <vector>
namespace g=reo::native::gameplay_world;
constexpr unsigned pool=0x3f4010,stride=0x250,work_entry=0x110000;
std::uint64_t checks{},operations{},passes{},source_calls{},refusals{},reuse_cases{};
std::string active_case;
std::function<void(unsigned)> source_work;
std::vector<unsigned> source_order,native_order;
unsigned source_post{},native_post{};
void check(bool yes,const std::source_location at=std::source_location::current()){
    ++checks;if(!yes)throw std::runtime_error(active_case+" line "+std::to_string(at.line()));
}
template<class T>T read(const std::uint8_t* ram,unsigned at){return transform_read<T>(ram,at);}
template<class T>void put(std::uint8_t* ram,unsigned at,T value){transform_write(ram,at,value);}
void original_transform_port(std::uint8_t* ram,R5900Context* ctx,PS2Runtime* runtime){
    ++source_calls;
    switch(ctx->pc){
#include "dispatch.inc"
        case 0x107c68:std::memset(ram+GPR_U32(ctx,4),GPR_U32(ctx,5)&255,GPR_U32(ctx,6));break;
        case work_entry:{const auto at=GPR_U32(ctx,4);source_order.push_back((at-pool)/stride);++ram[at+9];if(source_work)source_work(at);break;}
        case 0x6aeda0:++source_post;break;
        default:throw std::runtime_error("Unadmitted resource owner dependency "+std::to_string(ctx->pc));
    }
    ctx->pc=GPR_U32(ctx,31);
}
R5900Context call(std::uint8_t* ram,unsigned at,unsigned argument=0){
    R5900Context ctx{};PS2Runtime runtime;ctx.pc=at;SET_GPR_U32(&ctx,4,argument);SET_GPR_U32(&ctx,29,0x1f00000);SET_GPR_U32(&ctx,31,0xabcdef);original_transform_port(ram,&ctx,&runtime);check(ctx.pc==0xabcdef&&GPR_U32(&ctx,29)==0x1f00000);return ctx;
}
struct Work final:g::ResourceModelWork {
    std::function<void(g::ResourceModels&,const g::ResourceModelId&,g::ResourceModel&)> action;
    void update(g::ResourceModels& owner,const g::ResourceModelId& id,g::ResourceModel& model)override{
        const auto slot=owner.physical_slot(id);check(slot.has_value());native_order.push_back(*slot);++model.program.phase;if(action)action(owner,id,model);
    }
};
struct Post final:g::ResourceModelPostUpdate {void apply(g::ResourceModels&)override{++native_post;}};
struct Fixture {
    std::vector<std::uint8_t> ram=std::vector<std::uint8_t>(0x2000000);
    g::ResourceModels owner;
    std::array<g::ResourceModelId,64> ids;
    std::shared_ptr<Work> work=std::make_shared<Work>();
    Fixture(){source_work={};call(ram.data(),0x590be0);}
    std::optional<unsigned> native_slot(const g::ResourceModelId& id)const{const auto found=owner.physical_slot(id);return found?std::optional<unsigned>(*found):std::nullopt;}
    unsigned address(const g::ResourceModelId& id)const{const auto slot=native_slot(id);return slot?pool+stride**slot:0;}
    void compare(){
        check(owner.available()==read<std::uint16_t>(ram.data(),0x3b5700));check(address(owner.head())==read<unsigned>(ram.data(),0x3b5708)&&address(owner.tail())==read<unsigned>(ram.data(),0x3b5710));
        std::size_t count{};
        for(auto id=owner.head();id;id=owner.next(id)){
            const auto slot=native_slot(id);check(slot.has_value());const auto at=pool+stride**slot;const auto model=owner.retain(id);check(model&&model->current());
            check(model->physical_slot==ram[at+6]&&model->program.phase==ram[at+9]);check(address(owner.previous(id))==read<unsigned>(ram.data(),at+0x1c)&&address(owner.next(id))==read<unsigned>(ram.data(),at+0x20));check(++count<=64);
        }
        check(count+owner.available()==64);
    }
    std::optional<unsigned> create(bool front){
        const auto original=call(ram.data(),0x590c70,front);const auto native=owner.create(front?g::ResourceModelPlacement::front:g::ResourceModelPlacement::back);const auto raw=GPR_U32(&original,2);
        check((native.status==g::ResourceModelStatus::completed)==bool(raw));
        if(!raw){check(native.status==g::ResourceModelStatus::full);return{};}
        const auto slot=native_slot(native.id);check(slot&&pool+stride**slot==raw);ids[*slot]=native.id;native.model->work=work;put(ram.data(),raw+0x14,work_entry);compare();++operations;return slot;
    }
    void retire(unsigned slot){
        const auto id=ids[slot];const auto retained=owner.retain(id);check(bool(retained));const auto original=call(ram.data(),0x590d80,pool+stride*slot);check(GPR_U32(&original,2)==1);
        check(owner.retire(id)==g::ResourceModelStatus::completed&&!owner.retain(id)&&!retained->current());check(retained->flags==0&&!retained->work&&retained->program.phase==0);ids[slot]={};compare();++operations;
    }
};
int main()try{
    {
        active_case="capacity and LIFO reuse";Fixture f;for(unsigned i=0;i<64;++i){const auto slot=f.create(i%2!=0);check(slot&&*slot==63-i);}check(!f.create(false));
        std::vector<std::shared_ptr<g::ResourceModel>> retired;
        for(unsigned slot=0;slot<64;slot+=3){retired.push_back(f.owner.retain(f.ids[slot]));f.retire(slot);}
        for(int slot=63;slot>=0;--slot)if(slot%3==0){const auto found=f.create(slot%2!=0);check(found&&*found==unsigned(slot));}
        for(const auto& old:retired)check(!old->current());
        std::uint32_t random=0x5122;
        for(unsigned step=0;step<4096;++step){random=random*1664525u+1013904223u;const unsigned slot=(random>>16)%64;if(f.owner.retain(f.ids[slot]))f.retire(slot);else(void)f.create(random&1);}
    }
    for(unsigned action=0;action<10;++action)for(unsigned trigger=0;trigger<8;++trigger)for(bool skip:{false,true}){
        active_case="mutation action="+std::to_string(action)+" trigger="+std::to_string(trigger)+" skip="+std::to_string(skip);Fixture f;for(unsigned i=0;i<8;++i)(void)f.create(i%2!=0);
        bool source_done{},native_done{};const unsigned target=56+trigger;
        source_work=[&](unsigned at){if(source_done||(at-pool)/stride!=target)return;source_done=true;
            if(action==1)(void)call(f.ram.data(),0x590d80,at);
            if(action==2||action==3){const auto neighbor=read<unsigned>(f.ram.data(),at+(action==2?0x1c:0x20));if(neighbor)(void)call(f.ram.data(),0x590d80,neighbor);}
            if(action==4||action==5){const auto created=call(f.ram.data(),0x590c70,action==4);put(f.ram.data(),GPR_U32(&created,2)+0x14,work_entry);}
            if(action==6)f.ram[0x745d50]=1;
            if(action>=7){(void)call(f.ram.data(),0x590d80,at);const auto created=call(f.ram.data(),0x590c70,action==8);const auto next=GPR_U32(&created,2);put(f.ram.data(),next+0x14,work_entry);if(action==9){const auto again=call(f.ram.data(),0x590c70);put(f.ram.data(),GPR_U32(&again,2)+0x14,work_entry);}}
        };
        f.work->action=[&](g::ResourceModels& owner,const g::ResourceModelId& id,g::ResourceModel&){const auto slot=owner.physical_slot(id);check(slot.has_value());if(native_done||*slot!=target)return;native_done=true;
            if(action==1)check(owner.retire(id)==g::ResourceModelStatus::completed);
            if(action==2||action==3){const auto neighbor=action==2?owner.previous(id):owner.next(id);if(neighbor)check(owner.retire(neighbor)==g::ResourceModelStatus::completed);}
            if(action==4||action==5){const auto created=owner.create(action==4?g::ResourceModelPlacement::front:g::ResourceModelPlacement::back);check(created.status==g::ResourceModelStatus::completed);created.model->work=f.work;f.ids[*owner.physical_slot(created.id)]=created.id;}
            if(action==6)owner.request_refresh();
            if(action>=7){const auto retired=owner.retain(id);check(owner.retire(id)==g::ResourceModelStatus::completed&&!retired->current()&&!owner.retain(id));const auto created=owner.create(action==8?g::ResourceModelPlacement::front:g::ResourceModelPlacement::back);check(created.status==g::ResourceModelStatus::completed&&created.id!=id&&created.model!=retired);created.model->work=f.work;f.ids[*owner.physical_slot(created.id)]=created.id;if(action==9){const auto again=owner.create();check(again.status==g::ResourceModelStatus::completed);again.model->work=f.work;f.ids[*owner.physical_slot(again.id)]=again.id;}++reuse_cases;}
        };
        source_order.clear();native_order.clear();source_post=native_post=0;f.ram[0x4bae9a]=skip?7:0;f.ram[0x745d50]=1;f.owner.request_refresh();
        call(f.ram.data(),0x590ea0);Post post;const auto result=f.owner.update(skip,&post);check(result.status==g::ResourceModelStatus::completed&&result.called==source_order.size()&&source_order==native_order&&source_post==native_post&&f.owner.refresh_requested()==bool(f.ram[0x745d50]));f.compare();++passes;
    }
    {
        active_case="native identity/refusal extensions";Fixture f;const auto slot=f.create(false);check(slot.has_value());const auto old=f.ids[*slot];auto retained=f.owner.retain(old);f.retire(*slot);check(f.create(false)==slot&&f.ids[*slot]!=old&&retained!=f.owner.retain(f.ids[*slot])&&!retained->current());++refusals;
        g::ResourceModels foreign;check(f.owner.retire({})==g::ResourceModelStatus::foreign_or_stale&&!foreign.retain(f.ids[*slot]));++refusals;
        f.owner.retain(f.ids[*slot])->work.reset();check(f.owner.update(false).status==g::ResourceModelStatus::unavailable);++refusals;
        f.owner.retain(f.ids[*slot])->work=f.work;check(f.owner.update(false,nullptr,0).status==g::ResourceModelStatus::budget_exhausted);++refusals;
        f.work->action=[&](g::ResourceModels& owner,const g::ResourceModelId& id,g::ResourceModel&){check(owner.retire(id)==g::ResourceModelStatus::completed);const auto next=owner.create();check(next.status==g::ResourceModelStatus::completed);next.model->work=f.work;};
        check(f.owner.update(false).status==g::ResourceModelStatus::completed);++reuse_cases;
        auto live=f.owner.retain(f.owner.head());check(f.owner.close()==g::ResourceModelStatus::completed&&!live->current()&&f.owner.create().status==g::ResourceModelStatus::closed&&f.owner.update(false).status==g::ResourceModelStatus::closed);++refusals;
    }
    std::cout<<"{\"checks\":"<<checks<<",\"operations\":"<<operations<<",\"passes\":"<<passes<<",\"source_calls\":"<<source_calls<<",\"refusals\":"<<refusals<<",\"reuse_cases\":"<<reuse_cases<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
