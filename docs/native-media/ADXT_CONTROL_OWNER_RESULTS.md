# Native controller and source shutdown checks

The controller admission owner passes all three workflows on GCC and LLVM.
The combined native project has **73 passing suites** on each compiler. The
new owner preserves one canonical native instance Session and its separate
render lease; it does not create a device, run guest scheduling or bind game
audio functions.

Real native workers exercise a blocked mono source and independently rendering
stereo peer. A controller operation remains accepted while another caller waits.
Stop refuses new callers immediately. Join waits for the accepted operation
before closing private output, and the already waiting caller is then refused
before effects. Private output closure is not counted as completion while the
first source still owns a blocked read. Completion follows its real read/worker
acknowledgement. The final private snapshot has no instances/source records and
does not claim an outer device fence. Retained rendering remains safe after the
controller is destroyed.

All three injected faults fail on both compilers: removing the admission recheck
after the mutex, bypassing the controller fence during join, and publishing a
pending source cancellation as completed. Source/provider/model scopes remain
explicit. The tests do not reproduce the runtime destructor or guest scheduler;
the destructor order motivating the guard is separately verified from the
audited dependency source.

The aggregate checks now pass **15 scenarios** per compiler. Actual native
workers render through the model's one combined PCM/bank/master callback. A
second callback pauses at the existing raw-PCM/native-submix/bank boundary;
the native controller joins and is destroyed while the outer callback remains
accepted. That callback resumes safely through the closed retained submix, and
banks continue on a third callback. There is exactly one outer attach, detach,
stop and unload, with no callback allocation or free. The null-native profile
still matches the qualified parent across 21 cases, 287 actions, 9,316 sample
bitwords and 10,052 hooks, retaining its 14 raw terminal-policy differences.

Initial aggregate fixture results are retained in
`native-audio-aggregate-v3/control-owner-{llvm,gcc}-v1`. They expected the pause
hook to follow native PCM; the actual hook precedes it. V2 first renders native
PCM in an ordinary callback, then exercises shutdown at the real boundary.
Production owner/aggregate code was unchanged by that fixture correction.

All source/compiler/archive/receipt identities are in
`tools/native_reconstruction/adxt_control_owner_qualification.json`. Runtime
registration, guest source/control APIs, scheduler ordering and live A/V
validation remain Step 3 requirements.
