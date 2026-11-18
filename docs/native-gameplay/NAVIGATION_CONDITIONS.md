# Native navigation conditions and admitted links

2026-11-10. Qualified component; **Stage4 remains incomplete**. No game launched,
installed gameplay change or measured performance claim accompanies this work.

The navigation library now supplies complete bounded81A0E0 applicability,
819220 admission,819360 link-condition routing,8193A0 first-triplet lookup and
819410 first-admitted lookup. Original instruction words and jump tables are
anchored to the pinned o9 image. Native runtime code contains typed facts and
immutable authored conditions, without a register context or guest RAM model.

Applicability first requires an active condition. Type1's byte6 subtype may
require a matching character, actor slot, nonzero AI-control byte or their
combination; subtypes7/8 reject and other/default subtypes retain the original
index. Admission is distinct: several condition types intentionally return true
even when applicability would reject. Types0/2 additionally require a clear bit
in the existing strided room flag halfword, with the original five-bit shift
count behavior. Type7 applies its active check only to byte3 subtypes19/20.
These rules are preserved rather than generalized into one Boolean predicate.

The actual UpdateOwner exposes these operations through its own World bank,
resolved actor capability and canonical FlagState room slot0. The actor's
existing `ai_control` already owns originalFF0; no duplicate field was added.
Flag mutations and actor changes are observed immediately. Unfiltered lookup
returns the first matching signed room/variant/node triplet. Admitted lookup
continues past denied duplicates and returns the first admitted one. An unknown
or invalid required record refuses; it is not skipped as if denied.

Both compilers pass9,364,884 checks, including561,008 condition comparisons and
2,062 admitted-link comparisons. Every owned retail condition is exercised under
16 actor/flag combinations. Synthetic coverage includes every type/subtype byte,
all character bytes, AI-control zero/nonzero, matching/mismatching slots, flag
bit shifts and duplicate-link ordering. The3,077 link refusals include deliberate
queries under missing room bindings and a synthetic invalid ordinal; they are
not a count of retail content defects.

All ten current parent integration tests pass. The real UpdateOwner test checks
flag-slot identity, actor changes, absent links, invalid/foreign/retired actor
capabilities and World closure. Source hashes and concrete parent binary hashes
are retained in `native_navigation_conditions_qualification_v1.json`, produced by
`tools/native_reconstruction/qualify_navigation_conditions_v1.py`. The earlier
full VM qualification remains linked historical evidence, not a claimed full VM
rerun for these extra predicate methods.

Next are node-edge admission and the separate authored route policies, followed
by actual scene/AI execution and loading. Semantic saves, remaining gameplay
families and coherent native installation/acceptance remain Stage4 gates.
