#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012B3F8
// Address: 0x12b3f8 - 0x12b490
void sub_0012B3F8_0x12b3f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012B3F8_0x12b3f8");
#endif

    switch (ctx->pc) {
        case 0x12b44cu: goto label_12b44c;
        case 0x12b460u: goto label_12b460;
        case 0x12b470u: goto label_12b470;
        case 0x12b47cu: goto label_12b47c;
        default: break;
    }

    ctx->pc = 0x12b3f8u;

    // 0x12b3f8: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12b3f8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12b3fc: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x12b3fcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x12b400: 0x8c477d78  lw          $a3, 0x7D78($v0)
    ctx->pc = 0x12b400u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 32120)));
    // 0x12b404: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x12b404u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x12b408: 0x3c050013  lui         $a1, 0x13
    ctx->pc = 0x12b408u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)19 << 16));
    // 0x12b40c: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12b40cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12b410: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x12b410u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x12b414: 0x3c100021  lui         $s0, 0x21
    ctx->pc = 0x12b414u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)33 << 16));
    // 0x12b418: 0x24633d70  addiu       $v1, $v1, 0x3D70
    ctx->pc = 0x12b418u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 15728));
    // 0x12b41c: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x12b41cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12b420: 0x24062000  addiu       $a2, $zero, 0x2000
    ctx->pc = 0x12b420u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
    // 0x12b424: 0x24a5ae50  addiu       $a1, $a1, -0x51B0
    ctx->pc = 0x12b424u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294946384));
    // 0x12b428: 0x24421cf0  addiu       $v0, $v0, 0x1CF0
    ctx->pc = 0x12b428u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 7408));
    // 0x12b42c: 0x261004ec  addiu       $s0, $s0, 0x4EC
    ctx->pc = 0x12b42cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1260));
    // 0x12b430: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x12b430u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x12b434: 0xafa50004  sw          $a1, 0x4($sp)
    ctx->pc = 0x12b434u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 5));
    // 0x12b438: 0xafa30008  sw          $v1, 0x8($sp)
    ctx->pc = 0x12b438u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 3));
    // 0x12b43c: 0xafa6000c  sw          $a2, 0xC($sp)
    ctx->pc = 0x12b43cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 6));
    // 0x12b440: 0xafa70014  sw          $a3, 0x14($sp)
    ctx->pc = 0x12b440u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 7));
    // 0x12b444: 0xc045108  jal         func_114420
    ctx->pc = 0x12B444u;
    SET_GPR_U32(ctx, 31, 0x12B44Cu);
    ctx->pc = 0x12B448u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B444u;
            // 0x12b448: 0xafa20010  sw          $v0, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114420u;
    if (runtime->hasFunction(0x114420u)) {
        auto targetFn = runtime->lookupFunction(0x114420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B44Cu; }
        if (ctx->pc != 0x12B44Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114420_0x114420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B44Cu; }
        if (ctx->pc != 0x12B44Cu) { return; }
    }
    ctx->pc = 0x12B44Cu;
label_12b44c:
    // 0x12b44c: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x12b44cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x12b450: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12b450u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12b454: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x12b454u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12b458: 0xc045110  jal         func_114440
    ctx->pc = 0x12B458u;
    SET_GPR_U32(ctx, 31, 0x12B460u);
    ctx->pc = 0x12B45Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B458u;
            // 0x12b45c: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114440u;
    if (runtime->hasFunction(0x114440u)) {
        auto targetFn = runtime->lookupFunction(0x114440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B460u; }
        if (ctx->pc != 0x12B460u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114440_0x114440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B460u; }
        if (ctx->pc != 0x12B460u) { return; }
    }
    ctx->pc = 0x12B460u;
label_12b460:
    // 0x12b460: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x12b460u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12b464: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12b464u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12b468: 0xc04512c  jal         func_1144B0
    ctx->pc = 0x12B468u;
    SET_GPR_U32(ctx, 31, 0x12B470u);
    ctx->pc = 0x12B46Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B468u;
            // 0x12b46c: 0x8c450478  lw          $a1, 0x478($v0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1144)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1144B0u;
    if (runtime->hasFunction(0x1144B0u)) {
        auto targetFn = runtime->lookupFunction(0x1144B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B470u; }
        if (ctx->pc != 0x12B470u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001144B0_0x1144b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B470u; }
        if (ctx->pc != 0x12B470u) { return; }
    }
    ctx->pc = 0x12B470u;
label_12b470:
    // 0x12b470: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x12b470u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12b474: 0xc04ac56  jal         func_12B158
    ctx->pc = 0x12B474u;
    SET_GPR_U32(ctx, 31, 0x12B47Cu);
    ctx->pc = 0x12B158u;
    if (runtime->hasFunction(0x12B158u)) {
        auto targetFn = runtime->lookupFunction(0x12B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B47Cu; }
        if (ctx->pc != 0x12B47Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B158_0x12b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B47Cu; }
        if (ctx->pc != 0x12B47Cu) { return; }
    }
    ctx->pc = 0x12B47Cu;
label_12b47c:
    // 0x12b47c: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x12b47cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12b480: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x12b480u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12b484: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x12b484u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12b488: 0x3e00008  jr          $ra
    ctx->pc = 0x12B488u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12B48Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12B488u;
            // 0x12b48c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12B44Cu: goto label_12b44c;
            case 0x12B460u: goto label_12b460;
            case 0x12B470u: goto label_12b470;
            case 0x12B47Cu: goto label_12b47c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12B490u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
