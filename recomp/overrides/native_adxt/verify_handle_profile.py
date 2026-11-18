#!/usr/bin/env python3
"""File1 handle admission shape checks, with owned constructor word provenance.

This does not execute the guest constructors or attest runtime RAM ownership.
"""
import argparse,hashlib,json,os,re,subprocess,sys
from pathlib import Path
HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[2]
sys.path.insert(0,str(ROOT/'tools/function_index'))
from index import Elf
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
RANGES={0x1315e0:0x1318c8,0x12c9d8:0x12cb58,0x1300c8:0x130100,0x130108:0x130218,0x138ab8:0x138ba8,0x13e770:0x13eac0,0x132c08:0x132cd8}
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists() or not out.is_relative_to(ROOT/'build-native-sjuni/adxt-binding'):raise ValueError('Fresh owned output required')
    elf=Elf(ROOT/'game_data/SLUS_207.65');ranges=[];sources={}
    for start,end in RANGES.items():
        source=ROOT/f'recomp/config/output/sub_{start:08X}_0x{start:x}.cpp';raw=source.read_bytes();words={int(at,16):int(word,16)for at,word in re.findall(rb'//\s*0x([0-9a-fA-F]+):\s*0x([0-9a-fA-F]+)',raw)}
        for at in range(start,end,4):
            original=int.from_bytes(elf.read(at,4),'little')
            if at in words:
                if original!=words[at]:raise ValueError('Original word disagreement '+hex(at))
            elif original:raise ValueError('Missing original source word '+hex(at))
        sources[source.relative_to(ROOT).as_posix()]=sha(source);ranges.append(dict(start=start,end=end,sha256=hashlib.sha256(elf.read(start,end-start)).hexdigest()))
    authored={p.relative_to(ROOT).as_posix():sha(p)for p in (HERE/'handle_profile.h',HERE/'handle_profile_tests.cpp',Path(__file__),ROOT/'tools/function_index/index.py')}
    out.mkdir(parents=True);env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
    record=dict(schema=1,status='failed',compiler_sha256=sha(a.compiler),elf_sha256=elf.sha256,original_ranges=ranges,original_sources=sources,authored=authored,checks=[],game_run=False,process_attached=False,actual_guest_construction_executed=False,ram='declared synthetic constructor layout; not runtime acquisition')
    def run(label,command,negative=False):
        v=subprocess.run(list(map(str,command)),capture_output=True,text=True,env=env,timeout=45);(out/(label+'.txt')).write_text(v.stdout+v.stderr,encoding='utf-8',newline='\n');record['checks'].append(dict(label=label,exit=v.returncode,negative=negative))
        if (v.returncode==0)==negative:raise ValueError('Unexpected result '+label)
    try:
        flags=[a.compiler,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-I'+str(HERE)]
        exe=out/'handles.exe';run('compile',flags+[HERE/'handle_profile_tests.cpp','-o',exe]);run('native',[exe])
        header=(HERE/'handle_profile.h').read_text();test=(HERE/'handle_profile_tests.cpp').read_text()
        mutations=[('sixteen-file-descriptors','files{0x21a8c0,0x5c,40}','files{0x21a8c0,0x5c,16}'),('skip-dtr-destination','detail::load<std::uint32_t>(ram,h.transfer[channel]+8)!=destination','false'),('accept-nonadjacent-dtr','h.transfer_slot[1]!=h.transfer_slot[0]+1','false')]
        for label,old,new in mutations:
            if header.count(old)!=1:raise ValueError('Mutation anchor '+label)
            folder=out/label;folder.mkdir();(folder/'handle_profile.h').write_text(header.replace(old,new),encoding='utf-8',newline='\n');(folder/'handle_profile_tests.cpp').write_text(test,encoding='utf-8',newline='\n');bad=folder/'handles.exe';run(label+'-compile',flags+[folder/'handle_profile_tests.cpp','-o',bad]);run(label,[bad],True)
        if any(sha(ROOT/n)!=d for n,d in {**sources,**authored}.items()):raise ValueError('Input drift')
        record.update(status='File1 handle shape admission qualified with original word provenance',detected_faults=3,binary_sha256=sha(exe))
    finally:
        record['outputs_sha256']={p.name:sha(p)for p in out.iterdir()if p.suffix=='.txt'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps({'status':record['status'],'receipt_sha256':sha(out/'receipt.json')}))
if __name__=='__main__':main()
