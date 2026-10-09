#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00136AA8
// Address: 0x136aa8 - 0x136b0c
void sub_00136AA8_0x136aa8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00136AA8_0x136aa8");
#endif

    switch (ctx->pc) {
        case 0x136ac8u: goto label_136ac8;
        case 0x136ae8u: goto label_136ae8;
        case 0x136af8u: goto label_136af8;
        default: break;
    }

    ctx->pc = 0x136aa8u;

    // 0x136aa8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x136aa8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x136aac: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x136aacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x136ab0: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x136ab0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136ab4: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x136AB4u;
    {
        const bool branch_taken_0x136ab4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x136AB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136AB4u;
            // 0x136ab8: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136ab4) {
            ctx->pc = 0x136AD0u;
            goto label_136ad0;
        }
    }
    ctx->pc = 0x136ABCu;
    // 0x136abc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136abcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136ac0: 0xc04d480  jal         func_135200
    ctx->pc = 0x136AC0u;
    SET_GPR_U32(ctx, 31, 0x136AC8u);
    ctx->pc = 0x136AC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136AC0u;
            // 0x136ac4: 0x2484c0c0  addiu       $a0, $a0, -0x3F40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951104));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136AC8u; }
        if (ctx->pc != 0x136AC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136AC8u; }
        if (ctx->pc != 0x136AC8u) { return; }
    }
    ctx->pc = 0x136AC8u;
label_136ac8:
    // 0x136ac8: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x136AC8u;
    {
        const bool branch_taken_0x136ac8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136ACCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136AC8u;
            // 0x136acc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136ac8) {
            ctx->pc = 0x136AFCu;
            goto label_136afc;
        }
    }
    ctx->pc = 0x136AD0u;
label_136ad0:
    // 0x136ad0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x136ad0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x136ad4: 0x8c420060  lw          $v0, 0x60($v0)
    ctx->pc = 0x136ad4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 96)));
    // 0x136ad8: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x136AD8u;
    {
        const bool branch_taken_0x136ad8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x136ad8) {
            ctx->pc = 0x136ADCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x136AD8u;
            // 0x136adc: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x136AF0u;
            goto label_136af0;
        }
    }
    ctx->pc = 0x136AE0u;
    // 0x136ae0: 0x40f809  jalr        $v0
    ctx->pc = 0x136AE0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x136AE8u);
        ctx->pc = 0x136AE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136AE0u;
            // 0x136ae4: 0x8c840004  lw          $a0, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x136AE8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136AC8u: goto label_136ac8;
            case 0x136AD0u: goto label_136ad0;
            case 0x136AE8u: goto label_136ae8;
            case 0x136AF0u: goto label_136af0;
            case 0x136AF8u: goto label_136af8;
            case 0x136AFCu: goto label_136afc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136AE8u; }
            if (ctx->pc != 0x136AE8u) { return; }
        }
        }
    }
    ctx->pc = 0x136AE8u;
label_136ae8:
    // 0x136ae8: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x136AE8u;
    {
        const bool branch_taken_0x136ae8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136AECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136AE8u;
            // 0x136aec: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136ae8) {
            ctx->pc = 0x136AF8u;
            goto label_136af8;
        }
    }
    ctx->pc = 0x136AF0u;
label_136af0:
    // 0x136af0: 0xc04d480  jal         func_135200
    ctx->pc = 0x136AF0u;
    SET_GPR_U32(ctx, 31, 0x136AF8u);
    ctx->pc = 0x136AF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136AF0u;
            // 0x136af4: 0x2484c0e0  addiu       $a0, $a0, -0x3F20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951136));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136AF8u; }
        if (ctx->pc != 0x136AF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136AF8u; }
        if (ctx->pc != 0x136AF8u) { return; }
    }
    ctx->pc = 0x136AF8u;
label_136af8:
    // 0x136af8: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x136af8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_136afc:
    // 0x136afc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x136afcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x136b00: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x136b00u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x136b04: 0x3e00008  jr          $ra
    ctx->pc = 0x136B04u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136B08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136B04u;
            // 0x136b08: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136AC8u: goto label_136ac8;
            case 0x136AD0u: goto label_136ad0;
            case 0x136AE8u: goto label_136ae8;
            case 0x136AF0u: goto label_136af0;
            case 0x136AF8u: goto label_136af8;
            case 0x136AFCu: goto label_136afc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136B0Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
