# Native navigation inputs and initial queries

2026-11-10. Qualified component; **Stage 4 remains incomplete**. No game was
launched or installed for these comparisons. The installed game remains V39.

The new `game/native/gameplay_navigation` library reads the five owned File #1
SGL inputs without process pointers, in-place relocation or mutable guest RAM.
All five selected payload hashes are checked against exact ISO extents in the
pinned asset inventory. Together they contain166 room/variant descriptors,
3334 nodes,2167 conditions and432 cross-room links. Descriptor order is retained;
the last matching room/variant wins, as in original815E70. Shared resource offsets
share one immutable graph. Native budgets and structural checks are explicit
admission rules, not bounds attributed to the unchecked original code.

Section A contains12-byte cross-room links, a byte adjacency matrix, four-byte
alignment and four actor-sized byte visit masks. Original8194D0 selects
`actor * link_count` bytes, so these are not per-link32-bit flags. Section B has
12-byte room descriptors whose resource offsets are relative to the entire
file. Each room contains64-byte nodes, four ranked route bytes per source/target
pair, a condition header,16-byte condition records, then16 relative directory
entries. The directory's offsets are relative to the directory itself. Native
views remain immutable; original8163F0 relocates only the reference fixture.
Unknown link operands, node-field overlaps and directory payload meanings are
retained as authored encoding rather than assigned invented semantic names.

Native `nearest_node` supplies complete8171E0's unfiltered, finite-distance
profile, including8171D0 group0. It preserves signed query group versus unsigned
stored halfword, active-nonzero admission and the first minimum on equal
distances. Empty candidates or overflow return unavailable; the original empty
case reads an uninitialized stack slot. Flags1 collision filtering is still open.

Native `reverse_edge_action` supplies bounded8196E0. Signed neighbor count<=0
returns no action before consulting conditions. Within the first productive
neighbor, the last accepted reverse action4/5/8/9 wins and retains its full
halfword. Types11/12 return11 immediately. Later neighbors are skipped after a
productive one. Only then can a condition type/subtype provide the fallback.
Invalid references return unavailable instead of reading adjacent sections.

The r041 resource at descriptor29/node0 contains condition ordinal19 with
condition count14. Its original reverse-action query resolves a reverse edge
before reaching that fallback; all3334 retail nodes compare successfully in this
cohort. The invalid ordinal is preserved, not repaired or generalized as safe for
other consumers. Synthetic tests verify refusal when such a fallback is reached.

Correction: the initial qualification's narrative said the ordinal equalled
the count. The actual count is14, as independently rechecked at r041 descriptor29,
room70/variant1, resource offset138140. The historical sealed JSON is retained;
the newer edge qualification supersedes that narrative. The parser and comparisons
always used the actual count and are unchanged by this documentation correction.

Both LLVM and GCC pass2,683,729 checks each, including26,930 nearest comparisons,
265,608 action comparisons and1,920 room-binding cells. Coverage includes every
condition type/subtype pair, three passes through all65,536 action words, signed
counts/groups, missing candidates, duplicate keys/resources and malformed
extents. All nine current parent integration tests pass per compiler. Earlier
failed harness builds and the corrected zero-fill test port are retained in
the versioned evidence folders.

The reproducible runner is
`tools/native_reconstruction/verify_gameplay_navigation.py`. The sealed evidence
is `tools/native_reconstruction/native_gameplay_navigation_qualification_v1.json`.
The original bodies are word-audited against pinned o9 and the main ELF;
107C68 zero-fill is a declared bounded original-only fixture port. Production
code has no register context or RAM model.

Static Ghidra inspection reused the existing reoiso project. The analyzed o9
memory image was exported and fully matched the pinned113152-byte overlay.
Queried data xrefs were empty even for known references, so that absence was
not used as evidence of missing consumers. Main-program metadata matched the
owned executable hash; its generic MIPS analysis language is not substituted
for the instruction-word audits. The readiness diagnostic did not change
configuration or install prerequisites. This is static evidence, not a live
SGL load or game capture.

Next work is the canonical room-variant producer and native mutable navigation
bank, actor visits/occupancy, dynamic condition admission, route policies and
the real scene/AI action consumers. Actual gameplay installation and acceptance,
semantic saves and the remaining Stage4 boundaries stay open. No historical
slowdown diagnosis or measured speedup follows from this component.
