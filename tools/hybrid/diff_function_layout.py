"""Align a File #1 function's disassembly with its File #2 counterpart.

Prints instruction pairs whose mnemonic/registers match but whose immediates or
jump targets differ - the address and field-offset changes between editions.
Reads the instruction comments the recompiler writes into each generated body.

usage: diff_function_layout.py FILE1_SOURCE FILE2_SOURCE
"""
import difflib, re, sys

LINE = re.compile(r'//\s*0x([0-9a-f]+):\s*0x[0-9a-f]+\s+(\S+)\s*(.*?)(?:\s*\(Delay Slot\))?\s*$')


def load(path):
    rows = []
    for text in open(path, encoding='utf8', errors='replace'):
        m = LINE.search(text)
        if m:
            address, mnemonic, operands = m.groups()
            rows.append((int(address, 16), mnemonic, operands.strip()))
    return rows


def shape(row):
    _, mnemonic, operands = row
    return mnemonic + ' ' + re.sub(r'-?0x[0-9A-Fa-f]+|func_[0-9A-Fa-f]+|\. \+ 4 \+ \([^)]*\)', '#', operands)


a, b = load(sys.argv[1]), load(sys.argv[2])
matcher = difflib.SequenceMatcher(None, [shape(r) for r in a], [shape(r) for r in b], autojunk=False)
print(f'file1 {len(a)} instructions, file2 {len(b)}, similarity {matcher.ratio():.3f}')
for tag, i1, i2, j1, j2 in matcher.get_opcodes():
    if tag == 'equal':
        for x, y in zip(a[i1:i2], b[j1:j2]):
            if x[2] != y[2] and not x[1].startswith('b'):
                print(f'  {x[0]:06x} {x[1]:8s} {x[2]:34s} | {y[0]:06x} {y[2]}')
    else:
        print(f'  -- {tag}: file1 {i2 - i1} vs file2 {j2 - j1} instructions at {a[i1][0] if i1 < len(a) else 0:06x} / {b[j1][0] if j1 < len(b) else 0:06x}')
