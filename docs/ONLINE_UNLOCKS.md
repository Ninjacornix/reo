# Online progression unlocks (#29)

For the selected game, open **Cheats**, turn on **Enable cheats**, and select
**Unlock everything**. Deselect other cheats, then host or join normally.
File #1 and File #2 retain separate selections. This uses each game's existing
progression operation; it does not replace or directly edit a memory card.
Saving through the game can retain unlocks.

The launcher previously rejected every cheat selection in both manifest export
and shared-session setup. Both paths now permit the built-in progression unlock.
Mixed selections still report which option is available online. Health,
infection, ammunition, results points, escape-time and imported data cheats
remain available in Play alone. Validation preserves saved selections rather
than silently dropping selected effects.

The unlock changes local progression/menu availability. It is not included in
the host's randomizer configuration and does not grant unlocks to other players.
Each player chooses their own progression option. The existing native capability
check still requires the selected edition's progression marker; update/rebuild
an older native game if prompted.

Both exported manifests and host/join setup use this rule. Imported patch groups
are not accepted based on a name such as “Unlock everything.” Data patches and
other mod effects cannot piggyback on the built-in unlock manifest.

## Verification

`OnlineUnlockTests` runs in the Windows launcher self-test. It covers every
combination of the six built-in choices for both editions in host and join mode,
master-switch behavior, edition isolation, imported patches, mixed mod effects,
and actual UDP host/guest configuration transfer. Existing capability and
randomizer-session tests remain in place. The new tests and those related suites
passed 833 assertions locally using the production changed files and the Mac
branch's portable core adapters in an isolated temporary harness.

The Windows C#/XAML compile check passes on Mac with the unavailable compiled
preview shader excluded for compilation only. The normal Windows build pipeline
builds that shader. Updated WPF UI diagnostics check the co-op explanation; those
UI tests and live online scenario/costume selection still need a Windows run.
No completed online gameplay or save/reload result is claimed here.

The native checker parses an unlock-only manifest and applies it with a living
actor in each of four player slots in both editions. Full-RAM comparison rejects
changes outside progression fields, checks scenario bits and verifies repeated
application. It passes 33 checks, or 34 with an external launcher manifest.
Existing File #2 progression checks also pass. To repeat without a game disc:

```sh
c++ -std=c++17 -O2 tools/cheat_check/online_unlock_tests.cpp -o /tmp/reo-online-unlocks
/tmp/reo-online-unlocks
```

An optional manifest argument checks the exact file emitted by the launcher.
The source CI job runs this native checker, and Windows CI runs the launcher
self-tests. Remote CI has not been run as part of this local verification.
