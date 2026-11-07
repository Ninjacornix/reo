# Native player attenuation control profile

The phased player, control Session and stable instance now have an explicit
optional original-unit attenuation profile. Construction retains a prepared
immutable `adxt_attenuation::Table`. The default raw-volume profile keeps its
existing arithmetic and admission rules. A table instance refuses direct raw
volume setters; a raw-volume instance refuses attenuation setters. Callers
cannot silently mix the two units.

A table player applies its initial signed-halfword request before source service
or play. Header readiness reapplies that request plus eligible AINF metadata to
the integer PCM volume before play admission. It leaves sample frequency, clock
quanta and decoder progress unchanged. The older window field named `pitch`
carries AINF attenuation; the table profile now consumes it in its correct role.
The default player still refuses nonzero values there. No actual pitch-changing
profile is added.

Stable instances own the attenuation request across stop/start and pending
replacement. A change while the old source retires applies to the next source;
it does not reopen or mutate retired output. Destruction/recreation resets the
request to zero. The read-only instance observation exposes the stored requested
halfword even while idle. Source-start config cannot inject a different table
or override this stable property; such conflicts refuse before retiring the
active source. The table must be qualified against the actual game/edition by
the eventual adapter.

The second cohort also admits immutable sequences and dynamic LSC sources.
Their private `Clip::parse` admission already rejects effective nonzero AINF
attenuation and nondefault channel pan. `Sequence::prepare` uses that parser;
LSC registration accepts only the same sealed immutable Clip type. A header
transition therefore cannot change the attenuation contribution. Existing
original-unit fades remain valid across those transitions without an invented
per-segment gain or per-pump clock. Nonzero AINF offsets in seamless clips still
refuse at preparation. Finite and supported regular-loop sources retain their
first-cohort behavior. Custom pan/downmix/pitch profiles retain their existing
refusals. An honest unsupported status is not
silence, a guessed gain, legacy fallback after native effects, or completion.

Checks must cover actual workers with nonzero AINF attenuation, pre-header and
live fades, request narrowing, independent peers, replacement while an actual
read is blocked, stale keys and fresh instance defaults. An actual-import check
must retain the owned table and files through mount/runtime retirement, match
the qualified payload baseline, and observe original table values 80 and 25 for
requests -100 and -200. Combined callback checks retain one bank/master/device
owner. Native game API/scheduler binding and audible A/V evidence remain required.
