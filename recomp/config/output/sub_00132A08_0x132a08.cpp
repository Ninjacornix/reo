#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00132A08
// Address: 0x132a08 - 0x132bc8
void sub_00132A08_0x132a08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00132A08_0x132a08");
#endif

    switch (ctx->pc) {
        case 0x132a28u: goto label_132a28;
        case 0x132a50u: goto label_132a50;
        case 0x132aa0u: goto label_132aa0;
        case 0x132ab8u: goto label_132ab8;
        case 0x132ae0u: goto label_132ae0;
        case 0x132aecu: goto label_132aec;
        case 0x132af8u: goto label_132af8;
        case 0x132b78u: goto label_132b78;
        case 0x132b9cu: goto label_132b9c;
        default: break;
    }

    ctx->pc = 0x132a08u;

    // 0x132a08: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x132a08u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x132a0c: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x132A0Cu;
    {
        const bool branch_taken_0x132a0c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x132A10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132A0Cu;
            // 0x132a10: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132a0c) {
            ctx->pc = 0x132A1Cu;
            goto label_132a1c;
        }
    }
    ctx->pc = 0x132A14u;
    // 0x132a14: 0x4a10006  bgez        $a1, . + 4 + (0x6 << 2)
    ctx->pc = 0x132A14u;
    {
        const bool branch_taken_0x132a14 = (GPR_S64(ctx, 5) >= 0);
        ctx->pc = 0x132A18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132A14u;
            // 0x132a18: 0x51080  sll         $v0, $a1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132a14) {
            ctx->pc = 0x132A30u;
            goto label_132a30;
        }
    }
    ctx->pc = 0x132A1Cu;
label_132a1c:
    // 0x132a1c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x132a1cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x132a20: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x132A20u;
    SET_GPR_U32(ctx, 31, 0x132A28u);
    ctx->pc = 0x132A24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132A20u;
            // 0x132a24: 0x2484b298  addiu       $a0, $a0, -0x4D68 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294947480));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132A28u; }
        if (ctx->pc != 0x132A28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132A28u; }
        if (ctx->pc != 0x132A28u) { return; }
    }
    ctx->pc = 0x132A28u;
label_132a28:
    // 0x132a28: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x132A28u;
    {
        const bool branch_taken_0x132a28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x132A2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132A28u;
            // 0x132a2c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132a28) {
            ctx->pc = 0x132A64u;
            goto label_132a64;
        }
    }
    ctx->pc = 0x132A30u;
label_132a30:
    // 0x132a30: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x132a30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x132a34: 0x8c420018  lw          $v0, 0x18($v0)
    ctx->pc = 0x132a34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x132a38: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x132A38u;
    {
        const bool branch_taken_0x132a38 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x132A3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132A38u;
            // 0x132a3c: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132a38) {
            ctx->pc = 0x132A60u;
            goto label_132a60;
        }
    }
    ctx->pc = 0x132A40u;
    // 0x132a40: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x132a40u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x132a44: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x132a44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x132a48: 0x40f809  jalr        $v0
    ctx->pc = 0x132A48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x132A50u);
        ctx->pc = 0x132A4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132A48u;
            // 0x132a4c: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x132A50u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x132A1Cu: goto label_132a1c;
            case 0x132A28u: goto label_132a28;
            case 0x132A30u: goto label_132a30;
            case 0x132A50u: goto label_132a50;
            case 0x132A60u: goto label_132a60;
            case 0x132A64u: goto label_132a64;
            case 0x132AA0u: goto label_132aa0;
            case 0x132AB0u: goto label_132ab0;
            case 0x132AB8u: goto label_132ab8;
            case 0x132AE0u: goto label_132ae0;
            case 0x132AECu: goto label_132aec;
            case 0x132AF8u: goto label_132af8;
            case 0x132B18u: goto label_132b18;
            case 0x132B38u: goto label_132b38;
            case 0x132B3Cu: goto label_132b3c;
            case 0x132B78u: goto label_132b78;
            case 0x132B80u: goto label_132b80;
            case 0x132B9Cu: goto label_132b9c;
            case 0x132BB0u: goto label_132bb0;
            case 0x132BB4u: goto label_132bb4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x132A50u; }
            if (ctx->pc != 0x132A50u) { return; }
        }
        }
    }
    ctx->pc = 0x132A50u;
label_132a50:
    // 0x132a50: 0x21fc2  srl         $v1, $v0, 31
    ctx->pc = 0x132a50u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x132a54: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x132a54u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x132a58: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x132A58u;
    {
        const bool branch_taken_0x132a58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x132A5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132A58u;
            // 0x132a5c: 0x31043  sra         $v0, $v1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132a58) {
            ctx->pc = 0x132A64u;
            goto label_132a64;
        }
    }
    ctx->pc = 0x132A60u;
label_132a60:
    // 0x132a60: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x132a60u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_132a64:
    // 0x132a64: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x132a64u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132a68: 0x3e00008  jr          $ra
    ctx->pc = 0x132A68u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x132A6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132A68u;
            // 0x132a6c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x132A1Cu: goto label_132a1c;
            case 0x132A28u: goto label_132a28;
            case 0x132A30u: goto label_132a30;
            case 0x132A50u: goto label_132a50;
            case 0x132A60u: goto label_132a60;
            case 0x132A64u: goto label_132a64;
            case 0x132AA0u: goto label_132aa0;
            case 0x132AB0u: goto label_132ab0;
            case 0x132AB8u: goto label_132ab8;
            case 0x132AE0u: goto label_132ae0;
            case 0x132AECu: goto label_132aec;
            case 0x132AF8u: goto label_132af8;
            case 0x132B18u: goto label_132b18;
            case 0x132B38u: goto label_132b38;
            case 0x132B3Cu: goto label_132b3c;
            case 0x132B78u: goto label_132b78;
            case 0x132B80u: goto label_132b80;
            case 0x132B9Cu: goto label_132b9c;
            case 0x132BB0u: goto label_132bb0;
            case 0x132BB4u: goto label_132bb4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x132A70u;
    // 0x132a70: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x132a70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x132a74: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x132a74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x132a78: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x132a78u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x132a7c: 0xe7b40020  swc1        $f20, 0x20($sp)
    ctx->pc = 0x132a7cu;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 32), bits); }
    // 0x132a80: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x132a80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x132a84: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x132a84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x132a88: 0x4480a000  mtc1        $zero, $f20
    ctx->pc = 0x132a88u;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[20], &bits, sizeof(bits)); }
    // 0x132a8c: 0x16400008  bnez        $s2, . + 4 + (0x8 << 2)
    ctx->pc = 0x132A8Cu;
    {
        const bool branch_taken_0x132a8c = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        ctx->pc = 0x132A90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132A8Cu;
            // 0x132a90: 0xffbf0018  sd          $ra, 0x18($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132a8c) {
            ctx->pc = 0x132AB0u;
            goto label_132ab0;
        }
    }
    ctx->pc = 0x132A94u;
    // 0x132a94: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x132a94u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x132a98: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x132A98u;
    SET_GPR_U32(ctx, 31, 0x132AA0u);
    ctx->pc = 0x132A9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132A98u;
            // 0x132a9c: 0x2484b2c8  addiu       $a0, $a0, -0x4D38 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294947528));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132AA0u; }
        if (ctx->pc != 0x132AA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132AA0u; }
        if (ctx->pc != 0x132AA0u) { return; }
    }
    ctx->pc = 0x132AA0u;
label_132aa0:
    // 0x132aa0: 0x3c01bf80  lui         $at, 0xBF80
    ctx->pc = 0x132aa0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49024 << 16));
    // 0x132aa4: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x132aa4u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x132aa8: 0x10000024  b           . + 4 + (0x24 << 2)
    ctx->pc = 0x132AA8u;
    {
        const bool branch_taken_0x132aa8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x132AACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132AA8u;
            // 0x132aac: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132aa8) {
            ctx->pc = 0x132B3Cu;
            goto label_132b3c;
        }
    }
    ctx->pc = 0x132AB0u;
label_132ab0:
    // 0x132ab0: 0xc04c7be  jal         func_131EF8
    ctx->pc = 0x132AB0u;
    SET_GPR_U32(ctx, 31, 0x132AB8u);
    ctx->pc = 0x131EF8u;
    if (runtime->hasFunction(0x131EF8u)) {
        auto targetFn = runtime->lookupFunction(0x131EF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132AB8u; }
        if (ctx->pc != 0x132AB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131EF8_0x131ef8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132AB8u; }
        if (ctx->pc != 0x132AB8u) { return; }
    }
    ctx->pc = 0x132AB8u;
label_132ab8:
    // 0x132ab8: 0x28420002  slti        $v0, $v0, 0x2
    ctx->pc = 0x132ab8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x132abc: 0x1440001e  bnez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x132ABCu;
    {
        const bool branch_taken_0x132abc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x132AC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132ABCu;
            // 0x132ac0: 0x4600a006  mov.s       $f0, $f20 (Delay Slot)
        ctx->f[0] = FPU_MOV_S(ctx->f[20]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x132abc) {
            ctx->pc = 0x132B38u;
            goto label_132b38;
        }
    }
    ctx->pc = 0x132AC4u;
    // 0x132ac4: 0x8e430014  lw          $v1, 0x14($s2)
    ctx->pc = 0x132ac4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 20)));
    // 0x132ac8: 0x1060001b  beqz        $v1, . + 4 + (0x1B << 2)
    ctx->pc = 0x132AC8u;
    {
        const bool branch_taken_0x132ac8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x132ACCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132AC8u;
            // 0x132acc: 0x60202d  daddu       $a0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132ac8) {
            ctx->pc = 0x132B38u;
            goto label_132b38;
        }
    }
    ctx->pc = 0x132AD0u;
    // 0x132ad0: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x132ad0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x132ad4: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x132ad4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x132ad8: 0x40f809  jalr        $v0
    ctx->pc = 0x132AD8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x132AE0u);
        ctx->pc = 0x132ADCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132AD8u;
            // 0x132adc: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x132AE0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x132A1Cu: goto label_132a1c;
            case 0x132A28u: goto label_132a28;
            case 0x132A30u: goto label_132a30;
            case 0x132A50u: goto label_132a50;
            case 0x132A60u: goto label_132a60;
            case 0x132A64u: goto label_132a64;
            case 0x132AA0u: goto label_132aa0;
            case 0x132AB0u: goto label_132ab0;
            case 0x132AB8u: goto label_132ab8;
            case 0x132AE0u: goto label_132ae0;
            case 0x132AECu: goto label_132aec;
            case 0x132AF8u: goto label_132af8;
            case 0x132B18u: goto label_132b18;
            case 0x132B38u: goto label_132b38;
            case 0x132B3Cu: goto label_132b3c;
            case 0x132B78u: goto label_132b78;
            case 0x132B80u: goto label_132b80;
            case 0x132B9Cu: goto label_132b9c;
            case 0x132BB0u: goto label_132bb0;
            case 0x132BB4u: goto label_132bb4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x132AE0u; }
            if (ctx->pc != 0x132AE0u) { return; }
        }
        }
    }
    ctx->pc = 0x132AE0u;
label_132ae0:
    // 0x132ae0: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x132ae0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x132ae4: 0xc04c952  jal         func_132548
    ctx->pc = 0x132AE4u;
    SET_GPR_U32(ctx, 31, 0x132AECu);
    ctx->pc = 0x132AE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132AE4u;
            // 0x132ae8: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x132548u;
    if (runtime->hasFunction(0x132548u)) {
        auto targetFn = runtime->lookupFunction(0x132548u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132AECu; }
        if (ctx->pc != 0x132AECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00132548_0x132548(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132AECu; }
        if (ctx->pc != 0x132AECu) { return; }
    }
    ctx->pc = 0x132AECu;
label_132aec:
    // 0x132aec: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x132aecu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x132af0: 0xc04c93e  jal         func_1324F8
    ctx->pc = 0x132AF0u;
    SET_GPR_U32(ctx, 31, 0x132AF8u);
    ctx->pc = 0x132AF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132AF0u;
            // 0x132af4: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1324F8u;
    if (runtime->hasFunction(0x1324F8u)) {
        auto targetFn = runtime->lookupFunction(0x1324F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132AF8u; }
        if (ctx->pc != 0x132AF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001324F8_0x1324f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132AF8u; }
        if (ctx->pc != 0x132AF8u) { return; }
    }
    ctx->pc = 0x132AF8u;
label_132af8:
    // 0x132af8: 0x1118c0  sll         $v1, $s1, 3
    ctx->pc = 0x132af8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x132afc: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x132afcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x132b00: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x132b00u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x132b04: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x132b04u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x132b08: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x132b08u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x132b0c: 0x203001a  div         $zero, $s0, $v1
    ctx->pc = 0x132b0cu;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 16);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x132b10: 0x50600001  beql        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x132B10u;
    {
        const bool branch_taken_0x132b10 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x132b10) {
            ctx->pc = 0x132B14u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x132B10u;
            // 0x132b14: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x132B18u;
            goto label_132b18;
        }
    }
    ctx->pc = 0x132B18u;
label_132b18:
    // 0x132b18: 0x8012  mflo        $s0
    ctx->pc = 0x132b18u;
    SET_GPR_U64(ctx, 16, ctx->lo);
    // 0x132b1c: 0x108140  sll         $s0, $s0, 5
    ctx->pc = 0x132b1cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 5));
    // 0x132b20: 0x44900000  mtc1        $s0, $f0
    ctx->pc = 0x132b20u;
    { uint32_t bits = GPR_U32(ctx, 16); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x132b24: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x132b24u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x132b28: 0x0  nop
    ctx->pc = 0x132b28u;
    // NOP
    // 0x132b2c: 0x0  nop
    ctx->pc = 0x132b2cu;
    // NOP
    // 0x132b30: 0x46010503  div.s       $f20, $f0, $f1
    ctx->pc = 0x132b30u;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[0]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[20] = std::bit_cast<float>(__maxf); } else ctx->f[20] = ctx->f[0] / ctx->f[1];
    // 0x132b34: 0x4600a006  mov.s       $f0, $f20
    ctx->pc = 0x132b34u;
    ctx->f[0] = FPU_MOV_S(ctx->f[20]);
label_132b38:
    // 0x132b38: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x132b38u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_132b3c:
    // 0x132b3c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x132b3cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x132b40: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x132b40u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x132b44: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x132b44u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x132b48: 0xc7b40020  lwc1        $f20, 0x20($sp)
    ctx->pc = 0x132b48u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 32)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x132b4c: 0x3e00008  jr          $ra
    ctx->pc = 0x132B4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x132B50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132B4Cu;
            // 0x132b50: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x132A1Cu: goto label_132a1c;
            case 0x132A28u: goto label_132a28;
            case 0x132A30u: goto label_132a30;
            case 0x132A50u: goto label_132a50;
            case 0x132A60u: goto label_132a60;
            case 0x132A64u: goto label_132a64;
            case 0x132AA0u: goto label_132aa0;
            case 0x132AB0u: goto label_132ab0;
            case 0x132AB8u: goto label_132ab8;
            case 0x132AE0u: goto label_132ae0;
            case 0x132AECu: goto label_132aec;
            case 0x132AF8u: goto label_132af8;
            case 0x132B18u: goto label_132b18;
            case 0x132B38u: goto label_132b38;
            case 0x132B3Cu: goto label_132b3c;
            case 0x132B78u: goto label_132b78;
            case 0x132B80u: goto label_132b80;
            case 0x132B9Cu: goto label_132b9c;
            case 0x132BB0u: goto label_132bb0;
            case 0x132BB4u: goto label_132bb4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x132B54u;
    // 0x132b54: 0x0  nop
    ctx->pc = 0x132b54u;
    // NOP
    // 0x132b58: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x132b58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x132b5c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x132b5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x132b60: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x132b60u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x132b64: 0x16000006  bnez        $s0, . + 4 + (0x6 << 2)
    ctx->pc = 0x132B64u;
    {
        const bool branch_taken_0x132b64 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x132B68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132B64u;
            // 0x132b68: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132b64) {
            ctx->pc = 0x132B80u;
            goto label_132b80;
        }
    }
    ctx->pc = 0x132B6Cu;
    // 0x132b6c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x132b6cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x132b70: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x132B70u;
    SET_GPR_U32(ctx, 31, 0x132B78u);
    ctx->pc = 0x132B74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132B70u;
            // 0x132b74: 0x2484b300  addiu       $a0, $a0, -0x4D00 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294947584));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132B78u; }
        if (ctx->pc != 0x132B78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132B78u; }
        if (ctx->pc != 0x132B78u) { return; }
    }
    ctx->pc = 0x132B78u;
label_132b78:
    // 0x132b78: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x132B78u;
    {
        const bool branch_taken_0x132b78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x132B7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132B78u;
            // 0x132b7c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132b78) {
            ctx->pc = 0x132BB4u;
            goto label_132bb4;
        }
    }
    ctx->pc = 0x132B80u;
label_132b80:
    // 0x132b80: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x132b80u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x132b84: 0x1060000a  beqz        $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x132B84u;
    {
        const bool branch_taken_0x132b84 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x132B88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132B84u;
            // 0x132b88: 0x60202d  daddu       $a0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132b84) {
            ctx->pc = 0x132BB0u;
            goto label_132bb0;
        }
    }
    ctx->pc = 0x132B8Cu;
    // 0x132b8c: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x132b8cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x132b90: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x132b90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x132b94: 0x40f809  jalr        $v0
    ctx->pc = 0x132B94u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x132B9Cu);
        ctx->pc = 0x132B98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132B94u;
            // 0x132b98: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x132B9Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x132A1Cu: goto label_132a1c;
            case 0x132A28u: goto label_132a28;
            case 0x132A30u: goto label_132a30;
            case 0x132A50u: goto label_132a50;
            case 0x132A60u: goto label_132a60;
            case 0x132A64u: goto label_132a64;
            case 0x132AA0u: goto label_132aa0;
            case 0x132AB0u: goto label_132ab0;
            case 0x132AB8u: goto label_132ab8;
            case 0x132AE0u: goto label_132ae0;
            case 0x132AECu: goto label_132aec;
            case 0x132AF8u: goto label_132af8;
            case 0x132B18u: goto label_132b18;
            case 0x132B38u: goto label_132b38;
            case 0x132B3Cu: goto label_132b3c;
            case 0x132B78u: goto label_132b78;
            case 0x132B80u: goto label_132b80;
            case 0x132B9Cu: goto label_132b9c;
            case 0x132BB0u: goto label_132bb0;
            case 0x132BB4u: goto label_132bb4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x132B9Cu; }
            if (ctx->pc != 0x132B9Cu) { return; }
        }
        }
    }
    ctx->pc = 0x132B9Cu;
label_132b9c:
    // 0x132b9c: 0x8603003e  lh          $v1, 0x3E($s0)
    ctx->pc = 0x132b9cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 62)));
    // 0x132ba0: 0x31ac0  sll         $v1, $v1, 11
    ctx->pc = 0x132ba0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 11));
    // 0x132ba4: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x132ba4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x132ba8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x132BA8u;
    {
        const bool branch_taken_0x132ba8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x132BACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132BA8u;
            // 0x132bac: 0x2c420001  sltiu       $v0, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x132ba8) {
            ctx->pc = 0x132BB4u;
            goto label_132bb4;
        }
    }
    ctx->pc = 0x132BB0u;
label_132bb0:
    // 0x132bb0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x132bb0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_132bb4:
    // 0x132bb4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x132bb4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132bb8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x132bb8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x132bbc: 0x3e00008  jr          $ra
    ctx->pc = 0x132BBCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x132BC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132BBCu;
            // 0x132bc0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x132A1Cu: goto label_132a1c;
            case 0x132A28u: goto label_132a28;
            case 0x132A30u: goto label_132a30;
            case 0x132A50u: goto label_132a50;
            case 0x132A60u: goto label_132a60;
            case 0x132A64u: goto label_132a64;
            case 0x132AA0u: goto label_132aa0;
            case 0x132AB0u: goto label_132ab0;
            case 0x132AB8u: goto label_132ab8;
            case 0x132AE0u: goto label_132ae0;
            case 0x132AECu: goto label_132aec;
            case 0x132AF8u: goto label_132af8;
            case 0x132B18u: goto label_132b18;
            case 0x132B38u: goto label_132b38;
            case 0x132B3Cu: goto label_132b3c;
            case 0x132B78u: goto label_132b78;
            case 0x132B80u: goto label_132b80;
            case 0x132B9Cu: goto label_132b9c;
            case 0x132BB0u: goto label_132bb0;
            case 0x132BB4u: goto label_132bb4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x132BC4u;
    // 0x132bc4: 0x0  nop
    ctx->pc = 0x132bc4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
