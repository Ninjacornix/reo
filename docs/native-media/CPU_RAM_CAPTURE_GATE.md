# Conservative CPU-authoritative RAM capture gate

Status: bounded admission core and conditional actual graphics-Service
instrumentation implemented 2026-11-06. Both compilers pass isolated checks and
compile the actual Service constructor. No linked game, graphics device or real
bank capture factory has used this gate.

The first supported capture profile can be narrower than the general read-lease
design: refuse capture for **any** backing that has attempted to construct an
advanced graphics parent Service. This avoids reading unpublished or GPU-opaque
values altogether. It covers a Service without a NativeTarget, and queued work
such as `191280` before its results enter an opaque-range table. It does not
need to dereference a potentially retired Service to inspect its internals.

[Coordinator](../../game/native/ram_capture/cpu_authority_gate.hpp) has fixed
metadata for 16 backing identities and 16 simultaneous CPU groups per backing.
The backing pointer is only a registry key, not a Runtime identity, memory
lifetime guarantee or proof of CPU authority. Tokens, counters and thread IDs
allocate no dynamic metadata. CPU tokens are synchronous and thread-confined;
the coordinator must outlive all tokens and calls.

One CPU group spans all related copies, for example HD/BD/TQ. The registry lock
is released before those copies; the group retires before decoding, provider or
other callbacks. Actual guest execution, mapping lifetime, address validation,
disc-writer seals, control-write provenance and other writer exclusions remain
the caller's separate obligations. No arbitrary memcpy factory is installed.

The actual
[Service](../../tools/parallel_gs_backend/resident_geometry/parent/parent_owner_service.hpp)
conditionally declares its GraphicsActivity first and initializes it before
other members when `REO_BUILD_NATIVE_SOUND_RAM_CAPTURE` is defined. The base
`protocol::Backend` is a data-free interface with no RAM-affecting constructor.
The guard therefore precedes producer/transport creation and dies after every
other Service member. Existing owner shutdown still has to retire actual work;
the guard itself neither fences Vulkan nor joins workers.

A graphics attempt closes new CPU admission before waiting for existing groups
to finish. This wait belongs outside guest/RPC/source/protocol locks. A same-
thread wait refuses explicitly. Once the last bounded copy releases, normal
graphics initialization proceeds. Subsequent CPU capture remains unsupported
for that backing **for the rest of this process**, even after graphics objects
retire or construction fails. This conservative exclusion prevents an old
CPU-authority assumption from reappearing; it is not a GPU-to-CPU ownership
transfer or a general opaque-memory readback implementation.

## Verification and limits

GCC and pinned LLVM each pass **79 assertions**: finite domains, move/replacement
counts, self-wait refusal, pending graphics exclusion before any opaque
publication, grouped three-part copies, initialization waiting and final-member
destruction ordering. A global C++ allocation-denial probe covers actual metadata
operations. A Service-shaped negative variant omitting its lifetime guard fails
the pending-state check; it introduces no intentional data race. Source-placement
checks also reject removing the actual Service constructor's guard initializer.

The actual Service constructor is compiled with capture instrumentation enabled
against the qualified fresh 125-source SDK and immutable sealed V8 graphics
headers. Both receipts qualify **166 included project/SDK headers**, reject
dirty active or old SDK headers, verify patch/source inputs, and record empty
source/include postchecks. These are real header objects, with unresolved Vulkan
and gate dependencies; no graphics Service is constructed or device opened.

| Private receipt below `build-native-sjuni/ram-capture-gate` | SHA-256 |
| --- | --- |
| `gcc-proof-v4/receipt.json` | `5a80cf49490502dec52508de3320040df046131a27dfd0568c8360b939cfee1a` |
| `llvm-proof-v4/receipt.json` | `ca6eecda8896e6fe6ef2471e3c5c195dcb360b1be616feee745299febf0f5c63` |

The earlier raw Service-header cohort and receipts remain in ignored outputs.
V4 reruns the complete checks with the canonical LF header bytes that Git stores;
this avoids presenting a prior CRLF working-copy identity as the committed cohort.

The combined standalone CMake project now includes this target; its selected
CTest passes under both toolchains. The game CMake/bootstrap/preparer do not yet
enable or link the capture profile. A future private candidate must prove that
**all** Service-instantiating units use this flag and matching sources, establish
actual graphics instrumentation capability, and close the complete RAM-writer
catalogue. Absence of a registered target alone remains insufficient.

The [disc configuration seal](CD_RAM_CONFIGURATION_SEAL.md) and this gate address
different writers. The [SDK companion design](NATIVE_BANK_CAPTURE_CAPABILITY_DESIGN.md)
still requires earlier ABI/transport/query/IOP status capture and versioned
grouped bank capture. General coexistence with active advanced graphics ownership
would need the stronger per-target/protocol/storage read/write capability; this
first profile deliberately refuses it.
