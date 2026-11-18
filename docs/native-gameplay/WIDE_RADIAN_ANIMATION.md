# Wider authored animation rotations

Status: qualified on both compilers; uninstalled. Step4 remains incomplete.

The actual object/model/motion audit found74 controlled clock/pair cases with
rotations outside the native one-revolution admission bound, reaching about76.6
radians. The original18F570 reduction supports these inputs. Native math now
admits the nonwrapping signed16 winding range: the FP32 quotient of angle times
the owned reciprocal-pi constant must be in[-32768,32767). Values outside it
refuse before host integer conversion. The polynomial, constants, FP32 operation
order and ordinary unsigned16 actor-angle behavior are unchanged.

Both wide-transform-math-{llvm,gcc}-v1 cohorts pass262,129 additional bitwise
comparisons against complete original18F570 execution. They include adjacent
representable values around65,531 winding boundaries and65,536 wider random
angles. Existing65,536 angle conversions,73,744 small-range trig cases,131,072
Euler cases and matrix/direction/scale checks pass. The verifier now reads and
hashes the actual checked-out runtime macro header, rather than a private build
copy; no dependency source or library was changed.

The real-data composition audit now completes1,236 of1,356 model/motion/clock
pairs: all74 previously refused angle cases complete seventeen controlled
updates. The remaining118 track-cardinality refusals, two nonfinite clip cases
and12 missing-model descriptor requests stay explicit. Full World regressions
pass13,276,674 checks and all five CMake parents pass on both compilers.

Evidence: `tools/native_reconstruction/native_wide_radian_qualification_v1.json`.
This admits required native arithmetic and corrects a reconstruction limitation.
It is not a newly recorded game slowdown cause or measured speedup. Full scene
cadence, remaining data/actor/pose consumers and installed gameplay acceptance
remain open; Step4 is not complete.
