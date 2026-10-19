#include "lobby_client.h"
#include <cstdio>

namespace reo {

void LobbyClient::refresh() {
    printf("[LOBBY] Refreshing room list...\n");
    // TODO: Request room list via SnapProtocol
}

bool LobbyClient::create(const std::string& name, const std::string& scenario,
                         const std::string& difficulty, int max_players) {
    printf("[LOBBY] Creating room: %s (%s / %s / %d players)\n", name.c_str(), scenario.c_str(),
           difficulty.c_str(), max_players);
    // TODO: Send create room request
    return true;
}

bool LobbyClient::join(uint32_t room_id) {
    printf("[LOBBY] Joining room %u\n", room_id);
    // TODO: Send join request
    return true;
}

void LobbyClient::leave() {
    printf("[LOBBY] Leaving room\n");
    m_current_room = nullptr;
}

void LobbyClient::set_ready(bool ready) {
    printf("[LOBBY] Ready: %s\n", ready ? "yes" : "no");
}

void LobbyClient::chat(const std::string& message) {
    printf("[LOBBY] Chat: %s\n", message.c_str());
}

} // namespace reo
