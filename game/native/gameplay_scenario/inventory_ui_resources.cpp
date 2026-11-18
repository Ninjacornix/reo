#include "inventory_ui_resources.hpp"
#include "../gameplay_world/world.hpp"
#include "../transform_math/transform_math.hpp"
#include "../../../runtime/assets/virtual_afs.h"
#include <algorithm>
#include <bit>
#include <cmath>
#include <cstdio>
#include <new>
#include <stdexcept>
namespace reo::native::gameplay_scenario {
namespace {
std::string lower(std::string value){for(auto& c:value)if(c>='A'&&c<='Z')c+='a'-'A';return value;}
struct DefaultArchive {
    std::shared_ptr<const reo::assets::Source> source;
    std::uint64_t base{},bytes{};
    reo::assets::Table table;
    explicit DefaultArchive(std::shared_ptr<const reo::assets::Source> input):source(std::move(input)){
        const auto root=reo::assets::table(*source,0,source->size);
        const auto found=std::find_if(root.entries.begin(),root.entries.end(),[](const auto& e){return lower(e.name)=="romdata_usa.afs";});
        if(found==root.entries.end()||std::find_if(found+1,root.entries.end(),[](const auto& e){return lower(e.name)=="romdata_usa.afs";})!=root.entries.end())throw std::runtime_error("Inventory default archive unavailable");
        base=found->offset;bytes=found->size;table=reo::assets::table(*source,base,bytes);
        if(table.entries.size()!=1342)throw std::runtime_error("Inventory default catalogue profile unavailable");
    }
    content::Bytes read(std::size_t ordinal,const char* name)const{
        const auto& e=table.entries.at(ordinal);const auto storage=(std::uint64_t(e.size)+2047)&~std::uint64_t(2047);
        if(lower(e.name)!=name||e.offset>bytes||storage>bytes-e.offset||storage>0x200000)throw std::runtime_error("Inventory owned resource extent/name unavailable");
        if(!storage)return{};
        auto out=std::make_shared<std::vector<std::byte>>(storage);source->read(base+e.offset,out->size(),out->data());return out;
    }
};
std::uint32_t word(const std::vector<std::byte>& bytes,std::size_t at){std::uint32_t result{};for(unsigned i=0;i<4;++i)result|=std::uint32_t(std::to_integer<unsigned>(bytes.at(at+i)))<<(8*i);return result;}
InventoryImage icons(const content::Bytes& bytes,unsigned width,unsigned count,unsigned palettes,std::uint64_t identity){
    const auto pixels=std::size_t(width)*width*count;const auto palette_at=(pixels+63)&~std::size_t(63);
    if(!bytes||palette_at+palettes*1024>bytes->size())throw std::invalid_argument("Inventory icon payload unavailable");
    InventoryImage image;image.identity=identity;image.width=width;image.height=width;image.count=count;image.palette_count=palettes;image.index_bits=8;
    image.indices.assign(bytes->begin(),bytes->begin()+pixels);image.palettes.reserve(palettes*256);
    for(unsigned i=0;i<palettes*256;++i){const auto rgba=word(*bytes,palette_at+4*i);const auto a=rgba>>24;const auto alpha=a==255?128u:a?std::max(1u,a>>1):0u;image.palettes.push_back((rgba&0xffffffu)|(alpha<<24));}
    return image;
}
InventoryImage background(const content::Bytes& bytes,std::uint64_t identity){
    if(!bytes||bytes->size()<0xbc00)throw std::invalid_argument("Inventory background payload unavailable");
    InventoryImage image;image.identity=identity;image.count=7;image.palette_count=16;image.index_bits=4;
    image.indices.assign(bytes->begin(),bytes->begin()+0xbc00);
    image.regions={{0,64,64,0},{0x800,128,128,0x20},{0x2800,64,64,0x40},{0x3000,32,32,0x60},{0x3200,64,64,0x80},{0x3a00,256,256,0xa0},{0xba00,32,32,0x120}};
    // Source733C80/733D90, expanded by complete6D8850 into16x16 CLUTs.
    constexpr std::uint32_t first[]{0x80020202,0x80060505,0x800b0505,0x800e0808,0x80110b0c,0x80191010,0x80201616,0x80261a1b,0x802c1e1f,0x80312425,0x80362829,0x80392c2d,0x803f3131,0x80473939,0x80524344,0x805b4d4e,
      0x80000000,0x80000000,0x80000000,0x80000000,0x80000000,0x80000000,0x80000000,0x80000000,0x80000000,0x80000000,0x80000000,0x80000000,0x00ffffff,0x05ffffff,0x7fffffff,0x80ffffff,
      0x6d2d201a,0x663a2c24,0x5856483e,0x0d55493e,0x3d564a3f,0x5064574d,0x2f6d6156,0x0d74695e,0x49746860,0x3c847971,0x018b7f75,0x19898076,0x3a948984,0x039b8f87,0x01a69b95,0x30a69c97};
    image.palettes.assign(std::begin(first),std::end(first));
    constexpr std::uint32_t pairs[]{0,0x80000000,0x80000000,0x80100404,0,0x40200f0f,0x18000000,0x80000000,0x80000000,0x80000000,0,0x80ffffff,0,0x400000ff,0x80000000,0,0x80ffffff,0x80ffffff,0,0};
    for(unsigned i=0;i<10;++i){image.palettes.push_back(pairs[2*i]);image.palettes.insert(image.palettes.end(),15,pairs[2*i+1]);}
    constexpr unsigned char alpha[]{0,9,14,19,21,25,28,30,32,35,38,45,49,54,60,63,0,5,11,19,26,31,38,46,55,61,67,76,88,100,112,124,0,9,14,19,21,25,28,30,32,35,38,45,49,54,60,63};
    for(unsigned i=0;i<std::size(alpha);++i)
        image.palettes.push_back((i<16?0xffffffu:0u)|(std::uint32_t(alpha[i])<<24));
    return image;
}
void particles(gameplay_session::Random& random,std::array<InventoryBackgroundParticle,32>& records){
    constexpr float tau=std::bit_cast<float>(0x40c90fdbu);
    const auto angle=[&]{const float product=tau*float(random.request(1));return product/65536.0f;};
    for(auto& p:records){p={};p.angle=std::uint16_t((random.request(1)&15u)<<12);p.selector=random.request(1)&1u;
        p.velocity_x=0.5f*transform_math::sin_cos(angle()).sine;p.velocity_y=0.5f*transform_math::sin_cos(angle()).cosine;
        // Source CVT.W.S truncates toward zero; finite products stay in[-16,16].
        p.offset_x=std::int8_t(std::int32_t(16.0f*transform_math::sin_cos(angle()).sine)+4);
        p.offset_y=std::int8_t(std::int32_t(16.0f*transform_math::sin_cos(angle()).cosine)-8);
        p.x=542.0f+float(p.offset_x);p.y=368.0f+float(p.offset_y);
    }
}
}
InventoryUiResources::InventoryUiResources(gameplay_world::World& world,const content::ScenarioArchive& archive,std::shared_ptr<const reo::assets::Source> source,const std::optional<SceneTextVariant>& selector)noexcept:world_(world),archive_(archive),source_(std::move(source)),selector_(selector){}
bool InventoryUiResources::bound_to(const gameplay_world::World& world)const noexcept{return &world==&world_&&!closed_&&!world_.closed();}
bool InventoryUiResources::ready_zero()const noexcept{
    if(!bound_to(world_)||running_)return false;
    if(world_.paused)return true;
    const auto& session=world_.session();return source_&&selector_&&
        (*selector_==SceneTextVariant::standard||*selector_==SceneTextVariant::alternate)&&
        session.scenario&&session.asset_loading_mode&&(session.sound_loading_mode!=1||context_);
}
InventoryResourcesStatus InventoryUiResources::refresh_zero()noexcept{
    if(closed_||world_.closed())return InventoryResourcesStatus::closed;
    if(running_)return InventoryResourcesStatus::busy;
    if(!ready_zero())return InventoryResourcesStatus::unavailable;
    running_=true;struct Exit{bool& flag;~Exit(){flag=false;}}exit{running_};
    //604310 delay-slot publication order is observable even on the paused exit.
    state_.cache[2]=0;state_.cache[0]=0;state_.cache[1]=0;state_.cache_known=true;
    if(world_.paused)return InventoryResourcesStatus::completed;
    try{
        state_.common_text.reset();state_.scenario_text.reset(); //6DE030 clears5778/5780, not5798
        const DefaultArchive defaults(source_);auto& session=world_.session();const auto scenario=*session.scenario;
        if(*selector_==SceneTextVariant::alternate)state_.common_text=defaults.read(510,"itmsge.dat");
        if(*session.asset_loading_mode){char key[32];std::snprintf(key,sizeof(key),*selector_==SceneTextVariant::alternate?"itmsg%03ue.dat":"itmsg%03u.dat",unsigned(scenario));state_.scenario_text=archive_.read_resource_sectors(scenario,key);}
        // Standard/default scenario keys are absent in the qualified1342 table.
        if(const auto items=defaults.read(511,"spitem.dat"))state_.special_items=items;
        //377B30 creates the native UI resource context before publishing324405.
        if(!session.sound_loading_mode){
            transform_math::require_profile();context_=std::make_shared<const std::uint64_t>(next_identity_++);
            state_.context_identity=*context_;session.sound_loading_mode=1;
        }
        if(session.sound_loading_mode!=1){state_.result_present=false;return InventoryResourcesStatus::completed;}
        state_.item_icons.reset();state_.file_icons.reset(); //6D82B0 clears the image record
        state_.item_icons=icons(defaults.read(516,"itemicon.img"),48,117,2,next_identity_++);
        state_.file_icons=icons(defaults.read(515,"file.img"),128,7,7,next_identity_++);
        state_.cache[0]=1;
        state_.background.reset(); //6D8120's zeroed header is published before IO
        if(const auto bytes=defaults.read(514,"cp_back.img")){
            state_.background=background(bytes,next_identity_++);
            particles(session.random,state_.particles);state_.cache[2]=1;
        }
        char key[32];std::snprintf(key,sizeof(key),*selector_==SceneTextVariant::alternate?"file%03ue.dat":"file%03u.dat",unsigned(scenario));
        state_.files=archive_.read_resource_sectors(scenario,key);
        if(!state_.files||state_.files->empty())state_.result_present=false;
        return InventoryResourcesStatus::completed;
    }catch(const std::bad_alloc&){return InventoryResourcesStatus::no_memory;}
    catch(const std::invalid_argument&){return InventoryResourcesStatus::invalid_asset;}
    catch(...){return InventoryResourcesStatus::unavailable;}
}
InventoryResourcesStatus InventoryUiResources::close()noexcept{
    if(running_||world_.busy())return InventoryResourcesStatus::busy;
    if(closed_)return InventoryResourcesStatus::completed;
    state_={};context_.reset();closed_=true;return InventoryResourcesStatus::completed;
}
}
