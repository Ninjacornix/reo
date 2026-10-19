// SPDX-License-Identifier: GPL-3.0-only
#pragma once

#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <mutex>
#include <string>
#include <utility>
#include <vector>

// Private report source for the original 0x80000211 USBKB RPC service.
// No process-global keyboard state is read or modified.
class PrivateUsbKeyboard {
  public:
    explicit PrivateUsbKeyboard(std::string path) : path_(std::u8string(path.begin(), path.end())) {
        refresh();
    }

    std::vector<uint8_t> call(uint32_t op, const std::vector<uint8_t>& request, size_t replySize) {
        std::lock_guard lock(mutex_);
        std::vector<uint8_t> reply(std::min<size_t>(replySize, 0x1000));
        if (op == 1 || op == 2)
            refresh();
        const uint8_t slot = request.empty() ? 0xff : request[0];
        const uint8_t value = request.size() > 1 ? request[1] : 0;
        const bool valid = attached_ && slot == 0;
        const auto put = [&](size_t at, uint8_t byte) {
            if (at < reply.size())
                reply[at] = byte;
        };
        switch (op) {
            case 1:
                put(0, 1); // One supported virtual slot; attached count is separate.
                put(1, attached_ ? 1 : 0);
                put(2, attached_ ? 1 : 0);
                break;
            case 2:
                put(0, leds_);
                if (!valid) {
                    put(1, 0xff);
                } else if (cursor_ < reports_.size() && reply.size() >= 10) {
                    const auto& report = reports_[cursor_++];
                    updateLocks(report);
                    put(0, leds_);
                    put(1, 8);
                    std::copy(report.begin(), report.end(), reply.begin() + 2);
                    if (cursor_ == reports_.size())
                        acknowledge();
                }
                break;
            case 3:
                // A virtual queue has no physical seven-byte USB topology to report.
                // The original driver's failure representation is an all-zero route.
                break;
            case 4:
                put(0, slot);
                if (valid) {
                    leds_ = value;
                    put(1, leds_);
                } else {
                    put(1, uint8_t(~value));
                }
                break;
            case 5:
                put(0, slot);
                if (valid) {
                    lockMode_ = value;
                    put(1, lockMode_);
                } else {
                    put(1, uint8_t(~value));
                }
                break;
            case 6:
                put(0, slot);
                if (valid) {
                    cursor_ = reports_.size();
                    acknowledge();
                }
                break;
            default:
                warning("unsupported RPC operation");
                break;
        }
        return reply;
    }

  private:
    static constexpr uint32_t Magic = 0x52454f4b;
    static constexpr size_t MaxReports = 512;
    std::filesystem::path path_;
    std::mutex mutex_;
    std::vector<std::array<uint8_t, 8>> reports_;
    size_t cursor_ = 0;
    uint32_t sequence_ = 0;
    bool haveSequence_ = false;
    bool acknowledged_ = false;
    bool attached_ = false;
    uint8_t leds_ = 0;
    uint8_t lockMode_ = 1;
    uint8_t priorLocks_ = 0;
    unsigned warnings_ = 0;

    static uint32_t word(const uint8_t* bytes) {
        return uint32_t(bytes[0]) | uint32_t(bytes[1]) << 8 | uint32_t(bytes[2]) << 16 |
               uint32_t(bytes[3]) << 24;
    }
    void warning(const char* message) {
        if (warnings_++ < 16)
            std::fprintf(stderr, "[USB-KB] %s\n", message);
    }
    void acknowledge() {
        if (!haveSequence_ || acknowledged_ || cursor_ != reports_.size())
            return;
        auto ack = path_;
        ack += ".ack";
        auto temporary = ack;
        temporary += ".tmp";
        {
            std::ofstream output(temporary, std::ios::binary | std::ios::trunc);
            output << sequence_ << '\n';
            output.close();
            if (!output) {
                warning("cannot write report-consumption acknowledgement");
                return;
            }
        }
        std::error_code error;
        std::filesystem::remove(ack, error);
        error.clear();
        std::filesystem::rename(temporary, ack, error);
        if (error) {
            warning("cannot publish report-consumption acknowledgement");
            return;
        }
        acknowledged_ = true;
    }
    void refresh() {
        std::ifstream input(path_, std::ios::binary | std::ios::ate);
        const auto length = input ? input.tellg() : std::streampos(-1);
        if (length < std::streampos(12) || length > std::streampos(12 + MaxReports * 8)) {
            if (cursor_ == reports_.size())
                attached_ = false;
            return;
        }
        input.seekg(0);
        std::array<uint8_t, 12> header{};
        input.read(reinterpret_cast<char*>(header.data()), header.size());
        const uint32_t magic = word(header.data());
        const uint32_t sequence = word(header.data() + 4);
        const uint32_t count = word(header.data() + 8);
        if (!input || magic != Magic || count > MaxReports ||
            length != std::streampos(12 + size_t(count) * 8)) {
            if (cursor_ == reports_.size())
                attached_ = false;
            warning("invalid private report file; no new reports accepted");
            return;
        }
        if (haveSequence_ && sequence == sequence_) {
            attached_ = true;
            acknowledge();
            return;
        }
        if (haveSequence_ && sequence < sequence_) {
            warning("stale report sequence rejected");
            return;
        }
        if (cursor_ != reports_.size() || (haveSequence_ && !acknowledged_)) {
            warning("new sequence held until all preceding reports are consumed");
            acknowledge();
            return;
        }
        std::vector<std::array<uint8_t, 8>> incoming(count);
        if (count)
            input.read(reinterpret_cast<char*>(incoming.data()), std::streamsize(count * 8));
        if (!input) {
            warning("private report file changed during read; retrying later");
            return;
        }
        reports_ = std::move(incoming);
        cursor_ = 0;
        sequence_ = sequence;
        haveSequence_ = true;
        acknowledged_ = false;
        attached_ = true;
        acknowledge();
    }
    void updateLocks(const std::array<uint8_t, 8>& report) {
        uint8_t locks = 0;
        for (size_t i = 2; i < report.size(); ++i) {
            switch (report[i]) {
                case 0x53:
                    locks |= 1;
                    break;
                case 0x39:
                    if (lockMode_ == 1 || (lockMode_ == 2 && (report[0] & 0x22)))
                        locks |= 2;
                    break;
                case 0x47:
                    locks |= 4;
                    break;
                case 0xe3:
                    locks |= 8;
                    break;
                case 0x90:
                    locks |= 16;
                    break;
                default:
                    break;
            }
        }
        if (lockMode_ && priorLocks_ != locks) {
            priorLocks_ = locks;
            leds_ ^= locks;
        }
    }
};
