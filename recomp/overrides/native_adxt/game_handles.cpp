#include "game_handles.h"
#include <limits>
#include <stdexcept>
#include <utility>

namespace reo::native::adxt_binding {
struct GameIdentity {};
namespace {
using S=instances::Status;
template<class F>struct Operation final:control_owner::Operation {
    F fn;explicit Operation(F f):fn(std::move(f)){}void run(instances::Instances& value)noexcept override{fn(value);}
};
S admission(control_owner::Admission value,S status)noexcept{return value==control_owner::Admission::accepted?status:value==control_owner::Admission::closed?S::closed:S::busy;}
bool same(const Handle& a,const Handle& b)noexcept{
    return a.address==b.address && a.slot==b.slot && a.channels==b.channels && a.decoder==b.decoder && a.file==b.file && a.rna==b.rna && a.route==b.route && a.input==b.input && a.transfer==b.transfer && a.paired_record==b.paired_record && a.output==b.output;
}
bool conflict(const Handle& a,const Handle& b)noexcept{
    if(a.address==b.address || a.decoder==b.decoder || a.file==b.file || a.rna==b.rna || a.route==b.route || a.input==b.input)return true;
    for(unsigned i=0;i<a.channels;++i)if(a.output[i]==b.input)return true;
    for(unsigned j=0;j<b.channels;++j)if(b.output[j]==a.input)return true;
    for(unsigned i=0;i<a.channels;++i)for(unsigned j=0;j<b.channels;++j)
        if(a.transfer[i]==b.transfer[j] || a.paired_record[i]==b.paired_record[j] || a.output[i]==b.output[j])return true;
    return false;
}
bool coherent(const Handle& h)noexcept{
    std::uint32_t index{};
    if(!detail::slot(handles,h.address,index) || index!=h.slot || h.channels<1 || h.channels>2 ||
       !detail::slot(decoders,h.decoder,index) || index!=h.decoder_slot ||
       !detail::slot(files,h.file,index) || index!=h.file_slot ||
       !detail::slot(rnas,h.rna,index) || index!=h.rna_slot)return false;
    for(unsigned channel=0;channel<h.channels;++channel)
        if(!detail::slot(transfers,h.transfer[channel],index) || index!=h.transfer_slot[channel])return false;
    return h.channels!=2 || h.transfer_slot[1]==h.transfer_slot[0]+1;
}
}
struct GameHandles::State {
    struct Record {Handle guest;instances::Key native;std::uint64_t generation{1};bool owned{},destroying{},exhausted{};};
    std::shared_ptr<const GameIdentity> identity=std::make_shared<GameIdentity>();
    std::shared_ptr<control_owner::Owner> owner;std::array<Record,16> records;bool cleared{};
    explicit State(std::shared_ptr<control_owner::Owner> value):owner(std::move(value)){}
};
GameHandles::GameHandles(std::shared_ptr<control_owner::Owner> owner):state_(std::make_unique<State>(std::move(owner))){
    if(!state_->owner)throw std::invalid_argument("Canonical native source owner required");
    bool empty{};Operation check([&](auto& p){empty=p.snapshot().instances==0;});
    if(state_->owner->run(check)!=control_owner::Admission::accepted || !empty)throw std::invalid_argument("Empty exclusive native instance owner required");
}
GameHandles::~GameHandles()=default;
bool GameHandles::valid(const GameKey& key,bool destroying)const noexcept{
    const auto& s=*state_;if(key.owner_.lock()!=s.identity || key.slot_>=s.records.size())return false;
    const auto& r=s.records[key.slot_];return r.owned && r.generation==key.generation_ && (destroying || !r.destroying);
}
void GameHandles::release(std::uint32_t slot)noexcept{
    auto& r=state_->records[slot];r.owned=false;r.destroying=false;r.native={};r.guest={};
    if(r.generation==std::numeric_limits<std::uint64_t>::max())r.exhausted=true;else ++r.generation;
}
Adoption GameHandles::adopt(const HandleResult& prepared,std::shared_ptr<const adxt_attenuation::Table> table)noexcept{
    auto& s=*state_;if(s.cleared)return{S::closed,{}};
    if(prepared.status!=HandleStatus::ready || !table)return{};
    const auto& h=prepared.value;if(!coherent(h))return{};
    auto& r=s.records[h.slot];if(r.owned)return{S::occupied,{}};if(r.exhausted)return{S::capacity,{}};
    for(const auto& current:s.records)if(current.owned && conflict(h,current.guest))return{S::occupied,{}};
    instances::Open opened;Operation create([&](auto& p){
        // ADXT stream slot and file descriptor slot are DIFFERENT domains.
        opened=p.create({h.channels,{h.decoder_slot,h.slot,h.rna_slot,h.transfer_slot[0],h.route},std::move(table)});
    });
    const auto admitted=s.owner->run(create);
    const auto status=admission(admitted,opened.status);if(status!=S::completed)return{status,{}};
    r.guest=h;r.native=opened.key;r.owned=true;r.destroying=false;
    GameKey key;key.owner_=s.identity;key.slot_=h.slot;key.generation_=r.generation;return{S::completed,std::move(key)};
}
GameKey GameHandles::find(const HandleResult& prepared)const noexcept{
    const auto& s=*state_;if(s.cleared || prepared.status!=HandleStatus::ready || prepared.value.slot>=s.records.size())return{};
    const auto& r=s.records[prepared.value.slot];if(!r.owned || r.destroying || !same(r.guest,prepared.value))return{};
    GameKey key;key.owner_=s.identity;key.slot_=prepared.value.slot;key.generation_=r.generation;return key;
}
S GameHandles::with(const GameKey& key,HandleOperation& operation)noexcept{
    auto& s=*state_;if(s.cleared)return S::closed;if(!valid(key))return S::invalid_key;auto& r=s.records[key.slot_];
    S result=S::fault;Operation invoke([&](auto& p){if(p.inspect(r.native).status!=S::completed)return;operation.run(p,r.native,r.guest);result=S::completed;});
    const auto admitted=s.owner->run(invoke);return admission(admitted,result);
}
S GameHandles::destroy(const GameKey& key)noexcept{
    auto& s=*state_;if(s.cleared)return S::closed;if(!valid(key,true))return S::invalid_key;auto& r=s.records[key.slot_];
    S result=S::fault;Operation destroy([&](auto& p){
        if(r.destroying && p.inspect(r.native).status==S::invalid_key){result=S::completed;return;}
        result=p.destroy(r.native);if(result==S::pending || result==S::completed)r.destroying=true;
    });
    const auto admitted=s.owner->run(destroy);
    const auto status=admission(admitted,result);if(status==S::completed)release(key.slot_);return status;
}
S GameHandles::set_order(std::span<const GameKey> keys)noexcept{
    auto& s=*state_;if(s.cleared)return S::closed;unsigned count{};for(const auto& r:s.records)count+=r.owned && !r.destroying;
    if(keys.size()!=count)return S::invalid_input;
    std::array<instances::Key,16> native;std::array<bool,16> used{};
    for(unsigned i=0;i<keys.size();++i){const auto& key=keys[i];if(!valid(key) || used[key.slot_])return S::invalid_key;used[key.slot_]=true;native[i]=s.records[key.slot_].native;}
    S result=S::fault;Operation order([&](auto& p){result=p.set_order(std::span(native).first(keys.size()));});
    const auto admitted=s.owner->run(order);return admission(admitted,result);
}
S GameHandles::service(std::uint32_t tick)noexcept{
    auto& s=*state_;if(s.cleared)return S::closed;S result=S::fault;Operation service([&](auto& p){result=p.service(tick);});
    const auto admitted=s.owner->run(service);return admission(admitted,result);
}
HandleCounts GameHandles::counts()const noexcept{HandleCounts result;result.cleared_after_join=state_->cleared;for(const auto& r:state_->records){result.mapped+=r.owned;result.destroying+=r.destroying;}return result;}
S GameHandles::clear_after_join()noexcept{
    auto& s=*state_;if(s.cleared)return S::completed;if(!s.owner->report().joined)return S::pending;
    for(unsigned i=0;i<s.records.size();++i)if(s.records[i].owned)release(i);
    s.cleared=true;return S::completed;
}
} // namespace reo::native::adxt_binding
