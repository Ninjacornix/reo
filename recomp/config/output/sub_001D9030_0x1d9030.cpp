#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D9030
// Address: 0x1d9030 - 0x1d90e0
void sub_001D9030_0x1d9030(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D9030_0x1d9030");
#endif

    switch (ctx->pc) {
        case 0x1d9058u: goto label_1d9058;
        case 0x1d9070u: goto label_1d9070;
        case 0x1d90a8u: goto label_1d90a8;
        case 0x1d90b4u: goto label_1d90b4;
        default: break;
    }

    ctx->pc = 0x1d9030u;

    // 0x1d9030: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1d9030u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1d9034: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1d9034u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1d9038: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d9038u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d903c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d903cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d9040: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1d9040u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9044: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d9044u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d9048: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1d9048u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d904c: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x1d904cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9050: 0xc075e38  jal         func_1D78E0
    ctx->pc = 0x1D9050u;
    SET_GPR_U32(ctx, 31, 0x1D9058u);
    ctx->pc = 0x1D9054u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9050u;
            // 0x1d9054: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78E0u;
    if (runtime->hasFunction(0x1D78E0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9058u; }
        if (ctx->pc != 0x1D9058u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78E0_0x1d78e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9058u; }
        if (ctx->pc != 0x1D9058u) { return; }
    }
    ctx->pc = 0x1D9058u;
label_1d9058:
    // 0x1d9058: 0x3c100034  lui         $s0, 0x34
    ctx->pc = 0x1d9058u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)52 << 16));
    // 0x1d905c: 0x12600006  beqz        $s3, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D905Cu;
    {
        const bool branch_taken_0x1d905c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9060u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D905Cu;
            // 0x1d9060: 0x2610729c  addiu       $s0, $s0, 0x729C (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 29340));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d905c) {
            ctx->pc = 0x1D9078u;
            goto label_1d9078;
        }
    }
    ctx->pc = 0x1D9064u;
    // 0x1d9064: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1d9064u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9068: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1D9068u;
    SET_GPR_U32(ctx, 31, 0x1D9070u);
    ctx->pc = 0x1D906Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9068u;
            // 0x1d906c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9070u; }
        if (ctx->pc != 0x1D9070u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9070u; }
        if (ctx->pc != 0x1D9070u) { return; }
    }
    ctx->pc = 0x1D9070u;
label_1d9070:
    // 0x1d9070: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1D9070u;
    {
        const bool branch_taken_0x1d9070 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d9070) {
            ctx->pc = 0x1D9080u;
            goto label_1d9080;
        }
    }
    ctx->pc = 0x1D9078u;
label_1d9078:
    // 0x1d9078: 0xa2000000  sb          $zero, 0x0($s0)
    ctx->pc = 0x1d9078u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1d907c: 0x0  nop
    ctx->pc = 0x1d907cu;
    // NOP
label_1d9080:
    // 0x1d9080: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d9080u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1d9084: 0x3c070034  lui         $a3, 0x34
    ctx->pc = 0x1d9084u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)52 << 16));
    // 0x1d9088: 0xae120100  sw          $s2, 0x100($s0)
    ctx->pc = 0x1d9088u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 256), GPR_U32(ctx, 18));
    // 0x1d908c: 0x24040038  addiu       $a0, $zero, 0x38
    ctx->pc = 0x1d908cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 56));
    // 0x1d9090: 0x24a57280  addiu       $a1, $a1, 0x7280
    ctx->pc = 0x1d9090u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 29312));
    // 0x1d9094: 0x24060128  addiu       $a2, $zero, 0x128
    ctx->pc = 0x1d9094u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 296));
    // 0x1d9098: 0x24e76280  addiu       $a3, $a3, 0x6280
    ctx->pc = 0x1d9098u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 25216));
    // 0x1d909c: 0x24080020  addiu       $t0, $zero, 0x20
    ctx->pc = 0x1d909cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1d90a0: 0xc075e40  jal         func_1D7900
    ctx->pc = 0x1D90A0u;
    SET_GPR_U32(ctx, 31, 0x1D90A8u);
    ctx->pc = 0x1D90A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D90A0u;
            // 0x1d90a4: 0xae110104  sw          $s1, 0x104($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 260), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7900u;
    if (runtime->hasFunction(0x1D7900u)) {
        auto targetFn = runtime->lookupFunction(0x1D7900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D90A8u; }
        if (ctx->pc != 0x1D90A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7900_0x1d7900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D90A8u; }
        if (ctx->pc != 0x1D90A8u) { return; }
    }
    ctx->pc = 0x1D90A8u;
label_1d90a8:
    // 0x1d90a8: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d90a8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d90ac: 0xc075e3c  jal         func_1D78F0
    ctx->pc = 0x1D90ACu;
    SET_GPR_U32(ctx, 31, 0x1D90B4u);
    ctx->pc = 0x1D90B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D90ACu;
            // 0x1d90b0: 0x84306298  lh          $s0, 0x6298($at) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 25240)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78F0u;
    if (runtime->hasFunction(0x1D78F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D90B4u; }
        if (ctx->pc != 0x1D90B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78F0_0x1d78f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D90B4u; }
        if (ctx->pc != 0x1D90B4u) { return; }
    }
    ctx->pc = 0x1D90B4u;
label_1d90b4:
    // 0x1d90b4: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1d90b4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d90b8: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1d90b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d90bc: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d90bcu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d90c0: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d90c0u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d90c4: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d90c4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d90c8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d90c8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d90cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1D90CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D90D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D90CCu;
            // 0x1d90d0: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D9058u: goto label_1d9058;
            case 0x1D9070u: goto label_1d9070;
            case 0x1D9078u: goto label_1d9078;
            case 0x1D9080u: goto label_1d9080;
            case 0x1D90A8u: goto label_1d90a8;
            case 0x1D90B4u: goto label_1d90b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D90D4u;
    // 0x1d90d4: 0x0  nop
    ctx->pc = 0x1d90d4u;
    // NOP
    // 0x1d90d8: 0x0  nop
    ctx->pc = 0x1d90d8u;
    // NOP
    // 0x1d90dc: 0x0  nop
    ctx->pc = 0x1d90dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
