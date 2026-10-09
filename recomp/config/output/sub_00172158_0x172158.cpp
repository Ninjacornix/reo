#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00172158
// Address: 0x172158 - 0x1721e8
void sub_00172158_0x172158(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00172158_0x172158");
#endif

    switch (ctx->pc) {
        case 0x1721d0u: goto label_1721d0;
        default: break;
    }

    ctx->pc = 0x172158u;

    // 0x172158: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x172158u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17215c: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x17215cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172160: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x172160u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x172164: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x172164u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x172168: 0x80182d  daddu       $v1, $a0, $zero
    ctx->pc = 0x172168u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17216c: 0x10c2000c  beq         $a2, $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x17216Cu;
    {
        const bool branch_taken_0x17216c = (GPR_U64(ctx, 6) == GPR_U64(ctx, 2));
        ctx->pc = 0x172170u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17216Cu;
            // 0x172170: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17216c) {
            ctx->pc = 0x1721A0u;
            goto label_1721a0;
        }
    }
    ctx->pc = 0x172174u;
    // 0x172174: 0x50c00010  beql        $a2, $zero, . + 4 + (0x10 << 2)
    ctx->pc = 0x172174u;
    {
        const bool branch_taken_0x172174 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x172174) {
            ctx->pc = 0x172178u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x172174u;
            // 0x172178: 0x8c620054  lw          $v0, 0x54($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 84)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1721B8u;
            goto label_1721b8;
        }
    }
    ctx->pc = 0x17217Cu;
    // 0x17217c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x17217cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x172180: 0x14c20015  bne         $a2, $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x172180u;
    {
        const bool branch_taken_0x172180 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        ctx->pc = 0x172184u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172180u;
            // 0x172184: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172180) {
            ctx->pc = 0x1721D8u;
            goto label_1721d8;
        }
    }
    ctx->pc = 0x172188u;
    // 0x172188: 0x8c630048  lw          $v1, 0x48($v1)
    ctx->pc = 0x172188u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 72)));
    // 0x17218c: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x17218cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x172190: 0x14620012  bne         $v1, $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x172190u;
    {
        const bool branch_taken_0x172190 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x172194u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172190u;
            // 0x172194: 0xe0102d  daddu       $v0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172190) {
            ctx->pc = 0x1721DCu;
            goto label_1721dc;
        }
    }
    ctx->pc = 0x172198u;
    // 0x172198: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x172198u;
    {
        const bool branch_taken_0x172198 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x172198) {
            ctx->pc = 0x1721C8u;
            goto label_1721c8;
        }
    }
    ctx->pc = 0x1721A0u;
label_1721a0:
    // 0x1721a0: 0x8c620054  lw          $v0, 0x54($v1)
    ctx->pc = 0x1721a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 84)));
    // 0x1721a4: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1721a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1721a8: 0x1446000a  bne         $v0, $a2, . + 4 + (0xA << 2)
    ctx->pc = 0x1721A8u;
    {
        const bool branch_taken_0x1721a8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 6));
        ctx->pc = 0x1721ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1721A8u;
            // 0x1721ac: 0xac620054  sw          $v0, 0x54($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 84), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1721a8) {
            ctx->pc = 0x1721D4u;
            goto label_1721d4;
        }
    }
    ctx->pc = 0x1721B0u;
    // 0x1721b0: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1721B0u;
    {
        const bool branch_taken_0x1721b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1721b0) {
            ctx->pc = 0x1721C8u;
            goto label_1721c8;
        }
    }
    ctx->pc = 0x1721B8u;
label_1721b8:
    // 0x1721b8: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1721b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1721bc: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1721BCu;
    {
        const bool branch_taken_0x1721bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1721C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1721BCu;
            // 0x1721c0: 0xac620054  sw          $v0, 0x54($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 84), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1721bc) {
            ctx->pc = 0x1721D4u;
            goto label_1721d4;
        }
    }
    ctx->pc = 0x1721C4u;
    // 0x1721c4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1721c4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1721c8:
    // 0x1721c8: 0xc05c87a  jal         func_1721E8
    ctx->pc = 0x1721C8u;
    SET_GPR_U32(ctx, 31, 0x1721D0u);
    ctx->pc = 0x1721E8u;
    if (runtime->hasFunction(0x1721E8u)) {
        auto targetFn = runtime->lookupFunction(0x1721E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1721D0u; }
        if (ctx->pc != 0x1721D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001721E8_0x1721e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1721D0u; }
        if (ctx->pc != 0x1721D0u) { return; }
    }
    ctx->pc = 0x1721D0u;
label_1721d0:
    // 0x1721d0: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x1721d0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_1721d4:
    // 0x1721d4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1721d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1721d8:
    // 0x1721d8: 0xe0102d  daddu       $v0, $a3, $zero
    ctx->pc = 0x1721d8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
label_1721dc:
    // 0x1721dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1721DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1721E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1721DCu;
            // 0x1721e0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1721A0u: goto label_1721a0;
            case 0x1721B8u: goto label_1721b8;
            case 0x1721C8u: goto label_1721c8;
            case 0x1721D0u: goto label_1721d0;
            case 0x1721D4u: goto label_1721d4;
            case 0x1721D8u: goto label_1721d8;
            case 0x1721DCu: goto label_1721dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1721E4u;
    // 0x1721e4: 0x0  nop
    ctx->pc = 0x1721e4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
