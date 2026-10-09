#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00139C30
// Address: 0x139c30 - 0x139cc4
void sub_00139C30_0x139c30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00139C30_0x139c30");
#endif

    switch (ctx->pc) {
        case 0x139c4cu: goto label_139c4c;
        default: break;
    }

    ctx->pc = 0x139c30u;

    // 0x139c30: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x139c30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x139c34: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x139c34u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139c38: 0x14e00007  bnez        $a3, . + 4 + (0x7 << 2)
    ctx->pc = 0x139C38u;
    {
        const bool branch_taken_0x139c38 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        ctx->pc = 0x139C3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139C38u;
            // 0x139c3c: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139c38) {
            ctx->pc = 0x139C58u;
            goto label_139c58;
        }
    }
    ctx->pc = 0x139C40u;
    // 0x139c40: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x139c40u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x139c44: 0xc04e57e  jal         func_1395F8
    ctx->pc = 0x139C44u;
    SET_GPR_U32(ctx, 31, 0x139C4Cu);
    ctx->pc = 0x139C48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x139C44u;
            // 0x139c48: 0x24a5cbe8  addiu       $a1, $a1, -0x3418 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294953960));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1395F8u;
    if (runtime->hasFunction(0x1395F8u)) {
        auto targetFn = runtime->lookupFunction(0x1395F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139C4Cu; }
        if (ctx->pc != 0x139C4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001395F8_0x1395f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139C4Cu; }
        if (ctx->pc != 0x139C4Cu) { return; }
    }
    ctx->pc = 0x139C4Cu;
label_139c4c:
    // 0x139c4c: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x139C4Cu;
    {
        const bool branch_taken_0x139c4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x139C50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139C4Cu;
            // 0x139c50: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139c4c) {
            ctx->pc = 0x139CB8u;
            goto label_139cb8;
        }
    }
    ctx->pc = 0x139C54u;
    // 0x139c54: 0x0  nop
    ctx->pc = 0x139c54u;
    // NOP
label_139c58:
    // 0x139c58: 0x14c00003  bnez        $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x139C58u;
    {
        const bool branch_taken_0x139c58 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x139C5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139C58u;
            // 0x139c5c: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139c58) {
            ctx->pc = 0x139C68u;
            goto label_139c68;
        }
    }
    ctx->pc = 0x139C60u;
    // 0x139c60: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x139C60u;
    {
        const bool branch_taken_0x139c60 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x139C64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139C60u;
            // 0x139c64: 0xace5000c  sw          $a1, 0xC($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 12), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139c60) {
            ctx->pc = 0x139C98u;
            goto label_139c98;
        }
    }
    ctx->pc = 0x139C68u;
label_139c68:
    // 0x139c68: 0x14c20005  bne         $a2, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x139C68u;
    {
        const bool branch_taken_0x139c68 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        ctx->pc = 0x139C6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139C68u;
            // 0x139c6c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139c68) {
            ctx->pc = 0x139C80u;
            goto label_139c80;
        }
    }
    ctx->pc = 0x139C70u;
    // 0x139c70: 0x8ce40008  lw          $a0, 0x8($a3)
    ctx->pc = 0x139c70u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 8)));
    // 0x139c74: 0x851021  addu        $v0, $a0, $a1
    ctx->pc = 0x139c74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x139c78: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x139C78u;
    {
        const bool branch_taken_0x139c78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x139C7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139C78u;
            // 0x139c7c: 0xace2000c  sw          $v0, 0xC($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 12), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139c78) {
            ctx->pc = 0x139C9Cu;
            goto label_139c9c;
        }
    }
    ctx->pc = 0x139C80u;
label_139c80:
    // 0x139c80: 0x14c20006  bne         $a2, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x139C80u;
    {
        const bool branch_taken_0x139c80 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        ctx->pc = 0x139C84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139C80u;
            // 0x139c84: 0x8ce40008  lw          $a0, 0x8($a3) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139c80) {
            ctx->pc = 0x139C9Cu;
            goto label_139c9c;
        }
    }
    ctx->pc = 0x139C88u;
    // 0x139c88: 0x8ce2000c  lw          $v0, 0xC($a3)
    ctx->pc = 0x139c88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 12)));
    // 0x139c8c: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x139c8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x139c90: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x139C90u;
    {
        const bool branch_taken_0x139c90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x139C94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139C90u;
            // 0x139c94: 0xace2000c  sw          $v0, 0xC($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 12), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139c90) {
            ctx->pc = 0x139C9Cu;
            goto label_139c9c;
        }
    }
    ctx->pc = 0x139C98u;
label_139c98:
    // 0x139c98: 0x8ce40008  lw          $a0, 0x8($a3)
    ctx->pc = 0x139c98u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 8)));
label_139c9c:
    // 0x139c9c: 0x8ce2000c  lw          $v0, 0xC($a3)
    ctx->pc = 0x139c9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 12)));
    // 0x139ca0: 0xace00014  sw          $zero, 0x14($a3)
    ctx->pc = 0x139ca0u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 20), GPR_U32(ctx, 0));
    // 0x139ca4: 0x44182a  slt         $v1, $v0, $a0
    ctx->pc = 0x139ca4u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x139ca8: 0x83100a  movz        $v0, $a0, $v1
    ctx->pc = 0x139ca8u;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 4));
    // 0x139cac: 0x28440000  slti        $a0, $v0, 0x0
    ctx->pc = 0x139cacu;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x139cb0: 0x4100b  movn        $v0, $zero, $a0
    ctx->pc = 0x139cb0u;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 0));
    // 0x139cb4: 0xace2000c  sw          $v0, 0xC($a3)
    ctx->pc = 0x139cb4u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 12), GPR_U32(ctx, 2));
label_139cb8:
    // 0x139cb8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x139cb8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x139cbc: 0x3e00008  jr          $ra
    ctx->pc = 0x139CBCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x139CC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139CBCu;
            // 0x139cc0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x139C4Cu: goto label_139c4c;
            case 0x139C58u: goto label_139c58;
            case 0x139C68u: goto label_139c68;
            case 0x139C80u: goto label_139c80;
            case 0x139C98u: goto label_139c98;
            case 0x139C9Cu: goto label_139c9c;
            case 0x139CB8u: goto label_139cb8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x139CC4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
