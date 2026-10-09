#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001609A0
// Address: 0x1609a0 - 0x160a04
void sub_001609A0_0x1609a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001609A0_0x1609a0");
#endif

    switch (ctx->pc) {
        case 0x1609bcu: goto label_1609bc;
        case 0x1609e8u: goto label_1609e8;
        default: break;
    }

    ctx->pc = 0x1609a0u;

    // 0x1609a0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1609a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1609a4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1609a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1609a8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1609a8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1609ac: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1609acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1609b0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1609b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1609b4: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x1609B4u;
    SET_GPR_U32(ctx, 31, 0x1609BCu);
    ctx->pc = 0x1609B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1609B4u;
            // 0x1609b8: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1609BCu; }
        if (ctx->pc != 0x1609BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1609BCu; }
        if (ctx->pc != 0x1609BCu) { return; }
    }
    ctx->pc = 0x1609BCu;
label_1609bc:
    // 0x1609bc: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1609BCu;
    {
        const bool branch_taken_0x1609bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1609C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1609BCu;
            // 0x1609c0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1609bc) {
            ctx->pc = 0x1609E0u;
            goto label_1609e0;
        }
    }
    ctx->pc = 0x1609C4u;
    // 0x1609c4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1609c4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1609c8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1609c8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1609cc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1609ccu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1609d0: 0x2484f848  addiu       $a0, $a0, -0x7B8
    ctx->pc = 0x1609d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294965320));
    // 0x1609d4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1609d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1609d8: 0x8058dd4  j           func_163750
    ctx->pc = 0x1609D8u;
    ctx->pc = 0x1609DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1609D8u;
            // 0x1609dc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1609E0u;
label_1609e0:
    // 0x1609e0: 0xc057ec8  jal         func_15FB20
    ctx->pc = 0x1609E0u;
    SET_GPR_U32(ctx, 31, 0x1609E8u);
    ctx->pc = 0x15FB20u;
    if (runtime->hasFunction(0x15FB20u)) {
        auto targetFn = runtime->lookupFunction(0x15FB20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1609E8u; }
        if (ctx->pc != 0x1609E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FB20_0x15fb20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1609E8u; }
        if (ctx->pc != 0x1609E8u) { return; }
    }
    ctx->pc = 0x1609E8u;
label_1609e8:
    // 0x1609e8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1609e8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1609ec: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1609ecu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1609f0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1609f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1609f4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1609f4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1609f8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1609f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1609fc: 0x805c8b4  j           func_1722D0
    ctx->pc = 0x1609FCu;
    ctx->pc = 0x160A00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1609FCu;
            // 0x160a00: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1722D0u;
    if (runtime->hasFunction(0x1722D0u)) {
        auto targetFn = runtime->lookupFunction(0x1722D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001722D0_0x1722d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x160A04u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
