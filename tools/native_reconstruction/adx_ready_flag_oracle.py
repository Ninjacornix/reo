#!/usr/bin/env python3
"""Independent raw alignment/count and loop-enable fields through original ready."""
import argparse
import copy
import importlib.util
import json
import os
from pathlib import Path
import struct
import adx_window_v2_oracle as original

ROOT=Path(__file__).resolve().parents[2]
BASE=ROOT/'build-native-sjuni/adx-ready-flag'
CAPTURE=ROOT/'game/native/adx_window/v2/capture_original.py'
sha=original.sha
encode=original.old.compact_serialized


def inputs():
    frozen=json.loads((ROOT/'build-native-sjuni/adx-window-v2-oracle/frozen-v3/inputs.json').read_bytes())
    base=next(c for c in frozen['cases']if c['name']=='ready-44100-finite')
    cases=[]
    for rate in (24000,44100,48000):
        for version in (3,4):
            for count in (0,1,13,-1):
                for flag in (0,1):
                    c=copy.deepcopy(base);data=bytearray.fromhex(c['file_hex'])
                    struct.pack_into('>II',data,8,rate,1024);data[18]=version
                    offset=32 if version==4 else 20
                    # Zero the history/extension area, then set the two fields
                    # independently. The header declares its existing96 bytes.
                    data[20:96]=bytes(76)
                    struct.pack_into('>hHHHIIII',data,offset,count,flag,0,1,32,114,96,150)
                    c.update(name=f'flag-{flag}-count-{count}-rate-{rate}-v{version}',file_hex=data.hex(),
                             domain='Independent raw count/alignment and enable flag; header/ready only')
                    cases.append(c)
    return cases


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--freeze',action='store_true');p.add_argument('--frozen',type=Path)
    p.add_argument('--compiler',choices=original.FP_PARENTS);p.add_argument('--output',type=Path,required=True)
    a=p.parse_args();out=a.output.resolve()
    if out.exists()or not out.is_relative_to(BASE):raise ValueError('Fresh scoped output required')
    bodies,authority=original.authority()
    engines={n:sha(Path(__file__).with_name(n).read_bytes())for n in ['adx_window_v2_oracle.py',*original.ENGINE_NAMES]}
    if a.freeze:
        out.mkdir(parents=True);(out/'inputs.json').write_bytes(encode(dict(cases=inputs())))
        identity=dict(schema=1,authority=authority,oracle_sha256=sha(Path(__file__).read_bytes()),
                      capture_sha256=sha(CAPTURE.read_bytes()),engines=engines,inputs_sha256=sha((out/'inputs.json').read_bytes()),
                      correction_exists=(ROOT/'game/native/adx_window/v2/ready_flag_r1/stream_window.cpp').exists())
        (out/'manifest.json').write_bytes(encode(identity));print('Frozen48 independent flag/count cases');return
    if not a.frozen or not a.compiler:raise ValueError('Frozen inputs and qualified worker required')
    identity=json.loads((a.frozen/'manifest.json').read_bytes())
    if identity['authority']!=authority or identity['engines']!=engines or sha(Path(__file__).read_bytes())!=identity['oracle_sha256']or sha(CAPTURE.read_bytes())!=identity['capture_sha256']or sha((a.frozen/'inputs.json').read_bytes())!=identity['inputs_sha256']:raise ValueError('Frozen source/input drift')
    folder=original.FP_PARENTS[a.compiler];parent=json.loads((folder/'original-fixture.json').read_bytes())
    if sha((folder/'original-fixture.json').read_bytes())!=original.FP_PARENT_SHA[a.compiler]:raise ValueError('FP authority changed')
    compiler=Path(parent['compatibility']['compiler']);worker=folder/'fp_worker.exe'
    if sha(compiler.read_bytes())!=parent['compatibility']['compiler_sha256']or sha(worker.read_bytes())!=parent['compatibility']['worker_binary_sha256']:raise ValueError('Exact compiler/worker changed')
    os.environ['PATH']=str(compiler.parent)+os.pathsep+os.environ.get('PATH','')
    spec=importlib.util.spec_from_file_location('ready_capture',CAPTURE);capture=importlib.util.module_from_spec(spec);spec.loader.exec_module(capture)
    rows=[];out.mkdir(parents=True)
    with original.old.math.FpuWorker(worker)as fp:
        for case in json.loads((a.frozen/'inputs.json').read_bytes())['cases']:
            result=original.execute(case,fp,bodies)
            prior=original.old.Machine;original.old.Machine=capture.Capture
            try:observed=original.execute(case,fp,bodies)
            finally:original.old.Machine=prior
            if encode(result)!=encode(observed):raise ValueError('Read-only observations changed original transcript')
            if any(r['failure']for op in result['operations']for r in(op['results']if isinstance(op['results'],list)else[op['results']])):raise ValueError('Partial original ready path')
            path=out/(case['name']+'.json');path.write_bytes(encode(dict(original=result,observations=capture.Capture.latest.observations)))
            rows.append(dict(name=case['name'],sha256=sha(path.read_bytes()),instructions=result['original_instructions']))
    receipt=dict(schema=1,status='passed unchanged original ready observations',cases=rows,original_instructions=sum(r['instructions']for r in rows),
                 manifest_sha256=sha((a.frozen/'manifest.json').read_bytes()),compiler_sha256=sha(compiler.read_bytes()),fp_worker_sha256=sha(worker.read_bytes()),
                 original_transcripts_unchanged=True,game_run=False,device_opened=False)
    (out/'receipt.json').write_bytes(encode(receipt));print(json.dumps(dict(cases=len(rows),instructions=receipt['original_instructions'])))


if __name__=='__main__':main()
