#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00163988
// Address: 0x163988 - 0x163b30
void sub_00163988_0x163988(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00163988_0x163988");
#endif

    switch (ctx->pc) {
        case 0x1639d4u: goto label_1639d4;
        case 0x1639e0u: goto label_1639e0;
        case 0x163a10u: goto label_163a10;
        case 0x163a20u: goto label_163a20;
        case 0x163a38u: goto label_163a38;
        case 0x163a50u: goto label_163a50;
        case 0x163a64u: goto label_163a64;
        case 0x163ac0u: goto label_163ac0;
        case 0x163ad4u: goto label_163ad4;
        case 0x163aecu: goto label_163aec;
        case 0x163b04u: goto label_163b04;
        default: break;
    }

    ctx->pc = 0x163988u;

    // 0x163988: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x163988u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16398c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x16398cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x163990: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x163990u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x163994: 0x8c8301ec  lw          $v1, 0x1EC($a0)
    ctx->pc = 0x163994u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 492)));
    // 0x163998: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x163998u;
    {
        const bool branch_taken_0x163998 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x16399Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163998u;
            // 0x16399c: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163998) {
            ctx->pc = 0x1639A8u;
            goto label_1639a8;
        }
    }
    ctx->pc = 0x1639A0u;
    // 0x1639a0: 0x8058e6c  j           func_1639B0
    ctx->pc = 0x1639A0u;
    ctx->pc = 0x1639A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1639A0u;
            // 0x1639a4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1639B0u;
    goto label_1639b0;
    ctx->pc = 0x1639A8u;
label_1639a8:
    // 0x1639a8: 0x8058eaa  j           func_163AA8
    ctx->pc = 0x1639A8u;
    ctx->pc = 0x1639ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1639A8u;
            // 0x1639ac: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163AA8u;
    goto label_163aa8;
    ctx->pc = 0x1639B0u;
label_1639b0:
    // 0x1639b0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1639b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1639b4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1639b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1639b8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1639b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1639bc: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1639bcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1639c0: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1639c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1639c4: 0x263201ec  addiu       $s2, $s1, 0x1EC
    ctx->pc = 0x1639c4u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 17), 492));
    // 0x1639c8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1639c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1639cc: 0xc05d4be  jal         func_1752F8
    ctx->pc = 0x1639CCu;
    SET_GPR_U32(ctx, 31, 0x1639D4u);
    ctx->pc = 0x1639D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1639CCu;
            // 0x1639d0: 0x8e240040  lw          $a0, 0x40($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 64)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1752F8u;
    if (runtime->hasFunction(0x1752F8u)) {
        auto targetFn = runtime->lookupFunction(0x1752F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1639D4u; }
        if (ctx->pc != 0x1639D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001752F8_0x1752f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1639D4u; }
        if (ctx->pc != 0x1639D4u) { return; }
    }
    ctx->pc = 0x1639D4u;
label_1639d4:
    // 0x1639d4: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1639d4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1639d8: 0xc058be8  jal         func_162FA0
    ctx->pc = 0x1639D8u;
    SET_GPR_U32(ctx, 31, 0x1639E0u);
    ctx->pc = 0x1639DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1639D8u;
            // 0x1639dc: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x162FA0u;
    if (runtime->hasFunction(0x162FA0u)) {
        auto targetFn = runtime->lookupFunction(0x162FA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1639E0u; }
        if (ctx->pc != 0x1639E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00162FA0_0x162fa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1639E0u; }
        if (ctx->pc != 0x1639E0u) { return; }
    }
    ctx->pc = 0x1639E0u;
label_1639e0:
    // 0x1639e0: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1639e0u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1639e4: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1639e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1639e8: 0x56020029  bnel        $s0, $v0, . + 4 + (0x29 << 2)
    ctx->pc = 0x1639E8u;
    {
        const bool branch_taken_0x1639e8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        if (branch_taken_0x1639e8) {
            ctx->pc = 0x1639ECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1639E8u;
            // 0x1639ec: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x163A90u;
            goto label_163a90;
        }
    }
    ctx->pc = 0x1639F0u;
    // 0x1639f0: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1639f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1639f4: 0x10620008  beq         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1639F4u;
    {
        const bool branch_taken_0x1639f4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1639f4) {
            ctx->pc = 0x163A18u;
            goto label_163a18;
        }
    }
    ctx->pc = 0x1639FCu;
    // 0x1639fc: 0x8e44000c  lw          $a0, 0xC($s2)
    ctx->pc = 0x1639fcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 12)));
    // 0x163a00: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x163a00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x163a04: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x163a04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x163a08: 0x40f809  jalr        $v0
    ctx->pc = 0x163A08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x163A10u);
        ctx->pc = 0x163A0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163A08u;
            // 0x163a0c: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x163A10u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1639A8u: goto label_1639a8;
            case 0x1639B0u: goto label_1639b0;
            case 0x1639D4u: goto label_1639d4;
            case 0x1639E0u: goto label_1639e0;
            case 0x163A10u: goto label_163a10;
            case 0x163A18u: goto label_163a18;
            case 0x163A20u: goto label_163a20;
            case 0x163A38u: goto label_163a38;
            case 0x163A3Cu: goto label_163a3c;
            case 0x163A50u: goto label_163a50;
            case 0x163A64u: goto label_163a64;
            case 0x163A68u: goto label_163a68;
            case 0x163A90u: goto label_163a90;
            case 0x163AA8u: goto label_163aa8;
            case 0x163AC0u: goto label_163ac0;
            case 0x163AD4u: goto label_163ad4;
            case 0x163AECu: goto label_163aec;
            case 0x163B04u: goto label_163b04;
            case 0x163B20u: goto label_163b20;
            case 0x163B24u: goto label_163b24;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x163A10u; }
            if (ctx->pc != 0x163A10u) { return; }
        }
        }
    }
    ctx->pc = 0x163A10u;
label_163a10:
    // 0x163a10: 0x1440001f  bnez        $v0, . + 4 + (0x1F << 2)
    ctx->pc = 0x163A10u;
    {
        const bool branch_taken_0x163a10 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x163A14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163A10u;
            // 0x163a14: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163a10) {
            ctx->pc = 0x163A90u;
            goto label_163a90;
        }
    }
    ctx->pc = 0x163A18u;
label_163a18:
    // 0x163a18: 0xc057ba2  jal         func_15EE88
    ctx->pc = 0x163A18u;
    SET_GPR_U32(ctx, 31, 0x163A20u);
    ctx->pc = 0x163A1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163A18u;
            // 0x163a1c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15EE88u;
    if (runtime->hasFunction(0x15EE88u)) {
        auto targetFn = runtime->lookupFunction(0x15EE88u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163A20u; }
        if (ctx->pc != 0x163A20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015EE88_0x15ee88(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163A20u; }
        if (ctx->pc != 0x163A20u) { return; }
    }
    ctx->pc = 0x163A20u;
label_163a20:
    // 0x163a20: 0x82230072  lb          $v1, 0x72($s1)
    ctx->pc = 0x163a20u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 114)));
    // 0x163a24: 0x54600005  bnel        $v1, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x163A24u;
    {
        const bool branch_taken_0x163a24 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x163a24) {
            ctx->pc = 0x163A28u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x163A24u;
            // 0x163a28: 0x82230070  lb          $v1, 0x70($s1) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 112)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x163A3Cu;
            goto label_163a3c;
        }
    }
    ctx->pc = 0x163A2Cu;
    // 0x163a2c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x163a2cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163a30: 0xc057cfc  jal         func_15F3F0
    ctx->pc = 0x163A30u;
    SET_GPR_U32(ctx, 31, 0x163A38u);
    ctx->pc = 0x163A34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163A30u;
            // 0x163a34: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F3F0u;
    if (runtime->hasFunction(0x15F3F0u)) {
        auto targetFn = runtime->lookupFunction(0x15F3F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163A38u; }
        if (ctx->pc != 0x163A38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F3F0_0x15f3f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163A38u; }
        if (ctx->pc != 0x163A38u) { return; }
    }
    ctx->pc = 0x163A38u;
label_163a38:
    // 0x163a38: 0x82230070  lb          $v1, 0x70($s1)
    ctx->pc = 0x163a38u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 112)));
label_163a3c:
    // 0x163a3c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x163a3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x163a40: 0x54620009  bnel        $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x163A40u;
    {
        const bool branch_taken_0x163a40 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x163a40) {
            ctx->pc = 0x163A44u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x163A40u;
            // 0x163a44: 0x82220072  lb          $v0, 0x72($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 114)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x163A68u;
            goto label_163a68;
        }
    }
    ctx->pc = 0x163A48u;
    // 0x163a48: 0xc059f5c  jal         func_167D70
    ctx->pc = 0x163A48u;
    SET_GPR_U32(ctx, 31, 0x163A50u);
    ctx->pc = 0x163A4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163A48u;
            // 0x163a4c: 0x8e240040  lw          $a0, 0x40($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 64)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167D70u;
    if (runtime->hasFunction(0x167D70u)) {
        auto targetFn = runtime->lookupFunction(0x167D70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163A50u; }
        if (ctx->pc != 0x163A50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167D70_0x167d70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163A50u; }
        if (ctx->pc != 0x163A50u) { return; }
    }
    ctx->pc = 0x163A50u;
label_163a50:
    // 0x163a50: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x163A50u;
    {
        const bool branch_taken_0x163a50 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x163a50) {
            ctx->pc = 0x163A54u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x163A50u;
            // 0x163a54: 0x82220072  lb          $v0, 0x72($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 114)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x163A68u;
            goto label_163a68;
        }
    }
    ctx->pc = 0x163A58u;
    // 0x163a58: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x163a58u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x163a5c: 0xc058dd4  jal         func_163750
    ctx->pc = 0x163A5Cu;
    SET_GPR_U32(ctx, 31, 0x163A64u);
    ctx->pc = 0x163A60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163A5Cu;
            // 0x163a60: 0x248404a0  addiu       $a0, $a0, 0x4A0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1184));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163A64u; }
        if (ctx->pc != 0x163A64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163A64u; }
        if (ctx->pc != 0x163A64u) { return; }
    }
    ctx->pc = 0x163A64u;
label_163a64:
    // 0x163a64: 0x82220072  lb          $v0, 0x72($s1)
    ctx->pc = 0x163a64u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 114)));
label_163a68:
    // 0x163a68: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x163A68u;
    {
        const bool branch_taken_0x163a68 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x163A6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163A68u;
            // 0x163a6c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163a68) {
            ctx->pc = 0x163A90u;
            goto label_163a90;
        }
    }
    ctx->pc = 0x163A70u;
    // 0x163a70: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x163a70u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163a74: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x163a74u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x163a78: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x163a78u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163a7c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x163a7cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x163a80: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x163a80u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x163a84: 0x8058c1e  j           func_163078
    ctx->pc = 0x163A84u;
    ctx->pc = 0x163A88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163A84u;
            // 0x163a88: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163078u;
    if (runtime->hasFunction(0x163078u)) {
        auto targetFn = runtime->lookupFunction(0x163078u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163078_0x163078(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x163A8Cu;
    // 0x163a8c: 0x0  nop
    ctx->pc = 0x163a8cu;
    // NOP
label_163a90:
    // 0x163a90: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x163a90u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x163a94: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x163a94u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x163a98: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x163a98u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x163a9c: 0x3e00008  jr          $ra
    ctx->pc = 0x163A9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x163AA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163A9Cu;
            // 0x163aa0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1639A8u: goto label_1639a8;
            case 0x1639B0u: goto label_1639b0;
            case 0x1639D4u: goto label_1639d4;
            case 0x1639E0u: goto label_1639e0;
            case 0x163A10u: goto label_163a10;
            case 0x163A18u: goto label_163a18;
            case 0x163A20u: goto label_163a20;
            case 0x163A38u: goto label_163a38;
            case 0x163A3Cu: goto label_163a3c;
            case 0x163A50u: goto label_163a50;
            case 0x163A64u: goto label_163a64;
            case 0x163A68u: goto label_163a68;
            case 0x163A90u: goto label_163a90;
            case 0x163AA8u: goto label_163aa8;
            case 0x163AC0u: goto label_163ac0;
            case 0x163AD4u: goto label_163ad4;
            case 0x163AECu: goto label_163aec;
            case 0x163B04u: goto label_163b04;
            case 0x163B20u: goto label_163b20;
            case 0x163B24u: goto label_163b24;
            default: break;
        }
        return;
    }
    ctx->pc = 0x163AA4u;
    // 0x163aa4: 0x0  nop
    ctx->pc = 0x163aa4u;
    // NOP
label_163aa8:
    // 0x163aa8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x163aa8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x163aac: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x163aacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x163ab0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x163ab0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163ab4: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x163ab4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x163ab8: 0xc05d4be  jal         func_1752F8
    ctx->pc = 0x163AB8u;
    SET_GPR_U32(ctx, 31, 0x163AC0u);
    ctx->pc = 0x163ABCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163AB8u;
            // 0x163abc: 0x8e040040  lw          $a0, 0x40($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1752F8u;
    if (runtime->hasFunction(0x1752F8u)) {
        auto targetFn = runtime->lookupFunction(0x1752F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163AC0u; }
        if (ctx->pc != 0x163AC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001752F8_0x1752f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163AC0u; }
        if (ctx->pc != 0x163AC0u) { return; }
    }
    ctx->pc = 0x163AC0u;
label_163ac0:
    // 0x163ac0: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x163ac0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x163ac4: 0x14430016  bne         $v0, $v1, . + 4 + (0x16 << 2)
    ctx->pc = 0x163AC4u;
    {
        const bool branch_taken_0x163ac4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x163AC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163AC4u;
            // 0x163ac8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163ac4) {
            ctx->pc = 0x163B20u;
            goto label_163b20;
        }
    }
    ctx->pc = 0x163ACCu;
    // 0x163acc: 0xc057ba2  jal         func_15EE88
    ctx->pc = 0x163ACCu;
    SET_GPR_U32(ctx, 31, 0x163AD4u);
    ctx->pc = 0x15EE88u;
    if (runtime->hasFunction(0x15EE88u)) {
        auto targetFn = runtime->lookupFunction(0x15EE88u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163AD4u; }
        if (ctx->pc != 0x163AD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015EE88_0x15ee88(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163AD4u; }
        if (ctx->pc != 0x163AD4u) { return; }
    }
    ctx->pc = 0x163AD4u;
label_163ad4:
    // 0x163ad4: 0x82030072  lb          $v1, 0x72($s0)
    ctx->pc = 0x163ad4u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 114)));
    // 0x163ad8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x163ad8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163adc: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x163ADCu;
    {
        const bool branch_taken_0x163adc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x163AE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163ADCu;
            // 0x163ae0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163adc) {
            ctx->pc = 0x163AECu;
            goto label_163aec;
        }
    }
    ctx->pc = 0x163AE4u;
    // 0x163ae4: 0xc057cfc  jal         func_15F3F0
    ctx->pc = 0x163AE4u;
    SET_GPR_U32(ctx, 31, 0x163AECu);
    ctx->pc = 0x15F3F0u;
    if (runtime->hasFunction(0x15F3F0u)) {
        auto targetFn = runtime->lookupFunction(0x15F3F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163AECu; }
        if (ctx->pc != 0x163AECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F3F0_0x15f3f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163AECu; }
        if (ctx->pc != 0x163AECu) { return; }
    }
    ctx->pc = 0x163AECu;
label_163aec:
    // 0x163aec: 0x82030070  lb          $v1, 0x70($s0)
    ctx->pc = 0x163aecu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 112)));
    // 0x163af0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x163af0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x163af4: 0x5462000b  bnel        $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x163AF4u;
    {
        const bool branch_taken_0x163af4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x163af4) {
            ctx->pc = 0x163AF8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x163AF4u;
            // 0x163af8: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x163B24u;
            goto label_163b24;
        }
    }
    ctx->pc = 0x163AFCu;
    // 0x163afc: 0xc059f5c  jal         func_167D70
    ctx->pc = 0x163AFCu;
    SET_GPR_U32(ctx, 31, 0x163B04u);
    ctx->pc = 0x163B00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163AFCu;
            // 0x163b00: 0x8e040040  lw          $a0, 0x40($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167D70u;
    if (runtime->hasFunction(0x167D70u)) {
        auto targetFn = runtime->lookupFunction(0x167D70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163B04u; }
        if (ctx->pc != 0x163B04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167D70_0x167d70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163B04u; }
        if (ctx->pc != 0x163B04u) { return; }
    }
    ctx->pc = 0x163B04u;
label_163b04:
    // 0x163b04: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x163b04u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x163b08: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x163B08u;
    {
        const bool branch_taken_0x163b08 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x163B0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163B08u;
            // 0x163b0c: 0x248404a0  addiu       $a0, $a0, 0x4A0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1184));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163b08) {
            ctx->pc = 0x163B20u;
            goto label_163b20;
        }
    }
    ctx->pc = 0x163B10u;
    // 0x163b10: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x163b10u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x163b14: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x163b14u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x163b18: 0x8058dd4  j           func_163750
    ctx->pc = 0x163B18u;
    ctx->pc = 0x163B1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163B18u;
            // 0x163b1c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x163B20u;
label_163b20:
    // 0x163b20: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x163b20u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_163b24:
    // 0x163b24: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x163b24u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x163b28: 0x3e00008  jr          $ra
    ctx->pc = 0x163B28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x163B2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163B28u;
            // 0x163b2c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1639A8u: goto label_1639a8;
            case 0x1639B0u: goto label_1639b0;
            case 0x1639D4u: goto label_1639d4;
            case 0x1639E0u: goto label_1639e0;
            case 0x163A10u: goto label_163a10;
            case 0x163A18u: goto label_163a18;
            case 0x163A20u: goto label_163a20;
            case 0x163A38u: goto label_163a38;
            case 0x163A3Cu: goto label_163a3c;
            case 0x163A50u: goto label_163a50;
            case 0x163A64u: goto label_163a64;
            case 0x163A68u: goto label_163a68;
            case 0x163A90u: goto label_163a90;
            case 0x163AA8u: goto label_163aa8;
            case 0x163AC0u: goto label_163ac0;
            case 0x163AD4u: goto label_163ad4;
            case 0x163AECu: goto label_163aec;
            case 0x163B04u: goto label_163b04;
            case 0x163B20u: goto label_163b20;
            case 0x163B24u: goto label_163b24;
            default: break;
        }
        return;
    }
    ctx->pc = 0x163B30u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
