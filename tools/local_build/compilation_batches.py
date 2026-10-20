"""Group ordinary generated functions; keep special compiler exceptions separate."""
from copy import deepcopy

# Larger batches remain experimental: one full-build guest body differed.
GENERATED_BATCH_SIZE = 8


def with_generated_batches(plan, batch_size=GENERATED_BATCH_SIZE):
    result = deepcopy(plan)
    for group in result.get("sourceGroups", []):
        # Only replace the historical default. Explicit/custom group limits,
        # standalone overrides and their compiler options remain authoritative.
        if group.get("id") in {"main", "overlay", "extra"} and group.get("batch", 8) == 8:
            group["batch"] = batch_size
    return result
