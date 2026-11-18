# Secondary pose body contacts

Status: qualified on both compilers; uninstalled. Step4 remains incomplete.

The native secondary pose path now implements complete61B250/61B330/61B390
capsule preparation and point correction, and61B920's character7 ordinary/high
model pass. The latter derives four points from actual anchor joints, corrects
them against two body capsules, and publishes four world joints with the source
orientation and fourth components. It preserves the character, appearance and
model-variant gates without inventing an active/visible gate inside this helper.

The finite nonnegative-radius math preserves two source quirks: the particle
radius affects collision admission while correction uses the capsule radius
alone, and the near-axis fallback can shift the projection's Y coordinate while
its displaced cross-product input keeps its old Y. These are behavior comparisons,
not proposed gameplay changes. An initial wrong cross-product order was caught
by the source comparison and corrected; failed evidence remains retained.

`Instance::patch_world_poses` validates joint indices and finite matrices, then
prepares a new immutable snapshot before changing world poses. Old snapshot
leases remain independent; sampled local poses and animation parameters stay
unchanged. Missing current publication and insufficient model cardinality refuse.

Both secondary-pose-contacts-{llvm,gcc}-v1 cohorts pass472,202 checks:
73,312 capsule/point cases,7,079 contacts,26 no-work gates and256 poses using
actual owned P07/HP07 skeletons, with1,024 joint patches and eight refusal cases.
The complete original contact/math bodies execute. Initial joint worlds come
from native hierarchy construction, which has separate original comparisons.
Both current World regressions pass13,276,674 checks, and five CMake parents pass.

Evidence: `tools/native_reconstruction/native_secondary_pose_contacts_qualification_v1.json`.
61AAA0/61A820 secondary dynamics and67C100/6613A0 reaction/head work remain open,
as do full scene phases and native game installation. No game, audio, renderer,
input, device or power action was used; no in-game slowdown cause is claimed.
