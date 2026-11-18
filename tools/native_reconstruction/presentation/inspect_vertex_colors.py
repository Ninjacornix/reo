"""Inspect source vertex-color ranges in an owned AMO without altering it."""
import argparse,collections,struct
from pathlib import Path
def main():
 p=argparse.ArgumentParser();p.add_argument('model',type=Path);a=p.parse_args();b=a.model.read_bytes()
 def u(at):return struct.unpack_from('<I',b,at)[0]
 def children(at):
  end=at+u(at+8);cursor=at+12
  while cursor<end:
   kind,count,size=struct.unpack_from('<III',b,cursor);assert size>=12 and cursor+size<=end;yield cursor,kind,count,size;cursor+=size
  assert cursor==end
 root=u(20);objects=next(c for c in children(root) if c[1]==2);counts=collections.Counter()
 for obj in children(objects[0]):
  color=next(c for c in children(obj[0]) if c[1]==0xb0000);assert color[3]==12+16*color[2]
  for i in range(color[2]):counts[struct.unpack_from('<4f',b,color[0]+12+16*i)]+=1
 print('vertices',sum(counts.values()),'distinct',len(counts),'most_common',counts.most_common(8))
if __name__=='__main__':main()
