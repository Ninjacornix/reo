# Code: Veronica source cross-check against Outbreak symbols

Static review, completed 2026-11-05 for the available pinned source.
The [complete scope report](COMPLETE_SCOPE_REPORT.md) accounts for all 4,599
reference C definitions: 1,817 detailed shared/platform/utility/availability
dispositions and 2,782 function-level game/integration exclusions. All 223 absent
alternate assembly bodies are tracked separately. The curated address crosswalk
now has 620 comparisons; detailed ledgers retain additional bounded and
many-to-many cases without forcing aliases.

This folder is comparative research. Supported corrections and qualified
candidate names are reconciled into the annotation index. No original public
symbol is claimed recovered solely from another game's source. No native
replacement, runtime correctness or performance improvement is established.

## Results and scope

The current snapshot inventories **1,362 `docs/SYMBOLS*.md` notebooks** and
identifies definitions from **228 Code: Veronica C files**, plus the available
startup assembly. The curated crosswalk contains **620 Outbreak main-ELF entries
across 61 notebooks**. The initial 72-entry pass grew to 170, then 620; the complete
13-scope audit separately tracks all identified shared candidates and reference
availability. Comparison counts are not new mapping counts or equivalence tests.

| Result | Entries | Meaning |
| --- | ---: | --- |
| `supported-role` | 237 | The stated API role is supported by the compared control flow, fields, interface slots or data units. Complete equivalence is unproved. |
| `name-candidate` | 3 | Comparative evidence supports a qualified candidate spelling or legacy interface role. No original symbol is claimed recovered. |
| `related-different` | 378 | Related library code has a concrete layout, arithmetic, control-flow, ABI-expression or lifecycle difference. |
| `concept-only` | 2 | Scheduling concepts are similar; a one-to-one function identity is not established. |

The complete ledgers establish recorded dispositions within their available
source scopes. Unmatched functions, missing SDK implementations and ownership
boundaries remain explicit; they are not completed equivalence comparisons.
Exact API-token overlap is only a search lead; a zero count does not rule out
shared code under descriptive labels. Engine, room, script, animation and
network boundaries are discussed separately without claiming function matches.
The underlying notebooks are changing during development; the hashes in the
inventory identify the exact snapshot used.

## Read the findings

- [Completed available-source audit](COMPLETE_SCOPE_REPORT.md): scope totals,
  corrections, limitations and links to all 13 detailed reports.
- [Every reference function](complete-function-coverage.csv) and
  [every source file](complete-file-coverage.csv): exact disposition accounting.
- [Second-pass corrections and omissions](SECOND_PASS_FINDINGS.md): current
  summary, with detailed [filesystem](FILESYSTEM_SECOND_PASS.md),
  [audio](AUDIO_SECOND_PASS.md), [stream](STREAM_SECOND_PASS.md) and
  [engine](ENGINE_SECOND_PASS.md) evidence.
- [Native reconstruction plan](../NATIVE_RECONSTRUCTION_PLAN.md): the staged
  path from mapping to independent native subsystems, starting with SJUNI.
- [Findings and naming leads](FINDINGS.md): concrete evidence, incompatible
  contracts and useful follow-up work.
- [Reviewed function crosswalk](CROSSWALK.md): each Outbreak entry linked to its
  notebook and the exact CVX source function at the pinned revision.
- [Engine and coverage boundaries](ENGINE_BOUNDARIES.md): graphics, scripts,
  rooms, animation, multiplayer and movies.
- [Crosswalk CSV](crosswalk.csv): current Outbreak labels, generated-source
  paths, CVX functions, confidence and comparison text for filtering.
- [Notebook inventory](notebook-inventory.csv): every discovered symbol notebook,
  its content hash, curated-entry count and lexical API search hits.
- [Provenance and integrity checks](provenance.json): revisions, source hashes
  and the generated-source files checked against the owned ELF.

## Source identities

Outbreak is **File #1 US, SLUS-20765**, owned main executable
`game_data/SLUS_207.65`, SHA-256:

```text
06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46
```

Code: Veronica is [AshfordFamily/recvx-decomp at
657b0c0c9489943116c71f151804ad7304fca975](https://github.com/AshfordFamily/recvx-decomp/tree/657b0c0c9489943116c71f151804ad7304fca975).
Its documented game target is PS2 US SLUS-20184. The external checkout was read
without building it or obtaining a CVX executable. This review cannot independently
verify its binary-matching claims. Source comments describing matching objects
are upstream claims, not proof of equivalence to Outbreak.

The enhanced-port engine follow-up separately inspects
`aikatore/recvx-enhanced-port` at `2fa8a14224ebb92d0103a8c828e6a032c338d6d4`.
This differs from the earlier overview's revision; its native rendering and
File #2 asset importer are comparative source, not a File #1 replacement.

All curated addresses are **Outbreak main-ELF guest addresses**, not CVX
addresses. They must not be transferred to File #2, another region or an overlay.
Overlay evidence in the boundary discussion explicitly retains its image label.

## Method and validation

The cross-check compares existing Outbreak notebook evidence with pinned CVX
C source and relevant headers. Selected Outbreak original-instruction comments
were also reread for the naming candidates and major differences. The refresh
script verified **30,173 instruction-comment records in 620 referenced generated
files** against file-backed segments of the SHA-256-verified owned ELF. A file
can contain adjacent routines and repeated comments; this count is not a count
of distinct reviewed functions or proof of correct generated semantics.

No game, emulator, compiler build, RPC, audio decode, live process attachment,
timing capture or new playtest was run. Existing runtime compatibility support
is source context only. No performance diagnosis follows from a shared API name.

Curated comparisons are authored in [review.json](review.json). To validate and
regenerate the inventory, crosswalk and provenance with an existing clean
checkout of the pinned reference:

```powershell
python docs/recvx-crosscheck/refresh.py --reference C:/path/to/recvx-decomp --elf game_data/SLUS_207.65
```

The script rejects a different reference revision, tracked reference edits,
incorrect Outbreak ELF identity, missing notebook rows/functions, duplicate
curated addresses and instruction-comment mismatches. It reads source files;
it does not execute game code or download dependencies. It writes only the
generated reports in this folder. The external source and owned game bytes
are not copied into these reports.

Related Outbreak work: [central index](../FUNCTION_INDEX.md),
[notebook directory](../FUNCTION_NOTEBOOKS.md),
[earlier CVX comparison](../SYMBOLS.md#7-code-veronica-comparison-techniques-to-reuse).
