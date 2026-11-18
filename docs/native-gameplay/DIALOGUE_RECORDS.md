# Dialogue cue, text and record ownership

The ordinary voice frontend is overlay 6B9590 → 6B97D0. Its records are a
separate 16-entry pool with 0x98-byte source stride, cleared by 6B7810 and
allocated by 6B7890. Canonical native records contain typed values, retained
text owners and domain/generation actor identities. No production guest memory
or register context is used.

`DialogueCues` admits the owned SP metadata format. Its two 6,000-entry offset
tables have different record roles: 6B7930 requests the first table through
6B7520(mode1), whose records have a 20-byte stride. Native cue values expose
the text index, signed delay and signed voice member actually consumed by that
constructor. The second table is retained but is not reinterpreted as the same
record type. `DialogueTexts` admits the separate SPM format, validating its
index, single-variant string references, eight-byte presentation prefixes,
terminated bodies and eight effect values per text row.

`prepare_dialogue_bank` resolves actual 1D41F0 names through the existing
ScenarioArchive resource index: `sp%02d%02d%02d.bin` and
`spm%02d%02d%02d.bin`. Scenario, section and character are explicit. This
preparation does not claim that the complete room selector or 1D41F0 loader has
been installed. Each absent half stays absent. It does not manufacture an empty
bank or infer the section from the current room number.

Both compilers pass 4,460,784 asset checks across all 270 owned cue/text pairs
(540 verified files), including 1,620,000 complete original cue getter calls,
81,295 text rows, malformed input refusal and retained lifetimes. Complete
6B7350 executes as a layout registration proof; 6B7520, 6B9750 and 6B9790 execute
for their actual compared roles. Text pointer/effect projections are identified
as projections, rather than described as execution of the whole constructor.

`advance_dialogue_record` implements complete 6B97D0 over those retained native
text banks and canonical World actors/random state. Original byte and short
wrapping, fade/page transitions, corruption selection, cached-text redraw,
voice selection, buffer contents, actor display style and callback ordering are
preserved. Two unusual source details are deliberate: glyph counting repeatedly
classifies the first body byte, and the primary voice gate reads signed
actor+0x58 through the previous secondary actor pointer. The latter is the low
halfword of canonical `collision.basis.x.z`. The timeout shortcut reads selection
slot one. A completed fade returns after erasing even when another page remains.

Both compilers pass 131,709 record checks, comparing 4,096 varied state cohorts
and 86 complete multi-page continuation frames (4,182 original returns and
41,242 source calls). Native UI presentation remains an explicit capability:
cache erase, suppression query and drawing have no successful default provider.
The separately qualified ordinary voice helper is used with an explicit known
zero archive marker in this record suite. No audio device or playback source is
started by the dialogue comparisons. Unsupported source overruns or unavailable
capabilities preserve their completed prefix.

`DialoguePool` owns the actual construction, age sorting, channel selection,
discard and update sequence. Its World registration prevents a second mutable
pool for the same World. The cold method is explicitly a projection of 6B7610
onto this owner's represented fields; it does not install the source's other
timer/monitor owners. 6B7810 clears only channel zero's selection count, so the
native secondary count stays unavailable until 6B9590 first writes it and is
preserved by later record clears. Pause and the two distinct source dialogue
gates are explicit; unknown gates are not assumed zero.

The whole-pool comparison passes 1,133,345 checks on both compilers: 787 complete
6B7930 constructors, 1,176 complete 6B9590 updates, 560 authored flag writes,
capacity refusal, selection/discard ordering, record reuse and retained text
lifetimes. Full record bytes, canonical actor fields, random state and primitive
event ordering agree. A controlled retained text copy exercises the 8169 literal
prefix and its successful zero return; none of the owned USA texts has that
prefix. The fixture keeps that distinction explicit. Cold 6B7610 comparison is
a projection onto represented fields, rather than a claim that its separate
timer and monitor subsystem is installed.

Canonical SpeechState gains optional DBC delay and 1075 display style. Actual
66A730/5F1290/682D10 full clears establish zero through the shared clear
initializer. Generic Actor construction leaves both unavailable. Paired full
66A730 + 107C68 regression passes 2,235,228 checks, including actual source-byte
comparisons, canonical rollback/busy checks and 512 retained actor lifetimes.

Failed record comparison snapshots remain retained: the first fixture omitted
an aggregate initializer, a second direct closure missed routing/resource
dependencies, and later comparisons identified the cached redraw, selection
slot and page-fade return corrections described above. The corrected record
and asset receipts identify exact immutable source snapshots. Full dialogue UI
ownership, the outer 6B7E40 actor response orchestration and complete room-bank
publication remain separate integration work. This is not full Stage 4
acceptance or a claim of an authored game launch.
