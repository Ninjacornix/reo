#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013EC58
// Address: 0x13ec58 - 0x13ed28
void sub_0013EC58_0x13ec58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013EC58_0x13ec58");
#endif

    switch (ctx->pc) {
        case 0x13ecd0u: goto label_13ecd0;
        case 0x13ed10u: goto label_13ed10;
        default: break;
    }

    ctx->pc = 0x13ec58u;

    // 0x13ec58: 0x3e00008  jr          $ra
    ctx->pc = 0x13EC58u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13EC5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EC58u;
            // 0x13ec5c: 0xa0850053  sb          $a1, 0x53($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 83), (uint8_t)GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13ECD0u: goto label_13ecd0;
            case 0x13ED10u: goto label_13ed10;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13EC60u;
    // 0x13ec60: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13ec60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13ec64: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13ec64u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13ec68: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13ec68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13ec6c: 0x2484d848  addiu       $a0, $a0, -0x27B8
    ctx->pc = 0x13ec6cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957128));
    // 0x13ec70: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13ec70u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13ec74: 0x8045a12  j           func_116848
    ctx->pc = 0x13EC74u;
    ctx->pc = 0x13EC78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13EC74u;
            // 0x13ec78: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00116848_0x116848(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13EC7Cu;
    // 0x13ec7c: 0x0  nop
    ctx->pc = 0x13ec7cu;
    // NOP
    // 0x13ec80: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13ec80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13ec84: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13ec84u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13ec88: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13ec88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13ec8c: 0x2484d870  addiu       $a0, $a0, -0x2790
    ctx->pc = 0x13ec8cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957168));
    // 0x13ec90: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13ec90u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13ec94: 0x8045a12  j           func_116848
    ctx->pc = 0x13EC94u;
    ctx->pc = 0x13EC98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13EC94u;
            // 0x13ec98: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00116848_0x116848(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13EC9Cu;
    // 0x13ec9c: 0x0  nop
    ctx->pc = 0x13ec9cu;
    // NOP
    // 0x13eca0: 0x3402bb80  ori         $v0, $zero, 0xBB80
    ctx->pc = 0x13eca0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)48000);
    // 0x13eca4: 0xaca00000  sw          $zero, 0x0($a1)
    ctx->pc = 0x13eca4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 0));
    // 0x13eca8: 0x3e00008  jr          $ra
    ctx->pc = 0x13ECA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13ECACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13ECA8u;
            // 0x13ecac: 0xacc20000  sw          $v0, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13ECD0u: goto label_13ecd0;
            case 0x13ED10u: goto label_13ed10;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13ECB0u;
    // 0x13ecb0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13ecb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13ecb4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13ecb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13ecb8: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x13ecb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x13ecbc: 0x8c440008  lw          $a0, 0x8($v0)
    ctx->pc = 0x13ecbcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x13ecc0: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x13ecc0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x13ecc4: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x13ecc4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x13ecc8: 0x40f809  jalr        $v0
    ctx->pc = 0x13ECC8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13ECD0u);
        ctx->pc = 0x13ECCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13ECC8u;
            // 0x13eccc: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13ECD0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13ECD0u: goto label_13ecd0;
            case 0x13ED10u: goto label_13ed10;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13ECD0u; }
            if (ctx->pc != 0x13ECD0u) { return; }
        }
        }
    }
    ctx->pc = 0x13ECD0u;
label_13ecd0:
    // 0x13ecd0: 0x24034000  addiu       $v1, $zero, 0x4000
    ctx->pc = 0x13ecd0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16384));
    // 0x13ecd4: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x13ecd4u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x13ecd8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13ecd8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13ecdc: 0x317c2  srl         $v0, $v1, 31
    ctx->pc = 0x13ecdcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x13ece0: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x13ece0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x13ece4: 0x31043  sra         $v0, $v1, 1
    ctx->pc = 0x13ece4u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 1));
    // 0x13ece8: 0x3e00008  jr          $ra
    ctx->pc = 0x13ECE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13ECECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13ECE8u;
            // 0x13ecec: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13ECD0u: goto label_13ecd0;
            case 0x13ED10u: goto label_13ed10;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13ECF0u;
    // 0x13ecf0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13ecf0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13ecf4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13ecf4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13ecf8: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x13ecf8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x13ecfc: 0x8c440008  lw          $a0, 0x8($v0)
    ctx->pc = 0x13ecfcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x13ed00: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x13ed00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x13ed04: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x13ed04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x13ed08: 0x40f809  jalr        $v0
    ctx->pc = 0x13ED08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13ED10u);
        ctx->pc = 0x13ED0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13ED08u;
            // 0x13ed0c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13ED10u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13ECD0u: goto label_13ecd0;
            case 0x13ED10u: goto label_13ed10;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13ED10u; }
            if (ctx->pc != 0x13ED10u) { return; }
        }
        }
    }
    ctx->pc = 0x13ED10u;
label_13ed10:
    // 0x13ed10: 0x21fc2  srl         $v1, $v0, 31
    ctx->pc = 0x13ed10u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x13ed14: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13ed14u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13ed18: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x13ed18u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x13ed1c: 0x31043  sra         $v0, $v1, 1
    ctx->pc = 0x13ed1cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 1));
    // 0x13ed20: 0x3e00008  jr          $ra
    ctx->pc = 0x13ED20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13ED24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13ED20u;
            // 0x13ed24: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13ECD0u: goto label_13ecd0;
            case 0x13ED10u: goto label_13ed10;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13ED28u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
