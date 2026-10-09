#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C56A0
// Address: 0x1c56a0 - 0x1c5760
void sub_001C56A0_0x1c56a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C56A0_0x1c56a0");
#endif

    switch (ctx->pc) {
        case 0x1c56b8u: goto label_1c56b8;
        case 0x1c56e8u: goto label_1c56e8;
        default: break;
    }

    ctx->pc = 0x1c56a0u;

    // 0x1c56a0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c56a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c56a4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c56a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c56a8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c56a8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c56ac: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1c56acu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c56b0: 0xc06bb20  jal         func_1AEC80
    ctx->pc = 0x1C56B0u;
    SET_GPR_U32(ctx, 31, 0x1C56B8u);
    ctx->pc = 0x1C56B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C56B0u;
            // 0x1c56b4: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AEC80u;
    if (runtime->hasFunction(0x1AEC80u)) {
        auto targetFn = runtime->lookupFunction(0x1AEC80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C56B8u; }
        if (ctx->pc != 0x1C56B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AEC80_0x1aec80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C56B8u; }
        if (ctx->pc != 0x1C56B8u) { return; }
    }
    ctx->pc = 0x1C56B8u;
label_1c56b8:
    // 0x1c56b8: 0x24035963  addiu       $v1, $zero, 0x5963
    ctx->pc = 0x1c56b8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 22883));
    // 0x1c56bc: 0x26080004  addiu       $t0, $s0, 0x4
    ctx->pc = 0x1c56bcu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x1c56c0: 0xa6030000  sh          $v1, 0x0($s0)
    ctx->pc = 0x1c56c0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1c56c4: 0x3049ffff  andi        $t1, $v0, 0xFFFF
    ctx->pc = 0x1c56c4u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1c56c8: 0xa6020002  sh          $v0, 0x2($s0)
    ctx->pc = 0x1c56c8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x1c56cc: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x1c56ccu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c56d0: 0xa6000004  sh          $zero, 0x4($s0)
    ctx->pc = 0x1c56d0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c56d4: 0xa6000006  sh          $zero, 0x6($s0)
    ctx->pc = 0x1c56d4u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c56d8: 0x26100008  addiu       $s0, $s0, 0x8
    ctx->pc = 0x1c56d8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
    // 0x1c56dc: 0x3c030001  lui         $v1, 0x1
    ctx->pc = 0x1c56dcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)1 << 16));
    // 0x1c56e0: 0x3406ff53  ori         $a2, $zero, 0xFF53
    ctx->pc = 0x1c56e0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65363);
    // 0x1c56e4: 0x3464fe5c  ori         $a0, $v1, 0xFE5C
    ctx->pc = 0x1c56e4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65116);
label_1c56e8:
    // 0x1c56e8: 0x95070000  lhu         $a3, 0x0($t0)
    ctx->pc = 0x1c56e8u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1c56ec: 0x3123ffff  andi        $v1, $t1, 0xFFFF
    ctx->pc = 0x1c56ecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 9) & (uint64_t)(uint16_t)65535);
    // 0x1c56f0: 0x96050000  lhu         $a1, 0x0($s0)
    ctx->pc = 0x1c56f0u;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1c56f4: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x1c56f4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x1c56f8: 0xa5050000  sh          $a1, 0x0($t0)
    ctx->pc = 0x1c56f8u;
    WRITE16(ADD32(GPR_U32(ctx, 8), 0), (uint16_t)GPR_U32(ctx, 5));
    // 0x1c56fc: 0x96050000  lhu         $a1, 0x0($s0)
    ctx->pc = 0x1c56fcu;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1c5700: 0xa92826  xor         $a1, $a1, $t1
    ctx->pc = 0x1c5700u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) ^ GPR_U64(ctx, 9));
    // 0x1c5704: 0xa6050000  sh          $a1, 0x0($s0)
    ctx->pc = 0x1c5704u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 5));
    // 0x1c5708: 0x14600002  bnez        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1C5708u;
    {
        const bool branch_taken_0x1c5708 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C570Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5708u;
            // 0x1c570c: 0x26100002  addiu       $s0, $s0, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5708) {
            ctx->pc = 0x1C5714u;
            goto label_1c5714;
        }
    }
    ctx->pc = 0x1C5710u;
    // 0x1c5710: 0x64090001  daddiu      $t1, $zero, 0x1
    ctx->pc = 0x1c5710u;
    SET_GPR_S64(ctx, 9, (int64_t)GPR_S64(ctx, 0) + (int64_t)(int32_t)1);
label_1c5714:
    // 0x1c5714: 0x3127ffff  andi        $a3, $t1, 0xFFFF
    ctx->pc = 0x1c5714u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 9) & (uint64_t)(uint16_t)65535);
    // 0x1c5718: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x1c5718u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x1c571c: 0x72880  sll         $a1, $a3, 2
    ctx->pc = 0x1c571cu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 7), 2));
    // 0x1c5720: 0x144182a  slt         $v1, $t2, $a0
    ctx->pc = 0x1c5720u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 10) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x1c5724: 0xa72821  addu        $a1, $a1, $a3
    ctx->pc = 0x1c5724u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 7)));
    // 0x1c5728: 0x52840  sll         $a1, $a1, 1
    ctx->pc = 0x1c5728u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x1c572c: 0xa72821  addu        $a1, $a1, $a3
    ctx->pc = 0x1c572cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 7)));
    // 0x1c5730: 0x52900  sll         $a1, $a1, 4
    ctx->pc = 0x1c5730u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 4));
    // 0x1c5734: 0xa6001a  div         $zero, $a1, $a2
    ctx->pc = 0x1c5734u;
    { int32_t divisor = GPR_S32(ctx, 6);    int32_t dividend = GPR_S32(ctx, 5);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1c5738: 0x0  nop
    ctx->pc = 0x1c5738u;
    // NOP
    // 0x1c573c: 0x0  nop
    ctx->pc = 0x1c573cu;
    // NOP
    // 0x1c5740: 0x2810  mfhi        $a1
    ctx->pc = 0x1c5740u;
    SET_GPR_U64(ctx, 5, ctx->hi);
    // 0x1c5744: 0x1460ffe8  bnez        $v1, . + 4 + (-0x18 << 2)
    ctx->pc = 0x1C5744u;
    {
        const bool branch_taken_0x1c5744 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C5748u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5744u;
            // 0x1c5748: 0x30a9ffff  andi        $t1, $a1, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 9, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5744) {
            ctx->pc = 0x1C56E8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c56e8;
        }
    }
    ctx->pc = 0x1C574Cu;
    // 0x1c574c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c574cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c5750: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c5750u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c5754: 0x3e00008  jr          $ra
    ctx->pc = 0x1C5754u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C5758u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5754u;
            // 0x1c5758: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C56B8u: goto label_1c56b8;
            case 0x1C56E8u: goto label_1c56e8;
            case 0x1C5714u: goto label_1c5714;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C575Cu;
    // 0x1c575c: 0x0  nop
    ctx->pc = 0x1c575cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
