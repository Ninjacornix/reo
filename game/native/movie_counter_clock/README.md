# Native movie counter and built-in query core

`execute` implements the admitted integer counter, rebase and built-in rational
query operations with typed state and selective ordered effects. It never samples
a host clock. The future movie owner must supply actual admitted tick events.
The active and elapsed counters have different gates; nonzero pause does not
suppress the elapsed counter when its own sentinel/request gates admit it.

Rebasing selects its source using property `0x47` exactly equal to one.
Callback selection property `0x0F` is separate. Eligible contextual queries leave
both supplied words untouched. Zero denominators and raw signed sentinels remain
literal; the core does not invent valid playback timestamps.

See the [contract](../../../docs/native-media/MOVIE_COUNTER_CLOCK_CONTRACT.md)
and [evidence](../../../docs/native-media/MOVIE_COUNTER_CLOCK_IMPLEMENTATION.md).
This is an isolated core, not a movie player or game-clock binding. Selected
callback/cache authority, audio filtering, due/skip decisions and frame/source
lifetimes remain before stage 3 can complete.
