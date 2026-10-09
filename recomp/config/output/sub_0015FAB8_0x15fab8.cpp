#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015FAB8
// Address: 0x15fab8 - 0x15fb20
void sub_0015FAB8_0x15fab8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015FAB8_0x15fab8");
#endif

    switch (ctx->pc) {
        case 0x15fadcu: goto label_15fadc;
        default: break;
    }

    ctx->pc = 0x15fab8u;

    // 0x15fab8: 0x3e00008  jr          $ra
    ctx->pc = 0x15FAB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15FADCu: goto label_15fadc;
            case 0x15FB08u: goto label_15fb08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15FAC0u;
    // 0x15fac0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15fac0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15fac4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15fac4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15fac8: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x15fac8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15facc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15faccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15fad0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x15fad0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x15fad4: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x15FAD4u;
    SET_GPR_U32(ctx, 31, 0x15FADCu);
    ctx->pc = 0x15FAD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FAD4u;
            // 0x15fad8: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FADCu; }
        if (ctx->pc != 0x15FADCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FADCu; }
        if (ctx->pc != 0x15FADCu) { return; }
    }
    ctx->pc = 0x15FADCu;
label_15fadc:
    // 0x15fadc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15fadcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15fae0: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x15fae0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15fae4: 0x2484f2a8  addiu       $a0, $a0, -0xD58
    ctx->pc = 0x15fae4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294963880));
    // 0x15fae8: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x15FAE8u;
    {
        const bool branch_taken_0x15fae8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15FAECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FAE8u;
            // 0x15faec: 0x24050006  addiu       $a1, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15fae8) {
            ctx->pc = 0x15FB08u;
            goto label_15fb08;
        }
    }
    ctx->pc = 0x15FAF0u;
    // 0x15faf0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15faf0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15faf4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15faf4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15faf8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15faf8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15fafc: 0x8058dd4  j           func_163750
    ctx->pc = 0x15FAFCu;
    ctx->pc = 0x15FB00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FAFCu;
            // 0x15fb00: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15FB04u;
    // 0x15fb04: 0x0  nop
    ctx->pc = 0x15fb04u;
    // NOP
label_15fb08:
    // 0x15fb08: 0x8e240040  lw          $a0, 0x40($s1)
    ctx->pc = 0x15fb08u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 64)));
    // 0x15fb0c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15fb0cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15fb10: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15fb10u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15fb14: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15fb14u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15fb18: 0x805d4ce  j           func_175338
    ctx->pc = 0x15FB18u;
    ctx->pc = 0x15FB1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FB18u;
            // 0x15fb1c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175338u;
    if (runtime->hasFunction(0x175338u)) {
        auto targetFn = runtime->lookupFunction(0x175338u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00175338_0x175338(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15FB20u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
