# SPDX-License-Identifier: GPL-3.0-only
"""Classify complete enemy-only SNAP frames for an owned loopback fixture.

This classifier never rewrites packets or returns their payload bytes. It
deliberately preserves mixed traffic, ACKs and unknown framing. Consequently,
selective loss does not guarantee that every enemy update is suppressed.
"""
import struct


KINEMATIC_LENGTHS = {
    1: 30, 2: 30, 6: 42, 7: 32, 0x28: 30, 0x29: 40,
    0x2A: 32, 0x2B: 30, 0x2C: 40, 0x2D: 32,
}
FOOTERS = (bytes.fromhex('ba476611'), bytes.fromhex('ba476610'))


def classify_enemy_blackout(data):
    """Return ``(safe_to_drop, reason, record_count)`` without payload data.

    SNAP uses a 16-byte big-endian header and a four-byte datagram footer.
    Only flags exactly 0x2000 and command 0x0f qualify: RESPONSE, RELIABLE,
    MULTI and other contexts are preserved. With RESPONSE clear, the header
    ACK word can contain stale SDK bytes and does not represent an ACK.

    Original SDK 1C6E70 packs one or more batches into each message payload.
    Each little-endian batch word has origin slot in its high four bits and
    padded record-byte count in its low twelve bits. 8129C0 / 1C5F30 build
    each 12-byte SDK header: group u16 at +0, mode at +2, unpadded total length
    at +3, duplicated application subtype at +10, application record at +12.
    Record stepping rounds the total length up to four bytes. These boundaries
    are also corroborated by the owned File #1 multiplayer fixture captures.
    """
    if len(data) < 22 or len(data) > 65535 or data[:4] == b'REO2':
        return False, 'not-snap', 0
    if data[-4:] not in FOOTERS:
        return False, 'footer', 0
    end, offset, records = len(data) - 4, 0, 0
    while offset < end:
        if end - offset < 18:
            return False, 'short-snap-header', 0
        word, command = struct.unpack_from('>HH', data, offset)
        flags, message_size = word & 0xFC00, word & 0x03FF
        if flags != 0x2000:
            return False, 'reliable-ack-multi-or-other-context', 0
        if command & 0xFF != 0x0F:
            return False, 'other-command', 0
        if message_size < 18 or offset + message_size > end:
            return False, 'snap-length', 0
        limit, batch = offset + message_size, offset + 16
        while batch < limit:
            if limit - batch < 2:
                return False, 'short-batch', 0
            batch_word = struct.unpack_from('<H', data, batch)[0]
            batch_size = batch_word & 0xFFF
            if batch_word >> 12 >= 4:
                return False, 'batch-sender', 0
            # Preserve heartbeat-only batches, including mixed payloads.
            if not batch_size or batch_size & 3:
                return False, 'empty-or-unaligned-batch', 0
            cursor, batch_end = batch + 2, batch + 2 + batch_size
            if batch_end > limit:
                return False, 'batch-length', 0
            while cursor < batch_end:
                if batch_end - cursor < 16:
                    return False, 'short-sdk-record', 0
                group, mode, record_size = struct.unpack_from('<HBB', data, cursor)
                if group != 8:
                    return False, 'mixed-group', 0
                if mode not in (2, 3):
                    return False, 'other-sdk-mode', 0
                if record_size < 16 or cursor + record_size > batch_end:
                    return False, 'sdk-length', 0
                app = cursor + 12
                kind = data[app]
                app_size = KINEMATIC_LENGTHS.get(kind)
                if app_size is None:
                    return False, 'critical-or-unknown-enemy-kind', 0
                if (data[cursor + 10] != kind or data[app + 1] != app_size or
                        record_size != 12 + app_size):
                    return False, 'app-framing', 0
                if data[app + 2] >= 4:
                    return False, 'actor-sender', 0
                records += 1
                cursor += (record_size + 3) & ~3
            if cursor != batch_end:
                return False, 'sdk-padding', 0
            batch = batch_end
        if batch != limit:
            return False, 'batch-end', 0
        offset = limit
    if offset != end or not records:
        return False, 'no-complete-enemy-record', 0
    return True, 'enemy-kinematic-only', records


def enemy_kinematic_only_unreliable_snap(data):
    return classify_enemy_blackout(data)[0]
