# Native dialogue text cache

The typed TextCache owns the 32 source text entries. Explicit reset implements
1B4A60; construction leaves the capability unavailable. Request, duplicate and
priority admission, dialogue alpha publication, erase, expiry and culling follow
complete 1B4590/1B4650/1B46E0/1B48E0/1B49B0/1B4940/1B4450 bodies. Snapshots retain
values independently of subsequent clears and reuse. No source memory layout or
register model enters production.

CachedDialoguePresentation connects the existing canonical DialoguePool to this
cache. It borrows the same World and cache and uses the canonical Session
inventory owner for complete 6DEE20 suppression. The enabled and mode values
remain explicit optional inputs until their real timed-message producers are
installed. An admitted insertion attempt can produce no cache entry, matching
the original void draw call; it is not a fabricated rendering success.

Admission compares the full incoming priority, coordinates, height and fade
before the source's byte/halfword storage truncation. Duplicate detection uses
the stored signed Y and text bytes, ignoring X. Copied text preserves the old
unused tail. A 128-byte body reaches the source copy boundary after metadata
writes; native reports that unsupported profile with the same visible prefix,
instead of overflowing the 128-byte field.

Both compilers pass 1,208,167 cache checks across 32,768 complete commands,
16,431 insertions, 4,422 admitted attempts without insertion and 126,895 original
calls. Original string comparison, copy and clear bodies execute. One controlled
copy-entry interruption verifies the unsupported profile prefix. The failed
first GCC fixture compile, missing a reference SRA32 macro, remains retained.

Both compilers pass all 262,144 enabled/mode/inventory combinations against
complete 6DEE20, plus three native unavailable-input and early-return checks.
This establishes the query, not the separate 6DEC80 timed-message initialization.

The integrated comparison now runs complete DialoguePool constructors and
updates with actual cache erase/admission/draw and suppression bodies instead
of presentation ports. Both compilers pass 1,264,192 checks, 787 constructors,
1,176 updates and 100,384 original calls. All cache entries, pool records,
canonical actor fields, random continuation and observed call order agree.
Retained bank lifetime, reentrant mutation rejection and authored effect flags
remain covered. The earlier record v8 proof is retained; fresh v9 repeats its
131,709 checks after conditionalizing the oracle-only Event equality operator
so standalone LLVM -Werror also accepts the CMake contract fixture.

Remaining integration is explicit: 1B4A20 callback registration, actual 1B4500
font/glyph consumption and graphics gates, timed-message visibility ownership,
full 1D41F0 room-bank publication, and 6B7E40 actor-response orchestration. No
frame worker substitutes the inner pool updater for that larger source caller.
No game, audio device or renderer is run by these checks. This is not full
Stage 4 acceptance.
