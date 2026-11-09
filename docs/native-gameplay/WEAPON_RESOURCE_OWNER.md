# Native weapon animation and sound resources

Status: admitted native weapon-resource composition qualified. Not installed in the game; Stage4
remains incomplete. No game, audio device or game window is used by these checks.

The new `gameplay_weapon_resources::Catalogue` prepares the sixteen File1 WMD
members1260..1275 from the actual ROM archive before gameplay. Its immutable
native `WeaponProgramBank` objects replace the four mutable2KiB equipment buffers.
Preparation uses bounded resource reads; equipment refresh performs no WMD I/O.

`Owner::refresh` reconstructs1D3B00,5B4CE0 and6B4AE0 using the canonical World,
resource descriptors, ITEM templates and named-bank loader. Selected resource255,
inactive descriptors, template255 and signed weapon selector−1 preserve the
previous animation bank. An eligible change first publishes a cleared bank;
resource0 keeps that cleared bank, whereas a nonzero resource binds the prepared
bank. Unsupported selectors report unavailable after the measured clear prefix.
The admitted profile requires one of the four canonical primary actors.

Only session sound-loading mode2 suppresses enqueue. Other modes submit the
original `weapon%02d` name to the actual bounded background loader on port8..11.
A full/closed loader is reported separately from the committed animation change.
Animation selectors0 and51 have no corresponding named SND member in the owned
File1 sound archive; enqueue acceptance must not be described as a loaded bank.

The owner rejects an audio owner using another RNG or a loader belonging to a
different audio owner. Descriptor/model ownership remains generation checked.
Existing resource animation programs retain their original immutable source;
replacing the actor's bank does not silently retarget an already selected program.

The comparison driver audits complete original bodies against the owned ELF/o2
instruction words. Its two formatting ports accept only the actual format
strings. The source file-read port copies independently hashed owned WMD bytes
into a bounded cleared reference buffer; it does not claim a new comparison of
the original filesystem worker. Actual native preparation instead reads the ROM
archive through a retained, hash-verified ISO handle. Sound composition uses the
real loader, asynchronous resource worker, decoder, bank owner and mixer. PCM is
compared with direct installation of the same independently read SND payload.
Those underlying import/loader/mixer algorithms have separate qualifications.

Both compilers pass18,187,281 combined assertions, including3,072 equipment
refresh cases across all sixteen banks, four canonical actors, four loading
modes, inactive/missing descriptors and selected resources0/3/255. The actual
loader installs fourteen matching sound banks and reports two missing names.
Direct-install PCM comparison covers23,936 frames with494 nonzero samples.
Eight explicit refusal/lifecycle checks cover queue capacity, unavailable
selectors, incorrect archive/owner binding, stale actors and closure.
No WMD reads occur after catalogue preparation. Parent builds and all four
World/collision tests pass with LLVM and GCC. Exact receipts and source hashes
are sealed in `native_weapon_resource_owner_qualification_v1.json`.
Equipment attachment construction5B18D0, use/recipes/transfer, extended owners,
actual installation and game acceptance remain open.
