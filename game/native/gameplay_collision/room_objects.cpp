#include "room_objects.hpp"
#include <algorithm>
#include <bit>
#include <cmath>
#include <stdexcept>
namespace reo::native::gameplay_collision::room_objects {
struct Domain {};
namespace {
// Ten immutable owned stock footprint profiles. Each has four rotated integer
// rectangles followed by width/height/depth; byte19 is unused padding.
constexpr std::array<std::array<std::int8_t,19>,10> profiles{{
 {{0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,1,1,1}},
 {{0,0,2,2,0,-1,2,1,-1,-1,1,1,-1,0,1,2,2,2,2}},
 {{0,0,3,2,0,-2,2,1,-2,-1,1,1,-1,0,1,3,3,2,2}},
 {{0,0,4,2,0,-3,2,1,-3,-1,1,1,-1,0,1,4,4,2,2}},
 {{0,0,10,4,0,-9,4,1,-9,-3,1,1,-3,0,1,10,10,3,4}},
 {{0,0,4,4,0,-3,4,1,-3,-3,1,1,-3,0,1,4,4,4,4}},
 {{0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,1,2,1}},
 {{0,0,1,3,0,0,3,1,0,-2,1,1,-2,0,1,1,1,1,3}},
 {{0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,1,3,1}},
 {{0,0,2,1,0,-1,1,1,-1,0,1,1,0,0,1,2,2,5,1}}
}};
std::uint32_t word(std::span<const std::byte> b,std::size_t at){if(at>b.size()||4>b.size()-at)throw std::invalid_argument("Truncated room-object resource");std::uint32_t value{};for(unsigned i=0;i<4;++i)value|=std::uint32_t(std::to_integer<std::uint8_t>(b[at+i]))<<(8*i);return value;}
std::int8_t signed_byte(std::span<const std::byte> b,std::size_t at){if(at>=b.size())throw std::invalid_argument("Truncated room-object byte");return std::bit_cast<std::int8_t>(std::to_integer<std::uint8_t>(b[at]));}
std::int8_t narrow(std::int32_t v){return std::bit_cast<std::int8_t>(std::uint8_t(v));}
std::optional<std::int32_t> integer(float v){const auto truncated=std::trunc(double(v));if(!std::isfinite(v)||truncated<-2147483648.0||truncated>2147483647.0)return{};return std::int32_t(truncated);}
std::optional<std::int8_t> band(float y,float origin){const auto height=integer((1.0f+y)-origin);if(!height)return{};return narrow(*height/50);}
void bit(Grid::Mask& mask,std::int32_t x,std::int32_t z,bool occupied){if(x<0||x>=96||z<0||z>=96)throw std::invalid_argument("Room-object footprint exceeds owned mask domain");auto& word=mask[std::size_t(x)*3+std::uint32_t(z)/32];const auto value=1u<<(std::uint32_t(z)&31);if(occupied)word|=value;else word&=~value;}
bool occupied(const Grid::Mask& mask,std::int32_t x,std::int32_t z){return(mask[std::size_t(x)*3+std::uint32_t(z)/32]&(1u<<(std::uint32_t(z)&31)))!=0;}
}
Grid Grid::import(std::span<const std::byte> bytes){
    if(bytes.size()<0x934)throw std::invalid_argument("Incomplete room-object grid section");
    Grid result;result.origin={std::bit_cast<float>(word(bytes,0)),std::bit_cast<float>(word(bytes,4)),std::bit_cast<float>(word(bytes,8))};result.width=std::bit_cast<std::int16_t>(std::uint16_t(word(bytes,12)));result.depth=std::bit_cast<std::int16_t>(std::uint16_t(word(bytes,16)));
    if(result.width<0||result.depth<0||result.width>96||result.depth>96||!std::isfinite(result.origin.x)||!std::isfinite(result.origin.y)||!std::isfinite(result.origin.z))throw std::invalid_argument("Unsupported room-object grid domain");
    for(unsigned i=0;i<result.base.size();++i){result.base[i]=word(bytes,0x14+4*i);result.padded[i]=word(bytes,0x494+4*i);}
    for(unsigned i=0;i<8;++i){const auto value=word(bytes,0x914+4*i);result.queries[i]={bool(value&1),std::uint8_t((value>>16)&127),std::uint8_t((value>>24)&127)};}return result;
}
Owner::Owner():domain_(std::make_shared<Domain>()){}
Owner Owner::import(std::span<const std::byte> types,std::span<const std::byte> placements){
    Owner result;const auto count=word(types,4),type_offset=word(types,8),model_offset=word(types,12);if(count>32)throw std::invalid_argument("Room-object type count exceeds physical capacity");result.type_count_=count;
    if(type_offset){if(type_offset>types.size()||std::size_t(count)*8>types.size()-type_offset)throw std::invalid_argument("Room-object type table outside owned blob");for(unsigned i=0;i<count;++i){const auto at=type_offset+8*i;auto& t=result.types_[i];t.profile=signed_byte(types,at);t.capacity=signed_byte(types,at+1);t.request_threshold=signed_byte(types,at+2);t.callback=std::to_integer<std::uint8_t>(types[at+3]);t.parameter4=std::to_integer<std::uint8_t>(types[at+4]);t.parameter5=std::to_integer<std::uint8_t>(types[at+5]);t.flags=std::uint16_t(word(types,at+4)>>16);if(t.profile<0||std::size_t(t.profile)>=profiles.size()||t.callback>=4)throw std::invalid_argument("Unsupported room-object profile/callback");}}
    if(model_offset){if(model_offset>types.size()||std::size_t(count)*2>types.size()-model_offset)throw std::invalid_argument("Room-object models outside owned blob");for(unsigned i=0;i<count;++i){const auto at=model_offset+2*i;result.types_[i].model_slot=std::uint16_t(std::to_integer<std::uint8_t>(types[at])|(std::uint16_t(std::to_integer<std::uint8_t>(types[at+1]))<<8));}}
    if(word(placements,0)!=2)throw std::invalid_argument("Unsupported room-object placement schema");
    const auto records=std::bit_cast<std::int32_t>(word(placements,4));if(records>0&&(std::size_t(records)>((placements.size()-8)/16)))throw std::invalid_argument("Room-object placements outside owned blob");
    for(std::int32_t i=0;i<records&&result.count_<31;++i){const auto b=placements.subspan(8+std::size_t(i)*16,16);auto& object=result.objects_[++result.count_];object.active=true;object.room=std::to_integer<std::uint8_t>(b[0]);object.external_id=std::to_integer<std::uint8_t>(b[1]);object.control_flags=word(b,12)|1;object.type=object.control_flags&4?31:std::uint16_t(std::int16_t(signed_byte(b,2)));if(object.type>=32||(!(object.control_flags&4)&&object.type>=count))throw std::invalid_argument("Placement type outside imported native table");const auto& t=result.types_[object.type];object.initial_x=object.x=signed_byte(b,3);object.initial_z=object.z=signed_byte(b,4);object.rotation=std::to_integer<std::uint8_t>(b[5])&3;object.allowed_directions=std::to_integer<std::uint8_t>(b[6])&15;
        if(object.control_flags&4){object.width=signed_byte(b,7);object.height=signed_byte(b,8);object.depth=signed_byte(b,9);}else{const auto& p=profiles[std::size_t(t.profile)];object.width=p[16];object.height=p[17];object.depth=p[18];}
        if(t.capacity==0)object.height=7;
        object.control_flags|=t.flags;object.parameter=t.parameter4;
    }result.initialized_=true;return result;
}
ObjectId Owner::id(std::uint32_t slot)const noexcept{ObjectId result;result.domain_=domain_;result.slot_=slot;return result;}
const Object* Owner::get(const ObjectId& handle)const noexcept{return handle&&handle.domain_==domain_&&handle.slot_<32&&objects_[handle.slot_].active?&objects_[handle.slot_]:nullptr;}
Object* Owner::mutable_object(const ObjectId& handle)noexcept{return get(handle)?&objects_[handle.slot_]:nullptr;}
std::optional<std::uint8_t> Owner::ordinal(const ObjectId& handle)const noexcept{return get(handle)?std::optional<std::uint8_t>(std::uint8_t(handle.slot_)):std::nullopt;}
std::vector<ObjectId> Owner::objects()const{std::vector<ObjectId> result;for(unsigned i=0;i<32;++i)if(objects_[i].active)result.push_back(id(i));return result;}
const Type* Owner::type(std::uint16_t index)const noexcept{return index<types_.size()?&types_[index]:nullptr;}
bool Owner::install_grid(std::uint16_t room,std::span<const std::byte> bytes){if(!count_)return false;bool present{};for(const auto& object:objects_)if(object.active&&object.room==room)present=true;if(!present)return false;auto imported=Grid::import(bytes);room_=room;grid_=std::move(imported);for(auto& object:objects_)if(object.active&&object.room==room_)object.center=center(object);rebuild();return true;}
Cell Owner::cell_at(Vec3 p)const noexcept{if(!grid_)return{};const auto x=(p.x-grid_->origin.x)/50,z=(p.z-grid_->origin.z)/50;const auto ix=integer(x),iz=integer(z);if(!ix||!iz)return{};return{*ix,*iz,x>=0&&z>=0&&x<float(grid_->width)&&z<float(grid_->depth)};}
Rectangle Owner::footprint(const Object& o)const{if(o.control_flags&4)return{o.x,o.z,std::int32_t(o.x)+o.width,std::int32_t(o.z)+o.depth};const auto& p=profiles[std::size_t(types_[o.type].profile)];const auto at=4*(o.rotation&3);return{std::int32_t(o.x)+p[at],std::int32_t(o.z)+p[at+1],std::int32_t(o.x)+p[at+2],std::int32_t(o.z)+p[at+3]};}
Vec3 Owner::center(const Object& o)const{if(!grid_)return{};const auto r=footprint(o);return{grid_->origin.x+50.0f*float(o.x)+25.0f*float(r.min_x+r.max_x-2*o.x),grid_->origin.y,grid_->origin.z+50.0f*float(o.z)+25.0f*float(r.min_z+r.max_z-2*o.z)};}
std::optional<ObjectId> Owner::at_cell(std::int32_t x,std::int32_t z)const{if(!grid_||x<0||z<0||x>=grid_->width||z>=grid_->depth)return{};for(unsigned i=0;i<32;++i){const auto& o=objects_[i];if(!o.active||!(o.control_flags&1)||o.room!=room_)continue;const auto r=footprint(o);if(x>=r.min_x&&x<=narrow(r.max_x-1)&&z>=r.min_z&&z<=narrow(r.max_z-1))return id(i);}return{};}
std::optional<ObjectId> Owner::mapped(std::size_t index)const noexcept{if(index>=8)return{};const auto& m=mappings_[index];return m&&get(*m)?m:std::nullopt;}
bool Owner::mapped_external(std::size_t index,std::int8_t external)const noexcept{const auto m=mapped(index);if(!m)return false;const auto* o=get(*m);return std::int32_t(o->external_id)==external&&!(o->control_flags&2);}
bool Owner::mapped_presence(std::size_t index,bool desired)const noexcept{const auto m=mapped(index);return desired?bool(m):!m||(get(*m)->control_flags&2);}
Object* Owner::active_external(std::uint8_t external)noexcept{for(auto& o:objects_)if(o.active&&o.external_id==external)return &o;return nullptr;}
bool Owner::move_external(std::uint8_t external,std::uint8_t x,std::uint8_t z){if(external>=32||!grid_||std::int32_t(x)>=grid_->width||std::int32_t(z)>=grid_->depth)return false;auto* o=active_external(external);if(!o)return false;o->x=std::bit_cast<std::int8_t>(x);o->z=std::bit_cast<std::int8_t>(z);o->center=center(*o);return true;}
bool Owner::change_external_flags(std::uint8_t external,std::uint32_t set,std::uint32_t clear){if(external>=32)return false;auto* o=active_external(external);if(!o)return false;o->control_flags=(o->control_flags&~clear)|set;return true;}
bool Owner::enable_external(std::int8_t external,bool enabled){if(external<0)return false;for(auto& o:objects_)if(o.external_id==std::uint8_t(external)){if(!o.active)return false;if(enabled)o.control_flags|=1;else o.control_flags&=~1u;rebuild();return true;}return false;}
void Owner::rebuild(){if(!grid_)return;layers_[0]=grid_->base;for(unsigned i=1;i<4;++i)layers_[i].fill(0xffffffffu);for(const auto& o:objects_){if(!o.active||!(o.control_flags&1)||o.room!=room_)continue;const auto r=footprint(o);for(auto x=r.min_x;x<r.max_x;++x)for(auto z=r.min_z;z<r.max_z;++z){bit(layers_[0],x,z,true);if(types_[o.type].capacity>0)for(unsigned layer=1;layer<4;++layer)if(o.height==std::int32_t(layer*2))bit(layers_[layer],x,z,false);}}
    for(unsigned i=0;i<8;++i)if(grid_->queries[i].active)mappings_[i]=at_cell(grid_->queries[i].x,grid_->queries[i].z);else mappings_[i].reset();
}
Classified Owner::classify(Vec3 point,bool height_layers,const response::Grid* floors)const{const auto cell=cell_at(point);if(!grid_)return{Classification::outside,cell};auto height=band(point.y,grid_->origin.y);if(!height)return{Classification::unknown_height,cell};if(!height_layers)height=0;
    if(cell.inside){if(*height==0)return{at_cell(narrow(cell.x),narrow(cell.z))?Classification::blocked:Classification::clear,cell};if(*height<0||*height>6||(*height&1))return{Classification::unknown_height,cell};return{occupied(layers_[unsigned(*height)/2],cell.x,cell.z)?Classification::blocked:Classification::clear,cell};}
    if(*height<=0)return{Classification::outside,cell};
    if(!floors)return{Classification::missing_floor,cell};
    const auto floor=band(floors->floor(point).height,grid_->origin.y);return{floor&&*floor==*height?Classification::outside:Classification::incompatible,cell};
}
Classified Owner::refine(Vec3 point,bool height_layers,std::optional<ObjectId> excluded,const response::Grid* floors)const{auto result=classify(point,height_layers,floors);if(result.status!=Classification::clear)return result;const auto object=at_cell(narrow(result.cell.x),narrow(result.cell.z));if(!object)return result;if(excluded&&*excluded==*object)return result;const auto* o=get(*object);if(o->count>=types_[o->type].capacity)result.status=Classification::blocked;return result;}
}
