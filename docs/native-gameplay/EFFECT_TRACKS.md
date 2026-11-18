# Native effect tracks

The native `gameplay_effects::Tracks` owner imports the File1 effect mappings,
group/part metadata and signed key curves into immutable native values. Its
`sample_transform` implements the complete original5903E0 channel policy. There
is no register context, guest address, generated function or game clock in the
production owner. This is one dependency of the periodic visual consumer; the
full resource/material owner, effect lifetime, game installation and Stage4
remain open.

Original590B10 scans in authored order for the first timestamp greater than the
signed query. The native code preserves duplicates and descending timestamps,
first/last clamps, signed values and literal zero/negative-count behavior. A
zero count reads the preceding value only if it is inside the supplied asset;
negative counts read the first value. Interior interpolation preserves each
FP32 operation and the original order. Transform channels0..2 divide by16 for
translation,3..5 use the original rounded angle conversion,6..8 divide by16 for
scale. Other kinds leave the caller's values intact, including rotation's fourth
halfword. Strict round-to-nearest FP32, gradual underflow and no contraction are
required. This is comparison to the audited current SDK profile, not a physical
PS2 exceptional-FPU claim.

`import_effect_tracks.py` extracts all25 physical `efdata*.bin` members from the
hash-checked owned File1 ISO inventory, without changing original assets. Both
compiler cohorts pass1,288,852 checks:357,580 scalar samples,61,380 complete
original-body part transforms,65,536 signed synthetic query cases with extreme,
unsorted and duplicate keys, logical lookup boundaries and malformed asset
refusals. They read24 members into2,107 groups and6,138 parts. Physical duplicate
assets and repeated samples remain counted; these totals are not unique content
or gameplay coverage. The original bodies and their jump table are checked
against the owned o2 instruction/data bytes. Test-only CPU/RAM surroundings do
not enter production.

One member is explicitly refused: `NETBIO00.DAT/0/541`, `efdata26.bin`,
SHA256 `b032c7c3ba08c110980096d6ab922fc8aee363280dea840187536bb6a258a62d`.
It has147 identical1024-byte mapping blocks before a plausible group table at
0x24C00. The observed original1D1030 consumer copies the loaded bytes and fixes
its group base at file+0x400. No alternate consumed layout or runtime reachability
has been established for this member. The importer does not discard extra blocks
or claim it repaired the file. The actual read provider's treatment remains an
explicit investigation item before admitting that asset profile.

Group mapping is separate from loaded geometry identity. Original372720 searches
the model's root IDs; it does not consult the efdata logical map. Material curves
use the common table at the first header's word4 and the model's per-root palette
indices. Those resource/material consumers are not replaced by transform-only
success. The renderer boundary remains Stage5, while the native gameplay effect
owner and its real resource selection remain required in Stage4.

Reproduce with `verify_effect_tracks.py --compiler <LLVM-or-GCC> --corpus
build-native-sjuni/effect-tracks-owned-v2 --output <fresh-workspace-directory>`.
The immutable final receipts are `effect-tracks-llvm-v2/receipt.json` and
`effect-tracks-gcc-v2/receipt.json` under build-native-sjuni. The versioned
qualification records their identities and this document. No game was launched.
