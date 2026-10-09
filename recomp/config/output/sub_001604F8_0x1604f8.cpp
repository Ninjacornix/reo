#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001604F8
// Address: 0x1604f8 - 0x160548
void sub_001604F8_0x1604f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001604F8_0x1604f8");
#endif

    switch (ctx->pc) {
        case 0x16050cu: goto label_16050c;
        case 0x160520u: goto label_160520;
        default: break;
    }

    ctx->pc = 0x1604f8u;

    // 0x1604f8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1604f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1604fc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1604fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x160500: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x160500u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x160504: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x160504u;
    SET_GPR_U32(ctx, 31, 0x16050Cu);
    ctx->pc = 0x160508u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160504u;
            // 0x160508: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16050Cu; }
        if (ctx->pc != 0x16050Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16050Cu; }
        if (ctx->pc != 0x16050Cu) { return; }
    }
    ctx->pc = 0x16050Cu;
label_16050c:
    // 0x16050c: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x16050Cu;
    {
        const bool branch_taken_0x16050c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x160510u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16050Cu;
            // 0x160510: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16050c) {
            ctx->pc = 0x160538u;
            goto label_160538;
        }
    }
    ctx->pc = 0x160514u;
    // 0x160514: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x160514u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x160518: 0xc058dd4  jal         func_163750
    ctx->pc = 0x160518u;
    SET_GPR_U32(ctx, 31, 0x160520u);
    ctx->pc = 0x16051Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160518u;
            // 0x16051c: 0x2484f6e8  addiu       $a0, $a0, -0x918 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294964968));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160520u; }
        if (ctx->pc != 0x160520u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160520u; }
        if (ctx->pc != 0x160520u) { return; }
    }
    ctx->pc = 0x160520u;
label_160520:
    // 0x160520: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x160520u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160524: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x160524u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160528: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x160528u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16052c: 0x3e00008  jr          $ra
    ctx->pc = 0x16052Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x160530u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16052Cu;
            // 0x160530: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16050Cu: goto label_16050c;
            case 0x160520u: goto label_160520;
            case 0x160538u: goto label_160538;
            default: break;
        }
        return;
    }
    ctx->pc = 0x160534u;
    // 0x160534: 0x0  nop
    ctx->pc = 0x160534u;
    // NOP
label_160538:
    // 0x160538: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x160538u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16053c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x16053cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x160540: 0x8057dea  j           func_15F7A8
    ctx->pc = 0x160540u;
    ctx->pc = 0x160544u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160540u;
            // 0x160544: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F7A8u;
    if (runtime->hasFunction(0x15F7A8u)) {
        auto targetFn = runtime->lookupFunction(0x15F7A8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0015F7A8_0x15f7a8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x160548u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
