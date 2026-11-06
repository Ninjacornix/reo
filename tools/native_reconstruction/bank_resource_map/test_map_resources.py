"""Synthetic wrapper field and range tests; never use owned payload fixtures."""
import unittest

import map_resources as m


class WrapperFields(unittest.TestCase):
    def test_literal_pair_order(self):
        parts=m.checked_parts([0,4,64,80,144,96,240,32,272,48],320)
        self.assertEqual({n:(p['offset'],p['bytes'])for n,p in parts.items()},
                         dict(hd=(64,80),bd=(144,96),tq=(240,32),tsb=(272,48)))

    def test_rounding_is_not_raw_size(self):
        parts=m.checked_parts([0,4,64,17,96,31,128,16,144,16],160)
        self.assertEqual(parts['hd']['rounded_transfer_bytes'],32)
        self.assertEqual(parts['bd']['rounded_transfer_bytes'],32)

    def test_refuses_outside_part(self):
        self.assertIsNone(m.checked_parts([0,4,64,80,144,96,240,32,272,49],320))
        self.assertIsNone(m.checked_parts([0,4,321,0,144,96,240,32,272,48],320))

    def test_empty_partial_parts_not_fabricated(self):
        result=m.checked_parts([0,4,64,80,144,96,0,0,0,0],240)
        self.assertEqual(result['tq']['bytes'],0)
        self.assertEqual(result['tsb']['rounded_transfer_bytes'],0)

    def test_name_normalization_not_pairing(self):
        self.assertEqual(m.normalized('common.snd'),'COMMON_SND')
        self.assertNotEqual(m.normalized('battle_usa.adx'),'DEMO_BATTLE_ADX')


if __name__=='__main__':unittest.main()
