# Bounded live LSC minimum controls

The native live input now exposes the original queue's signed minimum control
within its existing 8192-byte source profile. The default remains 6553. Valid
values from zero through 8192 take effect when the next lower file opens;
negative values and 8193 diagnose without changing the preceding queue value.
Controls on a retired input return closed. A changed queue minimum does not
revise an already opened lower file or an accepted read.

The backend keeps strict `occupied < minimum` admission. At zero there are no
accepted reads, source publication, decoded samples or output signal. At one,
actual decode can leave a partial encoded block and stall: the missing suffix
cannot be read while those bytes remain occupied. This is preserved rather than
inventing EOF, progress or a refill exception. At 6144 and 8192, actual private
workers complete the finite clip with all 20,000 payload samples, no skipped
samples and no output underruns. Both raw and attenuation profiles are checked.

Both compilers pass all 78 native suites. The first complete cohort compiled
successfully and passed 77 suites, but its new test incorrectly expected the
one-byte threshold to reach EOF. Those failed receipts, logs, original V1 source
manifest and exact changed source copies remain retained. After correcting only
that test expectation, the incremental recheck admits exactly its compile/link,
verifies every production archive remains unchanged and reruns all 78 suites.
No native threshold rule was weakened to make the corrected test pass.

This is not complete game LSC admission. Early V22 read-only observations show
original child capacities of 272,384 bytes for stereo and 53,248 for mono, with
default minimums 217,907 and 42,598 respectively. The C4 start controls also
contain larger sector-based minimums. These exceed the current physical native
source profile. Do not clamp those values to 8192 or admit them against a smaller
ring. Larger source/window capacity qualification and actual game enqueue,
control, query, retirement and movie integration remain required.

See `tools/native_reconstruction/lsc_minimum_qualification.json` for exact
inputs and results. The running V22 executable is the earlier sealed route
correction; it does not contain this separate minimum-control extension.
