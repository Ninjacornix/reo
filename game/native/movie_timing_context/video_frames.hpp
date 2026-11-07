#pragma once
#include "context.hpp"
#include <array>
#include <span>
namespace reo::native::movie_timing_context {
struct Picture {
    std::uint32_t state{},references{};Words time;
};
struct PictureSelection {int first{-1},second{-1};std::uint32_t count{};bool last{};};
// Original numeric pool policy. Pixel ownership is deliberately in VideoFrames.
class PicturePool final {
public:
    explicit PicturePool(std::span<const Picture>);
    explicit PicturePool(std::uint32_t count);
    [[nodiscard]] int reserve()noexcept;
    [[nodiscard]] Result can_advance(Context&)const noexcept;
    [[nodiscard]] PictureSelection select(std::uint32_t end)const noexcept;
    void release(std::uint32_t)noexcept;
    void demote(std::uint32_t)noexcept;
    [[nodiscard]] std::span<const Picture> pictures()const noexcept{return{pictures_.data(),count_};}
private:
    friend class VideoFrames;
    std::array<Picture,16> pictures_{};std::uint32_t count_{};
};
enum class FrameStatus {completed,pending,empty,held,busy,closed,invalid_key,invalid_input,provider_failure,clock_failure};
// Owner-thread only. Each surface retains its real decoder/render resources.
// ready/submit/retire never wait on CPU. retire succeeds only after all producer
// and reader fences. drain is the explicit blocking STOP/destructor fallback.
// Calls are noexcept/nonreentrant; no timeouts or elapsed-time completion guesses.
class FrameSurface {
public:
    virtual ~FrameSurface()=default;
    virtual FrameStatus ready()noexcept=0;
    virtual FrameStatus submit()noexcept=0;
    virtual FrameStatus retire()noexcept=0;
    virtual void drain()noexcept=0;
};
struct FrameIdentity;
class FrameKey final {
public:
    FrameKey()=default;
    bool operator==(const FrameKey& other)const noexcept {
        return serial_==other.serial_ && slot_==other.slot_ && !owner_.owner_before(other.owner_) && !other.owner_.owner_before(owner_);
    }
private:
    friend class VideoFrames;
    std::weak_ptr<const FrameIdentity> owner_;std::uint64_t serial_{};std::uint32_t slot_{};
};
struct FrameResult {FrameStatus status{FrameStatus::invalid_input};FrameKey key{};bool decision{},last{};};
struct FrameSnapshot {
    std::array<Picture,16> pictures;std::array<bool,16> borrowed;
    std::uint32_t count{},resources{},references{},end{};int current{-1};
    bool closing{},closed{};
};
class VideoFrames final:public std::enable_shared_from_this<VideoFrames> {
public:
    [[nodiscard]] static std::shared_ptr<VideoFrames> create(std::shared_ptr<Context>,std::uint32_t count);
    ~VideoFrames();
    VideoFrames(const VideoFrames&)=delete;VideoFrames& operator=(const VideoFrames&)=delete;
    [[nodiscard]] FrameResult reserve()noexcept;
    [[nodiscard]] FrameStatus publish(const FrameKey&,Words,std::shared_ptr<FrameSurface>,bool reference=false)noexcept;
    [[nodiscard]] FrameResult acquire()noexcept;
    [[nodiscard]] FrameResult peek()noexcept;
    [[nodiscard]] FrameResult can_advance()noexcept;
    // An explicit bounded caller decision: original advance predicate followed
    // by one public get/release. It never discards decoded reference surfaces.
    [[nodiscard]] FrameResult skip_if_due()noexcept;
    [[nodiscard]] FrameStatus present(const FrameKey&)noexcept;
    [[nodiscard]] FrameStatus release(const FrameKey&)noexcept;
    [[nodiscard]] FrameStatus retain_reference(const FrameKey&)noexcept;
    [[nodiscard]] FrameStatus release_reference(const FrameKey&)noexcept;
    [[nodiscard]] FrameStatus demote(const FrameKey&)noexcept;
    [[nodiscard]] FrameStatus abandon(const FrameKey&)noexcept;
    [[nodiscard]] FrameStatus end(std::uint32_t)noexcept;
    [[nodiscard]] FrameStatus poll()noexcept;
    [[nodiscard]] FrameStatus close()noexcept;
    [[nodiscard]] FrameSnapshot snapshot()const noexcept;
private:
    class Guard;
    VideoFrames(std::shared_ptr<Context>,std::uint32_t);
    [[nodiscard]] bool valid(const FrameKey&)const noexcept;
    [[nodiscard]] FrameKey key(std::uint32_t)const noexcept;
    [[nodiscard]] bool open()const noexcept;
    [[nodiscard]] FrameResult advance()noexcept;
    [[nodiscard]] FrameResult get(bool admission)noexcept;
    [[nodiscard]] FrameStatus collect()noexcept;
    [[nodiscard]] FrameStatus unborrow(const FrameKey&)noexcept;
    struct Resource {std::shared_ptr<FrameSurface> surface;std::uint64_t serial{};bool pending{},reference{},borrowed{};};
    std::shared_ptr<Context> clock_;std::shared_ptr<const FrameIdentity> identity_;
    PicturePool pool_;std::array<Resource,16> resources_{};
    std::uint64_t next_serial_{};std::uint32_t end_{},references_{};int current_{-1};
    bool busy_{},closing_{},closed_{};
};
}
