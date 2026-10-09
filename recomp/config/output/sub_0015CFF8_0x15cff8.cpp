#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015CFF8
// Address: 0x15cff8 - 0x15d048
void sub_0015CFF8_0x15cff8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015CFF8_0x15cff8");
#endif

    switch (ctx->pc) {
        case 0x15d00cu: goto label_15d00c;
        default: break;
    }

    ctx->pc = 0x15cff8u;

    // 0x15cff8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15cff8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15cffc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15cffcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15d000: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x15d000u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x15d004: 0xc05799e  jal         func_15E678
    ctx->pc = 0x15D004u;
    SET_GPR_U32(ctx, 31, 0x15D00Cu);
    ctx->pc = 0x15D008u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D004u;
            // 0x15d008: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15E678u;
    if (runtime->hasFunction(0x15E678u)) {
        auto targetFn = runtime->lookupFunction(0x15E678u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D00Cu; }
        if (ctx->pc != 0x15D00Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E678_0x15e678(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D00Cu; }
        if (ctx->pc != 0x15D00Cu) { return; }
    }
    ctx->pc = 0x15D00Cu;
label_15d00c:
    // 0x15d00c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x15d00cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d010: 0x8e020018  lw          $v0, 0x18($s0)
    ctx->pc = 0x15d010u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x15d014: 0x2406ffff  addiu       $a2, $zero, -0x1
    ctx->pc = 0x15d014u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x15d018: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x15D018u;
    {
        const bool branch_taken_0x15d018 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15D01Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D018u;
            // 0x15d01c: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d018) {
            ctx->pc = 0x15D034u;
            goto label_15d034;
        }
    }
    ctx->pc = 0x15D020u;
    // 0x15d020: 0x8ca30028  lw          $v1, 0x28($a1)
    ctx->pc = 0x15d020u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 40)));
    // 0x15d024: 0xc0202d  daddu       $a0, $a2, $zero
    ctx->pc = 0x15d024u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d028: 0x8ca2002c  lw          $v0, 0x2C($a1)
    ctx->pc = 0x15d028u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 44)));
    // 0x15d02c: 0x3200b  movn        $a0, $zero, $v1
    ctx->pc = 0x15d02cu;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 0));
    // 0x15d030: 0xc2200a  movz        $a0, $a2, $v0
    ctx->pc = 0x15d030u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 6));
label_15d034:
    // 0x15d034: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15d034u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15d038: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x15d038u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d03c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x15d03cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15d040: 0x3e00008  jr          $ra
    ctx->pc = 0x15D040u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15D044u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D040u;
            // 0x15d044: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15D00Cu: goto label_15d00c;
            case 0x15D034u: goto label_15d034;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15D048u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
