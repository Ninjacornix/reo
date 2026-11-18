"""Static, hash-bound per-definition inventory of the admitted CVX Ninja scope."""
import collections
import hashlib
import json
import pathlib
import re
import sqlite3
import struct
import subprocess
import sys

REF = pathlib.Path("C:/Users/Ninjacornix/AppData/Local/Temp/reo-recvx-crosscheck-20261104")
BASE = REF / "src/ps2/veronica/prog"
PIN = "657b0c0c9489943116c71f151804ad7304fca975"
EXTRA = {"ps2_pxlconv.c", "ps2_texture.c", "njplus.c", "njloop.c", "expand.c", "binfunc.c", "Motion.c", "MdlPut.c"}

def sha(data):
    return hashlib.sha256(data).hexdigest()

def mask(source):
    # Keep every byte/newline position while removing comment and literal contents.
    return re.sub(r'/\*.*?\*/|//[^\n]*|"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'',
                  lambda m: ''.join('\n' if x == '\n' else ' ' for x in m[0]), source, flags=re.S)

def signature(segment):
    segment = re.sub(r'^\s*#[^\n]*', '', segment, flags=re.M).strip()
    m = re.search(r'([A-Za-z_]\w*)\s*\([^;{}]*\)\s*$', segment, flags=re.S)
    if not m or '=' in segment[:m.start()] or segment.startswith('typedef'):
        return None
    prefix = segment[:m.start()].strip()
    if not prefix or '(' in prefix or ')' in prefix:
        return None
    return m[1]

def definitions(source):
    clean = mask(source)
    depth = 0
    boundary = 0
    active = None
    result = []
    for i, char in enumerate(clean):
        if char == '{':
            if depth == 0:
                name = signature(clean[boundary:i])
                if name:
                    start = boundary
                    # Exclude leading includes/comments and whitespace from signature bounds.
                    sig_clean = clean[boundary:i]
                    tokens = [x for x in re.finditer(r'\S+', sig_clean) if not sig_clean[:x.start()].strip().startswith('#')]
                    # Last newline with a preprocessor directive, if present.
                    directives = list(re.finditer(r'^\s*#[^\n]*\n', sig_clean, re.M))
                    if directives:
                        start = boundary + directives[-1].end()
                    while start < i and clean[start].isspace():
                        start += 1
                    active = (name, start, i)
            depth += 1
        elif char == '}':
            depth -= 1
            assert depth >= 0
            if depth == 0:
                if active:
                    name, start, brace = active
                    result.append((name, start, brace, i + 1))
                    active = None
                boundary = i + 1
        elif char == ';' and depth == 0:
            boundary = i + 1
    assert depth == 0
    return result

def implementation(body):
    code = mask(body)[1:-1].strip()
    if not code:
        return "empty"
    if not re.search(r'\b(return|if|for|while|do|switch|goto|asm|__asm)\b|[{}]|\+\+|--|(?<![=!<>])=(?!=)', code):
        # Local declarations only, not an implemented function.
        statements = [s.strip() for s in code.split(';') if s.strip()]
        if statements and all(re.match(r'(?:const\s+|unsigned\s+|signed\s+|struct\s+|static\s+|register\s+)*[\w]+(?:\s+|\s*\*+\s*)[\w*][\w\s*,\[\]]*$', s) for s in statements):
            return "declarations_only"
    return "implemented"

def build():
    files = sorted(p for p in BASE.glob('*.c') if p.name.startswith(('ps2_Na', 'ps2_Ninja', 'ps2_Vu')) or p.name in EXTRA)
    records = []
    file_rows = []
    for path in files:
        raw = path.read_bytes()
        source = raw.decode('utf-8')
        assert source.isascii()
        rows = definitions(source)
        for name, start, brace, end in rows:
            body = source[brace:end]
            records.append({"id": f"{path.name}:{name}", "file": str(path.relative_to(REF)).replace('\\', '/'),
                            "symbol": name, "signature_start": start, "body_start": brace, "end_exclusive": end,
                            "line_start": source.count('\n', 0, start) + 1,
                            "body_line_start": source.count('\n', 0, brace) + 1,
                            "line_end": source.count('\n', 0, end) + 1,
                            "source_sha256": sha(raw), "definition_sha256": sha(source[start:end].encode()),
                            "body_sha256": sha(body.encode()), "implementation_status": implementation(body),
                            "disposition": "pending", "outbreak_comparisons": [], "evidence": []})
        file_rows.append({"file": str(path.relative_to(REF)).replace('\\', '/'), "sha256": sha(raw),
                          "bytes": len(raw), "definitions": len(rows)})
    ids = [r['id'] for r in records]
    assert len(ids) == len(set(ids))
    result = {"schema": 1, "kind": "static-source-contract-inventory", "reference_commit": PIN,
            "enhanced_context_commit": "2fa8a14224ebb92d0103a8c828e6a032c338d6d4",
            "bounds_encoding": "UTF-8 byte offsets (these source files are ASCII); end is exclusive",
            "files": file_rows, "definitions": records}
    return result

# Comparisons are deliberately contract dispositions, never original-name aliases.
CASES = {}
def case(file, symbols, ids, verdict, reason):
    for symbol in symbols.split():
        CASES[f'{file}:{symbol}'] = (ids.split(), verdict, reason)

case('ps2_NaMath.c', '_Make_SinTable njSin njCos njSinCos', 'main:0018F340 main:0018F470 o0:003700C0 o0:00370100',
     'related_different_contract', 'Turn16 convention is shared by the wrappers; CVX quadrant table and Outbreak phase polynomial/signed-square-root paths differ. SinCos also publishes VF11/VF12; no numerical/state alias.')
case('ps2_NaMath.c', 'njFraction', 'main:00192200 main:0010A2F0', 'related_different_contract',
     'CVX n-floorf(n) differs from the Outbreak signed fractional-part splitter on ordinary negative nonintegers; e.g. -1.5 gives +0.5 versus -0.5 by the respective arithmetic.')
case('ps2_NaMath.c', 'njSqrt', 'main:00192220', 'supported_local_role',
     'Both move scalar input to VU, VSQRT/VWAITQ, and return Q via a VU add and scalar float. Different registers/ABI side effects remain; this establishes the local square-root role only.')
case('ps2_NaMath.c', 'njLinear', 'main:0018F1E0', 'related_different_contract',
     'CVX lerps adjacent XYZ triples with a normalized fraction; Outbreak evaluates one scalar between explicit sample-time/value pairs using a different division and rounding order.')
case('ps2_NaMath.c', 'njBezierSpline', 'o0:00371600 o0:00370420', 'related_different_contract',
     'CVX arbitrary-degree factorial/Bernstein sum versus fixed three-control-point quadratic constructed by successive lerps in Outbreak; argument layout, degree, overflow and operation order differ.')
case('ps2_NaMatrix.c', 'njGetTranslation', 'main:001900E0', 'supported_local_role',
     'Same XYZ translation offsets30/34/38; CVX matrix/output and NULL-current fallback differ from Outbreak output/matrix and interleaved load/store alias behavior.')
case('ps2_NaMatrix.c', 'njUnitRotPortion', 'main:0018FE20', 'related_different_contract',
     'CVX writes complete constant basis quadwords; Outbreak copies only XYZ from mutable shared template294E00 and explicitly preserves destination W/translation.')
case('ps2_NaMatrix.c', 'njUnitMatrix', 'main:0018FDF0', 'related_different_contract',
     'CVX constructs identity from VF0, with NULL-current fallback; Outbreak copies all64 bytes from shared template294E00, whose contents are a separate state dependency.')
case('ps2_NaMatrix.c', 'njSetMatrix njGetMatrix njCopyMatrix', 'main:00191500', 'supported_local_role',
     'Full64-byte load-before-store copy is shared. Set/Get include CVX current-stack selection; CVX uses VU loads/stores whereas Outbreak uses EE LQ/SQ, so VU clobbers differ.')
case('ps2_NaMatrix.c', 'njTransposeMatrix', 'main:001911D0', 'related_different_contract',
     'Both transpose XYZ basis, but CVX stores full VF7/8/9 after XYZ-only assignments; Outbreak explicitly captures/restores destination basis W. Neither is a general4x4 transpose.')
case('ps2_NaMatrix.c', 'njInvertMatrix', 'main:00191220 main:001911D0 main:001919D0', 'related_different_contract',
     'Both use transposed3x3 and transformed negative translation rather than a general matrix inverse. CVX repacks whole vectors and always TRUE; Outbreak helper preserves original W. Rigid-transform domain only.')
case('ps2_NaMatrix.c', 'njMultiMatrix njMulMatrixCN', 'main:00191280', 'related_different_contract',
     'CVX affine shortcuts omit basis translation terms/assume homogeneous layout; CN publishes VF28..31. Outbreak computes all four XYZW terms per output vector, not the same general4x4 operation.')
case('ps2_NaMatrix.c', 'njCalcPoint njCalcPoint4 njCalcPointCN', 'main:00191AB0', 'related_different_contract',
     'CVX forms affine XYZ with implicit translation weight1; Point4 still ignores source W and writes a full output register with XYZ mask history. Outbreak point helper computes XYZW and divides XYZ by resulting W.')
case('ps2_NaMatrix.c', 'njCalcVector', 'main:001919D0', 'supported_local_role',
     'Same translation-free first3matrix-vector weighted XYZ sum; argument order and CVX NULL/current matrix selection differ. No host FP/state equivalence established.')
case('ps2_NaMatrix.c', 'njUnitVector', 'main:00191D80 main:0017EC98', 'related_different_contract',
     '191D80 is a closer in-place XYZ VRSQRT normalization than17EC98, but CVX additionally returns squared-length times reciprocal length;17EC98 uses VSQRT/VDIV and writes W0. No common full ABI.')
case('ps2_NaMatrix.c', 'njScalor', 'main:00191CC0', 'supported_local_role',
     'Both compute sum of squared XYZ in X/Y/Z VU order, VSQRT/VWAITQ and return scalar length; VU-register clobbers and input staging differ.')
case('ps2_NaMatrix.c', 'njInnerProduct', 'main:00191DF0', 'supported_local_role',
     'Same XYZ component product then X+Y+Z VU reduction and scalar result; different staging/register side effects prevent a whole-state equivalence claim.')
case('ps2_NaMatrix.c', 'njOuterProduct', 'main:00191E50', 'related_different_contract',
     'Both form XYZ cross using VOPMULA/VOPMSUB and capture inputs before output. CVX additionally computes/returns cross magnitude; Outbreak does not. Argument ordering differs.')
case('ps2_NaMatrix.c', 'njSubVector', 'o0:00370420', 'related_different_contract',
     'CVX in-place vd-=vs with EE scalar arithmetic; Outbreak separate output=a1-a2 with VU arithmetic and staged inputs. Ordinary subtraction role only.')
case('ps2_NaColi.c', 'njDistanceP2P', 'main:00191D10', 'supported_local_role',
     'Both compute XYZ Euclidean distance. CVX scalar sums then njSqrt versus Outbreak VU subtraction/square/reduction; operand subtraction direction and FP path differ.')
case('ps2_NaColi.c', 'njCollisionCheckSS', 'o2:0061B330', 'supported_local_role',
     'Both admit squared XYZ distance <= squared sum of radii. CVX embeds radius in NJS_SPHERE; Outbreak takes center pointers and two float arguments and uses EE ACC summation. No structure alias.')
case('ps2_NaMem.c', 'njMemCopy4', 'main:00189A88', 'related_different_contract',
     'Both forward-copy32bit units for ordinary positive counts; CVX checks count before access, Outbreak enters its do-while loop even when count0. Argument source/destination order differs.')
case('ps2_NaTextureFunction.c', 'Ps2MemCopy4', 'main:00189A88', 'related_different_contract',
     'Forward word copy is similar for admitted positive counts; CVX test-before-loop count0 and signed count differ from Outbreak unconditional first iteration and source/destination ABI.')
case('njplus.c', 'npSetMemoryL', 'main:00189C48', 'related_different_contract',
     'Both fill32bit units for positive counts. CVX test-before-loop avoids zero access; Outbreak executes first store unconditionally. Signed/count/ABI constraints remain.')
case('expand.c', 'Expand', 'main:001AF5D0', 'related_different_contract',
     'CVX byte-oriented, LSB-first control stream with short/long negative backrefs and byte output count versus Outbreak MSB-first16bit controls, halfword literal/run tokens and zero-run extension. Not the same decoder.')
case('ps2_texture.c', 'ClutCopy ClutCopy256', 'main:0019E130', 'supported_shared_suboperation',
     'CVX ClutCopy256 swaps entries8..15/16..23 within32-entry groups; ClutCopy selects just the first16positions of that permutation. Owned Outbreak byte table230770 is exactly the same32entry permutation. Outbreak also applies descriptor channel unpack/repack and alpha scaling; its whole function is not a raw CLUT copy.')
case('ps2_pxlconv.c', 'Tim2_Format_Check', 'main:0019E440', 'related_different_contract',
     'CVX parses/mutates a TIM2 image and chooses4/8bit conversion; Outbreak numeric-mode wrapper selects already separated packed page converters and does not parse a TIM2 header here.')
case('ps2_pxlconv.c', 'Conv4to32', 'main:0019E490', 'related_different_contract',
     'Both stage128x128 four-bit pages. CVX validates power-of-two dimensions and copies bounded partial edges into zeroed scratch; Outbreak rounds page counts and unconditionally copies128 rows of64bytes per page from page-padded source.')
case('ps2_pxlconv.c', 'Conv8to32', 'main:0019E7D0', 'related_different_contract',
     'Both stage128x64 eight-bit pages. CVX validates power-of-two dimensions and crops partial edges; Outbreak uses rounded page counts, reads64 full128byte rows per page and forwards page-count output pitch.')
case('ps2_pxlconv.c', 'PageConv4to32', 'main:0019E5D0', 'supported_shared_suboperation',
     'Owned Outbreak230890 equals the complete CVX32entry four-bit block table; owned inverse32bit XY tables match CVX construction. CVX gathers contiguous scratch blocks; Outbreak child gathers directly from a pitched full page and writes pitched rows. Whole-page API/edge behavior not identical.')
case('ps2_pxlconv.c', 'PageConv8to32', 'main:0019E910', 'supported_shared_suboperation',
     'Owned Outbreak230910 equals the complete CVX32entry eight-bit block table; owned inverse32bit XY tables match CVX construction. CVX gathers a contiguous scratch block while Outbreak uses page-pitched input/output. No whole-function alias.')
case('ps2_pxlconv.c', 'BlockConv4to32', 'main:0019E6B0', 'related_different_contract',
     'Both gather paired indexed nibbles into256outputbytes. CVX LUT addresses a contiguous256byte block; Outbreak pointer-selected nibble offsets address a pitched page and advance output by256*pageCount. Address tables are different; not a raw interchangeable block call.')
case('ps2_pxlconv.c', 'BlockConv8to32', 'main:0019E9F0', 'related_different_contract',
     'Both gather256indexed bytes. CVX LUT addresses contiguous block segments; Outbreak tables address page-pitched rows with caller-derived output pitch. Same GS storage task does not make input/output ABI identical.')

FAMILIES = {
 'binfunc.c': ('cvx_binary_format_boundary', 'MLB/MNB basic/chunk model or motion relocation using NJS object/data records and -1 sentinels; Outbreak Clay/track ownership is not this binary ABI.', ['docs/SYMBOLS_CLAY_RESOURCE_CONVERSION.md','docs/SYMBOLS_ANIMATION.md']),
 'expand.c': ('cvx_state_boundary', 'CVX ExpandCtrlBuf initialization, separate from the Outbreak halfword decoder contract.', ['docs/SYMBOLS_RENDER_STATE_CONTROLLER.md']),
 'MdlPut.c': ('cvx_actor_wrapper', 'CVX BH_PWORK/ML_WORK/O_WORK, camera and Ninja chunk/basic draw traversal; no admitted Outbreak actor-layout or callback ABI counterpart.', ['docs/SYMBOLS_ANIMATION.md','docs/SYMBOLS_CLAY_RESOURCE_CONVERSION.md']),
 'Motion.c': ('cvx_actor_wrapper', 'CVX BH_PWORK/NJS_MDATA2_MOD motion,16.16 frame and object angle/state contracts; Outbreak model tracks/float-frame curve sampling are a different layer.', ['docs/SYMBOLS_ANIMATION.md','docs/recvx-crosscheck/ENGINE_SECOND_PASS.md']),
 'njloop.c': ('cvx_application_shell', 'Calls CVX njUserInit/Main/Exit and empty njWaitVSync; the shell does not establish an Outbreak pacing or application-loop contract.', ['docs/recvx-crosscheck/ENGINE_BOUNDARIES.md']),
 'njplus.c': ('cvx_model_format_boundary', 'CVX global np state and Ninja chunk/model/skin structures; no admitted Outbreak Clay model or skinning ABI counterpart.', ['docs/SYMBOLS_CLAY_RESOURCE_CONVERSION.md','docs/recvx-crosscheck/ENGINE_SECOND_PASS.md']),
 'ps2_NaColi.c': ('generic_geometry_unpaired', 'Reusable geometric operation exists, but no same tolerance, degeneracy, output and structure contract has been established in the owned Outbreak catalogue; do not transfer a name from shape alone.', ['docs/SYMBOLS_COLLISION_GRID.md']),
 'ps2_NaDebugFontFunction.c': ('empty_reference_body', 'No implementation body is supplied by this definition; a matching debug-font API or absence in Outbreak cannot be inferred.', []),
 'ps2_NaDraw.c': ('cvx_packet_state_boundary', 'CVX NJS polygon/texture records, Ps2AddPrim ordering-table packet and selected texture/fog/transparency state; Outbreak uses different Clay/native submission ownership.', ['docs/recvx-crosscheck/ENGINE_BOUNDARIES.md','docs/SYMBOLS_RENDER_PALETTE_PACKET_VARIANTS.md']),
 'ps2_NaDraw2D.c': ('cvx_packet_state_boundary', 'CVX screen/depth, fixed-point conversion and Ps2AddPrim2D contracts; shared GS vocabulary alone does not admit an Outbreak packet-builder match.', ['docs/SYMBOLS_RENDER_MATH.md']),
 'ps2_NaFog.c': ('cvx_fog_state_boundary', 'CVX128-entry fog table/density and state bindings; no admitted same-table/normalization Outbreak counterpart.', ['docs/SYMBOLS_RENDER_PROGRAM_SELECTION.md']),
 'ps2_NaGraphics3D.c': ('cvx_packet_state_boundary', 'CVX view-cone planes or projected primitive Ps2AddPrim3D path; no compatible Outbreak plane/packet or clipping contract established.', ['docs/SYMBOLS_RENDER_MATH.md','docs/recvx-crosscheck/ENGINE_BOUNDARIES.md']),
 'ps2_NaMath.c': ('generic_math_unpaired', 'Available reusable arithmetic, but no owned Outbreak counterpart with admitted full input/output/state/domain contract was established; original name remains untransferred.', ['docs/SYMBOLS_RENDER_MATH.md','docs/SYMBOLS_ANIMATION.md']),
 'ps2_NaMatrix.c': ('cvx_matrix_state_boundary', 'CVX current matrix-stack/VU constant or scratch-register/projection contract is not an admitted Outbreak matrix or scratchpad interface.', ['docs/SYMBOLS_RENDER_MATH.md','docs/SYMBOLS_RESIDENT_VU0_VECTOR_MATRIX_ARITHMETIC.md']),
 'ps2_NaMem.c': ('generic_memory_unpaired', 'Ordinary forward byte copying is reusable, but no fully admitted same zero/count/overlap/result ABI was established; not an SDK identity claim.', ['docs/SYMBOLS_DISPATCH.md']),
 'ps2_NaSprite.c': ('cvx_packet_state_boundary', 'CVX NJS sprite/texture records and DMA/GIF/GS packet emission; no admitted Outbreak sprite-layout/submission counterpart.', ['docs/recvx-crosscheck/ENGINE_BOUNDARIES.md']),
 'ps2_NaSystem.c': ('cvx_platform_state_boundary', 'CVX double-buffer, ordering-table, texture/blend/system or interrupt callback state; cannot substitute for Outbreak launch, pacing or GS ownership.', ['docs/recvx-crosscheck/ENGINE_BOUNDARIES.md']),
 'ps2_NaTextureFunction.c': ('cvx_texture_allocator_boundary', 'CVX NJS_TEXMEMLIST/TIM2 extension ring, global-index/bank/refcount and texture-buffer ownership; shared TIM2 is insufficient for an Outbreak allocator ABI.', ['docs/SYMBOLS_TEXTURE_RESIDENCY_AND_PACKED_PAGES.md']),
 'ps2_NaView.c': ('cvx_view_state_boundary', 'CVX current screen/view globals, clip ranges and VU-register publication; Outbreak projection setup has separate inputs/state and conventions.', ['docs/SYMBOLS_RENDER_MATH.md']),
 'ps2_NinjaCnk.c': ('cvx_chunk_state_boundary', 'CVX NJS chunk command/lighting/draw-mode/strip layouts and callback tables; not an Outbreak Clay/material/VIF chain contract.', ['docs/SYMBOLS_CLAY_RESOURCE_CONVERSION.md','docs/SYMBOLS_RENDER_PROGRAM_SELECTION.md']),
 'ps2_Ninjapad.c': ('cvx_platform_wrapper', 'Only forwards the port to pdGetPeripheral; underlying pad implementation belongs to the separately reviewed platform scope, not a Ninja-specific Outbreak alias.', []),
 'ps2_NinjaPtcl.c': ('cvx_packet_state_boundary', 'CVX particle globals and NJS records projected into Ps2AddPrim3D; no admitted Outbreak particle callback/state ABI.', ['docs/recvx-crosscheck/ENGINE_BOUNDARIES.md']),
 'ps2_pxlconv.c': ('generic_gs_format_unpaired', 'Meaningful indexed4/8bit-to32bit GS block/page storage rearrangement, not color expansion. No owned Outbreak implementation with the same tables, page sizes and valid-dimension contract admitted.', ['docs/SYMBOLS_TEXTURE_IMAGE_LOADING.md']),
 'ps2_texture.c': ('cvx_texture_wrapper', 'CVX PVP/TIM2/NJS texture-list, game object and save-buffer ownership; Outbreak descriptor/registry ownership is different.', ['docs/SYMBOLS_TEXTURE_RESIDENCY_AND_PACKED_PAGES.md']),
 'ps2_Vu1Scissor2.c': ('cvx_vu_clip_state_boundary', 'CVX VU register state/node layout or exact VU0 microprogram call entry is required; no identical admitted Outbreak program/state interface.', ['docs/recvx-crosscheck/ENGINE_SECOND_PASS.md']),
 'ps2_Vu1Strip.c': ('cvx_vu_strip_state_boundary', 'CVX VU1_STRIP_BUF/PRIM_BUF, fixed register/clip/material state and Ps2AddPrim3D emission; no exact Outbreak microprogram or native-strip contract established.', ['docs/SYMBOLS_RENDER_PALETTE_PACKET_VARIANTS.md','docs/recvx-crosscheck/ENGINE_SECOND_PASS.md']),
}

def dispositions(result):
    for row in result['definitions']:
        file = pathlib.Path(row['file']).name
        source = (REF / row['file']).read_bytes().decode()
        body = source[row['body_start']:row['end_exclusive']]
        clean = mask(body)
        row['signature'] = re.sub(r'\s+', ' ', source[row['signature_start']:row['body_start']]).strip()
        calls = sorted(set(re.findall(r'\b([A-Za-z_]\w*)\s*\(', clean)) - {'if','for','while','switch','sizeof','return','volatile','__volatile__','asm','__asm__','int','float','void'})
        fields = sorted(set(re.findall(r'\b[A-Za-z_]\w*(?:(?:->|\.)[A-Za-z_]\w*)+', clean)))
        row['source_facts'] = {'call_or_macro_tokens': calls, 'member_expressions': fields,
                               'contains_asm': bool(re.search(r'\b(?:asm|__asm__)\b',clean)),
                               'contains_control_flow': bool(re.search(r'\b(?:if|for|while|switch|goto)\b',clean))}
        verdict, reason, evidence = FAMILIES[file]
        if row['implementation_status'] == 'empty':
            verdict, reason = 'empty_reference_body', 'Empty source body. No operation is available to compare; neither an original no-op nor an Outbreak equivalent is inferred from this alone.'
        if row['id'] in CASES:
            ids, verdict, reason = CASES[row['id']]
            row['outbreak_comparisons'] = ids
        if file == 'njplus.c' and row['symbol'] in ('npCollisionCheckCC','npCollisionCheckCCEx','npCollisionCheckSC','npDistanceP2C'):
            verdict, reason = 'generic_geometry_unpaired', 'CVX capsule contact/correction uses NJS sphere/line/capsule records, normalized directions and endpoint branching. No same correction/output/degeneracy contract admitted in Outbreak; no alias from collider names.'
        if file == 'njplus.c' and row['symbol'] in ('npSetMemory','npCopyMemory'):
            verdict, reason = 'generic_memory_unpaired', 'Test-before-loop forward byte fill/copy exists; no full same count, alias, failure or result ABI admitted. This is a generic role, not a library identity.'
        if file == 'Motion.c' and row['symbol'].startswith('Ang'):
            verdict, reason = 'generic_angle_conversion_unpaired', 'Actual trig/atan2f/asinf conversion between turn16 Euler orders; no Outbreak full conversion contract admitted. Rotation-order names do not prove matrix/state equivalence.'
        row['implementation_detail'] = ('inline_ee_vu_source' if row['source_facts']['contains_asm'] else ('empty_reference_body' if row['implementation_status']=='empty' else 'c_operations'))
        if row['id'] == 'ps2_NinjaCnk.c:njDrawModel':
            row['implementation_detail'] = 'pointer_sink_only'
            reason = 'Actual body only stores vpDummy=model; it supplies no basic-model drawing operation. Cannot use its callsites as evidence of an implemented renderer or Outbreak draw counterpart.'
        if row['id'] == 'ps2_NaSystem.c:njChangeSystem':
            row['implementation_detail'] = 'diagnostic_only'
            reason = 'Actual body only prints ChangeSystem; no display-mode change implementation or Outbreak equivalent is established.'
        if row['id'] == 'ps2_NaTextureFunction.c:njCalcTexture':
            row['implementation_detail'] = 'constant_return_only'
            reason = 'Actual body returns literal1048576 regardless flag; no texture computation, byte validation or Outbreak equivalent is established.'
        row['disposition'] = verdict
        row['reason'] = reason
        row['evidence'] = [f'https://github.com/AshfordFamily/recvx-decomp/blob/{PIN}/{row["file"]}#L{row["line_start"]}'] + evidence
        row['comparison_depth'] = ('direct_full_body_contract' if row['id'] in CASES else 'source_shape_and_ownership_boundary')
    result['counts'] = {'files': len(result['files']), 'definitions': len(result['definitions']),
                        'implementation':dict(collections.Counter(r['implementation_status'] for r in result['definitions'])),
                        'disposition':dict(collections.Counter(r['disposition'] for r in result['definitions'])),
                        'direct_comparison_definitions':sum(r['id'] in CASES for r in result['definitions'])}
    assert not any(r['disposition']=='pending' for r in result['definitions'])

def audit_outbreak(result):
    sys.path.insert(0, 'tools/function_index')
    from index import Elf
    identity = json.loads(pathlib.Path('tools/function_index/overlay_identities.json').read_text())
    elf_path = pathlib.Path('game_data/SLUS_207.65')
    assert sha(elf_path.read_bytes()) == identity['elf_sha256']
    elf = Elf(str(elf_path))
    keys = {key for row in result['definitions'] for key in row['outbreak_comparisons']}
    # Retain the previous engine comparison's12 complete original bodies.
    prior = json.loads(pathlib.Path('build-function-index/recvx-engine-second-pass-audit.json').read_text())
    keys.update(f'{r["image"]}:{int(r["start"],16):08X}' for r in prior['entries'])
    images = {}
    for im in identity['images']:
        if any(key.startswith(im['image']+':') for key in keys):
            raw = pathlib.Path(f'build-function-index/owned-overlays/{im["image"]}.bin').read_bytes()
            assert sha(raw)==im['imageSha256']
            images[im['image']] = (im['base'], raw)
    db = sqlite3.connect('file:build-function-index/index.sqlite?mode=ro',uri=True)
    db.row_factory = sqlite3.Row
    rows=[]
    for key in sorted(keys):
        image,address=key.split(':');start=int(address,16)
        f=db.execute('SELECT * FROM functions WHERE image=? AND start=?',(image,start)).fetchone()
        assert f
        path=pathlib.Path(f['source']);words={}
        for m in re.finditer(r'// 0x([\da-f]+): 0x([\da-f]+)\s+',path.read_text(),re.I):
            pc,word=int(m[1],16),int(m[2],16)
            if start<=pc<f['end']:
                assert pc not in words or words[pc]==word
                words[pc]=word
        zero=0
        for pc in range(start,f['end'],4):
            raw=elf.read(pc,4) if image=='main' else images[image][1][pc-images[image][0]:pc-images[image][0]+4]
            assert raw is not None and len(raw)==4
            word=int.from_bytes(raw,'little')
            if pc in words: assert words[pc]==word,(key,hex(pc))
            else: assert word==0,(key,hex(pc));zero+=1
        rows.append({'id':key,'source':f['source'],'start':start,'end':f['end'],
                     'source_sha256':sha(path.read_bytes()),'verified_comments':len(words),'omitted_zero_words':zero})
    permutation=list(elf.read(0x230770,32))
    assert permutation==list(range(8))+list(range(16,24))+list(range(8,16))+list(range(24,32))
    # Compare literal storage-layout data, not executable code or a runtime replay.
    pxl=(BASE/'ps2_pxlconv.c').read_bytes().decode()
    table_rows=[]
    for name,address in [('block_table4',0x230890),('block_table8',0x230910),('block_table32',0x230910)]:
        m=re.search(r'\b'+name+r'\[32\]\s*=\s*\{([^}]+)\}',pxl)
        assert m
        values=[int(x,0) for x in re.findall(r'0x[0-9a-fA-F]+|\d+',m[1])]
        raw=elf.read(address,128);owned=list(struct.unpack('<32I',raw))
        assert values==owned
        table_rows.append({'cvx_table':name,'outbreak_address':hex(address),'values':owned,'owned_bytes_sha256':sha(raw)})
    h=[None]*32;v=[None]*32
    for i,block in enumerate(table_rows[-1]['values']):h[block]=i%8;v[block]=i//8
    assert h==list(struct.unpack('<32I',elf.read(0x230790,128)))
    assert v==list(struct.unpack('<32I',elf.read(0x230810,128)))
    result['outbreak_evidence']={'elf_sha256':identity['elf_sha256'],'complete_catalogue_bodies':rows,
       'verified_comments':sum(r['verified_comments'] for r in rows),'omitted_zero_words':sum(r['omitted_zero_words'] for r in rows),
       'conflicts':0,'omitted_nonzero_words':0,'clut_permutation':{'address':'0x00230770','bytes':permutation,'sha256':sha(bytes(permutation))},
       'gs_block_tables':table_rows,'inverse32bit_xy_tables':{'x_address':'0x230790','y_address':'0x230810','verified':True}}

def reconcile(result):
    shared=json.loads(pathlib.Path('build-function-index/recvx-complete-source-inventory.json').read_text())
    paths={f['file'] for f in result['files']}
    a={(r['file'],r['symbol'],r['line_start'],r['body_sha256']) for r in result['definitions']}
    b={(f['path'],r['symbol'],r['start_line'],r['body_sha256']) for f in shared['files'] if f['path'] in paths for r in f['functions']}
    assert a==b,(a-b,b-a)
    assert not any(f['assembly_placeholders'] for f in shared['files'] if f['path'] in paths)
    result['independent_inventory_reconciliation']={'definitions':len(a),'missing':0,'extra':0,'different_body_hashes':0,'assembly_placeholders':0}
    for row in result['definitions']:
        for evidence in row['evidence'][1:]:
            assert pathlib.Path(evidence).exists(),evidence

def write_note(result):
    counts=result['counts'];audit=result['outbreak_evidence']
    lines=['# Complete Ninja, math and graphics reference scope', '',
      'Static cross-check, 2026-11-05. No target execution, game, build, attachment, live memory, rendering or decompression replay was performed. Original reference pin: `'+PIN+'`; enhanced-port context pin: `'+result['enhanced_context_commit']+'`.', '',
      'All **26 admitted source files and397 C definitions** have a recorded implementation status and applicability disposition. The independent whole-tree inventory reconciles397/397 by file, symbol, source line and complete body hash, with no missing/extra definitions or assembly placeholders in this scope. There are **371 nonempty bodies and26 empty bodies**, zero declarations-only bodies and zero INCLUDE_ASM placeholders here. Empty reference code is unavailable semantic evidence; it is not silently treated as an original no-op or an Outbreak match.', '',
      'This is exhaustive **source inventory and disposition** coverage of the listed scope. It is not a claim that every generic utility has an identified Outbreak equivalent, that every nonempty source body is a verified matching decompilation, or that every graphics function was proved semantically equivalent. The machine-readable ledger explicitly separates `direct_full_body_contract` comparisons from `source_shape_and_ownership_boundary` reviews. Unpaired generic operations remain unresolved rather than becoming invented aliases.', '',
      'The replayable static review is [review_recvx_ninja_complete_scope.py](../../tools/function_index/review_recvx_ninja_complete_scope.py). Its local output `build-function-index/recvx-ninja-complete-scope.json` records raw file hashes, exact UTF-8 body/definition offsets and hashes, signature/body line bounds, implementation detail, call/macro tokens, member expressions, disposition/reason, owned Outbreak comparison IDs and evidence paths. Source is ASCII in these files, so character and UTF-8 byte offsets coincide. No shared catalogue/index was written.', '',
      f'**{counts["direct_comparison_definitions"]} CVX definitions have direct contract comparisons** against {len(audit["complete_catalogue_bodies"])} complete owned Outbreak catalogue bodies, including the earlier12 reviewed bodies. The new word audit finds **{audit["verified_comments"]} matching original instruction comments, {audit["omitted_zero_words"]} omitted zero words, zero conflicts and zero omitted nonzero words**. This verifies source provenance; it does not simulate the programs. Literal GS table comparisons are data-only arithmetic.', '',
      '## Findings that change how the references should be used', '',
      '- **Positive shared GS storage evidence:** every entry of CVX\'s32-entry `block_table4`/`block_table8` equals owned Outbreak tables `0x230890`/`0x230910`. CVX\'s complete inverse32-bit block-coordinate construction equals owned `0x230790`/`0x230810`. CVX `ClutCopy256` and Outbreak `0x230770` also share the complete32-entry palette permutation; `ClutCopy` uses only its first16 selected entries. These are supported storage-format suboperations, not proof of shared model, actor, texture allocator or rendering-engine ABIs.',
      '- **Page-conversion contracts differ:** CVX `Conv4to32`/`Conv8to32` validate power-of-two sizes and copy partial edges into zero-initialized page scratch. Outbreak `0x19E490`/`0x19E7D0` compute rounded page counts and read full128x128 four-bit or128x64 eight-bit pages. Its inner block gathers address pitched full pages and pitched output; CVX first gathers contiguous blocks. A caller supplying tightly packed partial pages cannot interchange them without an adapter. Neither path expands palette indices into RGBA colours.',
      '- **More genuine local math matches:** square root (`njSqrt`/main`0x192220`), XYZ length (`njScalor`/`0x191CC0`), dot product (`njInnerProduct`/`0x191DF0`), distance (`njDistanceP2P`/`0x191D10`),64-byte load-before-store copy (`njCopyMatrix`/`0x191500`), and squared sphere overlap (`njCollisionCheckSS`/o2`0x61B330`) have supported local roles. Different ABI, EE/VU staging, floating-point path and register/state effects are preserved in the JSON, not hidden behind a transferred original name.',
      '- **Closer normalization lead:** main`0x191D80` is the in-place XYZ VRSQRT form and is closer to `njUnitVector` than the previously compared quadword helper `0x17EC98`. CVX also returns the original length as squared-length times reciprocal length; Outbreak does not implement that same return contract. The existing labels remain correct.',
      '- **Concrete negative examples:** CVX `njFraction` is `n-floorf(n)`, unlike Outbreak`0x192200`/`0x10A2F0`\'s signed fractional part (`-1.5` gives `+0.5` versus `-0.5` by their arithmetic). CVX `njTransposeMatrix` stores full scratch quadwords after XYZ-only assignments; Outbreak`0x1911D0` explicitly preserves destination W. CVX `njMultiMatrix`/`njMulMatrixCN` have affine shortcuts and current/register state; main`0x191280` computes the complete four-term XYZW product. CVX `njCalcPoint4` ignores source W for translation and masks XYZ arithmetic, unlike a general4D transform.',
      '- **Compression is different:** complete CVX `Expand` reads byte controls LSB-first and emits bytes using short/long backreferences. Complete Outbreak`0x1AF5D0` reads MSB-first16-bit control words and emits halfwords with packed length/distance plus extended zero runs. No decoder identity follows from both being LZ-like.',
      '- **Misleading names are retained as observations:** CVX `njDrawModel` only assigns `vpDummy=model`; `njChangeSystem` only prints. `njCalcTexture` returns literal1048576. `njWaitVSync` is empty, while actual CVX swap pacing is in `Ps2SwapDBuff`. These definitions are explicitly distinguished from usable draw, mode-change, allocation or pacing implementations.', '',
      'No demonstrated error requiring a canonical Outbreak math/graphics mapping edit was found. No names or structures were promoted. Existing evidence remains qualified in [ENGINE_SECOND_PASS.md](ENGINE_SECOND_PASS.md), [render math](../SYMBOLS_RENDER_MATH.md), [image loading](../SYMBOLS_TEXTURE_IMAGE_LOADING.md), [texture residency](../SYMBOLS_TEXTURE_RESIDENCY_AND_PACKED_PAGES.md), [Clay conversion](../SYMBOLS_CLAY_RESOURCE_CONVERSION.md) and [animation](../SYMBOLS_ANIMATION.md).', '',
      '## Scope and implementation distinctions', '',
      '`implemented` below means actual nonempty C/EE/VU operations exist, not that the body is portable C or verified equivalent. Detail `pointer_sink_only`/`diagnostic_only`/`constant_return_only` marks narrower bodies. `empty` supplies no operation. No declarations-only or assembly-placeholder definitions were found in this26-file scope, although they occur elsewhere in the reference tree.', '',
      'Boundary dispositions identify concrete CVX object/state/packet contracts rather than concluding that similarly named Outbreak systems do not exist. `generic_*_unpaired` means no admitted full counterpart was established; it is an honest unknown. `supported_local_role` and `supported_shared_suboperation` do not grant SDK symbol identity. `related_different_contract` records an actual candidate and a demonstrated difference.', '',
      '| File | Definitions / nonempty / empty | Raw source SHA-256 |', '| --- | --- | --- |']
    for f in result['files']:
        rows=[r for r in result['definitions'] if r['file']==f['file']]
        lines.append(f'| `{pathlib.Path(f["file"]).name}` | {len(rows)} / {sum(r["implementation_status"]=="implemented" for r in rows)} / {sum(r["implementation_status"]=="empty" for r in rows)} | `{f["sha256"]}` |')
    lines += ['', '## Per-file and symbol disposition ledger', '',
      'Each link is pinned source at the signature line; the following line bounds cover the complete definition. Full body hashes are reproduced to make the Markdown independently reviewable. Full byte bounds, definition hashes, individual reasons and feature evidence are in the JSON. Numeric Outbreak IDs remain image-qualified; an ID in a related row is a comparison target, not an alias.', '']
    for f in result['files']:
        lines += ['### '+pathlib.Path(f['file']).name,'',FAMILIES[pathlib.Path(f['file']).name][1],'',
          '| Symbol / complete source lines | Implementation / detail | Disposition; Outbreak comparison IDs | Complete body SHA-256 |', '| --- | --- | --- | --- |']
        for r in result['definitions']:
            if r['file']!=f['file']:continue
            ids=', '.join('`'+i+'`' for i in r['outbreak_comparisons']) or 'No admitted counterpart; see individual reason in JSON.'
            lines.append(f'| [{r["symbol"]}]({r["evidence"][0]}) {r["line_start"]}–{r["line_end"]} | {r["implementation_status"]}; {r["implementation_detail"]} | `{r["disposition"]}`; {ids} | `{r["body_sha256"]}` |')
        lines.append('')
    lines += ['## Remaining limits', '',
      'This completes the declared source enumeration and every-symbol applicability ledger, including excluded CVX game wrappers and empty definitions. It does not settle all generic unpaired geometry, spline, angle-conversion or memory functions. A full replacement admission still requires the Outbreak caller domain, exact image ownership, register/FP/memory side effects and controlled verification. Host renderer changes, performance claims and asset compatibility were not tested.']
    note='\n'.join(lines)+'\n'
    for old,new in [('and397','and 397'),('reconciles397/397','reconciles 397/397'),('and26','and 26'),('this26-file','this 26-file'),('earlier12','earlier 12'),("CVX's32-entry","CVX's 32-entry"),('inverse32-bit','inverse 32-bit'),('complete32-entry','complete 32-entry'),('first16 selected','first 16 selected'),('full128x128','full 128x128'),('or128x64','or 128x64'),('),64-byte','), 64-byte'),('main`','main `'),('Outbreak`','Outbreak `'),('o2`','o2 `'),('general4D','general 4D'),('MSB-first16-bit','MSB-first 16-bit'),('literal1048576','literal 1048576')]:
        note=note.replace(old,new)
    pathlib.Path('docs/recvx-crosscheck/NINJA_COMPLETE_SCOPE.md').write_text(note,encoding='utf-8')

if __name__ == '__main__':
    assert subprocess.check_output(['git','-C',str(REF),'rev-parse','HEAD'],text=True).strip()==PIN
    assert not subprocess.check_output(['git','-C',str(REF),'status','--porcelain','--untracked-files=no'],text=True).strip()
    result = build()
    dispositions(result)
    audit_outbreak(result)
    reconcile(result)
    write_note(result)
    dest = pathlib.Path('build-function-index/recvx-ninja-complete-scope.json')
    dest.write_text(json.dumps(result, indent=2) + '\n')
    print('files', len(result['files']), 'definitions', len(result['definitions']))
    print(dict(collections.Counter(r['implementation_status'] for r in result['definitions'])))
    for file in result['files']:
        rows = [r for r in result['definitions'] if r['file'] == file['file']]
        print(pathlib.Path(file['file']).name, len(rows), dict(collections.Counter(r['implementation_status'] for r in rows)))

