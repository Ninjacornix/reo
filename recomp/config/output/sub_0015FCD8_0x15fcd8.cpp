#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015FCD8
// Address: 0x15fcd8 - 0x15fd54
void sub_0015FCD8_0x15fcd8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015FCD8_0x15fcd8");
#endif

    switch (ctx->pc) {
        case 0x15fcf4u: goto label_15fcf4;
        case 0x15fd20u: goto label_15fd20;
        default: break;
    }

    ctx->pc = 0x15fcd8u;

    // 0x15fcd8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15fcd8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15fcdc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15fcdcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15fce0: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x15fce0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15fce4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15fce4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15fce8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x15fce8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x15fcec: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x15FCECu;
    SET_GPR_U32(ctx, 31, 0x15FCF4u);
    ctx->pc = 0x15FCF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FCECu;
            // 0x15fcf0: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FCF4u; }
        if (ctx->pc != 0x15FCF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FCF4u; }
        if (ctx->pc != 0x15FCF4u) { return; }
    }
    ctx->pc = 0x15FCF4u;
label_15fcf4:
    // 0x15fcf4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15fcf4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15fcf8: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x15fcf8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15fcfc: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x15FCFCu;
    {
        const bool branch_taken_0x15fcfc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15FD00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FCFCu;
            // 0x15fd00: 0x2484f3d0  addiu       $a0, $a0, -0xC30 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294964176));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15fcfc) {
            ctx->pc = 0x15FD18u;
            goto label_15fd18;
        }
    }
    ctx->pc = 0x15FD04u;
    // 0x15fd04: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15fd04u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15fd08: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15fd08u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15fd0c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15fd0cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15fd10: 0x8058dd4  j           func_163750
    ctx->pc = 0x15FD10u;
    ctx->pc = 0x15FD14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FD10u;
            // 0x15fd14: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15FD18u;
label_15fd18:
    // 0x15fd18: 0xc05c8d0  jal         func_172340
    ctx->pc = 0x15FD18u;
    SET_GPR_U32(ctx, 31, 0x15FD20u);
    ctx->pc = 0x15FD1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FD18u;
            // 0x15fd1c: 0x8e240040  lw          $a0, 0x40($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 64)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x172340u;
    if (runtime->hasFunction(0x172340u)) {
        auto targetFn = runtime->lookupFunction(0x172340u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FD20u; }
        if (ctx->pc != 0x15FD20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00172340_0x172340(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FD20u; }
        if (ctx->pc != 0x15FD20u) { return; }
    }
    ctx->pc = 0x15FD20u;
label_15fd20:
    // 0x15fd20: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15fd20u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15fd24: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x15FD24u;
    {
        const bool branch_taken_0x15fd24 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15FD28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FD24u;
            // 0x15fd28: 0x2484f400  addiu       $a0, $a0, -0xC00 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294964224));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15fd24) {
            ctx->pc = 0x15FD40u;
            goto label_15fd40;
        }
    }
    ctx->pc = 0x15FD2Cu;
    // 0x15fd2c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15fd2cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15fd30: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15fd30u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15fd34: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15fd34u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15fd38: 0x8058dd4  j           func_163750
    ctx->pc = 0x15FD38u;
    ctx->pc = 0x15FD3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FD38u;
            // 0x15fd3c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15FD40u;
label_15fd40:
    // 0x15fd40: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15fd40u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15fd44: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15fd44u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15fd48: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15fd48u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15fd4c: 0x3e00008  jr          $ra
    ctx->pc = 0x15FD4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15FD50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FD4Cu;
            // 0x15fd50: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15FCF4u: goto label_15fcf4;
            case 0x15FD18u: goto label_15fd18;
            case 0x15FD20u: goto label_15fd20;
            case 0x15FD40u: goto label_15fd40;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15FD54u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
