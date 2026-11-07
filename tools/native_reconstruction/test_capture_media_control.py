import struct,unittest
import capture_media_control as capture

class Reader:
    def __init__(self):self.spans={};self.reads=[];self.changing=False
    def put(self,at,data):self.spans[at]=data
    def read(self,at,size):
        self.reads.append((at,size))
        if self.changing and at==0x800044 and self.reads.count((at,size))==2:return struct.pack('<5I',1,4,6,0,0)
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

if __name__=='__main__':unittest.main()
