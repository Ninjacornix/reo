# Target-cache scratch determinacy audit

2026-11-10: controlled original-code investigation only. No live game, native
cache installation, stock-room admission, reproduced slowdown or confirmed
stutter cause is claimed. Stage4 remains incomplete.

Complete6D6240 rebuilds primary/auxiliary/linked target metrics and forward and
reverse order lists. Complete6D6D60 performs its pairwise sorts. The call creates
two68x68 distance work arrays but does not initialize them. Active eligible pairs
write selected entries. Some inverse sorts still read through the full physical
source population, including entries not written by this call. The source also
repeats those sorts inside a per-target loop; optimizing repeats requires proving
the admitted finite first-pass order and keeping this scratch issue separate.

Both compilers agree on87,112,894 audit checks.48 synthetic actor-presence profiles
each run with four finite caller-scratch patterns. The192 strict executions
produce119,712 reads before a write at6D6D80/84.24 profiles change output with prior
scratch contents. Only reverse linked-to-auxiliary order3B2880 (12 profiles) and
linked-to-primary order3B2C80 (18 profiles) change; their union is24 profiles.
Forward lists and all metric banks remain identical in these tests.

An additional192 separate candidate-policy executions initialize only the two
distance work arrays to finite maximum before entering the unchanged original
body. Every profile then has zero reads before a write and identical output
across other scratch patterns. Naturally deterministic profiles preserve their
strict original output. This is an explicit test policy to guide native migration,
not an installed patch or proof for arbitrary stock states.

The complete raw-mode source query chain executes. Euclidean distance, constant
heading and known-clear collision results are declared controlled ports used to
isolate scratch effects. Real model/collision/math production still needs its
own composition and game checks. First audit setup refused an undeclared mode
getter; v2 adds the full getter chain and v3 adds affected-range and initialization
checks. All failed and earlier evidence remains.

The native cache should own initialized bounded work arrays and explicitly name
this correction. Preserve canonical actor/model/collision inputs and defined
forward results. Compare strict defined profiles separately from the initialized
source profile; never treat arbitrary old stack values as authored behavior.
Evidence: `native_target_cache_scratch_audit_v1.json`, generated and checked by
`audit_target_cache_scratch.py` and `qualify_target_cache_scratch_v1.py`.
