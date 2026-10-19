// Only arithmetic operands capable of affecting a written lane are admitted.
// The 2^59 magnitude bound makes every upper float product/sum finite; integer
// bit copies (ITOF/LQ/SQ/MFIR/MFP) are not numeric floating-point operations.
VU_BLOCK_INLINE bool vuBlockNumber(float value) {
    uint32_t bits;
    std::memcpy(&bits, &value, 4);
    return (bits & 0x7FFFFFFFu) <= 0x5D000000u;
}
VU_BLOCK_INLINE bool vuBlockLanes(const float* values, unsigned mask) {
    for (unsigned c = 0; c < 4; ++c)
        if ((mask & (8u >> c)) && !vuBlockNumber(values[c]))
            return false;
    return true;
}
template <uint32_t hi> VU_BLOCK_INLINE bool vuBlockUpperSafe(const VU1State& s) {
    constexpr unsigned op = hi & 63u, fs = (hi >> 11) & 31u, ft = (hi >> 16) & 31u,
                       dest = (hi >> 21) & 15u;
    const float* a = s.vf[fs];
    const float* b = s.vf[ft];
    if constexpr (op < 0x1Cu)
        return !dest || (vuBlockLanes(a, dest) && vuBlockNumber(b[op & 3u]) &&
                         ((op >= 8u && op < 16u) ? vuBlockLanes(s.acc, dest) : true));
    else if constexpr (op >= 0x1Cu && op <= 0x27u) {
        constexpr bool useQ =
            op == 0x1Cu || op == 0x20u || op == 0x21u || op == 0x24u || op == 0x25u;
        constexpr bool acc = op == 0x21u || op == 0x23u || op == 0x25u || op == 0x27u;
        return !dest || (vuBlockLanes(a, dest) && vuBlockNumber(useQ ? s.q : s.i) &&
                         (!acc || vuBlockLanes(s.acc, dest)));
    } else if constexpr (op == 0x2Eu) {
        for (unsigned c = 0; c < 3; ++c)
            if (dest & (8u >> c))
                if (!vuBlockNumber(s.acc[c]) || !vuBlockNumber(a[(c + 1) % 3]) ||
                    !vuBlockNumber(b[(c + 2) % 3]))
                    return false;
        return true;
    } else if constexpr (op >= 0x28u && op <= 0x2Fu)
        return !dest || (vuBlockLanes(a, dest) && vuBlockLanes(b, dest) &&
                         ((op == 0x29u || op == 0x2Du) ? vuBlockLanes(s.acc, dest) : true));
    else if constexpr (op >= 0x3Cu) {
        constexpr unsigned row = (hi >> 6) & 31u, column = hi & 3u;
        if constexpr (row <= 3u || row == 6u)
            return !dest || (vuBlockLanes(a, dest) && vuBlockNumber(b[column]) &&
                             ((row == 2u || row == 3u) ? vuBlockLanes(s.acc, dest) : true));
        else if constexpr (row == 4u)
            return true; // ITOF interprets source bits as int32.
        else if constexpr (row == 5u)
            return vuBlockLanes(a, dest);
        else if constexpr (row == 7u && column == 3u)
            return vuBlockLanes(a, 14u) && vuBlockNumber(b[3]);
        else if constexpr (row == 7u && column == 1u)
            return vuBlockLanes(a, dest);
        else if constexpr (row == 7u)
            return !dest || (vuBlockLanes(a, dest) && vuBlockNumber(column == 0u ? s.q : s.i));
        else if constexpr (row == 8u || row == 9u)
            return !dest || (vuBlockLanes(a, dest) && vuBlockNumber(column < 2u ? s.q : s.i) &&
                             ((column & 1u) ? vuBlockLanes(s.acc, dest) : true));
        else if constexpr (row == 11u && column == 2u) {
            for (unsigned c = 0; c < 3; ++c)
                if (dest & (8u >> c))
                    if (!vuBlockNumber(a[(c + 1) % 3]) || !vuBlockNumber(b[(c + 2) % 3]))
                        return false;
            return true;
        } else if constexpr ((row == 10u || row == 11u) && column < 3u)
            return !dest || (vuBlockLanes(a, dest) && vuBlockLanes(b, dest) &&
                             (column == 1u ? vuBlockLanes(s.acc, dest) : true));
    }
    return true; // Original unimplemented/NOP upper performs no state writes.
}
template <uint32_t hi> constexpr bool vuBlockUpperWrites(unsigned reg, unsigned component) {
    constexpr unsigned op = hi & 63u, dest = (hi >> 21) & 15u;
    if (!(dest & (8u >> component)))
        return false;
    if constexpr (op <= 0x2Fu)
        return reg == ((hi >> 6) & 31u);
    else if constexpr (op >= 0x3Cu) {
        constexpr unsigned row = (hi >> 6) & 31u, column = hi & 3u;
        if constexpr (row == 4u || row == 5u || (row == 7u && column == 1u))
            return reg == ((hi >> 16) & 31u);
    }
    return false; // ACC/CLIP writes cannot change a lower VF operand.
}
template <uint32_t lo, uint32_t hi> VU_BLOCK_INLINE bool vuBlockLowerSafe(const VU1State& s) {
    if constexpr (hi & 0x80000000u)
        return true; // Lower literal, not arithmetic.
    if constexpr (((lo >> 25) & 127u) != 0x40u)
        return true;
    constexpr unsigned selector = lo & 2047u, fs = (lo >> 11) & 31u, ft = (lo >> 16) & 31u;
    const auto input = [&](unsigned r, unsigned c) {
        // Never execute upper first then retry the complete pair. Any same-pair
        // upper->lower VF dependency remains wholly in the original interpreter.
        return !vuBlockUpperWrites<hi>(r, c) && vuBlockNumber(s.vf[r][c]);
    };
    if constexpr (selector == 0x3BCu || selector == 0x3BDu || selector == 0x3BEu) {
        if (!input(ft, (lo >> 23) & 3u))
            return false;
        if constexpr (selector != 0x3BDu)
            return input(fs, (lo >> 21) & 3u);
    } else if constexpr (selector == 0x7BDu || selector == 0x7BCu || selector == 0x7BEu)
        return input(fs, (lo >> 21) & 3u);
    else if constexpr (selector >= 0x73Cu && selector <= 0x73Fu)
        return input(fs, 0) && input(fs, 1) && input(fs, 2);
    else if constexpr (selector == 0x77Eu)
        return input(fs, 0) && input(fs, 1) && input(fs, 2) && input(fs, 3);
    return true; // Memory transfers and register bit copies preserve all payloads.
}
template <uint32_t lo, uint32_t hi> VU_BLOCK_INLINE bool vuBlockPairSafe(const VU1State& s) {
    return vuBlockUpperSafe<hi>(s) && vuBlockLowerSafe<lo, hi>(s);
}
