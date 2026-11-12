# Direct native scenario archive loading

The later [scenario resource index](SCENARIO_RESOURCE_INDEX.md) adds the
separate owned key-to-ordinal lookup used by cinematic object loading. The
display-name API described below retains its existing behavior.

`ScenarioArchive` reads the five File #1 scenario archives from a retained
NETBIO00 source through the existing bounded AFS reader. Names and extents come
from the actual archive directories. Scenario EVBs and room RDTs become owned
immutable bytes without relocation or game-memory access.

The actual Update Owner can load these script inputs directly. It validates the
program before replacing channels. Unsupported or missing inputs preserve the
previous binding. The remaining startup commands must be implemented before
the five scenario EVBs can be installed.

The LLVM and GCC comparisons each pass 1,924 checks. The new loader reads all
171 owned EVB/RDT members, compares their complete bytes to independently
hash-verified extents, and binds 51 ordinary/offline room programs through the
Update Owner. It refuses 281 room profiles and all five startup EVBs. Fixture
checks also cover case-insensitive lookup, duplicate names, missing archives,
and missing members.

This supplies direct host content loading. Whole-room asset construction, the
startup controller, live platform providers, semantic saves, and installed
native gameplay acceptance remain open. The caller supplies the retained asset
source and its identity. The AFS source interface supports positioned providers.

Run `tools/native_reconstruction/gameplay_scenario/verify_archive.py` with each
compiler and its CMake build. The receipt captures the compiler, source hashes,
executable hash, owned member hashes, and results.
