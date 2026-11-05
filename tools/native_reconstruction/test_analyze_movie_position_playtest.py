import unittest
from analyze_movie_position_playtest import INSTALLED, parse

ENV = dict(REO_NATIVE_MOVIE_POSITION='1', REO_NATIVE_MOVIE_POSITION_TRACE='1')


def body(value):
    return f'[NATIVE-MOVIE-POSITION] native op=publish calls={value}'


class MoviePublicationEvidenceTests(unittest.TestCase):
    def test_selection_does_not_prove_body_execution(self):
        self.assertEqual(parse([], {})['status'], 'not-requested')
        self.assertEqual(parse([], ENV)['status'], 'requested-without-installation-proof')
        self.assertEqual(parse([INSTALLED], ENV)['status'], 'installed-without-body-proof')
        self.assertIsNone(parse([INSTALLED], ENV)['successful_publications_lower_bound'])

    def test_sparse_committed_counter_supplies_lower_bound(self):
        result = parse([INSTALLED, body(1), body(2), body(4), body(8), body(1024)], ENV)
        self.assertEqual(result['status'], 'native-publication-observed')
        self.assertEqual(result['successful_publications_lower_bound'], 1024)
        self.assertEqual(result['body_observations'][-1]['line'], 6)

    def test_refused_or_contradictory_evidence_is_explicit(self):
        unavailable = '[NATIVE-MOVIE-POSITION] installation unavailable; original publisher retained'
        self.assertEqual(parse([unavailable], ENV)['status'], 'unavailable')
        for lines, env in [([INSTALLED], {}), ([INSTALLED, INSTALLED], ENV),
                ([INSTALLED, unavailable], ENV), ([body(1)], ENV),
                ([INSTALLED, body(0)], ENV), ([INSTALLED, body(6)], ENV),
                ([INSTALLED, body(1 << 64)], ENV), ([INSTALLED, body(4), body(2)], ENV),
                ([INSTALLED, body(4), body(4)], ENV),
                ([INSTALLED, body(1)], dict(ENV, REO_NATIVE_MOVIE_POSITION_TRACE='0'))]:
            with self.subTest(lines=lines, env=env):
                result = parse(lines, env)
                self.assertEqual(result['status'], 'invalid-evidence')
                self.assertIsNone(result['successful_publications_lower_bound'])


if __name__ == '__main__':
    unittest.main()
