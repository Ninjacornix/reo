"""PAK-only harness isolation checks; no game or imported resource is opened."""
import copy
from pathlib import Path
import unittest

from coop_playtest import pak_only_environment, environment

ROOT = Path(__file__).resolve().parents[2]


class PakOnlyTests(unittest.TestCase):
    def fixture(self):
        folder = ROOT/'build-native-sjuni/test-pak-mode-never-created'
        player = dict(workingDirectory=str(folder/'player1/work'), card='private-card', map='private-map')
        record = dict(game='file1', players=[player], mountedIso=False, iso='original.iso')
        return folder, record, player

    def test_private_unavailable_path(self):
        folder, record, player = self.fixture()
        before = dict(REO_ISO='original.iso', REO_NATIVE_CD_OWNER='1')
        result = pak_only_environment(folder, record, player, before)
        self.assertEqual(before['REO_ISO'], 'original.iso')
        self.assertEqual(result['REO_GAME_PAK'], '1')
        self.assertEqual(result['REO_NATIVE_CD_OWNER'], '1')
        self.assertTrue(Path(result['REO_ISO']).is_relative_to(folder))
        self.assertFalse(Path(result['REO_ISO']).exists())
        self.assertEqual(record['iso'], 'original.iso')

    def test_scope_refusals(self):
        folder, record, player = self.fixture()
        cases = []
        cases.append((ROOT, record, player))
        cases.append((ROOT/'build-native-sjuni', record, player))
        cases.append((folder, record | {'game':'file2'}, player))
        cases.append((folder, record | {'players':[player, player]}, player))
        cases.append((folder, record | {'mountedIso':True}, player))
        cases.append((folder, record, player | {'workingDirectory':str(ROOT)}))
        for case in cases:
            with self.subTest(case=case), self.assertRaises(ValueError):
                pak_only_environment(*case, {})

    def test_extra_config_cannot_replace_pinned_iso(self):
        _, record, player = self.fixture()
        with self.assertRaises(ValueError):
            environment(record, player, {'REO_ISO':'another-user-image.iso'})


if __name__ == '__main__':
    unittest.main()
