#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00119EC0
// Address: 0x119ec0 - 0x11a270
void sub_00119EC0_0x119ec0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00119EC0_0x119ec0");
#endif

    switch (ctx->pc) {
        case 0x119f08u: goto label_119f08;
        case 0x119f20u: goto label_119f20;
        case 0x119f40u: goto label_119f40;
        case 0x119fa8u: goto label_119fa8;
        case 0x119fe8u: goto label_119fe8;
        case 0x11a008u: goto label_11a008;
        case 0x11a060u: goto label_11a060;
        case 0x11a080u: goto label_11a080;
        case 0x11a0a8u: goto label_11a0a8;
        case 0x11a0b8u: goto label_11a0b8;
        case 0x11a0c0u: goto label_11a0c0;
        case 0x11a0d4u: goto label_11a0d4;
        case 0x11a0e4u: goto label_11a0e4;
        case 0x11a0f4u: goto label_11a0f4;
        case 0x11a0fcu: goto label_11a0fc;
        case 0x11a15cu: goto label_11a15c;
        case 0x11a174u: goto label_11a174;
        case 0x11a190u: goto label_11a190;
        case 0x11a1dcu: goto label_11a1dc;
        case 0x11a1ecu: goto label_11a1ec;
        case 0x11a1f4u: goto label_11a1f4;
        case 0x11a208u: goto label_11a208;
        case 0x11a218u: goto label_11a218;
        case 0x11a228u: goto label_11a228;
        case 0x11a230u: goto label_11a230;
        case 0x11a260u: goto label_11a260;
        default: break;
    }

    ctx->pc = 0x119ec0u;

    // 0x119ec0: 0x27bdff30  addiu       $sp, $sp, -0xD0
    ctx->pc = 0x119ec0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967088));
    // 0x119ec4: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x119ec4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x119ec8: 0xffb600a0  sd          $s6, 0xA0($sp)
    ctx->pc = 0x119ec8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 22));
    // 0x119ecc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x119eccu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x119ed0: 0xffb20060  sd          $s2, 0x60($sp)
    ctx->pc = 0x119ed0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 18));
    // 0x119ed4: 0xc0b02d  daddu       $s6, $a2, $zero
    ctx->pc = 0x119ed4u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x119ed8: 0xffb10050  sd          $s1, 0x50($sp)
    ctx->pc = 0x119ed8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 17));
    // 0x119edc: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x119edcu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x119ee0: 0xffb700b0  sd          $s7, 0xB0($sp)
    ctx->pc = 0x119ee0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 23));
    // 0x119ee4: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x119ee4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x119ee8: 0xffb30070  sd          $s3, 0x70($sp)
    ctx->pc = 0x119ee8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 19));
    // 0x119eec: 0x2404000e  addiu       $a0, $zero, 0xE
    ctx->pc = 0x119eecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x119ef0: 0xffbf00c0  sd          $ra, 0xC0($sp)
    ctx->pc = 0x119ef0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 192), GPR_U64(ctx, 31));
    // 0x119ef4: 0x3c170026  lui         $s7, 0x26
    ctx->pc = 0x119ef4u;
    SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)38 << 16));
    // 0x119ef8: 0xffb50090  sd          $s5, 0x90($sp)
    ctx->pc = 0x119ef8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 21));
    // 0x119efc: 0x26f3ca40  addiu       $s3, $s7, -0x35C0
    ctx->pc = 0x119efcu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 23), 4294953536));
    // 0x119f00: 0xc04619c  jal         func_118670
    ctx->pc = 0x119F00u;
    SET_GPR_U32(ctx, 31, 0x119F08u);
    ctx->pc = 0x119F04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119F00u;
            // 0x119f04: 0xffb40080  sd          $s4, 0x80($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 20));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118670u;
    if (runtime->hasFunction(0x118670u)) {
        auto targetFn = runtime->lookupFunction(0x118670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119F08u; }
        if (ctx->pc != 0x119F08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118670_0x118670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119F08u; }
        if (ctx->pc != 0x119F08u) { return; }
    }
    ctx->pc = 0x119F08u;
label_119f08:
    // 0x119f08: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x119f08u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x119f0c: 0x8c439ddc  lw          $v1, -0x6224($v0)
    ctx->pc = 0x119f0cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294942172)));
    // 0x119f10: 0x54600004  bnel        $v1, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x119F10u;
    {
        const bool branch_taken_0x119f10 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x119f10) {
            ctx->pc = 0x119F14u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x119F10u;
            // 0x119f14: 0x92020000  lbu         $v0, 0x0($s0) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x119F24u;
            goto label_119f24;
        }
    }
    ctx->pc = 0x119F18u;
    // 0x119f18: 0xc0461e8  jal         func_1187A0
    ctx->pc = 0x119F18u;
    SET_GPR_U32(ctx, 31, 0x119F20u);
    ctx->pc = 0x1187A0u;
    if (runtime->hasFunction(0x1187A0u)) {
        auto targetFn = runtime->lookupFunction(0x1187A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119F20u; }
        if (ctx->pc != 0x119F20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001187A0_0x1187a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119F20u; }
        if (ctx->pc != 0x119F20u) { return; }
    }
    ctx->pc = 0x119F20u;
label_119f20:
    // 0x119f20: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x119f20u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
label_119f24:
    // 0x119f24: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x119f24u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x119f28: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x119f28u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x119f2c: 0x1060000f  beqz        $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x119F2Cu;
    {
        const bool branch_taken_0x119f2c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x119F30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119F2Cu;
            // 0x119f30: 0xa262000c  sb          $v0, 0xC($s3) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 19), 12), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119f2c) {
            ctx->pc = 0x119F6Cu;
            goto label_119f6c;
        }
    }
    ctx->pc = 0x119F34u;
    // 0x119f34: 0x2a270401  slti        $a3, $s1, 0x401
    ctx->pc = 0x119f34u;
    SET_GPR_U64(ctx, 7, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)1025) ? 1 : 0);
    // 0x119f38: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x119f38u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x119f3c: 0x0  nop
    ctx->pc = 0x119f3cu;
    // NOP
label_119f40:
    // 0x119f40: 0x28a20400  slti        $v0, $a1, 0x400
    ctx->pc = 0x119f40u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)1024) ? 1 : 0);
    // 0x119f44: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x119F44u;
    {
        const bool branch_taken_0x119f44 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x119F48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119F44u;
            // 0x119f48: 0x2051021  addu        $v0, $s0, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119f44) {
            ctx->pc = 0x119F70u;
            goto label_119f70;
        }
    }
    ctx->pc = 0x119F4Cu;
    // 0x119f4c: 0x2652021  addu        $a0, $s3, $a1
    ctx->pc = 0x119f4cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 5)));
    // 0x119f50: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x119f50u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x119f54: 0xa083000c  sb          $v1, 0xC($a0)
    ctx->pc = 0x119f54u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 12), (uint8_t)GPR_U32(ctx, 3));
    // 0x119f58: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x119f58u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x119f5c: 0x5460fff8  bnel        $v1, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x119F5Cu;
    {
        const bool branch_taken_0x119f5c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x119f5c) {
            ctx->pc = 0x119F60u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x119F5Cu;
            // 0x119f60: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x119F40u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_119f40;
        }
    }
    ctx->pc = 0x119F64u;
    // 0x119f64: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x119F64u;
    {
        const bool branch_taken_0x119f64 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x119F68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119F64u;
            // 0x119f68: 0x24020400  addiu       $v0, $zero, 0x400 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119f64) {
            ctx->pc = 0x119F74u;
            goto label_119f74;
        }
    }
    ctx->pc = 0x119F6Cu;
label_119f6c:
    // 0x119f6c: 0x2a270401  slti        $a3, $s1, 0x401
    ctx->pc = 0x119f6cu;
    SET_GPR_U64(ctx, 7, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)1025) ? 1 : 0);
label_119f70:
    // 0x119f70: 0x24020400  addiu       $v0, $zero, 0x400
    ctx->pc = 0x119f70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
label_119f74:
    // 0x119f74: 0x50a20001  beql        $a1, $v0, . + 4 + (0x1 << 2)
    ctx->pc = 0x119F74u;
    {
        const bool branch_taken_0x119f74 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        if (branch_taken_0x119f74) {
            ctx->pc = 0x119F78u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x119F74u;
            // 0x119f78: 0xa260040b  sb          $zero, 0x40B($s3) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 19), 1035), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x119F7Cu;
            goto label_119f7c;
        }
    }
    ctx->pc = 0x119F7Cu;
label_119f7c:
    // 0x119f7c: 0x56400003  bnel        $s2, $zero, . + 4 + (0x3 << 2)
    ctx->pc = 0x119F7Cu;
    {
        const bool branch_taken_0x119f7c = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        if (branch_taken_0x119f7c) {
            ctx->pc = 0x119F80u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x119F7Cu;
            // 0x119f80: 0x92420000  lbu         $v0, 0x0($s2) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x119F8Cu;
            goto label_119f8c;
        }
    }
    ctx->pc = 0x119F84u;
    // 0x119f84: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x119F84u;
    {
        const bool branch_taken_0x119f84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x119F88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119F84u;
            // 0x119f88: 0xa260040c  sb          $zero, 0x40C($s3) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 19), 1036), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119f84) {
            ctx->pc = 0x119FD8u;
            goto label_119fd8;
        }
    }
    ctx->pc = 0x119F8Cu;
label_119f8c:
    // 0x119f8c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x119f8cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x119f90: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x119f90u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x119f94: 0x1060000d  beqz        $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x119F94u;
    {
        const bool branch_taken_0x119f94 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x119F98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119F94u;
            // 0x119f98: 0xa262040c  sb          $v0, 0x40C($s3) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 19), 1036), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119f94) {
            ctx->pc = 0x119FCCu;
            goto label_119fcc;
        }
    }
    ctx->pc = 0x119F9Cu;
    // 0x119f9c: 0x2666040c  addiu       $a2, $s3, 0x40C
    ctx->pc = 0x119f9cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 19), 1036));
    // 0x119fa0: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x119fa0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x119fa4: 0x0  nop
    ctx->pc = 0x119fa4u;
    // NOP
label_119fa8:
    // 0x119fa8: 0x28a20400  slti        $v0, $a1, 0x400
    ctx->pc = 0x119fa8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)1024) ? 1 : 0);
    // 0x119fac: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x119FACu;
    {
        const bool branch_taken_0x119fac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x119FB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119FACu;
            // 0x119fb0: 0x2451021  addu        $v0, $s2, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119fac) {
            ctx->pc = 0x119FCCu;
            goto label_119fcc;
        }
    }
    ctx->pc = 0x119FB4u;
    // 0x119fb4: 0xc52021  addu        $a0, $a2, $a1
    ctx->pc = 0x119fb4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x119fb8: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x119fb8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x119fbc: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x119fbcu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x119fc0: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x119fc0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x119fc4: 0x5460fff8  bnel        $v1, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x119FC4u;
    {
        const bool branch_taken_0x119fc4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x119fc4) {
            ctx->pc = 0x119FC8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x119FC4u;
            // 0x119fc8: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x119FA8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_119fa8;
        }
    }
    ctx->pc = 0x119FCCu;
label_119fcc:
    // 0x119fcc: 0x24020400  addiu       $v0, $zero, 0x400
    ctx->pc = 0x119fccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
    // 0x119fd0: 0x50a20001  beql        $a1, $v0, . + 4 + (0x1 << 2)
    ctx->pc = 0x119FD0u;
    {
        const bool branch_taken_0x119fd0 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        if (branch_taken_0x119fd0) {
            ctx->pc = 0x119FD4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x119FD0u;
            // 0x119fd4: 0xa260080b  sb          $zero, 0x80B($s3) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 19), 2059), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x119FD8u;
            goto label_119fd8;
        }
    }
    ctx->pc = 0x119FD8u;
label_119fd8:
    // 0x119fd8: 0x14e00005  bnez        $a3, . + 4 + (0x5 << 2)
    ctx->pc = 0x119FD8u;
    {
        const bool branch_taken_0x119fd8 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        if (branch_taken_0x119fd8) {
            ctx->pc = 0x119FF0u;
            goto label_119ff0;
        }
    }
    ctx->pc = 0x119FE0u;
    // 0x119fe0: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x119FE0u;
    SET_GPR_U32(ctx, 31, 0x119FE8u);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119FE8u; }
        if (ctx->pc != 0x119FE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119FE8u; }
        if (ctx->pc != 0x119FE8u) { return; }
    }
    ctx->pc = 0x119FE8u;
label_119fe8:
    // 0x119fe8: 0x10000045  b           . + 4 + (0x45 << 2)
    ctx->pc = 0x119FE8u;
    {
        const bool branch_taken_0x119fe8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x119FECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119FE8u;
            // 0x119fec: 0x2402fff9  addiu       $v0, $zero, -0x7 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967289));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119fe8) {
            ctx->pc = 0x11A100u;
            goto label_11a100;
        }
    }
    ctx->pc = 0x119FF0u;
label_119ff0:
    // 0x119ff0: 0x1a20000f  blez        $s1, . + 4 + (0xF << 2)
    ctx->pc = 0x119FF0u;
    {
        const bool branch_taken_0x119ff0 = (GPR_S64(ctx, 17) <= 0);
        ctx->pc = 0x119FF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119FF0u;
            // 0x119ff4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119ff0) {
            ctx->pc = 0x11A030u;
            goto label_11a030;
        }
    }
    ctx->pc = 0x119FF8u;
    // 0x119ff8: 0x2666080c  addiu       $a2, $s3, 0x80C
    ctx->pc = 0x119ff8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 19), 2060));
    // 0x119ffc: 0x27b20030  addiu       $s2, $sp, 0x30
    ctx->pc = 0x119ffcu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x11a000: 0x3c150026  lui         $s5, 0x26
    ctx->pc = 0x11a000u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
    // 0x11a004: 0x3c140026  lui         $s4, 0x26
    ctx->pc = 0x11a004u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)38 << 16));
label_11a008:
    // 0x11a008: 0x2c51021  addu        $v0, $s6, $a1
    ctx->pc = 0x11a008u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 5)));
    // 0x11a00c: 0xc52021  addu        $a0, $a2, $a1
    ctx->pc = 0x11a00cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x11a010: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x11a010u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x11a014: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x11a014u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x11a018: 0xb1102a  slt         $v0, $a1, $s1
    ctx->pc = 0x11a018u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x11a01c: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x11a01cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x11a020: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x11A020u;
    {
        const bool branch_taken_0x11a020 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11a020) {
            ctx->pc = 0x11A008u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11a008;
        }
    }
    ctx->pc = 0x11A028u;
    // 0x11a028: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x11A028u;
    {
        const bool branch_taken_0x11a028 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11A02Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11A028u;
            // 0x11a02c: 0xae710c0c  sw          $s1, 0xC0C($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 3084), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11a028) {
            ctx->pc = 0x11A040u;
            goto label_11a040;
        }
    }
    ctx->pc = 0x11A030u;
label_11a030:
    // 0x11a030: 0x27b20030  addiu       $s2, $sp, 0x30
    ctx->pc = 0x11a030u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x11a034: 0x3c150026  lui         $s5, 0x26
    ctx->pc = 0x11a034u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
    // 0x11a038: 0x3c140026  lui         $s4, 0x26
    ctx->pc = 0x11a038u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)38 << 16));
    // 0x11a03c: 0xae710c0c  sw          $s1, 0xC0C($s3)
    ctx->pc = 0x11a03cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 3084), GPR_U32(ctx, 17));
label_11a040:
    // 0x11a040: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x11a040u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x11a044: 0xafa20014  sw          $v0, 0x14($sp)
    ctx->pc = 0x11a044u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x11a048: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x11a048u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x11a04c: 0xafa00018  sw          $zero, 0x18($sp)
    ctx->pc = 0x11a04cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
    // 0x11a050: 0x26f0ca40  addiu       $s0, $s7, -0x35C0
    ctx->pc = 0x11a050u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 23), 4294953536));
    // 0x11a054: 0xafa00024  sw          $zero, 0x24($sp)
    ctx->pc = 0x11a054u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 0));
    // 0x11a058: 0xc045188  jal         func_114620
    ctx->pc = 0x11A058u;
    SET_GPR_U32(ctx, 31, 0x11A060u);
    ctx->pc = 0x11A05Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A058u;
            // 0x11a05c: 0x2694d680  addiu       $s4, $s4, -0x2980 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 4294956672));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A060u; }
        if (ctx->pc != 0x11A060u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A060u; }
        if (ctx->pc != 0x11A060u) { return; }
    }
    ctx->pc = 0x11A060u;
label_11a060:
    // 0x11a060: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x11a060u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a064: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x11a064u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a068: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x11a068u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11a06c: 0xae720004  sw          $s2, 0x4($s3)
    ctx->pc = 0x11a06cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 18));
    // 0x11a070: 0xae620008  sw          $v0, 0x8($s3)
    ctx->pc = 0x11a070u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 8), GPR_U32(ctx, 2));
    // 0x11a074: 0x24050c10  addiu       $a1, $zero, 0xC10
    ctx->pc = 0x11a074u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3088));
    // 0x11a078: 0xc045bf4  jal         func_116FD0
    ctx->pc = 0x11A078u;
    SET_GPR_U32(ctx, 31, 0x11A080u);
    ctx->pc = 0x11A07Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A078u;
            // 0x11a07c: 0xae710000  sw          $s1, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116FD0u;
    if (runtime->hasFunction(0x116FD0u)) {
        auto targetFn = runtime->lookupFunction(0x116FD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A080u; }
        if (ctx->pc != 0x11A080u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116FD0_0x116fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A080u; }
        if (ctx->pc != 0x11A080u) { return; }
    }
    ctx->pc = 0x11A080u;
label_11a080:
    // 0x11a080: 0x26a4e140  addiu       $a0, $s5, -0x1EC0
    ctx->pc = 0x11a080u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), 4294959424));
    // 0x11a084: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x11a084u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a088: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11a088u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11a08c: 0x2405000e  addiu       $a1, $zero, 0xE
    ctx->pc = 0x11a08cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x11a090: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11a090u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a094: 0x24080c10  addiu       $t0, $zero, 0xC10
    ctx->pc = 0x11a094u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 3088));
    // 0x11a098: 0x280482d  daddu       $t1, $s4, $zero
    ctx->pc = 0x11a098u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a09c: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x11a09cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11a0a0: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11A0A0u;
    SET_GPR_U32(ctx, 31, 0x11A0A8u);
    ctx->pc = 0x11A0A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A0A0u;
            // 0x11a0a4: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A0A8u; }
        if (ctx->pc != 0x11A0A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A0A8u; }
        if (ctx->pc != 0x11A0A8u) { return; }
    }
    ctx->pc = 0x11A0A8u;
label_11a0a8:
    // 0x11a0a8: 0x4410007  bgez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x11A0A8u;
    {
        const bool branch_taken_0x11a0a8 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x11A0ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11A0A8u;
            // 0x11a0ac: 0x3c022000  lui         $v0, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11a0a8) {
            ctx->pc = 0x11A0C8u;
            goto label_11a0c8;
        }
    }
    ctx->pc = 0x11A0B0u;
    // 0x11a0b0: 0xc04518c  jal         func_114630
    ctx->pc = 0x11A0B0u;
    SET_GPR_U32(ctx, 31, 0x11A0B8u);
    ctx->pc = 0x11A0B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A0B0u;
            // 0x11a0b4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A0B8u; }
        if (ctx->pc != 0x11A0B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A0B8u; }
        if (ctx->pc != 0x11A0B8u) { return; }
    }
    ctx->pc = 0x11A0B8u;
label_11a0b8:
    // 0x11a0b8: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x11A0B8u;
    SET_GPR_U32(ctx, 31, 0x11A0C0u);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A0C0u; }
        if (ctx->pc != 0x11A0C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A0C0u; }
        if (ctx->pc != 0x11A0C0u) { return; }
    }
    ctx->pc = 0x11A0C0u;
label_11a0c0:
    // 0x11a0c0: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x11A0C0u;
    {
        const bool branch_taken_0x11a0c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11A0C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11A0C0u;
            // 0x11a0c4: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11a0c0) {
            ctx->pc = 0x11A100u;
            goto label_11a100;
        }
    }
    ctx->pc = 0x11A0C8u;
label_11a0c8:
    // 0x11a0c8: 0x2821025  or          $v0, $s4, $v0
    ctx->pc = 0x11a0c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) | GPR_U64(ctx, 2));
    // 0x11a0cc: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x11A0CCu;
    SET_GPR_U32(ctx, 31, 0x11A0D4u);
    ctx->pc = 0x11A0D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A0CCu;
            // 0x11a0d0: 0x8c500000  lw          $s0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A0D4u; }
        if (ctx->pc != 0x11A0D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A0D4u; }
        if (ctx->pc != 0x11A0D4u) { return; }
    }
    ctx->pc = 0x11A0D4u;
label_11a0d4:
    // 0x11a0d4: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x11A0D4u;
    {
        const bool branch_taken_0x11a0d4 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x11a0d4) {
            ctx->pc = 0x11A0ECu;
            goto label_11a0ec;
        }
    }
    ctx->pc = 0x11A0DCu;
    // 0x11a0dc: 0xc04518c  jal         func_114630
    ctx->pc = 0x11A0DCu;
    SET_GPR_U32(ctx, 31, 0x11A0E4u);
    ctx->pc = 0x11A0E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A0DCu;
            // 0x11a0e0: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A0E4u; }
        if (ctx->pc != 0x11A0E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A0E4u; }
        if (ctx->pc != 0x11A0E4u) { return; }
    }
    ctx->pc = 0x11A0E4u;
label_11a0e4:
    // 0x11a0e4: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x11A0E4u;
    {
        const bool branch_taken_0x11a0e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11A0E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11A0E4u;
            // 0x11a0e8: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11a0e4) {
            ctx->pc = 0x11A100u;
            goto label_11a100;
        }
    }
    ctx->pc = 0x11A0ECu;
label_11a0ec:
    // 0x11a0ec: 0xc045198  jal         func_114660
    ctx->pc = 0x11A0ECu;
    SET_GPR_U32(ctx, 31, 0x11A0F4u);
    ctx->pc = 0x11A0F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A0ECu;
            // 0x11a0f0: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A0F4u; }
        if (ctx->pc != 0x11A0F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A0F4u; }
        if (ctx->pc != 0x11A0F4u) { return; }
    }
    ctx->pc = 0x11A0F4u;
label_11a0f4:
    // 0x11a0f4: 0xc04518c  jal         func_114630
    ctx->pc = 0x11A0F4u;
    SET_GPR_U32(ctx, 31, 0x11A0FCu);
    ctx->pc = 0x11A0F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A0F4u;
            // 0x11a0f8: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A0FCu; }
        if (ctx->pc != 0x11A0FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A0FCu; }
        if (ctx->pc != 0x11A0FCu) { return; }
    }
    ctx->pc = 0x11A0FCu;
label_11a0fc:
    // 0x11a0fc: 0x8fa20030  lw          $v0, 0x30($sp)
    ctx->pc = 0x11a0fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_11a100:
    // 0x11a100: 0xdfbf00c0  ld          $ra, 0xC0($sp)
    ctx->pc = 0x11a100u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x11a104: 0xdfb700b0  ld          $s7, 0xB0($sp)
    ctx->pc = 0x11a104u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x11a108: 0xdfb600a0  ld          $s6, 0xA0($sp)
    ctx->pc = 0x11a108u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x11a10c: 0xdfb50090  ld          $s5, 0x90($sp)
    ctx->pc = 0x11a10cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x11a110: 0xdfb40080  ld          $s4, 0x80($sp)
    ctx->pc = 0x11a110u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x11a114: 0xdfb30070  ld          $s3, 0x70($sp)
    ctx->pc = 0x11a114u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x11a118: 0xdfb20060  ld          $s2, 0x60($sp)
    ctx->pc = 0x11a118u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x11a11c: 0xdfb10050  ld          $s1, 0x50($sp)
    ctx->pc = 0x11a11cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x11a120: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x11a120u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11a124: 0x3e00008  jr          $ra
    ctx->pc = 0x11A124u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11A128u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11A124u;
            // 0x11a128: 0x27bd00d0  addiu       $sp, $sp, 0xD0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 208));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x119F08u: goto label_119f08;
            case 0x119F20u: goto label_119f20;
            case 0x119F24u: goto label_119f24;
            case 0x119F40u: goto label_119f40;
            case 0x119F6Cu: goto label_119f6c;
            case 0x119F70u: goto label_119f70;
            case 0x119F74u: goto label_119f74;
            case 0x119F7Cu: goto label_119f7c;
            case 0x119F8Cu: goto label_119f8c;
            case 0x119FA8u: goto label_119fa8;
            case 0x119FCCu: goto label_119fcc;
            case 0x119FD8u: goto label_119fd8;
            case 0x119FE8u: goto label_119fe8;
            case 0x119FF0u: goto label_119ff0;
            case 0x11A008u: goto label_11a008;
            case 0x11A030u: goto label_11a030;
            case 0x11A040u: goto label_11a040;
            case 0x11A060u: goto label_11a060;
            case 0x11A080u: goto label_11a080;
            case 0x11A0A8u: goto label_11a0a8;
            case 0x11A0B8u: goto label_11a0b8;
            case 0x11A0C0u: goto label_11a0c0;
            case 0x11A0C8u: goto label_11a0c8;
            case 0x11A0D4u: goto label_11a0d4;
            case 0x11A0E4u: goto label_11a0e4;
            case 0x11A0ECu: goto label_11a0ec;
            case 0x11A0F4u: goto label_11a0f4;
            case 0x11A0FCu: goto label_11a0fc;
            case 0x11A100u: goto label_11a100;
            case 0x11A15Cu: goto label_11a15c;
            case 0x11A174u: goto label_11a174;
            case 0x11A178u: goto label_11a178;
            case 0x11A190u: goto label_11a190;
            case 0x11A1DCu: goto label_11a1dc;
            case 0x11A1ECu: goto label_11a1ec;
            case 0x11A1F4u: goto label_11a1f4;
            case 0x11A1FCu: goto label_11a1fc;
            case 0x11A208u: goto label_11a208;
            case 0x11A218u: goto label_11a218;
            case 0x11A220u: goto label_11a220;
            case 0x11A228u: goto label_11a228;
            case 0x11A230u: goto label_11a230;
            case 0x11A234u: goto label_11a234;
            case 0x11A260u: goto label_11a260;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11A12Cu;
    // 0x11a12c: 0x0  nop
    ctx->pc = 0x11a12cu;
    // NOP
    // 0x11a130: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x11a130u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x11a134: 0xffb10050  sd          $s1, 0x50($sp)
    ctx->pc = 0x11a134u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 17));
    // 0x11a138: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x11a138u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a13c: 0xffb30070  sd          $s3, 0x70($sp)
    ctx->pc = 0x11a13cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 19));
    // 0x11a140: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x11a140u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x11a144: 0x2404000f  addiu       $a0, $zero, 0xF
    ctx->pc = 0x11a144u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x11a148: 0xffbf0080  sd          $ra, 0x80($sp)
    ctx->pc = 0x11a148u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 31));
    // 0x11a14c: 0x3c130026  lui         $s3, 0x26
    ctx->pc = 0x11a14cu;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)38 << 16));
    // 0x11a150: 0xffb20060  sd          $s2, 0x60($sp)
    ctx->pc = 0x11a150u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 18));
    // 0x11a154: 0xc04619c  jal         func_118670
    ctx->pc = 0x11A154u;
    SET_GPR_U32(ctx, 31, 0x11A15Cu);
    ctx->pc = 0x11A158u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A154u;
            // 0x11a158: 0x2670ca40  addiu       $s0, $s3, -0x35C0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 19), 4294953536));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118670u;
    if (runtime->hasFunction(0x118670u)) {
        auto targetFn = runtime->lookupFunction(0x118670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A15Cu; }
        if (ctx->pc != 0x11A15Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118670_0x118670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A15Cu; }
        if (ctx->pc != 0x11A15Cu) { return; }
    }
    ctx->pc = 0x11A15Cu;
label_11a15c:
    // 0x11a15c: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x11a15cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x11a160: 0x8c629ddc  lw          $v0, -0x6224($v1)
    ctx->pc = 0x11a160u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294942172)));
    // 0x11a164: 0x54400004  bnel        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x11A164u;
    {
        const bool branch_taken_0x11a164 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11a164) {
            ctx->pc = 0x11A168u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11A164u;
            // 0x11a168: 0xae11000c  sw          $s1, 0xC($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11A178u;
            goto label_11a178;
        }
    }
    ctx->pc = 0x11A16Cu;
    // 0x11a16c: 0xc0461e8  jal         func_1187A0
    ctx->pc = 0x11A16Cu;
    SET_GPR_U32(ctx, 31, 0x11A174u);
    ctx->pc = 0x1187A0u;
    if (runtime->hasFunction(0x1187A0u)) {
        auto targetFn = runtime->lookupFunction(0x1187A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A174u; }
        if (ctx->pc != 0x11A174u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001187A0_0x1187a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A174u; }
        if (ctx->pc != 0x11A174u) { return; }
    }
    ctx->pc = 0x11A174u;
label_11a174:
    // 0x11a174: 0xae11000c  sw          $s1, 0xC($s0)
    ctx->pc = 0x11a174u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 17));
label_11a178:
    // 0x11a178: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x11a178u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x11a17c: 0xafa20014  sw          $v0, 0x14($sp)
    ctx->pc = 0x11a17cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x11a180: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x11a180u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x11a184: 0xafa00018  sw          $zero, 0x18($sp)
    ctx->pc = 0x11a184u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
    // 0x11a188: 0xc045188  jal         func_114620
    ctx->pc = 0x11A188u;
    SET_GPR_U32(ctx, 31, 0x11A190u);
    ctx->pc = 0x11A18Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A188u;
            // 0x11a18c: 0xafa00024  sw          $zero, 0x24($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A190u; }
        if (ctx->pc != 0x11A190u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A190u; }
        if (ctx->pc != 0x11A190u) { return; }
    }
    ctx->pc = 0x11A190u;
label_11a190:
    // 0x11a190: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x11a190u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a194: 0x27a30030  addiu       $v1, $sp, 0x30
    ctx->pc = 0x11a194u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x11a198: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x11a198u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x11a19c: 0xae71ca40  sw          $s1, -0x35C0($s3)
    ctx->pc = 0x11a19cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4294953536), GPR_U32(ctx, 17));
    // 0x11a1a0: 0x2452d680  addiu       $s2, $v0, -0x2980
    ctx->pc = 0x11a1a0u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 2), 4294956672));
    // 0x11a1a4: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x11a1a4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x11a1a8: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x11a1a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11a1ac: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x11a1acu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
    // 0x11a1b0: 0xae020008  sw          $v0, 0x8($s0)
    ctx->pc = 0x11a1b0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
    // 0x11a1b4: 0x2484e140  addiu       $a0, $a0, -0x1EC0
    ctx->pc = 0x11a1b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294959424));
    // 0x11a1b8: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x11a1b8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a1bc: 0x2405000f  addiu       $a1, $zero, 0xF
    ctx->pc = 0x11a1bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x11a1c0: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11a1c0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11a1c4: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11a1c4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a1c8: 0x24080010  addiu       $t0, $zero, 0x10
    ctx->pc = 0x11a1c8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x11a1cc: 0x240482d  daddu       $t1, $s2, $zero
    ctx->pc = 0x11a1ccu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a1d0: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x11a1d0u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11a1d4: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11A1D4u;
    SET_GPR_U32(ctx, 31, 0x11A1DCu);
    ctx->pc = 0x11A1D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A1D4u;
            // 0x11a1d8: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A1DCu; }
        if (ctx->pc != 0x11A1DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A1DCu; }
        if (ctx->pc != 0x11A1DCu) { return; }
    }
    ctx->pc = 0x11A1DCu;
label_11a1dc:
    // 0x11a1dc: 0x4410007  bgez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x11A1DCu;
    {
        const bool branch_taken_0x11a1dc = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x11A1E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11A1DCu;
            // 0x11a1e0: 0x3c022000  lui         $v0, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11a1dc) {
            ctx->pc = 0x11A1FCu;
            goto label_11a1fc;
        }
    }
    ctx->pc = 0x11A1E4u;
    // 0x11a1e4: 0xc04518c  jal         func_114630
    ctx->pc = 0x11A1E4u;
    SET_GPR_U32(ctx, 31, 0x11A1ECu);
    ctx->pc = 0x11A1E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A1E4u;
            // 0x11a1e8: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A1ECu; }
        if (ctx->pc != 0x11A1ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A1ECu; }
        if (ctx->pc != 0x11A1ECu) { return; }
    }
    ctx->pc = 0x11A1ECu;
label_11a1ec:
    // 0x11a1ec: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x11A1ECu;
    SET_GPR_U32(ctx, 31, 0x11A1F4u);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A1F4u; }
        if (ctx->pc != 0x11A1F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A1F4u; }
        if (ctx->pc != 0x11A1F4u) { return; }
    }
    ctx->pc = 0x11A1F4u;
label_11a1f4:
    // 0x11a1f4: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x11A1F4u;
    {
        const bool branch_taken_0x11a1f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11A1F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11A1F4u;
            // 0x11a1f8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11a1f4) {
            ctx->pc = 0x11A234u;
            goto label_11a234;
        }
    }
    ctx->pc = 0x11A1FCu;
label_11a1fc:
    // 0x11a1fc: 0x2421025  or          $v0, $s2, $v0
    ctx->pc = 0x11a1fcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x11a200: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x11A200u;
    SET_GPR_U32(ctx, 31, 0x11A208u);
    ctx->pc = 0x11A204u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A200u;
            // 0x11a204: 0x8c500000  lw          $s0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A208u; }
        if (ctx->pc != 0x11A208u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A208u; }
        if (ctx->pc != 0x11A208u) { return; }
    }
    ctx->pc = 0x11A208u;
label_11a208:
    // 0x11a208: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x11A208u;
    {
        const bool branch_taken_0x11a208 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x11a208) {
            ctx->pc = 0x11A220u;
            goto label_11a220;
        }
    }
    ctx->pc = 0x11A210u;
    // 0x11a210: 0xc04518c  jal         func_114630
    ctx->pc = 0x11A210u;
    SET_GPR_U32(ctx, 31, 0x11A218u);
    ctx->pc = 0x11A214u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A210u;
            // 0x11a214: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A218u; }
        if (ctx->pc != 0x11A218u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A218u; }
        if (ctx->pc != 0x11A218u) { return; }
    }
    ctx->pc = 0x11A218u;
label_11a218:
    // 0x11a218: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x11A218u;
    {
        const bool branch_taken_0x11a218 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11A21Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11A218u;
            // 0x11a21c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11a218) {
            ctx->pc = 0x11A234u;
            goto label_11a234;
        }
    }
    ctx->pc = 0x11A220u;
label_11a220:
    // 0x11a220: 0xc045198  jal         func_114660
    ctx->pc = 0x11A220u;
    SET_GPR_U32(ctx, 31, 0x11A228u);
    ctx->pc = 0x11A224u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A220u;
            // 0x11a224: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A228u; }
        if (ctx->pc != 0x11A228u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A228u; }
        if (ctx->pc != 0x11A228u) { return; }
    }
    ctx->pc = 0x11A228u;
label_11a228:
    // 0x11a228: 0xc04518c  jal         func_114630
    ctx->pc = 0x11A228u;
    SET_GPR_U32(ctx, 31, 0x11A230u);
    ctx->pc = 0x11A22Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A228u;
            // 0x11a22c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A230u; }
        if (ctx->pc != 0x11A230u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A230u; }
        if (ctx->pc != 0x11A230u) { return; }
    }
    ctx->pc = 0x11A230u;
label_11a230:
    // 0x11a230: 0x8fa20030  lw          $v0, 0x30($sp)
    ctx->pc = 0x11a230u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_11a234:
    // 0x11a234: 0xdfbf0080  ld          $ra, 0x80($sp)
    ctx->pc = 0x11a234u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x11a238: 0xdfb30070  ld          $s3, 0x70($sp)
    ctx->pc = 0x11a238u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x11a23c: 0xdfb20060  ld          $s2, 0x60($sp)
    ctx->pc = 0x11a23cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x11a240: 0xdfb10050  ld          $s1, 0x50($sp)
    ctx->pc = 0x11a240u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x11a244: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x11a244u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11a248: 0x3e00008  jr          $ra
    ctx->pc = 0x11A248u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11A24Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11A248u;
            // 0x11a24c: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x119F08u: goto label_119f08;
            case 0x119F20u: goto label_119f20;
            case 0x119F24u: goto label_119f24;
            case 0x119F40u: goto label_119f40;
            case 0x119F6Cu: goto label_119f6c;
            case 0x119F70u: goto label_119f70;
            case 0x119F74u: goto label_119f74;
            case 0x119F7Cu: goto label_119f7c;
            case 0x119F8Cu: goto label_119f8c;
            case 0x119FA8u: goto label_119fa8;
            case 0x119FCCu: goto label_119fcc;
            case 0x119FD8u: goto label_119fd8;
            case 0x119FE8u: goto label_119fe8;
            case 0x119FF0u: goto label_119ff0;
            case 0x11A008u: goto label_11a008;
            case 0x11A030u: goto label_11a030;
            case 0x11A040u: goto label_11a040;
            case 0x11A060u: goto label_11a060;
            case 0x11A080u: goto label_11a080;
            case 0x11A0A8u: goto label_11a0a8;
            case 0x11A0B8u: goto label_11a0b8;
            case 0x11A0C0u: goto label_11a0c0;
            case 0x11A0C8u: goto label_11a0c8;
            case 0x11A0D4u: goto label_11a0d4;
            case 0x11A0E4u: goto label_11a0e4;
            case 0x11A0ECu: goto label_11a0ec;
            case 0x11A0F4u: goto label_11a0f4;
            case 0x11A0FCu: goto label_11a0fc;
            case 0x11A100u: goto label_11a100;
            case 0x11A15Cu: goto label_11a15c;
            case 0x11A174u: goto label_11a174;
            case 0x11A178u: goto label_11a178;
            case 0x11A190u: goto label_11a190;
            case 0x11A1DCu: goto label_11a1dc;
            case 0x11A1ECu: goto label_11a1ec;
            case 0x11A1F4u: goto label_11a1f4;
            case 0x11A1FCu: goto label_11a1fc;
            case 0x11A208u: goto label_11a208;
            case 0x11A218u: goto label_11a218;
            case 0x11A220u: goto label_11a220;
            case 0x11A228u: goto label_11a228;
            case 0x11A230u: goto label_11a230;
            case 0x11A234u: goto label_11a234;
            case 0x11A260u: goto label_11a260;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11A250u;
    // 0x11a250: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x11a250u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x11a254: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x11a254u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x11a258: 0xc0466ca  jal         func_119B28
    ctx->pc = 0x11A258u;
    SET_GPR_U32(ctx, 31, 0x11A260u);
    ctx->pc = 0x11A25Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A258u;
            // 0x11a25c: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x119B28u;
    if (runtime->hasFunction(0x119B28u)) {
        auto targetFn = runtime->lookupFunction(0x119B28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A260u; }
        if (ctx->pc != 0x11A260u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00119B28_0x119b28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A260u; }
        if (ctx->pc != 0x11A260u) { return; }
    }
    ctx->pc = 0x11A260u;
label_11a260:
    // 0x11a260: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x11a260u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11a264: 0x3e00008  jr          $ra
    ctx->pc = 0x11A264u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11A268u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11A264u;
            // 0x11a268: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x119F08u: goto label_119f08;
            case 0x119F20u: goto label_119f20;
            case 0x119F24u: goto label_119f24;
            case 0x119F40u: goto label_119f40;
            case 0x119F6Cu: goto label_119f6c;
            case 0x119F70u: goto label_119f70;
            case 0x119F74u: goto label_119f74;
            case 0x119F7Cu: goto label_119f7c;
            case 0x119F8Cu: goto label_119f8c;
            case 0x119FA8u: goto label_119fa8;
            case 0x119FCCu: goto label_119fcc;
            case 0x119FD8u: goto label_119fd8;
            case 0x119FE8u: goto label_119fe8;
            case 0x119FF0u: goto label_119ff0;
            case 0x11A008u: goto label_11a008;
            case 0x11A030u: goto label_11a030;
            case 0x11A040u: goto label_11a040;
            case 0x11A060u: goto label_11a060;
            case 0x11A080u: goto label_11a080;
            case 0x11A0A8u: goto label_11a0a8;
            case 0x11A0B8u: goto label_11a0b8;
            case 0x11A0C0u: goto label_11a0c0;
            case 0x11A0C8u: goto label_11a0c8;
            case 0x11A0D4u: goto label_11a0d4;
            case 0x11A0E4u: goto label_11a0e4;
            case 0x11A0ECu: goto label_11a0ec;
            case 0x11A0F4u: goto label_11a0f4;
            case 0x11A0FCu: goto label_11a0fc;
            case 0x11A100u: goto label_11a100;
            case 0x11A15Cu: goto label_11a15c;
            case 0x11A174u: goto label_11a174;
            case 0x11A178u: goto label_11a178;
            case 0x11A190u: goto label_11a190;
            case 0x11A1DCu: goto label_11a1dc;
            case 0x11A1ECu: goto label_11a1ec;
            case 0x11A1F4u: goto label_11a1f4;
            case 0x11A1FCu: goto label_11a1fc;
            case 0x11A208u: goto label_11a208;
            case 0x11A218u: goto label_11a218;
            case 0x11A220u: goto label_11a220;
            case 0x11A228u: goto label_11a228;
            case 0x11A230u: goto label_11a230;
            case 0x11A234u: goto label_11a234;
            case 0x11A260u: goto label_11a260;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11A26Cu;
    // 0x11a26c: 0x0  nop
    ctx->pc = 0x11a26cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
