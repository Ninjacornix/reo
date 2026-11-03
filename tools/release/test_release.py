import hashlib
import io
import json
import os
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch
import zipfile

import release


def zipped(files):
    output = io.BytesIO()
    with zipfile.ZipFile(output, 'w') as archive:
        for name, data in files.items():
            archive.writestr(name, data)
    return output.getvalue()


def inventory(files):
    return [{'path': name, 'sha256': hashlib.sha256(value).hexdigest(), 'bytes': len(value)}
            for name, value in files.items()]


def player_package(tag, source):
    dist = {'version': '1.0.20', 'releaseTag': tag, 'prerelease': True, 'revision': source}
    files = {name: b'fixture' for name in ('Outbreak.Launcher.exe', 'XINPUT1_4.dll', 'reo-movie-check.exe',
                                         'THIRD-PARTY-NOTICES.txt', 'network-server/server-manifest.json')}
    for game, archive_name, kit_key, input_key in (
            ('file1', 'build-inputs.zip', 'kitSha256', 'inputsSha256'),
            ('file2', 'build-inputs-file2.zip', 'file2KitSha256', 'file2InputsSha256')):
        sources = {'source/runtime/test.h': b'verified source'}
        manifest = json.dumps({'format': 1, 'architecture': 'win-x64', 'toolchain': 'llvm-mingw',
                               'elfSha256': release.ELFS[game], 'files': inventory(sources)}).encode()
        files[archive_name] = zipped({**sources, 'build-kit.json': manifest})
        dist[kit_key] = hashlib.sha256(manifest).hexdigest()
        dist[input_key] = hashlib.sha256(files[archive_name]).hexdigest()
    files['distribution.json'] = json.dumps(dist).encode()
    return zipped({**files, 'package-manifest.json': json.dumps(inventory(files)).encode()})


class ReleaseTests(unittest.TestCase):
    def setUp(self):
        self.directory = tempfile.TemporaryDirectory()
        self.root = Path(self.directory.name)
        self.addCleanup(self.directory.cleanup)

    def test_stable_and_prerelease_identity(self):
        self.assertEqual(release.options('v1.0.20-rc3', True, 'validate-only', True)['version'], '1.0.20')
        self.assertFalse(release.options('v1.0.20', False, 'draft', False)['prerelease'])
        for tag, kind in [('v1.0.20-rc3', False), ('v1.0.20', True), ('v01.0.20', False),
                          ('v1.0.20; echo secret', True), ('../rc3', True), ('v1.0.20\n', False)]:
            with self.subTest(tag=tag), self.assertRaises(ValueError):
                release.options(tag, kind, 'draft', True)
        with self.assertRaises(ValueError):
            release.options('v1.0.20', False, 'automatic', True)

    def test_reuse_refuses_changed_game_sources_and_recipes(self):
        release.check_reuse(['launcher/OnlineOptions.cs', '.github/workflows/release.yml',
                             'docs/CI.md', 'network/server/native/protocol.py', 'tools/release/release.py'])
        for name in ['runtime/new.h', 'recomp/config/extra_functions.csv', 'network/native/new.cpp',
                     'third_party/PS2Recomp', 'third_party/patches/new.patch', 'deps/elfio/header.hpp',
                     'CMakeLists.txt', '.gitmodules', 'tools/local_build/generate_game.py',
                     'tools/parallel_gs_backend/resident_gs/gs_renderer.cpp']:
            with self.subTest(name=name), self.assertRaisesRegex(ValueError, 'Refresh and validate'):
                release.check_reuse([name])

    def test_archive_hashes_paths_and_inventory(self):
        files = {'source/runtime/test.h': b'checked source\n'}
        listing = inventory(files)
        with zipfile.ZipFile(io.BytesIO(zipped({**files, 'build-kit.json': b'{}'}))) as archive:
            release.verify_files(archive, listing, 'build-kit.json')
        for content in [{**files, 'extra': b'unlisted', 'build-kit.json': b'{}'},
                        {'source/runtime/test.h': b'edited', 'build-kit.json': b'{}'},
                        {'../escape': b'x', 'build-kit.json': b'{}'},
                        {'FILE': b'x', 'file': b'x', 'build-kit.json': b'{}'},
                        {'C:/file': b'x', 'build-kit.json': b'{}'}]:
            with self.subTest(names=list(content)), self.assertRaises(ValueError):
                with zipfile.ZipFile(io.BytesIO(zipped(content))) as archive:
                    release.verify_files(archive, listing, 'build-kit.json')

    def test_game_edition_and_private_content(self):
        for game in ('file1', 'file2'):
            files = {'source/runtime/check.h': b'source'}
            manifest = {'format': 1, 'architecture': 'win-x64', 'toolchain': 'llvm-mingw',
                        'elfSha256': release.ELFS[game], 'files': inventory(files)}
            kit = self.root / (game + '.zip')
            kit.write_bytes(zipped({**files, 'build-kit.json': json.dumps(manifest).encode()}))
            release.verify_kit(kit, self.root / 'manifest.json', game)
            with self.assertRaises(ValueError):
                release.verify_kit(kit, self.root / 'manifest.json', 'file2' if game == 'file1' else 'file1')
            files['game.elf'] = b'private'
            manifest['files'] = inventory(files)
            kit.write_bytes(zipped({**files, 'build-kit.json': json.dumps(manifest).encode()}))
            with self.assertRaisesRegex(ValueError, 'Private'):
                release.verify_kit(kit, self.root / 'manifest.json', game)

    def make_plan(self, publication='draft', create=True, prerelease=True):
        tag = 'v1.0.20-rc3' if prerelease else 'v1.0.20'
        plan = release.options(tag, prerelease, publication, create)
        plan.update(source='a' * 40, repository='owner/repo', assets=[])
        (self.root / 'assets').mkdir()
        for name in ('player.zip', 'sources.zip'):
            path = self.root / 'assets' / name
            path.write_bytes(b'verified bytes')
            plan['assets'].append({'name': name, 'sha256': release.sha(path)})
        release.write_json(self.root / 'release-plan.json', plan)
        (self.root / 'release-notes.md').write_text('Validation limits')
        return plan

    def test_validate_only_never_creates_tag_or_release(self):
        self.make_plan(publication='validate-only')
        with patch.object(release, 'api') as api, patch.object(release, 'run') as run:
            release.publish(self.root)
        api.assert_not_called()
        run.assert_not_called()

    def publish_spies(self, plan, existing=None, corrupt_upload=False):
        calls = []
        def api(path, method='GET', data=None):
            calls.append((path, method, data))
            if '/git/ref/tags/' in path:
                return {'object': existing or {'type': 'commit', 'sha': plan['source']}}
            if '/releases/tags/' in path:
                return {'id': 1, 'html_url': 'https://example/release', 'assets':
                        [{'name': a['name'], 'digest': 'sha256:' + ('0' * 64 if corrupt_upload else a['sha256'])}
                         for a in plan['assets']]}
            return {}
        return api, calls

    def test_tag_exact_commit_then_verify_assets_before_publication(self):
        plan = self.make_plan(publication='publish')
        api, calls = self.publish_spies(plan)
        with patch.dict(os.environ, {'GITHUB_SHA': plan['source'], 'GITHUB_REPOSITORY': plan['repository']}), \
                patch.object(release, 'api', side_effect=api), patch.object(release, 'run') as run:
            release.publish(self.root)
        self.assertEqual(calls[0][2], {'ref': 'refs/tags/v1.0.20-rc3', 'sha': plan['source']})
        self.assertIn('--verify-tag', run.call_args.args)
        self.assertIn('--draft', run.call_args.args)
        self.assertEqual(calls[-1][2], {'prerelease': True, 'draft': False, 'make_latest': 'false'})

    def test_draft_stable_is_not_published_or_marked_latest(self):
        plan = self.make_plan(prerelease=False)
        api, calls = self.publish_spies(plan)
        with patch.dict(os.environ, {'GITHUB_SHA': plan['source'], 'GITHUB_REPOSITORY': plan['repository']}), \
                patch.object(release, 'api', side_effect=api), patch.object(release, 'run'):
            release.publish(self.root)
        self.assertEqual(calls[-1][2], {'prerelease': False, 'draft': True, 'make_latest': 'false'})

    def test_stable_publication_and_existing_annotated_tag(self):
        plan = self.make_plan(publication='publish', create=False, prerelease=False)
        api, calls = self.publish_spies(plan, existing={'type': 'tag', 'sha': 'c' * 40})
        def annotated(path, method='GET', data=None):
            if '/git/tags/' in path:
                calls.append((path, method, data))
                return {'object': {'type': 'commit', 'sha': plan['source']}}
            return api(path, method, data)
        with patch.dict(os.environ, {'GITHUB_SHA': plan['source'], 'GITHUB_REPOSITORY': plan['repository']}), \
                patch.object(release, 'api', side_effect=annotated), patch.object(release, 'run'):
            release.publish(self.root)
        self.assertFalse(any(method == 'POST' for _, method, _ in calls))
        self.assertEqual(calls[-1][2], {'prerelease': False, 'draft': False, 'make_latest': 'true'})

    def test_another_commits_artifact_is_refused_before_network(self):
        self.make_plan()
        with patch.dict(os.environ, {'GITHUB_SHA': 'b' * 40, 'GITHUB_REPOSITORY': 'owner/repo'}), \
                patch.object(release, 'api') as api, self.assertRaisesRegex(ValueError, 'another commit'):
            release.publish(self.root)
        api.assert_not_called()

    def test_asset_upload_mismatch_keeps_release_draft(self):
        plan = self.make_plan(publication='publish')
        api, calls = self.publish_spies(plan, corrupt_upload=True)
        with patch.dict(os.environ, {'GITHUB_SHA': plan['source'], 'GITHUB_REPOSITORY': plan['repository']}), \
                patch.object(release, 'api', side_effect=api), patch.object(release, 'run'), \
                self.assertRaisesRegex(ValueError, 'remains a draft'):
            release.publish(self.root)
        self.assertFalse(any(method == 'PATCH' for _, method, _ in calls))

    def test_existing_tag_wrong_commit_and_artifact_tampering_refused(self):
        plan = self.make_plan(create=False)
        api, _ = self.publish_spies(plan, existing={'type': 'commit', 'sha': 'b' * 40})
        with patch.dict(os.environ, {'GITHUB_SHA': plan['source'], 'GITHUB_REPOSITORY': plan['repository']}), \
                patch.object(release, 'api', side_effect=api), patch.object(release, 'run') as run:
            with self.assertRaisesRegex(ValueError, 'Existing tag'):
                release.publish(self.root)
            run.assert_not_called()
        (self.root / 'assets/player.zip').write_bytes(b'changed')
        with patch.dict(os.environ, {'GITHUB_SHA': plan['source'], 'GITHUB_REPOSITORY': plan['repository']}), \
                patch.object(release, 'api') as api, self.assertRaisesRegex(ValueError, 'hash mismatch'):
            release.publish(self.root)
        api.assert_not_called()

    def test_existing_tag_collision_does_not_create_release(self):
        plan = self.make_plan()
        with patch.dict(os.environ, {'GITHUB_SHA': plan['source'], 'GITHUB_REPOSITORY': plan['repository']}), \
                patch.object(release, 'api', side_effect=RuntimeError('Tag already exists')), \
                patch.object(release, 'run') as run, self.assertRaises(RuntimeError):
            release.publish(self.root)
        run.assert_not_called()

    def test_prepare_and_finalize_produce_complete_artifacts_without_writes_to_github(self):
        (self.root / 'launcher').mkdir()
        (self.root / 'launcher/Updates.cs').write_text('public const string DefaultVersion = "1.0.20";')
        seed, target = 'v1.0.20-rc2-hotfix', 'v1.0.20-rc3'
        downloads = {f'RE-Outbreak-{seed}-Windows-x64.zip': player_package(seed, 'b' * 40),
                     f'RE-Outbreak-{seed}-Dependency-Sources.zip': zipped({'LICENSE': b'independent sources'})}
        metadata = {'prerelease': True, 'draft': False, 'assets':
                    [{'name': name, 'digest': 'sha256:' + hashlib.sha256(value).hexdigest()}
                     for name, value in downloads.items()]}
        work = self.root / 'work'
        def runner(*command, **kwargs):
            if command[:3] == ('git', 'rev-parse', 'HEAD'):
                return 'a' * 40
            if command[:2] == ('git', 'rev-parse'):
                return 'b' * 40
            if command[:2] == ('git', 'diff'):
                self.assertIn('--no-renames', command)
                return 'launcher/OnlineOptions.cs'
            if command[:3] == ('gh', 'release', 'download'):
                name = command[command.index('--pattern') + 1]
                (work / name).write_bytes(downloads[name])
                return ''
            raise AssertionError(command)
        environment = {'RELEASE_TAG': target, 'PRERELEASE': 'true', 'PUBLICATION': 'validate-only',
                       'CREATE_TAG': 'true', 'GITHUB_REPOSITORY': 'owner/repo', 'INPUTS_RELEASE': seed,
                       'GITHUB_SHA': 'a' * 40, 'GITHUB_REF': 'refs/heads/develop'}
        with patch.dict(os.environ, environment), patch.object(release, 'run', side_effect=runner), \
                patch.object(release, 'api', return_value=metadata) as api:
            release.prepare(self.root, work)
            self.assertEqual(api.call_args.args, (f'repos/owner/repo/releases/tags/{seed}',))
            self.assertEqual(api.call_count, 1)
        (work / 'staged').mkdir()
        (work / 'staged' / f'RE-Outbreak-{target}-Windows-x64.zip').write_bytes(player_package(target, 'a' * 40))
        release.finalize(work)
        plan = json.loads((work / 'release-plan.json').read_text())
        self.assertEqual(len(plan['assets']), 4)
        self.assertEqual(plan['source'], 'a' * 40)
        self.assertEqual(plan['publication'], 'validate-only')
        self.assertIn('not rerun', (work / 'release-notes.md').read_text())
        for asset in plan['assets']:
            self.assertEqual(release.sha(work / 'assets' / asset['name']), asset['sha256'])
        with patch.object(release, 'api') as api:
            release.publish(work)
        api.assert_not_called()

    def test_stable_preparation_from_develop_refused_before_network(self):
        environment = {'RELEASE_TAG': 'v1.0.20', 'PRERELEASE': 'false', 'PUBLICATION': 'validate-only',
                       'CREATE_TAG': 'true', 'GITHUB_REPOSITORY': 'owner/repo',
                       'INPUTS_RELEASE': 'v1.0.20-rc2-hotfix', 'GITHUB_SHA': 'a' * 40,
                       'GITHUB_REF': 'refs/heads/develop'}
        with patch.dict(os.environ, environment), patch.object(release, 'run', return_value='a' * 40), \
                patch.object(release, 'api') as api, self.assertRaisesRegex(ValueError, 'Select main'):
            release.prepare(self.root, self.root / 'work')
        api.assert_not_called()


if __name__ == '__main__':
    unittest.main()
