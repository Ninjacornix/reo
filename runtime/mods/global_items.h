#pragma once
#include "weapon_shuffle.h"
#include <filesystem>
#include <fstream>
#include <map>
#include <set>
#include <vector>

namespace reo::mods {
struct CatalogueItem {
    uint16_t type{};
    std::array<uint8_t,24> metadata{};
    std::array<uint8_t,4> scale{};
    std::array<uint8_t,8> priority{};
    std::vector<std::array<uint16_t,3>> combinations;
};
using ItemCatalogue = std::vector<CatalogueItem>;
inline ItemCatalogue readItemCatalogue(const char* path) {
    std::ifstream input(std::filesystem::path(std::u8string(reinterpret_cast<const char8_t*>(path))),std::ios::binary);
    if(!input) throw std::runtime_error("Cannot open global item catalogue");
    auto read=[&](void* p,size_t size) {
        if(!input.read(static_cast<char*>(p),size)) throw std::runtime_error("Truncated global item catalogue");
    };
    char magic[8];read(magic,8);
    if(std::memcmp(magic,"RGIC1\0\0\0",8)) throw std::runtime_error("Invalid global item catalogue");
    uint32_t count;read(&count,4);
    if(!count || count>128) throw std::runtime_error("Global item catalogue count exceeds capacity");
    ItemCatalogue result;std::set<uint16_t> types;
    for(unsigned i=0;i<count;++i) {
        CatalogueItem entry;read(&entry.type,2);read(entry.metadata.data(),24);
        read(entry.scale.data(),4);read(entry.priority.data(),8);
        uint16_t combinations;read(&combinations,2);
        if(entry.type>=600 || !types.insert(entry.type).second || combinations>128 ||
           reo::cheats::half(entry.metadata.data(),18)!=entry.type)
            throw std::runtime_error("Invalid global item definition");
        entry.combinations.resize(combinations);
        for(auto& triple:entry.combinations) read(triple.data(),6);
        result.push_back(std::move(entry));
    }
    if(input.peek()!=std::char_traits<char>::eof()) throw std::runtime_error("Trailing global item data");
    return result;
}
inline bool progressionItem(uint16_t type,uint32_t flags) {
    // Daylight and the lighter can affect progression despite their ordinary IDs.
    return type>=10000 || type==312 || type==450 || (flags&0x08000000u)!=0;
}
// Metadata slots 0..127; 128 is the native fallback. Keep every existing index,
// including the player's inventory references and scenario-key references.
inline unsigned installItemCatalogue(uint8_t* ram,const ItemCatalogue& catalogue) {
    using namespace reo::cheats;
    unsigned count=half(ram,0x74ccf0);
    if(!count || count>128) throw std::runtime_error("Scenario item definitions are not ready");
    auto index=[&](unsigned type) -> int {
        for(unsigned i=0;i<count;++i) if(half(ram,0x74bb50+i*24+18)==type) return int(i);
        return -1;
    };
    unsigned missing=0;
    for(const auto& entry:catalogue)
        if(!progressionItem(entry.type,word(entry.metadata.data(),0))) missing+=index(entry.type)<0;
    if(count+missing>128) throw std::runtime_error("Global item metadata exceeds native capacity");
    // Reserve the exact original combination ranges used by progression items.
    // Their metadata and all world pickup records remain byte-for-byte intact.
    std::array<bool,384> used{};
    for(unsigned i=0;i<count;++i) {
        const auto a=0x74bb50+i*24;
        if(!progressionItem(half(ram,a+18),word(ram,a))) continue;
        const unsigned start=half(ram,a+4),size=ram[a+6]*3u;
        if(start==65535 || !size) continue;
        if(start+size>used.size()) throw std::runtime_error("Invalid progression-item combination range");
        for(unsigned j=0;j<size;++j) used[start+j]=true;
    }
    struct Pending { unsigned index; const CatalogueItem* entry; };
    std::vector<Pending> pending;
    for(const auto& entry:catalogue) {
        if(progressionItem(entry.type,word(entry.metadata.data(),0))) continue;
        int existing=index(entry.type);
        if(existing<0) {
            existing=int(count++);
            std::memcpy(ram+0x74bb50+existing*24,entry.metadata.data(),24);
            std::memcpy(ram+0x74b940+existing*4,entry.scale.data(),4);
            std::memcpy(ram+0x74b2d0+existing*8,entry.priority.data(),8);
            ram[0x74b6e0+entry.type]=uint8_t(existing);
        }
        const auto a=0x74bb50+unsigned(existing)*24;
        if(!progressionItem(entry.type,word(ram,a))) pending.push_back({unsigned(existing),&entry});
    }
    // Larger lists first, fitting around protected ranges in the original buffer.
    std::stable_sort(pending.begin(),pending.end(),[](const auto& a,const auto& b) {
        return a.entry->combinations.size()>b.entry->combinations.size();
    });
    for(const auto& p:pending) {
        const unsigned size=unsigned(p.entry->combinations.size())*3;
        const auto a=0x74bb50+p.index*24;
        if(!size) { setHalf(ram,a+4,65535);ram[a+6]=0;continue; }
        unsigned start=0;
        for(;start+size<=used.size();start+=3) {
            bool free=true;
            for(unsigned j=0;j<size;++j) free &= !used[start+j];
            if(free) break;
        }
        if(start+size>used.size()) throw std::runtime_error("Global item combinations exceed native capacity");
        for(unsigned j=0;j<size;++j) used[start+j]=true;
        for(unsigned j=0;j<p.entry->combinations.size();++j)
            for(unsigned k=0;k<3;++k) setHalf(ram,0x74c970+(start+j*3+k)*2,p.entry->combinations[j][k]);
        setHalf(ram,a+4,uint16_t(start));ram[a+6]=uint8_t(p.entry->combinations.size());
    }
    setHalf(ram,0x74ccf0,uint16_t(count));
    return count;
}
enum class ItemCategory { None, Weapon, Ammunition, Common };
inline ItemCategory itemCategory(unsigned type,uint32_t flags) {
    if(type>=600 || progressionItem(uint16_t(type),flags) || type==402 || type==404) return ItemCategory::None;
    if(type>=200 && type<300) return ItemCategory::Ammunition;
    if((flags&1) && !(flags&4)) return ItemCategory::Weapon;
    if((flags&4) || (type>=300 && type<500)) return ItemCategory::Common;
    return ItemCategory::None;
}
inline ShuffleResult randomizeGlobalPickups(uint8_t* ram,uint32_t seed,const ItemExclusions& excluded={}) {
    using namespace reo::cheats;
    ShuffleResult result;
    const auto metadataCount=half(ram,0x74ccf0);
    if(!metadataCount || metadataCount>128) throw std::runtime_error("Invalid global item metadata count");
    for(unsigned handle=1;handle<256;++handle) {
        const auto a=0x3c5630u+handle*60u;
        const unsigned type=half(ram,a+6);
        if(type>=600) continue;
        const unsigned oldIndex=ram[0x74b6e0+type];
        if(ram[a]!=1 || ram[a+2]!=handle || (word(ram,a+0x18)&~1u)!=0x800 ||
           half(ram,a+0x28)!=0 || oldIndex>=metadataCount || type>=600 ||
           (type<excluded.size() && excluded[type])) continue;
        const auto oldInfo=0x74bb50+oldIndex*24;
        if(half(ram,oldInfo+18)!=type || (word(ram,oldInfo)&0x40)) continue;
        const auto category=itemCategory(type,word(ram,oldInfo));
        if(category==ItemCategory::None) continue;
        std::array<unsigned,128> candidates{};unsigned count=0;
        for(unsigned i=0;i<metadataCount;++i) {
            const auto info=0x74bb50+i*24;const unsigned candidate=half(ram,info+18);
            if(candidate==type || itemCategory(candidate,word(ram,info))!=category ||
               ((word(ram,info)&0x40) && category!=ItemCategory::Weapon) ||
               !half(ram,info+8) || (candidate<excluded.size() && excluded[candidate])) continue;
            candidates[count++]=i;
        }
        if(!count) continue;
        uint32_t state=seed ^ (uint32_t(half(ram,0x3243da))<<16) ^ (handle*0x9e3779b9u) ^ type;
        const unsigned chosen=candidates[next(state)%count],info=0x74bb50+chosen*24,
            replacement=half(ram,info+18),capacity=half(ram,info+8);
        unsigned maximum=capacity;
        if(category==ItemCategory::Ammunition) maximum=std::min(maximum,60u);
        else if(category==ItemCategory::Common) maximum=std::min(maximum,3u);
        else if(replacement<100) maximum=std::min(maximum,30u);
        const auto quantity=uint16_t(1+next(state)%maximum);
        result.before[result.count]={a,uint16_t(type),half(ram,a+0x24),uint8_t(oldIndex)};
        result.after[result.count++]={a,uint16_t(replacement),quantity,uint8_t(chosen)};
        setHalf(ram,a+6,uint16_t(replacement));setHalf(ram,a+0x24,quantity);ram[a+0x2b]=uint8_t(chosen);
        ++result.changed;
    }
    return result;
}
}
