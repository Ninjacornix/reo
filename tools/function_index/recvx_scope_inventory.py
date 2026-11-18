"""Enumerate pinned reference source without executing either game.

Balanced, comment/literal-aware C definition discovery is an inventory aid, not
a C compiler or proof of implementation completeness. It retains duplicates.
"""
from __future__ import annotations
import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import re
import subprocess

PIN = '657b0c0c9489943116c71f151804ad7304fca975'
ROOT = Path(__file__).resolve().parents[2]


def mask(text):
    return re.sub(r'/\*.*?\*/|//[^\n]*|"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'',
                  lambda m: re.sub(r'[^\n]', ' ', m.group()), text, flags=re.S)


def function_records(text):
    """One record per named top-level definition; multiline headers are admitted."""
    clean = mask(text)
    tokens = list(re.finditer(r'[A-Za-z_]\w*|[^\s]', clean))
    records = []
    depth, opening, pending, boundary = 0, None, None, 0
    for index, token in enumerate(tokens):
        value = token.group()
        if value == '{':
            if depth == 0:
                pending = None
                # Ordinary C function headers end in a balanced argument list.
                if index and tokens[index-1].group() == ')':
                    j, nesting = index-1, 0
                    while j >= 0:
                        current = tokens[j].group()
                        if current == ')': nesting += 1
                        elif current == '(':
                            nesting -= 1
                            if nesting == 0: break
                        j -= 1
                    if j > 0 and re.fullmatch(r'[A-Za-z_]\w*', tokens[j-1].group()):
                        name = tokens[j-1].group()
                        header_start = max(clean.rfind('\n', boundary, tokens[j-1].start())+1, boundary)
                        # Header line above can contain a multiline return type;
                        # name-line/body boundaries remain the stable identity.
                        pending = dict(symbol=name, name_offset=tokens[j-1].start(),
                                       header_start=header_start, body_start=token.start())
                        opening = token.start()
            depth += 1
        elif value == '}':
            depth -= 1
            if depth < 0: raise ValueError('Unbalanced closing brace')
            if depth == 0:
                if pending is not None:
                    body = clean[opening+1:token.start()]
                    raw_body = text[opening:token.end()].encode('utf-8')
                    pending.update(start_line=text.count('\n',0,pending['name_offset'])+1,
                                   end_line=text.count('\n',0,token.end())+1,
                                   body_start_line=text.count('\n',0,opening)+1,
                                   body_end_offset=token.end(),
                                   body_sha256=hashlib.sha256(raw_body).hexdigest(),
                                   implementation_shape='empty' if not body.strip() else 'nonempty',
                                   masked_body=body)
                    records.append(pending)
                pending, opening, boundary = None, None, token.end()
        elif value == ';' and depth == 0:
            boundary = token.end()
    if depth: raise ValueError('Unbalanced open brace')
    return records


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--reference',required=True,type=Path)
    parser.add_argument('--out',type=Path,default=ROOT/'build-function-index/recvx-complete-source-inventory.json')
    args=parser.parse_args()
    reference=args.reference.resolve()
    def git(*a): return subprocess.check_output(['git','-C',str(reference),*a],text=True,encoding='utf-8').strip()
    assert git('rev-parse','HEAD')==PIN
    assert not git('status','--porcelain','--untracked-files=no')
    files=[]
    for p in sorted((reference/'src').rglob('*')):
        if not p.is_file() or p.suffix.lower() not in ('.c','.s'): continue
        raw=p.read_bytes()
        text=raw.decode('utf-8-sig',errors='replace')
        records=function_records(text) if p.suffix.lower()=='.c' else []
        for record in records:
            record.pop('masked_body')
        placeholders=[dict(symbol=m[1],line=text.count('\n',0,m.start())+1)
                      for m in re.finditer(r'\bINCLUDE_ASM\s*\(\s*"[^"]+"\s*,\s*(\w+)\s*\)',text)]
        files.append(dict(path=p.relative_to(reference).as_posix(),sha256=hashlib.sha256(raw).hexdigest(),
                          functions=records,assembly_placeholders=placeholders,
                          file_bytes=len(raw),source_kind='C' if p.suffix.lower()=='.c' else 'assembly'))
    counts=Counter(record['implementation_shape'] for f in files for record in f['functions'])
    result=dict(schema=1,reference_commit=PIN,files=files,
                body_hash_form='UTF-8 encoded decoded source text, BOM removed, source newline form preserved; raw file SHA-256 remains authoritative for original bytes.',
                counts=dict(files=len(files),c_files=sum(f['source_kind']=='C' for f in files),
                            definitions=sum(len(f['functions']) for f in files),
                            assembly_placeholders=sum(len(f['assembly_placeholders']) for f in files),
                            **counts),
                limits='Syntactic inventory only. Nonempty does not prove implemented semantics. Every comparison disposition requires separate review; placeholders and duplicates are retained.')
    args.out.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(result['counts']))


if __name__=='__main__': main()
