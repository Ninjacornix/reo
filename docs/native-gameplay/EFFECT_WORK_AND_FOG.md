# Shared native effect work and fog

This offline checkpoint extends the existing periodic visual owner. It does not
install native gameplay, submit rendering, prove a speedup or complete Stage4.
All work families below use the same168 native identities and256 child slots.
There is no extra capacity per factory or a separate fog-companion allocator.

`PeriodicVisuals` now implements the actual ordinary653010, oriented6531D0 and
scaled653E80 consumers alongside periodic6535C0. Owned geometry, transform and
material tracks, optional copied basis, flags and signed lifetimes come from the
real constructor. Variant selection consumes the canonical session RNG only
after a successful main allocation and only for the original -1/count-positive
case. Contact callers supply variant0; their a2 argument is a child-enable mask.
`WorkBackend.bound_to` enforces the same RNG identity for contact producers.
Earlier populationv1 mask/variant and artificial constructor-RNG claims were
incorrect and are superseded by populationv2 and the real backend comparisons.

Ordinary and oriented work preserve delay/visibility, pre-sample expiry and age
order. Scaled work samples before decrementing lifetime, preserving its distinct
final frame. Oriented work consumes its one source RNG request and applies the
extra angle only to child1. Scaled attributes retain exact angle addition, scale
multiplication, material factor and child color rules. Both1919D0 and191A40
transform directions through basis axes; they do not add basis translation.
The first new native draft did add it, and the full original comparison caught
that error before qualification. Camera-relative ordinary work uses the complete
191430 inverse-basis arithmetic within an explicit finite, nonzero-axis profile.
Unknown numeric profiles fail visibly; no physical PS2 exceptions are claimed.

Checked edit leases retain work storage but reject retired generations and owner
shutdown. Feedback implements real652F90 propagation to allocated children,
preserves scalarA8 separately from periodicF0, and applies23E|100. Pool/resource
misses remain distinct from unsupported providers. Immutable published frames
retain bank/resources across retirement, and the reader test now waits for an
actual acquisition before completing its writer loop.

The previous track resolver treated byteFF as always unavailable. EF35 disproves
that assumption: the original652E20 has no FF guard. Its owned group255 header
at efdata35 byte6124 is complete, has zero parts and lifetime12; its large unused
part offset is never dereferenced. Native Tracks now admits that bounded empty
record. It does not synthesize intermediate groups or admit other banks' unsafe
nonempty headers. Seven selected EF35 logical IDs now create real empty visuals
and run their measured lifetime, preserving allocation and sound behavior.

`gameplay_scenario::Fog` owns the loaded sixteen-record catalog, selected index,
distance/color/direction/parameter values and flash state. Full6B23E0 import and
6B2200 selection preserve cached selection, ignored-version clearing, tail color,
packed bytes and all published values. The229 physical owned FOG assets include
four version1 files that the original ignores; this is preserved explicitly.
`FogPulse` supplies full654D90 delay, ramp, refreshed baseline, retrigger, restore,
RGB conversion and selected-fog refresh. The type1D companion lives inside the
same effect owner. Existing companions refresh phase10 even when the pool is
full. Its actual Fog owner must outlive this borrowed effect owner.

LLVMv15/GCCv2 each pass3,888,287 checks using identical captured sources:
732 general visual creations and24,316 frames across all six owned bank pairs,
492 measured natural resource misses and zero unadmitted selected profiles;
687 fog imports,175,872 selections and3,496 full pulse steps; plus all existing
periodic timing/camera/signed-timer/task and concurrent-reader comparisons.
They execute20,425,446 complete original/helper calls with97,674 balanced private
resource allocations/releases. Exact commands, source copies and owned instruction
audits are bound by `native_effect_work_qualification_v1.json`.

Failed exploration remains retained: missing original trigonometric/fog constants,
four ignored fog versions mistaken for valid version2 by a test, GCC fixture
format warnings, an unscheduled-reader test and a concurrent interface hash
change. They are not passing receipts or attributed gameplay faults. The final
source snapshots distinguish these fixture corrections from production changes.

Actual contact-population composition is checked separately. Canonical gameplay
modulation producers/type17 work, positional sound routing/native output callers,
other effect families and source task integration remain open. The render-facing
immutable values form a Stage5 interface; there is no successful renderer or
audio placeholder here.
