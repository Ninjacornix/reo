#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00176350
// Address: 0x176350 - 0x176418
void sub_00176350_0x176350(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00176350_0x176350");
#endif

    switch (ctx->pc) {
        case 0x1763c4u: goto label_1763c4;
        default: break;
    }

    ctx->pc = 0x176350u;

    // 0x176350: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x176350u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x176354: 0x24890cc0  addiu       $t1, $a0, 0xCC0
    ctx->pc = 0x176354u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 4), 3264));
    // 0x176358: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x176358u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17635c: 0x2402fffb  addiu       $v0, $zero, -0x5
    ctx->pc = 0x17635cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967291));
    // 0x176360: 0xa0382d  daddu       $a3, $a1, $zero
    ctx->pc = 0x176360u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176364: 0x8d230248  lw          $v1, 0x248($t1)
    ctx->pc = 0x176364u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 584)));
    // 0x176368: 0x14620005  bne         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x176368u;
    {
        const bool branch_taken_0x176368 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x17636Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176368u;
            // 0x17636c: 0xc0402d  daddu       $t0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x176368) {
            ctx->pc = 0x176380u;
            goto label_176380;
        }
    }
    ctx->pc = 0x176370u;
    // 0x176370: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x176370u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x176374: 0x805d906  j           func_176418
    ctx->pc = 0x176374u;
    ctx->pc = 0x176378u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x176374u;
            // 0x176378: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176418u;
    if (runtime->hasFunction(0x176418u)) {
        auto targetFn = runtime->lookupFunction(0x176418u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00176418_0x176418(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17637Cu;
    // 0x17637c: 0x0  nop
    ctx->pc = 0x17637cu;
    // NOP
label_176380:
    // 0x176380: 0xace30000  sw          $v1, 0x0($a3)
    ctx->pc = 0x176380u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 3));
    // 0x176384: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x176384u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176388: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x176388u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17638c: 0x8d23024c  lw          $v1, 0x24C($t1)
    ctx->pc = 0x17638cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 588)));
    // 0x176390: 0xad030000  sw          $v1, 0x0($t0)
    ctx->pc = 0x176390u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 0), GPR_U32(ctx, 3));
    // 0x176394: 0x3e00008  jr          $ra
    ctx->pc = 0x176394u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x176398u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176394u;
            // 0x176398: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x176380u: goto label_176380;
            case 0x1763C4u: goto label_1763c4;
            case 0x1763F8u: goto label_1763f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17639Cu;
    // 0x17639c: 0x0  nop
    ctx->pc = 0x17639cu;
    // NOP
    // 0x1763a0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1763a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1763a4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1763a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1763a8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1763a8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1763ac: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1763acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1763b0: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x1763b0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1763b4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1763b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1763b8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1763b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1763bc: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x1763BCu;
    SET_GPR_U32(ctx, 31, 0x1763C4u);
    ctx->pc = 0x1763C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1763BCu;
            // 0x1763c0: 0xa0902d  daddu       $s2, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1763C4u; }
        if (ctx->pc != 0x1763C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1763C4u; }
        if (ctx->pc != 0x1763C4u) { return; }
    }
    ctx->pc = 0x1763C4u;
label_1763c4:
    // 0x1763c4: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1763c4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1763c8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1763c8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1763cc: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1763ccu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1763d0: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1763D0u;
    {
        const bool branch_taken_0x1763d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1763D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1763D0u;
            // 0x1763d4: 0x34a50128  ori         $a1, $a1, 0x128 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)296);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1763d0) {
            ctx->pc = 0x1763F8u;
            goto label_1763f8;
        }
    }
    ctx->pc = 0x1763D8u;
    // 0x1763d8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1763d8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1763dc: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1763dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1763e0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1763e0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1763e4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1763e4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1763e8: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1763e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1763ec: 0x805a704  j           func_169C10
    ctx->pc = 0x1763ECu;
    ctx->pc = 0x1763F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1763ECu;
            // 0x1763f0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1763F4u;
    // 0x1763f4: 0x0  nop
    ctx->pc = 0x1763f4u;
    // NOP
label_1763f8:
    // 0x1763f8: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1763f8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1763fc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1763fcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x176400: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x176400u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x176404: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x176404u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x176408: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x176408u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17640c: 0x805d906  j           func_176418
    ctx->pc = 0x17640Cu;
    ctx->pc = 0x176410u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17640Cu;
            // 0x176410: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176418u;
    if (runtime->hasFunction(0x176418u)) {
        auto targetFn = runtime->lookupFunction(0x176418u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00176418_0x176418(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x176414u;
    // 0x176414: 0x0  nop
    ctx->pc = 0x176414u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
