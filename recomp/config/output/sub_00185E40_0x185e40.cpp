#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00185E40
// Address: 0x185e40 - 0x1860b0
void sub_00185E40_0x185e40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00185E40_0x185e40");
#endif

    switch (ctx->pc) {
        case 0x185e6cu: goto label_185e6c;
        case 0x185eb0u: goto label_185eb0;
        case 0x185ec0u: goto label_185ec0;
        case 0x185ee0u: goto label_185ee0;
        case 0x185f0cu: goto label_185f0c;
        case 0x185f48u: goto label_185f48;
        case 0x185f58u: goto label_185f58;
        case 0x185f74u: goto label_185f74;
        case 0x185fb0u: goto label_185fb0;
        case 0x185fd0u: goto label_185fd0;
        case 0x185ff8u: goto label_185ff8;
        case 0x18600cu: goto label_18600c;
        case 0x186030u: goto label_186030;
        case 0x18604cu: goto label_18604c;
        case 0x18605cu: goto label_18605c;
        default: break;
    }

    ctx->pc = 0x185e40u;

    // 0x185e40: 0x27bdfcb0  addiu       $sp, $sp, -0x350
    ctx->pc = 0x185e40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966448));
    // 0x185e44: 0xffb00310  sd          $s0, 0x310($sp)
    ctx->pc = 0x185e44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 784), GPR_U64(ctx, 16));
    // 0x185e48: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x185e48u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185e4c: 0xffb20320  sd          $s2, 0x320($sp)
    ctx->pc = 0x185e4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 800), GPR_U64(ctx, 18));
    // 0x185e50: 0xffb10318  sd          $s1, 0x318($sp)
    ctx->pc = 0x185e50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 792), GPR_U64(ctx, 17));
    // 0x185e54: 0xffb30328  sd          $s3, 0x328($sp)
    ctx->pc = 0x185e54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 808), GPR_U64(ctx, 19));
    // 0x185e58: 0xffb40330  sd          $s4, 0x330($sp)
    ctx->pc = 0x185e58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 816), GPR_U64(ctx, 20));
    // 0x185e5c: 0xffb50338  sd          $s5, 0x338($sp)
    ctx->pc = 0x185e5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 824), GPR_U64(ctx, 21));
    // 0x185e60: 0xffbf0340  sd          $ra, 0x340($sp)
    ctx->pc = 0x185e60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 832), GPR_U64(ctx, 31));
    // 0x185e64: 0xc062210  jal         func_188840
    ctx->pc = 0x185E64u;
    SET_GPR_U32(ctx, 31, 0x185E6Cu);
    ctx->pc = 0x185E68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x185E64u;
            // 0x185e68: 0x80902d  daddu       $s2, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x188840u;
    if (runtime->hasFunction(0x188840u)) {
        auto targetFn = runtime->lookupFunction(0x188840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185E6Cu; }
        if (ctx->pc != 0x185E6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00188840_0x188840(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185E6Cu; }
        if (ctx->pc != 0x185E6Cu) { return; }
    }
    ctx->pc = 0x185E6Cu;
label_185e6c:
    // 0x185e6c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x185E6Cu;
    {
        const bool branch_taken_0x185e6c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x185E70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x185E6Cu;
            // 0x185e70: 0x24030898  addiu       $v1, $zero, 0x898 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2200));
        ctx->in_delay_slot = false;
        if (branch_taken_0x185e6c) {
            ctx->pc = 0x185E80u;
            goto label_185e80;
        }
    }
    ctx->pc = 0x185E74u;
    // 0x185e74: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x185e74u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x185e78: 0x10000083  b           . + 4 + (0x83 << 2)
    ctx->pc = 0x185E78u;
    {
        const bool branch_taken_0x185e78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x185E7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x185E78u;
            // 0x185e7c: 0x34420013  ori         $v0, $v0, 0x13 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)19);
        ctx->in_delay_slot = false;
        if (branch_taken_0x185e78) {
            ctx->pc = 0x186088u;
            goto label_186088;
        }
    }
    ctx->pc = 0x185E80u;
label_185e80:
    // 0x185e80: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x185e80u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x185e84: 0x2431818  mult        $v1, $s2, $v1
    ctx->pc = 0x185e84u;
    { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x185e88: 0x3c040028  lui         $a0, 0x28
    ctx->pc = 0x185e88u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)40 << 16));
    // 0x185e8c: 0x832021  addu        $a0, $a0, $v1
    ctx->pc = 0x185e8cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x185e90: 0x8c8463d4  lw          $a0, 0x63D4($a0)
    ctx->pc = 0x185e90u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 25556)));
    // 0x185e94: 0x1080007c  beqz        $a0, . + 4 + (0x7C << 2)
    ctx->pc = 0x185E94u;
    {
        const bool branch_taken_0x185e94 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x185E98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x185E94u;
            // 0x185e98: 0x3442006f  ori         $v0, $v0, 0x6F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)111);
        ctx->in_delay_slot = false;
        if (branch_taken_0x185e94) {
            ctx->pc = 0x186088u;
            goto label_186088;
        }
    }
    ctx->pc = 0x185E9Cu;
    // 0x185e9c: 0x27b10200  addiu       $s1, $sp, 0x200
    ctx->pc = 0x185e9cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 512));
    // 0x185ea0: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x185ea0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185ea4: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x185ea4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185ea8: 0xc0609a2  jal         func_182688
    ctx->pc = 0x185EA8u;
    SET_GPR_U32(ctx, 31, 0x185EB0u);
    ctx->pc = 0x185EACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x185EA8u;
            // 0x185eac: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182688u;
    if (runtime->hasFunction(0x182688u)) {
        auto targetFn = runtime->lookupFunction(0x182688u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185EB0u; }
        if (ctx->pc != 0x185EB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182688_0x182688(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185EB0u; }
        if (ctx->pc != 0x185EB0u) { return; }
    }
    ctx->pc = 0x185EB0u;
label_185eb0:
    // 0x185eb0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x185EB0u;
    {
        const bool branch_taken_0x185eb0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x185eb0) {
            ctx->pc = 0x185EC8u;
            goto label_185ec8;
        }
    }
    ctx->pc = 0x185EB8u;
    // 0x185eb8: 0xc06089c  jal         func_182270
    ctx->pc = 0x185EB8u;
    SET_GPR_U32(ctx, 31, 0x185EC0u);
    ctx->pc = 0x185EBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x185EB8u;
            // 0x185ebc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182270u;
    if (runtime->hasFunction(0x182270u)) {
        auto targetFn = runtime->lookupFunction(0x182270u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185EC0u; }
        if (ctx->pc != 0x185EC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182270_0x182270(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185EC0u; }
        if (ctx->pc != 0x185EC0u) { return; }
    }
    ctx->pc = 0x185EC0u;
label_185ec0:
    // 0x185ec0: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x185EC0u;
    {
        const bool branch_taken_0x185ec0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x185ec0) {
            ctx->pc = 0x185ED8u;
            goto label_185ed8;
        }
    }
    ctx->pc = 0x185EC8u;
label_185ec8:
    // 0x185ec8: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x185ec8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x185ecc: 0x1000006e  b           . + 4 + (0x6E << 2)
    ctx->pc = 0x185ECCu;
    {
        const bool branch_taken_0x185ecc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x185ED0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x185ECCu;
            // 0x185ed0: 0x34420016  ori         $v0, $v0, 0x16 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)22);
        ctx->in_delay_slot = false;
        if (branch_taken_0x185ecc) {
            ctx->pc = 0x186088u;
            goto label_186088;
        }
    }
    ctx->pc = 0x185ED4u;
    // 0x185ed4: 0x0  nop
    ctx->pc = 0x185ed4u;
    // NOP
label_185ed8:
    // 0x185ed8: 0xc060880  jal         func_182200
    ctx->pc = 0x185ED8u;
    SET_GPR_U32(ctx, 31, 0x185EE0u);
    ctx->pc = 0x185EDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x185ED8u;
            // 0x185edc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182200u;
    if (runtime->hasFunction(0x182200u)) {
        auto targetFn = runtime->lookupFunction(0x182200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185EE0u; }
        if (ctx->pc != 0x185EE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182200_0x182200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185EE0u; }
        if (ctx->pc != 0x185EE0u) { return; }
    }
    ctx->pc = 0x185EE0u;
label_185ee0:
    // 0x185ee0: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x185EE0u;
    {
        const bool branch_taken_0x185ee0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x185ee0) {
            ctx->pc = 0x185EE4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x185EE0u;
            // 0x185ee4: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x185EF8u;
            goto label_185ef8;
        }
    }
    ctx->pc = 0x185EE8u;
    // 0x185ee8: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x185ee8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x185eec: 0x10000066  b           . + 4 + (0x66 << 2)
    ctx->pc = 0x185EECu;
    {
        const bool branch_taken_0x185eec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x185EF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x185EECu;
            // 0x185ef0: 0x3442005b  ori         $v0, $v0, 0x5B (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)91);
        ctx->in_delay_slot = false;
        if (branch_taken_0x185eec) {
            ctx->pc = 0x186088u;
            goto label_186088;
        }
    }
    ctx->pc = 0x185EF4u;
    // 0x185ef4: 0x0  nop
    ctx->pc = 0x185ef4u;
    // NOP
label_185ef8:
    // 0x185ef8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x185ef8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185efc: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x185efcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185f00: 0x27a70300  addiu       $a3, $sp, 0x300
    ctx->pc = 0x185f00u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 768));
    // 0x185f04: 0xc0610d8  jal         func_184360
    ctx->pc = 0x185F04u;
    SET_GPR_U32(ctx, 31, 0x185F0Cu);
    ctx->pc = 0x185F08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x185F04u;
            // 0x185f08: 0x27a80304  addiu       $t0, $sp, 0x304 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 772));
        ctx->in_delay_slot = false;
    ctx->pc = 0x184360u;
    if (runtime->hasFunction(0x184360u)) {
        auto targetFn = runtime->lookupFunction(0x184360u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185F0Cu; }
        if (ctx->pc != 0x185F0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00184360_0x184360(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185F0Cu; }
        if (ctx->pc != 0x185F0Cu) { return; }
    }
    ctx->pc = 0x185F0Cu;
label_185f0c:
    // 0x185f0c: 0x3c038101  lui         $v1, 0x8101
    ctx->pc = 0x185f0cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33025 << 16));
    // 0x185f10: 0x34630011  ori         $v1, $v1, 0x11
    ctx->pc = 0x185f10u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)17);
    // 0x185f14: 0x1443005c  bne         $v0, $v1, . + 4 + (0x5C << 2)
    ctx->pc = 0x185F14u;
    {
        const bool branch_taken_0x185f14 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x185F18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x185F14u;
            // 0x185f18: 0xafa2030c  sw          $v0, 0x30C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 780), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x185f14) {
            ctx->pc = 0x186088u;
            goto label_186088;
        }
    }
    ctx->pc = 0x185F1Cu;
    // 0x185f1c: 0x97a40000  lhu         $a0, 0x0($sp)
    ctx->pc = 0x185f1cu;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x185f20: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x185f20u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x185f24: 0x30830002  andi        $v1, $a0, 0x2
    ctx->pc = 0x185f24u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)2);
    // 0x185f28: 0x10600057  beqz        $v1, . + 4 + (0x57 << 2)
    ctx->pc = 0x185F28u;
    {
        const bool branch_taken_0x185f28 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x185F2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x185F28u;
            // 0x185f2c: 0x3442000d  ori         $v0, $v0, 0xD (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)13);
        ctx->in_delay_slot = false;
        if (branch_taken_0x185f28) {
            ctx->pc = 0x186088u;
            goto label_186088;
        }
    }
    ctx->pc = 0x185F30u;
    // 0x185f30: 0x30820020  andi        $v0, $a0, 0x20
    ctx->pc = 0x185f30u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)32);
    // 0x185f34: 0x10400017  beqz        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x185F34u;
    {
        const bool branch_taken_0x185f34 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x185F38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x185F34u;
            // 0x185f38: 0x27b00280  addiu       $s0, $sp, 0x280 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 640));
        ctx->in_delay_slot = false;
        if (branch_taken_0x185f34) {
            ctx->pc = 0x185F94u;
            goto label_185f94;
        }
    }
    ctx->pc = 0x185F3Cu;
    // 0x185f3c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x185f3cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185f40: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x185F40u;
    SET_GPR_U32(ctx, 31, 0x185F48u);
    ctx->pc = 0x185F44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x185F40u;
            // 0x185f44: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185F48u; }
        if (ctx->pc != 0x185F48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185F48u; }
        if (ctx->pc != 0x185F48u) { return; }
    }
    ctx->pc = 0x185F48u;
label_185f48:
    // 0x185f48: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x185f48u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x185f4c: 0x24a51820  addiu       $a1, $a1, 0x1820
    ctx->pc = 0x185f4cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 6176));
    // 0x185f50: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x185F50u;
    SET_GPR_U32(ctx, 31, 0x185F58u);
    ctx->pc = 0x185F54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x185F50u;
            // 0x185f54: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185F58u; }
        if (ctx->pc != 0x185F58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185F58u; }
        if (ctx->pc != 0x185F58u) { return; }
    }
    ctx->pc = 0x185F58u;
label_185f58:
    // 0x185f58: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x185f58u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185f5c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x185f5cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185f60: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x185f60u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185f64: 0x2407ffff  addiu       $a3, $zero, -0x1
    ctx->pc = 0x185f64u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x185f68: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x185f68u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185f6c: 0xc06188c  jal         func_186230
    ctx->pc = 0x185F6Cu;
    SET_GPR_U32(ctx, 31, 0x185F74u);
    ctx->pc = 0x185F70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x185F6Cu;
            // 0x185f70: 0x27a90308  addiu       $t1, $sp, 0x308 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 29), 776));
        ctx->in_delay_slot = false;
    ctx->pc = 0x186230u;
    if (runtime->hasFunction(0x186230u)) {
        auto targetFn = runtime->lookupFunction(0x186230u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185F74u; }
        if (ctx->pc != 0x185F74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00186230_0x186230(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185F74u; }
        if (ctx->pc != 0x185F74u) { return; }
    }
    ctx->pc = 0x185F74u;
label_185f74:
    // 0x185f74: 0x14400044  bnez        $v0, . + 4 + (0x44 << 2)
    ctx->pc = 0x185F74u;
    {
        const bool branch_taken_0x185f74 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x185F78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x185F74u;
            // 0x185f78: 0xafa2030c  sw          $v0, 0x30C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 780), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x185f74) {
            ctx->pc = 0x186088u;
            goto label_186088;
        }
    }
    ctx->pc = 0x185F7Cu;
    // 0x185f7c: 0x8fa30308  lw          $v1, 0x308($sp)
    ctx->pc = 0x185f7cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 776)));
    // 0x185f80: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x185f80u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x185f84: 0x28630003  slti        $v1, $v1, 0x3
    ctx->pc = 0x185f84u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x185f88: 0x1060003f  beqz        $v1, . + 4 + (0x3F << 2)
    ctx->pc = 0x185F88u;
    {
        const bool branch_taken_0x185f88 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x185F8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x185F88u;
            // 0x185f8c: 0x3442005a  ori         $v0, $v0, 0x5A (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)90);
        ctx->in_delay_slot = false;
        if (branch_taken_0x185f88) {
            ctx->pc = 0x186088u;
            goto label_186088;
        }
    }
    ctx->pc = 0x185F90u;
    // 0x185f90: 0x97a40000  lhu         $a0, 0x0($sp)
    ctx->pc = 0x185f90u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 0)));
label_185f94:
    // 0x185f94: 0x8fa60300  lw          $a2, 0x300($sp)
    ctx->pc = 0x185f94u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 768)));
    // 0x185f98: 0x38828000  xori        $v0, $a0, 0x8000
    ctx->pc = 0x185f98u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) ^ (uint64_t)(uint16_t)32768);
    // 0x185f9c: 0x8fa70304  lw          $a3, 0x304($sp)
    ctx->pc = 0x185f9cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 772)));
    // 0x185fa0: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x185fa0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185fa4: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x185fa4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185fa8: 0xc0612a8  jal         func_184AA0
    ctx->pc = 0x185FA8u;
    SET_GPR_U32(ctx, 31, 0x185FB0u);
    ctx->pc = 0x185FACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x185FA8u;
            // 0x185fac: 0xa7a20000  sh          $v0, 0x0($sp) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 29), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x184AA0u;
    if (runtime->hasFunction(0x184AA0u)) {
        auto targetFn = runtime->lookupFunction(0x184AA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185FB0u; }
        if (ctx->pc != 0x185FB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00184AA0_0x184aa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185FB0u; }
        if (ctx->pc != 0x185FB0u) { return; }
    }
    ctx->pc = 0x185FB0u;
label_185fb0:
    // 0x185fb0: 0x14400035  bnez        $v0, . + 4 + (0x35 << 2)
    ctx->pc = 0x185FB0u;
    {
        const bool branch_taken_0x185fb0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x185FB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x185FB0u;
            // 0x185fb4: 0xafa2030c  sw          $v0, 0x30C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 780), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x185fb0) {
            ctx->pc = 0x186088u;
            goto label_186088;
        }
    }
    ctx->pc = 0x185FB8u;
    // 0x185fb8: 0x8fb00010  lw          $s0, 0x10($sp)
    ctx->pc = 0x185fb8u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x185fbc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x185fbcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x185fc0: 0x16020009  bne         $s0, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x185FC0u;
    {
        const bool branch_taken_0x185fc0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        ctx->pc = 0x185FC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x185FC0u;
            // 0x185fc4: 0x3c137fff  lui         $s3, 0x7FFF (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)32767 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x185fc0) {
            ctx->pc = 0x185FE8u;
            goto label_185fe8;
        }
    }
    ctx->pc = 0x185FC8u;
    // 0x185fc8: 0xc061bbc  jal         func_186EF0
    ctx->pc = 0x185FC8u;
    SET_GPR_U32(ctx, 31, 0x185FD0u);
    ctx->pc = 0x185FCCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x185FC8u;
            // 0x185fcc: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x186EF0u;
    if (runtime->hasFunction(0x186EF0u)) {
        auto targetFn = runtime->lookupFunction(0x186EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185FD0u; }
        if (ctx->pc != 0x185FD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00186EF0_0x186ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185FD0u; }
        if (ctx->pc != 0x185FD0u) { return; }
    }
    ctx->pc = 0x185FD0u;
label_185fd0:
    // 0x185fd0: 0x3c038101  lui         $v1, 0x8101
    ctx->pc = 0x185fd0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33025 << 16));
    // 0x185fd4: 0x3463006f  ori         $v1, $v1, 0x6F
    ctx->pc = 0x185fd4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)111);
    // 0x185fd8: 0x2180b  movn        $v1, $zero, $v0
    ctx->pc = 0x185fd8u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 0));
    // 0x185fdc: 0x1000002a  b           . + 4 + (0x2A << 2)
    ctx->pc = 0x185FDCu;
    {
        const bool branch_taken_0x185fdc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x185FE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x185FDCu;
            // 0x185fe0: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x185fdc) {
            ctx->pc = 0x186088u;
            goto label_186088;
        }
    }
    ctx->pc = 0x185FE4u;
    // 0x185fe4: 0x0  nop
    ctx->pc = 0x185fe4u;
    // NOP
label_185fe8:
    // 0x185fe8: 0x200882d  daddu       $s1, $s0, $zero
    ctx->pc = 0x185fe8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185fec: 0x3c158000  lui         $s5, 0x8000
    ctx->pc = 0x185fecu;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)32768 << 16));
    // 0x185ff0: 0x2414ffff  addiu       $s4, $zero, -0x1
    ctx->pc = 0x185ff0u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x185ff4: 0x3673ffff  ori         $s3, $s3, 0xFFFF
    ctx->pc = 0x185ff4u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 19) | (uint64_t)(uint16_t)65535);
label_185ff8:
    // 0x185ff8: 0x220802d  daddu       $s0, $s1, $zero
    ctx->pc = 0x185ff8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185ffc: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x185ffcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186000: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x186000u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186004: 0xc060b02  jal         func_182C08
    ctx->pc = 0x186004u;
    SET_GPR_U32(ctx, 31, 0x18600Cu);
    ctx->pc = 0x186008u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186004u;
            // 0x186008: 0x27a6030c  addiu       $a2, $sp, 0x30C (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 780));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182C08u;
    if (runtime->hasFunction(0x182C08u)) {
        auto targetFn = runtime->lookupFunction(0x182C08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18600Cu; }
        if (ctx->pc != 0x18600Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182C08_0x182c08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18600Cu; }
        if (ctx->pc != 0x18600Cu) { return; }
    }
    ctx->pc = 0x18600Cu;
label_18600c:
    // 0x18600c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x18600cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186010: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x186010u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186014: 0x8fa2030c  lw          $v0, 0x30C($sp)
    ctx->pc = 0x186014u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 780)));
    // 0x186018: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x186018u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18601c: 0x2353026  xor         $a2, $s1, $s5
    ctx->pc = 0x18601cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 17) ^ GPR_U64(ctx, 21));
    // 0x186020: 0x14400019  bnez        $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x186020u;
    {
        const bool branch_taken_0x186020 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x186024u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186020u;
            // 0x186024: 0x27a7030c  addiu       $a3, $sp, 0x30C (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 780));
        ctx->in_delay_slot = false;
        if (branch_taken_0x186020) {
            ctx->pc = 0x186088u;
            goto label_186088;
        }
    }
    ctx->pc = 0x186028u;
    // 0x186028: 0xc060b28  jal         func_182CA0
    ctx->pc = 0x186028u;
    SET_GPR_U32(ctx, 31, 0x186030u);
    ctx->pc = 0x182CA0u;
    if (runtime->hasFunction(0x182CA0u)) {
        auto targetFn = runtime->lookupFunction(0x182CA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186030u; }
        if (ctx->pc != 0x186030u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182CA0_0x182ca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186030u; }
        if (ctx->pc != 0x186030u) { return; }
    }
    ctx->pc = 0x186030u;
label_186030:
    // 0x186030: 0x8fa3030c  lw          $v1, 0x30C($sp)
    ctx->pc = 0x186030u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 780)));
    // 0x186034: 0x14600014  bnez        $v1, . + 4 + (0x14 << 2)
    ctx->pc = 0x186034u;
    {
        const bool branch_taken_0x186034 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x186038u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186034u;
            // 0x186038: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x186034) {
            ctx->pc = 0x186088u;
            goto label_186088;
        }
    }
    ctx->pc = 0x18603Cu;
    // 0x18603c: 0x5634ffee  bnel        $s1, $s4, . + 4 + (-0x12 << 2)
    ctx->pc = 0x18603Cu;
    {
        const bool branch_taken_0x18603c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 20));
        if (branch_taken_0x18603c) {
            ctx->pc = 0x186040u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x18603Cu;
            // 0x186040: 0x2338824  and         $s1, $s1, $s3 (Delay Slot)
        SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) & GPR_U64(ctx, 19));
        ctx->in_delay_slot = false;
            ctx->pc = 0x185FF8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_185ff8;
        }
    }
    ctx->pc = 0x186044u;
    // 0x186044: 0xc061bbc  jal         func_186EF0
    ctx->pc = 0x186044u;
    SET_GPR_U32(ctx, 31, 0x18604Cu);
    ctx->pc = 0x186048u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186044u;
            // 0x186048: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x186EF0u;
    if (runtime->hasFunction(0x186EF0u)) {
        auto targetFn = runtime->lookupFunction(0x186EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18604Cu; }
        if (ctx->pc != 0x18604Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00186EF0_0x186ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18604Cu; }
        if (ctx->pc != 0x18604Cu) { return; }
    }
    ctx->pc = 0x18604Cu;
label_18604c:
    // 0x18604c: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x18604Cu;
    {
        const bool branch_taken_0x18604c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x18604c) {
            ctx->pc = 0x186064u;
            goto label_186064;
        }
    }
    ctx->pc = 0x186054u;
    // 0x186054: 0xc060a84  jal         func_182A10
    ctx->pc = 0x186054u;
    SET_GPR_U32(ctx, 31, 0x18605Cu);
    ctx->pc = 0x186058u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186054u;
            // 0x186058: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182A10u;
    if (runtime->hasFunction(0x182A10u)) {
        auto targetFn = runtime->lookupFunction(0x182A10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18605Cu; }
        if (ctx->pc != 0x18605Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182A10_0x182a10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18605Cu; }
        if (ctx->pc != 0x18605Cu) { return; }
    }
    ctx->pc = 0x18605Cu;
label_18605c:
    // 0x18605c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x18605Cu;
    {
        const bool branch_taken_0x18605c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x186060u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18605Cu;
            // 0x186060: 0x24030898  addiu       $v1, $zero, 0x898 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2200));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18605c) {
            ctx->pc = 0x186070u;
            goto label_186070;
        }
    }
    ctx->pc = 0x186064u;
label_186064:
    // 0x186064: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x186064u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x186068: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x186068u;
    {
        const bool branch_taken_0x186068 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18606Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186068u;
            // 0x18606c: 0x3442006f  ori         $v0, $v0, 0x6F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)111);
        ctx->in_delay_slot = false;
        if (branch_taken_0x186068) {
            ctx->pc = 0x186088u;
            goto label_186088;
        }
    }
    ctx->pc = 0x186070u;
label_186070:
    // 0x186070: 0x3c040028  lui         $a0, 0x28
    ctx->pc = 0x186070u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)40 << 16));
    // 0x186074: 0x2431818  mult        $v1, $s2, $v1
    ctx->pc = 0x186074u;
    { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x186078: 0x24845b48  addiu       $a0, $a0, 0x5B48
    ctx->pc = 0x186078u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 23368));
    // 0x18607c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x18607cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186080: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x186080u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x186084: 0xac600890  sw          $zero, 0x890($v1)
    ctx->pc = 0x186084u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 2192), GPR_U32(ctx, 0));
label_186088:
    // 0x186088: 0xdfb00310  ld          $s0, 0x310($sp)
    ctx->pc = 0x186088u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 784)));
    // 0x18608c: 0xdfb10318  ld          $s1, 0x318($sp)
    ctx->pc = 0x18608cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 792)));
    // 0x186090: 0xdfb20320  ld          $s2, 0x320($sp)
    ctx->pc = 0x186090u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 800)));
    // 0x186094: 0xdfb30328  ld          $s3, 0x328($sp)
    ctx->pc = 0x186094u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 808)));
    // 0x186098: 0xdfb40330  ld          $s4, 0x330($sp)
    ctx->pc = 0x186098u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 816)));
    // 0x18609c: 0xdfb50338  ld          $s5, 0x338($sp)
    ctx->pc = 0x18609cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 824)));
    // 0x1860a0: 0xdfbf0340  ld          $ra, 0x340($sp)
    ctx->pc = 0x1860a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 832)));
    // 0x1860a4: 0x3e00008  jr          $ra
    ctx->pc = 0x1860A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1860A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1860A4u;
            // 0x1860a8: 0x27bd0350  addiu       $sp, $sp, 0x350 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 848));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x185E6Cu: goto label_185e6c;
            case 0x185E80u: goto label_185e80;
            case 0x185EB0u: goto label_185eb0;
            case 0x185EC0u: goto label_185ec0;
            case 0x185EC8u: goto label_185ec8;
            case 0x185ED8u: goto label_185ed8;
            case 0x185EE0u: goto label_185ee0;
            case 0x185EF8u: goto label_185ef8;
            case 0x185F0Cu: goto label_185f0c;
            case 0x185F48u: goto label_185f48;
            case 0x185F58u: goto label_185f58;
            case 0x185F74u: goto label_185f74;
            case 0x185F94u: goto label_185f94;
            case 0x185FB0u: goto label_185fb0;
            case 0x185FD0u: goto label_185fd0;
            case 0x185FE8u: goto label_185fe8;
            case 0x185FF8u: goto label_185ff8;
            case 0x18600Cu: goto label_18600c;
            case 0x186030u: goto label_186030;
            case 0x18604Cu: goto label_18604c;
            case 0x18605Cu: goto label_18605c;
            case 0x186064u: goto label_186064;
            case 0x186070u: goto label_186070;
            case 0x186088u: goto label_186088;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1860ACu;
    // 0x1860ac: 0x0  nop
    ctx->pc = 0x1860acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
