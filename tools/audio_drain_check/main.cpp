// Standalone check for runtime patch 0120 (issue #72). Build it against a patched
// PS2Recomp tree, for example with llvm-mingw from a sealed build kit:
//   clang++ -std=c++20 -static -I<sdk>/ps2xRuntime/include -I<sdk>/ps2xRuntime/src/lib
//     -I<sdk>/out/build/_deps/raylib-src/src tools/audio_drain_check/main.cpp
//     <sdk>/ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/CriAudio.cpp <raylib library>
//     -lopengl32 -lgdi32 -lwinmm -luser32 -lshell32
// Without 0120 the paused voice keeps playing the producer's later PCM and this fails.
// A voice the game pauses mid-stream (drain) must stop after the PCM queued at
// the pause, even while its producer keeps queueing more; that PCM waits for a resume.
#include "Kernel/Syscalls/Helpers/CriAudio.h"
#include <cstdio>
#include <vector>
float reoAudioMasterGain() { return 1; }
void reoAudioResetStreams() {}
void reoAudioPoll() {}
float reoAudioStreamGain(uint32_t) { return 1; }
namespace ps2_reo_sound { void reportAudioPaths() {} void reset() {} void mix(float*, unsigned) {} }
namespace ps2_sched { int currentThread() { return 0; } }
static int failures = 0;
static void check(bool ok, const char* why) { std::printf("%s %s\n", ok ? "PASS" : "FAIL", why); failures += !ok; }
static void feed(uint32_t ring, size_t samples) {
    std::vector<int16_t> pcm(samples, 8192); uint64_t end = 0;
    ps2_cri_audio::queue(ring, reinterpret_cast<const uint8_t*>(pcm.data()), uint32_t(pcm.size() * 2), end);
}
static size_t audible(unsigned frames) {
    std::vector<float> out(frames * 2); ps2_cri_audio::render(out.data(), frames);
    size_t n = 0; for (unsigned i = 0; i < frames; ++i) n += out[i * 2] != 0; return n;
}
int main() {
    const uint32_t voice = 0x1e0140, left = 0x1e0000, right = 0x1e0040;
    ps2_cri_audio::render(nullptr, 0); // deterministic external clock
    feed(left, 4800); feed(right, 4800);  // 0.1 s accepted before the pause
    ps2_cri_audio::configure(voice, left, right, 2, 48000, 256, true);
    check(audible(480) == 480, "music audible while playing");
    // The game pauses the voice (SETPSW 0) with 4320 samples still queued.
    ps2_cri_audio::drain(voice);
    ps2_cri_audio::configure(voice, left, right, 2, 48000, 256, false);
    size_t heard = 0;
    for (int block = 0; block < 100; ++block) {  // 2 s of output while the producer keeps decoding
        feed(left, 480); feed(right, 480);
        heard += audible(480);
    }
    std::printf("samples heard after pause: %zu (queued at pause: 4320)\n", heard);
    check(heard == 4320, "paused voice plays only the PCM queued at the pause");
    check(ps2_cri_audio::queuedSamples(left) == 48000, "later producer PCM is kept for a resume");
    ps2_cri_audio::configure(voice, left, right, 2, 48000, 256, true);
    check(audible(480) == 480, "resume continues from the retained PCM");
    ps2_cri_audio::configure(voice, left, right, 2, 48000, 256, false); // silence it for the next case

    // ADXT_Pause on a stream that is still decoding (status PLAYING): the File #1
    // Decisions, Decisions music is started and paused 16 ms later. Hardware stops at
    // once; draining even the queued 0.1 s was an audible blip as the FMV started.
    const uint32_t music = 0x1e0180, musicLeft = 0x1e0080, musicRight = 0x1e00c0;
    feed(musicLeft, 4800); feed(musicRight, 4800);
    ps2_cri_audio::configure(music, musicLeft, musicRight, 2, 48000, 256, true);
    check(audible(480) == 480, "primed music audible before the pause");
    ps2_cri_audio::pauseNow(music, true);
    // Until the PS2RNA stop arrives (~15 ms later) the runtime re-applies the stale
    // "playing" state every tick; the pause must hold through that.
    size_t blip = 0;
    for (int tick = 0; tick < 3; ++tick) {
        ps2_cri_audio::configure(music, musicLeft, musicRight, 2, 48000, 256, true);
        feed(musicLeft, 480); feed(musicRight, 480); blip += audible(480);
    }
    ps2_cri_audio::drain(music); // the stop command: must not drain this pause
    ps2_cri_audio::configure(music, musicLeft, musicRight, 2, 48000, 256, false);
    for (int block = 0; block < 10; ++block) { feed(musicLeft, 480); feed(musicRight, 480); blip += audible(480); }
    std::printf("samples heard after a mid-stream pause: %zu\n", blip);
    check(blip == 0, "mid-stream pause stops at once and holds until the stop command");
    ps2_cri_audio::configure(music, musicLeft, musicRight, 2, 48000, 256, true);
    check(audible(480) == 480, "mid-stream pause keeps its PCM for the resume");
    return failures ? 1 : 0;
}
