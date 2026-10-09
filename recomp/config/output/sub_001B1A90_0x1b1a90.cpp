#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B1A90
// Address: 0x1b1a90 - 0x1b1b40
void sub_001B1A90_0x1b1a90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B1A90_0x1b1a90");
#endif

    switch (ctx->pc) {
        case 0x1b1ab0u: goto label_1b1ab0;
        case 0x1b1b00u: goto label_1b1b00;
        default: break;
    }

    ctx->pc = 0x1b1a90u;

    // 0x1b1a90: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1b1a90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1b1a94: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1b1a94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1b1a98: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b1a98u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b1a9c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b1a9cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b1aa0: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1b1aa0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b1aa4: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b1aa4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b1aa8: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1B1AA8u;
    {
        const bool branch_taken_0x1b1aa8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B1AACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1AA8u;
            // 0x1b1aac: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b1aa8) {
            ctx->pc = 0x1B1B08u;
            goto label_1b1b08;
        }
    }
    ctx->pc = 0x1B1AB0u;
label_1b1ab0:
    // 0x1b1ab0: 0x111040  sll         $v0, $s1, 1
    ctx->pc = 0x1b1ab0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 1));
    // 0x1b1ab4: 0x3c03004f  lui         $v1, 0x4F
    ctx->pc = 0x1b1ab4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)79 << 16));
    // 0x1b1ab8: 0x2423821  addu        $a3, $s2, $v0
    ctx->pc = 0x1b1ab8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
    // 0x1b1abc: 0x2463c910  addiu       $v1, $v1, -0x36F0
    ctx->pc = 0x1b1abcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294953232));
    // 0x1b1ac0: 0x94e40008  lhu         $a0, 0x8($a3)
    ctx->pc = 0x1b1ac0u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 8)));
    // 0x1b1ac4: 0x3c02004f  lui         $v0, 0x4F
    ctx->pc = 0x1b1ac4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)79 << 16));
    // 0x1b1ac8: 0x2442dd90  addiu       $v0, $v0, -0x2270
    ctx->pc = 0x1b1ac8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294958480));
    // 0x1b1acc: 0x24f00008  addiu       $s0, $a3, 0x8
    ctx->pc = 0x1b1accu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 7), 8));
    // 0x1b1ad0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b1ad0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b1ad4: 0x2406004c  addiu       $a2, $zero, 0x4C
    ctx->pc = 0x1b1ad4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 76));
    // 0x1b1ad8: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1b1ad8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1b1adc: 0xa0600000  sb          $zero, 0x0($v1)
    ctx->pc = 0x1b1adcu;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1b1ae0: 0x94e40008  lhu         $a0, 0x8($a3)
    ctx->pc = 0x1b1ae0u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 8)));
    // 0x1b1ae4: 0x418c0  sll         $v1, $a0, 3
    ctx->pc = 0x1b1ae4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x1b1ae8: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1b1ae8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1b1aec: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x1b1aecu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1b1af0: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1b1af0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1b1af4: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1b1af4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1b1af8: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1B1AF8u;
    SET_GPR_U32(ctx, 31, 0x1B1B00u);
    ctx->pc = 0x1B1AFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1AF8u;
            // 0x1b1afc: 0x432021  addu        $a0, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1B00u; }
        if (ctx->pc != 0x1B1B00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1B00u; }
        if (ctx->pc != 0x1B1B00u) { return; }
    }
    ctx->pc = 0x1B1B00u;
label_1b1b00:
    // 0x1b1b00: 0xa6000000  sh          $zero, 0x0($s0)
    ctx->pc = 0x1b1b00u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1b1b04: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1b1b04u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
label_1b1b08:
    // 0x1b1b08: 0x96430814  lhu         $v1, 0x814($s2)
    ctx->pc = 0x1b1b08u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 2068)));
    // 0x1b1b0c: 0x223182a  slt         $v1, $s1, $v1
    ctx->pc = 0x1b1b0cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1b1b10: 0x1460ffe7  bnez        $v1, . + 4 + (-0x19 << 2)
    ctx->pc = 0x1B1B10u;
    {
        const bool branch_taken_0x1b1b10 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b1b10) {
            ctx->pc = 0x1B1AB0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b1ab0;
        }
    }
    ctx->pc = 0x1B1B18u;
    // 0x1b1b18: 0xa6400814  sh          $zero, 0x814($s2)
    ctx->pc = 0x1b1b18u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 2068), (uint16_t)GPR_U32(ctx, 0));
    // 0x1b1b1c: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1b1b1cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b1b20: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b1b20u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b1b24: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b1b24u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b1b28: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b1b28u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b1b2c: 0x3e00008  jr          $ra
    ctx->pc = 0x1B1B2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B1B30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1B2Cu;
            // 0x1b1b30: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B1AB0u: goto label_1b1ab0;
            case 0x1B1B00u: goto label_1b1b00;
            case 0x1B1B08u: goto label_1b1b08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B1B34u;
    // 0x1b1b34: 0x0  nop
    ctx->pc = 0x1b1b34u;
    // NOP
    // 0x1b1b38: 0x0  nop
    ctx->pc = 0x1b1b38u;
    // NOP
    // 0x1b1b3c: 0x0  nop
    ctx->pc = 0x1b1b3cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
