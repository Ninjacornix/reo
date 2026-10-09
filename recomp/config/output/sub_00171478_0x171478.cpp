#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00171478
// Address: 0x171478 - 0x1714d0
void sub_00171478_0x171478(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00171478_0x171478");
#endif

    switch (ctx->pc) {
        case 0x171490u: goto label_171490;
        case 0x1714bcu: goto label_1714bc;
        default: break;
    }

    ctx->pc = 0x171478u;

    // 0x171478: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x171478u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17147c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17147cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x171480: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x171480u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171484: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x171484u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x171488: 0xc05c296  jal         func_170A58
    ctx->pc = 0x171488u;
    SET_GPR_U32(ctx, 31, 0x171490u);
    ctx->pc = 0x17148Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171488u;
            // 0x17148c: 0x24040005  addiu       $a0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x170A58u;
    if (runtime->hasFunction(0x170A58u)) {
        auto targetFn = runtime->lookupFunction(0x170A58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171490u; }
        if (ctx->pc != 0x171490u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00170A58_0x170a58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171490u; }
        if (ctx->pc != 0x171490u) { return; }
    }
    ctx->pc = 0x171490u;
label_171490:
    // 0x171490: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x171490u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x171494: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x171494u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x171498: 0x3c041000  lui         $a0, 0x1000
    ctx->pc = 0x171498u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4096 << 16));
    // 0x17149c: 0x3463b410  ori         $v1, $v1, 0xB410
    ctx->pc = 0x17149cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)46096);
    // 0x1714a0: 0x3442b420  ori         $v0, $v0, 0xB420
    ctx->pc = 0x1714a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)46112);
    // 0x1714a4: 0x3484b430  ori         $a0, $a0, 0xB430
    ctx->pc = 0x1714a4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)46128);
    // 0x1714a8: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x1714a8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x1714ac: 0xac600000  sw          $zero, 0x0($v1)
    ctx->pc = 0x1714acu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
    // 0x1714b0: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x1714b0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x1714b4: 0xc04518c  jal         func_114630
    ctx->pc = 0x1714B4u;
    SET_GPR_U32(ctx, 31, 0x1714BCu);
    ctx->pc = 0x1714B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1714B4u;
            // 0x1714b8: 0x8e040040  lw          $a0, 0x40($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1714BCu; }
        if (ctx->pc != 0x1714BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1714BCu; }
        if (ctx->pc != 0x1714BCu) { return; }
    }
    ctx->pc = 0x1714BCu;
label_1714bc:
    // 0x1714bc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1714bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1714c0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1714c0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1714c4: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1714c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1714c8: 0x3e00008  jr          $ra
    ctx->pc = 0x1714C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1714CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1714C8u;
            // 0x1714cc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x171490u: goto label_171490;
            case 0x1714BCu: goto label_1714bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1714D0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
