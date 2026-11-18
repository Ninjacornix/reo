# Native resource retirement and deactivation

Complete592770 now uses the canonical descriptor, template and instance owners.
It is a retirement/deactivation callback, correcting the earlier broad
"reconstruction" label. Flag40000000 gates the work. It releases the current
primary/shared secondary instances first. A positive signed descriptor parameter
then returns; an inactive descriptor or template255 needs no template lookup.
Otherwise template flag40000 controls complete591BE0 deactivation: clear the
active byte and flag1, then set flag20000000. The descriptor identity remains.

`SceneResources::active_count` derives its value from the same256 descriptors.
There is no extra mutable count that can drift after loading or replacement.
The original count is initialized consistently with the descriptor table in the
comparison. Source behavior with a corrupted independent counter is not claimed
equivalent. Deactivating an already inactive descriptor changes neither flags
nor count. Deactivation itself does not release capabilities;592770 performs the
ordered instance release first, matching the separate original boundaries.

`ResourceTemplates::flags` reads the existing owned24-byte asset record.
255 retains its meaningful no-template/zero result. Indices129..254 are an
explicit bounded-asset refusal when reached; they are not treated as a zero
record. Missing required template ownership also fails after the measured
release prefix. This checkpoint tests controlled version3 template records;
the existing owned item-template import evidence is separate.

Both compilers pass52,755,840 checks,832 deactivation cases and1,544 complete
template-flag queries. The cases include320 composed common-callback profiles,
all256 descriptor slots followed by a second inactive pass, parameter sign,
primary/secondary ownership, sentinel templates and all template-index bytes.
Of523 refusal checks,504 exercise out-of-range template accesses. Current WMD,
pose, primary/shared retirement and model-pass cases run in the same cohorts.
Parent libraries and four World/contact integration tests pass. Evidence is
bound in `native_resource_deactivation_qualification_v1.json`.

This closes another primary common-update branch. Extended actor ownership,
native asset/resource construction, real callers, coherent native gameplay and
representative game acceptance remain open. No game was launched and no
performance improvement is claimed.
