#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00138DE8
// Address: 0x138de8 - 0x138e58
void sub_00138DE8_0x138de8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00138DE8_0x138de8");
#endif

    switch (ctx->pc) {
        case 0x138e40u: goto label_138e40;
        default: break;
    }

    ctx->pc = 0x138de8u;

    // 0x138de8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x138de8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x138dec: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x138decu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x138df0: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x138df0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x138df4: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x138df4u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x138df8: 0x244223c0  addiu       $v0, $v0, 0x23C0
    ctx->pc = 0x138df8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 9152));
    // 0x138dfc: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x138dfcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x138e00: 0x261024c0  addiu       $s0, $s0, 0x24C0
    ctx->pc = 0x138e00u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 9408));
    // 0x138e04: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x138e04u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x138e08: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x138e08u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x138e0c: 0x2464c870  addiu       $a0, $v1, -0x3790
    ctx->pc = 0x138e0cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 4294953072));
    // 0x138e10: 0xac450004  sw          $a1, 0x4($v0)
    ctx->pc = 0x138e10u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 5));
    // 0x138e14: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x138e14u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x138e18: 0xac460008  sw          $a2, 0x8($v0)
    ctx->pc = 0x138e18u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 6));
    // 0x138e1c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x138e1cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138e20: 0xac47000c  sw          $a3, 0xC($v0)
    ctx->pc = 0x138e20u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 7));
    // 0x138e24: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x138e24u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138e28: 0x200482d  daddu       $t1, $s0, $zero
    ctx->pc = 0x138e28u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138e2c: 0x24080010  addiu       $t0, $zero, 0x10
    ctx->pc = 0x138e2cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x138e30: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x138e30u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x138e34: 0x582d  daddu       $t3, $zero, $zero
    ctx->pc = 0x138e34u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138e38: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x138E38u;
    SET_GPR_U32(ctx, 31, 0x138E40u);
    ctx->pc = 0x138E3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138E38u;
            // 0x138e3c: 0xafa00000  sw          $zero, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138E40u; }
        if (ctx->pc != 0x138E40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138E40u; }
        if (ctx->pc != 0x138E40u) { return; }
    }
    ctx->pc = 0x138E40u;
label_138e40:
    // 0x138e40: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x138e40u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x138e44: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x138e44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x138e48: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x138e48u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x138e4c: 0x3e00008  jr          $ra
    ctx->pc = 0x138E4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138E50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138E4Cu;
            // 0x138e50: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138E40u: goto label_138e40;
            default: break;
        }
        return;
    }
    ctx->pc = 0x138E54u;
    // 0x138e54: 0x0  nop
    ctx->pc = 0x138e54u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
