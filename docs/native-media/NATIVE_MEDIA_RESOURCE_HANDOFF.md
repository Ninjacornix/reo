# Validated resource mount handoff to native media

The native resource adapter now exports a bootstrap-only strong handle to its
existing immutable mount. This is an implemented ownership boundary, not a
claim that game ADXT/movie calls have been migrated.

The handoff checks runtime/RAM identity, complete RAM extent, absence of guest
execution, the actual runtime's pre-run setup lease and the configured session's
stop state. It neither reopens paths nor performs provider I/O or a second mount.
The returned alias owns the existing reader and its mount. It retains no runtime,
RAM or guest callback. Resolved native views can retain their own file providers
after the mount handle goes away. Consumer workers retain their independent
stop/join obligations. Stop prevents new handoffs; previously handed immutable
file data remains valid and is never interpreted as live runtime state.

Both compilers pass 25 adapter checks, including the real-header object build
against the independently reapplied 130-patch SDK. The runtime/bridge/reader test
ports check refusal before configuration, foreign identity, wrong RAM/extent,
guest entry, sealed setup and stopped setup, plus separate old/new incarnations.
An alias must share the reader's actual control block and keep it alive after
the declared runtime's destruction. These are adapter/lifetime checks, not a
second qualification of the real runtime's lifecycle implementation.

A separate actual-import check uses the unchanged Windows mounted-file provider,
the same adapter handoff and the V4 native library cohort. Only runtime/bridge
services are declared test ports. The real factory validates and retains all 85
installed routes; its bridge-layout acceptance is an explicit test port, not a
new game-layout measurement. Original ELF identity slices are checked as data;
no original instructions, game, scheduler or device are executed.

The declared runtime/RAM are destroyed before either source starts. Native AFS
trees resolve two independently inventoried members, then disappear. The mount
handle is released before servicing either source. Real native mono/stereo
workers finish through one canonical instance Session and private output render
lease, and actually retire/join. Their source extents, complete payload counts
and PCM byte digests match the independently qualified native decoder baseline:

| Member | Source bytes including retained sector tail | Payload samples per channel |
| --- | ---: | ---: |
| `NETBIO01.DAT/0/409/0` | 18,432 | 30,747 mono |
| `NETBIO01.DAT/0/39` | 215,040 | 189,476 stereo |

Both compilers produce the same source/PCM observations and 189,952 model output
frames with zero underrun frames or skipped samples. They prove the private
submix fence, with `provider_joined=false`; no actual device is fabricated. Input
file identities/size/timestamps and the import manifest remain unchanged. The
test deliberately consumes at a deterministic unpaced rate with caller tick zero;
it is not an A/V synchronization, latency or speed measurement.

`tools/native_reconstruction/media_mount_handoff_qualification.json` identifies
sources, native archives, compiler identities and all four new receipts. Actual
game source/control/scheduler binding and live transitions remain Step 3 work.
