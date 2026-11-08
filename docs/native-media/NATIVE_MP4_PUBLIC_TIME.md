# Native movie public time correction

The temporary game adapter's time query incorrectly writes a frame ordinal with
denominator 1 and returns constant zero. A frame count is not the native playback
clock. The corrected query uses the Media Engine session's elapsed seconds,
expressed as signed milliseconds / 1,000, and returns the count it writes.

The original public wrapper at `0x1603B8` calls `0x176198` with its two output
pointers. Its success path at `0x160430` loads the written numerator into V0;
nonnegative values return directly. Error/invalid-object paths normalize the
pair to 0/1. The lower ordinary implementation follows `0x176210 -> 0x176338 ->
0x176350`, obtaining a numerator/denominator from its selected clock/cache.
The replacement retains that public rational shape without restoring the old
clock callback, counter/cache or PS2 scheduling machinery.

These observations come from the already generated original function bodies in
the sealed V27 project, backed by the admitted owned File #1 ELF/code identity.
They are static source evidence, not a new game call capture. No claim links this
time-query error to the V25/V26 movie stall.

`playback_time.hpp` converts finite nonnegative native seconds to a millisecond
pair without using renderer frame counts, callback counts or display FPS. It
refuses invalid/out-of-range values instead of wrapping the signed public count.
The adapter returns 0/1 for its stopped source. Output-pointer aliasing follows
the original ordered writes and final numerator reload.

Both compiler checks cover zero, a 30000/1001 frame interval, the long opening,
a longer movie and a 96,000-second playlist, with less than 1 ms truncation.
Negative, infinity, NaN and signed-count overflow refuse. The actual adapter
compiles against the audited SDK131 header cohort. This is not linked-game
evidence; the next coherent candidate must include and retest the correction.

Evidence: `build-native-sjuni/host-movie/time-contract-v1/receipt.json` and
`build-native-sjuni/host-movie/sdk-objects-llvm-v6/receipt.json`.
Step 3 and audible synchronization remain open.
