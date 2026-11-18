#include "game/native/gameplay_world/resource_static_assets.hpp"
unsigned static_banks{},static_roots{},static_matrices{},static_lookups{},static_large_roots{},static_refusals{};
void compare_resource_static(const char* path,std::vector<std::uint8_t>& ram){
    namespace g=reo::native::gameplay_world;
    std::ifstream input(path,std::ios::binary);unsigned count{};input.read(reinterpret_cast<char*>(&count),4);check(count==16);
    for(unsigned asset=0;asset<count;++asset){
        unsigned size{};input.read(reinterpret_cast<char*>(&size),4);check(size&&size<0x400000);std::vector<std::byte> data(size);input.read(reinterpret_cast<char*>(data.data()),size);check(bool(input));
        auto cache=g::ResourceStaticAssets::import_nbd(data);std::fill(ram.begin(),ram.end(),0);auto* memory=ram.data();owned_constants(memory);put(memory,0x294e00,m::identity());
        unsigned offset{},length{};std::memcpy(&offset,data.data()+0x24,4);std::memcpy(&length,data.data()+0x28,4);check(offset&&length&&offset+length<=data.size());std::memcpy(memory+0x100000,data.data()+offset,length);put(memory,0x32440c,0x400000u);check(!allocated);
        call(memory,0x1d3100,{0x70000,0x100000});check(!allocated);check(get<std::int16_t>(memory,0x3dba50)==int(cache->roots().size())&&get<unsigned>(memory,0x70000+0x80c)==0);
        for(unsigned root=0;root<cache->roots().size();++root){
            const auto& value=cache->roots()[root];check(value.content==get<std::int16_t>(memory,0x3dba54+2*root));check(value.part_count==get<std::uint16_t>(memory,0x3dbb14+2*root));
            if(value.part_count>6){check(!value.admitted_parts);bool refused{};try{(void)cache->parts(std::int16_t(root));}catch(const std::runtime_error&){refused=true;}check(refused);++static_large_roots;++static_refusals;}
            else{const auto parts=cache->parts(std::int16_t(root));check(parts==value.admitted_parts&&parts->asset_index==int(root)&&parts->count==value.part_count);
                for(unsigned part=0;part<parts->count;++part){check(std::memcmp(&parts->poses[part],memory+0x3c9a50+384*root+64*part,64)==0);++static_matrices;}
            }
            ++static_roots;
        }
        for(unsigned bits=0;bits<65536;++bits){const auto expected=call(memory,0x372490,{bits|0xabc00000u});check(cache->find(std::bit_cast<std::int16_t>(std::uint16_t(bits)))==std::bit_cast<std::int32_t>(GPR_U32(&expected,2)));++static_lookups;}
        for(auto invalid:{std::int16_t(-1),std::int16_t(cache->roots().size())}){bool refused{};try{(void)cache->parts(invalid);}catch(const std::out_of_range&){refused=true;}check(refused);++static_refusals;}
        auto retained=cache->roots().empty()?nullptr:cache->roots()[0].admitted_parts;const auto old=retained?*retained:g::ResourcePartPoses{};cache.reset();std::fill(data.begin(),data.end(),std::byte{});if(retained)check(retained->count==old.count&&retained->asset_index==old.asset_index&&retained->poses==old.poses);
        for(unsigned n:{0u,8u,0x28u}){bool refused{};try{(void)g::ResourceStaticAssets::import_nbd(std::span(data).first(n));}catch(const std::invalid_argument&){refused=true;}check(refused);++static_refusals;}
        ++static_banks;
    }
}
