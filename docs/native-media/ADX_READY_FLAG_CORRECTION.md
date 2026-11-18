# ADX ready enable-flag correction

Status: correction implementation under qualification, 2026-11-06. The prior
Window2 is frozen; its Source2, header, workspace and PCM implementations remain
unchanged. This does not alter the normal game build.

Original133FE0 calls12D838, which forwards to124F10. The latter reads signed
inner halfword24: the loop-enable flag. The native Window2 incorrectly selected
the ready branch from the separate signed count/alignment word20. Prior original
clients paired those fields as0/0 or1/1, so that comparison did not distinguish
the mistake. The actual asset inventory includes13 references with count0 and
enable1; all89 loop-metadata references were explicitly excluded from the
completed non-looping full-asset decode run.

The new48-case corpus varies count0/1/13/-1 independently from enable0/1, over
three rates and header versions3/4. Inputs were frozen before the correction;
original instructions and old observations are unchanged. Corrected selection
must use the signed enable halfword. The frozen implementation is a negative
control, not silently relabeled as passing the wider domain.

The separately built implementation is
`game/native/adx_window/v2/ready_flag_r1/stream_window.cpp`. It uses the same
concrete class/interface and Source2 friend, with exactly the ready predicate
changed; the include is rebased mechanically. An executable must choose either
the frozen library or the corrected library, never link both. Keeping the type
does not grant any new Source2 access or widen its lifetime contract.

Required checks: original transcripts unchanged under read-only observation;
both compilers on all new cases and123 previously admitted whole clients;
frozen implementation detects the independent flag/count differences; inherited
owner tests and parent Release build; then real loop-bearing asset/control
validation. The complete player, RNA/DTR credits, LSC and device integration
remain separate stage-3 boundaries.
