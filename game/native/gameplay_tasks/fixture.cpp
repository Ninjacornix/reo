// Verification client only. The native library itself has no text/ABI parser.
#include "tasks.hpp"
#include "events.hpp"
#include <array>
#include <bit>
#include <cstdint>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
namespace g=reo::native::gameplay_tasks;
struct Client;
struct Work final:g::Task {
    Client& client;int id{},action{},argument{};
    Work(Client& c,int value,int a,int arg):client(c),id(value),action(a),argument(arg){}
    void execute(g::Scheduler&,const g::Handle&,bool)noexcept;
    void update(g::Scheduler& s,const g::Handle& h)noexcept override{execute(s,h,false);}
    void present(g::Scheduler& s,const g::Handle& h)noexcept override{execute(s,h,true);}
};
struct Client {
    g::Scheduler scheduler;std::array<g::Handle,256> handles{};std::vector<int> events,success;
    void create(int id,int placement,int active,int mask,int secondary,int action=0,int arg=0){
        const auto created=scheduler.create(std::make_shared<Work>(*this,id,action,arg),
            {static_cast<std::uint8_t>(active),static_cast<std::uint8_t>(mask),bool(secondary)},
            placement?g::Placement::oldest:g::Placement::newest);
        success.push_back(created.status==g::Status::completed);
        if(created.status==g::Status::completed)handles.at(std::size_t(id))=created.handle;
    }
    void erase(int id){success.push_back(scheduler.erase(handles.at(std::size_t(id)))==g::Status::completed);}
};
void Work::execute(g::Scheduler& owner,const g::Handle& self,bool secondary)noexcept{
    client.events.push_back(id+(secondary?1000:0));const auto operation=action;action=0;
    switch(operation){
    case 1:client.success.push_back(owner.erase(self)==g::Status::completed);break;
    case 2:client.create(argument,0,1,0,0);break;
    case 3:client.create(argument,1,1,0,0);break;
    case 4:client.erase(argument);break;
    case 5:client.erase(argument);client.create(argument+2,0,1,0,0);break;
    default:break;
    }
}
struct Expiries final:g::FlagSink {
    g::FlagTimers& timers;std::vector<int> events;int mutation{};
    explicit Expiries(g::FlagTimers& t):timers(t){}
    void expired(const g::FlagExpiry& event)noexcept override{
        events.insert(events.end(),{int(event.slot),int(event.target.scope==g::FlagScope::session_owner_zero),event.target.id});
        if(mutation && event.slot==0){mutation=0;timers.arm(0,2,{g::FlagScope::scenario,31});timers.arm(1,1,{g::FlagScope::session_owner_zero,32});}
    }
};
struct EventClient;
struct EventWork final:g::EventTask {
    EventClient& client;int id,action,argument;
    EventWork(EventClient& c,int value,int a,int arg):client(c),id(value),action(a),argument(arg){}
    void update(g::EventTasks&,const g::Handle&,g::EventContext)noexcept override;
};
struct EventClient{
    g::EventTasks owner;g::OwnerSelection selected;std::array<g::Handle,256> handles{};std::vector<int> events,success;
    void install(int id,int bank,int slot,int action,int arg){auto r=owner.install(std::size_t(bank),std::size_t(slot),std::make_shared<EventWork>(*this,id,action,arg));success.push_back(r.status==g::Status::completed);if(r.status==g::Status::completed)handles.at(std::size_t(id))=r.handle;}
    void erase(int id){success.push_back(owner.erase(handles.at(std::size_t(id)))==g::Status::completed);}
};
void EventWork::update(g::EventTasks&,const g::Handle&,g::EventContext context)noexcept{
    client.events.insert(client.events.end(),{id,context.bank,context.slot,context.owner.actor});const auto operation=action;action=0;
    if(operation==1)client.erase(id);
    else if(operation==2)client.install(id+100,argument/10,argument%10,0,0);
    else if(operation==3)client.erase(argument);
    else if(operation==4)context.owner.actor=static_cast<std::uint8_t>(argument);
}
int main(){
    std::string line;
    while(std::getline(std::cin,line)){
        if(line.empty())continue;std::istringstream input(line);char kind;unsigned count;input>>kind>>count;
        if(kind=='S'){
            Client c;
            for(unsigned i=0;i<count;++i){char op;input>>op;
                if(op=='C'){int id,where,active,mask,secondary,action,arg;input>>id>>where>>active>>mask>>secondary>>action>>arg;c.create(id,where,active,mask,secondary,action,arg);}
                else if(op=='D'){int id;input>>id;c.erase(id);}
                else if(op=='F'){int id,active,mask,secondary;input>>id>>active>>mask>>secondary;c.success.push_back(c.scheduler.policy(c.handles.at(std::size_t(id)),{static_cast<std::uint8_t>(active),static_cast<std::uint8_t>(mask),bool(secondary)})==g::Status::completed);}
                else if(op=='P'||op=='R'){if(c.scheduler.run(op=='P'?g::Pass::update:g::Pass::presentation).status!=g::Status::completed)return 2;}
                else return 3;
            }
            std::cout<<"S "<<c.events.size();for(auto value:c.events)std::cout<<' '<<value;
            std::vector<unsigned> alive;for(unsigned i=0;i<c.handles.size();++i)if(c.scheduler.contains(c.handles[i]))alive.push_back(i);
            std::cout<<' '<<alive.size();for(auto value:alive)std::cout<<' '<<value;
            std::cout<<' '<<c.success.size();for(auto value:c.success)std::cout<<' '<<value;std::cout<<'\n';
        }else if(kind=='E'){
            EventClient c;
            for(unsigned i=0;i<count;++i){char op;input>>op;
                if(op=='I'){int id,bank,slot,action,arg;input>>id>>bank>>slot>>action>>arg;c.install(id,bank,slot,action,arg);}
                else if(op=='D'){int id;input>>id;c.erase(id);}
                else if(op=='F'){int id,enabled;input>>id>>enabled;c.success.push_back(c.owner.enabled(c.handles.at(std::size_t(id)),bool(enabled))==g::Status::completed);}
                else if(op=='P'){int mode,selected;input>>mode>>selected;c.selected.actor=static_cast<std::uint8_t>(selected);c.owner.run(mode==1?g::EventMode::owner_banks:g::EventMode::shared_bank,c.selected);}
                else return 8;
            }
            std::cout<<"E "<<unsigned(c.selected.actor)<<' '<<c.events.size();for(auto value:c.events)std::cout<<' '<<value;
            std::vector<unsigned> alive;for(unsigned i=0;i<c.handles.size();++i)if(c.owner.contains(c.handles[i]))alive.push_back(i);
            std::cout<<' '<<alive.size();for(auto value:alive)std::cout<<' '<<value;std::cout<<' '<<c.success.size();for(auto value:c.success)std::cout<<' '<<value;std::cout<<'\n';
        }else if(kind=='T'){
            g::FlagTimers timers;Expiries sink(timers);
            for(unsigned i=0;i<count;++i){char op;input>>op;
                if(op=='A'){std::uint32_t slot,type,id,ticks;input>>slot>>type>>id>>ticks;const auto packed=static_cast<std::uint16_t>(id|(type?0x8000u:0));
                    timers.arm(slot,std::bit_cast<std::int16_t>(static_cast<std::uint16_t>(ticks)),{packed&0x8000?g::FlagScope::session_owner_zero:g::FlagScope::scenario,static_cast<std::uint16_t>(packed&0x7fff)});}
                else if(op=='T')timers.tick(sink);else if(op=='M')sink.mutation=1;else return 4;
            }
            std::cout<<"T";for(const auto& slot:timers.snapshot())std::cout<<' '<<slot.remaining<<' '<<(slot.target.id|(slot.target.scope==g::FlagScope::session_owner_zero?0x8000:0));
            std::cout<<' '<<sink.events.size();for(auto value:sink.events)std::cout<<' '<<value;std::cout<<'\n';
        }else if(kind=='K'){
            unsigned h,m,s,f,mode;input>>h>>m>>s>>f>>mode;g::SimulationClock clock;
            if(clock.restore({std::uint8_t(h),std::uint8_t(m),std::uint8_t(s),std::uint8_t(f)},0)!=g::Status::completed)return 5;
            for(unsigned i=0;i<count;++i)clock.commit_update(mode?g::ClockStep::two:g::ClockStep::one);
            const auto time=clock.play_time();std::cout<<"K "<<unsigned(time.hours)<<' '<<unsigned(time.minutes)<<' '<<unsigned(time.seconds)<<' '<<unsigned(time.sixtieths)<<'\n';
        }else return 6;
        if(!input)return 7;
    }
}
