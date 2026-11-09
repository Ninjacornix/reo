# Ordinary ADXT regression after native service binding

Both LLVM and GCC pass the complete **34-scenario ordinary-adapter regression**
and detect all **10 private injected faults** with the independent-service
binding changes present. The three new queue-feeder cases remain a separate
[focused cohort](NATIVE_AUDIO_QUEUE_WORKER_BINDING.md); the full regression's
scenario count is unchanged. No failed mutation anchors or retries occurred.

| Cohort | Expected-outcome scenarios | Detected faults | Compiler/test checks |
| --- | ---: | ---: | ---: |
| LLVM | 34 | 10 | 55 |
| GCC | 34 | 10 | 55 |

The checks include ordinary/three-source metadata, one/two-source ordering,
admission refusals, unsupported producer/callback boundaries, changed-child
identity, foreign runtime and guest-depth refusal, query aliases, mono/stereo
pan admission, bounded trace/lifecycle cases, finite queued audio, full E3
audio, append/repeat and malformed descriptor/member refusal. The full E3
adapter case retains its independent PCM comparison, rather than substituting
completion of the shorter finite cue.

Private faults remove child retirement, fall back to an unsupported original
producer, ignore child replacement, omit native discard, require an unused
mono pan field, ignore active stereo pan, require raw order for two sources,
ignore missing order for three sources, omit muted metadata refresh, or ignore
metadata refresh refusal. Each mutated adapter is compiled separately and
fails its intended fixture case. The production adapter remains unchanged.

The fixture compiles actual `ordinary_runtime.cpp`, game handles and source
profile against the qualified native audio/core archives and real immutable
owned imports. Runtime registry, factory acquisition and callback registration
are declared ports. The factory's fixture worker handles retirement; these
group-driven regression cases do not link the production composite refill
thread. Independent worker timing and actual game tests remain separate.

Both cohorts test production adapter SHA256
`5096f8f723548b6a7fb614144bc1246b9c92be4ca2530aca2f3210b6e88223b7`
and fixture SHA256
`6ea2726ee924dfa5b2dabed44695a9a38617a9125484a3ca48af426abe45bcdd`.
They verify all original-word/source and native/archive identities before and
after testing, with the explicit exception described below. Every imported
file's identity/stat tuple and the import manifest remain unchanged.

Final receipts:

- `build-native-sjuni/adxt-binding/ordinary-independent-service-regression-llvm-v1/receipt.json`,
  SHA256 `9ef6968989ca41b1f146adb14ffe3abbe84b6ce3b53fd485b35f04bf0a6aaddb`.
- `build-native-sjuni/adxt-binding/ordinary-independent-service-regression-gcc-v1/receipt.json`,
  SHA256 `d5cf6c2d353bf11fb9981c86c094c848be5f09fd5359dcf179a6c74262297cdb`.

## Strict default and explicit movie-archive exclusion

`verify_adxt_ordinary.py` retains strict source/archive verification by default.
The separately retained default-mode check rejects the known movie-session
source mismatch before creating any build output directory.

The optional `--exclude-unused-host-movie` flag excludes exactly one identified
`host_movie/libreo_native_host_movie.a` from this ordinary-audio link. It permits
only the following exact unlinked source delta:

| Source | Qualified archive-cohort source SHA256 | Current V36 private movie-fault source SHA256 |
| --- | --- | --- |
| `game/native/host_movie/session.cpp` | `5b4d5b6dc4d0808cd4c98ace8d49d3ea700f0af48079f966f125e8ad8665eb70` | `7df89065b4f0f62905639f0bf4cbc206ffa1c06e0c31a316feb8f756181393de` |

Any other source delta still fails. All **68 archive hashes**, including the
excluded archive, are verified unchanged; the remaining **67 archives** are
the identified link inputs. Each receipt records the exact excluded library,
unlinked source proof and linked archive hashes. This is not a blanket skip
for movie files or evidence of a fresh complete current 80-suite native build.
Actual V36 movie fault/recovery has its
[separate qualification](NATIVE_MOVIE_V36_ERROR_RECOVERY.md).

Use the normal full verifier arguments with the explicit exclusion flag when
reproducing these same inputs. Omitting `--trace-only` and `--queue-only` keeps
all 34 scenarios and all 10 fault checks. The default strict-refusal evidence is
`build-native-sjuni/adxt-binding/ordinary-independent-service-strict-refusal-v1`.

## Scope of the result

These builds and fixture runs overlapped ongoing V37 game acceptance work.
Their compilation, hashing and imported-asset reads add host load. Concurrent
game observations are stress retests, not isolated performance benchmarks;
the root acceptance record supplies their exact session overlap. Both cohorts
have finished; a subsequent quieter A/V run can proceed without their
compilation and fixture-test load.

No game, target-process, input or window action occurs in this verification.
The [V36 gameplay audio shortage](NATIVE_AUDIO_V36_RESOURCE_STALL.md) still needs
the independent worker's controlled/game retest evidence. These full ordinary
regressions preserve prior behavior but do not independently confirm that
incident's fix, final A/V synchronization or Step 3 completion.
