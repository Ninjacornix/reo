import copy
import unittest

from compilation_batches import GENERATED_BATCH_SIZE, with_generated_batches


class CompilationBatchTests(unittest.TestCase):
    def test_only_default_generated_group_limits_change(self):
        plan = {
            "runtimeAbi": "unchanged",
            "compileOptions": ["/fp:precise"],
            "units": [{"id": "special", "sources": ["override.cpp"], "options": ["/Od"]}],
            "sourceGroups": [
                {"id": "main", "batch": 8, "exclude": ["special.cpp"], "options": ["/DMAIN"]},
                {"id": "overlay", "root": "output_ovl", "pattern": "**/*.cpp"},
                {"id": "extra", "batch": 8},
                {"id": "legacy", "batch": 1},
                {"id": "custom", "batch": 8},
            ],
            "generatedSourceOverrides": {"special.cpp": "override.cpp"},
        }
        original = copy.deepcopy(plan)
        updated = with_generated_batches(plan)
        expected = copy.deepcopy(plan)
        for group in expected["sourceGroups"][:3]:
            group["batch"] = GENERATED_BATCH_SIZE
        self.assertEqual(updated, expected)
        self.assertEqual(plan, original)
        self.assertEqual(with_generated_batches(updated), updated)

    def test_explicit_nondefault_limits_are_preserved(self):
        for limit in (1, 4, 16, 32, 64):
            plan = {"sourceGroups": [{"id": "main", "batch": limit}]}
            self.assertEqual(with_generated_batches(plan), plan)

    def test_release_retains_original_grouping(self):
        self.assertEqual(GENERATED_BATCH_SIZE, 8)
        plan = {"sourceGroups": [{"id": "main", "batch": 8}]}
        self.assertEqual(with_generated_batches(plan), plan)
        self.assertEqual(with_generated_batches(plan, batch_size=64)["sourceGroups"][0]["batch"], 64)


if __name__ == "__main__":
    unittest.main()
