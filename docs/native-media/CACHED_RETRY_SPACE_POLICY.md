# Candidate retry space policy

The narrowly verified ordinary-ADXT retry keeps the normal **4 GiB minimum free
space** requirement. Its parent-output estimate is additional provenance, not
permission to reduce the reserve. This applies to future invocations; sealed
V20 build records retain the policy actually used by that invocation.

V20 passed with its earlier 2 GiB admission, but whole-machine free space fell
from roughly 2.9 GB to below 1 GB by completion. The parent materialization plus
two executable copies and margin was about 1.27 GB. That estimate did not measure
compiler peak usage, filesystem overhead or unrelated machine writes. Their
separate contributions have not been established. Therefore a smaller
materialization estimate does not justify a lower reserve. A minimum free-space
check is also not a guarantee against later external disk consumption.

The cache proof remains narrow: a successful matching full parent build,
identical compiler/ELF/complete compile plan, the same kit file set, one small
ordinary implementation change plus specified notices, and every copied object
and receipt hash. The ordinary worker still checks each compilation signature.
The ten declared-record policy tests cover the admitted case and refusal for
changed inputs, compiler, plan, incomplete cache and failed or altered parents.
They run no compiler or game and do not measure real disk demand.

Large builds and game tests remain paused while C: has approximately 0.5 GB
free. No cache deletion, system paging change or alternative deletion mechanism
was used to bypass the earlier automatic approval rejection.
