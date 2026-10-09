#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00135EF0
// Address: 0x135ef0 - 0x135f50
void sub_00135EF0_0x135ef0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00135EF0_0x135ef0");
#endif

    switch (ctx->pc) {
        case 0x135f10u: goto label_135f10;
        case 0x135f2cu: goto label_135f2c;
        default: break;
    }

    ctx->pc = 0x135ef0u;

    // 0x135ef0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x135ef0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x135ef4: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x135ef4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x135ef8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x135ef8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x135efc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x135efcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x135f00: 0x24502068  addiu       $s0, $v0, 0x2068
    ctx->pc = 0x135f00u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 8296));
    // 0x135f04: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x135f04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x135f08: 0x2411001f  addiu       $s1, $zero, 0x1F
    ctx->pc = 0x135f08u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x135f0c: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x135f0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_135f10:
    // 0x135f10: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x135F10u;
    {
        const bool branch_taken_0x135f10 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x135F14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135F10u;
            // 0x135f14: 0x26100010  addiu       $s0, $s0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135f10) {
            ctx->pc = 0x135F2Cu;
            goto label_135f2c;
        }
    }
    ctx->pc = 0x135F18u;
    // 0x135f18: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x135f18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x135f1c: 0x50400004  beql        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x135F1Cu;
    {
        const bool branch_taken_0x135f1c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x135f1c) {
            ctx->pc = 0x135F20u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x135F1Cu;
            // 0x135f20: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x135F30u;
            goto label_135f30;
        }
    }
    ctx->pc = 0x135F24u;
    // 0x135f24: 0x40f809  jalr        $v0
    ctx->pc = 0x135F24u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x135F2Cu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x135F2Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135F10u: goto label_135f10;
            case 0x135F2Cu: goto label_135f2c;
            case 0x135F30u: goto label_135f30;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x135F2Cu; }
            if (ctx->pc != 0x135F2Cu) { return; }
        }
        }
    }
    ctx->pc = 0x135F2Cu;
label_135f2c:
    // 0x135f2c: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x135f2cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_135f30:
    // 0x135f30: 0x623fff7  bgezl       $s1, . + 4 + (-0x9 << 2)
    ctx->pc = 0x135F30u;
    {
        const bool branch_taken_0x135f30 = (GPR_S64(ctx, 17) >= 0);
        if (branch_taken_0x135f30) {
            ctx->pc = 0x135F34u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x135F30u;
            // 0x135f34: 0x8e020000  lw          $v0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x135F10u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_135f10;
        }
    }
    ctx->pc = 0x135F38u;
    // 0x135f38: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x135f38u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x135f3c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x135f3cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x135f40: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x135f40u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x135f44: 0x3e00008  jr          $ra
    ctx->pc = 0x135F44u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x135F48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135F44u;
            // 0x135f48: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135F10u: goto label_135f10;
            case 0x135F2Cu: goto label_135f2c;
            case 0x135F30u: goto label_135f30;
            default: break;
        }
        return;
    }
    ctx->pc = 0x135F4Cu;
    // 0x135f4c: 0x0  nop
    ctx->pc = 0x135f4cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
