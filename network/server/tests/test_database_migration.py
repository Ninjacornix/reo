# SPDX-License-Identifier: AGPL-3.0-only
"""Upgrade real SQLite stores using synthetic pre-RC2 account/result data."""
from concurrent.futures import ThreadPoolExecutor
from contextlib import closing
import json
from pathlib import Path
import sqlite3
import tempfile
import threading
import unittest
from unittest.mock import patch

from opensnap.core.accounts import (
    encode_password_record, seal_kage_login_key, verify_password,
)
from opensnap.core.records import Ranking
from opensnap.storage.sql import SqlAccountStore, SqlRecordStore
from opensnap.storage.sqlite import SqliteConnection


SECRET = 'synthetic-migration-test-secret'
PASSWORD = 'testpassword123'


class DatabaseMigrationTests(unittest.TestCase):
    def setUp(self):
        self.temporary = tempfile.TemporaryDirectory(prefix='reo-schema-test-')
        self.addCleanup(self.temporary.cleanup)
        self.path = Path(self.temporary.name) / 'opensnap.db'

    def legacy(self, *, kage=True):
        with closing(sqlite3.connect(self.path)) as db, db:
            db.execute(
                'CREATE TABLE users (user_id INTEGER PRIMARY KEY, username TEXT NOT NULL UNIQUE, '
                "password TEXT NOT NULL, seed TEXT NOT NULL, team TEXT NOT NULL DEFAULT ''"
                + (', kage_login_key TEXT' if kage else '') + ')'
            )
            db.execute(
                'CREATE TABLE records (record_id INTEGER PRIMARY KEY AUTOINCREMENT, '
                'game TEXT NOT NULL, board TEXT NOT NULL, user_id INTEGER NOT NULL, '
                'player TEXT NOT NULL, score INTEGER NOT NULL, details TEXT NOT NULL, '
                'recorded_at TEXT NOT NULL)'
            )
            db.execute('CREATE INDEX records_board ON records (game, board, score)')
            for user_id, name in ((7, 'alice'), (12, 'bobs')):
                seed = 'synthetic-seed-' + name
                db.execute('INSERT INTO users (user_id, username, password, seed, team) VALUES (?, ?, ?, ?, ?)',
                           (user_id, name, encode_password_record(PASSWORD, seed), seed, 'test-team'))
                if kage:
                    db.execute('UPDATE users SET kage_login_key = ? WHERE user_id = ?',
                               (seal_kage_login_key(SECRET, name, b'test-key'), user_id))

    def add(self, game, board, score, *, user=7, character=0, time='2026-10-01T12:00:00+00:00'):
        with closing(sqlite3.connect(self.path)) as db, db:
            db.execute(
                'INSERT INTO records (game, board, user_id, player, score, details, recorded_at) '
                'VALUES (?, ?, ?, ?, ?, ?, ?)',
                (game, board, user, 'alice' if user == 7 else 'bobs', score,
                 json.dumps({'character': character}), time),
            )

    def open(self):
        connection = SqliteConnection(self.path)
        self.addCleanup(connection.close)
        return connection

    def snapshot(self):
        with closing(sqlite3.connect(self.path)) as db, db:
            return '\n'.join(db.iterdump())

    def test_legacy_accounts_keep_identity_credentials_team_and_kage_key(self):
        self.legacy()
        with closing(sqlite3.connect(self.path)) as db, db:
            before = db.execute('SELECT * FROM users ORDER BY user_id').fetchall()
        connection = self.open()
        accounts = SqlAccountStore(connection, server_secret=SECRET)
        codes = []
        for user_id, name in ((7, 'alice'), (12, 'bobs')):
            account = accounts.get_by_name(name)
            self.assertEqual(account.user_id, user_id)
            self.assertTrue(verify_password(account, PASSWORD))
            self.assertFalse(verify_password(account, 'wrong-password'))
            self.assertEqual(account.team, 'test-team')
            self.assertEqual(account.kage_login_key, b'test-key')
            self.assertEqual(len(account.recovery_code), 12)
            codes.append(account.recovery_code)
        self.assertNotEqual(*codes)
        after = [tuple(row)[:-1] for row in connection.query_all('SELECT * FROM users ORDER BY user_id')]
        self.assertEqual(after, before)
        fresh = accounts.create_user('new-user', PASSWORD)
        self.assertGreater(fresh.user_id, 12)

    def test_older_accounts_without_kage_column_still_log_in_and_recover(self):
        self.legacy(kage=False)
        accounts = SqlAccountStore(self.open(), server_secret=SECRET)
        account = accounts.get_by_id(7)
        self.assertEqual(account.kage_login_key, b'')
        self.assertTrue(verify_password(account, PASSWORD))
        recovered = accounts.recover('alice', account.recovery_code, 'replacement-password')
        self.assertIsNotNone(recovered)
        self.assertTrue(verify_password(recovered, 'replacement-password'))
        self.assertIsNone(accounts.recover('alice', account.recovery_code, 'wrong-repeat'))

    def test_both_editions_keep_best_clears_and_sum_old_scenario_points(self):
        self.legacy()
        for game in ('outbreak', 'outbreak2'):
            self.add(game, 'clear-0-0', 900, character=1)
            self.add(game, 'clear-0-0', 600, character=2, time='2026-10-02T12:00:00+00:00')
            self.add(game, 'clear-0-0', 600, character=3, time='2026-10-03T12:00:00+00:00')
            self.add(game, 'clear-0-0', 750, user=12)
            self.add(game, 'points-0', 100)
            self.add(game, 'points-1', 250, time='2026-10-02T12:00:00+00:00')
            self.add(game, 'points-1', 50, user=12)
        connection = self.open()
        records = SqlRecordStore(connection)
        for game in ('outbreak', 'outbreak2'):
            clear = records.top(game, 'clear-0-0', 10)
            self.assertEqual([(row.user_id, row.score) for row in clear], [(7, 600), (12, 750)])
            self.assertEqual(clear[0].details, {'character': 2})
            self.assertEqual(clear[0].reached_at, '2026-10-02T12:00:00+00:00')
            points = records.top(game, 'points', 10)
            self.assertEqual([(row.user_id, row.score) for row in points], [(7, 350), (12, 50)])
            self.assertEqual(set(records.boards(game)), {'clear-0-0', 'points'})
            self.assertEqual(records.entry(game, 'clear-0-0', 12).rank, 2)
        self.assertEqual(connection.query_one('SELECT COUNT(*) AS n FROM records_legacy_v1')['n'], 14)

    def test_new_results_update_migrated_unique_rows(self):
        self.legacy()
        self.add('outbreak', 'points-0', 10)
        self.add('outbreak', 'clear-0-0', 500)
        connection = self.open()
        store = SqlRecordStore(connection)
        store.submit(game='outbreak', board='points', ranking=Ranking.TOTAL,
                     user_id=7, player='alice', score=20)
        store.submit(game='outbreak', board='clear-0-0', ranking=Ranking.LOWEST,
                     user_id=7, player='alice', score=400, details={'character': 4})
        self.assertEqual(store.top('outbreak', 'points', 10)[0].score, 30)
        self.assertEqual(store.top('outbreak', 'clear-0-0', 10)[0].score, 400)
        self.assertEqual(connection.query_one('SELECT COUNT(*) AS n FROM records')['n'], 2)

    def test_archive_keeps_every_original_row_including_unknown_boards(self):
        self.legacy()
        self.add('outbreak', 'points-0', 50)
        self.add('other-game', 'custom-board', 123)
        self.add('outbreak', 'custom-board', 456)
        with closing(sqlite3.connect(self.path)) as db, db:
            before = db.execute('SELECT * FROM records ORDER BY record_id').fetchall()
        connection = self.open()
        after = [tuple(row) for row in connection.query_all('SELECT * FROM records_legacy_v1 ORDER BY record_id')]
        self.assertEqual(after, before)
        self.assertEqual(connection.query_one('SELECT COUNT(*) AS n FROM records')['n'], 1)

    def test_reopening_does_not_reimport_scores_or_change_recovery_codes(self):
        self.legacy()
        self.add('outbreak', 'points-0', 10)
        SqliteConnection(self.path).close()
        before = self.snapshot()
        for _ in range(3):
            SqliteConnection(self.path).close()
        self.assertEqual(self.snapshot(), before)

    def test_fresh_and_current_databases_stay_compatible(self):
        connection = self.open()
        account = SqlAccountStore(connection, server_secret=SECRET).create_user('fresh-user', PASSWORD)
        before = self.snapshot()
        again = self.open()
        self.assertEqual(self.snapshot(), before)
        self.assertEqual(SqlAccountStore(again, server_secret=SECRET).get_by_name('fresh-user').recovery_code,
                         account.recovery_code)
        self.assertIsNone(connection.query_one("SELECT name FROM sqlite_master WHERE name = 'records_legacy_v1'"))

    def test_failed_import_rolls_back_schema_and_account_changes(self):
        self.legacy(kage=False)
        self.add('outbreak', 'points-0', 10)
        before = self.snapshot()
        original = SqliteConnection._import_legacy_records

        def interrupted(connection):
            original(connection)
            raise RuntimeError('synthetic interrupted migration')

        with patch.object(SqliteConnection, '_import_legacy_records', interrupted):
            with self.assertRaisesRegex(RuntimeError, 'interrupted migration'):
                SqliteConnection(self.path)
        self.assertEqual(self.snapshot(), before)
        self.assertEqual(SqlRecordStore(self.open()).top('outbreak', 'points', 10)[0].score, 10)

    def test_existing_archive_is_never_overwritten(self):
        self.legacy()
        with closing(sqlite3.connect(self.path)) as db, db:
            db.execute('CREATE TABLE records_legacy_v1 (original TEXT)')
            db.execute("INSERT INTO records_legacy_v1 VALUES ('retained archive')")
        before = self.snapshot()
        with self.assertRaises(sqlite3.OperationalError):
            SqliteConnection(self.path)
        self.assertEqual(self.snapshot(), before)

    def test_four_services_can_upgrade_the_same_file_concurrently(self):
        self.legacy()
        self.add('outbreak', 'points-0', 10)
        gate = threading.Barrier(4)

        def start(_):
            gate.wait(timeout=10)
            connection = SqliteConnection(self.path)
            try:
                return (SqlAccountStore(connection, server_secret=SECRET).get_by_id(7).recovery_code,
                        SqlRecordStore(connection).top('outbreak', 'points', 10)[0].score)
            finally:
                connection.close()

        with ThreadPoolExecutor(max_workers=4) as services:
            results = list(services.map(start, range(4)))
        self.assertEqual(len(set(results)), 1)
        self.assertEqual(results[0][1], 10)


if __name__ == '__main__':
    unittest.main()
