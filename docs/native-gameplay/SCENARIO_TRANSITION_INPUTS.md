# Native scene transition inputs

The native Update Owner now exposes the cutscene request collector, actor
placement packet consumer, and room placement completion through its canonical
World and Session.

## Cutscene request collection

The collector resolves the original flag-owner and actor selectors, normalizes
mode 3 to mode 1, and produces the current scene identity and bounded audio cue
batch. Additional entries use the first request's actor selection. Collection
runs synchronously on the simulation owner. It admits a nonempty queue with
normalized indices. Missing flag/actor state preserves the queue for the caller.

The original scene-mode and media/UI calls are explicit test ports. Actual
playback and scene orchestration must consume the resulting typed batch. The
original collector's interleaved-producer behavior remains outside this
serialized native owner contract.

## Actor placement packets

The packet consumer validates and imports counted 32-byte placement records,
then applies pending requests to the canonical actors. It updates the current
position, yaw, request state, and auxiliary status in the original order. Prior
position and orientation stay available to their existing consumers. The
complete native operation validates its inputs before publishing changes.

The native profile supports up to 32 position records and four request slots.
An active actor beyond those request slots, an unknown roster, or an invalid
referenced position refuses the packet. The original unchecked neighboring
storage reads remain an explicit boundary.

## Room placement completion

After scene loading, the completion method applies the selected room request
and the four actor room values, then captures the room variant from the shared
variant map. The current variant has its own canonical Session field. The three
original preparation/resource-loading children are controlled test ports and
remain actual scene orchestration work.

## Verification

LLVM and GCC each pass 28,169,276 checks, including 4,096 original cutscene
collections, 4,096 complete placement packet calls, and 2,048 room placement
completion comparisons. The tests also cover bounds refusal, missing state,
queue preservation, and closed owners. Runtime transport, scene playback and
installed game acceptance remain open.
