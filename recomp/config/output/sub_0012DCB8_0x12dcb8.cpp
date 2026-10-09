#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012DCB8
// Address: 0x12dcb8 - 0x12dd24
void sub_0012DCB8_0x12dcb8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012DCB8_0x12dcb8");
#endif

    switch (ctx->pc) {
        case 0x12dcecu: goto label_12dcec;
        case 0x12dd08u: goto label_12dd08;
        default: break;
    }

    ctx->pc = 0x12dcb8u;

    // 0x12dcb8: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x12dcb8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x12dcbc: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x12dcbcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x12dcc0: 0x8c438748  lw          $v1, -0x78B8($v0)
    ctx->pc = 0x12dcc0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294936392)));
    // 0x12dcc4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12dcc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12dcc8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x12dcc8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12dccc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12dcccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12dcd0: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x12dcd0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12dcd4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x12dcd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12dcd8: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x12dcd8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12dcdc: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x12DCDCu;
    {
        const bool branch_taken_0x12dcdc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x12DCE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12DCDCu;
            // 0x12dce0: 0xffbf0018  sd          $ra, 0x18($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12dcdc) {
            ctx->pc = 0x12DCECu;
            goto label_12dcec;
        }
    }
    ctx->pc = 0x12DCE4u;
    // 0x12dce4: 0xc04b6b0  jal         func_12DAC0
    ctx->pc = 0x12DCE4u;
    SET_GPR_U32(ctx, 31, 0x12DCECu);
    ctx->pc = 0x12DAC0u;
    if (runtime->hasFunction(0x12DAC0u)) {
        auto targetFn = runtime->lookupFunction(0x12DAC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12DCECu; }
        if (ctx->pc != 0x12DCECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DAC0_0x12dac0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12DCECu; }
        if (ctx->pc != 0x12DCECu) { return; }
    }
    ctx->pc = 0x12DCECu;
label_12dcec:
    // 0x12dcec: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x12dcecu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x12dcf0: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x12dcf0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12dcf4: 0x220382d  daddu       $a3, $s1, $zero
    ctx->pc = 0x12dcf4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12dcf8: 0x240402d  daddu       $t0, $s2, $zero
    ctx->pc = 0x12dcf8u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12dcfc: 0x2484ad98  addiu       $a0, $a0, -0x5268
    ctx->pc = 0x12dcfcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294946200));
    // 0x12dd00: 0xc04b6c0  jal         func_12DB00
    ctx->pc = 0x12DD00u;
    SET_GPR_U32(ctx, 31, 0x12DD08u);
    ctx->pc = 0x12DD04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12DD00u;
            // 0x12dd04: 0x24050006  addiu       $a1, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DB00u;
    if (runtime->hasFunction(0x12DB00u)) {
        auto targetFn = runtime->lookupFunction(0x12DB00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12DD08u; }
        if (ctx->pc != 0x12DD08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DB00_0x12db00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12DD08u; }
        if (ctx->pc != 0x12DD08u) { return; }
    }
    ctx->pc = 0x12DD08u;
label_12dd08:
    // 0x12dd08: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x12dd08u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12dd0c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12dd0cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12dd10: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12dd10u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12dd14: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x12dd14u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12dd18: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x12dd18u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12dd1c: 0x3e00008  jr          $ra
    ctx->pc = 0x12DD1Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12DD20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12DD1Cu;
            // 0x12dd20: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12DCECu: goto label_12dcec;
            case 0x12DD08u: goto label_12dd08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12DD24u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
