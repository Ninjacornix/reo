# Native player attenuation checks

Both compiler builds pass **74 native suites**. The stable instance fixture now
has five workflows, including actual workers with AINF offset -25, attenuation
changes before header readiness, live request narrowing/fades, a separately
rendering peer, replacement during a blocked read, stale keys and fresh defaults.
The volume is already correct when the player is configured; source frequency
stays 48,000 and muted samples continue advancing normally. Four existing
ownership faults remain detected on each compiler.

The combined PCM/bank/master model passes 15 scenarios on each compiler, now
including the attenuation profile through the guarded controller and actual
callback. Its null-native profile still matches all qualified parent observations
in 21 cases, retaining the same 14 raw terminal-policy differences.

The actual-import handoff tests also pass on both compilers with the owned table.
Requests -100 and -200 produce raw integer volumes **80 and 25**. The mono/stereo
sources still match the independently qualified payload counts and PCM digests,
with zero output underruns and clean private/source retirement. The declared
runtime/RAM, native mount/tree facades and caller's table reference disappear
before playback completes. No actual audio device or guest scheduler is used.

`tools/native_reconstruction/adxt_attenuation_player_qualification.json` records
the exact 403-input source cohort, compiler/archive identities and ten receipts.
The original arithmetic/table comparison remains separately qualified against
1,856 non-null original cases, before this player integration was authored.

This first table-player cohort admits finite and regular-loop sources. Its
explicit seamless/LSC refusal is conservative pending examination of their
prepared clip invariants; it is not silently converted into successful playback.
Actual guest source/control/reset/scheduler consumers, runtime publication and
live A/V validation remain Step 3 work. This change does not diagnose or claim
to fix the previously measured RPC initializer stall.
