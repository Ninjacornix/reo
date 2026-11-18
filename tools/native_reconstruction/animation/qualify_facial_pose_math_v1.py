"""Seal the six-MAT facial math component and current production library build."""
import hashlib
import json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    sources=['game/native/animation/facial_pose_math.hpp','game/native/animation/facial_pose_math.cpp','game/native/animation/CMakeLists.txt','tools/native_reconstruction/animation/facial_pose_math_tests.cpp','tools/native_reconstruction/animation/verify_facial_pose_math.py','tools/native_reconstruction/animation/qualify_facial_pose_math_v1.py','docs/native-gameplay/FACIAL_POSE_MATH.md'];current={name:sha(ROOT/name)for name in sources};loaded=[];receipts={}
    for role,pattern in [('math','facial-pose-math-{}-v5'),('current_parents','actor-model-classes-parents-{}-v2')]:
        for compiler in ['llvm','gcc']:
            path=ROOT/'build-native-sjuni'/pattern.format(compiler)/'receipt.json';value=json.loads(path.read_text());assert value['status']=='passed'and value.get('source_unchanged',True)and not value.get('source_drift')
            for proof in value.get('original_owned_bodies',[]):assert proof['conflicts']==0 and proof['matched_comments']>0
            key=role+'_'+compiler;loaded.append((key,value));receipts[key]=dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),compiler_sha256=value['compiler_sha256'],observed=value.get('observed'),parent_tests=value.get('parent_tests'),source_unchanged=value.get('source_unchanged'),source_drift=value.get('source_drift'))
    matches={}
    for name,expected in current.items():
        if name.startswith('docs/')or name.endswith('qualify_facial_pose_math_v1.py'):continue
        matches[name]=[key for key,value in loaded if value.get('source_sha256',{}).get(name)==expected];assert matches[name],name
    record=dict(schema=1,status='passed',scope='Complete67C990 six-bank facial matrix blend and1A5050 scalar basis reconstruction with actual18MAT/pairedNBD caller-node admission.',game_run=False,device_opened=False,installed_in_game=False,stage4_complete=False,source_sha256=current,matching_qualified_snapshots=matches,receipts=receipts,limits=[
        'Seven original source entries execute their complete bodies without arithmetic/copy observation ports. Initialized identity294E00 is seeded from verified195E50 static authority, not an executed full bootstrap.',
        '18 actual MAT files are paired with base NBDs and their six track4 nodes. HP03/HN39 nonfinite unused matrix ordinal6 is retained as a caller-boundary finding. This does not establish every runtime relabel or replacement asset.',
        'Finite consumed inputs/intermediates and nearest FP32 rounding. Unconsumed W/third-axis and preserved translation words retain arbitrary bits. Physical PS2 exceptional arithmetic is not claimed.',
        'Current parent28 verifies production CMake/library build only. Facial asset workspace/loading, lip curves, lifetime/instances, actual actor joint adoption and complete cinematic/session/game installation remain open.',
    ])
    path=ROOT/'tools/native_reconstruction/native_facial_pose_math_qualification_v1.json';path.write_text(json.dumps(record,indent=2)+'\n');print(json.dumps(dict(status='passed',receipts=len(receipts),sources=len(sources),seal_sha256=sha(path))))


if __name__=='__main__':main()
