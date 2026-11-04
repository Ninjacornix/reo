import hashlib
import json
from pathlib import Path
import tempfile
import unittest
import zipfile

from export_slim_inputs import export


class SlimInputExportTests(unittest.TestCase):
    def fixture(self, directory, external):
        root=Path(directory);kit=root/'kit';kit.mkdir()
        (kit/'tools/local_build').mkdir(parents=True)
        (kit/'tools/local_build/build_game.py').write_text('# Synthetic worker fixture, never executed.\n')
        (kit/'notices').mkdir()
        (kit/'notices/LICENSE.txt').write_text('Synthetic notice fixture.\n')
        plan={'format':1,'sourceGroups':[], 'compiler':'{kit}/toolchain/bin/compiler.exe'}
        if external:
            plan.update(externalToolchain=True,externalCompilerSha256='a'*64)
        else:
            (kit/'toolchain/bin').mkdir(parents=True)
            (kit/'toolchain/bin/compiler.exe').write_bytes(b'Synthetic compiler identity, never executed.')
        (kit/'compile-plan.json').write_text(json.dumps(plan))
        files=[{'path':p.relative_to(kit).as_posix(),'sha256':hashlib.sha256(p.read_bytes()).hexdigest()}
               for p in kit.rglob('*') if p.is_file()]
        (kit/'build-kit.json').write_text(json.dumps({'format':1,'files':files}))
        return root,kit

    def test_verified_external_kit_can_be_reexported_without_copying_a_toolchain(self):
        with tempfile.TemporaryDirectory() as directory:
            root,kit=self.fixture(directory,True)
            out=root/'slim';archive=root/'slim.zip'
            export(kit,out,archive,Path(__file__).resolve().parents[2],'1.0.20-rc0')
            self.assertEqual(json.loads((out/'compile-plan.json').read_text())['externalCompilerSha256'],'a'*64)
            self.assertFalse((out/'toolchain').exists())
            with zipfile.ZipFile(archive) as zipped:
                manifest=json.loads(zipped.read('build-kit.json'))
                for item in manifest['files']:
                    self.assertEqual(hashlib.sha256(zipped.read(item['path'])).hexdigest(),item['sha256'])

    def test_full_kit_compiler_identity_is_derived_before_toolchain_omission(self):
        with tempfile.TemporaryDirectory() as directory:
            root,kit=self.fixture(directory,False)
            expected=hashlib.sha256((kit/'toolchain/bin/compiler.exe').read_bytes()).hexdigest()
            export(kit,root/'slim',root/'slim.zip',Path(__file__).resolve().parents[2])
            plan=json.loads((root/'slim/compile-plan.json').read_text())
            self.assertTrue(plan['externalToolchain'])
            self.assertEqual(plan['externalCompilerSha256'],expected)

    def test_external_kit_without_a_verified_driver_identity_is_rejected(self):
        with tempfile.TemporaryDirectory() as directory:
            root,kit=self.fixture(directory,True)
            path=kit/'compile-plan.json';plan=json.loads(path.read_text());plan.pop('externalCompilerSha256')
            path.write_text(json.dumps(plan));manifest=json.loads((kit/'build-kit.json').read_text())
            for item in manifest['files']:
                if item['path']=='compile-plan.json':item['sha256']=hashlib.sha256(path.read_bytes()).hexdigest()
            (kit/'build-kit.json').write_text(json.dumps(manifest))
            with self.assertRaisesRegex(ValueError,'compiler identity'):
                export(kit,root/'slim',root/'slim.zip',Path(__file__).resolve().parents[2])
            self.assertFalse((root/'slim.zip').exists())


if __name__=='__main__':
    unittest.main()
