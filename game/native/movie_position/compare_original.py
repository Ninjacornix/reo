#!/usr/bin/env python3
"""Compare a frozen typed publication core with independently executed EE words."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess

ROOT=Path(__file__).resolve().parents[3]
HERE=Path(__file__).resolve().parent
CORE='4ba067d7c2a7e0e84c2372470d40d815b3dfb57d0dc23dd5fb15bb7ec006fb3f'
HEADER='fa00728b7c6ff9fe294327f0ba667e4d931b04b7984fbeafb76a16daf1256062'
FIXTURE='232d07ee2991cb07f25bc65247db597aa2a85f6080ef8d1bff47c45b5fa94822'


def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def signed(value):return (value & 0xffffffff)-(0x100000000 if value & 0x80000000 else 0)


def compare(compiler,fixture,output):
    if sha(HERE/'movie_position.cpp')!=CORE or sha(HERE/'movie_position.hpp')!=HEADER or sha(fixture)!=FIXTURE:
        raise ValueError('Frozen core/header/original fixture identity changed')
    original=json.loads(fixture.read_text())
    if original['elf_sha256']!='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46':
        raise ValueError('Wrong original game image')
    compiler=shutil.which(compiler)
    if not compiler:raise ValueError('Existing C++20 compiler required')
    output=output.resolve()
    if not output.is_relative_to(ROOT/'build-native-sjuni') or output==ROOT/'build-native-sjuni':
        raise ValueError('Use private output below build-native-sjuni')
    output.mkdir(parents=True,exist_ok=True)
    source=['#include "movie_position.hpp"','#include <cstdint>','#include <iostream>',
            'using namespace reo::native::movie_position;','int main(){']
    for case in original['cases']:
        v=case['inputs']
        values=[v['header_numerator'],v['header_scale'],v['origin'],v['bias'],
            bool(v['clock_flag']),v['side_counter'],v['side_base'],signed(case['source_table_word_u32'])]
        args=','.join(str(int(n)) for n in values)
        source += ['{const auto r=publish(Input{'+args+'},Latest{'+str(v['latest_numerator'])+','+str(v['latest_scale'])+'});',
            'std::cout<<r.descriptor.position<<" "<<r.descriptor.denominator<<" "<<r.descriptor.source_position<<" "<<r.descriptor.offset_position<<" "<<r.latest.numerator<<" "<<r.latest.denominator<<" "<<r.final_value<<"\\n";}']
    source+=['}']
    driver=output/'compare.cpp';driver.write_text('\n'.join(source)+'\n',encoding='utf-8')
    exe=output/'compare.exe'
    command=[compiler,'-std=c++20','-O1','-Wall','-Wextra','-Wpedantic','-Werror',
        '-I'+str(HERE),str(HERE/'movie_position.cpp'),str(driver),'-o',str(exe)]
    subprocess.run(command,check=True,capture_output=True,text=True)
    env=dict(os.environ);env['PATH']=str(Path(compiler).parent)+os.pathsep+env.get('PATH','')
    observed=subprocess.check_output([str(exe)],env=env,text=True)
    rows=[list(map(int,line.split())) for line in observed.splitlines()]
    if len(rows)!=len(original['cases']):raise ValueError('Missing native output rows')
    results=[]
    for case,row in zip(original['cases'],rows):
        after=case['expected']['after'];d=after['descriptor_words_u32'];cc=after['cc0_words_u32']
        expected=[signed(d[n]) for n in (3,4,8,9)]+[signed(cc[n]) for n in (144,145)]+[signed(case['expected']['raw_v0_lower64'])]
        results.append(dict(case=case['name'],equal=row==expected,expected=expected,actual=row))
    report=dict(schema=1,core_sha256=CORE,header_sha256=HEADER,fixture_sha256=FIXTURE,
        compiler=compiler,command=command,executable_sha256=sha(exe),
        cases=len(results),compared_fields=len(results)*7,results=results,
        limitations=['Typed numerical fields and observed final v0 bits only; no guest ABI, alias, intermediate store/scheduling or frame reconstruction.',
            'Standalone helper observations qualify the independent oracle; they are not additional native API cases.',
            'No game, source lifetime, playback clock migration, speaker/display output or speedup is demonstrated.'])
    (output/'receipt.json').write_text(json.dumps(report,indent=2)+'\n')
    if any(not r['equal'] for r in results):raise ValueError('Native publication differs; inspect receipt')
    print(f"PASS {len(results)} original publisher cases / {len(results)*7} fields")


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--cxx',required=True)
    parser.add_argument('--fixture',type=Path,default=ROOT/'build-native-sjuni/movie-position-oracle-v1/original-fixture.json')
    parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args();compare(args.cxx,args.fixture,args.output)
