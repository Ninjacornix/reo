#include "weapon_program.hpp"
#include "../transform_math/transform_math.hpp"
#include <algorithm>
#include <bit>
#include <cmath>
#include <cstring>
#include <map>
#include <stdexcept>
namespace reo::native::animation {
namespace {
template<class T>T read(const std::array<std::byte,2048>& data,std::size_t at){
    if(at>data.size()||sizeof(T)>data.size()-at)throw std::invalid_argument("Weapon program field outside cleared asset extent");
    T result;std::memcpy(&result,data.data()+at,sizeof result);return result;
}
std::int32_t subtract(std::int32_t a,std::int32_t b)noexcept{return std::bit_cast<std::int32_t>(std::uint32_t(a)-std::uint32_t(b));}
}
WeaponSample WeaponCurve::sample(std::int32_t time)const{
    if(keys_.empty())throw std::runtime_error("Weapon curve unavailable");
    transform_math::require_profile();
    const auto next=std::upper_bound(keys_.begin(),keys_.end(),time,[](std::int32_t value,const WeaponKey& key){return value<key.time;});
    if(next==keys_.end())return {keys_.back().value,true};
    if(next==keys_.begin())return {next->value,false};
    const auto& previous=*(next-1);
    const float fraction=float(subtract(time,previous.time))/float(subtract(next->time,previous.time));
    const float difference=next->value-previous.value;
    const float result=fraction*difference+previous.value;
    if(!std::isfinite(result))throw std::domain_error("Weapon curve finite arithmetic unavailable");
    return {result,false};
}
std::shared_ptr<const WeaponProgramBank> WeaponProgramBank::import(std::span<const std::byte> bytes){
    if(bytes.size()>2048)throw std::invalid_argument("Weapon program exceeds original cleared asset extent");
    std::array<std::byte,2048> raw{};std::copy(bytes.begin(),bytes.end(),raw.begin());
    auto result=std::make_shared<WeaponProgramBank>();std::map<std::uint32_t,std::shared_ptr<const WeaponProgram>> programs;
    for(unsigned i=0;i<10;++i){auto& selected=result->selections_[i];const auto offset=read<std::uint32_t>(raw,4*i);if(!offset)continue;
        try{
            if(offset>raw.size()-24)throw std::invalid_argument("Weapon selection extent unavailable");
            if(const auto found=programs.find(offset);found!=programs.end()){selected={WeaponSelectionKind::program,found->second};continue;}
            auto program=std::make_shared<WeaponProgram>();
            for(unsigned part=0;part<6;++part){const auto at=read<std::uint32_t>(raw,offset+4*part);if(!at)continue;if(at>raw.size()-48)throw std::invalid_argument("Weapon part extent unavailable");auto& target=program->parts[part].emplace();
                for(unsigned axis=0;axis<6;++axis){const auto curve=read<std::uint32_t>(raw,at+8*axis);if(!curve)continue;const auto count=read<std::int32_t>(raw,at+8*axis+4);
                    if(count<=0||std::size_t(count)>raw.size()/8||curve>raw.size()-8*std::size_t(count))throw std::invalid_argument("Weapon curve extent unavailable");
                    auto& keys=target.curves[axis].emplace().keys_;keys.reserve(std::size_t(count));
                    for(int key=0;key<count;++key){const auto pos=curve+8*std::size_t(key);WeaponKey value{read<float>(raw,pos),read<std::int32_t>(raw,pos+4)};
                        if(!std::isfinite(value.value)||(!keys.empty()&&keys.back().time>value.time))throw std::invalid_argument("Weapon curve key profile unavailable");
                        keys.push_back(value);
                    }
                }
            }
            selected={WeaponSelectionKind::program,program};programs.emplace(offset,std::move(program));
        }catch(const std::invalid_argument&){selected={WeaponSelectionKind::unavailable,{}};}
    }
    return result;
}
const WeaponSelection& WeaponProgramBank::selection(unsigned index)const{return selections_.at(index);}
}
