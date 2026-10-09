#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011E440
// Address: 0x11e440 - 0x11e4c8
void sub_0011E440_0x11e440(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011E440_0x11e440");
#endif

    switch (ctx->pc) {
        case 0x11e470u: goto label_11e470;
        default: break;
    }

    ctx->pc = 0x11e440u;

    // 0x11e440: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x11e440u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11e444: 0x3c090021  lui         $t1, 0x21
    ctx->pc = 0x11e444u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)33 << 16));
    // 0x11e448: 0xdcc20020  ld          $v0, 0x20($a2)
    ctx->pc = 0x11e448u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 6), 32)));
    // 0x11e44c: 0x2525b3e8  addiu       $a1, $t1, -0x4C18
    ctx->pc = 0x11e44cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 9), 4294947816));
    // 0x11e450: 0xdcc30010  ld          $v1, 0x10($a2)
    ctx->pc = 0x11e450u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 6), 16)));
    // 0x11e454: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x11e454u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11e458: 0xdcc40018  ld          $a0, 0x18($a2)
    ctx->pc = 0x11e458u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 6), 24)));
    // 0x11e45c: 0x43102d  daddu       $v0, $v0, $v1
    ctx->pc = 0x11e45cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 3));
    // 0x11e460: 0x8ca50018  lw          $a1, 0x18($a1)
    ctx->pc = 0x11e460u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 24)));
    // 0x11e464: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x11E464u;
    {
        const bool branch_taken_0x11e464 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11E468u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E464u;
            // 0x11e468: 0x44382f  dsubu       $a3, $v0, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) - GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e464) {
            ctx->pc = 0x11E474u;
            goto label_11e474;
        }
    }
    ctx->pc = 0x11E46Cu;
    // 0x11e46c: 0x0  nop
    ctx->pc = 0x11e46cu;
    // NOP
label_11e470:
    // 0x11e470: 0x8d050000  lw          $a1, 0x0($t0)
    ctx->pc = 0x11e470u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
label_11e474:
    // 0x11e474: 0x50a0000a  beql        $a1, $zero, . + 4 + (0xA << 2)
    ctx->pc = 0x11E474u;
    {
        const bool branch_taken_0x11e474 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x11e474) {
            ctx->pc = 0x11E478u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11E474u;
            // 0x11e478: 0xacc80004  sw          $t0, 0x4($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 8));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11E4A0u;
            goto label_11e4a0;
        }
    }
    ctx->pc = 0x11E47Cu;
    // 0x11e47c: 0xdca20020  ld          $v0, 0x20($a1)
    ctx->pc = 0x11e47cu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 5), 32)));
    // 0x11e480: 0xdca30010  ld          $v1, 0x10($a1)
    ctx->pc = 0x11e480u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x11e484: 0xdca40018  ld          $a0, 0x18($a1)
    ctx->pc = 0x11e484u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 5), 24)));
    // 0x11e488: 0x43102d  daddu       $v0, $v0, $v1
    ctx->pc = 0x11e488u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 3));
    // 0x11e48c: 0x44102f  dsubu       $v0, $v0, $a0
    ctx->pc = 0x11e48cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) - GPR_U64(ctx, 4));
    // 0x11e490: 0xe2102b  sltu        $v0, $a3, $v0
    ctx->pc = 0x11e490u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x11e494: 0x5040fff6  beql        $v0, $zero, . + 4 + (-0xA << 2)
    ctx->pc = 0x11E494u;
    {
        const bool branch_taken_0x11e494 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x11e494) {
            ctx->pc = 0x11E498u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11E494u;
            // 0x11e498: 0xa0402d  daddu       $t0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11E470u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11e470;
        }
    }
    ctx->pc = 0x11E49Cu;
    // 0x11e49c: 0xacc80004  sw          $t0, 0x4($a2)
    ctx->pc = 0x11e49cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 8));
label_11e4a0:
    // 0x11e4a0: 0x10a00002  beqz        $a1, . + 4 + (0x2 << 2)
    ctx->pc = 0x11E4A0u;
    {
        const bool branch_taken_0x11e4a0 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x11E4A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E4A0u;
            // 0x11e4a4: 0xacc50000  sw          $a1, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e4a0) {
            ctx->pc = 0x11E4ACu;
            goto label_11e4ac;
        }
    }
    ctx->pc = 0x11E4A8u;
    // 0x11e4a8: 0xaca60004  sw          $a2, 0x4($a1)
    ctx->pc = 0x11e4a8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 6));
label_11e4ac:
    // 0x11e4ac: 0x11000003  beqz        $t0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11E4ACu;
    {
        const bool branch_taken_0x11e4ac = (GPR_U64(ctx, 8) == GPR_U64(ctx, 0));
        ctx->pc = 0x11E4B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E4ACu;
            // 0x11e4b0: 0x2522b3e8  addiu       $v0, $t1, -0x4C18 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 9), 4294947816));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e4ac) {
            ctx->pc = 0x11E4BCu;
            goto label_11e4bc;
        }
    }
    ctx->pc = 0x11E4B4u;
    // 0x11e4b4: 0x3e00008  jr          $ra
    ctx->pc = 0x11E4B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11E4B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E4B4u;
            // 0x11e4b8: 0xad060000  sw          $a2, 0x0($t0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 8), 0), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11E470u: goto label_11e470;
            case 0x11E474u: goto label_11e474;
            case 0x11E4A0u: goto label_11e4a0;
            case 0x11E4ACu: goto label_11e4ac;
            case 0x11E4BCu: goto label_11e4bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11E4BCu;
label_11e4bc:
    // 0x11e4bc: 0x3e00008  jr          $ra
    ctx->pc = 0x11E4BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11E4C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E4BCu;
            // 0x11e4c0: 0xac460018  sw          $a2, 0x18($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11E470u: goto label_11e470;
            case 0x11E474u: goto label_11e474;
            case 0x11E4A0u: goto label_11e4a0;
            case 0x11E4ACu: goto label_11e4ac;
            case 0x11E4BCu: goto label_11e4bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11E4C4u;
    // 0x11e4c4: 0x0  nop
    ctx->pc = 0x11e4c4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
