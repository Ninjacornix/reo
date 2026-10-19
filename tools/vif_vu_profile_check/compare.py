"""Check actual scoped profile output, including the disabled path."""
import re
import sys
from pathlib import Path

root = Path(sys.argv[1])
enabled = (root / "enabled.log").read_text(encoding="utf-8", errors="replace")
disabled = (root / "disabled.log").read_text(encoding="utf-8", errors="replace")
records = re.findall(r"^\[VIF-KICK-TIMING\].*$", enabled, re.MULTILINE)
assert len(records) == 1, records
values = dict(re.findall(r"(\w+)=([^\s]+)", records[0]))
assert (values["vu_calls"], values["vu_cycles"], values["vu_capped"]) == ("1", "2", "0"), values
assert 0 <= int(values["vu_us"]) <= int(values["duration_us"]), values
assert values["io_depth"] == "0", values
assert "[VIF-KICK-TIMING" not in disabled, disabled
for log in (enabled, disabled):
    assert "VIF VU aggregate: PASS failures=0" in log, log
    assert "activeThreads=0" in log, log
print("PASS bounded aggregate: one VU call, two pairs, no cap, disabled emits nothing")
