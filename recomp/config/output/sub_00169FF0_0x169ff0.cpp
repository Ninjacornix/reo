#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00169FF0
// Address: 0x169ff0 - 0x16a110
void sub_00169FF0_0x169ff0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00169FF0_0x169ff0");
#endif

    switch (ctx->pc) {
        case 0x16a024u: goto label_16a024;
        case 0x16a0b0u: goto label_16a0b0;
        case 0x16a0b8u: goto label_16a0b8;
        case 0x16a0e4u: goto label_16a0e4;
        default: break;
    }

    ctx->pc = 0x169ff0u;

    // 0x169ff0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x169ff0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x169ff4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x169ff4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x169ff8: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x169ff8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169ffc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x169ffcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16a000: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x16a000u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a004: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16a004u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x16a008: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x16a008u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a00c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x16a00cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x16a010: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x16a010u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a014: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x16a014u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x16a018: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x16a018u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x16a01c: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x16A01Cu;
    SET_GPR_U32(ctx, 31, 0x16A024u);
    ctx->pc = 0x16A020u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A01Cu;
            // 0x16a020: 0x100a02d  daddu       $s4, $t0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A024u; }
        if (ctx->pc != 0x16A024u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A024u; }
        if (ctx->pc != 0x16A024u) { return; }
    }
    ctx->pc = 0x16A024u;
label_16a024:
    // 0x16a024: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16a024u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x16a028: 0x2623ff44  addiu       $v1, $s1, -0xBC
    ctx->pc = 0x16a028u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967108));
    // 0x16a02c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x16a02cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a030: 0x34a50171  ori         $a1, $a1, 0x171
    ctx->pc = 0x16a030u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)369);
    // 0x16a034: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x16A034u;
    {
        const bool branch_taken_0x16a034 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16A038u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A034u;
            // 0x16a038: 0x2c630044  sltiu       $v1, $v1, 0x44 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)68) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a034) {
            ctx->pc = 0x16A060u;
            goto label_16a060;
        }
    }
    ctx->pc = 0x16A03Cu;
    // 0x16a03c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16a03cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16a040: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16a040u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16a044: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16a044u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16a048: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x16a048u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16a04c: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x16a04cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16a050: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x16a050u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16a054: 0x805a704  j           func_169C10
    ctx->pc = 0x16A054u;
    ctx->pc = 0x16A058u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A054u;
            // 0x16a058: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16A05Cu;
    // 0x16a05c: 0x0  nop
    ctx->pc = 0x16a05cu;
    // NOP
label_16a060:
    // 0x16a060: 0x50600008  beql        $v1, $zero, . + 4 + (0x8 << 2)
    ctx->pc = 0x16A060u;
    {
        const bool branch_taken_0x16a060 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x16a060) {
            ctx->pc = 0x16A064u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16A060u;
            // 0x16a064: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16A084u;
            goto label_16a084;
        }
    }
    ctx->pc = 0x16A068u;
    // 0x16a068: 0x8e041aec  lw          $a0, 0x1AEC($s0)
    ctx->pc = 0x16a068u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 6892)));
    // 0x16a06c: 0x111880  sll         $v1, $s1, 2
    ctx->pc = 0x16a06cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
    // 0x16a070: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x16a070u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x16a074: 0xac930144  sw          $s3, 0x144($a0)
    ctx->pc = 0x16a074u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 324), GPR_U32(ctx, 19));
    // 0x16a078: 0xac72fd44  sw          $s2, -0x2BC($v1)
    ctx->pc = 0x16a078u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294966596), GPR_U32(ctx, 18));
    // 0x16a07c: 0xac940148  sw          $s4, 0x148($a0)
    ctx->pc = 0x16a07cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 328), GPR_U32(ctx, 20));
    // 0x16a080: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16a080u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_16a084:
    // 0x16a084: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16a084u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16a088: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16a088u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16a08c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x16a08cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16a090: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x16a090u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16a094: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x16a094u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16a098: 0x3e00008  jr          $ra
    ctx->pc = 0x16A098u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16A09Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A098u;
            // 0x16a09c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16A024u: goto label_16a024;
            case 0x16A060u: goto label_16a060;
            case 0x16A084u: goto label_16a084;
            case 0x16A0B0u: goto label_16a0b0;
            case 0x16A0B8u: goto label_16a0b8;
            case 0x16A0D8u: goto label_16a0d8;
            case 0x16A0E4u: goto label_16a0e4;
            case 0x16A100u: goto label_16a100;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16A0A0u;
    // 0x16a0a0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x16a0a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16a0a4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16a0a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x16a0a8: 0xc05a844  jal         func_16A110
    ctx->pc = 0x16A0A8u;
    SET_GPR_U32(ctx, 31, 0x16A0B0u);
    ctx->pc = 0x16A110u;
    if (runtime->hasFunction(0x16A110u)) {
        auto targetFn = runtime->lookupFunction(0x16A110u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A0B0u; }
        if (ctx->pc != 0x16A0B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016A110_0x16a110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A0B0u; }
        if (ctx->pc != 0x16A0B0u) { return; }
    }
    ctx->pc = 0x16A0B0u;
label_16a0b0:
    // 0x16a0b0: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x16A0B0u;
    {
        const bool branch_taken_0x16a0b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16A0B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A0B0u;
            // 0x16a0b4: 0x3c050027  lui         $a1, 0x27 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)39 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a0b0) {
            ctx->pc = 0x16A0D8u;
            goto label_16a0d8;
        }
    }
    ctx->pc = 0x16A0B8u;
label_16a0b8:
    // 0x16a0b8: 0x0  nop
    ctx->pc = 0x16a0b8u;
    // NOP
    // 0x16a0bc: 0x0  nop
    ctx->pc = 0x16a0bcu;
    // NOP
    // 0x16a0c0: 0x0  nop
    ctx->pc = 0x16a0c0u;
    // NOP
    // 0x16a0c4: 0x0  nop
    ctx->pc = 0x16a0c4u;
    // NOP
    // 0x16a0c8: 0x0  nop
    ctx->pc = 0x16a0c8u;
    // NOP
    // 0x16a0cc: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x16A0CCu;
    {
        const bool branch_taken_0x16a0cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x16a0cc) {
            ctx->pc = 0x16A0B8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_16a0b8;
        }
    }
    ctx->pc = 0x16A0D4u;
    // 0x16a0d4: 0x0  nop
    ctx->pc = 0x16a0d4u;
    // NOP
label_16a0d8:
    // 0x16a0d8: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x16a0d8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x16a0dc: 0xc05600c  jal         func_158030
    ctx->pc = 0x16A0DCu;
    SET_GPR_U32(ctx, 31, 0x16A0E4u);
    ctx->pc = 0x16A0E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A0DCu;
            // 0x16a0e0: 0x24a51a18  addiu       $a1, $a1, 0x1A18 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 6680));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158030u;
    if (runtime->hasFunction(0x158030u)) {
        auto targetFn = runtime->lookupFunction(0x158030u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A0E4u; }
        if (ctx->pc != 0x16A0E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00158030_0x158030(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A0E4u; }
        if (ctx->pc != 0x16A0E4u) { return; }
    }
    ctx->pc = 0x16A0E4u;
label_16a0e4:
    // 0x16a0e4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x16A0E4u;
    {
        const bool branch_taken_0x16a0e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16A0E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A0E4u;
            // 0x16a0e8: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a0e4) {
            ctx->pc = 0x16A100u;
            goto label_16a100;
        }
    }
    ctx->pc = 0x16A0ECu;
    // 0x16a0ec: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16a0ecu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x16a0f0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x16a0f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a0f4: 0x34a50d01  ori         $a1, $a1, 0xD01
    ctx->pc = 0x16a0f4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3329);
    // 0x16a0f8: 0x805a704  j           func_169C10
    ctx->pc = 0x16A0F8u;
    ctx->pc = 0x16A0FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A0F8u;
            // 0x16a0fc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16A100u;
label_16a100:
    // 0x16a100: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x16a100u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x16a104: 0xac60f1b0  sw          $zero, -0xE50($v1)
    ctx->pc = 0x16a104u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294963632), GPR_U32(ctx, 0));
    // 0x16a108: 0x3e00008  jr          $ra
    ctx->pc = 0x16A108u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16A10Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A108u;
            // 0x16a10c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16A024u: goto label_16a024;
            case 0x16A060u: goto label_16a060;
            case 0x16A084u: goto label_16a084;
            case 0x16A0B0u: goto label_16a0b0;
            case 0x16A0B8u: goto label_16a0b8;
            case 0x16A0D8u: goto label_16a0d8;
            case 0x16A0E4u: goto label_16a0e4;
            case 0x16A100u: goto label_16a100;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16A110u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
