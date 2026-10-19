#include "snap_protocol.h"
#include <cstdio>
#include <cstring>

#ifdef REO_PLATFORM_WINDOWS
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#endif

namespace reo {

SnapProtocol::~SnapProtocol() {
    disconnect();
}

bool SnapProtocol::connect(const std::string& host, int port) {
#ifdef REO_PLATFORM_WINDOWS
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        fprintf(stderr, "[NET] WSAStartup failed\n");
        m_state = SnapState::Error;
        return false;
    }

    m_state = SnapState::Connecting;
    printf("[NET] Connecting to %s:%d...\n", host.c_str(), port);

    struct addrinfo hints = {}, *result = nullptr;
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    char port_str[16];
    snprintf(port_str, sizeof(port_str), "%d", port);

    if (getaddrinfo(host.c_str(), port_str, &hints, &result) != 0) {
        fprintf(stderr, "[NET] DNS resolution failed for %s\n", host.c_str());
        m_state = SnapState::Error;
        return false;
    }

    m_socket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (m_socket == INVALID_SOCKET) {
        fprintf(stderr, "[NET] Socket creation failed\n");
        freeaddrinfo(result);
        m_state = SnapState::Error;
        return false;
    }

    if (::connect((SOCKET)m_socket, result->ai_addr, (int)result->ai_addrlen) == SOCKET_ERROR) {
        fprintf(stderr, "[NET] Connection failed to %s:%d\n", host.c_str(), port);
        closesocket((SOCKET)m_socket);
        m_socket = INVALID_SOCKET;
        freeaddrinfo(result);
        m_state = SnapState::Error;
        return false;
    }

    freeaddrinfo(result);

    // Set non-blocking mode for update() polling
    u_long mode = 1;
    ioctlsocket((SOCKET)m_socket, FIONBIO, &mode);

    m_state = SnapState::Authenticating;
    printf("[NET] Connected to %s:%d\n", host.c_str(), port);

    if (m_on_connected)
        m_on_connected();
    return true;
#else
    fprintf(stderr, "[NET] Network not implemented on this platform\n");
    return false;
#endif
}

void SnapProtocol::disconnect() {
#ifdef REO_PLATFORM_WINDOWS
    if (m_socket != INVALID_SOCKET) {
        closesocket((SOCKET)m_socket);
        m_socket = INVALID_SOCKET;
        WSACleanup();
        printf("[NET] Disconnected\n");
    }
#endif
    m_state = SnapState::Disconnected;
}

bool SnapProtocol::authenticate(const std::string& player_name) {
    m_player_name = player_name;
    printf("[NET] Authenticating as '%s'...\n", player_name.c_str());

    // TODO: Send authentication packet
    // The obsrv.org server expects a specific handshake sequence
    // For now, mark as authenticated
    m_state = SnapState::InLobby;
    return true;
}

void SnapProtocol::request_room_list() {
    printf("[NET] Requesting room list...\n");
    // TODO: Send room list request packet
}

bool SnapProtocol::create_room(const std::string& name, const std::string& scenario,
                               int max_players) {
    printf("[NET] Creating room: %s (%s, max %d)\n", name.c_str(), scenario.c_str(), max_players);
    // TODO: Send room creation packet
    m_state = SnapState::InRoom;
    return true;
}

bool SnapProtocol::join_room(uint32_t room_id) {
    printf("[NET] Joining room %u\n", room_id);
    // TODO: Send room join packet
    m_state = SnapState::InRoom;
    return true;
}

void SnapProtocol::leave_room() {
    printf("[NET] Leaving room\n");
    // TODO: Send room leave packet
    m_state = SnapState::InLobby;
}

void SnapProtocol::send_game_data(const uint8_t* data, uint32_t size) {
    // TODO: Wrap in game data packet and send
    send_packet(0x10, data, size); // Placeholder type ID
}

void SnapProtocol::send_chat(const std::string& message) {
    printf("[NET] Chat: %s\n", message.c_str());
    // TODO: Send chat packet
}

void SnapProtocol::update() {
    if (m_state == SnapState::Disconnected || m_state == SnapState::Error)
        return;

    // TODO: Poll socket for incoming packets and dispatch
    SnapPacketHeader header;
    std::vector<uint8_t> data;

    while (recv_packet(header, data)) {
        handle_packet(header, data.data(), (uint32_t)data.size());
    }
}

void SnapProtocol::send_packet(uint16_t type, const void* data, uint32_t size) {
#ifdef REO_PLATFORM_WINDOWS
    if (m_socket == INVALID_SOCKET)
        return;

    SnapPacketHeader header;
    header.length = (uint16_t)(sizeof(header) + size);
    header.type = type;
    header.sequence = m_sequence++;

    // Send header + data
    send((SOCKET)m_socket, (const char*)&header, sizeof(header), 0);
    if (size > 0 && data) {
        send((SOCKET)m_socket, (const char*)data, size, 0);
    }
#endif
}

bool SnapProtocol::recv_packet(SnapPacketHeader& header, std::vector<uint8_t>& data) {
#ifdef REO_PLATFORM_WINDOWS
    if (m_socket == INVALID_SOCKET)
        return false;

    int received = recv((SOCKET)m_socket, (char*)&header, sizeof(header), MSG_PEEK);
    if (received <= 0)
        return false;

    if (received < (int)sizeof(header))
        return false;

    // Read full header
    recv((SOCKET)m_socket, (char*)&header, sizeof(header), 0);

    // Read payload
    uint32_t payload_size = header.length - sizeof(header);
    if (payload_size > 0 && payload_size < 65536) {
        data.resize(payload_size);
        recv((SOCKET)m_socket, (char*)data.data(), payload_size, 0);
    }

    return true;
#else
    return false;
#endif
}

void SnapProtocol::handle_packet(const SnapPacketHeader& header, const uint8_t* data,
                                 uint32_t size) {
    printf("[NET] Received packet: type=0x%04X seq=%u size=%u\n", header.type, header.sequence,
           size);

    // TODO: Dispatch based on packet type
    // Types will be reverse-engineered from obsrv.org server code
}

} // namespace reo
