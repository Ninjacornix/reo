# Spoken subtitle controls

The Audio page's Subtitles switch defaults to enabled, persists across launches,
and publishes changes immediately through its own 16-byte Windows mapping.
`REO_SUBTITLES=0|1` supplies the launch value; `REO_SUBTITLE_MAP` names the live
mapping. The layout is four little-endian uint32 values: magic `0x53554254`,
version `1`, sequence, enabled (`0` or `1`). Odd, changing, or invalid snapshots
retain the last valid setting. Existing audio IPC is unchanged.

The native override tags successful allocations from two verified spoken-text
producers: character callouts (speaker name and speech) and voiced NPC dialogue
(including typing and fades). It skips only their queued glyph draw calls when
disabled. Producers, voice playback, queue updates, expiry, and overlap culling
still execute. Interaction prompts, menus, and unrelated status text still draw.
Embedded text within a pre-rendered movie is outside this renderer.

| Function | File #1 | File #2 |
|---|---|---|
| Character callouts | `0x6df800` | `0x70efc0` |
| Typed spoken dialogue | `0x6b97d0` | `0x6e6e90` |
| Queue allocator | `0x1b46e0` | `0x1400d0` |
| Normal / custom-alpha enqueue | `0x1b4820` / `0x1b48e0` | `0x140210` / `0x1402d0` |
| Queue draw leaf | `0x1b4100` | `0x13faf0` |
| Queue base (32 records, stride `0x8c`) | `0x3151d0` | `0x2f3d10` |

The allocator returns the alpha pointer at record+10. The draw leaf receives
record+12 in `a3`. Every successful allocation replaces the host classification,
so ordinary text reusing an old speech slot remains visible. Caller provenance
comes from guest stack frames and exact known callsites, with a matching guest
JAL instruction required. Allocator continuations are hooked too; guest thread
preemption does not depend on a host stack scope. Generic interaction-message
functions (`0x1c1d00` / `0x14d9c0`) are deliberately excluded.

Run with a Windows MinGW clang++ compiler on PATH:

```powershell
python tools/subtitle_check/run.py
python tools/subtitle_check/run.py --owned-queue
```

The first command checks both production hooks against controlled callbacks and
real Windows IPC. The second also compiles the locally generated allocator,
enqueue fronts, overlap culler, queue update, and draw loop for each game into a
controlled guest runtime. It verifies actual guest frame classification, yielding
and resuming, glyph submission counts, TTL expiry, live re-enabling and slot reuse.
String-copy/comparison and unrelated engine services use controlled callbacks;
the final font leaf records submissions. This is queue execution verification,
not a claim that every scenario was played or final GPU pixels inspected.

Owned generated sources are staged only under ignored `build-ninja/subtitle-toggle`.
Game executables must be rebuilt to include the new native override.
