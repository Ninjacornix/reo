#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00136E08
// Address: 0x136e08 - 0x136ed4
void sub_00136E08_0x136e08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00136E08_0x136e08");
#endif

    switch (ctx->pc) {
        case 0x136e58u: goto label_136e58;
        case 0x136e7cu: goto label_136e7c;
        case 0x136e90u: goto label_136e90;
        case 0x136ebcu: goto label_136ebc;
        default: break;
    }

    ctx->pc = 0x136e08u;

    // 0x136e08: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x136e08u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x136e0c: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x136e0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x136e10: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x136e10u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136e14: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x136e14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x136e18: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x136e18u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136e1c: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x136e1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x136e20: 0x14800005  bnez        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x136E20u;
    {
        const bool branch_taken_0x136e20 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x136E24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136E20u;
            // 0x136e24: 0xffbf0038  sd          $ra, 0x38($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136e20) {
            ctx->pc = 0x136E38u;
            goto label_136e38;
        }
    }
    ctx->pc = 0x136E28u;
    // 0x136e28: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136e28u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136e2c: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x136E2Cu;
    {
        const bool branch_taken_0x136e2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136E30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136E2Cu;
            // 0x136e30: 0x2484c2d8  addiu       $a0, $a0, -0x3D28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951640));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136e2c) {
            ctx->pc = 0x136E74u;
            goto label_136e74;
        }
    }
    ctx->pc = 0x136E34u;
    // 0x136e34: 0x0  nop
    ctx->pc = 0x136e34u;
    // NOP
label_136e38:
    // 0x136e38: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x136E38u;
    {
        const bool branch_taken_0x136e38 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x136e38) {
            ctx->pc = 0x136E50u;
            goto label_136e50;
        }
    }
    ctx->pc = 0x136E40u;
    // 0x136e40: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136e40u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136e44: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x136E44u;
    {
        const bool branch_taken_0x136e44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136E48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136E44u;
            // 0x136e48: 0x2484c308  addiu       $a0, $a0, -0x3CF8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951688));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136e44) {
            ctx->pc = 0x136E74u;
            goto label_136e74;
        }
    }
    ctx->pc = 0x136E4Cu;
    // 0x136e4c: 0x0  nop
    ctx->pc = 0x136e4cu;
    // NOP
label_136e50:
    // 0x136e50: 0xc04d558  jal         func_135560
    ctx->pc = 0x136E50u;
    SET_GPR_U32(ctx, 31, 0x136E58u);
    ctx->pc = 0x135560u;
    if (runtime->hasFunction(0x135560u)) {
        auto targetFn = runtime->lookupFunction(0x135560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136E58u; }
        if (ctx->pc != 0x136E58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135560_0x135560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136E58u; }
        if (ctx->pc != 0x136E58u) { return; }
    }
    ctx->pc = 0x136E58u;
label_136e58:
    // 0x136e58: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x136e58u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136e5c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x136e5cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136e60: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x136e60u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136e64: 0x16200008  bnez        $s1, . + 4 + (0x8 << 2)
    ctx->pc = 0x136E64u;
    {
        const bool branch_taken_0x136e64 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x136E68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136E64u;
            // 0x136e68: 0x24060014  addiu       $a2, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136e64) {
            ctx->pc = 0x136E88u;
            goto label_136e88;
        }
    }
    ctx->pc = 0x136E6Cu;
    // 0x136e6c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136e6cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136e70: 0x2484c338  addiu       $a0, $a0, -0x3CC8
    ctx->pc = 0x136e70u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951736));
label_136e74:
    // 0x136e74: 0xc04d480  jal         func_135200
    ctx->pc = 0x136E74u;
    SET_GPR_U32(ctx, 31, 0x136E7Cu);
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136E7Cu; }
        if (ctx->pc != 0x136E7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136E7Cu; }
        if (ctx->pc != 0x136E7Cu) { return; }
    }
    ctx->pc = 0x136E7Cu;
label_136e7c:
    // 0x136e7c: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x136E7Cu;
    {
        const bool branch_taken_0x136e7c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136E80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136E7Cu;
            // 0x136e80: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136e7c) {
            ctx->pc = 0x136EBCu;
            goto label_136ebc;
        }
    }
    ctx->pc = 0x136E84u;
    // 0x136e84: 0x0  nop
    ctx->pc = 0x136e84u;
    // NOP
label_136e88:
    // 0x136e88: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x136E88u;
    SET_GPR_U32(ctx, 31, 0x136E90u);
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136E90u; }
        if (ctx->pc != 0x136E90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136E90u; }
        if (ctx->pc != 0x136E90u) { return; }
    }
    ctx->pc = 0x136E90u;
label_136e90:
    // 0x136e90: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x136e90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x136e94: 0xafb00004  sw          $s0, 0x4($sp)
    ctx->pc = 0x136e94u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 16));
    // 0x136e98: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x136e98u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136e9c: 0xafb20008  sw          $s2, 0x8($sp)
    ctx->pc = 0x136e9cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 18));
    // 0x136ea0: 0x24050005  addiu       $a1, $zero, 0x5
    ctx->pc = 0x136ea0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x136ea4: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x136ea4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136ea8: 0x8e230060  lw          $v1, 0x60($s1)
    ctx->pc = 0x136ea8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 96)));
    // 0x136eac: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x136EACu;
    {
        const bool branch_taken_0x136eac = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x136EB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136EACu;
            // 0x136eb0: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136eac) {
            ctx->pc = 0x136EBCu;
            goto label_136ebc;
        }
    }
    ctx->pc = 0x136EB4u;
    // 0x136eb4: 0x60f809  jalr        $v1
    ctx->pc = 0x136EB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x136EBCu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x136EBCu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136E38u: goto label_136e38;
            case 0x136E50u: goto label_136e50;
            case 0x136E58u: goto label_136e58;
            case 0x136E74u: goto label_136e74;
            case 0x136E7Cu: goto label_136e7c;
            case 0x136E88u: goto label_136e88;
            case 0x136E90u: goto label_136e90;
            case 0x136EBCu: goto label_136ebc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136EBCu; }
            if (ctx->pc != 0x136EBCu) { return; }
        }
        }
    }
    ctx->pc = 0x136EBCu;
label_136ebc:
    // 0x136ebc: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x136ebcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x136ec0: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x136ec0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x136ec4: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x136ec4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x136ec8: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x136ec8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x136ecc: 0x3e00008  jr          $ra
    ctx->pc = 0x136ECCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136ED0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136ECCu;
            // 0x136ed0: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136E38u: goto label_136e38;
            case 0x136E50u: goto label_136e50;
            case 0x136E58u: goto label_136e58;
            case 0x136E74u: goto label_136e74;
            case 0x136E7Cu: goto label_136e7c;
            case 0x136E88u: goto label_136e88;
            case 0x136E90u: goto label_136e90;
            case 0x136EBCu: goto label_136ebc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136ED4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
