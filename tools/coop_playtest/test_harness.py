import ctypes
import json
import mmap
import os
from pathlib import Path
import socket
import struct
import subprocess
import sys
import tempfile
import unittest
from unittest import mock
import zlib

import coop_playtest as harness


class IsolationTests(unittest.TestCase):
    def test_import_discovery_uses_portable_and_custom_storage_before_legacy(self):
        with tempfile.TemporaryDirectory() as temp, mock.patch.dict(os.environ, LOCALAPPDATA=temp):
            root = Path(temp) / "launcher"
            legacy = Path(temp) / "OutbreakRecomp" / "launcher"
            legacy.mkdir(parents=True)
            (legacy / "settings.json").write_text(json.dumps(dict(ImportedFile1="old-import")))
            self.assertEqual(harness.configured_import(root, root / "disc.iso", None), Path("old-import"))
            home = root / "data"
            home.mkdir(parents=True)
            (home / "settings.json").write_text(json.dumps(dict(ImportedFile1="portable-import")))
            self.assertEqual(harness.configured_import(root, root / "disc.iso", None), Path("portable-import"))
            custom = root / "chosen folder"
            custom.mkdir()
            (custom / "settings.json").write_text(json.dumps(dict(ImportedFile1="custom-import", ImportedFile2="file2-import")))
            for location in ("chosen folder", str(custom)):
                (root / "storage.json").write_text(json.dumps(dict(format=1, folder=location)))
                self.assertEqual(harness.configured_import(root, root / "disc.iso", None), Path("custom-import"))
                self.assertEqual(harness.configured_import(root, root / "disc.iso", None, "file2"), Path("file2-import"))
            self.assertEqual(harness.configured_import(root, root / "disc.iso", "explicit-import"), Path("explicit-import"))

    def test_import_is_bound_to_selected_edition(self):
        for game, (expected, elf_name, _, _) in harness.GAMES.items():
            with self.subTest(game=game), tempfile.TemporaryDirectory() as temp:
                root = Path(temp)
                iso = root / "disc.iso"
                iso.write_bytes(b"synthetic disc")
                data = root / "data"
                data.mkdir()
                elf = data / elf_name
                elf.write_bytes(b"synthetic ELF")
                record = dict(Version=1, Game=game, Source=str(iso),
                              SourceLength=iso.stat().st_size,
                              SourceWriteTicks=iso.stat().st_mtime_ns // 100 + 621355968000000000,
                              ElfSha256=expected, Files=[dict(Name=elf_name, Length=elf.stat().st_size)])
                (root / "import.json").write_text(json.dumps(record))
                with mock.patch.object(harness, "digest", return_value=expected):
                    self.assertEqual(harness.validate_import(root, iso, game), (data.resolve(), elf.resolve()))
                    with self.assertRaises(ValueError):
                        harness.validate_import(root, iso, "file2" if game == "file1" else "file1")
    def test_operator_stop_requires_confirmed_exact_identity_and_exit_code(self):
        with tempfile.TemporaryDirectory() as temp:
            identity = dict(pid=123, image=str(Path(temp) / "game.exe"), creationFileTime=456)
            def terminate(expected, *, before_terminate):
                self.assertEqual(expected, identity)
                before_terminate()
                return True
            self.assertTrue(harness.request_owned_stop(temp, identity, stopper=terminate))
            receipt = harness.owned_stop_provenance(temp, identity, 0xC000013A)
            self.assertIsNotNone(receipt)
            self.assertIsNone(harness.owned_stop_provenance(temp, identity, 0xC0000005))
            self.assertIsNone(harness.owned_stop_provenance(temp, dict(identity, creationFileTime=999), 0xC000013A))
            self.assertIsNone(harness.owned_stop_provenance(temp, dict(identity, image="wrong.exe"), 0xC000013A))
            clean = dict(fatal=False, readErrors=[])
            self.assertEqual(harness.native_outcome(0xC000013A, clean, operator_stopped=True), "operator-stopped")
            self.assertEqual(harness.native_outcome(0xC000013A, dict(fatal=True), operator_stopped=True), "fatal-diagnostic")

    def test_exit_before_stop_or_failed_identity_cannot_create_confirmed_receipt(self):
        with tempfile.TemporaryDirectory() as temp:
            identity = dict(pid=123, image="owned.exe", creationFileTime=456)
            def exited(expected, *, before_terminate):
                before_terminate()
                return False
            self.assertFalse(harness.request_owned_stop(temp, identity, stopper=exited))
            self.assertIsNone(harness.owned_stop_provenance(temp, identity, 0xC000013A))
            def refused(expected, *, before_terminate):
                raise ValueError("Different process")
            with self.assertRaises(ValueError):
                harness.request_owned_stop(temp, identity, stopper=refused)
            self.assertEqual(len(list((Path(temp) / "stop-requests").glob("*.json"))), 1)

    def test_relative_escape_refused(self):
        with tempfile.TemporaryDirectory() as temp:
            for path in ("../outside", ".", Path(temp).anchor):
                with self.assertRaises(ValueError):
                    harness.beneath(temp, path)
            self.assertEqual(harness.beneath(temp, "a/b").parent.name, "a")

    def test_isolation_environment_is_pinned(self):
        record = {"iso": "test.iso"}
        player = {"card": "private", "map": "private-map"}
        for key in harness.PINNED:
            with self.assertRaises(ValueError):
                harness.environment(record, player, {key: "external"})
        with self.assertRaises(ValueError):
            harness.environment(record, player, {"PATH": "external"})
        os.environ["REO_UNINTENDED_TEST_ENV"] = "should-not-propagate"
        try:
            env = harness.environment(record, player, {"REO_COOP_TEST_PORT": "1234"})
            self.assertNotIn("REO_UNINTENDED_TEST_ENV", env)
            self.assertEqual(env["REO_COOP_TEST_PORT"], "1234")
            self.assertEqual(env["REO_MC0_ROOT"], "private")
        finally:
            del os.environ["REO_UNINTENDED_TEST_ENV"]

    def test_pad_bounds_and_layout(self):
        state = harness.input_state({"buttons": ["cross", "start"], "lx": -32767, "rt": 255})
        self.assertEqual(state, (0x1010, 0, 255, -32767, 0, 0, 0))
        self.assertEqual(struct.calcsize("<IIIIIHBBhhhh"), 32)
        with self.assertRaises(KeyError):
            harness.input_state({"buttons": ["typo"]})
        with self.assertRaises(ValueError):
            harness.input_state({"lx": 32768})
        with self.assertRaises(ValueError):
            harness.input_state({"lt": -1})

    def test_session_paths_cannot_escape(self):
        with tempfile.TemporaryDirectory() as temp:
            folder = Path(temp)
            record = {"owner": "reo-coop-playtest", "session": str(folder), "players": [{
                "image": str(folder / "p/game.exe"), "workingDirectory": str(folder / "p/work"),
                "card": str(folder / "p/card"), "logs": str(folder / "p/logs"),
                "inputFile": str(folder.parent / "outside.json")}]}
            harness.save(folder / "session.json", record)
            with self.assertRaises(ValueError):
                harness.session_record(folder)

    def test_atomic_json(self):
        with tempfile.TemporaryDirectory() as temp:
            file = Path(temp) / "input.json"
            harness.save(file, {"buttons": ["circle"]})
            self.assertEqual(json.loads(file.read_text()), {"buttons": ["circle"]})
            self.assertFalse(file.with_suffix(".json.tmp").exists())

    def test_atomic_json_retries_windows_reader_sharing_without_partial_write(self):
        with tempfile.TemporaryDirectory() as temp:
            file = Path(temp) / "input.json"
            file.write_text('{"old": true}')
            original = Path.replace
            attempts = []
            def sharing(source, target):
                attempts.append(1)
                self.assertEqual(json.loads(file.read_text()), {"old": True})
                if len(attempts) < 3:
                    raise PermissionError("Reader sharing")
                return original(source, target)
            with mock.patch.object(Path, "replace", sharing), mock.patch.object(harness.time, "sleep") as wait:
                harness.save(file, {"new": True})
                self.assertEqual(wait.call_count, 2)
            self.assertEqual(json.loads(file.read_text()), {"new": True})
            self.assertEqual(list(Path(temp).glob("*.tmp-*")), [])
            with mock.patch.object(Path, "replace", side_effect=PermissionError("Permanent denial")), \
                    mock.patch.object(harness.time, "sleep") as wait:
                with self.assertRaises(PermissionError):
                    harness.save(file, {"bad": True})
                self.assertEqual(wait.call_count, 10)
            self.assertEqual(json.loads(file.read_text()), {"new": True})
            self.assertEqual(list(Path(temp).glob("*.tmp-*")), [])

    def test_usb_keyboard_reports_and_bounds(self):
        reports = harness.keyboard_reports("rEo01!", enter=True)
        self.assertEqual(len(reports), 18)
        self.assertEqual(reports[0], bytes((0, 0, 21, 0, 0, 0, 0, 0)))
        self.assertEqual(reports[2], bytes((2, 0, 0, 0, 0, 0, 0, 0)))
        self.assertEqual(reports[3], bytes((2, 0, 8, 0, 0, 0, 0, 0)))
        self.assertEqual(reports[-2], bytes((0, 0, 40, 0, 0, 0, 0, 0)))
        self.assertTrue(all(reports[i + 1][0] == report[0] and reports[i + 1][2:] == bytes(6)
                            for i, report in enumerate(reports) if any(report[2:])))
        self.assertLessEqual(len(harness.keyboard_reports("".join(chr(c) for c in range(32, 127)))), 512)
        for value in ("", "a" * 256, "hello\n", "\u00e9"):
            with self.assertRaises(ValueError):
                harness.keyboard_reports(value)

    def test_original_modifier_change_filter_preserves_mixed_case(self):
        def original_filter(reports):
            # Contract from original EE libusbkb 0x1d5a88: changed modifier
            # cache 0x34284c emits key0 and suppresses simultaneous keys.
            modifier = 0
            output = ""
            for report in reports:
                if report[0] != modifier:
                    modifier = report[0]
                    continue
                key = report[2]
                if 4 <= key <= 29:
                    letter = chr(ord('a') + key - 4)
                    output += letter.upper() if modifier & 0x22 else letter
            return output

        broken = []
        for letter in "CoopTest":
            broken.extend((bytes((2 if letter.isupper() else 0, 0,
                                  4 + ord(letter.lower()) - ord('a'), 0, 0, 0, 0, 0)), bytes(8)))
        self.assertEqual(original_filter(broken), "oopest")
        self.assertEqual(original_filter(harness.keyboard_reports("CoopTest")), "CoopTest")
        self.assertEqual(original_filter(harness.keyboard_reports("ReoTestPass")), "ReoTestPass")
        self.assertEqual(original_filter(harness.keyboard_reports("ABCxyzAA")), "ABCxyzAA")
        self.assertEqual(original_filter(harness.keyboard_reports("reotest")), "reotest")

    def test_shifted_symbols_have_stable_modifier_and_bounded_reports(self):
        reports = harness.keyboard_reports('A_!')
        modifier = 0
        for report in reports:
            if report[0] != modifier:
                self.assertEqual(report[2:], bytes(6), "Modifier changes cannot carry a new key")
            modifier = report[0]
        self.assertEqual(len(reports), 12)
        self.assertEqual(reports[-1], bytes(8))
        with self.assertRaises(ValueError):
            harness.keyboard_reports("A" * 128, enter=True)
        self.assertEqual(len(harness.keyboard_reports("A" * 127, enter=True)), 510)

    def test_password_replacement_uses_end_and_bounded_backspace(self):
        reports = harness.keyboard_reports("reotest", True, replace=True)
        keys = [r[2] for r in reports if r[2]]
        self.assertEqual(keys[:16], [77] + [42] * 15)
        for original in ("", "old", "123456789012345"):
            for initial_caret in (0, len(original) // 2, len(original)):
                value, caret = original, initial_caret
                for key in keys:
                    if key == 77:
                        caret = len(value)
                    elif key == 42 and caret:
                        value, caret = value[:caret - 1] + value[caret:], caret - 1
                    elif 4 <= key <= 29:
                        value = value[:caret] + chr(97 + key - 4) + value[caret:]
                        caret += 1
                self.assertEqual(value, "reotest")
        self.assertEqual(reports[-1], bytes(8))
        with self.assertRaises(ValueError):
            harness.keyboard_reports("A" * 120, True, replace=True)

    def test_usb_keyboard_no_pending_overwrite(self):
        with tempfile.TemporaryDirectory() as temp:
            file = Path(temp) / "keyboard.bin"
            initial = struct.pack("<III", harness.KEYBOARD_MAGIC, 0, 0)
            file.write_bytes(initial)
            with self.assertRaises(ValueError):
                harness.queue_keyboard(file, "reo01")
            self.assertEqual(file.read_bytes(), initial)
            ack = Path(str(file) + ".ack")
            ack.write_text("0")
            receipt = harness.queue_keyboard(file, "reo01")
            self.assertEqual(receipt["sequence"], 1)
            self.assertEqual(receipt["reports"], 10)
            payload = file.read_bytes()
            self.assertEqual(struct.unpack_from("<III", payload), (harness.KEYBOARD_MAGIC, 1, 10))
            with self.assertRaises(ValueError):
                harness.queue_keyboard(file, "reo02")
            self.assertEqual(file.read_bytes(), payload)
            ack.write_text("1\n")
            self.assertEqual(harness.queue_keyboard(file, "reo02")["sequence"], 2)

    def test_usb_keyboard_retries_transient_reader_sharing_without_partial_queue(self):
        with tempfile.TemporaryDirectory() as temp:
            file = Path(temp) / "keyboard.bin"
            initial = struct.pack("<III", harness.KEYBOARD_MAGIC, 0, 0)
            file.write_bytes(initial)
            Path(str(file) + ".ack").write_text("0")
            original_replace = Path.replace
            attempts = []
            def reader_sharing(source, destination):
                attempts.append(source)
                if len(attempts) == 1:
                    self.assertEqual(file.read_bytes(), initial)
                    raise PermissionError("Reader briefly denies FILE_SHARE_DELETE")
                return original_replace(source, destination)
            with mock.patch.object(Path, "replace", reader_sharing), mock.patch.object(harness.time, "sleep"):
                receipt = harness.queue_keyboard(file, "reo01", enter=True)
            self.assertEqual(receipt["sequence"], 1)
            self.assertEqual(len(attempts), 2)
            self.assertEqual(struct.unpack_from("<III", file.read_bytes()),
                             (harness.KEYBOARD_MAGIC, 1, 12))
            self.assertFalse(Path(str(file) + ".writer-lock").exists())
            self.assertEqual(list(Path(temp).glob("*.tmp-*")), [])

    def test_usb_keyboard_enter_only_respects_pending_ack(self):
        self.assertEqual(harness.keyboard_reports("", True),
                         [bytes((0, 0, 40, 0, 0, 0, 0, 0)), bytes(8)])
        with self.assertRaises(ValueError):
            harness.keyboard_reports("")
        with tempfile.TemporaryDirectory() as temp:
            file = Path(temp) / "keyboard.bin"
            file.write_bytes(struct.pack("<III", harness.KEYBOARD_MAGIC, 7, 0))
            ack = Path(str(file) + ".ack")
            ack.write_text("7")
            receipt = harness.queue_keyboard(file, "", True)
            self.assertEqual((receipt["sequence"], receipt["reports"], receipt["characters"]), (8, 2, 0))
            original = file.read_bytes()
            with self.assertRaises(ValueError):
                harness.queue_keyboard(file, "", True)
            self.assertEqual(file.read_bytes(), original)
            self.assertEqual(ack.read_text(), "7")
            ack.write_text("8")
            self.assertEqual(harness.queue_keyboard(file, "", True)["sequence"], 9)

    def test_usb_keyboard_corrupt_queue_and_writer_lock(self):
        with tempfile.TemporaryDirectory() as temp:
            file = Path(temp) / "keyboard.bin"
            file.write_bytes(b"invalid")
            Path(str(file) + ".ack").write_text("0")
            with self.assertRaises(ValueError):
                harness.queue_keyboard(file, "test")
            self.assertEqual(file.read_bytes(), b"invalid")
            self.assertFalse(Path(str(file) + ".writer-lock").exists())
            Path(str(file) + ".writer-lock").write_text("another writer")
            with self.assertRaises(ValueError):
                harness.queue_keyboard(file, "test")
            self.assertTrue(Path(str(file) + ".writer-lock").exists())

    def test_fatal_diagnostic_overrides_zero_exit(self):
        with tempfile.TemporaryDirectory() as temp:
            folder = Path(temp)
            (folder / "stdout.log").write_text("Normal boot\nError: Called unimplemented function at address0x6e2c84\n")
            (folder / "stderr.log").write_text("[CRASH] code=0xC0000005\n[GS-BACKEND-FAIL] test\n")
            diagnostics = harness.classify_native_logs(folder)
            self.assertTrue(diagnostics["fatal"])
            self.assertEqual(diagnostics["fatalLineCount"], 3)
            self.assertEqual(diagnostics["findings"][0]["line"], 2)
            self.assertEqual(harness.native_outcome(0, diagnostics), "fatal-diagnostic")
            self.assertEqual(harness.native_outcome(0, diagnostics, True), "fatal-diagnostic")

    def test_clean_exit_is_not_coop_success(self):
        with tempfile.TemporaryDirectory() as temp:
            folder = Path(temp)
            (folder / "stdout.log").write_text("Initialized successfully\n")
            (folder / "stderr.log").write_text("[GS-BACKEND] requested=parallel\n[run] window close requested\n")
            diagnostics = harness.classify_native_logs(folder)
            self.assertFalse(diagnostics["fatal"])
            self.assertEqual(harness.native_outcome(0, diagnostics), "exited-no-fatal-diagnostic")
            self.assertEqual(harness.native_outcome(1, diagnostics), "nonzero-exit")
            self.assertEqual(harness.native_outcome(0xC000013A, diagnostics, True), "supervisor-stopped")

    def test_missing_movie_shader_is_failure_even_when_native_exit_is_zero(self):
        with tempfile.TemporaryDirectory() as temp:
            folder = Path(temp)
            (folder / "stdout.log").write_text("")
            (folder / "stderr.log").write_text(
                "[StartThread] exception: Missing certified native movie shader asset\n"
                "[run] exiting loop, activeThreads=0\n")
            diagnostics = harness.classify_native_logs(folder)
            self.assertEqual(harness.native_outcome(0, diagnostics), "fatal-diagnostic")

    def test_account_provider_failure_is_fatal_even_at_exit_zero(self):
        with tempfile.TemporaryDirectory() as temp:
            folder = Path(temp)
            (folder / "stdout.log").write_text("")
            error_log = folder / "stderr.log"
            for message in (
                "[COOP-ACCOUNT] Cannot allocate account selection input",
                "[COOP-ACCOUNT] Invalid account selection stack",
                "[COOP-ACCOUNT] Original account helper did not return, pc=0060841c",
            ):
                with self.subTest(message=message):
                    error_log.write_text(message + "\nGame thread returned.\n")
                    diagnostics = harness.classify_native_logs(folder)
                    self.assertEqual(diagnostics["fatalLineCount"], 1)
                    self.assertEqual(diagnostics["findings"][0]["categories"], ["account-provider-failure"])
                    self.assertEqual(harness.native_outcome(0, diagnostics), "fatal-diagnostic")

    def test_normal_account_selection_is_not_fatal_or_authentication_proof(self):
        with tempfile.TemporaryDirectory() as temp:
            folder = Path(temp)
            (folder / "stdout.log").write_text("")
            (folder / "stderr.log").write_text("[COOP-ACCOUNT] Launcher account selected; server authentication still required\n")
            diagnostics = harness.classify_native_logs(folder)
            self.assertFalse(diagnostics["fatal"])
            self.assertEqual(harness.native_outcome(0, diagnostics), "exited-no-fatal-diagnostic")

    def test_diagnostic_missing_logs_and_bounded_evidence(self):
        with tempfile.TemporaryDirectory() as temp:
            folder = Path(temp)
            missing = harness.classify_native_logs(folder)
            self.assertEqual(harness.native_outcome(0, missing), "diagnostics-unavailable")
            (folder / "stdout.log").write_text("")
            (folder / "stderr.log").write_text("[run] graphics backend failure: test\n" * 110)
            diagnostics = harness.classify_native_logs(folder)
            self.assertEqual(diagnostics["fatalLineCount"], 110)
            self.assertEqual(len(diagnostics["findings"]), 100)
            self.assertTrue(diagnostics["findingsTruncated"])


@unittest.skipUnless(os.name == "nt", "Windows APIs")
class WindowsTests(unittest.TestCase):
    def test_operator_stop_receipt_matches_owned_child_termination(self):
        process = subprocess.Popen([sys.executable, "-c", "import time; time.sleep(30)"],
                                   creationflags=subprocess.CREATE_NO_WINDOW)
        try:
            identity = harness.process_identity(process.pid)
            with tempfile.TemporaryDirectory() as temp:
                self.assertTrue(harness.request_owned_stop(temp, identity))
                exit_code = process.wait(timeout=5)
                self.assertEqual(exit_code & 0xFFFFFFFF, 0xC000013A)
                self.assertIsNotNone(harness.owned_stop_provenance(temp, identity, exit_code))
        finally:
            if process.poll() is None:
                process.kill()
            process.wait(timeout=5)

    def test_owned_child_normal_exit_is_not_cleanup_failure(self):
        process = subprocess.Popen([sys.executable, "-c", "import sys; sys.stdin.readline()"],
                                   stdin=subprocess.PIPE, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL,
                                   creationflags=subprocess.CREATE_NO_WINDOW)
        try:
            identity = harness.process_identity(process.pid)
            self.assertIsNotNone(identity)
            process.communicate(b"exit\n", timeout=5)
            self.assertEqual(process.returncode, 0)
            # Popen still retains the Windows process handle: the exited PID
            # may remain queryable even though its image is no longer queryable.
            self.assertIsNone(harness.process_identity(process.pid))
            self.assertFalse(harness.stop_owned(identity))
        finally:
            if process.poll() is None:
                process.terminate()
                process.wait(timeout=5)
    def test_capture_refuses_wrong_identity_before_gdi(self):
        identity = harness.process_identity(os.getpid())
        identity["creationFileTime"] += 1
        with tempfile.TemporaryDirectory() as temp:
            output = Path(temp) / "refused.png"
            with self.assertRaises(ValueError):
                harness.capture_window(identity, output)
            self.assertFalse(output.exists())

    @unittest.skipUnless(os.environ.get("REO_COOP_CAPTURE_TEST_SESSION"), "Optional owned-window integration")
    def test_capture_owned_window_readonly(self):
        import uuid
        folder, record = harness.session_record(os.environ["REO_COOP_CAPTURE_TEST_SESSION"])
        receipt = json.loads((folder / "run.json").read_text())
        identity = receipt["players"][0]
        output = folder / "captures" / ("test-readonly-" + uuid.uuid4().hex + ".png")
        output.parent.mkdir(exist_ok=True)
        result = harness.capture_window(identity, output)
        image = output.read_bytes()
        self.assertEqual(image[:8], b"\x89PNG\r\n\x1a\n")
        self.assertEqual(struct.unpack_from(">II", image, 16), (result["width"], result["height"]))
        self.assertEqual(result["pid"], identity["pid"])
        self.assertFalse(result["foregroundRequested"])
        offset = 8
        payload = bytearray()
        while offset < len(image):
            length = struct.unpack_from(">I", image, offset)[0]
            kind = image[offset + 4:offset + 8]
            chunk = image[offset + 8:offset + 8 + length]
            crc = struct.unpack_from(">I", image, offset + 8 + length)[0]
            self.assertEqual(crc, zlib.crc32(kind + chunk))
            if kind == b"IDAT":
                payload += chunk
            offset += 12 + length
        self.assertEqual(len(zlib.decompress(payload)), result["height"] * (1 + result["width"] * 4))

    def test_named_map_isolation_and_adapter_abi(self):
        import uuid
        a = harness.Publisher("Local\\REO-Coop-Test-" + uuid.uuid4().hex)
        b = harness.Publisher("Local\\REO-Coop-Test-" + uuid.uuid4().hex)
        try:
            a.publish({"buttons": ["cross"], "lx": 1234})
            b.publish({"buttons": ["circle"], "lx": -2345})
            self.assertEqual(struct.unpack_from("<I", a.mapping)[0], 0x52454F50)
            self.assertEqual(struct.unpack_from("<H", a.mapping, 20)[0], 0x1000)
            self.assertEqual(struct.unpack_from("<H", b.mapping, 20)[0], 0x2000)
            self.assertEqual(struct.unpack_from("<h", a.mapping, 24)[0], 1234)
            self.assertEqual(struct.unpack_from("<h", b.mapping, 24)[0], -2345)
            self.assertEqual(struct.unpack_from("<I", a.mapping, 4)[0] % 2, 0)
        finally:
            a.close()
            b.close()

    def test_process_owned_endpoint_visibility_ipv4_and_ipv6(self):
        sockets = []
        try:
            for family, address in ((socket.AF_INET, "127.0.0.1"), (socket.AF_INET6, "::1")):
                for kind in (socket.SOCK_STREAM, socket.SOCK_DGRAM):
                    sock = socket.socket(family, kind)
                    sock.bind((address, 0))
                    if kind == socket.SOCK_STREAM:
                        sock.listen(1)
                    sockets.append(sock)
            rows = harness.endpoints({os.getpid()})
            found = {(x["protocol"], x["localPort"]) for x in rows}
            for sock in sockets:
                protocol = "tcp" if sock.type == socket.SOCK_STREAM else "udp"
                self.assertIn((protocol, sock.getsockname()[1]), found)
            self.assertEqual(harness.endpoints({0xFFFFFFFE}), [])
        finally:
            for sock in sockets:
                sock.close()

    def test_pid_creation_identity_and_reuse_guard(self):
        process = subprocess.Popen([sys.executable, "-c", "import time; time.sleep(60)"],
                                   creationflags=subprocess.CREATE_NO_WINDOW)
        try:
            identity = harness.process_identity(process.pid)
            # Microsoft Store Python's app-execution alias can differ from the
            # actual process image. The child must use our real interpreter.
            parent_image = harness.process_identity(os.getpid())["image"]
            self.assertEqual(Path(identity["image"]), Path(parent_image))
            wrong = dict(identity, creationFileTime=identity["creationFileTime"] + 1)
            with self.assertRaises(ValueError):
                harness.stop_owned(wrong)
            self.assertIsNone(process.poll())
            self.assertTrue(harness.stop_owned(identity))
            process.wait(timeout=5)
        finally:
            if process.poll() is None:
                process.terminate()
                process.wait(timeout=5)


if __name__ == "__main__":
    unittest.main(verbosity=2)
