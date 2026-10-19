import json
from pathlib import Path
import tempfile
import unittest

import coop_playtest as harness
import lobby_driver as lobby
from test_login_driver import Clock


def snapshot(**overrides):
    data = dict(state=2, sub=0, menu=1, phase=0, nested=0, chat=False, cursor=0,
                outerStep=37, outerSub=7, mainMode=1, serverController=3,
                serverWidget=2, serverWidgetSub=0, serverCount=2,
                serverRows=[dict(mode=0, backend=0), dict(mode=1, backend=1)],
                settingsCursor=0, joinCursor=0, areaCursor=0, areaPage=0,
                areaCount=1, roomCursor=0, roomPage=0, rooms=[], roomCount=0,
                title="", maxPlayersIndex=0, characterIndex=0, characterCount=8,
                keyboardInitialized=True, keyboardDelay=0, keyboardComplete=0,
                memberCount=1, host=1)
    data.update(overrides)
    return data


class LobbyTests(unittest.TestCase):
    def plan(self, state, player=1, context=None, goal="waiting-room", host_waiting=True):
        return lobby.plan(player, state, context or {}, goal=goal, host_waiting=host_waiting)

    def test_server_select_uses_real_map_not_stale_root_state(self):
        state = snapshot(mainMode=7, state=6)
        self.assertEqual(self.plan(state)[:2], ("button", "right"))
        state["cursor"] = 1
        self.assertEqual(self.plan(state)[:2], ("button", "cross"))
        state["serverRows"] = [dict(mode=1, backend=0), dict(mode=0, backend=1)]
        self.assertEqual(self.plan(state)[:2], ("button", "left"))
        state["serverWidgetSub"] = 1
        self.assertEqual(self.plan(state)[0], "wait")

    def test_ambiguous_server_map_and_poststart_are_refused(self):
        self.assertEqual(self.plan(snapshot(mainMode=7, serverRows=[dict(mode=1), dict(mode=1)]))[0], "refuse")
        self.assertEqual(self.plan(snapshot(state=14))[0], "refuse")
        self.assertEqual(self.plan(snapshot(state=6))[0], "refuse")
        self.assertEqual(self.plan(snapshot(chat=True))[0], "wait")

    def test_title_requires_actual_initialization_warmup(self):
        state = snapshot(state=3, menu=3, phase=3, nested=2)
        self.assertEqual(self.plan(state)[0], "wait")
        context = {"titleWarmupObserved": True}
        self.assertEqual(self.plan(state, context=context)[:2], ("text", "cooptest"))
        state["keyboardDelay"] = 1
        self.assertEqual(self.plan(state, context=context)[0], "wait")
        state.update(keyboardDelay=0, title="existing")
        self.assertEqual(self.plan(state, context=context)[0], "refuse")

    def test_create_and_character_join_only_known_gates(self):
        self.assertEqual(self.plan(snapshot(state=3, menu=3, phase=2, nested=1, title="cooptest",
                                            settingsCursor=2))[:2], ("button", "right"))
        self.assertEqual(self.plan(snapshot(state=3, menu=3, phase=2, nested=1, title="cooptest",
                                            settingsCursor=10, maxPlayersIndex=2))[:2], ("button", "cross"))
        state = snapshot(state=3, menu=2, phase=1, nested=1, host=0)
        self.assertEqual(self.plan(state, player=3)[:2], ("button", "down"))
        state["characterIndex"] = 1
        self.assertEqual(self.plan(state, player=3)[:2], ("button", "down"))
        state["joinCursor"] = 1
        self.assertEqual(self.plan(state, player=3)[:2], ("button", "cross"))
        for number in (2, 3, 4):
            for current in range(8):
                state.update(joinCursor=0, characterIndex=current)
                self.assertEqual(self.plan(state, player=number)[:2], ("button", "down"))
        state["characterIndex"] = 8
        self.assertEqual(self.plan(state, player=2)[0], "refuse")

    def test_waiting_goal_never_sends_start_and_never_claims_membership(self):
        state = snapshot(state=4, phase=6, nested=2, cursor=0)
        self.assertEqual(self.plan(state)[0], "done")
        with tempfile.TemporaryDirectory() as temp:
            folder = Path(temp)
            identity = dict(number=1, pid=123, image=str(folder / "game.exe"), creationFileTime=45)
            harness.save(folder / "run.json", {"players": [identity]})
            expected = {k: identity[k] for k in ("pid", "image", "creationFileTime")}
            record = dict(elf="unused", players=[dict(number=1, image=identity["image"], logs=str(folder))])
            class Reader:
                def __init__(self, *args): pass
                def snapshot(self): return state
                def close(self): pass
            clock, calls = Clock(), []
            result = lobby.drive(folder, record, goal="waiting-room", reader_factory=Reader,
                                 identity_reader=lambda pid: expected, pad_writer=lambda *args: calls.append(args),
                                 monotonic=clock.read, sleeper=clock.sleep)
            self.assertTrue(result["uiGoalObserved"])
            self.assertFalse(result["hostStartSent"])
            self.assertFalse(result["serverMembershipVerified"])
            self.assertEqual(result["coopVerdict"], "not-tested")
            self.assertEqual(calls, [])
            self.assertEqual(json.loads((folder / "drive-lobby-waiting-room.json").read_text())["hostStartSent"], False)

    def test_unknown_ui_timeout_is_bounded_and_sends_nothing(self):
        with tempfile.TemporaryDirectory() as temp:
            folder = Path(temp)
            identity = dict(number=1, pid=123, image=str(folder / "game.exe"), creationFileTime=45)
            harness.save(folder / "run.json", {"players": [identity]})
            record = dict(elf="unused", players=[dict(number=1, image=identity["image"], logs=str(folder))])
            class Reader:
                def __init__(self, *args): pass
                def snapshot(self): return snapshot(mainMode=9)
                def close(self): pass
            clock, calls = Clock(), []
            result = lobby.drive(folder, record, timeout=1, reader_factory=Reader,
                                 identity_reader=lambda pid: {k: identity[k] for k in ("pid", "image", "creationFileTime")},
                                 pad_writer=lambda *args: calls.append(args), monotonic=clock.read, sleeper=clock.sleep)
            self.assertEqual(calls, [])
            self.assertEqual(result["driverVerdict"], "incomplete")
            self.assertLess(result["elapsedSeconds"], 1.2)
