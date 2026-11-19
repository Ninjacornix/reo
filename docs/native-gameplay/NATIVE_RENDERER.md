# Native renderer: room drawn from the game's own data and camera

Goal: replace the PS2 graphics path (VIF/VU1/GS emulation) for gameplay with a renderer
that draws the game's models directly from the NBD assets, using the game's own camera
and model matrices read from guest memory. In-between frames then come from blending
matrices (not GS packets), and resolution/effects are no longer bound to the GS.

## Step 1 (2026-11-19): one room, offline, against a real frame — geometry and textures match

Inputs (all from the user's own disc; nothing is committed):

- room `r0350100.nbd` — the opening room of Below Freezing Point (scenario archive
  `NETBIO00.DAT/r035.afs`; the clock log reports `cache_scenario=35 cache_room=1`);
- textures: the room's `TID` list gives member ordinals of the same AFS (`.sld` =
  compressed TIM2), decoded with `tools/ps2_debug/dump_nbd_tex.py:ob_decompress`;
- the game's state at a captured frame: `tools/hybrid/room_driver.py --capture-at N
  --snapshot` writes `snap-at-N.json` next to `at-N.png` (read before and after the
  capture; camera and room regions were identical, only the actor records moved):

| region | File #1 address | use |
|---|---|---|
| view | `0x3240E0` | world → camera (row vectors) |
| composite2 | `0x294D80` | camera → pixels (x/w, y/w on the 512×448 frame) |
| room_current | `0x49FA10` | one 4×4 per room part (97 non-zero = 97 parts) |
| actors | `0x4A5C30` + n·`0x10E0` | position at +0x38 |

`tools/native_render/room_render.py` draws each part as
`vertex · node[part] · view · composite2`, triangles from the part strips, perspective-correct
UVs, GS-style modulate (vertex colour 128 = 1.0) and alpha blending.

Model layout facts confirmed on the way (and matching `game/native/gameplay_presentation/model_mesh.cpp`):

- part chunk `0x50000` = the materials the part uses; per strip `0x60000` indexes that list;
- material record (`0x9` list): its **last word** selects a texture record (`0xA` list),
  whose first word is the TID slot; the material type is `kind >> 16`:
  `0x12` = glow cards (radial glow textures, drawn additively), `0x13` plain,
  `0x14` with a specular exponent (3 … 50).

Result (`snap-at-10`): rails, gravel, walls, ceiling, doorway, pipes and lamp glows land on
the same pixels as the original frame, with the right textures.

Open differences:

- **brightness**: the native image is ~2.6× brighter, nearly uniformly (also next to the
  camera, so not the fog range 2200–3070 in `R0350100.FOG`). Next: read the RGBAQ the
  original actually sends for room vertices instead of guessing a scale;
- lamp boxes and other room objects come from the second AMO in the room NBD and the
  `OBJ*.NBD` banks — not drawn yet;
- fog, specular (`0x14`), characters (skinned; bones from the actor records).

## Step 2 (2026-11-19): measured colours, Kevin skinned from live bones

**Ground truth for colours**: `REO_GIF_DUMP_AT=N` (with `REO_FRAME_REPLAY=1
REO_FRAME_REPLAY_DEBUG=record REO_FRAME_REPLAY_DUMP=<dir>`) writes the GS input of displayed
frames N..N+2; `tools/native_render/gif_inspect.py` decodes it into drawn vertices with their
register state. Matching those vertices to the native projection (screen offset 1792/1824):

- room vertices: RGB sent = baked AMO colour × **0.373** (95/255; p10–p90 0.28–0.37, not
  depth-dependent), ALPHA `0x44`, fog enabled. With that factor the native frame's mean
  brightness is 23.3 vs 23.9 for the original (was 61);
- characters: UVs are sent unchanged (s/q = AMO u, t/q = AMO v; textures repeat), colours are
  lit per vertex by the game (AMO colours are 0; sent RGB 3–59, median 14).

**Bones**: `room_driver.py --snapshot-ram` saves the 32 MB guest RAM. Each character's 35
skeleton nodes are 0x190-byte records: world matrix at +0x00, local at +0x40, inverse bind at
+0x80. In the opening room Kevin's (actor 0) start at `0x4F9140`, the two partners' at
`0x5001C0` and `0x507240`. Skinned position = Σ weight × v · inverse_bind · world; weights from
part chunks `0xC0000`/`0x100000`. Kevin lands on the original's pixels.

Still open: the source of the 0.373 room factor; real per-vertex character lighting (now a
neutral light); the partners' models; destination-alpha decals on the right wall; fog; room
objects (second AMO, `OBJ*.NBD`); then moving this into the game as a live renderer.
