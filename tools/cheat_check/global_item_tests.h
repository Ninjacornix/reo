#pragma once
#include "../../runtime/mods/global_items.h"

inline void testGlobalItems() {
    using namespace reo::mods;using namespace reo::cheats;
    auto require=[](bool ok) {if(!ok) throw std::runtime_error("Global item RNG check failed");};
    std::vector<uint8_t> ram(0x2000000);
    std::memset(ram.data()+0x74b6e0,255,600);
    auto definition=[&](unsigned index,uint16_t type,uint32_t flags,uint16_t capacity) {
        auto a=0x74bb50+index*24;setWord(ram.data(),a,flags);setHalf(ram.data(),a+8,capacity);
        setHalf(ram.data(),a+18,type);setHalf(ram.data(),a+4,65535);
        if(type<600) ram[0x74b6e0+type]=uint8_t(index);
    };
    definition(0,0,0x102001,15);definition(1,300,0x40004,1);
    definition(2,250,0x100002,255);definition(3,10100,0x8040200,1);
    definition(4,400,0x102041,7);setHalf(ram.data(),0x74ccf0,5);
    setHalf(ram.data(),0x74bb50+3*24+4,381);ram[0x74bb50+3*24+6]=1;
    for(unsigned j=0;j<3;++j)setHalf(ram.data(),0x74c970+(381+j)*2,uint16_t(123+j));
    auto pickup=[&](unsigned handle,uint16_t type,unsigned metadata) {
        const auto a=0x3c5630+handle*60;ram[a]=1;ram[a+2]=uint8_t(handle);
        setWord(ram.data(),a+0x18,0x800);setHalf(ram.data(),a+6,type);
        setHalf(ram.data(),a+0x24,1);ram[a+0x2b]=uint8_t(metadata);
    };
    pickup(1,0,255);pickup(2,300,255);pickup(3,250,255); // Metadata caches may be unset at scenario initialization.
    pickup(4,10100,3);pickup(5,400,4);
    ItemCatalogue catalogue;
    for(auto [type,flags,capacity]:std::array<std::array<unsigned,3>,4>{{{11,0x104001,7},{301,0x40004,1},{254,0x100002,255},{455,8,1}}}) {
        CatalogueItem item;item.type=uint16_t(type);
        setWord(item.metadata.data(),0,flags);setHalf(item.metadata.data(),8,uint16_t(capacity));
        setHalf(item.metadata.data(),18,item.type);catalogue.push_back(item);
    }
    catalogue[0].combinations.push_back({254,11,1});
    const auto original=ram;
    require(installItemCatalogue(ram.data(),catalogue)==9);
    require(std::memcmp(ram.data()+0x74bb50+3*24,original.data()+0x74bb50+3*24,24)==0);
    require(std::memcmp(ram.data()+0x74c970+381*2,original.data()+0x74c970+381*2,6)==0);
    const auto prepared=ram;
    std::set<uint16_t> results;
    for(uint32_t seed=0;seed<32;++seed) {
        auto first=prepared,again=prepared;
        auto shuffled=randomizeGlobalPickups(first.data(),seed);randomizeGlobalPickups(again.data(),seed);
        require(first==again && shuffled.count==3);
        for(unsigned i=0;i<shuffled.count;++i) {
            const auto& before=shuffled.before[i];const auto& after=shuffled.after[i];
            require(before.type!=after.type);
            require(itemCategory(before.type,word(first.data(),0x74bb50+before.metadata*24))==
                    itemCategory(after.type,word(first.data(),0x74bb50+after.metadata*24)));
            results.insert(after.type);
        }
        for(unsigned handle:{4u,5u}) {
            const auto address=0x3c5630+handle*60;
            require(std::memcmp(first.data()+address,prepared.data()+address,60)==0);
        }
        for(size_t a=0;a<first.size();++a) {
            bool allowed=false;
            for(const auto& item:shuffled.before) {
                if(!item.address) break;
                allowed |= a==item.address+6 || a==item.address+7 || a==item.address+0x24 ||
                           a==item.address+0x25 || a==item.address+0x2b;
            }
            require(allowed || first[a]==prepared[a]);
        }
    }
    require(results.count(11) && results.count(301) && results.count(455) && results.count(254));
    require(itemCategory(309,0x140005)==ItemCategory::Common && itemCategory(450,8)==ItemCategory::None &&
            itemCategory(312,0x40004)==ItemCategory::None);
    std::cout<<"PASS global item RNG: absent definitions, strict categories, stable seeds, progression/personal records and full-RAM write boundaries\n";
}
