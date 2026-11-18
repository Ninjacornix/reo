# Batched immutable candidate header reads

Candidate preparation previously launched `git cat-file` separately for every
committed header. It now preloads the admitted header roots in one raw Git batch.
The selected commit, tree-mode/path checks and complete final SHA-256 input
manifest remain authoritative. No working-tree file supplies source bytes.
Uncached non-header reads retain the existing individual-blob path.

The batch decoder requires each requested object ID, blob type, exact byte
length, separator and complete output consumption. It recomputes each Git blob
identity and publishes the cache only after the whole batch validates. Repeated
paths sharing an object reuse the same immutable bytes. `check_output` drains
stdout while sending requests, avoiding a pipe deadlock for a large reply.

Eight tests cover binary/empty bodies, malformed identity/type/length/framing,
content corruption, atomic refusal, missing paths and a real temporary Git
repository with dirty/untracked files, duplicate blobs and Unicode names.
An additional read-only comparison uses the independently sealed V21 manifest:
all 443 committed headers (440 distinct objects, including headers outside the
preload roots) match both the manifest and actual sealed files byte for byte.

This removes repeated Git process starts from future header preparation. The
recorded batch-read time is not a benchmark of complete preparation or game
compilation. It does not reduce the required native compilation, change an
already sealed candidate, permit reuse across header changes, or relax any
compiler/dependency/source identity check.
