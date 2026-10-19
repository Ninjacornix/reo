#!/usr/bin/env python3
"""Remove raw instruction witness tables from the exported runtime patch."""

import re


def sanitize(data):
    text = data.decode("utf-8")
    parts = text.split("diff --git ")
    for i, part in enumerate(parts):
        if "+++ b/ps2xRuntime/src/lib/irq_cpu_original_catalogue.hpp\n" in part:
            part = re.sub(
                r"(?s)(\+inline constexpr Site sites\[\]\{\n).*?(\+\};)",
                r'\1+#include "local_source_catalogues/irq_cpu_sites.inc"\n\2', part,
            )
        elif "+++ b/ps2xRuntime/src/lib/pre_entry_heap_source_scope.hpp\n" in part:
            part = re.sub(
                r"(?s)(\+    static constexpr OriginalHeapControlSite sites\[\]=\{\n).*?\}\};",
                r'\1+#include "local_source_catalogues/heap_control_sites.inc"\n+    };', part,
            )
        else:
            continue
        # Both affected files are new-file hunks; their line count must match.
        assert "@@ -0,0 +1," in part
        count = sum(line.startswith("+") and not line.startswith("+++") for line in part.splitlines())
        parts[i] = re.sub(r"@@ -0,0 \+1,\d+ @@", f"@@ -0,0 +1,{count} @@", part)
    return "diff --git ".join(parts).encode("utf-8")


if __name__ == "__main__":
    import argparse
    from pathlib import Path
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("patch", type=Path)
    args = parser.parse_args()
    args.patch.write_bytes(sanitize(args.patch.read_bytes()))
