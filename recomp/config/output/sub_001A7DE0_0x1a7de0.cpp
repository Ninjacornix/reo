#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A7DE0
// Address: 0x1a7de0 - 0x1a7f50
void sub_001A7DE0_0x1a7de0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A7DE0_0x1a7de0");
#endif

    switch (ctx->pc) {
        case 0x1a7e08u: goto label_1a7e08;
        case 0x1a7e24u: goto label_1a7e24;
        case 0x1a7e30u: goto label_1a7e30;
        case 0x1a7e38u: goto label_1a7e38;
        case 0x1a7e4cu: goto label_1a7e4c;
        case 0x1a7ef8u: goto label_1a7ef8;
        case 0x1a7f0cu: goto label_1a7f0c;
        case 0x1a7f18u: goto label_1a7f18;
        case 0x1a7f30u: goto label_1a7f30;
        default: break;
    }

    ctx->pc = 0x1a7de0u;

    // 0x1a7de0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1a7de0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1a7de4: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1a7de4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1a7de8: 0x7fb20030  sq          $s2, 0x30($sp)
    ctx->pc = 0x1a7de8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 18));
    // 0x1a7dec: 0x7fb10020  sq          $s1, 0x20($sp)
    ctx->pc = 0x1a7decu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 17));
    // 0x1a7df0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1a7df0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a7df4: 0x12200008  beqz        $s1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1A7DF4u;
    {
        const bool branch_taken_0x1a7df4 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A7DF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7DF4u;
            // 0x1a7df8: 0x7fb00010  sq          $s0, 0x10($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7df4) {
            ctx->pc = 0x1A7E18u;
            goto label_1a7e18;
        }
    }
    ctx->pc = 0x1A7DFCu;
    // 0x1a7dfc: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1a7dfcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1a7e00: 0xc04519c  jal         func_114670
    ctx->pc = 0x1A7E00u;
    SET_GPR_U32(ctx, 31, 0x1A7E08u);
    ctx->pc = 0x1A7E04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7E00u;
            // 0x1a7e04: 0x8c241180  lw          $a0, 0x1180($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4480)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114670u;
    if (runtime->hasFunction(0x114670u)) {
        auto targetFn = runtime->lookupFunction(0x114670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7E08u; }
        if (ctx->pc != 0x1A7E08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114670_0x114670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7E08u; }
        if (ctx->pc != 0x1A7E08u) { return; }
    }
    ctx->pc = 0x1A7E08u;
label_1a7e08:
    // 0x1a7e08: 0x4410006  bgez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A7E08u;
    {
        const bool branch_taken_0x1a7e08 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1a7e08) {
            ctx->pc = 0x1A7E24u;
            goto label_1a7e24;
        }
    }
    ctx->pc = 0x1A7E10u;
    // 0x1a7e10: 0x10000048  b           . + 4 + (0x48 << 2)
    ctx->pc = 0x1A7E10u;
    {
        const bool branch_taken_0x1a7e10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A7E14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7E10u;
            // 0x1a7e14: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7e10) {
            ctx->pc = 0x1A7F34u;
            goto label_1a7f34;
        }
    }
    ctx->pc = 0x1A7E18u;
label_1a7e18:
    // 0x1a7e18: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1a7e18u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1a7e1c: 0xc045198  jal         func_114660
    ctx->pc = 0x1A7E1Cu;
    SET_GPR_U32(ctx, 31, 0x1A7E24u);
    ctx->pc = 0x1A7E20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7E1Cu;
            // 0x1a7e20: 0x8c241180  lw          $a0, 0x1180($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4480)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7E24u; }
        if (ctx->pc != 0x1A7E24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7E24u; }
        if (ctx->pc != 0x1A7E24u) { return; }
    }
    ctx->pc = 0x1A7E24u;
label_1a7e24:
    // 0x1a7e24: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a7e24u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a7e28: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1A7E28u;
    {
        const bool branch_taken_0x1a7e28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A7E2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7E28u;
            // 0x1a7e2c: 0x8c300a70  lw          $s0, 0xA70($at) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2672)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7e28) {
            ctx->pc = 0x1A7E70u;
            goto label_1a7e70;
        }
    }
    ctx->pc = 0x1A7E30u;
label_1a7e30:
    // 0x1a7e30: 0xc06a168  jal         func_1A85A0
    ctx->pc = 0x1A7E30u;
    SET_GPR_U32(ctx, 31, 0x1A7E38u);
    ctx->pc = 0x1A7E34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7E30u;
            // 0x1a7e34: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A85A0u;
    if (runtime->hasFunction(0x1A85A0u)) {
        auto targetFn = runtime->lookupFunction(0x1A85A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7E38u; }
        if (ctx->pc != 0x1A7E38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A85A0_0x1a85a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7E38u; }
        if (ctx->pc != 0x1A7E38u) { return; }
    }
    ctx->pc = 0x1A7E38u;
label_1a7e38:
    // 0x1a7e38: 0x4410006  bgez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A7E38u;
    {
        const bool branch_taken_0x1a7e38 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1A7E3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7E38u;
            // 0x1a7e3c: 0x2403ffff  addiu       $v1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7e38) {
            ctx->pc = 0x1A7E54u;
            goto label_1a7e54;
        }
    }
    ctx->pc = 0x1A7E40u;
    // 0x1a7e40: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1a7e40u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1a7e44: 0xc0423b4  jal         func_108ED0
    ctx->pc = 0x1A7E44u;
    SET_GPR_U32(ctx, 31, 0x1A7E4Cu);
    ctx->pc = 0x1A7E48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7E44u;
            // 0x1a7e48: 0x248423f0  addiu       $a0, $a0, 0x23F0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9200));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108ED0u;
    if (runtime->hasFunction(0x108ED0u)) {
        auto targetFn = runtime->lookupFunction(0x108ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7E4Cu; }
        if (ctx->pc != 0x1A7E4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108ED0_0x108ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7E4Cu; }
        if (ctx->pc != 0x1A7E4Cu) { return; }
    }
    ctx->pc = 0x1A7E4Cu;
label_1a7e4c:
    // 0x1a7e4c: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1A7E4Cu;
    {
        const bool branch_taken_0x1a7e4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a7e4c) {
            ctx->pc = 0x1A7E94u;
            goto label_1a7e94;
        }
    }
    ctx->pc = 0x1A7E54u;
label_1a7e54:
    // 0x1a7e54: 0x26020001  addiu       $v0, $s0, 0x1
    ctx->pc = 0x1a7e54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1a7e58: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x1a7e58u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
    // 0x1a7e5c: 0x4410004  bgez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1A7E5Cu;
    {
        const bool branch_taken_0x1a7e5c = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1A7E60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7E5Cu;
            // 0x1a7e60: 0x3050001f  andi        $s0, $v0, 0x1F (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)31);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7e5c) {
            ctx->pc = 0x1A7E70u;
            goto label_1a7e70;
        }
    }
    ctx->pc = 0x1A7E64u;
    // 0x1a7e64: 0x12000002  beqz        $s0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1A7E64u;
    {
        const bool branch_taken_0x1a7e64 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a7e64) {
            ctx->pc = 0x1A7E70u;
            goto label_1a7e70;
        }
    }
    ctx->pc = 0x1A7E6Cu;
    // 0x1a7e6c: 0x2610ffe0  addiu       $s0, $s0, -0x20
    ctx->pc = 0x1a7e6cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967264));
label_1a7e70:
    // 0x1a7e70: 0x101840  sll         $v1, $s0, 1
    ctx->pc = 0x1a7e70u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
    // 0x1a7e74: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1a7e74u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1a7e78: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x1a7e78u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1a7e7c: 0x24420a80  addiu       $v0, $v0, 0xA80
    ctx->pc = 0x1a7e7cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2688));
    // 0x1a7e80: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1a7e80u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1a7e84: 0x439021  addu        $s2, $v0, $v1
    ctx->pc = 0x1a7e84u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a7e88: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x1a7e88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1a7e8c: 0x441ffe8  bgez        $v0, . + 4 + (-0x18 << 2)
    ctx->pc = 0x1A7E8Cu;
    {
        const bool branch_taken_0x1a7e8c = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1a7e8c) {
            ctx->pc = 0x1A7E30u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a7e30;
        }
    }
    ctx->pc = 0x1A7E94u;
label_1a7e94:
    // 0x1a7e94: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a7e94u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a7e98: 0xac300a70  sw          $s0, 0xA70($at)
    ctx->pc = 0x1a7e98u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 2672), GPR_U32(ctx, 16));
    // 0x1a7e9c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a7e9cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a7ea0: 0x8c220a60  lw          $v0, 0xA60($at)
    ctx->pc = 0x1a7ea0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2656)));
    // 0x1a7ea4: 0x10400020  beqz        $v0, . + 4 + (0x20 << 2)
    ctx->pc = 0x1A7EA4u;
    {
        const bool branch_taken_0x1a7ea4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A7EA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7EA4u;
            // 0x1a7ea8: 0x3c010023  lui         $at, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7ea4) {
            ctx->pc = 0x1A7F28u;
            goto label_1a7f28;
        }
    }
    ctx->pc = 0x1A7EACu;
    // 0x1a7eac: 0x24430010  addiu       $v1, $v0, 0x10
    ctx->pc = 0x1a7eacu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 16));
    // 0x1a7eb0: 0x2402fff0  addiu       $v0, $zero, -0x10
    ctx->pc = 0x1a7eb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967280));
    // 0x1a7eb4: 0x12200002  beqz        $s1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1A7EB4u;
    {
        const bool branch_taken_0x1a7eb4 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A7EB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7EB4u;
            // 0x1a7eb8: 0x624024  and         $t0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 8, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7eb4) {
            ctx->pc = 0x1A7EC0u;
            goto label_1a7ec0;
        }
    }
    ctx->pc = 0x1A7EBCu;
    // 0x1a7ebc: 0x24110001  addiu       $s1, $zero, 0x1
    ctx->pc = 0x1a7ebcu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1a7ec0:
    // 0x1a7ec0: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1a7ec0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1a7ec4: 0x3c07002b  lui         $a3, 0x2B
    ctx->pc = 0x1a7ec4u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)43 << 16));
    // 0x1a7ec8: 0x8c221180  lw          $v0, 0x1180($at)
    ctx->pc = 0x1a7ec8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4480)));
    // 0x1a7ecc: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a7eccu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a7ed0: 0x24e70cc0  addiu       $a3, $a3, 0xCC0
    ctx->pc = 0x1a7ed0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 3264));
    // 0x1a7ed4: 0x3c0b001a  lui         $t3, 0x1A
    ctx->pc = 0x1a7ed4u;
    SET_GPR_S32(ctx, 11, (int32_t)((uint32_t)26 << 16));
    // 0x1a7ed8: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1a7ed8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a7edc: 0x24840c30  addiu       $a0, $a0, 0xC30
    ctx->pc = 0x1a7edcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 3120));
    // 0x1a7ee0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1a7ee0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a7ee4: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x1a7ee4u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a7ee8: 0xe0482d  daddu       $t1, $a3, $zero
    ctx->pc = 0x1a7ee8u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a7eec: 0x256b7fa0  addiu       $t3, $t3, 0x7FA0
    ctx->pc = 0x1a7eecu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 32672));
    // 0x1a7ef0: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x1A7EF0u;
    SET_GPR_U32(ctx, 31, 0x1A7EF8u);
    ctx->pc = 0x1A7EF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7EF0u;
            // 0x1a7ef4: 0xffa20000  sd          $v0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7EF8u; }
        if (ctx->pc != 0x1A7EF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7EF8u; }
        if (ctx->pc != 0x1A7EF8u) { return; }
    }
    ctx->pc = 0x1A7EF8u;
label_1a7ef8:
    // 0x1a7ef8: 0x4410009  bgez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1A7EF8u;
    {
        const bool branch_taken_0x1a7ef8 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1A7EFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7EF8u;
            // 0x1a7efc: 0x3c01002b  lui         $at, 0x2B (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7ef8) {
            ctx->pc = 0x1A7F20u;
            goto label_1a7f20;
        }
    }
    ctx->pc = 0x1A7F00u;
    // 0x1a7f00: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1a7f00u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1a7f04: 0xc0423b4  jal         func_108ED0
    ctx->pc = 0x1A7F04u;
    SET_GPR_U32(ctx, 31, 0x1A7F0Cu);
    ctx->pc = 0x1A7F08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7F04u;
            // 0x1a7f08: 0x24842450  addiu       $a0, $a0, 0x2450 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9296));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108ED0u;
    if (runtime->hasFunction(0x108ED0u)) {
        auto targetFn = runtime->lookupFunction(0x108ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7F0Cu; }
        if (ctx->pc != 0x1A7F0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108ED0_0x108ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7F0Cu; }
        if (ctx->pc != 0x1A7F0Cu) { return; }
    }
    ctx->pc = 0x1A7F0Cu;
label_1a7f0c:
    // 0x1a7f0c: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1a7f0cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1a7f10: 0xc045190  jal         func_114640
    ctx->pc = 0x1A7F10u;
    SET_GPR_U32(ctx, 31, 0x1A7F18u);
    ctx->pc = 0x1A7F14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7F10u;
            // 0x1a7f14: 0x8c241180  lw          $a0, 0x1180($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4480)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7F18u; }
        if (ctx->pc != 0x1A7F18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7F18u; }
        if (ctx->pc != 0x1A7F18u) { return; }
    }
    ctx->pc = 0x1A7F18u;
label_1a7f18:
    // 0x1a7f18: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1A7F18u;
    {
        const bool branch_taken_0x1a7f18 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A7F1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7F18u;
            // 0x1a7f1c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7f18) {
            ctx->pc = 0x1A7F34u;
            goto label_1a7f34;
        }
    }
    ctx->pc = 0x1A7F20u;
label_1a7f20:
    // 0x1a7f20: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1A7F20u;
    {
        const bool branch_taken_0x1a7f20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a7f20) {
            ctx->pc = 0x1A7F30u;
            goto label_1a7f30;
        }
    }
    ctx->pc = 0x1A7F28u;
label_1a7f28:
    // 0x1a7f28: 0xc045190  jal         func_114640
    ctx->pc = 0x1A7F28u;
    SET_GPR_U32(ctx, 31, 0x1A7F30u);
    ctx->pc = 0x1A7F2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7F28u;
            // 0x1a7f2c: 0x8c241180  lw          $a0, 0x1180($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4480)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7F30u; }
        if (ctx->pc != 0x1A7F30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7F30u; }
        if (ctx->pc != 0x1A7F30u) { return; }
    }
    ctx->pc = 0x1A7F30u;
label_1a7f30:
    // 0x1a7f30: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1a7f30u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1a7f34:
    // 0x1a7f34: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1a7f34u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1a7f38: 0x7bb20030  lq          $s2, 0x30($sp)
    ctx->pc = 0x1a7f38u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1a7f3c: 0x7bb10020  lq          $s1, 0x20($sp)
    ctx->pc = 0x1a7f3cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1a7f40: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x1a7f40u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a7f44: 0x3e00008  jr          $ra
    ctx->pc = 0x1A7F44u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A7F48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7F44u;
            // 0x1a7f48: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A7E08u: goto label_1a7e08;
            case 0x1A7E18u: goto label_1a7e18;
            case 0x1A7E24u: goto label_1a7e24;
            case 0x1A7E30u: goto label_1a7e30;
            case 0x1A7E38u: goto label_1a7e38;
            case 0x1A7E4Cu: goto label_1a7e4c;
            case 0x1A7E54u: goto label_1a7e54;
            case 0x1A7E70u: goto label_1a7e70;
            case 0x1A7E94u: goto label_1a7e94;
            case 0x1A7EC0u: goto label_1a7ec0;
            case 0x1A7EF8u: goto label_1a7ef8;
            case 0x1A7F0Cu: goto label_1a7f0c;
            case 0x1A7F18u: goto label_1a7f18;
            case 0x1A7F20u: goto label_1a7f20;
            case 0x1A7F28u: goto label_1a7f28;
            case 0x1A7F30u: goto label_1a7f30;
            case 0x1A7F34u: goto label_1a7f34;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A7F4Cu;
    // 0x1a7f4c: 0x0  nop
    ctx->pc = 0x1a7f4cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
