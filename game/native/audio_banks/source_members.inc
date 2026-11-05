// Source-derived from PS2Recomp ReoSoundBanks.{h,cpp}, qualified124.
// Original dependency GNU GPLv3 license retained: LICENSE-PS2Recomp.
void stop(unsigned port, int slot = -1, bool release = false) {
    for (auto& voice : voices) if (voice.port == port && (slot < 0 || voice.slot == unsigned(slot))) {
        if (release) voice.envelope.release(); else voice.active = false;
    }
    if (!release) for (unsigned i = 0; i < 16; ++i)
        if (slot < 0 || unsigned(slot) == i) ports[port].requests[i].sequence = {};
}
bool matches(const Request& request, unsigned index, unsigned group) {
    return ((index & 128) || request.index == (index & 127)) &&
           ((group & 128) || request.group == (group & 127));
}
void request(unsigned portByte, unsigned indexByte, unsigned groupByte, uint8_t volume, uint8_t pan,
             uint16_t pitch, uint8_t trailer, bool change, bool cancel) {
    const unsigned port = portByte & 127;
    if (port >= ports.size() || !ports[port].loaded) return;
    auto& p = ports[port];
    if (change || cancel) {
        for (unsigned slot = 0; slot < 16; ++slot) {
            auto& r = p.requests[slot];
            const bool selected = cancel ? r.index == (indexByte & 127) && r.group == (groupByte & 127)
                                         : matches(r,indexByte,groupByte);
            if (!r.sequence.active() || !selected) continue;
            if (cancel) {
                // Cancel the scheduler as well as releasing its current notes.
                r.sequence = {};
                stop(port,int(slot),true);
            }
            else { if (volume != 255) r.requestVolume = volume; if (pan != 255) r.requestPan = pan;
                   if (pitch != 65535) r.requestPitch = pitch; }
        }
        return;
    }
    uint32_t offset; uint8_t priority;
    if (!p.asset->bank.sequence(indexByte & 127, offset, priority)) return;
    int available = -1;
    for (int slot = 15; slot >= 0; --slot) {
        auto& r = p.requests[unsigned(slot)];
        if (r.sequence.active() && (((portByte & 128) && (r.cancelFlags & 1)) ||
            ((indexByte & 128) && (r.cancelFlags & 4) && r.index == (indexByte & 127)) ||
            ((groupByte & 128) && (r.cancelFlags & 2) && r.group == (groupByte & 127)))) {
            r.sequence = {};
            stop(port,slot,true);
        }
        if (!r.sequence.active() && available < 0) available = slot;
    }
    if (available < 0) {
        unsigned lowest = priority ? priority - 1 : 0; uint64_t oldest = requestAge;
        for (int slot = 15; slot >= 0; --slot) {
            const auto& r = p.requests[unsigned(slot)];
            if (r.priority <= lowest && r.age <= oldest) { lowest = r.priority; oldest = r.age; available = slot; }
        }
    }
    if (available < 0) return;
    stop(port,available);
    auto& r = p.requests[unsigned(available)]; r = {};
    r.index = indexByte & 127; r.group = groupByte & 127; r.priority = priority;
    r.cancelFlags = uint8_t((portByte >> 7) | ((groupByte >> 7) << 1) | ((indexByte >> 7) << 2));
    r.requestVolume = volume; r.requestPan = pan; r.requestPitch = pitch; r.age = ++requestAge;
    r.sequence.start(p.asset->bank, r.index, trailer);
    if (pathLog) ++pathCounters[port][r.index].requests;
}
double crossfade(unsigned value, unsigned low, unsigned pivot, unsigned high) {
    if (value < pivot && (low & 128) && (low & 127) != pivot)
        return double(int(value) - int(low & 127) + 1) / double(int(pivot) - int(low & 127) + 1);
    if (value >= pivot && (high & 128) && (high & 127) != pivot)
        return double(int(high & 127) + 1 - int(value)) / double(int(high & 127) + 1 - int(pivot));
    return 1;
}
void tickUnlocked() {
    events.clear(); samples.clear();
    for (unsigned port = 0; port < ports.size(); ++port) {
        auto& p = ports[port]; if (!p.loaded) continue;
        for (unsigned slot = 0; slot < 16; ++slot) {
            auto& r = p.requests[slot];
            bool playing = false;
            for (const auto& v : voices) if (v.active && v.port == port && v.slot == slot) { playing = true; break; }
            r.sequence.tick(p.asset->bank, playing, events);
            for (const auto& e : events) {
                switch (e.type) {
                case EventType::Program: r.program = e.value; break;
                case EventType::Volume: r.volume = e.value; break;
                case EventType::Expression: r.expression = e.value; break;
                case EventType::Pan: r.pan = e.value; break;
                case EventType::Pitch: r.pitch = e.value; break;
                case EventType::AllNotesOff: stop(port,int(slot),true); break;
                case EventType::AllSoundOff: stop(port,int(slot)); break;
                case EventType::Note:
                    if (!e.value) {
                        for (auto& v : voices) if (v.active && v.port == port && v.slot == slot && v.note == e.note && v.group == e.group) v.envelope.release();
                    } else if (p.asset->bank.resolve(r.program,e.note,uint8_t(e.value),samples)) {
                        for (const auto& s : samples) {
                            if (s.velocityCurve) { report("velocity-curve",s.velocityCurve); continue; }
                            Voice v; v.asset_serial=p.asset->serial; v.port = port; v.slot = slot; v.note = e.note; v.group = e.group;
                            v.velocity = uint8_t(e.value); v.sample = s; v.envelope.first = s.adsr1; v.envelope.second = s.adsr2;
                            v.data = p.asset->bank.decoded(s);
                            if (!v.data) { report("sample-decode",s.bdOffset); continue; }
                            if (voices.size() >= 48) { report("voice-capacity",48); continue; }
                            voices.push_back(std::move(v));
                        }
                    }
                    break;
                case EventType::Control: report("TQ-control",e.note); break;
                case EventType::Unsupported: report("TQ-opcode",e.value); stop(port,int(slot)); break;
                case EventType::End: break;
                }
            }
        }
    }
}
