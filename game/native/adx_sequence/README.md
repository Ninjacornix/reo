# Prepared immutable ADX sequences

`Sequence::prepare` validates two to sixteen retained immutable sector-backed
views and returns a sealed read-only sequence. It performs bounded header/tail
I/O on the control thread. Playback reads cross file boundaries without payload
copies, new paths or synthetic padding. Backing immutability remains the source
provider's obligation; preparation does not snapshot the full payload.

The private player requires the exact prepared view identity to enable its
bounded seamless profile. Output geometry and source limits are checked before
decoder publication. Source polling stays explicit, and next-header readiness
uses actual source publication, not a callback count or guessed EOF.

Read the [contract](../../../docs/native-media/ADX_IMMUTABLE_SEQUENCE_CONTRACT.md)
and [validation](../../../docs/native-media/ADX_IMMUTABLE_SEQUENCE_IMPLEMENTATION.md).
This is not a dynamic LSC source or a selected game backend.

```powershell
python game/native/adx_sequence/verify.py --cxx C:/msys64/mingw64/bin/g++.exe --output build-native-sjuni/adx-sequence/new-gcc-run
```

Use a fresh scoped output. The verifier runs preparation and real private-owner
checks and four counterfactual controls. Its additional exact-size independent
view test is derived in the output directory. The source manifest predates that
helper; the helper and generated test identities are recorded in its receipt.
`tools/native_reconstruction/verify_imported_adxt_sequences.py` accepts the
installed File1 `--data-root`, exact compiler and fresh scoped output. It checks
all 6,706 payloads against the earlier independent native decoder baseline.
The comparator retains scheduling/padding differences separately. These checks
open neither the game nor a real audio device.
