#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016D648
// Address: 0x16d648 - 0x16d6e8
void sub_0016D648_0x16d648(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016D648_0x16d648");
#endif

    ctx->pc = 0x16d648u;

    // 0x16d648: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x16d648u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16d64c: 0xa0182d  daddu       $v1, $a1, $zero
    ctx->pc = 0x16d64cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d650: 0x2402fffd  addiu       $v0, $zero, -0x3
    ctx->pc = 0x16d650u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
    // 0x16d654: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16d654u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x16d658: 0x10620015  beq         $v1, $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x16D658u;
    {
        const bool branch_taken_0x16d658 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x16D65Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D658u;
            // 0x16d65c: 0x80402d  daddu       $t0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d658) {
            ctx->pc = 0x16D6B0u;
            goto label_16d6b0;
        }
    }
    ctx->pc = 0x16D660u;
    // 0x16d660: 0x2c62fffe  sltiu       $v0, $v1, -0x2
    ctx->pc = 0x16d660u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)4294967294) ? 1 : 0);
    // 0x16d664: 0x50400006  beql        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x16D664u;
    {
        const bool branch_taken_0x16d664 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x16d664) {
            ctx->pc = 0x16D668u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16D664u;
            // 0x16d668: 0x2402fffe  addiu       $v0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16D680u;
            goto label_16d680;
        }
    }
    ctx->pc = 0x16D66Cu;
    // 0x16d66c: 0x10600008  beqz        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x16D66Cu;
    {
        const bool branch_taken_0x16d66c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x16D670u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D66Cu;
            // 0x16d670: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d66c) {
            ctx->pc = 0x16D690u;
            goto label_16d690;
        }
    }
    ctx->pc = 0x16D674u;
    // 0x16d674: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x16D674u;
    {
        const bool branch_taken_0x16d674 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16D678u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D674u;
            // 0x16d678: 0x100202d  daddu       $a0, $t0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d674) {
            ctx->pc = 0x16D6C8u;
            goto label_16d6c8;
        }
    }
    ctx->pc = 0x16D67Cu;
    // 0x16d67c: 0x0  nop
    ctx->pc = 0x16d67cu;
    // NOP
label_16d680:
    // 0x16d680: 0x10620005  beq         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x16D680u;
    {
        const bool branch_taken_0x16d680 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x16D684u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D680u;
            // 0x16d684: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d680) {
            ctx->pc = 0x16D698u;
            goto label_16d698;
        }
    }
    ctx->pc = 0x16D688u;
    // 0x16d688: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x16D688u;
    {
        const bool branch_taken_0x16d688 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16D68Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D688u;
            // 0x16d68c: 0x100202d  daddu       $a0, $t0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d688) {
            ctx->pc = 0x16D6C8u;
            goto label_16d6c8;
        }
    }
    ctx->pc = 0x16D690u;
label_16d690:
    // 0x16d690: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x16D690u;
    {
        const bool branch_taken_0x16d690 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16D694u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D690u;
            // 0x16d694: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d690) {
            ctx->pc = 0x16D6D8u;
            goto label_16d6d8;
        }
    }
    ctx->pc = 0x16D698u;
label_16d698:
    // 0x16d698: 0x1cc0000f  bgtz        $a2, . + 4 + (0xF << 2)
    ctx->pc = 0x16D698u;
    {
        const bool branch_taken_0x16d698 = (GPR_S64(ctx, 6) > 0);
        ctx->pc = 0x16D69Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D698u;
            // 0x16d69c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d698) {
            ctx->pc = 0x16D6D8u;
            goto label_16d6d8;
        }
    }
    ctx->pc = 0x16D6A0u;
    // 0x16d6a0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16d6a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16d6a4: 0x805a704  j           func_169C10
    ctx->pc = 0x16D6A4u;
    ctx->pc = 0x16D6A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D6A4u;
            // 0x16d6a8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16D6ACu;
    // 0x16d6ac: 0x0  nop
    ctx->pc = 0x16d6acu;
    // NOP
label_16d6b0:
    // 0x16d6b0: 0x1cc00009  bgtz        $a2, . + 4 + (0x9 << 2)
    ctx->pc = 0x16D6B0u;
    {
        const bool branch_taken_0x16d6b0 = (GPR_S64(ctx, 6) > 0);
        ctx->pc = 0x16D6B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D6B0u;
            // 0x16d6b4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d6b0) {
            ctx->pc = 0x16D6D8u;
            goto label_16d6d8;
        }
    }
    ctx->pc = 0x16D6B8u;
    // 0x16d6b8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16d6b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16d6bc: 0x805a704  j           func_169C10
    ctx->pc = 0x16D6BCu;
    ctx->pc = 0x16D6C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D6BCu;
            // 0x16d6c0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16D6C4u;
    // 0x16d6c4: 0x0  nop
    ctx->pc = 0x16d6c4u;
    // NOP
label_16d6c8:
    // 0x16d6c8: 0xe0282d  daddu       $a1, $a3, $zero
    ctx->pc = 0x16d6c8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d6cc: 0x805a704  j           func_169C10
    ctx->pc = 0x16D6CCu;
    ctx->pc = 0x16D6D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D6CCu;
            // 0x16d6d0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16D6D4u;
    // 0x16d6d4: 0x0  nop
    ctx->pc = 0x16d6d4u;
    // NOP
label_16d6d8:
    // 0x16d6d8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16d6d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16d6dc: 0x3e00008  jr          $ra
    ctx->pc = 0x16D6DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16D6E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D6DCu;
            // 0x16d6e0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16D680u: goto label_16d680;
            case 0x16D690u: goto label_16d690;
            case 0x16D698u: goto label_16d698;
            case 0x16D6B0u: goto label_16d6b0;
            case 0x16D6C8u: goto label_16d6c8;
            case 0x16D6D8u: goto label_16d6d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16D6E4u;
    // 0x16d6e4: 0x0  nop
    ctx->pc = 0x16d6e4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
