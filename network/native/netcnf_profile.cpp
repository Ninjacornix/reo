// SPDX-License-Identifier: GPL-3.0-only
#include "netcnf_profile.h"

#include <algorithm>
#include <new>
#include <utility>

namespace reo_network {
namespace {
constexpr size_t RecordSize = 0x240;
constexpr size_t DetailSize = 0x1340;
constexpr size_t MaxReply = 0x10000;
constexpr size_t MaxWorkspace = 1024 * 1024;
constexpr char Identifier[] = "reo-native-host";
constexpr char DisplayName[] = "Native host network";
constexpr const char* Identifiers[] = {Identifier, "reo-native-ifc", "reo-native-dev"};
constexpr const char* DisplayNames[] = {DisplayName, "Native host interface", "Native host device"};

uint32_t word(const std::vector<uint8_t>& data, size_t offset) {
    if (offset > data.size() || data.size() - offset < 4)
        return 0;
    return uint32_t(data[offset]) | uint32_t(data[offset + 1]) << 8 |
           uint32_t(data[offset + 2]) << 16 | uint32_t(data[offset + 3]) << 24;
}

void put(std::vector<uint8_t>& data, size_t offset, uint32_t value) {
    if (offset > data.size() || data.size() - offset < 4)
        return;
    for (size_t i = 0; i < 4; ++i)
        data[offset + i] = uint8_t(value >> (i * 8));
}

bool text(const std::vector<uint8_t>& data, size_t offset, std::string& value) {
    if (offset > data.size() || data.size() - offset < 0x100)
        return false;
    const auto begin = data.begin() + offset;
    const auto end = std::find(begin, begin + 0x100, uint8_t(0));
    if (end == begin + 0x100)
        return false;
    value.assign(begin, end);
    return true;
}

void string(std::vector<uint8_t>& data, size_t offset, const std::string& value) {
    if (offset > data.size() || data.size() - offset < 0x100 || value.size() >= 0x100)
        return;
    std::copy(value.begin(), value.end(), data.begin() + offset);
}

bool ipv4(const std::string& value, bool requireNonzero) {
    size_t offset = 0;
    bool nonzero = false;
    for (unsigned part = 0; part < 4; ++part) {
        unsigned number = 0;
        size_t digits = 0;
        while (offset < value.size() && value[offset] >= '0' && value[offset] <= '9') {
            number = number * 10 + unsigned(value[offset++] - '0');
            if (++digits > 3 || number > 255)
                return false;
        }
        if (!digits)
            return false;
        nonzero = nonzero || number != 0;
        if (part != 3 && (offset == value.size() || value[offset++] != '.'))
            return false;
    }
    return offset == value.size() && (!requireNonzero || nonzero);
}

bool validMask(const std::string& value) {
    if (!ipv4(value, true))
        return false;
    uint32_t bits = 0;
    unsigned octet = 0;
    for (const char ch : value) {
        if (ch == '.') {
            bits = (bits << 8) | octet;
            octet = 0;
        } else {
            octet = octet * 10 + unsigned(ch - '0');
        }
    }
    bits = (bits << 8) | octet;
    const uint32_t inverse = ~bits;
    return (inverse & (inverse + 1)) == 0;
}

std::vector<uint8_t> detail(const NetcnfHostProfile& profile) {
    std::vector<uint8_t> data(DetailSize, 0);
    // Flat NETCNFIF environment, corroborated by its IOP formatter and EE parser.
    for (size_t offset = 0x1300; offset <= 0x1318; offset += 4)
        put(data, offset, 0xffffffffu);
    for (size_t offset = 0x1320; offset <= 0x1328; ++offset)
        data[offset] = 0xff;
    string(data, 0, DisplayNames[1]);
    string(data, 0x100, DisplayNames[2]);
    string(data, 0x300, profile.address);
    string(data, 0x400, profile.netmask);
    string(data, 0x500, profile.gateway);
    string(data, 0x600, profile.dns1);
    string(data, 0x700, profile.dns2);
    // The guest's dev9 registry identifies this implemented compatibility device
    // by this tuple (5E4C50/5E5690), independently of host adapter branding.
    string(data, 0xe00, "SCE");
    string(data, 0xf00, "Ethernet (Network Adaptor)");
    put(data, 0x1300, 3); // Original Ethernet profile writer 0x5E47D4.
    put(data, 0x1304, 1500);
    put(data, 0x1308, 0);
    put(data, 0x130c, 3); // Original Ethernet device writer 0x5E4B20.
    put(data, 0x1310, 1);
    data[0x1320] = 0; // Host stack already owns the supplied IPv4 configuration.
    data[0x1321] = 0;
    data[0x1322] = 0;
    data[0x1323] = 0;
    data[0x1324] = 0;
    data[0x1325] = 0;
    return data;
}
} // namespace

NetcnfProfileService::NetcnfProfileService(NetcnfHostProfile profile)
    : profile_(std::move(profile)) {
    profile_.available = profile_.available && ipv4(profile_.address, true) &&
                         validMask(profile_.netmask) && ipv4(profile_.gateway, false) &&
                         ipv4(profile_.dns1, false) && ipv4(profile_.dns2, false);
}

bool NetcnfProfileService::available() const {
    return profile_.available;
}

std::vector<uint8_t> NetcnfProfileService::call(uint32_t operation,
                                                const std::vector<uint8_t>& request,
                                                size_t replySize, const GuestWrite& write) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (replySize < 4 || replySize > MaxReply)
        return {};
    std::vector<uint8_t> reply(replySize, 0);
    std::copy_n(request.begin(), std::min(request.size(), reply.size()), reply.begin());
    put(reply, 0, 0xffffffffu);
    if (!available())
        return reply;

    // NETCNFIF dispatch 0x80C registers provider callbacks before parser allocation.
    if (operation == 11) {
        if (request.size() >= 12 && word(request, 8) == 1) {
            registered_ = true;
            put(reply, 0, 0);
        }
        return reply;
    }
    if (operation == 15) {
        registered_ = false;
        put(reply, 0, 0);
        return reply;
    }
    // Operations 101/102 allocate/free the IOP parser workspace (0x85C/0x8C4).
    if (operation == 102) {
        std::vector<uint8_t>().swap(workspace_);
        put(reply, 0, 0);
        return reply;
    }
    if (!registered_)
        return reply;
    if (operation == 101) {
        if (request.size() < 4)
            return reply;
        if (!workspace_.empty()) {
            put(reply, 0, 0);
            return reply;
        }
        const size_t size = word(request, 0);
        if (!size || size > MaxWorkspace) {
            put(reply, 0, 0xfffffffeu);
            return reply;
        }
        try {
            workspace_.resize(size, 0);
            put(reply, 0, 0);
        } catch (const std::bad_alloc&) {
            put(reply, 0, 0xfffffffeu);
        }
        return reply;
    }
    if (workspace_.empty() || request.size() < 0x110)
        return reply;

    std::string path;
    if (!text(request, 0x10, path))
        return reply;
    const uint32_t category = word(request, 8);
    if (category > 2)
        return reply;
    if (operation == 0) {
        // The original selector requires all three record categories before it
        // classifies the combined profile against the available hardware.
        put(reply, 0, 1);
        return reply;
    }
    if (operation == 1) {
        if (int32_t(word(request, 0)) <= 0)
            return reply;
        std::vector<uint8_t> record(RecordSize, 0);
        put(record, 0, category);
        put(record, 4, 1);
        string(record, 8, DisplayNames[category]);
        string(record, 0x108, Identifiers[category]);
        if (write && write(word(request, 0xc), record.data(), record.size()))
            put(reply, 0, 1);
        return reply;
    }
    if (operation == 2) {
        std::string identifier;
        if (!text(request, 0x110, identifier) || identifier != Identifiers[category])
            return reply;
        const auto data = detail(profile_);
        if (write && write(word(request, 0xc), data.data(), data.size()))
            put(reply, 0, 0);
    }
    return reply;
}

} // namespace reo_network
