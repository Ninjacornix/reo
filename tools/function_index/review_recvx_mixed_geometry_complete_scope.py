#!/usr/bin/env python3
"""Offline per-definition boundary audit of CVX collision/facial utilities.

Reads pinned reference sources and owned instruction bytes. Never executes a
guest function, constructs a game process, or mutates shared mapping outputs.
"""
import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import re
import sqlite3
import struct

from index import Elf
from recvx_scope_inventory import function_records, PIN
from review_recvx_audio_second_pass import SHA

ROOT = Path(__file__).resolve().parents[2]
BASE = 'src/ps2/veronica/prog/'
FILES = ('hitchk.c', 'hitchkl.c', 'rutchk.c', 'face.c', 'face_bh.c')


def dispositions():
    rows = {}

    def add(file, classification, text, candidates=''):
        for line in text.strip().splitlines():
            name, role = (x.strip() for x in line.split('|', 1))
            assert (file, name) not in rows
            rows[file, name] = dict(
                classification=classification,
                status='no-demonstrated-counterpart',
                outbreak_ids=[],
                searched_candidates=candidates.split(),
                comparison=role,
            )

    add('hitchk.c', 'reference-game-state-format', '''
bhCheckWall | Resolves actor movement against combined room walp and dynamic mwalp ATR_WORK sets; room height/floor elevations and player/effect/stair flags participate. BH_PWORK/ATR_WORK ownership and response branches are reference-game contracts, not the Outbreak triangle-list ABI.
bhCheckWallEx | Extended room/dynamic ATR wall response mutates actor/player movement and effect flags; uses rom->h and removes temporary step walls. No whole Outbreak actor/ATR layout correspondence established.
bhCheckWall2Box | Actor box response against room/dynamic ATR walls, with floor-height and signed shape dimensions. Explicit actor and room ownership prevents a generic box-box function identity from its name.
bhCheckWallType | Returns an admitted room/dynamic ATR wall record after type/height/shape gates. Outbreak grid/triangle queries use another record/filter representation, not a demonstrated identical wall-type enum.
bhCheckWallType2 | Variant room/dynamic ATR shape admission using actor radius/height and bounding-sphere/triangle helpers. Return-record and room height contracts remain CVX-specific.
bhCheckWallRefAngle | Full wall response traverses room/dynamic ATR records and calculates reference angles after shape-specific adjustments. Not a standalone angle or line-distance library helper.
bhSetWallRefAngle | Single supplied ATR wall response still uses rom->h, actor fields and CVX shape/attribute encoding. No correspondence to an Outbreak angle-control field is inferred.
bhGetGroundPosition | Searches room/dynamic ATR walls for ground height and publishes selected record in sys->htp; room height fallback and shape IDs are part of its complete contract.
bhCheckInnerTriangle | ATR_WORK signed width/depth, id-selected triangular footprint, actor width/height and rom->h fallback; may delegate expanded footprint to bhCheckInnerP4. This is not arbitrary three-vertex point containment.
bhCheckInnerTriangle2 | ATR_WORK triangular footprint variant using separate box extents plus vertical overlap and rom->h fallback. Name similarity does not transfer generic triangle API or record layout.
bhCheckInnerTriangle3 | ATR_WORK id-selected triangular footprint plus vertical interval using hp->h or rom->h. Consumes encoded bounding shape rather than three explicit XYZ vertices.
bhCheckBox | Mutates query position/angle through CVX ATR dimensions, corner flags, height fallback and radius response. Not equivalent to a stateless AABB predicate.
bhCheckBox2Box | ATR box/actor extents response with signed dimensions and rom->h fallback. Complete record/response contract differs from Outbreak triangle geometry helpers.
bhCheckExmAtari | Scans room/dynamic etc ATR interactions and mutates player modes, doors, camera, input, messages and interaction flags. Geometry is embedded in CVX gameplay state transitions.
bhSetUseKaidanFlag | Binds actor kdnp/kdnidx to room/dynamic stair ATR records and changes paired record flags. Reference stair ownership/index convention is not a reusable geometry API.
bhClrUseKaidanFlag | Uses actor stored stair pointer/index to clear paired room/dynamic ATR flags. No Outbreak actor offset/flag identity follows.
bhSetDansaLimitAtari | Scans step ATR records and appends temporary barriers to sys->mwalp while changing actor step state and sys->dla_n. This is reference room-state construction, not generic polygon generation.
bhCheckDansaAtari | Returns an active type2 step ATR matching floor and inclusive XZ bounds from room/dynamic etc sets. Specific type/parameter encoding remains reference-only.
bhCheckFloorP | Floor/step response combines actor/player state, room/dynamic floor ATRs, sound/effect fields and sys callback flags. No whole Outbreak collision/actor contract established.
bhCheckDansa | Clears/sets actor stflg bit20000 from room/dynamic step ATR and actor mode gates. Not a standalone geometric containment predicate.
bhCheckFloorSound | Selects prm0 sound value from type1 floor ATRs, with actor stflg10 and attr1 priority behavior; floor tables and attribute semantics belong to CVX.
bhCheckFloorEnemy | Returns first active type2 floor ATR containing XZ at selected floor; room/dynamic list layout is a concrete reference format boundary.
bhCheckFloorEffect | Returns first active type3 floor ATR containing XZ at selected floor. Shared box arithmetic does not identify an Outbreak floor-effect record.
bhCheckWater | Selects active type3/prm0=1 floor ATR by inclusive XYZ volume; its water classification comes from CVX floor format, not a shared triangle type enum.
bhCheckL2Water | Tests line against upper Y plane of type3/prm0=1 floor ATRs with forward strict dot, segment-distance gate and XZ bounds; returns ATR pointer. Format/list ownership differs from raw plane helpers.
bhResetAtariAttr | Rewrites wall/etc/floor ATR attributes across room and dynamic tables, including ceil-based room/floor interpretation. No generic geometry or Outbreak record correspondence.
bhCheckPlayer | Actor/player cylindrical push response reads BH_PWORK flags, offsets and EXP_WORK pose, mutates both actor coordinates/status. Not a reusable vector or distance function identity.
bhCheckEnemies | Iterates sys enemy work array, tests BH_PWORK cylinders and averages accepted displacement candidates. Actor table/layout and admission flags are reference-game contracts.
bhCheckWallAttrB89 | ATR attribute bits and sys->st_flg choose wall admission. No cross-game identity for those numeric bits is demonstrated.
''', 'o2:579300 o2:6169B0 o2:616BD0 o2:616CC0')

    add('hitchk.c', 'geometry-utility', '''
bhCheckInnerP4 | Pure four-point X/Y scanline footprint: requires caller ordering, accepts Y in [p0.y,p3.y), chooses three Y bands, swaps interpolated X endpoints and accepts [min,max). Outbreak o0 triangle/fan helpers use oriented areas/winding and inclusive triangle boundaries; no complete same ordered-quad half-open body demonstrated.
''', 'o0:370AC0 o0:370B00 o0:370C70')

    add('hitchkl.c', 'reference-game-state-format', '''
bhCollisionCheckLine | Scans room walp plus sys dynamic mwalp ATRs and dispatches full shape-specific line routine. Return ATR and input endpoint mutation belong to CVX room format.
bhCollisionCheckLine2 | Variant admission over combined room/dynamic wall ATRs before same line-shape dispatcher. No transferred shape flags or Outbreak grid-cell correspondence.
bhCollisionCheckLine3 | Further room/dynamic wall admission variant; complete wrapper depends on ATR flags and CVX room list ownership, not just a generic segment loop.
bhCollisionCheckLineMain | Shape/type-dispatching ATR line collision with hp->h fallback to rom->h, reconstructed faces and CVX attributes. The Outbreak precomputed triangle/plane record and one-sided gates differ.
''', 'o2:579300 o2:6169B0')

    add('hitchkl.c', 'geometry-utility', '''
bhCollisionCheckL2PL | Explicit polygon, but front-face dot<0, forward dot>=0, strict distance<segment length and bhInOutCheck gates precede mutation of p2 and global PLANE. Outbreak579300 instead uses optional side byte, precomputed triangle plane, strict opposite endpoint direction, angle-sum containment and accepted0.001 backoff; not the same full function.
bhInOutCheck | Related oriented-edge halfspace predicate: num<3 returns0, optional reference normal else computed normal, every closed polygon edge rejects n dot(edge cross(point-vertex))<0. Outbreak616BD0 fixes three edges and normalizes each cross via370640 before dot; related finite nondegenerate triangular mechanics, different arity, fallback and degenerate/NaN behavior. No original API-name identity established.
bhCollisionCheckL2XZPL | Builds signed Y-normal plane, calls njDistanceL2PL and tests inclusive XZ rectangle, then changes p2 and global PLANE. No additional explicit forward/length gate locally. Outbreak6169B0 returns side classes and has asymmetric zero-denominator writes; no same rectangle/global-result API.
bhCollisionCheckL2XYPL | Signed Z-normal plane with inclusive XY rectangle and global PLANE/p2 mutation; no local additional forward/length gate. Related plane arithmetic does not supply an identical Outbreak complete body.
bhCollisionCheckL2YZPL | Signed X-normal plane with inclusive YZ rectangle and global PLANE/p2 mutation; no local additional forward/length gate. Outbreak plane crossing helper has another output/classification protocol.
''', 'o2:579300 o2:6169B0 o2:616BD0 o2:616CC0 o0:370640')
    rows['hitchkl.c', 'bhInOutCheck'].update(status='version-different', outbreak_ids=['o2:616BD0'])

    add('hitchkl.c', 'reference-ninja-model-format', '''
bhCollisionCheckL2MDL | Ninja NJS_CNK_MODEL vlist/plist interpretation, transformed center/radius broadphase, aligned sys->memp scratch and polygon index traversal. Outbreak Clay/raw-mesh formats and scratch/resource ownership are different; shared matrix/line calls do not identify the mesh parser.
''', 'main:18A260 main:1A45A0 o2:579300')
    add('hitchkl.c', 'reference-global-hit-state', '''
bhGetHitCollisionNormal | Copies three components from file-global PLANE written by the line helpers. Outbreak579300/6169B0 publish via caller outputs; no connected same global hit-state getter/setter contract demonstrated. Generic three-float copy is insufficient function identity.
''', 'o2:579300 o2:6169B0')

    add('rutchk.c', 'reference-game-state-format', '''
bhCheckRoute | Resolves current/next route box IDs, indexes rom->ruttp[rut_n*next+current], and writes selected rom->rutp ATR box center. Reference room route lookup/format, not a generic graph solver.
bhCheckRouteID | Scans rom->rutp ATR boxes with inclusive XYZ bounds and returns byte ordinal orFF. No Outbreak route table or ATR layout correspondence inferred from shared containment arithmetic.
''')
    add('face.c', 'reference-game-state-format', '''
bhInitMask | Allocates actor exp0/exp1 MASK_WORK/exp2 LIP_WORK, binds actor mskp/ML_WORK and hardcoded parts6..14, initializes face/lip state. No complete Outbreak actor extension or facial-part correspondence established.
bhControlMask | Actor exp0 state machine, sys game/loop gates, frame/lip selection and hardcoded jaw/eye/tongue object angles. Ninja facial parameter processing is embedded in CVX actor scheduling.
bhSetMask | Selects size-prefixed sys->mspp mask entry with sentinel/actor ID rules and stages actor exp0 frame/pointer/flags. No demonstrated Outbreak serialized facial block format identity.
bhSetLip | Selects size-prefixed sys->lspp lip entry into actor exp0/exp2 state with sentinel rules. No transferred lip index or actor layout.
''', 'main:18A260 main:1A45A0')

    add('face_bh.c', 'reference-ninja-facial-format', '''
fmSetLipSyncParam | LIP_WORK timing/sequence selects PARAM_WORK facial muscle interpolation with mask and transient fade state. Complete format/state contract is not a generic interpolation routine.
_fmSetObjP | Clones/rebinds Ninja object tree into ML_WORK arrays using bhGetFreeMemory and fixed sibling stack. No complete Outbreak scene/actor tree ABI demonstrated.
_fmCnkSearchObject | Model-bearing DFS ordinal lookup excludes child traversal for selected MASK_WORK eye/tooth/tang IDs. Not an unfiltered generic object-tree lookup.
_fmGetVChunkType | Ninja first-u16 vertex opcode selects vtop/ntop/vofs in32-bit words and sometimes ORs mode1. Numeric37(dec=25hex) has4-word stride here versus7-word Outbreak Clay25hex; Clay35/135hex are not this table. No shared opcode identity.
_fmCnkSetFaceObject | Clones selected Ninja model header, allocates/copies mutable vertex stream using count*vofs+128 words and installs into facial object. Distinct from Clay DMA/VIF conversion.
_fmCnkSetEyeballObject | Builds/relinks facial eye Ninja objects and matrices from selected model/root transforms and MASK_WORK eye slots. No original Outbreak eye-part layout established.
_fmCnkSetTangObject | Clones/relinks Ninja tongue object/model and mutable vertex storage into MASK_WORK. Format ownership is specific to facial context, not shared raw mesh import.
_fmCnkSetToothObject | Relinks/copied Ninja tooth object into MASK_WORK facial subtree. No matching complete Outbreak object-edit contract found.
_fmCnkSetJaw | Reads facial source vertex stride/indices, derives jaw orientation with atan/inverse-square-root and constructs Ninja matrices/object state. Pure math subexpressions do not identify complete jaw routine.
fmCnkInitContext | Patches MASK blob counted adjacency/index lists into destination vertex pointers, binds face/tooth/tongue/nine eye IDs, jaw lists and PARAM_WORK frames, and rebuilds ML_WORK arrays. This establishes a reference serialized format boundary.
fmCnkSetParam | Copies one whole PARAM_WORK into MASK_WORK.param; no original Outbreak same parameter size/layout or connected producer established. Generic memcpy is not new mapping credit.
fmCnkSetParamLip | Copies masked32 muscles and lip/jaw/tongue fields, converting integer-reinterpreted angles by0.005493164f. It is not a generic float tuple setter.
fmCnkSetInterParam | PARAM_WORK flag selects linear/square/sqrt/half-cos/zero rate, masked32 muscles and jaw/tongue level scaling, unscaled eye interpolation. No whole same Outbreak parameter structure proven.
fmCnkSetInterParamLip | Same rate family but integer-reinterpreted lip-angle interpolation with0.005493164f and no eye update. Not interchangeable with ordinary PARAM_WORK interpolation.
fmCnkSetCurrentFrame | Scans PARAM_WORK frame keys by unsigned-cast query, snaps endpoints or calls context interpolation. No zero-count protection; this is facial-key format handling, not generic game-clock mapping.
fmCnkGetLastFrame | Reads face[fnum-1].frame without local count guard. No same Outbreak facial-key owner/structure established; one indexed load alone cannot prove identity.
_fmCnkCalcMuscle | MASK connection/vertex lists and32 muscle influence arrays drive in-place Ninja vertices through scalar and EE/VU macro instructions. Generic vector arithmetic does not establish same facial data/opcode pipeline.
_fmCnkCalcJaw | Uses facial jaw influence lists, Ninja vertex stride, object matrices and jaw angle/translation with EE/VU macro operations. No Outbreak jaw-index or modelpart contract established.
_fmCnkCalcEye | MASK eye slots/context transforms and Ninja vertex data drive eye orientation/deformation, including atan/inverse-square-root. No same complete pipeline or model part ownership proved.
_fmCnkCalcTang | Facial tongue list/object transforms and parameter angles update Ninja vertices using EE/VU macro operations. No cross-game tongue format mapping from the name.
_fmCnkCalcNormal | Facial adjacency/VLIST_WORK normal-pointer pairs accumulate polygon normals then normalize into Ninja vertex records. Outbreak normalized triangle helper is shared arithmetic only, not this adjacency/stride body.
fmCnkCalcFace | Dispatches muscle,jaw,tongue,eye calculations and conditionally normals based on MASK mode1. Not an Outbreak render/actor frame scheduler.
fmCnkSetMode | On0->1 copies stored normal quadwords in8-word-stride Ninja vertex records then assigns MASK mode. No same mode bit/stride transition established in Clay conversion.
''', 'main:18A260 main:1A45A0 o0:370640')
    assert len(rows) == 70
    return rows


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--reference', type=Path, default=Path.home() / 'AppData/Local/Temp/reo-recvx-crosscheck-20261104')
    ap.add_argument('--output', type=Path, default=ROOT / 'build-function-index/recvx-mixed-geometry-complete-scope.json')
    args = ap.parse_args()
    ref = args.reference.resolve()
    universe = json.loads((ROOT / 'build-function-index/recvx-complete-source-inventory.json').read_text(encoding='utf-8'))
    assert universe['reference_commit'] == PIN
    manual = dispositions()
    elf = Elf(ROOT / 'game_data/SLUS_207.65')
    assert elf.sha256 == SHA
    db = sqlite3.connect(f'file:{ROOT / "build-function-index/index.sqlite"}?mode=ro', uri=True)
    identity = json.loads((ROOT / 'tools/function_index/overlay_identities.json').read_text(encoding='utf-8'))
    overlays = {}
    for im in ('o0', 'o2'):
        meta = next(x for x in identity['images'] if x['image'] == im)
        raw = (ROOT / f'build-function-index/owned-overlays/{im}.bin').read_bytes()
        assert hashlib.sha256(raw).hexdigest() == meta['imageSha256']
        overlays[im] = (meta, raw)
    audited = {}

    def owned(address):
        if address in audited:
            return audited[address]
        image, addr = address.split(':')
        start = int(addr, 16)
        found = db.execute('select end,source,proposed_name from functions where image=? and start=?', (image, start)).fetchone()
        assert found, address
        end, source, label = found

        def read(pc, n):
            if image == 'main':
                return elf.read(pc, n)
            meta, data = overlays[image]
            off = pc - meta['base']
            assert off >= 0
            return data[off:off+n]

        raw = read(start, end-start)
        assert raw is not None and len(raw) == end-start
        comment_words = {int(pc, 16): int(w, 16) for pc, w in re.findall(
            r'// 0x([\da-f]+): 0x([\da-f]+)\s+', (ROOT / source).read_text(encoding='utf-8'), re.I)
            if start <= int(pc, 16) < end}
        for pc, word in comment_words.items():
            assert read(pc, 4) == struct.pack('<I', word), (address, hex(pc))
        missing = [pc for pc in range(start, end, 4) if pc not in comment_words]
        assert all(read(pc, 4) == b'\0'*4 for pc in missing), address
        item = dict(id=address, source=source, label=label, end_exclusive=f'{end:X}',
                    sha256=hashlib.sha256(raw).hexdigest(), verified_words=len(comment_words),
                    omitted_zero_words=len(missing))
        audited[address] = item
        return item

    files = []
    consumed = set()
    for name in FILES:
        original = next(x for x in universe['files'] if x['path'] == BASE+name)
        raw = (ref / original['path']).read_bytes()
        assert hashlib.sha256(raw).hexdigest() == original['sha256']
        text = raw.decode('utf-8-sig')
        parsed = function_records(text)
        assert [(d['symbol'], d['start_line'], d['body_sha256']) for d in parsed] == [
            (d['symbol'], d['start_line'], d['body_sha256']) for d in original['functions']]
        entries = []
        for source_record, parsed_record in zip(original['functions'], parsed):
            key = (name, source_record['symbol'])
            assert key in manual, key
            consumed.add(key)
            assert source_record['implementation_shape'] == 'nonempty'
            record = dict(reference_file=original['path'], reference_file_sha256=original['sha256'], **source_record, **manual[key])
            record['signature'] = text[source_record['header_start']:source_record['body_start']].strip()
            record['calls'] = sorted(set(re.findall(r'\b([A-Za-z_]\w*)\s*\(', parsed_record['masked_body'])) -
                                     {'if', 'for', 'while', 'switch', 'sizeof', 'return', 'asm', 'volatile', 'PREFETCH'})
            lines = text[source_record['body_start']:source_record['body_end_offset']].splitlines()
            record['reference_boundary_witnesses'] = [
                dict(line=source_record['body_start_line']+i, text=line.strip())
                for i, line in enumerate(lines)
                if re.search(r'\b(?:rom|sys|plp|pp|pw|fm)->|\b(?:PLANE|ATR_WORK|MASK_WORK|PARAM_WORK|NJS_CNK_MODEL|NJS_CNK_OBJECT|ML_WORK|BH_PWORK)\b', line)
            ]
            record['outbreak_evidence'] = [owned(a) for a in record['outbreak_ids']]
            record['searched_evidence'] = [owned(a) for a in record['searched_candidates']]
            record['limitations'] = ('Static boundary/complete-source comparison. Related arithmetic is not original API identity, '
                                    'shared record layout, runtime parity, exhaustive binary absence or new mapping credit. '
                                    'Large room-state bodies are classified by complete-body dependency/format witnesses; '
                                    'their gameplay branches are not translated into Outbreak state.')
            entries.append(record)
        files.append(dict(path=original['path'], sha256=original['sha256'], functions=entries))
    assert consumed == set(manual)
    counts = Counter(r['status'] for f in files for r in f['functions'])
    classes = Counter(r['classification'] for f in files for r in f['functions'])
    headers = []
    for name in ('hitchk.h', 'hitchkl.h', 'rutchk.h', 'face.h', 'face_bh.h', 'types.h'):
        path = 'include/ps2/veronica/prog/' + name
        raw = (ref / path).read_bytes()
        headers.append(dict(path=path, sha256=hashlib.sha256(raw).hexdigest()))
    # Related predicate only; do not promote a BH API alias or claim an identical
    # convex-polygon implementation from the fixed-three-edge Outbreak body.
    groups = [dict(notebook='SYMBOLS_COLLISION_GRID.md', cvx_file=BASE+'hitchkl.c', outbreak_image='o2', rows=[[
        'o2:616BD0', 'bhInOutCheck', 'related-different', manual['hitchkl.c', 'bhInOutCheck']['comparison']]])]
    result = dict(schema=1, reference_commit=PIN, outbreak_elf_sha256=SHA,
                  files=files, support_headers=headers, related_candidate_groups=groups,
                  counts=dict(files=5, functions=sum(len(f['functions']) for f in files), statuses=dict(counts), classifications=dict(classes),
                              owned_complete_intervals=len(audited), owned_verified_words=sum(x['verified_words'] for x in audited.values()),
                              owned_omitted_zero_words=sum(x['omitted_zero_words'] for x in audited.values())),
                  all_reference_definitions_dispositioned=True, no_target_activity=True,
                  new_semantic_mapping_credit=0, notes='docs/recvx-crosscheck/MIXED_GEOMETRY_COMPLETE_SCOPE.md')
    assert result['counts']['functions'] == 70
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2)+'\n', encoding='utf-8')
    print(json.dumps(result['counts'], indent=2))


if __name__ == '__main__':
    main()
