#pragma once
#include "ownership.hpp"
namespace reo::native::gameplay_collision::room_objects {
struct Domain;
class Owner;
class InteractionOwner;
class ObjectId final {
public:
    ObjectId()=default;
    explicit operator bool()const noexcept{return bool(domain_);}
    friend bool operator==(const ObjectId&,const ObjectId&)=default;
private:
    std::shared_ptr<const Domain> domain_;
    std::uint32_t slot_{};
    friend class Owner;
};
struct Type {
    std::int8_t profile{},capacity{},request_threshold{};
    std::uint8_t callback{},parameter4{},parameter5{};
    std::uint16_t flags{},model_slot{65535};
};
struct Object {
    bool active{};
    std::uint8_t room{},external_id{},allowed_directions{},parameter{};
    std::uint16_t type{},rotation{};
    std::int8_t initial_x{},initial_z{},x{},z{},width{},height{},depth{};
    std::int8_t count{},requests{};
    std::uint8_t direction{},secondary_direction{};
    std::uint32_t control_flags{};
    Vec3 center;
    gameplay_actors::EntityId instance;
    std::array<ownership::Handle,4> proxies;
};
struct Rectangle {std::int32_t min_x{},min_z{},max_x{},max_z{};};
struct Cell {std::int32_t x{},z{};bool inside{};};
struct Grid {
    Vec3 origin;
    std::int16_t width{},depth{};
    using Mask=std::array<std::uint32_t,96*3>;
    Mask base{},padded{};
    struct Query{bool active{};std::uint8_t x{},z{};};
    std::array<Query,8> queries;
    static Grid import(std::span<const std::byte>);
};
enum class Classification {outside=0,clear=1,blocked=2,incompatible=3,unknown_height=4,missing_floor=5};
struct Classified {Classification status{};Cell cell;};
// Separate from SceneResources256 and linked SceneControls. Native ownership
// preserves32 physical records, the allocator's reserved slot0 and external IDs.
class Owner final {
public:
    Owner();
    Owner(const Owner&)=delete;
    Owner& operator=(const Owner&)=delete;
    Owner(Owner&&)=default;
    Owner& operator=(Owner&&)=default;
    static Owner import(std::span<const std::byte> types,std::span<const std::byte> placements);
    const Object* get(const ObjectId&)const noexcept;
    std::vector<ObjectId> objects()const;
    const Type* type(std::uint16_t)const noexcept;
    bool install_grid(std::uint16_t room,std::span<const std::byte>);
    const Grid* grid()const noexcept{return grid_?&*grid_:nullptr;}
    bool initialized()const noexcept{return initialized_;}
    Cell cell_at(Vec3)const noexcept;
    Rectangle footprint(const Object&)const;
    Vec3 center(const Object&)const;
    std::optional<ObjectId> at_cell(std::int32_t,std::int32_t)const;
    std::optional<ObjectId> mapped(std::size_t)const noexcept;
    bool mapped_external(std::size_t,std::int8_t)const noexcept;
    bool mapped_presence(std::size_t,bool)const noexcept;
    bool move_external(std::uint8_t external,std::uint8_t x,std::uint8_t z);
    bool change_external_flags(std::uint8_t external,std::uint32_t set,std::uint32_t clear);
    bool enable_external(std::int8_t external,bool);
    void rebuild();
    Classified classify(Vec3,bool height_layers,const response::Grid* floors=nullptr)const;
    Classified refine(Vec3,bool height_layers,std::optional<ObjectId> excluded,const response::Grid* floors=nullptr)const;
    const std::array<Grid::Mask,4>& layers()const noexcept{return layers_;}
private:
    friend class InteractionOwner;
    std::shared_ptr<const Domain> domain_;
    std::array<Object,32> objects_{};
    std::array<Type,32> types_{};
    std::size_t count_{},type_count_{};
    bool initialized_{};
    std::optional<Grid> grid_;
    std::uint16_t room_{};
    std::array<Grid::Mask,4> layers_{};
    std::array<std::optional<ObjectId>,8> mappings_;
    ObjectId id(std::uint32_t)const noexcept;
    Object* active_external(std::uint8_t)noexcept;
    Object* mutable_object(const ObjectId&)noexcept;
    std::optional<std::uint8_t> ordinal(const ObjectId&)const noexcept;
};
}
