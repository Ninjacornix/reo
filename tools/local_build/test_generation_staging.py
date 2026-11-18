"""Fresh generation diagnostics stay outside compiler roots after interruption."""
from contextlib import ExitStack
import hashlib
import json
import os
from pathlib import Path
import shutil
import stat
import subprocess
import tempfile
import tomllib
import types
import unittest
from unittest import mock

import generate_game
from build_game import generation_staging_parent,note_legacy_generation_staging,stage
from build_scheduler import header_fingerprint
from long_paths import extended,native


class GenerationStagingTests(unittest.TestCase):
    def setUp(self):
        self.temporary=tempfile.TemporaryDirectory(prefix='reo-generation-staging-')
        self.root=Path(self.temporary.name).resolve()
        def cleanup():
            if self.root!=Path(self.temporary.name).resolve() or not self.root.name.startswith('reo-generation-staging-'):
                raise RuntimeError('Unexpected staging-test cleanup target')
            if extended(self.root).exists():
                shutil.rmtree(extended(self.root))
            self.temporary.cleanup()
        self.addCleanup(cleanup)
        self.work=self.root/'work';self.work.mkdir()
        self.kit=self.root/'kit';self.kit.mkdir()
        self.output=self.root/'output'
        self.generated=self.work/'project/recomp/config'
        self.parent=self.work/'generation-staging'
        self.disc=self.root/'disc';self.disc.mkdir();(self.disc/'BIN').mkdir()
        self.elf=self.disc/'SLUS_207.65';self.elf.write_bytes(bytes(range(64)))
        self.recompiler=self.kit/'ps2_recomp.exe';self.recompiler.write_bytes(b'synthetic tool never executed')
        self.metadata=self.kit/'metadata';self.metadata.mkdir();(self.metadata/'overlay_maps').mkdir()
        (self.metadata/'policy.toml').write_text('[mmio]\n')
        (self.metadata/'functions.csv').write_text('name,start,end,size\nsub_00100008,0x100008,0x100010,8\n')
        (self.metadata/'extra_functions.csv').write_text('name,start,end,size\nsub_00100010,0x100010,0x100018,8\n')
        self.profile=dict(elf='SLUS_207.65',sha256=generate_game.sha(self.elf),policy='policy.toml',functions='functions.csv',skip=[])
        self.plan=dict(format=1,runtimeAbi='synthetic',compileOptions=['/I{work}/project'],
            units=[dict(id='authored',sources=['{work}/project/authored.cpp'])],
            sourceGroups=[dict(id='generated',root='{generated}/output',pattern='*.cpp')])
        self.write_plan()
        self.invocations=[];self.interrupt=False

    def write_plan(self):
        (self.kit/'compile-plan.json').write_text(json.dumps(self.plan))

    def fake_recompiler(self,command,**kwargs):
        config=extended(Path(command[1]));general=tomllib.loads(config.read_text())['general']
        output=extended(Path(general['output']));output.mkdir(parents=True)
        self.invocations.append(dict(config=config,output=output))
        for name in ('ps2_recompiled_functions.h','ps2_recompiled_stubs.h'):
            (output/name).write_text('#pragma once\n')
        (output/'register_functions.cpp').write_text('runtime.registerFunction(0x100010, x_00100010);\n')
        (output/'x_00100010_0x100010.cpp').write_text('void synthetic(){}\n')
        kwargs['stdout'].write(b'synthetic recompiler output\n')
        if self.interrupt and config.stem=='main':
            raise RuntimeError('synthetic interruption after partial headers')
        return subprocess.CompletedProcess(command,0)

    def generate(self,parent):
        with ExitStack() as stack:
            stack.enter_context(mock.patch.dict(generate_game.GAMES,{'file1':self.profile}))
            stack.enter_context(mock.patch('generate_game.subprocess.run',side_effect=self.fake_recompiler))
            stack.enter_context(mock.patch('generate_game.validate_mapped_ranges'))
            stack.enter_context(mock.patch('generate_game.chunk_registrations',side_effect=lambda text:text))
            stack.enter_context(mock.patch('generate_game.generate_support'))
            stack.enter_context(mock.patch('generate_game.generate_catalogues',return_value=0))
            return generate_game.generate(self.recompiler,self.disc,self.metadata,self.generated,
                source_audit=True,staging_parent=parent)

    def fingerprint(self):
        project=self.work/'project';project.mkdir(exist_ok=True)
        return header_fingerprint([project],generate_game.sha)

    def test_interrupted_first_attempt_preserves_headers_outside_project(self):
        parent=generation_staging_parent(self.kit,self.generated,self.work,self.output)
        before=self.fingerprint();self.interrupt=True
        with self.assertRaisesRegex(RuntimeError,'synthetic interruption'):
            self.generate(parent)
        self.assertFalse(self.generated.exists())
        retained=list(extended(self.parent).glob('config.generating-*'))
        self.assertEqual(len(retained),1)
        self.assertTrue((retained[0]/'output/ps2_recompiled_functions.h').is_file())
        self.assertFalse(retained[0].is_relative_to(extended(self.work/'project')))
        self.assertEqual(self.fingerprint(),before)
        self.assertTrue(all(Path(native(row['output'])).is_relative_to(Path(native(retained[0]))) for row in self.invocations))

    def test_restart_keeps_old_diagnostics_then_atomically_publishes_new_directory(self):
        parent=generation_staging_parent(self.kit,self.generated,self.work,self.output)
        self.interrupt=True
        with self.assertRaises(RuntimeError):self.generate(parent)
        retained=list(extended(self.parent).glob('config.generating-*'))[0]
        evidence=generate_game.sha(retained/'output/ps2_recompiled_functions.h')
        self.interrupt=False;record=self.generate(parent)
        self.assertTrue((self.generated/'generation.json').is_file())
        self.assertEqual(generate_game.sha(retained/'output/ps2_recompiled_functions.h'),evidence)
        self.assertEqual(len(list(extended(self.parent).glob('config.generating-*'))),1)
        self.assertTrue(record['staging']['atomicRename'])
        self.assertEqual(Path(record['staging']['destination']),self.generated)
        self.assertEqual(Path(record['staging']['parent']),self.parent)
        config=tomllib.loads((self.generated/'inputs/main.toml').read_text())['general']
        self.assertTrue(Path(config['output']).is_relative_to(Path(record['staging']['directory'])))
        self.assertEqual(self.generated.stat().st_dev,self.parent.stat().st_dev)

    def test_completed_destination_is_untouched_before_any_new_staging(self):
        self.generated.mkdir(parents=True);marker=self.generated/'completed.h';marker.write_text('completed output')
        digest=generate_game.sha(marker)
        with self.assertRaises(FileExistsError):self.generate(self.parent)
        self.assertEqual(generate_game.sha(marker),digest)
        self.assertFalse(self.parent.exists())
        self.assertEqual(self.invocations,[])

    def test_verified_stage_reuses_completed_output_without_creating_more_staging(self):
        calls=[]
        def action():
            calls.append(1)
            self.generate(generation_staging_parent(self.kit,self.generated,self.work,self.output))
        outputs=lambda:[p for p in self.generated.rglob('*') if p.is_file()]
        stage(self.work,'generate',[self.elf,self.recompiler],action,outputs)
        manifest=generate_game.sha(self.generated/'generation.json')
        legacy=self.generated.with_name('config.generating-unleased');legacy.mkdir();(legacy/'old.h').write_text('retained')
        note_legacy_generation_staging(self.work,self.generated)
        stage(self.work,'generate',[self.elf,self.recompiler],action,outputs)
        self.assertEqual(calls,[1]);self.assertEqual(generate_game.sha(self.generated/'generation.json'),manifest)
        self.assertEqual((legacy/'old.h').read_text(),'retained')
        notice=json.loads((self.work/'generation-legacy-staging.json').read_text())
        self.assertFalse(notice['moved']);self.assertIn('inactivity cannot be proved',notice['reason'])

    def test_default_standalone_generation_remains_beside_destination(self):
        self.interrupt=True
        with self.assertRaises(RuntimeError):self.generate(None)
        self.assertEqual(len(list(self.generated.parent.glob('config.generating-*'))),1)
        self.assertFalse(self.parent.exists())

    def test_long_unicode_staging_and_destination_paths(self):
        self.work=self.root/'long'/('w'*130)/('éЖ'*20)
        extended(self.work).mkdir(parents=True)
        self.generated=self.work/'project/recomp/config';self.parent=self.work/'generation-staging'
        parent=generation_staging_parent(self.kit,self.generated,self.work,self.output)
        record=self.generate(parent)
        self.assertGreater(len(str(self.parent)),259)
        self.assertTrue(extended(self.generated/'generation.json').is_file())
        self.assertEqual(Path(record['staging']['parent']),self.parent)

    def test_destination_appearing_during_generation_preserves_both_outputs(self):
        parent=generation_staging_parent(self.kit,self.generated,self.work,self.output)
        original=self.fake_recompiler
        def publish_competitor(command,**kwargs):
            if Path(command[1]).stem=='main':
                self.generated.mkdir(parents=True);(self.generated/'completed.h').write_text('other completed output')
            return original(command,**kwargs)
        with mock.patch.object(self,'fake_recompiler',publish_competitor):
            with self.assertRaisesRegex(FileExistsError,'both outputs are preserved'):
                self.generate(parent)
        self.assertEqual((self.generated/'completed.h').read_text(),'other completed output')
        self.assertEqual(len(list(extended(self.parent).glob('config.generating-*'))),1)

    def test_include_and_source_roots_cannot_reach_new_staging_parent(self):
        for option in ('/I{work}','-I{work}/generation-staging/child','/FI{work}/generation-staging/prefix.h'):
            self.plan['compileOptions']=[option];self.write_plan()
            with self.subTest(option=option),self.assertRaisesRegex(ValueError,'input root'):
                generation_staging_parent(self.kit,self.generated,self.work,self.output)
            self.assertFalse(self.parent.exists())
        self.plan['compileOptions']=[];self.plan['units'][0]['sources']=['{work}/generation-staging/helper.cpp'];self.write_plan()
        with self.assertRaisesRegex(ValueError,'input root'):
            generation_staging_parent(self.kit,self.generated,self.work,self.output)

    def test_implicit_environment_include_root_and_unknown_substitution_fail_closed(self):
        with mock.patch.dict(os.environ,{'CPATH':str(self.work)}):
            with self.assertRaisesRegex(ValueError,'input root'):
                generation_staging_parent(self.kit,self.generated,self.work,self.output)
        self.plan['compileOptions']=['/I{unknown}/headers'];self.write_plan()
        with self.assertRaisesRegex(ValueError,'unknown include substitution'):
            generation_staging_parent(self.kit,self.generated,self.work,self.output)
        self.assertFalse(self.parent.exists())

    def test_outside_or_nested_destinations_are_rejected_without_moving_anything(self):
        outside=self.root/'outside/config'
        with self.assertRaises(ValueError):generation_staging_parent(self.kit,outside,self.work,self.output)
        with self.assertRaises(ValueError):
            generate_game.checked_staging_parent(self.generated,self.root/'outside',owned_work=self.work)
        with self.assertRaises(ValueError):
            generate_game.checked_staging_parent(self.generated,self.generated/'scratch',owned_work=self.work)
        self.assertFalse(outside.exists());self.assertFalse(self.parent.exists())

    def test_existing_names_collide_without_overwriting_diagnostics(self):
        parent=generation_staging_parent(self.kit,self.generated,self.work,self.output)
        retained=extended(self.parent/'config.generating-abcdefgh');retained.mkdir();marker=retained/'retained.h';marker.write_text('old evidence')
        with mock.patch('tempfile._get_candidate_names',return_value=iter(('abcdefgh','ijklmnop'))):
            record=self.generate(parent)
        self.assertEqual(marker.read_text(),'old evidence')
        self.assertEqual(Path(record['staging']['directory']).name,'config.generating-ijklmnop')
        self.assertTrue(self.generated.is_dir())

    def test_legacy_nonmatching_and_canonical_names_are_left_untouched(self):
        self.generated.mkdir(parents=True);(self.generated/'good.h').write_text('completed')
        unrelated=self.generated.parent/'other.generating-notours';unrelated.mkdir();(unrelated/'user.h').write_text('user data')
        named=self.generated.parent/'config.generating-not-a-lease';named.mkdir();(named/'unknown.h').write_text('unknown producer')
        note_legacy_generation_staging(self.work,self.generated)
        self.assertEqual((self.generated/'good.h').read_text(),'completed')
        self.assertEqual((unrelated/'user.h').read_text(),'user data')
        self.assertEqual((named/'unknown.h').read_text(),'unknown producer')
        notice=json.loads((self.work/'generation-legacy-staging.json').read_text())
        self.assertEqual(notice['names'],[named.name]);self.assertFalse(notice['moved'])

    def test_reparse_attribute_is_rejected_before_resolution(self):
        fake=types.SimpleNamespace(st_mode=stat.S_IFDIR|0o755,st_file_attributes=0x400)
        with mock.patch('generate_game._generation_io') as io:
            io.return_value.lstat.return_value=fake
            with self.assertRaisesRegex(ValueError,'reparse point'):
                generate_game.plain_generation_path(self.parent)

    def test_real_directory_link_or_junction_is_rejected(self):
        target=self.root/'outside';target.mkdir()
        try:
            self.parent.symlink_to(target,target_is_directory=True)
            self.addCleanup(lambda:self.parent.unlink())
        except OSError:
            if os.name!='nt':raise
            result=subprocess.run(['cmd','/c','mklink','/J',str(self.parent),str(target)],capture_output=True,text=True)
            if result.returncode:self.skipTest('Directory link/junction creation unavailable')
            self.addCleanup(lambda:os.rmdir(self.parent))
        with self.assertRaisesRegex(ValueError,'reparse point'):
            generation_staging_parent(self.kit,self.generated,self.work,self.output)
        self.assertEqual(list(target.iterdir()),[])

    def test_cross_filesystem_is_rejected_before_staging_creation(self):
        self.parent.mkdir()
        original=Path.stat
        def different_device(path,*args,**kwargs):
            value=original(path,*args,**kwargs)
            if Path(native(path))==self.parent:
                fields=list(value);fields[2]+=1;return os.stat_result(fields)
            return value
        with mock.patch.object(Path,'stat',different_device):
            with self.assertRaisesRegex(ValueError,'one filesystem'):
                generate_game.checked_staging_parent(self.generated,self.parent,owned_work=self.work)
        self.assertFalse(self.generated.exists());self.assertEqual(list(self.parent.iterdir()),[])


if __name__=='__main__':unittest.main()
