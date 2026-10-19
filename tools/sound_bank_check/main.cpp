#include "ReoSoundBanks.h"
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <stdexcept>
#include <vector>

using namespace ps2_reo_sound;
static std::vector<uint8_t> read(const std::filesystem::path& path) {
    std::ifstream stream(path, std::ios::binary);
    if (!stream)
        throw std::runtime_error("Missing capture: " + path.string());
    return {std::istreambuf_iterator<char>(stream), std::istreambuf_iterator<char>()};
}
static void require(bool ok, const char* message) {
    if (!ok)
        throw std::runtime_error(message);
}
int main(int argc, char** argv) {
    try {
        require(argc == 2 || argc == 3,
                "Usage: sound_bank_check.exe <completed sound capture> [Kevin-confirm capture]");
        const std::filesystem::path capture(argv[1]);
        auto hd = read(capture / "sound-bank-00-hd.bin"),
             bd = read(capture / "sound-bank-00-bd.bin"),
             tq = read(capture / "sound-bank-00-tq.bin");
        Bank bank;
        require(bank.load(hd.data(), hd.size(), bd.data(), bd.size(), tq.data(), tq.size()),
                "Original menu bank rejected");
        require(bank.sequenceCount() == 128, "Original TQ sequence count differs");
        uint32_t offset = 0;
        uint8_t priority = 255;
        require(bank.sequence(2, offset, priority) && offset == 0x230 && priority == 0,
                "Original sequence entry differs");
        std::vector<Sample> samples;
        require(bank.resolve(0, 62, 127, samples) && samples.size() == 1,
                "Menu sequence 2 does not resolve through original bank");
        require(samples[0].bdOffset == 0xFF0 && samples[0].sampleRate == 16000 &&
                    samples[0].rootNote == 62,
                "Original sample metadata differs");
        DecodedSample decoded;
        require(bank.decode(samples[0], decoded) && !decoded.pcm.empty(),
                "Menu ADPCM decode failed");
        Sequence seq;
        std::vector<Event> events;
        require(seq.start(bank, 2, 0) && seq.tick(bank, false, events),
                "Original sequence start failed");
        require(events.size() == 3 && events[0].type == EventType::Volume &&
                    events[1].type == EventType::Program && events[2].type == EventType::Note &&
                    events[2].note == 62 && events[2].value == 127,
                "Original TQ event order differs");
        require(seq.tick(bank, true, events) && events.empty(),
                "FE00 must wait for original voice completion");
        (void)seq.tick(bank, false, events);
        require(seq.active() && !events.empty() && events.front().type == EventType::Note &&
                    events.front().value == 0,
                "Original note-off not reached");
        (void)seq.tick(bank, false, events);
        require(!seq.active(), "Original FF must end on the tick after note-off");

        auto packet = read(capture / "sound-packet-002.bin");
        auto render = [&](bool partitioned) {
            reset();
            require(submitBank(0, hd.data(), hd.size(), bd.data(), bd.size(), tq.data(), tq.size()),
                    "Submit menu bank failed");
            require(submitPacket(nullptr, 0, packet.data(), packet.size()),
                    "Captured 9-byte SE request rejected");
            require(seState(0, 2, 1) == 1, "Original SE query must report active sequence");
            std::vector<float> pcm(48000 * 2, 0.f);
            if (partitioned) {
                unsigned at = 0;
                for (; at < 48000;) {
                    const unsigned n = std::min(137u, 48000 - at);
                    mix(pcm.data() + at * 2, n);
                    at += n;
                }
            } else
                mix(pcm.data(), 48000);
            require(seState(0, 2, 1) == 0, "Completed one-shot query stays active");
            return pcm;
        };
        auto whole = render(false), split = render(true);
        require(whole == split, "Output depends on callback partitioning");
        double energy = 0;
        float peak = 0;
        size_t nonzero = 0;
        for (float value : whole) {
            require(std::isfinite(value), "Nonfinite mixer sample");
            energy += value * value;
            peak = std::max(peak, std::abs(value));
            if (value != 0)
                ++nonzero;
        }
        require(nonzero > 100 && peak > 0 && peak <= 1,
                "Menu one-shot output is silent or clipped");
        require(!submitPacket(nullptr, 0, packet.data(), 4), "Truncated SE command accepted");
        std::vector<uint8_t> corrupt = hd;
        corrupt[0] = 0;
        Bank invalid;
        require(!invalid.load(corrupt.data(), corrupt.size(), bd.data(), bd.size(), tq.data(),
                              tq.size()),
                "Bad bank tag accepted");

        auto voiceHd = read(capture / "sound-bank-02-hd.bin"),
             voiceBd = read(capture / "sound-bank-02-bd.bin"),
             voiceTq = read(capture / "sound-bank-02-tq.bin");
        require(bank.load(voiceHd.data(), voiceHd.size(), voiceBd.data(), voiceBd.size(),
                          voiceTq.data(), voiceTq.size()),
                "Character bank rejected");
        require(bank.resolve(0, 92, 127, samples) && samples.size() == 2 &&
                    samples[0].sampleRate == 22050 && samples[1].sampleRate == 22050 &&
                    samples[0].basePan == 0 && samples[1].basePan == 127,
                "Original stereo character sequence 32 metadata differs");
        require(bank.decode(samples[0], decoded), "Character voice ADPCM decode failed");
        const size_t characterFrames = decoded.pcm.size();
        reset();
        require(submitBank(12, voiceHd.data(), voiceHd.size(), voiceBd.data(), voiceBd.size(),
                           voiceTq.data(), voiceTq.size()),
                "Submit character bank failed");
        auto characterPacket = read(capture / "sound-packet-008.bin");
        require(submitPacket(nullptr, 0, characterPacket.data(), characterPacket.size()),
                "Captured character voice request rejected");
        std::vector<float> characterPcm(48000 * 5 * 2, 0.f);
        mix(characterPcm.data(), 48000 * 5);
        double charEnergy = 0;
        float charPeak = 0;
        size_t stereoDifferences = 0;
        for (size_t i = 0; i < characterPcm.size(); i += 2) {
            charEnergy +=
                characterPcm[i] * characterPcm[i] + characterPcm[i + 1] * characterPcm[i + 1];
            charPeak =
                std::max({charPeak, std::abs(characterPcm[i]), std::abs(characterPcm[i + 1])});
            if (characterPcm[i] != characterPcm[i + 1])
                ++stereoDifferences;
        }
        require(charEnergy > 0 && charPeak <= 1 && stereoDifferences > 100,
                "Original stereo voice silent, collapsed or clipped");
        require(seState(12, 32, 3) == 0, "Completed bank12 stereo speech stays active");
        if (argc == 3) {
            const std::filesystem::path kevinCapture(argv[2]);
            auto kevinHd = read(kevinCapture / "sound-bank-02-hd.bin"),
                 kevinBd = read(kevinCapture / "sound-bank-02-bd.bin"),
                 kevinTq = read(kevinCapture / "sound-bank-02-tq.bin"),
                 kevinPacket = read(kevinCapture / "sound-packet-012.bin");
            const std::vector<uint8_t> expectedRequest{0x07, 0x0c, 0x08, 0x80, 0x7f,
                                                       0x40, 0x20, 0x00, 0x00, 0xff};
            require(
                kevinPacket.size() >= expectedRequest.size() &&
                    std::equal(expectedRequest.begin(), expectedRequest.end(), kevinPacket.begin()),
                "Fixture is not the actual Kevin confirmation request");
            require(bank.load(kevinHd.data(), kevinHd.size(), kevinBd.data(), kevinBd.size(),
                              kevinTq.data(), kevinTq.size()),
                    "Kevin bank rejected");
            require(bank.sequence(8, offset, priority) && offset == 0x290 && priority == 0,
                    "Kevin TQ sequence entry differs");
            require(seq.start(bank, 8, 0) && seq.tick(bank, false, events) && events.size() == 3 &&
                        events[2].type == EventType::Note && events[2].note == 68 &&
                        events[2].value == 127,
                    "Kevin TQ note differs from original");
            require(bank.resolve(0, 68, 127, samples) && samples.size() == 2,
                    "Kevin confirmation must resolve both original layers");
            require(samples[0].bdOffset == 0x1a650 && samples[1].bdOffset == 0x45480 &&
                        samples[0].sampleRate == 22050 && samples[1].sampleRate == 22050 &&
                        samples[0].basePan == 64 && samples[1].basePan == 64,
                    "Kevin sample metadata differs");
            require(bank.decode(samples[0], decoded) && decoded.pcm.size() == 9380,
                    "Kevin name sample extent differs");
            require(bank.decode(samples[1], decoded) && decoded.pcm.size() == 30604,
                    "Kevin shared confirmation sample extent differs");
            auto renderKevin = [&](bool partitioned) {
                reset();
                require(submitBank(12, kevinHd.data(), kevinHd.size(), kevinBd.data(),
                                   kevinBd.size(), kevinTq.data(), kevinTq.size()),
                        "Submit Kevin bank failed");
                require(submitPacket(nullptr, 0, kevinPacket.data(), kevinPacket.size()),
                        "Actual Kevin confirmation packet rejected");
                require(seState(12, 8, 0) == 1, "Kevin confirmation query must report active");
                std::vector<float> pcm(48000 * 2 * 2, 0.f);
                mix(pcm.data(), kFramesPerTick);
                require(seState(12, 8, 0) == 1,
                        "Kevin confirmation ended before original samples played");
                if (partitioned) {
                    for (unsigned at = kFramesPerTick; at < 48000 * 2;) {
                        const unsigned n = std::min(137u, 48000 * 2 - at);
                        mix(pcm.data() + at * 2, n);
                        at += n;
                    }
                } else
                    mix(pcm.data() + kFramesPerTick * 2, 48000 * 2 - kFramesPerTick);
                require(seState(12, 8, 0) == 0,
                        "Kevin confirmation query stays active after completion");
                return pcm;
            };
            const auto kevinPcm = renderKevin(false), kevinSplit = renderKevin(true);
            require(kevinPcm == kevinSplit, "Kevin output depends on callback partitioning");
            double kevinEnergy = 0;
            float kevinPeak = 0;
            size_t kevinNonzero = 0;
            for (size_t i = 0; i < kevinPcm.size(); i += 2) {
                require(std::isfinite(kevinPcm[i]) && std::isfinite(kevinPcm[i + 1]),
                        "Nonfinite Kevin output");
                require(kevinPcm[i] == kevinPcm[i + 1],
                        "Original centered Kevin layers differ between output channels");
                kevinEnergy += kevinPcm[i] * kevinPcm[i] + kevinPcm[i + 1] * kevinPcm[i + 1];
                kevinPeak = std::max(kevinPeak, std::abs(kevinPcm[i]));
                if (kevinPcm[i] != 0)
                    ++kevinNonzero;
            }
            require(kevinNonzero > 1000 && kevinPeak > 0 && kevinPeak <= 1,
                    "Kevin confirmation output is silent or clipped");
            std::printf("PASS actual Kevin confirmation packet012/port12/seq8/group0; two original "
                        "layers, query active/completed, callback partitioning, centered output "
                        "peak=%.6f rms=%.6f nonzero_frames=%zu\n",
                        kevinPeak, std::sqrt(kevinEnergy / kevinPcm.size()), kevinNonzero);
        }
        std::printf("PASS menu + bank12 stereo speech PCM, original metadata, TQ/FE00 semantics, "
                    "malformed input, callback partitioning; menu peak=%.6f rms=%.6f nonzero=%zu "
                    "speech_frames=%zu peak=%.6f rms=%.6f stereo_differences=%zu\n",
                    peak, std::sqrt(energy / whole.size()), nonzero, characterFrames, charPeak,
                    std::sqrt(charEnergy / characterPcm.size()), stereoDifferences);
        return 0;
    } catch (const std::exception& e) {
        std::fprintf(stderr, "FAIL: %s\n", e.what());
        return 1;
    }
}
