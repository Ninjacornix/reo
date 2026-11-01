# SPDX-License-Identifier: AGPL-3.0-only
"""Room-scoped native protocol. Original SN@P events are never intercepted/replayed.

No extra port, unauthenticated admission, or world simulation is introduced.
All extension traffic uses the already authenticated game socket endpoint.
"""
from dataclasses import dataclass
import json
import logging
import math
import os
from pathlib import Path
import struct
import time

from opensnap.protocol.models import Endpoint

MAGIC = b'REO2'
VERSION = 1
HEADER = struct.Struct('!4sBBHIIIIQ')
HELLO, STATUS, MOTION, PING, PONG, WORLD_DIGEST, WORLD_REQUEST = range(1, 8)
LEGACY, READY, ENHANCED = range(3)
CAP_BATCH, CAP_MOTION, CAP_CRITICAL, CAP_WORLD = 1, 2, 4, 8
CAPABILITIES = CAP_BATCH | CAP_MOTION | CAP_CRITICAL | CAP_WORLD
HELLO_BODY = struct.Struct('!QII')  # instance nonce, supported features, acknowledged room epoch
STATUS_BODY = struct.Struct('!QII4I')  # nonce, common features, mode, roster
MOTION_BODY = struct.Struct('!BBHfffH')  # slot, reserved, game room, xyz, yaw
MAX_PACKET = 1200
LEASE_SECONDS = 5.0


def packet(kind, sid, room=0, epoch=0, sequence=0, stamp=0, body=b''):
    return HEADER.pack(MAGIC, VERSION, kind, len(body), sid, room, epoch, sequence, stamp) + body


@dataclass
class Peer:
    endpoint: Endpoint
    nonce: int
    capabilities: int
    seen: float
    acknowledged: int = 0
    sequence: int | None = None
    slot: int | None = None
    tokens: float = 40.0
    token_time: float = 0.0
    world_request_at: float = -1e9


@dataclass
class Room:
    epoch: int
    members: tuple[int, ...]
    started: bool = False
    features: int = 0
    mode: int = READY


class NativeRooms:
    """Single-threaded companion to the UDP loop, with bounded per-session state."""
    def __init__(self, engine, clock=time.monotonic):
        self.engine, self.clock = engine, clock
        self.peers: dict[int, Peer] = {}
        self.rooms: dict[int, Room] = {}
        self.next_epoch = 0
        self.status_sequence = 0
        self.endpoint_moves = []
        self.received = self.rejected = self.forwarded = 0
        self.logger = logging.getLogger('opensnap.native')
        self.metrics = os.environ.get('OPENSNAP_NATIVE_METRICS_FILE', '')
        self.reported_at = -1e9

    def _epoch(self):
        self.next_epoch = (self.next_epoch + 1) & 0xffffffff or 1
        return self.next_epoch

    def observe(self):
        # Extension state can only be allocated for real admitted sessions.
        sessions = {s.session_id: s for s in self.engine._sessions.all()}
        now = self.clock()
        for sid in list(self.peers):
            session = sessions.get(sid)
            if session is None or session.endpoint.host != self.peers[sid].endpoint.host:
                del self.peers[sid]
            elif session.endpoint != self.peers[sid].endpoint:
                # Preserve the negotiated nonce across a move already authenticated
                # by the original engine's SID/host checks.
                self.peers[sid].endpoint = session.endpoint
        active_rooms = {s.room_id for s in sessions.values() if s.room_id}
        for room_id in list(self.rooms):
            if room_id not in active_rooms:
                del self.rooms[room_id]
        for room_id in active_rooms:
            original = self.engine._rooms.get(room_id)
            if original is None:
                continue
            members = tuple(sorted(sid for sid in original.members if sid in sessions))
            state = self.rooms.get(room_id)
            # Original bit: room started/disbanded. Once selected, no mid-scenario upgrade.
            started = bool(original.rules & 0x40000000)
            if state is None or (not state.started and state.members != members):
                state = self.rooms[room_id] = Room(self._epoch(), members)
                for sid in members:
                    if sid in self.peers:
                        self.peers[sid].slot = None
                        self.peers[sid].sequence = None
            if state.started and not started:
                state = self.rooms[room_id] = Room(self._epoch(), members)
                for sid in members:
                    if sid in self.peers:
                        self.peers[sid].slot = None
                        self.peers[sid].sequence = None
            if not state.started:
                features = CAPABILITIES
                agreed = len(members) >= 2
                for sid in members:
                    peer = self.peers.get(sid)
                    if peer is None or now - peer.seen > LEASE_SECONDS:
                        features = 0
                        agreed = False
                        break
                    features &= peer.capabilities
                    agreed &= peer.acknowledged == state.epoch
                state.features = features
                state.mode = ENHANCED if started and agreed and features & CAP_BATCH else LEGACY if started else READY
                state.started = started
                if started:
                    self.logger.info('Room %d epoch %d native=%s features=%d members=%d',
                                     room_id, state.epoch, state.mode == ENHANCED, features, len(members))

    def handle(self, data, endpoint):
        """Return None for SN@P, otherwise addressed raw responses (possibly empty)."""
        if not data.startswith(MAGIC):
            return None
        # The magic can theoretically coincide with a valid original header.
        # Preserve complete original framing, including bundled SNAP messages.
        if len(data) >= 20 and data[-4:] in (b'\xba\x47\x66\x11', b'\xba\x47\x66\x10'):
            offset, end = 0, len(data) - 4
            while offset + 16 <= end:
                size = int.from_bytes(data[offset:offset+2], 'big') & 0x3ff
                if size < 16 or offset + size > end:
                    break
                offset += size
            if offset == end:
                return None
        self.received += 1
        if not HEADER.size <= len(data) <= MAX_PACKET:
            return self._reject()
        magic, version, kind, length, sid, room_id, epoch, sequence, stamp = HEADER.unpack_from(data)
        if version != VERSION or length != len(data) - HEADER.size:
            return self._reject()
        session = self.engine._sessions.get(sid)
        # resolve_session's fallback accepts an arbitrary SID at a known endpoint;
        # this protocol deliberately requires BOTH the exact SID and exact endpoint.
        if session is None or session.game_plugin not in ('outbreak', 'outbreak2'):
            return self._reject()
        body = data[HEADER.size:]
        now = self.clock()
        if session.endpoint != endpoint:
            peer = self.peers.get(sid)
            # An already negotiated random instance nonce permits a UDP port
            # rebinding on the same host. SID alone never authorizes this path.
            if (kind != HELLO or len(body) != HELLO_BODY.size or peer is None or
                    peer.endpoint != session.endpoint or endpoint.host != session.endpoint.host or
                    HELLO_BODY.unpack(body)[0] != peer.nonce):
                return self._reject()
            old = session.endpoint
            self.engine._sessions.rebind_endpoint(sid, endpoint)
            peer.endpoint = endpoint
            session.last_inbound_at = now
            self.endpoint_moves.append((old, endpoint, sid))
        if kind == HELLO and len(body) == HELLO_BODY.size:
            nonce, features, acknowledged = HELLO_BODY.unpack(body)
            if not nonce:
                return self._reject()
            peer = self.peers.get(sid)
            if peer is None:
                peer = self.peers[sid] = Peer(endpoint, nonce, features & CAPABILITIES, now, token_time=now)
            if peer.nonce != nonce:
                # A restarted native process must perform the normal game login again.
                return self._reject()
            if now - peer.seen < 0.1 and peer.seen != peer.token_time:
                return self._reject()
            peer.seen = now
            peer.capabilities &= features
            state = self.rooms.get(session.room_id)
            if state and room_id == session.room_id and epoch == state.epoch:
                peer.acknowledged = acknowledged if acknowledged == epoch else 0
            self.observe()
            state = self.rooms.get(session.room_id)
            self.status_sequence = (self.status_sequence + 1) & 0xffffffff
            members = () if state is None else state.members
            response = STATUS_BODY.pack(nonce, 0 if state is None else state.features,
                                        LEGACY if state is None else state.mode, *(members + (0,) * (4 - len(members))))
            return [(endpoint, packet(STATUS, sid, session.room_id, 0 if state is None else state.epoch,
                                      self.status_sequence, stamp, response))]
        peer = self.peers.get(sid)
        state = self.rooms.get(session.room_id)
        if (peer is None or state is None or state.mode != ENHANCED or
                now - peer.seen > LEASE_SECONDS or room_id != session.room_id or epoch != state.epoch):
            return self._reject()
        peer.tokens = min(40.0, peer.tokens + max(0, now - peer.token_time) * 30)
        peer.token_time = now
        if peer.tokens < 1:
            return self._reject()
        peer.tokens -= 1
        if kind == PING and not body:
            return [(endpoint, packet(PONG, sid, room_id, epoch, sequence, stamp))]
        if kind in (WORLD_DIGEST, WORLD_REQUEST):
            if not state.features & CAP_WORLD or len(body) != (16 if kind == WORLD_DIGEST else 4):
                return self._reject()
            game_room, authority, reserved = struct.unpack_from('!HBB', body)
            if game_room >= 128 or authority >= 4 or reserved:
                return self._reject()
            if kind == WORLD_DIGEST and (peer.slot != authority or struct.unpack_from('!H', body, 12)[0] > 256 or body[14:] != b'\0\0'):
                return self._reject()
            if peer.sequence is not None and not 0 < ((sequence - peer.sequence) & 0xffffffff) < 0x80000000:
                return self._reject()
            peer.sequence = sequence
            if kind == WORLD_REQUEST:
                if now - peer.world_request_at < 3.0:
                    return self._reject()
                peer.world_request_at = now
            targets = []
            for recipient in state.members:
                other, target = self.peers.get(recipient), self.engine._sessions.get(recipient)
                if (recipient != sid and other is not None and target is not None and target.room_id == room_id
                        and now - other.seen <= LEASE_SECONDS and
                        (kind == WORLD_DIGEST or other.slot == authority)):
                    targets.append((target.endpoint, data))
            self.forwarded += len(targets)
            return targets
        if kind != MOTION or not state.features & CAP_MOTION or len(body) != MOTION_BODY.size:
            return self._reject()
        slot, reserved, game_room, x, y, z, yaw = MOTION_BODY.unpack(body)
        if reserved or slot >= 4 or not all(math.isfinite(v) and abs(v) < 1e7 for v in (x, y, z)):
            return self._reject()
        if peer.slot is not None and peer.slot != slot:
            return self._reject()
        if any(other != sid and self.peers.get(other) and self.peers[other].slot == slot for other in state.members):
            return self._reject()
        if peer.sequence is not None and not 0 < ((sequence - peer.sequence) & 0xffffffff) < 0x80000000:
            return self._reject()
        peer.slot, peer.sequence = slot, sequence
        targets = []
        for recipient in state.members:
            other = self.peers.get(recipient)
            target = self.engine._sessions.get(recipient)
            if (recipient != sid and other is not None and target is not None and target.room_id == room_id
                    and now - other.seen <= LEASE_SECONDS):
                targets.append((target.endpoint, data))
        self.forwarded += len(targets)
        return targets

    def _reject(self):
        self.rejected += 1
        return []

    def take_endpoint_moves(self):
        moves, self.endpoint_moves = self.endpoint_moves, []
        return moves

    def restart(self, session_id):
        self.peers.pop(session_id, None)
        # A logical login restarts native sequencing. End enhancement for this
        # scenario and fence off old packets; a UDP port move does neither.
        for state in self.rooms.values():
            if state.started and session_id in state.members:
                state.epoch = self._epoch()
                state.mode = LEGACY

    def report(self, transport):
        now = self.clock()
        if not self.metrics or now - self.reported_at < 1.0:
            return
        self.reported_at = now
        pending = list(transport._reliable_pending.values())
        row = {'t': now, 'native_received': self.received, 'native_rejected': self.rejected,
               'native_forwarded': self.forwarded, 'native_peers': len(self.peers),
               'reliable_pending': len(pending),
               'reliable_deferred': sum(len(v) for v in transport._deferred_reliable.values()),
               'oldest_unacked_ms': round(1000 * max((now - p.first_sent_at for p in pending), default=0), 2),
               'pending_retransmits': sum(p.retransmit_attempts for p in pending),
               'rtt_estimates_ms': [round(1000 * v, 2) for v in list(transport._rtt_estimate_by_endpoint.values())[:64]]}
        try:
            path = Path(self.metrics)
            if path.exists() and path.stat().st_size >= 8 * 1024 * 1024:
                path.replace(path.with_suffix(path.suffix + '.1'))
            with path.open('a', encoding='utf-8') as stream:
                stream.write(json.dumps(row, separators=(',', ':'), allow_nan=False) + '\n')
        except OSError as error:
            self.logger.warning('Native metrics disabled: %s', error)
            self.metrics = ''
