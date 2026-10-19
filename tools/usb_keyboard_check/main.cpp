// SPDX-License-Identifier: GPL-3.0-only
#include "../../network/native/private_usb_keyboard.h"

#include <chrono>
#include <stdexcept>

namespace {
unsigned checks = 0;
void require(bool value, const char* message) {
    ++checks;
    if (!value)
        throw std::runtime_error(message);
}
void word(std::ofstream& output, uint32_t value) {
    const std::array<char, 4> bytes{char(value), char(value >> 8), char(value >> 16),
                                    char(value >> 24)};
    output.write(bytes.data(), bytes.size());
}
using Report = std::array<uint8_t, 8>;
void publish(const std::filesystem::path& path, uint32_t sequence,
             const std::vector<Report>& reports) {
    std::ofstream output(path, std::ios::binary | std::ios::trunc);
    word(output, 0x52454f4b);
    word(output, sequence);
    word(output, uint32_t(reports.size()));
    for (const auto& report : reports)
        output.write(reinterpret_cast<const char*>(report.data()), report.size());
}
int acknowledgement(const std::filesystem::path& path) {
    auto ack = path;
    ack += ".ack";
    std::ifstream input(ack);
    int sequence = -1;
    input >> sequence;
    return sequence;
}
} // namespace

int main() {
    const auto directory =
        std::filesystem::temp_directory_path() /
        ("reo-usb-keyboard-check-" +
         std::to_string(std::chrono::steady_clock::now().time_since_epoch().count()));
    try {
        std::filesystem::create_directory(directory);
        const auto input = directory / "player1.bin";
        PrivateUsbKeyboard absent(input.string());
        require(absent.call(1, {}, 0x90)[1] == 0,
                "missing private file is not an attached keyboard");
        require(absent.call(2, {0}, 0x50)[1] == 0xff, "unattached slot returns failure");
        publish(input, 0, {});
        PrivateUsbKeyboard keyboard(input.string());
        const auto enumeration = keyboard.call(1, {}, 0x90);
        require(enumeration.size() == 0x90 && enumeration[0] == 1 && enumeration[1] == 1 &&
                    enumeration[2] == 1,
                "one valid private keyboard is enumerated");
        require(acknowledgement(input) == 0, "empty initial sequence acknowledged");
        require(keyboard.call(2, {0}, 0x50)[1] == 0, "empty queue has zero report length");
        require(keyboard.call(2, {1}, 0x50)[1] == 0xff, "only slot zero attached");
        require(keyboard.call(4, {0, 5}, 16)[1] == 5, "explicit LED state");
        const Report down{2, 0, 4, 0, 0, 0, 0, 0};
        const Report release{};
        publish(input, 1, {down, release});
        require(keyboard.call(2, {0}, 9)[1] == 0,
                "short reply cannot consume a partial HID report");
        auto report = keyboard.call(2, {0}, 0x50);
        require(report[1] == 8 && std::equal(down.begin(), down.end(), report.begin() + 2),
                "raw HID down report preserved");
        require(acknowledgement(input) == 0, "batch not acknowledged after only one report");
        publish(input, 2, {Report{0, 0, 5, 0, 0, 0, 0, 0}});
        report = keyboard.call(2, {0}, 0x50);
        require(report[1] == 8 && std::equal(release.begin(), release.end(), report.begin() + 2),
                "new sequence cannot replace unconsumed release");
        require(acknowledgement(input) == 1, "first sequence acknowledged after release");
        report = keyboard.call(2, {0}, 0x50);
        require(report[1] == 8 && report[4] == 5 && acknowledgement(input) == 2,
                "held next sequence delivered exactly once");
        require(keyboard.call(2, {0}, 0x50)[1] == 0, "same sequence never replayed");
        publish(input, 1, {down});
        require(keyboard.call(2, {0}, 0x50)[1] == 0, "stale sequence rejected");
        publish(input, 3, {down, release});
        keyboard.call(1, {}, 0x90);
        keyboard.call(6, {0}, 16);
        require(acknowledgement(input) == 3 && keyboard.call(2, {0}, 0x50)[1] == 0,
                "original clear-buffer command clears and acknowledges queue");
        const auto secondInput = directory / "player2.bin";
        publish(secondInput, 0, {});
        PrivateUsbKeyboard second(secondInput.string());
        publish(input, 4, {down});
        require(second.call(2, {0}, 0x50)[1] == 0, "second process source isolated");
        require(keyboard.call(2, {0}, 0x50)[1] == 8, "first source still receives its own input");
        publish(input, 5, {Report{0, 0, 0x39, 0, 0, 0, 0, 0}, release});
        keyboard.call(4, {0, 0}, 16);
        keyboard.call(5, {0, 1}, 16);
        require(keyboard.call(2, {0}, 0x50)[0] == 2, "original automatic Caps Lock LED mode");
        keyboard.call(2, {0}, 0x50);
        publish(input, 6, std::vector<Report>(513));
        require(keyboard.call(1, {}, 0x90)[1] == 0, "oversized input rejected and detached");
        require(keyboard.call(2, {0}, 0x50)[1] == 0xff, "malformed source cannot supply reports");
        publish(input, 7, {});
        require(keyboard.call(1, {}, 0x90)[1] == 1 && acknowledgement(input) == 7,
                "valid source recovers without process-global state");
        require(keyboard.call(3, {0}, 16) == std::vector<uint8_t>(16),
                "virtual keyboard does not invent a physical USB location");
        require(keyboard.call(2, {}, 0x50)[1] == 0xff, "truncated request rejected");
        const Report shiftOnly{2, 0, 0, 0, 0, 0, 0, 0};
        const Report shiftedC{2, 0, 6, 0, 0, 0, 0, 0};
        publish(input, 8, {shiftOnly, shiftedC, shiftOnly, release});
        report = keyboard.call(2, {0}, 0x50);
        require(report[1] == 8 &&
                    std::equal(shiftOnly.begin(), shiftOnly.end(), report.begin() + 2),
                "modifier-only edge reaches original EE libusbkb before a shifted key");
        require(acknowledgement(input) == 7,
                "modifier-only prelude does not acknowledge the remaining key");
        report = keyboard.call(2, {0}, 0x50);
        require(std::equal(shiftedC.begin(), shiftedC.end(), report.begin() + 2),
                "shifted key follows its already established modifier");
        report = keyboard.call(2, {0}, 0x50);
        require(std::equal(shiftOnly.begin(), shiftOnly.end(), report.begin() + 2),
                "key release retains Shift until its separate release");
        require(acknowledgement(input) == 7,
                "key release does not acknowledge pending modifier release");
        report = keyboard.call(2, {0}, 0x50);
        require(std::equal(release.begin(), release.end(), report.begin() + 2) &&
                    acknowledgement(input) == 8,
                "Shift release is preserved and finishes the four-report sequence");
        std::printf("PASS checks=%u private_sources=2 global_keyboard=0\n", checks);
        return 0;
    } catch (const std::exception& error) {
        std::fprintf(stderr, "FAIL checks=%u: %s\n", checks, error.what());
        return 1;
    }
}
