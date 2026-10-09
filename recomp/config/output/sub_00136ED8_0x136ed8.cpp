#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00136ED8
// Address: 0x136ed8 - 0x136f98
void sub_00136ED8_0x136ed8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00136ED8_0x136ed8");
#endif

    switch (ctx->pc) {
        case 0x136efcu: goto label_136efc;
        case 0x136f1cu: goto label_136f1c;
        case 0x136f30u: goto label_136f30;
        case 0x136f50u: goto label_136f50;
        case 0x136f60u: goto label_136f60;
        case 0x136f84u: goto label_136f84;
        default: break;
    }

    ctx->pc = 0x136ed8u;

    // 0x136ed8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x136ed8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x136edc: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x136edcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x136ee0: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x136ee0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136ee4: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x136ee4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x136ee8: 0x14800007  bnez        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x136EE8u;
    {
        const bool branch_taken_0x136ee8 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x136EECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136EE8u;
            // 0x136eec: 0xffbf0030  sd          $ra, 0x30($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136ee8) {
            ctx->pc = 0x136F08u;
            goto label_136f08;
        }
    }
    ctx->pc = 0x136EF0u;
    // 0x136ef0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136ef0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136ef4: 0xc04d480  jal         func_135200
    ctx->pc = 0x136EF4u;
    SET_GPR_U32(ctx, 31, 0x136EFCu);
    ctx->pc = 0x136EF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136EF4u;
            // 0x136ef8: 0x2484c360  addiu       $a0, $a0, -0x3CA0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951776));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136EFCu; }
        if (ctx->pc != 0x136EFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136EFCu; }
        if (ctx->pc != 0x136EFCu) { return; }
    }
    ctx->pc = 0x136EFCu;
label_136efc:
    // 0x136efc: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x136EFCu;
    {
        const bool branch_taken_0x136efc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136F00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136EFCu;
            // 0x136f00: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136efc) {
            ctx->pc = 0x136F88u;
            goto label_136f88;
        }
    }
    ctx->pc = 0x136F04u;
    // 0x136f04: 0x0  nop
    ctx->pc = 0x136f04u;
    // NOP
label_136f08:
    // 0x136f08: 0x16000007  bnez        $s0, . + 4 + (0x7 << 2)
    ctx->pc = 0x136F08u;
    {
        const bool branch_taken_0x136f08 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x136f08) {
            ctx->pc = 0x136F28u;
            goto label_136f28;
        }
    }
    ctx->pc = 0x136F10u;
    // 0x136f10: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136f10u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136f14: 0xc04d480  jal         func_135200
    ctx->pc = 0x136F14u;
    SET_GPR_U32(ctx, 31, 0x136F1Cu);
    ctx->pc = 0x136F18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136F14u;
            // 0x136f18: 0x2484c388  addiu       $a0, $a0, -0x3C78 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951816));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136F1Cu; }
        if (ctx->pc != 0x136F1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136F1Cu; }
        if (ctx->pc != 0x136F1Cu) { return; }
    }
    ctx->pc = 0x136F1Cu;
label_136f1c:
    // 0x136f1c: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x136F1Cu;
    {
        const bool branch_taken_0x136f1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136F20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136F1Cu;
            // 0x136f20: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136f1c) {
            ctx->pc = 0x136F88u;
            goto label_136f88;
        }
    }
    ctx->pc = 0x136F24u;
    // 0x136f24: 0x0  nop
    ctx->pc = 0x136f24u;
    // NOP
label_136f28:
    // 0x136f28: 0xc04d558  jal         func_135560
    ctx->pc = 0x136F28u;
    SET_GPR_U32(ctx, 31, 0x136F30u);
    ctx->pc = 0x135560u;
    if (runtime->hasFunction(0x135560u)) {
        auto targetFn = runtime->lookupFunction(0x135560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136F30u; }
        if (ctx->pc != 0x136F30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135560_0x135560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136F30u; }
        if (ctx->pc != 0x136F30u) { return; }
    }
    ctx->pc = 0x136F30u;
label_136f30:
    // 0x136f30: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x136f30u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136f34: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x136f34u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136f38: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x136f38u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136f3c: 0x16200006  bnez        $s1, . + 4 + (0x6 << 2)
    ctx->pc = 0x136F3Cu;
    {
        const bool branch_taken_0x136f3c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x136F40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136F3Cu;
            // 0x136f40: 0x24060014  addiu       $a2, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136f3c) {
            ctx->pc = 0x136F58u;
            goto label_136f58;
        }
    }
    ctx->pc = 0x136F44u;
    // 0x136f44: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136f44u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136f48: 0xc04d480  jal         func_135200
    ctx->pc = 0x136F48u;
    SET_GPR_U32(ctx, 31, 0x136F50u);
    ctx->pc = 0x136F4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136F48u;
            // 0x136f4c: 0x2484c3b0  addiu       $a0, $a0, -0x3C50 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951856));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136F50u; }
        if (ctx->pc != 0x136F50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136F50u; }
        if (ctx->pc != 0x136F50u) { return; }
    }
    ctx->pc = 0x136F50u;
label_136f50:
    // 0x136f50: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x136F50u;
    {
        const bool branch_taken_0x136f50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136F54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136F50u;
            // 0x136f54: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136f50) {
            ctx->pc = 0x136F88u;
            goto label_136f88;
        }
    }
    ctx->pc = 0x136F58u;
label_136f58:
    // 0x136f58: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x136F58u;
    SET_GPR_U32(ctx, 31, 0x136F60u);
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136F60u; }
        if (ctx->pc != 0x136F60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136F60u; }
        if (ctx->pc != 0x136F60u) { return; }
    }
    ctx->pc = 0x136F60u;
label_136f60:
    // 0x136f60: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x136f60u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x136f64: 0xafb00004  sw          $s0, 0x4($sp)
    ctx->pc = 0x136f64u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 16));
    // 0x136f68: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x136f68u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136f6c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x136f6cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136f70: 0x8e220060  lw          $v0, 0x60($s1)
    ctx->pc = 0x136f70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 96)));
    // 0x136f74: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x136F74u;
    {
        const bool branch_taken_0x136f74 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x136F78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136F74u;
            // 0x136f78: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136f74) {
            ctx->pc = 0x136F84u;
            goto label_136f84;
        }
    }
    ctx->pc = 0x136F7Cu;
    // 0x136f7c: 0x40f809  jalr        $v0
    ctx->pc = 0x136F7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x136F84u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x136F84u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136EFCu: goto label_136efc;
            case 0x136F08u: goto label_136f08;
            case 0x136F1Cu: goto label_136f1c;
            case 0x136F28u: goto label_136f28;
            case 0x136F30u: goto label_136f30;
            case 0x136F50u: goto label_136f50;
            case 0x136F58u: goto label_136f58;
            case 0x136F60u: goto label_136f60;
            case 0x136F84u: goto label_136f84;
            case 0x136F88u: goto label_136f88;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136F84u; }
            if (ctx->pc != 0x136F84u) { return; }
        }
        }
    }
    ctx->pc = 0x136F84u;
label_136f84:
    // 0x136f84: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x136f84u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_136f88:
    // 0x136f88: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x136f88u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x136f8c: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x136f8cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x136f90: 0x3e00008  jr          $ra
    ctx->pc = 0x136F90u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136F94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136F90u;
            // 0x136f94: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136EFCu: goto label_136efc;
            case 0x136F08u: goto label_136f08;
            case 0x136F1Cu: goto label_136f1c;
            case 0x136F28u: goto label_136f28;
            case 0x136F30u: goto label_136f30;
            case 0x136F50u: goto label_136f50;
            case 0x136F58u: goto label_136f58;
            case 0x136F60u: goto label_136f60;
            case 0x136F84u: goto label_136f84;
            case 0x136F88u: goto label_136f88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136F98u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
