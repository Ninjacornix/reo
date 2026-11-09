# Offline human actor selection for read-only diagnostics

2026-11-09, File #1 US. Static original-word audit only: no game, process,
window, input or build action ran. This corrects a diagnostic identity
assumption; it does not diagnose a game-code room-transition failure.

The byte at `4BADED` is not a permanent human-player index in offline mode.
`669F30` writes each active actor's byte `+3` there at `66A018`, then resets it
to zero at `66A2C4`. An external reader can therefore observe different actor
slots during one update. An in-context game callback and an asynchronous
external observer do not have the same meaning for that byte.

The actual input router `1B0B80` establishes a better offline discriminator:

- The session getter `1B0300` reads **one unsigned byte** at `3243F2`.
- In session mode **0**, `1B0B80` keeps its initially zero port index and copies
  input from port 0 only when actor byte **`+FF0 == 0`**. The `lbu` at
  `1B0BE8` and nonzero branch at `1B0BEC` skip input copying otherwise.
- Mode 1 instead compares actor byte `+3` with `4BADED`; modes 2/3 take the
  separate actor-to-controller map at `2B8E90`. Those modes are not admitted by
  the offline selector described here.

`5EB0D0` initializes the roster from launch record `316680`. The first unsigned
count at `316684` uses consecutive actors from `4A5C30`, stride `10E0`, and
writes `FF0=0` at `5EB154`. The following count at `316685` writes `FF0=1` at
`5EB19C`. Consequently slot zero is the sole human-input slot **if the actual
launch count at `316684` is one** and the actor remains eligible. This audit
does not observe that runtime value or claim slot zero unconditionally.

`5EB520` independently assigns actor byte `+3` to its physical roster index:
`5EB598` stores the index, `5EB59C` increments it and `5EB5A0` advances the
pointer by `10E0`. That provides a consistency check before using a sampled
actor's position or writing ordinary pad input.

A conservative external test should require mode 0, eligible gameplay state,
one unambiguous active actor with `FF0=0` in its admitted four-player scan, and
byte `+3` equal to the physical slot. Recheck identity and eligibility before
each pad publication, and stop on an ambiguous or changing selection. Reading
the actual launch counts and corresponding character ID (`316688+i` versus
actor `+B98`) supplies additional identity evidence. A class-zero filter is an
extra diagnostic restriction: **`1B0B80` itself has no class-byte `+2` check**.
Likewise the input router does not independently test activity; the enclosing
actor loop supplies its nonzero-active gate.

The original actor loop has eight entries; this diagnostic's four-player scan
is deliberately narrower. This is not a new claim about arbitrary custom
rosters, additional active slots, another edition, or network control routing.
The existing `actor_snapshot.py` name `localActor` should not be treated as a
permanent offline human identity solely because it samples `4BADED`.

Seven complete bodies/leaves are checked against the owned main ELF and o2
image: **534 commented instruction words, 46 omitted zero words, no mismatch**.
The selected mode, FF0 stores, physical-index stores and temporary-index writes
are also asserted directly. The reproducible read-only audit is:

```powershell
python tools/native_reconstruction/audit_offline_human_actor_selector.py --output build-native-sjuni/offline-human-selection-v1
```

The output folder must be fresh; the recorded completed result is bound by the
[qualification record](../../tools/native_reconstruction/offline_human_actor_selector_qualification_v1.json).
