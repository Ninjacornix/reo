#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001189A8
// Address: 0x1189a8 - 0x118a38
void sub_001189A8_0x1189a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001189A8_0x1189a8");
#endif

    switch (ctx->pc) {
        case 0x1189e4u: goto label_1189e4;
        case 0x1189fcu: goto label_1189fc;
        case 0x118a10u: goto label_118a10;
        default: break;
    }

    ctx->pc = 0x1189a8u;

    // 0x1189a8: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1189a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1189ac: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x1189acu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x1189b0: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x1189b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x1189b4: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x1189b4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x1189b8: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x1189b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x1189bc: 0x24539d2c  addiu       $s3, $v0, -0x62D4
    ctx->pc = 0x1189bcu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941996));
    // 0x1189c0: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x1189c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x1189c4: 0x2471e168  addiu       $s1, $v1, -0x1E98
    ctx->pc = 0x1189c4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), 4294959464));
    // 0x1189c8: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1189c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1189cc: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x1189ccu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1189d0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1189d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1189d4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1189d4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1189d8: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1189d8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1189dc: 0xc041e86  jal         func_107A18
    ctx->pc = 0x1189DCu;
    SET_GPR_U32(ctx, 31, 0x1189E4u);
    ctx->pc = 0x1189E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1189DCu;
            // 0x1189e0: 0x24060004  addiu       $a2, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107A18u;
    if (runtime->hasFunction(0x107A18u)) {
        auto targetFn = runtime->lookupFunction(0x107A18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1189E4u; }
        if (ctx->pc != 0x1189E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107A18_0x107a18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1189E4u; }
        if (ctx->pc != 0x1189E4u) { return; }
    }
    ctx->pc = 0x1189E4u;
label_1189e4:
    // 0x1189e4: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1189E4u;
    {
        const bool branch_taken_0x1189e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1189E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1189E4u;
            // 0x1189e8: 0x3c100021  lui         $s0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1189e4) {
            ctx->pc = 0x118A14u;
            goto label_118a14;
        }
    }
    ctx->pc = 0x1189ECu;
    // 0x1189ec: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1189ecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1189f0: 0x8e059df0  lw          $a1, -0x6210($s0)
    ctx->pc = 0x1189f0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294942192)));
    // 0x1189f4: 0xc041e86  jal         func_107A18
    ctx->pc = 0x1189F4u;
    SET_GPR_U32(ctx, 31, 0x1189FCu);
    ctx->pc = 0x1189F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1189F4u;
            // 0x1189f8: 0x24060004  addiu       $a2, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107A18u;
    if (runtime->hasFunction(0x107A18u)) {
        auto targetFn = runtime->lookupFunction(0x107A18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1189FCu; }
        if (ctx->pc != 0x1189FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107A18_0x107a18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1189FCu; }
        if (ctx->pc != 0x1189FCu) { return; }
    }
    ctx->pc = 0x1189FCu;
label_1189fc:
    // 0x1189fc: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1189FCu;
    {
        const bool branch_taken_0x1189fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x118A00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1189FCu;
            // 0x118a00: 0x8e059df0  lw          $a1, -0x6210($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294942192)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1189fc) {
            ctx->pc = 0x118A14u;
            goto label_118a14;
        }
    }
    ctx->pc = 0x118A04u;
    // 0x118a04: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x118a04u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118a08: 0xc041e86  jal         func_107A18
    ctx->pc = 0x118A08u;
    SET_GPR_U32(ctx, 31, 0x118A10u);
    ctx->pc = 0x118A0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118A08u;
            // 0x118a0c: 0x24060004  addiu       $a2, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107A18u;
    if (runtime->hasFunction(0x107A18u)) {
        auto targetFn = runtime->lookupFunction(0x107A18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118A10u; }
        if (ctx->pc != 0x118A10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107A18_0x107a18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118A10u; }
        if (ctx->pc != 0x118A10u) { return; }
    }
    ctx->pc = 0x118A10u;
label_118a10:
    // 0x118a10: 0x2902b  sltu        $s2, $zero, $v0
    ctx->pc = 0x118a10u;
    SET_GPR_U64(ctx, 18, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
label_118a14:
    // 0x118a14: 0x240102d  daddu       $v0, $s2, $zero
    ctx->pc = 0x118a14u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118a18: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x118a18u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x118a1c: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x118a1cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x118a20: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x118a20u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x118a24: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x118a24u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x118a28: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x118a28u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x118a2c: 0x3e00008  jr          $ra
    ctx->pc = 0x118A2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x118A30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118A2Cu;
            // 0x118a30: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1189E4u: goto label_1189e4;
            case 0x1189FCu: goto label_1189fc;
            case 0x118A10u: goto label_118a10;
            case 0x118A14u: goto label_118a14;
            default: break;
        }
        return;
    }
    ctx->pc = 0x118A34u;
    // 0x118a34: 0x0  nop
    ctx->pc = 0x118a34u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
