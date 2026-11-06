import copy
import unittest
from prepare_native_candidate import apply_sound_ram_cohort


class SoundCandidateCohort(unittest.TestCase):
    def plan(self):
        return {'units':[
            {'id':'sdk-runtime','archive':'runtime','options':['/DWIN32','/Icohort']},
            {'id':'gpu-static','archive':'backend','options':['/O2']},
            {'id':'game','options':['/DREO_GAME_FILE1']},
            {'id':'native-audio','options':['/DREO_BUILD_NATIVE_AUDIO=1']},
            {'id':'c-provider','language':'c','options':['/DMA_PERIODS=2']} ]}

    def test_rebuilds_runtime_and_backend_as_well_as_game(self):
        value=self.plan()
        before=copy.deepcopy(value)
        apply_sound_ram_cohort(value)
        for old,new in zip(before['units'],value['units']):
            if old.get('language')=='c':
                self.assertEqual(old,new)
            else:
                self.assertNotEqual(old['options'],new['options'])
                self.assertEqual(new['options'].count('/DREO_BUILD_NATIVE_SOUND_RAM_CAPTURE=2'),1)
                self.assertEqual(new['options'][:-1],old['options'])

    def test_repeated_selection_preserves_the_same_cohort(self):
        value=self.plan()
        apply_sound_ram_cohort(value)
        before=copy.deepcopy(value)
        apply_sound_ram_cohort(value)
        self.assertEqual(value,before)

    def test_foreign_sdk_flag_refuses_before_plan_changes(self):
        for invalid in ('/DREO_BUILD_NATIVE_SOUND_RAM_CAPTURE=0',
                        '/DREO_BUILD_NATIVE_SOUND_RAM_CAPTURE=1',
                        '/DREO_BUILD_NATIVE_SOUND_RAM_CAPTURE'):
            value=self.plan()
            value['units'][2]['options'].append(invalid)
            before=copy.deepcopy(value)
            with self.assertRaises(ValueError):
                apply_sound_ram_cohort(value)
            self.assertEqual(value,before)

    def test_generated_batches_inherit_the_same_definition(self):
        value=self.plan()
        value['sourceGroups']=[{'id':'generated-main','root':'{generated}/output','options':['/O2']},
                               {'id':'generated-overlay','root':'{generated}/overlay','options':[]}]
        apply_sound_ram_cohort(value)
        for group in value['sourceGroups']:
            self.assertIn('/DREO_BUILD_NATIVE_SOUND_RAM_CAPTURE=2',group['options'])

    def test_late_generated_conflict_does_not_partially_change_units(self):
        value=self.plan()
        value['sourceGroups']=[{'id':'generated-main','options':['/DREO_BUILD_NATIVE_SOUND_RAM_CAPTURE=1']}]
        before=copy.deepcopy(value)
        with self.assertRaises(ValueError):
            apply_sound_ram_cohort(value)
        self.assertEqual(value,before)

    def test_common_definition_is_validated_and_not_duplicated(self):
        value=self.plan()
        value['compileOptions']=['/DREO_BUILD_NATIVE_SOUND_RAM_CAPTURE=1']
        before=copy.deepcopy(value)
        with self.assertRaises(ValueError):
            apply_sound_ram_cohort(value)
        self.assertEqual(value,before)
        value['compileOptions']=['/DREO_BUILD_NATIVE_SOUND_RAM_CAPTURE=2']
        before=copy.deepcopy(value)
        apply_sound_ram_cohort(value)
        self.assertEqual(value,before)


if __name__=='__main__':
    unittest.main()
