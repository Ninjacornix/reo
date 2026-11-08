"""Space-policy admission with declared completed-build records, no compiler/game."""
import copy
import json
from pathlib import Path
import tempfile
import unittest

import build_sjuni_candidate as candidate


class CachedAudioRetryTests(unittest.TestCase):
    def setUp(self):
        self.original_root = candidate.ROOT
        self.allowed = (self.original_root / 'build-native-sjuni').resolve()
        self.temporary = tempfile.TemporaryDirectory(prefix='cached-retry-check-', dir=self.allowed)
        self.root = Path(self.temporary.name).resolve()
        self.assertTrue(self.root.is_relative_to(self.allowed))
        candidate.ROOT = self.root
        self.base = self.root / 'build-native-sjuni'
        self.parent, self.work = self.base / 'old-work', self.base / 'new-work'
        self.output = self.base / 'old-game'
        self.old_kit, self.kit = self.base / 'old-kit', self.base / 'new-kit'
        self.body = 'source/recomp/overrides/native_adxt/ordinary_runtime.cpp'
        self.header = 'source/example.hpp'
        self.identity = dict(toolchain=dict(compiler_sha256='same-declared-compiler'), disc_elf_sha256='same-declared-elf')
        for kit, body in ((self.old_kit, 'old bounded body'), (self.kit, 'new bounded body')):
            self.write(kit / self.body, body)
            self.write(kit / self.header, 'identical header')
            self.write(kit / 'compile-plan.json', 'identical complete plan')
        self.old_manifest = self.manifest(self.old_kit)
        self.manifest_value = self.manifest(self.kit)
        self.write(self.old_kit / 'build-kit.json', self.old_manifest)
        self.write(self.parent / 'candidate-build-inputs.json',
                   dict(self.identity, candidate_manifest_sha256=candidate.sha(self.old_kit / 'build-kit.json')))
        self.write(self.parent / 'candidate-build.log', 'Local game compiled: 1 units, 0 reused\n')
        self.write(self.output / 'reo_recomp.exe', 'declared linked executable')
        self.result = dict(status='passed', game_linked=True, preflight_only=False,
                           command=['declared-worker', '--kit', str(self.old_kit), '--output', str(self.output)],
                           executable_sha256=candidate.sha(self.output / 'reo_recomp.exe'),
                           build_log_sha256=candidate.sha(self.parent / 'candidate-build.log'))
        self.write(self.work / 'objects' / 'unit.obj', 'declared object bytes')
        self.write(self.work / 'objects' / 'unit.json', dict(input='declared input signature'))
        self.seed = dict(source=str(self.parent),
                         source_inputs_sha256=candidate.sha(self.parent / 'candidate-build-inputs.json'),
                         copied_objects=dict(unit=dict(object_sha256=candidate.sha(self.work / 'objects/unit.obj'),
                                                       receipt_sha256=candidate.sha(self.work / 'objects/unit.json'))))
        self.save_result()

    def tearDown(self):
        candidate.ROOT = self.original_root
        self.assertTrue(self.root.is_relative_to(self.allowed))
        self.temporary.cleanup()

    @staticmethod
    def write(path, value):
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(json.dumps(value) if isinstance(value, dict) else value, encoding='utf-8', newline='\n')

    def manifest(self, kit):
        return dict(files=[dict(path=p.relative_to(kit).as_posix(), sha256=candidate.sha(p))
                           for p in sorted(kit.rglob('*')) if p.is_file()])

    def save_result(self):
        self.write(self.parent / 'candidate-build-result.json', self.result)
        self.seed['source_result_sha256'] = candidate.sha(self.parent / 'candidate-build-result.json')
        self.write(self.work / 'seeded-object-cache.json', self.seed)

    def run_policy(self):
        return candidate.verified_audio_cache_retry(self.kit, self.work, self.identity, self.manifest_value)

    def test_bounded_retry_records_complete_cache_and_normal_four_gib_reserve(self):
        result = self.run_policy()
        self.assertEqual(result['minimum_free_bytes'], 4 * 1024 ** 3)
        self.assertEqual(result['copied_pairs'], 1)
        self.assertTrue(result['verified_retry'])

    def test_different_compiler_refuses(self):
        self.identity = copy.deepcopy(self.identity)
        self.identity['toolchain']['compiler_sha256'] = 'foreign'
        with self.assertRaisesRegex(ValueError, 'matching full game'):
            self.run_policy()

    def test_changed_plan_refuses(self):
        self.write(self.kit / 'compile-plan.json', 'changed flags')
        with self.assertRaisesRegex(ValueError, 'identical complete compile plan'):
            self.run_policy()

    def test_changed_header_refuses(self):
        self.write(self.kit / self.header, 'changed header')
        self.manifest_value = self.manifest(self.kit)
        with self.assertRaisesRegex(ValueError, 'all other inputs must match'):
            self.run_policy()

    def test_oversized_translation_refuses(self):
        self.write(self.kit / self.body, 'x' * 65537)
        self.manifest_value = self.manifest(self.kit)
        with self.assertRaisesRegex(ValueError, 'small ordinary ADXT'):
            self.run_policy()

    def test_changed_object_refuses(self):
        self.write(self.work / 'objects/unit.obj', 'corrupt object')
        with self.assertRaisesRegex(ValueError, 'object/receipt changed'):
            self.run_policy()

    def test_incomplete_cohort_refuses(self):
        self.seed['copied_objects'] = {}
        self.save_result()
        with self.assertRaisesRegex(ValueError, 'complete successful parent object cohort'):
            self.run_policy()

    def test_failed_parent_refuses(self):
        self.result['status'] = 'failed'
        self.save_result()
        with self.assertRaisesRegex(ValueError, 'completed matching full game'):
            self.run_policy()

    def test_changed_parent_log_refuses(self):
        self.write(self.parent / 'candidate-build.log', 'fabricated completion')
        with self.assertRaisesRegex(ValueError, 'parent build log changed'):
            self.run_policy()

    def test_changed_parent_executable_refuses(self):
        self.write(self.output / 'reo_recomp.exe', 'replaced executable')
        with self.assertRaisesRegex(ValueError, 'parent executable identity changed'):
            self.run_policy()


if __name__ == '__main__':
    unittest.main()
