#include "geometry.hpp"
#include <algorithm>
#include <bit>
#include <cstring>
#include <limits>
#include <stdexcept>
namespace reo::native::gameplay_effects {
namespace {
template<class T>T read(std::span<const std::byte> bytes,std::size_t at){
    if(at>bytes.size()||sizeof(T)>bytes.size()-at)throw std::invalid_argument("Truncated native effect geometry/material asset");
    T value;std::memcpy(&value,bytes.data()+at,sizeof value);return value;
}
struct Chunk {std::span<const std::byte> bytes;std::uint32_t type,count;};
std::vector<Chunk> chunks(std::span<const std::byte> bytes){
    const auto count=read<std::uint32_t>(bytes,4),length=read<std::uint32_t>(bytes,8);
    if(length<12||length>bytes.size()||count>(length-12)/12)throw std::invalid_argument("Invalid native effect chunk header");
    bytes=bytes.first(length);std::vector<Chunk> result;result.reserve(count);std::size_t at=12;
    for(std::uint32_t i=0;i<count;++i){
        const auto type=read<std::uint32_t>(bytes,at),n=read<std::uint32_t>(bytes,at+4),size=read<std::uint32_t>(bytes,at+8);
        if(size<12||size>bytes.size()-at)throw std::invalid_argument("Invalid native effect chunk extent");
        result.push_back({bytes.subspan(at,size),type,n});at+=size;
    }
    if(at!=bytes.size())throw std::invalid_argument("Unconsumed native effect chunk bytes");
    return result;
}
std::optional<Chunk> find_chunk(std::span<const std::byte> bytes,std::uint32_t type){
    const auto count=read<std::uint32_t>(bytes,4),length=read<std::uint32_t>(bytes,8);
    if(length<12||length>bytes.size())throw std::invalid_argument("Invalid native effect searchable chunk extent");
    bytes=bytes.first(length);std::size_t at=12;
    // Match the original early-return lookup. Stock type4 object counts exceed
    // the physically contained child count; finding an authored required tag
    // must not eagerly walk later, unconsumed records or beyond the object.
    for(std::uint32_t i=0;i<count;++i){
        const auto tag=read<std::uint32_t>(bytes,at),n=read<std::uint32_t>(bytes,at+4),size=read<std::uint32_t>(bytes,at+8);
        if(size<12||size>bytes.size()-at)throw std::invalid_argument("Invalid native effect searchable chunk");
        if(tag==type)return Chunk{bytes.subspan(at,size),tag,n};
        at+=size;
    }
    return{};
}
std::span<const std::byte> section(std::span<const std::byte> bytes,unsigned field){
    const auto at=read<std::uint32_t>(bytes,field),size=read<std::uint32_t>(bytes,field+4);
    if(!at||!size||at>bytes.size()||size>bytes.size()-at)throw std::invalid_argument("Missing native effect NBD section");
    return bytes.subspan(at,size);
}
}
std::shared_ptr<const Geometry> Geometry::import_nbd(std::span<const std::byte> bytes){
    const auto model=section(bytes,0x14),forest=section(bytes,0x24);
    const auto top=chunks(model);const auto objects=std::find_if(top.begin(),top.end(),[](const auto& c){return c.type==2;});
    if(objects==top.end())throw std::invalid_argument("Missing native effect model objects");
    auto geometry=std::make_shared<Geometry>();
    for(const auto& object:chunks(objects->bytes)){
        if(object.type!=4)throw std::invalid_argument("Native effect geometry object profile unavailable");
        MeshChannels mesh;const auto list=find_chunk(object.bytes,0x50000);
        if(list){
            // Child runtime storage50..6C owns eight scalar values. Refuse a
            // profile that would overrun that original published-piece layout.
            if(list->count>8||list->count>(list->bytes.size()-12)/4)throw std::invalid_argument("Native effect material slot extent unavailable");
            for(unsigned i=0;i<list->count;++i)mesh.indices.push_back(read<std::uint32_t>(list->bytes,12+4*i));
        }
        geometry->meshes_.push_back(std::move(mesh));
    }
    const auto roots=chunks(forest);const auto table=std::find_if(roots.begin(),roots.end(),[](const auto& c){return !(c.type&255);});
    if(table==roots.end()||!table->count||table->count>(table->bytes.size()-12)/4)throw std::invalid_argument("Missing native effect geometry roots");
    for(unsigned i=0;i<table->count;++i){
        const auto skeleton=animation::Skeleton::import_raw(forest,i);const auto nodes=skeleton->nodes();
        // Source1A2E00 raw44 -> packed2 ->193BD0 nodeC6 (root identity),
        // raw40 -> packedA -> node174 (mesh palette), independently of raw0.
        GeometryRoot root;root.id=std::bit_cast<std::int16_t>(nodes.front().track);
        const auto first=read<std::uint32_t>(table->bytes,12+4*i);
        const auto end=i+1<table->count?read<std::uint32_t>(table->bytes,16+4*i):std::uint32_t(std::count_if(roots.begin(),roots.end(),[](const auto& c){return c.type&255;}));
        // Original1D3350 iterates to the next authored root index even when
        // packing produced fewer reachable nodes. That reads stale workspace
        // nodes. Keep the root identity but explicitly refuse this palette.
        root.palette_admitted=end>=first&&std::size_t(end-first)==nodes.size();
        for(std::size_t j=1;j<nodes.size();++j)if(nodes[j].static_index>=0){
            if(std::size_t(nodes[j].static_index)>=geometry->meshes_.size())throw std::invalid_argument("Native effect palette exceeds owned meshes");
            root.meshes.push_back(std::size_t(nodes[j].static_index));
        }
        // Source fixed32-byte rows admit16 palette references per root.
        if(root.meshes.size()>16)throw std::invalid_argument("Native effect root palette exceeds observed row profile");
        geometry->roots_.push_back(std::move(root));
    }
    return geometry;
}
std::optional<std::size_t> Geometry::resolve(std::int16_t id)const noexcept{
    for(std::size_t i=0;i<roots_.size();++i)if(roots_[i].id==id)return i;
    return{};
}
const MeshChannels* Geometry::material(std::size_t root,std::uint8_t slot)const noexcept{
    if(root>=roots_.size()||!roots_[root].palette_admitted||slot>=roots_[root].meshes.size())return nullptr;
    return &meshes_[roots_[root].meshes[slot]];
}
std::shared_ptr<const MaterialTracks> MaterialTracks::import(std::span<const std::byte> bytes,const Geometry& geometry){
    constexpr std::size_t base=1024;const auto relative=read<std::uint32_t>(bytes,base+4);
    if(bytes.size()<base||relative>bytes.size()-base)throw std::invalid_argument("Native effect common material table exceeds asset");
    const auto table=base+std::size_t(relative);std::vector<std::uint32_t> indices;
    for(const auto& mesh:geometry.meshes())indices.insert(indices.end(),mesh.indices.begin(),mesh.indices.end());
    std::sort(indices.begin(),indices.end());indices.erase(std::unique(indices.begin(),indices.end()),indices.end());
    auto tracks=std::make_shared<MaterialTracks>();tracks->entries_.reserve(indices.size());
    for(const auto index:indices){
        if(std::size_t(index)>=(bytes.size()-table)/8)throw std::invalid_argument("Native effect common channel index exceeds asset");
        const auto at=table+std::size_t(index)*8;Entry entry;entry.index=index;
        if(read<std::int16_t>(bytes,at+6)==11){
            const auto offset=read<std::uint32_t>(bytes,at);
            if(offset>bytes.size()-base)throw std::invalid_argument("Native effect material keys exceed asset");
            entry.curve=Curve::import(bytes,base+std::size_t(offset),read<std::int16_t>(bytes,at+4));
        }
        tracks->entries_.push_back(std::move(entry));
    }
    return tracks;
}
void MaterialTracks::sample(const MeshChannels& mesh,std::int16_t time,std::span<float> values)const{
    if(values.size()<mesh.indices.size())throw std::invalid_argument("Native effect material destination too small");
    for(std::size_t i=0;i<mesh.indices.size();++i){
        const auto index=mesh.indices[i];const auto entry=std::lower_bound(entries_.begin(),entries_.end(),index,[](const Entry& value,auto key){return value.index<key;});
        if(entry==entries_.end()||entry->index!=index)throw std::invalid_argument("Native effect material curve not admitted");
        if(entry->curve)values[i]=1.f-entry->curve->sample(time)/16.f;
    }
}
bool MaterialTracks::complete(const MeshChannels& mesh)const noexcept{
    for(const auto index:mesh.indices){
        const auto entry=std::lower_bound(entries_.begin(),entries_.end(),index,[](const Entry& value,auto key){return value.index<key;});
        if(entry==entries_.end()||entry->index!=index||!entry->curve)return false;
    }
    return true;
}
}
