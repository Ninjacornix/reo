import sqlite3
import struct
import unittest

from classify_leaves import classify_words, classify_accessor_words, classify_tail_words, collect


class LeafTests(unittest.TestCase):
    def test_tail_keeps_jump_and_delay_contract_separate_from_callee(self):
        tail = classify_tail_words(0x1000, [0x08000800, 0])
        self.assertEqual(tail['target'], '0x00002000')
        self.assertIsNone(tail['argument_adjustment'])
        adjusted = classify_tail_words(0x1000, [0x08000800, 0x2485FFFF])
        self.assertEqual(adjusted['argument_adjustment'], -1)
        # J uses the high bits of PC+4, including a region-boundary delay slot.
        self.assertEqual(classify_tail_words(0x0FFFFFFC, [0x08000800, 0])['target'], '0x10002000')
        for words in ([0x0C000800, 0], [0x08000400, 0],
                      [0x08000800, 0xAC850000], [0x08000800, 0, 1]):
            self.assertIsNone(classify_tail_words(0x1000, words))

    def test_tail_requires_reviewed_same_image_target_and_excludes_protected_images(self):
        c = sqlite3.connect(':memory:')
        self.addCleanup(c.close)
        c.row_factory = sqlite3.Row
        c.execute('CREATE TABLE functions(id,image,start,end,source,proposed_name)')
        c.executemany('INSERT INTO functions VALUES(?,?,?,?,?,?)', [
            ('tail', 'o2', 0x1000, 0x1008, 'tail.cpp', ''),
            ('target', 'o2', 0x2000, 0x2008, 'target.cpp', 'reviewed'),
            ('wrong-image', 'o3', 0x1000, 0x1008, 'wrong.cpp', ''),
            ('protected', 'o4', 0x1000, 0x1008, 'protected.cpp', ''),
            ('protected-target', 'o4', 0x2000, 0x2008, 'p-target.cpp', 'reviewed'),
        ])
        entries = collect(c, lambda image, address, size: struct.pack('<II', 0x08000800, 0))
        self.assertEqual([(e['id'], e['reviewed_target']) for e in entries], [('tail', 'target')])

    def test_noop_preserves_return_register_not_zero(self):
        result = classify_words([0x03E00008, 0])
        self.assertEqual(result['kind'], 'no_op')
        self.assertNotIn('value', result)

    def test_admitted_zero_forms(self):
        for word in (0x102D, 0x1021, 0x1025):
            self.assertEqual(classify_words([0x03E00008, word])['value'], 0)

    def test_signed_constants(self):
        for word, value in ((0x2402FFFF, -1), (0x24028000, -32768), (0x24027FFF, 32767)):
            self.assertEqual(classify_words([0x03E00008, word])['value'], value)

    def test_nonzero_trailer_memory_delay_and_other_register_rejected(self):
        for words in ([0x03E00008, 0, 1], [0x03E00008, 0xAC820000],
                      [0x03E00008, 0x24030001], [0x08000000, 0],
                      [0x03E00008], [0x03E00008, 0] + [0] * 7):
            self.assertIsNone(classify_words(words))

    def test_zero_padding_is_admitted(self):
        self.assertIsNotNone(classify_words([0x03E00008, 0x24020001, 0, 0]))

    def test_accessors_sign_extension_and_negative_offset(self):
        signed = classify_accessor_words([0x8082FFFF, 0x03E00008, 0])
        unsigned = classify_accessor_words([0x03E00008, 0x90820004])
        self.assertEqual((signed['extension'], signed['width'], signed['offset']), ('signed', 8, -1))
        self.assertEqual(unsigned['extension'], 'unsigned')

    def test_setters_preserve_return_and_limit_sources(self):
        result = classify_accessor_words([0x03E00008, 0xAC850018])
        self.assertEqual((result['kind'], result['register'], result['offset']), ('write_a0_field', 'a1', 24))
        self.assertIn('preserves v0', result['behavior'])
        self.assertIsNone(classify_accessor_words([0x03E00008, 0xAC820018]))

    def test_accessor_extra_instruction_other_base_and_return_mutation_rejected(self):
        for words in ([0x8C820004, 0x03E00008, 0x24020001],
                      [0x8FA20004, 0x03E00008, 0],
                      [0x8C820004, 0, 0x03E00008, 0],
                      [0x8C830004, 0x03E00008, 0]):
            self.assertIsNone(classify_accessor_words(words))

    def test_float_accessors_do_not_guess_scalar_conversion(self):
        result = classify_accessor_words([0x03E00008, 0xC4800010])
        self.assertEqual(result['kind'], 'read_a0_float_field')
        self.assertIn('raw', result['behavior'])
        self.assertEqual(classify_accessor_words([0x03E00008, 0xE48C0014])['kind'], 'write_a0_float_field')

    def test_catalogue_images_bounds_and_existing_names(self):
        c = sqlite3.connect(':memory:')
        self.addCleanup(c.close)
        c.row_factory = sqlite3.Row
        c.execute('CREATE TABLE functions(id,image,start,end,source,proposed_name)')
        c.executemany('INSERT INTO functions VALUES(?,?,?,?,?,?)', [
            ('o2:a', 'o2', 0x1000, 0x1008, 'a.cpp', ''),
            ('o3:a', 'o3', 0x1000, 0x1008, 'b.cpp', ''),
            ('unaligned', 'o2', 0x1001, 0x1009, 'u.cpp', ''),
            ('named', 'o2', 0x1010, 0x1018, 'n.cpp', 'reviewed'),
            ('missing', 'o2', 0x1020, 0x1028, '', ''),
            ('short', 'o2', 0x1030, 0x1034, 's.cpp', ''),
            ('unbacked', 'main', 0x9000, 0x9008, 'm.cpp', ''),
        ])
        def read(image, address, size):
            if image == 'main':
                return None
            return struct.pack('<II', 0x03E00008, 0x24020001 if image == 'o2' else 0)
        entries = collect(c, read)
        self.assertEqual([(e['id'], e['kind']) for e in entries],
                         [('o2:a', 'return_constant'), ('o3:a', 'no_op')])


if __name__ == '__main__':
    unittest.main()
