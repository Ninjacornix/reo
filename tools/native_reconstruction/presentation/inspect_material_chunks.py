"""Print bounded NBD AMO material records for renderer source investigation."""
import argparse,struct
from pathlib import Path
def main():
 p=argparse.ArgumentParser();p.add_argument('model',type=Path);a=p.parse_args();b=a.model.read_bytes()
 def word(at):return struct.unpack_from('<I',b,at)[0]
 def chunks(at):
  end=at+word(at+8);cursor=at+12
  while cursor<end:
   kind,count,size=struct.unpack_from('<III',b,cursor);assert size>=12 and cursor+size<=end;yield cursor,kind,count,size;cursor+=size
  assert cursor==end
 model=word(20);assert model and word(24)==word(model+8)
 top=list(chunks(model));materials=next(c for c in top if c[1]==9)
 for i,(at,kind,count,size) in enumerate(chunks(materials[0])):
  raw=b[at+12:at+size];words=struct.unpack('<'+'I'*(len(raw)//4),raw);floats=struct.unpack('<'+'f'*(len(raw)//4),raw)
  print(i,hex(kind),count,size,'words',*[f'{x:08x}' for x in words],'floats',*[f'{x:.5g}' for x in floats])
if __name__=='__main__':main()
