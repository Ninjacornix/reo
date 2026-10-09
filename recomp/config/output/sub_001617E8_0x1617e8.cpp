#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001617E8
// Address: 0x1617e8 - 0x16184c
void sub_001617E8_0x1617e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001617E8_0x1617e8");
#endif

    switch (ctx->pc) {
        case 0x161804u: goto label_161804;
        case 0x161830u: goto label_161830;
        default: break;
    }

    ctx->pc = 0x1617e8u;

    // 0x1617e8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1617e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1617ec: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1617ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1617f0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1617f0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1617f4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1617f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1617f8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1617f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1617fc: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x1617FCu;
    SET_GPR_U32(ctx, 31, 0x161804u);
    ctx->pc = 0x161800u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1617FCu;
            // 0x161800: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161804u; }
        if (ctx->pc != 0x161804u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161804u; }
        if (ctx->pc != 0x161804u) { return; }
    }
    ctx->pc = 0x161804u;
label_161804:
    // 0x161804: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x161804u;
    {
        const bool branch_taken_0x161804 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x161808u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161804u;
            // 0x161808: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161804) {
            ctx->pc = 0x161828u;
            goto label_161828;
        }
    }
    ctx->pc = 0x16180Cu;
    // 0x16180c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x16180cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x161810: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x161810u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x161814: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x161814u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x161818: 0x2484fe10  addiu       $a0, $a0, -0x1F0
    ctx->pc = 0x161818u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966800));
    // 0x16181c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x16181cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x161820: 0x8058dd4  j           func_163750
    ctx->pc = 0x161820u;
    ctx->pc = 0x161824u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161820u;
            // 0x161824: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x161828u;
label_161828:
    // 0x161828: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x161828u;
    SET_GPR_U32(ctx, 31, 0x161830u);
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161830u; }
        if (ctx->pc != 0x161830u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161830u; }
        if (ctx->pc != 0x161830u) { return; }
    }
    ctx->pc = 0x161830u;
label_161830:
    // 0x161830: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x161830u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161834: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x161834u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x161838: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x161838u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16183c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16183cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x161840: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x161840u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x161844: 0x805f4f4  j           func_17D3D0
    ctx->pc = 0x161844u;
    ctx->pc = 0x161848u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161844u;
            // 0x161848: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D3D0u;
    if (runtime->hasFunction(0x17D3D0u)) {
        auto targetFn = runtime->lookupFunction(0x17D3D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D3D0_0x17d3d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16184Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
