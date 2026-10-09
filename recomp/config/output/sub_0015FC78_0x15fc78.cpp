#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015FC78
// Address: 0x15fc78 - 0x15fcd8
void sub_0015FC78_0x15fc78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015FC78_0x15fc78");
#endif

    switch (ctx->pc) {
        case 0x15fc94u: goto label_15fc94;
        default: break;
    }

    ctx->pc = 0x15fc78u;

    // 0x15fc78: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15fc78u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15fc7c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15fc7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15fc80: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x15fc80u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15fc84: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15fc84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15fc88: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x15fc88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x15fc8c: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x15FC8Cu;
    SET_GPR_U32(ctx, 31, 0x15FC94u);
    ctx->pc = 0x15FC90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FC8Cu;
            // 0x15fc90: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FC94u; }
        if (ctx->pc != 0x15FC94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FC94u; }
        if (ctx->pc != 0x15FC94u) { return; }
    }
    ctx->pc = 0x15FC94u;
label_15fc94:
    // 0x15fc94: 0x3a100001  xori        $s0, $s0, 0x1
    ctx->pc = 0x15fc94u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) ^ (uint64_t)(uint16_t)1);
    // 0x15fc98: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15fc98u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15fc9c: 0x2484f3a0  addiu       $a0, $a0, -0xC60
    ctx->pc = 0x15fc9cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294964128));
    // 0x15fca0: 0x10302b  sltu        $a2, $zero, $s0
    ctx->pc = 0x15fca0u;
    SET_GPR_U64(ctx, 6, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
    // 0x15fca4: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x15FCA4u;
    {
        const bool branch_taken_0x15fca4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15FCA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FCA4u;
            // 0x15fca8: 0x24050004  addiu       $a1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15fca4) {
            ctx->pc = 0x15FCC0u;
            goto label_15fcc0;
        }
    }
    ctx->pc = 0x15FCACu;
    // 0x15fcac: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15fcacu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15fcb0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15fcb0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15fcb4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15fcb4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15fcb8: 0x8058dd4  j           func_163750
    ctx->pc = 0x15FCB8u;
    ctx->pc = 0x15FCBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FCB8u;
            // 0x15fcbc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15FCC0u;
label_15fcc0:
    // 0x15fcc0: 0x8e240040  lw          $a0, 0x40($s1)
    ctx->pc = 0x15fcc0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 64)));
    // 0x15fcc4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15fcc4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15fcc8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15fcc8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15fccc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15fcccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15fcd0: 0x805d4ce  j           func_175338
    ctx->pc = 0x15FCD0u;
    ctx->pc = 0x15FCD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FCD0u;
            // 0x15fcd4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175338u;
    if (runtime->hasFunction(0x175338u)) {
        auto targetFn = runtime->lookupFunction(0x175338u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00175338_0x175338(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15FCD8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
