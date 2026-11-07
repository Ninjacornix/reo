# Movie audio clock envelope

Next native boundary, File #1 US. Reconstruct complete `165C08` and slot-2
`165B48`, executing the qualified original filter and actual signed-byte ADXT
status and movie admission getters. Original `132160` estimator samples and
`17E870` hardware-counter samples are declared external observations at this
cut; no result hook may replace filter arithmetic or cache selection.

The envelope reads ADXT status, publishes its signed-byte value to the diagnostic
observation, obtains both ADXT words, sign-extends each to a 64-bit lane, reads
the helper counter and then its frequency, runs the filter and narrows both
output lanes to words. Preserve this order even when filtering is bypassed.
Do not reject a negative numerator or denominator merely because a host rational
library considers it invalid.

Slot 2 first admits actual states 4, -4, 6 and -6. The actual admission helper
writes -1/1 in ineligible states without sampling providers. Eligible states other than 4
publish the retained audio cache. Actual 4 queries the envelope and raises the
cache only when its signed word numerator strictly increases. Equal/decreasing
values preserve both old words, even when the denominator changes. This is a
raw signed maximum, not a rational comparison. The slot returns zero on all
these admitted executions; `165C08` has no normalized public return contract.

The native owner retains typed providers and filter/cache state. A native ADXT
binding must retain the actual control Session and its opaque generation key,
sample its real estimate using the actual supplied service tick, and reject
closed, stale or foreign keys. Provider failures must be visible separately
from original callback status, preserve prior caller words, and never claim
that already consumed observations or estimator effects were rolled back.
Serialize controls and queries; detect query reentry before effects. Provider
destruction and session retirement have independent fences.

The helper-clock provider owns its counter domain and frequency. This cut does
not qualify a host timer as a substitute for the original 16-bit extension, or
substitute presentation FPS for the service tick. Binding to the selected-clock
owner is explicit, with no default production selection. Movie construction,
pause/buffering/due/skip and source/frame ownership still gate stage 3. Stages
4–6 remain required.
