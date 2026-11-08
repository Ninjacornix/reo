# ADXT service divisor results

Both compiler cohorts pass **77 standalone native suites**. The new distinct
`service_r4` class matches all 96 captured original ready requests for both
channel counts: 154 admitted and 38 explicitly refused sizes, with twelve
successful 30 Hz decode cases. Each compiler detects three injected faults:
hardcoding divisor 60, retaining the old 76-group decode limit, and losing the
stable divisor on source replacement.

The canonical game-control suite also runs regular looped playback with the
4864-sample request and stereo finite replacement with the 2432-sample request.
The combined runtime factory's twelve declared-port scenarios and game handle
router's three workflows pass again on both compilers; the router detects its
three existing ownership faults. The factory compiles against actual audited
130-patch SDK headers with each compiler. No game or audio device was opened.

The original evidence is a full header/ready replay, not an implementation-derived
formula. Each compiler executes 183,936 original instructions for the 96 rows.
The output SHA-256 is
`28d0c51c1a9de79351b28ed85aefbfd2214c188dfe8166c074825c1ef76cf41a`.
The dynamic-divisor input manifest was frozen before authoring this extension.
It records the existing fixed-60 implementation explicitly.

V1 built successfully with both compilers but its new quantum test stopped at
the first intentionally refused request: the cleanup assertion expected an
ordinary stop status from a faulted owner. The test now accepts the retained
`owned_fault` and verifies actual retirement. Its complete 420-input snapshot
and failed receipts remain under `build-native-sjuni/adxt-service-divisor/v1-source`.
The production code did not change for that correction. V2 was a local targeted
check; V3 is the fresh complete two-compiler cohort, including the fault driver.

`tools/native_reconstruction/adxt_service_divisor_qualification.json` records
the source manifest, original replay, native archives and ten new receipts.
The guest ABI hook is still absent; this is a required control correction on
the way to actual source/service integration. Step 3 remains open, and the
machine-sleep request has not been executed.
