# Native pending-hit response

The independent `consume_pending_hit` function now owns the full original
pending-hit orchestration: early consumption/notice writes, authority and lock
gates, timed responses, status application, scene/equipment cleanup, progression
requests, high-kind response selection, health damage and state publication.
Production uses typed native state and domain services; it contains no guest
addresses, register context or generated-function dispatch.

The order matters. A rejected hit can already be consumed. Timed responses use
signed timer comparisons followed by halfword wrapping. Feedback can change
the damage subsequently read. A lethal ordinary hit can retain one health
point, whereas a handled override returns through its own path. A remote-class
publication can follow the ordinary publication; these calls are not deduplicated.
The temporary publication status is cleared from the post-callback status,
rather than restoring a stale snapshot.

Complete owned instruction review confirms the scene interaction index at
actor C7A is a **byte**. The related masked partner lookup and full partner
character lookup remain distinct. Equipment identity is reread after the first
detach callback. Native relation cleanup is a typed owner service: this core
does not retain the original pointer-containing 24-byte guest relation block.

Both compilers pass 131,072 comparisons and 718,877 ordered trace words against
seven complete original bodies, including actual health adjustment, authority,
hit override and pure cleanup helpers. Mutation fixtures check later reads,
early gates, transient flags, damage narrowing, equipment rereads and
publication ordering. The owned timer-prefix amounts 500/300/1000 are compared;
an out-of-span timer class is explicitly refused after its preceding consume
effects. This is admission policy for unsupported input, not invented original
behavior. The [qualification](../../tools/native_reconstruction/native_gameplay_actor_hit_qualification_v1.json)
binds all compared inputs and receipts.

The separate native health-class helper compares the source's 50/25 thresholds
across 589,824 finite signed-health/maximum cases per compiler. Category/status
bypasses and 64 zero-maximum admission cases are also tested. A required division
by zero is explicitly outside this helper's admission; reproducing PS2 FPU status
flags is not a native-game requirement. Its [qualification](../../tools/native_reconstruction/native_gameplay_actor_health_class_qualification_v1.json)
states that limit rather than substituting an unspecified host result.

Scene/inventory/progression ownership, actual feedback/publication providers,
complete actor composition and live callers remain migration gates. These are
isolated component results, not complete native combat or Stage 4 acceptance.

The combined source snapshot at commit 77f7e59c separately builds and passes
all 82 native regression suites on LLVM and GCC, with 693 sealed source members
and 74 native archives per compiler. The [combined qualification](../../tools/native_reconstruction/native_gameplay_combined_qualification_v1.json)
records its exact counts and identities. That snapshot precedes the new hit and
health-class companions, whose focused comparisons above are separate evidence.
