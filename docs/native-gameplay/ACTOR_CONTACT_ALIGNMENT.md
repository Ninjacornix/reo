# Native contact alignment target preparation

Status: qualified on LLVM and GCC; uninstalled. Stage4 remains incomplete.
No game was launched and installedV39 remains unchanged.

`prepare_contact_alignment` supplies the complete666F50 contact-offset policy.
It reads the canonical actor contact point/normal, prepares the existing optional
AlignmentTarget, and retains current pose. A rejected angular limit retains the
old target. The signed low half controls whether to check the limit; the actual
comparison uses the complete signed32 argument, including positive65535 versus
negative-1. The UpdateOwner facade checks lifetime/identity and keeps preparation
separate from the existing selector6 publication.

The heading calculation is native arithmetic, with an owned coefficient profile
and explicit quadrant/subnormal policy. It does not call host atan/atan2 or use a
guest register/memory context. Source-derived angle conversion feeds the already
native sine/cosine polynomial. Native arithmetic requires finite inputs,
round-to-nearest and gradual underflow, and refuses unsupported profiles without
changing thread FP controls. Actor Y is copied raw, matching the source contract.

Both compiler cohorts execute complete666F50 and its original heading and
separate sine/cosine chain. They independently check coefficients/constants
against the pinned owned ELF/overlay. All65,536 turn values are covered, together
with signed zeros, subnormal/normal boundaries, atan polynomial branches,
exponent cutoffs, dispersed finite values, wrapped yaw/limit behavior and offsets.
The source surroundings model the admitted finite scalar/SIMD profile; they do
not establish physical PS2 exceptional arithmetic or FP flags.

Both compilers produce identical79,490,412 combined checks, including525,440
contact producer cases,589,827 heading/trig cases,131,073 angular rejections,
17 capability/profile refusals and four actual Owner composition cases. All eight
parent integration checks pass per compiler. Frozen sources, instruction audits,
outputs and logs are sealed in
`native_actor_contact_alignment_qualification_v1.json`.

Other target producers/import and animation-driven alignment movement remain
open, as do remaining actor messages, actual transport, semantic saves and game
installation/acceptance. This result supplies target preparation; it does not
claim an installed gameplay or slowdown fix.
