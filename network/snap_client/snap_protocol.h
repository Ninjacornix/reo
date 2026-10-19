#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include <functional>

namespace reo {

/*
 * SN@P Protocol Client
 *
 * RE Outbreak NTSC-U uses SN Systems' SN@P middleware for online play.
 * (The Japanese version uses KDDI middleware instead.)
 *
 * The protocol sits on top of TCP and handles:
 *   - Server discovery and lobby listing
 *   - Player authentication
 *   - Game room creation/joining
 *   - In-game state synchronization
 *   - Chat messaging
 *
 * We implement the client side to connect to obsrv.org's reconstructed
 * game servers (which are Java + MySQL). The server sends lobby info,
 * routes players to game rooms, and relays game state.
 *
 * Protocol details are partially documented via obsrv.org's open-source
 * server code. Packet format analysis is ongoing.
 */

// Connection states
enum class SnapState { Disconnected, Connecting, Authenticating, InLobby, InRoom, InGame, Error };

// Packet header (tentative — based on server code analysis)
struct SnapPacketHeader {
    uint16_t length;   // Total packet length including header
    uint16_t type;     // Packet type ID
    uint32_t sequence; // Sequence number
};

// Lobby entry
struct LobbyRoom {
    uint32_t room_id;
    std::string name;
    std::string scenario;
    int player_count;
    int max_players;
    bool in_progress;
};

// Callbacks
using OnConnected = std::function<void()>;
using OnDisconnected = std::function<void(const std::string& reason)>;
using OnLobbyUpdate = std::function<void(const std::vector<LobbyRoom>& rooms)>;
using OnGameData = std::function<void(const uint8_t* data, uint32_t size)>;

class SnapProtocol {
  public:
    SnapProtocol() = default;
    ~SnapProtocol();

    // Connect to game server
    bool connect(const std::string& host, int port);
    void disconnect();

    // Authentication
    bool authenticate(const std::string& player_name);

    // Lobby operations
    void request_room_list();
    bool create_room(const std::string& name, const std::string& scenario, int max_players);
    bool join_room(uint32_t room_id);
    void leave_room();

    // In-game
    void send_game_data(const uint8_t* data, uint32_t size);
    void send_chat(const std::string& message);

    // Process incoming packets (call from main loop)
    void update();

    SnapState state() const {
        return m_state;
    }

    // Event callbacks
    void on_connected(OnConnected cb) {
        m_on_connected = cb;
    }
    void on_disconnected(OnDisconnected cb) {
        m_on_disconnected = cb;
    }
    void on_lobby_update(OnLobbyUpdate cb) {
        m_on_lobby_update = cb;
    }
    void on_game_data(OnGameData cb) {
        m_on_game_data = cb;
    }

  private:
    void send_packet(uint16_t type, const void* data, uint32_t size);
    bool recv_packet(SnapPacketHeader& header, std::vector<uint8_t>& data);
    void handle_packet(const SnapPacketHeader& header, const uint8_t* data, uint32_t size);

    SnapState m_state = SnapState::Disconnected;

#ifdef REO_PLATFORM_WINDOWS
    uintptr_t m_socket = ~(uintptr_t)0; // INVALID_SOCKET
#endif

    uint32_t m_sequence = 0;
    std::string m_player_name;

    // Callbacks
    OnConnected m_on_connected;
    OnDisconnected m_on_disconnected;
    OnLobbyUpdate m_on_lobby_update;
    OnGameData m_on_game_data;
};

} // namespace reo
