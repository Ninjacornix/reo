# Cinematic object motion banks

Status: component qualification passed on LLVM and GCC; uninstalled. Step4
remains incomplete. No game was launched or speedup measured.

`CinematicObjectMotionAssets` implements1D1E00's separate object bank preparation.
It selects `motion/demo/rNNN/bNN.bin` by destination scenario and request area.
Request scene/suffix do not select different object banks. All52 members use
exact owned ROM alias ordinals; duplicate AFS display names are not identities.

Reads happen outside simulation. Missing/empty files and I/O or parsing failures
retain the previous immutable bank and return an explicit status. A successful
load copies the previous bank before applying the existing qualified literal200
strided parser. Absent rows retain previous slots; old banks and block leases stay
valid. The loader does not clear or publish a live scene bank or change clocks.

Both cinematic-object-motion-assets-{llvm,gcc}-v2 cohorts pass230,928 checks.
All52 actual owned members load cold and in sequence:104 loads,1,079 live-block
comparisons and677 retained prior-member slots.312 original1D1E00 calls cover
successful reads and zero/negative read failures. Complete1D1960/1D1500 execute;
headers and all2,000 slots match. Original I/O is a controlled actual-byte port;
raw-block packing/token allocation expose provenance rather than claiming full
original curve packing. Native blocks retain the exact bounded source bytes.

Six native fault/retention cases cover missing requests without reads, injected
I/O failure, successful absent-row replacement, malformed replacement, empty
replacement and a missing archive owner. The five dependent CMake parents pass
on both compilers and the new library builds through CMake. V1's GCC missing
explicit optional include is corrected; failed evidence remains retained.

Evidence: `tools/native_reconstruction/native_cinematic_object_motion_assets_qualification_v1.json`.
The existing scalar object consumer can consume these native banks, but actual
scene publication and model/clip pairing still need combined qualification.
Full scene phases/entry/exit, remaining actor/reaction/pose work and installed
native gameplay acceptance remain open. This component does not close Step4.
