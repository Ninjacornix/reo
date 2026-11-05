"""Small synthetic offline fixtures: no game, Ghidra, network, or build tools."""
import csv
from contextlib import closing
import hashlib
import json
from pathlib import Path
import sqlite3
import struct
import tempfile
import unittest
from unittest.mock import patch

import index


def immediate(op, rs, rt, low):
    return op << 26 | rs << 21 | rt << 16 | low & 0xffff


def jump(op, addr):
    return op << 26 | addr >> 2 & 0x3ffffff


def fixture_function(start=0x100000, end=0x100100):
    return index.Function('main', start, end, 'sub_test', 'map.csv', 2)


def make_map(path, rows):
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open('w', newline='') as stream:
        writer = csv.writer(stream)
        writer.writerow(('name', 'start', 'end', 'size'))
        for name, start, end in rows:
            writer.writerow((name, hex(start), hex(end), end - start))


class ExtractionTests(unittest.TestCase):
    def extract(self, words, start=0x100000):
        return index.extract(fixture_function(start), [(start + i * 4, word, i + 1) for i, word in enumerate(words)])

    def test_global_materialization_signed_low_and_memory_use(self):
        _, refs = self.extract([immediate(15, 0, 8, 0x23), immediate(9, 8, 8, 0xa618),
                                immediate(35, 8, 4, 0), immediate(43, 8, 4, 4)])
        self.assertEqual([(r['address'], r['kind']) for r in refs],
                         [(0x22a618, 'materialized_address_candidate'), (0x22a618, 'memory_read'), (0x22a61c, 'memory_write')])

    def test_ori_uses_unsigned_immediate(self):
        _, refs = self.extract([immediate(15, 0, 8, 0x23), immediate(13, 8, 8, 0xa618)])
        self.assertEqual(refs[-1]['address'], 0x23a618)

    def test_call_clobbers_constants_after_delay_slot(self):
        _, refs = self.extract([immediate(15, 0, 8, 0x26), jump(3, 0x114540),
                                immediate(9, 8, 4, 0x4820), immediate(35, 8, 5, 0x4820)])
        self.assertEqual(len(refs), 1)
        self.assertEqual(refs[0]['address'], 0x264820)

    def test_incoming_branch_target_invalidates_linear_constants(self):
        _, refs = self.extract([immediate(4, 4, 0, 2), 0,
                                immediate(15, 0, 8, 0x26), immediate(35, 8, 4, 0x4820)])
        self.assertEqual(refs, [])

    def test_load_clobbers_base_register_value(self):
        _, refs = self.extract([immediate(15, 0, 8, 0x26), immediate(35, 8, 8, 0x4820),
                                immediate(35, 8, 4, 0x4820)])
        self.assertEqual(len(refs), 1)

    def test_mmi_unknown_writer_invalidates_values(self):
        _, refs = self.extract([immediate(15, 0, 8, 0x26), 28 << 26,
                                immediate(35, 8, 4, 0x4820)])
        self.assertEqual(refs, [])

    def test_indirect_call_is_unresolved_and_jr_switch_is_not_a_call(self):
        edges, _ = self.extract([8 << 21 | 31 << 11 | 9, 0, 9 << 21 | 8, 0])
        self.assertEqual([e['kind'] for e in edges], ['indirect_call', 'indirect_jump'])
        self.assertIsNone(edges[0]['target'])

    def test_ordinary_return_and_local_jump_are_not_call_edges(self):
        edges, _ = self.extract([jump(2, 0x100008), 0, 31 << 21 | 8, 0])
        self.assertEqual(edges, [])

    def test_tail_jump_and_direct_call_are_distinct(self):
        edges, _ = self.extract([jump(3, 0x114540), 0, jump(2, 0x114460), 0])
        self.assertEqual([e['kind'] for e in edges], ['call', 'tail_jump_candidate'])

    def test_jump_uses_pc_plus_four_high_bits(self):
        self.assertEqual(index.control(0x0ffffffc, jump(3, 0x10000000))[1], 0x10000000)

    def test_aliases_and_mmio_are_not_conflated(self):
        self.assertEqual(index.physical(0xa04badd0), 0x4badd0)
        self.assertEqual(index.physical(0x204badd0), 0x4badd0)
        self.assertEqual(index.address_class(0x120000e0), 'mmio_candidate')
        self.assertEqual(index.physical(0x70003700), 0x70003700)


class IndexTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        config = self.root / 'recomp/config'
        make_map(config / 'outbreak_ghidra_functions.csv',
                 [('sub_a', 0x100000, 0x100008), ('sub_b', 0x100008, 0x100010)])
        make_map(config / 'overlay_maps/ovl2.csv', [('o2_a', 0x570000, 0x570010)])
        make_map(config / 'overlay_maps/ovl3.csv', [('o3_a', 0x570000, 0x570010)])
        source = config / 'output/sub_00100000_0x100000.cpp'
        source.parent.mkdir(parents=True)
        source.write_text('// 0x100000: 0x%08x jal func_100008\n'
                          '// 0x100004: 0x0 nop\n'
                          '// 0x100008: 0x3e00008 jr ra\n'
                          '// 0x10000c: 0x0 nop\n' % jump(3, 0x100008))
        self.source = source
        self.annotations = self.root / 'annotations.json'
        self.annotations.write_text(json.dumps(dict(schema=1, edition='SLUS-20765', elf_sha256=index.ELF_SHA,
            annotations=[dict(id='main:0x00100000', image='main', address='0x00100000',
                              proposed_name='named_caller', confidence='probable',
                              rationale='test evidence', evidence=[])])))
        self.output = self.root / 'out/index.sqlite'

    def test_cross_overlay_ambiguity_and_interior_targets(self):
        catalogue = index.Catalogue(self.root)
        targets, status = catalogue.resolve('main', 0x570000)
        self.assertEqual(status, 'ambiguous_overlay')
        self.assertEqual(len(targets), 2)
        self.assertEqual(catalogue.resolve('o2', 0x570004), (['o2:0x00570000'], 'interior'))

    def test_unaligned_catalogue_entries_are_preserved_but_flagged(self):
        make_map(self.root / 'recomp/config/extra_functions.csv', [('suspected_data', 0x100011, 0x100012)])
        catalogue = index.Catalogue(self.root)
        self.assertIn('main:0x00100011', catalogue.functions)
        self.assertTrue(any('unaligned' in warning for warning in catalogue.warnings))
        index.build(self.root, self.output, self.annotations)
        with index.connect(self.output) as db:
            self.assertEqual(index.show(db, '0x100011')['coverage'], 'unaligned_catalogue')

    def test_merged_file_ownership_call_graph_search_and_suggestions(self):
        index.build(self.root, self.output, self.annotations)
        with index.connect(self.output) as db:
            a = index.show(db, '0x100000')
            b = index.show(db, '0x10000c')
            self.assertEqual(a['instruction_count'], 2)
            self.assertEqual(b['id'], 'main:0x00100008')
            self.assertEqual(b['instruction_count'], 2)
            self.assertEqual(b['callers'][0]['caller'], a['id'])
            self.assertEqual(index.summary(db)['annotated'], 1)
            self.assertEqual(index.search(db, 'named_caller', 10)[0]['id'], a['id'])
            self.assertEqual(index.search(db, '%', 10), [])
            self.assertEqual(index.suggestions(db, 10)[0]['id'], b['id'])
            with self.assertRaisesRegex(ValueError, 'Ambiguous'):
                index.show(db, '0x570000')
            with self.assertRaises(sqlite3.OperationalError):
                db.execute('DELETE FROM functions')

    def test_unknown_annotation_fails_without_overwriting_previous_database(self):
        self.output.parent.mkdir(parents=True)
        self.output.write_bytes(b'previous completed file')
        data = json.loads(self.annotations.read_text())
        data['annotations'][0]['id'] = 'main:0x99999999'
        self.annotations.write_text(json.dumps(data))
        with self.assertRaisesRegex(ValueError, 'matching catalogue'):
            index.build(self.root, self.output, self.annotations)
        self.assertEqual(self.output.read_bytes(), b'previous completed file')

    def test_paired_annotation_import_preserves_qualifiers_and_evidence(self):
        path = self.root / 'docs/notes.md'
        path.parent.mkdir()
        path.write_text('| [0x100000](../recomp/config/output/sub_00100000_0x100000.cpp), '
                        '[0x100008](../recomp/config/output/sub_00100008_0x100008.cpp) '
                        '| `lock` / `unlock` | Confirmed/static; API probable | proof with escaped \\| value |\n')
        result = index.import_notes(self.root, [path])['annotations']
        self.assertEqual([r['proposed_name'] for r in result], ['lock', 'unlock'])
        self.assertEqual(result[0]['confidence_detail'], 'Confirmed/static; API probable')
        self.assertIn('\\| value', result[0]['rationale'])
        self.assertEqual(result[0]['evidence'], [dict(path='docs/notes.md', line=1)])

    def test_note_entry_address_can_differ_from_merged_source_filename(self):
        path = self.root / 'notes.md'
        path.write_text('| [0x100008](../recomp/config/output/sub_00100000_0x100000.cpp) '
                        '| `second_entry` | Confirmed/static | shared file, separate entry |\n')
        rows = index.import_notes(self.root, [path])['annotations']
        self.assertEqual(rows[0]['id'], 'main:0x00100008')

    def test_catalogue_link_import_preserves_missing_generated_body(self):
        path = self.root / 'docs/notes.md'
        path.parent.mkdir()
        path.write_text('| [o3 0x570000](../recomp/config/overlay_maps/ovl3.csv) '
                        '| `raw_review` | Probable raw words | owned-image evidence |\n')
        rows = index.import_notes(self.root, [path])['annotations']
        self.assertEqual(rows[0]['id'], 'o3:0x00570000')
        self.annotations.write_text(json.dumps(dict(schema=1, edition='SLUS-20765',
            elf_sha256=index.ELF_SHA, annotations=rows)))
        index.build(self.root, self.output, self.annotations)
        with index.connect(self.output) as db:
            row = index.show(db, 'o3:0x00570000')
            self.assertEqual(row['proposed_name'], 'raw_review')
            self.assertFalse(row['source'])
            self.assertEqual(row['instruction_count'], 0)

    def test_catalogue_link_rejects_entry_from_other_image(self):
        path = self.root / 'notes.md'
        path.write_text('| [0x100000](recomp/config/overlay_maps/ovl2.csv) '
                        '| `wrong_image` | Probable | wrong catalogue |\n')
        with self.assertRaisesRegex(ValueError, 'absent from linked catalogue'):
            index.import_notes(self.root, [path])

    def test_catalogue_link_rejects_path_outside_checkout(self):
        path = self.root / 'docs/notes.md'
        path.parent.mkdir()
        path.write_text('| [o2 0x570000](../../recomp/config/overlay_maps/ovl2.csv) '
                        '| `wrong_checkout` | Probable | wrong path |\n')
        with self.assertRaisesRegex(ValueError, 'outside expected checkout'):
            index.import_notes(self.root, [path])

    def test_catalogue_link_rejects_other_overlay_at_same_address(self):
        path = self.root / 'notes.md'
        path.write_text('| [o2 0x570000](recomp/config/overlay_maps/ovl3.csv) '
                        '| `wrong_overlay` | Probable | same address, different image |\n')
        with self.assertRaisesRegex(ValueError, 'Image label disagrees'):
            index.import_notes(self.root, [path])

    def test_catalogue_link_does_not_import_file2_or_narrative_links(self):
        path = self.root / 'notes.md'
        path.write_text('| [0x570000](recomp/config/file2/overlay_maps/ovl2.csv) '
                        '| `file2` | Probable | wrong edition |\n'
                        '| [catalogue](recomp/config/overlay_maps/ovl2.csv) '
                        '| `not_entry` | Probable | no explicit address |\n')
        self.assertEqual(index.import_notes(self.root, [path])['annotations'], [])

    def test_refresh_updates_annotations_without_changing_graph_and_can_remove_old_names(self):
        index.build(self.root, self.output, self.annotations)
        data = json.loads(self.annotations.read_text())
        data['annotations'][0].update(id='main:0x00100008', address='0x00100008', proposed_name='second')
        self.annotations.write_text(json.dumps(data))
        index.refresh_annotations(self.root, self.output, self.annotations)
        with index.connect(self.output) as db:
            self.assertEqual(index.show(db, '0x100000')['confidence'], 'unknown')
            self.assertEqual(index.show(db, '0x100008')['proposed_name'], 'second')
            self.assertEqual(len(index.show(db, '0x100008')['callers']), 1)

    def test_refresh_rejects_changed_catalogue_without_mutation(self):
        index.build(self.root, self.output, self.annotations)
        path = self.root / 'recomp/config/outbreak_ghidra_functions.csv'
        path.write_text(path.read_text() + '\n')
        with self.assertRaisesRegex(ValueError, 'Catalogue changed'):
            index.refresh_annotations(self.root, self.output, self.annotations)
        with index.connect(self.output) as db:
            self.assertEqual(index.show(db, '0x100000')['proposed_name'], 'named_caller')

    def test_refresh_rejects_a_new_catalogue_file(self):
        index.build(self.root, self.output, self.annotations)
        make_map(self.root / 'recomp/config/overlay_maps/ovl9.csv', [('new_entry', 0x810000, 0x810010)])
        with self.assertRaisesRegex(ValueError, 'Catalogue changed'):
            index.refresh_annotations(self.root, self.output, self.annotations)

    def test_refresh_rejects_invalid_annotation_without_clearing_old_names(self):
        index.build(self.root, self.output, self.annotations)
        data = json.loads(self.annotations.read_text())
        data['annotations'][0]['confidence'] = 'invented'
        self.annotations.write_text(json.dumps(data))
        with self.assertRaisesRegex(ValueError, 'confidence'):
            index.refresh_annotations(self.root, self.output, self.annotations)
        with index.connect(self.output) as db:
            self.assertEqual(index.show(db, '0x100000')['proposed_name'], 'named_caller')

    def test_inconsistent_instruction_comments_are_rejected(self):
        self.source.write_text('// 0x100000: 0x0 nop\n// 0x100000: 0x1 bogus\n')
        with self.assertRaisesRegex(ValueError, 'Conflicting'):
            index.read_instructions(self.source)

    def test_csv_export_does_not_create_spreadsheet_formulas(self):
        index.build(self.root, self.output, self.annotations)
        with closing(sqlite3.connect(self.output)) as db, db:
            db.execute("UPDATE functions SET proposed_name='=1+1' WHERE start=1048576")
        out = self.root / 'out/functions.csv'
        with index.connect(self.output) as db:
            index.export_csv(db, out)
        with out.open(encoding='utf-8-sig', newline='') as stream:
            self.assertEqual(next(csv.DictReader(stream))['proposed_name'], "'=1+1")

    def test_wrong_elf_identity_is_rejected(self):
        elf = self.root / 'wrong.elf'
        elf.write_bytes(b'not the owned ELF')
        with self.assertRaisesRegex(ValueError, 'identity mismatch'):
            index.Elf(elf)

    def test_verified_elf_reads_only_mapped_terminated_ascii(self):
        data = bytearray(256)
        data[:6] = b'\x7fELF\x01\x01'
        struct.pack_into('<I', data, 28, 52)
        struct.pack_into('<HH', data, 42, 32, 1)
        struct.pack_into('<8I', data, 52, 1, 128, 0x100000, 0, 128, 128, 5, 16)
        data[144:150] = b'HELLO\0'
        data[150:156] = b'BAD\x01!\0'
        data[240:256] = b'UNTERMINATED!!!!'
        elf = self.root / 'fixture.elf'
        elf.write_bytes(data)
        with patch.object(index, 'ELF_SHA', hashlib.sha256(data).hexdigest()):
            image = index.Elf(elf)
        self.assertEqual(image.string(0x100010), 'HELLO')
        self.assertIsNone(image.string(0x100016))
        self.assertIsNone(image.string(0x100070))
        self.assertEqual(image.read(0x100010, 5), b'HELLO')
        self.assertIsNone(image.read(0x10007f, 4))


if __name__ == '__main__':
    unittest.main()
