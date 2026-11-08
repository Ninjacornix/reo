# Native movie asset catalogue

`Catalogue` loads the prepared native `movies.json`, validates its format/profile
and entries, hashes the actual MP4 files and retains real read-only file leases.
It performs preflight before gameplay. `find` and `find_label` subsequently use
only retained native metadata; they do not reopen/hash source archives, spawn a
converter or touch guest memory.

Retain the returned `Asset` for the native player's source lifetime and pass its
ordinary local `path()` to `host_movie::Player`. An asset retains its file after
the catalogue goes away. Equal resource keys share the same file lease, while
distinct cue labels stay available. The actual File #1 catalogue has201 labels
and200 physical video assets. Caller-side validation must still establish that
the selected game cues are present; a parsed cache manifest is not game binding.

Default loading requires a complete catalogue; explicit partial loading is for
bounded preparation/testing. Invalid files, hashes, counts, conflicting aliases
and profiles throw before returning a partially constructed catalogue. Unknown
resource lookups return empty. Every filename is derived from a validated hash
key, so source labels are never filesystem lookup authority.

GCC and bundled LLVM pass a real-file check of the complete201-entry catalogue,
shared assets, explicit partial-cache refusal/admission, retained file leases,
write refusal while leased, native Media Engine/D3D11 frame transfer from the
leased path, release and corrupt-cache refusal. These are actual Windows files
and GPU operations. No game or audible A/V test is claimed. The standalone CMake
library also builds with LLVM.

Source/receipt identities are in
`tools/native_reconstruction/native_movie_asset_cache_qualification.json`.
The game cue/render adapter and launcher prelaunch preparation are still open.
