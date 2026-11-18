"""Compare CPU fog factors with one owned VU program and controlled captures.

This replays a captured program in the isolated project VU interpreter. It
does not execute the game, test PS2 hardware, or prove whole-frame fog output.
"""
import argparse,hashlib,json,math,os,re,shutil,struct,subprocess,sys,time
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source,elf_reader
CC=Path('C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe')
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    parser=argparse.ArgumentParser();parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--build-receipt',type=Path);args=parser.parse_args();out=args.output.resolve()
    assert not out.exists() and out.is_relative_to((ROOT/'build-native-sjuni').resolve());out.mkdir()
    elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    read=elf_reader(elf.read_bytes());capture=ROOT/'build-ninja/issue26-verify/hellfire-vu-capture-mixed-01/vu1-run-0308'
    original=[Path(str(capture)+'.'+ext+'.bin') for ext in ('code','data','state','meta')]
    code=original[0].read_bytes();assert len(code)==16384 and struct.unpack('<I',read(0x1fe1dc,4))[0]==0x4a000000
    assert code[:2048]==read(0x1fe1e0,2048) and struct.unpack('<I',read(0x1fe9e4,4))[0]==0x4ae60100
    assert code[2048:3888]==read(0x1fe9e8,1840)
    state_bytes=original[2].read_bytes();data_bytes=original[1].read_bytes()
    assert len(state_bytes)==632 and len(data_bytes)==16384 and struct.unpack_from('<I',state_bytes,604)[0]==0x128
    parameters=struct.unpack_from('<2f',state_bytes,0xb0)
    assert parameters==struct.unpack_from('<2f',data_bytes,0x20) and parameters[0]==2000.0
    assert parameters[1]==struct.unpack('<f',struct.pack('<f',1/1500))[0]
    native=ROOT/'game/native/gameplay_presentation/raster.cpp';header=native.with_suffix('.hpp');fixture=ROOT/'tools/native_reconstruction/presentation/fog_factor_compare.cpp'
    parser_script=ROOT/'tools/ps2_debug/m2_vu_gif_geometry.py';runtime=ROOT/'third_party/PS2Recomp/ps2xRuntime/src/lib'
    vu_sources=[ROOT/'tools/vu1_check/main.cpp',*(runtime/name for name in ('ps2_vu1.cpp','vu_specialized_route.cpp','vu_native_geometry_route.cpp','vu_cost_attribution.cpp','vu_whole_program.cpp'))]
    audited=[];audit_sources=[]
    overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';overlay_bytes=overlay.read_bytes()
    for address,bank in ((0x198c80,'sub'),(0x19bea0,'sub'),(0x6b1660,'o2')):
        directory=ROOT/('recomp/config/output' if bank=='sub' else 'recomp/config/output_ovl/o2')
        source=next(directory.glob(f'{bank}_{address:08X}_*'));body=source.read_text()
        begin,end=(int(v,16) for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',body).groups())
        source_read=read if bank=='sub' else lambda at,n:overlay_bytes[at-0x570000:at-0x570000+n]
        audited.append(compare_source('fog publication and program binding',source.relative_to(ROOT).as_posix(),begin,end,source_read));audit_sources.append(source)
    inputs={*original,native,header,fixture,parser_script,*vu_sources,*audit_sources}
    for directory in (ROOT/'tools/vu1_check/stubs',ROOT/'third_party/PS2Recomp/ps2xRuntime/include',runtime):
        inputs.update(x for x in directory.rglob('*') if x.is_file() and x.suffix in ('.h','.hpp','.inc'))
    pending=[native,fixture,header]
    while pending:
        current=pending.pop()
        for include in re.findall(r'^\s*#include "([^"]+)"',current.read_text(),re.M):
            candidate=(current.parent/include).resolve()
            if not candidate.is_file():candidate=(ROOT/include).resolve()
            if candidate.is_file() and candidate.is_relative_to(ROOT) and candidate not in inputs:
                inputs.add(candidate);pending.append(candidate)
    inputs=sorted(inputs);identities={str(p.relative_to(ROOT)):sha(p) for p in inputs}
    archive=None;build_receipt=None
    if args.build_receipt:
        build_receipt=json.loads(args.build_receipt.read_text())
        assert build_receipt['status']=='passed' and not build_receipt['source_drift'] and not build_receipt['archive_drift']
        assert sha(CC)==build_receipt['compiler_sha256']
        def verify_sources():
            for name,expected in build_receipt['sources_sha256'].items():
                if sha(ROOT/name)!=expected:raise RuntimeError('source identity mismatch: '+name)
        verify_sources();relative='gameplay_application/libreo_native_gameplay_presentation.a'
        archive=ROOT/'build-native-sjuni/gameplay-native-llvm-v1'/relative
        assert sha(archive)==build_receipt['archives_sha256'][relative]
    env=dict(os.environ,PATH=str(CC.parent)+os.pathsep+os.environ.get('PATH',''));vu=out/'vu_check.exe';native_exe=out/'native_check.exe'
    common=[str(CC),'-std=c++20','-O2','-msse4.1','-ffp-contract=off']
    commands=[('compile_vu',common+['-DREO_VU_ISOLATED_RUNTIME_STUBS=1','-DNOMINMAX','-I'+str(ROOT/'tools/vu1_check/stubs'),
               '-I'+str(ROOT/'third_party/PS2Recomp/ps2xRuntime/include'),'-I'+str(runtime),*(str(p) for p in vu_sources),'-o',str(vu)]),
              ('compile_native',common+['-Wall','-Wextra','-Werror','-I'+str(ROOT),str(fixture),str(archive or native),'-o',str(native_exe)])]
    receipt={'status':'failed','compiler_sha256':sha(CC),'elf_sha256':sha(elf),'inputs':identities,'driver_sha256':sha(Path(__file__)),
             'program_match':'owned descriptor24 MPG chunks at 1FE1E0 (2048 bytes) and 1FE9E8 (1840 bytes)',
             'overlay_sha256':sha(overlay),'original_word_audits':audited,
             'limits':['One captured VU image and continuation; controlled finite fog ranges and ADC-eligible vertices.','The project VU interpreter is an oracle here, not a hardware or complete-frame proof.'],
             'checks':[],'game_run':False}
    if archive:receipt.update(build_receipt=str(args.build_receipt.resolve()),build_receipt_sha256=sha(args.build_receipt),archive_sha256=sha(archive))
    def run(name,command):
        start=time.monotonic();result=subprocess.run(command,capture_output=True,env=env,timeout=120)
        (out/(name+'.out')).write_bytes(result.stdout);(out/(name+'.err')).write_bytes(result.stderr)
        receipt['checks'].append({'name':name,'seconds':time.monotonic()-start,'exit':result.returncode})
        if result.returncode:raise RuntimeError(name+': '+result.stderr.decode(errors='replace')[-3000:])
    try:
        for name,command in commands:run(name,command)
        rows=[];reference_geometry={}
        for k,far in enumerate((-500.,0.,500.,1000.,2000.)):
            prefix=out/f'case{k}'
            for ext,source in zip(('code','data','state','meta'),original):shutil.copyfile(source,str(prefix)+'.'+ext+'.bin')
            for ext in ('state','data'):
                path=Path(str(prefix)+'.'+ext+'.bin');blob=bytearray(path.read_bytes())
                for at in ((0xb0,) if ext=='state' else (0x20,)):struct.pack_into('<2f',blob,at,far,1/1500)
                path.write_bytes(blob)
            exported=out/f'packet{k}';run(f'replay{k}',[str(vu),str(prefix),'--dump-gif',str(exported)])
            report=exported/'geometry.json';run(f'parse{k}',[sys.executable,str(parser_script),str(exported),'--sample-limit','256','--report',str(report)])
            parsed=json.loads(report.read_text());assert parsed['packet_count']==17
            assert parsed['counts']['adc_eligible_nondegenerate_triangles']==18
            vertices={}
            for triangle in parsed['triangle_samples']:
                if triangle['adc_suppressed']:continue
                for vertex in triangle['vertices']:
                    vertices[(vertex['source']['packet_index'],vertex['source']['byte_offset'])]=vertex
            count=0
            for offset,vertex in sorted(vertices.items()):
                q=vertex['q']
                if not isinstance(q,(float,int)) or not math.isfinite(q) or q<=0 or abs(q)<1e-30:continue
                signature=(q,vertex['x_raw'],vertex['y_raw'],vertex['z'],vertex['adc'])
                if offset in reference_geometry:assert signature==reference_geometry[offset]
                else:reference_geometry[offset]=signature
                rows.append(f'{1/q:.9g} {far-1500:.9g} {far:.9g} {vertex["fog"]}\n');count+=1
            assert count==40
        cases=out/'factor_cases.txt';cases.write_text(''.join(rows));run('compare_native',[str(native_exe),str(cases)])
        observed=json.loads((out/'compare_native.out').read_text());assert observed['checks']==200
        assert identities=={str(p.relative_to(ROOT)):sha(p) for p in inputs}
        if archive:verify_sources();assert sha(archive)==receipt['archive_sha256']
        receipt.update(status='passed',observed=observed)
    finally:(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print(json.dumps(receipt['observed']))
if __name__=='__main__':main()
