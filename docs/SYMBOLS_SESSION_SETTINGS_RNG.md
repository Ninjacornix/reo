# Session settings, defaults and two RNG streams

Static File #1 US research, 2026-11-04. [Owned identities](FUNCTION_INDEX.md). No target execution, live-state reads, builds or timing measurements.

The RNG entry is called by many actor, audio and policy routines. Its mode selects a stream or a read operation; a callback count is not a random update count or a global game-clock count. Settings addresses below are original guest fields, not launcher diagnostics settings.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [0x1AEBE0](../recomp/config/output/sub_001AEBE0_0x1aebe0.cpp) | `clear_session_settings_block_and_reset_auxiliary_work_candidate` | Confirmed/static narrow mechanics | Clears240 bytes at0x3243C0 through guest memset0x107C68, then calls0x1AEC10. Does not install option defaults or seed RNG itself. |
| [0x1AEC10](../recomp/config/output/sub_001AEC10_0x1aec10.cpp) | `clear_session_auxiliary_work_and_two_counters_candidate` | Confirmed/static narrow mechanics | Clears64 bytes0x2B8E50, zeros words0x2B8DD8/2B8DE0. Other globals, settings and RNG halfwords remain untouched. |
| [0x1AEC50](../recomp/config/output/sub_001AEC50_0x1aec50.cpp) | `seed_both_guest_rng_streams_from_session_byte_candidate` | Confirmed/static narrow mechanics | Clears byte0x2B8DE8, copies unsigned byte0x324199 to halfwords0x3244B8 and0x3244B0. Zero seed is stored as zero here; advancing modes replace it with1. Does not use a host wall clock or entropy source. |
| [0x1AEC80](../recomp/config/output/sub_001AEC80_0x1aec80.cpp) | `advance_or_read_two_guest_rng_streams_candidate` | Probable semantic role; mechanics verified | Mode0 reads unsigned halfword0x3244B8 without advance;1 advances0x3244B0;2 reads unsigned byte0x2B8DE8;3 advances0x3244B8;other values0. Each advance substitutes1 for zero state, computes (state*176)%65363 using unsigned word arithmetic, stores low16 and returns it. Streams are separate, not a single shared seed. Preserve mode, draw order and zero substitution in any replacement; no randomness-quality or performance claim. |
| [0x1AED60](../recomp/config/output/sub_001AED60_0x1aed60.cpp) | `initialize_saved_option_snapshot_from_owned_defaults_candidate` | Confirmed/static narrow mechanics | Clears16 bytes0x3241A0 then copies owned16-byte tuple0x24FE30: 00 07 07 00 01 80 00 00 01 00 00 00 00 00 00 00. Calls0x1B8290 afterward. This initializes a snapshot, not every field in live settings0x3243C0. |
| [0x1AEDB0](../recomp/config/output/sub_001AEDB0_0x1aedb0.cpp) | `copy_live_option_fields_into_saved_snapshot_candidate` | Confirmed/static narrow mechanics | Copies bytes0x3243C5/C9/CA/EC/EF/F0 to0x3241A0..A5, signed bytes43ED/EE to41A6/A7. Remaining snapshot bytes unchanged. No persistence/file write here. |
| [0x1AEE40](../recomp/config/output/sub_001AEE40_0x1aee40.cpp) | `sanitize_live_option_fields_to_guest_ranges_candidate` | Confirmed/static narrow mechanics | 43EC>=6 becomes0;43EF and43C5 masked to1;43C9/CA>=8 become7. Signed offsets43ED/EE outside[-10,10] become0.43F0 outside[56,164] becomes128. Does not clamp invalid offsets to nearest endpoint or change clock-speed flags. Setting names need caller/page corroboration. |
| [0x1AEF00](../recomp/config/output/sub_001AEF00_0x1aef00.cpp) | `initialize_persistent_progress_block_and_default_scenario_slots_candidate` | Probable subsystem role; mechanics verified | Clears4234 hex bytes at0x31FB60, sets selected initial flags/slot byte and ORs mask1 into words0x323BD8/321EF4. Reads verified signed-halfword list0x2342D0 (0,12,15,18,21,24,27,30,33,-1), sets corresponding bits in block+4094. Reads slot ordinals0,1,2,3,4,FF at0x234268, formats owned scenario names Outbreak/Below Freezing Point/The Hive/Hellfire/Decisions, Decisions from pointer table0x2342B0 into24-byte records at block+9C, stores count at0x31FB80. No external save file is written; sentinel tables and output extents are trusted. |

## Option-field corroboration

Owned English labels and accesses in the [o1 options pages](SYMBOLS_O1_OPTIONS_MOVIE.md) connect the original byte fields to player settings. This adds caller evidence; it does not change the range checks above.

| Guest field | Candidate setting | Corroborating o1 entry |
| --- | --- | --- |
| 0x3243C5 | Stereo/monaural selection | 0x5718C0 |
| 0x3243C9 | BGM volume0..7 | 0x5718C0 |
| 0x3243CA | SE volume0..7 | 0x5718C0 |
| 0x3243EC | Controller type0..5 | 0x5708C0 |
| 0x3243ED | Signed horizontal screen offset | 0x572610 |
| 0x3243EE | Signed vertical screen offset, displayed divided by2 | 0x572610 |
| 0x3243EF | Vibration boolean | 0x5708C0 |
| 0x3243F0 | Brightness centered128 | 0x571FB0 |

The settings snapshot and initialized progress block have different ownership and lifetimes. None of these functions enables experimental rendering, changes original game speed or enables recording as part of this research; only their static contracts are documented.
