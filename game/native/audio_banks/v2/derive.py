#!/usr/bin/env python3
"""Explicit allocator-policy derivation from immutable BankSession v1.

This preserves source DSP expressions and the original blind-freeze identity.
v2 is a post-oracle allocator/admission cohort, not a second blind freeze.
"""
import hashlib
from pathlib import Path
import sys
HERE=Path(__file__).resolve().parent
BASE=HERE.parent
sys.path.insert(0,str(BASE))
from verify import FROZEN
def change(s,old,new,n=1):
    if s.count(old)!=n:raise ValueError(f'derivation location count: {old!r}: {s.count(old)} != {n}')
    return s.replace(old,new)
def derive():
    for name,digest in FROZEN.items():
        if hashlib.sha256((BASE/name).read_bytes()).hexdigest()!=digest:raise ValueError('Historical v1 changed: '+name)
    outputs={}
    for name in ['session.hpp','session.cpp','algorithms.hpp','algorithms.cpp']:
        s=(BASE/name).read_text(encoding='utf-8').replace('namespace reo::native::audio_banks {','namespace reo::native::audio_banks::v2 {').replace('namespace reo::native::audio_banks::detail {','namespace reo::native::audio_banks::v2::detail {')
        if name=='session.hpp':
            s=change(s,'#include <vector>','#include <vector>\n#include "budget.hpp"')
            s=change(s,'struct OwnedBankBytes {std::vector<std::uint8_t> hd,bd,tq;};','''struct BankSizes {std::size_t hd{},bd{},tq{};};
// Session::capture obtains count/byte admission BEFORE allocating these writable
// buffers. Adapter holds Submission across capture, fill, prepare and install.
class CapturedBank final {
public:
    CapturedBank()=default;
    CapturedBank(CapturedBank&&)=default;
    CapturedBank& operator=(CapturedBank&&)=default;
    CapturedBank(const CapturedBank&)=delete;
    CapturedBank& operator=(const CapturedBank&)=delete;
    std::span<std::uint8_t> hd() noexcept{return hd_;}
    std::span<std::uint8_t> bd() noexcept{return bd_;}
    std::span<std::uint8_t> tq() noexcept{return tq_;}
private:
    friend class Session;
    CapturedBank(std::shared_ptr<AssetLease> lease,std::weak_ptr<const Identity> owner,std::uint64_t epoch)
        :lease_(std::move(lease)),hd_(AssetAllocator<std::uint8_t>(lease_)),bd_(AssetAllocator<std::uint8_t>(lease_)),tq_(AssetAllocator<std::uint8_t>(lease_)),owner_(std::move(owner)),epoch_(epoch){}
    std::shared_ptr<AssetLease> lease_;
    AssetVector<std::uint8_t> hd_,bd_,tq_;
    std::weak_ptr<const Identity> owner_;
    std::uint64_t epoch_{};
};''')
            # Identity must be forward-declared before capture's weak identity.
            s=change(s,'struct BankSizes {','struct Identity;\nstruct BankSizes {')
            s=change(s,'    bool path_counters{};','    bool path_counters{};\n    std::size_t max_asset_bytes{64u*1024u*1024u},max_assets{128};\n    std::shared_ptr<AllocationSource> allocation_source;')
            s=change(s,'    [[nodiscard]] Result<PreparedBank> prepare(const Submission&,OwnedBankBytes) noexcept;','    [[nodiscard]] Result<CapturedBank> capture(const Submission&,BankSizes) noexcept;\n    [[nodiscard]] Result<PreparedBank> prepare(const Submission&,CapturedBank) noexcept;\n    [[nodiscard]] std::shared_ptr<const Budget> budget_observer() const noexcept;')
        elif name=='session.cpp':
            s=change(s,'struct AssetData {Bank bank;std::uint64_t serial{};};','struct AssetData {explicit AssetData(std::shared_ptr<AssetLease> lease):bank(std::move(lease)){} Bank bank;std::uint64_t serial{};};')
            for inc in ['source_records.inc','source_members.inc','source_mix.inc']:s=change(s,f'#include "{inc}"',f'#include "../{inc}"')
            s=change(s,'    Config config;','    Config config;\n    std::shared_ptr<Budget> budget;')
            s=change(s,'explicit State(Config c):config(c),submissions(c.max_submissions),pathLog(c.path_counters)', 'explicit State(Config c):config(c),budget(std::make_shared<Budget>(c.max_asset_bytes,c.max_assets,c.allocation_source)),submissions(c.max_submissions),pathLog(c.path_counters)')
            s=change(s,'Result<PreparedBank> Session::prepare(const Submission& submission,OwnedBankBytes bytes) noexcept {','''std::shared_ptr<const Budget> Session::budget_observer() const noexcept{return state_->budget;}
Result<CapturedBank> Session::capture(const Submission& submission,BankSizes sizes) noexcept {
    auto& s=*state_;
    if(submission.state_.get()!=&s)return {Status::invalid_submission,{}};
    const auto valid=s.valid_submission(submission.slot_,submission.generation_);if(valid!=Status::ok)return {valid,{}};
    constexpr std::size_t part_limit=2u*1024u*1024u;
    if(sizes.hd>part_limit||sizes.bd>part_limit||sizes.tq>part_limit)return {Status::invalid_asset,{}};
    std::uint64_t epoch{};{std::lock_guard lock(s.gate);epoch=s.submissions[submission.slot_].epoch;}
    try {
        auto lease=acquire_asset(s.budget);
        CapturedBank result(std::move(lease),s.identity,epoch);
        result.hd_.resize(sizes.hd);result.bd_.resize(sizes.bd);result.tq_.resize(sizes.tq);
        const auto after=s.valid_submission(submission.slot_,submission.generation_);if(after!=Status::ok)return {after,{}};
        return {Status::ok,std::move(result)};
    }catch(const BudgetExceeded&){return {Status::capacity,{}};}
    catch(const std::bad_alloc&){return {Status::no_memory,{}};}
}
Result<PreparedBank> Session::prepare(const Submission& submission,CapturedBank bytes) noexcept {''')
            s=change(s,'    std::uint64_t epoch{},serial{};','    if(!bytes.lease_||bytes.owner_.lock()!=s.identity)return {Status::invalid_asset,{}};\n    if(bytes.epoch_!=s.epoch.load())return {Status::stale_generation,{}};\n    std::uint64_t epoch{},serial{};')
            s=change(s,'auto data=std::make_shared<AssetData>();data->serial=serial;','auto data=std::allocate_shared<AssetData>(AssetAllocator<AssetData>(bytes.lease_),bytes.lease_);data->serial=serial;')
            s=change(s,'bytes.hd.data(),bytes.hd.size(),bytes.bd.data(),bytes.bd.size(),bytes.tq.data(),bytes.tq.size()','bytes.hd_.data(),bytes.hd_.size(),bytes.bd_.data(),bytes.bd_.size(),bytes.tq_.data(),bytes.tq_.size()')
            s=change(s,'    }catch(const std::bad_alloc&){return {Status::no_memory,{}};}','    }catch(const BudgetExceeded&){return {Status::capacity,{}};}\n    catch(const std::bad_alloc&){return {Status::no_memory,{}};}')
        elif name=='algorithms.hpp':
            s=change(s,'    std::vector<int16_t> pcm;','    explicit DecodedSample(std::shared_ptr<AssetLease> lease):pcm(AssetAllocator<int16_t>(std::move(lease))){}\n    AssetVector<int16_t> pcm;\n    void clear(){pcm.clear();loopStart=0;hasLoop=false;}')
            s=change(s,'class Bank {\npublic:','class Bank {\npublic:\n    explicit Bank(std::shared_ptr<AssetLease> lease):lease_(std::move(lease)),hd_(AssetAllocator<uint8_t>(lease_)),bd_(AssetAllocator<uint8_t>(lease_)),tq_(AssetAllocator<uint8_t>(lease_)),decoded_(0,std::hash<uint32_t>{},std::equal_to<uint32_t>{},AssetAllocator<CacheEntry>(lease_)){}\n    const auto& allocation_lease()const noexcept{return lease_;}')
            s=change(s,'const std::vector<uint8_t>& tq()','const AssetVector<uint8_t>& tq()')
            s=change(s,'    std::vector<uint8_t> hd_, bd_, tq_;','    using CacheEntry=std::pair<const uint32_t,std::shared_ptr<const DecodedSample>>;\n    std::shared_ptr<AssetLease> lease_;\n    AssetVector<uint8_t> hd_, bd_, tq_;')
            s=change(s,'    std::unordered_map<uint32_t,std::shared_ptr<const DecodedSample>> decoded_;','    std::unordered_map<uint32_t,std::shared_ptr<const DecodedSample>,std::hash<uint32_t>,std::equal_to<uint32_t>,AssetAllocator<CacheEntry>> decoded_;')
        elif name=='algorithms.cpp':
            s=change(s,'const std::vector<uint8_t>&','const AssetVector<uint8_t>&',4)
            s=change(s,'std::vector<uint8_t> header(hd, hd + hn);','AssetVector<uint8_t> header(hd, hd + hn,AssetAllocator<uint8_t>(lease_));')
            s=change(s,'auto pcm = std::make_shared<DecodedSample>();','auto pcm = std::allocate_shared<DecodedSample>(AssetAllocator<DecodedSample>(lease_),lease_);')
            s=change(s,'    out = {};','    out.clear();',2)
        outputs[name]='// Budget v2 generated by derive.py from frozen v1; allocation/admission\n// changed after original expectations were available; DSP expressions retained.\n'+s
    return outputs
if __name__=='__main__':
    for name,text in derive().items():(HERE/name).write_text(text,encoding='utf-8',newline='\n')
