#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00112708
// Address: 0x112708 - 0x112770
void sub_00112708_0x112708(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00112708_0x112708");
#endif

    ctx->pc = 0x112708u;

    // 0x112708: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x112708u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x11270c: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x11270cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x112710: 0x34423c10  ori         $v0, $v0, 0x3C10
    ctx->pc = 0x112710u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)15376);
    // 0x112714: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x112714u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x112718: 0xac470000  sw          $a3, 0x0($v0)
    ctx->pc = 0x112718u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 7)); // MMIO: 0x10000000
    // 0x11271c: 0x34633c20  ori         $v1, $v1, 0x3C20
    ctx->pc = 0x11271cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)15392);
    // 0x112720: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x112720u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x112724: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x112724u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x112728: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x112728u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2)); // MMIO: 0x10000000
    // 0x11272c: 0xf  sync
    ctx->pc = 0x11272cu;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x112730: 0x4844e000  cfc2.ni     $a0, $vi28
    ctx->pc = 0x112730u;
    SET_GPR_U32(ctx, 4, ctx->vu0_itop);
    // 0x112734: 0x34840200  ori         $a0, $a0, 0x200
    ctx->pc = 0x112734u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)512);
    // 0x112738: 0x48c4e000  ctc2.ni     $a0, $vi28
    ctx->pc = 0x112738u;
    ctx->vu0_itop = GPR_U32(ctx, 4) & 0x3FF;
    // 0x11273c: 0x40f  sync.p
    ctx->pc = 0x11273cu;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x112740: 0x3c050021  lui         $a1, 0x21
    ctx->pc = 0x112740u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)33 << 16));
    // 0x112744: 0x3c061000  lui         $a2, 0x1000
    ctx->pc = 0x112744u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)4096 << 16));
    // 0x112748: 0x24a59c80  addiu       $a1, $a1, -0x6380
    ctx->pc = 0x112748u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294941824));
    // 0x11274c: 0x34c65000  ori         $a2, $a2, 0x5000
    ctx->pc = 0x11274cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)20480);
    // 0x112750: 0x78a40000  lq          $a0, 0x0($a1)
    ctx->pc = 0x112750u;
    SET_GPR_VEC(ctx, 4, READ128(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x112754: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x112754u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x112758: 0x34633000  ori         $v1, $v1, 0x3000
    ctx->pc = 0x112758u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)12288);
    // 0x11275c: 0x7cc40000  sq          $a0, 0x0($a2)
    ctx->pc = 0x11275cu;
    WRITE128(ADD32(GPR_U32(ctx, 6), 0), GPR_VEC(ctx, 4));
    // 0x112760: 0x78a20010  lq          $v0, 0x10($a1)
    ctx->pc = 0x112760u;
    SET_GPR_VEC(ctx, 2, READ128(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x112764: 0x7cc20000  sq          $v0, 0x0($a2)
    ctx->pc = 0x112764u;
    WRITE128(ADD32(GPR_U32(ctx, 6), 0), GPR_VEC(ctx, 2));
    // 0x112768: 0x3e00008  jr          $ra
    ctx->pc = 0x112768u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11276Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112768u;
            // 0x11276c: 0xac670000  sw          $a3, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 7));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x112770u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
