# Committed-source candidate preparation

`prepare_native_candidate.py` creates inputs only. It does not compile or start a
game, alter the player build, reset a checkout, or read authored working changes.
`--revision` must be an explicit root commit containing the complete dependency
patch series and native CD owner integration. Source files come from Git blobs.

The carrier is the exact sealed `build-native-sjuni/candidate-inputs-v1` kit. Its
libraries and compiler proof remain fixed. The preparer verifies the complete
installed LLVM/MinGW 20251216 compiler/sysroot, the dependency receipt and its
source hashes, and every committed patch hash. It refuses changes to the reviewed
stock-library build configuration or compiler sources.

First use `--check-only`, which verifies prerequisites without creating output:

```powershell
python -B tools/native_reconstruction/prepare_native_candidate.py `
  --revision COMMIT_HASH `
  --kit build-native-sjuni/candidate-inputs-v1 `
  --output build-native-sjuni/candidate-inputs-v2 `
  --dependency build-native-sjuni/dependency-workers-reapply-v2 `
  --dependency-receipt build-native-sjuni/dependency-workers-reapply-v2-receipt.json `
  --toolchain C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64 `
  --raylib-source third_party/PS2Recomp/out/build/_deps/raylib-src/src `
  --check-only
```

Run the same command without `--check-only` to create a fresh sealed kit. Existing
output directories are rejected, and partial failures are retained for inspection.
Use a new output path for a retry.

The source refresh includes committed authored carrier files, the relevant full
header cohort, local-build/VU tools, address maps and metadata, and all audited
dependency source files. It adds network state/world, serial-worker and CD-owner
compilation units. The bootstrap and override receive
`REO_BUILD_NATIVE_RESOURCE_OWNER=1`; existing SJUNI compilation options are kept.
Registration is taken from committed source without textual injection.

The direct raylib audio provider is regenerated with the committed reviewed
transform from exactly hashed pinned `raudio.c`. Its two C helper includes are
copied, and its dedicated unit selects C11 with 5 ms/two-period audio definitions.
Runtime, handwritten backend and game units must be rebuilt together; the seven
verified independent stock archives and the recompiler are retained. The optional
original-code includes in the committed DNAS/network routes remain optional.

The new manifest seals every input. `notices/native-candidate-source-delta.json`
records the commit, preparer, dependency, compiler and refreshed file hashes.
`PS2RECOMP-SOURCE-PROOF.json` explicitly supersedes the carrier's 110-patch runtime
proof; that older compiler/stock source proof remains separately preserved.
The old SJUNI notice is preserved under `CARRIER-NATIVE-SJUNI-CANDIDATE.json`, and
its compatibility filename points to the new delta for existing build drivers.

A successful preparation establishes input provenance and source-plan closure,
not successful compilation, gameplay correctness or a performance improvement.

The separate build driver accepts `--cache-from <completed-private-work>` when
starting a fresh work directory. It copies only verified `.obj`/per-unit `.json`
pairs from a finished candidate with the same verified toolchain. No archives,
precompiled headers, generated source or input marker is copied. The sealed
ordinary compile worker recomputes each unit's source/options/header/ABI/compiler
signature and object hash before accepting a hit; changed inputs rebuild. Cache
provenance is recorded separately. A failed build can supply successful objects,
but it never counts as a completed candidate or gameplay validation.

Two explicit preparation options add later migrations without changing the
default worker-only candidate: `--disc-stream-adapter` adds the independent
DVCI scalar core/adapter and its override macro; `--resource-reads` adds the
resource core, verified Windows mount/reader and synchronous RPC adapter, plus
Windows `bcrypt`/`runtimeobject` import libraries. The preparer requires matching
committed installation/dispatch source and includes all authored units in its
source-plan closure. Runtime admission remains separately off by default. The
read prototype additionally requires actual plain PAK layout agreement and
`REO_CD_ASYNC=0`; an enabled compilation macro does not prove native reads ran.
