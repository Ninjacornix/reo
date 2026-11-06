# Corrected ready enable predicate

Status: isolated corrected implementation qualified, 2026-11-06; actual looping
asset validation is recorded separately. No game setting or runtime adapter is
enabled. Stage3 remains in progress.

The [correction contract](ADX_READY_FLAG_CORRECTION.md) identifies the missed
distinction: original124F10 returns signed inner halfword24 (enable), while the
frozen Window2 used word20 (count/alignment). The correction uses
`bit_cast<int16_t>(header.loop.enabled)>0`. An automated source check proves its
only executable change is this predicate; the relative header include is rebased.
Source2, the common class/interface, header parser, workspace and PCM store are
byte-identical to their earlier freezes.

The separately frozen48-case original corpus independently varies count0/1/13/
-1 and enable0/1 over24/44.1/48kHz and versions3/4. Each original pass executes
**91,968 instructions**; a second read-only instrumented pass must reproduce
every original transcript exactly. Both actual compiler workers agree on the
captured state. Inputs were frozen before the corrected implementation existed.

Both GCC15.2 and bundled UCRT LLVM21.1.8 pass:

- All **48 new clients /720 complete snapshots and events**.
- All **123 earlier admitted clients /8,034 snapshots and events**, with the
  existing narrow live-grant/cache relation retained and no broader masking.
- All **996 inherited whole-owner checks**, including ownership, failure,
  allocation, FP and real blocked-worker paths.
- Parent Release build and selected`stream_window_v2_ready_flag_r1` CTest.

The frozen implementation differs on **24 of48** new clients. Some incorrectly
select loop setup; others incorrectly select finite setup. This negative control
demonstrates the prior coverage gap, rather than rewriting old expected outputs.
The earlier bounded comparison stays evidence for its paired-field inputs and
is not evidence for the newly exposed independent-field domain.

Use target`reo_native_stream_window_v2_ready_flag_r1` for the corrected owner.
The frozen target remains available for regression/negative evidence. Both
implement the same concrete class and private Source2 friend: link exactly one
in any executable. This preserves the private source interface rather than
adding an escape or casting another class into its authority.

Private cohorts are under`build-native-sjuni/adx-ready-flag/`:

| Native receipt | SHA-256 |
| --- | --- |
| `native-gcc-v1/receipt.json` | `0548e224e6e8dd692a1131d4b740fcb7615c84ede4eccf92a17fee5e2f8f8ba2` |
| `native-llvm-v1/receipt.json` | `d005d68cd00db4bf8e8d5db5eab2a103fc70a29b9346bc59b92f24e148c0fb33` |

The new oracle has separate freeze/replay stages and uses the unchanged original
whole-owner driver, qualified FP workers and read-only observation subclass.
Its capture must match the uninstrumented original transcript. No expected value
enters the native fixture. The correction manifest and qualification file pin
the exact delta, dependencies, scripts, receipt identities and parent build.

This fixes a native prototype defect. It is not an explanation or fix for a
slowdown observed in the normal game, which does not select this owner.
