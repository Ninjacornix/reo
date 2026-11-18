"""Synthetic metadata tests only; no owned payload fixtures."""
import io
import struct
import unittest

import inventory as inv


def header(**changes):
    data=bytearray(64)
    data[:2]=b'\x80\0';struct.pack_into('>H',data,2,60)
    data[4:8]=bytes([3,18,4,2]);struct.pack_into('>IIh',data,8,44100,1000,500)
    data[18]=3;data[-6:]=b'(c)CRI'
    for at, value in changes.items():
        at=int(at)
        data[at:at+len(value)]=value
    return data


def iso_fixture():
    data=bytearray(40*inv.SECTOR)
    def dual(at,value):
        struct.pack_into('<I',data,at,value);struct.pack_into('>I',data,at+4,value)
    def row(name,lba,size,flags=0):
        value=bytearray(33+len(name)+(not len(name)%2))
        value[0]=len(value);value[25]=flags;value[32]=len(name);value[33:33+len(name)]=name
        struct.pack_into('<I',value,2,lba);struct.pack_into('>I',value,6,lba)
        struct.pack_into('<I',value,10,size);struct.pack_into('>I',value,14,size)
        return value
    pvd=16*inv.SECTOR;data[pvd:pvd+7]=b'\x01CD001\x01';dual(pvd+80,40)
    struct.pack_into('<H',data,pvd+128,inv.SECTOR);struct.pack_into('>H',data,pvd+130,inv.SECTOR)
    root=row(b'\0',20,inv.SECTOR,2);data[pvd+156:pvd+156+len(root)]=root
    first=row(b'A.ADX;1',21,64);directory=row(b'D',22,inv.SECTOR,2)
    data[20*inv.SECTOR:20*inv.SECTOR+len(first)+len(directory)]=first+directory
    child=row(b'B.BD;1',23,80);data[22*inv.SECTOR:22*inv.SECTOR+len(child)]=child
    return data


class MetadataTests(unittest.TestCase):
    def test_finite_header(self):
        result=inv.adx_metadata(header(),64)
        self.assertEqual(result['recognition'],'adx_structural_header')
        self.assertTrue(result['finite_header_profile'])
        self.assertEqual((result['frequency'],result['filter'],result['channels']),(44100,500,2))
        self.assertEqual(result['loop']['enabled'],0)

    def test_outside_profile_is_recognized(self):
        data=header();struct.pack_into('>I',data,8,32000)
        result=inv.adx_metadata(data,len(data))
        self.assertEqual(result['recognition'],'adx_structural_header')
        self.assertFalse(result['finite_header_profile'])
        self.assertEqual(result['reasons'],['rate_filter'])

    def test_no_filename_evidence(self):
        self.assertIsNone(inv.adx_metadata(b'not audio',100))
        data=header();data[-6:]=b'XXXXXX'
        result=inv.adx_metadata(data,len(data))
        self.assertEqual(result['recognition'],'adx_magic_candidate_unconfirmed')

    def test_short_and_extent(self):
        self.assertEqual(inv.adx_metadata(b'\x80\0',2)['recognition'],'short_adx_magic_candidate')
        self.assertFalse(inv.adx_metadata(header(),30)['finite_header_profile'])

    def test_ahx_not_supported_player(self):
        data=header();data[4]=5
        result=inv.adx_metadata(data,len(data))
        self.assertFalse(result['finite_header_profile'])
        self.assertIn('encoding',result['reasons'])

    def test_hd_chunks_and_part_bound(self):
        data=bytearray(144);data[:8]=b'IECSsreV';data[16:24]=b'IECSdaeH'
        offsets=[64,80,96,112];struct.pack_into('<4I',data,0x24,*offsets)
        for at, signature in zip(offsets,[b'IECSgorP',b'IECStesS',b'IECSlpmS',b'IECSigaV']):data[at:at+8]=signature
        result=inv.bank_hd_metadata(data,3*1024*1024)
        self.assertEqual(result['recognition'],'hsyn_hd_structural_header')
        self.assertFalse(result['within_individual_part_limit'])
        self.assertEqual(result['paired_bd_tq'],'unknown_no_authoritative_pairing')
        data[64]=0
        self.assertEqual(inv.bank_hd_metadata(data,len(data))['recognition'],'hsyn_hd_signature_candidate')

    def test_dual_endian_and_extent_refusal(self):
        raw=struct.pack('<I',7)+struct.pack('>I',7)
        self.assertEqual(inv.dual32(raw,0),7)
        with self.assertRaises(ValueError):inv.dual32(raw[:-1]+b'\x08',0)
        with self.assertRaises(ValueError):inv.read_at(io.BytesIO(b'abc'),2,2,3)
        with self.assertRaises(ValueError):inv.read_at(io.BytesIO(b'abc'),0,4,4)

    def test_iso_nested_index(self):
        data=iso_fixture();rows=inv.iso_index(io.BytesIO(data),len(data))
        self.assertEqual(rows,[dict(path='A.ADX',offset=21*inv.SECTOR,bytes=64),
                               dict(path='D/B.BD',offset=23*inv.SECTOR,bytes=80)])

    def test_iso_rejects_bad_dual_value(self):
        data=iso_fixture();data[16*inv.SECTOR+87]^=1
        with self.assertRaisesRegex(ValueError,'dual-endian'):inv.iso_index(io.BytesIO(data),len(data))

    def test_iso_rejects_multiextent_before_data(self):
        data=iso_fixture();data[20*inv.SECTOR+25]=0x80
        with self.assertRaisesRegex(ValueError,'multi-extent'):inv.iso_index(io.BytesIO(data),len(data))

    def test_version4_loop(self):
        data=header();data[18]=4;struct.pack_into('>HH',data,32,2,1)
        struct.pack_into('>H',data,38,3);struct.pack_into('>IIII',data,40,10,100,20,200)
        result=inv.adx_metadata(data,len(data));self.assertTrue(result['finite_header_profile'])
        self.assertEqual(result['loop'],dict(status='fields_read',count=2,enabled=1,index=3,positions=[10,100,20,200]))


if __name__=='__main__':unittest.main()
