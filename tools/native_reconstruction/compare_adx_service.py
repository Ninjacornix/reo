#!/usr/bin/env python3
"""Transport frozen original-word service observations to an independent core.

No oracle or native decoder arithmetic is imported. Expected states come only
from the separately generated owned-word fixture. The transport excludes the
guest stack/register ABI, which the typed core does not represent.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import struct
import subprocess

ROOT = Path(__file__).resolve().parents[2]
FIXTURE_SHA = '2ece8cd061280fca02b5cf648f9ca70fd8073e8d6118b451a1130ffd2fe09954'
FROZEN = {
    'game/native/adx_control/predictor_service.cpp':'50f3863f3f4cf623a0eefc04a6c12bc5aa025b48450af43cef7fdfe2e9dbbfdb',
    'game/native/adx_control/predictor_service.hpp':'50e90ebc916ebdf79163f15f10e0a05e5298273dad4c77c4cd572808e8751063'}
EFFECTS = {'none':0,'cancel':1,'release':2,'request':3,'acknowledge':4}


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def encode(data):
    if data['schema'] != 1 or data['counts']['cases'] != 74 or data['counts']['codec_calls'] != 54:
        raise ValueError('Expected complete independent 74-case/54-hook corpus')
    output = bytearray(b'ADXSRV1\0'+struct.pack('<II',1,len(data['cases'])))
    def word(value):
        output.extend(struct.pack('<I',value&0xFFFFFFFF))
    def snapshot(state):
        words = state['context_words_u32']
        if len(words) != 15:
            raise ValueError('Unexpected context image extent')
        for value in words:
            word(value)
        word(state['odd_flag_u32'])
        for name in ('left_bytes_hex','right_bytes_hex'):
            value = bytes.fromhex(state[name])
            if len(value) != 64:
                raise ValueError('Unexpected synthetic payload extent')
            output.extend(value)
    for case in data['cases']:
        name = case['name'].encode('utf-8')
        word(len(name));output.extend(name)
        snapshot(case['initial_state'])
        inputs,expected = case['input'],case['expected']
        if expected['return_is_defined']:
            raise ValueError('Original service must remain void')
        word(inputs['scripted_result_i32']);word(EFFECTS[inputs['scripted_effect']]);word(int(inputs['scripted_payload']))
        events = expected['events']
        if len(events)>1:
            raise ValueError('Unexpected service codec count')
        word(len(events))
        for event in events:
            args,stack = event['arguments_lower64'],event['stack_argument_words_u32']
            if len(args)!=8 or len(stack)!=3 or event['route'] not in ('mono','stereo'):
                raise ValueError('Unexpected codec ABI image')
            mono = event['route']=='mono'
            word(1 if mono else 2)
            word(args[0]);word(args[1]);word(args[2]);word(0 if mono else args[4])
            word(args[4] if mono else args[6]);word(args[5] if mono else args[7])
            word(args[7] if mono else stack[1]);word(stack[0] if mono else stack[2])
            snapshot(event['before']);snapshot(event['after'])
        snapshot(expected['state'])
    return output


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--cxx',required=True)
    parser.add_argument('--output',required=True,type=Path)
    parser.add_argument('--fixture',type=Path,default=ROOT/'build-native-sjuni/adx-service-fixtures.json')
    args = parser.parse_args()
    output = args.output.resolve()
    allowed = ROOT/'build-native-sjuni'
    if output==allowed or not output.is_relative_to(allowed):
        raise ValueError('Use a private ignored output directory')
    compiler = shutil.which(args.cxx)
    if not compiler:
        raise ValueError('Existing C++20 compiler required')
    if sha(args.fixture)!=FIXTURE_SHA:
        raise ValueError('Frozen independent service fixture changed')
    if any(sha(ROOT/name)!=value for name,value in FROZEN.items()):
        raise ValueError('Independently frozen native service changed')
    data = json.loads(args.fixture.read_text(encoding='utf-8'))
    output.mkdir(parents=True,exist_ok=True)
    wire = output/'fixtures.bin';wire.write_bytes(encode(data))
    paths = [ROOT/name for name in FROZEN]+[
        ROOT/'game/native/adx_control/predictor_control.cpp',ROOT/'game/native/adx_control/predictor_control.hpp',
        ROOT/'game/native/adx_control/predictor_service_tests.cpp',Path(__file__)]
    sources = {p.relative_to(ROOT).as_posix():sha(p) for p in paths}
    executable = output/'predictor_service_tests.exe'
    command = [compiler,'-std=c++20','-O1','-Wall','-Wextra','-Wpedantic','-Werror',
        str(ROOT/'game/native/adx_control/predictor_control.cpp'),str(ROOT/'game/native/adx_control/predictor_service.cpp'),
        str(ROOT/'game/native/adx_control/predictor_service_tests.cpp'),'-o',str(executable)]
    env = dict(os.environ)
    env['PATH'] = str(Path(compiler).parent)+os.pathsep+env.get('PATH','')
    proof = dict(schema=1,status='running',game_run=False,runtime_linked=False,codec_algorithm_executed=False,
        compiler=compiler,compiler_sha256=sha(Path(compiler)),source_sha256=sources,
        original_fixture_sha256=FIXTURE_SHA,original_identity=data['identity'],
        frozen_before_fixture_inspection=FROZEN,wire_sha256=sha(wire),checks=[])
    try:
        for name,call in [('compile',command),('unit',[str(executable),'--unit']),
                ('original_comparison',[str(executable),'--fixtures',str(wire)])]:
            result = subprocess.run(call,env=env,capture_output=True,text=True,timeout=90)
            proof['checks'].append(dict(name=name,command=call,exit_code=result.returncode,stdout=result.stdout,stderr=result.stderr))
            if result.returncode:
                raise RuntimeError(name+' failed:\n'+result.stdout+result.stderr)
        metrics = {name:int(value) for name,value in re.findall(r'(cases|hooks|state_images|context_words|payload_bytes|ignored_void_returns)=(\d+)',result.stdout)}
        if metrics != dict(cases=74,hooks=54,state_images=182,context_words=2730,payload_bytes=23296,ignored_void_returns=74):
            raise ValueError('Incomplete original service comparison')
        if sources!={p.relative_to(ROOT).as_posix():sha(p) for p in paths}:
            raise ValueError('Native/test source changed during comparison')
        proof.update(status='passed',comparison=metrics,executable_sha256=sha(executable),unchanged_from_independent_implementation=True)
    except Exception as error:
        proof.update(status='failed',failure=str(error));raise
    finally:
        proof['limitations'] = ['Synchronous typed scalar service and scripted mutations only; no codec/PCM algorithm executed.',
            'Guest stack/register effects excluded; original service is void and raw return observations are ignored.',
            'Opaque buffer tokens do not establish storage capacity/lifetime, scheduling, incarnation or cancellation join.',
            'Missing decoder refusal is new prepublication native admission metadata, not an original service error result.']
        (output/'receipt.json').write_text(json.dumps(proof,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=proof['status'],**metrics)))


if __name__ == '__main__':
    main()
