import unittest

from analyze_adx_playtest import parse_adx, TAG, INSTALLED

ENV = {'REO_NATIVE_ADX_BLOCK':'1', 'REO_NATIVE_ADX_BLOCK_TRACE':'1'}
FIRST = TAG + 'native op=keyed-mono calls=1 blocks=16 marker=0'


class AdxEvidenceTests(unittest.TestCase):
    def test_setting_and_installation_do_not_prove_work(self):
        for lines in ([], [INSTALLED]):
            self.assertEqual(parse_adx(lines, ENV)['native_call_lower_bound'], 0)

    def test_sparse_counts_do_not_extrapolate_pcm_samples(self):
        result = parse_adx(['prefix' + INSTALLED, FIRST,
            TAG + 'native op=keyed-mono calls=8 blocks=2 marker=1',
            TAG + 'native op=keyed-mono calls=16 blocks=0 marker=1'], ENV)
        self.assertEqual(result['native_call_lower_bound'], 16)
        self.assertEqual(result['sampled_pcm_sample_lower_bound'], 18*32)

    def test_unavailable_notice_preserved(self):
        notice = TAG + 'unavailable; original decoder retained'
        self.assertEqual(parse_adx([notice], ENV)['notices'][0]['text'], notice)

    def test_bad_provenance_order_and_counts_reject(self):
        for lines, env in [([FIRST], ENV), ([INSTALLED, FIRST, FIRST], ENV),
            ([INSTALLED, INSTALLED], ENV), ([INSTALLED], {}),
            ([INSTALLED,FIRST], ENV | {'REO_NATIVE_ADX_BLOCK_TRACE':'0'}),
            ([INSTALLED,FIRST.replace('blocks=16','blocks=17')], ENV),
            ([INSTALLED,FIRST.replace('blocks=16','blocks=0')], ENV),
            ([INSTALLED,FIRST.replace('marker=0','marker=2')], ENV)]:
            with self.subTest(lines=lines, env=env), self.assertRaises(ValueError):
                parse_adx(lines, env)


if __name__ == '__main__':
    unittest.main()
