# Native room model remaps, visibility, styles and poses

Status, 2026-11-09: interpreter v12 qualifies `0B0`, `0B1` and `0B4` in ordinary and offline dispatch. The native owner imports the actual bounded room remap and owns visibility, style words and current poses. External pose bindings, resource construction, renderer consumption and actual game callers remain separate work. Stage 4 remains incomplete.

## Owned content and state

`68C570` copies the room script section to the scenario container's `+8000` area and relocates its 16 references. `581830` reads the reference at `+8004`, therefore room-section table index 1. [`import_room_model_remap`](../../game/native/gameplay_scenario/scene_models.cpp) reads exactly 32 bytes from that bounded object. All 166 hash-verified owned RDT sections have a 32-byte upper bound for this object. The native importer does not interpret unknown adjacent objects or install a script.

`581830` narrows an authored ID to its unsigned low byte. IDs below 32 select the remap; the other values return model slot zero without reading the remap. The owned maps contain values 0 through 127 and `FF`. These are scene model slots, separate from canonical primary actor identity and from the 256 scene-resource descriptors.

`SceneModels` owns 128 visibility bytes, 128 style words and 128 full 16-float current poses. The slot bound comes from the actual `5D7D60` reset, not from the argument's byte width. Initial state is supplied explicitly; this checkpoint does not manufacture stock resource initialization or implement the rest of that reset.

The original visibility byte base `49F790` is exactly 128 bytes before style base `49F810`. Consequently, mapped indices 128 through 255 **mutate a style-word bit**, rather than a separate visibility flag. The native owner represents this effect explicitly: style index `(slot-128)/4`, bit `7+8*((slot-128)%4)`. In particular `FF` changes style word 31's bit 31. No native array overrun, guest memory or independent 256-byte shadow flag array is used. The full visibility/style oracle checks all these indices. Eight conservative offline prefix candidates resolve to `FF`; this is not proof that those paths execute with that remap in a live session.

`5D8350` style writes admit authored indices below 32 and resolved slots below 128; wider source indexing is not silently redirected. `5D8390` resets all 128 style words to `FFFFFFFF`. Invalid native pose/style indices refuse before changing state. Visibility commands retain their separately proven style-bit effects for every remap byte.

## Native pose adjustment

`0B4` uses the eight owned 24-byte float-radian/offset presets at `7174F0..7175AF`. All currently found owned-prefix selectors are 0 through 7; unknown continuations remain open. The default native profile explicitly refuses wider preset indices. Preset bytes are independently seeded from the hash-verified overlay in the oracle and compared to the native immutable table.

Adjustment transforms the offset through the old pose basis, builds the original X/Y/Z rotation from the initialized identity profile, multiplies only the basis XYZ, copies those nine values back while preserving axis W and translation, then adds the transformed offset to translation XYZ. Existing native original-polynomial trig and ordered direction math are reused. The local float-radian/basis operations are compared against the complete original `690700` chain, including actual `18FDF0`, `190A10`, `1913E0`, `191530` and `1919D0` bodies.

The numeric profile requires finite used values, nearest rounding and gradual underflow with fast math and contraction disabled. Arbitrary unused W bits, including nonfinite copied bits, are retained. Invalid arithmetic computes no published partial pose. Wider exceptional arithmetic and physical PS2 accumulator/exception parity are not claimed.

The interpreter requires a model owner before any operation in an admitted model-dependent program. It also checks every referenced `0B4` remap resolves to an owned pose before earlier operations or offline selected-context changes. Numeric refusal during an operation is not a transactional rollback of preceding successful operations.

## Qualification and remaining work

The standalone LLVM/GCC cohorts each pass 1,051,061 assertions, 49,792 complete original entry invocations and 13,312 helper calls. They cover all 166 owned room imports and all 256 authored low-byte values per room, 2,048 visibility/style cases, 1,024 complete pose-adjustment chains, preserved lanes, malformed imports and refusal without partial publication. The initial GCC fixture warning and earlier LLVM prototype remain retained in distinct private folders.

The whole VM oracle now uses the already qualified VU-capable finite SIMD/scalar reference with SDK131's sign-extending word setter. It executes the actual math bodies in the same context as the dispatcher. Historical scalar cohorts remain independent evidence. No divergence was observed in the admitted earlier handler cases; this does not qualify previously excluded numeric outliers. Both final compilers pass 12,289,928 assertions and 14,136 dispatcher invocations, with 6,064 instruction comments checked against the owned source. Masks are 316/432 ordinary and 289/432 offline, including original no-op bindings. Offline context gates, shared three-actor model changes and dependency refusal are included.

Binding to native scene entities, binding lifetime/unbind semantics, initial model asset/pose construction, style consumers, scheduled pose programs and rendering remain unported consumers. A mask percentage does not establish complete stock coverage or native gameplay execution. No game, window, physical audio or performance test is part of this qualification.
