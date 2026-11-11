# Native retained cutscene descriptors

CutsceneDescriptor now imports the admitted0950 layout of complete5F15A0 into
immutable asset ownership. Sections hold bounded offsets, counts and strides;
production contains no relocated pointers, simulated registers or guest RAM.
ScenarioArchive supplies actual named DM members from retained NETBIO00 data.
The descriptor prepares the first seven actor sections as real immutable
CutsceneActorStream programs. The eighth remains the actor construction header.
Scene construction must supply checked native actor bindings before installation.

Camera selection/streams, events, general commands, all eight actor sections,
all seven object sections, secondary commands, extension groups and the three
tail sections retain their exact bytes. Unknown trailing data is retained and
exposed, not decoded or discarded. Section counts and extents are checked before
allocation/use. The admitted group capacity32 covers the owned0950 inventory;
native storage separates domains that can alias in original scene state.

The optional extension count has three explicit outcomes: complete sections,
an authoredFFFFFFFF terminal, or physical EOF where5ED900 supplies exactly one
appendedFFFFFFFF word. No other missing bytes are padded. Terminal imports leave
later views absent, preserving uncertainty where the original early return
leaves previous global values untouched.0930/0940 versions remain unadmitted.

Both compiler comparisons pass2,633,038 checks and7,556,711 original calls in the
current World cohort. New parser coverage runs all548 owned0950 files plus two
controlled terminal cases against the complete source-word-audited5F15A0 body:
24,458 section comparisons,10,283 actor streams and50 refusal contracts.
It compares exact pointers/offsets, metadata narrowing, content, consumed bytes,
return values and the partial-return fields that remain untouched. Real file
comparison includes all17 descriptors declaring more than16 actors, up to32.
This compares descriptor parsing, not the original aliased actor-construction
or dispatcher behavior for those larger scenes.

Both actual archive cohorts pass80,852 checks:548 imports,142 explicit legacy
format refusals,1,469 actor groups and10,283 exact retained command streams.
They also check file identity bytes, all section bytes, unknown trailers, empty
and terminal imports, and absent named members. All seven current parent CTest
entries pass on both compilers. The first archive fixture incorrectly assumed
dm9999A.BIN was absent; that is an actual legacy member in scenario1. The fixture
was corrected to a separately checked absent name; no parser fix was needed.
Failed receipts remain preserved.

Reproduce using animation/verify_world_playback.py with --descriptors pointing
to the pinned cutscene-descriptor-inventory-v2 corpus, and
verify_cutscene_descriptor_assets.py with the actual retained data, explicit
compiler/CMake/build paths and fresh output directories. The evidence seal is
native_cutscene_descriptor_qualification_v1.json. No game was launched, installed
gameplay remains V39, and no new slowdown or speedup was measured.

Actual scene actor assignment/construction, other stream consumers, primary/NPC
motion replacement, speech/facial ownership and cinematic phase lifecycle remain
open. This importer is a qualified Step4 component; it does not close Step4.
