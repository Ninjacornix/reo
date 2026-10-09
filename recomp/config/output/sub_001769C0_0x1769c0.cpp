#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001769C0
// Address: 0x1769c0 - 0x176a60
void sub_001769C0_0x1769c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001769C0_0x1769c0");
#endif

    switch (ctx->pc) {
        case 0x176a2cu: goto label_176a2c;
        case 0x176a4cu: goto label_176a4c;
        default: break;
    }

    ctx->pc = 0x1769c0u;

    // 0x1769c0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1769c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1769c4: 0x80402d  daddu       $t0, $a0, $zero
    ctx->pc = 0x1769c4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1769c8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1769c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1769cc: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x1769ccu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1769d0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1769d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1769d4: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1769d4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1769d8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1769d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1769dc: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1769dcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1769e0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1769e0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1769e4: 0x34a50221  ori         $a1, $a1, 0x221
    ctx->pc = 0x1769e4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)545);
    // 0x1769e8: 0x8d020000  lw          $v0, 0x0($t0)
    ctx->pc = 0x1769e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1769ec: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1769ecu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1769f0: 0x8d070004  lw          $a3, 0x4($t0)
    ctx->pc = 0x1769f0u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 4)));
    // 0x1769f4: 0x21840  sll         $v1, $v0, 1
    ctx->pc = 0x1769f4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1769f8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1769f8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1769fc: 0x671821  addu        $v1, $v1, $a3
    ctx->pc = 0x1769fcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x176a00: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x176a00u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x176a04: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x176a04u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x176a08: 0x220821  addu        $at, $at, $v0
    ctx->pc = 0x176a08u;
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x176a0c: 0x8c220af0  lw          $v0, 0xAF0($at)
    ctx->pc = 0x176a0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2800)));
    // 0x176a10: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x176a10u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x176a14: 0x230821  addu        $at, $at, $v1
    ctx->pc = 0x176a14u;
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0x176a18: 0x8c230b18  lw          $v1, 0xB18($at)
    ctx->pc = 0x176a18u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2840)));
    // 0x176a1c: 0x14600008  bnez        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x176A1Cu;
    {
        const bool branch_taken_0x176a1c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x176A20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176A1Cu;
            // 0x176a20: 0x200382d  daddu       $a3, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x176a1c) {
            ctx->pc = 0x176A40u;
            goto label_176a40;
        }
    }
    ctx->pc = 0x176A24u;
    // 0x176a24: 0xc05a704  jal         func_169C10
    ctx->pc = 0x176A24u;
    SET_GPR_U32(ctx, 31, 0x176A2Cu);
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176A2Cu; }
        if (ctx->pc != 0x176A2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176A2Cu; }
        if (ctx->pc != 0x176A2Cu) { return; }
    }
    ctx->pc = 0x176A2Cu;
label_176a2c:
    // 0x176a2c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x176a2cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x176a30: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x176a30u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x176a34: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x176A34u;
    {
        const bool branch_taken_0x176a34 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x176A38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176A34u;
            // 0x176a38: 0xae030000  sw          $v1, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x176a34) {
            ctx->pc = 0x176A4Cu;
            goto label_176a4c;
        }
    }
    ctx->pc = 0x176A3Cu;
    // 0x176a3c: 0x0  nop
    ctx->pc = 0x176a3cu;
    // NOP
label_176a40:
    // 0x176a40: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x176a40u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176a44: 0x60f809  jalr        $v1
    ctx->pc = 0x176A44u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x176A4Cu);
        ctx->pc = 0x176A48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176A44u;
            // 0x176a48: 0x100282d  daddu       $a1, $t0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x176A4Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x176A2Cu: goto label_176a2c;
            case 0x176A40u: goto label_176a40;
            case 0x176A4Cu: goto label_176a4c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x176A4Cu; }
            if (ctx->pc != 0x176A4Cu) { return; }
        }
        }
    }
    ctx->pc = 0x176A4Cu;
label_176a4c:
    // 0x176a4c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x176a4cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x176a50: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x176a50u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x176a54: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x176a54u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x176a58: 0x3e00008  jr          $ra
    ctx->pc = 0x176A58u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x176A5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176A58u;
            // 0x176a5c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x176A2Cu: goto label_176a2c;
            case 0x176A40u: goto label_176a40;
            case 0x176A4Cu: goto label_176a4c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x176A60u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
