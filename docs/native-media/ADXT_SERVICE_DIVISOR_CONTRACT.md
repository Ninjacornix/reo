# Native ADXT service divisor

The File #1 engine initializer `1ADC00` supplies `30` to `ADXT_SetSvrFreq`
(`1328B8`) at `1ADEB8`. This is an input to the original ready configuration,
not an instruction to change game speed or output sample frequency.

Full original header (`12D638`) and ready (`133FE0`) replays were frozen and
executed before this extension. Six original templates, sixteen positive
signed divisors and both qualified FP workers produce 96 identical rows per
compiler. The captured request and decoder request agree in every row. The
original strictly rounds to the next 64-sample quantum for this ADX profile.
For 48 kHz / divisor 30 the result is 2432 samples for finite and 4864 for
looped headers. Loop detection here is the parsed header flag; it is separate
from the mutable runtime repeat enable.

`adx_window::service_r4` has a distinct C++ namespace and class ABI. It retains
the frozen R3 queue-safe implementation, extends readiness with a positive
signed divisor (default 60), and expands the admitted decode budget to the
already bounded workspace and PCM backing. Historical window implementations
and headers are unchanged. Separate historical archives cannot satisfy this
class's symbols. The shared source grants the new concrete class the same
private single-owner window-link operations; no mutable public alias is added.

Ready requests larger than the fixed 8192-sample output are unsupported. They
are refused before ready notifications and output configuration, rather than
clipped or allowed to throw from a noexcept service. Nonpositive divisors are
refused without changing the setting. This does not claim original behavior
for zero or negative divisors.

Player, canonical Session and stable Instances forward the setting. The stable
instance retains an explicitly set value across stop/replacement and clears
it on destruction/reuse. A source's own divisor applies when no explicit
instance setting exists. Setting the value after readiness changes the input
to later readiness; it does not resize the current decoder/playback request.
No worker scheduling frequency or game clock is changed by this control.

The standalone checks compare the captured original rows for both channel
counts, refuse unsupported sizes, decode every 30 Hz ready profile, and run
the inherited queue/credit/lifetime/allocation checks against the new class.
Stable-instance checks cover a pre-ready setter, an active setter, looped
playback, replacement, bad values, stale keys and defaults after reuse.
These are native owner checks. No actual guest ABI hook or audio device is
claimed by this contract.
