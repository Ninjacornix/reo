// SPDX-License-Identifier: GPL-3.0-only
#include "snap_iop_transport.h"

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <winsock2.h>
#include <ws2tcpip.h>

#include <algorithm>
#include <array>
#include <chrono>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <map>
#include <mutex>
#include <string>

#pragma comment(lib, "ws2_32.lib")

namespace {
constexpr size_t Header = 0x1c;
constexpr size_t MaxReply = 256 * 1024;
constexpr size_t MaxQueued = 1024 * 1024;
constexpr int32_t Failure = -1;
constexpr int32_t Again = -16;

uint16_t u16(const std::vector<uint8_t>& data, size_t at) {
    return at + 2 <= data.size() ? uint16_t(data[at] | uint16_t(data[at + 1]) << 8) : 0;
}
uint32_t u32(const std::vector<uint8_t>& data, size_t at) {
    return at + 4 <= data.size() ? uint32_t(u16(data, at)) | uint32_t(u16(data, at + 2)) << 16 : 0;
}
void put16(std::vector<uint8_t>& data, size_t at, uint16_t value) {
    if (at + 2 <= data.size()) {
        data[at] = uint8_t(value);
        data[at + 1] = uint8_t(value >> 8);
    }
}
void put32(std::vector<uint8_t>& data, size_t at, uint32_t value) {
    put16(data, at, uint16_t(value));
    put16(data, at + 2, uint16_t(value >> 16));
}
std::string env(const char* name) {
    char* value = nullptr;
    size_t size = 0;
    if (_dupenv_s(&value, &size, name) != 0 || !value)
        return {};
    std::string result(value);
    std::free(value);
    return result;
}
bool pending(int code) {
    return code == WSAEWOULDBLOCK || code == WSAEINPROGRESS || code == WSAEALREADY;
}
std::string hex(const uint8_t* data, size_t size) {
    constexpr char digits[] = "0123456789abcdef";
    std::string result;
    result.reserve(size * 2);
    for (size_t i = 0; i < size; ++i) {
        result += digits[data[i] >> 4];
        result += digits[data[i] & 15];
    }
    return result;
}
} // namespace

struct SnapIopTransport::Impl {
    struct Socket {
        SOCKET native = INVALID_SOCKET;
        bool udp = false;
        bool connecting = false;
        bool closed = false;
        bool failed = false;
        std::vector<uint8_t> outgoing;
    };
    struct Query {
        uint32_t address = 0;
        bool ok = false;
    };
    std::mutex mutex;
    std::map<uint16_t, Socket> sockets;
    std::map<uint16_t, Query> queries;
    std::string resolverHostname;
    std::array<uint32_t, 2> resolverAddresses{};
    uint16_t nextQuery = 1;
    bool ready = false;
    uint32_t target = 0;
    uint32_t localAddress = 0;
    bool linkStarted = false;
    bool configChanged = true;
    bool diagnostics = false;
    uint64_t calls = 0;
    std::ofstream trace;

    Impl() {
        WSADATA data{};
        ready = WSAStartup(MAKEWORD(2, 2), &data) == 0;
        const auto host = env("REO_COOP_HOST");
        IN_ADDR address{};
        // Explicit IPv4 configuration prevents accidental public DNS/service traffic.
        if (ready && !host.empty() && InetPtonA(AF_INET, host.c_str(), &address) == 1)
            target = address.s_addr;
        if (target) {
            const SOCKET probe = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
            if (probe != INVALID_SOCKET) {
                sockaddr_in route{};
                route.sin_family = AF_INET;
                route.sin_addr.s_addr = target;
                route.sin_port = htons(9091);
                if (connect(probe, reinterpret_cast<sockaddr*>(&route), sizeof(route)) == 0) {
                    int length = sizeof(route);
                    if (getsockname(probe, reinterpret_cast<sockaddr*>(&route), &length) == 0)
                        localAddress = route.sin_addr.s_addr;
                }
                closesocket(probe);
            }
        }
        diagnostics = !env("REO_NET_TRACE").empty() && env("REO_NET_TRACE") != "0";
        const auto path = env("REO_COOP_TRACE_FILE");
        if (!path.empty())
            trace.open(path, std::ios::app | std::ios::binary);
    }
    ~Impl() {
        clear();
        if (ready)
            WSACleanup();
    }
    void clear() {
        for (auto& [id, entry] : sockets) {
            (void)id;
            if (entry.native != INVALID_SOCKET)
                closesocket(entry.native);
        }
        sockets.clear();
        queries.clear();
        resolverHostname.clear();
        resolverAddresses = {};
        nextQuery = 1;
        linkStarted = false;
        configChanged = true;
    }
    void log(const char* direction, const char* protocol, uint16_t id, const uint8_t* data,
             size_t length, const sockaddr_in* peer = nullptr) {
        if (!trace)
            return;
        const auto stamp = std::chrono::duration_cast<std::chrono::microseconds>(
                               std::chrono::steady_clock::now().time_since_epoch())
                               .count();
        trace << "{\"t_us\":" << stamp << ",\"direction\":\"" << direction << "\",\"transport\":\""
              << protocol << "\",\"socket\":" << id;
        if (peer) {
            char ip[INET_ADDRSTRLEN]{};
            InetNtopA(AF_INET, &peer->sin_addr, ip, sizeof(ip));
            trace << ",\"peer\":\"" << ip << "\",\"port\":" << ntohs(peer->sin_port);
        }
        trace << ",\"bytes\":" << length << ",\"hex\":\"" << hex(data, length) << "\"}\n";
        trace.flush();
    }
    Socket* get(uint16_t id, bool udp) {
        auto it = sockets.find(id);
        return it != sockets.end() && it->second.udp == udp ? &it->second : nullptr;
    }
    void service(uint16_t id, Socket& entry) {
        if (entry.native == INVALID_SOCKET || entry.failed || entry.closed)
            return;
        if (entry.connecting) {
            fd_set writable, errors;
            FD_ZERO(&writable);
            FD_ZERO(&errors);
            FD_SET(entry.native, &writable);
            FD_SET(entry.native, &errors);
            timeval zero{};
            if (select(0, nullptr, &writable, &errors, &zero) > 0) {
                int error = 0;
                int size = sizeof(error);
                if (getsockopt(entry.native, SOL_SOCKET, SO_ERROR, reinterpret_cast<char*>(&error),
                               &size) != 0 ||
                    error != 0)
                    entry.failed = true;
                entry.connecting = false;
            }
        }
        if (entry.connecting || entry.failed)
            return;
        while (!entry.outgoing.empty()) {
            const int sent =
                send(entry.native, reinterpret_cast<const char*>(entry.outgoing.data()),
                     int(entry.outgoing.size()), 0);
            if (sent == SOCKET_ERROR) {
                if (!pending(WSAGetLastError()))
                    entry.failed = true;
                break;
            }
            if (sent == 0)
                break;
            log("send", "tcp", id, entry.outgoing.data(), size_t(sent));
            entry.outgoing.erase(entry.outgoing.begin(), entry.outgoing.begin() + sent);
        }
    }
    int32_t open(bool udp, const std::vector<uint8_t>& request) {
        if (request.size() < Header + 8 || !ready || !target || sockets.size() >= 128)
            return Failure;
        uint16_t id = 0;
        while (sockets.contains(id))
            ++id;
        Socket entry;
        entry.udp = udp;
        entry.native =
            socket(AF_INET, udp ? SOCK_DGRAM : SOCK_STREAM, udp ? IPPROTO_UDP : IPPROTO_TCP);
        if (entry.native == INVALID_SOCKET)
            return Failure;
        u_long nonblocking = 1;
        if (ioctlsocket(entry.native, FIONBIO, &nonblocking) != 0) {
            closesocket(entry.native);
            return Failure;
        }
        sockaddr_in endpoint{};
        endpoint.sin_family = AF_INET;
        endpoint.sin_port = u16(request, Header + 4);
        endpoint.sin_addr.s_addr = u32(request, Header);
        if (udp) {
            // Guest bind ports may repeat between native game instances; each gets a host ephemeral port.
            endpoint.sin_addr.s_addr = localAddress;
            endpoint.sin_port = 0;
            if (bind(entry.native, reinterpret_cast<sockaddr*>(&endpoint), sizeof(endpoint)) != 0) {
                closesocket(entry.native);
                return Failure;
            }
        } else {
            // APP (10127), legacy registration HTTP (80), and test peers must all be
            // on the explicitly selected server. No public hostname/IP fallthrough.
            if (endpoint.sin_addr.s_addr != target) {
                closesocket(entry.native);
                return Failure;
            }
            const int result =
                connect(entry.native, reinterpret_cast<sockaddr*>(&endpoint), sizeof(endpoint));
            if (result != 0) {
                if (!pending(WSAGetLastError())) {
                    closesocket(entry.native);
                    return Failure;
                }
                entry.connecting = true;
            }
        }
        sockets.emplace(id, std::move(entry));
        return id;
    }
    int32_t closeTcp(uint16_t id, bool abort) {
        auto* entry = get(id, false);
        if (!entry)
            return Failure;
        if (entry->native != INVALID_SOCKET) {
            if (abort) {
                const linger reset{1, 0};
                setsockopt(entry->native, SOL_SOCKET, SO_LINGER,
                           reinterpret_cast<const char*>(&reset), sizeof(reset));
            } else {
                shutdown(entry->native, SD_SEND);
            }
            closesocket(entry->native);
            entry->native = INVALID_SOCKET;
        }
        entry->connecting = false;
        entry->closed = true;
        entry->outgoing.clear();
        return 0;
    }
    int32_t release(uint16_t id, bool udp) {
        auto found = sockets.find(id);
        if (found == sockets.end() || found->second.udp != udp)
            return Failure;
        if (found->second.native != INVALID_SOCKET)
            closesocket(found->second.native);
        sockets.erase(found);
        return 0;
    }
    std::vector<uint8_t> call(uint32_t op, const std::vector<uint8_t>& request, size_t replySize) {
        std::vector<uint8_t> reply(std::min(replySize, MaxReply));
        std::copy_n(request.begin(), std::min({request.size(), reply.size(), Header}),
                    reply.begin());
        int32_t result = Failure;
        if (reply.size() < Header)
            return reply;
        const auto id = u16(request, Header);
        for (auto& [socketId, entry] : sockets) {
            if (!entry.udp)
                service(socketId, entry);
        }
        switch (op) {
            case 0x01: // Configure the guest's virtual interface; routing stays with Winsock.
            case 0x1c: // Configure name service for this virtual interface.
            case 0x05: // TCP initialization over an actual Winsock provider.
            case 0x1f: // Interface initialization.
            case 0x25: // Interface option; no guest Ethernet adapter is created.
            case 0x27: // Initialize the virtual Ethernet link.
            case 0x2b: // The host already owns its IP configuration, including DHCP if used.
            case 0x33:
                result = ready && target && localAddress ? 0 : Failure;
                break;
            case 0x21:
            case 0x29:
                if (ready && target && localAddress) {
                    linkStarted = true;
                    result = 0;
                }
                break;
            case 0x23:
                if (ready && target && reply.size() >= Header + 44) {
                    put16(reply, 0x24, 4);
                    result = 0;
                }
                break;
            case 0x24:
                if (ready && target && reply.size() >= Header + 4) {
                    put32(reply, Header, 1);
                    result = 1;
                }
                break;
            case 0x34:
                if (localAddress && reply.size() >= 0x28) {
                    put32(reply, 0x1c, localAddress);
                    put32(reply, 0x20, 0xffffffff); // Point-to-host virtual interface.
                    put32(reply, 0x24, 0);
                    result = 0;
                }
                break;
            case 0x2e:
                if (localAddress && reply.size() >= 0x20) {
                    put32(reply, 0x1c, localAddress);
                    result = 0;
                }
                break;
            case 0x2d:
                if (target && reply.size() >= 0x124) {
                    const auto host = env("REO_COOP_HOST");
                    std::copy_n(host.begin(), std::min<size_t>(host.size(), 255),
                                reply.begin() + 0x1c);
                    put32(reply, 0x11c, target);
                    put32(reply, 0x120, target);
                    result = 0;
                }
                break;
            case 0x35:
                result = localAddress && linkStarted ? 3 : Failure;
                break;
            case 0x50:
            case 0x53:
                result = localAddress && linkStarted ? 1 : 0;
                break;
            case 0x4d:
                if (localAddress) {
                    put32(reply, 0, 1);
                    result = configChanged ? 1 : 0;
                    configChanged = false;
                }
                break;
            case 0x4e:
                if (localAddress && reply.size() >= 0x20 + 0x30c) {
                    put32(reply, 0x20, 1);
                    put32(reply, 0x24, 1);
                    put32(reply, 0x28, 1);
                    result = 1;
                }
                break;
            case 0x4f:
                result = localAddress && request.size() >= 4 && u32(request, 0) == 1 ? 0 : Failure;
                break;
            case 0x07:
            case 0x18:
                result = open(op == 0x18, request);
                break;
            case 0x0b:
            case 0x0c:
                if (request.size() >= Header + 2)
                    result = closeTcp(id, op == 0x0c);
                break;
            case 0x1a:
                if (request.size() >= Header + 2)
                    result = release(id, true);
                break;
            case 0x4a:
                if (request.size() >= Header + 2)
                    result = release(id, false);
                break;
            case 0x0e: {
                auto* entry = get(id, false);
                if (!entry || request.size() < 0x1e || reply.size() < 0x26)
                    break;
                u_long bytes = 0;
                if (entry->native != INVALID_SOCKET)
                    ioctlsocket(entry->native, FIONREAD, &bytes);
                put16(reply, 0x1e,
                      entry->failed       ? 0
                      : entry->closed     ? 9
                      : entry->connecting ? 1
                                          : 4);
                put16(reply, 0x20, 0);
                put16(reply, 0x22,
                      entry->closed
                          ? 0
                          : uint16_t(std::min<size_t>(65535, MaxQueued - entry->outgoing.size())));
                put16(reply, 0x24, uint16_t(std::min<u_long>(bytes, 65535)));
                result = entry->failed ? Failure : 0;
                break;
            }
            case 0x0f: {
                auto* entry = get(id, false);
                const auto length = u16(request, 0x1e);
                if (!entry || request.size() < 0x20 + size_t(length) || entry->failed ||
                    entry->closed)
                    break;
                if (entry->connecting) {
                    result = Again;
                    break;
                }
                if (entry->outgoing.size() + length > MaxQueued) {
                    result = Again;
                    break;
                }
                entry->outgoing.insert(entry->outgoing.end(), request.begin() + 0x20,
                                       request.begin() + 0x20 + length);
                service(id, *entry);
                if (!entry->failed) {
                    result = 0;
                }
                break;
            }
            case 0x12:
            case 0x13: {
                auto* entry = get(id, false);
                if (!entry || reply.size() < 0x20 || request.size() < 0x20 || entry->failed)
                    break;
                if (entry->connecting) {
                    result = Again;
                    break;
                }
                if (entry->closed) {
                    result = 0;
                    break;
                }
                const size_t length = std::min<size_t>(u16(request, 0x1e), reply.size() - 0x20);
                if (!length) {
                    result = 0;
                    break;
                }
                result = recv(entry->native, reinterpret_cast<char*>(reply.data() + 0x20),
                              int(length), 0);
                if (result == SOCKET_ERROR) {
                    result = pending(WSAGetLastError()) ? (op == 0x13 ? 0 : Again) : Failure;
                } else if (result == 0) {
                    entry->closed = true;
                } else {
                    log("recv", "tcp", id, reply.data() + 0x20, size_t(result));
                }
                break;
            }
            case 0x19: {
                auto* entry = get(id, true);
                const auto length = u16(request, 0x26);
                if (!entry || request.size() < 0x28 + size_t(length))
                    break;
                sockaddr_in peer{};
                peer.sin_family = AF_INET;
                peer.sin_addr.s_addr = u32(request, 0x20);
                peer.sin_port = u16(request, 0x24);
                if (peer.sin_addr.s_addr != target)
                    break;
                const int sent =
                    sendto(entry->native, reinterpret_cast<const char*>(request.data() + 0x28),
                           int(length), 0, reinterpret_cast<const sockaddr*>(&peer), sizeof(peer));
                if (sent == length) {
                    result = 0;
                    log("send", "udp", id, request.data() + 0x28, length, &peer);
                } else if (sent == SOCKET_ERROR && pending(WSAGetLastError())) {
                    result = Again;
                }
                break;
            }
            case 0x1b: {
                size_t cursor = Header;
                unsigned count = 0;
                std::array<uint8_t, 65536> packet{};
                for (auto& [socketId, entry] : sockets) {
                    if (!entry.udp)
                        continue;
                    while (count < 64 && cursor + 14 <= reply.size()) {
                        fd_set readable;
                        FD_ZERO(&readable);
                        FD_SET(entry.native, &readable);
                        timeval zero{};
                        if (select(0, &readable, nullptr, nullptr, &zero) <= 0)
                            break;
                        u_long available = 0;
                        if (ioctlsocket(entry.native, FIONREAD, &available) != 0)
                            break;
                        const size_t padded = (size_t(available) + 3) & ~size_t(3);
                        if (cursor + 12 + padded + 2 > reply.size())
                            break;
                        sockaddr_in peer{};
                        int peerSize = sizeof(peer);
                        const int received = recvfrom(
                            entry.native, reinterpret_cast<char*>(packet.data()),
                            int(packet.size()), 0, reinterpret_cast<sockaddr*>(&peer), &peerSize);
                        if (received == SOCKET_ERROR)
                            break;
                        put16(reply, cursor, socketId);
                        put16(reply, cursor + 2, uint16_t(received));
                        put16(reply, cursor + 4, peer.sin_port);
                        put16(reply, cursor + 6, uint16_t((4 - (received & 3)) & 3));
                        put32(reply, cursor + 8, peer.sin_addr.s_addr);
                        std::copy_n(packet.begin(), received, reply.begin() + cursor + 12);
                        cursor += 12 + ((size_t(received) + 3) & ~size_t(3));
                        ++count;
                        log("recv", "udp", socketId, packet.data(), size_t(received), &peer);
                    }
                }
                put16(reply, cursor, 0xffff);
                result = count ? 0 : Failure;
                break;
            }
            case 0x38: {
                // AVE resolver initialization: hostname[256], primary and secondary raw IPv4.
                if (!ready || !target || !localAddress || request.size() < 0x124)
                    break;
                const auto first = request.begin() + Header;
                const auto end = std::find(first, first + 256, uint8_t(0));
                if (end == first + 256)
                    break;
                if (!std::all_of(first, end, [](uint8_t byte) {
                        return (byte >= 'a' && byte <= 'z') || (byte >= 'A' && byte <= 'Z') ||
                               (byte >= '0' && byte <= '9') || byte == '-' || byte == '_' ||
                               byte == '.';
                    }))
                    break;
                resolverHostname.assign(first, end);
                resolverAddresses = {u32(request, 0x11c), u32(request, 0x120)};
                queries.clear();
                nextQuery = 1;
                // Known game aliases still use the explicitly selected host resolver.
                // Supplied legacy DNS addresses are retained, never queried externally.
                if (trace) {
                    trace << "{\"event\":\"resolver_init\",\"hostname\":\"" << resolverHostname
                          << "\",\"primary_raw\":" << resolverAddresses[0]
                          << ",\"secondary_raw\":" << resolverAddresses[1] << "}\n";
                    trace.flush();
                }
                result = 0;
                break;
            }
            case 0x3a: {
                if (request.size() <= Header || queries.size() >= 128)
                    break;
                const auto end = std::find(request.begin() + Header, request.end(), uint8_t(0));
                if (end == request.end() || size_t(end - request.begin() - Header) > 253)
                    break;
                std::string name(request.begin() + Header, end);
                std::transform(name.begin(), name.end(), name.begin(), [](unsigned char c) {
                    return char(c >= 'A' && c <= 'Z' ? c + ('a' - 'A') : c);
                });
                const bool known = name == "snap01.reo.capcom.sf.yav4.com" ||
                                   name == "snap01.capcom.client.sf.yav4.com" ||
                                   name == "app01.reo.capcom.sf.yav4.com" ||
                                   name == "regweb.reo.capcom.sf.yav4.com" || name == "localhost" ||
                                   name == env("REO_COOP_HOST");
                while (!nextQuery || queries.contains(nextQuery))
                    ++nextQuery;
                result = nextQuery++;
                queries.emplace(uint16_t(result), Query{target, known && target != 0});
                break;
            }
            case 0x3c: {
                auto found = queries.find(id);
                if (found == queries.end() || reply.size() < 0x24)
                    break;
                if (found->second.ok) {
                    put32(reply, 0x20, found->second.address);
                    result = 1;
                }
                // Query identity remains owned until the original DNS release RPC.
                break;
            }
            case 0x3b: {
                if (request.size() < Header + 2)
                    break;
                result = queries.erase(id) == 1 ? 0 : Failure;
                break;
            }
            default:
                break;
        }
        put32(reply, 0x18, uint32_t(result));
        ++calls;
        if (diagnostics && (calls <= 256 || calls % 128 == 0)) {
            const auto requestHex = hex(request.data(), std::min<size_t>(request.size(), 64));
            std::fprintf(stderr,
                         "[NET-RPC] op=0x%02x ret=%d req=%zu reply=%zu sockets=%zu data=%s\n", op,
                         result, request.size(), reply.size(), sockets.size(), requestHex.c_str());
        }
        if (trace) {
            trace << "{\"event\":\"rpc\",\"op\":" << op << ",\"ret\":" << result
                  << ",\"request_bytes\":" << request.size() << ",\"reply_bytes\":" << reply.size()
                  << ",\"sockets\":" << sockets.size() << "}\n";
            trace.flush();
        }
        return reply;
    }
};

SnapIopTransport::SnapIopTransport() : impl_(std::make_unique<Impl>()) {}
SnapIopTransport::~SnapIopTransport() = default;
std::vector<uint8_t> SnapIopTransport::call(uint32_t op, const std::vector<uint8_t>& request,
                                            size_t replySize) {
    std::lock_guard lock(impl_->mutex);
    return impl_->call(op, request, replySize);
}
void SnapIopTransport::reset() {
    std::lock_guard lock(impl_->mutex);
    impl_->clear();
}
