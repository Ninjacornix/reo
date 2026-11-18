#pragma once
#include "model.hpp"
namespace reo::native::animation {
struct ConstraintContext {
    Matrix relative_first{},relative_second{};
    std::uint16_t mode{},enabled{};
    float twist{};
    std::size_t first_node{},second_node{};
    float first_length{},second_length{};
    Vector reference{},target{};
    float bend{};
};
enum class ConstraintCallback {none,two_link,already_solved,standard};
struct ConstraintBinding {ConstraintCallback callback{ConstraintCallback::none};std::size_t context{};};
class Constraints {
public:
    static constexpr std::size_t context_count=7;
    explicit Constraints(std::shared_ptr<Instance>);
    const std::shared_ptr<Instance>& model()const noexcept{return model_;}
    std::span<const ConstraintContext,context_count> contexts()const noexcept{return contexts_;}
    std::span<const ConstraintBinding> bindings()const noexcept{return bindings_;}
    bool any_enabled()const noexcept;
    std::shared_ptr<Constraints> replacement(std::shared_ptr<Instance>)const;
    // Copy an existing constraint snapshot to an independently copied model
    // with the exact same authored topology. Unlike reconstruction, preserve
    // every context, callback binding and solved state, including contexts2..6.
    std::shared_ptr<Constraints> clone_for_model(std::shared_ptr<Instance>)const;
    void reference(std::size_t context,Vector);
    void target(std::size_t context,Vector);
    std::span<const float,2> floor_heights()const noexcept{return floor_heights_;}
    void floor_height(std::size_t index,float);
    void invalidate_pose()noexcept;
    void create(std::size_t context,std::uint16_t mode,std::size_t first,std::size_t middle,std::size_t last,Vector scale,float twist,Vector auxiliary);
    // Complete5D6850: paused !=0 preserves all prior contexts/bindings.
    void initialize_mirrored(std::int8_t paused,Vector scale);
    void rebuild(const Matrix& parent);
private:
    std::shared_ptr<Instance> model_;
    std::array<ConstraintContext,context_count> contexts_{};
    std::vector<ConstraintBinding> bindings_;
    std::array<float,2> floor_heights_{};
    void solve(std::size_t context,std::size_t node,const Matrix& parent);
};
} // namespace reo::native::animation
