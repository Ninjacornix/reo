# Stock weapon selectors without WMD files: follow-up finding

Status: source/asset investigation; the native correction is not yet implemented
or installed. This finding follows the admitted resource-depletion checkpoint.

All five owned ITEM sections contain29 nonnegative weapon-selector values. The
complete pinned File1 asset inventory contains16 named WMD members, at ROM
indices1260..1275: selectors0,1,2,4,5,7,8,9,12,18,22,23,24,25,26,51.
Eighteen stock ITEM selectors have no named WMD member:
11,15,20,27,28,29,30,31,32,33,35,36,39,41,42,43,44,46.
The inventory SHA256 is
276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2.

For example, owned6A uses selector33,6E/6F use35 and74 uses33 in the containing
sections. These are real stock inputs, not only arbitrary test selectors.
Associated weapon33/35/36 sound banks also contain direct cue5 programs.

Source6B4AE0 first clears the actor's2048-byte WMD buffer. For nonzero selected
resource it requests the formatted WMD path through1CC8F0 and ignores the
returned result. Flag1 follows1AA480 to1A9F20. If name lookup1A9D70 returns-1,
1A9F20 returns0 before the1297A0 destination-write path. The cleared buffer
therefore remains cleared. Source1D3B00 then formats the same selector's sound
name and calls1AD610 regardless of that file-read result; sound-loading mode2
and actual queue capacity still govern enqueue.

The current native `Catalogue` contains only the sixteen existing WMD banks.
`Owner::refresh` clears the actor binding, sees a missing catalogue bank and
returns unavailable before enqueuing sound. Its existing sixteen-selector
qualification remains a valid bounded checkpoint, but this gate excludes real
stock inputs and must close before gameplay installation.

Next implementation: admit only the audited stock absences as the existing
native cleared program bank, then continue the actual named sound enqueue.
Keep unknown selectors distinct from these known absences. Compare complete
refresh/cost/depletion callers for the additional stock values with the explicit
failed-file-read contract, and include actual weapon35 sound loading/cue output.
Do not invent a generic success fallback or a new program for a missing file.
This is not a game-session measurement or a reproduced slowdown diagnosis.
