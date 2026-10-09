#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00174F58
// Address: 0x174f58 - 0x174fc8
void sub_00174F58_0x174f58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00174F58_0x174f58");
#endif

    switch (ctx->pc) {
        case 0x174f74u: goto label_174f74;
        case 0x174fb0u: goto label_174fb0;
        default: break;
    }

    ctx->pc = 0x174f58u;

    // 0x174f58: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x174f58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x174f5c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x174f5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x174f60: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x174f60u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174f64: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x174f64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x174f68: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x174f68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x174f6c: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x174F6Cu;
    SET_GPR_U32(ctx, 31, 0x174F74u);
    ctx->pc = 0x174F70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x174F6Cu;
            // 0x174f70: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174F74u; }
        if (ctx->pc != 0x174F74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174F74u; }
        if (ctx->pc != 0x174F74u) { return; }
    }
    ctx->pc = 0x174F74u;
label_174f74:
    // 0x174f74: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x174f74u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x174f78: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x174F78u;
    {
        const bool branch_taken_0x174f78 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x174F7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174F78u;
            // 0x174f7c: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x174f78) {
            ctx->pc = 0x174F98u;
            goto label_174f98;
        }
    }
    ctx->pc = 0x174F80u;
    // 0x174f80: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x174f80u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x174f84: 0x34a50159  ori         $a1, $a1, 0x159
    ctx->pc = 0x174f84u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)345);
    // 0x174f88: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x174f88u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x174f8c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x174f8cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x174f90: 0x805a704  j           func_169C10
    ctx->pc = 0x174F90u;
    ctx->pc = 0x174F94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x174F90u;
            // 0x174f94: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x174F98u;
label_174f98:
    // 0x174f98: 0x8e032ab0  lw          $v1, 0x2AB0($s0)
    ctx->pc = 0x174f98u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 10928)));
    // 0x174f9c: 0x50600006  beql        $v1, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x174F9Cu;
    {
        const bool branch_taken_0x174f9c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x174f9c) {
            ctx->pc = 0x174FA0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x174F9Cu;
            // 0x174fa0: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x174FB8u;
            goto label_174fb8;
        }
    }
    ctx->pc = 0x174FA4u;
    // 0x174fa4: 0xac710db0  sw          $s1, 0xDB0($v1)
    ctx->pc = 0x174fa4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 3504), GPR_U32(ctx, 17));
    // 0x174fa8: 0xc05d496  jal         func_175258
    ctx->pc = 0x174FA8u;
    SET_GPR_U32(ctx, 31, 0x174FB0u);
    ctx->pc = 0x174FACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x174FA8u;
            // 0x174fac: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175258u;
    if (runtime->hasFunction(0x175258u)) {
        auto targetFn = runtime->lookupFunction(0x175258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174FB0u; }
        if (ctx->pc != 0x174FB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175258_0x175258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174FB0u; }
        if (ctx->pc != 0x174FB0u) { return; }
    }
    ctx->pc = 0x174FB0u;
label_174fb0:
    // 0x174fb0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x174fb0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174fb4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x174fb4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_174fb8:
    // 0x174fb8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x174fb8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x174fbc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x174fbcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x174fc0: 0x3e00008  jr          $ra
    ctx->pc = 0x174FC0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x174FC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174FC0u;
            // 0x174fc4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x174F74u: goto label_174f74;
            case 0x174F98u: goto label_174f98;
            case 0x174FB0u: goto label_174fb0;
            case 0x174FB8u: goto label_174fb8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x174FC8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
