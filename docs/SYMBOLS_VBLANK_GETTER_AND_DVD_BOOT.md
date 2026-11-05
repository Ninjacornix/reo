# Resident vblank getter and DVD/archive initialization

Static owned resident executable SHA-256 `06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`. Both complete original bodies reviewed; external roles reuse independently reviewed callees. No filesystem/archive/movie initialization or target execution.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x1AC630](../recomp/config/output/sub_001AC630_0x1ac630.cpp) | `read_shared_vblank_counter_without_advancing_game_state` | Confirmed complete static getter/orchestration | Returnsword294170 only. Existing19F600 vblankhandler incrementsit;displayinterrupt counter,not originalgameupdatecount. No conversion,advance or barrier. |
| [0x1AC650](../recomp/config/output/sub_001AC650_0x1ac650.cpp) | `initialize_dvd_filesystem_movie_cri_error_callback_and_nested_archives` | Confirmed complete static getter/orchestration | Calls1A8970(null,owned24FDE0backslash),1CC260 movieconfig,12A1E8 CRIinit,12B620(callback1AC640,nullcontext),sets3243D7=1,1A8CE0(-1)directorylist,1A9870 nestedAFS,1AB4F0 emptyhook. No childstatus admission/aggregate rollback or gameclock advance. |

Owned24FDE0 startsbackslashNUL;96-byte neighborblock SHA-256 `86f6167bc865fefa8e03bac377e6b35afd578e3d04a00e31b0277be59c5d7e27`. Neighboring sound strings are not used by this initializer. Related [filesystem setup](SYMBOLS_RESIDENT_FILESYSTEM.md), [nested archives](SYMBOLS_OVERLAY_LOAD_AND_NESTED_ARCHIVES.md), [movie configuration](SYMBOLS_ENGINE_EFFECT_MOVIE_IPU_PLAYBACK.md), [CRI callback registration](SYMBOLS_MOVIE_CRI_SERVICE_REGISTRATION.md), [vblank handler](SYMBOLS.md). Callback1AC640 is a mechanical empty entry unless stronger role evidence is recorded separately; no row added here.

Audit: 2 rows, 25 verified owned instruction words; 4 omitted interval words are zero/NOP; 0 omitted nonzero words.
