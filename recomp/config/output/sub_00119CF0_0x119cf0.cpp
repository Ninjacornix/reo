#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00119CF0
// Address: 0x119cf0 - 0x119ec0
void sub_00119CF0_0x119cf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00119CF0_0x119cf0");
#endif

    switch (ctx->pc) {
        case 0x119d30u: goto label_119d30;
        case 0x119d48u: goto label_119d48;
        case 0x119d70u: goto label_119d70;
        case 0x119ddcu: goto label_119ddc;
        case 0x119e18u: goto label_119e18;
        case 0x119e28u: goto label_119e28;
        case 0x119e30u: goto label_119e30;
        case 0x119e44u: goto label_119e44;
        case 0x119e54u: goto label_119e54;
        case 0x119e64u: goto label_119e64;
        case 0x119e6cu: goto label_119e6c;
        case 0x119eb0u: goto label_119eb0;
        default: break;
    }

    ctx->pc = 0x119cf0u;

    // 0x119cf0: 0x27bdff30  addiu       $sp, $sp, -0xD0
    ctx->pc = 0x119cf0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967088));
    // 0x119cf4: 0xffb10050  sd          $s1, 0x50($sp)
    ctx->pc = 0x119cf4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 17));
    // 0x119cf8: 0xffb600a0  sd          $s6, 0xA0($sp)
    ctx->pc = 0x119cf8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 22));
    // 0x119cfc: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x119cfcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x119d00: 0xffb700b0  sd          $s7, 0xB0($sp)
    ctx->pc = 0x119d00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 23));
    // 0x119d04: 0xa0b02d  daddu       $s6, $a1, $zero
    ctx->pc = 0x119d04u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x119d08: 0xffb20060  sd          $s2, 0x60($sp)
    ctx->pc = 0x119d08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 18));
    // 0x119d0c: 0x24040007  addiu       $a0, $zero, 0x7
    ctx->pc = 0x119d0cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x119d10: 0xffbf00c0  sd          $ra, 0xC0($sp)
    ctx->pc = 0x119d10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 192), GPR_U64(ctx, 31));
    // 0x119d14: 0x3c170026  lui         $s7, 0x26
    ctx->pc = 0x119d14u;
    SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)38 << 16));
    // 0x119d18: 0xffb50090  sd          $s5, 0x90($sp)
    ctx->pc = 0x119d18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 21));
    // 0x119d1c: 0x26f2ca40  addiu       $s2, $s7, -0x35C0
    ctx->pc = 0x119d1cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 23), 4294953536));
    // 0x119d20: 0xffb40080  sd          $s4, 0x80($sp)
    ctx->pc = 0x119d20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 20));
    // 0x119d24: 0xffb30070  sd          $s3, 0x70($sp)
    ctx->pc = 0x119d24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 19));
    // 0x119d28: 0xc04619c  jal         func_118670
    ctx->pc = 0x119D28u;
    SET_GPR_U32(ctx, 31, 0x119D30u);
    ctx->pc = 0x119D2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119D28u;
            // 0x119d2c: 0xffb00040  sd          $s0, 0x40($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118670u;
    if (runtime->hasFunction(0x118670u)) {
        auto targetFn = runtime->lookupFunction(0x118670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119D30u; }
        if (ctx->pc != 0x119D30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118670_0x118670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119D30u; }
        if (ctx->pc != 0x119D30u) { return; }
    }
    ctx->pc = 0x119D30u;
label_119d30:
    // 0x119d30: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x119d30u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x119d34: 0x8c439ddc  lw          $v1, -0x6224($v0)
    ctx->pc = 0x119d34u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294942172)));
    // 0x119d38: 0x54600004  bnel        $v1, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x119D38u;
    {
        const bool branch_taken_0x119d38 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x119d38) {
            ctx->pc = 0x119D3Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x119D38u;
            // 0x119d3c: 0x92220000  lbu         $v0, 0x0($s1) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x119D4Cu;
            goto label_119d4c;
        }
    }
    ctx->pc = 0x119D40u;
    // 0x119d40: 0xc0461e8  jal         func_1187A0
    ctx->pc = 0x119D40u;
    SET_GPR_U32(ctx, 31, 0x119D48u);
    ctx->pc = 0x1187A0u;
    if (runtime->hasFunction(0x1187A0u)) {
        auto targetFn = runtime->lookupFunction(0x1187A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119D48u; }
        if (ctx->pc != 0x119D48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001187A0_0x1187a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119D48u; }
        if (ctx->pc != 0x119D48u) { return; }
    }
    ctx->pc = 0x119D48u;
label_119d48:
    // 0x119d48: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x119d48u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
label_119d4c:
    // 0x119d4c: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x119d4cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x119d50: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x119d50u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x119d54: 0x10600011  beqz        $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x119D54u;
    {
        const bool branch_taken_0x119d54 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x119D58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119D54u;
            // 0x119d58: 0xa2420010  sb          $v0, 0x10($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 16), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119d54) {
            ctx->pc = 0x119D9Cu;
            goto label_119d9c;
        }
    }
    ctx->pc = 0x119D5Cu;
    // 0x119d5c: 0x27b30030  addiu       $s3, $sp, 0x30
    ctx->pc = 0x119d5cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x119d60: 0x3c150026  lui         $s5, 0x26
    ctx->pc = 0x119d60u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
    // 0x119d64: 0x3c140026  lui         $s4, 0x26
    ctx->pc = 0x119d64u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)38 << 16));
    // 0x119d68: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x119d68u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x119d6c: 0x0  nop
    ctx->pc = 0x119d6cu;
    // NOP
label_119d70:
    // 0x119d70: 0x2a020400  slti        $v0, $s0, 0x400
    ctx->pc = 0x119d70u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)1024) ? 1 : 0);
    // 0x119d74: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x119D74u;
    {
        const bool branch_taken_0x119d74 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x119D78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119D74u;
            // 0x119d78: 0x2301021  addu        $v0, $s1, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119d74) {
            ctx->pc = 0x119DA8u;
            goto label_119da8;
        }
    }
    ctx->pc = 0x119D7Cu;
    // 0x119d7c: 0x2502021  addu        $a0, $s2, $s0
    ctx->pc = 0x119d7cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 16)));
    // 0x119d80: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x119d80u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x119d84: 0xa0830010  sb          $v1, 0x10($a0)
    ctx->pc = 0x119d84u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 16), (uint8_t)GPR_U32(ctx, 3));
    // 0x119d88: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x119d88u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x119d8c: 0x5460fff8  bnel        $v1, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x119D8Cu;
    {
        const bool branch_taken_0x119d8c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x119d8c) {
            ctx->pc = 0x119D90u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x119D8Cu;
            // 0x119d90: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x119D70u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_119d70;
        }
    }
    ctx->pc = 0x119D94u;
    // 0x119d94: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x119D94u;
    {
        const bool branch_taken_0x119d94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x119D98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119D94u;
            // 0x119d98: 0x24020400  addiu       $v0, $zero, 0x400 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119d94) {
            ctx->pc = 0x119DACu;
            goto label_119dac;
        }
    }
    ctx->pc = 0x119D9Cu;
label_119d9c:
    // 0x119d9c: 0x27b30030  addiu       $s3, $sp, 0x30
    ctx->pc = 0x119d9cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x119da0: 0x3c150026  lui         $s5, 0x26
    ctx->pc = 0x119da0u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
    // 0x119da4: 0x3c140026  lui         $s4, 0x26
    ctx->pc = 0x119da4u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)38 << 16));
label_119da8:
    // 0x119da8: 0x24020400  addiu       $v0, $zero, 0x400
    ctx->pc = 0x119da8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
label_119dac:
    // 0x119dac: 0x56020004  bnel        $s0, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x119DACu;
    {
        const bool branch_taken_0x119dac = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        if (branch_taken_0x119dac) {
            ctx->pc = 0x119DB0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x119DACu;
            // 0x119db0: 0xae56000c  sw          $s6, 0xC($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 12), GPR_U32(ctx, 22));
        ctx->in_delay_slot = false;
            ctx->pc = 0x119DC0u;
            goto label_119dc0;
        }
    }
    ctx->pc = 0x119DB4u;
    // 0x119db4: 0xa240040f  sb          $zero, 0x40F($s2)
    ctx->pc = 0x119db4u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 1039), (uint8_t)GPR_U32(ctx, 0));
    // 0x119db8: 0x241003ff  addiu       $s0, $zero, 0x3FF
    ctx->pc = 0x119db8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1023));
    // 0x119dbc: 0xae56000c  sw          $s6, 0xC($s2)
    ctx->pc = 0x119dbcu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 12), GPR_U32(ctx, 22));
label_119dc0:
    // 0x119dc0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x119dc0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x119dc4: 0xafa20014  sw          $v0, 0x14($sp)
    ctx->pc = 0x119dc4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x119dc8: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x119dc8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x119dcc: 0xafa00018  sw          $zero, 0x18($sp)
    ctx->pc = 0x119dccu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
    // 0x119dd0: 0x2694d680  addiu       $s4, $s4, -0x2980
    ctx->pc = 0x119dd0u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 4294956672));
    // 0x119dd4: 0xc045188  jal         func_114620
    ctx->pc = 0x119DD4u;
    SET_GPR_U32(ctx, 31, 0x119DDCu);
    ctx->pc = 0x119DD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119DD4u;
            // 0x119dd8: 0xafa00024  sw          $zero, 0x24($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119DDCu; }
        if (ctx->pc != 0x119DDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119DDCu; }
        if (ctx->pc != 0x119DDCu) { return; }
    }
    ctx->pc = 0x119DDCu;
label_119ddc:
    // 0x119ddc: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x119ddcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x119de0: 0xae530004  sw          $s3, 0x4($s2)
    ctx->pc = 0x119de0u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 19));
    // 0x119de4: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x119de4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x119de8: 0xae510000  sw          $s1, 0x0($s2)
    ctx->pc = 0x119de8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 17));
    // 0x119dec: 0xae420008  sw          $v0, 0x8($s2)
    ctx->pc = 0x119decu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 2));
    // 0x119df0: 0x26a4e140  addiu       $a0, $s5, -0x1EC0
    ctx->pc = 0x119df0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), 4294959424));
    // 0x119df4: 0x26e7ca40  addiu       $a3, $s7, -0x35C0
    ctx->pc = 0x119df4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 23), 4294953536));
    // 0x119df8: 0x26080011  addiu       $t0, $s0, 0x11
    ctx->pc = 0x119df8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 16), 17));
    // 0x119dfc: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x119dfcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x119e00: 0x24050007  addiu       $a1, $zero, 0x7
    ctx->pc = 0x119e00u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x119e04: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x119e04u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x119e08: 0x280482d  daddu       $t1, $s4, $zero
    ctx->pc = 0x119e08u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x119e0c: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x119e0cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x119e10: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x119E10u;
    SET_GPR_U32(ctx, 31, 0x119E18u);
    ctx->pc = 0x119E14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119E10u;
            // 0x119e14: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119E18u; }
        if (ctx->pc != 0x119E18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119E18u; }
        if (ctx->pc != 0x119E18u) { return; }
    }
    ctx->pc = 0x119E18u;
label_119e18:
    // 0x119e18: 0x4410007  bgez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x119E18u;
    {
        const bool branch_taken_0x119e18 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x119E1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119E18u;
            // 0x119e1c: 0x3c022000  lui         $v0, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119e18) {
            ctx->pc = 0x119E38u;
            goto label_119e38;
        }
    }
    ctx->pc = 0x119E20u;
    // 0x119e20: 0xc04518c  jal         func_114630
    ctx->pc = 0x119E20u;
    SET_GPR_U32(ctx, 31, 0x119E28u);
    ctx->pc = 0x119E24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119E20u;
            // 0x119e24: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119E28u; }
        if (ctx->pc != 0x119E28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119E28u; }
        if (ctx->pc != 0x119E28u) { return; }
    }
    ctx->pc = 0x119E28u;
label_119e28:
    // 0x119e28: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x119E28u;
    SET_GPR_U32(ctx, 31, 0x119E30u);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119E30u; }
        if (ctx->pc != 0x119E30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119E30u; }
        if (ctx->pc != 0x119E30u) { return; }
    }
    ctx->pc = 0x119E30u;
label_119e30:
    // 0x119e30: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x119E30u;
    {
        const bool branch_taken_0x119e30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x119E34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119E30u;
            // 0x119e34: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119e30) {
            ctx->pc = 0x119E70u;
            goto label_119e70;
        }
    }
    ctx->pc = 0x119E38u;
label_119e38:
    // 0x119e38: 0x2821025  or          $v0, $s4, $v0
    ctx->pc = 0x119e38u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) | GPR_U64(ctx, 2));
    // 0x119e3c: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x119E3Cu;
    SET_GPR_U32(ctx, 31, 0x119E44u);
    ctx->pc = 0x119E40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119E3Cu;
            // 0x119e40: 0x8c500000  lw          $s0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119E44u; }
        if (ctx->pc != 0x119E44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119E44u; }
        if (ctx->pc != 0x119E44u) { return; }
    }
    ctx->pc = 0x119E44u;
label_119e44:
    // 0x119e44: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x119E44u;
    {
        const bool branch_taken_0x119e44 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x119e44) {
            ctx->pc = 0x119E5Cu;
            goto label_119e5c;
        }
    }
    ctx->pc = 0x119E4Cu;
    // 0x119e4c: 0xc04518c  jal         func_114630
    ctx->pc = 0x119E4Cu;
    SET_GPR_U32(ctx, 31, 0x119E54u);
    ctx->pc = 0x119E50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119E4Cu;
            // 0x119e50: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119E54u; }
        if (ctx->pc != 0x119E54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119E54u; }
        if (ctx->pc != 0x119E54u) { return; }
    }
    ctx->pc = 0x119E54u;
label_119e54:
    // 0x119e54: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x119E54u;
    {
        const bool branch_taken_0x119e54 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x119E58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119E54u;
            // 0x119e58: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119e54) {
            ctx->pc = 0x119E70u;
            goto label_119e70;
        }
    }
    ctx->pc = 0x119E5Cu;
label_119e5c:
    // 0x119e5c: 0xc045198  jal         func_114660
    ctx->pc = 0x119E5Cu;
    SET_GPR_U32(ctx, 31, 0x119E64u);
    ctx->pc = 0x119E60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119E5Cu;
            // 0x119e60: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119E64u; }
        if (ctx->pc != 0x119E64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119E64u; }
        if (ctx->pc != 0x119E64u) { return; }
    }
    ctx->pc = 0x119E64u;
label_119e64:
    // 0x119e64: 0xc04518c  jal         func_114630
    ctx->pc = 0x119E64u;
    SET_GPR_U32(ctx, 31, 0x119E6Cu);
    ctx->pc = 0x119E68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119E64u;
            // 0x119e68: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119E6Cu; }
        if (ctx->pc != 0x119E6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119E6Cu; }
        if (ctx->pc != 0x119E6Cu) { return; }
    }
    ctx->pc = 0x119E6Cu;
label_119e6c:
    // 0x119e6c: 0x8fa20030  lw          $v0, 0x30($sp)
    ctx->pc = 0x119e6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_119e70:
    // 0x119e70: 0xdfbf00c0  ld          $ra, 0xC0($sp)
    ctx->pc = 0x119e70u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x119e74: 0xdfb700b0  ld          $s7, 0xB0($sp)
    ctx->pc = 0x119e74u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x119e78: 0xdfb600a0  ld          $s6, 0xA0($sp)
    ctx->pc = 0x119e78u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x119e7c: 0xdfb50090  ld          $s5, 0x90($sp)
    ctx->pc = 0x119e7cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x119e80: 0xdfb40080  ld          $s4, 0x80($sp)
    ctx->pc = 0x119e80u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x119e84: 0xdfb30070  ld          $s3, 0x70($sp)
    ctx->pc = 0x119e84u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x119e88: 0xdfb20060  ld          $s2, 0x60($sp)
    ctx->pc = 0x119e88u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x119e8c: 0xdfb10050  ld          $s1, 0x50($sp)
    ctx->pc = 0x119e8cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x119e90: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x119e90u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x119e94: 0x3e00008  jr          $ra
    ctx->pc = 0x119E94u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x119E98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119E94u;
            // 0x119e98: 0x27bd00d0  addiu       $sp, $sp, 0xD0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 208));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x119D30u: goto label_119d30;
            case 0x119D48u: goto label_119d48;
            case 0x119D4Cu: goto label_119d4c;
            case 0x119D70u: goto label_119d70;
            case 0x119D9Cu: goto label_119d9c;
            case 0x119DA8u: goto label_119da8;
            case 0x119DACu: goto label_119dac;
            case 0x119DC0u: goto label_119dc0;
            case 0x119DDCu: goto label_119ddc;
            case 0x119E18u: goto label_119e18;
            case 0x119E28u: goto label_119e28;
            case 0x119E30u: goto label_119e30;
            case 0x119E38u: goto label_119e38;
            case 0x119E44u: goto label_119e44;
            case 0x119E54u: goto label_119e54;
            case 0x119E5Cu: goto label_119e5c;
            case 0x119E64u: goto label_119e64;
            case 0x119E6Cu: goto label_119e6c;
            case 0x119E70u: goto label_119e70;
            case 0x119EB0u: goto label_119eb0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x119E9Cu;
    // 0x119e9c: 0x0  nop
    ctx->pc = 0x119e9cu;
    // NOP
    // 0x119ea0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x119ea0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x119ea4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x119ea4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x119ea8: 0xc0466ca  jal         func_119B28
    ctx->pc = 0x119EA8u;
    SET_GPR_U32(ctx, 31, 0x119EB0u);
    ctx->pc = 0x119EACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119EA8u;
            // 0x119eac: 0x24050008  addiu       $a1, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x119B28u;
    if (runtime->hasFunction(0x119B28u)) {
        auto targetFn = runtime->lookupFunction(0x119B28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119EB0u; }
        if (ctx->pc != 0x119EB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00119B28_0x119b28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119EB0u; }
        if (ctx->pc != 0x119EB0u) { return; }
    }
    ctx->pc = 0x119EB0u;
label_119eb0:
    // 0x119eb0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x119eb0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x119eb4: 0x3e00008  jr          $ra
    ctx->pc = 0x119EB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x119EB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119EB4u;
            // 0x119eb8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x119D30u: goto label_119d30;
            case 0x119D48u: goto label_119d48;
            case 0x119D4Cu: goto label_119d4c;
            case 0x119D70u: goto label_119d70;
            case 0x119D9Cu: goto label_119d9c;
            case 0x119DA8u: goto label_119da8;
            case 0x119DACu: goto label_119dac;
            case 0x119DC0u: goto label_119dc0;
            case 0x119DDCu: goto label_119ddc;
            case 0x119E18u: goto label_119e18;
            case 0x119E28u: goto label_119e28;
            case 0x119E30u: goto label_119e30;
            case 0x119E38u: goto label_119e38;
            case 0x119E44u: goto label_119e44;
            case 0x119E54u: goto label_119e54;
            case 0x119E5Cu: goto label_119e5c;
            case 0x119E64u: goto label_119e64;
            case 0x119E6Cu: goto label_119e6c;
            case 0x119E70u: goto label_119e70;
            case 0x119EB0u: goto label_119eb0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x119EBCu;
    // 0x119ebc: 0x0  nop
    ctx->pc = 0x119ebcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
