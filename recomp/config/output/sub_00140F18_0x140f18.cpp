#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00140F18
// Address: 0x140f18 - 0x140fb4
void sub_00140F18_0x140f18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00140F18_0x140f18");
#endif

    switch (ctx->pc) {
        case 0x140f30u: goto label_140f30;
        case 0x140f58u: goto label_140f58;
        case 0x140f68u: goto label_140f68;
        case 0x140f94u: goto label_140f94;
        default: break;
    }

    ctx->pc = 0x140f18u;

    // 0x140f18: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x140f18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x140f1c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x140f1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x140f20: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x140f20u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140f24: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x140f24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x140f28: 0x16000009  bnez        $s0, . + 4 + (0x9 << 2)
    ctx->pc = 0x140F28u;
    {
        const bool branch_taken_0x140f28 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x140F2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140F28u;
            // 0x140f2c: 0xffbf0010  sd          $ra, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140f28) {
            ctx->pc = 0x140F50u;
            goto label_140f50;
        }
    }
    ctx->pc = 0x140F30u;
label_140f30:
    // 0x140f30: 0x0  nop
    ctx->pc = 0x140f30u;
    // NOP
    // 0x140f34: 0x0  nop
    ctx->pc = 0x140f34u;
    // NOP
    // 0x140f38: 0x0  nop
    ctx->pc = 0x140f38u;
    // NOP
    // 0x140f3c: 0x0  nop
    ctx->pc = 0x140f3cu;
    // NOP
    // 0x140f40: 0x0  nop
    ctx->pc = 0x140f40u;
    // NOP
    // 0x140f44: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x140F44u;
    {
        const bool branch_taken_0x140f44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x140f44) {
            ctx->pc = 0x140F30u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_140f30;
        }
    }
    ctx->pc = 0x140F4Cu;
    // 0x140f4c: 0x0  nop
    ctx->pc = 0x140f4cu;
    // NOP
label_140f50:
    // 0x140f50: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x140F50u;
    SET_GPR_U32(ctx, 31, 0x140F58u);
    ctx->pc = 0x140F54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x140F50u;
            // 0x140f54: 0x8e110000  lw          $s1, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140F58u; }
        if (ctx->pc != 0x140F58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140F58u; }
        if (ctx->pc != 0x140F58u) { return; }
    }
    ctx->pc = 0x140F58u;
label_140f58:
    // 0x140f58: 0x5a200012  blezl       $s1, . + 4 + (0x12 << 2)
    ctx->pc = 0x140F58u;
    {
        const bool branch_taken_0x140f58 = (GPR_S64(ctx, 17) <= 0);
        if (branch_taken_0x140f58) {
            ctx->pc = 0x140F5Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x140F58u;
            // 0x140f5c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x140FA4u;
            goto label_140fa4;
        }
    }
    ctx->pc = 0x140F60u;
    // 0x140f60: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x140f60u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140f64: 0x0  nop
    ctx->pc = 0x140f64u;
    // NOP
label_140f68:
    // 0x140f68: 0x24b00010  addiu       $s0, $a1, 0x10
    ctx->pc = 0x140f68u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), 16));
    // 0x140f6c: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x140f6cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x140f70: 0x54400009  bnel        $v0, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x140F70u;
    {
        const bool branch_taken_0x140f70 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x140f70) {
            ctx->pc = 0x140F74u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x140F70u;
            // 0x140f74: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x140F98u;
            goto label_140f98;
        }
    }
    ctx->pc = 0x140F78u;
    // 0x140f78: 0x8ca20014  lw          $v0, 0x14($a1)
    ctx->pc = 0x140f78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 20)));
    // 0x140f7c: 0x24a60018  addiu       $a2, $a1, 0x18
    ctx->pc = 0x140f7cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 5), 24));
    // 0x140f80: 0x8c440004  lw          $a0, 0x4($v0)
    ctx->pc = 0x140f80u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x140f84: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x140f84u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x140f88: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x140f88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x140f8c: 0x40f809  jalr        $v0
    ctx->pc = 0x140F8Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x140F94u);
        ctx->pc = 0x140F90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140F8Cu;
            // 0x140f90: 0x80a50011  lb          $a1, 0x11($a1) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 17)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x140F94u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140F30u: goto label_140f30;
            case 0x140F50u: goto label_140f50;
            case 0x140F58u: goto label_140f58;
            case 0x140F68u: goto label_140f68;
            case 0x140F94u: goto label_140f94;
            case 0x140F98u: goto label_140f98;
            case 0x140FA4u: goto label_140fa4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x140F94u; }
            if (ctx->pc != 0x140F94u) { return; }
        }
        }
    }
    ctx->pc = 0x140F94u;
label_140f94:
    // 0x140f94: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x140f94u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_140f98:
    // 0x140f98: 0x1620fff3  bnez        $s1, . + 4 + (-0xD << 2)
    ctx->pc = 0x140F98u;
    {
        const bool branch_taken_0x140f98 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x140F9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140F98u;
            // 0x140f9c: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140f98) {
            ctx->pc = 0x140F68u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_140f68;
        }
    }
    ctx->pc = 0x140FA0u;
    // 0x140fa0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x140fa0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_140fa4:
    // 0x140fa4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x140fa4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x140fa8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x140fa8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x140fac: 0x804fc9c  j           func_13F270
    ctx->pc = 0x140FACu;
    ctx->pc = 0x140FB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x140FACu;
            // 0x140fb0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F270_0x13f270(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x140FB4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
