import json
from pathlib import Path
import struct
import tempfile
import unittest

import actor_snapshot as actors
import coop_playtest as harness
from lobby_driver import GuestRam


def fixture(folder, count=4):
    players = [dict(number=i, pid=100 + i, image=str(folder / f"p{i}/game.exe"), creationFileTime=900 + i)
               for i in range(1, count + 1)]
    harness.save(folder / "run.json", {"players": players})
    record = dict(elf="not-opened-by-mock", players=players)
    identities = {p["pid"]: {k: p[k] for k in ("pid", "image", "creationFileTime")} for p in players}
    return record, identities


class FakeRam:
    instances = []
    def __init__(self, identity, elf):
        self.number = identity["number"]
        self.closed, self.reads = False, []
        self.instances.append(self)
    def check(self): pass
    def close(self): self.closed = True
    def read(self, address, size):
        self.reads.append((address, size))
        if address == actors.LOCAL_ACTOR:
            return bytes([self.number - 1])
        slot = (address - actors.ACTOR_BASE) // actors.ACTOR_STRIDE
        data = bytearray(actors.ACTOR_READ_SIZE)
        data[0] = 1
        struct.pack_into("<fff", data, 0x38, float(slot), 2.5, -3)
        struct.pack_into("<H", data, 0x92, 123)
        struct.pack_into("<f", data, 0x1E4, 42.5)
        return bytes(data)


class ActorSnapshotTests(unittest.TestCase):
    def setUp(self): FakeRam.instances = []

    def test_four_player_readonly_receipt_and_immutable_label(self):
        with tempfile.TemporaryDirectory() as temp:
            folder = Path(temp)
            record, identities = fixture(folder)
            result = actors.snapshot_actors(folder, record, "before-move", reader_factory=FakeRam,
                                           identity_reader=identities.get)
            self.assertEqual(result["status"], "captured")
            self.assertEqual(result["coopVerdict"], "not-tested")
            self.assertFalse(result["simultaneousAcrossProcesses"])
            self.assertTrue(result["readOnly"])
            self.assertEqual([p["localActor"] for p in result["players"]], [0, 1, 2, 3])
            self.assertEqual(result["players"][3]["actors"][2]["xyz"], [2.0, 2.5, -3.0])
            self.assertEqual(result["players"][0]["actors"][0]["frame"], 42.5)
            for reader in FakeRam.instances:
                self.assertTrue(reader.closed)
                self.assertEqual(reader.reads, [(actors.LOCAL_ACTOR, 1)] + [
                    (actors.ACTOR_BASE + i * actors.ACTOR_STRIDE, actors.ACTOR_READ_SIZE) for i in range(4)])
            path = Path(result["receipt"])
            saved = path.read_bytes()
            with self.assertRaises(FileExistsError):
                actors.snapshot_actors(folder, record, "before-move", reader_factory=FakeRam,
                                       identity_reader=identities.get)
            self.assertEqual(path.read_bytes(), saved)
            self.assertEqual(len(FakeRam.instances), 4)

    def test_identity_mismatch_never_opens_ram_and_failed_receipt_is_preserved(self):
        with tempfile.TemporaryDirectory() as temp:
            folder = Path(temp)
            record, identities = fixture(folder, 1)
            with self.assertRaises(ValueError):
                actors.snapshot_actors(folder, record, "wrong-pid", reader_factory=FakeRam,
                                       identity_reader=lambda pid: dict(identities[pid], creationFileTime=99))
            self.assertEqual(FakeRam.instances, [])
            result = json.loads((folder / "actors-wrong-pid.json").read_text())
            self.assertEqual(result["status"], "failed")
            self.assertEqual(result["players"], [])

    def test_identity_change_during_capture_closes_reader_and_does_not_append_sample(self):
        with tempfile.TemporaryDirectory() as temp:
            folder = Path(temp)
            record, identities = fixture(folder, 1)
            calls = []
            def changing(pid):
                calls.append(pid)
                return identities[pid] if len(calls) == 1 else None
            with self.assertRaises(ValueError):
                actors.snapshot_actors(folder, record, "changed", reader_factory=FakeRam, identity_reader=changing)
            self.assertTrue(FakeRam.instances[0].closed)
            self.assertEqual(json.loads((folder / "actors-changed.json").read_text())["players"], [])

    def test_label_and_read_bounds(self):
        with tempfile.TemporaryDirectory() as temp:
            folder = Path(temp)
            record, identities = fixture(folder, 1)
            for label in ("", "../escape", "a/b", "two words", "é", "x" * 65, "-hidden"):
                with self.assertRaises(ValueError):
                    actors.snapshot_actors(folder, record, label, reader_factory=FakeRam, identity_reader=identities.get)
            self.assertEqual(list(folder.glob("actors-*.json")), [])
        ram = GuestRam.__new__(GuestRam)
        for address, size in ((-1, 1), (0x1FFFFFF, 2), (0, -1)):
            with self.assertRaises(ValueError): ram.read(address, size)
        for slot in (-1, 4):
            with self.assertRaises(ValueError): actors.decode_actor(slot, bytes(actors.ACTOR_READ_SIZE))
        with self.assertRaises(ValueError): actors.decode_actor(0, b"short")
        data = bytearray(actors.ACTOR_READ_SIZE)
        struct.pack_into("<f", data, 0x38, float("nan"))
        with self.assertRaises(ValueError): actors.decode_actor(0, data)
