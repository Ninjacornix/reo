# Native local route dispatch

2026-11-10. Qualified bounded component; **Stage4 remains incomplete**. V39 is
unchanged. No game run, installation or measured performance claim occurred.

Native817DB0 now composes the existing bank, edge/condition owner, ranked
policies and bounded-cost policy through the actual UpdateOwner. Policy0/1
selects the distinct ranked variants; every other32-bit value selects cost
search. Source==destination bypasses every inner policy and leaves cost
untouched, including policy2 with a zero cost-work budget. Destination-link
admission still follows the same-node position copy.

Before unequal-node routing, an unfiltered target link in the current room/
variant triggers node-level target admission. A known denial returns-1 without
writing any output, including the prior link field. Inner route failure instead
writes source nodes/positions and clears the link. After successful routing the
link is first cleared, then set to the first admitted target link if one exists.
Unavailable later metadata retains this known output prefix. The native owner
does not conflate denial, complete route failure and unavailable evidence.

Both link passes read the actual current Session variant. Changing that byte
does not silently rebind graph selection; the dispatcher can query new-variant
links against the still-bound graph, as the source does. Actual World/UpdateOwner
tests verify this state identity without introducing another variant field.

Both compilers pass25,073,840 checks with56,616 completed dispatcher comparisons,
including duplicate link admission, pre-denial preservation, inner failure,
same-node policy bypass, all three policy branches, unknown later metadata and
current-variant changes. Both parent builds and all ten current integration
tests pass. Earlier failed compile output is retained with the final evidence.

The retail cohort leaves3,412 cost-search queries unavailable under the lower
4096-edge verification profile. Another synthetic budget exhaustion and one
unavailable post-link record are explicit. These cells do not execute unsafe or
incomplete original comparisons. The wider cost-work allowance remains an
admission gate, alongside the known r041 ordinal reference.

Evidence is sealed by
`tools/native_reconstruction/qualify_local_navigation_v1.py` in
`native_local_navigation_qualification_v1.json`. Complete original817DB0 and
817170 bodies are word-audited against the pinned overlay and execute only in
the reference fixture. Native runtime code uses typed state and no guest RAM.

Next are cross-room link collection/traversal and the actual actor destination/
AI consumers. Wider work/content admission, real loading, semantic saves and
coherent native game installation/acceptance are still required for Stage4.
