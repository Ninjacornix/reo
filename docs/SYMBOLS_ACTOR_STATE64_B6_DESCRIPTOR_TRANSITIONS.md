# Actor state64 and B6 descriptor transitions

Static File #1 US, 2026-11-05. Two complete original o2 bodies reviewed, including full phase tables, exact animation-result comparisons, fallthrough, and delay slots. Addresses, states, masks and field offsets are hexadecimal; floats/blends are decimal. No execution, build, attachment, live memory, input or timing. Numeric action/descriptor names are retained.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x62F940](../recomp/config/output_ovl/o2/o2_0062F940_0x62f940.cpp) | `align_state64_play_two_descriptors_turn_and_enter34_candidate` | High mechanics; candidate role | Primary-one64 target712DE0. Prefix54A F/32FF; consumed reset restarts0. Seven-phase table:0 visual1A/D10=1/snapshot, target saved XZ/currentY/yaw, mode2 alignment once ignoring result;unmatched phases continue mode2 and nonzero selects1. Phase1 sets2/flags82/710210 start0/blend20;2 full animation result nonzero advances3. Phase3 increments4/yaw-=8000 then falls into4, which increments5/root clear/flags82/710220 start0/blend0. Phase5 full nonzero animation result advances6;6 selects (1,34,0,0)/snapshot/root clear. No local bank activation after descriptors. |
| [o2 0x62FB20](../recomp/config/output_ovl/o2/o2_0062FB20_0x62fb20.cpp) | `play_visual36_descriptors125_126_then_return_base_candidate` | High mechanics; candidate role | Primary-oneB6 target712F28. Prefix54A7, no32FF store. Consumed reset base cancellation/blend10. Six-phase table:0 visual36/D10=1/snapshot/root clear/increment falls into1;1 sets2/flags82/710230 start0/blend10.2 signed-byte boundary exactly1 advances3;3 sets4 and710238 start0/blend10, without local flags82;4 exact signed-byte boundary1 advances5;5 base cancellation. No local bank activation after either descriptor; base cancellation activates banks. |

Owned primary-one pointer712DE0=62F940 (secondary64), pointer712F28=62FB20 (secondaryB6). Complete seven-target phase table73FEC0..73FEDB targets62F99C,62FA04,62FA38,62FA60,62FA74,62FAB4,62FADC; SHA256`077ca4ecef3f28282a76633f2444d8e203fd8a9fb7dd59a9524322c355f47c7c`. Values>=7 in62F940 continue alignment rather than returning immediately. Complete six-target phase table73FEE0..73FEF7 targets62FBC8,62FBF8,62FC30,62FC64,62FC90,62FCC4; SHA256`1496e13bcb73a5e8952a2b8e904367f127dac487e7df4dabd91f0c9abbf7272a`. Values>=6 in62FB20 return after prefix/reset work.

62F940 phase0 does not explicitly clear root deltas before its initial alignment call. Phase3 falls through phase4, applying the half-turn and next motion in one call; a direct phase4 entry skips that half-turn. Animation phases2/5 test the full returned register for nonzero. 62FB20 instead narrows the result to signedbyte and requires exactly1 in phases2/4. These are not mechanically interchangeable completion rules.

Fixed48-byte window710210..71023F contains:

| Address | Word0 | Halfwords4/6 | Consumer in this note |
| --- | --- | --- | --- |
|710210|10|2E0/2E0|62F940 first descriptor|
|710218|10|2E2/2E2|none claimed|
|710220|10|24E/24E|62F940 second descriptor|
|710228|0|0/0|none claimed|
|710230|20|125/125|62FB20 first descriptor|
|710238|20|126/126|62FB20 second descriptor|

SHA256`bf3db1c929b10d81b74d8df08b222b6a769a28201913097a4fbd4c60bf2d7411`. Flag word20 differs from10; no descriptor merge or zero-row interpretation is inferred from adjacency. [Animation contracts](SYMBOLS_ANIMATION.md), [alignment](SYMBOLS_ACTOR_ACTIONS.md), and [state snapshot/reset](SYMBOLS_DISPATCH.md) retain distinct operations.

Base cancellation clears54F/548 bit0; selects (primary,secondary,phase,B)=(1,0,1,0), snapshots, requests2050/start0/blend10 and activates banks. 62F940 instead finishes in state34 without that base sequence. Neither body initializes BA8 or changes original clock speed. Runtime action admission/frequency, asset semantics and cost remain unknown. Owned o2 base570000 SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`.

Full owned-body audit: 235 original words verified; 12 omitted words all zero/NOP. Zero conflicts or omitted nonzero words.
