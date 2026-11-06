#!/usr/bin/env python3
"""Compare reconstructed codec inputs with read-only original-entry capture."""
import argparse
import json
from pathlib import Path
import sys

import original_cases as original
ROOT=original.ROOT
sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
import adx_window_oracle as window
import adx_shared_window_oracle as shared
from sjuni_oracle import OracleError

FIELDS=('route','requested','encoded_hex','history','key','coefficients','multiplier','addend','output_samples')


class Capture:
    def instruction(self,pc,word):
        if pc in (0x1276D8,0x127C80,0x1278B8):
            active=self.mem.active;self.mem.active=False
            try:
                entry=dict(pc=pc,arguments_u64=list(self.regs[4:12]),state=self.small())
                capacity=getattr(self,'capacity',window.INPUT_CAP)
                case=original.entry_input('actual-entry',entry,self.raw(window.INPUT-16,capacity+68),window.INPUT,{})
                self.captured.append({field:case[field] for field in FIELDS})
            finally:self.mem.active=active
        return super().instruction(pc,word)


class CapturedWindow(Capture,window.Machine):pass
class CapturedShared(Capture,shared.Machine):pass


def run_window(case,profile):
    m=CapturedWindow(case,profile);m.captured=[];m.prepare()
    for action in case['actions']:
        if action=='service':result=m.run(0x12D638,[window.OUTER],full=False)
        elif action=='consume64':
            for ring in m.rings[1:]:
                m.run(0x13FA88,[ring,1,64,window.SCRATCH],full=False);m.run(0x13FBF8,[ring,0,window.SCRATCH],full=False)
            continue
        elif action=='default_reserve':
            m.mem.store(window.INNER+0x8C,4,7);m.mem.store(window.INNER+0x88,4,12)
            result=m.run(0x124810,[window.INNER,window.SCRATCH,window.SCRATCH+4,window.SCRATCH+8],full=False)
        else:raise OracleError('Unknown original window action')
        if result['failure']:break
    return m


def run_shared(case,worker,bodies):
    m=CapturedShared(case,worker,bodies);m.captured=[];m.prepare()
    for action in case['actions']:
        m.action=action;m.status_index=0;kind=action['kind']
        if kind in ('header','decode'):result=m.run(0x12D638,[window.OUTER],full=False,limit=2500000)
        elif kind=='ready':result=m.run(0x133FE0,[shared.MAIN],full=False)
        elif kind=='source':result=m.run(0x130800,[shared.FILE_RECORD],full=False)
        elif kind=='call':
            entry,argument={'repeat':(0x133928,shared.MAIN),'source_stop':(0x1306E0,shared.FILE_RECORD)}[action['entry']]
            result=m.run(entry,[argument],full=False)
        elif kind=='write_job':m.write_job(action['id']);continue
        elif kind=='consume_pcm':
            for ring in m.rings[1:]:
                m.run(0x13FA88,[ring,1,action['bytes'],window.SCRATCH],full=False);m.run(0x13FBF8,[ring,0,window.SCRATCH],full=False)
            continue
        else:raise OracleError('Unknown frozen original action')
        if result['failure']:break
    return m


def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--fixture',type=Path,required=True)
    parser.add_argument('--output',type=Path,required=True);args=parser.parse_args()
    if args.output.exists():raise OracleError('Preserve old qualification receipt')
    manifest=json.loads((args.fixture/'manifest.json').read_bytes());raw=(args.fixture/'inputs.json').read_bytes()
    if original.sha(raw)!=manifest['inputs_sha256']:raise OracleError('Frozen projection inputs changed')
    expected=json.loads(raw)['cases'];sources=original.load_sources()
    rows=[];steps=0;captured=0
    transcripts=[('window',window.corpus_inputs()),('shared',shared.corpus_inputs())]
    worker_path=ROOT/'build-native-sjuni/adx-header-math-oracle-v4/gcc/fp_worker.exe'
    bodies=shared.owned_bodies()
    with shared.math.FpuWorker(worker_path) as worker:
        for family,transcript in transcripts:
            for case in transcript['cases']:
                m=run_window(case,transcript['profile']) if family=='window' else run_shared(case,worker,bodies)
                selected=[{field:row[field] for field in FIELDS} for row in expected
                    if row.get('projection',{}).get('family')==family and row['projection']['case']==case['name']]
                if selected!=m.captured:raise OracleError('Reconstructed input differs from actual original-entry capture: '+case['name'])
                rows.append(dict(family=family,name=case['name'],original_instructions=m.total_steps,
                    codec_entries=len(m.captured),matched=True));steps+=m.total_steps;captured+=len(m.captured)
                print(family,case['name'],len(m.captured),flush=True)
    receipt=dict(schema=1,provenance='Read-only capture at actual original kernel entry during complete unchanged original-word replay; no loop teleport or decoder substitution.',
        manifest_sha256=original.sha((args.fixture/'manifest.json').read_bytes()),input_sha256=manifest['inputs_sha256'],
        validator_sha256=original.sha(Path(__file__).read_bytes()),worker_sha256=original.sha(worker_path.read_bytes()),
        source_manifest_pins=original.SOURCES,rows=rows,summary=dict(transcripts=len(rows),codec_entries=captured,original_instructions=steps,all_matched=True))
    args.output.parent.mkdir(parents=True,exist_ok=True);args.output.write_bytes(original.encode(receipt));print(json.dumps(receipt['summary'],indent=2))


if __name__=='__main__':main()
