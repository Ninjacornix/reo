#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00100768
// Address: 0x100768 - 0x1007bc
void sub_00100768_0x100768(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00100768_0x100768");
#endif

    switch (ctx->pc) {
        case 0x1007a8u: goto label_1007a8;
        default: break;
    }

    ctx->pc = 0x100768u;

    // 0x100768: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x100768u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x10076c: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x10076cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x100770: 0x8c459f88  lw          $a1, -0x6078($v0)
    ctx->pc = 0x100770u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294942600)));
    // 0x100774: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x100774u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x100778: 0x10a0000c  beqz        $a1, . + 4 + (0xC << 2)
    ctx->pc = 0x100778u;
    {
        const bool branch_taken_0x100778 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x10077Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100778u;
            // 0x10077c: 0xffb00000  sd          $s0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100778) {
            ctx->pc = 0x1007ACu;
            goto label_1007ac;
        }
    }
    ctx->pc = 0x100780u;
    // 0x100780: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x100780u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x100784: 0x8c437924  lw          $v1, 0x7924($v0)
    ctx->pc = 0x100784u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 31012)));
    // 0x100788: 0x14600009  bnez        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x100788u;
    {
        const bool branch_taken_0x100788 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x10078Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100788u;
            // 0x10078c: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100788) {
            ctx->pc = 0x1007B0u;
            goto label_1007b0;
        }
    }
    ctx->pc = 0x100790u;
    // 0x100790: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x100790u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x100794: 0x380802d  daddu       $s0, $gp, $zero
    ctx->pc = 0x100794u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 28) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100798: 0x8c5c9f8c  lw          $gp, -0x6074($v0)
    ctx->pc = 0x100798u;
    SET_GPR_S32(ctx, 28, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294942604)));
    // 0x10079c: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x10079cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x1007a0: 0xa0f809  jalr        $a1
    ctx->pc = 0x1007A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 5);
        SET_GPR_U32(ctx, 31, 0x1007A8u);
        ctx->pc = 0x1007A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1007A0u;
            // 0x1007a4: 0x8c649f90  lw          $a0, -0x6070($v1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294942608)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1007A8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1007A8u: goto label_1007a8;
            case 0x1007ACu: goto label_1007ac;
            case 0x1007B0u: goto label_1007b0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1007A8u; }
            if (ctx->pc != 0x1007A8u) { return; }
        }
        }
    }
    ctx->pc = 0x1007A8u;
label_1007a8:
    // 0x1007a8: 0x200e02d  daddu       $gp, $s0, $zero
    ctx->pc = 0x1007a8u;
    SET_GPR_U64(ctx, 28, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1007ac:
    // 0x1007ac: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1007acu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1007b0:
    // 0x1007b0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1007b0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1007b4: 0x3e00008  jr          $ra
    ctx->pc = 0x1007B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1007B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1007B4u;
            // 0x1007b8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1007A8u: goto label_1007a8;
            case 0x1007ACu: goto label_1007ac;
            case 0x1007B0u: goto label_1007b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1007BCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
