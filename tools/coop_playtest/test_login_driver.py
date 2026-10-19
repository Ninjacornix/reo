"""Mock original UI progression; never attaches to or sends input to a game."""

import json
from pathlib import Path
import struct
import tempfile
import unittest

import coop_playtest as harness


class Clock:
    def __init__(self):
        self.now = 0.0

    def read(self):
        return self.now

    def sleep(self, seconds):
        self.now += seconds


def fixture(folder, count=1, ready=True):
    players, identities = [], {}
    for number in range(1, count + 1):
        player = folder / f"player{number}"
        logs = player / "logs"
        logs.mkdir(parents=True)
        (logs / "stderr.log").write_text("[TEST-ROUTE] password-input-ready t=1\n" if ready else "")
        keyboard = player / "keyboard.bin"
        keyboard.write_bytes(struct.pack("<III", harness.KEYBOARD_MAGIC, 0, 0))
        Path(str(keyboard) + ".ack").write_text("0")
        image = player / "image" / "reo_coop_game.exe"
        players.append({"number": number, "image": str(image), "logs": str(logs), "keyboardFile": str(keyboard)})
        identities[number] = {"number": number, "pid": 1000 + number, "image": str(image), "creationFileTime": number * 100}
    harness.save(folder / "run.json", {"players": list(identities.values())})
    return {"players": players}, identities


def reader(identities):
    def read(pid):
        row = next(value for value in identities.values() if value["pid"] == pid)
        return {k: row[k] for k in ("pid", "image", "creationFileTime")}
    return read


class LoginDriverTests(unittest.TestCase):
    def test_explicit_replacement_is_once_and_password_not_recorded(self):
        with tempfile.TemporaryDirectory() as temp:
            folder = Path(temp)
            record, identities = fixture(folder)
            calls = []

            def consume(path, password, enter, *, replace=False):
                calls.append(replace)
                queued = harness.queue_keyboard(path, password, enter, replace=replace)
                Path(str(path) + ".ack").write_text(str(queued["sequence"]))
                with open(path.parent / "logs" / "stderr.log", "a") as log:
                    log.write("[TEST-ROUTE] login-submitted\n")
                return queued

            clock = Clock()
            result = harness.drive_login(folder, record, {1: "dummy-pass"}, 2, replace=True,
                                         identity_reader=reader(identities), queue_writer=consume,
                                         monotonic=clock.read, sleeper=clock.sleep)
            self.assertEqual(calls, [True])
            self.assertTrue(result["replaceExisting"])
            self.assertEqual(result["driverVerdict"], "submitted-not-authenticated")
            self.assertNotIn("dummy-pass", (folder / "drive-login.json").read_text())

    def test_four_players_queue_once_and_only_report_submitted(self):
        with tempfile.TemporaryDirectory() as temp:
            folder = Path(temp)
            record, identities = fixture(folder, 4)
            calls = []

            def consume(path, password, enter):
                calls.append((path, enter))
                queued = harness.queue_keyboard(path, password, enter)
                Path(str(path) + ".ack").write_text(str(queued["sequence"]))
                with open(path.parent / "logs" / "stderr.log", "a") as log:
                    log.write("[TEST-ROUTE] login-submitted t=2; automatic input disabled\n")
                return queued

            clock = Clock()
            result = harness.drive_login(folder, record, {i: "dummy-pass" for i in range(1, 5)}, 2,
                                         identity_reader=reader(identities), queue_writer=consume,
                                         monotonic=clock.read, sleeper=clock.sleep)
            self.assertEqual(len(calls), 4)
            self.assertTrue(all(enter for _, enter in calls))
            self.assertEqual(len({str(path) for path, _ in calls}), 4)
            self.assertEqual(result["driverVerdict"], "submitted-not-authenticated")
            self.assertEqual(result["coopVerdict"], "not-tested")
            self.assertTrue(all(p["queueAcknowledged"] and p["submittedObserved"] for p in result["players"]))
            receipt = (folder / "drive-login.json").read_text()
            self.assertNotIn("dummy-pass", receipt)
            with self.assertRaises(ValueError):
                harness.drive_login(folder, record, {1: "dummy-pass"}, 2, identity_reader=reader(identities))
            self.assertEqual((folder / "drive-login.json").read_text(), receipt)

    def test_queue_backpressure_retries_without_duplicate_delivery(self):
        with tempfile.TemporaryDirectory() as temp:
            folder = Path(temp)
            record, identities = fixture(folder)
            attempts, deliveries = [], []

            def busy_then_consume(path, password, enter):
                attempts.append(1)
                if len(attempts) == 1:
                    raise ValueError("Keyboard reports are still pending; refusing to overwrite them")
                deliveries.append(1)
                with open(path.parent / "logs" / "stderr.log", "a") as log:
                    log.write("[TEST-ROUTE] login-submitted\n")
                return {"sequence": 1}

            clock = Clock()
            result = harness.drive_login(folder, record, {1: "dummy-pass"}, 2,
                                         identity_reader=reader(identities), queue_writer=busy_then_consume,
                                         monotonic=clock.read, sleeper=clock.sleep)
            self.assertEqual((len(attempts), len(deliveries)), (2, 1))
            self.assertEqual(result["players"][0]["status"], "submitted-not-authenticated")

    def test_already_submitted_marker_never_types_password(self):
        with tempfile.TemporaryDirectory() as temp:
            folder = Path(temp)
            record, identities = fixture(folder)
            with open(Path(record["players"][0]["logs"]) / "stderr.log", "a") as log:
                log.write("[TEST-ROUTE] login-submitted\n")
            clock = Clock()
            result = harness.drive_login(folder, record, {1: "dummy-pass"}, 2,
                                         identity_reader=reader(identities),
                                         queue_writer=lambda *_: self.fail("Must not type after submission"),
                                         monotonic=clock.read, sleeper=clock.sleep)
            self.assertEqual(result["players"][0]["status"], "already-submitted")
            self.assertIsNone(result["players"][0]["queuedSequence"])

    def test_mismatched_or_exited_process_never_receives_queue(self):
        for exited in (False, True):
            with self.subTest(exited=exited), tempfile.TemporaryDirectory() as temp:
                folder = Path(temp)
                record, identities = fixture(folder)
                wrong = reader(identities)(1001)
                wrong["creationFileTime"] += 1
                clock = Clock()
                result = harness.drive_login(folder, record, {1: "dummy-pass"}, 2,
                                             identity_reader=lambda _: None if exited else wrong,
                                             queue_writer=lambda *_: self.fail("Unowned process must not receive input"),
                                             monotonic=clock.read, sleeper=clock.sleep)
                self.assertEqual(result["players"][0]["status"], "process-exited" if exited else "identity-mismatch")

    def test_readiness_timeout_is_bounded_and_sends_nothing(self):
        with tempfile.TemporaryDirectory() as temp:
            folder = Path(temp)
            record, identities = fixture(folder, ready=False)
            clock = Clock()
            result = harness.drive_login(folder, record, {1: "dummy-pass"}, 1,
                                         identity_reader=reader(identities),
                                         queue_writer=lambda *_: self.fail("No original UI readiness"),
                                         monotonic=clock.read, sleeper=clock.sleep)
            self.assertEqual(result["players"][0]["status"], "timed-out")
            self.assertLess(result["elapsedSeconds"], 1.2)
            self.assertEqual(result["driverVerdict"], "incomplete")

    def test_identity_revalidated_immediately_before_queue(self):
        with tempfile.TemporaryDirectory() as temp:
            folder = Path(temp)
            record, identities = fixture(folder)
            reads = []

            def replaced_between_checks(pid):
                reads.append(1)
                identity = reader(identities)(pid)
                if len(reads) > 1:
                    identity["creationFileTime"] += 1
                return identity

            clock = Clock()
            result = harness.drive_login(folder, record, {1: "dummy-pass"}, 2,
                                         identity_reader=replaced_between_checks,
                                         queue_writer=lambda *_: self.fail("Identity changed before queue"),
                                         monotonic=clock.read, sleeper=clock.sleep)
            self.assertEqual(result["players"][0]["status"], "identity-mismatch")

    def test_native_fatal_diagnostic_blocks_queue(self):
        with tempfile.TemporaryDirectory() as temp:
            folder = Path(temp)
            record, identities = fixture(folder)
            with open(Path(record["players"][0]["logs"]) / "stderr.log", "a") as log:
                log.write("[COOP-ACCOUNT] Invalid account selection stack\n")
            clock = Clock()
            result = harness.drive_login(folder, record, {1: "dummy-pass"}, 2,
                                         identity_reader=reader(identities),
                                         queue_writer=lambda *_: self.fail("Fatal native flow"),
                                         monotonic=clock.read, sleeper=clock.sleep)
            self.assertEqual(result["players"][0]["status"], "fatal-diagnostic")

    def test_password_and_timeout_validation_before_receipt_creation(self):
        with tempfile.TemporaryDirectory() as temp:
            folder = Path(temp)
            record, identities = fixture(folder)
            for password in ("", "abc", "x" * 16, "test\n", "t\u00e9st"):
                with self.subTest(password=password), self.assertRaises(ValueError):
                    harness.drive_login(folder, record, {1: password}, 2)
            with self.assertRaises(ValueError):
                harness.drive_login(folder, record, {1: "dummy-pass"}, 0)
            self.assertFalse((folder / "drive-login.json").exists())

    def test_log_cursor_retains_partial_marker_without_replay(self):
        with tempfile.TemporaryDirectory() as temp:
            file = Path(temp) / "stderr.log"
            file.write_bytes(b"[TEST-ROUTE] password-input-")
            cursor = harness.LoginLogCursor(file)
            self.assertEqual(cursor.lines(), [])
            with open(file, "ab") as log:
                log.write(b"ready\n")
            self.assertEqual(cursor.lines(), ["[TEST-ROUTE] password-input-ready"])
            self.assertEqual(cursor.lines(), [])


if __name__ == "__main__":
    unittest.main(verbosity=2)
