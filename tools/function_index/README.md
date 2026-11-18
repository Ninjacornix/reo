# Offline function index

File #1 research tool using Python's standard library. It reads function CSV
catalogues and original instruction comments in locally generated C++ files.
It writes a local SQLite index, a CSV suitable for filtering, and a Markdown
overview. It never loads or executes generated code, starts the game, attaches
to a process, contacts Ghidra, or changes runtime settings.

Reviewed names live in [annotations.json](annotations.json), imported from the
[subsystem notebooks listed in the central index](../../docs/FUNCTION_INDEX.md).
Unknown entries stay unknown.

Default import discovers `docs/SYMBOLS*.md`, including later subsystem notebooks.
Only explicit mapping-table rows become annotations; duplicate image/address
entries are rejected. This discovery does not infer names from unreviewed code.

A reviewed entry without generated C++ may link to its exact File #1 catalogue
instead. The importer validates the checkout path, image label and entry
membership. Such a name does **not** change missing generated-source coverage
or add inferred instructions/calls to the graph. Its notebook must supply the
separate owned-image evidence, as in the raw o8 metadata helper review.

## Build the local index

Run from the repository root:

```powershell
python tools/function_index/index.py build --elf game_data/SLUS_207.65
python tools/function_index/index.py summary
python tools/function_index/index.py export --out build-function-index/functions.csv
python tools/function_index/index.py report --out build-function-index/REPORT.md
```

The default database is `build-function-index/index.sqlite`. All those generated
outputs are ignored by Git. On Windows, this tool runs at idle process priority.
Source reading is sequential. No compiler, emulator, third-party Python package,
or Ghidra installation is needed.

`--elf` is optional. When supplied, its SHA-256 must match the established
File #1 US identity. The tool compares main-ELF instruction comments with the
original words and decodes bounded ASCII strings at candidate references. The
database records comparison results; a mismatch is evidence to review, not an
automatic source repair. Without `--elf`, string decoding and binary comparison
are unavailable. No overlay binaries are required or implicitly selected.

The index includes the main catalogue, main `extra_functions.csv`, and all
File #1 `overlay_maps/ovl*.csv`. Authored supplemental registration groups are
excluded because their overlay labels need separate identity reconciliation.
Source discovery is limited to `output`, `output_extra`, and `output_ovl/o*`.
Missing generated bodies remain in the index with missing coverage.

## Search and inspect

```powershell
python tools/function_index/index.py search animation
python tools/function_index/index.py search "ST_HIT"
python tools/function_index/index.py show main:0x00141E20
python tools/function_index/index.py show 0x193178
python tools/function_index/index.py show o2:0x0068C660
python tools/function_index/index.py refs 0x264820 --limit 20
python tools/function_index/index.py suggest --limit 20
```

`search` matches proposed names, catalogue symbols, documented rationale and
decoded strings. `show` returns bounds, source location, notebook evidence,
callers, callees and references. A bare interior PC can locate its containing
catalogue entry. If the address is ambiguous across overlays, the command asks
for an image-qualified key. Image labels `o0`, `o2`, etc. refer to source/map
partitions; they must not be assumed to equal runtime overlay IDs.

`refs` searches exact or equivalent RAM-alias addresses. Reference entries
include their instruction sites and source lines. `suggest` ranks currently
unnamed entries by relationships with annotated neighbors, then instruction
count. It is an exploration queue, not a runtime or compiler performance profile.

For a separate index, place `--db` before the subcommand:

```powershell
python tools/function_index/index.py --db build-function-index/alternate.sqlite build
```

## Refresh reviewed annotations

```powershell
python tools/function_index/index.py import-notes --out tools/function_index/annotations.json
python tools/function_index/index.py refresh-annotations
```

Review that JSON diff before refreshing. It retains proposed names, complete
confidence qualifiers, rationale, and notebook path/line evidence. Paired entries
in one notebook row become separate entries. Re-import after editing notebooks
so evidence line numbers remain current. No automatic extraction upgrades a
name's confidence or renames a Ghidra symbol.

`refresh-annotations` updates only names, confidence, rationale and evidence in
the existing local database. It resets annotations removed from the seed to
unknown. Identity and all catalogue hashes/file membership must still match;
validation completes before the transaction changes any names. Calls,
references and source verification remain the old snapshot. Use `build` after
generated source or catalogue changes; refreshing names does not re-extract code.

`confirmed_static` establishes the narrow stated behavior, not a complete
hardware/library contract or original symbol name. `probable` and `speculative`
are hypotheses. A role's uncertainties remain in `confidence_detail` and
`rationale` even when its basic mechanics are explicit.

## Exact mechanical leaf classifications

```powershell
python tools/function_index/classify_leaves.py
python -m unittest discover -s tools/function_index -p 'test_*.py' -q
```

The classifier reads the verified main ELF and locally decoded overlays using
[overlay_identities.json](overlay_identities.json). It checks each image hash,
runtime header id and base before accepting any original words. Decoded images
stay in ignored `build-function-index/owned-overlays`; the tool never obtains
game files from the network or reads a live process.

Only small aligned catalogue intervals with a completely admitted body are
classified: no-ops, constant returns, and single a0-relative field accesses.
Trailing words must be zero. Field widths, signedness, offsets and register
effects remain explicit. A no-op preserves the return register; it is not a
return-zero stub. Accessor matches do not prove pure getters, host ABI types,
safe memory, or a library identity.

Results live in [leaf_classifications.json](leaf_classifications.json) and
[the mechanical report](../../docs/FUNCTION_LEAF_CLASSIFICATIONS.md). They remain
separate from semantic annotations. Refresh reviewed annotations first, then
rerun this classifier: entries with a reviewed name are excluded so the two
counts do not overlap. These classifications authorize no runtime replacement.

## Evidence and limitations

- **Direct calls:** decoded from original instruction words in comments, with
  instruction sites. External `j` targets are tail-jump candidates. `jalr`
  remains unresolved unless its register is a tracked constant. Non-return
  `jr` is an indirect jump, which can be a switch rather than a call.
- **Address references:** constant propagation is restricted to straight-line
  blocks and invalidated at control-flow boundaries, missing instructions,
  calls and unsupported writers. Memory uses are distinguished from merely
  materialized address-shaped integers. These are static candidates, not proof
  that a global/table is accessed in the current scene. R5900 MMI writers clear
  tracked constants; the tool does not guess their semantics.
- **Strings:** up to 255 bytes of terminated ASCII from the verified main ELF.
  Dynamic strings, encodings such as CP932 and overlay strings are not decoded.
  A correct string at a candidate address does not prove an execution path used it.
- **Overlays:** local image and resident main code take precedence. Other-image
  targets are explicitly marked `overlay_unverified` or `ambiguous_overlay`.
  All candidates are retained, without claiming which overlay was resident.
- **Boundaries:** ownership follows catalogue intervals and exact entries. A
  merged generated file is split for indexing by those intervals, not by its
  C++ filename alone. Shared tails, inaccurate end bounds, byte-sized analysis
  artifacts, and omitted entries remain possible. Unaligned intervals are
  preserved and flagged. Conflicting instruction sites are excluded.
- **Coverage:** `complete` means comments cover the catalogue's byte interval;
  it is not complete decompilation, proof of correct boundaries, or gameplay
  validation. Partial coverage can also reflect omitted padding/NOP comments;
  it does not by itself identify missing gameplay implementation.
  `source_bytes` is the containing generated file size; shared
  files must not be counted repeatedly as independent compile costs.
- **Provenance:** SQLite metadata records hashes of catalogues, scanned source
  files, annotations and the optional main binary comparison. The output is
  a snapshot. Rebuild after relevant inputs change. It cannot identify the
  currently compiled/playing executable from source files alone.

The index deliberately stores no instruction byte arrays, disassembly bodies,
RAM dumps, account settings or game assets. Strings and derived metadata remain
in ignored local outputs. Rebuilds replace a completed database only after a
successful transaction and close; failed `.building` files are retained for
inspection. Read/query commands open SQLite in read-only mode.

## Verification

```powershell
python -m unittest discover -s tools/function_index -p test_index.py -v
```

The tests use tiny synthetic instruction/catalogue/Markdown fixtures. They do
not run a game, GPU, replay, network request, or Ghidra session.
