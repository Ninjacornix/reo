#pragma once
#include <cstdint>
#include <filesystem>
#include <memory>
#include <span>
#include <string>
#include <string_view>
#include <vector>

namespace reo::native::resources::win32 {class PinnedFile;}
namespace reo::native::movie_assets {
class Catalogue;
// Prepared modern asset, with an actual retained read-only file/hash lease.
// Hold this asset for the entire native player's source lifetime.
class Asset final {
public:
    [[nodiscard]] const std::string& key()const noexcept{return key_;}
    [[nodiscard]] const std::filesystem::path& path()const noexcept{return path_;}
    [[nodiscard]] std::uint32_t frames()const noexcept{return frames_;}
    [[nodiscard]] std::uint64_t bytes()const noexcept{return bytes_;}
private:
    friend class Catalogue;
    Asset(std::string,std::filesystem::path,std::uint32_t,std::uint64_t,std::shared_ptr<const resources::win32::PinnedFile>);
    std::string key_;std::filesystem::path path_;std::uint32_t frames_{};std::uint64_t bytes_{};
    std::shared_ptr<const resources::win32::PinnedFile> lease_;
};
struct Entry {
    std::string label;std::shared_ptr<const Asset> asset;
    // Import metadata used by the temporary game-cue adapter, never an I/O
    // address or permission to read the original archive during playback.
    std::uint32_t imported_member_index{};
};
// Preflight before gameplay: parse the prepared manifest, verify actual output
// files, and retain their leases. No archive access, decoder, process spawn,
// runtime transcoding, guest address or lazy game-thread hashing exists here.
class Catalogue final {
public:
    [[nodiscard]] static std::shared_ptr<const Catalogue> open(const std::filesystem::path&,bool require_complete=true);
    [[nodiscard]] std::span<const Entry> entries()const noexcept{return entries_;}
    [[nodiscard]] std::shared_ptr<const Asset> find(std::string_view key)const noexcept;
    // Labels support the temporary game-cue adapter. New game logic should use
    // the stable native resource key; these labels grant no arbitrary path I/O.
    [[nodiscard]] std::shared_ptr<const Asset> find_label(std::string_view)const noexcept;
private:
    Catalogue()=default;
    std::vector<Entry> entries_;
};
}
