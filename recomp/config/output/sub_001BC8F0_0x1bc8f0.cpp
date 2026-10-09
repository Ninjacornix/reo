#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BC8F0
// Address: 0x1bc8f0 - 0x1bcca8
void sub_001BC8F0_0x1bc8f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BC8F0_0x1bc8f0");
#endif

    switch (ctx->pc) {
        case 0x1bc930u: goto label_1bc930;
        case 0x1bc95cu: goto label_1bc95c;
        case 0x1bc980u: goto label_1bc980;
        case 0x1bc9a0u: goto label_1bc9a0;
        case 0x1bc9b8u: goto label_1bc9b8;
        case 0x1bc9d0u: goto label_1bc9d0;
        case 0x1bc9d8u: goto label_1bc9d8;
        case 0x1bc9f4u: goto label_1bc9f4;
        case 0x1bca04u: goto label_1bca04;
        case 0x1bca4cu: goto label_1bca4c;
        case 0x1bca58u: goto label_1bca58;
        case 0x1bca60u: goto label_1bca60;
        case 0x1bca84u: goto label_1bca84;
        case 0x1bcabcu: goto label_1bcabc;
        case 0x1bcac8u: goto label_1bcac8;
        case 0x1bcad0u: goto label_1bcad0;
        case 0x1bcaf4u: goto label_1bcaf4;
        case 0x1bcb2cu: goto label_1bcb2c;
        case 0x1bcb38u: goto label_1bcb38;
        case 0x1bcb40u: goto label_1bcb40;
        case 0x1bcb64u: goto label_1bcb64;
        case 0x1bcb9cu: goto label_1bcb9c;
        case 0x1bcba8u: goto label_1bcba8;
        case 0x1bcbb0u: goto label_1bcbb0;
        case 0x1bcbd4u: goto label_1bcbd4;
        case 0x1bcc0cu: goto label_1bcc0c;
        case 0x1bcc18u: goto label_1bcc18;
        case 0x1bcc20u: goto label_1bcc20;
        case 0x1bcc50u: goto label_1bcc50;
        case 0x1bcc60u: goto label_1bcc60;
        case 0x1bcc68u: goto label_1bcc68;
        case 0x1bcc70u: goto label_1bcc70;
        case 0x1bcc78u: goto label_1bcc78;
        case 0x1bcc98u: goto label_1bcc98;
        default: break;
    }

    ctx->pc = 0x1bc8f0u;

    // 0x1bc8f0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1bc8f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1bc8f4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1bc8f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1bc8f8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1bc8f8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1bc8fc: 0x90860009  lbu         $a2, 0x9($a0)
    ctx->pc = 0x1bc8fcu;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 9)));
    // 0x1bc900: 0x2cc1000d  sltiu       $at, $a2, 0xD
    ctx->pc = 0x1bc900u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)13) ? 1 : 0);
    // 0x1bc904: 0x102000dc  beqz        $at, . + 4 + (0xDC << 2)
    ctx->pc = 0x1BC904u;
    {
        const bool branch_taken_0x1bc904 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BC908u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC904u;
            // 0x1bc908: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bc904) {
            ctx->pc = 0x1BCC78u;
            goto label_1bcc78;
        }
    }
    ctx->pc = 0x1BC90Cu;
    // 0x1bc90c: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1bc90cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1bc910: 0x61880  sll         $v1, $a2, 2
    ctx->pc = 0x1bc910u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x1bc914: 0x24a502c0  addiu       $a1, $a1, 0x2C0
    ctx->pc = 0x1bc914u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 704));
    // 0x1bc918: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x1bc918u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1bc91c: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1bc91cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1bc920: 0x600008  jr          $v1
    ctx->pc = 0x1BC920u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BC928u: goto label_1bc928;
            case 0x1BC954u: goto label_1bc954;
            case 0x1BC974u: goto label_1bc974;
            case 0x1BC98Cu: goto label_1bc98c;
            case 0x1BC998u: goto label_1bc998;
            case 0x1BC9C8u: goto label_1bc9c8;
            case 0x1BC9FCu: goto label_1bc9fc;
            case 0x1BCA1Cu: goto label_1bca1c;
            case 0x1BCA8Cu: goto label_1bca8c;
            case 0x1BCAFCu: goto label_1bcafc;
            case 0x1BCB6Cu: goto label_1bcb6c;
            case 0x1BCBDCu: goto label_1bcbdc;
            case 0x1BCC38u: goto label_1bcc38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BC928u;
label_1bc928:
    // 0x1bc928: 0xc06c280  jal         func_1B0A00
    ctx->pc = 0x1BC928u;
    SET_GPR_U32(ctx, 31, 0x1BC930u);
    ctx->pc = 0x1B0A00u;
    if (runtime->hasFunction(0x1B0A00u)) {
        auto targetFn = runtime->lookupFunction(0x1B0A00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC930u; }
        if (ctx->pc != 0x1BC930u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0A00_0x1b0a00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC930u; }
        if (ctx->pc != 0x1BC930u) { return; }
    }
    ctx->pc = 0x1BC930u;
label_1bc930:
    // 0x1bc930: 0x2263c  dsll32      $a0, $v0, 24
    ctx->pc = 0x1bc930u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (32 + 24));
    // 0x1bc934: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1bc934u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1bc938: 0x4263f  dsra32      $a0, $a0, 24
    ctx->pc = 0x1bc938u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 24));
    // 0x1bc93c: 0x108300ce  beq         $a0, $v1, . + 4 + (0xCE << 2)
    ctx->pc = 0x1BC93Cu;
    {
        const bool branch_taken_0x1bc93c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1bc93c) {
            ctx->pc = 0x1BCC78u;
            goto label_1bcc78;
        }
    }
    ctx->pc = 0x1BC944u;
    // 0x1bc944: 0x92030009  lbu         $v1, 0x9($s0)
    ctx->pc = 0x1bc944u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 9)));
    // 0x1bc948: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1bc948u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1bc94c: 0x100000ca  b           . + 4 + (0xCA << 2)
    ctx->pc = 0x1BC94Cu;
    {
        const bool branch_taken_0x1bc94c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BC950u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC94Cu;
            // 0x1bc950: 0xa2030009  sb          $v1, 0x9($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 9), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bc94c) {
            ctx->pc = 0x1BCC78u;
            goto label_1bcc78;
        }
    }
    ctx->pc = 0x1BC954u;
label_1bc954:
    // 0x1bc954: 0xc06f34c  jal         func_1BCD30
    ctx->pc = 0x1BC954u;
    SET_GPR_U32(ctx, 31, 0x1BC95Cu);
    ctx->pc = 0x1BCD30u;
    if (runtime->hasFunction(0x1BCD30u)) {
        auto targetFn = runtime->lookupFunction(0x1BCD30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC95Cu; }
        if (ctx->pc != 0x1BC95Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BCD30_0x1bcd30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC95Cu; }
        if (ctx->pc != 0x1BC95Cu) { return; }
    }
    ctx->pc = 0x1BC95Cu;
label_1bc95c:
    // 0x1bc95c: 0x144000c6  bnez        $v0, . + 4 + (0xC6 << 2)
    ctx->pc = 0x1BC95Cu;
    {
        const bool branch_taken_0x1bc95c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1bc95c) {
            ctx->pc = 0x1BCC78u;
            goto label_1bcc78;
        }
    }
    ctx->pc = 0x1BC964u;
    // 0x1bc964: 0x92030009  lbu         $v1, 0x9($s0)
    ctx->pc = 0x1bc964u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 9)));
    // 0x1bc968: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1bc968u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1bc96c: 0x100000c2  b           . + 4 + (0xC2 << 2)
    ctx->pc = 0x1BC96Cu;
    {
        const bool branch_taken_0x1bc96c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BC970u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC96Cu;
            // 0x1bc970: 0xa2030009  sb          $v1, 0x9($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 9), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bc96c) {
            ctx->pc = 0x1BCC78u;
            goto label_1bcc78;
        }
    }
    ctx->pc = 0x1BC974u;
label_1bc974:
    // 0x1bc974: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1bc974u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bc978: 0xc070980  jal         func_1C2600
    ctx->pc = 0x1BC978u;
    SET_GPR_U32(ctx, 31, 0x1BC980u);
    ctx->pc = 0x1BC97Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC978u;
            // 0x1bc97c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C2600u;
    if (runtime->hasFunction(0x1C2600u)) {
        auto targetFn = runtime->lookupFunction(0x1C2600u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC980u; }
        if (ctx->pc != 0x1BC980u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C2600_0x1c2600(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC980u; }
        if (ctx->pc != 0x1BC980u) { return; }
    }
    ctx->pc = 0x1BC980u;
label_1bc980:
    // 0x1bc980: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1bc980u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1bc984: 0x100000bc  b           . + 4 + (0xBC << 2)
    ctx->pc = 0x1BC984u;
    {
        const bool branch_taken_0x1bc984 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BC988u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC984u;
            // 0x1bc988: 0xa2030009  sb          $v1, 0x9($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 9), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bc984) {
            ctx->pc = 0x1BCC78u;
            goto label_1bcc78;
        }
    }
    ctx->pc = 0x1BC98Cu;
label_1bc98c:
    // 0x1bc98c: 0x24c30001  addiu       $v1, $a2, 0x1
    ctx->pc = 0x1bc98cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1bc990: 0x100000b9  b           . + 4 + (0xB9 << 2)
    ctx->pc = 0x1BC990u;
    {
        const bool branch_taken_0x1bc990 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BC994u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC990u;
            // 0x1bc994: 0xa2030009  sb          $v1, 0x9($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 9), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bc990) {
            ctx->pc = 0x1BCC78u;
            goto label_1bcc78;
        }
    }
    ctx->pc = 0x1BC998u;
label_1bc998:
    // 0x1bc998: 0xc070a50  jal         func_1C2940
    ctx->pc = 0x1BC998u;
    SET_GPR_U32(ctx, 31, 0x1BC9A0u);
    ctx->pc = 0x1C2940u;
    if (runtime->hasFunction(0x1C2940u)) {
        auto targetFn = runtime->lookupFunction(0x1C2940u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC9A0u; }
        if (ctx->pc != 0x1BC9A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C2940_0x1c2940(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC9A0u; }
        if (ctx->pc != 0x1BC9A0u) { return; }
    }
    ctx->pc = 0x1BC9A0u;
label_1bc9a0:
    // 0x1bc9a0: 0x144000b5  bnez        $v0, . + 4 + (0xB5 << 2)
    ctx->pc = 0x1BC9A0u;
    {
        const bool branch_taken_0x1bc9a0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1bc9a0) {
            ctx->pc = 0x1BCC78u;
            goto label_1bcc78;
        }
    }
    ctx->pc = 0x1BC9A8u;
    // 0x1bc9a8: 0x24020080  addiu       $v0, $zero, 0x80
    ctx->pc = 0x1bc9a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x1bc9ac: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x1bc9acu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1bc9b0: 0xc06f074  jal         func_1BC1D0
    ctx->pc = 0x1BC9B0u;
    SET_GPR_U32(ctx, 31, 0x1BC9B8u);
    ctx->pc = 0x1BC9B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC9B0u;
            // 0x1bc9b4: 0xa202000a  sb          $v0, 0xA($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 10), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BC1D0u;
    if (runtime->hasFunction(0x1BC1D0u)) {
        auto targetFn = runtime->lookupFunction(0x1BC1D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC9B8u; }
        if (ctx->pc != 0x1BC9B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BC1D0_0x1bc1d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC9B8u; }
        if (ctx->pc != 0x1BC9B8u) { return; }
    }
    ctx->pc = 0x1BC9B8u;
label_1bc9b8:
    // 0x1bc9b8: 0x92030009  lbu         $v1, 0x9($s0)
    ctx->pc = 0x1bc9b8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 9)));
    // 0x1bc9bc: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1bc9bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1bc9c0: 0x100000ad  b           . + 4 + (0xAD << 2)
    ctx->pc = 0x1BC9C0u;
    {
        const bool branch_taken_0x1bc9c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BC9C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC9C0u;
            // 0x1bc9c4: 0xa2030009  sb          $v1, 0x9($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 9), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bc9c0) {
            ctx->pc = 0x1BCC78u;
            goto label_1bcc78;
        }
    }
    ctx->pc = 0x1BC9C8u;
label_1bc9c8:
    // 0x1bc9c8: 0xc06f1e0  jal         func_1BC780
    ctx->pc = 0x1BC9C8u;
    SET_GPR_U32(ctx, 31, 0x1BC9D0u);
    ctx->pc = 0x1BC780u;
    if (runtime->hasFunction(0x1BC780u)) {
        auto targetFn = runtime->lookupFunction(0x1BC780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC9D0u; }
        if (ctx->pc != 0x1BC9D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BC780_0x1bc780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC9D0u; }
        if (ctx->pc != 0x1BC9D0u) { return; }
    }
    ctx->pc = 0x1BC9D0u;
label_1bc9d0:
    // 0x1bc9d0: 0xc06f220  jal         func_1BC880
    ctx->pc = 0x1BC9D0u;
    SET_GPR_U32(ctx, 31, 0x1BC9D8u);
    ctx->pc = 0x1BC880u;
    if (runtime->hasFunction(0x1BC880u)) {
        auto targetFn = runtime->lookupFunction(0x1BC880u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC9D8u; }
        if (ctx->pc != 0x1BC9D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BC880_0x1bc880(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC9D8u; }
        if (ctx->pc != 0x1BC9D8u) { return; }
    }
    ctx->pc = 0x1BC9D8u;
label_1bc9d8:
    // 0x1bc9d8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bc9d8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bc9dc: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x1bc9dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1bc9e0: 0xac2044d8  sw          $zero, 0x44D8($at)
    ctx->pc = 0x1bc9e0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17624), GPR_U32(ctx, 0));
    // 0x1bc9e4: 0x92020009  lbu         $v0, 0x9($s0)
    ctx->pc = 0x1bc9e4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 9)));
    // 0x1bc9e8: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1bc9e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1bc9ec: 0xc06f074  jal         func_1BC1D0
    ctx->pc = 0x1BC9ECu;
    SET_GPR_U32(ctx, 31, 0x1BC9F4u);
    ctx->pc = 0x1BC9F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC9ECu;
            // 0x1bc9f0: 0xa2020009  sb          $v0, 0x9($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 9), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BC1D0u;
    if (runtime->hasFunction(0x1BC1D0u)) {
        auto targetFn = runtime->lookupFunction(0x1BC1D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC9F4u; }
        if (ctx->pc != 0x1BC9F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BC1D0_0x1bc1d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC9F4u; }
        if (ctx->pc != 0x1BC9F4u) { return; }
    }
    ctx->pc = 0x1BC9F4u;
label_1bc9f4:
    // 0x1bc9f4: 0x100000a1  b           . + 4 + (0xA1 << 2)
    ctx->pc = 0x1BC9F4u;
    {
        const bool branch_taken_0x1bc9f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BC9F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC9F4u;
            // 0x1bc9f8: 0x92040009  lbu         $a0, 0x9($s0) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 9)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bc9f4) {
            ctx->pc = 0x1BCC7Cu;
            goto label_1bcc7c;
        }
    }
    ctx->pc = 0x1BC9FCu;
label_1bc9fc:
    // 0x1bc9fc: 0xc075328  jal         func_1D4CA0
    ctx->pc = 0x1BC9FCu;
    SET_GPR_U32(ctx, 31, 0x1BCA04u);
    ctx->pc = 0x1D4CA0u;
    if (runtime->hasFunction(0x1D4CA0u)) {
        auto targetFn = runtime->lookupFunction(0x1D4CA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCA04u; }
        if (ctx->pc != 0x1BCA04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D4CA0_0x1d4ca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCA04u; }
        if (ctx->pc != 0x1BCA04u) { return; }
    }
    ctx->pc = 0x1BCA04u;
label_1bca04:
    // 0x1bca04: 0x1440009c  bnez        $v0, . + 4 + (0x9C << 2)
    ctx->pc = 0x1BCA04u;
    {
        const bool branch_taken_0x1bca04 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1bca04) {
            ctx->pc = 0x1BCC78u;
            goto label_1bcc78;
        }
    }
    ctx->pc = 0x1BCA0Cu;
    // 0x1bca0c: 0x92030009  lbu         $v1, 0x9($s0)
    ctx->pc = 0x1bca0cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 9)));
    // 0x1bca10: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1bca10u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1bca14: 0x10000098  b           . + 4 + (0x98 << 2)
    ctx->pc = 0x1BCA14u;
    {
        const bool branch_taken_0x1bca14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BCA18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCA14u;
            // 0x1bca18: 0xa2030009  sb          $v1, 0x9($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 9), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bca14) {
            ctx->pc = 0x1BCC78u;
            goto label_1bcc78;
        }
    }
    ctx->pc = 0x1BCA1Cu;
label_1bca1c:
    // 0x1bca1c: 0x9202000a  lbu         $v0, 0xA($s0)
    ctx->pc = 0x1bca1cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 10)));
    // 0x1bca20: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1bca20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1bca24: 0xa202000a  sb          $v0, 0xA($s0)
    ctx->pc = 0x1bca24u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 10), (uint8_t)GPR_U32(ctx, 2));
    // 0x1bca28: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1bca28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1bca2c: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1BCA2Cu;
    {
        const bool branch_taken_0x1bca2c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bca2c) {
            ctx->pc = 0x1BCA68u;
            goto label_1bca68;
        }
    }
    ctx->pc = 0x1BCA34u;
    // 0x1bca34: 0x9203000a  lbu         $v1, 0xA($s0)
    ctx->pc = 0x1bca34u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 10)));
    // 0x1bca38: 0x24020014  addiu       $v0, $zero, 0x14
    ctx->pc = 0x1bca38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1bca3c: 0x14620004  bne         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1BCA3Cu;
    {
        const bool branch_taken_0x1bca3c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1BCA40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCA3Cu;
            // 0x1bca40: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bca3c) {
            ctx->pc = 0x1BCA50u;
            goto label_1bca50;
        }
    }
    ctx->pc = 0x1BCA44u;
    // 0x1bca44: 0xc06f074  jal         func_1BC1D0
    ctx->pc = 0x1BCA44u;
    SET_GPR_U32(ctx, 31, 0x1BCA4Cu);
    ctx->pc = 0x1BCA48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCA44u;
            // 0x1bca48: 0x24040007  addiu       $a0, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BC1D0u;
    if (runtime->hasFunction(0x1BC1D0u)) {
        auto targetFn = runtime->lookupFunction(0x1BC1D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCA4Cu; }
        if (ctx->pc != 0x1BCA4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BC1D0_0x1bc1d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCA4Cu; }
        if (ctx->pc != 0x1BCA4Cu) { return; }
    }
    ctx->pc = 0x1BCA4Cu;
label_1bca4c:
    // 0x1bca4c: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1bca4cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1bca50:
    // 0x1bca50: 0xc06f1ec  jal         func_1BC7B0
    ctx->pc = 0x1BCA50u;
    SET_GPR_U32(ctx, 31, 0x1BCA58u);
    ctx->pc = 0x1BC7B0u;
    if (runtime->hasFunction(0x1BC7B0u)) {
        auto targetFn = runtime->lookupFunction(0x1BC7B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCA58u; }
        if (ctx->pc != 0x1BCA58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BC7B0_0x1bc7b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCA58u; }
        if (ctx->pc != 0x1BCA58u) { return; }
    }
    ctx->pc = 0x1BCA58u;
label_1bca58:
    // 0x1bca58: 0xc06edb8  jal         func_1BB6E0
    ctx->pc = 0x1BCA58u;
    SET_GPR_U32(ctx, 31, 0x1BCA60u);
    ctx->pc = 0x1BB6E0u;
    if (runtime->hasFunction(0x1BB6E0u)) {
        auto targetFn = runtime->lookupFunction(0x1BB6E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCA60u; }
        if (ctx->pc != 0x1BCA60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BB6E0_0x1bb6e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCA60u; }
        if (ctx->pc != 0x1BCA60u) { return; }
    }
    ctx->pc = 0x1BCA60u;
label_1bca60:
    // 0x1bca60: 0x10000085  b           . + 4 + (0x85 << 2)
    ctx->pc = 0x1BCA60u;
    {
        const bool branch_taken_0x1bca60 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bca60) {
            ctx->pc = 0x1BCC78u;
            goto label_1bcc78;
        }
    }
    ctx->pc = 0x1BCA68u;
label_1bca68:
    // 0x1bca68: 0x92030009  lbu         $v1, 0x9($s0)
    ctx->pc = 0x1bca68u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 9)));
    // 0x1bca6c: 0x24020080  addiu       $v0, $zero, 0x80
    ctx->pc = 0x1bca6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x1bca70: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x1bca70u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1bca74: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1bca74u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1bca78: 0xa2030009  sb          $v1, 0x9($s0)
    ctx->pc = 0x1bca78u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 9), (uint8_t)GPR_U32(ctx, 3));
    // 0x1bca7c: 0xc06f074  jal         func_1BC1D0
    ctx->pc = 0x1BCA7Cu;
    SET_GPR_U32(ctx, 31, 0x1BCA84u);
    ctx->pc = 0x1BCA80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCA7Cu;
            // 0x1bca80: 0xa202000a  sb          $v0, 0xA($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 10), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BC1D0u;
    if (runtime->hasFunction(0x1BC1D0u)) {
        auto targetFn = runtime->lookupFunction(0x1BC1D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCA84u; }
        if (ctx->pc != 0x1BCA84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BC1D0_0x1bc1d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCA84u; }
        if (ctx->pc != 0x1BCA84u) { return; }
    }
    ctx->pc = 0x1BCA84u;
label_1bca84:
    // 0x1bca84: 0x1000007c  b           . + 4 + (0x7C << 2)
    ctx->pc = 0x1BCA84u;
    {
        const bool branch_taken_0x1bca84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bca84) {
            ctx->pc = 0x1BCC78u;
            goto label_1bcc78;
        }
    }
    ctx->pc = 0x1BCA8Cu;
label_1bca8c:
    // 0x1bca8c: 0x9202000a  lbu         $v0, 0xA($s0)
    ctx->pc = 0x1bca8cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 10)));
    // 0x1bca90: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1bca90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1bca94: 0xa202000a  sb          $v0, 0xA($s0)
    ctx->pc = 0x1bca94u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 10), (uint8_t)GPR_U32(ctx, 2));
    // 0x1bca98: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1bca98u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1bca9c: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1BCA9Cu;
    {
        const bool branch_taken_0x1bca9c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bca9c) {
            ctx->pc = 0x1BCAD8u;
            goto label_1bcad8;
        }
    }
    ctx->pc = 0x1BCAA4u;
    // 0x1bcaa4: 0x9203000a  lbu         $v1, 0xA($s0)
    ctx->pc = 0x1bcaa4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 10)));
    // 0x1bcaa8: 0x24020014  addiu       $v0, $zero, 0x14
    ctx->pc = 0x1bcaa8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1bcaac: 0x14620004  bne         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1BCAACu;
    {
        const bool branch_taken_0x1bcaac = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1BCAB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCAACu;
            // 0x1bcab0: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bcaac) {
            ctx->pc = 0x1BCAC0u;
            goto label_1bcac0;
        }
    }
    ctx->pc = 0x1BCAB4u;
    // 0x1bcab4: 0xc06f074  jal         func_1BC1D0
    ctx->pc = 0x1BCAB4u;
    SET_GPR_U32(ctx, 31, 0x1BCABCu);
    ctx->pc = 0x1BCAB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCAB4u;
            // 0x1bcab8: 0x24040007  addiu       $a0, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BC1D0u;
    if (runtime->hasFunction(0x1BC1D0u)) {
        auto targetFn = runtime->lookupFunction(0x1BC1D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCABCu; }
        if (ctx->pc != 0x1BCABCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BC1D0_0x1bc1d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCABCu; }
        if (ctx->pc != 0x1BCABCu) { return; }
    }
    ctx->pc = 0x1BCABCu;
label_1bcabc:
    // 0x1bcabc: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1bcabcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
label_1bcac0:
    // 0x1bcac0: 0xc06f1ec  jal         func_1BC7B0
    ctx->pc = 0x1BCAC0u;
    SET_GPR_U32(ctx, 31, 0x1BCAC8u);
    ctx->pc = 0x1BC7B0u;
    if (runtime->hasFunction(0x1BC7B0u)) {
        auto targetFn = runtime->lookupFunction(0x1BC7B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCAC8u; }
        if (ctx->pc != 0x1BCAC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BC7B0_0x1bc7b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCAC8u; }
        if (ctx->pc != 0x1BCAC8u) { return; }
    }
    ctx->pc = 0x1BCAC8u;
label_1bcac8:
    // 0x1bcac8: 0xc06edb8  jal         func_1BB6E0
    ctx->pc = 0x1BCAC8u;
    SET_GPR_U32(ctx, 31, 0x1BCAD0u);
    ctx->pc = 0x1BB6E0u;
    if (runtime->hasFunction(0x1BB6E0u)) {
        auto targetFn = runtime->lookupFunction(0x1BB6E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCAD0u; }
        if (ctx->pc != 0x1BCAD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BB6E0_0x1bb6e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCAD0u; }
        if (ctx->pc != 0x1BCAD0u) { return; }
    }
    ctx->pc = 0x1BCAD0u;
label_1bcad0:
    // 0x1bcad0: 0x10000069  b           . + 4 + (0x69 << 2)
    ctx->pc = 0x1BCAD0u;
    {
        const bool branch_taken_0x1bcad0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bcad0) {
            ctx->pc = 0x1BCC78u;
            goto label_1bcc78;
        }
    }
    ctx->pc = 0x1BCAD8u;
label_1bcad8:
    // 0x1bcad8: 0x92030009  lbu         $v1, 0x9($s0)
    ctx->pc = 0x1bcad8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 9)));
    // 0x1bcadc: 0x24020080  addiu       $v0, $zero, 0x80
    ctx->pc = 0x1bcadcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x1bcae0: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x1bcae0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1bcae4: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1bcae4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1bcae8: 0xa2030009  sb          $v1, 0x9($s0)
    ctx->pc = 0x1bcae8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 9), (uint8_t)GPR_U32(ctx, 3));
    // 0x1bcaec: 0xc06f074  jal         func_1BC1D0
    ctx->pc = 0x1BCAECu;
    SET_GPR_U32(ctx, 31, 0x1BCAF4u);
    ctx->pc = 0x1BCAF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCAECu;
            // 0x1bcaf0: 0xa202000a  sb          $v0, 0xA($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 10), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BC1D0u;
    if (runtime->hasFunction(0x1BC1D0u)) {
        auto targetFn = runtime->lookupFunction(0x1BC1D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCAF4u; }
        if (ctx->pc != 0x1BCAF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BC1D0_0x1bc1d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCAF4u; }
        if (ctx->pc != 0x1BCAF4u) { return; }
    }
    ctx->pc = 0x1BCAF4u;
label_1bcaf4:
    // 0x1bcaf4: 0x10000060  b           . + 4 + (0x60 << 2)
    ctx->pc = 0x1BCAF4u;
    {
        const bool branch_taken_0x1bcaf4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bcaf4) {
            ctx->pc = 0x1BCC78u;
            goto label_1bcc78;
        }
    }
    ctx->pc = 0x1BCAFCu;
label_1bcafc:
    // 0x1bcafc: 0x9202000a  lbu         $v0, 0xA($s0)
    ctx->pc = 0x1bcafcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 10)));
    // 0x1bcb00: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1bcb00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1bcb04: 0xa202000a  sb          $v0, 0xA($s0)
    ctx->pc = 0x1bcb04u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 10), (uint8_t)GPR_U32(ctx, 2));
    // 0x1bcb08: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1bcb08u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1bcb0c: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1BCB0Cu;
    {
        const bool branch_taken_0x1bcb0c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bcb0c) {
            ctx->pc = 0x1BCB48u;
            goto label_1bcb48;
        }
    }
    ctx->pc = 0x1BCB14u;
    // 0x1bcb14: 0x9203000a  lbu         $v1, 0xA($s0)
    ctx->pc = 0x1bcb14u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 10)));
    // 0x1bcb18: 0x24020014  addiu       $v0, $zero, 0x14
    ctx->pc = 0x1bcb18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1bcb1c: 0x14620004  bne         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1BCB1Cu;
    {
        const bool branch_taken_0x1bcb1c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1BCB20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCB1Cu;
            // 0x1bcb20: 0x24040004  addiu       $a0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bcb1c) {
            ctx->pc = 0x1BCB30u;
            goto label_1bcb30;
        }
    }
    ctx->pc = 0x1BCB24u;
    // 0x1bcb24: 0xc06f074  jal         func_1BC1D0
    ctx->pc = 0x1BCB24u;
    SET_GPR_U32(ctx, 31, 0x1BCB2Cu);
    ctx->pc = 0x1BCB28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCB24u;
            // 0x1bcb28: 0x24040007  addiu       $a0, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BC1D0u;
    if (runtime->hasFunction(0x1BC1D0u)) {
        auto targetFn = runtime->lookupFunction(0x1BC1D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCB2Cu; }
        if (ctx->pc != 0x1BCB2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BC1D0_0x1bc1d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCB2Cu; }
        if (ctx->pc != 0x1BCB2Cu) { return; }
    }
    ctx->pc = 0x1BCB2Cu;
label_1bcb2c:
    // 0x1bcb2c: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x1bcb2cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
label_1bcb30:
    // 0x1bcb30: 0xc06f1ec  jal         func_1BC7B0
    ctx->pc = 0x1BCB30u;
    SET_GPR_U32(ctx, 31, 0x1BCB38u);
    ctx->pc = 0x1BC7B0u;
    if (runtime->hasFunction(0x1BC7B0u)) {
        auto targetFn = runtime->lookupFunction(0x1BC7B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCB38u; }
        if (ctx->pc != 0x1BCB38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BC7B0_0x1bc7b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCB38u; }
        if (ctx->pc != 0x1BCB38u) { return; }
    }
    ctx->pc = 0x1BCB38u;
label_1bcb38:
    // 0x1bcb38: 0xc06edb8  jal         func_1BB6E0
    ctx->pc = 0x1BCB38u;
    SET_GPR_U32(ctx, 31, 0x1BCB40u);
    ctx->pc = 0x1BB6E0u;
    if (runtime->hasFunction(0x1BB6E0u)) {
        auto targetFn = runtime->lookupFunction(0x1BB6E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCB40u; }
        if (ctx->pc != 0x1BCB40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BB6E0_0x1bb6e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCB40u; }
        if (ctx->pc != 0x1BCB40u) { return; }
    }
    ctx->pc = 0x1BCB40u;
label_1bcb40:
    // 0x1bcb40: 0x1000004d  b           . + 4 + (0x4D << 2)
    ctx->pc = 0x1BCB40u;
    {
        const bool branch_taken_0x1bcb40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bcb40) {
            ctx->pc = 0x1BCC78u;
            goto label_1bcc78;
        }
    }
    ctx->pc = 0x1BCB48u;
label_1bcb48:
    // 0x1bcb48: 0x92030009  lbu         $v1, 0x9($s0)
    ctx->pc = 0x1bcb48u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 9)));
    // 0x1bcb4c: 0x24020080  addiu       $v0, $zero, 0x80
    ctx->pc = 0x1bcb4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x1bcb50: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x1bcb50u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1bcb54: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1bcb54u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1bcb58: 0xa2030009  sb          $v1, 0x9($s0)
    ctx->pc = 0x1bcb58u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 9), (uint8_t)GPR_U32(ctx, 3));
    // 0x1bcb5c: 0xc06f074  jal         func_1BC1D0
    ctx->pc = 0x1BCB5Cu;
    SET_GPR_U32(ctx, 31, 0x1BCB64u);
    ctx->pc = 0x1BCB60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCB5Cu;
            // 0x1bcb60: 0xa202000a  sb          $v0, 0xA($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 10), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BC1D0u;
    if (runtime->hasFunction(0x1BC1D0u)) {
        auto targetFn = runtime->lookupFunction(0x1BC1D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCB64u; }
        if (ctx->pc != 0x1BCB64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BC1D0_0x1bc1d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCB64u; }
        if (ctx->pc != 0x1BCB64u) { return; }
    }
    ctx->pc = 0x1BCB64u;
label_1bcb64:
    // 0x1bcb64: 0x10000044  b           . + 4 + (0x44 << 2)
    ctx->pc = 0x1BCB64u;
    {
        const bool branch_taken_0x1bcb64 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bcb64) {
            ctx->pc = 0x1BCC78u;
            goto label_1bcc78;
        }
    }
    ctx->pc = 0x1BCB6Cu;
label_1bcb6c:
    // 0x1bcb6c: 0x9202000a  lbu         $v0, 0xA($s0)
    ctx->pc = 0x1bcb6cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 10)));
    // 0x1bcb70: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1bcb70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1bcb74: 0xa202000a  sb          $v0, 0xA($s0)
    ctx->pc = 0x1bcb74u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 10), (uint8_t)GPR_U32(ctx, 2));
    // 0x1bcb78: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1bcb78u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1bcb7c: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1BCB7Cu;
    {
        const bool branch_taken_0x1bcb7c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bcb7c) {
            ctx->pc = 0x1BCBB8u;
            goto label_1bcbb8;
        }
    }
    ctx->pc = 0x1BCB84u;
    // 0x1bcb84: 0x9203000a  lbu         $v1, 0xA($s0)
    ctx->pc = 0x1bcb84u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 10)));
    // 0x1bcb88: 0x24020014  addiu       $v0, $zero, 0x14
    ctx->pc = 0x1bcb88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1bcb8c: 0x14620004  bne         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1BCB8Cu;
    {
        const bool branch_taken_0x1bcb8c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1BCB90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCB8Cu;
            // 0x1bcb90: 0x24040005  addiu       $a0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bcb8c) {
            ctx->pc = 0x1BCBA0u;
            goto label_1bcba0;
        }
    }
    ctx->pc = 0x1BCB94u;
    // 0x1bcb94: 0xc06f074  jal         func_1BC1D0
    ctx->pc = 0x1BCB94u;
    SET_GPR_U32(ctx, 31, 0x1BCB9Cu);
    ctx->pc = 0x1BCB98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCB94u;
            // 0x1bcb98: 0x24040007  addiu       $a0, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BC1D0u;
    if (runtime->hasFunction(0x1BC1D0u)) {
        auto targetFn = runtime->lookupFunction(0x1BC1D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCB9Cu; }
        if (ctx->pc != 0x1BCB9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BC1D0_0x1bc1d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCB9Cu; }
        if (ctx->pc != 0x1BCB9Cu) { return; }
    }
    ctx->pc = 0x1BCB9Cu;
label_1bcb9c:
    // 0x1bcb9c: 0x24040005  addiu       $a0, $zero, 0x5
    ctx->pc = 0x1bcb9cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
label_1bcba0:
    // 0x1bcba0: 0xc06f1ec  jal         func_1BC7B0
    ctx->pc = 0x1BCBA0u;
    SET_GPR_U32(ctx, 31, 0x1BCBA8u);
    ctx->pc = 0x1BC7B0u;
    if (runtime->hasFunction(0x1BC7B0u)) {
        auto targetFn = runtime->lookupFunction(0x1BC7B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCBA8u; }
        if (ctx->pc != 0x1BCBA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BC7B0_0x1bc7b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCBA8u; }
        if (ctx->pc != 0x1BCBA8u) { return; }
    }
    ctx->pc = 0x1BCBA8u;
label_1bcba8:
    // 0x1bcba8: 0xc06edb8  jal         func_1BB6E0
    ctx->pc = 0x1BCBA8u;
    SET_GPR_U32(ctx, 31, 0x1BCBB0u);
    ctx->pc = 0x1BB6E0u;
    if (runtime->hasFunction(0x1BB6E0u)) {
        auto targetFn = runtime->lookupFunction(0x1BB6E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCBB0u; }
        if (ctx->pc != 0x1BCBB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BB6E0_0x1bb6e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCBB0u; }
        if (ctx->pc != 0x1BCBB0u) { return; }
    }
    ctx->pc = 0x1BCBB0u;
label_1bcbb0:
    // 0x1bcbb0: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x1BCBB0u;
    {
        const bool branch_taken_0x1bcbb0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bcbb0) {
            ctx->pc = 0x1BCC78u;
            goto label_1bcc78;
        }
    }
    ctx->pc = 0x1BCBB8u;
label_1bcbb8:
    // 0x1bcbb8: 0x92030009  lbu         $v1, 0x9($s0)
    ctx->pc = 0x1bcbb8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 9)));
    // 0x1bcbbc: 0x24020080  addiu       $v0, $zero, 0x80
    ctx->pc = 0x1bcbbcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x1bcbc0: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x1bcbc0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1bcbc4: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1bcbc4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1bcbc8: 0xa2030009  sb          $v1, 0x9($s0)
    ctx->pc = 0x1bcbc8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 9), (uint8_t)GPR_U32(ctx, 3));
    // 0x1bcbcc: 0xc06f074  jal         func_1BC1D0
    ctx->pc = 0x1BCBCCu;
    SET_GPR_U32(ctx, 31, 0x1BCBD4u);
    ctx->pc = 0x1BCBD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCBCCu;
            // 0x1bcbd0: 0xa202000a  sb          $v0, 0xA($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 10), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BC1D0u;
    if (runtime->hasFunction(0x1BC1D0u)) {
        auto targetFn = runtime->lookupFunction(0x1BC1D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCBD4u; }
        if (ctx->pc != 0x1BCBD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BC1D0_0x1bc1d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCBD4u; }
        if (ctx->pc != 0x1BCBD4u) { return; }
    }
    ctx->pc = 0x1BCBD4u;
label_1bcbd4:
    // 0x1bcbd4: 0x10000028  b           . + 4 + (0x28 << 2)
    ctx->pc = 0x1BCBD4u;
    {
        const bool branch_taken_0x1bcbd4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bcbd4) {
            ctx->pc = 0x1BCC78u;
            goto label_1bcc78;
        }
    }
    ctx->pc = 0x1BCBDCu;
label_1bcbdc:
    // 0x1bcbdc: 0x9203000a  lbu         $v1, 0xA($s0)
    ctx->pc = 0x1bcbdcu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 10)));
    // 0x1bcbe0: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1bcbe0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1bcbe4: 0xa203000a  sb          $v1, 0xA($s0)
    ctx->pc = 0x1bcbe4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 10), (uint8_t)GPR_U32(ctx, 3));
    // 0x1bcbe8: 0x306300ff  andi        $v1, $v1, 0xFF
    ctx->pc = 0x1bcbe8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1bcbec: 0x1060000e  beqz        $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x1BCBECu;
    {
        const bool branch_taken_0x1bcbec = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bcbec) {
            ctx->pc = 0x1BCC28u;
            goto label_1bcc28;
        }
    }
    ctx->pc = 0x1BCBF4u;
    // 0x1bcbf4: 0x9203000a  lbu         $v1, 0xA($s0)
    ctx->pc = 0x1bcbf4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 10)));
    // 0x1bcbf8: 0x24020014  addiu       $v0, $zero, 0x14
    ctx->pc = 0x1bcbf8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1bcbfc: 0x14620004  bne         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1BCBFCu;
    {
        const bool branch_taken_0x1bcbfc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1BCC00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCBFCu;
            // 0x1bcc00: 0x24040003  addiu       $a0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bcbfc) {
            ctx->pc = 0x1BCC10u;
            goto label_1bcc10;
        }
    }
    ctx->pc = 0x1BCC04u;
    // 0x1bcc04: 0xc06f074  jal         func_1BC1D0
    ctx->pc = 0x1BCC04u;
    SET_GPR_U32(ctx, 31, 0x1BCC0Cu);
    ctx->pc = 0x1BCC08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCC04u;
            // 0x1bcc08: 0x24040007  addiu       $a0, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BC1D0u;
    if (runtime->hasFunction(0x1BC1D0u)) {
        auto targetFn = runtime->lookupFunction(0x1BC1D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCC0Cu; }
        if (ctx->pc != 0x1BCC0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BC1D0_0x1bc1d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCC0Cu; }
        if (ctx->pc != 0x1BCC0Cu) { return; }
    }
    ctx->pc = 0x1BCC0Cu;
label_1bcc0c:
    // 0x1bcc0c: 0x24040003  addiu       $a0, $zero, 0x3
    ctx->pc = 0x1bcc0cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
label_1bcc10:
    // 0x1bcc10: 0xc06f1ec  jal         func_1BC7B0
    ctx->pc = 0x1BCC10u;
    SET_GPR_U32(ctx, 31, 0x1BCC18u);
    ctx->pc = 0x1BC7B0u;
    if (runtime->hasFunction(0x1BC7B0u)) {
        auto targetFn = runtime->lookupFunction(0x1BC7B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCC18u; }
        if (ctx->pc != 0x1BCC18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BC7B0_0x1bc7b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCC18u; }
        if (ctx->pc != 0x1BCC18u) { return; }
    }
    ctx->pc = 0x1BCC18u;
label_1bcc18:
    // 0x1bcc18: 0xc06edb8  jal         func_1BB6E0
    ctx->pc = 0x1BCC18u;
    SET_GPR_U32(ctx, 31, 0x1BCC20u);
    ctx->pc = 0x1BB6E0u;
    if (runtime->hasFunction(0x1BB6E0u)) {
        auto targetFn = runtime->lookupFunction(0x1BB6E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCC20u; }
        if (ctx->pc != 0x1BCC20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BB6E0_0x1bb6e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCC20u; }
        if (ctx->pc != 0x1BCC20u) { return; }
    }
    ctx->pc = 0x1BCC20u;
label_1bcc20:
    // 0x1bcc20: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1BCC20u;
    {
        const bool branch_taken_0x1bcc20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bcc20) {
            ctx->pc = 0x1BCC78u;
            goto label_1bcc78;
        }
    }
    ctx->pc = 0x1BCC28u;
label_1bcc28:
    // 0x1bcc28: 0x92030009  lbu         $v1, 0x9($s0)
    ctx->pc = 0x1bcc28u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 9)));
    // 0x1bcc2c: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1bcc2cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1bcc30: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1BCC30u;
    {
        const bool branch_taken_0x1bcc30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BCC34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCC30u;
            // 0x1bcc34: 0xa2030009  sb          $v1, 0x9($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 9), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bcc30) {
            ctx->pc = 0x1BCC78u;
            goto label_1bcc78;
        }
    }
    ctx->pc = 0x1BCC38u;
label_1bcc38:
    // 0x1bcc38: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bcc38u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bcc3c: 0x8c2244d8  lw          $v0, 0x44D8($at)
    ctx->pc = 0x1bcc3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17624)));
    // 0x1bcc40: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1BCC40u;
    {
        const bool branch_taken_0x1bcc40 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1bcc40) {
            ctx->pc = 0x1BCC58u;
            goto label_1bcc58;
        }
    }
    ctx->pc = 0x1BCC48u;
    // 0x1bcc48: 0xc06f22c  jal         func_1BC8B0
    ctx->pc = 0x1BCC48u;
    SET_GPR_U32(ctx, 31, 0x1BCC50u);
    ctx->pc = 0x1BC8B0u;
    if (runtime->hasFunction(0x1BC8B0u)) {
        auto targetFn = runtime->lookupFunction(0x1BC8B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCC50u; }
        if (ctx->pc != 0x1BCC50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BC8B0_0x1bc8b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCC50u; }
        if (ctx->pc != 0x1BCC50u) { return; }
    }
    ctx->pc = 0x1BCC50u;
label_1bcc50:
    // 0x1bcc50: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1BCC50u;
    {
        const bool branch_taken_0x1bcc50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BCC54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCC50u;
            // 0x1bcc54: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bcc50) {
            ctx->pc = 0x1BCC9Cu;
            goto label_1bcc9c;
        }
    }
    ctx->pc = 0x1BCC58u;
label_1bcc58:
    // 0x1bcc58: 0xc06eb08  jal         func_1BAC20
    ctx->pc = 0x1BCC58u;
    SET_GPR_U32(ctx, 31, 0x1BCC60u);
    ctx->pc = 0x1BAC20u;
    if (runtime->hasFunction(0x1BAC20u)) {
        auto targetFn = runtime->lookupFunction(0x1BAC20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCC60u; }
        if (ctx->pc != 0x1BCC60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BAC20_0x1bac20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCC60u; }
        if (ctx->pc != 0x1BCC60u) { return; }
    }
    ctx->pc = 0x1BCC60u;
label_1bcc60:
    // 0x1bcc60: 0xc06f0ac  jal         func_1BC2B0
    ctx->pc = 0x1BCC60u;
    SET_GPR_U32(ctx, 31, 0x1BCC68u);
    ctx->pc = 0x1BC2B0u;
    if (runtime->hasFunction(0x1BC2B0u)) {
        auto targetFn = runtime->lookupFunction(0x1BC2B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCC68u; }
        if (ctx->pc != 0x1BCC68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BC2B0_0x1bc2b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCC68u; }
        if (ctx->pc != 0x1BCC68u) { return; }
    }
    ctx->pc = 0x1BCC68u;
label_1bcc68:
    // 0x1bcc68: 0xc06e05c  jal         func_1B8170
    ctx->pc = 0x1BCC68u;
    SET_GPR_U32(ctx, 31, 0x1BCC70u);
    ctx->pc = 0x1B8170u;
    if (runtime->hasFunction(0x1B8170u)) {
        auto targetFn = runtime->lookupFunction(0x1B8170u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCC70u; }
        if (ctx->pc != 0x1BCC70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B8170_0x1b8170(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCC70u; }
        if (ctx->pc != 0x1BCC70u) { return; }
    }
    ctx->pc = 0x1BCC70u;
label_1bcc70:
    // 0x1bcc70: 0xc06dfec  jal         func_1B7FB0
    ctx->pc = 0x1BCC70u;
    SET_GPR_U32(ctx, 31, 0x1BCC78u);
    ctx->pc = 0x1BCC74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCC70u;
            // 0x1bcc74: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B7FB0u;
    if (runtime->hasFunction(0x1B7FB0u)) {
        auto targetFn = runtime->lookupFunction(0x1B7FB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCC78u; }
        if (ctx->pc != 0x1BCC78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B7FB0_0x1b7fb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCC78u; }
        if (ctx->pc != 0x1BCC78u) { return; }
    }
    ctx->pc = 0x1BCC78u;
label_1bcc78:
    // 0x1bcc78: 0x92040009  lbu         $a0, 0x9($s0)
    ctx->pc = 0x1bcc78u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 9)));
label_1bcc7c:
    // 0x1bcc7c: 0x28830007  slti        $v1, $a0, 0x7
    ctx->pc = 0x1bcc7cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)7) ? 1 : 0);
    // 0x1bcc80: 0x14600005  bnez        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1BCC80u;
    {
        const bool branch_taken_0x1bcc80 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BCC84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCC80u;
            // 0x1bcc84: 0x2881000c  slti        $at, $a0, 0xC (Delay Slot)
        SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)12) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bcc80) {
            ctx->pc = 0x1BCC98u;
            goto label_1bcc98;
        }
    }
    ctx->pc = 0x1BCC88u;
    // 0x1bcc88: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BCC88u;
    {
        const bool branch_taken_0x1bcc88 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bcc88) {
            ctx->pc = 0x1BCC98u;
            goto label_1bcc98;
        }
    }
    ctx->pc = 0x1BCC90u;
    // 0x1bcc90: 0xc06f22c  jal         func_1BC8B0
    ctx->pc = 0x1BCC90u;
    SET_GPR_U32(ctx, 31, 0x1BCC98u);
    ctx->pc = 0x1BC8B0u;
    if (runtime->hasFunction(0x1BC8B0u)) {
        auto targetFn = runtime->lookupFunction(0x1BC8B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCC98u; }
        if (ctx->pc != 0x1BCC98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BC8B0_0x1bc8b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCC98u; }
        if (ctx->pc != 0x1BCC98u) { return; }
    }
    ctx->pc = 0x1BCC98u;
label_1bcc98:
    // 0x1bcc98: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1bcc98u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1bcc9c:
    // 0x1bcc9c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1bcc9cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bcca0: 0x3e00008  jr          $ra
    ctx->pc = 0x1BCCA0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BCCA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCCA0u;
            // 0x1bcca4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BC928u: goto label_1bc928;
            case 0x1BC930u: goto label_1bc930;
            case 0x1BC954u: goto label_1bc954;
            case 0x1BC95Cu: goto label_1bc95c;
            case 0x1BC974u: goto label_1bc974;
            case 0x1BC980u: goto label_1bc980;
            case 0x1BC98Cu: goto label_1bc98c;
            case 0x1BC998u: goto label_1bc998;
            case 0x1BC9A0u: goto label_1bc9a0;
            case 0x1BC9B8u: goto label_1bc9b8;
            case 0x1BC9C8u: goto label_1bc9c8;
            case 0x1BC9D0u: goto label_1bc9d0;
            case 0x1BC9D8u: goto label_1bc9d8;
            case 0x1BC9F4u: goto label_1bc9f4;
            case 0x1BC9FCu: goto label_1bc9fc;
            case 0x1BCA04u: goto label_1bca04;
            case 0x1BCA1Cu: goto label_1bca1c;
            case 0x1BCA4Cu: goto label_1bca4c;
            case 0x1BCA50u: goto label_1bca50;
            case 0x1BCA58u: goto label_1bca58;
            case 0x1BCA60u: goto label_1bca60;
            case 0x1BCA68u: goto label_1bca68;
            case 0x1BCA84u: goto label_1bca84;
            case 0x1BCA8Cu: goto label_1bca8c;
            case 0x1BCABCu: goto label_1bcabc;
            case 0x1BCAC0u: goto label_1bcac0;
            case 0x1BCAC8u: goto label_1bcac8;
            case 0x1BCAD0u: goto label_1bcad0;
            case 0x1BCAD8u: goto label_1bcad8;
            case 0x1BCAF4u: goto label_1bcaf4;
            case 0x1BCAFCu: goto label_1bcafc;
            case 0x1BCB2Cu: goto label_1bcb2c;
            case 0x1BCB30u: goto label_1bcb30;
            case 0x1BCB38u: goto label_1bcb38;
            case 0x1BCB40u: goto label_1bcb40;
            case 0x1BCB48u: goto label_1bcb48;
            case 0x1BCB64u: goto label_1bcb64;
            case 0x1BCB6Cu: goto label_1bcb6c;
            case 0x1BCB9Cu: goto label_1bcb9c;
            case 0x1BCBA0u: goto label_1bcba0;
            case 0x1BCBA8u: goto label_1bcba8;
            case 0x1BCBB0u: goto label_1bcbb0;
            case 0x1BCBB8u: goto label_1bcbb8;
            case 0x1BCBD4u: goto label_1bcbd4;
            case 0x1BCBDCu: goto label_1bcbdc;
            case 0x1BCC0Cu: goto label_1bcc0c;
            case 0x1BCC10u: goto label_1bcc10;
            case 0x1BCC18u: goto label_1bcc18;
            case 0x1BCC20u: goto label_1bcc20;
            case 0x1BCC28u: goto label_1bcc28;
            case 0x1BCC38u: goto label_1bcc38;
            case 0x1BCC50u: goto label_1bcc50;
            case 0x1BCC58u: goto label_1bcc58;
            case 0x1BCC60u: goto label_1bcc60;
            case 0x1BCC68u: goto label_1bcc68;
            case 0x1BCC70u: goto label_1bcc70;
            case 0x1BCC78u: goto label_1bcc78;
            case 0x1BCC7Cu: goto label_1bcc7c;
            case 0x1BCC98u: goto label_1bcc98;
            case 0x1BCC9Cu: goto label_1bcc9c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BCCA8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
