// SPDX-License-Identifier: GPL-3.0-only
#pragma once
#include <atomic>
#include <array>
#include <span>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <string>

namespace reo_network::automatic_account {
inline std::atomic<bool> armed{false};
inline std::atomic<bool> completed{false};
inline std::atomic<unsigned> generation{0};
// Set only by a verified original password-poll call site. File #2's one-frame
// initialization can finish between host pad polls, unlike File #1's eight frames.
inline std::atomic<unsigned> editorReadyGeneration{0};
inline bool enabled() {
    const char* option = std::getenv("REO_COOP_AUTO_ACCOUNT");
    const char* path = std::getenv("REO_COOP_ACCOUNT_STATUS");
    return option && std::strcmp(option, "1") == 0 && path && *path;
}
inline void arm() {
    if (enabled() && (!armed.load() || completed.exchange(false))) {
        editorReadyGeneration.store(0);
        unsigned attempt = generation.fetch_add(1) + 1;
        armed.store(true);
        std::fprintf(stderr, "\n[COOP-AUTO] account-request %u\n", attempt);
    }
}
inline std::string status() {
    const char* path = std::getenv("REO_COOP_ACCOUNT_STATUS");
    if (!path || !*path)
        return {};
    std::ifstream input(std::filesystem::path(std::u8string(path, path + std::strlen(path))));
    std::string value;
    std::getline(input, value);
    return value;
}
inline bool accountReady() {
    const auto value = status();
    const auto suffix = " " + std::to_string(generation.load());
    return value == "ready" + suffix || value == "typed" + suffix;
}
inline bool decodeCredential(std::span<const uint8_t> bytes, unsigned attempt,
                             std::array<char, 16>& result) {
    if (bytes.size() != 28 || !attempt) return false;
    const auto word = [&](unsigned i) {
        return uint32_t(bytes[i]) | uint32_t(bytes[i+1]) << 8 |
            uint32_t(bytes[i+2]) << 16 | uint32_t(bytes[i+3]) << 24;
    };
    if (word(0) != 0x52454F41 || word(4) != attempt || word(8) != 15 || bytes[27] != 0) return false;
    for (unsigned i = 12; i < 27; ++i)
        if (!((bytes[i] >= 'a' && bytes[i] <= 'z') || (bytes[i] >= 'A' && bytes[i] <= 'Z') ||
            (bytes[i] >= '0' && bytes[i] <= '9'))) return false;
    for (unsigned i = 0; i < 16; ++i) result[i] = char(bytes[12+i]);
    return true;
}
inline std::filesystem::path inputPath(const char* suffix) {
    const char* name = std::getenv("REO_COOP_ACCOUNT_STATUS");
    if (!name || !*name) return {};
    auto path = std::filesystem::path(std::u8string(name, name + std::strlen(name)));
    path += suffix;
    return path;
}
inline bool credential(std::array<char, 16>& result) {
    const unsigned attempt = generation.load();
    if (status() != "input " + std::to_string(attempt)) return false;
    std::array<uint8_t, 29> bytes{};
    std::ifstream input(inputPath(".credential"), std::ios::binary);
    input.read(reinterpret_cast<char*>(bytes.data()), bytes.size());
    bool valid = decodeCredential(std::span(bytes.data(), size_t(input.gcount())), attempt, result);
    volatile uint8_t* clear = bytes.data();
    for (size_t i = 0; i < bytes.size(); ++i) clear[i] = 0;
    return valid;
}
inline void inputApplied() {
    std::error_code error;
    std::filesystem::remove(inputPath(".credential"), error);
    {
        std::ofstream output(inputPath(".applied.tmp"), std::ios::trunc);
        output << generation.load() << '\n';
        if (!output) return;
    }
    std::filesystem::remove(inputPath(".applied"), error);
    error.clear();
    std::filesystem::rename(inputPath(".applied.tmp"), inputPath(".applied"), error);
}

enum class Button { None, Confirm, Up, Down };
struct Menu {
    bool gameFile2 = false;
    unsigned step = 0, substep = 0;
    int cursor = 0, delay = 0;
    int upperDelay = 0;
    unsigned choice = 0, profileStage = 0, profileCursor = 0;
    unsigned cardStage = 0, cardDialog = 0, cardKind = 0, cardMessage = 0;
    int cardDelay = 0;
    bool profileReady = false;
    bool keyboardValid = false, keyboardActive = false, keyboardDone = false;
    bool originalEditorReady = false;
    unsigned keyboardDelay = 0;
    bool passwordPresent = false;
};
struct Decision {
    Button button = Button::None;
    bool requestPassword = false, submitted = false;
};

// Only steers the original account/password UI. No server result or menu state is written.
class Flow {
    bool editorChosen_ = false, keyboardStarted_ = false, passwordRequested_ = false;
    bool finished_ = false;
    double releaseAt_ = 0, pressAt_ = 0, start_ = -1;
    unsigned attempts_ = 0;
    Button button_ = Button::None;

  public:
    Decision tick(const Menu& menu, double now, bool ready, bool typed) {
        if (finished_)
            return now < pressAt_ ? Decision{button_} : Decision{};
        if (!ready)
            return {};
        if (start_ < 0)
            start_ = now;
        if (now - start_ > 180 || attempts_ > 40) {
            finished_ = true;
            return {};
        }
        if (now < pressAt_)
            return {button_};
        if (now < releaseAt_)
            return {};
        button_ = Button::None;
        // File #2's 6162D0 adds a separate fade/debounce stage before the
        // warning accepts input (6163BC); File #1 accepts it in substep 1.
        if (menu.step == 1 && menu.substep == (menu.gameFile2 ? 2u : 1u) && menu.upperDelay <= 0) {
            button_ = Button::Confirm;
        } else if (menu.gameFile2 && menu.step == 2 && menu.substep == 1 &&
                   menu.cardStage == 1 && menu.cardDialog == 20 && menu.cardKind == 2) {
            // 617120's missing NET-save prompt: YES creates via 617A2C/14C690.
            // Other card dialogs (including overwrite/format errors) are not accepted.
            button_ = menu.choice ? Button::Up : Button::Confirm;
        } else if (menu.gameFile2 && menu.step == 2 && menu.substep == 1 &&
                   menu.cardStage == 1 && menu.cardDialog == 91 && menu.cardKind == 0 &&
                   menu.cardMessage == 7 && menu.cardDelay == 0) {
            // 617C58: successful-save informational page accepts any face button.
            button_ = Button::Confirm;
        } else if (!menu.gameFile2 && menu.step == 2 && (menu.substep == 4 || menu.substep == 21) && menu.upperDelay <= 0) {
            button_ = menu.choice ? Button::Up : Button::Confirm;
        } else if ((menu.step == 3 || menu.step == 4) && menu.substep == 2 && menu.delay == 0) {
            button_ = menu.cursor == 0 ? Button::Confirm : Button::Up;
        } else if (menu.step == 6 && menu.profileReady && menu.profileStage == 1) {
            button_ = menu.profileCursor == 2 ? Button::Confirm : Button::Down;
        } else if (menu.step == (menu.gameFile2 ? 46u : 44u) && menu.substep == 1 && menu.delay == 0 && !editorChosen_) {
            button_ = menu.cursor == 1 ? Button::Confirm : Button::Down;
            if (menu.cursor == 1)
                editorChosen_ = true;
        } else if (editorChosen_ && menu.step == (menu.gameFile2 ? 47u : 49u) && menu.substep == 1) {
            button_ = Button::Confirm;
        } else if (editorChosen_ && menu.step == (menu.gameFile2 ? 49u : 46u)) {
            if (menu.substep == 11) {
                if (menu.keyboardValid && menu.keyboardActive && menu.keyboardDelay > 0)
                    keyboardStarted_ = true;
                if ((keyboardStarted_ || menu.originalEditorReady) && !passwordRequested_ && menu.keyboardValid &&
                    menu.keyboardActive && !menu.keyboardDone && menu.keyboardDelay == 0) {
                    passwordRequested_ = true;
                    return {Button::None, true};
                }
            } else if (menu.substep == 1 && menu.delay == 0) {
                if (passwordRequested_ && typed && menu.passwordPresent) {
                    button_ = menu.cursor == 0 ? Button::Confirm : Button::Up;
                    if (menu.cursor == 0) {
                        finished_ = true;
                        pressAt_ = now + .12;
                        return {button_, false, true};
                    }
                } else if (!passwordRequested_) {
                    button_ = menu.cursor == 1 ? Button::Confirm : Button::Down;
                }
            }
        }
        if (button_ == Button::None)
            return {};
        attempts_++;
        pressAt_ = now + .08;
        releaseAt_ = now + .40;
        return {button_};
    }
};
} // namespace reo_network::automatic_account
