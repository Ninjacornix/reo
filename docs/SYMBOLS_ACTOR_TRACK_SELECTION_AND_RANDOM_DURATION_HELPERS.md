# Track selection and original random-duration helpers

Static File #1 US, 2026-11-05. Three complete original o2 bodies reviewed, including track-loop entry, argument conversions, division and delay slots. Addresses, selectors and sizes are hexadecimal; random-table values and division results stated as ordinary integers are decimal. No execution, build, attachment, live memory, input or timing. Wait/counter semantics depend on callers; these are not wall-time APIs.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o2 0x6346C0](../recomp/config/output_ovl/o2/o2_006346C0_0x6346c0.cpp) | `initialize_unmarked_bank_tracks_from_slot_selected_six_byte_motion_record_candidate` | High mechanics; candidate role | a0actor,a1signed16recordselector,a2unsigned-style integer blend,f12start. Table728E90 indexed byunsignedactorbyte3 suppliesbank-specific recordbase; motionkey=signedhalf(base+6*selector+4), samekey for everyeligibletrack. Loops signed16trackindex againstactor51C->unsignedbyte1 count; trackbyte1FF!=0 skips. Other tracks call58B9A0(actor,bank51C,key,low16index,start,floatunsigned(a2)), then storekey to1F2+20hex*index. No local pointer/selector/capacity checks or index advance through source records. |
| [o2 0x634800](../recomp/config/output_ovl/o2/o2_00634800_0x634800.cpp) | `draw_signed_byte_row_value_divide_clock_factor_and_replace_zero_candidate` | High mechanics; candidate role | AdvancesRNG1,chooseslow3bits. Reads signedbyte72BA40+8*low8originala0+choice. Divides byunsignedbyte74F200 usingguest signedDIV; narrows quotient signed16;onlyzero replaced1. Negative quotient retained. Actual row admission/physical table extent unresolved. No global speed mutation. |
| [o2 0x634A40](../recomp/config/output_ovl/o2/o2_00634A40_0x634a40.cpp) | `draw_one_of_eight_halfword_durations_divide_clock_factor_and_replace_zero_candidate` | High mechanics; candidate role | AdvancesRNG1;low3bits index signedhalf72BC00. Literalvalues60,90,120,180,240,300,360,420. Divides byunsignedbyte74F200, narrows signed16, replacesonlyzero with1. No input arguments read. No local zero-divisor admission or result clamp beyond zero replacement. |

## Track selector contract

The motion record has six-byte stride because the signed a1 selector is multiplied by6 before adding4. The source pointer is not advanced inside the track loop: all admitted tracks receive the same signed key, while their destination state and track argument differ. Bank51C and header count are reread in loop control. Trackbyte1FF admission occurs before any source key load/call/store for that track. The integerblend conversion uses the original unsigned-style floating conversion, including the negative-register half/round/re-double branch; it is not a direct signedfloat cast.

Owned32-byte pointer window728E90..728EAF contains712150,713CD0,711E50,713CD0,713CD0,710470,730790,731770; SHA256`16d562541d03448e2e3512e5de20d65488f0aea6e2039326cef8c41afb9bbb65`. This establishes eight pointer words, not a local byte3<8 guarantee or a bound for signedrecordselector. Valid selectors and source record lengths require callers/assets. [Model-work track initialization](SYMBOLS_MODEL_WORK_INITIALIZATION_AND_TAGGED_QUEUE.md) independently maps58BEA0/58BF40; this function's selective byte1FF gate is different.

## Random tables and factor identity

Complete16-byte table72BC00..72BC0F has eight signedhalfwords60,90,120,180,240,300,360,420, SHA256`c098ff17b3fd2e0771939d107dfc681e9a0a6e748b94e3ca1a43c63e8bd43de4`.

634800's arithmetic can address any of256 eight-byte rows from72BA40 under its low8 argument conversion. That entire2048-byte owned address window72BA40..72C23F was verified, SHA256`a8ed50f8e3478b54283e62928df1f4a2880eb7a2f550a050ef692baf04984897`. This is an address-coverage window only: it includes physically adjacent data, and this pass does not assert256 semantic rows. First eight physical rows are signedbytes:

| Row | Eight values |
| --- | --- |
|0|1,1,1,1,2,2,2,2|
|1|2,2,2,2,3,3,3,3|
|2|3,3,3,4,4,4,2,2|
|3|4,4,4,5,5,5,6,6|
|4|6,6,6,7,7,7,8,8|
|5|8,8,8,9,9,9,10,10|
|6|12,12,12,11,11,11,10,10|
|7|15,15,15,16,16,16,17,17|

Neither helper reads a measured frame rate or advances the clock. A verified writer6BBBA0 initializes74F200 to1 for3243CC==0 and2 otherwise, recorded in [actor runtime binding](SYMBOLS_EMD_ACTOR_RUNTIME_FIELD_BINDING.md). Runtime74F200 lies beyond file-backed o2 and was not read live. All-writer coverage and initialization order remain unknown; no zero divisor or negative duration was observed. Preserve guest division and exact zero replacement before attempting a host helper substitution. [RNG stream semantics](SYMBOLS_SESSION_SETTINGS_RNG.md) retain draw order and state.

Caller row/record domains, track capacity, draw frequency, intended counter units and performance cost remain unknown. Owned o2 base570000 SHA256`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`.

Full owned-body audit: 120 original words verified; 2 omitted words all zero/NOP. Zero conflicts or omitted nonzero words.
