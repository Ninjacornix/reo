#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00100E88
// Address: 0x100e88 - 0x1010a8
void sub_00100E88_0x100e88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00100E88_0x100e88");
#endif

    switch (ctx->pc) {
        case 0x100ea8u: goto label_100ea8;
        case 0x100eb4u: goto label_100eb4;
        case 0x100ee0u: goto label_100ee0;
        case 0x100f04u: goto label_100f04;
        case 0x100f0cu: goto label_100f0c;
        case 0x100f20u: goto label_100f20;
        case 0x100f30u: goto label_100f30;
        case 0x100f48u: goto label_100f48;
        case 0x100f50u: goto label_100f50;
        case 0x100f70u: goto label_100f70;
        case 0x100f84u: goto label_100f84;
        case 0x100fa8u: goto label_100fa8;
        case 0x100fb0u: goto label_100fb0;
        default: break;
    }

    ctx->pc = 0x100e88u;

    // 0x100e88: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x100e88u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x100e8c: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x100e8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x100e90: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x100e90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x100e94: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x100e94u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100e98: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x100e98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x100e9c: 0x3c100020  lui         $s0, 0x20
    ctx->pc = 0x100e9cu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)32 << 16));
    // 0x100ea0: 0xc040164  jal         func_100590
    ctx->pc = 0x100EA0u;
    SET_GPR_U32(ctx, 31, 0x100EA8u);
    ctx->pc = 0x100EA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100EA0u;
            // 0x100ea4: 0xffb20020  sd          $s2, 0x20($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100590u;
    if (runtime->hasFunction(0x100590u)) {
        auto targetFn = runtime->lookupFunction(0x100590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100EA8u; }
        if (ctx->pc != 0x100EA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100590_0x100590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100EA8u; }
        if (ctx->pc != 0x100EA8u) { return; }
    }
    ctx->pc = 0x100EA8u;
label_100ea8:
    // 0x100ea8: 0x8e04792c  lw          $a0, 0x792C($s0)
    ctx->pc = 0x100ea8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 31020)));
    // 0x100eac: 0xc04519c  jal         func_114670
    ctx->pc = 0x100EACu;
    SET_GPR_U32(ctx, 31, 0x100EB4u);
    ctx->pc = 0x114670u;
    if (runtime->hasFunction(0x114670u)) {
        auto targetFn = runtime->lookupFunction(0x114670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100EB4u; }
        if (ctx->pc != 0x100EB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114670_0x114670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100EB4u; }
        if (ctx->pc != 0x100EB4u) { return; }
    }
    ctx->pc = 0x100EB4u;
label_100eb4:
    // 0x100eb4: 0x8e03792c  lw          $v1, 0x792C($s0)
    ctx->pc = 0x100eb4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 31020)));
    // 0x100eb8: 0x1062000b  beq         $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x100EB8u;
    {
        const bool branch_taken_0x100eb8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x100EBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100EB8u;
            // 0x100ebc: 0x3c020020  lui         $v0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100eb8) {
            ctx->pc = 0x100EE8u;
            goto label_100ee8;
        }
    }
    ctx->pc = 0x100EC0u;
    // 0x100ec0: 0x8c437910  lw          $v1, 0x7910($v0)
    ctx->pc = 0x100ec0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 30992)));
    // 0x100ec4: 0x18600016  blez        $v1, . + 4 + (0x16 << 2)
    ctx->pc = 0x100EC4u;
    {
        const bool branch_taken_0x100ec4 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x100EC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100EC4u;
            // 0x100ec8: 0x3c020020  lui         $v0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100ec4) {
            ctx->pc = 0x100F20u;
            goto label_100f20;
        }
    }
    ctx->pc = 0x100ECCu;
    // 0x100ecc: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x100eccu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x100ed0: 0x8c467918  lw          $a2, 0x7918($v0)
    ctx->pc = 0x100ed0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 31000)));
    // 0x100ed4: 0x24847578  addiu       $a0, $a0, 0x7578
    ctx->pc = 0x100ed4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 30072));
    // 0x100ed8: 0xc045a12  jal         func_116848
    ctx->pc = 0x100ED8u;
    SET_GPR_U32(ctx, 31, 0x100EE0u);
    ctx->pc = 0x100EDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100ED8u;
            // 0x100edc: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100EE0u; }
        if (ctx->pc != 0x100EE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100EE0u; }
        if (ctx->pc != 0x100EE0u) { return; }
    }
    ctx->pc = 0x100EE0u;
label_100ee0:
    // 0x100ee0: 0x1000003f  b           . + 4 + (0x3F << 2)
    ctx->pc = 0x100EE0u;
    {
        const bool branch_taken_0x100ee0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x100EE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100EE0u;
            // 0x100ee4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100ee0) {
            ctx->pc = 0x100FE0u;
            goto label_100fe0;
        }
    }
    ctx->pc = 0x100EE8u;
label_100ee8:
    // 0x100ee8: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x100ee8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x100eec: 0x3c030020  lui         $v1, 0x20
    ctx->pc = 0x100eecu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32 << 16));
    // 0x100ef0: 0x8c449f98  lw          $a0, -0x6068($v0)
    ctx->pc = 0x100ef0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294942616)));
    // 0x100ef4: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x100ef4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x100ef8: 0x0  nop
    ctx->pc = 0x100ef8u;
    // NOP
    // 0x100efc: 0xc045148  jal         func_114520
    ctx->pc = 0x100EFCu;
    SET_GPR_U32(ctx, 31, 0x100F04u);
    ctx->pc = 0x100F00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100EFCu;
            // 0x100f00: 0x24a59fa0  addiu       $a1, $a1, -0x6060 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294942624));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114520u;
    if (runtime->hasFunction(0x114520u)) {
        auto targetFn = runtime->lookupFunction(0x114520u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100F04u; }
        if (ctx->pc != 0x100F04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114520_0x114520(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100F04u; }
        if (ctx->pc != 0x100F04u) { return; }
    }
    ctx->pc = 0x100F04u;
label_100f04:
    // 0x100f04: 0xc040386  jal         func_100E18
    ctx->pc = 0x100F04u;
    SET_GPR_U32(ctx, 31, 0x100F0Cu);
    ctx->pc = 0x100F08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100F04u;
            // 0x100f08: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100E18u;
    if (runtime->hasFunction(0x100E18u)) {
        auto targetFn = runtime->lookupFunction(0x100E18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100F0Cu; }
        if (ctx->pc != 0x100F0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100E18_0x100e18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100F0Cu; }
        if (ctx->pc != 0x100F0Cu) { return; }
    }
    ctx->pc = 0x100F0Cu;
label_100f0c:
    // 0x100f0c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x100F0Cu;
    {
        const bool branch_taken_0x100f0c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x100F10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100F0Cu;
            // 0x100f10: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100f0c) {
            ctx->pc = 0x100F28u;
            goto label_100f28;
        }
    }
    ctx->pc = 0x100F14u;
    // 0x100f14: 0x8e04792c  lw          $a0, 0x792C($s0)
    ctx->pc = 0x100f14u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 31020)));
    // 0x100f18: 0xc045190  jal         func_114640
    ctx->pc = 0x100F18u;
    SET_GPR_U32(ctx, 31, 0x100F20u);
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100F20u; }
        if (ctx->pc != 0x100F20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100F20u; }
        if (ctx->pc != 0x100F20u) { return; }
    }
    ctx->pc = 0x100F20u;
label_100f20:
    // 0x100f20: 0x1000002f  b           . + 4 + (0x2F << 2)
    ctx->pc = 0x100F20u;
    {
        const bool branch_taken_0x100f20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x100F24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100F20u;
            // 0x100f24: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100f20) {
            ctx->pc = 0x100FE0u;
            goto label_100fe0;
        }
    }
    ctx->pc = 0x100F28u;
label_100f28:
    // 0x100f28: 0xc045c20  jal         func_117080
    ctx->pc = 0x100F28u;
    SET_GPR_U32(ctx, 31, 0x100F30u);
    ctx->pc = 0x100F2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100F28u;
            // 0x100f2c: 0x3c120020  lui         $s2, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117080u;
    if (runtime->hasFunction(0x117080u)) {
        auto targetFn = runtime->lookupFunction(0x117080u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100F30u; }
        if (ctx->pc != 0x100F30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117080_0x117080(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100F30u; }
        if (ctx->pc != 0x100F30u) { return; }
    }
    ctx->pc = 0x100F30u;
label_100f30:
    // 0x100f30: 0x8e42794c  lw          $v0, 0x794C($s2)
    ctx->pc = 0x100f30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 31052)));
    // 0x100f34: 0x441002a  bgez        $v0, . + 4 + (0x2A << 2)
    ctx->pc = 0x100F34u;
    {
        const bool branch_taken_0x100f34 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x100F38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100F34u;
            // 0x100f38: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100f34) {
            ctx->pc = 0x100FE0u;
            goto label_100fe0;
        }
    }
    ctx->pc = 0x100F3Cu;
    // 0x100f3c: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x100F3Cu;
    {
        const bool branch_taken_0x100f3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x100F40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100F3Cu;
            // 0x100f40: 0x3c110021  lui         $s1, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100f3c) {
            ctx->pc = 0x100F6Cu;
            goto label_100f6c;
        }
    }
    ctx->pc = 0x100F44u;
    // 0x100f44: 0x0  nop
    ctx->pc = 0x100f44u;
    // NOP
label_100f48:
    // 0x100f48: 0x3c020010  lui         $v0, 0x10
    ctx->pc = 0x100f48u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
    // 0x100f4c: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x100f4cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_100f50:
    // 0x100f50: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x100f50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x100f54: 0x0  nop
    ctx->pc = 0x100f54u;
    // NOP
    // 0x100f58: 0x0  nop
    ctx->pc = 0x100f58u;
    // NOP
    // 0x100f5c: 0x0  nop
    ctx->pc = 0x100f5cu;
    // NOP
    // 0x100f60: 0x0  nop
    ctx->pc = 0x100f60u;
    // NOP
    // 0x100f64: 0x1443fffa  bne         $v0, $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x100F64u;
    {
        const bool branch_taken_0x100f64 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x100f64) {
            ctx->pc = 0x100F50u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_100f50;
        }
    }
    ctx->pc = 0x100F6Cu;
label_100f6c:
    // 0x100f6c: 0x26309480  addiu       $s0, $s1, -0x6B80
    ctx->pc = 0x100f6cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 4294939776));
label_100f70:
    // 0x100f70: 0x3c058000  lui         $a1, 0x8000
    ctx->pc = 0x100f70u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x100f74: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x100f74u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100f78: 0x34a50593  ori         $a1, $a1, 0x593
    ctx->pc = 0x100f78u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1427);
    // 0x100f7c: 0xc045e06  jal         func_117818
    ctx->pc = 0x100F7Cu;
    SET_GPR_U32(ctx, 31, 0x100F84u);
    ctx->pc = 0x100F80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100F7Cu;
            // 0x100f80: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117818u;
    if (runtime->hasFunction(0x117818u)) {
        auto targetFn = runtime->lookupFunction(0x117818u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100F84u; }
        if (ctx->pc != 0x100F84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117818_0x117818(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100F84u; }
        if (ctx->pc != 0x100F84u) { return; }
    }
    ctx->pc = 0x100F84u;
label_100f84:
    // 0x100f84: 0x4430013  bgezl       $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x100F84u;
    {
        const bool branch_taken_0x100f84 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x100f84) {
            ctx->pc = 0x100F88u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x100F84u;
            // 0x100f88: 0x8e020024  lw          $v0, 0x24($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x100FD4u;
            goto label_100fd4;
        }
    }
    ctx->pc = 0x100F8Cu;
    // 0x100f8c: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x100f8cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x100f90: 0x8c437910  lw          $v1, 0x7910($v0)
    ctx->pc = 0x100f90u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 30992)));
    // 0x100f94: 0x18600005  blez        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x100F94u;
    {
        const bool branch_taken_0x100f94 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x100F98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100F94u;
            // 0x100f98: 0x3c020010  lui         $v0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100f94) {
            ctx->pc = 0x100FACu;
            goto label_100fac;
        }
    }
    ctx->pc = 0x100F9Cu;
    // 0x100f9c: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x100f9cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x100fa0: 0xc045a12  jal         func_116848
    ctx->pc = 0x100FA0u;
    SET_GPR_U32(ctx, 31, 0x100FA8u);
    ctx->pc = 0x100FA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100FA0u;
            // 0x100fa4: 0x248475a0  addiu       $a0, $a0, 0x75A0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 30112));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100FA8u; }
        if (ctx->pc != 0x100FA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100FA8u; }
        if (ctx->pc != 0x100FA8u) { return; }
    }
    ctx->pc = 0x100FA8u;
label_100fa8:
    // 0x100fa8: 0x3c020010  lui         $v0, 0x10
    ctx->pc = 0x100fa8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
label_100fac:
    // 0x100fac: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x100facu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_100fb0:
    // 0x100fb0: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x100fb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x100fb4: 0x0  nop
    ctx->pc = 0x100fb4u;
    // NOP
    // 0x100fb8: 0x0  nop
    ctx->pc = 0x100fb8u;
    // NOP
    // 0x100fbc: 0x0  nop
    ctx->pc = 0x100fbcu;
    // NOP
    // 0x100fc0: 0x0  nop
    ctx->pc = 0x100fc0u;
    // NOP
    // 0x100fc4: 0x1443fffa  bne         $v0, $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x100FC4u;
    {
        const bool branch_taken_0x100fc4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x100fc4) {
            ctx->pc = 0x100FB0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_100fb0;
        }
    }
    ctx->pc = 0x100FCCu;
    // 0x100fcc: 0x1000ffe8  b           . + 4 + (-0x18 << 2)
    ctx->pc = 0x100FCCu;
    {
        const bool branch_taken_0x100fcc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x100FD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100FCCu;
            // 0x100fd0: 0x26309480  addiu       $s0, $s1, -0x6B80 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 4294939776));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100fcc) {
            ctx->pc = 0x100F70u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_100f70;
        }
    }
    ctx->pc = 0x100FD4u;
label_100fd4:
    // 0x100fd4: 0x1040ffdc  beqz        $v0, . + 4 + (-0x24 << 2)
    ctx->pc = 0x100FD4u;
    {
        const bool branch_taken_0x100fd4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x100FD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100FD4u;
            // 0x100fd8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100fd4) {
            ctx->pc = 0x100F48u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_100f48;
        }
    }
    ctx->pc = 0x100FDCu;
    // 0x100fdc: 0xae40794c  sw          $zero, 0x794C($s2)
    ctx->pc = 0x100fdcu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 31052), GPR_U32(ctx, 0));
label_100fe0:
    // 0x100fe0: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x100fe0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x100fe4: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x100fe4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x100fe8: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x100fe8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x100fec: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x100fecu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x100ff0: 0x3e00008  jr          $ra
    ctx->pc = 0x100FF0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x100FF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100FF0u;
            // 0x100ff4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x100EA8u: goto label_100ea8;
            case 0x100EB4u: goto label_100eb4;
            case 0x100EE0u: goto label_100ee0;
            case 0x100EE8u: goto label_100ee8;
            case 0x100F04u: goto label_100f04;
            case 0x100F0Cu: goto label_100f0c;
            case 0x100F20u: goto label_100f20;
            case 0x100F28u: goto label_100f28;
            case 0x100F30u: goto label_100f30;
            case 0x100F48u: goto label_100f48;
            case 0x100F50u: goto label_100f50;
            case 0x100F6Cu: goto label_100f6c;
            case 0x100F70u: goto label_100f70;
            case 0x100F84u: goto label_100f84;
            case 0x100FA8u: goto label_100fa8;
            case 0x100FACu: goto label_100fac;
            case 0x100FB0u: goto label_100fb0;
            case 0x100FD4u: goto label_100fd4;
            case 0x100FE0u: goto label_100fe0;
            case 0x101060u: goto label_101060;
            case 0x101068u: goto label_101068;
            case 0x101070u: goto label_101070;
            case 0x101080u: goto label_101080;
            case 0x101088u: goto label_101088;
            case 0x101090u: goto label_101090;
            case 0x101098u: goto label_101098;
            case 0x10109Cu: goto label_10109c;
            case 0x1010A0u: goto label_1010a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x100FF8u;
    // 0x100ff8: 0x34028001  ori         $v0, $zero, 0x8001
    ctx->pc = 0x100ff8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32769);
    // 0x100ffc: 0x10820026  beq         $a0, $v0, . + 4 + (0x26 << 2)
    ctx->pc = 0x100FFCu;
    {
        const bool branch_taken_0x100ffc = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x101000u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100FFCu;
            // 0x101000: 0x3c020020  lui         $v0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100ffc) {
            ctx->pc = 0x101098u;
            goto label_101098;
        }
    }
    ctx->pc = 0x101004u;
    // 0x101004: 0x34028003  ori         $v0, $zero, 0x8003
    ctx->pc = 0x101004u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32771);
    // 0x101008: 0x10820021  beq         $a0, $v0, . + 4 + (0x21 << 2)
    ctx->pc = 0x101008u;
    {
        const bool branch_taken_0x101008 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x10100Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101008u;
            // 0x10100c: 0x3c020020  lui         $v0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101008) {
            ctx->pc = 0x101090u;
            goto label_101090;
        }
    }
    ctx->pc = 0x101010u;
    // 0x101010: 0x34028002  ori         $v0, $zero, 0x8002
    ctx->pc = 0x101010u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32770);
    // 0x101014: 0x1082001c  beq         $a0, $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x101014u;
    {
        const bool branch_taken_0x101014 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x101018u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101014u;
            // 0x101018: 0x3c020020  lui         $v0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101014) {
            ctx->pc = 0x101088u;
            goto label_101088;
        }
    }
    ctx->pc = 0x10101Cu;
    // 0x10101c: 0x34028004  ori         $v0, $zero, 0x8004
    ctx->pc = 0x10101cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32772);
    // 0x101020: 0x10820017  beq         $a0, $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x101020u;
    {
        const bool branch_taken_0x101020 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x101024u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101020u;
            // 0x101024: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101020) {
            ctx->pc = 0x101080u;
            goto label_101080;
        }
    }
    ctx->pc = 0x101028u;
    // 0x101028: 0x34028011  ori         $v0, $zero, 0x8011
    ctx->pc = 0x101028u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32785);
    // 0x10102c: 0x10820010  beq         $a0, $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x10102Cu;
    {
        const bool branch_taken_0x10102c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x101030u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10102Cu;
            // 0x101030: 0x34028013  ori         $v0, $zero, 0x8013 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32787);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10102c) {
            ctx->pc = 0x101070u;
            goto label_101070;
        }
    }
    ctx->pc = 0x101034u;
    // 0x101034: 0x1082000c  beq         $a0, $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x101034u;
    {
        const bool branch_taken_0x101034 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x101038u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101034u;
            // 0x101038: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101034) {
            ctx->pc = 0x101068u;
            goto label_101068;
        }
    }
    ctx->pc = 0x10103Cu;
    // 0x10103c: 0x34028012  ori         $v0, $zero, 0x8012
    ctx->pc = 0x10103cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32786);
    // 0x101040: 0x10820007  beq         $a0, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x101040u;
    {
        const bool branch_taken_0x101040 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x101044u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101040u;
            // 0x101044: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101040) {
            ctx->pc = 0x101060u;
            goto label_101060;
        }
    }
    ctx->pc = 0x101048u;
    // 0x101048: 0x34028014  ori         $v0, $zero, 0x8014
    ctx->pc = 0x101048u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32788);
    // 0x10104c: 0x54820013  bnel        $a0, $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x10104Cu;
    {
        const bool branch_taken_0x10104c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x10104c) {
            ctx->pc = 0x101050u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10104Cu;
            // 0x101050: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10109Cu;
            goto label_10109c;
        }
    }
    ctx->pc = 0x101054u;
    // 0x101054: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x101054u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x101058: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x101058u;
    {
        const bool branch_taken_0x101058 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10105Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101058u;
            // 0x10105c: 0x24429480  addiu       $v0, $v0, -0x6B80 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294939776));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101058) {
            ctx->pc = 0x10109Cu;
            goto label_10109c;
        }
    }
    ctx->pc = 0x101060u;
label_101060:
    // 0x101060: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x101060u;
    {
        const bool branch_taken_0x101060 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x101064u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101060u;
            // 0x101064: 0x24428f40  addiu       $v0, $v0, -0x70C0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294938432));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101060) {
            ctx->pc = 0x10109Cu;
            goto label_10109c;
        }
    }
    ctx->pc = 0x101068u;
label_101068:
    // 0x101068: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x101068u;
    {
        const bool branch_taken_0x101068 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10106Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101068u;
            // 0x10106c: 0x24428b00  addiu       $v0, $v0, -0x7500 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937344));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101068) {
            ctx->pc = 0x10109Cu;
            goto label_10109c;
        }
    }
    ctx->pc = 0x101070u;
label_101070:
    // 0x101070: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x101070u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x101074: 0x8c42792c  lw          $v0, 0x792C($v0)
    ctx->pc = 0x101074u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 31020)));
    // 0x101078: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x101078u;
    {
        const bool branch_taken_0x101078 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10107Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101078u;
            // 0x10107c: 0xaca20000  sw          $v0, 0x0($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101078) {
            ctx->pc = 0x1010A0u;
            goto label_1010a0;
        }
    }
    ctx->pc = 0x101080u;
label_101080:
    // 0x101080: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x101080u;
    {
        const bool branch_taken_0x101080 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x101084u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101080u;
            // 0x101084: 0x24428ad0  addiu       $v0, $v0, -0x7530 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937296));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101080) {
            ctx->pc = 0x10109Cu;
            goto label_10109c;
        }
    }
    ctx->pc = 0x101088u;
label_101088:
    // 0x101088: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x101088u;
    {
        const bool branch_taken_0x101088 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10108Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101088u;
            // 0x10108c: 0x24427a00  addiu       $v0, $v0, 0x7A00 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 31232));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101088) {
            ctx->pc = 0x10109Cu;
            goto label_10109c;
        }
    }
    ctx->pc = 0x101090u;
label_101090:
    // 0x101090: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x101090u;
    {
        const bool branch_taken_0x101090 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x101094u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101090u;
            // 0x101094: 0x24427980  addiu       $v0, $v0, 0x7980 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 31104));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101090) {
            ctx->pc = 0x10109Cu;
            goto label_10109c;
        }
    }
    ctx->pc = 0x101098u;
label_101098:
    // 0x101098: 0x8c427928  lw          $v0, 0x7928($v0)
    ctx->pc = 0x101098u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 31016)));
label_10109c:
    // 0x10109c: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x10109cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
label_1010a0:
    // 0x1010a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1010A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1010A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1010A0u;
            // 0x1010a4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x100EA8u: goto label_100ea8;
            case 0x100EB4u: goto label_100eb4;
            case 0x100EE0u: goto label_100ee0;
            case 0x100EE8u: goto label_100ee8;
            case 0x100F04u: goto label_100f04;
            case 0x100F0Cu: goto label_100f0c;
            case 0x100F20u: goto label_100f20;
            case 0x100F28u: goto label_100f28;
            case 0x100F30u: goto label_100f30;
            case 0x100F48u: goto label_100f48;
            case 0x100F50u: goto label_100f50;
            case 0x100F6Cu: goto label_100f6c;
            case 0x100F70u: goto label_100f70;
            case 0x100F84u: goto label_100f84;
            case 0x100FA8u: goto label_100fa8;
            case 0x100FACu: goto label_100fac;
            case 0x100FB0u: goto label_100fb0;
            case 0x100FD4u: goto label_100fd4;
            case 0x100FE0u: goto label_100fe0;
            case 0x101060u: goto label_101060;
            case 0x101068u: goto label_101068;
            case 0x101070u: goto label_101070;
            case 0x101080u: goto label_101080;
            case 0x101088u: goto label_101088;
            case 0x101090u: goto label_101090;
            case 0x101098u: goto label_101098;
            case 0x10109Cu: goto label_10109c;
            case 0x1010A0u: goto label_1010a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1010A8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
