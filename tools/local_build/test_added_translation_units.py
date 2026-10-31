"""A refreshed game kit must link its new authored unit under the audited ABI."""
import unittest
from refresh_inputs import add_translation_units


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


if __name__ == '__main__':
    unittest.main()
