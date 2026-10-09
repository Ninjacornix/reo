#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00136D48
// Address: 0x136d48 - 0x136e04
void sub_00136D48_0x136d48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00136D48_0x136d48");
#endif

    switch (ctx->pc) {
        case 0x136d90u: goto label_136d90;
        case 0x136db4u: goto label_136db4;
        case 0x136dc8u: goto label_136dc8;
        case 0x136df0u: goto label_136df0;
        default: break;
    }

    ctx->pc = 0x136d48u;

    // 0x136d48: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x136d48u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x136d4c: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x136d4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x136d50: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x136d50u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136d54: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x136d54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x136d58: 0x14800005  bnez        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x136D58u;
    {
        const bool branch_taken_0x136d58 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x136D5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136D58u;
            // 0x136d5c: 0xffbf0030  sd          $ra, 0x30($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136d58) {
            ctx->pc = 0x136D70u;
            goto label_136d70;
        }
    }
    ctx->pc = 0x136D60u;
    // 0x136d60: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136d60u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136d64: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x136D64u;
    {
        const bool branch_taken_0x136d64 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136D68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136D64u;
            // 0x136d68: 0x2484c260  addiu       $a0, $a0, -0x3DA0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951520));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136d64) {
            ctx->pc = 0x136DACu;
            goto label_136dac;
        }
    }
    ctx->pc = 0x136D6Cu;
    // 0x136d6c: 0x0  nop
    ctx->pc = 0x136d6cu;
    // NOP
label_136d70:
    // 0x136d70: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x136D70u;
    {
        const bool branch_taken_0x136d70 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x136d70) {
            ctx->pc = 0x136D88u;
            goto label_136d88;
        }
    }
    ctx->pc = 0x136D78u;
    // 0x136d78: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136d78u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136d7c: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x136D7Cu;
    {
        const bool branch_taken_0x136d7c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136D80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136D7Cu;
            // 0x136d80: 0x2484c288  addiu       $a0, $a0, -0x3D78 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951560));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136d7c) {
            ctx->pc = 0x136DACu;
            goto label_136dac;
        }
    }
    ctx->pc = 0x136D84u;
    // 0x136d84: 0x0  nop
    ctx->pc = 0x136d84u;
    // NOP
label_136d88:
    // 0x136d88: 0xc04d558  jal         func_135560
    ctx->pc = 0x136D88u;
    SET_GPR_U32(ctx, 31, 0x136D90u);
    ctx->pc = 0x135560u;
    if (runtime->hasFunction(0x135560u)) {
        auto targetFn = runtime->lookupFunction(0x135560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136D90u; }
        if (ctx->pc != 0x136D90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135560_0x135560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136D90u; }
        if (ctx->pc != 0x136D90u) { return; }
    }
    ctx->pc = 0x136D90u;
label_136d90:
    // 0x136d90: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x136d90u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136d94: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x136d94u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136d98: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x136d98u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136d9c: 0x16200008  bnez        $s1, . + 4 + (0x8 << 2)
    ctx->pc = 0x136D9Cu;
    {
        const bool branch_taken_0x136d9c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x136DA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136D9Cu;
            // 0x136da0: 0x24060014  addiu       $a2, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136d9c) {
            ctx->pc = 0x136DC0u;
            goto label_136dc0;
        }
    }
    ctx->pc = 0x136DA4u;
    // 0x136da4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136da4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136da8: 0x2484c2b0  addiu       $a0, $a0, -0x3D50
    ctx->pc = 0x136da8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951600));
label_136dac:
    // 0x136dac: 0xc04d480  jal         func_135200
    ctx->pc = 0x136DACu;
    SET_GPR_U32(ctx, 31, 0x136DB4u);
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136DB4u; }
        if (ctx->pc != 0x136DB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136DB4u; }
        if (ctx->pc != 0x136DB4u) { return; }
    }
    ctx->pc = 0x136DB4u;
label_136db4:
    // 0x136db4: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x136DB4u;
    {
        const bool branch_taken_0x136db4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136DB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136DB4u;
            // 0x136db8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136db4) {
            ctx->pc = 0x136DF0u;
            goto label_136df0;
        }
    }
    ctx->pc = 0x136DBCu;
    // 0x136dbc: 0x0  nop
    ctx->pc = 0x136dbcu;
    // NOP
label_136dc0:
    // 0x136dc0: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x136DC0u;
    SET_GPR_U32(ctx, 31, 0x136DC8u);
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136DC8u; }
        if (ctx->pc != 0x136DC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136DC8u; }
        if (ctx->pc != 0x136DC8u) { return; }
    }
    ctx->pc = 0x136DC8u;
label_136dc8:
    // 0x136dc8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x136dc8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x136dcc: 0xafb00004  sw          $s0, 0x4($sp)
    ctx->pc = 0x136dccu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 16));
    // 0x136dd0: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x136dd0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136dd4: 0x24050003  addiu       $a1, $zero, 0x3
    ctx->pc = 0x136dd4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x136dd8: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x136dd8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136ddc: 0x8e230060  lw          $v1, 0x60($s1)
    ctx->pc = 0x136ddcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 96)));
    // 0x136de0: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x136DE0u;
    {
        const bool branch_taken_0x136de0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x136DE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136DE0u;
            // 0x136de4: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136de0) {
            ctx->pc = 0x136DF0u;
            goto label_136df0;
        }
    }
    ctx->pc = 0x136DE8u;
    // 0x136de8: 0x60f809  jalr        $v1
    ctx->pc = 0x136DE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x136DF0u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x136DF0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136D70u: goto label_136d70;
            case 0x136D88u: goto label_136d88;
            case 0x136D90u: goto label_136d90;
            case 0x136DACu: goto label_136dac;
            case 0x136DB4u: goto label_136db4;
            case 0x136DC0u: goto label_136dc0;
            case 0x136DC8u: goto label_136dc8;
            case 0x136DF0u: goto label_136df0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136DF0u; }
            if (ctx->pc != 0x136DF0u) { return; }
        }
        }
    }
    ctx->pc = 0x136DF0u;
label_136df0:
    // 0x136df0: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x136df0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x136df4: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x136df4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x136df8: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x136df8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x136dfc: 0x3e00008  jr          $ra
    ctx->pc = 0x136DFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136E00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136DFCu;
            // 0x136e00: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136D70u: goto label_136d70;
            case 0x136D88u: goto label_136d88;
            case 0x136D90u: goto label_136d90;
            case 0x136DACu: goto label_136dac;
            case 0x136DB4u: goto label_136db4;
            case 0x136DC0u: goto label_136dc0;
            case 0x136DC8u: goto label_136dc8;
            case 0x136DF0u: goto label_136df0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136E04u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
