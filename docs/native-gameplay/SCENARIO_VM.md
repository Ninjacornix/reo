# Native scenario interpreter: partial capability boundary

Status, 2026-11-09: qualified native control-flow, flag and offline actor-delta core. This is **not a complete stock-script replacement**, is not installed in the game, and does not close Stage 4. Original instruction execution exists only in the isolated comparison fixture.

The versioned machine-readable ledger is [gameplay_scenario_qualification_v1.json](../../tools/native_reconstruction/gameplay_scenario_qualification_v1.json). It contains all 432 ordinary bindings and all 432 offline bindings, with separate supported masks and original target addresses. A mapped original function and an implemented native algorithm are different claims. A true algorithm bit also does not prove a production provider or migrated game caller.

## Native ownership and admission

[interpreter.hpp](../../game/native/gameplay_scenario/interpreter.hpp) owns six script channels, their current/saved positions, countdowns, block index and condition ordinal, four wrapping counters, and four actor event banks with four slots each. Programs own immutable bounded content blocks and use relative positions. They contain no guest addresses, register contexts or MIPS execution. The original authored bytecode remains game content; interpreting that bytecode is a native gameplay engine operation.

The importer must establish bounded block extents and replace the original block-pointer table. That actual stock-content importer is still missing. Program admission validates every encoded record, opcode range and supported-handler bit before a channel can install or restore the program. Any unsupported opcode refuses the **whole** program. Execution never performs a few native effects and silently falls back to the recompiler. Invalid positions, missing providers, recursion and exhausted operation budgets produce explicit statuses. Native admission bounds are deliberate supported profiles, not assertions that the original unchecked code enforced them.

The header low 24 bits select an opcode. Record bytes are `uint32_t((1u << ((header >> 24) & 31)) * 4u)`, preserving the original variable-shift and wrap behavior. A wrapped zero span is rejected during admission. Flow result zero advances, one retains the handler-selected position, and two re-enters before the special 0A/0D yield checks. Condition scanning preserves the original 32-opcode opener list, E4/E5 nesting, and 0A/0D boundaries. No host time, sleep or renderer rate changes the script clock.

[flags.hpp](../../game/native/gameplay_scenario/flags.hpp) owns scenario/secondary banks, three primary and three auxiliary actor banks, bounded byte/halfword banks, and a bounded strided-bank profile. The notification sink receives raw byte values and the selected-actor-plus-one or zero route synchronously after the local write. Notification operations refuse before their own mutation when no sink exists. Provider failures during a script invocation are reported; this module does not promise transactional rollback of already completed effects. Notification sinks and actual multiplayer delivery still require game integration.

Timer opcode45 uses the independently qualified [FlagTimers](../../game/native/gameplay_tasks/tasks.hpp). It preserves the packed low-halfword scope bit and signed countdown, with no independent scheduler or host-time ticking. RNG is not yet a supported opcode dependency; future handlers must use the shared native `gameplay_session::Random`, never a private per-VM stream. Message opcodes46/47/48 have typed `Signals` providers, tested with doubles; an authoritative native message owner remains missing.

## Separate offline path

The ordinary table at original717830 has 432 four-byte handler entries. The offline table at73CBE0 has 432 eight-byte records with a handler and three independent gating bytes. **41 handler bindings differ**. Ordinary coverage must never be applied to this second table: for example ordinary default slots175/176 and1A0..1AD contain real offline actions, while offline5/6 are no-ops.

[offline.hpp](../../game/native/gameplay_scenario/offline.hpp) implements the actual mode-zero wrapper7003E0 around offline dispatcher7006D0. It consumes three ordered authored party references resolved by the native actor owner, not guest pointers or a physical actor layout. Channel1 evaluates each active actor from one shared scenario/secondary baseline, records additions/removals and merges persistent actor deltas in original order. Inactive deltas remain present. Duplicate actor script classes share their original channel state. Class3 maps to channel0; this does not invent a fourth party member. Other channels run once with zeroed offline dispatch context and preserve the incoming selected actor.

The three gating conditions are independent: restricted/category>=2, relation-one with its byte, and relation-two with its byte. A skipped conditional opener still invokes failure scanning. Category zero local writes broadcast to three banks. Categories1..3 choose those banks. Category4 preserves a cross-family original alias: primary writes auxiliary0, and auxiliary writes scenario. These aliases are explicitly tested against the original bank helpers. The wrapper remains independent of the 32-linked-task scheduler and the separate event-task banks.

Root actor integration must resolve authored references through the native actor owner. New provider interfaces use `gameplay_actors::EntityId` where actual actor identity is needed; resource descriptors require a distinct resource identity. No conversion from a guest address is part of this core.

## Qualified subset and comparison evidence

Current ordinary algorithm mask is **252/432**: 221 no-op bindings, including the distinct192 no-op, plus31 substantive operations. Offline mask is **236/432**. Counts include no-op bindings and must not be presented as a percentage of whole gameplay, stock script occurrences, migrated callers or completed Stage 4.

Substantive families currently include saved/relative control flow01..08/0A..0D, actor event05/06 on the ordinary profile, scenario/local flag operations0B/0C, strided40..43, bounded44/49/4C/4D, timer45, typed messages46..48, E4/E5 scanning, and four-counter110..114 operations. The ledger contains every false bit; unknown or unimplemented operations stay false.

Both LLVM and GCC cohorts pass **38,455 assertions and425 actual-original entry invocations each**, using **1,604 owned instruction comments** checked byte-for-byte against owned overlay o2 SHA-256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`. Private receipts are `build-native-sjuni/gameplay-scenario-llvm-v6/receipt.json` and `build-native-sjuni/gameplay-scenario-gcc-v4/receipt.json`. The qualification ledger retains their hashes, compiler identities and source hashes. Each original source body is copied into the private receipt directory; no original game asset is committed.

Comparisons exercise saved pointers, blocks, countdowns, all256 header exponents, all admitted ordinary no-ops, actor event preservation, packed timer scope, unsigned counter boundary cases, flag/message selectors and raw values, all five offline actor categories with four relation values, and the complete three-actor wrapper over64 mixed active/class/room/disabled cases. Another40 wrapper cases cover all non-party channels, disabled execution and incoming actor selections. Unsupported whole-program admission and operation-budget exhaustion are explicit negative checks. Production providers are never substituted by the original comparison implementation.

## Corrections to earlier mapping prose

These original-body comparisons supersede three details in the older [SYMBOLS_SCRIPT_VM.md](../SYMBOLS_SCRIPT_VM.md) notes:

- Opcode0C with nonzero selector uses the local **auxiliary** bank at original4B9B40, not primary4B9A80. The offline handler applies the analogous auxiliary actor-bank mapping.
- Opcode47 with a nonzero desired selector passes when query680850 returns **zero**. Selector zero passes for nonzero query results. Opcode48 separately tests exact-one equality/inequality. Nonzero is not interchangeable with exactly one.
- Opcode04 returns to the dispatcher, which immediately checks/decrements the new countdown in the same invocation before yielding. Later calls continue the countdown; delaying that first decrement changes gameplay.

The earlier Save qualification is frozen historical evidence with its then-empty VM capability mask. It does not claim that this later partial VM core or its callers existed at the time.

## Remaining migration gates

The full stock program set is not yet admitted or traced by this core. Remaining ordinary180/offline196 operations need original-body contracts and typed native owners for resource/actor lifecycle, scenario sequences, camera/presentation, inventory, event tasks, messages and session coordination. Native resource30..37 investigations must preserve eligibility, room/lifetime gates and constructor/release dependencies; labels such as enable or reset do not establish those semantics.

Actual game integration must import/own bounded stock scripts, install one canonical set of channels/flags, preserve original caller order and script enable/mode selection, connect native message/notification owners, share native timers/RNG, and migrate every required handler before removing the original dispatcher. The save bridge must capture/restore these same canonical owners. No game, window, audio capture, live memory or full game build was accessed for this qualification. No performance improvement or stutter diagnosis is inferred from offline semantic parity.
