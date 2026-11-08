# Actual PCM voice-order handoff

The explicit native-source factory now returns a read-only `PcmOrder` capability
alongside its canonical source owner. It retains the **same** selected V3
aggregate and copies its actual raw voice-container traversal under the existing
PCM bridge's data lock. It exposes no mutable aggregate, independent guessed
map, source controller or rendering/device API. The capability is allocated
before SDK publication; failed selection returns no capability.

This prepares the guest adapter to translate raw RNA identities into a complete
native instance permutation. The game adapter must take the copy outside native
owner admission and output callbacks, validate every participating route and
publish that permutation before more than two streams play. Creation timing and
muted original RNA control bookkeeping still require actual guest binding. A
correct read-only order copy alone does not prove live mixed PCM parity.

Both compiler protocol cohorts pass 13 factory scenarios. The new scenario has
237 checks, including 16 actual facade voice configurations across default STL
bucket growth, replacement without reinsertion, release/reinsert, cold reset,
bounded destination refusal without writes, and a retained read after joined
backend teardown. It compares order with the compiler's actual unsorted host
container history. Existing real-worker, accepted-callback, publication-failure,
device-fence and legacy-route scenarios continue to pass. SDK130 object checks
compile the observer and changed factory with both production toolchains.

These protocol tests have explicit acquisition and device ports. They do not
claim real runtime admission or live game use. The native archives and aggregate
bodies are unchanged. V1 compilation exposed two missing aggregate-result field
initializers; V2 explicitly initializes the new capability on failure, then
passes both strict compiler cohorts. The failed inputs and logs remain retained.

See [qualification](../../tools/native_reconstruction/adxt_pcm_order_qualification.json)
for exact inputs and receipts. Post-source reset remains refused, and the
bootstrap still selects the earlier original-source route.
