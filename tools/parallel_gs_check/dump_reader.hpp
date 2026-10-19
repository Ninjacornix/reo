// Bounded adapter for PCSX2 frozen GS dump v8/v9.
// State field ordering follows pinned parallel-gs/dump/gs_dump_parser.cpp.
// Unlike that parser, this executes ReadFIFO and validates every byte range.
struct DumpReader {
    const std::vector<uint8_t>& bytes;
    size_t pos = 0;
    void copy(void* out, size_t length) {
        if (pos > bytes.size() || length > bytes.size() - pos)
            throw std::runtime_error("Truncated GS dump");
        if (length)
            std::memcpy(out, bytes.data() + pos, length);
        pos += length;
    }
    void skip(size_t length) {
        if (pos > bytes.size() || length > bytes.size() - pos)
            throw std::runtime_error("Truncated GS dump skip");
        pos += length;
    }
    template <class T> T value() {
        T out = {};
        copy(&out, sizeof(out));
        return out;
    }
    template <class T> void reg(T& out) {
        out.bits = value<uint64_t>();
    }
};
struct DumpStats {
    uint64_t packets = 0, packetBytes = 0, frames = 0, fifoReads = 0;
    unsigned lastPhase = 0;
};
struct DumpRecord {
    uint8_t kind = 0;
    unsigned pathOrPhase = 0;
    uint32_t qwc = 0;
    std::vector<uint64_t> payload; // Packet alignment is preserved independently of file offsets.
};
struct ParsedDump {
    RegisterState registers = {};
    GIFPath paths[4] = {};
    PrivRegisterState privileged = {};
    std::vector<uint8_t> vram;
    std::vector<DumpRecord> records;
    DumpStats stats;
};
static ParsedDump parseDump(const std::vector<uint8_t>& bytes) {
    ParsedDump parsed;
    DumpReader r{bytes};
    if (r.value<uint32_t>() != UINT32_MAX)
        throw std::runtime_error("Only new-header GS dumps v8/v9 are supported");
    const uint32_t headerSize = r.value<uint32_t>();
    const size_t headerBegin = r.pos;
    if (headerSize < 36 || headerSize > 16u * 1024u * 1024u)
        throw std::runtime_error("Invalid GS dump header size");
    const uint32_t version = r.value<uint32_t>(), stateSize = r.value<uint32_t>();
    const uint32_t serialOffset = r.value<uint32_t>(), serialSize = r.value<uint32_t>();
    r.skip(12); // CRC, screenshot width/height.
    const uint32_t screenshotOffset = r.value<uint32_t>(), screenshotSize = r.value<uint32_t>();
    const auto range = [headerSize](uint32_t offset, uint32_t size) {
        return offset <= headerSize && size <= headerSize - offset;
    };
    if (!range(serialOffset, serialSize) || !range(screenshotOffset, screenshotSize))
        throw std::runtime_error("Header subrange outside GS dump blob");
    if (version != 8 && version != 9)
        throw std::runtime_error("Unsupported GS frozen state version");
    if (stateSize != 364u + vramSize + 84u + (version == 9 ? 61u : 0u))
        throw std::runtime_error("Unexpected frozen state size");
    r.skip(headerSize - (r.pos - headerBegin));
    const size_t stateBegin = r.pos;
    if (r.value<uint32_t>() != version)
        throw std::runtime_error("Embedded/header state versions disagree");
    auto& s = parsed.registers;
    r.reg(s.prim);
    r.reg(s.prmodecont);
    r.reg(s.texclut);
    r.reg(s.scanmsk);
    r.reg(s.texa);
    r.reg(s.fogcol);
    r.reg(s.dimx);
    r.reg(s.dthe);
    r.reg(s.colclamp);
    r.reg(s.pabe);
    r.reg(s.bitbltbuf);
    r.reg(s.trxdir);
    r.reg(s.trxpos);
    r.reg(s.trxreg);
    r.skip(8);
    for (auto& c : s.ctx) {
        r.reg(c.xyoffset);
        r.reg(c.tex0);
        r.reg(c.tex1);
        r.reg(c.clamp);
        r.reg(c.miptbl_1_3);
        r.reg(c.miptbl_4_6);
        r.reg(c.scissor);
        r.reg(c.alpha);
        r.reg(c.test);
        r.reg(c.fba);
        r.reg(c.frame);
        r.reg(c.zbuf);
    }
    r.reg(s.rgbaq);
    r.reg(s.st);
    s.uv.words[0] = r.value<uint32_t>();
    s.fog.words[0] = r.value<uint32_t>();
    r.skip(8 + 16); // XYZ, GIFReg, transfer X/Y.
    if (version == 9)
        r.skip(61);
    if (r.pos - stateBegin != 364u + (version == 9 ? 61u : 0u))
        throw std::runtime_error("Frozen prefix layout mismatch");
    parsed.vram.resize(vramSize);
    r.copy(parsed.vram.data(), vramSize);
    for (unsigned path = 0; path < 4; ++path) {
        auto& p = parsed.paths[path];
        r.copy(&p.tag, sizeof(p.tag));
        p.reg = r.value<uint32_t>();
        p.loop = 0;
        if (p.reg >= (p.tag.NREG ? p.tag.NREG : 16))
            throw std::runtime_error("Invalid frozen GIF cursor");
    }
    s.internal_q = r.value<float>();
    if (r.pos - stateBegin != stateSize)
        throw std::runtime_error("Frozen state trailer layout mismatch");
    static_assert(sizeof(PrivRegisterState) == 8192, "Privileged GS register layout changed");
    r.copy(&parsed.privileged, sizeof(PrivRegisterState));
    auto& stats = parsed.stats;
    while (r.pos < bytes.size()) {
        // Bound allocation even for a malicious sequence of one-byte markers.
        if (parsed.records.size() >= 1024u * 1024u)
            throw std::runtime_error("GS dump record count limit");
        DumpRecord record;
        record.kind = r.value<uint8_t>();
        switch (record.kind) {
            case 0: {
                const unsigned path = r.value<uint8_t>();
                const uint32_t size = r.value<uint32_t>();
                if (path > 3 || size % 16 || size > 64u * 1024u * 1024u)
                    throw std::runtime_error("Invalid GIF dump transfer");
                record.pathOrPhase = path;
                record.payload.resize(size / 8);
                r.copy(record.payload.data(), size);
                ++stats.packets;
                stats.packetBytes += size;
                break;
            }
            case 1: {
                stats.lastPhase = r.value<uint8_t>();
                if (stats.lastPhase > 1)
                    throw std::runtime_error("Invalid dump field phase");
                record.pathOrPhase = stats.lastPhase;
                ++stats.frames;
                break;
            }
            case 2: {
                const uint32_t qwc = r.value<uint32_t>();
                if (qwc > 1024u * 1024u)
                    throw std::runtime_error("FIFO read size limit");
                record.qwc = qwc;
                ++stats.fifoReads;
                break;
            }
            case 3:
                record.payload.resize(sizeof(PrivRegisterState) / 8);
                r.copy(record.payload.data(), sizeof(PrivRegisterState));
                break;
            default:
                throw std::runtime_error("Unknown GS dump record");
        }
        parsed.records.push_back(std::move(record));
    }
    return parsed;
}
static void restoreDump(GSInterface& gs, const ParsedDump& parsed) {
    gs.reset_context_state();
    gs.get_register_state() = parsed.registers;
    std::memcpy(gs.map_vram_write(0, vramSize), parsed.vram.data(), vramSize);
    gs.end_vram_write(0, vramSize);
    gs.write_register(RegisterAddr::TEXFLUSH, uint64_t(0));
    for (unsigned path = 0; path < 4; ++path)
        gs.get_gif_path(path) = parsed.paths[path];
    gs.get_priv_register_state() = parsed.privileged;
    gs.clobber_register_state();
}
template <class VSyncObserver>
static ScanoutResult enqueueDump(GSInterface& gs, const ParsedDump& parsed,
                                 VSyncObserver observer) {
    ScanoutResult lastImage{};
    unsigned frameIndex = 0;
    size_t recordIndex = 0;
    for (const auto& record : parsed.records) {
        switch (record.kind) {
            case 0:
                gs.gif_transfer(record.pathOrPhase, record.payload.data(),
                                record.payload.size() * 8);
                break;
            case 1:
                lastImage = scanout(gs, record.pathOrPhase);
                observer(frameIndex++, recordIndex, record.pathOrPhase, lastImage);
                break;
            case 2: {
                std::vector<uint64_t> fifo(size_t(record.qwc) * 2);
                gs.read_transfer_fifo(fifo.data(), record.qwc);
                break;
            }
            case 3:
                std::memcpy(&gs.get_priv_register_state(), record.payload.data(),
                            sizeof(PrivRegisterState));
                break;
            default:
                throw std::runtime_error("Invalid parsed GS dump record");
        }
        ++recordIndex;
    }
    return lastImage;
}
