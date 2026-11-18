"""Compare all eight-instance facial cursor/weight/terminal paths with original67C6D0."""
import argparse
import hashlib
import json
import os
import re
import struct
import subprocess
import sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source,elf_reader
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
    image=ROOT/'game_data/SLUS_207.65';assert sha(image)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';bank=overlay.read_bytes();read=lambda at,n:bank[at-0x570000:at-0x570000+n]
    entries={0x67c6d0:'recomp/config/output_ovl/o2/o2_0067C6D0_0x67c6d0.cpp'};proof=[]
    for name in entries.values():
        start,end=[int(value,16)for value in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',(ROOT/name).read_text()).groups()];proof.append(compare_source('complete eight-instance facial curve/terminal/model dispatch body',name,start,end,read))
    claim='recomp/config/output_ovl/o2/o2_0067C590_0x67c590.cpp';start,end=[int(value,16)for value in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',(ROOT/claim).read_text()).groups()];authority=compare_source('static five-relative-channel decoder/cursor initialization authority; claim not executed',claim,start,end,read)
    units=['game/native/animation/facial_curves.cpp','game/native/transform_math/transform_math.cpp'];files=set(units);pending=list(units)
    while pending:
        name=pending.pop()
        for include in re.findall(r'^#include "([^"]+)"',(ROOT/name).read_text(),re.M):
            path=((ROOT/name).parent/include).resolve();assert path.is_file()and path.is_relative_to(ROOT);relative=path.relative_to(ROOT).as_posix()
            if relative not in files:files.add(relative);pending.append(relative)
    fixture='tools/native_reconstruction/animation/facial_curves_tests.cpp';reference='tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp';files|={fixture,reference,claim,Path(__file__).relative_to(ROOT).as_posix(),*entries.values()};before={name:sha(ROOT/name)for name in sorted(files)};out.mkdir()
    record=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(a.compiler),original_owned_bodies=proof,claim_static_authority=authority,game_run=False,stage4_complete=False,limits=['Complete67C6D0 executes over eight input records with model-node count0, an explicit geometry boundary. The source67C990 child is a throwing unentered target here; its complete numeric chain has separate original comparison. This cohort establishes curves/cursors/batch retirement, not actor-model patching or full owner lifetime.','All33 owned LIP payloads execute to retirement. Synthetic eight-slot masks, cursor positions and signed32 frame wrapping compare source state. Only source stack weight results from a nonretired final visited instance are compared; no such scratch exists in production.','Increasing nonterminal integer times, finite values/intermediates and nearest-rounding profile. No zero-duration or physical PS2 exceptional arithmetic claim.67C590 is static header/initialization authority only; its actual owner/admission remains separate.'])
    try:
        for name in files:
            target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/name).read_bytes())
        (out/'reference.hpp').write_text((ROOT/reference).read_text()+'\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n')
        body='\n'.join((ROOT/name).read_text()for name in entries.values());actual={Path(name).stem for name in entries.values()};calls=set(re.findall(r'\b((?:sub|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual));decl+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for name in sorted(calls-actual));(out/'functions.h').write_text('#pragma once\n'+decl);(out/'original.cpp').write_text(body);(out/'original_dispatch.hpp').write_text(''.join('case '+hex(address)+':'+Path(name).stem+'(memory,context,runtime);return;\n'for address,name in entries.items()))
        for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
        for name in ['ps2_recompiled_functions.h','o2_functions.h']:(out/name).write_text('#pragma once\n#include "functions.h"\n')
        for name in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/name).write_text('#pragma once\n')
        inventory=ROOT/'build-native-sjuni/facial-resource-inventory-v2/receipt.json';data=json.loads(inventory.read_text());assert data['status']=='passed'and len(data['lip_assets'])==33;identity=json.loads((ROOT/'build-native-sjuni/primary-scene-scope-llvm-v4/receipt.json').read_text());archive=Path(identity['commands'][2]['command'][1]);stamp=archive.stat().st_size,archive.stat().st_mtime_ns;payloads=[]
        with archive.open('rb')as source:
            for row in data['lip_assets']:
                source.seek(row['archive_offset']);payload=source.read(row['logical_bytes']);assert hashlib.sha256(payload).hexdigest()==row['sha256'];payloads.append(payload)
        corpus=out/'owned_curves.bin';corpus.write_bytes(struct.pack('<I',len(payloads))+b''.join(struct.pack('<I',len(payload))+payload for payload in payloads));record['asset_inventory']=dict(path=inventory.relative_to(ROOT).as_posix(),sha256=sha(inventory));record['owned_assets']=data['lip_assets'];record['corpus_sha256']=sha(corpus)
        env=dict(os.environ,PATH=str(a.compiler.resolve().parent)+os.pathsep+os.environ.get('PATH',''));exe=out/'checks.exe';command=[str(a.compiler),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-Wno-unused-variable','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),*[str(out/'source'/name)for name in units],str(out/'source'/fixture),str(out/'original.cpp'),'-o',str(exe)];record['command']=command
        result=subprocess.run(command,env=env,capture_output=True,timeout=300);(out/'compile.txt').write_bytes(result.stdout+result.stderr);assert result.returncode==0,'compile failed'
        record['run_command']=[str(exe),str(corpus)];result=subprocess.run(record['run_command'],env=env,capture_output=True,timeout=180);(out/'run.txt').write_bytes(result.stdout+result.stderr);assert result.returncode==0,'comparison failed';assert stamp==(archive.stat().st_size,archive.stat().st_mtime_ns)
        record.update(status='passed',observed=json.loads(result.stdout),source_unchanged=all(sha(ROOT/name)==value for name,value in before.items()));assert record['source_unchanged']
    except BaseException as error:
        record['error']=repr(error);raise
    finally:
        record['output_sha256']={path.relative_to(out).as_posix():sha(path)for path in out.rglob('*')if path.is_file()and path.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
    print(json.dumps(dict(status=record['status'],observed=record['observed'])))


if __name__=='__main__':main()
