"""Separate audited helper inputs from ordinary CPU game sources."""
import hashlib
import json
from pathlib import Path
import tempfile
import unittest

from source_recipes import apply_plan


class RecipeInputTests(unittest.TestCase):
    def run_plan(self, *, audit_body, ordinary_body):
        with tempfile.TemporaryDirectory(prefix='reo-recipe-source-') as directory:
            root = Path(directory)
            generated = root / 'generated'
            ordinary = generated / 'output/helper.cpp'
            ordinary.parent.mkdir(parents=True)
            ordinary.write_text(ordinary_body)
            if audit_body is not None:
                audit = generated / 'audit_sources/output/helper.cpp'
                audit.parent.mkdir(parents=True)
                audit.write_text(audit_body)
            image = bytes(64)  # No program segments or instruction witnesses in this fixture.
            elf = root / 'synthetic.elf'
            elf.write_bytes(image)
            expected = 'tracked_helper\n'
            sha = lambda data: hashlib.sha256(data).hexdigest()
            plan = root / 'recipes.json'
            plan.write_text(json.dumps({'format': 1, 'elfSha256': sha(image), 'recipes': [{
                'source': 'output/helper.cpp', 'destination': 'helper.inc',
                'baseSha256': sha(expected.encode()), 'resultSha256': sha(expected.encode()),
                'parts': [['copy', 0, len(expected)]]}]}))
            count = apply_plan(elf, generated, plan, root / 'result')
            self.assertEqual(count, 1)
            self.assertEqual((root / 'result/helper.inc').read_text(), expected)
            self.assertEqual(ordinary.read_text(), ordinary_body)

    def test_player_build_uses_separate_exact_audit_input(self):
        self.run_plan(audit_body='tracked_helper\n', ordinary_body='ordinary_cpu_game\n')

    def test_guarded_build_uses_its_existing_source(self):
        self.run_plan(audit_body=None, ordinary_body='tracked_helper\n')

    def test_invalid_audit_copy_cannot_fall_back_to_matching_game_source(self):
        with self.assertRaisesRegex(ValueError, 'differs from this instrumentation recipe'):
            self.run_plan(audit_body='changed_helper\n', ordinary_body='tracked_helper\n')

    def test_plain_body_cannot_satisfy_a_tracked_helper_recipe(self):
        with self.assertRaisesRegex(ValueError, 'differs from this instrumentation recipe'):
            self.run_plan(audit_body=None, ordinary_body='ordinary_cpu_game\n')


if __name__ == '__main__':
    unittest.main()
