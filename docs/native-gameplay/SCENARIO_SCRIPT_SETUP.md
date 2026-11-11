# Native scenario and room script setup

The Update Owner binds the EVB roots to channels 0 and 4. The room roots bind
to channels 1 and 5 in ordinary mode. Explicit offline room setup can select
the primary room channel from 1 through 3 while updating channel 5.
These indices follow the source writes in `68C260`, `68C570` and `700330`.
The current native mode chooses the dispatch profile.

The interpreter validates both replacements before publishing either one.
A bank that lacks a secondary root clears that channel's previous binding.
Unsupported instructions, malformed policy data and unavailable room
counters leave prior bindings intact. A successful scenario bind initializes
the Session room counters and clears the four interpreter counters.

The native worker borrows its own World when invoking a script. The composition
test runs an imported scenario and room script through the actual worker and
checks the Session's authored F2 value. It also checks missing-policy refusal,
foreign World refusal and successful offline channel setup.

Both compilers passed the five native parent tests and the original-order
comparison of 2,048 worker and 4,096 phase cases. The receipt SHA-256 digests
are `7b17d5f7cb3e060743006952076a1aed674dab4d1f75a03e3b2dd92fef757d76`
for LLVM and `bc247a7844ef0055d6cd8823e91f2b83c246847b710cb813fd1e6bbbe4ba3be9`
for GCC, under `build-native-sjuni/gameplay-update-script-owner-*-v2`.
The startup and room transition callers must still supply the actual stock
banks and providers during live game execution.
