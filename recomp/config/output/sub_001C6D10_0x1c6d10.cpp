#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C6D10
// Address: 0x1c6d10 - 0x1c6e70
void sub_001C6D10_0x1c6d10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C6D10_0x1c6d10");
#endif

    switch (ctx->pc) {
        case 0x1c6d34u: goto label_1c6d34;
        case 0x1c6d54u: goto label_1c6d54;
        case 0x1c6db4u: goto label_1c6db4;
        case 0x1c6dc8u: goto label_1c6dc8;
        case 0x1c6ddcu: goto label_1c6ddc;
        default: break;
    }

    ctx->pc = 0x1c6d10u;

    // 0x1c6d10: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1c6d10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1c6d14: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1c6d14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1c6d18: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c6d18u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c6d1c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1c6d1cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c6d20: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c6d20u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c6d24: 0x3c040033  lui         $a0, 0x33
    ctx->pc = 0x1c6d24u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
    // 0x1c6d28: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1c6d28u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c6d2c: 0xc071f2c  jal         func_1C7CB0
    ctx->pc = 0x1C6D2Cu;
    SET_GPR_U32(ctx, 31, 0x1C6D34u);
    ctx->pc = 0x1C6D30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6D2Cu;
            // 0x1c6d30: 0x248437b0  addiu       $a0, $a0, 0x37B0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 14256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7CB0u;
    if (runtime->hasFunction(0x1C7CB0u)) {
        auto targetFn = runtime->lookupFunction(0x1C7CB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6D34u; }
        if (ctx->pc != 0x1C6D34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7CB0_0x1c7cb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6D34u; }
        if (ctx->pc != 0x1C6D34u) { return; }
    }
    ctx->pc = 0x1C6D34u;
label_1c6d34:
    // 0x1c6d34: 0x26030002  addiu       $v1, $s0, 0x2
    ctx->pc = 0x1c6d34u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 2));
    // 0x1c6d38: 0x62082a  slt         $at, $v1, $v0
    ctx->pc = 0x1c6d38u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1c6d3c: 0x14200014  bnez        $at, . + 4 + (0x14 << 2)
    ctx->pc = 0x1C6D3Cu;
    {
        const bool branch_taken_0x1c6d3c = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c6d3c) {
            ctx->pc = 0x1C6D90u;
            goto label_1c6d90;
        }
    }
    ctx->pc = 0x1C6D44u;
    // 0x1c6d44: 0x24040005  addiu       $a0, $zero, 0x5
    ctx->pc = 0x1c6d44u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c6d48: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1c6d48u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c6d4c: 0xc071eb0  jal         func_1C7AC0
    ctx->pc = 0x1C6D4Cu;
    SET_GPR_U32(ctx, 31, 0x1C6D54u);
    ctx->pc = 0x1C6D50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6D4Cu;
            // 0x1c6d50: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7AC0u;
    if (runtime->hasFunction(0x1C7AC0u)) {
        auto targetFn = runtime->lookupFunction(0x1C7AC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6D54u; }
        if (ctx->pc != 0x1C6D54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7AC0_0x1c7ac0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6D54u; }
        if (ctx->pc != 0x1C6D54u) { return; }
    }
    ctx->pc = 0x1C6D54u;
label_1c6d54:
    // 0x1c6d54: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6d54u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6d58: 0x24030015  addiu       $v1, $zero, 0x15
    ctx->pc = 0x1c6d58u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
    // 0x1c6d5c: 0x942451b8  lhu         $a0, 0x51B8($at)
    ctx->pc = 0x1c6d5cu;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 20920)));
    // 0x1c6d60: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6d60u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6d64: 0xac2351b0  sw          $v1, 0x51B0($at)
    ctx->pc = 0x1c6d64u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 20912), GPR_U32(ctx, 3));
    // 0x1c6d68: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1c6d68u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1c6d6c: 0x8c235f58  lw          $v1, 0x5F58($at)
    ctx->pc = 0x1c6d6cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24408)));
    // 0x1c6d70: 0x83182a  slt         $v1, $a0, $v1
    ctx->pc = 0x1c6d70u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1c6d74: 0x14600037  bnez        $v1, . + 4 + (0x37 << 2)
    ctx->pc = 0x1C6D74u;
    {
        const bool branch_taken_0x1c6d74 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c6d74) {
            ctx->pc = 0x1C6E54u;
            goto label_1c6e54;
        }
    }
    ctx->pc = 0x1C6D7Cu;
    // 0x1c6d7c: 0x24030010  addiu       $v1, $zero, 0x10
    ctx->pc = 0x1c6d7cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1c6d80: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6d80u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6d84: 0xac2351b0  sw          $v1, 0x51B0($at)
    ctx->pc = 0x1c6d84u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 20912), GPR_U32(ctx, 3));
    // 0x1c6d88: 0x10000033  b           . + 4 + (0x33 << 2)
    ctx->pc = 0x1C6D88u;
    {
        const bool branch_taken_0x1c6d88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C6D8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6D88u;
            // 0x1c6d8c: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c6d88) {
            ctx->pc = 0x1C6E58u;
            goto label_1c6e58;
        }
    }
    ctx->pc = 0x1C6D90u;
label_1c6d90:
    // 0x1c6d90: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6d90u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6d94: 0x3c040033  lui         $a0, 0x33
    ctx->pc = 0x1c6d94u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
    // 0x1c6d98: 0x90235054  lbu         $v1, 0x5054($at)
    ctx->pc = 0x1c6d98u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 20564)));
    // 0x1c6d9c: 0x32020fff  andi        $v0, $s0, 0xFFF
    ctx->pc = 0x1c6d9cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)4095);
    // 0x1c6da0: 0x248437b0  addiu       $a0, $a0, 0x37B0
    ctx->pc = 0x1c6da0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 14256));
    // 0x1c6da4: 0x31b00  sll         $v1, $v1, 12
    ctx->pc = 0x1c6da4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 12));
    // 0x1c6da8: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1c6da8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1c6dac: 0xc071f54  jal         func_1C7D50
    ctx->pc = 0x1C6DACu;
    SET_GPR_U32(ctx, 31, 0x1C6DB4u);
    ctx->pc = 0x1C6DB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6DACu;
            // 0x1c6db0: 0x3045ffff  andi        $a1, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7D50u;
    if (runtime->hasFunction(0x1C7D50u)) {
        auto targetFn = runtime->lookupFunction(0x1C7D50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6DB4u; }
        if (ctx->pc != 0x1C6DB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7D50_0x1c7d50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6DB4u; }
        if (ctx->pc != 0x1C6DB4u) { return; }
    }
    ctx->pc = 0x1C6DB4u;
label_1c6db4:
    // 0x1c6db4: 0x3c040033  lui         $a0, 0x33
    ctx->pc = 0x1c6db4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
    // 0x1c6db8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1c6db8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c6dbc: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1c6dbcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c6dc0: 0xc071f4c  jal         func_1C7D30
    ctx->pc = 0x1C6DC0u;
    SET_GPR_U32(ctx, 31, 0x1C6DC8u);
    ctx->pc = 0x1C6DC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6DC0u;
            // 0x1c6dc4: 0x248437b0  addiu       $a0, $a0, 0x37B0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 14256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7D30u;
    if (runtime->hasFunction(0x1C7D30u)) {
        auto targetFn = runtime->lookupFunction(0x1C7D30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6DC8u; }
        if (ctx->pc != 0x1C6DC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7D30_0x1c7d30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6DC8u; }
        if (ctx->pc != 0x1C6DC8u) { return; }
    }
    ctx->pc = 0x1C6DC8u;
label_1c6dc8:
    // 0x1c6dc8: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6dc8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6dcc: 0x3c040033  lui         $a0, 0x33
    ctx->pc = 0x1c6dccu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
    // 0x1c6dd0: 0x8c3051d0  lw          $s0, 0x51D0($at)
    ctx->pc = 0x1c6dd0u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 20944)));
    // 0x1c6dd4: 0xc071f24  jal         func_1C7C90
    ctx->pc = 0x1C6DD4u;
    SET_GPR_U32(ctx, 31, 0x1C6DDCu);
    ctx->pc = 0x1C6DD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6DD4u;
            // 0x1c6dd8: 0x248437b0  addiu       $a0, $a0, 0x37B0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 14256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7C90u;
    if (runtime->hasFunction(0x1C7C90u)) {
        auto targetFn = runtime->lookupFunction(0x1C7C90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6DDCu; }
        if (ctx->pc != 0x1C6DDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7C90_0x1c7c90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6DDCu; }
        if (ctx->pc != 0x1C6DDCu) { return; }
    }
    ctx->pc = 0x1C6DDCu;
label_1c6ddc:
    // 0x1c6ddc: 0x202082a  slt         $at, $s0, $v0
    ctx->pc = 0x1c6ddcu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1c6de0: 0x10200017  beqz        $at, . + 4 + (0x17 << 2)
    ctx->pc = 0x1C6DE0u;
    {
        const bool branch_taken_0x1c6de0 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c6de0) {
            ctx->pc = 0x1C6E40u;
            goto label_1c6e40;
        }
    }
    ctx->pc = 0x1C6DE8u;
    // 0x1c6de8: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6de8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6dec: 0xac2251d0  sw          $v0, 0x51D0($at)
    ctx->pc = 0x1c6decu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 20944), GPR_U32(ctx, 2));
    // 0x1c6df0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c6df0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c6df4: 0x902643dc  lbu         $a2, 0x43DC($at)
    ctx->pc = 0x1c6df4u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17372)));
    // 0x1c6df8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c6df8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c6dfc: 0x902543dd  lbu         $a1, 0x43DD($at)
    ctx->pc = 0x1c6dfcu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17373)));
    // 0x1c6e00: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c6e00u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c6e04: 0x52a00  sll         $a1, $a1, 8
    ctx->pc = 0x1c6e04u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 8));
    // 0x1c6e08: 0x902443da  lbu         $a0, 0x43DA($at)
    ctx->pc = 0x1c6e08u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1c6e0c: 0xc52825  or          $a1, $a2, $a1
    ctx->pc = 0x1c6e0cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 6) | GPR_U64(ctx, 5));
    // 0x1c6e10: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c6e10u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c6e14: 0x902343db  lbu         $v1, 0x43DB($at)
    ctx->pc = 0x1c6e14u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17371)));
    // 0x1c6e18: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x1c6e18u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x1c6e1c: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6e1cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6e20: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x1c6e20u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1c6e24: 0x41940  sll         $v1, $a0, 5
    ctx->pc = 0x1c6e24u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 5));
    // 0x1c6e28: 0x641823  subu        $v1, $v1, $a0
    ctx->pc = 0x1c6e28u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1c6e2c: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1c6e2cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1c6e30: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1c6e30u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1c6e34: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x1c6e34u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1c6e38: 0xa31821  addu        $v1, $a1, $v1
    ctx->pc = 0x1c6e38u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x1c6e3c: 0xac2351c0  sw          $v1, 0x51C0($at)
    ctx->pc = 0x1c6e3cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 20928), GPR_U32(ctx, 3));
label_1c6e40:
    // 0x1c6e40: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6e40u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6e44: 0x8c235084  lw          $v1, 0x5084($at)
    ctx->pc = 0x1c6e44u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 20612)));
    // 0x1c6e48: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1c6e48u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1c6e4c: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c6e4cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c6e50: 0xac235084  sw          $v1, 0x5084($at)
    ctx->pc = 0x1c6e50u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 20612), GPR_U32(ctx, 3));
label_1c6e54:
    // 0x1c6e54: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1c6e54u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_1c6e58:
    // 0x1c6e58: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c6e58u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c6e5c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c6e5cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c6e60: 0x3e00008  jr          $ra
    ctx->pc = 0x1C6E60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C6E64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6E60u;
            // 0x1c6e64: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C6D34u: goto label_1c6d34;
            case 0x1C6D54u: goto label_1c6d54;
            case 0x1C6D90u: goto label_1c6d90;
            case 0x1C6DB4u: goto label_1c6db4;
            case 0x1C6DC8u: goto label_1c6dc8;
            case 0x1C6DDCu: goto label_1c6ddc;
            case 0x1C6E40u: goto label_1c6e40;
            case 0x1C6E54u: goto label_1c6e54;
            case 0x1C6E58u: goto label_1c6e58;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C6E68u;
    // 0x1c6e68: 0x0  nop
    ctx->pc = 0x1c6e68u;
    // NOP
    // 0x1c6e6c: 0x0  nop
    ctx->pc = 0x1c6e6cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
