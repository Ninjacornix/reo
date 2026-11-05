import unittest

from analyze_cd_owner_playtest import owner_records, TAG, REGISTERED, JOINED


class OwnerProofTests(unittest.TestCase):
    def test_read_does_not_prove_callback(self):
        result = owner_records([TAG + REGISTERED, TAG + 'read lsn=1 n=2 dst=00400000 result=ok'])
        self.assertEqual(result['callback_return_lower_bound'], 0)
        self.assertEqual(len(result['logged_reads']), 1)
        self.assertEqual(result['joins'], [])

    def test_return_is_sampled_lower_bound(self):
        result = owner_records([TAG + REGISTERED, TAG + 'completion calls=1 dispatches=2',
                                TAG + 'completion calls=4 dispatches=1', TAG + JOINED])
        self.assertEqual(result['callback_return_lower_bound'], 4)
        self.assertEqual(result['errors'], [])

    def test_specific_errors_are_not_lost(self):
        messages = ['completion stopped: synthetic', 'completion dispatch limit at 00100508',
                    'completion continuation unregistered at 00100508', 'worker join failed',
                    'runtime stop raised during session cleanup', 'completion metadata changed']
        result = owner_records([TAG + REGISTERED] + [TAG + x for x in messages])
        self.assertEqual(len(result['errors']), len(messages))

    def test_false_read_is_an_error(self):
        result = owner_records([TAG + REGISTERED, TAG + 'read lsn=1 n=2 dst=00400000 result=FAIL'])
        self.assertEqual(len(result['errors']), 1)

    def test_empty_is_not_recording(self):
        self.assertEqual(owner_records(['unrelated'])['registrations'], [])

    def test_runtime_prefix_without_newline(self):
        result = owner_records(['ELF file loaded.' + TAG + REGISTERED,
            '[SifInitRpc] re-init' + TAG + 'read lsn=1 n=2 dst=00400000 result=ok',
            TAG + 'completion calls=1 dispatches=1[other logger]',
            '[run] exiting loop, activeThreads=0' + TAG + JOINED])
        self.assertEqual(len(result['registrations']), 1)
        self.assertEqual(len(result['joins']), 1)
        self.assertEqual(len(result['logged_reads']), 1)
        self.assertEqual(result['callback_return_lower_bound'], 1)

    def test_invalid_proof_rejects(self):
        cases = [
            [TAG + 'completion calls=1 dispatches=1'],
            [TAG + REGISTERED, TAG + REGISTERED],
            [TAG + REGISTERED, TAG + 'completion calls=1 dispatches=0'],
            [TAG + REGISTERED, TAG + 'completion calls=1 dispatches=257'],
            [TAG + REGISTERED, TAG + 'completion calls=2 dispatches=1', TAG + 'completion calls=1 dispatches=1'],
            [TAG + JOINED, TAG + REGISTERED],
            [TAG + REGISTERED, TAG + JOINED, TAG + 'completion calls=1 dispatches=1'],
        ]
        for lines in cases:
            with self.subTest(lines=lines), self.assertRaises(ValueError):
                owner_records(lines)


if __name__ == '__main__':
    unittest.main()
