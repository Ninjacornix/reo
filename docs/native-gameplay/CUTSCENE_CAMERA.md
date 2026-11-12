# Cinematic camera playback

CutsceneCamera borrows the sole playback controller state. Selection uses its
camera selection/end bytes and low16 frame; paired pose interpolation uses the
signed32 difference from the current key. The controller alone advances that
same simulation frame. No second media or pose clock is introduced.

PreparedCameraTracks copies bounded selection and56-byte curve records from the
retained0950 descriptor. Native selection reproduces5EE950 and5C0970, including
one event per stream visit, nonzero clock-mode half-frame comparisons, retained
final pose bindings, type0 eye versus nonzero aim binding, and continued stream
visits after selection ends. Selection reaches the existing canonical Fog owner
through6B2200; room Lighting selection is a different operation.

The paired evaluator reproduces complete5C09A0, including fixed terminal poses,
quadratic position curves, separate scalar easing, signedword roll interpolation,
conditional low16 truncation and preserved near/far/up fields. Far is the first
projection field324178; near is32417C. Complete375A50 view math composes the native
Euler basis with the normalized direction basis and orthonormal inverse. The
in-place191820 basis operation preserves translationXYZ.

The sole CutscenePlayback accepts unique camera ownership only for its exact
state and only while idle. Refused binding preserves caller ownership. Native
selection and sampling run directly inside the complete controller order. A
sampled pose requires the explicit375920 publication capability; its default is
unavailable, preserving the sampled prefix and leaving the frame uncommitted.
Unbinding or rebinding during a callback refuses, as does closing the live World.

Independent LLVM and GCC cohorts each pass:

- 6,684,672 view/basis/inverse checks, including131,072 complete375A50 cases.
- 23,585,303 paired evaluator checks and2,196,607 original helper calls.
- 3,946,506 selection checks over262,144 updates and490,880 retained binding visits.
- 2,487,321 full controller checks,256 bound camera updates and3,072 callback binding guards.

The current CMake pair also passes20,155,942 checks across all548 admitted owned
scene descriptors,1,092 streams,2,833 keys,1,123,196 updates and1,118,590 samples.
Prepared records remain usable after548 descriptor/source buffers retire. The
fixture supplies explicit initial projection/pose values and a separately
qualified cold fog catalog; it does not infer room renderer configuration.

Development controller v15 retained a qualifier syntax error before compilation;
v16/v17 retained source-freeze failures from concurrent shared schema edits.
V18 passed the previous projection field names; v19 and current CMake evidence
capture the corrected far/near names. All earlier cohorts remain distinct.

[The seal](../../tools/native_reconstruction/native_cutscene_camera_qualification_v1.json)
records all ten exact receipts and scoped working-source hashes. Current CMake
receipts retain the concurrent voice-registration source identity as well.
Independent new projection/fade units are excluded from this checkpoint. No game,
renderer/device installation or complete Step4 claim is made.
