#include "runtime/core/macos_run_control.h"
#include "runtime/audio/host_bridge.h"
#include "runtime/text/subtitles.h"
#include <filesystem>
#include <cassert>
int main(int argc, char** argv) {
    if (argc != 2 || std::filesystem::exists(argv[1])) return 2;
    setenv("REO_MACOS_LIVE_SETTINGS", argv[1], 1);
    { std::ofstream out(argv[1]); out << "100,25,50,75,0\n0\n"; }
    {
        reo::ScopedMacRunControl control([] {}, [](const char* audio, const char* subtitles) {
            reo::audio::applyEnvironmentLevels(audio); reo::subtitles::applyEnvironment(subtitles);
        });
        std::this_thread::sleep_for(std::chrono::milliseconds(350));
        assert(reo::audio::gain(reo::audio::Music) == .25f);
        assert(!reo::subtitles::enabled.load());
        { std::ofstream out(std::string(argv[1])+".pending"); out << "10,20,30,40,50\n1\n"; }
        std::filesystem::rename(std::string(argv[1])+".pending", argv[1]);
        std::this_thread::sleep_for(std::chrono::milliseconds(350));
        assert(reo::audio::gain(reo::audio::Master) == .1f);
        assert(reo::subtitles::enabled.load());
    }
    std::filesystem::remove(argv[1]);
    std::puts("PASS native live mixer and subtitle IPC updates");
}
