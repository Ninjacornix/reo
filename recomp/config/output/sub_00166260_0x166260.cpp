#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00166260
// Address: 0x166260 - 0x1662dc
void sub_00166260_0x166260(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00166260_0x166260");
#endif

    switch (ctx->pc) {
        case 0x16627cu: goto label_16627c;
        case 0x1662acu: goto label_1662ac;
        case 0x1662c8u: goto label_1662c8;
        default: break;
    }

    ctx->pc = 0x166260u;

    // 0x166260: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x166260u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x166264: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x166264u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x166268: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x166268u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16626c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16626cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x166270: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x166270u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x166274: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x166274u;
    SET_GPR_U32(ctx, 31, 0x16627Cu);
    ctx->pc = 0x166278u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166274u;
            // 0x166278: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16627Cu; }
        if (ctx->pc != 0x16627Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16627Cu; }
        if (ctx->pc != 0x16627Cu) { return; }
    }
    ctx->pc = 0x16627Cu;
label_16627c:
    // 0x16627c: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16627cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x166280: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x166280u;
    {
        const bool branch_taken_0x166280 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x166284u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166280u;
            // 0x166284: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x166280) {
            ctx->pc = 0x1662A0u;
            goto label_1662a0;
        }
    }
    ctx->pc = 0x166288u;
    // 0x166288: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x166288u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16628c: 0x34a501a3  ori         $a1, $a1, 0x1A3
    ctx->pc = 0x16628cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)419);
    // 0x166290: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x166290u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x166294: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x166294u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x166298: 0x805a704  j           func_169C10
    ctx->pc = 0x166298u;
    ctx->pc = 0x16629Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166298u;
            // 0x16629c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1662A0u;
label_1662a0:
    // 0x1662a0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1662a0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1662a4: 0xc05d58a  jal         func_175628
    ctx->pc = 0x1662A4u;
    SET_GPR_U32(ctx, 31, 0x1662ACu);
    ctx->pc = 0x1662A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1662A4u;
            // 0x1662a8: 0x24050006  addiu       $a1, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1662ACu; }
        if (ctx->pc != 0x1662ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1662ACu; }
        if (ctx->pc != 0x1662ACu) { return; }
    }
    ctx->pc = 0x1662ACu;
label_1662ac:
    // 0x1662ac: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1662acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1662b0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1662B0u;
    {
        const bool branch_taken_0x1662b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1662B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1662B0u;
            // 0x1662b4: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1662b0) {
            ctx->pc = 0x1662C8u;
            goto label_1662c8;
        }
    }
    ctx->pc = 0x1662B8u;
    // 0x1662b8: 0x8e021c84  lw          $v0, 0x1C84($s0)
    ctx->pc = 0x1662b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 7300)));
    // 0x1662bc: 0x8c43000c  lw          $v1, 0xC($v0)
    ctx->pc = 0x1662bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x1662c0: 0x60f809  jalr        $v1
    ctx->pc = 0x1662C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x1662C8u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1662C8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16627Cu: goto label_16627c;
            case 0x1662A0u: goto label_1662a0;
            case 0x1662ACu: goto label_1662ac;
            case 0x1662C8u: goto label_1662c8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1662C8u; }
            if (ctx->pc != 0x1662C8u) { return; }
        }
        }
    }
    ctx->pc = 0x1662C8u;
label_1662c8:
    // 0x1662c8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1662c8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1662cc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1662ccu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1662d0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1662d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1662d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1662D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1662D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1662D4u;
            // 0x1662d8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16627Cu: goto label_16627c;
            case 0x1662A0u: goto label_1662a0;
            case 0x1662ACu: goto label_1662ac;
            case 0x1662C8u: goto label_1662c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1662DCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
