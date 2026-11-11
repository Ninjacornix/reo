#include "motion_bank.hpp"
#include <algorithm>
#include <cstring>
#include <limits>
#include <map>
#include <stdexcept>
namespace reo::native::animation {
namespace {
template<class T>T read(std::span<const std::byte> bytes,std::size_t offset){if(offset>bytes.size()||sizeof(T)>bytes.size()-offset)throw std::invalid_argument("Native motion bank asset extent unavailable");T value;std::memcpy(&value,bytes.data()+offset,sizeof value);return value;}
void header(std::span<const std::byte> bytes,std::uint8_t& first,std::uint8_t& width){first=std::uint8_t(read<std::uint32_t>(bytes,0));width=std::uint8_t(read<std::uint32_t>(bytes,4));if(width==0||width>5||first>4||first+width>5)throw std::invalid_argument("Native motion bank track profile unavailable");}
}
MotionBlock::MotionBlock(std::span<const std::byte> bytes,std::size_t offset,std::string identity):bytes_(bytes.begin(),bytes.end()),source_offset_(offset),source_identity_(std::move(identity)){}
std::shared_ptr<const Clip> MotionBlock::clip()const{if(!clip_)clip_=Clip::import_raw(bytes_);return clip_;}
MotionBank MotionBank::cleared_bank(MotionBankKind kind){
    if(kind!=MotionBankKind::strided&&kind!=MotionBankKind::sparse&&kind!=MotionBankKind::strided_500)throw std::invalid_argument("Native cleared motion bank kind unavailable");
    MotionBank result;result.kind_=kind;result.clear();return result;
}
void MotionBank::clear()noexcept{slots_.fill({});rows_.fill(0);first_=width_=0;cleared_=true;}
void MotionBank::clear_family(std::uint8_t family){
    struct Family {std::size_t first_row,rows,first_token,tokens;};
    static constexpr std::array<Family,3> profiles{{{100,200,5,995},{300,1700,1000,1000},{0,100,1000,1000}}};
    if(family>=profiles.size())throw std::out_of_range("Native motion release family unavailable");
    const auto& profile=profiles[family];
    std::fill_n(rows_.begin()+profile.first_row,profile.rows,0);
    std::fill_n(slots_.begin()+profile.first_token,profile.tokens,std::shared_ptr<const MotionBlock>{});
}
void MotionBank::load_sparse(std::span<const std::byte> bytes,std::size_t table,std::uint8_t mode,std::string identity){
    if(mode>2||identity.empty())throw std::invalid_argument("Native sparse motion bank mode/identity unavailable");
    std::uint8_t first,width;header(bytes,first,width);const auto limit=read<std::uint32_t>(bytes,table+4);if(limit>bytes.size()||table>=limit)throw std::invalid_argument("Native sparse motion descriptor range unavailable");
    auto slots=slots_;auto rows=rows_;std::map<std::size_t,std::shared_ptr<const MotionBlock>> blocks;std::size_t cursor=mode==1?1000:5;
    for(std::size_t group=0;group<20&&table+8*group<limit;++group){
        const auto n=read<std::uint32_t>(bytes,table+8*group),list=read<std::uint32_t>(bytes,table+8*group+4);if(n>65535||list>bytes.size()||std::size_t(n)*4>bytes.size()-list)throw std::invalid_argument("Native sparse motion entry extent unavailable");bool row_live=false;
        for(std::size_t entry=0;entry<n;++entry){const auto column=entry%width;if(column==0)row_live=false;const auto offset=read<std::int32_t>(bytes,list+4*entry);
            if(offset!=-1){if(offset<0)throw std::invalid_argument("Native motion block negative offset");const auto at=std::size_t(offset);const auto size=read<std::uint32_t>(bytes,at+8);if(size<20||at>bytes.size()||size>bytes.size()-at)throw std::invalid_argument("Native motion block extent unavailable");if(cursor+column>=capacity||group*100+entry/width>=capacity)throw std::out_of_range("Native sparse motion bank capacity exhausted");auto& block=blocks[at];if(!block)block=std::shared_ptr<const MotionBlock>(new MotionBlock(bytes.subspan(at,size),at,identity));slots[cursor+column]=block;rows[group*100+entry/width]=std::uint16_t(cursor);row_live=true;}
            if(column+1==width&&row_live)cursor+=width;
        }
    }
    slots_=std::move(slots);rows_=rows;first_=first;width_=width;kind_=MotionBankKind::sparse;cleared_=false;
}
void MotionBank::load_strided(std::span<const std::byte> bytes,std::size_t stride,std::size_t bias,std::string identity){
    if((stride!=200&&stride!=500)||bias>=capacity||identity.empty())throw std::invalid_argument("Native strided motion bank profile unavailable");
    std::uint8_t first,width;header(bytes,first,width);const auto limit=read<std::uint32_t>(bytes,12);if(limit>bytes.size()||8>=limit)throw std::invalid_argument("Native strided motion descriptor range unavailable");auto slots=slots_;std::map<std::size_t,std::shared_ptr<const MotionBlock>> blocks;
    for(std::size_t group=0;group<8&&8+8*group<limit;++group){const auto n=read<std::uint32_t>(bytes,8+8*group),list=read<std::uint32_t>(bytes,12+8*group);if(n>65535||list>bytes.size()||std::size_t(n)*4>bytes.size()-list)throw std::invalid_argument("Native strided motion entry extent unavailable");
        for(std::size_t entry=0;entry<n;++entry){const auto offset=read<std::int32_t>(bytes,list+4*entry);if(offset==-1)continue;if(offset<0)throw std::invalid_argument("Native motion block negative offset");const auto at=std::size_t(offset),destination=bias+group*stride+entry;const auto size=read<std::uint32_t>(bytes,at+8);if(size<20||at>bytes.size()||size>bytes.size()-at||destination>=capacity)throw std::invalid_argument("Native strided motion block/capacity unavailable");auto& block=blocks[at];if(!block)block=std::shared_ptr<const MotionBlock>(new MotionBlock(bytes.subspan(at,size),at,identity));slots[destination]=block;}
    }
    slots_=std::move(slots);first_=first;width_=width;kind_=stride==500?MotionBankKind::strided_500:MotionBankKind::strided;cleared_=false;
}
std::shared_ptr<const MotionBlock> MotionBank::find(std::uint32_t key,std::uint16_t track)const{
    if((!width_&&!cleared_)||track>=5)throw std::out_of_range("Native motion bank track unavailable");
    std::size_t slot;
    if(kind_==MotionBankKind::sparse){const auto index=key&0x7fffu;if(index>=capacity)throw std::out_of_range("Native sparse logical motion row unavailable");slot=std::size_t(rows_[index])+track;}
    else{if(!cleared_&&(track<first_||track>=first_+width_))throw std::out_of_range("Native strided motion track outside authored range");slot=200ull*(key/100)+std::size_t(key%100)*width_+(track-first_);}
    if(slot>=capacity)throw std::out_of_range("Native physical motion row unavailable");
    return slots_[slot];
}
} // namespace reo::native::animation
