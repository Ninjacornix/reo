import struct,unittest
import capture_media_control as capture

class Reader:
    def __init__(self):self.spans={};self.reads=[];self.changing=False;self.changing_c4=False;self.changing_rna=False
    def put(self,at,data):self.spans[at]=data
    def read(self,at,size):
        self.reads.append((at,size))
        if self.changing and at==0x800044 and self.reads.count((at,size))==2:return struct.pack('<5I',1,4,6,0,0)
        if 0x20F3C8<=at<0x20F3C8+16*0xC4 and (at-0x20F3C8)%0xC4==0 and size==0xC4:
            value=bytearray(self.spans.get(0x20F3C8,bytes(16*0xC4))[at-0x20F3C8:at-0x20F3C8+0xC4])
            if self.changing_c4:value[1]^=1
            return bytes(value)
        if self.changing_rna and at==0x223880 and size==0x60 and self.reads.count((at,size))==2:return bytes(size)
        if at in self.spans:
            value=self.spans[at];assert len(value)==size;return value
        allowed=[(0x4BADD0,0x40),(0x20F3C4,4),(0x22F138,4),(0x20F3C8,16*0xC4),(0x22F18C,32)]
        allowed += [(0x800044,20),(0x802AB0,4),(0x8009A0,400),(0x800B30,400),(0x800CC0,0x298),(0x900DA4,8)]
        allowed += [(0x801AA0+68*i,8) for i in range(9)]
        if (at,size) not in allowed:raise AssertionError('Unexpected process-memory range')
        return bytes(size)

class CaptureTests(unittest.TestCase):
    def movie(self):
        r=Reader();r.put(0x22F18C,struct.pack('<8I',0x800000,0,0,0,0,0,0,0));return r
    def test_empty_has_no_pointer_following(self):
        r=Reader();value=capture.sample(r);self.assertEqual(value['movies'],[]);self.assertEqual(value['adxt'],[]);self.assertFalse(value['atomic'])
    def test_pool_fields_and_cached_words(self):
        r=self.movie();pool=bytearray(16*0xC4);pool[2*0xC4:2*0xC4+4]=bytes([1,3,2,2]);pool[2*0xC4+0x72]=1;r.put(0x20F3C8,bytes(pool))
        r.put(0x801AA0+68*6,struct.pack('<2I',7,9));v=capture.sample(r)
        self.assertEqual([(a['slot'],a['channels'],a['pause']) for a in v['adxt']],[(2,2,1)])
        self.assertEqual(v['movies'][0]['components'][6],[7,9]);self.assertTrue(v['movies'][0]['control_end_matches'])
    def test_invalid_main_is_never_dereferenced(self):
        r=Reader();r.put(0x22F18C,struct.pack('<8I',0x1FFFFFC,0,0,0,0,0,0,0));v=capture.sample(r)
        self.assertFalse(v['movies'][0]['admitted']);self.assertFalse(any(at==0x2000040 for at,_ in r.reads))
    def test_invalid_shared_is_never_dereferenced(self):
        r=self.movie();r.put(0x802AB0,struct.pack('<I',0xFFFFF000));v=capture.sample(r)
        self.assertIn('shared_reason',v['movies'][0]);self.assertNotIn('shared_source_flags',v['movies'][0])
    def test_changed_control_is_retained_as_unstable(self):
        r=self.movie();r.changing=True;v=capture.sample(r);self.assertFalse(v['movies'][0]['control_end_matches']);self.assertFalse(v['atomic'])
    def audio(self,child=0x223880):
        r=Reader();pool=bytearray(16*0xC4);pool[:4]=bytes([1,3,1,2]);struct.pack_into('<I',pool,12,child);r.put(0x20F3C8,bytes(pool));return r
    def test_exact_rna_child_fields(self):
        r=self.audio();rna=bytearray(0x60);rna[0]=1;struct.pack_into('<I',rna,4,2);struct.pack_into('<I',rna,0x20,0x1e0140);r.put(0x223880,bytes(rna));v=capture.sample(r)['adxt'][0]
        self.assertEqual(v['rna']['route'],0x1e0140);self.assertTrue(v['rna']['active_channels_match']);self.assertTrue(v['rna']['end_matches']);self.assertTrue(v['c4_end_matches'])
    def test_invalid_rna_pointer_is_never_followed(self):
        for child in (0,0x223881,0x223880+16*0x60,0xFFFFFFFF):
            with self.subTest(child=child):
                r=self.audio(child);v=capture.sample(r)['adxt'][0];self.assertIn('rna_unavailable',v);self.assertNotIn((child,0x60),r.reads)
    def test_rna_torn_read_is_preserved_as_unstable(self):
        r=self.audio();rna=bytearray(0x60);rna[0]=1;struct.pack_into('<I',rna,4,2);r.put(0x223880,bytes(rna));r.changing_rna=True
        v=capture.sample(r)['adxt'][0];self.assertTrue(v['rna']['active_channels_match']);self.assertFalse(v['rna']['end_matches'])
    def test_changed_c4_is_preserved_as_unstable(self):
        r=self.audio(0);r.changing_c4=True;v=capture.sample(r)['adxt'][0];self.assertFalse(v['c4_end_matches'])

if __name__=='__main__':unittest.main()
