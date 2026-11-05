# Source attribution

`algorithms.hpp/.cpp` and the source-derived record/member/mix includes reuse
PS2Recomp's `ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/ReoSoundBanks.{h,cpp}`.
They retain the dependency's GNU General Public License version3, copied verbatim
as `LICENSE-PS2Recomp`. The qualified upstream base is
`c46d1c7d8ab00fbfa18d2c1f764c559e4e5dc78f` with the public124 patch series.

Reference CPP SHA-256:
`e164ba72cc002311d4811d803be2e2df9a6228d5abcaa0c4fa419a31ee09b818`;
header `28963da544d533ae8f04765558ff0665c4dc87c38cfba767a4828705c07616c8`.

Changes separate mutable globals into Session state, use immutable prepared bank
assets and session-qualified submission leases, preallocate render scratch,
replace callback logging with bounded diagnostic counters, and defer old decoded
clip reclamation to producer/control operations. A numeric-domain refusal guards
the original float-to-unsigned pitch conversion outside its defined input domain.
The packet decoder, guest memory, runtime/provider and host global gain functions
are not part of this component. `extract_reference.py` records the mechanical
extraction of the qualified existing algorithms; generated files are checked in.
