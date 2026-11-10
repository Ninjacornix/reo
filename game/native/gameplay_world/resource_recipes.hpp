#pragma once
#include "resource_pairs.hpp"
#include "resource_contents.hpp"
#include "inventory.hpp"
namespace reo::native::gameplay_world {
enum class RecipePrimitive {
    merge_positive,merge_matching,replace_owned_and_consume,replace_owned,
    redistribute,swap_into_second,fill_first,replace_from_195,
    consume_owner_199,consume_19a,replace_with_reverse_followup,
    merge_general,replace_general_and_consume
};
// Actual recipe primitive consumers; no simulated record pointers. Full owned
// recipe dispatch additionally needs the canonical cooperative event owner.
class ResourceRecipes final {
public:
    ResourceRecipes(ResourcePairs&,ResourceContents&,WorldInventory&);
    std::int8_t primitive(RecipePrimitive,std::uint8_t first,std::uint8_t second,std::uint32_t new_content=0);
    // Complete5B3490: active pair, flag1 publication, low-byte kind3/4 paths.
    std::int8_t combine_active(std::uint32_t first,std::uint32_t second);
private:
    friend class OwnedResourceRecipes;
    friend class ResourceConsumption;
    friend class ResourceHealthEffects;
    friend class ResourceDeployment;
    friend class ResourceEffects;
    ResourcePairs& pairs_;ResourceContents& contents_;WorldInventory& inventory_;
    std::int8_t merge(std::uint8_t,std::uint8_t,bool require_positive,bool reject_full,bool general);
    std::int8_t redistribute(std::uint8_t,std::uint8_t,std::uint32_t);
    std::int8_t fill(std::uint8_t,std::uint8_t);
    std::int8_t consume_owner(std::uint8_t,std::uint8_t,std::uint32_t);
    void destroy_general(std::uint8_t);
};
}
