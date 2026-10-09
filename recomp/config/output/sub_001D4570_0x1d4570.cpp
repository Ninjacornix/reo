#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D4570
// Address: 0x1d4570 - 0x1d45e4
void sub_001D4570_0x1d4570(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D4570_0x1d4570");
#endif

    switch (ctx->pc) {
        case 0x1d45a0u: goto label_1d45a0;
        case 0x1d45bcu: goto label_1d45bc;
        case 0x1d45d8u: goto label_1d45d8;
        default: break;
    }

    ctx->pc = 0x1d4570u;

    // 0x1d4570: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1d4570u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1d4574: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d4574u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d4578: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d4578u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d457c: 0x802243d7  lb          $v0, 0x43D7($at)
    ctx->pc = 0x1d457cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d4580: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1D4580u;
    {
        const bool branch_taken_0x1d4580 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D4584u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4580u;
            // 0x1d4584: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4580) {
            ctx->pc = 0x1D45A8u;
            goto label_1d45a8;
        }
    }
    ctx->pc = 0x1D4588u;
    // 0x1d4588: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d4588u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d458c: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d458cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d4590: 0x942643da  lhu         $a2, 0x43DA($at)
    ctx->pc = 0x1d4590u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d4594: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x1d4594u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1d4598: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D4598u;
    SET_GPR_U32(ctx, 31, 0x1D45A0u);
    ctx->pc = 0x1D459Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4598u;
            // 0x1d459c: 0x24a56910  addiu       $a1, $a1, 0x6910 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26896));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D45A0u; }
        if (ctx->pc != 0x1D45A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D45A0u; }
        if (ctx->pc != 0x1D45A0u) { return; }
    }
    ctx->pc = 0x1D45A0u;
label_1d45a0:
    // 0x1d45a0: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1D45A0u;
    {
        const bool branch_taken_0x1d45a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d45a0) {
            ctx->pc = 0x1D45BCu;
            goto label_1d45bc;
        }
    }
    ctx->pc = 0x1D45A8u;
label_1d45a8:
    // 0x1d45a8: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d45a8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d45ac: 0x942643da  lhu         $a2, 0x43DA($at)
    ctx->pc = 0x1d45acu;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d45b0: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x1d45b0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1d45b4: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D45B4u;
    SET_GPR_U32(ctx, 31, 0x1D45BCu);
    ctx->pc = 0x1D45B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D45B4u;
            // 0x1d45b8: 0x24a56930  addiu       $a1, $a1, 0x6930 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26928));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D45BCu; }
        if (ctx->pc != 0x1D45BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D45BCu; }
        if (ctx->pc != 0x1D45BCu) { return; }
    }
    ctx->pc = 0x1D45BCu;
label_1d45bc:
    // 0x1d45bc: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d45bcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d45c0: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x1d45c0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x1d45c4: 0x8c254464  lw          $a1, 0x4464($at)
    ctx->pc = 0x1d45c4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17508)));
    // 0x1d45c8: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x1d45c8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1d45cc: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1d45ccu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d45d0: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D45D0u;
    SET_GPR_U32(ctx, 31, 0x1D45D8u);
    ctx->pc = 0x1D45D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D45D0u;
            // 0x1d45d4: 0x34460001  ori         $a2, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D45D8u; }
        if (ctx->pc != 0x1D45D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D45D8u; }
        if (ctx->pc != 0x1D45D8u) { return; }
    }
    ctx->pc = 0x1D45D8u;
label_1d45d8:
    // 0x1d45d8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d45d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d45dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1D45DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D45E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D45DCu;
            // 0x1d45e0: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D45A0u: goto label_1d45a0;
            case 0x1D45A8u: goto label_1d45a8;
            case 0x1D45BCu: goto label_1d45bc;
            case 0x1D45D8u: goto label_1d45d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D45E4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
