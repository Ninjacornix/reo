# Contact direction and the advanced region pointer

Offline File #1 source/data audit, 2026-11-09. No game or live-memory capture was
run. This finding explains a native-admission boundary; it is not a measured
gameplay incident or slowdown diagnosis.

The global margin and angular scanners read direction from an advanced region
pointer after traversing the last admitted actor. They separately retain the
selected hit actor, point and region index. The advanced pointer is therefore
not necessarily the selected region's center. The existing
[scanner mapping](../SYMBOLS_ACTOR_CONTACT_PACKET_SCANNERS.md) records the exact
read sites and the separate last-scanned accumulator clamp.

All four direct o2 stores to actor field 1DC bind it to the actor's inline AEC
storage. The complete initializer bodies and the scanner/region-refresh bodies
were checked against the owned overlay.

| Initializer | Inline-base instruction | Pointer publication |
| --- | --- | --- |
| 66A750 | 66AAA4: v0 = actor + AEC | 66AB74 |
| 6834B0 | 6835FC: v1 = actor + AEC | 6836B0 |
| 6837C0 | 683950: v1 = actor + AEC | 683A00 |
| 6BBDA0 | 6BBDC0: v1 = actor + AEC | 6BBE3C |

All eight primary default descriptor lists selected through 71BDC0 have four
regions. The first four subtype entries at 716440 also select four-region
lists. Each has an actual radius -1 terminator. Consequently, after those
four regions the scanner reads XYZ at actor offsets B1C/B20/B24. Refresh 5DC1B0
writes the actual transformed points and count; it does not write a transformed
sentinel point after them.

A bounded search of all 4,425 current generated o2 source files found zero
direct immediate-offset stores to B1C or B20, and 45 direct stores to B24.
Several B24 stores publish related-actor pointers in behavior routines. This
search does not cover aliases, bulk initialization, other overlays or all
runtime descriptor selections. It therefore cannot establish universal zeros,
an initialized geometric tail or a safe fixed region capacity.

Native transformed regions should not invent a zero tail or reproduce an
unrelated storage address as geometric data. The source-comparison profile
keeps this direction read explicitly unadmitted unless its backing values are
proven. An additional candidate repair may use the selected hit region's center,
as the per-actor response path does. That is an explicit behavior change and
requires separate comparisons and game acceptance; it is not original parity.

Reproduce with `audit_hit_region_backing.py --output NEW_PRIVATE_DIRECTORY`.
The [retained audit](../../tools/native_reconstruction/native_hit_region_backing_audit_v1.json)
binds the overlay, all seven owned-word audits, default descriptor hashes,
bounded source-index digest and every matching direct store. Its receipt SHA-256
is `4ae7e7390ba7eebba5ce227efb5c8f033c295bb66327e3539304fff9bac8c769`.
