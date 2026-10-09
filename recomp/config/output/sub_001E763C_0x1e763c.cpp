#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E763C
// Address: 0x1e763c - 0x1e77f4
void sub_001E763C_0x1e763c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E763C_0x1e763c");
#endif

    switch (ctx->pc) {
        case 0x1e769cu: goto label_1e769c;
        case 0x1e7774u: goto label_1e7774;
        case 0x1e7784u: goto label_1e7784;
        case 0x1e779cu: goto label_1e779c;
        case 0x1e77d8u: goto label_1e77d8;
        default: break;
    }

    ctx->pc = 0x1e763cu;

    // 0x1e763c: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1e763cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1e7640: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1e7640u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1e7644: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1e7644u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1e7648: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e7648u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e764c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e764cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e7650: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e7650u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e7654: 0xc0102d  daddu       $v0, $a2, $zero
    ctx->pc = 0x1e7654u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7658: 0xe0182d  daddu       $v1, $a3, $zero
    ctx->pc = 0x1e7658u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e765c: 0x100202d  daddu       $a0, $t0, $zero
    ctx->pc = 0x1e765cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7660: 0x120282d  daddu       $a1, $t1, $zero
    ctx->pc = 0x1e7660u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7664: 0xa7c20008  sh          $v0, 0x8($fp)
    ctx->pc = 0x1e7664u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 8), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e7668: 0xa7c3000a  sh          $v1, 0xA($fp)
    ctx->pc = 0x1e7668u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 10), (uint16_t)GPR_U32(ctx, 3));
    // 0x1e766c: 0xa3c4000c  sb          $a0, 0xC($fp)
    ctx->pc = 0x1e766cu;
    WRITE8(ADD32(GPR_U32(ctx, 30), 12), (uint8_t)GPR_U32(ctx, 4));
    // 0x1e7670: 0xa3c5000d  sb          $a1, 0xD($fp)
    ctx->pc = 0x1e7670u;
    WRITE8(ADD32(GPR_U32(ctx, 30), 13), (uint8_t)GPR_U32(ctx, 5));
    // 0x1e7674: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e7674u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e7678: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e7678u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e767c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1E767Cu;
    {
        const bool branch_taken_0x1e767c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e767c) {
            ctx->pc = 0x1E7690u;
            goto label_1e7690;
        }
    }
    ctx->pc = 0x1E7684u;
    // 0x1e7684: 0x24020027  addiu       $v0, $zero, 0x27
    ctx->pc = 0x1e7684u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 39));
    // 0x1e7688: 0x10000054  b           . + 4 + (0x54 << 2)
    ctx->pc = 0x1E7688u;
    {
        const bool branch_taken_0x1e7688 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7688) {
            ctx->pc = 0x1E77DCu;
            goto label_1e77dc;
        }
    }
    ctx->pc = 0x1E7690u;
label_1e7690:
    // 0x1e7690: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1e7690u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e7694: 0xc07c6b6  jal         func_1F1AD8
    ctx->pc = 0x1E7694u;
    SET_GPR_U32(ctx, 31, 0x1E769Cu);
    ctx->pc = 0x1F1AD8u;
    if (runtime->hasFunction(0x1F1AD8u)) {
        auto targetFn = runtime->lookupFunction(0x1F1AD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E769Cu; }
        if (ctx->pc != 0x1E769Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1AD8_0x1f1ad8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E769Cu; }
        if (ctx->pc != 0x1E769Cu) { return; }
    }
    ctx->pc = 0x1E769Cu;
label_1e769c:
    // 0x1e769c: 0x97c3000a  lhu         $v1, 0xA($fp)
    ctx->pc = 0x1e769cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 10)));
    // 0x1e76a0: 0x24630010  addiu       $v1, $v1, 0x10
    ctx->pc = 0x1e76a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 16));
    // 0x1e76a4: 0x10430004  beq         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1E76A4u;
    {
        const bool branch_taken_0x1e76a4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1e76a4) {
            ctx->pc = 0x1E76B8u;
            goto label_1e76b8;
        }
    }
    ctx->pc = 0x1E76ACu;
    // 0x1e76ac: 0x24020027  addiu       $v0, $zero, 0x27
    ctx->pc = 0x1e76acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 39));
    // 0x1e76b0: 0x1000004a  b           . + 4 + (0x4A << 2)
    ctx->pc = 0x1E76B0u;
    {
        const bool branch_taken_0x1e76b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e76b0) {
            ctx->pc = 0x1E77DCu;
            goto label_1e77dc;
        }
    }
    ctx->pc = 0x1E76B8u;
label_1e76b8:
    // 0x1e76b8: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e76b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e76bc: 0x2443002c  addiu       $v1, $v0, 0x2C
    ctx->pc = 0x1e76bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 44));
    // 0x1e76c0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e76c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e76c4: 0x8c420044  lw          $v0, 0x44($v0)
    ctx->pc = 0x1e76c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 68)));
    // 0x1e76c8: 0xac620004  sw          $v0, 0x4($v1)
    ctx->pc = 0x1e76c8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
    // 0x1e76cc: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e76ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e76d0: 0x2443002c  addiu       $v1, $v0, 0x2C
    ctx->pc = 0x1e76d0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 44));
    // 0x1e76d4: 0x97c20008  lhu         $v0, 0x8($fp)
    ctx->pc = 0x1e76d4u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e76d8: 0xa4620000  sh          $v0, 0x0($v1)
    ctx->pc = 0x1e76d8u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e76dc: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e76dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e76e0: 0x2443002c  addiu       $v1, $v0, 0x2C
    ctx->pc = 0x1e76e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 44));
    // 0x1e76e4: 0x93c2000d  lbu         $v0, 0xD($fp)
    ctx->pc = 0x1e76e4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 13)));
    // 0x1e76e8: 0xa4620002  sh          $v0, 0x2($v1)
    ctx->pc = 0x1e76e8u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e76ec: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e76ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e76f0: 0x2443002c  addiu       $v1, $v0, 0x2C
    ctx->pc = 0x1e76f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 44));
    // 0x1e76f4: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e76f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e76f8: 0x2442002c  addiu       $v0, $v0, 0x2C
    ctx->pc = 0x1e76f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 44));
    // 0x1e76fc: 0x94420002  lhu         $v0, 0x2($v0)
    ctx->pc = 0x1e76fcu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x1e7700: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e7700u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e7704: 0xa4620002  sh          $v0, 0x2($v1)
    ctx->pc = 0x1e7704u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e7708: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e7708u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e770c: 0x2444002c  addiu       $a0, $v0, 0x2C
    ctx->pc = 0x1e770cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 44));
    // 0x1e7710: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e7710u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e7714: 0x2442002c  addiu       $v0, $v0, 0x2C
    ctx->pc = 0x1e7714u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 44));
    // 0x1e7718: 0x93c3000c  lbu         $v1, 0xC($fp)
    ctx->pc = 0x1e7718u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e771c: 0x94420002  lhu         $v0, 0x2($v0)
    ctx->pc = 0x1e771cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x1e7720: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1e7720u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1e7724: 0xa4820002  sh          $v0, 0x2($a0)
    ctx->pc = 0x1e7724u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e7728: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e7728u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e772c: 0x2444002c  addiu       $a0, $v0, 0x2C
    ctx->pc = 0x1e772cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 44));
    // 0x1e7730: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e7730u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e7734: 0x2443002c  addiu       $v1, $v0, 0x2C
    ctx->pc = 0x1e7734u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 44));
    // 0x1e7738: 0x97c2000a  lhu         $v0, 0xA($fp)
    ctx->pc = 0x1e7738u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 10)));
    // 0x1e773c: 0x24420010  addiu       $v0, $v0, 0x10
    ctx->pc = 0x1e773cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 16));
    // 0x1e7740: 0x304203ff  andi        $v0, $v0, 0x3FF
    ctx->pc = 0x1e7740u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1023);
    // 0x1e7744: 0x94630000  lhu         $v1, 0x0($v1)
    ctx->pc = 0x1e7744u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1e7748: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1e7748u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e774c: 0xa4820000  sh          $v0, 0x0($a0)
    ctx->pc = 0x1e774cu;
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e7750: 0x97c20008  lhu         $v0, 0x8($fp)
    ctx->pc = 0x1e7750u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e7754: 0x30428000  andi        $v0, $v0, 0x8000
    ctx->pc = 0x1e7754u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)32768);
    // 0x1e7758: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e7758u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e775c: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E775Cu;
    {
        const bool branch_taken_0x1e775c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e775c) {
            ctx->pc = 0x1E778Cu;
            goto label_1e778c;
        }
    }
    ctx->pc = 0x1E7764u;
    // 0x1e7764: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1e7764u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e7768: 0x24050011  addiu       $a1, $zero, 0x11
    ctx->pc = 0x1e7768u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
    // 0x1e776c: 0xc07ccd5  jal         func_1F3354
    ctx->pc = 0x1E776Cu;
    SET_GPR_U32(ctx, 31, 0x1E7774u);
    ctx->pc = 0x1F3354u;
    if (runtime->hasFunction(0x1F3354u)) {
        auto targetFn = runtime->lookupFunction(0x1F3354u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7774u; }
        if (ctx->pc != 0x1E7774u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F3354_0x1f3354(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7774u; }
        if (ctx->pc != 0x1E7774u) { return; }
    }
    ctx->pc = 0x1E7774u;
label_1e7774:
    // 0x1e7774: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1e7774u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e7778: 0x34058001  ori         $a1, $zero, 0x8001
    ctx->pc = 0x1e7778u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32769);
    // 0x1e777c: 0xc07c680  jal         func_1F1A00
    ctx->pc = 0x1E777Cu;
    SET_GPR_U32(ctx, 31, 0x1E7784u);
    ctx->pc = 0x1F1A00u;
    if (runtime->hasFunction(0x1F1A00u)) {
        auto targetFn = runtime->lookupFunction(0x1F1A00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7784u; }
        if (ctx->pc != 0x1E7784u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1A00_0x1f1a00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7784u; }
        if (ctx->pc != 0x1E7784u) { return; }
    }
    ctx->pc = 0x1E7784u;
label_1e7784:
    // 0x1e7784: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1E7784u;
    {
        const bool branch_taken_0x1e7784 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7784) {
            ctx->pc = 0x1E77BCu;
            goto label_1e77bc;
        }
    }
    ctx->pc = 0x1E778Cu;
label_1e778c:
    // 0x1e778c: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1e778cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e7790: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x1e7790u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1e7794: 0xc07c680  jal         func_1F1A00
    ctx->pc = 0x1E7794u;
    SET_GPR_U32(ctx, 31, 0x1E779Cu);
    ctx->pc = 0x1F1A00u;
    if (runtime->hasFunction(0x1F1A00u)) {
        auto targetFn = runtime->lookupFunction(0x1F1A00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E779Cu; }
        if (ctx->pc != 0x1E779Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1A00_0x1f1a00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E779Cu; }
        if (ctx->pc != 0x1E779Cu) { return; }
    }
    ctx->pc = 0x1E779Cu;
label_1e779c:
    // 0x1e779c: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e779cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e77a0: 0x2444002c  addiu       $a0, $v0, 0x2C
    ctx->pc = 0x1e77a0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 44));
    // 0x1e77a4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e77a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e77a8: 0x2443000c  addiu       $v1, $v0, 0xC
    ctx->pc = 0x1e77a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x1e77ac: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1e77acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1e77b0: 0xac820008  sw          $v0, 0x8($a0)
    ctx->pc = 0x1e77b0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 2));
    // 0x1e77b4: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1e77b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1e77b8: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e77b8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
label_1e77bc:
    // 0x1e77bc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e77bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e77c0: 0x8c420060  lw          $v0, 0x60($v0)
    ctx->pc = 0x1e77c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 96)));
    // 0x1e77c4: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1e77c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1e77c8: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e77c8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e77cc: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1e77ccu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e77d0: 0xc07c47a  jal         func_1F11E8
    ctx->pc = 0x1E77D0u;
    SET_GPR_U32(ctx, 31, 0x1E77D8u);
    ctx->pc = 0x1F11E8u;
    if (runtime->hasFunction(0x1F11E8u)) {
        auto targetFn = runtime->lookupFunction(0x1F11E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E77D8u; }
        if (ctx->pc != 0x1E77D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F11E8_0x1f11e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E77D8u; }
        if (ctx->pc != 0x1E77D8u) { return; }
    }
    ctx->pc = 0x1E77D8u;
label_1e77d8:
    // 0x1e77d8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e77d8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e77dc:
    // 0x1e77dc: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e77dcu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e77e0: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1e77e0u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1e77e4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1e77e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1e77e8: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1e77e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1e77ec: 0x3e00008  jr          $ra
    ctx->pc = 0x1E77ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E7690u: goto label_1e7690;
            case 0x1E769Cu: goto label_1e769c;
            case 0x1E76B8u: goto label_1e76b8;
            case 0x1E7774u: goto label_1e7774;
            case 0x1E7784u: goto label_1e7784;
            case 0x1E778Cu: goto label_1e778c;
            case 0x1E779Cu: goto label_1e779c;
            case 0x1E77BCu: goto label_1e77bc;
            case 0x1E77D8u: goto label_1e77d8;
            case 0x1E77DCu: goto label_1e77dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E77F4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
