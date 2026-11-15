"""A refreshed game kit must link its new authored unit under the audited ABI."""
from pathlib import Path
import subprocess
import tempfile
import unittest
from refresh_inputs import add_translation_units, apply_sdk_patch


class TranslationUnitTests(unittest.TestCase):
    def plan(self):
        return {'units': [{'id': 'authored0', 'sources': ['{work}/project/network/native/snap_iop_transport.cpp'],
                           'options': ['/DREO_GAME_FILE2', '/I{work}/project/runtime']}]}

    def test_new_unit_preserves_edition_and_include_cohort(self):
        plan = self.plan()
        new = 'network/native/native_netcode.cpp'
        add_translation_units(plan, [(new, 'network/native/snap_iop_transport.cpp')])
        self.assertEqual(plan['units'][-1]['sources'], ['{work}/project/' + new])
        self.assertEqual(plan['units'][-1]['options'], plan['units'][0]['options'])
        plan['units'][-1]['options'].append('/DNEW')
        self.assertNotIn('/DNEW', plan['units'][0]['options'])

    def test_ambiguous_missing_duplicate_and_unsafe_units_refused(self):
        new, old = 'network/native/native_netcode.cpp', 'network/native/snap_iop_transport.cpp'
        for name, template in [(new, 'missing.cpp'), (old, old), ('../escape.cpp', old), ('header.h', old)]:
            with self.subTest(name=name, template=template), self.assertRaises(ValueError):
                add_translation_units(self.plan(), [(name, template)])

    def test_apply_sdk_patch_modifies_targets_inside_git_subdirectory(self):
        with tempfile.TemporaryDirectory(prefix='reo-sdk-patch-') as folder:
            repo = Path(folder)
            subprocess.run(['git', 'init', '-q'], cwd=repo, check=True)
            sdk = repo / 'build-ninja/v1.0.21-rc0/sdk-canonical'
            helper = sdk / 'ps2xRuntime/src/lib/Kernel/Syscalls/Helpers'
            helper.mkdir(parents=True)
            (helper / 'CriAudio.h').write_text('namespace ps2_cri_audio {\nvoid drain(uint32_t voice);\n}\n')
            (helper / 'CriAudio.cpp').write_text('namespace ps2_cri_audio {\nvoid drain(uint32_t voice) {}\n}\n')
            patch = repo / '0120.patch'
            patch.write_text(
                'diff --git a/ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/CriAudio.h '
                'b/ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/CriAudio.h\n'
                '--- a/ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/CriAudio.h\n'
                '+++ b/ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/CriAudio.h\n'
                '@@ -1,3 +1,4 @@\n'
                ' namespace ps2_cri_audio {\n'
                ' void drain(uint32_t voice);\n'
                '+void pauseNow(uint32_t voice, bool paused);\n'
                ' }\n'
                'diff --git a/ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/CriAudio.cpp '
                'b/ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/CriAudio.cpp\n'
                '--- a/ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/CriAudio.cpp\n'
                '+++ b/ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/CriAudio.cpp\n'
                '@@ -1,3 +1,4 @@\n'
                ' namespace ps2_cri_audio {\n'
                ' void drain(uint32_t voice) {}\n'
                '+void pauseNow(uint32_t voice, bool paused) {}\n'
                ' }\n'
            )
            targets = apply_sdk_patch(sdk, patch)
            self.assertEqual(len(targets), 2)
            self.assertIn('pauseNow(uint32_t voice, bool paused);', (helper / 'CriAudio.h').read_text())
            self.assertIn('pauseNow(uint32_t voice, bool paused) {}', (helper / 'CriAudio.cpp').read_text())


if __name__ == '__main__':
    unittest.main()
