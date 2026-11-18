# Stock room script admission

The native loader uses the configured roots at EVB table slots 0 and 4 or room
table slots 8 and 12. It retains the numeric table slots, including holes.
The control-flow walk follows saved continuations, block advances, countdown
reentry, conditional scans and both allowed outcomes of offline context filters.
It refuses an unknown continuation, an out-of-bounds record, an unsupported
handler or exhausted proof budget before returning a program. Every retained
record must then pass the interpreter's payload validation. The loader copies
only the prefixes consumed during this walk, so trailing float and asset data
stay out of the program.

Both compilers independently produced the same result for 171 hash-verified
stock banks. The VM installed 25 ordinary and 20 offline room programs in the
admission probe. All five scenario EVBs still have open frontiers. The loader
retains both offline context outcomes per record, which can conservatively
reject paths that the original would skip under a specific actor context.

Both compilers also ran the stock `r0417300.rdt` script from its original
entry through the first block transfer and two additional invocations. The
36 controlled comparisons checked the two original dispatchers, continuation
and current pointers, table index, flags, scene controls, lighting and sequence
state. This used stock script bytes with controlled providers. The live scene
loader, original room resources, transport and game acceptance remain open.
[Qualification](../../tools/native_reconstruction/native_stock_script_program_qualification_v1.json)
