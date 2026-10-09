#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016BEC8
// Address: 0x16bec8 - 0x16bf80
void sub_0016BEC8_0x16bec8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016BEC8_0x16bec8");
#endif

    switch (ctx->pc) {
        case 0x16bef8u: goto label_16bef8;
        case 0x16bf40u: goto label_16bf40;
        default: break;
    }

    ctx->pc = 0x16bec8u;

    // 0x16bec8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x16bec8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16becc: 0x182d  daddu       $v1, $zero, $zero
    ctx->pc = 0x16beccu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16bed0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16bed0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16bed4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x16bed4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16bed8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16bed8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16bedc: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x16bedcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16bee0: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16bee0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x16bee4: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x16bee4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16bee8: 0x1200000f  beqz        $s0, . + 4 + (0xF << 2)
    ctx->pc = 0x16BEE8u;
    {
        const bool branch_taken_0x16bee8 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x16BEECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16BEE8u;
            // 0x16beec: 0xffbf0018  sd          $ra, 0x18($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16bee8) {
            ctx->pc = 0x16BF28u;
            goto label_16bf28;
        }
    }
    ctx->pc = 0x16BEF0u;
    // 0x16bef0: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x16BEF0u;
    SET_GPR_U32(ctx, 31, 0x16BEF8u);
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16BEF8u; }
        if (ctx->pc != 0x16BEF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16BEF8u; }
        if (ctx->pc != 0x16BEF8u) { return; }
    }
    ctx->pc = 0x16BEF8u;
label_16bef8:
    // 0x16bef8: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16bef8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x16befc: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x16BEFCu;
    {
        const bool branch_taken_0x16befc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16BF00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16BEFCu;
            // 0x16bf00: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16befc) {
            ctx->pc = 0x16BF20u;
            goto label_16bf20;
        }
    }
    ctx->pc = 0x16BF04u;
    // 0x16bf04: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16bf04u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16bf08: 0x34a50181  ori         $a1, $a1, 0x181
    ctx->pc = 0x16bf08u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)385);
    // 0x16bf0c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16bf0cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16bf10: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16bf10u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16bf14: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x16bf14u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16bf18: 0x805a704  j           func_169C10
    ctx->pc = 0x16BF18u;
    ctx->pc = 0x16BF1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16BF18u;
            // 0x16bf1c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16BF20u;
label_16bf20:
    // 0x16bf20: 0x8e021b30  lw          $v0, 0x1B30($s0)
    ctx->pc = 0x16bf20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 6960)));
    // 0x16bf24: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x16bf24u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_16bf28:
    // 0x16bf28: 0x3a220005  xori        $v0, $s1, 0x5
    ctx->pc = 0x16bf28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) ^ (uint64_t)(uint16_t)5);
    // 0x16bf2c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x16bf2cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16bf30: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x16bf30u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16bf34: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x16bf34u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16bf38: 0xc056daa  jal         func_15B6A8
    ctx->pc = 0x16BF38u;
    SET_GPR_U32(ctx, 31, 0x16BF40u);
    ctx->pc = 0x16BF3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16BF38u;
            // 0x16bf3c: 0x242300b  movn        $a2, $s2, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 18));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15B6A8u;
    if (runtime->hasFunction(0x15B6A8u)) {
        auto targetFn = runtime->lookupFunction(0x15B6A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16BF40u; }
        if (ctx->pc != 0x16BF40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B6A8_0x15b6a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16BF40u; }
        if (ctx->pc != 0x16BF40u) { return; }
    }
    ctx->pc = 0x16BF40u;
label_16bf40:
    // 0x16bf40: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16bf40u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x16bf44: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x16BF44u;
    {
        const bool branch_taken_0x16bf44 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16BF48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16BF44u;
            // 0x16bf48: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16bf44) {
            ctx->pc = 0x16BF68u;
            goto label_16bf68;
        }
    }
    ctx->pc = 0x16BF4Cu;
    // 0x16bf4c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16bf4cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16bf50: 0x34a50f12  ori         $a1, $a1, 0xF12
    ctx->pc = 0x16bf50u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3858);
    // 0x16bf54: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16bf54u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16bf58: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16bf58u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16bf5c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x16bf5cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16bf60: 0x805a704  j           func_169C10
    ctx->pc = 0x16BF60u;
    ctx->pc = 0x16BF64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16BF60u;
            // 0x16bf64: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16BF68u;
label_16bf68:
    // 0x16bf68: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16bf68u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16bf6c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16bf6cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16bf70: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16bf70u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16bf74: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x16bf74u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16bf78: 0x3e00008  jr          $ra
    ctx->pc = 0x16BF78u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16BF7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16BF78u;
            // 0x16bf7c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16BEF8u: goto label_16bef8;
            case 0x16BF20u: goto label_16bf20;
            case 0x16BF28u: goto label_16bf28;
            case 0x16BF40u: goto label_16bf40;
            case 0x16BF68u: goto label_16bf68;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16BF80u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
