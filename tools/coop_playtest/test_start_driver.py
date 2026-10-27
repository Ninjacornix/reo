"""Edition isolation and read-only start-driver regression checks."""
import json
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch
import start_driver as driver

class StartProfileTests(unittest.TestCase):
    def test_each_edition_reads_only_its_gameplay_block(self):
        for game, address in [('file1',0x4BADD0),('file2',0x4DB390)]:
            with self.subTest(game=game), tempfile.TemporaryDirectory() as temp:
                folder=Path(temp)
                players=[dict(number=i,pid=i,image=str(folder/f'p{i}.exe'),creationFileTime=i,inputFile='unused') for i in [1,2]]
                identities={p['pid']:{k:p[k] for k in ['pid','image','creationFileTime']} for p in players}
                (folder/'run.json').write_text(json.dumps({'players':players}))
                reads=[];instances=[];presses=[];clock=[0.0]
                class Ram:
                    def __init__(self, identity, elf):self.closed=False;instances.append(self)
                    def snapshot(self):return {'memberCount':2}
                    def read(self, at, size):
                        reads.append((self.game,at,size))
                        data=bytearray(size);data[0]=2;return data
                    def close(self):self.closed=True
                def sleep(seconds):clock[0]+=seconds
                with patch('lobby_driver.waiting_room',return_value=True):
                    result=driver.drive(folder,{'game':game,'elf':'unused','players':players},timeout=10,
                      reader_factory=Ram,identity_reader=identities.get,pad_writer=lambda p,b:presses.append((p['number'],b)),
                      monotonic=lambda:clock[0],sleeper=sleep)
                self.assertTrue(result['allInGameplay'])
                self.assertEqual(result['game'],game)
                self.assertEqual(set(reads),{(game,address,0x40)})
                self.assertEqual(presses,[(1,'left'),(1,'cross')])
                self.assertTrue(all(r.closed for r in instances))
    def test_unknown_edition_rejected_before_attachment(self):
        with self.assertRaises(ValueError):driver.drive('.',{'game':'unknown'})

if __name__=='__main__':unittest.main()
