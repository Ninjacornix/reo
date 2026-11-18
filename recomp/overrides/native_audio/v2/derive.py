#!/usr/bin/env python3
"""Mechanical Aggregate2: namespace + packet3 types/includes; no DSP/lifecycle edit."""
import argparse,hashlib,json
from pathlib import Path
HERE=Path(__file__).resolve().parent
PARENT=HERE.parent
PIN='bc33ed692ea0be697dcd0b8d3950e534c8dca3226dc62b119b8dfd3d1523a8db'
TRANSPORT_PIN='67ca38ec3ad3e111b39c3bfa6e0ebb11783a93d3508b5bcbcc4bb78e9edac845'
FILES=('aggregate.h','aggregate.cpp','tests.cpp','oracle_transport.hpp')
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def check_parent():
    if sha(PARENT/'identity.json')!=PIN:raise ValueError('Frozen Aggregate1 identity changed')
    for name,digest in json.loads((PARENT/'identity.json').read_bytes())['candidate_sha256'].items():
        if sha(PARENT/name)!=digest:raise ValueError('Frozen Aggregate1 source changed '+name)
    if sha(PARENT/'oracle_transport.hpp')!=TRANSPORT_PIN:raise ValueError('Parent input-only transport changed')
def derived(name):
    s=(PARENT/name).read_text(encoding='utf-8')
    s=s.replace('reo::native::audio_aggregate','reo::native::audio_aggregate::v2')
    s=s.replace('namespace packet=bank_packets;','namespace packet=bank_packets::v3;')
    s=s.replace('recomp/overrides/native_banks/','recomp/overrides/native_banks/v3/')
    return '// Mechanically derived from frozen Aggregate1 by derive.py; grouped packet3 contract.\n'+s
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--check',action='store_true');a=p.parse_args();check_parent()
    for name in FILES:
        s=derived(name)
        if a.check:
            if (HERE/name).read_text(encoding='utf-8')!=s:raise ValueError('Mechanical derivation drift '+name)
        else:(HERE/name).write_text(s,encoding='utf-8',newline='\n')
    print('Aggregate2 derivation '+('checked' if a.check else 'written'))
if __name__=='__main__':main()
