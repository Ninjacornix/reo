# Nonattached resource poses

This follow-up closes the 1904A0/190020 branch of the native common resource
callback. It supersedes that specific missing-consumer limit in
[the first resource-frame checkpoint](RESOURCE_FRAMES.md). It does not install
the native resource factory or close Stage 4.

The original uses X–Z–Y rotations, with unsigned 16-bit turn angles converted
by 191F80. `reset_euler_axes_xzy` preserves the existing fourth component of
each basis column and the whole translation column. The following 190020 call
constructs a scale matrix and composes only basis XYZ through 1913E0. Its input
at source22C is a separate axis-scale vector; it is not the position at200 and
must not replace translation. The native model now owns that vector explicitly.
Retirement clears it through the same model owner.

Both compilers compare complete 5932F0, 1904A0, 191F80, 190020, 18FEB0 and
1913E0 bodies with the native callback. The new 262,144 pose cases test all
65,536 turn values independently on each axis plus a mixed-angle sweep, with
eight scale patterns including negative and signed-zero values. Every result
is compared bit for bit, including retained non-affine W and translation values.
The unchanged owned WMD playback cases run in the same fresh source cohorts.
Each compiler passes 49,584,917 checks, 190,464 playback frames and fourteen
explicit native safety/refusal cases. The original unit matrix and initialized
math constants are declared test surroundings, not a new guest-state dependency
in production.

Evidence is bound in `native_resource_frames_qualification_v2.json`. The older
v1 seal and its exact source copies remain historical evidence. Extended actors,
room-pulse queries, required resource reconstruction, secondary release, actual
asset/factory ownership and game acceptance remain open. No game was launched.
