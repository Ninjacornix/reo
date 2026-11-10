# Stock weapon selectors without WMD files

Status: the native correction is qualified on both compilers. It is not
installed. Stage4 remains incomplete.

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

The earlier native `Catalogue` contained only the sixteen existing WMD banks.
`Owner::refresh` cleared the actor binding, saw a missing catalogue bank and
returned unavailable before enqueuing sound. That bounded checkpoint excluded
these real stock inputs.

`known_wmd_absences.inc` now admits exactly those eighteen values as the same
immutable cleared bank. `Owner::refresh` consequently continues through the
existing bounded named sound loader. The original slot0 clear rule, loading
mode2 suppression and queue-full behavior remain. Unknown selector3 still
returns unavailable after clearing the binding. Preparation still reads only the
sixteen actual ROM members; refresh and depletion do no further ROM reads.

The comparison derives the absence set independently from all332 nonnegative
selector rows in the five owned ITEM sections and every named WMD inventory
member, then requires exact equality with the production profile. Both compilers
compare6,528 refresh cases across the34 admitted selectors, all four actors,
loading modes, descriptor gates and selected slots0/3/255. Actual asynchronous
loading installs32 sound banks and reports the two existing missing sound names
(selectors0/51). Direct-install reference mixing compares45,568 PCM frames.
The combined depletion/cost matrix adds4,033 live cases, including all eighteen
absences, redirected descriptor self indices, mode2, and full sound/visual pools.
A real weapon35 cue bank produces337 commands and55,706 nonzero samples under
explicit controlled identity-bank assignment. These isolated checks do not
establish an observed room's bank assignment.

Complete original refresh/depletion/cost/audio frontends execute. The final
WMD-read port accepts only the independently enumerated existing/absent paths;
an absent path returns0 without touching the cleared buffer. Static owned-word
audits cover1CC8F0/1AA480/1A9F20/1A9D70 and explain that contract; filesystem
worker internals are not newly executed. Final positioned audio uses the
independently qualified native mixer. Prior qualification seals remain
historical snapshots.

Both cohorts pass273,209,210 combined assertions with identical observations,
including1,153 failed WMD attempts that leave the cleared buffer unchanged.
Both parent builds and eight integration checks per compiler pass. Identities
are sealed in `native_stock_wmd_absence_qualification_v1.json`, SHA256
acb3eab3aa1dcd70bd373e0c4fa980055561b5e958c6195d3a01a4367050c5bf.

Actual gameplay installation, inventory ownership/transfer/UI callers and the
remaining Stage4 families still require work. Installed V39 is unchanged.
This is not a game-session measurement or a reproduced slowdown diagnosis.
