#pragma once
// Diagnostic model only: never supplies colors to the rasterizer.
#include <array>
#include <cstdint>

namespace clut_shadow {
struct Tex {
    uint32_t cbp = 0;
    uint8_t psm = 0, cpsm = 0, csm = 0, csa = 0, cld = 0;
};
struct Origin {
    uint8_t cbw = 0, cou = 0;
    uint16_t cov = 0;
};
struct Raw {
    uint32_t value = 0, offset = 0;
    bool valid = false;
};
enum class Reason : unsigned {
    None,
    NoLoad,
    UnsupportedIndex,
    ReservedCld,
    UnknownCbp,
    UnsupportedFormat,
    InvalidCsa,
    UnsupportedCsm2,
    T8Offset,
    SourceUnavailable,
    UnknownEntry,
    CsmReinterpretation
};
struct Event {
    bool permitted = false, loaded = false;
    Reason reason = Reason::None;
    uint64_t serial = 0, generation = 0;
};
struct Selection {
    Raw raw;
    Reason reason = Reason::None;
    uint64_t loadSerial = 0;
    uint32_t sourceOffset = 0;
};
struct Primitive {
    Tex tex;
    Origin origin;
    uint64_t test = 0, zbuf = 0, clamp = 0, alpha = 0;
    uint32_t fbp = 0, fbw = 0, fbmsk = 0;
    uint16_t ofx = 0, ofy = 0;
    uint8_t context = 0, type = 0, framePsm = 0, tcc = 0, tfx = 0, ta0 = 0, ta1 = 0, aem = 0;
    unsigned vertices = 0;
    std::array<float, 3> x{}, y{};
};
inline bool indexed(uint8_t psm) {
    return psm == 0x13 || psm == 0x14 || psm == 0x1b || psm == 0x24 || psm == 0x2c;
}
inline bool four(uint8_t psm) {
    return psm == 0x14 || psm == 0x24 || psm == 0x2c;
}
inline bool wide(uint8_t cpsm) {
    return cpsm == 0;
}
inline unsigned entries(const Tex& t) {
    return four(t.psm) ? 16 : 256;
}
inline uint32_t swap38(uint32_t i) {
    return (i & ~0x18u) | ((i & 8) << 1) | ((i & 16) >> 1);
}

class Shadow {
    std::array<uint16_t, 512> words_{};
    std::array<bool, 512> known_{};
    std::array<uint64_t, 512> loads_{};
    std::array<uint32_t, 512> offsets_{};
    std::array<uint8_t, 512> csms_{};
    std::array<uint32_t, 2> cbps_{};
    std::array<bool, 2> cbpKnown_{};
    uint64_t serial_ = 0, generation_ = 0;
    Reason lastReason_ = Reason::UnknownEntry;

  public:
    void reset() {
        *this = Shadow{};
    }
    uint64_t generation() const {
        return generation_;
    }
    uint64_t serial() const {
        return serial_;
    }
    const auto& words() const {
        return words_;
    }
    const auto& known() const {
        return known_;
    }
    const auto& loadSerials() const {
        return loads_;
    }
    const auto& sourceOffsets() const {
        return offsets_;
    }
    const auto& loadCsms() const {
        return csms_;
    }
    const auto& cbps() const {
        return cbps_;
    }
    const auto& cbpKnown() const {
        return cbpKnown_;
    }
    Reason lastReason() const {
        return lastReason_;
    }
    static Reason supported(const Tex& t, const Origin& o) {
        if (!indexed(t.psm))
            return Reason::UnsupportedIndex;
        // CT24 and CSM2 CT32/16S are observed emulator extensions, not the
        // documented GS combinations implemented by this diagnostic.
        if (t.cpsm != 0 && t.cpsm != 2 && t.cpsm != 10)
            return Reason::UnsupportedFormat;
        if (t.csa > (wide(t.cpsm) ? 15 : 31))
            return Reason::InvalidCsa;
        if (t.csm && (t.cpsm != 2 || t.csa || !o.cbw))
            return Reason::UnsupportedCsm2;
        // PCSX2/Play! differ on historical I8 offsets; do not synthesize an
        // answer for nonzero CSA T8 partial-load/read clamping.
        if (!four(t.psm) && t.csa)
            return Reason::T8Offset;
        return Reason::None;
    }
    template <class Reader> Event load(const Tex& t, const Origin& o, Reader&& reader) {
        Event e;
        e.serial = ++serial_;
        e.generation = generation_;
        if (!indexed(t.psm)) {
            e.reason = Reason::UnsupportedIndex;
            return e;
        }
        if (t.cld == 0) {
            e.reason = Reason::NoLoad;
            return e;
        }
        if (t.cld >= 6) {
            known_.fill(false);
            cbpKnown_.fill(false);
            e.reason = lastReason_ = Reason::ReservedCld;
            return e;
        }
        if (t.cld == 4 || t.cld == 5) {
            const unsigned n = t.cld - 4;
            if (!cbpKnown_[n]) {
                // Unknown power-on/reset register state: not guessed zero.
                cbps_[n] = t.cbp;
                cbpKnown_[n] = true;
                known_.fill(false);
                e.reason = lastReason_ = Reason::UnknownCbp;
                return e;
            }
            if (cbps_[n] == t.cbp) {
                e.reason = Reason::NoLoad;
                return e;
            }
        }
        if (t.cld >= 2) {
            unsigned n = t.cld == 2 || t.cld == 4 ? 0 : 1;
            cbps_[n] = t.cbp;
            cbpKnown_[n] = true;
        }
        e.permitted = true;
        if (auto why = supported(t, o); why != Reason::None) {
            // Undefined/unsupported destination can overlap any old bank.
            known_.fill(false);
            e.reason = lastReason_ = why;
            return e;
        }
        const unsigned count = entries(t), base = t.csa * 16;
        ++generation_;
        e.generation = generation_;
        e.loaded = true;
        for (unsigned i = 0; i < count; ++i) {
            unsigned x, y, width;
            if (t.csm) {
                x = unsigned(o.cou) * 16 + i;
                y = o.cov;
                width = o.cbw;
            } else if (count == 16) {
                x = i & 7;
                y = i >> 3;
                width = 1;
            } else {
                auto si = swap38(i);
                x = si & 15;
                y = si >> 4;
                width = 1;
            }
            const Raw raw = reader(t.cpsm, t.cbp, width, x, y);
            const unsigned n = base + i;
            words_[n] = uint16_t(raw.value);
            known_[n] = raw.valid;
            loads_[n] = e.serial;
            offsets_[n] = raw.offset;
            csms_[n] = t.csm;
            if (wide(t.cpsm)) {
                words_[n + 256] = uint16_t(raw.value >> 16);
                known_[n + 256] = raw.valid;
                loads_[n + 256] = e.serial;
                offsets_[n + 256] = raw.offset;
                csms_[n + 256] = t.csm;
            }
            if (!raw.valid)
                e.reason = Reason::SourceUnavailable;
        }
        lastReason_ = e.reason;
        return e;
    }
    Selection select(const Tex& t, const Origin& o, unsigned index) const {
        Selection s;
        if (auto why = supported(t, o); why != Reason::None) {
            s.reason = why;
            return s;
        }
        unsigned n = t.csa * 16 + (four(t.psm) ? index & 15 : index & 255);
        if (!known_[n] || (wide(t.cpsm) && !known_[n + 256])) {
            s.reason = Reason::UnknownEntry;
            return s;
        }
        if (csms_[n] != t.csm || (wide(t.cpsm) && csms_[n + 256] != t.csm)) {
            s.reason = Reason::CsmReinterpretation;
            return s;
        }
        s.raw = {words_[n], offsets_[n], true};
        if (wide(t.cpsm))
            s.raw.value |= uint32_t(words_[n + 256]) << 16;
        s.loadSerial = loads_[n];
        s.sourceOffset = offsets_[n];
        return s;
    }
    // This is explicitly our CURRENT renderer's source selection, not hardware.
    template <class Reader>
    static Raw live(const Tex& t, const Origin& o, unsigned index, Reader&& reader) {
        unsigned ci = index;
        if (t.psm == 0x14) {
            ci = t.csa * 16 + (index & 15);
            if (!t.csm)
                ci = (ci & 0xe7) | ((ci & 8) << 1) | ((ci & 16) >> 1);
        } else if (t.psm == 0x13 && !t.csm)
            ci = (ci & 0xe7) | ((ci & 8) << 1) | ((ci & 16) >> 1);
        return reader(t.cpsm, t.cbp, o.cbw ? o.cbw : 1, unsigned(o.cou) + (ci & 15),
                      unsigned(o.cov) + (ci >> 4));
    }
};
} // namespace clut_shadow
