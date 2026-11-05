# Standalone host output lifetime owner

Status: implemented and isolated-tested on 2026-11-05; no actual provider binding,
native backend installation, device opening or game validation. This is one
piece of [complete PCM backend installation](PCM_BACKEND_INSTALLATION.md), not
its completion.

The implementation is
[game/native/audio_output](../../game/native/audio_output/README.md).
`Owner`, `CallbackSlot`, `Provider` and `Renderer` are a deliberately small C++20
boundary. They manage one host stream and callback route, independently of
device ownership, PCM queues, bank voices, guest RPC state and facade selection.

## Lifetime and admission

Construct a source-qualified provider, a renderer with bounded callback work,
and an externally stable `CallbackSlot`, then call `Owner::create` and `start`
outside any audio callback or guest/PCM/bank/registry lock. A source mismatch or
missing provider/renderer is rejected. The hash check prevents accidental
revision mismatch; a provider's self-reported hash does not prove its contract.
No real raylib adapter is supplied by this change.

Before provider attachment, the slot receives a strong owner reference. Each
dispatch copies that reference under a short slot mutex and releases the mutex
before calling the renderer. The owner uses one lock-free 64-bit atomic whose
high bit closes admission and whose remaining bits count admitted callbacks.
Callback admission and stop have one atomic modification order: either admission
wins and the callback remains counted through render, or stop wins and the
renderer is not entered. A stopped callback writes silence for a valid bounded
float32 stereo buffer. Null output and requests over 512 frames are rejected
without touching the buffer; a qualified real provider must honor the source
bound and must not submit such requests.

`request_stop` performs only the atomic close operation. It never waits, locks
the provider, detaches, frees storage or drops a strong reference. It is safe to
repeat during a paused callback. A start already executing when stop is
requested can finish its attachment; callback admission remains closed, and
`join` serializes behind that start before cleaning it up. Stop does not cancel
an already admitted renderer invocation.

The owner itself does not allocate during dispatch: strong-reference copying,
atomic admission/accounting and at most 512 stereo frames of silence are the
complete wrapper work. Renderer internals must independently honor the bounded,
no-allocation contract. Short mutex synchronization and operating-system
scheduling mean this is not a hard real-time latency guarantee. Under the
pinned provider's serialized callback execution, a strong admission CAS can
race only the monotonic stop transition, rather than unrelated producer work.

## Fence, retry and lock ordering

`join` first closes admission and refuses to run provider operations from this
component's callback trampoline. A thread-local callback-depth marker covers
joining this owner or another owner from the same callback, since both could
invert the process-wide audio-system lock. A callback self-join returns
`callback_thread` and leaves shutdown pending for an outside control thread.
The eventual adapter must also prohibit control calls from other audio callbacks
that bypass this component's marker.

An outside join serializes provider control using a lifecycle mutex which the
callback never acquires. It executes successful callback detach/fence, drains
its counted admissions, stops the stream and unloads it, in that order. It then
clears the strong slot reference. A temporary strong reference keeps the owner
alive through control operations; removed references are destroyed outside the
slot and lifecycle locks. Simultaneous and repeated joins serialize and return
`joined` without repeating already successful provider operations.

Each failed detach, stop or unload returns an explicit incomplete result and
retains the owner/provider/renderer route storage. Retrying resumes the first
unfinished step. The supplied provider must guarantee that failure leaves that
step retryable: a failed attach publishes no callback and has no remaining
active callback from that attempt; a failed unload must not have consumed its
resource. These semantics are interface requirements, not assertions about
arbitrary provider libraries. The pinned raylib functions are void; a future
adapter should return success only after its valid call has completed, rather
than inventing timeouts or retrying an uncertain partially completed unload.

The slot must remain alive until successful join and all legitimate trampoline
callers have returned. Dropping an external owner reference before join does not
free it: the published slot intentionally retains it. There is no implicit
blocking destructor cleanup and no timer that discards a failed-fence lease.
The application must retain the control path needed to retry and join; it must
not destroy the slot early. Manually captured callback pointers and provider
lifecycle changes outside the specified ownership are not admitted.

No registry, PCM, bank, guest/RPC or slot mutex may be held by a caller across
`start` or `join`. The implementation invokes provider methods with only its
independent lifecycle mutex held. Callbacks can take the eventual PCM/core locks
without forming a reverse edge through provider control. The component does
not serialize producer PCM calls; the enclosing selected backend still needs
its own producer admission and drain before resetting PCM/bank storage.

## Source-qualified provider boundary

The qualification is exact pinned raylib revision
`c1ab645ca298a2801097931d1079b10ff7eb9df8`, `raudio.c` SHA-256
`2d6a2d5b9f86b44b879605f654659c542a317d97477ddfde54683019e8bfeacc`.
Its relevant semantics are documented in
[PCM_BACKEND_INSTALLATION.md](PCM_BACKEND_INSTALLATION.md) and
[AUDIO_PROVIDER_CLOSE.md](AUDIO_PROVIDER_CLOSE.md):

- `OnSendAudioDataToDevice` holds `AUDIO.System.lock` across mixing and invoking
  the stream callback, including stream traversal with no active voices.
- `SetAudioStreamCallback(stream,nullptr)` acquires the same lock and therefore
  waits for an earlier registered callback before null publication.
- `StopAudioStream` and `UnloadAudioStream` follow the callback fence on one
  serialized provider-control path. Buffer unload first untracks under the
  system lock, then destroys converter/storage.
- The source input buffer is 4096 bytes, bounding a float32 stereo callback to
  512 frames. This does not establish arbitrary public render sizes.

The future no-userdata raylib trampoline must use the stable session slot and
retain it until real detach/unload return. Device initialization/recreation and
shutdown remain separately owned by the application. Stream join must precede
device teardown; this owner never calls `CloseAudioDevice` and a false
`IsAudioDeviceReady` is not a fence receipt. The staged provider close-order fix
remains a separate coherent-build requirement.

## Isolated evidence

GCC 15.2.0 (MSYS2 Rev8) and bundled Clang 21.1.8 both compiled this component
and its fake-provider tests with `-std=c++20 -O2 -Wall -Wextra -Werror -pthread`.
Both passed five deterministic cases:

1. A callback paused in render retains the owner after external references are
   dropped; repeated stop is immediate, detach waits, join/unload happen after
   release, and later concurrent joins repeat no completed teardown steps.
2. Stop wins before a callback reaches admission while holding the fake device
   lock; detach waits, render is never called, and the bounded output is silent.
3. Failed attach, detach, stop and unload are individually retried; leases remain
   after incomplete join and successful prior teardown steps are not repeated.
4. A callback's self-join is refused without entering provider control, and an
   outside join subsequently completes.
5. Wrong source identity, null provider, occupied slot and invalid callback
   bounds are rejected; joining an unstarted competing owner does not remove
   the active owner's slot.

The private receipt is `build-native-sjuni/audio-output-owner/receipt.json`.
These tests model the pinned provider's synchronization contract. They do not
link raylib, prove an actual device callback's behavior, install the native PCM
backend, validate audio/movie output, or retire the PS2 runtime audio path.
