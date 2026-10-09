#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C10C0
// Address: 0x1c10c0 - 0x1c1130
void sub_001C10C0_0x1c10c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C10C0_0x1c10c0");
#endif

    switch (ctx->pc) {
        case 0x1c1118u: goto label_1c1118;
        default: break;
    }

    ctx->pc = 0x1c10c0u;

    // 0x1c10c0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c10c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c10c4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c10c4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c10c8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c10c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c10cc: 0x24020009  addiu       $v0, $zero, 0x9
    ctx->pc = 0x1c10ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1c10d0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c10d0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c10d4: 0xac206c50  sw          $zero, 0x6C50($at)
    ctx->pc = 0x1c10d4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27728), GPR_U32(ctx, 0));
    // 0x1c10d8: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x1c10d8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c10dc: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c10dcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c10e0: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x1c10e0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c10e4: 0xac206c54  sw          $zero, 0x6C54($at)
    ctx->pc = 0x1c10e4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27732), GPR_U32(ctx, 0));
    // 0x1c10e8: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1c10e8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1c10ec: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c10ecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c10f0: 0x24a50638  addiu       $a1, $a1, 0x638
    ctx->pc = 0x1c10f0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1592));
    // 0x1c10f4: 0xac246c64  sw          $a0, 0x6C64($at)
    ctx->pc = 0x1c10f4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27748), GPR_U32(ctx, 4));
    // 0x1c10f8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c10f8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c10fc: 0x3c040032  lui         $a0, 0x32
    ctx->pc = 0x1c10fcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)50 << 16));
    // 0x1c1100: 0xac226ce8  sw          $v0, 0x6CE8($at)
    ctx->pc = 0x1c1100u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27880), GPR_U32(ctx, 2));
    // 0x1c1104: 0x24846c94  addiu       $a0, $a0, 0x6C94
    ctx->pc = 0x1c1104u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 27796));
    // 0x1c1108: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1c1108u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1c110c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c110cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c1110: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1C1110u;
    SET_GPR_U32(ctx, 31, 0x1C1118u);
    ctx->pc = 0x1C1114u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1110u;
            // 0x1c1114: 0xac226c74  sw          $v0, 0x6C74($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 27764), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1118u; }
        if (ctx->pc != 0x1C1118u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1118u; }
        if (ctx->pc != 0x1C1118u) { return; }
    }
    ctx->pc = 0x1C1118u;
label_1c1118:
    // 0x1c1118: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c1118u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c111c: 0xac306cec  sw          $s0, 0x6CEC($at)
    ctx->pc = 0x1c111cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27884), GPR_U32(ctx, 16));
    // 0x1c1120: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c1120u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c1124: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c1124u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c1128: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1128u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C112Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1128u;
            // 0x1c112c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C1118u: goto label_1c1118;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C1130u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
