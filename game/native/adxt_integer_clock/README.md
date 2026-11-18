# ADXT integer clock values

Independent raw ratio queries and mode/count state. This module consumes
externally serialized observations; it owns no ring, output device, estimated
FP/tick clock or game callback. Original modulo32 and separate queue truncation
are retained. See [contract, original evidence and limits](../../../docs/native-media/ADXT_INTEGER_CLOCK.md).

Standalone CMake builds `adxt_integer_clock_tests`. The parent native project
also includes it. Sixteen assertions,132 original comparisons and two negative
controls pass with GCC15.2 and bundled UCRT LLVM21.1.8. The native source freeze
was recorded after original-corpus exposure and before comparator development.
