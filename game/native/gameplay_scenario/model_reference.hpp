#pragma once
#include <cstdint>
#include <concepts>
#include <array>
#include <memory>
#include <optional>
#include <utility>

namespace reo::native::gameplay_scenario {
class RoomSceneInput;
class RoomSceneOwner;
class SceneModels;
struct AuthoredModelDomain final {};

// An authored asset reference is not a physical model-array index. Raw values
// outside the128 real slots are unavailable. Only the bounded room parser can
// mint the distinct authored NoModel sentinel and its immutable provenance.
class ModelReference final {
public:
    enum class Kind : std::uint8_t {real,authored_absent,unavailable};
    ModelReference()noexcept=default;
    ModelReference(std::uint32_t value)noexcept:value_(value),kind_(value<128?Kind::real:Kind::unavailable){}
    Kind kind()const noexcept{return kind_;}
    std::optional<std::uint8_t> slot()const noexcept{return kind_==Kind::real?std::optional<std::uint8_t>(std::uint8_t(value_)):std::nullopt;}
    bool absent()const noexcept{return kind_==Kind::authored_absent;}
    std::uint32_t encoded()const noexcept{return value_;}
    ModelReference byte_view()const noexcept{return absent()?*this:ModelReference(value_&255u);}
    // Compatibility with existing authored-word fixtures/callers. Native
    // operations use typed overloads; converting back never grants admission.
    operator std::uint32_t()const noexcept{return encoded();}
    friend bool operator==(const ModelReference&,const ModelReference&)=default;
    template<std::integral T> friend bool operator==(const ModelReference& ref,T value)noexcept{return std::cmp_equal(ref.value_,value);}
private:
    std::uint32_t value_{};
    Kind kind_{Kind::real};
    std::shared_ptr<const AuthoredModelDomain> origin_;
    static ModelReference authored(std::uint8_t value,const std::shared_ptr<const AuthoredModelDomain>& origin)noexcept{
        ModelReference result(value);
        if(value==255&&origin){result.kind_=Kind::authored_absent;result.origin_=origin;}
        return result;
    }
    friend class RoomSceneInput;
    friend class RoomSceneOwner;
    friend class SceneModels;
};

// The room owner holds the only strong installation lease. Model references
// retain asset provenance, while SceneModels keeps a weak lease; teardown makes
// missing-model operations unavailable without touching a destroyed owner.
class AuthoredModelLease final {
private:
    explicit AuthoredModelLease(std::shared_ptr<const AuthoredModelDomain> domain,const std::array<std::uint8_t,32>& mapping,std::uint16_t channels):origin_(std::move(domain)),mapping_(mapping),channels_(channels){}
    std::shared_ptr<const AuthoredModelDomain> origin_;
    std::array<std::uint8_t,32> mapping_;
    std::uint16_t channels_{};
    friend class RoomSceneOwner;
    friend class SceneModels;
};
} // namespace reo::native::gameplay_scenario
