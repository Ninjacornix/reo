#!/usr/bin/env python3
"""Derive logical audio-source geometry from pinned metadata; no payload/player read."""
import argparse
import collections
import hashlib
import json
from pathlib import Path
import re
from sjuni_oracle import Elf

ROOT = Path(__file__).resolve().parents[2]
MEMBERS = ROOT / 'build-native-sjuni/audio-asset-inventory/file1-v1/members.json'
MEMBERS_SHA = '276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2'
ELF_SHA = '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
INTERVALS = {0x133490:0x133580, 0x133618:0x133630, 0x133630:0x133708,
             0x131c50:0x131d18, 0x1307a8:0x1307e8, 0x130800:0x130b78}


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args(); out = args.output.resolve()
    if out.exists() or not out.is_relative_to(ROOT / 'build-native-sjuni/audio-source-geometry'):
        raise ValueError('Fresh scoped output required')
    if sha(MEMBERS) != MEMBERS_SHA: raise ValueError('Pinned inventory drift')
    elf = Elf(ROOT / 'game_data/SLUS_207.65')
    if elf.sha256 != ELF_SHA: raise ValueError('Owned executable drift')
    audits = []
    for start, end in INTERVALS.items():
        path = ROOT / f'recomp/config/output/sub_{start:08X}_0x{start:x}.cpp'
        comments = {int(a,16):int(b,16) for a,b in re.findall(rb'//\s*0x([0-9a-fA-F]+):\s*0x([0-9a-fA-F]+)', path.read_bytes())}
        matched = 0; zeros = []
        for pc in range(start,end,4):
            word = int.from_bytes(elf.read(pc,4),'little')
            if pc in comments:
                if comments[pc] != word: raise ValueError('Source word mismatch')
                matched += 1
            elif word: raise ValueError('Missing nonzero source word')
            else: zeros.append(pc)
        audits.append(dict(start=start,end=end,body_sha256=hashlib.sha256(elf.read(start,end-start)).hexdigest(),
                           source=path.relative_to(ROOT).as_posix(),source_sha256=sha(path),matched_words=matched,omitted_zero_pcs=zeros))
    rows = [r for r in json.loads(MEMBERS.read_bytes()) if r['recognition'] == 'adx_structural_header']
    groups = collections.defaultdict(collections.Counter)
    insufficient = []; short = 0
    for row in rows:
        aligned = row['bytes'] % 2048 == 0
        groups[row['names'][0]]['whole_sector' if aligned else 'partial_sector'] += 1
        short += row['bytes'] < 2048
        h = row['adx']; minimum = h['header_bytes'] + ((h['total_samples'] + 31)//32)*h['channels']*18
        if minimum > row['bytes']:
            insufficient.append(dict(member=row['member'],bytes=row['bytes'],minimum_declared_blocks=minimum))
    report = dict(schema=1,scope='Metadata geometry plus static owned-word audit, not source-route execution or native admission',
                  members_sha256=MEMBERS_SHA,elf_sha256=ELF_SHA,tool_sha256=sha(Path(__file__)),
                  identified_references=len(rows),unique_payload_hashes=len({r['sha256'] for r in rows}),
                  whole_sector_references=sum(r['bytes']%2048==0 for r in rows),
                  partial_sector_references=sum(r['bytes']%2048!=0 for r in rows),
                  shorter_than_sector_references=short,by_first_archive={k:dict(v)for k,v in sorted(groups.items())},
                  insufficient_declared_block_extent=insufficient,audits=audits,game_run=False,device_opened=False,
                  limitations=['Archive member length does not identify live StartAfs/StartMem/LSC route',
                               'Archive alignment does not prove padding belongs to a member ByteView',
                               'Static source matching is not execution coverage',
                               'No automatic zero padding, native admission widening or tail completion is inferred'])
    if sha(MEMBERS) != MEMBERS_SHA: raise ValueError('Inventory changed during audit')
    out.mkdir(parents=True); path = out / 'report.json'
    path.write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps({k:report[k]for k in ['identified_references','whole_sector_references','partial_sector_references','shorter_than_sector_references']}))
    print(json.dumps(dict(report_sha256=sha(path),audited_bodies=len(audits),matched_words=sum(a['matched_words']for a in audits),
                          omitted_zeros=sum(len(a['omitted_zero_pcs'])for a in audits),insufficient_extents=len(insufficient))))


if __name__ == '__main__': main()
