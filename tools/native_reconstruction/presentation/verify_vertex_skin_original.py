"""Compare owned actor skin weights to the actual original packing slice.

The original 1A3D00 and 1A35F0 getters run on each owned raw object. 1A45A0
is entered at its skin loop and stops after its index/weight stores. This is
not a full actor frame or hardware skinning comparison.
"""
import argparse,hashlib,json,os,re,struct,subprocess,sys,time
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source,elf_reader
CC=Path('C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe')
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    parser=argparse.ArgumentParser();parser.add_argument('--output',type=Path,required=True)
    group=parser.add_mutually_exclusive_group();group.add_argument('--build-receipt',type=Path);group.add_argument('--cohort-snapshot',type=Path)
    args=parser.parse_args();out=args.output.resolve();assert not out.exists() and out.is_relative_to((ROOT/'build-native-sjuni').resolve());out.mkdir()
    elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(elf.read_bytes())
    sources=[];audits=[]
    for address in (0x1a45a0,0x1a3d00,0x1a35f0):
        source=next((ROOT/'recomp/config/output').glob(f'sub_{address:08X}_*'));body=source.read_text()
        begin,end=(int(v,16) for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',body).groups())
        audits.append(compare_source('skin packing or source getter',source.relative_to(ROOT).as_posix(),begin,end,read));sources.append(source)
    reference=(ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp').read_text()
    extra='\n#include "ps2_fpu_convert.h"\n#define FPU_CVT_W_S(v) Ps2FpuConvertWord(v)\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\nstruct SkinStop{};\n'
    (out/'reference.hpp').write_text(reference+extra)
    packing=sources[0].read_text();start=packing.index('ctx->pc = 0x1a4c28u;')
    marker='WRITE32(ADD32(GPR_U32(ctx, 13), 0), GPR_U32(ctx, 2));';pos=packing.index(marker,start)+len(marker)
    packing=packing[:pos]+' throw SkinStop{};'+packing[pos:]
    body=packing+'\n'+'\n'.join(source.read_text() for source in sources[1:]);names={source.stem for source in sources}
    calls=set(re.findall(r'\b(sub_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join('void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n' for n in sorted(names))
    decl+=''.join('inline void '+n+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n' for n in sorted(calls-names))
    (out/'functions.h').write_text('#pragma once\n'+decl);(out/'original.cpp').write_text(body)
    for name in ('ps2_runtime.h','ps2_runtime_macros.h'):(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
    (out/'ps2_recompiled_functions.h').write_text('#pragma once\n#include "functions.h"\n')
    for name in ('ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h'):(out/name).write_text('#pragma once\n')
    snapshot=args.cohort_snapshot.resolve() if args.cohort_snapshot else None
    source_root=snapshot/'source' if snapshot else ROOT
    fixture=ROOT/'tools/native_reconstruction/presentation/vertex_skin_original.cpp';native=source_root/'game/native/gameplay_presentation/model_mesh.cpp';header=native.with_suffix('.hpp')
    model=ROOT/'build-native-sjuni/stage4-orchestration/presentation-mesh-explore/P00_00.nbd';exe=out/'checks.exe'
    inputs=[fixture,native,header,model,ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp',
            ROOT/'tools/native_reconstruction/audit_retail_effect_descriptors.py',ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h',*sources]
    identities={str(p.relative_to(ROOT)):sha(p) for p in inputs}
    archive=None
    if args.build_receipt:
        prior=json.loads(args.build_receipt.read_text());assert prior['status']=='passed' and not prior['source_drift'] and not prior['archive_drift'] and sha(CC)==prior['compiler_sha256']
        def verify_sources():
            for name,expected in prior['sources_sha256'].items():
                if sha(ROOT/name)!=expected:raise RuntimeError('source identity mismatch: '+name)
        verify_sources();relative='gameplay_application/libreo_native_gameplay_presentation.a';archive=ROOT/'build-native-sjuni/gameplay-native-llvm-v1'/relative
        assert sha(archive)==prior['archives_sha256'][relative]
    elif snapshot:
        snapshot_receipt=snapshot/'receipt.json';prior=json.loads(snapshot_receipt.read_text());assert prior['status']=='passed'
        cohort_receipt=ROOT/prior['cohort'];assert sha(cohort_receipt)==prior['cohort_sha256']
        cohort=json.loads(cohort_receipt.read_text());assert cohort['status']=='passed' and not cohort['source_drift'] and not cohort['archive_drift'] and sha(CC)==cohort['compiler_sha256']
        def verify_sources():
            for name,expected in prior['source_sha256'].items():
                if sha(source_root/name)!=expected:raise RuntimeError('snapshot source identity mismatch: '+name)
            for name,expected in cohort['sources_sha256'].items():
                if prior['source_sha256'].get(name)!=expected:raise RuntimeError('cohort source identity mismatch: '+name)
        verify_sources();relative='gameplay_application/libreo_native_gameplay_presentation.a';archive=snapshot/'native-build'/relative
        assert sha(archive)==prior['archives_sha256'][relative]==cohort['archives_sha256'][relative]
    env=dict(os.environ,PATH=str(CC.parent)+os.pathsep+os.environ.get('PATH',''))
    flags=[str(CC),'-std=c++20','-O2','-msse4.1','-ffp-contract=off','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-Wno-unused-variable','-I'+str(source_root),'-I'+str(ROOT),'-I'+str(out),'-I'+str(ROOT/'third_party/PS2Recomp/ps2xRuntime/include')]
    # Keep the real actor bundle and alter only the indicated weight floats in
    # controlled copies. The original getter walks each modified raw object.
    raw=model.read_bytes()
    def word(at):return struct.unpack_from('<I',raw,at)[0]
    def children(at):
        end=at+word(at+8);at+=12
        while at<end:
            kind,count,size=struct.unpack_from('<III',raw,at);assert size>=12 and at+size<=end
            yield at,kind,count,size;at+=size
        assert at==end
    top=list(children(word(20)));objects=next(x for x in top if x[1]==2);offsets={}
    for obj in children(objects[0]):
        section=next(x for x in children(obj[0]) if x[1]==0xc0000);at=section[0]+12
        for _ in range(section[2]):
            count=word(at);at+=4
            if count in (2,3) and count not in offsets:offsets[count]=[at+8*i+4 for i in range(count)]
            at+=8*count
    assert set(offsets)=={2,3}
    control_values=[(0.,100.),(100.,0.),(.1,99.9),(99.9,.1),(0.,0.,100.),(0.,50.,50.)]
    controls=[]
    for i,values in enumerate(control_values):
        altered=bytearray(raw)
        for offset,value in zip(offsets[len(values)],values):struct.pack_into('<f',altered,offset,value)
        path=out/f'controlled_{i}.nbd';path.write_bytes(altered);controls.append(path)
    commands=[('compile',flags+[str(out/'original.cpp'),str(fixture),str(archive or native),'-o',str(exe)]),('run_owned',[str(exe),str(model)])]
    commands += [(f'run_control_{i}',[str(exe),str(path)]) for i,path in enumerate(controls)]
    receipt={'status':'failed','compiler_sha256':sha(CC),'elf_sha256':sha(elf),'inputs':identities,'driver_sha256':sha(Path(__file__)),
             'original_word_audits':audits,'packing_scope':'1A4AA4 through 1A4C28 store; instrumented stop; complete original getters',
             'controlled_weight_values':control_values,'controlled_asset_sha256':[sha(path) for path in controls],
             'checks':[],'game_run':False}
    if archive:
        prior_path=snapshot_receipt if snapshot else args.build_receipt
        receipt.update(build_receipt=str(prior_path.resolve()),build_receipt_sha256=sha(prior_path),archive_sha256=sha(archive),snapshot=bool(snapshot))
    try:
        for name,command in commands:
            start=time.monotonic();result=subprocess.run(command,capture_output=True,env=env,timeout=120)
            (out/(name+'.out')).write_bytes(result.stdout);(out/(name+'.err')).write_bytes(result.stderr)
            receipt['checks'].append({'name':name,'seconds':time.monotonic()-start,'exit':result.returncode})
            if result.returncode:raise RuntimeError(name+': '+result.stderr.decode(errors='replace')[-4000:])
        assert identities=={str(p.relative_to(ROOT)):sha(p) for p in inputs}
        if archive:verify_sources();assert sha(archive)==receipt['archive_sha256']
        observed={name:json.loads((out/(name+'.out')).read_text()) for name,_ in commands if name.startswith('run_')}
        receipt.update(status='passed',observed=observed)
    finally:(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print(json.dumps(receipt['observed']))
if __name__=='__main__':main()
