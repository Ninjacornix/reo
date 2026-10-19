#include "../../network/native/automatic_account.h"
#include <cstdio>
#include <stdexcept>
using namespace reo_network::automatic_account;
int main() {
    unsigned checks = 0;
    auto check = [&](bool ok) {
        if (!ok)
            throw std::runtime_error("automatic account flow failed");
        ++checks;
    };
    std::array<uint8_t, 28> credentialBytes{};
    const auto put = [&](unsigned offset, uint32_t word) {
        for (unsigned i = 0; i < 4; ++i)
            credentialBytes[offset + i] = uint8_t(word >> (i * 8));
    };
    put(0, 0x52454F41);
    put(4, 3);
    put(8, 15);
    for (unsigned i = 12; i < 27; ++i)
        credentialBytes[i] = 'a';
    std::array<char, 16> decoded{};
    check(decodeCredential(credentialBytes, 3, decoded) && decoded[14] == 'a' && decoded[15] == 0);
    check(!decodeCredential(credentialBytes, 2, decoded));
    check(!decodeCredential(std::span(credentialBytes.data(), 27), 3, decoded));
    credentialBytes[12] = '\n';
    check(!decodeCredential(credentialBytes, 3, decoded));
    Flow flow;
    Menu menu;
    menu.step = 44;
    menu.substep = 1;
    check(flow.tick(menu, 0, false, false).button == Button::None);
    check(flow.tick(menu, 1, true, false).button == Button::Down);
    menu.cursor = 1;
    check(flow.tick(menu, 1.5, true, false).button == Button::Confirm);
    menu.step = 45;
    menu.substep = 3;
    check(flow.tick(menu, 2, true, false).button == Button::None);
    menu.step = 49;
    menu.substep = 1;
    check(flow.tick(menu, 3, true, false).button == Button::Confirm);
    menu.step = 46;
    menu.cursor = 0;
    check(flow.tick(menu, 4, true, false).button == Button::Down);
    menu.cursor = 1;
    check(flow.tick(menu, 4.5, true, false).button == Button::Confirm);
    menu.substep = 11;
    menu.keyboardValid = menu.keyboardActive = true;
    // Reaching the editor before seeing its actual initialization is insufficient.
    check(!flow.tick(menu, 5, true, false).requestPassword);
    menu.keyboardDelay = 8;
    check(!flow.tick(menu, 5.1, true, false).requestPassword);
    menu.keyboardDelay = 0;
    check(flow.tick(menu, 5.2, true, false).requestPassword);
    check(!flow.tick(menu, 5.3, true, false).requestPassword);
    menu.substep = 1;
    menu.cursor = 0;
    menu.passwordPresent = true;
    check(!flow.tick(menu, 6, true, false).submitted); // Stale password is not enough.
    auto submit = flow.tick(menu, 6.1, true, true);
    check(submit.submitted && submit.button == Button::Confirm);
    check(flow.tick(menu, 6.15, true, true).button == Button::Confirm);
    check(flow.tick(menu, 6.5, true, true).button == Button::None);
    check(!flow.tick(menu, 7, true, true).submitted);
    Flow unrelated;
    menu.step = 4;
    check(unrelated.tick(menu, 0, true, true).button == Button::None);
    Flow fresh;
    menu = {};
    menu.step = 2;
    menu.substep = 21;
    menu.choice = 1;
    check(fresh.tick(menu, 0, true, false).button == Button::Up);
    menu.choice = 0;
    check(fresh.tick(menu, .5, true, false).button == Button::Confirm);
    menu.step = 6;
    menu.profileReady = true;
    menu.profileStage = 1;
    menu.profileCursor = 2;
    check(fresh.tick(menu, 1, true, false).button == Button::Confirm);
    std::printf("PASS automatic_account checks=%u game=0\n", checks);
}
