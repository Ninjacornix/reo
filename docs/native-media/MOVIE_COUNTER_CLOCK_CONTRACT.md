# Movie counter clock and rational query contract

Status: pre-implementation contract for the next movie-control cut. The complete
movie player, clock callback selection, audio filter, due/skip controller and GPU
frame lifetime are not implemented by this proposed component.

Recover and compare complete owned File #1 bodies for `175E50`, its real
`175EC0`/`175EF8` predicate children, `175F20` with its real `175628` property
getter, and built-in rational queries `1764B0`, `1764F8`, `176558` with the real
`176670` admission child. Preserve all source words and freeze their original
outputs before writing a native implementation. No clock-result hook, host timer,
GPU presentation count or native implementation may supply the original answer.

The native state uses ordinary typed words for actual/requested state, explicit
pause, buffering pause, counter increment, active counter, elapsed counter and
elapsed origin. On one admitted tick event, `175E50` increments active counter
only for actual state 4 with both pause words zero. It separately increments
elapsed counter only when that counter is not the raw -1 sentinel and requested
state is 4. Either increment may wrap modulo 32 bits. These gates are independent;
pause must not suppress the requested-state counter by analogy.

`175F20` selects active counter when property 0x47 is exactly 1, otherwise the
external accumulated counter, and writes the selected word to elapsed origin.
Do not normalize nonzero property values to 1, reset elapsed counter, or sample a
new clock during this operation. The original property getter must execute in the
comparison; the native component receives that typed property observation.

Rational queries distinguish raw word values, write masks and status. States
4, -4, 6 and -6 are eligible. Ineligible admission writes -1/1; eligible admission
leaves both caller-provided output words untouched. The unavailable callback
writes -2/1 after successful admission. The counter callback writes active
counter/shared frequency after successful admission, preserving arbitrary raw
denominators including zero. The contextual callback always returns zero but
does not initialize eligible output words. No generic valid-time normalization
or denominator admission may replace these source rules.

Include independent state/pause/property/sentinel boundary cases, negative and
wrapped counters, zero/negative frequency words, selective unchanged outputs,
source memory guards and actual lower64 ABI restoration in the frozen corpus.
Use a bounded original-word runner with no unowned control transfer. The native
implementation must compile independently of PS2Recomp and must not expose guest
memory, register files or native-state setters disguised as clock observations.

This cut does not establish the origin/frequency of tick events. Its eventual
movie owner must supply the actual admitted event and retain source generation,
requested/actual state, explicit/nested pause and buffering state correctly.
Cache misses, callback selection/registration, external clocks, ADXT filtering,
due/hysteresis, frame return and stop/rebuild remain separate complete contracts.
