# Engine comparison and limits of the current crosswalk

The 2026-11-05 [second engine pass](ENGINE_SECOND_PASS.md) adds concrete math,
overlap, script-format and enhanced-renderer/importer comparisons. Its twelve
Outbreak bodies retain their own image identities and audit receipt; no new
Ninja engine alias or actor-layout equivalence was established.

The pinned CVX tree provides useful examples of how a PS2 game organizes its
systems. The evidence below does not establish function identity, a common
complete engine, compatible assets or transferable original symbol names.
Only the entries in [CROSSWALK.md](CROSSWALK.md) have curated function-level
comparisons in this pass. The [inventory](notebook-inventory.csv) retains the
remaining notebook coverage explicitly.

## Graphics and model conversion

CVX's [njDrawPolygon][draw] consumes `NJS_POLYGON_VTX`, builds a local primitive
buffer and sends it through `Ps2AddPrim2D`. Its room-loading code also uses
Ninja/chunk model helpers. Outbreak's [Clay conversion notebook](../SYMBOLS_CLAY_RESOURCE_CONVERSION.md)
instead traces owned `flPS2ConvClayData` evidence and conversion into persistent
material-linked DMA/VIF chains. Its [render-program selection](../SYMBOLS_RENDER_PROGRAM_SELECTION.md)
and [palette packet callbacks](../SYMBOLS_RENDER_PALETTE_PACKET_VARIANTS.md)
have their own recovered descriptor contracts.

These are different inspected rendering boundaries. They do not show that all
math or PS2 packet helpers are unrelated, but they do rule out inferring an
Outbreak Clay structure or replacing its draw path from a CVX Ninja API name.
The native renderer in our checkout also has ownership separate from original
guest submission code; original symbol mapping alone does not validate host
GPU behavior.

## Room resources

CVX's [bhSetRoom][room] interprets an RDT image, checks a version field,
relocates room pointers and realizes room model data with `bhMlbBinRealize`.
Outbreak's [gameplay resource map](../SYMBOLS_GAMEPLAY.md) identifies separate
room object/script loading, while [overlay/archive loading](../SYMBOLS_OVERLAY_LOAD_AND_NESTED_ARCHIVES.md)
and [room section loading](../SYMBOLS_ROOM_SECTION_AND_SOUND_LOADING.md) retain
their own resource hierarchy and ownership.

Pointer relocation, room setup and streaming are useful concepts to compare.
There is no reviewed evidence here that CVX's `RDT_WORK`, relative offsets,
version gate or room structures describe Outbreak's formats.

## Script VM and actors

CVX's [event source][event] initializes 16 event-task records, selects room
`scd0/scd1` streams, and runs `bhScenarioCheck`/`bhEventScheduler2`.
Outbreak's [script VM notebook](../SYMBOLS_SCRIPT_VM.md) describes encoded
record lengths and observed opcode tables. Its [room-script bank runtime](../SYMBOLS_ROOM_SCRIPT_BANK_RUNTIME.md)
in overlay **o2** binds separate bank/context state for three selected player
slots and merges flag families. Those fixed three-slot loops are local
implementation facts, not a statement about the game's maximum co-op size.

Do not assign CVX opcode numbers, handler names, task layouts or `BH_PWORK`
offsets to Outbreak actors on the basis of similar behavior. Outbreak's actor
family notebooks retain their own overlay identity, dispatch tables, state
fields and admission evidence. Broad actor coverage is inventoried; individual
enemy behavior was not matched to CVX in this pass.

## Animation

CVX's [bhSetMotion][motion] selects motion interpolation paths using its actor
motion flags and blending fields. Outbreak's [animation notebook](../SYMBOLS_ANIMATION.md)
separates motion selection, track advancement, pose sampling and root-motion
extraction; main 0x1930F0 is a model-track lookup/sample boundary.

The distinction between selection, interpolation and pose evaluation is useful
when choosing Outbreak reconstruction boundaries. A motion function's general
purpose does not establish identical key encoding, frame units, floating-point
semantics, blending or side effects. No one-to-one animation alias is proposed.

## Movies and media libraries

CVX's [movie wrapper][movie] calls Sofdec initialization/display APIs. That
supports shared media vocabulary; it does not establish that every Outbreak
Sofdec/MWSF, MPEG header, conversion or clock routine has a decompiled counterpart
in this checkout. The curated table focuses on CRI audio and generic stream
interfaces, not the entire movie stack.

Outbreak's [movie service map](../SYMBOLS_MOVIE_SERVICE_DISPATCH_AND_START_PENDING.md)
and [movie clocks](../SYMBOLS_MOVIE_CLOCKS_AND_TIMECODES.md) therefore remain
independent evidence. In particular, CVX's ADXPS2 service order does not establish
Outbreak's movie scheduling or cutscene timing.

## Networking, platform libraries and remaining coverage

Outbreak's SN@P/SNIOP, lobby, HTTP/DNAS and online-authority notebooks have no
function-level CVX crosswalk in this pass. A literal search for `SNAP` and
`SNIOP` found no hits in the 228 CVX C source files screened. This is a bounded
source-tree observation, not proof of absence from dependencies, binaries or
other spellings. No CVX network replacement or naming transfer is proposed.

Both projects target PS2 interfaces, but sharing syscall names does not prove
the same Sony SDK version, wrapper ABI or native HLE contract. SDK, libc, math,
security, UI and the remaining notebooks are lexically inventoried here;
their functions have not all been semantically compared.

## Project architecture

CVX's [documented build][readme] reconstructs a PS2 executable and repackages
the disc for console/emulator testing. Our [project README](../../README.md)
describes static recompilation with a PC compatibility runtime and native
overrides. Consequently, a CVX C function is comparative source material, not
automatically portable host code. Guest addresses, 32-bit layouts, callbacks,
hardware effects, scheduling and generated/native override boundaries still
need explicit reconstruction.

[draw]: https://github.com/AshfordFamily/recvx-decomp/blob/657b0c0c9489943116c71f151804ad7304fca975/src/ps2/veronica/prog/ps2_NaDraw.c#L8
[room]: https://github.com/AshfordFamily/recvx-decomp/blob/657b0c0c9489943116c71f151804ad7304fca975/src/ps2/veronica/prog/room.c#L47
[event]: https://github.com/AshfordFamily/recvx-decomp/blob/657b0c0c9489943116c71f151804ad7304fca975/src/ps2/veronica/prog/event.c#L339
[motion]: https://github.com/AshfordFamily/recvx-decomp/blob/657b0c0c9489943116c71f151804ad7304fca975/src/ps2/veronica/prog/Motion.c#L21
[movie]: https://github.com/AshfordFamily/recvx-decomp/blob/657b0c0c9489943116c71f151804ad7304fca975/src/ps2/veronica/prog/mwwrap.c#L16
[readme]: https://github.com/AshfordFamily/recvx-decomp/blob/657b0c0c9489943116c71f151804ad7304fca975/README.md
