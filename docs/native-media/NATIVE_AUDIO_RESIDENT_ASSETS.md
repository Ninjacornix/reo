# Bounded resident audio assets

Status, 2026-11-09: the resident resource cache, complete-body native clip
preparation and queue-content/lifetime checks pass on LLVM and GCC. Adaptive
resident backend, actual source-profile integration and coherent game/A-V
retests remain separate gates. This document does not close Step 3.

The [qualification](../../tools/native_reconstruction/native_resident_assets_qualification_v1.json)
retains both compiler receipts, exact source snapshots, the retired test
expectation and the verified owned inventory. This work opens no game, window
or physical audio device and changes no public header layout.

## Native preparation boundary

The [V37 incident](NATIVE_AUDIO_V37_INPUT_INCIDENT.md) shows that metadata-ready
queued audio still depended on file-backed reads during playback. Two accepted
requests remained pending while encoded and PCM data drained. Its inner
read/scheduling cause is unconfirmed.

An explicit native resident view now admits a complete finite immutable asset.
Its constructor retains the source and reserves its size without reading it.
The first valid nonempty read copies the **entire** admitted body privately;
readiness is published only after exact completion. Later reads are bounded
memory copies. A failed or partial load never publishes readiness or partial
caller output and never falls back to the original provider.

The generic helper accepts a caller-validated identity and immutable byte view.
Production integration supplies the validated mount route hash, canonical file
name, sector start and byte length. Identity plus size weakly deduplicates live
views. Existing resident wrappers and their bounded slices retain their original
extent and reservation, including before loading completes. A ready probe
recognizes only the private resident/bounded wrapper types; it never calls an
arbitrary provider's `read()` or `size()` to guess residency.

`AudioClipLoader` prepares its clip from this view on its existing asynchronous
worker. Its header/tail parsing therefore follows the full immutable body copy,
and a ready ticket cannot precede complete-body availability. Production callers
already supply canonical resident wrappers. Generic finite loader callers use
unique anonymous identities instead of guessed filenames or provider addresses.
Admission, allocation and source errors publish a failed ticket rather than
leaving it pending after a worker exception.

Direct `Clip::prepare` calls outside this loader keep their previous behavior.
Unknown file-backed byte views remain outside the resident profile. The separate
adaptive backend must use the readiness probe before selecting an immediate
memory-read path; the lazy first load still belongs on an asynchronous worker.

## Bounds and ownership

- Maximum admitted view: **32 MiB**.
- Shared live reservation budget: **2 GiB**, including lazy and failed views
  still retained by callers, clips or bounded slices.
- Expired identities are pruned; the cache holds weak view references.
- A view retains the budget state through static destruction and returns its
  reservation only after its backing allocation/provider ownership is released.

Construction of one cache entry is coordinated separately from body loading.
Provider I/O and provider/control-block destruction occur outside the registry
lock. The full body has its own materialization lock, and provider destruction
also happens outside that lock. Concurrent same-key constructors share one view;
concurrent body readers perform one provider copy. Allocation rollback completes
before the factory releases its original provider reference.

These are resident-cache bounds, not a whole-process memory guarantee. Existing
native buffers, caller/provider memory and OS file caching have separate costs.
Cold full-body reads can delay readiness; the game integration must preserve
startup synchronization and expose preparation failures honestly.

The verified File #1 inventory contains **8,916 recognized ADX entries**, all
below this per-view ceiling. The largest is `s413900a.adx`, **22,366,854 bytes**;
E3 is 11,081,142 bytes. This is an all-inventory size audit, not a claim every
recognized header/codec/loop profile is admitted by every consumer.

## Verification

Both compilers pass the dedicated cache tests, all **220 existing clip-loader
checks**, and the complete cue-queue suite. Asynchronous observation/check totals
vary with scheduling; the retained receipts report their exact counts.

The cache tests establish lazy construction and probing, complete nested-slice
contents, concurrent identity/read deduplication, failed-load isolation,
allocation-failure propagation, provider-destructor reentry and unrelated
construction during a blocked body read. They fill the 2 GiB reservation using
64 lazy 32 MiB test views without allocating those bodies, verify overflow
refusal and deduplication at the limit, and prove a small retained slice keeps
its parent's complete reservation charged until final destruction.

The loader test blocks the actual full-body provider read and verifies pending
status and false residency. Two loaders share one canonical pending asset;
both become ready only after release, perform one complete original read and
retain byte-identical content after the original provider disappears.

The queue regression retires an obsolete expectation that a source read must
block *after* metadata readiness. It instead prepares the complete body, arms
the original provider to throw on any later read, and plays the native queue to
EOF. Every payload digest matches the unarmed native reference, no original read
occurs, underruns remain zero, and a replacement reaches its own EOF after actual
retirement. The old test source remains retained. An initial replacement
predicate accidentally accepted the previous source's retained EOF snapshot;
the corrected predicate requires the second source generation/start before EOF.

These checks establish immutable resource preparation and ownership. They do
not identify the old operating-system read delay, prove physical audibility or
substitute for the next actual game and complete synchronization retests.
