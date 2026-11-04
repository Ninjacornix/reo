import struct
import unittest

from scan_overlay_gaps import scan


class OverlayGapTests(unittest.TestCase):
    BASE = 0x58D000

    def image(self):
        raw = bytearray(0x140)
        struct.pack_into("<4s4I", raw, 0, b"MWo3", 4, self.BASE, 0xC0, 0x40)
        return raw

    def row(self, start, end):
        return {"start": hex(self.BASE + start), "end": hex(self.BASE + end)}

    def test_pointer_and_call_to_missing_function(self):
        raw = self.image()
        target = self.BASE + 0xA0
        struct.pack_into("<I", raw, 0x80, 0x0C000000 | (target >> 2))
        struct.pack_into("<I", raw, 0xA0, 0x03E00008)
        struct.pack_into("<I", raw, 0x100, target)
        result = scan(raw, [self.row(0x80, 0x90)])
        refs = result["nonzero_gaps"][0]["references"]
        self.assertEqual([(r["kind"], r["target"]) for r in refs],
                         [("jal", target), ("data-pointer", target)])
        # Once mapped, zero padding is not reported as a missing function.
        self.assertEqual(scan(raw, [self.row(0x80, 0x90), self.row(0xA0, 0xA8)])
                         ["nonzero_gaps"], [])

    def test_unmapped_words_are_not_trusted_as_instructions(self):
        raw = self.image()
        struct.pack_into("<I", raw, 0xA0, 0x0C000000 | ((self.BASE + 0xB0) >> 2))
        struct.pack_into("<I", raw, 0xB0, 0x03E00008)
        result = scan(raw, [self.row(0x80, 0x90)])
        self.assertEqual(result["nonzero_gaps"][0]["references"], [])

    def test_table_return_entry_inside_mapped_function(self):
        raw = self.image()
        target = self.BASE + 0xA0
        struct.pack_into("<II", raw, 0xA0, 0x03E00008, 0)
        struct.pack_into("<I", raw, 0x100, target)
        result = scan(raw, [self.row(0x80, 0xA8)])
        self.assertEqual(result["nonzero_gaps"], [])
        entry, = result["interior_references"]
        self.assertEqual(entry["target"], target)
        self.assertTrue(entry["return_only"])
        self.assertEqual(entry["references"], [{"source": self.BASE + 0x100,
                                               "kind": "data-pointer"}])
        # Splitting out the callable entry resolves the finding, without
        # interpreting every interior table label as a new function.
        self.assertEqual(scan(raw, [self.row(0x80, 0x98), self.row(0xA0, 0xA8)])
                         ["interior_references"], [])

    def test_interior_jal_and_nontrivial_label_are_reported(self):
        raw = self.image()
        target = self.BASE + 0xA0
        struct.pack_into("<I", raw, 0x80, 0x0C000000 | (target >> 2))
        struct.pack_into("<I", raw, 0xA0, 0x24020001)
        entry, = scan(raw, [self.row(0x80, 0xB0)])["interior_references"]
        self.assertFalse(entry["return_only"])
        self.assertEqual(entry["references"][0]["kind"], "jal")

    def test_cross_function_jump_is_not_hidden_by_adjacent_ranges(self):
        raw = self.image()
        target = self.BASE + 0xA0
        struct.pack_into("<I", raw, 0x80, 0x08000000 | (target >> 2))
        struct.pack_into("<II", raw, 0xA0, 0x03E00008, 0)
        entry, = scan(raw, [self.row(0x80, 0x90), self.row(0x90, 0xA8)])["interior_references"]
        self.assertEqual(entry["containing_range"], [self.BASE + 0x90, self.BASE + 0xA8])
        self.assertEqual(entry["references"][0]["kind"], "j")

    def test_unaligned_map_entries_do_not_hide_code(self):
        raw = self.image()
        struct.pack_into("<I", raw, 0xA0, 0x03E00008)
        result = scan(raw, [self.row(0x80, 0x90), self.row(0x91, 0xB0)])
        self.assertEqual(result["nonzero_gaps"][0]["start"], self.BASE + 0x90)

    def test_overlapping_maps_are_merged(self):
        raw = self.image()
        struct.pack_into("<I", raw, 0xA0, 0x03E00008)
        self.assertEqual(scan(raw, [self.row(0x80, 0xA8), self.row(0x90, 0x98)])
                         ["nonzero_gaps"], [])

    def test_rejects_truncation_and_out_of_text_ranges(self):
        with self.assertRaises(ValueError):
            scan(self.image()[:0x110], [])
        with self.assertRaises(ValueError):
            scan(self.image(), [self.row(0x80, 0x104)])


if __name__ == "__main__":
    unittest.main()
