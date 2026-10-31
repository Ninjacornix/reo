// SPDX-License-Identifier: GPL-3.0-only
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <winsock2.h>
#include <ws2tcpip.h>
using SocketLength = int;
#else
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>
using SOCKET = int;
using SocketLength = socklen_t;
constexpr int INVALID_SOCKET = -1;
static void closesocket(SOCKET socket) { close(socket); }
#endif

#include "../../network/native/snap_iop_transport.h"

#include <algorithm>
#include <array>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include <string>
#include <thread>
#include <vector>

namespace {
void setEnvironment(const char* key, const char* value) {
#ifdef _WIN32
    _putenv_s(key, value);
#else
    if (*value) setenv(key, value, 1); else unsetenv(key);
#endif
}
unsigned checks = 0;
void require(bool ok, const char* message) {
    ++checks;
    if (!ok)
        throw std::runtime_error(message);
}
uint16_t read16(const std::vector<uint8_t>& data, size_t offset) {
    require(offset + 2 <= data.size(), "reply range");
    return uint16_t(data[offset] | uint16_t(data[offset + 1]) << 8);
}
int32_t result(const std::vector<uint8_t>& data) {
    require(data.size() >= 0x1c, "result range");
    uint32_t value = 0;
    std::memcpy(&value, data.data() + 0x18, 4);
    return int32_t(value);
}
void put16(std::vector<uint8_t>& data, size_t offset, uint16_t value) {
    std::memcpy(data.data() + offset, &value, 2);
}
void put32(std::vector<uint8_t>& data, size_t offset, uint32_t value) {
    std::memcpy(data.data() + offset, &value, 4);
}
std::vector<uint8_t> request(size_t size = 64) {
    return std::vector<uint8_t>(size);
}
sockaddr_in local(uint16_t port = 0) {
    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    address.sin_port = port;
    return address;
}
uint16_t boundPort(SOCKET socket) {
    auto address = local();
    SocketLength length = sizeof(address);
    require(getsockname(socket, reinterpret_cast<sockaddr*>(&address), &length) == 0,
            "bound host port");
    return address.sin_port;
}
int open(SnapIopTransport& transport, uint32_t op, uint16_t port) {
    auto data = request();
    put32(data, 0x1c, htonl(INADDR_LOOPBACK));
    put16(data, 0x20, port);
    return result(transport.call(op, data, 64));
}
std::vector<uint8_t> socketRequest(int id, uint16_t length = 0, size_t size = 64) {
    auto data = request(size);
    put16(data, 0x1c, uint16_t(id));
    put16(data, 0x1e, length);
    return data;
}
void connected(SnapIopTransport& transport, int id) {
    for (int i = 0; i < 500; ++i) {
        auto status = transport.call(0x0e, socketRequest(id), 64);
        if (result(status) == 0 && read16(status, 0x1e) == 4)
            return;
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
    require(false, "TCP connection must really establish");
}
std::vector<uint8_t> receive(SnapIopTransport& transport, int id, size_t wanted) {
    std::vector<uint8_t> bytes;
    for (int i = 0; i < 500 && bytes.size() < wanted; ++i) {
        auto response =
            transport.call(0x12, socketRequest(id, uint16_t(wanted - bytes.size())), 0x20 + wanted);
        const int count = result(response);
        if (count > 0)
            bytes.insert(bytes.end(), response.begin() + 0x20, response.begin() + 0x20 + count);
        else if (count != -16)
            throw std::runtime_error("unexpected TCP receive result");
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
    require(bytes.size() == wanted, "TCP receive completes");
    return bytes;
}
} // namespace

int main(int argc, char** argv) {
    try {
        setEnvironment("REO_COOP_HOST", "127.0.0.1");
        SnapIopTransport transport;
        require(result(transport.call(0x05, request(), 64)) == 0, "actual native socket init");
        require(result(transport.call(0x10, request(), 64)) == -1,
                "unavailable TcpSendNb rejected");
        require(result(transport.call(0xffff, request(), 64)) == -1, "unknown RPC rejected");
        require(result(transport.call(0x07, {}, 64)) == -1, "truncated open rejected");
        require(transport.call(0x07, {}, 4).size() == 4, "small reply bounded");
        auto external = request();
        put32(external, 0x1c, htonl(0x08080808));
        put16(external, 0x20, htons(10127));
        require(result(transport.call(7, external, 64)) == -1,
                "unselected public endpoint rejected before any socket connection");
        require(result(transport.call(0x4d, request(), 64)) == 1, "config initial change");
        require(result(transport.call(0x4d, request(), 64)) == 0, "no repeated config change");
        auto dns = request(128);
        const std::string hostname = "snap01.reo.capcom.sf.yav4.com";
        std::copy(hostname.begin(), hostname.end(), dns.begin() + 0x1c);
        const int query = result(transport.call(0x3a, dns, 64));
        require(query > 0, "DNS allocates query");
        auto answer = transport.call(0x3c, socketRequest(query), 64);
        require(result(answer) == 1, "DNS resolves configured game service");
        uint32_t address = 0;
        std::memcpy(&address, answer.data() + 0x20, 4);
        require(address == htonl(INADDR_LOOPBACK), "DNS raw network-order IPv4");
        require(result(transport.call(0x3b, socketRequest(query), 64)) == 0,
                "original DNS release frees the known query");
        require(result(transport.call(0x3c, socketRequest(query), 64)) == -1,
                "released DNS query cannot be polled");
        require(result(transport.call(0x3b, socketRequest(query), 64)) == -1,
                "double DNS release rejects unknown handle");
        dns = request(128);
        const std::string file2Host = "snap01.capcom.client.sf.yav4.com";
        std::copy(file2Host.begin(), file2Host.end(), dns.begin() + 0x1c);
        const int file2Query = result(transport.call(0x3a, dns, 64));
        auto file2Answer = transport.call(0x3c, socketRequest(file2Query), 64);
        std::memcpy(&address, file2Answer.data() + 0x20, 4);
        require(file2Query > 0 && result(file2Answer) == 1 && address == htonl(INADDR_LOOPBACK),
                "File #2 bootstrap alias resolves to the selected host");
        require(result(transport.call(0x3b, socketRequest(file2Query), 64)) == 0,
                "File #2 bootstrap query is released");
        dns = request(128);
        const std::string unknownHost = "gate1.us.dnas.playstation.org";
        std::copy(unknownHost.begin(), unknownHost.end(), dns.begin() + 0x1c);
        const int unknownQuery = result(transport.call(0x3a, dns, 64));
        require(unknownQuery > 0 &&
                    result(transport.call(0x3c, socketRequest(unknownQuery), 64)) == -1,
                "unimplemented DNAS is not falsely resolved");

        dns = request(128);
        std::copy(hostname.begin(), hostname.end(), dns.begin() + 0x1c);
        const int cancelledQuery = result(transport.call(0x3a, dns, 64));
        require(cancelledQuery > 0, "pending query before resolver initialization");
        auto resolver = request(0x128);
        const std::string machineName = "reo-local";
        std::copy(machineName.begin(), machineName.end(), resolver.begin() + 0x1c);
        put32(resolver, 0x11c, htonl(INADDR_LOOPBACK));
        put32(resolver, 0x120, htonl(0x7f000002));
        require(result(transport.call(0x38, resolver, 0x20)) == 0,
                "verified resolver init accepts configured host interface");
        require(result(transport.call(0x3c, socketRequest(cancelledQuery), 64)) == -1,
                "resolver initialization cancels prior query handles");
        const int afterInit = result(transport.call(0x3a, dns, 64));
        require(afterInit > 0 && result(transport.call(0x3c, socketRequest(afterInit), 64)) == 1,
                "game alias remains resolvable after initialization");
        auto unterminated = resolver;
        std::fill(unterminated.begin() + 0x1c, unterminated.begin() + 0x11c, 'a');
        require(result(transport.call(0x38, unterminated, 0x20)) == -1,
                "unterminated 256-byte resolver hostname rejected");
        auto truncatedResolver = resolver;
        truncatedResolver.resize(0x123);
        require(result(transport.call(0x38, truncatedResolver, 0x20)) == -1,
                "truncated secondary resolver IPv4 rejected");
        auto invalidResolver = resolver;
        invalidResolver[0x1c] = '\"';
        require(result(transport.call(0x38, invalidResolver, 0x20)) == -1,
                "invalid resolver hostname rejected");
        setEnvironment("REO_COOP_HOST", "");
        {
            SnapIopTransport unconfigured;
            require(result(unconfigured.call(0x38, resolver, 0x20)) == -1,
                    "resolver initialization fails without selected host resolver");
        }
        setEnvironment("REO_COOP_HOST", "127.0.0.1");

        SOCKET udp = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        auto bindAddress = local();
        require(bind(udp, reinterpret_cast<sockaddr*>(&bindAddress), sizeof(bindAddress)) == 0,
                "real UDP echo bind");
        const uint16_t udpPort = boundPort(udp);
#ifdef _WIN32
        DWORD timeout = 2000;
#else
        timeval timeout{2, 0};
#endif
        setsockopt(udp, SOL_SOCKET, SO_RCVTIMEO, reinterpret_cast<char*>(&timeout),
                   sizeof(timeout));
        const int udpId = open(transport, 0x18, 0);
        require(udpId >= 0, "UDP open including valid socket zero");
        auto sendRequest = socketRequest(udpId, 0, 0x28 + 5);
        put32(sendRequest, 0x20, htonl(INADDR_LOOPBACK));
        put16(sendRequest, 0x24, udpPort);
        put16(sendRequest, 0x26, 5);
        const std::array<uint8_t, 5> payload{1, 2, 3, 4, 5};
        std::copy(payload.begin(), payload.end(), sendRequest.begin() + 0x28);
        require(result(transport.call(0x19, sendRequest, 64)) == 0, "UDP send success uses zero");
        std::array<char, 64> wire{};
        sockaddr_in source{};
        SocketLength sourceLength = sizeof(source);
        const int received = recvfrom(udp, wire.data(), int(wire.size()), 0,
                                      reinterpret_cast<sockaddr*>(&source), &sourceLength);
        require(received == 5 && std::memcmp(wire.data(), payload.data(), 5) == 0,
                "UDP sends actual bytes to network-order port");
        require(sendto(udp, wire.data(), received, 0, reinterpret_cast<sockaddr*>(&source),
                       sourceLength) == received,
                "actual UDP echo reply");
        std::vector<uint8_t> frames;
        for (int i = 0; i < 100; ++i) {
            frames = transport.call(0x1b, request(), 128);
            if (result(frames) == 0)
                break;
            std::this_thread::sleep_for(std::chrono::milliseconds(2));
        }
        require(result(frames) == 0, "UDP bulk receive");
        require(read16(frames, 0x1c) == udpId && read16(frames, 0x1e) == 5, "UDP record header");
        require(read16(frames, 0x20) == udpPort && read16(frames, 0x22) == 3,
                "UDP network port and four-byte padding");
        require(std::equal(payload.begin(), payload.end(), frames.begin() + 0x28), "UDP payload");
        require(read16(frames, 0x30) == 0xffff, "UDP sentinel after padded record");
        require(result(transport.call(0x1b, request(), 128)) == -1, "empty UDP poll");
        closesocket(udp);

        // Real local TCP exchange independently checks send's zero-success contract.
        SOCKET listener = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        bindAddress = local();
        require(bind(listener, reinterpret_cast<sockaddr*>(&bindAddress), sizeof(bindAddress)) == 0,
                "real TCP bind");
        require(listen(listener, 1) == 0, "real TCP listen");
        const int tcpId = open(transport, 7, boundPort(listener));
        require(tcpId >= 0, "TCP asynchronous open");
        connected(transport, tcpId);
        SOCKET accepted = accept(listener, nullptr, nullptr);
        require(accepted != INVALID_SOCKET, "TCP server actually accepted");
        setsockopt(accepted, SOL_SOCKET, SO_RCVTIMEO, reinterpret_cast<char*>(&timeout),
                   sizeof(timeout));
        sendRequest = socketRequest(tcpId, 5, 0x20 + 5);
        std::copy(payload.begin(), payload.end(), sendRequest.begin() + 0x20);
        require(result(transport.call(0x0f, sendRequest, 64)) == 0, "TCP send success uses zero");
        require(recv(accepted, wire.data(), 5, MSG_WAITALL) == 5, "TCP payload reached real peer");
        require(send(accepted, wire.data(), 5, 0) == 5, "TCP echo sent");
        const auto echo = receive(transport, tcpId, 5);
        require(std::equal(payload.begin(), payload.end(), echo.begin()),
                "TCP exact echoed payload");
        require(result(transport.call(0x13, socketRequest(tcpId, 8), 64)) == 0,
                "nonblocking recv returns zero when empty");
        closesocket(accepted);
        closesocket(listener);
        require(result(transport.call(0x0b, socketRequest(tcpId), 64)) == 0,
                "TCP graceful close retains the guest handle");
        const auto closedStatus = transport.call(0x0e, socketRequest(tcpId), 64);
        require(result(closedStatus) == 0 && read16(closedStatus, 0x1e) == 9,
                "closed handle status is safe without an OS socket");
        require(result(transport.call(0x12, socketRequest(tcpId, 8), 64)) == 0,
                "closed handle receive returns EOF without host socket access");
        require(result(transport.call(0x4a, socketRequest(tcpId), 64)) == 0,
                "TCP delete releases the closed tombstone");
        require(result(transport.call(0x4a, socketRequest(tcpId), 64)) == -1,
                "double TCP delete rejects unknown handle");
        const int refusedId = open(transport, 7, udpPort);
        if (refusedId >= 0) {
            bool failed = false;
            for (int i = 0; i < 500; ++i) {
                const auto refused = transport.call(0x0e, socketRequest(refusedId), 64);
                require(read16(refused, 0x1e) != 4, "refused connection never reports connected");
                if (result(refused) == -1) {
                    failed = true;
                    break;
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(2));
            }
            require(failed, "real connect refusal is observed");
        }

        const bool loopbackOnly = argc > 1 && std::strcmp(argv[1], "--loopback-only") == 0;
        if (!loopbackOnly) {
        // The reviewed separate openSNAP APP process must speak first.
        const int appId = open(transport, 7, htons(10127));
        require(appId >= 0, "real Capcom APP open");
        connected(transport, appId);
        const auto opening = receive(transport, appId, 10);
        require(opening[0] == 0 && opening[1] == 2 && opening[2] == 1 && opening[3] == 0x10 &&
                    opening[4] == 2 && opening[8] == 0 && opening[9] == 0,
                "actual APP 1002 opening including no-salt payload");
        require(result(transport.call(0x0b, socketRequest(appId), 64)) == 0, "actual TCP close");
        require(result(transport.call(0x4a, socketRequest(appId), 64)) == 0,
                "APP TCP delete after original close");
        if (argc > 1 && std::strcmp(argv[1], "--http") == 0) {
            const int httpId = open(transport, 7, htons(80));
            require(httpId >= 0, "legacy registration HTTP opens only selected host");
            connected(transport, httpId);
            const std::string get = "GET /reweb/index.jsp HTTP/1.0\r\n"
                                    "Host: regweb.reo.capcom.sf.yav4.com\r\n"
                                    "User-Agent: reo-snap-iop-check/1\r\n"
                                    "Connection: close\r\n\r\n";
            auto httpSend = socketRequest(httpId, uint16_t(get.size()), 0x20 + get.size());
            std::copy(get.begin(), get.end(), httpSend.begin() + 0x20);
            require(result(transport.call(0x0f, httpSend, 64)) == 0, "real HTTP GET transmitted");
            std::string receivedHttp;
            bool eof = false;
            for (int i = 0; i < 500 && !eof; ++i) {
                const auto httpReply = transport.call(0x12, socketRequest(httpId, 4096), 0x1020);
                const int count = result(httpReply);
                if (count > 0)
                    receivedHttp.append(reinterpret_cast<const char*>(httpReply.data() + 0x20),
                                        size_t(count));
                else if (count == 0)
                    eof = true;
                else
                    require(count == -16, "HTTP pending is a genuine nonblocking receive");
                std::this_thread::sleep_for(std::chrono::milliseconds(2));
            }
            require(eof && receivedHttp.find("200 OK") != std::string::npos &&
                        receivedHttp.find("/reweb/signup/") != std::string::npos,
                    "real legacy registration portal received intact");
            require(result(transport.call(0x0c, socketRequest(httpId), 64)) == 0 &&
                        result(transport.call(0x4a, socketRequest(httpId), 64)) == 0,
                    "HTTP EOF socket abort/delete lifecycle");
        }
        }
        transport.reset();
        require(result(transport.call(0x0e, socketRequest(tcpId), 64)) == -1,
                "reset invalidates old TCP handles");
        require(result(transport.call(0x1a, socketRequest(udpId), 64)) == -1,
                "reset closes old UDP handles");
        std::printf("PASS checks=%u real_tcp=1 real_udp=1 capcom_app=%u\n", checks,
                    loopbackOnly ? 0u : 1u);
        return 0;
    } catch (const std::exception& error) {
        std::fprintf(stderr, "FAIL checks=%u: %s\n", checks, error.what());
        return 1;
    }
}
