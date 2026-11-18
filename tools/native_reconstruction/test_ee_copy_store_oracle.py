"""Authored byte/halfword vectors for the scoped verification engine extension."""
import unittest
from ee_copy_store_oracle import CopyStoreInstructions
from movie_position_oracle import ClockIntegerInstructions
from sjuni_oracle import Memory, OracleError, UnknownInstruction


class Micro(CopyStoreInstructions,ClockIntegerInstructions):
    def __init__(self):
        self.regs=[0]*32;self.mem=Memory();self.mem.map(0x400000,128,0xA5)
        self.initialize_copy_store();self.initialize_mac(hi=0,lo=0,hi1=0,lo1=0);self.extension_counts={}


def instruction(op,rs,rt,rd=0,sa=0,fn=0):return op<<26|rs<<21|rt<<16|rd<<11|sa<<6|fn


class Vectors(unittest.TestCase):
    def test_doubleword_immediate_addition(self):
        for left,immediate,expected in [(0xFFFFFFFF,1,0x100000000),(0x7FFFFFFFFFFFFFFF,1,0x8000000000000000),(0,-1,0xFFFFFFFFFFFFFFFF)]:
            for destination in [0,2,3]:
                with self.subTest(left=left,destination=destination):
                    m=Micro();m.regs[2]=left
                    m.instruction(0,(0x19<<26)|(2<<21)|(destination<<16)|(immediate&0xFFFF))
                    self.assertEqual(m.regs[destination],expected if destination else 0)

    def test_doubleword_subtraction_wrap_and_aliases(self):
        for left,right,expected in [(0,1,0xFFFFFFFFFFFFFFFF),(0x8000000000000000,1,0x7FFFFFFFFFFFFFFF),(0x100000000,1,0xFFFFFFFF)]:
            for destination in [0,2,3,4]:
                with self.subTest(left=left,destination=destination):
                    m=Micro();m.regs[2]=left;m.regs[3]=right
                    m.instruction(0,instruction(0,2,3,destination,0,0x2F))
                    self.assertEqual(m.regs[destination],expected if destination else 0)

    def test_doubleword_shifts_use_full_lower64(self):
        for fn,expected in [(0x38,0x10),(0x3A,0x0800000000000000),(0x3B,0xF800000000000000)]:
            for destination in [0,2,3]:
                with self.subTest(fn=fn,destination=destination):
                    m=Micro();m.regs[2]=0x8000000000000001;m.upper[destination]=0x1234 if destination else 0
                    m.instruction(0,instruction(0,0,2,destination,4,fn))
                    self.assertEqual(m.regs[destination],expected if destination else 0)
                    self.assertEqual(m.upper[destination],0x1234 if destination else 0)

    def test_halfword_halves_and_aliases(self):
        for destination in [0,2,3]:
            with self.subTest(destination=destination):
                m=Micro();m.regs[2]=0x111122223333ABCD;m.upper[2]=0x4444555566669876
                m.instruction(0,instruction(0x1C,0,2,destination,0x1B,0x29))
                self.assertEqual(m.regs[destination],0 if destination==0 else 0xABCDABCDABCDABCD)
                self.assertEqual(m.upper[destination],0 if destination==0 else 0x9876987698769876)

    def test_lower_doubleword_order_and_aliases(self):
        for destination in [0,2,3,4]:
            with self.subTest(destination=destination):
                m=Micro();m.regs[2]=0x0123456789ABCDEF;m.regs[3]=0xFEDCBA9876543210
                m.instruction(0,instruction(0x1C,2,3,destination,0x0E,0x09))
                self.assertEqual(m.regs[destination],0 if destination==0 else 0xFEDCBA9876543210)
                self.assertEqual(m.upper[destination],0 if destination==0 else 0x0123456789ABCDEF)

    def test_unknown_upper_not_fabricated(self):
        m=Micro();m.regs[2]=0xABCD;m.regs[4]=0x400000
        m.instruction(0,instruction(0x1C,0,2,3,0x1B,0x29))
        self.assertNotIn(3,m.upper);before=m.mem.load(0x400000,16)
        with self.assertRaises(OracleError):m.instruction(0,instruction(0x1F,4,3))
        self.assertEqual(m.mem.load(0x400000,16),before)

    def test_sq_masks_low_address_bits_and_byte_order(self):
        for low in range(16):
            with self.subTest(low=low):
                m=Micro();m.regs[2]=0x0706050403020100;m.upper[2]=0x0F0E0D0C0B0A0908;m.regs[4]=0x400020+low
                m.instruction(0,instruction(0x1F,4,2))
                self.assertEqual(m.mem.load(0x400020,16).to_bytes(16,'little'),bytes(range(16)))
                self.assertEqual(m.mem.load(0x40001F,1),0xA5);self.assertEqual(m.mem.load(0x400030,1),0xA5)

    def test_negative_store_offset(self):
        m=Micro();m.regs[4]=0x400030;m.regs[2]=0x0706050403020100;m.upper[2]=0x0F0E0D0C0B0A0908
        m.instruction(0,(0x1F<<26)|(4<<21)|(2<<16)|0xFFF0)
        self.assertEqual(m.mem.load(0x400020,16).to_bytes(16,'little'),bytes(range(16)))

    def test_scalar_write_preserves_established_upper(self):
        m=Micro();m.regs[2]=7;m.upper[2]=0x0123456789ABCDEF
        m.instruction(0,(9<<26)|(2<<16)|5)
        self.assertEqual(m.regs[2],5);self.assertEqual(m.upper[2],0x0123456789ABCDEF)

    def test_reserved_encoding_refuses_before_effects(self):
        m=Micro();m.regs[2]=0xABCD;before=m.regs[:]
        with self.assertRaises(UnknownInstruction):m.instruction(0,instruction(0x1C,1,2,3,0x1B,0x29))
        self.assertEqual(m.regs,before)


if __name__=='__main__':unittest.main()
