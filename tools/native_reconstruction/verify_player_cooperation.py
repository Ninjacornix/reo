"""Bounded assistance/cooperation/registration original comparison on shipping LLVM."""
import argparse,hashlib,json,os,re,shutil,struct,subprocess,time
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
ROOT=Path(__file__).resolve().parents[2]
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--snapshot',type=Path,required=True);p.add_argument('--output',type=Path,required=True);p.add_argument('--prepare-only',action='store_true')
    p.add_argument('--suite',choices=('cooperation','hit-contact'),default='cooperation')
    p.add_argument('--native-override',type=Path,action='append',default=[]);a=p.parse_args()
    out=a.output.resolve();out.mkdir(parents=True,exist_ok=False);snapshot=a.snapshot.resolve();manifest=json.loads((snapshot/'receipt.json').read_text());assert manifest['status']=='passed'
    compiler=Path(os.environ['LOCALAPPDATA'])/'OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe'
    assert sha(compiler)=='f1377bd9c4e35669930d0fb2ebdc51cac1d1f4ca16638c0ed0d77c113bc195d3'
    for name,digest in manifest['archives_sha256'].items():assert sha(snapshot/'native-build'/name)==digest,name
    shutil.copytree(snapshot/'source',out/'source')
    fpu=ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h'
    target=out/'source'/fpu.relative_to(ROOT);target.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(fpu,target)
    if a.prepare_only:shutil.copytree(ROOT/'game/native',out/'source/game/native',dirs_exist_ok=True)
    elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    raw=overlay.read_bytes();entries=[('o2',x) for x in (0x6507f0,0x6506c0,0x666a10,0x666680,0x666b70,0x666af0,0x666640,0x667370,0x64f720,0x64f7b0,0x67ff80)]
    for address,expected in (
        (0x740410,(0x66673c,0x6667f0,0x6667d8,0x666814,0x666748,0x666874,0x6668fc)),
        (0x740790,(0x680134,0x680018,0x68004c,0x680070,0x6800b0,0x6800d4,0x680114))):
        assert struct.unpack_from('<7I',raw,address-0x570000)==expected,hex(address)
    entries += [('main',x) for x in (0x1b0310,0x1b0340,0x1b02d0,0x1b0300)]
    fixture_name='player_cooperation_tests.cpp'
    if a.suite=='hit-contact':
        entries=[('o2',0x6689e0),('o2',0x663350)];fixture_name='hit_contact_response_tests.cpp'
        assert struct.unpack_from('<3f',raw,0x712bb8-0x570000)==(0.,0.,1.)
        assert struct.unpack_from('<I',raw,0x740470-0x570000)[0]==0x40c90fdb
    bodies=[];audits=[];symbols={};inputs=[Path(__file__).resolve(),ROOT/'tools/native_reconstruction'/fixture_name,ROOT/'tools/native_reconstruction/gameplay_collision_oracle/reference.hpp']
    for family,at in entries:
        symbol=f'sub_{at:08X}_0x{at:x}' if family=='main' else f'o2_{at:08X}_0x{at:x}'
        source=ROOT/(f'recomp/config/output/{symbol}.cpp' if family=='main' else f'recomp/config/output_ovl/o2/{symbol}.cpp')
        text=source.read_text();end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',text)[1],16)
        reader=elf_reader(elf.read_bytes()) if family=='main' else lambda addr,n:raw[addr-0x570000:addr-0x570000+n]
        audits.append(compare_source('Player cooperation',source.relative_to(ROOT).as_posix(),at,end,reader));inputs.append(source);symbols[at]=symbol;bodies.append(text[text.index('// Function:'):])
    prefix=inputs[2].read_text().split('void o0_00370760')[0].replace('#pragma once','',1)
    prefix+='\n#define WRITE16(at,v) ref_write(rdram,at,std::uint16_t(v))\n#define SRA32(v,n) (std::int32_t(v)>>(n))\n#define SRL32(v,n) (std::uint32_t(v)>>(n))\n#define FPU_C_EQ_S(a,b) ((a)==(b))\n'
    body='\n'.join(bodies)
    calls={int(at,16):name for name,at in re.findall(r'(\w+_0x([0-9a-f]+))\(rdram',body)}
    prefix+='\n'.join(f'void {name}(uint8_t*,R5900Context*,PS2Runtime*);' for name in symbols.values())
    for at,name in calls.items():
        if at not in symbols:prefix+=f'\nvoid {name}(uint8_t*r,R5900Context*c,PS2Runtime*t){{c->pc=0x{at:x};t->lookupFunction(0x{at:x})(r,c,t);}}'
    fixture=inputs[1].read_text();mapping='\n'.join(f'case 0x{at:x}:return {name};' for at,name in symbols.items())
    generated=out/'original_native.cpp';generated.write_text(prefix+'\n'+body+'\n'+fixture.replace('/* ORIGINAL_LOOKUP */',mapping))
    overrides=[]
    for original in a.native_override:
        original=original.resolve();assert original.is_relative_to(ROOT/'game/native') and original.suffix=='.cpp'
        target=out/'source'/original.relative_to(ROOT);target.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(original,target)
        inputs.append(original);overrides.append(str(target))
        header=original.with_suffix('.hpp')
        if header.is_file():
            header_target=out/'source'/header.relative_to(ROOT);shutil.copy2(header,header_target);inputs.append(header)
    inputs.append(fpu);before={x.relative_to(ROOT).as_posix():sha(x) for x in inputs}
    exe=out/('cooperation.o' if a.prepare_only else 'cooperation.exe')
    cmd=[str(compiler),'-std=c++20','-O2','-fno-fast-math','-ffp-contract=off','-I'+str(out/'source'),str(generated)]
    if a.prepare_only:cmd+=['-c']
    else:cmd+=overrides+['-Wl,--start-group',*[str(snapshot/'native-build'/n) for n in manifest['archives_sha256']],'-Wl,--end-group','-lwinmm','-lxinput','-luser32','-lgdi32','-ldxgi','-luuid']
    cmd+=['-o',str(exe)]
    receipt=dict(status='failed',snapshot=str(snapshot),compiler_sha256=sha(compiler),input_sha256=before,original_word_audits=audits,commands=[],game_run=False,stage4_complete=False,
        declared_boundaries=['191D10 horizontal distance arithmetic','65F410 uses independently qualified direction_turn heading','67E230 qualified actor message boundary, comparison cases suppress snapshot side effects','37C060 event record boundary','5D4CF0/58C7B0 qualified animation select/activate','5F4FD0 qualified cold inventory close','107C68 bounded memset'])
    receipt.update(suite=a.suite,native_overrides=[str(x) for x in a.native_override],archive_only=not a.native_override)
    if a.suite=='hit-contact':receipt['declared_boundaries']=['191D80 reciprocal square-root vector normalization port','191BC0 vector rotation using independently qualified sin_cos','191DF0 ordered dot product port']
    env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+env.get('PATH','')
    archive=Path(os.environ['LOCALAPPDATA'])/'OutbreakRecomp/launcher/imports/file1/25e64b631bbaa0cac9a4822cb66174ff14c3531851d1e502c0a06704379bf446/data/NETBIO00.DAT'
    for label,command in [('compile',cmd)]+([] if a.prepare_only else [('run',[str(exe),str(archive)])]):
        start=time.monotonic();run=subprocess.run(command,cwd=ROOT,env=env,capture_output=True,text=True,timeout=180)
        (out/(label+'.stdout.txt')).write_text(run.stdout);(out/(label+'.stderr.txt')).write_text(run.stderr)
        receipt['commands'].append(dict(label=label,command=command,returncode=run.returncode,seconds=time.monotonic()-start));print(label,run.returncode,run.stdout[-1000:],run.stderr[-3000:],flush=True)
        if run.returncode:break
    receipt['source_drift']=[name for name,digest in before.items() if sha(ROOT/name)!=digest]
    receipt['archive_drift']=[name for name,digest in manifest['archives_sha256'].items() if sha(snapshot/'native-build'/name)!=digest]
    if not run.returncode and not receipt['source_drift'] and not receipt['archive_drift']:
        receipt['status']='prepared' if a.prepare_only else 'passed_diagnostic' if a.native_override else 'passed'
        if not a.prepare_only:receipt['observed']=json.loads(run.stdout)
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n');return receipt['status']=='failed'
if __name__=='__main__':raise SystemExit(main())
