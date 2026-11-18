#include "room_geometry.hpp"
#include <bit>
#include <cmath>
#include <stdexcept>
namespace reo::native::gameplay_collision::room_geometry {
namespace {
Vec3 add(Vec3 a,Vec3 b){return{a.x+b.x,a.y+b.y,a.z+b.z};}
float dot(Vec3 a,Vec3 b){return(a.x*b.x+a.y*b.y)+a.z*b.z;}
std::optional<std::int32_t> integer(float value){const auto x=std::trunc(double(value));if(!std::isfinite(x)||x<-2147483648.0||x>2147483647.0)return{};return std::int32_t(x);}
constexpr std::array<std::int8_t,10> heights{1,2,2,2,3,4,2,1,3,5};
}
std::optional<Quads> quads(const room_objects::Owner& owner,const room_objects::Object& object)noexcept{
    if(!object.active||!owner.grid())return{};
    Quads result;const auto center=owner.center(object);const auto turn=std::uint16_t(object.rotation<<14);float angle=(3.1415927410125732f*(0.0054931640625f*float(turn)))/180.0f;if(angle>3.1415927410125732f)angle+=-6.2831854820251465f;const auto sine=std::sin(angle),cosine=std::cos(angle);
    constexpr std::array<float,4> x{-0.5f,-0.5f,0.5f,0.5f},z{-0.5f,0.5f,0.5f,-0.5f},a{15,-15,-15,15},b{15,15,-15,-15};
    for(unsigned i=0;i<4;++i){const auto local_x=x[i]*(float(object.width)*50),local_z=z[i]*(float(object.depth)*50);const auto world_x=(cosine*local_x+0.0f)+sine*local_z,world_z=(-sine*local_x+0.0f)+cosine*local_z;const auto expanded=integer_xz({(center.x+world_x)+10*x[i],0,(center.z+world_z)+10*z[i]}),first=integer_xz({(center.x+world_x)+10*x[i],0,(center.z+world_z)+a[i]}),second=integer_xz({(center.x+world_x)+b[i],0,(center.z+world_z)+10*z[i]}),exact=integer_xz({center.x+world_x,0,center.z+world_z});if(!expanded||!first||!second||!exact)return{};result.expanded[i]=*expanded;result.first[i]=*first;result.second[i]=*second;result.exact[i]=*exact;}
    return result;
}
ProxyDescriptions proxies(const room_objects::Owner& owner,const room_objects::Object& object,Instance instance){
    ProxyDescriptions result;if(object.control_flags&4)return result;const auto* type=owner.type(object.type);if(!type||type->profile==7)return result;if(!instance.id){result.missing_owner=true;return result;}const auto geometry=quads(owner,object);if(!geometry)throw std::invalid_argument("Invalid native room-object proxy geometry");const auto lower=integer(instance.position.y);if(!lower)throw std::invalid_argument("Invalid native room-object height");const auto upper=std::bit_cast<std::int32_t>(std::uint32_t(*lower)+std::uint32_t(50*heights[std::size_t(type->profile)]-1));
    if(type->request_threshold>0&&(object.allowed_directions&15))result.records[0]=ownership::owned_region(0x81,geometry->expanded,*lower,upper,instance.id,instance.object_ordinal);
    if(type->capacity>0){result.records[1]=ownership::owned_region(0x82,geometry->first,*lower,upper,instance.id,instance.object_ordinal,0);result.records[2]=ownership::owned_region(0x82,geometry->second,*lower,upper,instance.id,instance.object_ordinal,1);result.records[3]=ownership::owned_region(0x83,geometry->exact,upper,std::bit_cast<std::int32_t>(std::uint32_t(upper)+50),instance.id,instance.object_ordinal);}
    return result;
}
room_objects::Grid::Mask combined_occupancy(const room_objects::Owner& owner,std::span<const Occupant> actors){
    auto result=owner.layers()[0];const auto* grid=owner.grid();if(!grid)return result;constexpr std::array<Point,8> signs{{{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1}}};
    for(const auto& actor:actors){if(!actor.active||!actor.visible)continue;const auto height=integer((1.0f+actor.position.y)-grid->origin.y);if(!height||*height/50!=0)continue;for(const auto sign:signs){const auto cell=owner.cell_at({actor.position.x+49.5f*float(sign.x),actor.position.y,actor.position.z+49.5f*float(sign.z)});if(cell.inside)result[std::size_t(cell.x)*3+std::uint32_t(cell.z)/32]|=1u<<(std::uint32_t(cell.z)&31);}}
    return result;
}
Prism prism(const room_objects::Owner& owner,const room_objects::Object& object,const response::Grid& walls,response::Filter filter,std::span<const response::Triangle> existing){
    Prism result;const auto* grid=owner.grid();const auto* type=owner.type(object.type);if(!grid||!type)throw std::invalid_argument("Missing native prism resource owner");const auto bounds=owner.footprint(object);const auto min_x=grid->origin.x+float(bounds.min_x)*50,max_x=grid->origin.x+float(bounds.max_x)*50,min_z=grid->origin.z+float(bounds.min_z)*50,max_z=grid->origin.z+float(bounds.max_z)*50;auto ceiling=grid->origin.y+float(object.control_flags&4?object.height:heights[std::size_t(type->profile)])*50;if(type->capacity<1&&ceiling-grid->origin.y<300)ceiling=grid->origin.y+300;const auto base=grid->origin.y;
    result.vertices={Vec3{min_x,ceiling,min_z},Vec3{min_x,base,min_z},Vec3{min_x,ceiling,max_z},Vec3{min_x,base,max_z},Vec3{max_x,ceiling,max_z},Vec3{max_x,base,max_z},Vec3{max_x,ceiling,min_z},Vec3{max_x,base,min_z}};std::array<Vec3,8> offsets{};constexpr std::array<Vec3,4> rays{{{-90,0,0},{0,0,90},{90,0,0},{0,0,-90}}};filter.include=0x4ffff;filter.exclude=0;filter.dynamic_kind_gate=false;
    for(unsigned side=0;side<4;++side){const auto i=side*2,j=(i+2)&7,k=(i+3)&7;const auto a=result.vertices[k],b=result.vertices[j],c=result.vertices[i],d=result.vertices[i+1];const Vec3 start{((a.x+b.x)+c.x+d.x)/4,((a.y+b.y)+c.y+d.y)/4,((a.z+b.z)+c.z+d.z)/4};const auto query=trace::any(walls,start,add(start,rays[side]),filter,existing);if(query.status==trace::SamplingStatus::capacity||query.status==trace::SamplingStatus::nonprogress){result.status=query.status;return result;}if(query.hit){result.inflated[side]=true;for(const auto index:{i,i+1,j,k})offsets[index]=add(offsets[index],rays[side]);}}
    for(unsigned i=0;i<8;++i)result.vertices[i]=add(result.vertices[i],offsets[i]);
    constexpr std::array<std::array<unsigned,3>,8> indices{{{{0,1,2}},{{2,3,1}},{{4,5,6}},{{6,5,7}},{{0,1,7}},{{6,7,0}},{{2,3,4}},{{4,5,3}}}};constexpr std::array<Vec3,4> normals{{{-1,0,0},{1,0,0},{0,0,-1},{0,0,1}}};for(unsigned i=0;i<8;++i){auto& t=result.triangles[i];t.flags=0x270000;t.normal=normals[i/2];for(unsigned v=0;v<3;++v)t.vertices[v]=result.vertices[indices[i][v]];t.plane_d=-dot(t.vertices[0],t.normal);}return result;
}
Dynamic build_dynamic(const room_objects::Owner& owner,std::uint16_t room,const response::Grid& walls,response::Filter filter){Dynamic result;for(const auto& id:owner.objects()){const auto& object=*owner.get(id);if(!(object.control_flags&1)||object.room!=room)continue;const auto geometry=prism(owner,object,walls,filter,result.triangles());if(geometry.status==trace::SamplingStatus::capacity||geometry.status==trace::SamplingStatus::nonprogress){result.status=geometry.status;return result;}for(const auto& triangle:geometry.triangles){++result.attempted;if(result.count<result.storage.size())result.storage[result.count++]=triangle;else ++result.dropped;}}return result;}
}
