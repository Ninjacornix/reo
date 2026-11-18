#pragma once
#include "../gameplay_scenario/lighting.hpp"
#include <vector>
namespace reo::native::gameplay_lighting {
using Definition=gameplay_scenario::LightDescriptor;
using Light=gameplay_scenario::NativeLight;
using LightId=gameplay_scenario::LightHandle;
inline Definition decode_definition(std::span<const std::byte> bytes){return gameplay_scenario::decode_light_descriptor(bytes);}
enum class Status {completed,full,foreign_or_stale,closed};
struct Created {Status status{Status::closed};LightId id;std::optional<Light> light;};
struct FrameEntry {LightId id;Light value;};
// Borrowed capability view over the existing canonical scenario lighting
// owner. It has no second pool or live payload copy. Immutable snapshots can
// outlive reuse; timed consumers use handles that cannot retarget generations.
// The canonical Lighting must outlive this facade. Destruction does not reset it.
class Pool final {
public:
    explicit Pool(gameplay_scenario::Lighting& owner):owner_(owner){}
    Pool(const Pool&)=delete;
    Pool& operator=(const Pool&)=delete;
    Created allocate()noexcept;
    Created create(const std::optional<Definition>&,std::uint8_t selector,std::uint8_t variant)noexcept;
    Status retire(const LightId&)noexcept;
    Status replace(const LightId&,const Definition&)noexcept;
    std::optional<Light> retain(const LightId&)const noexcept;
    std::optional<std::uint8_t> physical_slot(const LightId&)const noexcept;
    std::vector<FrameEntry> snapshot()const;
    Status reset()noexcept;
    void close()noexcept;
    std::size_t size()const noexcept{return closed_?0:owner_.primary_count();}
    bool closed()const noexcept{return closed_;}
    bool bound_to(const gameplay_scenario::Lighting& value)const noexcept{return !closed_&&(&owner_==&value);}
private:
    gameplay_scenario::Lighting& owner_;
    bool closed_{};
};
}
