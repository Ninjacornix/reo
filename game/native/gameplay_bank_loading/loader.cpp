#include "loader.hpp"
#include "aliases.hpp"
#include "../resource_io/async_read_owner.hpp"
#include "../tasks/serial_worker.hpp"
#include <atomic>
#include <algorithm>
#include <stdexcept>
namespace reo::native::gameplay_bank_loading {
struct LoadDomain {};
struct Loader::State {
    enum class Phase {empty,queued,awaiting_read,reading,preparing,ready};
    struct Completion {gameplay_audio::BankResult result;std::atomic<bool> done{};};
    struct Slot {
        std::uint64_t id{};
        Phase phase{Phase::empty};
        std::array<char,16> name{};
        unsigned port{};
        resource_io::Ticket read;
        gameplay_audio::BankTicket bank;
        std::shared_ptr<const resources::ByteView> source;
        std::shared_ptr<Completion> completion;
        LoadResult result;
    };
    std::shared_ptr<gameplay_audio::Owner> owner;
    std::shared_ptr<const afs_source_range::Archive> archive;
    resource_io::AsyncReadOwner reads{{1,1024*1024,2*1024*1024}};
    tasks::SerialWorker prepare{1};
    std::array<Slot,9> slots;
    std::array<std::size_t,8> queue{};
    std::size_t head{},count{};
    std::optional<std::size_t> active;
    struct Cached {unsigned member;std::array<char,16> name;gameplay_audio::BankTicket bank;};
    std::array<std::optional<Cached>,14> cache;
    std::uint64_t serial{};
    bool closed{};
    State(std::shared_ptr<gameplay_audio::Owner> value,std::shared_ptr<const afs_source_range::Archive> input):owner(std::move(value)),archive(std::move(input)){}
    void finish(std::size_t i,LoadStatus status)noexcept{
        auto& slot=slots[i];
        if(status!=LoadStatus::completed&&status!=LoadStatus::cached&&slot.bank)(void)owner->cancel(slot.bank);
        slot.source.reset();slot.result.status=status;slot.phase=Phase::ready;active.reset();
    }
};
Loader::Loader(std::shared_ptr<gameplay_audio::Owner> owner,std::shared_ptr<const afs_source_range::Archive> archive)
    :domain_(std::make_shared<const LoadDomain>()){
    if(!owner||!archive||archive->count()!=422)throw std::invalid_argument("Native named banks require the actual File1 sound archive/owner");
    state_=std::make_unique<State>(std::move(owner),std::move(archive));
}
Loader::~Loader(){shutdown();if(!join())std::terminate();}
std::optional<std::size_t> Loader::locate(const LoadTicket& ticket)const noexcept{
    if(!ticket.id_||ticket.domain_.lock()!=domain_)return{};
    for(std::size_t i=0;i<state_->slots.size();++i)if(state_->slots[i].id==ticket.id_&&state_->slots[i].phase!=State::Phase::empty)return i;
    return{};
}
Submitted Loader::enqueue(std::string_view name,unsigned port)noexcept{
    auto& s=*state_;
    if(s.closed)return {LoadStatus::closed,{}};
    if(port>=14)return {LoadStatus::invalid_input,{}};
    if(s.count==s.queue.size())return {LoadStatus::full,{}};
    if(s.serial==UINT64_MAX)return {LoadStatus::capacity,{}};
    std::size_t i{};while(i<s.slots.size()&&s.slots[i].phase!=State::Phase::empty)++i;
    if(i==s.slots.size())return {LoadStatus::full,{}};
    auto& slot=s.slots[i];slot={};slot.id=++s.serial;slot.phase=State::Phase::queued;slot.port=port;
    name=name.substr(0,name.find('\0'));name=name.substr(0,15);std::copy(name.begin(),name.end(),slot.name.begin());
    s.queue[(s.head+s.count)%s.queue.size()]=i;++s.count;
    LoadTicket ticket;ticket.domain_=domain_;ticket.id_=slot.id;return {LoadStatus::accepted,ticket};
}
void Loader::service()noexcept{
    auto& s=*state_;if(s.closed)return;
    try{
        if(s.active){
            const auto i=*s.active;auto& slot=s.slots[i];
            if(slot.phase==State::Phase::awaiting_read){
                const auto read=s.reads.submit(slot.source,0,std::size_t(slot.source->size()));
                if(read.status==resource_io::SubmitStatus::request_capacity||read.status==resource_io::SubmitStatus::byte_budget)return;
                if(read.status!=resource_io::SubmitStatus::accepted){s.finish(i,LoadStatus::source_failure);return;}
                slot.read=read.ticket;slot.source.reset();slot.phase=State::Phase::reading;
            }
            if(slot.phase==State::Phase::reading){
                auto ready=s.reads.poll(slot.read);
                if(ready.status==resource_io::PollStatus::pending)return;
                if(ready.status!=resource_io::PollStatus::ready||ready.outcome.status!=resources::Status::ok){s.finish(i,LoadStatus::source_failure);return;}
                auto completion=std::make_shared<State::Completion>();
                auto bytes=std::make_shared<const std::vector<std::byte>>(std::move(ready.outcome.bytes));
                const auto owner=s.owner;const auto bank=slot.bank;
                tasks::Task job=[owner,bank,bytes,completion]{completion->result=owner->install(bank,{reinterpret_cast<const std::uint8_t*>(bytes->data()),bytes->size()});completion->done.store(true,std::memory_order_release);};
                const auto submitted=s.prepare.submit(std::move(job));
                if(submitted!=tasks::SubmitStatus::accepted){s.finish(i,LoadStatus::capacity);return;}
                slot.completion=std::move(completion);slot.phase=State::Phase::preparing;
            }
            if(slot.phase==State::Phase::preparing&&slot.completion->done.load(std::memory_order_acquire)){
                slot.result.bank=slot.completion->result;
                if(slot.result.bank.status==gameplay_audio::Status::completed){s.cache[slot.port]=State::Cached{*slot.result.member,slot.name,slot.bank};s.finish(i,LoadStatus::completed);}
                else s.finish(i,LoadStatus::bank_failure);
            }
            return;
        }
        if(!s.count)return;
        const auto i=s.queue[s.head];s.head=(s.head+1)%s.queue.size();--s.count;s.active=i;auto& slot=s.slots[i];
        const auto member=sound_member(std::string(slot.name.data())+".snd");slot.result.member=member;
        if(member&&s.cache[slot.port]&&s.cache[slot.port]->member==*member&&s.cache[slot.port]->name==slot.name&&s.owner->current(s.cache[slot.port]->bank)&&s.owner->state(slot.port)==gameplay_audio::Status::completed){s.finish(i,LoadStatus::cached);return;}
        slot.result.bank=s.owner->stop(slot.port);
        if(slot.result.bank.status!=gameplay_audio::Status::completed){s.finish(i,LoadStatus::bank_failure);return;}
        s.cache[slot.port].reset();
        if(!member){s.finish(i,LoadStatus::not_found);return;}
        const auto view=s.archive->member(*member);
        if(view.status!=afs_source_range::Status::completed||!view.view){s.finish(i,LoadStatus::source_failure);return;}
        slot.bank=s.owner->begin_bank(slot.port);
        if(!slot.bank){s.finish(i,LoadStatus::capacity);return;}
        if(view.view->size()>1024*1024){s.finish(i,LoadStatus::capacity);return;}
        slot.source=view.view;slot.phase=State::Phase::awaiting_read;
    }catch(...){if(s.active)s.finish(*s.active,LoadStatus::capacity);}
}
LoadResult Loader::poll(const LoadTicket& ticket)noexcept{
    if(state_->closed)return {LoadStatus::closed,{},{}};
    const auto i=locate(ticket);if(!i)return{};auto& slot=state_->slots[*i];
    if(slot.phase!=State::Phase::ready)return {LoadStatus::pending,{},slot.result.member};
    const auto result=slot.result;slot={};return result;
}
bool Loader::cancel(const LoadTicket& ticket)noexcept{
    const auto found=locate(ticket);if(!found)return false;auto& s=*state_;const auto i=*found;auto& slot=s.slots[i];
    if(slot.phase==State::Phase::queued){
        std::array<std::size_t,8> kept{};std::size_t count{};
        for(std::size_t n=0;n<s.count;++n){const auto current=s.queue[(s.head+n)%s.queue.size()];if(current!=i)kept[count++]=current;}
        s.queue=kept;s.head=0;s.count=count;
    }else if(s.active==found){
        if(slot.phase==State::Phase::reading)(void)s.reads.cancel(slot.read);
        if(slot.bank)(void)s.owner->cancel(slot.bank);
        s.active.reset();
    }
    slot={};return true;
}
void Loader::shutdown()noexcept{
    auto& s=*state_;if(s.closed)return;s.closed=true;
    for(auto& slot:s.slots)if(slot.bank)(void)s.owner->cancel(slot.bank);
    s.reads.shutdown();s.prepare.request_stop(tasks::StopMode::cancel_pending);
    s.queue={};s.count=0;s.active.reset();s.slots={};s.cache={};
}
bool Loader::join()noexcept{
    if(!state_->closed)return false;
    return state_->reads.join()&&state_->prepare.join();
}
}
