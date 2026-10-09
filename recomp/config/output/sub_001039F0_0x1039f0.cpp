#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001039F0
// Address: 0x1039f0 - 0x103a48
void sub_001039F0_0x1039f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001039F0_0x1039f0");
#endif

    switch (ctx->pc) {
        case 0x103a18u: goto label_103a18;
        default: break;
    }

    ctx->pc = 0x1039f0u;

    // 0x1039f0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1039f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1039f4: 0x3c020037  lui         $v0, 0x37
    ctx->pc = 0x1039f4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)55 << 16));
    // 0x1039f8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1039f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1039fc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1039fcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103a00: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x103a00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x103a04: 0x2451f0dc  addiu       $s1, $v0, -0xF24
    ctx->pc = 0x103a04u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963420));
    // 0x103a08: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x103a08u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103a0c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x103a0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x103a10: 0xc045342  jal         func_114D08
    ctx->pc = 0x103A10u;
    SET_GPR_U32(ctx, 31, 0x103A18u);
    ctx->pc = 0x103A14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x103A10u;
            // 0x103a14: 0xae200000  sw          $zero, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114D08u;
    if (runtime->hasFunction(0x114D08u)) {
        auto targetFn = runtime->lookupFunction(0x114D08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103A18u; }
        if (ctx->pc != 0x103A18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114D08_0x114d08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103A18u; }
        if (ctx->pc != 0x103A18u) { return; }
    }
    ctx->pc = 0x103A18u;
label_103a18:
    // 0x103a18: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x103a18u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103a1c: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x103a1cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x103a20: 0x54830005  bnel        $a0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x103A20u;
    {
        const bool branch_taken_0x103a20 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        if (branch_taken_0x103a20) {
            ctx->pc = 0x103A24u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x103A20u;
            // 0x103a24: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x103A38u;
            goto label_103a38;
        }
    }
    ctx->pc = 0x103A28u;
    // 0x103a28: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x103a28u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x103a2c: 0x54600001  bnel        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x103A2Cu;
    {
        const bool branch_taken_0x103a2c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x103a2c) {
            ctx->pc = 0x103A30u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x103A2Cu;
            // 0x103a30: 0xae030000  sw          $v1, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
            ctx->pc = 0x103A34u;
            goto label_103a34;
        }
    }
    ctx->pc = 0x103A34u;
label_103a34:
    // 0x103a34: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x103a34u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_103a38:
    // 0x103a38: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x103a38u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x103a3c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x103a3cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x103a40: 0x3e00008  jr          $ra
    ctx->pc = 0x103A40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x103A44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103A40u;
            // 0x103a44: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x103A18u: goto label_103a18;
            case 0x103A34u: goto label_103a34;
            case 0x103A38u: goto label_103a38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x103A48u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
