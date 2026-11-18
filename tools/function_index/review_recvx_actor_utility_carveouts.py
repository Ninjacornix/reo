"""Static eligibility screen of the assigned CVX actor/effect source partition.

No target execution: independent source enumeration and owned-word comparisons only.
"""
import collections
import hashlib
import json
import pathlib
import re
import subprocess

from review_recvx_ninja_complete_scope import REF, PIN, definitions, implementation, mask
from review_recvx_platform_complete_scope import audit_owned

sha = lambda value: hashlib.sha256(value).hexdigest()
EXTRA = {'effect.c', 'player.c', 'playpch.c', 'playpch2.c', 'pl_evt.c', 'subpl.c', 'weapon.c', 'pwksub.c'}
ACTOR = r'\b(BH_PWORK|O_WRK|O_WORK|ATR|ATR_WORK|EF_WORK|PL_WORK)\b'
DEPENDENCY = r'\b(sys|plp|ene|rom|cam|BH_PWORK|O_WRK|OR_WORK)\b'

# Each row was reviewed through its complete closing brace. These are utility
# carveouts, including narrow format adapters, not original-name promotions.
CASES = {
 'bhDrawPARAM2D': ('njs_quad_adapter', [], 'Writes four XY corners from origin plus extents, publishes caller UV pointer, calls njDrawPolygon2D with count4 and fixed flags0x80000060. Render submission is a side effect; NJS record and flag semantics are not an Outbreak quad ABI.'),
 'ryLinerColor': ('packed_colour_arithmetic', ['main:001BBBA0'], 'Converts rate*256 to signed int, performs masked signed per-channel multiply/shift interpolation, including shifted alpha, without clamp. Signed overflow/right-shift/float conversion assumptions remain. Outbreak1BBBA0 instead scans global cutscene records, uses half-time keys, float interpolation and packed half channels; not an interchangeable packed-colour helper.'),
 'ryRapTexAnm': ('effect_record_adapter', [], 'For nonnegative caller animation index, fills four UV/colour vertices at seven-float stride; optional update decrements index and adds/subtracts packed colour increments. Returns original index. No UV-table bound or output-capacity guard; no compatible Outbreak ANM_WORK/DSP_WRK owner established.'),
 'ryRapDspSet': ('effect_record_adapter', [], 'Copies caller position/scale and initializes four unit-quad XYZ vertices at seven-float stride. Format-specific DSP_WRK output; no shared Outbreak record ABI established.'),
 'ryRapAnmColSet': ('effect_record_adapter', [], 'Stores source colour and builds packed add/subtract steps using signed masked differences divided by col_cnt. Negative steps use bitwise complement, not arithmetic negation; opposite accumulator is not universally initialized. Zero divisor and overflow are not guarded. No exact Outbreak helper established.'),
 'bhEne03_HidePartsSub0': ('njs_tree_bit_operation', [], 'Recursively ORs evalflags mask0x8 on caller NJS_CNK_OBJECT root, child and sibling. No NULL-root or cycle guard. Outbreak actor/CLAY ownership and flag meanings are not inferred from this Ninja object traversal.'),
 'bhEne03_HidePartsSub1': ('njs_tree_bit_operation', [], 'Recursively clears evalflags mask0x8 on caller NJS_CNK_OBJECT root, child and sibling. No NULL-root or cycle guard. No matching Outbreak node layout/flag contract established.'),
 'bhEne03_GetWallDir': ('axis_threshold_classifier', [], 'Ordered Y+,Y-,X+,X-,Z+,Z- threshold0.9 checks return0,1,2,4,5,3. Supplied nonvoid body has no return if all comparisons fail. This missing case is not silently replaced by a generic axis classifier.'),
 'bhEne04_SpeedUp': ('scalar_conditional_step', [], 'Only when *spd<limit, adds g and clamps overshoot above limit. Negative g, unordered comparisons and existing above-limit values follow literal source; no time scaling or generic clamp equivalence established.'),
 'bhEne04_SpeedDown': ('scalar_conditional_step', [], 'Only when *spd>limit, subtracts g and clamps undershoot below limit. No negative-g, NaN or elapsed-time normalization; no exact Outbreak helper established.'),
 'bhEne09_ChkDiffAngle': ('turn16_difference', ['o0:00377110', 'o0:00377140'], 'Computes (dang-pang)&0xFFFF, subtracts0x10000 only if result>0x8000. Half-turn tie is +32768. Outbreak377140 sign-extends16-bit difference before signed16 division, so divisor1 gives -32768 at the tie;377110 reports sign using bit15. Similar angle task, different edge contract.'),
 'bhEne13_ScaleModel': ('ninja_vertex_format_adapter', [], 'If model exists, uses HDR_PS.usIndexMax and scales XYZ of both consecutive NJS_POINT4 records per vertex, advancing by two. Does not normalize the second vector or recurse. CVX vertex/normal packing is not an Outbreak CLAY stream identity.'),
 'ChangeAmbient': ('ninja_material_format_adapter', [], 'Walks short chunk stream until0xFF, changes byte+5 for commands18/22 and byte+9 for19/23, with command-dependent skips. No stream length supplied. No compatible Outbreak material stream established.'),
 'bhEne19_CollisionCircle2Oval': ('njs_geometry_adapter', [], 'Uses optional identity base, inverse transform in shared lcmat, divides X/Z by radii, normalizes and rescales, compares rc squared plus local squared length against world XZ distance. Writes transformed pos on both return branches, including return0. No degenerate-radius guard or exact ellipse closest-point proof; shared scratch side effects retained.'),
 'bhEne22_GetDengekiColorAddr': ('ninja_material_format_adapter', [], 'Finds nth material command17..23 in caller Ninja plist, skipping strip64..66, texture8 and modifier56..58 records; returns payload word pointer. Local short*plp shadows global player name. Terminator exits without a return value; no bounded stream or Outbreak format equivalence.'),
 'bhEne22_ChgDengekiColor': ('ninja_material_format_adapter', [], 'Traverses caller plist and writes one BGRA colour for material17/21 or two for19/23; other selected material types cause no colour write. Local plp is not the player global. No stream extent/null guard or Outbreak material ABI established.'),
 'bhEne29_ActionSearch': ('caller_table_binary_search', [], 'Binary-searches caller EA_WORK.label for key low8(act_nw)<<8|low8(act_no), low0 and inclusive high=tbl_num. Count-versus-last-index remains a caller invariant. This is an algorithmic carveout from eaw_typ, not an Outbreak action record or standard bsearch ABI.'),
 'MixSetToJointRot': ('njs_joint_rotation_adapter', [], 'Composes path rotations until rutP[1]==-1, object rotation, inverse and yaw using shared lcmat[0/1], then writes three Euler turn16 angles to chosen NJS_CNK_OBJECT. No path bound or asin domain clamp. Matrix scratch mutations and Ninja layout prevent a pure host or Outbreak skeleton alias.'),
 'bhGetFrameNum': ('frame_unit_adapter', [], 'Unsigned frame totals convert to float; fno_now/65536 is integer division before scaling, then truncates result and multiplies65536, followed by mixed signed/unsigned comparison with fnm_new. No zero old-total guard. Preserve source unit/rounding oddities; Outbreak float track sampling is not this16.16 adapter.'),
 'NitenDir_ck': ('scalar_bearing', ['o0:00370140'], 'atan2f(hontai_x-target_x,hontai_z-target_z)*10430.381f converted to int. Outbreak370140 takes point pointers, subtracts target-current, substitutes a nonzero value for zero Z before angle conversion and masks result16. Argument orientation, zero-Z and normalization differ.'),
 'bhCdirCheck': ('turn16_half_plane', ['o0:00377110'], 'Returns (((my_ang-trg_ang)+0x4000)&0xFFFF)<0x8000. This shifted half-plane interval is not Outbreak377110 sign-bit test of signed16 input difference; no whole-function alias.'),
 'bhDGCdirCheck': ('njs_direction_classifier', [], 'Normalizes a local vector copy and tests dot with (-sin(rot),0,-cos(rot)); negative returns0, otherwise1. Caller input remains unchanged, unlike AngleCheck. Ninja trig/normalization dependencies differ from Outbreak polynomial/VU paths; no exact classifier counterpart.'),
 'bhDGCdirCheck3': ('turn16_sector_classifier', [], 'atan2 bearing minus rotation masked16; quarter-turn sectors with0x2000/0x6000/0xA000/0xE000 boundaries return0/1/2/3. Integer conversion and zero-vector atan2 semantics remain dependencies; no exact Outbreak four-sector helper established.'),
 'bhEne_AngleCheck': ('stateful_njs_angle_test', [], 'Resets/rotates current Ninja matrix twice, constructs comparison vectors, normalizes caller vec in place, then uses strict dot comparison. Current matrix is clobbered; not a pure angle predicate or admitted Outbreak matrix owner.'),
 'bhEne_PosCheck': ('scalar_rectangle_test', [], 'Ordinary finite inputs test inclusive rectangle x..x+w,z..z+h. Literal comparisons use !((x+w)<px) and !((z+h)<pz), so unordered upper edges differ from a substituted <= expression. No negative-extent normalization or exact Outbreak owner established.'),
 'bhEne_QuickSort': ('caller_array_sort', ['main:001C5DA0','main:001C5EC0'], 'Sorts eight-byte WORK{float wk,int indx} ascending via midpoint pivot, strict comparisons, paired swaps and recursion guarded first<last. Outbreak1C5DA0 partitions four-byte pointers by unsigned word at pointee+8 and uses1C5EC0 pointer swap. Layout, key type/NaN, and initial guard differ.'),
 'bhEne_DirCheck': ('stateful_njs_direction_test', [], 'Resets current Ninja matrix, rotates by -ay, transforms vector, returns0 for resulting z>=0 otherwise1. Current matrix is overwritten, no exact Outbreak predicate admitted.'),
 'bhEne_GetShapeCnt': ('caller_key_interpolation', ['main:0018F1E0','o2:00590B10'], 'Unbounded scan of eight-byte P_WORK{int key,float cnt}, exact-key return otherwise linear interpolation with previous record. No first-key/count/end guard. Outbreak590B10 has explicit count, four-byte signed16 value/time records and endpoint clamps for admitted positive counts, but no zero-count guard;18F1E0 is scalar time/value line arithmetic with no record scan.'),
 'bhArcTan2': ('scalar_bearing', ['o0:00370140'], 'Uses sqrt(x*x+y*y), zero-length return0, asin(y/len)*10430.381, with x<0 branch assigning signed16(32768-ang). This is not atan2f or Outbreak370140 epsilon/masked pointer-bearing contract; overflow, normalization and quadrant rounding differ.'),
 'SetEff5SnowRectAreaCenter': ('particle_record_math', [], 'Stores caller centre and derives six bounds as centre +/- stored size/2. Uses CVX EFF5SNOWRECT fields only; no pool access, but no corresponding Outbreak record established.'),
 'SetEff5SnowRectAreaCenterAndSize': ('particle_record_math', [], 'Stores caller centre and sizes and computes six centre +/- size/2 bounds. No extent validation or Outbreak particle ABI established.'),
 'SetEff5SnowRectParticleMax': ('particle_record_setter', [], 'Negative or above-total requested count becomes total, then writes previous/current/next and zeroes timers. This literal negative-to-total policy is not generic clamp-to-zero.'),
 'MovEff5SnowRectParticleMax': ('particle_record_setter', [], 'Same negative/above-total-to-total policy; only changed target updates previous/current target and transition timer. Caller EFF5SNOWRECT layout and timer unit remain CVX-specific.'),
 'ArrangeEff5SnowRectParticle': ('particle_record_rng_adapter', [], 'Uses caller group/point counts to write XYZ=min+size*(-rand()/-2.1474836E9f). Mutates standard RNG state, with no authored wind/sys access inside this helper. Negative counts are not guarded; no same Outbreak RNG sequence or record owner established.'),
 'SetEff5SnowRectParticleTexture': ('particle_record_setter', [], 'Stores texture-list pointer/number and four UV pairs into caller particle model. No texture upload, allocation or Outbreak ownership equivalence follows.'),
 'SetEff5SnowRectParticleColor': ('particle_record_setter', [], 'Writes four caller packed colours to SnowModel vertices, without interpolation or palette conversion. No shared Outbreak record ABI.'),
 'SetEff5SnowRectParticleSize': ('particle_record_math', [], 'Writes quad X +/-width/2, Y +/-height/2 and Z0 to four caller model vertices. Leaves UV/colour fields; no exact Outbreak owner established.'),
}

# These passed the primitive-signature screen but a complete body demonstrated
# authored ownership/policy or a transitive dependency instead of a pure utility.
BOUNDARIES = {
 'bhCPM2_act_scp': 'Complete scoped-weapon player state machine: reads/writes global plp, sys and cam; uses authored PlMtnWpn/WpnTab/WpnEffTab, weapon18 effect branch, bullet checks/counting, gun collision, vibration/audio, recoil timer and analog aim limits. Embedded Ninja transforms and scalar aim math are not independent functions; generic primitives are separately covered.',
 'bhClearEffect': 'Clears global eff array; underlying memory fill is separately reusable, not this game owner.',
 'bhClearEventEffect': 'Calls three game-specific effect-pool clear owners.',
 'bhDraw021': 'Publishes fixed letterbox quads/640x480 screen policy rather than a caller-parameterized rectangle helper.',
 'bhEff307Drw': 'OR_WORK/R07_WORK effect renderer with Ninja render-state and authored spline progression; ryLinerColor is separately carved out.',
 'bhEff309Drw': 'OR_WORK/R09_WORK effect renderer and ryRapTexDrw dependency, which reads global camera matrix.',
 'CreateEff5SnowRect': 'Owns game effect-pool allocation through bhSetExtraEffectWork, capped particle capacity and allocation-header conventions; math setters separately carved out.',
 'DeleteEff5SnowRect': 'Marks CVX pool allocation preceding point array through pPointTop[-1].z; not generic free.',
 'ExecEff5SnowRect': 'Calls GetEff5SnowRectCurrentWindVector, which reads sys wind fields; updates authored fall/wrap and timer policy.',
 'bhEne01Parent_Move': 'Calls parent nearest/no-stair actor searches with game-global enemy owners.',
 'bhEne02_SetSandEffectMain': 'Authored effect-type switch and transitive SetSandSpr/Particle global effect-pool creation.',
 'bhEne03_CheckClimbWall': 'Constant return0 body, no climbing geometry supplied.',
 'bhEne03_CheckClimbDownWall': 'Constant return0 body, no climbing geometry supplied.',
 'bhEne03_AvoidWall': 'Constant return0 body, no wall-avoidance algorithm supplied.',
 'bhEne19_ActionSearch': 'Binary-search algorithm is tied to authored global En19ActTbl and fixed inclusive high50; caller-table en29 variant separately carved out.',
 'bhEne19_SetLeftClaw': 'Builds reflected claw PRM_WRK from ML_WORK then allocates authored effect312 through bhSetRapEff; not a pure reflection helper.',
 'bhEne22_GetAreaNo': 'Four fixed70x70 local region rectangles are authored area policy; generic bhEne_PosCheck separately carved out.',
 'bhEne22_AreaCheck': 'Compares authored area labels; two outside points (-1/-1) compare equal. Not generic geometric equality.',
 'bhEne29_ActionInit': 'Stores caller table/count but initializes current action to authored30; no independent search algorithm here.',
 'bhEne_SetVibration': 'Fixed game input enum maps to vibration patterns9/10/11 at port1.',
 'bhEne_CallPlayerVoice': 'Game audio helper with fixed sound volume127; not an independent decoder or mixer.',
 'bhEne_CallEffectSE': 'Game audio wrapper with fixed flags0x400 and volume127.',
 'bhEne_CheckPlayEffectSE': 'Game audio status wrapper with fixed flags0x400; no backend algorithm supplied.',
}

def partition(path):
    path = pathlib.PurePosixPath(path)
    return str(path.parent) == 'src/ps2/veronica/prog' and (path.name.startswith(('en', 'effsub', 'zonzon')) or path.name in EXTRA)

def main():
    assert subprocess.check_output(['git','-C',str(REF),'rev-parse','HEAD'],text=True).strip() == PIN
    assert not subprocess.check_output(['git','-C',str(REF),'status','--porcelain','--untracked-files=no'],text=True).strip()
    # Seed only from the pinned source inventory, never aggregate coverage or
    # an earlier output receipt: promotion cannot shrink this fixed partition.
    inventory_path=pathlib.Path('build-function-index/recvx-complete-source-inventory.json')
    inventory_raw=inventory_path.read_bytes();shared=json.loads(inventory_raw)
    by_file={f['path']:f['functions'] for f in shared['files'] if partition(f['path'])}
    shared_by_file={f['path']:f for f in shared['files']}
    screened=[]; admitted=[]; files=[]; boundary_rows=[]
    for file, expected in sorted(by_file.items()):
        raw=(REF/file).read_bytes();src=raw.decode(); local=[]
        for symbol,a,b,e in definitions(src):
            body=src[b:e];clean=mask(body);sig=src[a:b]
            status=implementation(body);line=src.count('\n',0,a)+1
            row={'id':file+':'+symbol+':'+str(line),'file':file,'reference_file':file,'symbol':symbol,'start_line':line,'line_start':line,
                 'body_line_start':src.count('\n',0,b)+1,'line_end':src.count('\n',0,e)+1,'signature_start':a,'body_start':b,'end_exclusive':e,
                 'signature':re.sub(r'\s+',' ',sig).strip(),'source_sha256':sha(raw),'body_sha256':sha(body.encode()),'definition_sha256':sha(src[a:e].encode()),
                 'implementation_status':status,'signature_actor_tokens':sorted(set(re.findall(ACTOR,mask(sig)))),
                 'body_dependency_tokens':sorted(set(re.findall(DEPENDENCY,clean))),'outbreak_comparisons':[],
                 'evidence':[f'https://github.com/AshfordFamily/recvx-decomp/blob/{PIN}/{file}#L{line}']}
            if status!='implemented':
                row.update(disposition='empty_or_unavailable_reference_body',reason='Empty/declaration-only reference supplies no implemented utility; no original no-op equivalence inferred.',comparison_depth='implementation_shape_screen')
            elif symbol in CASES:
                kind,ids,reason=CASES[symbol]
                row.update(disposition=kind,reason=reason,outbreak_comparisons=ids,comparison_depth='complete_source_and_owned_candidate_contract' if ids else 'complete_source_contract_no_identified_outbreak_counterpart')
                row['source_facts']={'call_or_macro_tokens':sorted(set(re.findall(r'\b([A-Za-z_]\w*)\s*\(',clean))-{'if','for','while','switch','sizeof','return','void','float','int','short'})}
                admitted.append(row)
            elif row['signature_actor_tokens']:
                row.update(disposition='actor_record_signature_dependency',reason='Complete masked signature explicitly consumes or returns '+','.join(row['signature_actor_tokens'])+'; whole actor/state owner is outside the independent-utility scope. Embedded scalar expressions are not separate functions.',comparison_depth='exact_signature_dependency_screen')
            elif symbol in BOUNDARIES:
                row.update(disposition='reviewed_authored_or_transitive_boundary',reason=BOUNDARIES[symbol],comparison_depth='complete_body_eligibility_boundary')
                boundary_rows.append(row)
            else:
                assert row['body_dependency_tokens'],(file,symbol)
                row.update(disposition='explicit_body_game_dependency',reason='Masked body has explicit game-global/actor dependency tokens: '+','.join(row['body_dependency_tokens'])+'. These names are dependency-screen evidence, not semantic aliases; all primitive-signature exceptions without such ownership are separately reviewed.',comparison_depth='body_dependency_eligibility_screen')
            local.append(row);screened.append(row)
        assert {(r['symbol'],r['start_line'],r['body_sha256']) for r in local} == {(r['symbol'],r['start_line'],r['body_sha256']) for r in shared_by_file[file]['functions']}
        assert {(r['symbol'],r['start_line']) for r in local} == {(r['symbol'],r['start_line']) for r in expected}
        files.append({'file':file,'sha256':sha(raw),'bytes':len(raw),'definitions':len(local)})
    assert len(screened)==1850 and len(files)==59 and len(admitted)==37 and len(boundary_rows)==23
    assert {r['symbol'] for r in admitted}==set(CASES)
    result={'schema':1,'kind':'static-actor-utility-eligibility-screen-and-carveout-contracts','reference_commit':PIN,
            'scope_input':str(inventory_path),'scope_input_sha256':sha(inventory_raw),'scope_predicate':'Exact parent src/ps2/veronica/prog; basename begins en/effsub/zonzon or is one of sorted EXTRA in helper.','files':files,
            'screened_definitions':screened,'definitions':admitted,'reviewed_boundary_definitions':boundary_rows,
            'counts':{'screened_files':len(files),'screened_definitions':len(screened),'admitted_utility_carveouts':len(admitted),
                      'screen_implementation':dict(collections.Counter(r['implementation_status'] for r in screened)),
                      'screen_dispositions':dict(collections.Counter(r['disposition'] for r in screened)),
                      'direct_owned_comparisons':sum(bool(r['outbreak_comparisons']) for r in admitted)},
            'independent_inventory_reconciliation':{'screened':len(screened),'missing':0,'extra':0,'different_body_hashes':0},
            'outbreak_evidence':audit_owned({i for r in admitted for i in r['outbreak_comparisons']}),
            'limitations':['Eligibility screen is exhaustive over assigned definitions, not full semantic decompilation of every excluded actor behavior.',
                          'All37 admitted and23 boundary definitions were read as complete bodies; only named Outbreak candidates have direct full-body comparison.',
                          'NJS/effect-format adapters and standard RNG/current-matrix scratch effects are explicitly retained; they are not pure host functions.',
                          'No runtime performance, original SDK name, whole-engine identity or safe replacement is established.']}
    pathlib.Path('build-function-index/recvx-actor-utility-carveouts.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    write_note(result)
    print(json.dumps({'counts':result['counts'],'owned_word_audit':result['outbreak_evidence']}))

def write_note(result):
    a=result['outbreak_evidence'];c=result['counts']
    lines=['# Actor-source utility eligibility audit','',
      f'Static review, 2026-11-05. Reference commit `{PIN}`. The assigned actor/effect partition contains **1,850 definitions across 59 files**. The screen admits **37 narrow utility or caller-format adapters**, including helpers inside actor files that a whole-file game-specific exclusion would otherwise miss. This is reference coverage, not 37 newly named Outbreak functions. No canonical Outbreak mapping mistake or whole-function alias was demonstrated.','',
      'The frozen scope is selected directly from the pinned source inventory: files immediately under `src/ps2/veronica/prog` whose basenames begin `en`, `effsub` or `zonzon`, plus `effect`, `player`, `playpch`, `playpch2`, `pl_evt`, `subpl`, `weapon` and `pwksub`. These correspond to the original actor exclusion partition; live aggregate coverage and earlier output receipts are never inputs. Every exact `(file, symbol, start_line)` identity, complete body hash/bounds, screen disposition and dependency token is retained in `build-function-index/recvx-actor-utility-carveouts.json`. The independent extractor reconciles all 1,850 definitions and body hashes with the shared source inventory, with zero missing/extra/different records. No game, build, target execution, attachment or live-memory access occurred.','',
      '## Method and limits','',
      'The eligibility screen examines implementation shape, complete masked signatures and explicit body dependencies. A BH_PWORK/O_WORK/ATR actor argument or game globals/actor-local records gives an ownership boundary, rather than an invented reusable function. Primitive-signature survivors were reviewed as complete bodies, including transitive effect-pool, camera, wind and audio dependencies. The two en22 material helpers have a local `short* plp`; this shadows the player-global spelling and was manually exempted from a lexical false positive. Shared Ninja current-matrix/lcmat state and standard RNG state are retained as explicit utility side effects.','',
      'This is an exhaustive eligibility screen, **not a claim that all excluded actor behaviours were semantically translated**. The 37 admitted utilities and 23 policy/transitive boundary bodies were read completely; actor-record/global exclusions have the narrower signature/body-dependency depth stated per row. Empty bodies are unavailable implementations, not evidence of equivalent original no-ops. No Outbreak counterpart was guessed where its ownership and complete contract were not established.','',
      '| Screen disposition | Definitions |','| --- | --- |']
    for kind,count in sorted(c['screen_dispositions'].items()):lines.append(f'| `{kind}` | {count} |')
    lines+=['',
      '## Concrete comparison results','',
      '- **Turn16 half-turn:** CVX `bhEne09_ChkDiffAngle` keeps +32768. Outbreak o0 `0x377140` sign-extends the difference, giving -32768 with divisor1; o0 `0x377110` uses the sign bit for its direction result. An apparently identical angle subtraction therefore has a real edge difference.',
      '- **Interpolation:** CVX `bhEne_GetShapeCnt` scans unbounded eight-byte integer-key/float-value records and may access the previous record before its first key. Outbreak o2 `0x590B10` supplies a count, uses four-byte signed-half value/time records and clamps endpoints. Main `0x18F1E0` is a scalar line formula, not a record scan. No track-layout substitution follows.',
      '- **Sort:** CVX `bhEne_QuickSort` sorts eight-byte float-key/index pairs, with a first<last entry guard. Outbreak main `0x1C5DA0` sorts four-byte pointers by unsigned pointee+8 words and swaps through `0x1C5EC0`. Pivot/partition resemblance does not establish the same key domain, NaN behaviour or ABI.',
      '- **Packed colour:** `ryLinerColor` quantizes rate to signed rate*256 and uses channel masks with integer multiply/arithmetic shifts. Outbreak main `0x1BBBA0` is a global cutscene-track owner using float interpolation of packed half channels and halved key times. It is not the same packed-byte utility.',
      '- **Bearing:** `NitenDir_ck` and `bhArcTan2` differ from o0 `0x370140` in scalar-versus-point inputs, subtraction orientation, zero-Z handling and masking. `bhArcTan2` uses sqrt/asin with a signed-half quadrant assignment; its name does not make it the same atan2 implementation.',
      '- **State and formats:** Ninja tree flags, chunk materials, paired vertex records and joint matrices remain CVX/NJS contracts. Angle/direction tests overwrite the current Ninja matrix, AngleCheck normalizes caller input, joint/oval helpers overwrite lcmat, and particle arrangement advances standard RNG. Particle setters are admitted only as caller-record adapters, not as the game wind/pool controller. No Outbreak CLAY/NBD ownership or native renderer was inferred.','',
      f'The focused comparison validates **{len(a["complete_catalogue_bodies"])} complete owned Outbreak bodies and {a["verified_comments"]} original instruction comments**, with {a["omitted_zero_words"]} omitted zero words, zero conflicts and zero omitted nonzero words. Image-qualified targets are preserved. [Static audit helper](../../tools/function_index/review_recvx_actor_utility_carveouts.py).','',
      '## Complete admitted-utility ledger','',
      'Each pinned source link identifies a complete function. Full hashes/bounds and exact dependency/call evidence are in the JSON. A target below is an investigated candidate, not a promoted alias.','',
      '| Reference function and lines | Narrow disposition / full-body contract | Complete body SHA-256 |','| --- | --- | --- |']
    for r in result['definitions']:
        ids=' '.join('`'+i+'`' for i in r['outbreak_comparisons'])
        lines.append(f'| [{pathlib.Path(r["file"]).name}:{r["symbol"]}]({r["evidence"][0]}) {r["line_start"]}-{r["line_end"]} | `{r["disposition"]}` {ids}. {r["reason"].replace(chr(124),chr(92)+chr(124))} | `{r["body_sha256"]}` |')
    lines+=['','## Reviewed exclusions at the utility boundary','','| Reference | Why whole owner remains game-specific or unavailable |','| --- | --- |']
    for r in result['reviewed_boundary_definitions']:
        lines.append(f'| [{pathlib.Path(r["file"]).name}:{r["symbol"]}]({r["evidence"][0]}) | {r["reason"]} |')
    lines+=['','## Screened file universe','','| File | Definitions | Raw source SHA-256 |','| --- | --- | --- |']
    for f in result['files']:lines.append(f'| `{f["file"]}` | {f["definitions"]} | `{f["sha256"]}` |')
    pathlib.Path('docs/recvx-crosscheck/ACTOR_UTILITY_ELIGIBILITY_AUDIT.md').write_text('\n'.join(lines)+'\n',encoding='utf-8')

if __name__ == '__main__':main()
