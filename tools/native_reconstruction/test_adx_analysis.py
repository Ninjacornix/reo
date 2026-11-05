import unittest

from analyze_adx_playtest import parse_adx, TAG, INSTALLED, parse_stereo, STEREO_TAG, STEREO_INSTALLED

ENV = {'REO_NATIVE_ADX_BLOCK':'1', 'REO_NATIVE_ADX_BLOCK_TRACE':'1'}
FIRST = TAG + 'native op=keyed-mono calls=1 blocks=16 marker=0'


class AdxEvidenceTests(unittest.TestCase):
    def test_large_proof_uses_actual_installed_capability(self):
        mono = TAG + 'native op=keyed-mono calls=1 blocks=300 marker=0'
        self.assertEqual(parse_adx([INSTALLED.replace('16','512'),mono],ENV)['sampled_pcm_sample_lower_bound'],9600)
        stereo = STEREO_TAG + 'native op=stereo calls=1 pairs=150 marker=0'
        env = {'REO_NATIVE_ADX_STEREO':'1','REO_NATIVE_ADX_STEREO_TRACE':'1'}
        self.assertEqual(parse_stereo([STEREO_INSTALLED.replace('16','512'),stereo],env)
            ['operations']['stereo']['sampled_pcm_sample_lower_bound'],9600)
        for cap in ('160','513','1024'):
            with self.subTest(cap=cap),self.assertRaises(ValueError):
                parse_adx([INSTALLED.replace('16',cap)],ENV)
        with self.assertRaises(ValueError):
            parse_stereo([STEREO_INSTALLED,stereo],env)

    def test_stereo_and_downmix_counts_remain_independent(self):
        env = {'REO_NATIVE_ADX_STEREO':'1','REO_NATIVE_ADX_STEREO_TRACE':'1'}
        stereo = STEREO_TAG + 'native op=stereo calls=1 pairs=8 marker=0'
        downmix = STEREO_TAG + 'native op=downmix calls=1 pairs=0 marker=2'
        result = parse_stereo([STEREO_INSTALLED,stereo,downmix,
            STEREO_TAG + 'native op=stereo calls=8 pairs=1 marker=1'], env)
        self.assertEqual(result['operations']['stereo']['native_call_lower_bound'], 8)
        self.assertEqual(result['operations']['stereo']['sampled_pcm_sample_lower_bound'], 9*64)
        self.assertEqual(result['operations']['downmix']['sampled_pcm_sample_lower_bound'], 0)
        self.assertFalse(parse_stereo([], env)['installations'])
        for lines, bad_env in [([stereo],env),([STEREO_INSTALLED],{}),
            ([STEREO_INSTALLED,stereo,stereo],env),
            ([STEREO_INSTALLED,stereo.replace('pairs=8','pairs=9')],env),
            ([STEREO_INSTALLED,stereo.replace('marker=0','marker=3')],env),
            ([STEREO_INSTALLED,stereo], env | {'REO_NATIVE_ADX_STEREO_TRACE':'0'})]:
            with self.subTest(lines=lines), self.assertRaises(ValueError):
                parse_stereo(lines,bad_env)

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
