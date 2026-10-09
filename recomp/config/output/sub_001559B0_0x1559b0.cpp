#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001559B0
// Address: 0x1559b0 - 0x155a84
void sub_001559B0_0x1559b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001559B0_0x1559b0");
#endif

    switch (ctx->pc) {
        case 0x1559e0u: goto label_1559e0;
        case 0x1559ecu: goto label_1559ec;
        case 0x155a10u: goto label_155a10;
        case 0x155a18u: goto label_155a18;
        case 0x155a28u: goto label_155a28;
        case 0x155a60u: goto label_155a60;
        default: break;
    }

    ctx->pc = 0x1559b0u;

    // 0x1559b0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1559b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1559b4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1559b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1559b8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1559b8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1559bc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1559bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1559c0: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1559c0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1559c4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1559c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1559c8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1559c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1559cc: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x1559ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x1559d0: 0x9043e544  lbu         $v1, -0x1ABC($v0)
    ctx->pc = 0x1559d0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 4294960452)));
    // 0x1559d4: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x1559d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1559d8: 0x10640007  beq         $v1, $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1559D8u;
    {
        const bool branch_taken_0x1559d8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x1559DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1559D8u;
            // 0x1559dc: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1559d8) {
            ctx->pc = 0x1559F8u;
            goto label_1559f8;
        }
    }
    ctx->pc = 0x1559E0u;
label_1559e0:
    // 0x1559e0: 0x2401ffff  addiu       $at, $zero, -0x1
    ctx->pc = 0x1559e0u;
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1559e4: 0x20f809  jalr        $at
    ctx->pc = 0x1559E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 1);
        SET_GPR_U32(ctx, 31, 0x1559ECu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1559ECu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1559E0u: goto label_1559e0;
            case 0x1559ECu: goto label_1559ec;
            case 0x1559F8u: goto label_1559f8;
            case 0x155A10u: goto label_155a10;
            case 0x155A18u: goto label_155a18;
            case 0x155A28u: goto label_155a28;
            case 0x155A40u: goto label_155a40;
            case 0x155A60u: goto label_155a60;
            case 0x155A7Cu: goto label_155a7c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1559ECu; }
            if (ctx->pc != 0x1559ECu) { return; }
        }
        }
    }
    ctx->pc = 0x1559ECu;
label_1559ec:
    // 0x1559ec: 0x1000fffc  b           . + 4 + (-0x4 << 2)
    ctx->pc = 0x1559ECu;
    {
        const bool branch_taken_0x1559ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1559ec) {
            ctx->pc = 0x1559E0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1559e0;
        }
    }
    ctx->pc = 0x1559F4u;
    // 0x1559f4: 0x0  nop
    ctx->pc = 0x1559f4u;
    // NOP
label_1559f8:
    // 0x1559f8: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x1559f8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x1559fc: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x1559fcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x155a00: 0x24634c08  addiu       $v1, $v1, 0x4C08
    ctx->pc = 0x155a00u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 19464));
    // 0x155a04: 0x2442e4a8  addiu       $v0, $v0, -0x1B58
    ctx->pc = 0x155a04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294960296));
    // 0x155a08: 0xc054152  jal         func_150548
    ctx->pc = 0x155A08u;
    SET_GPR_U32(ctx, 31, 0x155A10u);
    ctx->pc = 0x155A0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x155A08u;
            // 0x155a0c: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150548u;
    if (runtime->hasFunction(0x150548u)) {
        auto targetFn = runtime->lookupFunction(0x150548u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155A10u; }
        if (ctx->pc != 0x155A10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00150548_0x150548(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155A10u; }
        if (ctx->pc != 0x155A10u) { return; }
    }
    ctx->pc = 0x155A10u;
label_155a10:
    // 0x155a10: 0xc054292  jal         func_150A48
    ctx->pc = 0x155A10u;
    SET_GPR_U32(ctx, 31, 0x155A18u);
    ctx->pc = 0x150A48u;
    if (runtime->hasFunction(0x150A48u)) {
        auto targetFn = runtime->lookupFunction(0x150A48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155A18u; }
        if (ctx->pc != 0x155A18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00150A48_0x150a48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155A18u; }
        if (ctx->pc != 0x155A18u) { return; }
    }
    ctx->pc = 0x155A18u;
label_155a18:
    // 0x155a18: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x155a18u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x155a1c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x155a1cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x155a20: 0xc0556a2  jal         func_155A88
    ctx->pc = 0x155A20u;
    SET_GPR_U32(ctx, 31, 0x155A28u);
    ctx->pc = 0x155A24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x155A20u;
            // 0x155a24: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155A88u;
    if (runtime->hasFunction(0x155A88u)) {
        auto targetFn = runtime->lookupFunction(0x155A88u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155A28u; }
        if (ctx->pc != 0x155A28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155A88_0x155a88(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155A28u; }
        if (ctx->pc != 0x155A28u) { return; }
    }
    ctx->pc = 0x155A28u;
label_155a28:
    // 0x155a28: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x155a28u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x155a2c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x155a2cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x155a30: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x155a30u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x155a34: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x155a34u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x155a38: 0x8055690  j           func_155A40
    ctx->pc = 0x155A38u;
    ctx->pc = 0x155A3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x155A38u;
            // 0x155a3c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155A40u;
    goto label_155a40;
    ctx->pc = 0x155A40u;
label_155a40:
    // 0x155a40: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x155a40u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x155a44: 0x24424c10  addiu       $v0, $v0, 0x4C10
    ctx->pc = 0x155a44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 19472));
    // 0x155a48: 0x8c440040  lw          $a0, 0x40($v0)
    ctx->pc = 0x155a48u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 64)));
    // 0x155a4c: 0x1880000b  blez        $a0, . + 4 + (0xB << 2)
    ctx->pc = 0x155A4Cu;
    {
        const bool branch_taken_0x155a4c = (GPR_S64(ctx, 4) <= 0);
        ctx->pc = 0x155A50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155A4Cu;
            // 0x155a50: 0x8c430044  lw          $v1, 0x44($v0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 68)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155a4c) {
            ctx->pc = 0x155A7Cu;
            goto label_155a7c;
        }
    }
    ctx->pc = 0x155A54u;
    // 0x155a54: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x155a54u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x155a58: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x155a58u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x155a5c: 0x0  nop
    ctx->pc = 0x155a5cu;
    // NOP
label_155a60:
    // 0x155a60: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x155a60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x155a64: 0xac640000  sw          $a0, 0x0($v1)
    ctx->pc = 0x155a64u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4));
    // 0x155a68: 0x0  nop
    ctx->pc = 0x155a68u;
    // NOP
    // 0x155a6c: 0x0  nop
    ctx->pc = 0x155a6cu;
    // NOP
    // 0x155a70: 0x0  nop
    ctx->pc = 0x155a70u;
    // NOP
    // 0x155a74: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x155A74u;
    {
        const bool branch_taken_0x155a74 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x155A78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155A74u;
            // 0x155a78: 0x246306a0  addiu       $v1, $v1, 0x6A0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1696));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155a74) {
            ctx->pc = 0x155A60u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_155a60;
        }
    }
    ctx->pc = 0x155A7Cu;
label_155a7c:
    // 0x155a7c: 0x3e00008  jr          $ra
    ctx->pc = 0x155A7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1559E0u: goto label_1559e0;
            case 0x1559ECu: goto label_1559ec;
            case 0x1559F8u: goto label_1559f8;
            case 0x155A10u: goto label_155a10;
            case 0x155A18u: goto label_155a18;
            case 0x155A28u: goto label_155a28;
            case 0x155A40u: goto label_155a40;
            case 0x155A60u: goto label_155a60;
            case 0x155A7Cu: goto label_155a7c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x155A84u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
