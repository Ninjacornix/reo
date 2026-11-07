# Owned selected movie clock

`Clock` owns one typed counter/cache/history and seven bounded callback slots.
It reuses the qualified movie counter core. Query providers receive copied state
and explicit prior words; selective replies preserve untouched outputs, raw
status and declared fact updates. Both selected and external providers are
retained across their own invocation, including self-unregistration.

`execute` accepts point-of-use scratch words explicitly. This matters when an
original callback leaves its local outputs untouched: preceding calls may have
overwritten the old frame. Those words are raw evidence, not a validated playback
timestamp. The eventual game binding must supply actual admitted inputs or retain
the original path; default zero scratch is not a general equivalence claim.

The initial guard profile admits paired, pure, externally serialized hooks and
the original counter/tag effects. The guard seed is an isolated context input.
Shared CRI guard ownership, cross-consumer nesting and thread-priority behavior
still require integration; this class is not their global authority.

Callbacks may replace a slot and return bounded fact updates. Nested query/service,
owner destruction, I/O and allocation inside callbacks are outside the admitted
contract. Nested execution is refused before effects. The optional probe receives
copied snapshots; it performs no device or guest work.

See the [contract](../../../docs/native-media/MOVIE_SELECTED_CLOCK_CONTRACT.md)
and [evidence](../../../docs/native-media/MOVIE_SELECTED_CLOCK_IMPLEMENTATION.md).
ADXT audio filtering, due/skip policy, frame/source lifetimes and game binding
remain. This isolated owner is not selected in the game.
