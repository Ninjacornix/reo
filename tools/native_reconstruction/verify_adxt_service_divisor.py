#!/usr/bin/env python3
"""Compare frozen original ready rows and detect lost game service settings."""
import argparse,hashlib,json,os,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--compiler',type=Path,required=True);p.add_argument('--native-receipt',type=Path,required=True);p.add_argument('--manifest',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists() or not out.is_relative_to(ROOT/'build-native-sjuni/adxt-service-divisor'):raise ValueError('Fresh owned output required')
    native=json.loads(a.native_receipt.read_bytes());manifest=json.loads(a.manifest.read_bytes())
    if native['status']!='native media pipeline standalone build and tests passed' or native['manifest_sha256']!=sha(a.manifest) or native['compiler_sha256']!=sha(a.compiler):raise ValueError('Matching complete native build required')
    def verify():
        for n,d in manifest['files'].items():
            if sha(ROOT/n)!=d:raise ValueError('Source drift '+n)
        for n,d in native['libraries'].items():
            if sha(ROOT/n)!=d:raise ValueError('Archive drift '+n)
    verify();out.mkdir(parents=True);env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
    record=dict(status='failed',manifest_sha256=sha(a.manifest),native_receipt_sha256=sha(a.native_receipt),compiler_sha256=sha(a.compiler),checks=[],detected_faults=[],game_run=False,device_opened=False)
    window=ROOT/'game/native/adx_window/v2/service_r4';instances=ROOT/'game/native/adxt_instances'
    def run(label,sources,negative=False):
        exe=out/(label+'.exe');cmd=[a.compiler,'-std=c++20','-O2','-pthread','-Wall','-Wextra','-Wpedantic','-Werror','-fno-fast-math','-ffp-contract=off','-frounding-math','-I'+str(window),'-I'+str(instances),*sources,'-Wl,--start-group',*[ROOT/n for n in native['libraries']],'-Wl,--end-group','-o',exe]
        v=subprocess.run(list(map(str,cmd)),capture_output=True,text=True,env=env,timeout=90);(out/(label+'-compile.txt')).write_text(v.stdout+v.stderr,encoding='utf-8',newline='\n')
        if v.returncode:raise ValueError('Compile failed '+label)
        v=subprocess.run([str(exe)],capture_output=True,text=True,env=env,timeout=60);(out/(label+'.txt')).write_text(v.stdout+v.stderr,encoding='utf-8',newline='\n');record['checks'].append(dict(label=label,exit=v.returncode,negative=negative,exe_sha256=sha(exe)))
        if (v.returncode==0)==negative:raise ValueError('Unexpected result '+label)
        print(label+': '+('fault detected' if negative else 'passed'),flush=True)
        return v.stdout.strip()
    try:
        record['native_rows']=run('native-quantum',[window/'quantum_tests.cpp'])
        cases=json.loads((ROOT/'build-native-sjuni/adxt-ready-quantum/original-llvm-v1/expected.json').read_bytes())
        gcc=ROOT/'build-native-sjuni/adxt-ready-quantum/original-gcc-v1/expected.json'
        if sha(gcc)!=sha(ROOT/'build-native-sjuni/adxt-ready-quantum/original-llvm-v1/expected.json'):raise ValueError('Original worker rows differ')
        header=(window/'quantum_cases.hpp').read_text()
        for case in cases:
            rate=int(case['template'].split('-')[1]);line='{'+f"{rate},{str(case['template'].endswith('-loop')).lower()},{case['divisor']},{case['request_u32']}"+'},'
            if header.count(line)!=1 or case['request_u32']!=case['decoder_request_u32']:raise ValueError('Frozen captured row differs')
        record['original_expected_sha256']=sha(gcc);record['original_cases']=len(cases)
        for label,path,anchor,replacement,tests in (
            ('hardcode-divisor60',window/'stream_window.cpp','rate / static_cast<std::uint32_t>(config_.service_divisor)','rate / 60',window/'quantum_tests.cpp'),
            ('retain-old76-group-limit',window/'stream_window.cpp','groups > static_cast<std::int32_t>(adx_workspace::maximum_pcm_samples_per_plane / 32)','groups > 76',window/'quantum_tests.cpp'),
            ('lose-stable-divisor',instances/'instances.cpp','if(r.service_divisor)requested.player.decoder.service_divisor=*r.service_divisor;','',instances/'game_control_tests.cpp'),
        ):
            body=path.read_text()
            if body.count(anchor)!=1:raise ValueError('Mutation anchor '+label)
            changed=out/(label+'.cpp');changed.write_text(body.replace(anchor,replacement),encoding='utf-8',newline='\n');run(label,[changed,tests],True);record['detected_faults'].append(label)
        verify();record['status']='original ready rows and stable service divisor qualified'
    finally:
        record['outputs_sha256']={p.name:sha(p)for p in out.iterdir()if p.suffix in ('.txt','.cpp')};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps({'status':record['status'],'receipt_sha256':sha(out/'receipt.json')}))
if __name__=='__main__':main()
