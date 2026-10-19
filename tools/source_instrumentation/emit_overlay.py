from pathlib import Path
import argparse,subprocess,json,hashlib,os
a=argparse.ArgumentParser();a.add_argument('--tool',required=True);a.add_argument('--output',required=True);a.add_argument('--sources',required=True);args=a.parse_args()
tool=Path(args.tool).resolve();output=Path(args.output).resolve();sources=Path(args.sources).resolve()
if not tool.is_file():raise RuntimeError('Reviewed source instrumenter missing')
output.mkdir(parents=True,exist_ok=True)
tool_hash=hashlib.sha256(tool.read_bytes()).hexdigest();records=[];emitted=[]
for row in sources.read_text().splitlines():
    if not row.strip():continue
    original=Path(row).resolve()
    if not original.is_file():raise RuntimeError('Generated source missing: '+str(original))
    identity=hashlib.sha256(str(original).encode()).hexdigest()[:16];folder=output/identity;folder.mkdir(exist_ok=True)
    target=folder/original.name;stamp=folder/'source.json';input_hash=hashlib.sha256(original.read_bytes()).hexdigest()
    prior=json.loads(stamp.read_text()) if stamp.exists() else {}
    if prior.get('source_sha256')!=input_hash or prior.get('tool_sha256')!=tool_hash or not target.exists():
        temporary=folder/(original.name+'.new')
        result=subprocess.run([str(tool),str(original),str(temporary)],capture_output=True,text=True)
        if result.returncode:raise RuntimeError('Uninstrumentable source '+str(original)+': '+result.stderr)
        # Refuse field syntax missed by the concrete emitter. All remaining
        # ctx arrows must be arguments of the reviewed read/write/address API.
        text=temporary.read_text()
        if '#include "source_instruction_access.hpp"' not in text:raise RuntimeError('Source overlay omitted actual accessor include')
        accessor=text.find('#include "source_instruction_access.hpp"');entry=text.find('reo_source_instrumentation::EntryScope reo_source_entry(')
        if entry>=0 and accessor>entry:raise RuntimeError('Source overlay placed actual accessor after its first use')
        os.replace(temporary,target)
    record={'source':str(original),'source_sha256':input_hash,'tool_sha256':tool_hash,'output':str(target),'output_sha256':hashlib.sha256(target.read_bytes()).hexdigest()}
    stamp.write_text(json.dumps(record,indent=2)+'\n');records.append(record);emitted.append(target)
def quoted(path):return '[==['+str(path).replace('\\','/')+']==]'
# Preserve quoted-header lookup without per-source INCLUDE_DIRECTORIES,
# which otherwise excludes every generated file from real CMake unity batches.
import re
# Actual originals identify the canonical workspace; no guessed private tree.
source_roots={Path(record['source']).resolve().parents[3] for record in records if Path(record['source']).parent.name=='output'}
if source_roots:
    workspace=next(iter(source_roots))
else:
    first=Path(records[0]['source']).resolve()
    workspace=next(parent for parent in first.parents if (parent/'recomp/CMakeLists.txt').is_file())
runtime=workspace/'third_party/PS2Recomp/ps2xRuntime/src/lib'
geometry=workspace/'tools/parallel_gs_backend/resident_geometry'
forwarders={};header_hashes={}
for target,record in zip(emitted,records):
    original=Path(record['source']).resolve()
    includes=set(re.findall(r'^\s*#\s*include\s*"([^"]+)"',target.read_text(),re.MULTILINE))
    includes.add('upstream/original_composition_control.hpp')
    for name in sorted(includes):
        relative=Path(name)
        if relative.is_absolute() or '..' in relative.parts:
            raise RuntimeError('Quoted header needs explicit bounded forwarding: '+name)
        selected=next((p.resolve() for p in [original.parent/relative,runtime/relative,geometry/relative] if p.is_file()),None)
        if selected is None:continue # Existing target/global include path.
        forward=target.parent/relative
        content='#pragma once\n#include "'+selected.as_posix()+'"\n'
        if forward.exists() and forward.read_text()!=content:
            raise RuntimeError('Preserve prior private header identity: '+str(forward))
        forward.parent.mkdir(parents=True,exist_ok=True)
        if not forward.exists():forward.write_text(content)
        if selected not in header_hashes:header_hashes[selected]=hashlib.sha256(selected.read_bytes()).hexdigest()
        forwarders[str(forward)]={'original':str(selected),'sha256':header_hashes[selected],'forwarder_sha256':hashlib.sha256(forward.read_bytes()).hexdigest()}
(output/'header-forwarders.json').write_text(json.dumps(forwarders,indent=2)+'\n')
(output/'emitted.cmake').write_text('set(REO_EMITTED_SOURCES\n'+''.join('    '+quoted(f)+'\n' for f in emitted)+')\n')

(output/'manifest.json').write_text(json.dumps({'tool':str(tool),'tool_sha256':tool_hash,'sources':records,'original_or_gpu_execution':False},indent=2)+'\n')
print('Prepared '+str(len(records))+' guarded build-only source overlays')
