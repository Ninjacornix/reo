"""Copy absent cohort archives into a separate, receipt-checked supplement."""
import argparse,hashlib,json,shutil
from pathlib import Path

def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--receipt',type=Path,required=True);p.add_argument('--snapshot',type=Path,required=True);p.add_argument('--build',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args()
 receipt=json.loads(a.receipt.read_text());assert receipt['status']=='passed' and not receipt['archive_drift'];assert not a.output.exists();a.output.mkdir(parents=True)
 copied={}
 for name,expected in receipt['archives_sha256'].items():
  if (a.snapshot/name).is_file():assert sha(a.snapshot/name)==expected;continue
  src=a.build/name;assert sha(src)==expected;dest=a.output/name;dest.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(src,dest);assert sha(dest)==expected and sha(src)==expected;copied[name]=expected
 (a.output/'receipt.json').write_text(json.dumps({'status':'passed','cohort_sha256':sha(a.receipt),'archives_sha256':copied},indent=2)+'\n')
 print(json.dumps({'copied':len(copied),'status':'passed'}))
if __name__=='__main__':main()
