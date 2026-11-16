"""Bounded real RTP point/nearest queries against complete original bodies."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
ROOT=Path(__file__).resolve().parents[2]
CC=Path(os.environ['LOCALAPPDATA'])/'OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe'
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);p.add_argument('--snapshot',type=Path);a=p.parse_args();out=a.output.resolve()
    assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir(parents=True)
    elf=ROOT/'game_data/SLUS_207.65';o0=ROOT/'build-function-index/owned-overlays/o0.bin';o2=ROOT/'build-function-index/owned-overlays/o2.bin'
    assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    assert sha(o0)=='bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2'
    assert sha(o2)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    main_read=elf_reader(elf.read_bytes());b0=o0.read_bytes();b2=o2.read_bytes();sources=[];bodies=[];audits=[];dispatch=[]
    for at in (0x5fdf10,0x5fe160,0x3700c0,0x370100,0x191d10,0x192190,0x1921a0,0x18f340,0x18f470,0x1aec80):
        family='o2' if at>=0x570000 else 'o0' if at>=0x370000 else 'sub'
        directory=f'recomp/config/output_ovl/{family}' if family!='sub' else 'recomp/config/output'
        source=ROOT/directory/f'{family}_{at:08X}_0x{at:x}.cpp';body=source.read_text();end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',body)[1],16)
        read=(lambda address,size:b2[address-0x570000:address-0x570000+size]) if family=='o2' else (lambda address,size:b0[address-0x370000:address-0x370000+size]) if family=='o0' else main_read
        audits.append(compare_source('complete RTP query and math/random helper',source.relative_to(ROOT).as_posix(),at,end,read));sources.append(source);bodies.append(body)
        dispatch.append(f'case 0x{at:x}:return {source.stem}(memory,context,runtime);')
    reference=ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp'
    header=reference.read_text().replace('Register r[32];','std::uint64_t lo{},hi{};Register r[32];')
    header+='\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n'
    (out/'reference.hpp').write_text(header)
    names={x.stem for x in sources};calls=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram','\n'.join(bodies)))
    declarations=''.join('void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n' for n in sorted(names))
    declarations+=''.join('inline void '+n+'(std::uint8_t*m,R5900Context*c,PS2Runtime*r){original_transform_port(m,c,r);}\n' for n in sorted(calls-names))
    (out/'functions.h').write_text('#pragma once\n'+declarations);(out/'original_dispatch.inc').write_text('\n'.join(dispatch));(out/'original.cpp').write_text('\n'.join(bodies))
    for name in ('ps2_runtime.h','ps2_runtime_macros.h'):(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
    for name in ('ps2_recompiled_functions.h','o0_functions.h','o2_functions.h'):(out/name).write_text('#pragma once\n#include "functions.h"\n')
    for name in ('ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h'):(out/name).write_text('#pragma once\n')
    native=[ROOT/'game/native/gameplay_scenario/room_return_points.cpp',ROOT/'game/native/transform_math/transform_math.cpp',ROOT/'game/native/gameplay_session/session.cpp'];include=ROOT
    receipt=dict(status='failed',source_audits=audits,game_run=False,archive_only=bool(a.snapshot))
    if a.snapshot:
        snapshot=a.snapshot.resolve();capture=json.loads((snapshot/'receipt.json').read_text());assert capture['status']=='passed'
        include=snapshot/'source';native=[snapshot/'native-build'/x for x in ('gameplay_scenario/libreo_native_gameplay_scenario.a','transform_math/libreo_native_transform_math.a','gameplay_session/libreo_native_gameplay_session.a')]
        for x in native:assert sha(x)==capture['archives_sha256'][x.relative_to(snapshot/'native-build').as_posix()]
        receipt['snapshot']=str(snapshot.relative_to(ROOT));receipt['snapshot_sha256']=sha(snapshot/'receipt.json')
    asset_dir=ROOT/'build-native-sjuni/room-return-points-source-audit-v1'
    asset_audit=json.loads((asset_dir/'receipt.json').read_text());assert asset_audit['status']=='passed'
    assets=[]
    for row in asset_audit['assets']:
        if row.get('missing'):continue
        asset=asset_dir/f"r{row['scenario']:02d}.rtp";assert sha(asset)==row['sha256'];assets.append(asset)
    fixture=ROOT/'tools/native_reconstruction/room_return_points_original.cpp';inputs=[*native,*assets,asset_dir/'receipt.json',elf,o0,o2,fixture,reference,Path(__file__),include/'game/native/gameplay_scenario/room_return_points.hpp'];before={str(x):sha(x) for x in inputs}
    command=[str(CC),'-std=c++20','-O1','-msse4.1','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(include),str(fixture),str(out/'original.cpp'),*[str(x) for x in native],'-o',str(out/'checks.exe')]
    env=dict(os.environ,PATH=str(CC.parent)+os.pathsep+os.environ.get('PATH',''))
    try:
        done=subprocess.run(command,cwd=ROOT,env=env,capture_output=True,text=True,timeout=180);(out/'compile.stdout').write_text(done.stdout);(out/'compile.stderr').write_text(done.stderr);assert done.returncode==0,done.stderr[-3000:]
        ran=subprocess.run([str(out/'checks.exe'),str(elf),str(o0),str(ROOT/'build-native-sjuni/room-return-points-source-audit-v1')],cwd=ROOT,env=env,capture_output=True,text=True,timeout=120)
        (out/'stdout.txt').write_text(ran.stdout);(out/'stderr.txt').write_text(ran.stderr);assert ran.returncode==0,ran.stderr
        receipt.update(status='passed',observed=json.loads(ran.stdout),inputs_sha256=before,executable_sha256=sha(out/'checks.exe'))
        assert all(sha(Path(x))==h for x,h in before.items())
    finally:(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print(json.dumps(dict(status=receipt['status'],observed=receipt.get('observed'))))
if __name__=='__main__':main()
