#include "game/native/gameplay_world/resource_static_assets.hpp"
#include <cmath>
int main(int argc,char** argv)try{
    check(argc==2);std::ifstream input(argv[1],std::ios::binary);unsigned count{};input.read(reinterpret_cast<char*>(&count),4);check(count==16);
    std::vector<std::uint8_t> ram(0x2000000);std::size_t pairs{},components{};
    for(unsigned asset=0;asset<4;++asset){
        unsigned size{};input.read(reinterpret_cast<char*>(&size),4);std::vector<std::byte> data(size);input.read(reinterpret_cast<char*>(data.data()),size);check(bool(input));
        auto cache=reo::native::gameplay_world::ResourceStaticAssets::import_nbd(data);
        std::fill(ram.begin(),ram.end(),0);auto* memory=ram.data();owned_constants(memory);put(memory,0x294e00,m::identity());
        unsigned offset{},length{};std::memcpy(&offset,data.data()+0x24,4);std::memcpy(&length,data.data()+0x28,4);
        check(offset<=data.size()&&length<=data.size()-offset);std::memcpy(memory+0x100000,data.data()+offset,length);put(memory,0x32440c,0x400000u);check(!allocated);
        call(memory,0x1d3100,{0x70000,0x100000});check(!allocated);
        for(std::size_t root=0;root<cache->roots().size();++root){const auto& entry=cache->roots()[root];if(!entry.admitted_parts)continue;
            for(unsigned part=0;part<entry.part_count;++part){const auto pose=entry.admitted_parts->poses[part];const auto inverse=get<m::Matrix>(memory,0x3d2a50+384*unsigned(root)+64*part);
                auto product=inverse;m::concatenate_left(product,pose);
                for(unsigned column=0;column<4;++column)for(unsigned row=0;row<4;++row){const float expected=column==row?1.f:0.f;
                    if(!std::isfinite(product[column][row])||std::abs(product[column][row]-expected)>0.0001f)
                        throw std::runtime_error("bind bank is not inverse of native static pose: asset="+std::to_string(asset)+" root="+std::to_string(root)+" part="+std::to_string(part));
                    ++components;
                }++pairs;
                // 191430 normalizes each source axis, transposes the result,
                // transforms negative translation, then applies the reciprocal
                // lengths again. Compare its native finite scalar equivalent.
                m::Matrix candidate=m::identity();float lengths[3]{};
                for(unsigned row=0;row<3;++row){const auto& axis=pose[row];
                    const float norm=(axis[0]*axis[0]+axis[1]*axis[1])+axis[2]*axis[2];
                    if(!(norm>0)||!std::isfinite(norm))throw std::runtime_error("singular source axis");
                    lengths[row]=1.f/std::sqrt(norm);
                    for(unsigned column=0;column<3;++column)candidate[column][row]=(pose[row][column]*lengths[row])*lengths[row];
                    const float rotated=((pose[row][0]*lengths[row])*(-pose[3][0])+(pose[row][1]*lengths[row])*(-pose[3][1]))+(pose[row][2]*lengths[row])*(-pose[3][2]);
                    candidate[3][row]=rotated*lengths[row];
                }
                for(unsigned column=0;column<4;++column)for(unsigned row=0;row<4;++row){
                    if(!std::isfinite(candidate[column][row])||std::abs(candidate[column][row]-inverse[column][row])>0.0001f)
                        throw std::runtime_error("candidate inverse differs from source: asset="+std::to_string(asset)+" root="+std::to_string(root)+" part="+std::to_string(part));
                    ++components;
                }
            }
        }
    }
    std::cout<<"{\"assets\":4,\"matrix_pairs\":"<<pairs<<",\"components\":"<<components<<",\"comparison\":\"inverse composition tolerance 0.0001\",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
