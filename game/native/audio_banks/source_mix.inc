// Source-derived from PS2Recomp ReoSoundBanks.{h,cpp}, qualified124.
// Original dependency GNU GPLv3 license retained: LICENSE-PS2Recomp.


    for (unsigned frame = 0; frame < frames; ++frame, ++frameClock) {
        if (frameClock % kFramesPerTick == 0) tickUnlocked();
        for (auto& v : voices) {
            if (!v.active || !v.data || v.data->pcm.empty()) continue;
            const auto& data = *v.data;
            if (v.position >= data.pcm.size()) {
                if (data.hasLoop && data.loopStart < data.pcm.size())
                    v.position = data.loopStart + std::fmod(v.position - data.loopStart, double(data.pcm.size() - data.loopStart));
                else { v.active = false; continue; }
            }
            const auto& p = ports[v.port]; const auto& r = p.requests[v.slot]; const auto& s = v.sample;
            const int bend = std::clamp(int(r.pitch) + int(r.requestPitch) - 0x4000, -8192, 8191);
            if (bend != v.cachedBend) {
                const double bendFine = double(bend) * (bend < 0 ? s.bendDown : s.bendUp) / 8192.;
                const double semitones = int(v.note) + s.programTranspose + s.regionTranspose - int(s.rootNote) +
                    (s.programFine + s.regionFine + s.sampleFine + bendFine) / 128.;
                const double pitch_value=std::max(0.,std::floor(4096. * s.sampleRate / kOutputRate * std::exp2(semitones / 12.)));
                if(!std::isfinite(pitch_value)||pitch_value>double(UINT32_MAX))return numeric_failure();
                const unsigned pitch = std::min(0x3FFFu, unsigned(pitch_value));
                v.step = double(pitch) / 4096.; v.cachedBend = bend;
            }
            const size_t index = size_t(v.position);
            const size_t next = index + 1 < data.pcm.size() ? index + 1 : data.hasLoop ? data.loopStart : index;
            const double fraction = v.position - index;
            const double pcm = data.pcm[index] + (data.pcm[next] - data.pcm[index]) * fraction;
            double amplitude = double(s.programVolume) * s.regionVolume * s.sampleVolume * v.velocity / 16384.;
            amplitude *= crossfade(v.note,s.regionLow,s.regionCenter,s.regionHigh) * crossfade(v.velocity,s.velocityLow,s.velocityCenter,s.velocityHigh);
            const unsigned channelVolume = std::min(127u,r.volume * r.requestVolume / 127) * 128 / 127;
            const unsigned expression = std::min(127u,r.expression) * 128 / 127;
            amplitude = std::floor(amplitude * channelVolume * expression / 16384.);
            amplitude = std::min(16383.,std::floor(amplitude * p.volume / 256.));
            const float envelope = v.envelope.advance();
            if (v.envelope.phase == Envelope::Off) { v.active = false; continue; }
            const int pan = mono ? 64 : std::clamp(s.basePan + int(r.pan) + int(r.requestPan) - 128,0,127);
            const double left = pan > 64 ? double(127 - pan) / 63 : 1;
            const double right = pan < 64 ? double(std::max(pan - 1,0)) / 63 : 1;
            if (!muted) { stereo[frame * 2] += float(pcm / 32768. * amplitude / 16384. * envelope * left * gains[v.port][v.slot]);
                          stereo[frame * 2 + 1] += float(pcm / 32768. * amplitude / 16384. * envelope * right * gains[v.port][v.slot]); }
            if (pathLog) {
                auto& counters=pathCounters[v.port][r.index];
                ++counters.activeVoiceFrames;
                counters.signalVoiceFrames += !muted && pcm != 0 && amplitude != 0 && envelope != 0 && (left != 0 || right != 0);
            }
            v.position += v.step;
        }
        if (frameClock % kFramesPerTick == kFramesPerTick - 1) reclaim_inactive();
    }
