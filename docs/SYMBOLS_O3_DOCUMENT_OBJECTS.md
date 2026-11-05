# Overlay o3 document object construction and text-style allocation

Static File #1 US research,2026-11-04. Owned provenance and instruction audit are in
[menu input](SYMBOLS_O3_MENU_INPUT.md); workspace ownership and object allocation are in
[browser phases](SYMBOLS_O3_BROWSER_PHASES.md). No game, build, replay, network traffic or attachment.
The large body58E1E0 spans through59007C and was read in bounded PC slices after an initial display truncated.
Both source-backed catalogue entries have one mapping each. Proposed names do not assert original symbols,
handwritten translation, observed allocation counts, rendering timings or a reproduced slowdown cause.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o3 0x58E090](../recomp/config/output_ovl/o3/o3_0058E090_0x58e090.cpp) | `find_or_allocate_browser_text_style_channel` | Confirmed/static broad mechanics; subtype semantics partial | Searches16 style records at root+68F94, stride8, for color (a0 or1) OR FF000000 and lowbyte a1. Returns existing index; else searches free active-byte slots2..15, stores color/flag and calls1B77E0(channel13+index,...). Full returns1. Slots0/1 are reserved by58DFC0. Finite searches; no heap allocation. |
| [o3 0x58E1E0](../recomp/config/output_ovl/o3/o3_0058E1E0_0x58e1e0.cpp) | `construct_or_update_browser_document_object_and_arena_strings` | Confirmed/static broad mechanics; subtype semantics partial | Mode67DBA0 must0 for body work. Nonzero object type a0 scans at most500 records for first inactive; type0 uses slot0. Type8 group actions can find/update existing objects instead. Builds legacy text/form/group records, copies or substitutes arena strings, writes geometry/type/color/style and state flags, then scans objects through592AB0 and marks context5C4 dirty. See contracts below; broad role confirmed, full original HTML tag taxonomy and all alias/admission guarantees remain unresolved. |

For58E1E0, a0 is object type, a1 is initial state/subtype, a2/a3 and t0/t1 supply opposite
rectangle coordinates, t2 supplies color/style value, t3 an object flag. Stack arguments are consumed as
bytes at incoming SP+0/+8 and pointers at+10/+18/+20. These positions are observed contracts; their full
caller-level type names remain candidates. Context1A/1E adds page offsets to coordinates before storage.
Objects come from the preallocated pointer table root+5FFC0, not an allocation call inside this body.

The body handles these connected mechanisms:

- Initial free-object search skips active records and returns at500. Existing type8 group operations scan the
  same bounded collection. Subtypes10/20 build group/choice ordinals in object5E/5F;30 finds an existing
  type8/state10 object, changes state11, preserves shared string pointer60 and updates selected choice state.
  Null/inactive termination differs among searches, so no universal hole-safe collection guarantee is claimed.
- Types6/7 with stack byte0 in1..3 reject primary strings longer than16. Type13 subtypes2/3/5 trim a secondary
  label into a255-byte stack temporary based on rectangle width/height before storing its actual byte length.
  This is legacy byte geometry, not Unicode grapheme-aware layout.
- Arena base root+60DD0 has nominal size8000hex, current pointer root+68DD4. Object60/64/68 refer to three
  stored string fields. Empty fields often reference current_pointer-1; nonempty fields copy bytes, append NUL
  and advance. Many length scans are full strlen followed by lowbyte truncation; several form fields reserve
  caller-specified byte capacity and then adjust the pointer by reserved minus copied length.
  Checks compare used+length/reservation against8000 at specific branches. They do not establish a complete
  memory-safety proof across every subtype, terminator and caller contract. No malformed case was executed.
- Types6/7 stack policy1 prefers context57F, policy2 context590, otherwise caller primary text; policy1 also
  updates saved preferences0 with up to14 bytes. Policy4 decodes first two bytes of object60 as a decimal
  selector and dispatches owned622440. Selectors0/8 prefer profile+CD;1 profile+0;2 decimal profilebyte14E;
  3 profile+41;5 profile+4C;7 profile+14F;4/6 and invalid selector use caller fallback. Profile pointer67C2D0
  is loaded rather than allocated here. Product labels for those fields remain unresolved.
- Final object metadata stores initial state at0, type2, coordinates as floats34/38 and rectangle spans40/44,
  color58, style channel5C, flag4, two caller bytes5/5D. Types1/2/17/18 obtain style via58E090; others use
  channel13. Fixed-point/sign conversion behavior is preserved, not simplified to host arithmetic.
- A final bounded500-object scan calls592AB0 until an inactive/null entry or its positive stop result.
  Context5C4 is set1. Existing root+68E78 index can reset vertical scroll if selected geometry exceeds a
  page-relative threshold (412-context1C). These writes identify UI/document work, not a global game update.

All loop initial branches and count tests were considered. String-reservation arithmetic, unsupported object
subtypes, parser admission, object ownership/aliasing and exact semantic names remain incomplete. The role is
useful for locating browser layout work while retaining these limits. It is unrelated to native VU compilation.
