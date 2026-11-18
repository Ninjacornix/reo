// Source-derived from PS2Recomp ReoSoundBanks.{h,cpp}, qualified124.
// Original dependency GNU GPLv3 license retained: LICENSE-PS2Recomp.
struct Envelope {
    enum Phase { Attack, Decay, Sustain, Release, Off } phase = Attack;
    int value = 0;
    uint32_t countdown = 0;
    uint16_t first = 0, second = 0;
    void release() { phase = Release; countdown = 0; }
    float advance() {
        if (phase == Off) return 0;
        if (countdown) { --countdown; return float(value) / 32768.f; }
        unsigned rate = 0; bool decreasing = false, exponential = false;
        if (phase == Attack) { rate = (first >> 8) & 127; exponential = (first & 0x8000) != 0; }
        else if (phase == Decay) { rate = ((first >> 4) & 15) * 4; decreasing = exponential = true; }
        else if (phase == Sustain) {
            rate = (second >> 6) & 127; decreasing = (second & 0x4000) != 0; exponential = (second & 0x8000) != 0;
        } else { rate = (second & 31) * 4; decreasing = true; exponential = (second & 32) != 0; }
        if (rate == 127) return float(value) / 32768.f;
        const unsigned shift = rate >> 2;
        int step = decreasing ? -8 + int(rate & 3) : 7 - int(rate & 3);
        uint32_t cycles = 1u << (shift > 11 ? shift - 11 : 0);
        if (shift < 11) step *= 1 << (11 - shift);
        if (exponential && decreasing) step = (step * value) >> 15;
        else if (exponential && value > 0x6000) cycles *= 4;
        value = std::clamp(value + step, 0, 32767); countdown = cycles - 1;
        if (phase == Attack && value == 32767) { phase = Decay; countdown = 0; }
        else if (phase == Decay && value <= int((first & 15) + 1) * 0x800) { phase = Sustain; countdown = 0; }
        else if (phase == Release && value == 0) phase = Off;
        return float(value) / 32768.f;
    }
};
struct Voice {
    unsigned port = 0, slot = 0;
    uint8_t note = 0, group = 0, velocity = 0;
    Sample sample;
    std::uint64_t asset_serial{};
    std::shared_ptr<const DecodedSample> data;
    double position = 0;
    double step = 0;
    int cachedBend = 32768;
    Envelope envelope;
    bool active = true;
};
struct Request {
    Sequence sequence;
    uint8_t index = 0, group = 0, priority = 0, cancelFlags = 0;
    uint8_t requestVolume = 127, requestPan = 64;
    uint16_t requestPitch = 0x2000, pitch = 0x2000;
    unsigned program = 0, volume = 127, expression = 127, pan = 64;
    uint64_t age = 0;
};
struct Port { uint64_t fingerprint=0; std::shared_ptr<const AssetData> asset; bool loaded = false; unsigned volume = 256; std::array<Request,16> requests; };
