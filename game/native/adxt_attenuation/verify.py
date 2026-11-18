#!/usr/bin/env python3
"""Compare native attenuation to frozen owned setter/getter/type-5 observations."""
import argparse,hashlib,json,os,subprocess,sys
from pathlib import Path
HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[2]
ORIGINAL=ROOT/'build-native-sjuni/adxt-attenuation/original-v3'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists() or not out.is_relative_to(ROOT/'build-native-sjuni/adxt-attenuation'):raise ValueError('Fresh owned output required')
    manifest=json.loads((HERE/'manifest.json').read_bytes())
    if sha(ORIGINAL/'receipt.json')!=manifest['original_reference']['sha256']:raise ValueError('Pinned original receipt changed')
    original=json.loads((ORIGINAL/'receipt.json').read_bytes());plan=json.loads((ORIGINAL/'input-manifest.json').read_bytes())
    if original['native_core_authored'] or original['status']!='owned attenuation/setter/getter/type5 producer replay completed' or sha(ORIGINAL/'input-manifest.json')!=original['input_manifest_sha256'] or sha(ORIGINAL/'expected.json')!=original['expected_sha256'] or sha(ORIGINAL/'inputs.json')!=plan['inputs_sha256']:raise ValueError('Frozen original evidence changed')
    oracle=ROOT/'tools/native_reconstruction/adxt_attenuation_oracle.py'
    if sha(oracle)!=plan['oracle_sha256']:raise ValueError('Oracle changed')
    sys.path.insert(0,str(oracle.parent));import adxt_attenuation_oracle as owned
    if owned.authority()!=plan['authority']:raise ValueError('Original authority drift')
    sources=manifest['files']
    def verify():
        for name,digest in sources.items():
            if sha(ROOT/name)!=digest:raise ValueError('Native source drift '+name)
    verify();out.mkdir(parents=True);inputs=json.loads((ORIGINAL/'inputs.json').read_bytes())['cases'];expected={r['name']:r['projection']for r in json.loads((ORIGINAL/'expected.json').read_bytes())}
    selected=[c for c in inputs if not c['null']]
    (out/'plan.txt').write_text(''.join(' '.join(map(str,[c['name'],c['request'],c['presence'],c['phase'],c['metadata']]))+'\n'for c in selected),encoding='utf-8',newline='\n')
    elf=owned.Elf(ROOT/'game_data/SLUS_207.65');(out/'table.bin').write_bytes(elf.read(owned.TABLE,owned.TABLE_BYTES))
    if sha(out/'table.bin')!=plan['authority']['table_sha256']:raise ValueError('Owned table drift')
    env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
    record=dict(status='failed',compiler_sha256=sha(a.compiler),manifest_sha256=sha(HERE/'manifest.json'),original_receipt_sha256=sha(ORIGINAL/'receipt.json'),input_manifest_sha256=sha(ORIGINAL/'input-manifest.json'),original_expected_before_native_implementation=True,game_run=False,device_opened=False,checks=[],negative_controls=[])
    flags=[a.compiler,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-I'+str(HERE)]
    def run(label,command):
        value=subprocess.run(list(map(str,command)),capture_output=True,text=True,env=env,timeout=90);(out/(label+'.txt')).write_text(value.stdout+value.stderr,encoding='utf-8',newline='\n')
        record['checks'].append(dict(label=label,exit=value.returncode,command=list(map(str,command))))
        if value.returncode:raise ValueError(label+' failed')
    def compare(label,source,negative=False):
        binary=out/(label+'.exe');run(label+'-compile',flags+[source,HERE/'fixture_runner.cpp','-o',binary])
        result=out/(label+'.jsonl');run(label,[binary,out/'table.bin',out/'plan.txt',result]);rows=list(map(json.loads,result.read_text().splitlines()))
        if len(rows)!=len(selected) or any(row['name']!=case['name']for row,case in zip(rows,selected)):raise ValueError('Incomplete or reordered actual result')
        differences=[dict(name=row['name'],field=key,expected=expected[row['name']][key],actual=row[key])for row in rows for key in ['stored_i16','rna_i32','volume_u32']if row[key]!=expected[row['name']][key]]
        (out/(label+'-differences.json')).write_text(json.dumps(differences,indent=2)+'\n',encoding='utf-8',newline='\n')
        if bool(differences)!=negative:raise ValueError('Unexpected comparison '+label)
        return len(differences)
    try:
        unit=out/'table-tests.exe';run('unit-compile',flags+[HERE/'attenuation.cpp',HERE/'attenuation_tests.cpp','-o',unit]);run('unit',[unit])
        compare('native',HERE/'attenuation.cpp');body=(HERE/'attenuation.cpp').read_text()
        mutations=[('lose-request-halfword','std::bit_cast<std::int16_t>(static_cast<std::uint16_t>(requested_word))','std::bit_cast<std::int32_t>(requested_word)'),
            ('ignore-ainf-readiness','const bool ready=std::bit_cast<std::int32_t>(metadata.presence)>0 &&\n        (metadata.decoder_phase==2 || metadata.decoder_phase==3);','const bool ready=true;'),
            ('linearize-owned-table','words_[static_cast<std::size_t>(-clamped)]','static_cast<std::uint32_t>((999+clamped)*256/999)')]
        for label,old,new in mutations:
            if body.count(old)!=1:raise ValueError('Mutation anchor missing '+label)
            changed=body.replace(old,new)
            if label=='lose-request-halfword':changed=changed.replace('return {requested,clamped,','return {static_cast<std::int16_t>(requested),clamped,')
            source=out/(label+'.cpp');source.write_text(changed,encoding='utf-8',newline='\n');count=compare(label,source,True);record['negative_controls'].append(dict(name=label,differences=count,detected=True))
        verify();record.update(status='native signed attenuation and raw volume match owned setter/type5 observations',compared_cases=len(selected),original_null_diagnostic_cases_retained=sum(c['null']for c in inputs),physical_decibel_units_claimed=False)
    finally:
        record['outputs_sha256']={p.name:sha(p)for p in out.iterdir()if p.is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=record['status'],cases=record['compared_cases'],receipt_sha256=sha(out/'receipt.json'))))
if __name__=='__main__':main()
