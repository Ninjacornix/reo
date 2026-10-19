Reusable complete VU program source generator. These files contain no owned
game microcode arrays, game identity hashes, observed game entry keys or fixed
local capture paths. Generated output contains supplied local code bytes and
must remain in ignored/local output. The caller supplies owned captures or a
bounded collection directory explicitly.

    python generate.py --capture-dir LOCAL_CAPTURE --out FRESH_LOCAL_OUTPUT
    python generate.py --collection LOCAL_COLLECTION --out FRESH_LOCAL_OUTPUT

Multiple --capture-dir arguments are supported. No synthetic programs are
silently added. Entry keys come from original632-byte state artifacts or actual
recorded launches. Code must be16KiB and entries aligned/inrange; SHA256 only
deduplicates owned input images. The emitted factory is separate from the
generic runtime, returning a private immutable Table. Namespace can be set with
--factory-name; no game image lives in the runtime registration implementation.

Compile generated source with the private runtime headers and this helper
directory on the include path. The table, images and old replaced tables must
outlive every VU call. Register before initialization through
vu_whole_program::registerProgramTable. The selector verifies exact image,
observed entry, dimensions, inactive capture, and state/code/data disjointness.
Unknown keys retain current block/generic execution.

The CFG conservatively includes all aligned sites after a reachable indirect
branch. Bounded Plain regions accept all suffix entries, with one complete
budget/context admission, and retain exact cold scheduling for incoming E,
branch, first pair, short budget and XGKICK. Math retains the original paired
interpreter byte semantics, including exact generic fallback for unsafe input;
it does not claim Sony VU flags/numbers or hardware pipeline timing correctness.
An unexpected aligned inrange CFG hole faults explicitly after mutation.

`vu_math_helpers.h` is extracted from the validated byte-parity arithmetic
foundation. It has only generic ISA/runtime operations, never owned arrays.
The source-only reproduction in local-generated was compared with all149
retained native Plain bodies after program-ID/namespace normalization. Root
must still run actual runtime/factory full-output oracles before promotion.
