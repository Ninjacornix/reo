#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001614E8
// Address: 0x1614e8 - 0x161578
void sub_001614E8_0x1614e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001614E8_0x1614e8");
#endif

    switch (ctx->pc) {
        case 0x1614fcu: goto label_1614fc;
        case 0x16152cu: goto label_16152c;
        case 0x161540u: goto label_161540;
        case 0x161560u: goto label_161560;
        default: break;
    }

    ctx->pc = 0x1614e8u;

    // 0x1614e8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1614e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1614ec: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1614ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1614f0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1614f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1614f4: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x1614F4u;
    SET_GPR_U32(ctx, 31, 0x1614FCu);
    ctx->pc = 0x1614F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1614F4u;
            // 0x1614f8: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1614FCu; }
        if (ctx->pc != 0x1614FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1614FCu; }
        if (ctx->pc != 0x1614FCu) { return; }
    }
    ctx->pc = 0x1614FCu;
label_1614fc:
    // 0x1614fc: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1614fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x161500: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x161500u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161504: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x161504u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x161508: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x161508u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16150c: 0x805f492  j           func_17D248
    ctx->pc = 0x16150Cu;
    ctx->pc = 0x161510u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16150Cu;
            // 0x161510: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D248u;
    if (runtime->hasFunction(0x17D248u)) {
        auto targetFn = runtime->lookupFunction(0x17D248u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D248_0x17d248(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x161514u;
    // 0x161514: 0x0  nop
    ctx->pc = 0x161514u;
    // NOP
    // 0x161518: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x161518u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16151c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16151cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x161520: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x161520u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x161524: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x161524u;
    SET_GPR_U32(ctx, 31, 0x16152Cu);
    ctx->pc = 0x161528u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161524u;
            // 0x161528: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16152Cu; }
        if (ctx->pc != 0x16152Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16152Cu; }
        if (ctx->pc != 0x16152Cu) { return; }
    }
    ctx->pc = 0x16152Cu;
label_16152c:
    // 0x16152c: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x16152Cu;
    {
        const bool branch_taken_0x16152c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x161530u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16152Cu;
            // 0x161530: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16152c) {
            ctx->pc = 0x161558u;
            goto label_161558;
        }
    }
    ctx->pc = 0x161534u;
    // 0x161534: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x161534u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x161538: 0xc058dd4  jal         func_163750
    ctx->pc = 0x161538u;
    SET_GPR_U32(ctx, 31, 0x161540u);
    ctx->pc = 0x16153Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161538u;
            // 0x16153c: 0x2484fcf0  addiu       $a0, $a0, -0x310 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966512));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161540u; }
        if (ctx->pc != 0x161540u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161540u; }
        if (ctx->pc != 0x161540u) { return; }
    }
    ctx->pc = 0x161540u;
label_161540:
    // 0x161540: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x161540u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161544: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x161544u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x161548: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x161548u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16154c: 0x3e00008  jr          $ra
    ctx->pc = 0x16154Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x161550u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16154Cu;
            // 0x161550: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1614FCu: goto label_1614fc;
            case 0x16152Cu: goto label_16152c;
            case 0x161540u: goto label_161540;
            case 0x161558u: goto label_161558;
            case 0x161560u: goto label_161560;
            default: break;
        }
        return;
    }
    ctx->pc = 0x161554u;
    // 0x161554: 0x0  nop
    ctx->pc = 0x161554u;
    // NOP
label_161558:
    // 0x161558: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x161558u;
    SET_GPR_U32(ctx, 31, 0x161560u);
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161560u; }
        if (ctx->pc != 0x161560u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161560u; }
        if (ctx->pc != 0x161560u) { return; }
    }
    ctx->pc = 0x161560u;
label_161560:
    // 0x161560: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x161560u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x161564: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x161564u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161568: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x161568u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16156c: 0x805f494  j           func_17D250
    ctx->pc = 0x16156Cu;
    ctx->pc = 0x161570u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16156Cu;
            // 0x161570: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D250u;
    if (runtime->hasFunction(0x17D250u)) {
        auto targetFn = runtime->lookupFunction(0x17D250u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D250_0x17d250(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x161574u;
    // 0x161574: 0x0  nop
    ctx->pc = 0x161574u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
