"""Decode local GPU retirement failures; an aggregate sticky is not a culprit."""
import argparse
import json
from pathlib import Path
import re

ap = argparse.ArgumentParser(description=__doc__)
ap.add_argument("log", type=Path)
ap.add_argument("--out", type=Path)
a = ap.parse_args()
if a.out and a.out.exists():
    raise SystemExit("Preserve the prior failure report")
conditions = {
    1: "producer result already failed",
    2: "authority completion sticky already failed",
    4: "consumer certificate already failed",
    8: "consumer not ready",
    16: "consumer not validated",
    32: "consumer already committed before admission",
    64: "producer tape already failed",
    128: "producer tape magic/version mismatch",
    256: "producer tape not ready",
    512: "producer tape status nonzero",
    1024: "generation or job identity mismatch",
    2048: "producer/consumer event counts differ",
    4096: "consumer certificate magic/version mismatch",
    8192: "post-state PC differs from producer tape PC",
    16384: "post-state E-bit not set",
}
records = []
with a.log.open(encoding="utf8", errors="replace") as stream:
    for line in stream:
        match = re.search(r"\[GPU-ARRAY-FIRST-LOCAL-FAILURE\] ordinal=(\d+) error=(\d+) global=(\d+) multi=(\d+) receipt=(.*)", line)
        if not match:
            continue
        words = [int(word, 16) for word in match[5].split()]
        if len(words) != 16:
            raise SystemExit("Truncated local retirement receipt")
        mask = words[13]
        records.append({"ordinal": int(match[1]), "error": int(match[2]),
                        "batch_sticky": int(match[3]), "multi_effect": bool(int(match[4])),
                        "receipt_words": words, "admission_mask": mask,
                        "failed_conditions": [name for bit, name in conditions.items() if mask & bit],
                        "unknown_mask_bits": mask & ~32767})
result = {"scope": "first local failure; predicate bits require diagnostic admission module 9aa8aeab",
          "records": records,
          "limitations": "A prior-sticky predicate identifies inherited failure, not its original cause. No records does not imply a successful run."}
rendered = json.dumps(result, indent=2)
if a.out:
    a.out.write_text(rendered + "\n", encoding="utf8")
print(rendered)
