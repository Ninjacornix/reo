#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00115890
// Address: 0x115890 - 0x1158c8
void sub_00115890_0x115890(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00115890_0x115890");
#endif

    switch (ctx->pc) {
        case 0x1158b8u: goto label_1158b8;
        default: break;
    }

    ctx->pc = 0x115890u;

    // 0x115890: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x115890u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x115894: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x115894u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115898: 0x30c6ffff  andi        $a2, $a2, 0xFFFF
    ctx->pc = 0x115898u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)65535);
    // 0x11589c: 0xafa40000  sw          $a0, 0x0($sp)
    ctx->pc = 0x11589cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 4));
    // 0x1158a0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1158a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1158a4: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x1158a4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1158a8: 0xafa20004  sw          $v0, 0x4($sp)
    ctx->pc = 0x1158a8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
    // 0x1158ac: 0x2404fffb  addiu       $a0, $zero, -0x5
    ctx->pc = 0x1158acu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967291));
    // 0x1158b0: 0xc045294  jal         func_114A50
    ctx->pc = 0x1158B0u;
    SET_GPR_U32(ctx, 31, 0x1158B8u);
    ctx->pc = 0x1158B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1158B0u;
            // 0x1158b4: 0xafa60008  sw          $a2, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114A50u;
    if (runtime->hasFunction(0x114A50u)) {
        auto targetFn = runtime->lookupFunction(0x114A50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1158B8u; }
        if (ctx->pc != 0x1158B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114A50_0x114a50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1158B8u; }
        if (ctx->pc != 0x1158B8u) { return; }
    }
    ctx->pc = 0x1158B8u;
label_1158b8:
    // 0x1158b8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1158b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1158bc: 0x3e00008  jr          $ra
    ctx->pc = 0x1158BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1158C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1158BCu;
            // 0x1158c0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1158B8u: goto label_1158b8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1158C4u;
    // 0x1158c4: 0x0  nop
    ctx->pc = 0x1158c4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
