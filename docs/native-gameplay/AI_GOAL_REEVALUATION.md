# Native AI goal reevaluation

2026-11-10: complete admitted8133D0,825CC0 and823190 now run through the actual
World Actor, navigation Bank and SceneResources owners. Stage4 is incomplete;
this component is not installed in V39.

`Owner::reevaluate_ai_goal` resolves primary reference0 and companion2 when the
actor's logical slot is1, otherwise companion1. Physical primary indices and
logical actor slots remain distinct. Missing required native state refuses;
early refresh/motion/status/graph no-op branches need no irrelevant providers.
After admitted graph lookup, the observation byte clears before later dependencies.

The reevaluator preserves the source branch order: own status/motion priorities,
same-room reference reactions with companion suppression, explicit reference and
owned requests, character7 item selection, then the first strict maximum of the
eight combined weights. Winners5..7 and all-zero weights call no setter. The
separate823190 predicate tests motion>=6, auxiliary30000 and status200; it is not
the broader813BD0 observation gate.

Character7 selection reads the existing canonical inventory: special storage28
and extended storage10..18, preserving first-match order. Descriptors must be
active with exact attachment/content IDs131/12D. Signed current/max health and the original
FP32 multiply/divide order are retained. Owned constant71B034 is25.0; the signed
B034 displacement from720000 must not be read as72B034. Goal-resource1090 is one
word: this selector replaces its low byte, while the reference request overwrites
the word with the zero-extended equipment-slot byte.

Both compilers pass400,438,140 current AI checks, including62,722 full original
reevaluations,4,027 setter calls,512 actor alias cases,470,019 resource selections
and2,048 target-busy comparisons. Five native capability refusals are separate
from the original comparisons. Whole actor ranges and unrelated state compare.
The exact immutable table/constant inputs and complete source instructions are
audited against owned binaries; only the prior profile zero-fill port remains.
Actual Owner checks additionally cover canonical resource mutation, companion
selection, missing/retired actors and closure. Thirteen parent checks pass per
compiler. `native_gameplay_ai_descriptor_alias_qualification_v1.json` seals the
current comparisons and preserves the earlier qualification as history.

The first implementation and fixture confused descriptor+4 (authored lookup ID)
with descriptor+6 (attachment/content ID). Both original selector paths read+6.
The corrected fixture projects both fields independently, including crossed IDs.
The real Owner rejects a matching authored ID with the wrong content, and admits
matching content with an unrelated authored ID. This supersedes the earlier
resource-field mapping; no installed game change is claimed.

Full observations, reactions/action callbacks, actor construction and native
game acceptance remain open. There was no game launch or performance measurement.
