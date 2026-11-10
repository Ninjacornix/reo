# Actor color fades and admitted offline resume

`ColorFade` owns the primary actor's packed color, step and update count. The
source6656E0/665730 setters establish the meaning: white RGB, alpha in the high
byte and an integer quotient shifted into that byte. This is a native color
value, not an array preserving the guest work layout. Other actor families reuse
the source offsets for different state; they do not establish this capability.

Both setters and665640/665690 advancement preserve source unsigned arithmetic,
including zero-count underflow on advancement, duration-dependent zero steps,
expiry colors and auxiliary flag masks. Start duration0 is an explicit native
preflight refusal with no effects; no physical PS2 zero-divisor behavior is
claimed. Missing fade state is unavailable when the active flags need it.

Complete6655F0 supplies the finish policy: increase4000 wins over decrease8000,
even when the first operation expires. `ColorFadeFrameServices` owns that actual
`World::update_primary` finish point, after grid work and before pending action
publication. It does not forward the stage to an opaque provider. Other frame,
AI, pose and collision owners remain required. This does not install the new
World in the game or implement the Stage5 renderer's color submission.

The offline668F20 consumer now handles its original no-op gates and the paths
where819880's status8/80 checks reject scene reconstruction before any scene work.
The canonical BD0 byte clears before that selection. A room mismatch hides the
actor, clears the fade flags and resets this same color owner to opaque white;
the source action/status and pose capture follow. These paths also bind through
the actual interaction request consumer. Successful scene/navigation selection
still requires its real native owners and refuses explicitly after the measured
prefix; it is not a successful fallback.

Both compiler comparisons cover1775616 fade cases,65536 finish-policy cases,
4096 real World frame compositions and1756 admitted offline resumes. The
combined sender/control/hit/event comparisons and focused receiver/equipment/
queue regressions pass with current sources. Both parent builds and eight
integration checks pass. The full VM and outer scheduler comparisons are retained
at the preceding [control-state qualification](ACTOR_ROOM_CONTROL.md); they are
not claimed rerun for this isolated addition.

Successful offline navigation and scene reconstruction, actual higher action/AI/
VM callers, native semantic saves, external transport and coherent game
installation/acceptance remain open. Installed V39 is unchanged and Stage4 is
incomplete. These were headless comparisons, without a game launch or measured
performance-fix claim.
