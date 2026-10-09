#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D7D20
// Address: 0x1d7d20 - 0x1d7dc0
void sub_001D7D20_0x1d7d20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D7D20_0x1d7d20");
#endif

    switch (ctx->pc) {
        case 0x1d7d4cu: goto label_1d7d4c;
        case 0x1d7d74u: goto label_1d7d74;
        case 0x1d7da0u: goto label_1d7da0;
        default: break;
    }

    ctx->pc = 0x1d7d20u;

    // 0x1d7d20: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1d7d20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1d7d24: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1d7d24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1d7d28: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d7d28u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d7d2c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d7d2cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d7d30: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1d7d30u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d7d34: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d7d34u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d7d38: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1d7d38u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d7d3c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d7d3cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d7d40: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x1d7d40u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d7d44: 0xc075e38  jal         func_1D78E0
    ctx->pc = 0x1D7D44u;
    SET_GPR_U32(ctx, 31, 0x1D7D4Cu);
    ctx->pc = 0x1D7D48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7D44u;
            // 0x1d7d48: 0xe0802d  daddu       $s0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78E0u;
    if (runtime->hasFunction(0x1D78E0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7D4Cu; }
        if (ctx->pc != 0x1D7D4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78E0_0x1d78e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7D4Cu; }
        if (ctx->pc != 0x1D7D4Cu) { return; }
    }
    ctx->pc = 0x1D7D4Cu;
label_1d7d4c:
    // 0x1d7d4c: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d7d4cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1d7d50: 0x2406002a  addiu       $a2, $zero, 0x2A
    ctx->pc = 0x1d7d50u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 42));
    // 0x1d7d54: 0x3c070034  lui         $a3, 0x34
    ctx->pc = 0x1d7d54u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)52 << 16));
    // 0x1d7d58: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d7d58u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d7d5c: 0x2404000e  addiu       $a0, $zero, 0xE
    ctx->pc = 0x1d7d5cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1d7d60: 0x24a57280  addiu       $a1, $a1, 0x7280
    ctx->pc = 0x1d7d60u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 29312));
    // 0x1d7d64: 0x24e76280  addiu       $a3, $a3, 0x6280
    ctx->pc = 0x1d7d64u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 25216));
    // 0x1d7d68: 0xc0402d  daddu       $t0, $a2, $zero
    ctx->pc = 0x1d7d68u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d7d6c: 0xc075e40  jal         func_1D7900
    ctx->pc = 0x1D7D6Cu;
    SET_GPR_U32(ctx, 31, 0x1D7D74u);
    ctx->pc = 0x1D7D70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7D6Cu;
            // 0x1d7d70: 0xa433729c  sh          $s3, 0x729C($at) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 1), 29340), (uint16_t)GPR_U32(ctx, 19));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7900u;
    if (runtime->hasFunction(0x1D7900u)) {
        auto targetFn = runtime->lookupFunction(0x1D7900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7D74u; }
        if (ctx->pc != 0x1D7D74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7900_0x1d7900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7D74u; }
        if (ctx->pc != 0x1D7D74u) { return; }
    }
    ctx->pc = 0x1D7D74u;
label_1d7d74:
    // 0x1d7d74: 0x3c030034  lui         $v1, 0x34
    ctx->pc = 0x1d7d74u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)52 << 16));
    // 0x1d7d78: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d7d78u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d7d7c: 0x2463629c  addiu       $v1, $v1, 0x629C
    ctx->pc = 0x1d7d7cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 25244));
    // 0x1d7d80: 0x94620002  lhu         $v0, 0x2($v1)
    ctx->pc = 0x1d7d80u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 2)));
    // 0x1d7d84: 0xa6420000  sh          $v0, 0x0($s2)
    ctx->pc = 0x1d7d84u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1d7d88: 0x94620006  lhu         $v0, 0x6($v1)
    ctx->pc = 0x1d7d88u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 6)));
    // 0x1d7d8c: 0xa6220000  sh          $v0, 0x0($s1)
    ctx->pc = 0x1d7d8cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1d7d90: 0x94620008  lhu         $v0, 0x8($v1)
    ctx->pc = 0x1d7d90u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x1d7d94: 0xa6020000  sh          $v0, 0x0($s0)
    ctx->pc = 0x1d7d94u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1d7d98: 0xc075e3c  jal         func_1D78F0
    ctx->pc = 0x1D7D98u;
    SET_GPR_U32(ctx, 31, 0x1D7DA0u);
    ctx->pc = 0x1D7D9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7D98u;
            // 0x1d7d9c: 0x84306298  lh          $s0, 0x6298($at) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 25240)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78F0u;
    if (runtime->hasFunction(0x1D78F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7DA0u; }
        if (ctx->pc != 0x1D7DA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78F0_0x1d78f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7DA0u; }
        if (ctx->pc != 0x1D7DA0u) { return; }
    }
    ctx->pc = 0x1D7DA0u;
label_1d7da0:
    // 0x1d7da0: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1d7da0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d7da4: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1d7da4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d7da8: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d7da8u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d7dac: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d7dacu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d7db0: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d7db0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d7db4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d7db4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d7db8: 0x3e00008  jr          $ra
    ctx->pc = 0x1D7DB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D7DBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7DB8u;
            // 0x1d7dbc: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D7D4Cu: goto label_1d7d4c;
            case 0x1D7D74u: goto label_1d7d74;
            case 0x1D7DA0u: goto label_1d7da0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D7DC0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
