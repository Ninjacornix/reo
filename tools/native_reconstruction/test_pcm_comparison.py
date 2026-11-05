import unittest

from compare_pcm_playtests import differences


class PcmArtifactComparison(unittest.TestCase):
    def test_difference_in_later_sample_is_not_lost(self):
        result = differences(b'\x00\x00\x01\x02',b'\x00\x00\x01\x03')
        self.assertFalse(result['equal'])
        self.assertEqual(result['first_difference_byte'],3)
        self.assertEqual(result['first_difference_sample'],1)

    def test_matching_prefix_does_not_hide_truncated_capture(self):
        result = differences(b'\x00\x00',b'\x00\x00\x00\x00')
        self.assertFalse(result['equal'])
        self.assertEqual(result['first_difference_byte'],2)
        self.assertTrue(differences(b'\xff\x7f',b'\xff\x7f')['equal'])


if __name__ == '__main__':
    unittest.main()
