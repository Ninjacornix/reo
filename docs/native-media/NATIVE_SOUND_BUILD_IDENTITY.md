# Sound candidate file identity observations

Status: Windows pre-run metadata helper, 2026-11-06. No game Runtime, RAM
capability, audio backend or device was constructed by these checks.

`recomp/overrides/native_sound_ram/build_identity.{h,cpp}` observes the complete
owned File1 ELF file and the current process's executable file through Windows
read handles. SHA256 uses Windows CNG; the report session uses its system random
generator. The ELF must match
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
Open handles deny concurrent writes/deletion during hashing, and before/after
file identity, size and write time must agree with the bytes actually read.

The returned `MemoryIdentity` records the original file SHA in
`executable_sha256`, the current native executable file SHA in
`native_build_sha256`, and a random16-byte session. Its Runtime incarnation,
RAM incarnation and RAM byte count remain zero. Only the actual memory factory
can populate those fields from its selected-backend and backing binding.

These are file observations, not attestation of every loaded byte or a RAM
read permission. The concrete factory must independently check loaded game code,
actual backings, writer/configuration capabilities and lifetime. File changes
after these handles close are outside the snapshot; matching rebuilt and sealed
candidate inputs remain a separate requirement. Missing/inaccessible input,
hash-provider or random-generator failure returns unavailable metadata.

Both GCC and pinned LLVM execute the real Windows helper successfully. Python
independently hashes each running fixture executable and confirms the returned
native file digest; the original digest matches the owned ELF. Repeated runs
return different nonzero session IDs, while missing and wrong input files return
their declared failures. No incarnation or byte-count authority is invented.
A private negative control removes original-file identity refusal and then
admits the wrong file, demonstrating the policy check's effect.

| Compiler | Private receipt SHA256 |
| --- | --- |
| GCC15.2 | `f2822197553faf64fda7b5bef8fdd874522a46aebc9e825d6f7e498be15ea12f` |
| pinned LLVM21.1.8 | `5dd9317a663b799619467e43ee615b000ba26b1d91f004e820d29a8c05748fa1` |

Receipts are under
`build-native-sjuni/native-sound-identity/{gcc-v2,llvm-v2}/receipt.json`.
Reproduce using `verify_identity.py` with an unused private output directory.
Earlier v1 compiler failures from the fixture's deprecated C++20 `u8path` call
are retained. The corrected fixture explicitly constructs a UTF8 string/path;
production hashing code was unchanged. The actual full sound candidate remains
unbuilt and unvalidated at this point.
