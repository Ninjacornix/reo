# Selected movie clock, cache and callback ownership

Status: next implementation contract. The counter/query core is qualified
separately. This document does not claim a reconstructed movie player, audio
filter, selected-clock owner or game test.

Execute complete owned paths for cached query `176350`, selected query `176418`,
external-clock wrapper `176578`, refresh `176930` and per-context tick `175E00`,
including their real counter, property, built-in callback and guard children.
Use the actual literal selector property `0x0F` and refresh/rebase property `0x47`
as independent inputs. The earlier counter comparison established that confusing
those properties is observable. Freeze original results before native code.

Cached query returns the stored pair unless its numerator is exactly raw -5.
Other negative numerators, and zero/negative denominators, are literal cache hits.
Only a -5 cache miss delegates to the selected query. Selected query enters the
tag-one guard, reads the current selector, invokes the selected callback or
unavailable fallback, then leaves the guard while preserving callback status.
The bounded initial table domain and callback signatures must be explicit; an
arbitrary source index is not permission to read past native storage.

External wrapper first executes the existing four-state admission. No external
provider yields -2/1. With a provider, preserve its in/out word write mask and raw
status. The original callback receives local words that may be untouched; the
comparison must declare their prior scratch contents instead of inventing a
successful timestamp. After the callback, consult the actual current active
counter predicate. If active and previous sample differs from -5, accumulate the
wrapped sample delta. Always retain the returned sample and denominator, and
publish accumulation/denominator, including when callback status is nonzero.

Refresh queries into declared owned scratch, compares raw numerator/denominator
with the cached pair and rebases through the real property-0x47 getter only when
the pair differs. Then store both new words in order. Always set pending work to
one, even if unchanged or the query status is nonzero. A per-context tick runs
the actual counter update first and refreshes only when property 0x47 equals one.
Do not substitute audio callback counts, display FPS or host wall time.

The native owner must retain a callback across its own invocation, including
replacement/removal of its table slot. It owns its clock/cache/history and
provides copied observations. No mutable state alias escapes to workers.
Registered providers and guards have an explicit bounded, serialized callback
contract. Nested query/service, owner destruction and arbitrary guest writes are
not inferred as safe. If declared callback fact updates are admitted, observe
them before the post-callback gate/rebase; do not reuse a stale initial snapshot.

Source guard wrappers ultimately call optional tag-one hooks and conditionally
change shared nesting/tag words. Execute those original bodies in the comparison
with declared hook inputs. A test guard is not proof of original thread priority
or complete cross-subsystem scheduling. Arbitrary callback/RAM mutation, invalid
selectors, unbalanced guards and actual runtime capture require their own
admission/lifetime closure before production binding.

Required evidence includes cache hit/miss, all admitted built-ins/fallbacks,
external prior-sample sentinel and wrapped deltas, untouched/partial outputs,
nonzero status, fresh callback facts, changed/unchanged refresh, exact-one tick
refresh, callback replacement lifetime and balanced optional guards. The actual
ADXT filter chain, due/skip hysteresis, stop/rebuild, frame/source ownership and
game/movie transitions remain independent requirements before stage 3 completes.
