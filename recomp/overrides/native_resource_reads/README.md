# Synchronous native resource payload pilot

This isolated File #1 Windows adapter replaces only an exact resource payload
attempt below the existing N-command RPC handler. It does not implement the RPC
reply, original callback, DVCI/SRD state machine, worker or asynchronous guest
target lease. Root bootstrap/bridge wiring is separate.

Build feature `REO_BUILD_NATIVE_RESOURCE_READS=1` is required; absent/numeric-zero,
other-edition and non-Windows headers provide no-op/uncovered stubs. The actual
external-worker runtime patch is mandatory for an enabled object.

`configure(serial, ram, bytes, runtime, dataRoot)` must run after final ELF load
and before guest execution. It requires exact environment values
`REO_NATIVE_RESOURCE_READS=1`, `REO_GAME_PAK=1`, `REO_CD_ASYNC=0`. Thus neither the
native CD worker nor the old detached CD target path is admitted. Loaded original
text identities are pinned for `101788..101967`, `1004D8..10058F` and
`100298..100337`. The Windows mount factory verifies the import and optional
wide-character `REO_ASSET_OVERLAY` plan. The bridge must also validate the mount
against its actual retained legacy CDVD facade layout before registration.
The setup report contains actual manifest/overlay/route digests and source count,
not merely saved configuration. Failed setup leaves the legacy handler available.

`tryRead(ram,runtime,send,size,receive,receiveSize,ok)` is called **only** for service
`80000595`, RPC `1`, while the original RPC mutex and guest execution remain held.
It verifies actual guest-scope depth and never releases that scope, invokes a
service/callback or retries original work. `false` means uncovered before native
I/O/destination publication, leaving `ok` unchanged. `true` consumes the attempt;
the caller uses `ok` while retaining its existing reply/callback policy. Typed
native failures return `true,ok=false` and must not restart legacy I/O.

This is successful-read parity within the admitted domain. Failed-read bytes
deliberately differ: the legacy PAK facade zeroes output before I/O and can leave
a partial prefix, whereas ResourceSession preserves the previous destination.
The current bridge logs `ok=false` but retains its original handled reply and
completion callback. No guest-visible DVCI error is synthesized. Correct error/
status publication remains an open gate before broader/default admission.

Admission requires packet `207A00`/size `18`, zero receive arguments, data-pattern
byte `packet+0E == 0`, packet pointers `+10 == 208A00` and `+14 == 208AC0`, and zero
head/tail edge-copy counts at `208A00/+4`. Counts are positive, at most `4000`,
and must fit the reader's 8 MiB cap. The positive 64-byte-aligned whole-sector
destination lies wholly inside normal 32 MiB RAM and cannot overlap:

- Packet `207A00..207A17`, client `208AD0..208AF7`, end block `208A00..208A8F`.
- Any of the three pinned original-text intervals above.
- Conservative SRD/DVCI control span `21BB88..21D8EB`, including forty DVCI records
  at `21CC60` stride `48`, their following scratch data and mode/verbosity words.

The reader additionally refuses unknown, oversized, padding-only or partial-EOF
routes before I/O. These exclusions intentionally preserve legacy coverage;
they are not a proof about every unrelated guest global or code address.

A weak registry under a short mutex locates the session. Runtime registration
strongly retains it. Each synchronous read retains that session/reader and an
in-flight lease until return. Stop only sets an atomic flag; join waits for those
leases without guest/RPC/reader locks, and TLS rejects self-join or nested read
reentry before waiting/I/O. Reader/file lifetime may extend to session destruction
after join. Configure is a bootstrap operation, not live reconfiguration; an
attached runtime remains one-shot under the external-worker patch. The caller
must keep runtime/RAM alive through calls and serialize/synchronize destinations.

`retain_mount_before_run` hands media consumers the same validated immutable
mount. It takes the runtime's real pre-run setup lease, checks the configured
runtime/RAM incarnation and refuses guest execution, late/stopped setup and
foreign identities. The aliasing strong handle retains the existing reader's
mount and files, without another mount, environment lookup or read. It exposes
no runtime, RAM or guest callback. Consumers resolve retained native ByteViews
and own their worker stop/join; a file-only lease may outlive the runtime.
See [the resource handoff evidence](../../../docs/native-media/NATIVE_MEDIA_RESOURCE_HANDOFF.md).

Sampled payload counters are emitted only after exact successful native reads.
They prove payload attempts, not the later original reply/callback, SRD/DVCI/SJ
publication, complete route coverage or a performance improvement.

Host checks use synthetic runtime/RAM/reader/facade services. The pinned owned
ELF contributes only three identity byte intervals in ignored output; no original
instructions or actual imported files are executed/read by the mock factory.
Both GCC and LLVM can run the same checks:

```powershell
python -B recomp/overrides/native_resource_reads/tests/run_checks.py `
  --cxx C:/msys64/mingw64/bin/g++.exe `
  --output build-native-sjuni/native-payload-checks/gcc `
  --runtime-headers build-native-sjuni/dependency-workers-reapply-v2
```

Real-header mode compiles one actual adapter object without linking a runtime or
game. Its existing runtime inline unused-local/parameter warnings have explicit
exceptions; the isolated adapter/harness builds use all requested warnings as
errors, including `-Wpedantic`.
