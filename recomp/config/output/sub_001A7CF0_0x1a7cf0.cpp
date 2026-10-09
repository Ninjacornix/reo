#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A7CF0
// Address: 0x1a7cf0 - 0x1a7de0
void sub_001A7CF0_0x1a7cf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A7CF0_0x1a7cf0");
#endif

    switch (ctx->pc) {
        case 0x1a7d0cu: goto label_1a7d0c;
        case 0x1a7d2cu: goto label_1a7d2c;
        case 0x1a7d68u: goto label_1a7d68;
        default: break;
    }

    ctx->pc = 0x1a7cf0u;

    // 0x1a7cf0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a7cf0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a7cf4: 0x2c810003  sltiu       $at, $a0, 0x3
    ctx->pc = 0x1a7cf4u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)3) ? 1 : 0);
    // 0x1a7cf8: 0x14200006  bnez        $at, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A7CF8u;
    {
        const bool branch_taken_0x1a7cf8 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A7CFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7CF8u;
            // 0x1a7cfc: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7cf8) {
            ctx->pc = 0x1A7D14u;
            goto label_1a7d14;
        }
    }
    ctx->pc = 0x1A7D00u;
    // 0x1a7d00: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1a7d00u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1a7d04: 0xc0423b4  jal         func_108ED0
    ctx->pc = 0x1A7D04u;
    SET_GPR_U32(ctx, 31, 0x1A7D0Cu);
    ctx->pc = 0x1A7D08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7D04u;
            // 0x1a7d08: 0x24842360  addiu       $a0, $a0, 0x2360 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9056));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108ED0u;
    if (runtime->hasFunction(0x108ED0u)) {
        auto targetFn = runtime->lookupFunction(0x108ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7D0Cu; }
        if (ctx->pc != 0x1A7D0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108ED0_0x108ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7D0Cu; }
        if (ctx->pc != 0x1A7D0Cu) { return; }
    }
    ctx->pc = 0x1A7D0Cu;
label_1a7d0c:
    // 0x1a7d0c: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x1A7D0Cu;
    {
        const bool branch_taken_0x1a7d0c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A7D10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7D0Cu;
            // 0x1a7d10: 0x2402fffd  addiu       $v0, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7d0c) {
            ctx->pc = 0x1A7DD4u;
            goto label_1a7dd4;
        }
    }
    ctx->pc = 0x1A7D14u;
label_1a7d14:
    // 0x1a7d14: 0x2ca2000a  sltiu       $v0, $a1, 0xA
    ctx->pc = 0x1a7d14u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
    // 0x1a7d18: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A7D18u;
    {
        const bool branch_taken_0x1a7d18 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A7D1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7D18u;
            // 0x1a7d1c: 0x3c01002b  lui         $at, 0x2B (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7d18) {
            ctx->pc = 0x1A7D34u;
            goto label_1a7d34;
        }
    }
    ctx->pc = 0x1A7D20u;
    // 0x1a7d20: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1a7d20u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1a7d24: 0xc0423b4  jal         func_108ED0
    ctx->pc = 0x1A7D24u;
    SET_GPR_U32(ctx, 31, 0x1A7D2Cu);
    ctx->pc = 0x1A7D28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7D24u;
            // 0x1a7d28: 0x24842390  addiu       $a0, $a0, 0x2390 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9104));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108ED0u;
    if (runtime->hasFunction(0x108ED0u)) {
        auto targetFn = runtime->lookupFunction(0x108ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7D2Cu; }
        if (ctx->pc != 0x1A7D2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108ED0_0x108ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7D2Cu; }
        if (ctx->pc != 0x1A7D2Cu) { return; }
    }
    ctx->pc = 0x1A7D2Cu;
label_1a7d2c:
    // 0x1a7d2c: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x1A7D2Cu;
    {
        const bool branch_taken_0x1a7d2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A7D30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7D2Cu;
            // 0x1a7d30: 0x2402fffe  addiu       $v0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7d2c) {
            ctx->pc = 0x1A7DD4u;
            goto label_1a7dd4;
        }
    }
    ctx->pc = 0x1A7D34u;
label_1a7d34:
    // 0x1a7d34: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1a7d34u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1a7d38: 0x8c290a68  lw          $t1, 0xA68($at)
    ctx->pc = 0x1a7d38u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2664)));
    // 0x1a7d3c: 0x24420a80  addiu       $v0, $v0, 0xA80
    ctx->pc = 0x1a7d3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2688));
    // 0x1a7d40: 0x91840  sll         $v1, $t1, 1
    ctx->pc = 0x1a7d40u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 9), 1));
    // 0x1a7d44: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x1a7d44u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x1a7d48: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1a7d48u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1a7d4c: 0x434821  addu        $t1, $v0, $v1
    ctx->pc = 0x1a7d4cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a7d50: 0x8d220000  lw          $v0, 0x0($t1)
    ctx->pc = 0x1a7d50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1a7d54: 0x4400006  bltz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A7D54u;
    {
        const bool branch_taken_0x1a7d54 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1A7D58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7D54u;
            // 0x1a7d58: 0x24830001  addiu       $v1, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7d54) {
            ctx->pc = 0x1A7D70u;
            goto label_1a7d70;
        }
    }
    ctx->pc = 0x1A7D5Cu;
    // 0x1a7d5c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1a7d5cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1a7d60: 0xc0423b4  jal         func_108ED0
    ctx->pc = 0x1A7D60u;
    SET_GPR_U32(ctx, 31, 0x1A7D68u);
    ctx->pc = 0x1A7D64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7D60u;
            // 0x1a7d64: 0x248423c0  addiu       $a0, $a0, 0x23C0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9152));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108ED0u;
    if (runtime->hasFunction(0x108ED0u)) {
        auto targetFn = runtime->lookupFunction(0x108ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7D68u; }
        if (ctx->pc != 0x1A7D68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108ED0_0x108ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7D68u; }
        if (ctx->pc != 0x1A7D68u) { return; }
    }
    ctx->pc = 0x1A7D68u;
label_1a7d68:
    // 0x1a7d68: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x1A7D68u;
    {
        const bool branch_taken_0x1a7d68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A7D6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7D68u;
            // 0x1a7d6c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7d68) {
            ctx->pc = 0x1A7DD4u;
            goto label_1a7dd4;
        }
    }
    ctx->pc = 0x1A7D70u;
label_1a7d70:
    // 0x1a7d70: 0x6143c  dsll32      $v0, $a2, 16
    ctx->pc = 0x1a7d70u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) << (32 + 16));
    // 0x1a7d74: 0x32180  sll         $a0, $v1, 6
    ctx->pc = 0x1a7d74u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 6));
    // 0x1a7d78: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1a7d78u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1a7d7c: 0xa42825  or          $a1, $a1, $a0
    ctx->pc = 0x1a7d7cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x1a7d80: 0x3043ffff  andi        $v1, $v0, 0xFFFF
    ctx->pc = 0x1a7d80u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1a7d84: 0x52400  sll         $a0, $a1, 16
    ctx->pc = 0x1a7d84u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 16));
    // 0x1a7d88: 0x3c024400  lui         $v0, 0x4400
    ctx->pc = 0x1a7d88u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17408 << 16));
    // 0x1a7d8c: 0x831825  or          $v1, $a0, $v1
    ctx->pc = 0x1a7d8cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1a7d90: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a7d90u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a7d94: 0x31a3c  dsll32      $v1, $v1, 8
    ctx->pc = 0x1a7d94u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 8));
    // 0x1a7d98: 0x31a3e  dsrl32      $v1, $v1, 8
    ctx->pc = 0x1a7d98u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 8));
    // 0x1a7d9c: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1a7d9cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1a7da0: 0xad220000  sw          $v0, 0x0($t1)
    ctx->pc = 0x1a7da0u;
    WRITE32(ADD32(GPR_U32(ctx, 9), 0), GPR_U32(ctx, 2));
    // 0x1a7da4: 0xa1270004  sb          $a3, 0x4($t1)
    ctx->pc = 0x1a7da4u;
    WRITE8(ADD32(GPR_U32(ctx, 9), 4), (uint8_t)GPR_U32(ctx, 7));
    // 0x1a7da8: 0xa1280005  sb          $t0, 0x5($t1)
    ctx->pc = 0x1a7da8u;
    WRITE8(ADD32(GPR_U32(ctx, 9), 5), (uint8_t)GPR_U32(ctx, 8));
    // 0x1a7dac: 0x8c220a68  lw          $v0, 0xA68($at)
    ctx->pc = 0x1a7dacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2664)));
    // 0x1a7db0: 0x24430001  addiu       $v1, $v0, 0x1
    ctx->pc = 0x1a7db0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1a7db4: 0x4610004  bgez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1A7DB4u;
    {
        const bool branch_taken_0x1a7db4 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1A7DB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7DB4u;
            // 0x1a7db8: 0x3062001f  andi        $v0, $v1, 0x1F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)31);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7db4) {
            ctx->pc = 0x1A7DC8u;
            goto label_1a7dc8;
        }
    }
    ctx->pc = 0x1A7DBCu;
    // 0x1a7dbc: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1A7DBCu;
    {
        const bool branch_taken_0x1a7dbc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a7dbc) {
            ctx->pc = 0x1A7DC8u;
            goto label_1a7dc8;
        }
    }
    ctx->pc = 0x1A7DC4u;
    // 0x1a7dc4: 0x2442ffe0  addiu       $v0, $v0, -0x20
    ctx->pc = 0x1a7dc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967264));
label_1a7dc8:
    // 0x1a7dc8: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a7dc8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a7dcc: 0xac220a68  sw          $v0, 0xA68($at)
    ctx->pc = 0x1a7dccu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 2664), GPR_U32(ctx, 2));
    // 0x1a7dd0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1a7dd0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1a7dd4:
    // 0x1a7dd4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a7dd4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a7dd8: 0x3e00008  jr          $ra
    ctx->pc = 0x1A7DD8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A7DDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7DD8u;
            // 0x1a7ddc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A7D0Cu: goto label_1a7d0c;
            case 0x1A7D14u: goto label_1a7d14;
            case 0x1A7D2Cu: goto label_1a7d2c;
            case 0x1A7D34u: goto label_1a7d34;
            case 0x1A7D68u: goto label_1a7d68;
            case 0x1A7D70u: goto label_1a7d70;
            case 0x1A7DC8u: goto label_1a7dc8;
            case 0x1A7DD4u: goto label_1a7dd4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A7DE0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
