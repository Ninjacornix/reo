#pragma once

#include <string>
#include <vector>
#include <functional>

namespace reo {

struct LobbyPlayer {
    uint32_t id;
    std::string name;
    std::string character; // Kevin, Mark, Jim, etc.
    bool ready;
};

struct LobbyGameRoom {
    uint32_t id;
    std::string name;
    std::string scenario;   // "Outbreak", "Below Freezing Point", etc.
    std::string difficulty; // Easy, Normal, Hard, Very Hard
    int current_players;
    int max_players;
    bool in_progress;
    std::vector<LobbyPlayer> players;
};

class LobbyClient {
  public:
    LobbyClient() = default;

    // Refresh the room list from server
    void refresh();

    // Get current room list
    const std::vector<LobbyGameRoom>& rooms() const {
        return m_rooms;
    }

    // Create a new game room
    bool create(const std::string& name, const std::string& scenario, const std::string& difficulty,
                int max_players);

    // Join existing room
    bool join(uint32_t room_id);

    // Leave current room
    void leave();

    // Set ready status
    void set_ready(bool ready);

    // Chat in lobby
    void chat(const std::string& message);

  private:
    std::vector<LobbyGameRoom> m_rooms;
    LobbyGameRoom* m_current_room = nullptr;
};

} // namespace reo
