# Native weapon program selection and curves

The canonical Actor now retains an immutable imported WMD bank. Its actual
`ResourceModel` attachment owns program phase, signed elapsed time, seven
completion bytes and the selected native program. `WorldResourcePrograms`
implements complete6B4420 using the existing World and SceneResources; reached
`NativeConsumer` events use that concrete owner. No second resource pool or
guest-addressed program state is added.

There are16 owned weapon program assets,120–736 bytes each.6B4AE0 clears a2KiB
asset slot before loading `data/rom/motion/weapon/wp%02d.wmd`; import preserves
that bounded zero padding. The files do not all contain ten header offsets.
For example, wp00 has key data where later selector words would be. Import
distinguishes a zero offset from an unavailable tree. It admits only bounded
parts, curves, finite values and ordered integer times. Unsupported reached
selectors refuse instead of producing a made-up empty program.

The selector preserves the source category guards, the descriptor parameter's
zero/nonzero test, nonzero-style selection, phase transitions and partial resets.
NPC selection only clears the phase. An empty selection clears the phase but
preserves prior time/completion bytes; an actual program resets both. Modes
other than0/1/2 use the source fourth pair. Missing/foreign actors, absent source
profiles and unrecognized native resource capabilities fail visibly.

The native sampler implements full6B4A30: the first strictly later integer key
chooses the segment, values clamp before the first key, and reaching the last
key returns its value with completion. It preserves source32-bit subtraction
and the original FP32 interpolation order. The importer and sampler read
typed immutable values; the original register context exists only in tests.

Each compiler passes11671463 checks, retaining45056 earlier primitive cases.
New comparisons cover73444 admitted selector calls and284 reached unadmitted
cell refusals, plus missing-source/foreign-actor guards.83 distinct owned curves
are sampled at all65536 signed16-bit times:5439488 exact value/completion
comparisons against full6B4A30. Raw owned bytes independently check imported
keys and offsets. Eight full596470 event cases exercise the concrete owner and
kind5's auxiliary-bit clear order. Parent libraries and four World/body/
collision/contact checks pass on both compilers.

This checkpoint supplies selection and scalar sampling. Full6B45C0 visual
updates, common5932F0 resource work, actual WMD loading on weapon changes,
resource construction, game installation and whole Stage4 acceptance remain
open. In particular, these results do not establish that an original invalid
selector is reached during normal play, nor that a recorded stutter was fixed.
