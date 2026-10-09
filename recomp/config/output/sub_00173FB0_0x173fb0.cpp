#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00173FB0
// Address: 0x173fb0 - 0x174030
void sub_00173FB0_0x173fb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00173FB0_0x173fb0");
#endif

    switch (ctx->pc) {
        case 0x173fd0u: goto label_173fd0;
        case 0x17400cu: goto label_17400c;
        default: break;
    }

    ctx->pc = 0x173fb0u;

    // 0x173fb0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x173fb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x173fb4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x173fb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x173fb8: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x173fb8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173fbc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x173fbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x173fc0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x173fc0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173fc4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x173fc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x173fc8: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x173FC8u;
    SET_GPR_U32(ctx, 31, 0x173FD0u);
    ctx->pc = 0x173FCCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173FC8u;
            // 0x173fcc: 0xae000000  sw          $zero, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173FD0u; }
        if (ctx->pc != 0x173FD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173FD0u; }
        if (ctx->pc != 0x173FD0u) { return; }
    }
    ctx->pc = 0x173FD0u;
label_173fd0:
    // 0x173fd0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x173fd0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173fd4: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x173fd4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x173fd8: 0x2406000b  addiu       $a2, $zero, 0xB
    ctx->pc = 0x173fd8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x173fdc: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x173fdcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173fe0: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x173fe0u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173fe4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x173FE4u;
    {
        const bool branch_taken_0x173fe4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x173FE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173FE4u;
            // 0x173fe8: 0x34a50136  ori         $a1, $a1, 0x136 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)310);
        ctx->in_delay_slot = false;
        if (branch_taken_0x173fe4) {
            ctx->pc = 0x174000u;
            goto label_174000;
        }
    }
    ctx->pc = 0x173FECu;
    // 0x173fec: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x173fecu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x173ff0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x173ff0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x173ff4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x173ff4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x173ff8: 0x805a704  j           func_169C10
    ctx->pc = 0x173FF8u;
    ctx->pc = 0x173FFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173FF8u;
            // 0x173ffc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x174000u;
label_174000:
    // 0x174000: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x174000u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174004: 0xc05def8  jal         func_177BE0
    ctx->pc = 0x174004u;
    SET_GPR_U32(ctx, 31, 0x17400Cu);
    ctx->pc = 0x174008u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x174004u;
            // 0x174008: 0x24050006  addiu       $a1, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177BE0u;
    if (runtime->hasFunction(0x177BE0u)) {
        auto targetFn = runtime->lookupFunction(0x177BE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17400Cu; }
        if (ctx->pc != 0x17400Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177BE0_0x177be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17400Cu; }
        if (ctx->pc != 0x17400Cu) { return; }
    }
    ctx->pc = 0x17400Cu;
label_17400c:
    // 0x17400c: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x17400cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x174010: 0x10600002  beqz        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x174010u;
    {
        const bool branch_taken_0x174010 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x174014u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174010u;
            // 0x174014: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x174010) {
            ctx->pc = 0x17401Cu;
            goto label_17401c;
        }
    }
    ctx->pc = 0x174018u;
    // 0x174018: 0xae230960  sw          $v1, 0x960($s1)
    ctx->pc = 0x174018u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2400), GPR_U32(ctx, 3));
label_17401c:
    // 0x17401c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17401cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x174020: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x174020u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x174024: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x174024u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x174028: 0x3e00008  jr          $ra
    ctx->pc = 0x174028u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17402Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174028u;
            // 0x17402c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x173FD0u: goto label_173fd0;
            case 0x174000u: goto label_174000;
            case 0x17400Cu: goto label_17400c;
            case 0x17401Cu: goto label_17401c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x174030u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
