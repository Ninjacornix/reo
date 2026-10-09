#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F4B90
// Address: 0x1f4b90 - 0x1f4c20
void sub_001F4B90_0x1f4b90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F4B90_0x1f4b90");
#endif

    switch (ctx->pc) {
        case 0x1f4bf0u: goto label_1f4bf0;
        default: break;
    }

    ctx->pc = 0x1f4b90u;

    // 0x1f4b90: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1f4b90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1f4b94: 0x30a7ffff  andi        $a3, $a1, 0xFFFF
    ctx->pc = 0x1f4b94u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
    // 0x1f4b98: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1f4b98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1f4b9c: 0x71200  sll         $v0, $a3, 8
    ctx->pc = 0x1f4b9cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1f4ba0: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1f4ba0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1f4ba4: 0x3043ff00  andi        $v1, $v0, 0xFF00
    ctx->pc = 0x1f4ba4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1f4ba8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f4ba8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f4bac: 0x71203  sra         $v0, $a3, 8
    ctx->pc = 0x1f4bacu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 7), 8));
    // 0x1f4bb0: 0x8c860020  lw          $a2, 0x20($a0)
    ctx->pc = 0x1f4bb0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 32)));
    // 0x1f4bb4: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1f4bb4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1f4bb8: 0x8c85002c  lw          $a1, 0x2C($a0)
    ctx->pc = 0x1f4bb8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 44)));
    // 0x1f4bbc: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1f4bbcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1f4bc0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1f4bc0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4bc4: 0xa7a2003e  sh          $v0, 0x3E($sp)
    ctx->pc = 0x1f4bc4u;
    WRITE16(ADD32(GPR_U32(ctx, 29), 62), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f4bc8: 0x8c83002c  lw          $v1, 0x2C($a0)
    ctx->pc = 0x1f4bc8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 44)));
    // 0x1f4bcc: 0x8c820014  lw          $v0, 0x14($a0)
    ctx->pc = 0x1f4bccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x1f4bd0: 0x24630002  addiu       $v1, $v1, 0x2
    ctx->pc = 0x1f4bd0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2));
    // 0x1f4bd4: 0x43082b  sltu        $at, $v0, $v1
    ctx->pc = 0x1f4bd4u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1f4bd8: 0x14200008  bnez        $at, . + 4 + (0x8 << 2)
    ctx->pc = 0x1F4BD8u;
    {
        const bool branch_taken_0x1f4bd8 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F4BDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4BD8u;
            // 0x1f4bdc: 0xc58021  addu        $s0, $a2, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4bd8) {
            ctx->pc = 0x1F4BFCu;
            goto label_1f4bfc;
        }
    }
    ctx->pc = 0x1F4BE0u;
    // 0x1f4be0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1f4be0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4be4: 0x27a5003e  addiu       $a1, $sp, 0x3E
    ctx->pc = 0x1f4be4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 62));
    // 0x1f4be8: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F4BE8u;
    SET_GPR_U32(ctx, 31, 0x1F4BF0u);
    ctx->pc = 0x1F4BECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4BE8u;
            // 0x1f4bec: 0x24060002  addiu       $a2, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4BF0u; }
        if (ctx->pc != 0x1F4BF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4BF0u; }
        if (ctx->pc != 0x1F4BF0u) { return; }
    }
    ctx->pc = 0x1F4BF0u;
label_1f4bf0:
    // 0x1f4bf0: 0x8e22002c  lw          $v0, 0x2C($s1)
    ctx->pc = 0x1f4bf0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 44)));
    // 0x1f4bf4: 0x24420002  addiu       $v0, $v0, 0x2
    ctx->pc = 0x1f4bf4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2));
    // 0x1f4bf8: 0xae22002c  sw          $v0, 0x2C($s1)
    ctx->pc = 0x1f4bf8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 44), GPR_U32(ctx, 2));
label_1f4bfc:
    // 0x1f4bfc: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1f4bfcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4c00: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1f4c00u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1f4c04: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1f4c04u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f4c08: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f4c08u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f4c0c: 0x3e00008  jr          $ra
    ctx->pc = 0x1F4C0Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F4C10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4C0Cu;
            // 0x1f4c10: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F4BF0u: goto label_1f4bf0;
            case 0x1F4BFCu: goto label_1f4bfc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F4C14u;
    // 0x1f4c14: 0x0  nop
    ctx->pc = 0x1f4c14u;
    // NOP
    // 0x1f4c18: 0x0  nop
    ctx->pc = 0x1f4c18u;
    // NOP
    // 0x1f4c1c: 0x0  nop
    ctx->pc = 0x1f4c1cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
