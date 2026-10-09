#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00174FC8
// Address: 0x174fc8 - 0x17504c
void sub_00174FC8_0x174fc8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00174FC8_0x174fc8");
#endif

    switch (ctx->pc) {
        case 0x174fecu: goto label_174fec;
        case 0x175030u: goto label_175030;
        default: break;
    }

    ctx->pc = 0x174fc8u;

    // 0x174fc8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x174fc8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x174fcc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x174fccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x174fd0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x174fd0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174fd4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x174fd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x174fd8: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x174fd8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174fdc: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x174fdcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x174fe0: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x174fe0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x174fe4: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x174FE4u;
    SET_GPR_U32(ctx, 31, 0x174FECu);
    ctx->pc = 0x174FE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x174FE4u;
            // 0x174fe8: 0xa0902d  daddu       $s2, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174FECu; }
        if (ctx->pc != 0x174FECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174FECu; }
        if (ctx->pc != 0x174FECu) { return; }
    }
    ctx->pc = 0x174FECu;
label_174fec:
    // 0x174fec: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x174fecu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x174ff0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x174ff0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174ff4: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x174FF4u;
    {
        const bool branch_taken_0x174ff4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x174FF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174FF4u;
            // 0x174ff8: 0x34a5015a  ori         $a1, $a1, 0x15A (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)346);
        ctx->in_delay_slot = false;
        if (branch_taken_0x174ff4) {
            ctx->pc = 0x175018u;
            goto label_175018;
        }
    }
    ctx->pc = 0x174FFCu;
    // 0x174ffc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x174ffcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x175000: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x175000u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x175004: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x175004u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x175008: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x175008u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17500c: 0x805a704  j           func_169C10
    ctx->pc = 0x17500Cu;
    ctx->pc = 0x175010u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17500Cu;
            // 0x175010: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x175014u;
    // 0x175014: 0x0  nop
    ctx->pc = 0x175014u;
    // NOP
label_175018:
    // 0x175018: 0x8e032ab0  lw          $v1, 0x2AB0($s0)
    ctx->pc = 0x175018u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 10928)));
    // 0x17501c: 0x10600005  beqz        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x17501Cu;
    {
        const bool branch_taken_0x17501c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x175020u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17501Cu;
            // 0x175020: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17501c) {
            ctx->pc = 0x175034u;
            goto label_175034;
        }
    }
    ctx->pc = 0x175024u;
    // 0x175024: 0xac710db8  sw          $s1, 0xDB8($v1)
    ctx->pc = 0x175024u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 3512), GPR_U32(ctx, 17));
    // 0x175028: 0xc05d496  jal         func_175258
    ctx->pc = 0x175028u;
    SET_GPR_U32(ctx, 31, 0x175030u);
    ctx->pc = 0x17502Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x175028u;
            // 0x17502c: 0xac720db4  sw          $s2, 0xDB4($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 3508), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175258u;
    if (runtime->hasFunction(0x175258u)) {
        auto targetFn = runtime->lookupFunction(0x175258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175030u; }
        if (ctx->pc != 0x175030u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175258_0x175258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175030u; }
        if (ctx->pc != 0x175030u) { return; }
    }
    ctx->pc = 0x175030u;
label_175030:
    // 0x175030: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x175030u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_175034:
    // 0x175034: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x175034u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x175038: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x175038u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17503c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17503cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x175040: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x175040u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x175044: 0x3e00008  jr          $ra
    ctx->pc = 0x175044u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x175048u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175044u;
            // 0x175048: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x174FECu: goto label_174fec;
            case 0x175018u: goto label_175018;
            case 0x175030u: goto label_175030;
            case 0x175034u: goto label_175034;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17504Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
