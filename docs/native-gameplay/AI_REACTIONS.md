# Native AI reaction scheduling

2026-11-10: complete8130D0 now schedules native pending reactions through the
same canonical Actor execution component and Session RNG. Stage4 is incomplete;
the installed game remains V39.

The owned generator decodes thirteen signed policy triples and eight authored
character chance columns after asserting the exact original jump/pointer table
contents. Native production stores logical policies without guest addresses.
Events0..4/9..11 test inclusive modulo100 chance and optionally a second chance;
5..8 use the first strict maximum of combined weights, with zero weights choosing
index0. A matching policy index needs one chance draw; other winners select the
source deterministic reaction. Event12 writes directly. IDs>=13 are source no-ops.
Scheduling changes pending reaction/countdown; it does not advance its timer or
change the current reaction. The source's exact number and order of random draws
are preserved.

Characters8..255 have no authored chance columns. Native calls requiring those
columns refuse before effects/RNG advancement. Deterministic branches remain
available. These native admission refusals are separate from original comparisons.

Both compilers pass129,158,736 identical checks including895,957 complete reaction
comparisons,1,014,101 original/native RNG draws and680,504 scheduled writes. All
65,536 initial primary RNG states are compared for each of thirteen events, plus
all character chance columns, byte-weight maxima/ties, unsupported events and
2,976 native refusals. Complete original1AEC80 executes with no RNG substitute.
Whole actor ranges and surrounding RNG bytes compare. The original-only fixture
needed HI/LO division registers; failed v1 evidence is retained and v2 passes.
Twelve current parent tests pass per compiler, including canonical Session RNG,
missing state, actor retirement and closure. Qualification is recorded by
`qualify_gameplay_ai_reactions_v1.py` in
`native_gameplay_ai_reactions_qualification_v1.json`.

Observation production/timer consumption, remaining callbacks and coherent native
game acceptance remain open. No game launch or performance measurement was used.
