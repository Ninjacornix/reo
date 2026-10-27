# File #1 Collections navigation audio

The original Collections menu calls `0x1D3BD0` to select `shop.snd` on
sound port 12. The function map merges this entry into another function,
whose generated entry switch exposes return continuations but not this entry.
Consequently the call was skipped and port 12 retained `start.snd` from the
title screen. Collections navigation then selected a vocal from the wrong bank.

`reo_collection_asset_entry` restores the original selector frame and filename
copy, then resumes the generated function at `0x1D3C68`. The original code still
loads the asset, sets reverb, and restores the stack and saved registers. Binding
uses both runtime dispatch and the direct-call override registry, as other
missing-entry adapters do. It is installed only for File #1.

## Validation (2026-10-27)

Compared the supported File #1 disc against PCSX2 2.2.0, then exercised the
native Release build with ordinary controller input and an isolated memory card:

- Entered Collections and navigated items and category tabs.
- The loaded HD, BD, and TQ data matched the original `shop.snd` byte for byte.
- All 128 stable port-12 sound configuration records matched PCSX2 in Collections.
- Confirmed return to the main menu restores `start.snd`, then re-entering
  Collections restores `shop.snd` and navigation continues to work.
- Built the final executable after removing temporary bank tracing;
  `git diff --check` passed.

Local captures and read-only comparisons are under the ignored directory
`build-ninja/collections-sound-investigation/`; no disc assets are committed.
This verification covers Collections navigation and the menu round trip, not
a full campaign playthrough or File #2.
