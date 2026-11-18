import unittest

from analyze_resource_playtest import parse_native, READ_TAG, SCALAR_TAG, SCALAR_INSTALLED

SETUP = READ_TAG + 'mounted import=1 sources=86 route=' + 'a'*64 + ' manifest=' + 'b'*64 + \
        ' overlay=none mode=synchronous-exact maxBytes=8388608'
ENV = {'REO_NATIVE_RESOURCE_READS':'1', 'REO_GAME_PAK':'1', 'REO_CD_ASYNC':'0',
       'REO_NATIVE_DISC_STREAM':'1', 'REO_NATIVE_DISC_STREAM_TRACE':'1'}


class NativeEvidenceTests(unittest.TestCase):
    def test_setting_alone_is_not_capability_or_execution(self):
        result = parse_native([], ENV)
        self.assertEqual(result['resource_setup'], [])
        self.assertEqual(result['payload_success_lower_bound'], 0)

    def test_setup_alone_is_not_payload(self):
        result = parse_native(['other logger' + SETUP], ENV)
        self.assertEqual(len(result['resource_setup']), 1)
        self.assertEqual(result['payload_success_lower_bound'], 0)

    def test_sampled_proof_and_failures_remain_separate(self):
        result = parse_native([SETUP, READ_TAG + 'payload successes=1 lba=16777216 sectors=2 bytes=4096',
            READ_TAG + 'payload failed disposition=2 resource=4 bytes=0; no legacy retry',
            READ_TAG + 'payload exception; no legacy retry',
            READ_TAG + 'payload successes=8 lba=16777217 sectors=1 bytes=2048'], ENV)
        self.assertEqual(result['payload_success_lower_bound'], 8)
        self.assertEqual(len(result['payload_failures']), 2)

    def test_scalar_install_and_sampled_commits(self):
        result = parse_native([SCALAR_TAG + SCALAR_INSTALLED,
            '[prefix]' + SCALAR_TAG + 'native op=seek calls=1 slot=39',
            SCALAR_TAG + 'native op=seek calls=8 slot=2'], ENV)
        self.assertEqual(result['scalar_body_proofs']['seek']['body_count_lower_bound'], 8)

    def test_bad_provenance_and_malformed_counts_reject(self):
        payload = READ_TAG + 'payload successes=1 lba=16777216 sectors=1 bytes=2048'
        scalar = SCALAR_TAG + 'native op=seek calls=1 slot=0'
        for lines, env in [([payload], ENV), ([SETUP], ENV | {'REO_CD_ASYNC':'1'}),
            ([SETUP,payload,payload], ENV),
            ([SETUP,payload.replace('bytes=2048','bytes=2047')], ENV),
            ([SETUP.replace('maxBytes=8388608','maxBytes=2048'),
              payload.replace('sectors=1 bytes=2048','sectors=2 bytes=4096')], ENV),
            ([SETUP,SETUP], ENV), ([scalar], ENV),
            ([SCALAR_TAG+SCALAR_INSTALLED,scalar], ENV | {'REO_NATIVE_DISC_STREAM_TRACE':'0'}),
            ([SCALAR_TAG+SCALAR_INSTALLED,scalar.replace('slot=0','slot=40')], ENV)]:
            with self.subTest(lines=lines, env=env), self.assertRaises(ValueError):
                parse_native(lines, env)


if __name__ == '__main__':
    unittest.main()
