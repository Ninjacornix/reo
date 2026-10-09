#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00164648
// Address: 0x164648 - 0x1646c0
void sub_00164648_0x164648(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00164648_0x164648");
#endif

    switch (ctx->pc) {
        case 0x16467cu: goto label_16467c;
        case 0x164694u: goto label_164694;
        default: break;
    }

    ctx->pc = 0x164648u;

    // 0x164648: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x164648u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x16464c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16464cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x164650: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x164650u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164654: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x164654u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x164658: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x164658u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16465c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16465cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x164660: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x164660u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164664: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x164664u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x164668: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x164668u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16466c: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x16466cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x164670: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x164670u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x164674: 0xc04c148  jal         func_130520
    ctx->pc = 0x164674u;
    SET_GPR_U32(ctx, 31, 0x16467Cu);
    ctx->pc = 0x164678u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164674u;
            // 0x164678: 0x100a02d  daddu       $s4, $t0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130520u;
    if (runtime->hasFunction(0x130520u)) {
        auto targetFn = runtime->lookupFunction(0x130520u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16467Cu; }
        if (ctx->pc != 0x16467Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130520_0x130520(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16467Cu; }
        if (ctx->pc != 0x16467Cu) { return; }
    }
    ctx->pc = 0x16467Cu;
label_16467c:
    // 0x16467c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16467cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164680: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x164680u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164684: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x164684u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164688: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x164688u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16468c: 0xc04c11e  jal         func_130478
    ctx->pc = 0x16468Cu;
    SET_GPR_U32(ctx, 31, 0x164694u);
    ctx->pc = 0x164690u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16468Cu;
            // 0x164690: 0x280402d  daddu       $t0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130478u;
    if (runtime->hasFunction(0x130478u)) {
        auto targetFn = runtime->lookupFunction(0x130478u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164694u; }
        if (ctx->pc != 0x164694u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130478_0x130478(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164694u; }
        if (ctx->pc != 0x164694u) { return; }
    }
    ctx->pc = 0x164694u;
label_164694:
    // 0x164694: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x164694u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164698: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x164698u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16469c: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x16469cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1646a0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1646a0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1646a4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1646a4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1646a8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1646a8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1646ac: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1646acu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1646b0: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1646b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1646b4: 0x804c1ea  j           func_1307A8
    ctx->pc = 0x1646B4u;
    ctx->pc = 0x1646B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1646B4u;
            // 0x1646b8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1307A8u;
    if (runtime->hasFunction(0x1307A8u)) {
        auto targetFn = runtime->lookupFunction(0x1307A8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001307A8_0x1307a8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1646BCu;
    // 0x1646bc: 0x0  nop
    ctx->pc = 0x1646bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
