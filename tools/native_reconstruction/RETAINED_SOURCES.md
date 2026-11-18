# Retained asset-source plumbing

`reo::assets::PositionedSource` supplies immutable `size() noexcept` and positioned
`size_t read(uint64_t,size_t,void*) const`. The provider must keep its size and
bytes immutable, support concurrent sharing Sources, stay within the supplied
output range and report the actual count. It may throw. This interface does not
verify filesystem identity or make externally mutable backing files immutable.

`Source(label, shared_ptr<const PositionedSource>)` captures that size and retains
the provider without opening a pathname. `label` is diagnostic metadata only.
Adopted reads use the provider outside the legacy stream mutex, reject short or
oversized completion, and propagate exceptions. `transient` does not cause an
adopted source to reopen its label. The original pathname constructor and stream
behavior remain available. Keep each Source alive during calls, and do not
concurrently mutate Source metadata; only the backend shared pointer is const.

`VirtualFileView::create` retains adopted backends while privately freezing source
metadata, segment metadata and memory buffers. Pathname-only sources retain the
existing reopen/size-check behavior and external file-immutability requirement.
Provider sharing does not place provider methods/final destruction under the
legacy stream or resource registry mutex. Direct Source/VirtualFile reads can
modify output before failure; ResourceSession provides transactional output.

`Overlay(root, span<const uint8_t> plan, Overlay::SourceResolver)` copies bounded
plan bytes and obtains all ELF, original archive and replacement Sources through
the supplied factory. The factory must return non-null Sources corresponding to
the requested paths; it is trusted wiring, not identity verification. The same
existing PlanReader/Overlay body validates magic, game/ELF and leaf/replacement
hashes, paths, lengths, AFS extents, limits and generated archive layout.
`Overlay(root, plan_path)` delegates to that same body with pathname Sources.
The retained constructor does not access `assets::active`.

The additive `VerifiedSourceResolver(path, SourceExpectation)` overload receives
the ELF digest, no additional metadata for base archives, and both expected
length/digest for replacement payloads from that same plan parser. An owning
service can verify and retain a handle before returning its Source. This avoids
a second plan parser; the existing hash and extent checks still run afterward.

Validation command from the repository root:

```text
python tools/native_reconstruction/verify_retained_sources.py --cxx C:/msys64/mingw64/bin/g++.exe
```

This builds with C++20, `-Wall -Wextra -Wpedantic -Werror`, then tests adopted
provider lifetime after caller release/path replacement, frozen metadata/memory,
concurrent exact reads, short/oversized/throwing providers and transactional
failures. A synthetic overlay checks ELF/base/replacement factory calls, copied
plan ownership, unchanged hash rejection, byte/layout/sector-padding parity with
the legacy constructor, and retained bytes after source/plan removal. A copy of
the owned ELF is used only for the unchanged executable identity check; archive,
payload and provider fixtures are synthetic. Its bytes are never executed.
All 84 checks pass, including the expected metadata passed to the verified
resolver and byte parity through that overload.
The source/compiler-bound receipt is under
`build-native-sjuni/retained-source-checks/receipt.json`.

There is no Windows handle backend, snapshot implementation, JSON/manifest
reader, mount identity, new cryptography, game integration or security claim in
this change. Provider immutability remains a required precondition until the
owning mount establishes it.
