"""Full byte oracle reused from vu_nop_check, with additional block controls."""
from pathlib import Path
import sys

source=(Path(__file__).resolve().parent.parent/'vu_nop_check/compare.py').read_text()
source=source.replace('len(names_l) != 328','len(names_l) != 368')
source=source.replace('320 capture + 8 fixture artifacts','320 capture + 8 original + 40 block fixture artifacts')
source=source.replace('PASS 328','PASS 368').replace('NOP bypass','compiled blocks')
exec(compile(source,'reused-vu-replay-oracle','exec'))
