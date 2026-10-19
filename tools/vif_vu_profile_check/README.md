Run `tools\vif_vu_profile_check\run.bat` after building the Release runtime.

The fixture uploads an actual two-pair VU program through MPG and executes it
through MSCAL in a real VIF DMA write. Independent checks verify the E delay
pair's integer result, final PC/E state, uploaded code, original DMA input,
completion and clean shutdown. The aggregate TLS scope must be absent before
and after the write. Enabled and disabled runs must both pass; the log checker
requires exactly one VU call, two executed pairs, zero capped calls and VU time
within the complete write duration. Disabled profiling must emit no records.

This measures VU time inside selected VIF writes. Profiling is opt-in and adds
two clock reads per VU invocation in a selected write. It changes no instruction
semantics. Counts below a duration threshold are not emitted. Nested selected
writes restore their parent TLS collector; their VU work belongs to the nested
record rather than being counted twice in its parent.
