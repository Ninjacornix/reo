#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C8D60
// Address: 0x1c8d60 - 0x1c8eb0
void sub_001C8D60_0x1c8d60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C8D60_0x1c8d60");
#endif

    switch (ctx->pc) {
        case 0x1c8d84u: goto label_1c8d84;
        case 0x1c8dbcu: goto label_1c8dbc;
        case 0x1c8df0u: goto label_1c8df0;
        case 0x1c8e04u: goto label_1c8e04;
        case 0x1c8e18u: goto label_1c8e18;
        case 0x1c8e3cu: goto label_1c8e3c;
        case 0x1c8e50u: goto label_1c8e50;
        case 0x1c8ea0u: goto label_1c8ea0;
        default: break;
    }

    ctx->pc = 0x1c8d60u;

    // 0x1c8d60: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1c8d60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1c8d64: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1c8d64u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1c8d68: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1c8d68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1c8d6c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8d6cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8d70: 0x2484cd80  addiu       $a0, $a0, -0x3280
    ctx->pc = 0x1c8d70u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294954368));
    // 0x1c8d74: 0x240500ff  addiu       $a1, $zero, 0xFF
    ctx->pc = 0x1c8d74u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1c8d78: 0x240603d4  addiu       $a2, $zero, 0x3D4
    ctx->pc = 0x1c8d78u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 980));
    // 0x1c8d7c: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1C8D7Cu;
    SET_GPR_U32(ctx, 31, 0x1C8D84u);
    ctx->pc = 0x1C8D80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8D7Cu;
            // 0x1c8d80: 0xac20d158  sw          $zero, -0x2EA8($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294955352), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8D84u; }
        if (ctx->pc != 0x1C8D84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8D84u; }
        if (ctx->pc != 0x1C8D84u) { return; }
    }
    ctx->pc = 0x1C8D84u;
label_1c8d84:
    // 0x1c8d84: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8d84u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8d88: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1c8d88u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1c8d8c: 0xa020cd68  sb          $zero, -0x3298($at)
    ctx->pc = 0x1c8d8cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294954344), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c8d90: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1c8d90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1c8d94: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8d94u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8d98: 0x2484cc60  addiu       $a0, $a0, -0x33A0
    ctx->pc = 0x1c8d98u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294954080));
    // 0x1c8d9c: 0xac22cd78  sw          $v0, -0x3288($at)
    ctx->pc = 0x1c8d9cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294954360), GPR_U32(ctx, 2));
    // 0x1c8da0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1c8da0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c8da4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8da4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8da8: 0x24060100  addiu       $a2, $zero, 0x100
    ctx->pc = 0x1c8da8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x1c8dac: 0xac22cd70  sw          $v0, -0x3290($at)
    ctx->pc = 0x1c8dacu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294954352), GPR_U32(ctx, 2));
    // 0x1c8db0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8db0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8db4: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1C8DB4u;
    SET_GPR_U32(ctx, 31, 0x1C8DBCu);
    ctx->pc = 0x1C8DB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8DB4u;
            // 0x1c8db8: 0xa020cd60  sb          $zero, -0x32A0($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 4294954336), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8DBCu; }
        if (ctx->pc != 0x1C8DBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8DBCu; }
        if (ctx->pc != 0x1C8DBCu) { return; }
    }
    ctx->pc = 0x1C8DBCu;
label_1c8dbc:
    // 0x1c8dbc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8dbcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8dc0: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1c8dc0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1c8dc4: 0xac20cc58  sw          $zero, -0x33A8($at)
    ctx->pc = 0x1c8dc4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294954072), GPR_U32(ctx, 0));
    // 0x1c8dc8: 0x2484cb50  addiu       $a0, $a0, -0x34B0
    ctx->pc = 0x1c8dc8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294953808));
    // 0x1c8dcc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8dccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8dd0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1c8dd0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c8dd4: 0xa420cc50  sh          $zero, -0x33B0($at)
    ctx->pc = 0x1c8dd4u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 4294954064), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c8dd8: 0x240600f0  addiu       $a2, $zero, 0xF0
    ctx->pc = 0x1c8dd8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 240));
    // 0x1c8ddc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8ddcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8de0: 0xa020cc48  sb          $zero, -0x33B8($at)
    ctx->pc = 0x1c8de0u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294954056), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c8de4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8de4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8de8: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1C8DE8u;
    SET_GPR_U32(ctx, 31, 0x1C8DF0u);
    ctx->pc = 0x1C8DECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8DE8u;
            // 0x1c8dec: 0xa020cc40  sb          $zero, -0x33C0($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 4294954048), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8DF0u; }
        if (ctx->pc != 0x1C8DF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8DF0u; }
        if (ctx->pc != 0x1C8DF0u) { return; }
    }
    ctx->pc = 0x1C8DF0u;
label_1c8df0:
    // 0x1c8df0: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1c8df0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1c8df4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1c8df4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c8df8: 0x2484cb40  addiu       $a0, $a0, -0x34C0
    ctx->pc = 0x1c8df8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294953792));
    // 0x1c8dfc: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1C8DFCu;
    SET_GPR_U32(ctx, 31, 0x1C8E04u);
    ctx->pc = 0x1C8E00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8DFCu;
            // 0x1c8e00: 0x24060010  addiu       $a2, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8E04u; }
        if (ctx->pc != 0x1C8E04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8E04u; }
        if (ctx->pc != 0x1C8E04u) { return; }
    }
    ctx->pc = 0x1C8E04u;
label_1c8e04:
    // 0x1c8e04: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1c8e04u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1c8e08: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1c8e08u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c8e0c: 0x2484ca40  addiu       $a0, $a0, -0x35C0
    ctx->pc = 0x1c8e0cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294953536));
    // 0x1c8e10: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1C8E10u;
    SET_GPR_U32(ctx, 31, 0x1C8E18u);
    ctx->pc = 0x1C8E14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8E10u;
            // 0x1c8e14: 0x24060100  addiu       $a2, $zero, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8E18u; }
        if (ctx->pc != 0x1C8E18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8E18u; }
        if (ctx->pc != 0x1C8E18u) { return; }
    }
    ctx->pc = 0x1C8E18u;
label_1c8e18:
    // 0x1c8e18: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8e18u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8e1c: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1c8e1cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1c8e20: 0xac20ca38  sw          $zero, -0x35C8($at)
    ctx->pc = 0x1c8e20u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294953528), GPR_U32(ctx, 0));
    // 0x1c8e24: 0x2484c930  addiu       $a0, $a0, -0x36D0
    ctx->pc = 0x1c8e24u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294953264));
    // 0x1c8e28: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8e28u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8e2c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1c8e2cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c8e30: 0x24060100  addiu       $a2, $zero, 0x100
    ctx->pc = 0x1c8e30u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x1c8e34: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1C8E34u;
    SET_GPR_U32(ctx, 31, 0x1C8E3Cu);
    ctx->pc = 0x1C8E38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8E34u;
            // 0x1c8e38: 0xac20ca30  sw          $zero, -0x35D0($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294953520), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8E3Cu; }
        if (ctx->pc != 0x1C8E3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8E3Cu; }
        if (ctx->pc != 0x1C8E3Cu) { return; }
    }
    ctx->pc = 0x1C8E3Cu;
label_1c8e3c:
    // 0x1c8e3c: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1c8e3cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1c8e40: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1c8e40u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c8e44: 0x2484c830  addiu       $a0, $a0, -0x37D0
    ctx->pc = 0x1c8e44u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294953008));
    // 0x1c8e48: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1C8E48u;
    SET_GPR_U32(ctx, 31, 0x1C8E50u);
    ctx->pc = 0x1C8E4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8E48u;
            // 0x1c8e4c: 0x24060100  addiu       $a2, $zero, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8E50u; }
        if (ctx->pc != 0x1C8E50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8E50u; }
        if (ctx->pc != 0x1C8E50u) { return; }
    }
    ctx->pc = 0x1C8E50u;
label_1c8e50:
    // 0x1c8e50: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8e50u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8e54: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1c8e54u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1c8e58: 0xa020c820  sb          $zero, -0x37E0($at)
    ctx->pc = 0x1c8e58u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952992), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c8e5c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1c8e5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1c8e60: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8e60u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8e64: 0x2484c6f0  addiu       $a0, $a0, -0x3910
    ctx->pc = 0x1c8e64u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952688));
    // 0x1c8e68: 0xac22c7f0  sw          $v0, -0x3810($at)
    ctx->pc = 0x1c8e68u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294952944), GPR_U32(ctx, 2));
    // 0x1c8e6c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1c8e6cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c8e70: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8e70u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8e74: 0x24060100  addiu       $a2, $zero, 0x100
    ctx->pc = 0x1c8e74u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x1c8e78: 0xa020c818  sb          $zero, -0x37E8($at)
    ctx->pc = 0x1c8e78u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952984), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c8e7c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8e7cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8e80: 0xac20c810  sw          $zero, -0x37F0($at)
    ctx->pc = 0x1c8e80u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294952976), GPR_U32(ctx, 0));
    // 0x1c8e84: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8e84u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8e88: 0xac20c808  sw          $zero, -0x37F8($at)
    ctx->pc = 0x1c8e88u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294952968), GPR_U32(ctx, 0));
    // 0x1c8e8c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8e8cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8e90: 0xac20c800  sw          $zero, -0x3800($at)
    ctx->pc = 0x1c8e90u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294952960), GPR_U32(ctx, 0));
    // 0x1c8e94: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8e94u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8e98: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1C8E98u;
    SET_GPR_U32(ctx, 31, 0x1C8EA0u);
    ctx->pc = 0x1C8E9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8E98u;
            // 0x1c8e9c: 0xac20c7f8  sw          $zero, -0x3808($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294952952), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8EA0u; }
        if (ctx->pc != 0x1C8EA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8EA0u; }
        if (ctx->pc != 0x1C8EA0u) { return; }
    }
    ctx->pc = 0x1C8EA0u;
label_1c8ea0:
    // 0x1c8ea0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1c8ea0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c8ea4: 0x3e00008  jr          $ra
    ctx->pc = 0x1C8EA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C8EA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8EA4u;
            // 0x1c8ea8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C8D84u: goto label_1c8d84;
            case 0x1C8DBCu: goto label_1c8dbc;
            case 0x1C8DF0u: goto label_1c8df0;
            case 0x1C8E04u: goto label_1c8e04;
            case 0x1C8E18u: goto label_1c8e18;
            case 0x1C8E3Cu: goto label_1c8e3c;
            case 0x1C8E50u: goto label_1c8e50;
            case 0x1C8EA0u: goto label_1c8ea0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C8EACu;
    // 0x1c8eac: 0x0  nop
    ctx->pc = 0x1c8eacu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
