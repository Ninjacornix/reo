#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00161720
// Address: 0x161720 - 0x161784
void sub_00161720_0x161720(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00161720_0x161720");
#endif

    switch (ctx->pc) {
        case 0x16173cu: goto label_16173c;
        case 0x161768u: goto label_161768;
        default: break;
    }

    ctx->pc = 0x161720u;

    // 0x161720: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x161720u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x161724: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x161724u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x161728: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x161728u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16172c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16172cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x161730: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x161730u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x161734: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x161734u;
    SET_GPR_U32(ctx, 31, 0x16173Cu);
    ctx->pc = 0x161738u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161734u;
            // 0x161738: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16173Cu; }
        if (ctx->pc != 0x16173Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16173Cu; }
        if (ctx->pc != 0x16173Cu) { return; }
    }
    ctx->pc = 0x16173Cu;
label_16173c:
    // 0x16173c: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x16173Cu;
    {
        const bool branch_taken_0x16173c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x161740u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16173Cu;
            // 0x161740: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16173c) {
            ctx->pc = 0x161760u;
            goto label_161760;
        }
    }
    ctx->pc = 0x161744u;
    // 0x161744: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x161744u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x161748: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x161748u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16174c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16174cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x161750: 0x2484fda0  addiu       $a0, $a0, -0x260
    ctx->pc = 0x161750u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966688));
    // 0x161754: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x161754u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x161758: 0x8058dd4  j           func_163750
    ctx->pc = 0x161758u;
    ctx->pc = 0x16175Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161758u;
            // 0x16175c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x161760u;
label_161760:
    // 0x161760: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x161760u;
    SET_GPR_U32(ctx, 31, 0x161768u);
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161768u; }
        if (ctx->pc != 0x161768u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161768u; }
        if (ctx->pc != 0x161768u) { return; }
    }
    ctx->pc = 0x161768u;
label_161768:
    // 0x161768: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x161768u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16176c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16176cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x161770: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x161770u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161774: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x161774u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x161778: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x161778u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16177c: 0x805f4f0  j           func_17D3C0
    ctx->pc = 0x16177Cu;
    ctx->pc = 0x161780u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16177Cu;
            // 0x161780: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D3C0u;
    if (runtime->hasFunction(0x17D3C0u)) {
        auto targetFn = runtime->lookupFunction(0x17D3C0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D3C0_0x17d3c0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x161784u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
