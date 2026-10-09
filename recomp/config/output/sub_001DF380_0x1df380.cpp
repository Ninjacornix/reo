#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DF380
// Address: 0x1df380 - 0x1df4a8
void sub_001DF380_0x1df380(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DF380_0x1df380");
#endif

    switch (ctx->pc) {
        case 0x1df454u: goto label_1df454;
        case 0x1df480u: goto label_1df480;
        default: break;
    }

    ctx->pc = 0x1df380u;

    // 0x1df380: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1df380u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1df384: 0xffbe0040  sd          $fp, 0x40($sp)
    ctx->pc = 0x1df384u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 30));
    // 0x1df388: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x1df388u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x1df38c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1df38cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df390: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1df390u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1df394: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1df394u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1df398: 0x24020027  addiu       $v0, $zero, 0x27
    ctx->pc = 0x1df398u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 39));
    // 0x1df39c: 0xa3c20010  sb          $v0, 0x10($fp)
    ctx->pc = 0x1df39cu;
    WRITE8(ADD32(GPR_U32(ctx, 30), 16), (uint8_t)GPR_U32(ctx, 2));
    // 0x1df3a0: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1df3a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1df3a4: 0x2442002c  addiu       $v0, $v0, 0x2C
    ctx->pc = 0x1df3a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 44));
    // 0x1df3a8: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1df3a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1df3ac: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1df3acu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1df3b0: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x1df3b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1df3b4: 0xa7c20014  sh          $v0, 0x14($fp)
    ctx->pc = 0x1df3b4u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 20), (uint16_t)GPR_U32(ctx, 2));
    // 0x1df3b8: 0x24021000  addiu       $v0, $zero, 0x1000
    ctx->pc = 0x1df3b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x1df3bc: 0xa7c20016  sh          $v0, 0x16($fp)
    ctx->pc = 0x1df3bcu;
    WRITE16(ADD32(GPR_U32(ctx, 30), 22), (uint16_t)GPR_U32(ctx, 2));
    // 0x1df3c0: 0xa3c00011  sb          $zero, 0x11($fp)
    ctx->pc = 0x1df3c0u;
    WRITE8(ADD32(GPR_U32(ctx, 30), 17), (uint8_t)GPR_U32(ctx, 0));
    // 0x1df3c4: 0xa7c00012  sh          $zero, 0x12($fp)
    ctx->pc = 0x1df3c4u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 18), (uint16_t)GPR_U32(ctx, 0));
    // 0x1df3c8: 0xafc0001c  sw          $zero, 0x1C($fp)
    ctx->pc = 0x1df3c8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 0));
    // 0x1df3cc: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1df3ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1df3d0: 0x2442003c  addiu       $v0, $v0, 0x3C
    ctx->pc = 0x1df3d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 60));
    // 0x1df3d4: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1df3d4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1df3d8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1df3d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1df3dc: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1df3dcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1df3e0: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1df3e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1df3e4: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1df3e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1df3e8: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1df3e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1df3ec: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1df3ecu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1df3f0: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1df3f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1df3f4: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1df3f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1df3f8: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1df3f8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1df3fc: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1df3fcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1df400: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1df400u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1df404: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1df404u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1df408: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x1df408u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1df40c: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1df40cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1df410: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1df410u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1df414: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1df414u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1df418: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1df418u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1df41c: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1df41cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1df420: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x1df420u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1df424: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1df424u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1df428: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1df428u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1df42c: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1df42cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1df430: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1df430u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1df434: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1df434u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1df438: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1df438u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1df43c: 0x94420000  lhu         $v0, 0x0($v0)
    ctx->pc = 0x1df43cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1df440: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1df440u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df444: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1df444u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df448: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1df448u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df44c: 0xc076bab  jal         func_1DAEAC
    ctx->pc = 0x1DF44Cu;
    SET_GPR_U32(ctx, 31, 0x1DF454u);
    ctx->pc = 0x1DAEACu;
    if (runtime->hasFunction(0x1DAEACu)) {
        auto targetFn = runtime->lookupFunction(0x1DAEACu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DF454u; }
        if (ctx->pc != 0x1DF454u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAEAC_0x1daeac(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DF454u; }
        if (ctx->pc != 0x1DF454u) { return; }
    }
    ctx->pc = 0x1DF454u;
label_1df454:
    // 0x1df454: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df454u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df458: 0x8c4205b8  lw          $v0, 0x5B8($v0)
    ctx->pc = 0x1df458u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1464)));
    // 0x1df45c: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1DF45Cu;
    {
        const bool branch_taken_0x1df45c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1df45c) {
            ctx->pc = 0x1DF480u;
            goto label_1df480;
        }
    }
    ctx->pc = 0x1DF464u;
    // 0x1df464: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df464u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df468: 0x27c30010  addiu       $v1, $fp, 0x10
    ctx->pc = 0x1df468u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 16));
    // 0x1df46c: 0x27c50020  addiu       $a1, $fp, 0x20
    ctx->pc = 0x1df46cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 30), 32));
    // 0x1df470: 0x8c4205b8  lw          $v0, 0x5B8($v0)
    ctx->pc = 0x1df470u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1464)));
    // 0x1df474: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x1df474u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df478: 0x40f809  jalr        $v0
    ctx->pc = 0x1DF478u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1DF480u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1DF480u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DF454u: goto label_1df454;
            case 0x1DF480u: goto label_1df480;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1DF480u; }
            if (ctx->pc != 0x1DF480u) { return; }
        }
        }
    }
    ctx->pc = 0x1DF480u;
label_1df480:
    // 0x1df480: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df480u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df484: 0xac40007c  sw          $zero, 0x7C($v0)
    ctx->pc = 0x1df484u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 124), GPR_U32(ctx, 0));
    // 0x1df488: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1df488u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df48c: 0xac400080  sw          $zero, 0x80($v0)
    ctx->pc = 0x1df48cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 128), GPR_U32(ctx, 0));
    // 0x1df490: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1df490u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df494: 0xdfbe0040  ld          $fp, 0x40($sp)
    ctx->pc = 0x1df494u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1df498: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x1df498u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1df49c: 0x27bd0050  addiu       $sp, $sp, 0x50
    ctx->pc = 0x1df49cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1df4a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1DF4A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DF454u: goto label_1df454;
            case 0x1DF480u: goto label_1df480;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DF4A8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
