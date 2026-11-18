"""Bounded room membership comparison against both owned overlay bodies."""
import argparse,hashlib,json,os,re,shutil,subprocess,time
from pathlib import Path
from audit_retail_effect_descriptors import compare_source
ROOT=Path(__file__).resolve().parents[2]
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def main():
    parser=argparse.ArgumentParser();parser.add_argument('--output',type=Path,required=True);parser.add_argument('--snapshot',type=Path)
    args=parser.parse_args();out=args.output.resolve();out.mkdir(parents=True,exist_ok=False)
    compiler=Path(os.environ['LOCALAPPDATA'])/'OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe'
    assert sha(compiler)=='f1377bd9c4e35669930d0fb2ebdc51cac1d1f4ca16638c0ed0d77c113bc195d3'
    snapshot=args.snapshot.resolve() if args.snapshot else None
    manifest=json.loads((snapshot/'receipt.json').read_text()) if snapshot else None
    if manifest:assert manifest['status']=='passed'
    header='game/native/gameplay_session/room_membership.hpp';cpp='game/native/gameplay_session/room_membership.cpp'
    ref=ROOT/'tools/native_reconstruction/gameplay_collision_oracle/reference.hpp'
    fpu='third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h'
    fixture=ROOT/'tools/native_reconstruction/room_membership_original_tests.cpp'
    inputs=[Path(__file__).resolve(),ref,fixture,ROOT/fpu];native_hashes={};objects=[]
    for name in (header,) if snapshot else (header,cpp):
        path=(snapshot/'source'/name) if snapshot else ROOT/name
        if manifest:assert sha(path)==manifest['source_sha256'][name]
        destination=out/'source'/name;destination.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(path,destination)
        native_hashes[name]=sha(path)
        if not snapshot:inputs.append(path)
    destination=out/'source'/fpu;destination.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(ROOT/fpu,destination)
    if snapshot:
        archive_name='gameplay_session/libreo_native_gameplay_session.a';archive=snapshot/'native-build'/archive_name
        assert sha(archive)==manifest['archives_sha256'][archive_name];objects=[str(archive)]
    else:objects=[str(out/'source'/cpp)]
    bodies=[];symbols={};audits=[]
    profiles=[('o9','604126d6edca1b1333948d79d1d2c8d2f2e22f4a233efbdfb769c106dafe7343',(0x811970,0x811b30,0x811780,0x8118f0,0x811c50,0x811ca0,0x811d40)),
              ('o8','f42da66b07a00fb221c5954b0e02b06a46b5694afd5596e866d35feec1fc92ab',(0x811140,0x811300,0x810f50,0x8110c0,0x8114b0,0x811550,0x8115f0))]
    for family,digest,entries in profiles:
        overlay=ROOT/f'build-function-index/owned-overlays/{family}.bin';assert sha(overlay)==digest;raw=overlay.read_bytes();inputs.append(overlay)
        for at in entries:
            symbol=f'{family}_{at:08X}_0x{at:x}';path=ROOT/f'recomp/config/output_ovl/{family}/{symbol}.cpp';source=path.read_text()
            end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',source)[1],16)
            audits.append(compare_source('Room membership',path.relative_to(ROOT).as_posix(),at,end,lambda address,count:raw[address-0x810000:address-0x810000+count]))
            inputs.append(path);assert at not in symbols;symbols[at]=symbol;bodies.append(source[source.index('// Function:'):])
    prefix=ref.read_text().split('void o0_00370760')[0].replace('#pragma once','',1)
    prefix+='\n#define SRA32(v,n) (std::int32_t(v)>>(n))\n#define SRL32(v,n) (std::uint32_t(v)>>(n))\n#define WRITE16(at,v) ref_write(rdram,at,std::uint16_t(v))\n'
    body='\n'.join(bodies);calls={int(at,16):name for name,at in re.findall(r'(\w+_0x([0-9a-f]+))\(rdram',body)}
    prefix+='\n'.join(f'void {name}(uint8_t*,R5900Context*,PS2Runtime*);' for name in symbols.values())
    for at,name in calls.items():
        if at not in symbols:prefix+=f'\nvoid {name}(uint8_t*r,R5900Context*c,PS2Runtime*t){{c->pc=0x{at:x};t->lookupFunction(c->pc)(r,c,t);}}'
    mapping='\n'.join(f'case 0x{at:x}:return {name};' for at,name in symbols.items())
    generated=out/'original_native.cpp';generated.write_text(prefix+'\n'+body+'\n'+fixture.read_text().replace('/* ORIGINAL_LOOKUP */',mapping))
    before={p.relative_to(ROOT).as_posix():sha(p) for p in inputs}
    exe=out/'membership.exe';command=[str(compiler),'-std=c++20','-O2','-fno-fast-math','-ffp-contract=off','-I'+str(out/'source'),str(generated),*objects,'-o',str(exe)]
    env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+env.get('PATH','')
    receipt=dict(status='failed',compiler_sha256=sha(compiler),snapshot=str(snapshot) if snapshot else None,native_source_sha256=native_hashes,input_sha256=before,original_word_audits=audits,commands=[],archive_only=bool(snapshot),declared_boundaries=['107AB0 byte copy','810960/8129C0 capture typed snapshot publication; transport scheduler not executed','Explicit initialized tables and frame workspace copy; overlay lifecycle remains separate'],game_run=False,stage4_complete=False)
    for label,cmd in [('compile',command),('run',[str(exe)])]:
        start=time.monotonic();result=subprocess.run(cmd,cwd=ROOT,env=env,capture_output=True,text=True,timeout=120)
        (out/f'{label}.stdout.txt').write_text(result.stdout);(out/f'{label}.stderr.txt').write_text(result.stderr)
        receipt['commands'].append(dict(label=label,command=cmd,returncode=result.returncode,seconds=time.monotonic()-start));print(label,result.returncode,result.stdout[-1000:],result.stderr[-2000:],flush=True)
        if result.returncode:break
    receipt['source_drift']=[name for name,digest in before.items() if sha(ROOT/name)!=digest]
    if not result.returncode and not receipt['source_drift']:
        receipt['status']='passed' if snapshot else 'passed_diagnostic';receipt['observed']=json.loads(result.stdout)
    if snapshot:assert sha(archive)==manifest['archives_sha256'][archive_name]
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n');return receipt['status']=='failed'
if __name__=='__main__':raise SystemExit(main())
