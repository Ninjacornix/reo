"""A room's cached USER count cannot establish its actual waiting-room roster."""
import json
from pathlib import Path
import struct
import tempfile
import unittest

import coop_playtest as harness
import lobby_driver as lobby
from test_login_driver import Clock


def ram_fixture(game="file1", *, cached=2, rows=None, host=1, waiting=True):
    second = game == "file2"
    base = 0x6E2ED0 if second else 0x6D8DB0
    raw = bytearray(0xA00 if second else 0x980)
    raw[0], raw[0xF], raw[0x10] = (4, 6, 2) if waiting else (3, 0, 0)
    raw[0x41A] = 1
    raw[0x97E if second else 0x956] = host
    struct.pack_into("<H", raw, 0x456 if second else 0x452, cached)
    segments = {base: raw,
        0x58D000 if second else 0x570000: struct.pack("<II", 0x336F574D, 4),
        0x6E293E if second else 0x6D881E: bytes(6),
        0x64C160 if second else 0x6436D0: bytes(4),
        0x6B53F2 if second else 0x6A3DF2: b"cooptest".ljust(16, b"\0"),
        0x6B547A if second else 0x6A3E7A: bytes([2]),
        0x6E9490 if second else 0x6DF150: bytes([37]),
        0x6E9491 if second else 0x6DF151: bytes([7]),
        0x6A9848 if second else 0x6995A0: bytes([3]),
        0x64C148 if second else 0x6436C8: bytes([0])}
    if second:
        segments.update({0x8AA5D8: bytes([1]), 0x6A9849: bytes([0])})
    else:
        segments.update({0x699560: struct.pack("<I", 1), 0x6994E0: bytes([1, 1])})
    if waiting:
        if rows is None:
            rows = [(f"1234567{i+1}".encode(), f"rc2auto{i+1}".encode()) for i in range(4)]
        for slot, (sid, name) in enumerate(rows):
            # Literal supported-game addresses keep the fixture independent of
            # the production address table; an edition mixup must fail the read.
            address = (0x6E5F6C if second else 0x6DBBE4) + slot * 944
            segments[address] = sid.ljust(16, b"\0") + name.ljust(16, b"\0")
    reader = object.__new__(lobby.GuestRam)
    reader.game = game
    reader.check = lambda: None
    reads = []
    def read(address, size):
        reads.append((address, size))
        if address not in segments or len(segments[address]) != size:
            raise AssertionError(f"Unexpected {game} guest read {address:X}/{size}")
        return bytes(segments[address])
    reader.read = read
    return reader, segments, reads


class LobbyRosterTests(unittest.TestCase):
    def test_four_actual_members_are_visible_when_cached_population_is_two(self):
        for game in ("file1", "file2"):
            with self.subTest(game=game):
                reader, _, _ = ram_fixture(game)
                sample = reader.snapshot()
                self.assertEqual(sample["cachedRoomPopulation"], 2)
                self.assertEqual(sample["memberCount"], 4)
                self.assertEqual([r["name"] for r in sample["roster"]],
                                 [f"rc2auto{i}" for i in range(1, 5)])

    def test_holes_and_duplicate_or_partial_identity_rows_do_not_inflate_membership(self):
        for game in ("file1", "file2"):
            with self.subTest(game=game):
                rows = [(b"9:;<=>?0", b"rc2auto1"), (b"", b""),
                        (b"9:;<=>?0", b"rc2auto1"), (b"12345672", b"rc2auto2")]
                reader, _, _ = ram_fixture(game, cached=4, rows=rows)
                sample = reader.snapshot()
                self.assertEqual(sample["memberCount"], 2)
                self.assertEqual([r["occupied"] for r in sample["roster"]], [True, False, False, True])
                rows = [(b"00000000", b"rc2auto1"), (b"12345672", b"rc2\x01auto"),
                        (b"ABCDEFGH", b"rc2auto3"), (b"12345674", b"")]
                reader, _, _ = ram_fixture(game, rows=rows)
                self.assertEqual(reader.snapshot()["memberCount"], 0)

    def test_no_roster_reads_outside_waiting_room_or_after_overlay_replacement(self):
        for game in ("file1", "file2"):
            with self.subTest(game=game):
                reader, segments, reads = ram_fixture(game, waiting=False)
                self.assertEqual(reader.snapshot()["roster"], [])
                self.assertEqual(reader.snapshot()["memberCount"], 0)
                self.assertTrue(all(address not in (0x6DBBE4, 0x6E5F6C) for address, _ in reads))
                segments[0x58D000 if game == "file2" else 0x570000] = struct.pack("<II", 0x336F574D, 3)
                reads.clear()
                with self.assertRaisesRegex(ValueError, "overlay"):
                    reader.snapshot()
                self.assertEqual(len(reads), 1)

    def drive_four(self, game, *, actual, cached):
        with tempfile.TemporaryDirectory() as temporary:
            folder = Path(temporary)
            identities = [dict(number=i, pid=100+i, image=str(folder/f"player{i}/game.exe"),
                               creationFileTime=1000+i) for i in range(1,5)]
            by_pid = {p["pid"]: {k:p[k] for k in ("pid", "image", "creationFileTime")} for p in identities}
            harness.save(folder/"run.json", {"players":identities})
            players = [dict(number=i["number"], image=i["image"], logs=str(folder)) for i in identities]
            record = dict(game=game, elf="unused", players=players)
            rows = [(f"1234567{i+1}".encode(), f"rc2auto{i+1}".encode()) if i<actual else (b"",b"") for i in range(4)]
            class Reader:
                def __init__(self, identity, elf):
                    self.reader, _, _ = ram_fixture(game, cached=cached, rows=rows,
                                                   host=int(identity["pid"] == 101))
                def snapshot(self): return self.reader.snapshot()
                def close(self): pass
            clock, presses = Clock(), []
            result = lobby.drive(folder, record, goal="waiting-room", timeout=1, reader_factory=Reader,
                                 identity_reader=lambda pid:by_pid[pid],
                                 pad_writer=lambda *args:presses.append(args),
                                 monotonic=clock.read, sleeper=clock.sleep)
            self.assertFalse(result["hostStartSent"])
            self.assertFalse(result["serverMembershipVerified"])
            self.assertEqual(result["coopVerdict"], "not-tested")
            self.assertEqual(presses, [])
            self.assertEqual(json.loads((folder/"drive-lobby-waiting-room.json").read_text())["driverVerdict"],
                             result["driverVerdict"])
            return result

    def test_four_player_driver_uses_roster_instead_of_stale_room_attribute(self):
        for game in ("file1", "file2"):
            with self.subTest(game=game):
                self.assertTrue(self.drive_four(game, actual=4, cached=2).get("uiGoalObserved"))
                self.assertEqual(self.drive_four(game, actual=2, cached=4)["driverVerdict"], "incomplete")
