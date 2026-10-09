#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00165DD8
// Address: 0x165dd8 - 0x165ef0
void sub_00165DD8_0x165dd8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00165DD8_0x165dd8");
#endif

    switch (ctx->pc) {
        case 0x165decu: goto label_165dec;
        case 0x165e5cu: goto label_165e5c;
        case 0x165e70u: goto label_165e70;
        case 0x165e80u: goto label_165e80;
        case 0x165e94u: goto label_165e94;
        case 0x165eacu: goto label_165eac;
        case 0x165eccu: goto label_165ecc;
        default: break;
    }

    ctx->pc = 0x165dd8u;

    // 0x165dd8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x165dd8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x165ddc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x165ddcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x165de0: 0x8c821b74  lw          $v0, 0x1B74($a0)
    ctx->pc = 0x165de0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 7028)));
    // 0x165de4: 0xc04c78e  jal         func_131E38
    ctx->pc = 0x165DE4u;
    SET_GPR_U32(ctx, 31, 0x165DECu);
    ctx->pc = 0x165DE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165DE4u;
            // 0x165de8: 0x8c440000  lw          $a0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x131E38u;
    if (runtime->hasFunction(0x131E38u)) {
        auto targetFn = runtime->lookupFunction(0x131E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165DECu; }
        if (ctx->pc != 0x165DECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131E38_0x131e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165DECu; }
        if (ctx->pc != 0x165DECu) { return; }
    }
    ctx->pc = 0x165DECu;
label_165dec:
    // 0x165dec: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x165decu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165df0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x165df0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x165df4: 0x3e00008  jr          $ra
    ctx->pc = 0x165DF4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x165DF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165DF4u;
            // 0x165df8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x165DECu: goto label_165dec;
            case 0x165E50u: goto label_165e50;
            case 0x165E54u: goto label_165e54;
            case 0x165E5Cu: goto label_165e5c;
            case 0x165E68u: goto label_165e68;
            case 0x165E70u: goto label_165e70;
            case 0x165E80u: goto label_165e80;
            case 0x165E94u: goto label_165e94;
            case 0x165EACu: goto label_165eac;
            case 0x165ECCu: goto label_165ecc;
            case 0x165ED0u: goto label_165ed0;
            case 0x165ED4u: goto label_165ed4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x165DFCu;
    // 0x165dfc: 0x0  nop
    ctx->pc = 0x165dfcu;
    // NOP
    // 0x165e00: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x165e00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x165e04: 0xa0182d  daddu       $v1, $a1, $zero
    ctx->pc = 0x165e04u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165e08: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x165e08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x165e0c: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x165e0cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165e10: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x165e10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x165e14: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x165e14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x165e18: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x165e18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x165e1c: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x165e1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x165e20: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x165e20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x165e24: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x165e24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x165e28: 0x8e931b74  lw          $s3, 0x1B74($s4)
    ctx->pc = 0x165e28u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 7028)));
    // 0x165e2c: 0x10620009  beq         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x165E2Cu;
    {
        const bool branch_taken_0x165e2c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x165E30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165E2Cu;
            // 0x165e30: 0x8e720000  lw          $s2, 0x0($s3) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x165e2c) {
            ctx->pc = 0x165E54u;
            goto label_165e54;
        }
    }
    ctx->pc = 0x165E34u;
    // 0x165e34: 0x50600006  beql        $v1, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x165E34u;
    {
        const bool branch_taken_0x165e34 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x165e34) {
            ctx->pc = 0x165E38u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x165E34u;
            // 0x165e38: 0xae600030  sw          $zero, 0x30($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 48), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x165E50u;
            goto label_165e50;
        }
    }
    ctx->pc = 0x165E3Cu;
    // 0x165e3c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x165e3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x165e40: 0x10620009  beq         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x165E40u;
    {
        const bool branch_taken_0x165e40 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x165E44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165E40u;
            // 0x165e44: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x165e40) {
            ctx->pc = 0x165E68u;
            goto label_165e68;
        }
    }
    ctx->pc = 0x165E48u;
    // 0x165e48: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x165E48u;
    {
        const bool branch_taken_0x165e48 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x165E4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165E48u;
            // 0x165e4c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x165e48) {
            ctx->pc = 0x165ED4u;
            goto label_165ed4;
        }
    }
    ctx->pc = 0x165E50u;
label_165e50:
    // 0x165e50: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x165e50u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_165e54:
    // 0x165e54: 0xc0597d0  jal         func_165F40
    ctx->pc = 0x165E54u;
    SET_GPR_U32(ctx, 31, 0x165E5Cu);
    ctx->pc = 0x165F40u;
    if (runtime->hasFunction(0x165F40u)) {
        auto targetFn = runtime->lookupFunction(0x165F40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165E5Cu; }
        if (ctx->pc != 0x165E5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00165F40_0x165f40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165E5Cu; }
        if (ctx->pc != 0x165E5Cu) { return; }
    }
    ctx->pc = 0x165E5Cu;
label_165e5c:
    // 0x165e5c: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x165E5Cu;
    {
        const bool branch_taken_0x165e5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x165E60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165E5Cu;
            // 0x165e60: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x165e5c) {
            ctx->pc = 0x165ED0u;
            goto label_165ed0;
        }
    }
    ctx->pc = 0x165E64u;
    // 0x165e64: 0x0  nop
    ctx->pc = 0x165e64u;
    // NOP
label_165e68:
    // 0x165e68: 0xc0595ba  jal         func_1656E8
    ctx->pc = 0x165E68u;
    SET_GPR_U32(ctx, 31, 0x165E70u);
    ctx->pc = 0x165E6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165E68u;
            // 0x165e6c: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1656E8u;
    if (runtime->hasFunction(0x1656E8u)) {
        auto targetFn = runtime->lookupFunction(0x1656E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165E70u; }
        if (ctx->pc != 0x165E70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001656E8_0x1656e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165E70u; }
        if (ctx->pc != 0x165E70u) { return; }
    }
    ctx->pc = 0x165E70u;
label_165e70:
    // 0x165e70: 0x10400017  beqz        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x165E70u;
    {
        const bool branch_taken_0x165e70 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x165E74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165E70u;
            // 0x165e74: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x165e70) {
            ctx->pc = 0x165ED0u;
            goto label_165ed0;
        }
    }
    ctx->pc = 0x165E78u;
    // 0x165e78: 0xc04c93e  jal         func_1324F8
    ctx->pc = 0x165E78u;
    SET_GPR_U32(ctx, 31, 0x165E80u);
    ctx->pc = 0x165E7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165E78u;
            // 0x165e7c: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1324F8u;
    if (runtime->hasFunction(0x1324F8u)) {
        auto targetFn = runtime->lookupFunction(0x1324F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165E80u; }
        if (ctx->pc != 0x165E80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001324F8_0x1324f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165E80u; }
        if (ctx->pc != 0x165E80u) { return; }
    }
    ctx->pc = 0x165E80u;
label_165e80:
    // 0x165e80: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x165e80u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165e84: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x165e84u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165e88: 0x27a50010  addiu       $a1, $sp, 0x10
    ctx->pc = 0x165e88u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x165e8c: 0xc0597f2  jal         func_165FC8
    ctx->pc = 0x165E8Cu;
    SET_GPR_U32(ctx, 31, 0x165E94u);
    ctx->pc = 0x165E90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165E8Cu;
            // 0x165e90: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x165FC8u;
    if (runtime->hasFunction(0x165FC8u)) {
        auto targetFn = runtime->lookupFunction(0x165FC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165E94u; }
        if (ctx->pc != 0x165E94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00165FC8_0x165fc8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165E94u; }
        if (ctx->pc != 0x165E94u) { return; }
    }
    ctx->pc = 0x165E94u;
label_165e94:
    // 0x165e94: 0x8e620030  lw          $v0, 0x30($s3)
    ctx->pc = 0x165e94u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 48)));
    // 0x165e98: 0x8fb00010  lw          $s0, 0x10($sp)
    ctx->pc = 0x165e98u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x165e9c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x165e9cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165ea0: 0x2028021  addu        $s0, $s0, $v0
    ctx->pc = 0x165ea0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x165ea4: 0xc04cc16  jal         func_133058
    ctx->pc = 0x165EA4u;
    SET_GPR_U32(ctx, 31, 0x165EACu);
    ctx->pc = 0x165EA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165EA4u;
            // 0x165ea8: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x133058u;
    if (runtime->hasFunction(0x133058u)) {
        auto targetFn = runtime->lookupFunction(0x133058u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165EACu; }
        if (ctx->pc != 0x165EACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00133058_0x133058(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165EACu; }
        if (ctx->pc != 0x165EACu) { return; }
    }
    ctx->pc = 0x165EACu;
label_165eac:
    // 0x165eac: 0x26840f60  addiu       $a0, $s4, 0xF60
    ctx->pc = 0x165eacu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), 3936));
    // 0x165eb0: 0x2028023  subu        $s0, $s0, $v0
    ctx->pc = 0x165eb0u;
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x165eb4: 0x8fa20010  lw          $v0, 0x10($sp)
    ctx->pc = 0x165eb4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x165eb8: 0xae700030  sw          $s0, 0x30($s3)
    ctx->pc = 0x165eb8u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 48), GPR_U32(ctx, 16));
    // 0x165ebc: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x165ebcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165ec0: 0xffa20000  sd          $v0, 0x0($sp)
    ctx->pc = 0x165ec0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 2));
    // 0x165ec4: 0xc05df96  jal         func_177E58
    ctx->pc = 0x165EC4u;
    SET_GPR_U32(ctx, 31, 0x165ECCu);
    ctx->pc = 0x165EC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165EC4u;
            // 0x165ec8: 0xffb10008  sd          $s1, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177E58u;
    if (runtime->hasFunction(0x177E58u)) {
        auto targetFn = runtime->lookupFunction(0x177E58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165ECCu; }
        if (ctx->pc != 0x165ECCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177E58_0x177e58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165ECCu; }
        if (ctx->pc != 0x165ECCu) { return; }
    }
    ctx->pc = 0x165ECCu;
label_165ecc:
    // 0x165ecc: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x165eccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_165ed0:
    // 0x165ed0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x165ed0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_165ed4:
    // 0x165ed4: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x165ed4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x165ed8: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x165ed8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x165edc: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x165edcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x165ee0: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x165ee0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x165ee4: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x165ee4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x165ee8: 0x3e00008  jr          $ra
    ctx->pc = 0x165EE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x165EECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165EE8u;
            // 0x165eec: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x165DECu: goto label_165dec;
            case 0x165E50u: goto label_165e50;
            case 0x165E54u: goto label_165e54;
            case 0x165E5Cu: goto label_165e5c;
            case 0x165E68u: goto label_165e68;
            case 0x165E70u: goto label_165e70;
            case 0x165E80u: goto label_165e80;
            case 0x165E94u: goto label_165e94;
            case 0x165EACu: goto label_165eac;
            case 0x165ECCu: goto label_165ecc;
            case 0x165ED0u: goto label_165ed0;
            case 0x165ED4u: goto label_165ed4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x165EF0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
