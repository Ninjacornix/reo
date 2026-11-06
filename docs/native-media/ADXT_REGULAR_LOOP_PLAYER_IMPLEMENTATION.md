# Regular loop player and queued PCM validation

The actual native control owner now plays regular file loops from retained
imported AFS members. Its private session key also controls the runtime loop
flag. Source rewind, predictor/history restoration, queue credits and clock
state retain their existing owners. **Stage3 remains in progress.** No game or
actual audio device was opened for this work.

Both compilers pass all **89 references /80 distinct loop payloads**, with two
complete accepted output-copy cycles each: **962,466,636 channel samples**,
or 1,924,933,272 PCM bytes. Counts and hashes match the earlier independently
qualified decoder cycles. Complete per-asset rows also match between compilers.
Group/poll counts differ and remain recorded separately. Raw clocks agree with
the actual consumed-output ledger. There are no model underruns or skipped
samples, all sources join, every producer retires, and the shared provider has
one final detach/stop/unload. The installed import supplies actual sector tails;
this verifier never opens the ISO.

The first full runs exposed a real integration refusal at NETBIO01.DAT/1/36.
In its second cycle, 996 valid samples required a 1024-sample raw ADPCM write.
The actual free grant was 2040 bytes at offset 8; 2048 raw bytes would overwrite
eight queued bytes. The existing PCM guard correctly refused it. Both failed
runs, a focused diagnostic run and their sources remain preserved.

The separate [R3 contract](ADX_QUEUE_SAFE_WINDOW_CONTRACT.md) adds pure admission
against the actual PCM reservation. Before codec effects, R3 selects the largest
whole group count whose raw, corrected and published writes preserve queued and
held PCM. If none fits, it returns actual reservations and reports backpressure.
R2 remains available. A mechanical comparison verifies every other R2 algorithm
is unchanged. Requests can be split, so identical intermediate scheduling is
not claimed. Safety checks, predictor state and encoded credit were preserved.

Both compilers pass 3,618 PCM ownership assertions with zero post-construction
allocations, all 90 original storage clients and 30 intermediate original
captures. The complete storage transcript remains identical to the earlier
independent projection. The native control, phased player, their negative
controls and measured-clock original replay pass again. All **50 standalone
native suites** pass in both Release builds. The full finite-player regression
also covers 8,910 references /6,706 distinct finite payloads with exact earlier
PCM prefixes and no model starvation.

The post-copy observer exists only in derived verification sources and hashes
bytes after actual output acceptance. Production copying has no new callback.
Buffered model rendering is not audible-output proof or a slowdown measurement.
Counters remain bounded; unlimited loop duration is outside qualification.

The [qualification](../../game/native/adxt_control_session/regular_loops/qualification.json)
pins source manifests, ancestor snapshots, full run receipts, failed runs and
parent build/test logs. Principal local receipts:

| Evidence | SHA-256 |
| --- | --- |
| Imported loop GCC | `b8289f1b0a494ef403beb047104c472339f928e9ab4f357da27c980b326b6328` |
| Imported loop LLVM | `39a9219ca6e1047a3837fed83c1fbad7345693330be23cbf7a781750e3028224` |
| Loop comparison | `4dbc5057f09b9d95da401c5942debf316615b5a2c4100099f40598f71deeae00` |
| PCM/R3 GCC | `2fc6111f9683b6ef4a40e34b49df2b662f521f7db95ce2ec2307d7aea15da34f` |
| PCM/R3 LLVM | `e912d83eccfaf9a33b62135678a6eee53491c842175953bb92c4c98077d5e599` |
| Finite GCC | `8297867c16cea89860fdb8671601865b363c2d1debd1672c3f2c80092f04fa0f` |
| Finite LLVM | `b51d292a588fc152161b87558817b127fd9aa339ac4d26be7b5230b0405484d5` |
| Finite comparison | `e100e33e96034156ad60f3c7b5d1ab9892fd5f8e0c14c180f5d7bddd51595126` |

LSC/seamless ownership, combined bank/packet output, movie controls, game ABI
selection and controlled media transitions still gate stage 3. Gameplay and
scheduling, graphics/platform reconstruction and final runtime removal remain
stages4–6. No player executable has changed as a result of these offline checks.
