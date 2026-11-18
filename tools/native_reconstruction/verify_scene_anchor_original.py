"""Bounded 5C4940 native/original comparison, including one positive transition path."""
import hashlib, json, os, re, subprocess, time
from pathlib import Path
from audit_retail_effect_descriptors import compare_source

ROOT=Path(__file__).resolve().parents[2]
OVERLAY_SHA="45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226"
COMPILER_SHA="f1377bd9c4e35669930d0fb2ebdc51cac1d1f4ca16638c0ed0d77c113bc195d3"
FILES=("game/native/gameplay_application/session_scene_query_effects.hpp",
       "game/native/gameplay_application/session_scene_query_effects.cpp",
       "game/native/gameplay_application/native_session.hpp",
       "game/native/gameplay_application/session_rooms.hpp",
       "game/native/gameplay_world/world.hpp",
       "game/native/gameplay_scene/records.hpp",
       "game/native/gameplay_scenario/scene_control_types.hpp")
def sha(path):return hashlib.sha256(Path(path).read_bytes()).hexdigest()

def main():
 import argparse
 p=argparse.ArgumentParser();p.add_argument("--output",type=Path,required=True);p.add_argument("--snapshot",type=Path,required=True);a=p.parse_args()
 out=a.output.resolve();base=(ROOT/"build-native-sjuni").resolve()
 if out.exists() or not out.is_relative_to(base):raise ValueError("output must be a fresh directory under build-native-sjuni")
 snapshot=a.snapshot.resolve();receipt=json.loads((snapshot/"receipt.json").read_text())
 if receipt.get("status")!="passed":raise ValueError("native archive snapshot is not passed")
 for name in FILES:
  if sha(snapshot/"source"/name)!=receipt["source_sha256"][name]:raise ValueError(f"snapshot source hash mismatch: {name}")
 for name,digest in receipt["archives_sha256"].items():
  if sha(snapshot/"native-build"/name)!=digest:raise ValueError(f"snapshot archive hash mismatch: {name}")
 overlay=ROOT/"build-function-index/owned-overlays/o2.bin"
 if sha(overlay)!=OVERLAY_SHA:raise ValueError("owned O2 overlay hash mismatch")
 source=ROOT/"recomp/config/output_ovl/o2/o2_005C4940_0x5c4940.cpp";text=source.read_text(encoding="utf-8")
 end=int(re.search(r"// Address: 0x[\da-f]+ - 0x([\da-f]+)",text)[1],16)
 audit=compare_source("complete scene-anchor callback",source.relative_to(ROOT).as_posix(),0x5c4940,end,
                      lambda at,n:overlay.read_bytes()[at-0x570000:at-0x570000+n])
 body=text[text.index("// Function:"):]
 body=re.sub(r"o[02]_([0-9A-Fa-f]{8})_0x([0-9a-f]+)\(rdram, ctx, runtime\);",lambda m:f"runtime->lookupFunction(0x{m.group(2)}u)(rdram,ctx,runtime);",body)
 reference=(ROOT/"tools/native_reconstruction/gameplay_collision_oracle/reference.hpp").read_text(encoding="utf-8")
 start=reference.index("inline PS2Runtime::Fn PS2Runtime::lookupFunction");finish=reference.index("\n}",start)+2;reference=reference[:start]+reference[finish:]
 reference+="\n#define WRITE16(at,v) ref_write(rdram,at,std::uint16_t(v))\n"
 name=source.stem
 reference+=f"\nvoid {name}(std::uint8_t*,R5900Context*,PS2Runtime*);\nvoid original_port(std::uint8_t*,R5900Context*,PS2Runtime*);\nvoid unused_scene_transform(std::uint8_t*,R5900Context*,PS2Runtime*);\nvoid local_control_gate(std::uint8_t*,R5900Context*,PS2Runtime*);\ninline PS2Runtime::Fn PS2Runtime::lookupFunction(std::uint32_t a)const{{if(a==0x5c4940u)return {name};if(a==0x370320u||a==0x1900e0u)return unused_scene_transform;if(a==0x1b0340u)return local_control_gate;return original_port;}}\n"
 out.mkdir(parents=True);(out/"scene_anchor_reference.hpp").write_text(reference,encoding="utf-8")
 (out/"o2_functions.h").write_text('#pragma once\n#include "scene_anchor_reference.hpp"\n')
 for n in ("ps2_runtime.h","ps2_runtime_macros.h","ps2_recompiled_stubs.h","ps2_syscalls.h","ps2_stubs.h"):
  (out/n).write_text('#pragma once\n#include "scene_anchor_reference.hpp"\n' if n in ("ps2_runtime.h","ps2_runtime_macros.h") else "#pragma once\n")
 generated=out/"original_and_checks.cpp";(generated).write_text('#include "scene_anchor_reference.hpp"\n'+body+'\n'+(ROOT/"tools/native_reconstruction/scene_anchor_original_tests.cpp").read_text(encoding="utf-8"),encoding="utf-8")
 compiler=Path(os.environ["LOCALAPPDATA"])/"OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe"
 if sha(compiler)!=COMPILER_SHA:raise ValueError("pinned LLVM compiler hash mismatch")
 exe=out/"scene-anchor-original.exe";cmd=[str(compiler),"-std=c++20","-O2","-Wall","-Wextra","-Wpedantic","-Werror","-Wno-unused-parameter","-I"+str(out),"-I"+str(snapshot/"source"),"-I"+str(ROOT),str(generated),str(snapshot/"source/game/native/gameplay_application/session_scene_query_effects.cpp"),"-Wl,--start-group"]
 cmd.extend(str(snapshot/"native-build"/n) for n in receipt["archives_sha256"]);cmd.extend(["-Wl,--end-group","-lwinmm","-lxinput","-luser32","-lgdi32","-o",str(exe)])
 env=dict(os.environ,PATH=str(compiler.parent)+os.pathsep+os.environ.get("PATH",""));began=time.monotonic()
 built=subprocess.run(cmd,cwd=ROOT,env=env,text=True,capture_output=True,timeout=240)
 (out/"compile.stdout.txt").write_text(built.stdout);(out/"compile.stderr.txt").write_text(built.stderr)
 result={"status":"failed","snapshot":str(snapshot.relative_to(ROOT)),"snapshot_receipt_sha256":sha(snapshot/"receipt.json"),"source_audit":{"start":audit["start"],"end_exclusive":audit["end_exclusive"],"matched_comments":audit["matched_comments"],"omitted_zero_words":audit["omitted_zero_words"],"conflicts":audit["conflicts"]},"compiler_sha256":sha(compiler),"compile_seconds":time.monotonic()-began,"game_run":False,"oracle_helpers":{"370320":"controlled no-op; outputs are unused on selected mode5 special branch","1900E0":"controlled no-op; transformed matrix is unused on selected mode5 special branch","1B0340":"controlled true result; native counterpart is World::locally_controlled(actor)"},"positive_path":{"actor_category":0,"motion_class":"0x1A","mode":5,"scenario":"0x1234","proxy_scene_value":"0x36","proxy_destination":"0x5678","checks":"actor request bytes and transition bytes/globals compared to native result","owned_room":"scenario 41 room 73 from NETBIO00.DAT"},"oracle_test_sha256":sha(ROOT/"tools/native_reconstruction/scene_anchor_original_tests.cpp"),"driver_sha256":sha(Path(__file__))}
 if built.returncode==0:
  asset=Path(os.environ["LOCALAPPDATA"])/"OutbreakRecomp/launcher/imports/file1/25e64b631bbaa0cac9a4822cb66174ff14c3531851d1e502c0a06704379bf446/data/NETBIO00.DAT"
  if not asset.is_file():raise FileNotFoundError(f"owned positive-path asset missing: {asset}")
  run=subprocess.run([str(exe),str(asset)],cwd=ROOT,env=env,text=True,capture_output=True,timeout=120);(out/"run.stdout.txt").write_text(run.stdout);(out/"run.stderr.txt").write_text(run.stderr)
  result.update(run_returncode=run.returncode,run_stdout=run.stdout,run_stderr=run.stderr)
  if run.returncode==0:result["status"]="passed"
 else:result.update(compile_returncode=built.returncode,compile_stderr=built.stderr[-4000:])
 (out/"receipt.json").write_text(json.dumps(result,indent=2)+"\n");print(json.dumps(result,indent=2));return int(result["status"]!="passed")
if __name__=="__main__":raise SystemExit(main())
