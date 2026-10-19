#pragma once

#include <string>

#define REO_VERSION_MAJOR 0
#define REO_VERSION_MINOR 3
#define REO_VERSION_PATCH 0
#define REO_VERSION_STRING "0.3.0"

namespace reo {

// Which game to run
enum class GameTitle {
    Outbreak, // RE Outbreak File #1 (SLUS-20765)
    File2,    // RE Outbreak File #2 (SLUS-20984)
};

struct GameInfo {
    GameTitle title;
    const char* display_name;
    const char* elf_name; // e.g. "SLUS_207.65" or "SLUS_209.84"
    const char* serial;   // e.g. "SLUS-20765"
    uint32_t entry_point;
    const char* default_data_path;
};

// Lookup tables for supported games
const GameInfo& get_game_info(GameTitle title);

struct Config {
    // Game selection
    GameTitle game = GameTitle::Outbreak;

    // Paths (auto-set from game selection if not overridden)
    std::string game_data_path; // empty = use default for selected game
    std::string save_path = "saves";

    // Display
    int window_width = 1280;
    int window_height = 720;
    bool fullscreen = false;
    bool vsync = true;
    int fps_target = 60; // Original was 30, we aim for 60

    // Audio
    int audio_sample_rate = 48000;
    float master_volume = 1.0f;

    // Network
    bool online_enabled = false;
    std::string server_address = "obsrv.org";
    int server_port = 8200;
    std::string player_name = "Survivor";

    // Input
    bool prefer_controller = true;

    bool load(int argc, char* argv[]);
    bool save() const;

    // Resolved game info (set after load())
    const GameInfo& game_info() const {
        return get_game_info(game);
    }
};

} // namespace reo
