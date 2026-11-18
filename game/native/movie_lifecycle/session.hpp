#pragma once
#include "../resources/byte_view.hpp"
#include <memory>
#include <cstdint>
namespace reo::native::movie_lifecycle {
enum class Status {completed,pending,closed,busy,invalid_key,invalid_input,provider_failure,capacity};
struct Identity;
class Key final {
public:Key()=default;
private:friend class Session;std::weak_ptr<const Identity> owner_;std::uint64_t generation_{};
};
struct Recipe {
    std::shared_ptr<const resources::ByteView> source;
    std::uint64_t offset{},bytes{};
};
// A graph owns its source/demux/decoder, clock, audio stream and video pool.
// Calls occur on their serialized native owner. No fake completion/timeout.
class Graph {
public:
    virtual ~Graph()=default;
    virtual Status service()noexcept=0;
    virtual void request_stop()noexcept=0;
    virtual Status poll_retired()noexcept=0;
    virtual void drain()noexcept=0;
};
struct Build {Status status{Status::provider_failure};std::shared_ptr<Graph> graph;};
class Factory {
public:
    virtual ~Factory()=default;
    // On failure return any partially created graph so retirement can finish.
    // A graph must hold native resources itself, never borrow its Factory.
    virtual Build construct(const Recipe&,std::uint64_t generation)noexcept=0;
};
struct Open {Status status{Status::invalid_input};Key key;};
struct Snapshot {std::uint64_t generation{};bool live{},closing{},retired{},rebuilding{},failed{},busy{};};
// Physical lifetime layer, separate from Policy's original numeric decisions.
// Close/rebuild rejects old keys immediately; replacement waits for real joins.
class Session final:public std::enable_shared_from_this<Session> {
public:
    static std::shared_ptr<Session> create(std::shared_ptr<Factory>);
    ~Session();
    Session(const Session&)=delete;Session& operator=(const Session&)=delete;
    [[nodiscard]] Open open(Recipe)noexcept;
    [[nodiscard]] Status service(const Key&)noexcept;
    [[nodiscard]] Status stop(const Key&)noexcept;
    [[nodiscard]] Status rebuild(const Key&)noexcept;
    // Polls current retirement/rebuild. A returned replacement key is new.
    [[nodiscard]] Open poll()noexcept;
    [[nodiscard]] Status close()noexcept;
    [[nodiscard]] Snapshot snapshot()const noexcept;
private:
    explicit Session(std::shared_ptr<Factory>);
    std::shared_ptr<Factory> factory_;std::shared_ptr<const Identity> identity_;
    std::shared_ptr<Graph> graph_;Recipe recipe_;
    std::uint64_t generation_{};bool busy_{},closing_{},retired_{true},rebuilding_{},failed_{},closed_{};
    bool valid(const Key&)const noexcept;
    Key key()const noexcept;
    Open construct()noexcept;
    Open retire()noexcept;
    void begin_stop()noexcept;
};
}
