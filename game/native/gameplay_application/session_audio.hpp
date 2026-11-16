#pragma once
#include "../gameplay_audio/owner.hpp"
#include "../afs_source_range/afs_source_range.hpp"
#include "../resource_io/async_read_owner.hpp"
#include <memory>
#include <string_view>

namespace reo::native::adxt_output_session { class Session; }
namespace reo::native::audio_mix_tail { class Mixer; }
namespace reo::native::gameplay_world { class World; }
namespace reo::native::gameplay_application {
enum class SessionAudioLoadStatus {completed,busy,closed,not_found,source_failure,bank_failure,capacity};
struct SessionAudioLoadResult {SessionAudioLoadStatus status{SessionAudioLoadStatus::source_failure};gameplay_audio::BankResult bank;std::optional<unsigned> member;};
// One serialized gameplay sound control owner. World outlives it; close
// retires source reads before the retained output may be joined by its host.
// The audio owner is borrowed by clients and must not outlive this owner.
class SessionAudio final {
public:
    SessionAudio(gameplay_world::World&,std::shared_ptr<audio_mix_tail::Mixer>,
                 std::shared_ptr<adxt_output_session::Session>,std::shared_ptr<const afs_source_range::Archive>);
    ~SessionAudio();
    SessionAudio(const SessionAudio&)=delete;
    SessionAudio& operator=(const SessionAudio&)=delete;
    [[nodiscard]] bool bound_to(const gameplay_world::World&)const noexcept;
    [[nodiscard]] bool busy()const noexcept{return running_;}
    [[nodiscard]] gameplay_audio::Owner* owner()noexcept{return owner_.get();}
    // Direct common bank path reads the real member before installing port 0.
    // A retry rereads and reinstalls it; it is not the queued Loader's cache.
    [[nodiscard]] SessionAudioLoadResult load_common()noexcept;
    // Complete1D3DC0 direct named-bank path. Lookup is authoritative over the
    // same422-member alias catalogue; a missing name leaves its port intact.
    [[nodiscard]] SessionAudioLoadResult load_named(std::string_view,unsigned port)noexcept;
    [[nodiscard]] bool close()noexcept;
private:
    gameplay_world::World* world_;
    std::shared_ptr<audio_mix_tail::Mixer> mixer_;
    std::shared_ptr<adxt_output_session::Session> output_;
    std::shared_ptr<gameplay_audio::Owner> owner_;
    std::shared_ptr<const afs_source_range::Archive> archive_;
    std::unique_ptr<resource_io::AsyncReadOwner> reads_;
    bool running_{},closed_{};
};
}
