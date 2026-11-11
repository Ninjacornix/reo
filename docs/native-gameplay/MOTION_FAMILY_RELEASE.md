# Partial motion-family retirement and default restoration

The scene-entry audit found a production omission and an incorrect fixture port:
1B1DF0 was described as work-buffer preparation/release. Its complete body instead
calls1B1CB0(0), which performs actual partial motion-bank release, then clears the
default-loaded flag. The earlier native `ensure_base` reloaded PC_000 without that
release. The historical comparison port hid those effects. Its default-restoration
coverage claim is superseded by this correction, made before native game installation.

`MotionBank::clear_family` now reproduces complete1B1C20 using the owned234410
table. Unlike whole-bank clear, it preserves first track, count, kind and existing
header admission. These are literal family profiles; additional semantic names
are not inferred.

| Family | Logical rows cleared | Physical token slots released |
| --- | --- | --- |
| 0 | 100..299 | 5..999 |
| 1 | 300..1999 | 1000..1999 |
| 2 | 0..99 | 1000..1999 |

Every other row and token remains. Zeroing a logical row is not a promise that
every subsequent lookup is absent: the source's actual lookup formula still
applies to retained reserved slots. Unknown families refuse before mutation;
partial clear cannot manufacture a known header for a default-constructed bank.

`HumanoidMotionAssets::release_base` prepares one immutable child publication for
complete1B1DF0: family0 release in the shared ordinary/head bank, alternate bank
and all prepared character banks, with the default-loaded gate cleared. Primary,
scene-body and scene-face banks remain unchanged. `load_defaults` now performs the
same cleanup before its PC_000 conversion. Old snapshots and block leases remain
valid; changed character stores receive new publication identities.

The original fixture now executes complete1B1DF0/1B1CB0/1B1C20 and uses the exact
owned family table. Only pair-cursor reset1B2CE0, file acquisition, raw packing and
heap identities remain declared observation ports. The full shared global-family1
wrapper is not newly supplied by this component; the required scene/default
family0 wrapper and all three bank-local profiles are the admitted operations.

Both compilers pass436,495 bank checks, including nine family cases across warm
sparse, strided200 and strided500 banks. They compare every retained/cleared slot
and row with the complete original bodies, verify exact original release counts,
repeat clear and invalid-family refusal. The paired shared-bank cohort passes
317,927 native checks plus13,661,821 original checks over948 bank cases. It checks
all eight character stores, actual scene/head restoration and independent old
leases. The live publication cohort passes35 checks, seven publications and55
rebindings, preserving model/channel state through the new global cleanup.

Evidence is `motion-family-clear-{llvm,gcc}-v1` and
`humanoid-base-release-{llvm,gcc}-v2`, with current primary-model and initialization
regression cohorts prefixed `base-release-primary-*`. The combined seal is
`native_motion_family_release_qualification_v1.json`. Complete scene-entry/exit
ownership, remaining cinematic consumers and installed acceptance remain open.
The installed game is V39; no game was run and no slowdown attribution is claimed.
