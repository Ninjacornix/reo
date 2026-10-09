"""Export a Ghidra function map for ps2_recomp's `ghidra_output` setting.

Reads every function from a running Ghidra (ghidra-mcp HTTP server, default
127.0.0.1:8089) and writes `name,start,end,size` rows. Names use the existing
`sub_XXXXXXXX` convention so generated symbols keep the names reo's hand-written
code refers to. Read-only: no Ghidra scripts are executed.

    python tools/ghidra_export_functions.py --program /ps2/SLUS_207.65 \
        --out recomp/config/outbreak_ghidra_functions.csv

The Ghidra program must use the Emotion Engine language (r5900:LE:32:default,
ghidra-emotionengine-reloaded) and have completed auto-analysis. From Git Bash, prefix
the command with MSYS_NO_PATHCONV=1 so `/ps2/...` is not rewritten into a Windows path.
"""
import argparse
import json
import urllib.parse
import urllib.request


def get(base, path, **params):
    url = f"{base}/{path}?{urllib.parse.urlencode(params)}"
    with urllib.request.urlopen(url, timeout=300) as r:
        return json.load(r)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--program", required=True)
    ap.add_argument("--out", required=True)
    ap.add_argument("--url", default="http://127.0.0.1:8089")
    a = ap.parse_args()

    funcs = [f for f in get(a.url, "find_functions", program=a.program, limit=0, sort_by="address")["functions"]
             if not f["is_external"]]
    rows = []
    for i in range(0, len(funcs), 20):
        batch = funcs[i:i + 20]
        d = get(a.url, "get_functions", program=a.program, fields="body_start,body_end",
                functions=",".join("0x" + f["address"] for f in batch))["functions"]
        by_addr = {int(k, 16): v for k, v in d.items()}
        for f in batch:
            r = by_addr.get(int(f["address"], 16))
            if not r or "body_end" not in r:
                raise SystemExit(f"no bounds for function at 0x{f['address']}")
            start = int(r["address"], 16)
            end = int(r["body_end"], 16) + 1
            rows.append((start, end))

    # Ghidra bodies can be non-contiguous (shared tails, far chunks); body_end alone
    # then spans other functions and the recompiler emits giant overlapping
    # functions. Clamp every function to the next function's start.
    rows.sort()
    clamped = 0
    with open(a.out, "w", newline="\n") as fo:
        fo.write("name,start,end,size\n")
        for i, (start, end) in enumerate(rows):
            if i + 1 < len(rows) and end > rows[i + 1][0]:
                end = rows[i + 1][0]
                clamped += 1
            fo.write(f"sub_{start:08X},0x{start:08X},0x{end:08X},{end - start}\n")
    print(f"wrote {len(rows)} functions to {a.out}; clamped {clamped} ends to the next function start")


if __name__ == "__main__":
    main()
