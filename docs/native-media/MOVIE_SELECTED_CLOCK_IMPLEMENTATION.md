# Selected movie clock/cache ownership evidence

The native owner now implements cached and selected queries, the external sample
wrapper, cache refresh and per-context tick. It reuses the native counter/query
core and owns its cache/history and callback slots. Registered and external
providers receive copied state and explicit prior words. Their selective replies
may update admitted facts or remove a slot. A strong invocation reference keeps
each provider alive until its callback and dependent work finish.

The source authority executes complete owned paths through 22 bodies, including
real counter/property/built-in query children and all optional-guard adapters.
External query and enter/leave hooks are declared scripted inputs. Their sample
values, status and bounded mutations are explicit test ports; this is not proof
of a real clock source, audio filter, runtime factory or thread-priority policy.

The pre-native v2 corpus contains 546 cases and 70,201 original instructions.
It covers all seven admitted slots, built-ins/custom/null fallbacks, the exact
-5 cache sentinel, arbitrary raw cached pairs, partial/untouched callback outputs,
nonzero status, post-callback facts, previous-sample sentinel/wrap, changed and
unchanged refresh, exact-one tick refresh, removal of selected slots and optional
guard hooks at zero, nested and wrapped depths.

Initial comparisons caught incorrect guard transcription: the tag is cleared
when leave reaches depth zero, and the leave hook is still invoked at nonzero
depth. They also exposed a scratch-binding mistake. A tick's earlier counter
call can overwrite a later refresh frame; eligible contextual callbacks leave
those overwritten words untouched. Entry-time fixture seeds were therefore not
the words actually consumed. The failed candidates and receipts are retained in
`build-native-sjuni/movie-selected-clock/failed-v{1,2}-inputs` and
`qualified-{gcc,llvm}-v{1,2}`. LLVM also caught a missing explicit standard header
in the first unit fixture; it is corrected.

Original-only v3 adds read-only observations of local words at actual refresh and
external-wrapper entry. It records that a native candidate existed and pins that
candidate. The verifier proves that all earlier original inputs, state/status
results, ABI/guard checks, instruction visits, reads/writes and callback traces
are unchanged after removing the new observations. The native fixture receives
these actual point-of-use words as explicit opaque inputs. It never receives an
expected query result as scratch, and it does not classify old frame bits as valid
timestamps. This observation extension is not labeled entirely pre-native.

Both GCC 15.2 and pinned LLVM 21.1.8 match every case's typed state, registry and
guard projection, caller output words, defined status and callback-time/guard
snapshots. Actual callback/hook invocation counts and hook parameters are checked.
Seven counterfactuals detect generic-negative cache misses, discarding nonzero
query status during refresh, stale post-callback gating, missing previous-sample
sentinel, unnecessary rebasing and missing selected/external callback retention.
The lifetime units refuse destructive self-removal in negative builds when no
invocation reference exists, so they detect the missing fence without a UAF.

The native owner has no PS2 execution, guest memory, worker, device, host timer or
floating-point operation. Its admitted callbacks and guard hooks are bounded and
serialized. Guard seeds are isolated inputs; cross-context/shared CRI guard
ownership, arbitrary guest mutation/reentry and real priority/scheduling remain
outside this profile. No game override or production backend has been selected.

This is not the ADXT `165C08`/`177EB0` filter, complete movie construction/reset,
pause/buffering controller, rational offset/due/skip path or GPU frame/source
owner. Those contracts and actual game/movie transitions still gate stage 3;
gameplay, graphics/platform migration and runtime removal remain stages 4–6.
