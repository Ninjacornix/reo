#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001370A0
// Address: 0x1370a0 - 0x137138
void sub_001370A0_0x1370a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001370A0_0x1370a0");
#endif

    switch (ctx->pc) {
        case 0x1370c8u: goto label_1370c8;
        case 0x1370f0u: goto label_1370f0;
        case 0x137110u: goto label_137110;
        default: break;
    }

    ctx->pc = 0x1370a0u;

    // 0x1370a0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1370a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1370a4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1370a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1370a8: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1370a8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1370ac: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1370acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1370b0: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1370b0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1370b4: 0x16200006  bnez        $s1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1370B4u;
    {
        const bool branch_taken_0x1370b4 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x1370B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1370B4u;
            // 0x1370b8: 0xffbf0010  sd          $ra, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1370b4) {
            ctx->pc = 0x1370D0u;
            goto label_1370d0;
        }
    }
    ctx->pc = 0x1370BCu;
    // 0x1370bc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1370bcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1370c0: 0xc04d480  jal         func_135200
    ctx->pc = 0x1370C0u;
    SET_GPR_U32(ctx, 31, 0x1370C8u);
    ctx->pc = 0x1370C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1370C0u;
            // 0x1370c4: 0x2484c3e0  addiu       $a0, $a0, -0x3C20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951904));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1370C8u; }
        if (ctx->pc != 0x1370C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1370C8u; }
        if (ctx->pc != 0x1370C8u) { return; }
    }
    ctx->pc = 0x1370C8u;
label_1370c8:
    // 0x1370c8: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x1370C8u;
    {
        const bool branch_taken_0x1370c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1370CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1370C8u;
            // 0x1370cc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1370c8) {
            ctx->pc = 0x137124u;
            goto label_137124;
        }
    }
    ctx->pc = 0x1370D0u;
label_1370d0:
    // 0x1370d0: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x1370d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1370d4: 0x8c420060  lw          $v0, 0x60($v0)
    ctx->pc = 0x1370d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 96)));
    // 0x1370d8: 0x10400011  beqz        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1370D8u;
    {
        const bool branch_taken_0x1370d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1370DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1370D8u;
            // 0x1370dc: 0x240500c8  addiu       $a1, $zero, 0xC8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 200));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1370d8) {
            ctx->pc = 0x137120u;
            goto label_137120;
        }
    }
    ctx->pc = 0x1370E0u;
    // 0x1370e0: 0x8e240004  lw          $a0, 0x4($s1)
    ctx->pc = 0x1370e0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1370e4: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1370e4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1370e8: 0x40f809  jalr        $v0
    ctx->pc = 0x1370E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1370F0u);
        ctx->pc = 0x1370ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1370E8u;
            // 0x1370ec: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1370F0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1370C8u: goto label_1370c8;
            case 0x1370D0u: goto label_1370d0;
            case 0x1370F0u: goto label_1370f0;
            case 0x137110u: goto label_137110;
            case 0x137120u: goto label_137120;
            case 0x137124u: goto label_137124;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1370F0u; }
            if (ctx->pc != 0x1370F0u) { return; }
        }
        }
    }
    ctx->pc = 0x1370F0u;
label_1370f0:
    // 0x1370f0: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x1370f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1370f4: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1370f4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1370f8: 0x8e240004  lw          $a0, 0x4($s1)
    ctx->pc = 0x1370f8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1370fc: 0x8c620060  lw          $v0, 0x60($v1)
    ctx->pc = 0x1370fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 96)));
    // 0x137100: 0x240500c9  addiu       $a1, $zero, 0xC9
    ctx->pc = 0x137100u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 201));
    // 0x137104: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x137104u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137108: 0x40f809  jalr        $v0
    ctx->pc = 0x137108u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x137110u);
        ctx->pc = 0x13710Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137108u;
            // 0x13710c: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x137110u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1370C8u: goto label_1370c8;
            case 0x1370D0u: goto label_1370d0;
            case 0x1370F0u: goto label_1370f0;
            case 0x137110u: goto label_137110;
            case 0x137120u: goto label_137120;
            case 0x137124u: goto label_137124;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x137110u; }
            if (ctx->pc != 0x137110u) { return; }
        }
        }
    }
    ctx->pc = 0x137110u;
label_137110:
    // 0x137110: 0x10803c  dsll32      $s0, $s0, 0
    ctx->pc = 0x137110u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) << (32 + 0));
    // 0x137114: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x137114u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x137118: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x137118u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x13711c: 0x202802d  daddu       $s0, $s0, $v0
    ctx->pc = 0x13711cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 2));
label_137120:
    // 0x137120: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x137120u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_137124:
    // 0x137124: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x137124u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x137128: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x137128u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13712c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x13712cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x137130: 0x3e00008  jr          $ra
    ctx->pc = 0x137130u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x137134u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137130u;
            // 0x137134: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1370C8u: goto label_1370c8;
            case 0x1370D0u: goto label_1370d0;
            case 0x1370F0u: goto label_1370f0;
            case 0x137110u: goto label_137110;
            case 0x137120u: goto label_137120;
            case 0x137124u: goto label_137124;
            default: break;
        }
        return;
    }
    ctx->pc = 0x137138u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
