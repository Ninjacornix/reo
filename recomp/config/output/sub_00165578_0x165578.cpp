#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00165578
// Address: 0x165578 - 0x1655c0
void sub_00165578_0x165578(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00165578_0x165578");
#endif

    switch (ctx->pc) {
        case 0x16559cu: goto label_16559c;
        default: break;
    }

    ctx->pc = 0x165578u;

    // 0x165578: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x165578u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x16557c: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x16557cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x165580: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x165580u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165584: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x165584u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x165588: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x165588u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16558c: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x16558cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x165590: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x165590u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165594: 0xc059bfa  jal         func_166FE8
    ctx->pc = 0x165594u;
    SET_GPR_U32(ctx, 31, 0x16559Cu);
    ctx->pc = 0x165598u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165594u;
            // 0x165598: 0x8c851b7c  lw          $a1, 0x1B7C($a0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 7036)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166FE8u;
    if (runtime->hasFunction(0x166FE8u)) {
        auto targetFn = runtime->lookupFunction(0x166FE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16559Cu; }
        if (ctx->pc != 0x16559Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166FE8_0x166fe8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16559Cu; }
        if (ctx->pc != 0x16559Cu) { return; }
    }
    ctx->pc = 0x16559Cu;
label_16559c:
    // 0x16559c: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x16559cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1655a0: 0x8fa40004  lw          $a0, 0x4($sp)
    ctx->pc = 0x1655a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x1655a4: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x1655a4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x1655a8: 0xae040000  sw          $a0, 0x0($s0)
    ctx->pc = 0x1655a8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 4));
    // 0x1655ac: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x1655acu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1655b0: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x1655b0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1655b4: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1655b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1655b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1655B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1655BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1655B8u;
            // 0x1655bc: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16559Cu: goto label_16559c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1655C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
