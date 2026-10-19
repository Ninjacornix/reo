// SPDX-License-Identifier: GPL-3.0-only
#include "../../network/native/netcnf_profile.h"

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

using reo_network::NetcnfHostProfile;
using reo_network::NetcnfProfileService;

namespace {
unsigned checks = 0;
void check(bool value, const char* name) {
    ++checks;
    if (!value) {
        std::fprintf(stderr, "FAIL: %s\n", name);
        std::exit(1);
    }
}
void put(std::vector<uint8_t>& data, size_t offset, uint32_t value) {
    for (unsigned i = 0; i < 4; ++i)
        data.at(offset + i) = uint8_t(value >> (i * 8));
}
int32_t result(const std::vector<uint8_t>& data) {
    if (data.size() < 4)
        return -999;
    return int32_t(uint32_t(data[0]) | uint32_t(data[1]) << 8 | uint32_t(data[2]) << 16 |
                   uint32_t(data[3]) << 24);
}
void text(std::vector<uint8_t>& data, size_t offset, const std::string& value) {
    std::fill(data.begin() + offset, data.begin() + offset + 256, uint8_t(0));
    std::copy(value.begin(), value.end(), data.begin() + offset);
}
} // namespace

int main() {
    const NetcnfHostProfile profile{true,      "127.0.0.1", "255.0.0.0",
                                    "0.0.0.0", "0.0.0.0",   "0.0.0.0"};
    NetcnfProfileService service(profile);
    check(service.available(), "actual supplied loopback adapter");
    std::vector<uint8_t> request(0x1000, 0);
    text(request, 0x10, "mc0:SYS_NET/NETCNF");
    put(request, 0xc, 0x200);
    unsigned writes = 0;
    std::vector<uint8_t> bank(0x1800, 0x5a);
    const auto write = [&](uint32_t address, const uint8_t* bytes, size_t size) {
        ++writes;
        if (address > bank.size() || size > bank.size() - address)
            return false;
        std::copy_n(bytes, size, bank.begin() + address);
        return true;
    };
    check(result(service.call(0, request, 0x1000, write)) < 0,
          "profile unavailable before provider registration");
    check(result(service.call(101, request, 0x1000, write)) < 0,
          "workspace cannot precede provider registration");
    put(request, 8, 1);
    check(result(service.call(11, request, 0x1000, write)) == 0,
          "register real native profile provider");
    put(request, 8, 0);
    check(result(service.call(0, request, 0x1000, write)) < 0,
          "profile requires allocated parser workspace");
    put(request, 0, 0);
    check(result(service.call(101, request, 0x1000, write)) == -2,
          "zero workspace is an allocation failure");
    put(request, 0, 0x100001);
    check(result(service.call(101, request, 0x1000, write)) == -2,
          "oversized workspace fails bounded allocation");
    put(request, 0, 0x1000);
    check(result(service.call(101, request, 0x1000, write)) == 0,
          "allocate original requested 4096-byte workspace");
    check(result(service.call(0, request, 0x1000, write)) == 1, "profile count");
    check(writes == 0, "count never writes guest memory");
    put(request, 0, 10);
    check(result(service.call(1, request, 0x1000, write)) == 1,
          "bounded list returns actual count");
    check(writes == 1, "one list DMA write");
    check(bank[0x1ff] == 0x5a && bank[0x440] == 0x5a, "list DMA exact extent");
    check(std::string(reinterpret_cast<char*>(bank.data() + 0x208)) == "Native host network",
          "original display name field");
    const std::string identifier(reinterpret_cast<char*>(bank.data() + 0x308));
    text(request, 0x110, identifier);
    check(result(service.call(2, request, 0x1000, write)) == 0, "select listed identifier");
    check(writes == 2, "one selected detail DMA write");
    check(bank[0x1ff] == 0x5a && bank[0x1540] == 0x5a, "detail DMA exact extent");
    check(std::string(reinterpret_cast<char*>(bank.data() + 0x500)) == profile.address,
          "original address string field");
    check(std::string(reinterpret_cast<char*>(bank.data() + 0x600)) == profile.netmask,
          "original mask string field");
    check(bank[0x1520] == 0 && bank[0x1525] == 0, "host static address, no PPPoE");
    check(std::string(reinterpret_cast<char*>(bank.data() + 0x1000)) == "SCE" &&
              std::string(reinterpret_cast<char*>(bank.data() + 0x1100)) ==
                  "Ethernet (Network Adaptor)",
          "device tuple matches original available dev9 hardware registry");
    const std::string interfaceName(reinterpret_cast<char*>(bank.data() + 0x200));
    const std::string deviceName(reinterpret_cast<char*>(bank.data() + 0x300));
    const auto initial = bank;
    text(request, 0x110, "unknown-profile");
    check(result(service.call(2, request, 0x1000, write)) < 0 && bank == initial,
          "unknown identifier fails without write");
    for (const uint32_t operation : {3u, 4u, 5u, 103u, 0xffffffffu}) {
        check(result(service.call(operation, request, 0x1000, write)) < 0 && bank == initial,
              "unsupported mutation or authentication operation fails");
    }
    check(writes == 2, "refused operations make no DMA writes");
    for (const uint32_t category : {1u, 2u}) {
        put(request, 8, category);
        check(result(service.call(0, request, 0x1000, write)) == 1,
              "original scanner sees required interface and device categories");
        check(result(service.call(1, request, 0x1000, write)) == 1,
              "interface or device list succeeds");
        check(uint32_t(result(std::vector<uint8_t>(bank.begin() + 0x200, bank.begin() + 0x204))) ==
                  category,
              "list record keeps original category");
        check(std::string(reinterpret_cast<char*>(bank.data() + 0x208)) ==
                  (category == 1 ? interfaceName : deviceName),
              "combined attachment name joins listed category display name");
        const std::string categoryIdentifier(reinterpret_cast<char*>(bank.data() + 0x308));
        check(categoryIdentifier != identifier, "category identity is distinct");
        text(request, 0x110, identifier);
        check(result(service.call(2, request, 0x1000, write)) < 0,
              "combined identifier cannot select another category");
        text(request, 0x110, categoryIdentifier);
        check(result(service.call(2, request, 0x1000, write)) == 0,
              "listed interface or device detail succeeds");
    }
    put(request, 8, 3);
    check(result(service.call(0, request, 0x1000, write)) < 0, "unknown category fails");
    bank = initial;
    put(request, 8, 0);
    std::fill(request.begin() + 0x10, request.begin() + 0x110, uint8_t('x'));
    check(result(service.call(0, request, 0x1000, write)) < 0, "unterminated path fails");
    text(request, 0x10, "mc0:SYS_NET/NETCNF");
    put(request, 0xc, 0xffffffffu);
    check(result(service.call(1, request, 0x1000, write)) < 0 && bank == initial,
          "failed DMA destination cannot publish success");
    check(result(service.call(1, request, 0x1000, {})) < 0, "no memory writer fails");
    put(request, 0, 0);
    const auto beforeZero = writes;
    check(result(service.call(1, request, 0x1000, write)) < 0 && writes == beforeZero,
          "zero list allocation cannot receive record");
    check(service.call(0, request, 3, write).empty(), "short reply refused");
    check(service.call(0, request, 0x10001, write).empty(), "oversized reply refused");
    check(result(service.call(0, std::vector<uint8_t>(8), 16, write)) < 0, "short request refused");
    auto invalid = profile;
    invalid.available = false;
    check(!NetcnfProfileService(invalid).available(), "no implicit device availability");
    invalid = profile;
    invalid.address = "256.0.0.1";
    check(!NetcnfProfileService(invalid).available(), "invalid address refused");
    invalid = profile;
    invalid.address = "0.0.0.0";
    check(!NetcnfProfileService(invalid).available(), "unassigned address refused");
    invalid = profile;
    invalid.netmask = "255.0.255.0";
    check(!NetcnfProfileService(invalid).available(), "noncontiguous mask refused");
    invalid = profile;
    invalid.dns1 = "1.2.3.4 suffix";
    check(!NetcnfProfileService(invalid).available(), "malformed DNS refused");
    check(result(NetcnfProfileService(invalid).call(0, request, 16, write)) < 0,
          "unavailable host never advertises profile");
    check(result(service.call(102, request, 16, write)) == 0, "free native workspace");
    check(result(service.call(0, request, 16, write)) < 0, "free invalidates profile query work");
    put(request, 0, 4096);
    check(result(service.call(101, request, 16, write)) == 0, "reallocate workspace");
    check(result(service.call(15, request, 16, write)) == 0, "unregister provider");
    check(result(service.call(0, request, 16, write)) < 0,
          "unregistered provider cannot advertise profile");
    std::printf("PASS checks=%u\n", checks);
}
