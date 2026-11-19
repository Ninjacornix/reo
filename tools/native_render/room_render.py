"""Native renderer, step 1: draw a File #1 room NBD with the game's own camera, offline.

usage: room_render.py ROOM.nbd SNAPSHOT.json OUT.png [--reference SHOT.png]
                      [--data DISC_DATA --archive r035.afs]   (textures)
                      [--ram RAM.bin --character MODEL.NBD@BONES ...]   (skinned characters)

ROOM.nbd comes from the user's own disc (r035.afs etc.; never committed). SNAPSHOT.json is
written by tools/hybrid/room_driver.py --capture-at N --snapshot: it holds the game's view
matrix (0x3240E0), its pixel projection (0x294D80, "composite2") and the room's current
node matrices (0x49FA10, one per model part).

Per part: vertex (row vector) x node matrix x view x projection -> (X, Y, Z, W); pixel =
(X/W, Y/W) on the 512x448 frame. Triangles come from the part's strips and are shaded
with the baked vertex colours (128 = 1.0, as on the GS). With --data, each material's
texture (TID slot -> member ordinal of the scenario AFS; .sld = compressed TIM2) is
sampled perspective-correct and modulated by the vertex colour (GS MODULATE); material
type 0x12 (glow cards) is drawn additively after the opaque parts; 0x14 carries a
specular exponent (not lit here).

Characters (P00_00.NBD etc.): same AMO parts plus 0xC0000 weights (per vertex: n, then n x
(u32 palette index, f32 percent)) and 0x100000 palette (palette index -> skeleton node). Their
textures are embedded (TEX section). Live bones come from a RAM snapshot
(room_driver.py --snapshot-ram): one 0x190-byte record per node, world matrix at +0x00 and
inverse bind matrix at +0x80 (File #1: Kevin's first record at 0x4F9140 in the opening room).
Skinned vertex = sum(weight x vertex . inverse_bind[node] . world[node]).

AMO layout used (chunk = kind:u32 count:u32 size:u32, size includes the header):
  model  kind 0x20000 header, kind 0x2 parts (count = parts), each part kind 0x4:
    0x5     mesh: holds 0x30000 strips (count strips; each = n, then n vertex indices)
    0x50000 materials used by the part (model material indices)
    0x60000 per strip: index into the part's 0x50000 list
    0x70000 positions float3     0x80000 normals float3
    0xA0000 texcoords float2     0xB0000 colours float4 (0..255)
  model  kind 0x9 material list (record kind >> 16 = type 0x12 additive / 0x13 / 0x14),
         kind 0xA texture list (first word = TID slot); material last word -> texture record
"""
import argparse, json, struct, sys
from pathlib import Path
import numpy as np
from PIL import Image

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools/assets'))
sys.path.insert(0, str(ROOT / 'tools/ps2_debug'))

W, H = 512, 448
# Measured from the original's GS input (tools/native_render/gif_inspect.py on a REO_GIF_DUMP_AT
# frame of r0350100): room vertex RGB = baked AMO colour x 0.373 (95/255; p10..p90 0.28..0.37,
# independent of depth). Its source (a light colour in the VU1 room program?) is not found yet.
ROOM_COLOR_SCALE = 95.0 / 255.0
# Characters are lit per vertex by the game (their AMO colours are 0); until that lighting is
# connected, a neutral light at the room level stands in (as in game/native's presentation).
CHARACTER_NEUTRAL_LIGHT = ROOM_COLOR_SCALE


def chunks(b, at):
    end = at + struct.unpack_from('<I', b, at + 8)[0]
    cur = at + 12
    while cur < end:
        kind, count, size = struct.unpack_from('<III', b, cur)
        if size < 12 or cur + size > end:
            raise ValueError('bad chunk at 0x%x' % cur)
        yield cur, kind, count, size
        cur += size


def model_offset(b):
    if b[0x10:0x13] != b'AMO':
        raise ValueError('second NBD section is not AMO')
    return struct.unpack_from('<I', b, 0x14)[0]


def parse_parts(b):
    top = list(chunks(b, model_offset(b)))
    parts_chunk = next(c for c in top if c[1] == 0x2)
    parts = []
    for at, kind, count, size in chunks(b, parts_chunk[0]):
        if kind != 0x4:
            continue
        part = {'strips': [], 'materials': None, 'part_materials': None, 'pos': None, 'col': None, 'uv': None}
        for sat, skind, scount, ssize in chunks(b, at):
            data = sat + 12
            if skind == 0x5:
                for mat, mkind, mcount, msize in chunks(b, sat):
                    if mkind == 0x30000:
                        cur = mat + 12
                        for _ in range(mcount):
                            n = struct.unpack_from('<I', b, cur)[0]
                            part['strips'].append(list(struct.unpack_from('<%dI' % n, b, cur + 4)))
                            cur += 4 + 4 * n
            elif skind == 0x50000:  # materials this part uses (indices into the model list)
                part['part_materials'] = struct.unpack_from('<%dI' % scount, b, data)
            elif skind == 0x60000:  # per strip: index into the part's material list
                part['materials'] = struct.unpack_from('<%dI' % scount, b, data)
            elif skind == 0x70000:
                part['pos'] = np.frombuffer(b, '<f4', scount * 3, data).reshape(-1, 3).astype(np.float64)
            elif skind == 0xA0000:
                part['uv'] = np.frombuffer(b, '<f4', scount * 2, data).reshape(-1, 2).astype(np.float64)
            elif skind == 0xB0000:
                part['col'] = np.frombuffer(b, '<f4', scount * 4, data).reshape(-1, 4).astype(np.float64)
            elif skind == 0x100000:
                part['palette'] = struct.unpack_from('<%dI' % scount, b, data)
            elif skind == 0xC0000:
                cur, influences = data, []
                for _ in range(scount):
                    n = struct.unpack_from('<I', b, cur)[0]
                    influences.append([(struct.unpack_from('<I', b, cur + 4 + 8 * j)[0] & 255,
                                        struct.unpack_from('<f', b, cur + 8 + 8 * j)[0] / 100.0) for j in range(n)])
                    cur += 4 + 8 * n
                part['influences'] = influences
        parts.append(part)
    return parts


def parse_materials(b):
    """Per material: (type, texture slot) from the model's 0x9 / 0xA chunk lists."""
    top = {c[1]: c for c in chunks(b, model_offset(b))}
    # As game/native/gameplay_presentation/model_mesh.cpp: a material's last word selects its
    # texture record; that record's first word is the TID slot.
    slots = [struct.unpack_from('<I', b, at + 12)[0] for at, _, _, _ in chunks(b, top[0xA][0])]
    return [(kind >> 16, slots[struct.unpack_from('<I', b, at + size - 4)[0]])
            for at, kind, _, size in chunks(b, top[0x9][0])]


def decode_tim2(data):
    """Indexed TIM2 (PSMT4/PSMT8, 32-bit CLUT) -> HxWx4 float array, alpha 0..1 (0x80 = 1)."""
    from dump_nbd_tex import ob_decompress
    b = ob_decompress(data)
    if b[:4] != b'TIM2':
        raise ValueError('texture is not TIM2')
    p = 16 if b[5] == 0 else 128
    total, clut, image = struct.unpack_from('<III', b, p)
    header, colors = struct.unpack_from('<HH', b, p + 12)
    ct, typ = b[p + 18:p + 20]
    w, h = struct.unpack_from('<HH', b, p + 20)
    im = p + header
    pal = np.frombuffer(b, np.uint8, colors * 4, im + image).reshape(-1, 4).astype(np.float64)
    if typ == 4:
        raw = np.frombuffer(b, np.uint8, (w * h + 1) // 2, im).astype(np.int64)
        idx = np.empty(w * h, np.int64)
        idx[0::2] = raw[:len(idx[0::2])] & 15
        idx[1::2] = raw[:len(idx[1::2])] >> 4
    elif typ == 5:
        idx = np.frombuffer(b, np.uint8, w * h, im).astype(np.int64)
        if not ct & 128:  # CSM1 palette swizzle
            idx = (idx & ~24) | ((idx & 8) << 1) | ((idx & 16) >> 1)
    else:
        raise ValueError('unsupported TIM2 image type %d' % typ)
    rgba = pal[idx].reshape(h, w, 4)
    rgba[..., :3] /= 255.0
    rgba[..., 3] = np.minimum(rgba[..., 3] / 128.0, 1.0)
    return rgba


def character_textures(nbd):
    if nbd[:3] != b'TEX':
        raise ValueError('character NBD has no TEX section')
    at, size, count = struct.unpack_from('<III', nbd, 4)
    textures = []
    for _ in range(count):
        n = struct.unpack_from('<I', nbd, at)[0]
        textures.append(decode_tim2(nbd[at + 4:at + 4 + n]))
        at += 4 + n
    return textures


def skin(part, ram, bones):
    """World positions of a skinned part from live bone records (see module notes)."""
    def record(node, offset):
        return np.array(struct.unpack_from('<16f', ram, bones + node * 0x190 + offset), np.float64).reshape(4, 4)
    pos = np.c_[part['pos'], np.ones(len(part['pos']))]
    out = np.zeros_like(pos)
    cache = {}
    for i, influence in enumerate(part['influences']):
        for index, weight in influence:
            node = part['palette'][index]
            if node not in cache:
                cache[node] = record(node, 0x80) @ record(node, 0x00)
            out[i] += weight * (pos[i] @ cache[node])
    return out


def load_textures(nbd, data_dir, archive_name):
    from afs_inspect import read_toc
    if nbd[:3] != b'TID':
        raise ValueError('room NBD has no TID texture list')
    tid = struct.unpack_from('<I', nbd, 4)[0]
    count = struct.unpack_from('<I', nbd, tid)[0]
    ordinals = struct.unpack_from('<%dI' % count, nbd, tid + 4)
    textures = []
    with (Path(data_dir) / 'NETBIO00.DAT').open('rb') as f:
        top = read_toc(f, 0)
        names = [t[0] for t in top[2]]
        base = top[0][names.index(archive_name)][0]
        toc = read_toc(f, base)
        for ordinal in ordinals:
            off, ln = toc[0][ordinal]
            f.seek(base + off)
            textures.append(decode_tim2(f.read(ln)))
    return textures


def matrix(hexdata, index=0):
    return np.array(struct.unpack_from('<16f', bytes.fromhex(hexdata), index * 64), np.float64).reshape(4, 4)


def render(parts, snap, materials=None, textures=None, characters=()):
    view = matrix(snap['view'])
    proj = matrix(snap['composite2'])
    room = bytes.fromhex(snap['room_current'])
    color = np.zeros((H, W, 3), np.float64)
    depth = np.full((H, W), np.inf)
    stats = {'parts': 0, 'triangles': 0, 'drawn': 0, 'additive': 0}
    additive = []
    jobs = [(part, index, materials, textures, None) for index, part in enumerate(parts)]
    for c_parts, c_materials, c_textures, ram, bones in characters:
        jobs += [(part, None, c_materials, c_textures, (ram, bones)) for part in c_parts]
    for part, index, materials, textures, skinning in jobs:
        if part['pos'] is None or not part['strips']:
            continue
        if skinning is None:
            node = np.array(struct.unpack_from('<16f', room, index * 64), np.float64).reshape(4, 4)
            if not node.any():
                continue
            world = np.c_[part['pos'], np.ones(len(part['pos']))] @ node
        elif part.get('influences'):
            world = skin(part, *skinning)
        else:
            continue
        stats['parts'] += 1
        p = world @ view @ proj
        w = p[:, 3]
        ok = w > 1e-3
        sx = np.where(ok, p[:, 0] / np.where(ok, w, 1), np.nan)
        sy = np.where(ok, p[:, 1] / np.where(ok, w, 1), np.nan)
        col = part['col'][:, :4] / 128.0 if part['col'] is not None else np.ones((len(w), 4))
        if skinning is None:
            col = np.c_[col[:, :3] * ROOM_COLOR_SCALE, col[:, 3]]
        else:
            col = np.c_[np.full((len(w), 3), CHARACTER_NEUTRAL_LIGHT), np.ones(len(w))]
        uv = part['uv'] if part['uv'] is not None else np.zeros((len(w), 2))
        for s, strip in enumerate(part['strips']):
            tex, kind = None, 0
            if materials is not None and part['materials'] is not None and s < len(part['materials']):
                local = part['materials'][s]
                listed = part['part_materials']
                kind, slot = materials[listed[local] if listed is not None and local < len(listed) else local]
                tex = textures[slot] if textures is not None and slot < len(textures) else None
            for k in range(len(strip) - 2):
                a, b2, c = strip[k], strip[k + 1], strip[k + 2]
                stats['triangles'] += 1
                if not (ok[a] and ok[b2] and ok[c]):
                    continue
                tri = [(sx[i], sy[i], w[i], col[i], uv[i]) for i in (a, b2, c)]
                if kind == 0x12:  # glow cards (radial glow textures): additive
                    additive.append((tri, tex))
                    continue
                stats['drawn'] += raster(color, depth, tri, tex, False)
    for tri, tex in additive:
        stats['additive'] += raster(color, depth, tri, tex, True)
    return np.clip(color * 255, 0, 255).astype(np.uint8), stats


def raster(color, depth, tri, tex, additive):
    (ax, ay, aw, ac, au), (bx, by, bw, bc, bu), (cx, cy, cw, cc, cu) = tri
    x0 = max(int(np.floor(min(ax, bx, cx))), 0)
    x1 = min(int(np.ceil(max(ax, bx, cx))), W - 1)
    y0 = max(int(np.floor(min(ay, by, cy))), 0)
    y1 = min(int(np.ceil(max(ay, by, cy))), H - 1)
    if x0 > x1 or y0 > y1:
        return 0
    area = (bx - ax) * (cy - ay) - (by - ay) * (cx - ax)
    if abs(area) < 1e-9:
        return 0
    ys, xs = np.mgrid[y0:y1 + 1, x0:x1 + 1] + 0.5
    l0 = ((bx - xs) * (cy - ys) - (by - ys) * (cx - xs)) / area
    l1 = ((cx - xs) * (ay - ys) - (cy - ys) * (ax - xs)) / area
    l2 = 1 - l0 - l1
    inside = (l0 >= 0) & (l1 >= 0) & (l2 >= 0)
    if not inside.any():
        return 0
    z = l0 * aw + l1 * bw + l2 * cw  # view depth (W); smaller is nearer
    region = depth[y0:y1 + 1, x0:x1 + 1]
    test = inside & (z < region)
    if not test.any():
        return 0
    # Perspective-correct attributes: interpolate a/w and 1/w.
    q0, q1, q2 = l0 / aw, l1 / bw, l2 / cw
    qs = q0 + q1 + q2
    shade = (q0[..., None] * ac + q1[..., None] * bc + q2[..., None] * cc) / qs[..., None]
    if tex is not None:
        u = (q0 * au[0] + q1 * bu[0] + q2 * cu[0]) / qs
        v = (q0 * au[1] + q1 * bu[1] + q2 * cu[1]) / qs
        th, tw = tex.shape[:2]
        tx = np.floor(u * tw).astype(np.int64) % tw
        ty = np.floor(v * th).astype(np.int64) % th
        texel = tex[ty, tx]
        rgb = texel[..., :3] * shade[..., :3]
        alpha = texel[..., 3] * shade[..., 3]
    else:
        rgb = shade[..., :3]
        alpha = shade[..., 3]
    out = color[y0:y1 + 1, x0:x1 + 1]
    if additive:
        out[test] += rgb[test] * alpha[test, None]
    else:
        draw = test & (alpha > 0.0)  # alpha test, then blend over what is there
        a = np.minimum(alpha[draw, None], 1.0)
        out[draw] = rgb[draw] * a + out[draw] * (1 - a)
        region[draw] = z[draw]
    return 1


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('room', type=Path)
    ap.add_argument('snapshot', type=Path)
    ap.add_argument('out', type=Path)
    ap.add_argument('--reference', type=Path)
    ap.add_argument('--data', type=Path, help='Imported disc data folder (holds NETBIO00.DAT)')
    ap.add_argument('--archive', default='r035.afs', help='Scenario room archive inside NETBIO00.DAT')
    ap.add_argument('--ram', type=Path, help='Guest RAM snapshot (room_driver.py --snapshot-ram)')
    ap.add_argument('--character', action='append', default=[], help='MODEL.NBD@0xBONES: skinned character with its first bone record')
    a = ap.parse_args()
    nbd = a.room.read_bytes()
    parts = parse_parts(nbd)
    materials = parse_materials(nbd)
    textures = load_textures(nbd, a.data, a.archive) if a.data else None
    snap = json.loads(a.snapshot.read_text())['after']
    characters = []
    ram = a.ram.read_bytes() if a.ram else None
    for spec in a.character:
        path, bones = spec.rsplit('@', 1)
        c = Path(path).read_bytes()
        characters.append((parse_parts(c), parse_materials(c), character_textures(c), ram, int(bones, 0)))
    image, stats = render(parts, snap, materials, textures, characters)
    Image.fromarray(image).save(a.out)
    print(json.dumps(stats))
    if a.reference:
        ref = Image.open(a.reference).convert('RGB').resize((W, H))
        Image.blend(ref, Image.fromarray(image), 0.5).save(a.out.with_name(a.out.stem + '-overlay.png'))


if __name__ == '__main__':
    main()
